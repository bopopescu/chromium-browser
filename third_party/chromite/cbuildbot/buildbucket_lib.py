# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Code releated to buildbucket.

Buildbucket is a generic build queue. A build requester can schedule
a build and wait for a result. A building system, such as Buildbot,
can lease it, build it and report a result back.

For more documents about buildbucket, please refer to:
'https://chromium.googlesource.com/infra/infra/+/master/appengine/
cr-buildbucket/README.md'
"""

from __future__ import print_function

import json
import os
import urllib

from chromite.cbuildbot import topology
from chromite.lib import auth
from chromite.lib import constants
from chromite.lib import cros_logging as logging
from chromite.lib import retry_util

# Methods
PUT_METHOD = 'PUT'
POST_METHOD = 'POST'
GET_METHOD = 'GET'

# Default limit for SearchAllBuilds.
SEARCH_LIMIT_DEFAULT = 100
# Default limit for max_builds in Buildbucket search requests,
# max_builds cannot be larger than 100 in Buildbucket search requests
MAX_BUILDS_LIMIT = 100
# Default max_builds number
MAX_BUILDS_DEFAULT = 10

WATERFALL_BUCKET_MAP = {
    constants.WATERFALL_INTERNAL:
        constants.CHROMEOS_BUILDBUCKET_BUCKET,
    constants.WATERFALL_EXTERNAL:
        constants.CHROMIUMOS_BUILDBUCKET_BUCKET,
}

class BuildbucketResponseException(Exception):
  """Exception got from Buildbucket Response."""

class NoBuildbucketBucketFoundException(Exception):
  """Failed to found the corresponding buildbucket bucket."""

class NoBuildbucketClientException(Exception):
  """No Buildbucket client exception."""

def GetServiceAccount(service_account=None):
  """Get service account file.

  Args:
    service_account: Service account file path.

  Returns:
    Return service_account path if the file exists; else, return None.
  """
  if service_account and os.path.isfile(service_account):
    logging.info('Get service account %s', service_account)
    return service_account
  return None

class BuildbucketClient(object):
  """Buildbucket client to interact with the Buildbucket server."""

  def __init__(self, service_account=None):
    self.http = auth.AuthorizedHttp(
        auth.GetAccessToken,
        service_account_json=service_account)

  def GetHost(self, testjob):
    """Get buildbucket Server host."""
    return topology.topology[
        topology.BUILDBUCKET_TEST_HOST_KEY if testjob
        else topology.BUILDBUCKET_HOST_KEY]

  def SendBuildbucketRequest(self, url, method, body, dryrun):
    """Generic buildbucket request.

    Args:
      url: Buildbucket url to send requests.
      method: HTTP method to perform, such as GET, POST, DELETE.
      body: The entity body to be sent with the request (a string object).
            See httplib2.Http.request for details.
      dryrun: Whether a dryrun.

    Returns:
      A dict of response entity body if the request succeeds; else, None.
      See httplib2.Http.request for details.

    Raises:
      BuildbucketResponseException when response['status'] is invalid.
    """
    if dryrun:
      logging.info('Dryrun mode is on; Would have made a request '
                   'with url %s method %s body:\n%s', url, method, body)
      return

    def try_method():
      response, content = self.http.request(
          url,
          method,
          body=body,
          headers={'Content-Type': 'application/json'},
      )

      if int(response['status']) // 100 != 2:
        raise BuildbucketResponseException(
            'Got a %s response from buildbucket with url: %s\n'
            'content: %s' % (response['status'], url, content))

      # Deserialize the content into a python dict.
      return json.loads(content)

    return retry_util.GenericRetry(lambda _: True, 3, try_method)

  def PutBuildRequest(self, body, testjob, dryrun):
    """Send Put request to buildbucket server.

    Args:
      body: See body in SendBuildbucketRequest for details.
      testjob: Whether to use the test instance of the buildbucket server.
      dryrun: Whether a dryrun.

    Returns:
      See return type of SendBuildbucketRequest.
    """
    url = 'https://%(hostname)s/_ah/api/buildbucket/v1/builds' % {
        'hostname': self.GetHost(testjob)
    }

    return self.SendBuildbucketRequest(url, PUT_METHOD, body, dryrun)

  def GetBuildRequest(self, buildbucket_id, testjob, dryrun):
    """Send Get request to buildbucket server.

    Args:
      buildbucket_id: Buildbucket_id (string) of the build to get.
      testjob: Whether to use the test instance of the buildbucket server.
      dryrun: Whether a dryrun.

    Returns:
      See return type of SendBuildbucketRequest.
    """
    url = 'https://%(hostname)s/_ah/api/buildbucket/v1/builds/%(id)s' % {
        'hostname': self.GetHost(testjob),
        'id': buildbucket_id
    }

    return self.SendBuildbucketRequest(url, GET_METHOD, None, dryrun)

  def CancelBuildRequest(self, buildbucket_id, testjob, dryrun):
    """Send Cancel request to buildbucket server.

    Args:
      buildbucket_id: Buildbucket_id (string) of the build to cancel.
      testjob: Whether to use the test instance of the buildbucket server.
      dryrun: Whether a dryrun.

    Returns:
      See return type of SendBuildbucketRequest.
    """
    url = 'https://%(hostname)s/_ah/api/buildbucket/v1/builds/%(id)s/cancel' % {
        'hostname': self.GetHost(testjob),
        'id': buildbucket_id
    }

    return self.SendBuildbucketRequest(url, POST_METHOD, '{}', dryrun)

  def CancelBatchBuildsRequest(self, buildbucket_ids, testjob, dryrun):
    """Send CancelBatch request to buildbucket server.

    Args:
      buildbucket_ids: buildbucket_ids (string list) of the builds to cancel.
      testjob: Whether to use the test instance of the buildbucket server.
      dryrun: Whether a dryrun.

    Returns:
      See return type of SendBuildbucketRequest.
    """
    url = 'https://%(hostname)s/_ah/api/buildbucket/v1/builds/cancel' % {
        'hostname': self.GetHost(testjob)
    }

    body = json.dumps({'build_ids': buildbucket_ids})

    return self.SendBuildbucketRequest(url, POST_METHOD, body, dryrun)

  def SearchBuildsRequest(self, testjob, dryrun, buckets=None, tags=None,
                          status=None, start_cursor=None,
                          max_builds=MAX_BUILDS_DEFAULT):
    """Send Search requests to the Buildbucket server.

    Args:
      testjob: Whether to use the test instance of the buildbucket server.
      dryrun: Whether a dryrun.
      buckets: Search for builds in the buckets (string list).
      tags: Search for builds containing all the tags (string list).
      status: Search for builds in this status (string).
      start_cursor: Search for builds with this start cursor (string).
      max_builds: Maximum number of builds to return in this request (int).

    Returns:
      See return type of SendBuildbucketRequest.
    """
    params = []
    if buckets:
      assert isinstance(buckets, list), 'buckets must be a list of string.'
      for bucket in buckets:
        params.append(('bucket', bucket))
    if tags:
      assert isinstance(tags, list), 'tags must be a list of string.'
      for tag in tags:
        params.append(('tag', tag))
    if status:
      if status not in constants.BUILDBUCKET_BUILDER_STATUSES:
        raise ValueError('status must be one of %s' %
                         str(constants.BUILDBUCKET_BUILDER_STATUSES))
      params.append(('status', status))
    if start_cursor:
      params.append(('start_cursor', start_cursor))
    if max_builds is not None:
      if max_builds <= 0 or max_builds > MAX_BUILDS_LIMIT:
        raise ValueError('max_builds must be number in (0, %s]' %
                         MAX_BUILDS_LIMIT)
      params.append(('max_builds', max_builds))

    params_str = urllib.urlencode(params)

    url = ('https://%(hostname)s/_ah/api/buildbucket/v1/search?%(params_str)s'
           % {'hostname': self.GetHost(testjob), 'params_str': params_str})

    return self.SendBuildbucketRequest(url, GET_METHOD, None, dryrun)

  def SearchAllBuilds(self, testjob, dryrun, limit=SEARCH_LIMIT_DEFAULT,
                      buckets=None, tags=None, status=None):
    """Search all qualified builds.

    Args:
      testjob: Whether to use the test instance of the buildbucket server.
      limit: The limit count of search results.
      dryrun: Whether a dryrun.
      buckets: Search for builds in the buckets (string list).
      tags: Search for builds containing all the tags (string list).
      status: Search for builds in this status (string).

    Returns:
      List of builds.
    """

    if limit <= 0:
      raise ValueError('limit %s must be greater than 0.')

    next_cursor = None
    all_builds = []

    while True:
      current_limit = limit - len(all_builds)
      # Do not search for more than MAX_BUILDS_LIMIT builds in one request.
      max_builds = (MAX_BUILDS_LIMIT if current_limit > MAX_BUILDS_LIMIT
                    else current_limit)

      content = self.SearchBuildsRequest(
          testjob, dryrun, buckets=buckets, tags=tags, status=status,
          start_cursor=next_cursor, max_builds=max_builds)

      builds = GetNestedAttr(content, ['builds'], default=[])

      if not builds:
        logging.debug('No build found.')
        break

      all_builds.extend(builds)

      if len(all_builds) >= limit:
        logging.info('Reached the search limit %s', limit)
        break

      next_cursor = GetNestedAttr(content, ['next_cursor'])
      if next_cursor is None:
        logging.debug('No next_cursor in the response.')
        break

    return all_builds

def GetNestedAttr(content, nested_attr, default=None):
  """Get the (nested) attribuite from content.

  Get the (nested) attribute from the content dict.
  E.X. content is {key1: {key2: {key3: value3}}, key4: value4}
  nested_attr = [key1] gets {key2: value2, {key3: value3}}
  nested_attr = [key1, key2] gets {key3: value3}
  nested_attr = [key1, key2, key3] gets value3
  nested_attr = [key5] gets the default value.

  Args:
    content: A dict of (nested) attributes.
    nested_attr: String list presenting the (nested) attribute to get.
    default: Default value to return if the attribute doesn't exist.

  Returns:
    The corresponding value if the attribute exits; else, default.
  """
  assert isinstance(nested_attr, list), 'nested_attr must be a list.'

  if content is None:
    return default

  assert isinstance(content, dict), 'content must be a dict.'

  value = content
  for attr in nested_attr:
    assert isinstance(attr, str), 'attribute name must be a string.'

    if not isinstance(value, dict):
      return default

    value = value.get(attr, default)

  return value

def GetErrorReason(content):
  return GetNestedAttr(content, ['error', 'reason'])

def GetBuildId(content):
  return GetNestedAttr(content, ['build', 'id'])

def GetBuildStatus(content):
  return GetNestedAttr(content, ['build', 'status'])

def GetBuildResult(content):
  return GetNestedAttr(content, ['build', 'result'])

def GetBuildCreated_ts(content):
  return GetNestedAttr(content, ['build', 'created_ts'])

def GetBuildIds(content):
  builds = GetNestedAttr(content, ['builds'], default=[])
  return [b.get('id') for b in builds]

def ExtractBuildIds(builds):
  return ([b.get('id') for b in builds] if builds is not None else [])

def GetResultMap(content):
  """Get a build_id to result map."""
  build_result_map = {}
  results = GetNestedAttr(content, ['results'], default=[])

  for r in results:
    if r.get('build_id') is not None:
      build_id = r.pop('build_id')
      build_result_map[build_id] = r

  return build_result_map
