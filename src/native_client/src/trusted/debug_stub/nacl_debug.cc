/*
 * Copyright (c) 2012 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include <vector>
#include <map>

/*
 * NaCl Functions for intereacting with debuggers
 */

#include "native_client/src/trusted/gdb_rsp/session.h"
#include "native_client/src/trusted/gdb_rsp/target.h"
#include "native_client/src/trusted/port/platform.h"
#include "native_client/src/trusted/port/thread.h"

#include "native_client/src/include/nacl_string.h"
#include "native_client/src/shared/platform/nacl_check.h"
#include "native_client/src/shared/platform/nacl_log.h"
#include "native_client/src/shared/platform/nacl_exit.h"
#include "native_client/src/shared/platform/nacl_threads.h"
#include "native_client/src/trusted/debug_stub/debug_stub.h"
#include "native_client/src/trusted/debug_stub/nacl_debug.h"
#include "native_client/src/trusted/service_runtime/nacl_app_thread.h"
#include "native_client/src/trusted/service_runtime/nacl_debug_init.h"
#include "native_client/src/trusted/service_runtime/sel_ldr.h"

using port::IPlatform;
using port::IThread;
using port::ITransport;

using gdb_rsp::Session;
using gdb_rsp::Target;

#ifdef WIN32
/* Disable warning for unwind disabled when exceptions used */
#pragma warning(disable:4530)
#endif

/*
 * These macro wraps all debugging stub calls to prevent C++ code called
 * by the debugging stub to throw and exception past the C API.  We use
 * this technique to allow the use of STL templates.   We catch bad_alloc
 * separately purely to provide information for debugging purposes.
 */
#define DBG_CATCH_ALL                                                       \
  catch(std::bad_alloc) {                                                  \
    NaClLog(LOG_FATAL, "nacl_debug(%d) : Failed to allocate.\n", __LINE__); \
    NaClExit(-1);                                                          \
  }                                                                         \
  catch(std::exception e) {                                                \
    NaClLog(LOG_FATAL, "nacl_debug(%d) : Caught exception: %s.\n",          \
            __LINE__ , e.what());                                           \
    NaClExit(-1);                                                          \
  }                                                                         \
  catch(...) {                                                             \
    NaClLog(LOG_FATAL, "nacl_debug(%d) : Unexpected exception.\n", __LINE__);\
    NaClExit(-1);                                                           \
  }


enum NaClDebugStatus {
  NDS_DISABLED = 0,
  NDS_ENABLED = 1,
  NDS_STOPPED = 2
};

struct NaClDebugState {
  NaClDebugState() : target_(NULL), app_(NULL),
                     status_(NDS_DISABLED) {}

  bool Init() {
    NaClDebugStubInit();
    target_ = new Target();

    CHECK((NULL != target_) && (target_->Init()));

    status_ = NDS_ENABLED;
    return true;
  }

  ~NaClDebugState() {
    /*
     * TODO(mlinck): It is not safe to call this destructor, since there is an
     * unjoinable thread potentially accessing target_.
     */
    delete target_;
  }

  Target* target_;
  struct NaClApp *app_;
  NaClDebugStatus status_;
};

static const struct NaClDebugCallbacks debug_callbacks = {
  NaClDebugThreadPrepDebugging,
  NaClDebugThreadStopDebugging,
  NaClDebugStop,
};

static NaClDebugState *g_nacl_debug_state = NULL;

void WINAPI NaClStubThread(void *ptr) {
  Target *targ = reinterpret_cast<Target*>(ptr);
  while (1) {
    ITransport* trans = NULL;
    Session* ses = NULL;

    try {
      // Wait for a connection.
      trans = ITransport::Accept("127.0.0.1:4014");
      if (NULL == trans) continue;

      // Create a new session for this connection
      ses = new Session();
      ses->Init(trans);
      ses->SetFlags(Session::DEBUG_MASK);

      // Run this session for as long as it lasts
      targ->Run(ses);
    }
    catch(...) {
      delete ses;
      ITransport::Free(trans);
    }
  }
}

void NaClExceptionCatcher(uint32_t id, int8_t sig, void *cookie) {
  Target* targ = static_cast<Target*>(cookie);

  /* Signal the target that we caught something */
  IPlatform::LogWarning("Caught signal %d on thread %Xh.\n", sig, id);
  targ->Signal(id, sig, true);
}

void NaClDebugThreadPrepDebugging(struct NaClAppThread *natp) throw() {
  UNREFERENCED_PARAMETER(natp);

  uint32_t id = IPlatform::GetCurrentThread();
  IThread* thread = IThread::Create(id, natp);
  g_nacl_debug_state->target_->SetMemoryBase(natp->nap->mem_start);
  g_nacl_debug_state->target_->TrackThread(thread);
}

void NaClDebugThreadStopDebugging(struct NaClAppThread *natp) throw() {
  UNREFERENCED_PARAMETER(natp);

  uint32_t id = IPlatform::GetCurrentThread();
  IThread* thread = IThread::Acquire(id);
  g_nacl_debug_state->target_->IgnoreThread(thread);
  IThread::Release(thread);  /* for Acquire */
  IThread::Release(thread);  /* for Create at NaClDebugThreadPrepDebugging */
}

int NaClDebugStart(void) throw() {
  NaClThread *thread = new NaClThread;

  if (NULL == thread) return false;

  /* Add a temp breakpoint. */
  struct NaClApp* app = g_nacl_debug_state->app_;
  if (0 != app->user_entry_pt) {
    g_nacl_debug_state->target_->AddTemporaryBreakpoint(app->user_entry_pt +
                                                        app->mem_start);
  }
  g_nacl_debug_state->target_->AddTemporaryBreakpoint(app->initial_entry_pt +
                                                      app->mem_start);

  NaClLog(LOG_WARNING, "nacl_debug(%d) : Debugging started.\n", __LINE__);
  IThread::SetExceptionCatch(NaClExceptionCatcher,
                             g_nacl_debug_state->target_);
  return NaClThreadCtor(thread, NaClStubThread, g_nacl_debug_state->target_,
                        NACL_KERN_STACK_SIZE);
}

void NaClDebugStop(int ErrCode) throw() {
  /*
   * We check if debugging is enabled since this check is the only
   * mechanism for allocating the state object.  We free the
   * resources but not the object itself.  Instead we mark it as
   * STOPPED to prevent it from getting recreated.
   */
  g_nacl_debug_state->target_->Exit(ErrCode);
  g_nacl_debug_state->status_ = NDS_STOPPED;
  try {
    NaClDebugStubFini();
  } DBG_CATCH_ALL
}

/*
 * This function is implemented for the service runtime.  The service runtime
 * declares the function so it does not need to be declared in our header.
 */
int NaClDebugInit(struct NaClApp *nap) {
  static bool initialised = 0;
  CHECK(!initialised && NULL == g_nacl_debug_state);
  initialised = 1;
  nap->debug_stub_callbacks = &debug_callbacks;
  NaClDebugStubInit();
  g_nacl_debug_state = new NaClDebugState();
  CHECK(g_nacl_debug_state->Init());
  g_nacl_debug_state->app_ = nap;
  NaClDebugStart();
  return 1;
}
