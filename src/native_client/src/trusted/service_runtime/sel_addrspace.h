/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * NaCl Simple/secure ELF loader (NaCl SEL).
 */

#ifndef __SEL_ADDRSPACE_H__
#define __SEL_ADDRSPACE_H__ 1

#include "native_client/src/include/nacl_base.h"
#include "native_client/src/include/portability.h"
#include "native_client/src/trusted/service_runtime/nacl_error_code.h"

struct NaClApp; /* fwd */

EXTERN_C_BEGIN

#if NACL_LINUX
extern size_t g_prereserved_sandbox_size;
#endif

/*
 * Try to find prereserved sandbox memory.  Sets *p to the start of the
 * sandbox.
 *
 * Returns a non-zero value if prereserved sandbox memory was found and the
 * memory is the same size as the requested size.  Returns zero otherwise.
 */
int NaClFindPrereservedSandboxMemory(void **p, size_t num_bytes);

void NaClAddrSpaceBeforeAlloc(size_t guarded_addrsp_size);

NaClErrorCode NaClAllocAddrSpace(struct NaClApp *nap) NACL_WUR;

/*
 * Apply memory protection to memory regions.
 */
NaClErrorCode NaClMemoryProtection(struct NaClApp *nap) NACL_WUR;

/*
 * Platform-specific routine to allocate memory space for the NaCl
 * module.  mem is an out argument; addrsp_size is the requested
 * address space size, currently always ((size_t) 1) <<
 * nap->addr_bits.  On x86-64, there's a further requirement that this
 * is 4G.
 *
 * The actual amount of memory allocated is larger than requested on
 * x86-64 and on the ARM, since guard pages are also allocated to be
 * contiguous with the allocated address space.
 *
 * If successful, the guard pages are not yet memory protected.  The
 * function NaClMprotectGuards must be called for the guard pages to
 * be active.
 *
 * Returns LOAD_OK on success.
 */
NaClErrorCode NaClAllocateSpace(void **mem, size_t addrsp_size) NACL_WUR;

NaClErrorCode NaClMprotectGuards(struct NaClApp *nap);

/*
 * NaClAddrSpaceFree() unmaps all of untrusted address space.  This is
 * only safe if no untrusted threads are running.
 *
 * Note that this does not free any other data structures associated
 * with the NaClApp.  In particular, it does not free mem_map.
 */
void NaClAddrSpaceFree(struct NaClApp *nap);

EXTERN_C_END

#endif
