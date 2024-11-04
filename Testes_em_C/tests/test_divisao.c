#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "divisao.h"

void test_divisao(void **state) {
    assert_float_equal(divisao(5, 2), 2.5, 0.01);
}

