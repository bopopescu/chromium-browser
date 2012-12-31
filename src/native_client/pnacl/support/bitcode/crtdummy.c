/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Due to a bug in libLTO, this extra file is needed to
 * guarantee that the symbols in crtbegin.bc are available.
 */

void __do_global_dtors_aux(void);
extern void *__dso_handle;

/* This function is never actually invoked */
void __crtbegin_dummy() __attribute__((used));
void __crtbegin_dummy()
{
  __do_global_dtors_aux();
  __dso_handle = 0;
}
