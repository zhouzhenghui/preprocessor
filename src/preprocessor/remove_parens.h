/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */

#ifndef __PP_REMOVE_PARENS_H
#define __PP_REMOVE_PARENS_H

#include <boost/preprocessor/variadic.hpp>
#include <boost/preprocessor/control.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <preprocessor/is_empty.h>

/**
 * @file
 * @brief Take the element enclosed in parentheses.
 */

/**
 * @brief Remove the parentheses outside of an argument.
 * @param a: the argument may be surrounded by any number of parentheses.
 *
 * If variadic macro is supported then the \p a can be any input,
 * else the data inside should be a single element that doesn't contain comma.
 */
 #define __PP_REMOVE_PARENS(a) /* Empty definition for Doxygen */
 #undef __PP_REMOVE_PARENS
 
/** @cond */ 
#if BOOST_PP_VARIADICS
#  define __PP_IN_PARENS(...) __PP_IS_EMPTY(__PP_REMOVE_PARENS_ELEM __VA_ARGS__)
#  define __PP_REMOVE_PARENS_ELEM(...)
#  define __PP_REMOVE_PARENS_D(...) __VA_ARGS__
#else
#  define __PP_IN_PARENS(a) __PP_IS_EMPTY(__PP_REMOVE_PARENS_ELEM a)
#  define __PP_REMOVE_PARENS_ELEM(_)
#  define __PP_REMOVE_PARENS_D(a) a
#endif /* BOOST_PP_VARIADICS */

#define __PP_REMOVE_PARENS_PRED(d, a) __PP_IN_PARENS(__PP_REMOVE_PARENS_D a)
#define __PP_REMOVE_PARENS_OP(d, a) __PP_REMOVE_PARENS_D a
#define __PP_REMOVE_PARENS(a) BOOST_PP_EXPAND(__PP_REMOVE_PARENS_D BOOST_PP_WHILE(__PP_REMOVE_PARENS_PRED, __PP_REMOVE_PARENS_OP, (a)))
/** @endcond */

#endif /* __PP_REMOVE_PARENS_H */
