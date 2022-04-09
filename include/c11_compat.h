/* Copyright 2019 Intel Corporation */
/* SPDX-License-Identifier: MIT */

#include "no_extern_c.h"

#ifndef _C11_COMPAT_H_
#define _C11_COMPAT_H_

# ifdef _MSC_VER
#  include <crtdbg.h> /* For _STATIC_ASSERT */
#endif

#include "c99_compat.h"

#if !defined(_Static_assert)
#  if defined(__cplusplus_version) && (__cplusplus_version >= 201103L)
     /* C++11 and upper have no need of _Static_assert macro */
#  elif defined(_MSC_VER)
#    define _Static_assert(expr, ...) _STATIC_ASSERT(expr)
#  elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
     /* Assume other compilers always have keyword _Static_assert when support c11 */
#  else
     /* Also defined for cplusplus */
#    define _Static_assert(expr, ...) typedef char __static_assert_t[(expr) != 0]
#  endif
#endif /* _Static_assert */

#ifndef _Thread_local
#  if defined(_MSC_VER)
     /* MSVC not have keyword _Thread_local at all */
#    define _Thread_local __declspec(thread)
#  elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
     /* Assume other compilers always have keyword _Thread_local when support c11 */
#  elif defined(__GNUC__)
#    define _Thread_local __thread
#  else
     /* Leave _Thread_local undefined so that use of _Thread_local would not promote
      * to a non-thread-local global variable
      */
#  endif
#endif

#endif /* _C11_COMPAT_H_ */
