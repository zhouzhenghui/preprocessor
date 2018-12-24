/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 *
 * ported from variadic_macro_data in BOOST sandbox and chaos-pp project on sourceforge.net.
 */

#ifndef __PP_IS_BEGIN_PARENS_H
#define __PP_IS_BEGIN_PARENS_H

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple.hpp>
#include <boost/preprocessor/variadic.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>

/**
 * @file
 * @brief Begin parentheses detect.
 */

/**
 * @brief Test whether the input begins with a set of parentheses.
 * @param seq: the input argument such as a sequence.
 *
 * If variadic macro is supported then the \p seq can be any input,
 * else the argument \p seq should be a single parameter.
 */

#define __PP_IS_BEGIN_PARENS(seq) /* Empty definition for Doxygen */
#undef __PP_IS_BEGIN_PARENS

/** @cond */
#if BOOST_PP_VARIADICS
# define __PP_IS_BEGIN_PARENS_CAT(a, ...) __PP_IS_BEGIN_PARENS_CAT_D(a, __VA_ARGS__)
# define __PP_IS_BEGIN_PARENS_CAT_D(a, ...) a ## __VA_ARGS__
# define __PP_IS_BEGIN_PARENS_SPLIT_0(a, ...) __PP_IS_BEGIN_PARENS_SPLIT_0_D(a, __VA_ARGS__)
# define __PP_IS_BEGIN_PARENS_SPLIT_0_D(a, ...) a
# define __PP_IS_BEGIN_PARENS_I(...) __PP_IS_BEGIN_PARENS_C __VA_ARGS__
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#   define __PP_IS_BEGIN_PARENS(...) \
  BOOST_PP_EXPAND(__PP_IS_BEGIN_PARENS_SPLIT_0 BOOST_PP_LPAREN() BOOST_PP_EXPAND(__PP_IS_BEGIN_PARENS_CAT(__PP_IS_BEGIN_PARENS_R_, BOOST_PP_EXPAND(__PP_IS_BEGIN_PARENS_I(__VA_ARGS__)))) BOOST_PP_RPAREN())
# define __PP_IS_BEGIN_PARENS_C(...) 1 1

# else /* BOOST_PP_VARIADICS or not*/

#   define __PP_IS_BEGIN_PARENS(...) \
  __PP_IS_BEGIN_PARENS_SPLIT_0(__PP_IS_BEGIN_PARENS_CAT(__PP_IS_BEGIN_PARENS_R_, __PP_IS_BEGIN_PARENS_I(__VA_ARGS__)))
# define __PP_IS_BEGIN_PARENS_C(...) 1
# endif
#else
# define __PP_IS_BEGIN_PARENS(a) BOOST_PP_TUPLE_ELEM(2, 0, (BOOST_PP_CAT(__PP_IS_BEGIN_PARENS_R_, __PP_IS_BEGIN_PARENS_C a)))
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#   define __PP_IS_BEGIN_PARENS_C(_) 1 1
# else
#   define __PP_IS_BEGIN_PARENS_C(_) 1
# endif
#endif /* BOOST_PP_VARIADICS */

#define __PP_IS_BEGIN_PARENS_R___PP_IS_BEGIN_PARENS_C 0,
#define __PP_IS_BEGIN_PARENS_R_1 1,
/** @endcond */

#endif /* __PP_IS_BEGIN_PARENS_H */
