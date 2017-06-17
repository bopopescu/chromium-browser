# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""System metrics."""

from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import errno
import os
import time

import psutil

from chromite.lib import cros_logging as logging
from infra_libs import ts_mon

logger = logging.getLogger(__name__)


_cpu_count_metric = ts_mon.GaugeMetric(
    'dev/cpu/count',
    description='Number of CPU cores.')
_cpu_time_metric = ts_mon.FloatMetric(
    'dev/cpu/time',
    description='percentage of time spent by the CPU '
    'in different states.')

_disk_free_metric = ts_mon.GaugeMetric(
    'dev/disk/free',
    description='Available bytes on disk partition.',
    units=ts_mon.MetricsDataUnits.BYTES)
_disk_total_metric = ts_mon.GaugeMetric(
    'dev/disk/total',
    description='Total bytes on disk partition.',
    units=ts_mon.MetricsDataUnits.BYTES)

_inodes_free_metric = ts_mon.GaugeMetric(
    'dev/inodes/free',
    description='Number of available inodes on '
    'disk partition (unix only).')
_inodes_total_metric = ts_mon.GaugeMetric(
    'dev/inodes/total',
    description='Number of possible inodes on '
    'disk partition (unix only)')

_mem_free_metric = ts_mon.GaugeMetric(
    'dev/mem/free',
    description='Amount of memory available to a '
    'process (in Bytes). Buffers are considered '
    'free memory.',
    units=ts_mon.MetricsDataUnits.BYTES)

_mem_total_metric = ts_mon.GaugeMetric(
    'dev/mem/total',
    description='Total physical memory in Bytes.',
    units=ts_mon.MetricsDataUnits.BYTES)

_BOOT_TIME = psutil.boot_time()

_disk_read_metric = ts_mon.CounterMetric(
    'dev/disk/read', start_time=_BOOT_TIME,
    description='Number of Bytes read on disk.',
    units=ts_mon.MetricsDataUnits.BYTES)
_disk_write_metric = ts_mon.CounterMetric(
    'dev/disk/write', start_time=_BOOT_TIME,
    description='Number of Bytes written on disk.',
    units=ts_mon.MetricsDataUnits.BYTES)

_uptime_metric = ts_mon.GaugeMetric(
    'dev/uptime',
    description='Machine uptime, in seconds.',
    units=ts_mon.MetricsDataUnits.SECONDS)

_proc_count_metric = ts_mon.GaugeMetric(
    'dev/proc/count',
    description='Number of processes currently running.')
_autoserv_proc_count_metric = ts_mon.GaugeMetric(
    'dev/proc/autoserv_count',
    description='Number of autoserv processes currently running.')
_sysmon_proc_count_metric = ts_mon.GaugeMetric(
    'dev/proc/sysmon_count',
    description='Number of sysmon processes currently running.')
_load_average_metric = ts_mon.FloatMetric(
    'dev/proc/load_average',
    description='Number of processes currently '
    'in the system run queue.')

# ts_mon pipeline uses backend clocks when assigning timestamps to metric
# points.  By comparing point timestamp to the point value (i.e. time by
# machine's local clock), we can potentially detect some anomalies (clock
# drift, unusually high metrics pipeline delay, completely wrong clocks, etc).
#
# It is important to gather this metric right before the flush.
_unix_time_metric = ts_mon.GaugeMetric(
    'dev/unix_time',
    description='Number of milliseconds since epoch'
    ' based on local machine clock.')

_os_name_metric = ts_mon.StringMetric(
    'proc/os/name',
    description='OS name on the machine')

_os_version_metric = ts_mon.StringMetric(
    'proc/os/version',
    description='OS version on the machine')

_os_arch_metric = ts_mon.StringMetric(
    'proc/os/arch',
    description='OS architecture on this machine')

_python_arch_metric = ts_mon.StringMetric(
    'proc/python/arch',
    description='python userland '
    'architecture on this machine')


