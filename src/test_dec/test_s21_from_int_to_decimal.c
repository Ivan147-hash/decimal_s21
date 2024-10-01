#include "testes.h"

START_TEST(test_from_int_to_decimal_ok1) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_check = {0};
  int num = 1;
  s21_from_int_to_decimal(num, &dec_check);
  ck_assert_int_eq(dec_check.bits[0], num);
}

START_TEST(test_from_int_to_decimal_ok2) {
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal dec_check = {0};
  int num = -2147483647;
  int tmp = 0;
  s21_from_int_to_decimal(num, &dec_check);
  s21_from_decimal_to_int(dec_check, &tmp);
  ck_assert_int_eq(tmp, num);
}

START_TEST(test_from_int_to_decimal_ok3) {
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal dec_check = {0};
  int num = 0;
  int tmp = 1;
  s21_from_int_to_decimal(num, &dec_check);
  s21_from_decimal_to_int(dec_check, &tmp);
  ck_assert_int_eq(tmp, num);
}

START_TEST(test_from_int_to_decimal_ok4) {
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal dec_check = {0};
  int num = 2147483647;
  int tmp = 0;
  s21_from_int_to_decimal(num, &dec_check);
  s21_from_decimal_to_int(dec_check, &tmp);
  ck_assert_int_eq(tmp, num);
}

START_TEST(test_from_int_to_decimal_ok5) {
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  s21_decimal dec_check = {0};
  int num = -1;
  int tmp = 0;
  s21_from_int_to_decimal(num, &dec_check);
  s21_from_decimal_to_int(dec_check, &tmp);
  ck_assert_int_eq(tmp, num);
}

// START_TEST(test_from_int_to_decimal_ok3) {
//     int number = -214748364;
//     // Converted the Int32 value -214748364 to the Decimal value -214748364.
//     s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok4) {
//     int number = -214748;
//     // Converted the Int32 value -214748 to the Decimal value -214748.
//     s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok5) {
//     int number = -1000;
//     // Converted the Int32 value -1000 to the Decimal value -1000.
//     s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok6) {
//     int number = -1;
//     // Converted the Int32 value -1 to the Decimal value -1.
//     s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok7) {
//     int number = 0;
//     // Converted the Int32 value 0 to the Decimal value 0.
//     s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok8) {
//     int number = 1;
//     // Converted the Int32 value 1 to the Decimal value 1.
//     s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok9) {
//     int number = 1000;
//     // Converted the Int32 value 1000 to the Decimal value 1000.
//     s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok10) {
//     int number = 214748;
//     // Converted the Int32 value 214748 to the Decimal value 214748.
//     s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok11) {
//     int number = 214748364;
//     // Converted the Int32 value 214748364 to the Decimal value 214748364.
//     s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok12) {
//     int number = 2147483646;
//     // Converted the Int32 value 2147483646 to the Decimal value 2147483646.
//     s21_decimal decimal_check = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

// START_TEST(test_from_int_to_decimal_ok13) {
//     int number = 2147483647;
//     // Converted the Int32 value 2147483647 to the Decimal value 2147483647.
//     s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

//     test_from_int_to_decimal(number, decimal_check);
// }

Suite *suite_int_to_decimal(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_int_to_decimal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_int_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok5);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok6);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok7);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok8);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok9);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok10);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok11);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok12);
  // tcase_add_test(tc_core, test_from_int_to_decimal_ok13);

  suite_add_tcase(s, tc_core);

  return s;
}
