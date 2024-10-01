#include "testes.h"

START_TEST(test_decimal_to_int_ok1) {
  s21_decimal dec_check = {0};
  int num = 1;
  int tmp;
  s21_from_int_to_decimal(num, &dec_check);
  s21_from_decimal_to_int(dec_check, &tmp);
  ck_assert_int_eq(num, tmp);
}

START_TEST(test_decimal_to_int_not_ok2) {
  s21_decimal dec_check = {{0, 0, 1, 0}};
  int flag = 1;
  int num;
  ck_assert_int_eq(flag, s21_from_decimal_to_int(dec_check, &num));
}

Suite *suite_decimal_to_int(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_decimal_to_int_ok1);
  tcase_add_test(tc_core, test_decimal_to_int_not_ok2);

  suite_add_tcase(s, tc_core);

  return s;
}
