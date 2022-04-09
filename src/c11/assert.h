/*
 * Copyright 2022 Yonggang Luo
 * SPDX-License-Identifier: MIT
 *
 * C11 <assert.h> emulation library
 */

#ifndef C11_ASSERT_H_INCLUDED_
#define C11_ASSERT_H_INCLUDED_

#include <assert.h>

#include "c11_compat.h"

/*---------------------------- macros ---------------------------*/

#if defined(__cplusplus_version) && (__cplusplus_version >= 201103L)
   /* C++11 and upper already defined static_assert */
#  define __static_assert_predefined
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
   /* C11 static_assert macro already defined in assert.h */
#  define __static_assert_predefined
#elif defined(__cplusplus) && defined(_MSC_VER) && (_MSC_VER >= 1600)
#  define __static_assert_predefined
#endif

#if !defined(__static_assert_predefined) && !defined(static_assert)
#  define static_assert _Static_assert
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------- types ----------------------------*/

/*-------------------------- functions --------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* C11_ASSERT_H_INCLUDED_ */
