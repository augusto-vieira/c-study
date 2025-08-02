#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include "subtracao.h"
#include <cmocka.h>

void test_subtracao(void **state) { 
    assert_int_equal(subtracao(5, 3), 2);
    assert_int_equal(subtracao(3, 5), -2);
    assert_int_equal(subtracao(0, 0), 0);
    assert_int_equal(subtracao(-5, -3), -2);
    assert_int_equal(subtracao(-3, -5), 2); 
}

void test_subtracao3(void **state) {
    assert_int_equal(subtracao3(10, 3, 2), 5);
    assert_int_equal(subtracao3(0, 0, 0), 0);
    assert_int_equal(subtracao3(-5, -3, -2), 0);
    assert_int_equal(subtracao3(5, 10, 2), -7);
    assert_int_equal(subtracao3(3, 1, 5), -3);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_subtracao),
      cmocka_unit_test(test_subtracao3),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}