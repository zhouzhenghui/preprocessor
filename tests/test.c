#include <boost/preprocessor/debug/assert.hpp>

#include "preprocessor/is_begin_parens.h"
#include "preprocessor/is_empty.h"
#include "preprocessor/is_null.h"
#include "preprocessor/is_sequence.h"
#include "preprocessor/is_void_cast.h"
#include "preprocessor/remove_begin_parens.h"
#include "preprocessor/remove_parens.h"
#include "preprocessor/variadic_size_or_zero.h"

/* __PP_IS_BEGIN_PARENS */
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS(()));
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS((a)));
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS((a)b));
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS((a)));
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS((a)(b)c));
#if BOOST_PP_VARIADICS
BOOST_PP_ASSERT(__PP_IS_BEGIN_PARENS((a, b)c));
#endif

/* __PP_IS_EMPTY */
BOOST_PP_ASSERT(__PP_IS_EMPTY());

/* __PP_IS_NULL */
BOOST_PP_ASSERT(__PP_IS_NULL(NULL));

/* __PP_IS_SEQUENCE */
BOOST_PP_ASSERT(__PP_IS_SEQUENCE());
BOOST_PP_ASSERT(__PP_IS_SEQUENCE(()));
BOOST_PP_ASSERT(__PP_IS_SEQUENCE((a)));
BOOST_PP_ASSERT(__PP_IS_SEQUENCE((a)(b)));
BOOST_PP_ASSERT(__PP_IS_SEQUENCE((a)(b)(c)));

/* __PP_IS_VOID_CAST */
BOOST_PP_ASSERT(__PP_IS_VOID_CAST((void *)a));
BOOST_PP_ASSERT(__PP_IS_VOID_CAST(((void *)a)));
BOOST_PP_ASSERT(__PP_IS_VOID_CAST((void *)(a)));

/* __PP_REMOVE_PARENS */
BOOST_PP_ASSERT(__PP_REMOVE_PARENS(1));
BOOST_PP_ASSERT(__PP_REMOVE_PARENS((1)));
BOOST_PP_ASSERT(__PP_REMOVE_PARENS(((1))));

/* __PP_REMOVE_BEGIN_PARENS */
BOOST_PP_ASSERT(__PP_REMOVE_BEGIN_PARENS(()1))
BOOST_PP_ASSERT(__PP_REMOVE_BEGIN_PARENS((1)))
BOOST_PP_ASSERT(__PP_REMOVE_BEGIN_PARENS(((1))))
BOOST_PP_ASSERT(__PP_REMOVE_BEGIN_PARENS(()(1)))
#define __PP_TEST_1(a) 1
BOOST_PP_ASSERT(BOOST_PP_CAT(__PP_TEST_, __PP_REMOVE_BEGIN_PARENS((1)(a))))

#if BOOST_PP_VARIADICS
/* __PP_VARIADIC_SIZE_OR_ZERO */
BOOST_PP_ASSERT(BOOST_PP_NOT(__PP_VARIADIC_SIZE_OR_ZERO()))
BOOST_PP_ASSERT(__PP_VARIADIC_SIZE_OR_ZERO(a))
BOOST_PP_ASSERT(__PP_VARIADIC_SIZE_OR_ZERO(()))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(__PP_VARIADIC_SIZE_OR_ZERO(a), 1))
BOOST_PP_ASSERT(BOOST_PP_EQUAL(__PP_VARIADIC_SIZE_OR_ZERO(a, b), 2))

BOOST_PP_ASSERT(BOOST_PP_NOT(__PP_VARIADIC_SIZE_OR_ZERO(__PP_REMOVE_PARENS(()))))
BOOST_PP_ASSERT(BOOST_PP_NOT(__PP_VARIADIC_SIZE_OR_ZERO(__PP_REMOVE_PARENS((())))))
#endif

#error "This message tells that all tests are successful"
