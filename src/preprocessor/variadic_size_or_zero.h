/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com>
 */

#ifndef __PP_VARIADIC_SIZE_OR_ZERO_H
#define __PP_VARIADIC_SIZE_OR_ZERO_H

#include "is_empty.h"

/**
 * @file
 * @brief Arguments counting of variadic macro.
 */
 
 /**
  * @brief Count the number of arguments separated by comma.
  * @param a: any input of variadic macro.
  * @return the number of arguments, if the \p a is empty return 0.
  */
  #define __PP_VARIADIC_SIZE_OR_ZERO(a) /* Empty definition for Doxygen */
 #undef __PP_VARIADIC_SIZE_OR_ZERO
 
#if BOOST_PP_VARIADICS
# define __PP_VARIADIC_SIZE_OR_ZERO(...) \
  BOOST_PP_IF(__PP_IS_EMPTY(__VA_ARGS__), 0, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))
#endif

#endif
