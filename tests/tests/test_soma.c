#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "soma.h"

void test_soma(void **state) {
    assert_int_equal(soma(5, 3), 8);
    assert_int_equal(soma(0, 0), 0);
    assert_int_equal(soma(-2, 2), 0);
    assert_int_equal(soma(-5, -3), -8);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_soma),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}