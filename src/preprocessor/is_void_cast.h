/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */

#ifndef __PP_IS_VOID_CAST_H
#define __PP_IS_VOID_CAST_H

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/control.hpp>
#include <preprocessor/is_begin_parens.h>
#include <preprocessor/remove_begin_parens.h>
#include <preprocessor/remove_parens.h>

/**
 * @file
 * @brief  (void *) cast detect.
 */
 
 /**
 * @brief Test whether an argument has a (void *) prefix.
 * @param ref: the argument to test.
 * @return 1 if it begins with a void keyword, 0 otherwise.
 *
 * The parentheses outside are ignored.
 */
#define __PP_IS_VOID_CAST(ref)  /* Empty definition for Doxygen */
#undef __PP_IS_VOID_CAST

 /** @cond */
#define __PP_IS_VOID_CAST_0(ref) 0
#define __PP_IS_VOID_CAST_1(ref) __PP_IS_VOID_CAST_2(__PP_IS_VOID_CAST_D(__PP_IS_VOID_CAST_R ref))
#define __PP_IS_VOID_CAST_D(ref) __PP_IS_VOID_CAST_HELP(ref)
#define __PP_IS_VOID_CAST_R(ref) ref,
#define __PP_IS_VOID_CAST_SPLIT(ref, _) ref
#define __PP_IS_VOID_CAST_HELP __PP_IS_VOID_CAST_SPLIT
#define __PP_IS_VOID_CAST_2(ref) \
  BOOST_PP_IF(__PP_IS_BEGIN_PARENS(ref), __PP_IS_VOID_CAST_0, __PP_IS_VOID_CAST_3)(ref)
#define __PP_IS_VOID_CAST_3(ref) \
  BOOST_PP_SEQ_ELEM(1, (BOOST_PP_CAT(__PP_IS_VOID_CAST_DEF_, ref))(0))
#define __PP_IS_VOID_CAST_DEF_void )(1)(
#define __PP_IS_VOID_CAST(ref) \
  BOOST_PP_IF(__PP_IS_BEGIN_PARENS(__PP_REMOVE_PARENS(ref)), __PP_IS_VOID_CAST_1, __PP_IS_VOID_CAST_0)(__PP_REMOVE_PARENS(ref))
/** @endcond */

#endif  /* __PP_IS_VOID_CAST_H */
