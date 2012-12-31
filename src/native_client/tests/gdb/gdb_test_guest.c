/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <assert.h>
#include <string.h>

int global_var;

void test_two_line_function(int arg) {
  global_var = arg - 1;
  global_var = arg;
}

void test_stepi_after_break() {
  /* Something meaningful to step through.  */
  global_var = 0;
}

void set_global_var(int arg) {
  global_var = arg;
}

void leaf_call(int arg) {
  global_var = arg;
}

void nested_calls(int arg) {
  global_var = 1;
  leaf_call(arg + 1);
}

int test_print_symbol() {
  int local_var = 3;
  global_var = 2 + local_var * 0; /* Use local variable to prevent warning.  */
  set_global_var(1);
  nested_calls(1);
  return global_var;
}

int main(int argc, char **argv) {
  assert(argc >= 2);

  if (strcmp(argv[1], "break_inside_function") == 0) {
    test_two_line_function(1);
    return 0;
  }
  if (strcmp(argv[1], "stepi_after_break") == 0) {
    test_stepi_after_break();
    return 0;
  }
  if (strcmp(argv[1], "print_symbol") == 0) {
    return test_print_symbol();
  }
  if (strcmp(argv[1], "stack_trace") == 0) {
    nested_calls(1);
    return 0;
  }
  return 1;
}
