/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */

#ifndef __PP_REMOVE_BEGIN_PARENS_H
#define __PP_REMOVE_BEGIN_PARENS_H

#include <boost/preprocessor/control.hpp>
#include <preprocessor/is_begin_parens.h>

/**
 * @file
 * @brief Remove parentheses at the beginning.
 */

/**
 * @brief Remove all parentheses of the first element.
 * @param seq: the input argument such as a sequence.
 */
#define __PP_REMOVE_BEGIN_PARENS(seq)  /* Empty definition for Doxygen */
#undef __PP_REMOVE_BEGIN_PARENS

/** @cond */
#define __PP_REMOVE_BEGIN_PARENS_PRED(d, a) __PP_IS_BEGIN_PARENS(a)
#define __PP_REMOVE_BEGIN_PARENS_OP(d, a) __PP_REMOVE_BEGIN_PARENS_D a
#define __PP_REMOVE_BEGIN_PARENS_D(a) a
#define __PP_REMOVE_BEGIN_PARENS(a) BOOST_PP_WHILE(__PP_REMOVE_BEGIN_PARENS_PRED, __PP_REMOVE_BEGIN_PARENS_OP, a)
/** @endcond */

#endif /* __PP_REMOVE_BEGIN_PARENS_H */
