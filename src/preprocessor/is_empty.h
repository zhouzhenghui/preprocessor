/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */

#ifndef __PP_IS_VARIADIC_EMPTY_H
#define __PP_IS_VARIADIC_EMPTY_H

#include <boost/preprocessor/variadic.hpp>
#include "is_begin_parens.h"
#include "remove_begin_parens.h"

/**
 * @file
 * @brief Empty input detect.
 */

/**
 * @brief Test whether the input is empty or not.
 * @param a: the input argument.
 *
 * If variadic macro is supported then the \p a can be any input,
 * else the argument \p a should be a single parameter.
 */

#define __PP_IS_EMPTY(a) /* Empty definition for Doxygen */
#undef __PP_IS_EMPTY

/** @cond */
#if BOOST_PP_VARIADICS
/*
 * variadic macro arguments empty detect
 * suggested by Jens Gustedt, see http://gustedt.wordpress.com/
 */
#  define __PP_HAS_COMMA(...) BOOST_PP_VARIADIC_ELEM(15, __VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)
#  define __PP_TRIGGER_PARENS(...) ,
#  define __PP_IS_EMPTY_CASE_0001 ,
#  define __PP_PASTE_5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#  define __PP_IS_EMPTY_HELPER(_0, _1, _2, _3) __PP_HAS_COMMA(__PP_PASTE_5(__PP_IS_EMPTY_CASE_, _0, _1, _2, _3))
#  define __PP_IS_EMPTY(...) __PP_IS_EMPTY_HELPER(__PP_HAS_COMMA(__VA_ARGS__) \
                                , __PP_HAS_COMMA(__PP_TRIGGER_PARENS __VA_ARGS__) \
                                , __PP_HAS_COMMA(__VA_ARGS__ ()) \
                                , __PP_HAS_COMMA(__PP_TRIGGER_PARENS __VA_ARGS__ ()))
#else
/*
 * a single macro argument empty detect
 * ported from variadic_macro_data in BOOST sandbox and chaos-pp project on sourceforge.net
 */
#  define __PP_IS_EMPTY_D(a) __PP_IS_BEGIN_PARENS(a)
#  define __PP_IS_EMPTY_NON_FUNCTION_C() ()
#  define __PP_IS_EMPTY(a) __PP_IS_EMPTY_D(__PP_IS_EMPTY_NON_FUNCTION_C __PP_REMOVE_BEGIN_PARENS(a) ())
#endif /* BOOST_PP_VARIADICS */
/** @endcond */

#endif /* __PP_IS_EMPTY_H */
