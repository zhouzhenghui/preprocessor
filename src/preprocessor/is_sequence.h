/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */
 
#ifndef __PP_IS_SEQUENCE_H
#define __PP_IS_SEQUENCE_H

#include <boost/preprocessor/variadic.hpp>
#include <boost/preprocessor/control.hpp>
#include <boost/preprocessor/comparison.hpp>
#include <preprocessor/is_begin_parens.h>
#include <preprocessor/is_empty.h>

/**
 * @file
 * @brief  Boost PP sequence detect.
 */

/**
 * @brief Test whether the input is a Boost PP sequence.
 * @details A Boost PP sequence is a consecutive sets of parentheses, each with a single element of data. 
 * @param seq: the input argument can be a sequence.
 * @return 1 if it is a sequence, 0 otherwise.
 */
#define __PP_IS_SEQUENCE(seq)  /* Empty definition for Doxygen */
#undef __PP_IS_SEQUENCE

 /** @cond */
#if BOOST_PP_VARIADICS
# define __PP_IS_SEQUENCE_OP_D(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), BOOST_PP_EMPTY(), BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))
#else
# define __PP_IS_SEQUENCE_OP_D(a)
#endif

#define __PP_IS_SEQUENCE_PRED(d, a) __PP_IS_BEGIN_PARENS(a)
#define __PP_IS_SEQUENCE_OP(d, a) __PP_IS_SEQUENCE_OP_D a
#define __PP_IS_SEQUENCE(a) __PP_IS_EMPTY(BOOST_PP_WHILE(__PP_IS_SEQUENCE_PRED, __PP_IS_SEQUENCE_OP, a))
/** @endcond */

#endif /* __PP_IS_SEQUENCE_H */
