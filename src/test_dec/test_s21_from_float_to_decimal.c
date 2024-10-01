#include "testes.h"

START_TEST(test_s21_from_float_to_dec__ok1) {
  s21_decimal dec_check = {0};
  float num = 100.101;
  float tmp;
  s21_from_float_to_decimal(num, &dec_check);
  s21_from_decimal_to_float(dec_check, &tmp);
  ck_assert_float_eq(num, tmp);
}

START_TEST(test_s21_from_float_to_dec__ok2) {
  s21_decimal dec_check = {0};
  float num = -0.1023456;
  float tmp;
  s21_from_float_to_decimal(num, &dec_check);
  s21_from_decimal_to_float(dec_check, &tmp);
  ck_assert_float_eq(num, tmp);
}

Suite *suite_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_from_float_to_dec__ok1);
  tcase_add_test(tc_core, test_s21_from_float_to_dec__ok2);

  suite_add_tcase(s, tc_core);

  return s;
}
