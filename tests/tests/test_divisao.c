#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "divisao.h"

void test_divisao(void **state) {
    assert_float_equal((double)divisao(5, 2), 2.5, 0.01);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_divisao),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}