#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "subtracao.h"

void test_subtracao(void **state) {
    assert_int_equal(subtracao(5, 3), 2);
}

