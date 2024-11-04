#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "soma.h"

void test_soma(void **state) {
    assert_int_equal(soma(5, 3), 8);
}

