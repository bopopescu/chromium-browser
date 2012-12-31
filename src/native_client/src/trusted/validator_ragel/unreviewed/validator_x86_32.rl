/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "native_client/src/trusted/validator_ragel/unreviewed/validator_internal.h"

/* Ignore this information: it's not used by security model in IA32 mode.  */
#undef GET_VEX_PREFIX3
#define GET_VEX_PREFIX3 0
#undef SET_VEX_PREFIX3
#define SET_VEX_PREFIX3(P)

%%{
  machine x86_64_decoder;
  alphtype unsigned char;
  variable p current_position;
  variable pe end_of_bundle;
  variable eof end_of_bundle;
  variable cs current_state;

  action rel8_operand {
    rel8_operand(current_position + 1, data, jump_dests, size,
                 &errors_detected);
  }
  action rel16_operand {
    #error rel16_operand should never be used in nacl
  }
  action rel32_operand {
    rel32_operand(current_position + 1, data, jump_dests, size,
                  &errors_detected);
  }

  # Do nothing when IMM operand is detected for now.  Will be used later for
  # dynamic code modification support.
  action imm2_operand { }
  action imm8_operand { }
  action imm16_operand { }
  action imm32_operand { }
  action imm64_operand { }
  action imm8_second_operand { }
  action imm16_second_operand { }
  action imm32_second_operand { }
  action imm64_second_operand { }

  include decode_x86_32 "validator_x86_32_instruction.rl";

  special_instruction =
    (0x83 0xe0 0xe0 0xff (0xd0|0xe0)  | # naclcall/jmp %eax
     0x83 0xe1 0xe0 0xff (0xd1|0xe1)  | # naclcall/jmp %ecx
     0x83 0xe2 0xe0 0xff (0xd2|0xe2)  | # naclcall/jmp %edx
     0x83 0xe3 0xe0 0xff (0xd3|0xe3)  | # naclcall/jmp %ebx
     0x83 0xe4 0xe0 0xff (0xd4|0xe4)  | # naclcall/jmp %esp
     0x83 0xe5 0xe0 0xff (0xd5|0xe5)  | # naclcall/jmp %ebp
     0x83 0xe6 0xe0 0xff (0xd6|0xe6)  | # naclcall/jmp %esi
     0x83 0xe7 0xe0 0xff (0xd7|0xe7))   # naclcall/jmp %edi
    @{
      BitmapClearBit(valid_targets, (current_position - data) - 1);
    } |
    (0x65 0xa1 (0x00|0x04) 0x00 0x00 0x00      | # mov %gs:0x0/0x4,%eax
     0x65 0x8b (0x05|0x0d|0x015|0x1d|0x25|0x2d|0x35|0x3d)
          (0x00|0x04) 0x00 0x00 0x00);           # mov %gs:0x0/0x4,%reg

  main := ((one_instruction | special_instruction)
     >{
       BitmapSetBit(valid_targets, current_position - data);
     }
     @{
       if (errors_detected) {
         process_error(instruction_start, errors_detected, userdata);
         result = 1;
       }
       /* On successful match the instruction start must point to the next byte
        * to be able to report the new offset as the start of instruction
        * causing error.  */
       instruction_start = current_position + 1;
       errors_detected = 0;
     })*
    $err{
        process_error(instruction_start, UNRECOGNIZED_INSTRUCTION, userdata);
        result = 1;
        goto error_detected;
    };

}%%

%% write data;


int ValidateChunkIA32(const uint8_t *data, size_t size,
                      const NaClCPUFeaturesX86 *cpu_features,
                      process_validation_error_func process_error,
                      void *userdata) {
  uint8_t *valid_targets = BitmapAllocate(size);
  uint8_t *jump_dests = BitmapAllocate(size);

  const uint8_t *current_position = data;

  int result = 0;

  size_t i;

  uint32_t errors_detected = 0;

  assert(size % kBundleSize == 0);

  if (!valid_targets || !jump_dests) goto error_detected;

  while (current_position < data + size) {
    /* Start of the instruction being processed.  */
    const uint8_t *instruction_start = current_position;
    const uint8_t *end_of_bundle = current_position + kBundleSize;
    int current_state;

    %% write init;
    %% write exec;
  }

  for (i = 0; i < size / 32; i++) {
    uint32_t jump_dest_mask = ((uint32_t *) jump_dests)[i];
    uint32_t valid_target_mask = ((uint32_t *) valid_targets)[i];
    if ((jump_dest_mask & ~valid_target_mask) != 0) {
      process_error(data + i * 32, BAD_JUMP_TARGET, userdata);
      result = 1;
      break;
    }
  }

error_detected:
  free(jump_dests);
  free(valid_targets);
  return result;
}