def collect_uptime():
  _uptime_metric.set(int(time.time() - _BOOT_TIME))


def collect_cpu_info():
  _cpu_count_metric.set(psutil.cpu_count())

  times = psutil.cpu_times_percent()
  for mode in ('user', 'system', 'idle'):
    _cpu_time_metric.set(getattr(times, mode), {'mode': mode})


def collect_disk_info(mountpoints=None):
  if mountpoints is None:
    mountpoints = [disk.mountpoint for disk in psutil.disk_partitions()]
  for mountpoint in mountpoints:
    _collect_disk_info_single(mountpoint)
    _collect_fs_inode_info(mountpoint)
  _collect_disk_io_info()


def _collect_disk_info_single(mountpoint):
  fields = {'path': mountpoint}

  try:
    usage = psutil.disk_usage(mountpoint)
  except OSError as ex:
    if ex.errno == errno.ENOENT:
      # This happens on Windows when querying a removable drive that
      # doesn't have any media inserted right now.
      pass
    else:
      raise
  else:
    _disk_free_metric.set(usage.free, fields=fields)
    _disk_total_metric.set(usage.total, fields=fields)

  # inode counts are only available on Unix.
  if os.name == 'posix':
    _collect_fs_inode_info(mountpoint)


def _collect_fs_inode_info(mountpoint):
  fields = {'path': mountpoint}
  stats = os.statvfs(mountpoint)
  _inodes_free_metric.set(stats.f_favail, fields=fields)
  _inodes_total_metric.set(stats.f_files, fields=fields)


def _collect_disk_io_info():
  try:
    disk_counters = psutil.disk_io_counters(perdisk=True).iteritems()
  except RuntimeError as ex:
    if "couldn't find any physical disk" in str(ex):
      # Disk performance counters aren't enabled on Windows.
      pass
    else:
      raise
  else:
    for disk, counters in disk_counters:
      fields = {'disk': disk}
      _disk_read_metric.set(counters.read_bytes, fields=fields)
      _disk_write_metric.set(counters.write_bytes, fields=fields)


def collect_mem_info():
  # We don't report mem.used because (due to virtual memory) it is not
  # useful.
  mem = psutil.virtual_memory()
  _mem_free_metric.set(mem.available)
  _mem_total_metric.set(mem.total)


def collect_proc_info():
  autoserv_count = 0
  sysmon_count = 0
  total = 0
  for proc in psutil.process_iter():
    if _is_parent_autoserv(proc):
      autoserv_count += 1
    elif _is_sysmon(proc):
      sysmon_count += 1
    total += 1
  logger.debug('autoserv_count: %s', autoserv_count)
  logger.debug('sysmon_count: %s', sysmon_count)
  _autoserv_proc_count_metric.set(autoserv_count)
  _sysmon_proc_count_metric.set(sysmon_count)
  _proc_count_metric.set(total)


def _is_parent_autoserv(proc):
  """Return whether proc is a parent (not forked) autoserv process."""
  return _is_autoserv(proc) and not _is_autoserv(proc.parent())


def _is_autoserv(proc):
  """Return whether proc is an autoserv process."""
  # This relies on the autoserv script being run directly.  The script should
  # be named autoserv exactly and start with a shebang that is /usr/bin/python,
  # NOT /bin/env
  return proc.name() == 'autoserv'


def _is_sysmon(proc):
  """Return whether proc is a sysmon process."""
  return proc.cmdline()[:3] == ['python', '-m', 'chromite.scripts.sysmon']


def collect_load_avg():
  try:
    avg1, avg5, avg15 = os.getloadavg()
  except OSError:
    pass
  else:
    _load_average_metric.set(avg1, fields={'minutes': 1})
    _load_average_metric.set(avg5, fields={'minutes': 5})
    _load_average_metric.set(avg15, fields={'minutes': 15})


def collect_unix_time():
  _unix_time_metric.set(int(time.time() * 1000))
