/*
 * Copyright 2022 Yonggang Luo
 * SPDX-License-Identifier: MIT
 *
 * C11 <threads.h> implementation
 */

#if defined(_WIN32) && !defined(__CYGWIN__)
#include "c11/threads_win32.h"
#elif defined(HAVE_PTHREAD)
#include "c11/threads_posix.h"
#endif
