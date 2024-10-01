#include "testes.h"

s21_decimal max2 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};  //
s21_decimal middle2 = {{MAX_INT, MAX_INT, MAX_INT, 0}};
s21_decimal null2 = {{0, 0, 0, 0}};
s21_decimal null_minus2 = {{0, 0, 0, MINUS}};
s21_decimal middle_minus2 = {{MAX_INT, MAX_INT, MAX_INT, MINUS}};
s21_decimal max_minus2 = {{MAX_UINT, MAX_UINT, MAX_UINT, MINUS}};
s21_decimal middle_fractions2 = {{MAX_INT, MAX_INT, MAX_INT, EXPONENT_20}};
#define TEST_COMPARISON_TRUE 1
#define TEST_COMPARISON_FALSE 0

START_TEST(_is_greater) {
  ck_assert_int_eq(1, s21_is_greater(middle2, null2));
  ck_assert_int_eq(0, s21_is_greater(middle2, max2));
  ck_assert_int_eq(1, s21_is_greater(middle2, max_minus2));
  ck_assert_int_eq(1, s21_is_greater(middle_fractions2, middle_minus2));
  ck_assert_int_eq(0, s21_is_greater(middle_minus2, null2));
  ck_assert_int_eq(0, s21_is_greater(null_minus2, null2));
}
END_TEST

START_TEST(test_is_greater_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok82) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok84) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok85) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok86) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok87) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok88) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok89) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok90) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok91) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok92) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok93) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok94) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok95) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok96) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok97) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok98) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok99) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok100) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok101) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok102) {
  // -19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok103) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok104) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok105) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok106) {
  // 3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok107) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.2370474408201521914302817507
  s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok108) {
  // -3.2370474408201521914302817507
  s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok109) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok110) {
  // 858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok111) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -858826877820029649465.1465162
  s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok112) {
  // -858826877820029649465.1465162
  s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok114) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok118) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok120) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok122) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok124) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok126) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok128) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok130) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok132) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok134) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok136) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok138) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok140) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok142) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok144) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok146) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok148) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok150) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok152) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok154) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok156) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok158) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok160) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok162) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok164) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok166) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok168) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok169) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok170) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok171) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok172) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok173) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok174) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok175) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok176) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok177) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok178) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok179) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok180) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok181) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok182) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok183) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok184) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok185) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok186) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok187) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok188) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok189) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok190) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok191) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok192) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok193) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok194) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok195) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok196) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok197) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok198) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok199) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

START_TEST(test_is_greater_ok200) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
}

// START_TEST(test_is_greater_ok201) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok202) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok203) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok204) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok205) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok206) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok207) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok208) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok209) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok210) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok211) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok212) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok213) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok214) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok215) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok216) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok217) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok218) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok219) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok220) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok221) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok222) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok223) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok224) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok225) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok226) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok227) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok228) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok229) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok230) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok231) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok232) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok233) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok234) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok235) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok236) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok237) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok238) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok239) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok240) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok241) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok242) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok243) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok244) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok245) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok246) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok247) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok248) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok249) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok250) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok251) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok252) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok253) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok254) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok255) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok256) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok257) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok258) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok259) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok260) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok261) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok262) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok263) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok264) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok265) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok266) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok267) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok268) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok269) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok270) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok271) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok272) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok273) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok274) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok275) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok276) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok277) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok278) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok279) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok280) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok281) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok282) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok283) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok284) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok285) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok286) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok287) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok288) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok289) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok290) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok291) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok292) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok293) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok294) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok295) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok296) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok297) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok298) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok299) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok300) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1201) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1202) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1203) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1204) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1205) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1206) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1207) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1208) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1209) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1210) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1211) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1212) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1213) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1214) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1215) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1216) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1217) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1218) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1219) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1220) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1221) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1222) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1223) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1224) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1225) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1226) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1227) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1228) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1229) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1230) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1231) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1232) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1233) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1234) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1235) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1236) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1237) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1238) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1239) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1240) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1241) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1242) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1243) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1244) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1245) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1246) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1247) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1248) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1249) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1250) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1251) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1252) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1253) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1254) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1255) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1256) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1257) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1258) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1259) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1260) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1261) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1262) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1263) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1264) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1265) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1266) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1267) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1268) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1269) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1270) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1271) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1272) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1273) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1274) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1275) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1276) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1277) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1278) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1279) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1280) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1281) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1282) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1283) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1284) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1285) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1286) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1287) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1288) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1289) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1290) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1291) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1292) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1293) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1294) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1295) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1296) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1297) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1298) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1299) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1300) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1301) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1302) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1303) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1304) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1305) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1306) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1307) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1308) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1309) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1310) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1311) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1312) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1313) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1314) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1315) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1316) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1317) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1318) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1319) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1320) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1321) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1322) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1323) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1324) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1325) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1326) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1327) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1328) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1329) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1330) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1331) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1332) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1333) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1334) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1335) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1336) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1337) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1338) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1339) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1340) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1341) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1342) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1343) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1344) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1345) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1346) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1347) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1348) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1349) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1350) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1351) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1352) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1353) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1354) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1355) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1356) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1357) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1358) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1359) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1360) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1361) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1362) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1363) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1364) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1365) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1366) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1367) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1368) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1369) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1370) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1371) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1372) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1373) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1374) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1375) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1376) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1377) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1378) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1379) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1380) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1381) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1382) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1383) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1384) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1385) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1386) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1387) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1388) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1389) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1390) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1391) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1392) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1393) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1394) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1395) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1396) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1397) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1398) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1399) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1400) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1401) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1402) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1403) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1404) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1405) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1406) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1407) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1408) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1409) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1410) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1411) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1412) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1413) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1414) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1415) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1416) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1417) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1418) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1419) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1420) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1421) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1422) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1423) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1424) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1425) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1426) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1427) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1428) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1429) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1430) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1431) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1432) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1433) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1434) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1435) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1436) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1437) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1438) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1439) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1440) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1441) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1442) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1443) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1444) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1445) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1446) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1447) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1448) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1449) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1450) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1451) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1452) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1453) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1454) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1455) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1456) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1457) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1458) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1459) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1460) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1461) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1462) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1463) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1464) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1465) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1466) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1467) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1468) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1469) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1470) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1471) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1472) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1473) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1474) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1475) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1476) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1477) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1478) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1479) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1480) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1481) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1482) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1483) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1484) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1485) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1486) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1487) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1488) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1489) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1490) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1491) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1492) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1493) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1494) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1495) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1496) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1497) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1498) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1499) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok1500) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3601) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3602) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3603) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3604) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3605) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3606) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3607) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3608) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3609) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3610) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3611) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3612) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3613) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3614) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3615) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3616) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3617) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3618) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3619) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3620) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3621) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3622) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3623) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3624) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3625) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3626) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3627) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3628) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3629) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3630) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3631) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3632) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3633) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3634) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3635) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3636) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3637) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3638) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3639) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3640) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3641) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3642) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3643) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3644) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3645) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3646) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3647) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3648) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3649) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3650) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3651) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3652) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3653) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3654) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3655) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3656) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3657) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3658) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3659) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3660) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3661) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3662) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3663) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3664) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3665) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3666) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3667) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3668) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3669) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3670) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3671) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3672) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3673) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3674) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3675) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3676) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3677) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3678) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3679) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3680) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3681) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3682) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3683) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3684) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3685) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3686) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3687) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3688) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3689) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3690) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3691) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3692) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3693) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3694) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3695) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3696) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3697) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3698) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3699) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3700) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3701) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3702) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3703) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3704) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3705) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3706) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3707) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3708) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3709) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3710) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3711) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3712) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3713) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3714) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3715) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3716) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3717) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3718) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3719) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3720) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3721) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3722) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3723) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3724) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3725) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3726) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3727) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3728) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3729) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3730) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3731) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3732) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3733) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3734) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3735) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3736) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3737) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3738) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3739) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3740) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3741) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3742) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3743) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3744) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3745) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3746) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3747) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3748) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3749) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3750) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3751) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3752) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3753) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3754) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3755) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3756) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3757) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3758) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3759) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3760) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3761) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3762) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3763) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3764) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3765) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3766) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3767) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3768) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3769) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3770) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3771) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3772) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3773) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3774) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3775) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3776) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3777) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3778) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3779) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3780) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3781) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3782) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3783) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3784) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3785) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3786) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3787) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3788) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3789) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3790) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3791) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3792) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3793) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3794) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3795) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3796) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3797) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3798) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3799) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3800) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3801) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3802) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3803) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3804) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3805) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3806) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3807) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3808) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3809) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3810) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3811) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3812) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3813) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3814) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3815) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3816) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3817) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3818) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3819) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3820) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3821) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3822) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3823) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3824) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3825) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3826) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3827) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3828) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3829) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3830) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3831) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3832) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3833) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3834) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3835) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3836) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3837) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3838) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3839) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3840) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3841) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3842) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3843) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3844) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3845) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3846) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3847) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3848) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3849) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3850) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3851) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3852) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3853) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3854) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3855) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3856) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3857) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3858) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3859) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3860) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3861) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3862) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3863) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3864) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3865) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3866) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3867) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3868) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3869) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3870) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3871) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3872) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3873) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3874) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3875) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3876) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3877) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3878) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3879) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3880) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3881) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3882) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3883) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3884) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3885) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3886) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3887) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3888) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3889) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3890) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3891) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3892) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3893) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3894) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3895) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3896) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3897) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3898) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3899) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3900) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3901) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3902) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3903) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3904) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3905) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3906) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3907) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3908) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3909) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3910) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3911) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3912) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3913) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3914) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3915) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3916) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3917) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3918) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3919) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3920) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3921) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3922) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3923) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3924) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3925) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3926) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3927) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3928) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3929) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3930) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3931) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3932) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3933) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3934) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3935) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3936) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3937) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3938) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3939) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3940) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3941) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3942) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3943) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3944) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3945) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3946) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3947) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3948) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3949) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3950) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3951) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3952) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3953) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3954) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3955) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3956) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3957) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3958) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3959) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3960) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3961) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3962) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3963) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3964) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3965) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3966) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3967) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3968) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3969) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3970) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3971) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3972) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3973) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3974) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3975) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3976) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3977) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3978) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3979) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3980) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3981) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3982) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3983) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3984) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3985) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3986) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3987) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3988) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3989) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3990) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3991) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3992) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3993) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3994) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3995) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3996) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3997) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3998) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok3999) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok4000) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6001) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6002) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6003) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6004) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6005) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6006) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6007) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6008) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6009) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6010) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6011) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6012) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6013) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6014) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6015) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6016) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6017) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6018) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6019) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6020) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6021) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6022) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6023) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6024) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6025) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6026) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6027) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6028) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6029) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6030) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6031) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6032) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6033) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6034) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6035) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6036) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6037) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6038) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6039) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6040) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6041) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6042) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6043) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6044) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6045) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6046) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6047) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6048) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6049) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6050) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6051) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6052) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6053) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6054) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6055) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6056) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6057) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6058) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6059) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6060) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6061) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6062) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6063) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6064) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6065) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6066) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6067) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6068) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6069) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6070) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6071) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6072) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6073) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6074) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6075) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6076) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6077) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6078) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6079) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6080) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6081) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6082) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6083) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6084) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6085) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6086) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6087) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6088) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6089) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6090) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6091) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6092) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6093) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6094) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6095) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6096) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6097) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6098) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6099) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6100) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6101) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6102) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6103) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6104) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6105) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6106) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6107) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6108) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6109) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6110) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6111) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6112) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6113) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6114) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6115) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6116) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6117) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6118) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6119) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6120) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6121) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6122) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6123) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6124) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6125) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6126) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6127) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6128) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6129) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6130) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6131) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6132) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6133) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6134) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6135) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6136) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6137) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6138) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6139) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6140) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6141) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6142) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6143) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6144) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6145) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6146) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6147) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6148) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6149) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6150) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6151) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6152) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6153) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6154) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6155) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6156) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6157) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6158) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6159) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6160) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6161) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6162) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6163) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6164) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6165) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6166) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6167) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6168) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6169) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6170) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6171) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6172) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6173) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6174) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6175) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6176) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6177) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6178) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6179) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6180) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6181) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6182) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6183) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6184) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6185) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6186) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6187) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6188) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6189) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6190) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6191) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6192) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6193) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6194) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6195) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6196) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6197) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6198) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6199) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6200) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6201) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6202) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6203) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6204) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6205) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6206) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6207) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6208) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6209) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6210) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6211) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6212) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6213) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6214) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6215) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6216) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6217) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6218) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6219) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6220) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6221) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6222) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6223) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6224) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6225) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6226) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6227) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6228) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6229) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6230) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6231) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6232) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6233) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6234) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6235) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6236) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6237) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6238) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6239) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6240) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6241) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6242) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6243) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6244) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6245) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6246) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6247) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6248) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6249) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6250) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6251) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6252) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6253) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6254) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6255) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6256) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6257) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6258) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6259) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6260) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6261) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6262) {
//   // -19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80080000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6263) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 19290120297533996546.12653034
//   s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6264) {
//   // 19290120297533996546.12653034
//   s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6265) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6266) {
//   // 3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x1C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6267) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -3.2370474408201521914302817507
//   s21_decimal decimal2 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6268) {
//   // -3.2370474408201521914302817507
//   s21_decimal decimal1 = {{0xB219E4E3, 0xE34F18DD, 0x68983A95, 0x801C0000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6269) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // 858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6270) {
//   // 858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6271) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }

// START_TEST(test_is_greater_ok6272) {
//   // -858826877820029649465.1465162
//   s21_decimal decimal1 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   // -858826877820029649465.1465162
//   s21_decimal decimal2 = {{0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_greater(decimal1, decimal2));
// }
/////////////////////////////////////////////////////////////////////////////////////////

// START_TEST(greater_1) {
//   int error = 0;
//   float a = 1.2;
//   float b = 0.3;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_greater(a_dec, b_dec);
//   ck_assert_int_eq(res, 1);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(greater_2) {
//   int error = 0;
//   float a = -1.2;
//   float b = 0.3;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_greater(a_dec, b_dec);
//   ck_assert_int_eq(res, 0);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(greater_3) {
//   int error = 0;
//   float a = -1.2;
//   float b = -0.3;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_greater(a_dec, b_dec);
//   ck_assert_int_eq(res, 0);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(greater_4) {
//   int error = 0;
//   float a = 0;
//   float b = 0;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_greater(a_dec, b_dec);
//   ck_assert_int_eq(res, 0);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

Suite *suite_is_greater(void) {
  Suite *c = suite_create("s21_is_greater_cases");
  TCase *tc_core = tcase_create("s21_is_greater_tc");

  tcase_add_test(tc_core, _is_greater);
  // tcase_add_test(tc_core, greater_4);
  // tcase_add_test(tc_core, greater_3);
  // tcase_add_test(tc_core, greater_2);
  // tcase_add_test(tc_core, greater_1);
  tcase_add_test(tc_core, test_is_greater_ok1);
  tcase_add_test(tc_core, test_is_greater_ok2);
  tcase_add_test(tc_core, test_is_greater_ok3);
  tcase_add_test(tc_core, test_is_greater_ok4);
  tcase_add_test(tc_core, test_is_greater_ok5);
  tcase_add_test(tc_core, test_is_greater_ok6);
  tcase_add_test(tc_core, test_is_greater_ok7);
  tcase_add_test(tc_core, test_is_greater_ok8);
  tcase_add_test(tc_core, test_is_greater_ok9);
  tcase_add_test(tc_core, test_is_greater_ok10);
  tcase_add_test(tc_core, test_is_greater_ok11);
  tcase_add_test(tc_core, test_is_greater_ok12);
  tcase_add_test(tc_core, test_is_greater_ok13);
  tcase_add_test(tc_core, test_is_greater_ok14);
  tcase_add_test(tc_core, test_is_greater_ok15);
  tcase_add_test(tc_core, test_is_greater_ok16);
  tcase_add_test(tc_core, test_is_greater_ok17);
  tcase_add_test(tc_core, test_is_greater_ok18);
  tcase_add_test(tc_core, test_is_greater_ok19);
  tcase_add_test(tc_core, test_is_greater_ok20);
  tcase_add_test(tc_core, test_is_greater_ok21);
  tcase_add_test(tc_core, test_is_greater_ok22);
  tcase_add_test(tc_core, test_is_greater_ok23);
  tcase_add_test(tc_core, test_is_greater_ok24);
  tcase_add_test(tc_core, test_is_greater_ok25);
  tcase_add_test(tc_core, test_is_greater_ok26);
  tcase_add_test(tc_core, test_is_greater_ok27);
  tcase_add_test(tc_core, test_is_greater_ok28);
  tcase_add_test(tc_core, test_is_greater_ok29);
  tcase_add_test(tc_core, test_is_greater_ok30);
  tcase_add_test(tc_core, test_is_greater_ok31);
  tcase_add_test(tc_core, test_is_greater_ok32);
  tcase_add_test(tc_core, test_is_greater_ok33);
  tcase_add_test(tc_core, test_is_greater_ok34);
  tcase_add_test(tc_core, test_is_greater_ok35);
  tcase_add_test(tc_core, test_is_greater_ok36);
  tcase_add_test(tc_core, test_is_greater_ok37);
  tcase_add_test(tc_core, test_is_greater_ok38);
  tcase_add_test(tc_core, test_is_greater_ok39);
  tcase_add_test(tc_core, test_is_greater_ok40);
  tcase_add_test(tc_core, test_is_greater_ok41);
  tcase_add_test(tc_core, test_is_greater_ok42);
  tcase_add_test(tc_core, test_is_greater_ok43);
  tcase_add_test(tc_core, test_is_greater_ok44);
  tcase_add_test(tc_core, test_is_greater_ok45);
  tcase_add_test(tc_core, test_is_greater_ok46);
  tcase_add_test(tc_core, test_is_greater_ok47);
  tcase_add_test(tc_core, test_is_greater_ok48);
  tcase_add_test(tc_core, test_is_greater_ok49);
  tcase_add_test(tc_core, test_is_greater_ok50);
  tcase_add_test(tc_core, test_is_greater_ok51);
  tcase_add_test(tc_core, test_is_greater_ok52);
  tcase_add_test(tc_core, test_is_greater_ok53);
  tcase_add_test(tc_core, test_is_greater_ok54);
  tcase_add_test(tc_core, test_is_greater_ok55);
  tcase_add_test(tc_core, test_is_greater_ok56);
  tcase_add_test(tc_core, test_is_greater_ok57);
  tcase_add_test(tc_core, test_is_greater_ok58);
  tcase_add_test(tc_core, test_is_greater_ok59);
  tcase_add_test(tc_core, test_is_greater_ok60);
  tcase_add_test(tc_core, test_is_greater_ok61);
  tcase_add_test(tc_core, test_is_greater_ok62);
  tcase_add_test(tc_core, test_is_greater_ok63);
  tcase_add_test(tc_core, test_is_greater_ok64);
  tcase_add_test(tc_core, test_is_greater_ok65);
  tcase_add_test(tc_core, test_is_greater_ok66);
  tcase_add_test(tc_core, test_is_greater_ok67);
  tcase_add_test(tc_core, test_is_greater_ok68);
  tcase_add_test(tc_core, test_is_greater_ok69);
  tcase_add_test(tc_core, test_is_greater_ok70);
  tcase_add_test(tc_core, test_is_greater_ok71);
  tcase_add_test(tc_core, test_is_greater_ok72);
  tcase_add_test(tc_core, test_is_greater_ok73);
  tcase_add_test(tc_core, test_is_greater_ok74);
  tcase_add_test(tc_core, test_is_greater_ok75);
  tcase_add_test(tc_core, test_is_greater_ok76);
  tcase_add_test(tc_core, test_is_greater_ok77);
  tcase_add_test(tc_core, test_is_greater_ok78);
  tcase_add_test(tc_core, test_is_greater_ok79);
  tcase_add_test(tc_core, test_is_greater_ok80);
  tcase_add_test(tc_core, test_is_greater_ok81);
  tcase_add_test(tc_core, test_is_greater_ok82);
  tcase_add_test(tc_core, test_is_greater_ok83);
  tcase_add_test(tc_core, test_is_greater_ok84);
  tcase_add_test(tc_core, test_is_greater_ok85);
  tcase_add_test(tc_core, test_is_greater_ok86);
  tcase_add_test(tc_core, test_is_greater_ok87);
  tcase_add_test(tc_core, test_is_greater_ok88);
  tcase_add_test(tc_core, test_is_greater_ok89);
  tcase_add_test(tc_core, test_is_greater_ok90);
  tcase_add_test(tc_core, test_is_greater_ok91);
  tcase_add_test(tc_core, test_is_greater_ok92);
  tcase_add_test(tc_core, test_is_greater_ok93);
  tcase_add_test(tc_core, test_is_greater_ok94);
  tcase_add_test(tc_core, test_is_greater_ok95);
  tcase_add_test(tc_core, test_is_greater_ok96);
  tcase_add_test(tc_core, test_is_greater_ok97);
  tcase_add_test(tc_core, test_is_greater_ok98);
  tcase_add_test(tc_core, test_is_greater_ok99);
  tcase_add_test(tc_core, test_is_greater_ok100);
  tcase_add_test(tc_core, test_is_greater_ok101);
  tcase_add_test(tc_core, test_is_greater_ok102);
  tcase_add_test(tc_core, test_is_greater_ok103);
  tcase_add_test(tc_core, test_is_greater_ok104);
  tcase_add_test(tc_core, test_is_greater_ok105);
  tcase_add_test(tc_core, test_is_greater_ok106);
  tcase_add_test(tc_core, test_is_greater_ok107);
  tcase_add_test(tc_core, test_is_greater_ok108);
  tcase_add_test(tc_core, test_is_greater_ok109);
  tcase_add_test(tc_core, test_is_greater_ok110);
  tcase_add_test(tc_core, test_is_greater_ok111);
  tcase_add_test(tc_core, test_is_greater_ok112);
  tcase_add_test(tc_core, test_is_greater_ok113);
  tcase_add_test(tc_core, test_is_greater_ok114);
  tcase_add_test(tc_core, test_is_greater_ok115);
  tcase_add_test(tc_core, test_is_greater_ok116);
  tcase_add_test(tc_core, test_is_greater_ok117);
  tcase_add_test(tc_core, test_is_greater_ok118);
  tcase_add_test(tc_core, test_is_greater_ok119);
  tcase_add_test(tc_core, test_is_greater_ok120);
  tcase_add_test(tc_core, test_is_greater_ok121);
  tcase_add_test(tc_core, test_is_greater_ok122);
  tcase_add_test(tc_core, test_is_greater_ok123);
  tcase_add_test(tc_core, test_is_greater_ok124);
  tcase_add_test(tc_core, test_is_greater_ok125);
  tcase_add_test(tc_core, test_is_greater_ok126);
  tcase_add_test(tc_core, test_is_greater_ok127);
  tcase_add_test(tc_core, test_is_greater_ok128);
  tcase_add_test(tc_core, test_is_greater_ok129);
  tcase_add_test(tc_core, test_is_greater_ok130);
  tcase_add_test(tc_core, test_is_greater_ok131);
  tcase_add_test(tc_core, test_is_greater_ok132);
  tcase_add_test(tc_core, test_is_greater_ok133);
  tcase_add_test(tc_core, test_is_greater_ok134);
  tcase_add_test(tc_core, test_is_greater_ok135);
  tcase_add_test(tc_core, test_is_greater_ok136);
  tcase_add_test(tc_core, test_is_greater_ok137);
  tcase_add_test(tc_core, test_is_greater_ok138);
  tcase_add_test(tc_core, test_is_greater_ok139);
  tcase_add_test(tc_core, test_is_greater_ok140);
  tcase_add_test(tc_core, test_is_greater_ok141);
  tcase_add_test(tc_core, test_is_greater_ok142);
  tcase_add_test(tc_core, test_is_greater_ok143);
  tcase_add_test(tc_core, test_is_greater_ok144);
  tcase_add_test(tc_core, test_is_greater_ok145);
  tcase_add_test(tc_core, test_is_greater_ok146);
  tcase_add_test(tc_core, test_is_greater_ok147);
  tcase_add_test(tc_core, test_is_greater_ok148);
  tcase_add_test(tc_core, test_is_greater_ok149);
  tcase_add_test(tc_core, test_is_greater_ok150);
  tcase_add_test(tc_core, test_is_greater_ok151);
  tcase_add_test(tc_core, test_is_greater_ok152);
  tcase_add_test(tc_core, test_is_greater_ok153);
  tcase_add_test(tc_core, test_is_greater_ok154);
  tcase_add_test(tc_core, test_is_greater_ok155);
  tcase_add_test(tc_core, test_is_greater_ok156);
  tcase_add_test(tc_core, test_is_greater_ok157);
  tcase_add_test(tc_core, test_is_greater_ok158);
  tcase_add_test(tc_core, test_is_greater_ok159);
  tcase_add_test(tc_core, test_is_greater_ok160);
  tcase_add_test(tc_core, test_is_greater_ok161);
  tcase_add_test(tc_core, test_is_greater_ok162);
  tcase_add_test(tc_core, test_is_greater_ok163);
  tcase_add_test(tc_core, test_is_greater_ok164);
  tcase_add_test(tc_core, test_is_greater_ok165);
  tcase_add_test(tc_core, test_is_greater_ok166);
  tcase_add_test(tc_core, test_is_greater_ok167);
  tcase_add_test(tc_core, test_is_greater_ok168);
  tcase_add_test(tc_core, test_is_greater_ok169);
  tcase_add_test(tc_core, test_is_greater_ok170);
  tcase_add_test(tc_core, test_is_greater_ok171);
  tcase_add_test(tc_core, test_is_greater_ok172);
  tcase_add_test(tc_core, test_is_greater_ok173);
  tcase_add_test(tc_core, test_is_greater_ok174);
  tcase_add_test(tc_core, test_is_greater_ok175);
  tcase_add_test(tc_core, test_is_greater_ok176);
  tcase_add_test(tc_core, test_is_greater_ok177);
  tcase_add_test(tc_core, test_is_greater_ok178);
  tcase_add_test(tc_core, test_is_greater_ok179);
  tcase_add_test(tc_core, test_is_greater_ok180);
  tcase_add_test(tc_core, test_is_greater_ok181);
  tcase_add_test(tc_core, test_is_greater_ok182);
  tcase_add_test(tc_core, test_is_greater_ok183);
  tcase_add_test(tc_core, test_is_greater_ok184);
  tcase_add_test(tc_core, test_is_greater_ok185);
  tcase_add_test(tc_core, test_is_greater_ok186);
  tcase_add_test(tc_core, test_is_greater_ok187);
  tcase_add_test(tc_core, test_is_greater_ok188);
  tcase_add_test(tc_core, test_is_greater_ok189);
  tcase_add_test(tc_core, test_is_greater_ok190);
  tcase_add_test(tc_core, test_is_greater_ok191);
  tcase_add_test(tc_core, test_is_greater_ok192);
  tcase_add_test(tc_core, test_is_greater_ok193);
  tcase_add_test(tc_core, test_is_greater_ok194);
  tcase_add_test(tc_core, test_is_greater_ok195);
  tcase_add_test(tc_core, test_is_greater_ok196);
  tcase_add_test(tc_core, test_is_greater_ok197);
  tcase_add_test(tc_core, test_is_greater_ok198);
  tcase_add_test(tc_core, test_is_greater_ok199);
  tcase_add_test(tc_core, test_is_greater_ok200);
  // tcase_add_test(tc_core, test_is_greater_ok201);
  // tcase_add_test(tc_core, test_is_greater_ok202);
  // tcase_add_test(tc_core, test_is_greater_ok203);
  // tcase_add_test(tc_core, test_is_greater_ok204);
  // tcase_add_test(tc_core, test_is_greater_ok205);
  // tcase_add_test(tc_core, test_is_greater_ok206);
  // tcase_add_test(tc_core, test_is_greater_ok207);
  // tcase_add_test(tc_core, test_is_greater_ok208);
  // tcase_add_test(tc_core, test_is_greater_ok209);
  // tcase_add_test(tc_core, test_is_greater_ok210);
  // tcase_add_test(tc_core, test_is_greater_ok211);
  // tcase_add_test(tc_core, test_is_greater_ok212);
  // tcase_add_test(tc_core, test_is_greater_ok213);
  // tcase_add_test(tc_core, test_is_greater_ok214);
  // tcase_add_test(tc_core, test_is_greater_ok215);
  // tcase_add_test(tc_core, test_is_greater_ok216);
  // tcase_add_test(tc_core, test_is_greater_ok217);
  // tcase_add_test(tc_core, test_is_greater_ok218);
  // tcase_add_test(tc_core, test_is_greater_ok219);
  // tcase_add_test(tc_core, test_is_greater_ok220);
  // tcase_add_test(tc_core, test_is_greater_ok221);
  // tcase_add_test(tc_core, test_is_greater_ok222);
  // tcase_add_test(tc_core, test_is_greater_ok223);
  // tcase_add_test(tc_core, test_is_greater_ok224);
  // tcase_add_test(tc_core, test_is_greater_ok225);
  // tcase_add_test(tc_core, test_is_greater_ok226);
  // tcase_add_test(tc_core, test_is_greater_ok227);
  // tcase_add_test(tc_core, test_is_greater_ok228);
  // tcase_add_test(tc_core, test_is_greater_ok229);
  // tcase_add_test(tc_core, test_is_greater_ok230);
  // tcase_add_test(tc_core, test_is_greater_ok231);
  // tcase_add_test(tc_core, test_is_greater_ok232);
  // tcase_add_test(tc_core, test_is_greater_ok233);
  // tcase_add_test(tc_core, test_is_greater_ok234);
  // tcase_add_test(tc_core, test_is_greater_ok235);
  // tcase_add_test(tc_core, test_is_greater_ok236);
  // tcase_add_test(tc_core, test_is_greater_ok237);
  // tcase_add_test(tc_core, test_is_greater_ok238);
  // tcase_add_test(tc_core, test_is_greater_ok239);
  // tcase_add_test(tc_core, test_is_greater_ok240);
  // tcase_add_test(tc_core, test_is_greater_ok241);
  // tcase_add_test(tc_core, test_is_greater_ok242);
  // tcase_add_test(tc_core, test_is_greater_ok243);
  // tcase_add_test(tc_core, test_is_greater_ok244);
  // tcase_add_test(tc_core, test_is_greater_ok245);
  // tcase_add_test(tc_core, test_is_greater_ok246);
  // tcase_add_test(tc_core, test_is_greater_ok247);
  // tcase_add_test(tc_core, test_is_greater_ok248);
  // tcase_add_test(tc_core, test_is_greater_ok249);
  // tcase_add_test(tc_core, test_is_greater_ok250);
  // tcase_add_test(tc_core, test_is_greater_ok251);
  // tcase_add_test(tc_core, test_is_greater_ok252);
  // tcase_add_test(tc_core, test_is_greater_ok253);
  // tcase_add_test(tc_core, test_is_greater_ok254);
  // tcase_add_test(tc_core, test_is_greater_ok255);
  // tcase_add_test(tc_core, test_is_greater_ok256);
  // tcase_add_test(tc_core, test_is_greater_ok257);
  // tcase_add_test(tc_core, test_is_greater_ok258);
  // tcase_add_test(tc_core, test_is_greater_ok259);
  // tcase_add_test(tc_core, test_is_greater_ok260);
  // tcase_add_test(tc_core, test_is_greater_ok261);
  // tcase_add_test(tc_core, test_is_greater_ok262);
  // tcase_add_test(tc_core, test_is_greater_ok263);
  // tcase_add_test(tc_core, test_is_greater_ok264);
  // tcase_add_test(tc_core, test_is_greater_ok265);
  // tcase_add_test(tc_core, test_is_greater_ok266);
  // tcase_add_test(tc_core, test_is_greater_ok267);
  // tcase_add_test(tc_core, test_is_greater_ok268);
  // tcase_add_test(tc_core, test_is_greater_ok269);
  // tcase_add_test(tc_core, test_is_greater_ok270);
  // tcase_add_test(tc_core, test_is_greater_ok271);
  // tcase_add_test(tc_core, test_is_greater_ok272);
  // tcase_add_test(tc_core, test_is_greater_ok273);
  // tcase_add_test(tc_core, test_is_greater_ok274);
  // tcase_add_test(tc_core, test_is_greater_ok275);
  // tcase_add_test(tc_core, test_is_greater_ok276);
  // tcase_add_test(tc_core, test_is_greater_ok277);
  // tcase_add_test(tc_core, test_is_greater_ok278);
  // tcase_add_test(tc_core, test_is_greater_ok279);
  // tcase_add_test(tc_core, test_is_greater_ok280);
  // tcase_add_test(tc_core, test_is_greater_ok281);
  // tcase_add_test(tc_core, test_is_greater_ok282);
  // tcase_add_test(tc_core, test_is_greater_ok283);
  // tcase_add_test(tc_core, test_is_greater_ok284);
  // tcase_add_test(tc_core, test_is_greater_ok285);
  // tcase_add_test(tc_core, test_is_greater_ok286);
  // tcase_add_test(tc_core, test_is_greater_ok287);
  // tcase_add_test(tc_core, test_is_greater_ok288);
  // tcase_add_test(tc_core, test_is_greater_ok289);
  // tcase_add_test(tc_core, test_is_greater_ok290);
  // tcase_add_test(tc_core, test_is_greater_ok291);
  // tcase_add_test(tc_core, test_is_greater_ok292);
  // tcase_add_test(tc_core, test_is_greater_ok293);
  // tcase_add_test(tc_core, test_is_greater_ok294);
  // tcase_add_test(tc_core, test_is_greater_ok295);
  // tcase_add_test(tc_core, test_is_greater_ok296);
  // tcase_add_test(tc_core, test_is_greater_ok297);
  // tcase_add_test(tc_core, test_is_greater_ok298);
  // tcase_add_test(tc_core, test_is_greater_ok299);
  // tcase_add_test(tc_core, test_is_greater_ok300);
  // tcase_add_test(tc_core, test_is_greater_ok1201);
  // tcase_add_test(tc_core, test_is_greater_ok1202);
  // tcase_add_test(tc_core, test_is_greater_ok1203);
  // tcase_add_test(tc_core, test_is_greater_ok1204);
  // tcase_add_test(tc_core, test_is_greater_ok1205);
  // tcase_add_test(tc_core, test_is_greater_ok1206);
  // tcase_add_test(tc_core, test_is_greater_ok1207);
  // tcase_add_test(tc_core, test_is_greater_ok1208);
  // tcase_add_test(tc_core, test_is_greater_ok1209);
  // tcase_add_test(tc_core, test_is_greater_ok1210);
  // tcase_add_test(tc_core, test_is_greater_ok1211);
  // tcase_add_test(tc_core, test_is_greater_ok1212);
  // tcase_add_test(tc_core, test_is_greater_ok1213);
  // tcase_add_test(tc_core, test_is_greater_ok1214);
  // tcase_add_test(tc_core, test_is_greater_ok1215);
  // tcase_add_test(tc_core, test_is_greater_ok1216);
  // tcase_add_test(tc_core, test_is_greater_ok1217);
  // tcase_add_test(tc_core, test_is_greater_ok1218);
  // tcase_add_test(tc_core, test_is_greater_ok1219);
  // tcase_add_test(tc_core, test_is_greater_ok1220);
  // tcase_add_test(tc_core, test_is_greater_ok1221);
  // tcase_add_test(tc_core, test_is_greater_ok1222);
  // tcase_add_test(tc_core, test_is_greater_ok1223);
  // tcase_add_test(tc_core, test_is_greater_ok1224);
  // tcase_add_test(tc_core, test_is_greater_ok1225);
  // tcase_add_test(tc_core, test_is_greater_ok1226);
  // tcase_add_test(tc_core, test_is_greater_ok1227);
  // tcase_add_test(tc_core, test_is_greater_ok1228);
  // tcase_add_test(tc_core, test_is_greater_ok1229);
  // tcase_add_test(tc_core, test_is_greater_ok1230);
  // tcase_add_test(tc_core, test_is_greater_ok1231);
  // tcase_add_test(tc_core, test_is_greater_ok1232);
  // tcase_add_test(tc_core, test_is_greater_ok1233);
  // tcase_add_test(tc_core, test_is_greater_ok1234);
  // tcase_add_test(tc_core, test_is_greater_ok1235);
  // tcase_add_test(tc_core, test_is_greater_ok1236);
  // tcase_add_test(tc_core, test_is_greater_ok1237);
  // tcase_add_test(tc_core, test_is_greater_ok1238);
  // tcase_add_test(tc_core, test_is_greater_ok1239);
  // tcase_add_test(tc_core, test_is_greater_ok1240);
  // tcase_add_test(tc_core, test_is_greater_ok1241);
  // tcase_add_test(tc_core, test_is_greater_ok1242);
  // tcase_add_test(tc_core, test_is_greater_ok1243);
  // tcase_add_test(tc_core, test_is_greater_ok1244);
  // tcase_add_test(tc_core, test_is_greater_ok1245);
  // tcase_add_test(tc_core, test_is_greater_ok1246);
  // tcase_add_test(tc_core, test_is_greater_ok1247);
  // tcase_add_test(tc_core, test_is_greater_ok1248);
  // tcase_add_test(tc_core, test_is_greater_ok1249);
  // tcase_add_test(tc_core, test_is_greater_ok1250);
  // tcase_add_test(tc_core, test_is_greater_ok1251);
  // tcase_add_test(tc_core, test_is_greater_ok1252);
  // tcase_add_test(tc_core, test_is_greater_ok1253);
  // tcase_add_test(tc_core, test_is_greater_ok1254);
  // tcase_add_test(tc_core, test_is_greater_ok1255);
  // tcase_add_test(tc_core, test_is_greater_ok1256);
  // tcase_add_test(tc_core, test_is_greater_ok1257);
  // tcase_add_test(tc_core, test_is_greater_ok1258);
  // tcase_add_test(tc_core, test_is_greater_ok1259);
  // tcase_add_test(tc_core, test_is_greater_ok1260);
  // tcase_add_test(tc_core, test_is_greater_ok1261);
  // tcase_add_test(tc_core, test_is_greater_ok1262);
  // tcase_add_test(tc_core, test_is_greater_ok1263);
  // tcase_add_test(tc_core, test_is_greater_ok1264);
  // tcase_add_test(tc_core, test_is_greater_ok1265);
  // tcase_add_test(tc_core, test_is_greater_ok1266);
  // tcase_add_test(tc_core, test_is_greater_ok1267);
  // tcase_add_test(tc_core, test_is_greater_ok1268);
  // tcase_add_test(tc_core, test_is_greater_ok1269);
  // tcase_add_test(tc_core, test_is_greater_ok1270);
  // tcase_add_test(tc_core, test_is_greater_ok1271);
  // tcase_add_test(tc_core, test_is_greater_ok1272);
  // tcase_add_test(tc_core, test_is_greater_ok1273);
  // tcase_add_test(tc_core, test_is_greater_ok1274);
  // tcase_add_test(tc_core, test_is_greater_ok1275);
  // tcase_add_test(tc_core, test_is_greater_ok1276);
  // tcase_add_test(tc_core, test_is_greater_ok1277);
  // tcase_add_test(tc_core, test_is_greater_ok1278);
  // tcase_add_test(tc_core, test_is_greater_ok1279);
  // tcase_add_test(tc_core, test_is_greater_ok1280);
  // tcase_add_test(tc_core, test_is_greater_ok1281);
  // tcase_add_test(tc_core, test_is_greater_ok1282);
  // tcase_add_test(tc_core, test_is_greater_ok1283);
  // tcase_add_test(tc_core, test_is_greater_ok1284);
  // tcase_add_test(tc_core, test_is_greater_ok1285);
  // tcase_add_test(tc_core, test_is_greater_ok1286);
  // tcase_add_test(tc_core, test_is_greater_ok1287);
  // tcase_add_test(tc_core, test_is_greater_ok1288);
  // tcase_add_test(tc_core, test_is_greater_ok1289);
  // tcase_add_test(tc_core, test_is_greater_ok1290);
  // tcase_add_test(tc_core, test_is_greater_ok1291);
  // tcase_add_test(tc_core, test_is_greater_ok1292);
  // tcase_add_test(tc_core, test_is_greater_ok1293);
  // tcase_add_test(tc_core, test_is_greater_ok1294);
  // tcase_add_test(tc_core, test_is_greater_ok1295);
  // tcase_add_test(tc_core, test_is_greater_ok1296);
  // tcase_add_test(tc_core, test_is_greater_ok1297);
  // tcase_add_test(tc_core, test_is_greater_ok1298);
  // tcase_add_test(tc_core, test_is_greater_ok1299);
  // tcase_add_test(tc_core, test_is_greater_ok1300);
  // tcase_add_test(tc_core, test_is_greater_ok1301);
  // tcase_add_test(tc_core, test_is_greater_ok1302);
  // tcase_add_test(tc_core, test_is_greater_ok1303);
  // tcase_add_test(tc_core, test_is_greater_ok1304);
  // tcase_add_test(tc_core, test_is_greater_ok1305);
  // tcase_add_test(tc_core, test_is_greater_ok1306);
  // tcase_add_test(tc_core, test_is_greater_ok1307);
  // tcase_add_test(tc_core, test_is_greater_ok1308);
  // tcase_add_test(tc_core, test_is_greater_ok1309);
  // tcase_add_test(tc_core, test_is_greater_ok1310);
  // tcase_add_test(tc_core, test_is_greater_ok1311);
  // tcase_add_test(tc_core, test_is_greater_ok1312);
  // tcase_add_test(tc_core, test_is_greater_ok1313);
  // tcase_add_test(tc_core, test_is_greater_ok1314);
  // tcase_add_test(tc_core, test_is_greater_ok1315);
  // tcase_add_test(tc_core, test_is_greater_ok1316);
  // tcase_add_test(tc_core, test_is_greater_ok1317);
  // tcase_add_test(tc_core, test_is_greater_ok1318);
  // tcase_add_test(tc_core, test_is_greater_ok1319);
  // tcase_add_test(tc_core, test_is_greater_ok1320);
  // tcase_add_test(tc_core, test_is_greater_ok1321);
  // tcase_add_test(tc_core, test_is_greater_ok1322);
  // tcase_add_test(tc_core, test_is_greater_ok1323);
  // tcase_add_test(tc_core, test_is_greater_ok1324);
  // tcase_add_test(tc_core, test_is_greater_ok1325);
  // tcase_add_test(tc_core, test_is_greater_ok1326);
  // tcase_add_test(tc_core, test_is_greater_ok1327);
  // tcase_add_test(tc_core, test_is_greater_ok1328);
  // tcase_add_test(tc_core, test_is_greater_ok1329);
  // tcase_add_test(tc_core, test_is_greater_ok1330);
  // tcase_add_test(tc_core, test_is_greater_ok1331);
  // tcase_add_test(tc_core, test_is_greater_ok1332);
  // tcase_add_test(tc_core, test_is_greater_ok1333);
  // tcase_add_test(tc_core, test_is_greater_ok1334);
  // tcase_add_test(tc_core, test_is_greater_ok1335);
  // tcase_add_test(tc_core, test_is_greater_ok1336);
  // tcase_add_test(tc_core, test_is_greater_ok1337);
  // tcase_add_test(tc_core, test_is_greater_ok1338);
  // tcase_add_test(tc_core, test_is_greater_ok1339);
  // tcase_add_test(tc_core, test_is_greater_ok1340);
  // tcase_add_test(tc_core, test_is_greater_ok1341);
  // tcase_add_test(tc_core, test_is_greater_ok1342);
  // tcase_add_test(tc_core, test_is_greater_ok1343);
  // tcase_add_test(tc_core, test_is_greater_ok1344);
  // tcase_add_test(tc_core, test_is_greater_ok1345);
  // tcase_add_test(tc_core, test_is_greater_ok1346);
  // tcase_add_test(tc_core, test_is_greater_ok1347);
  // tcase_add_test(tc_core, test_is_greater_ok1348);
  // tcase_add_test(tc_core, test_is_greater_ok1349);
  // tcase_add_test(tc_core, test_is_greater_ok1350);
  // tcase_add_test(tc_core, test_is_greater_ok1351);
  // tcase_add_test(tc_core, test_is_greater_ok1352);
  // tcase_add_test(tc_core, test_is_greater_ok1353);
  // tcase_add_test(tc_core, test_is_greater_ok1354);
  // tcase_add_test(tc_core, test_is_greater_ok1355);
  // tcase_add_test(tc_core, test_is_greater_ok1356);
  // tcase_add_test(tc_core, test_is_greater_ok1357);
  // tcase_add_test(tc_core, test_is_greater_ok1358);
  // tcase_add_test(tc_core, test_is_greater_ok1359);
  // tcase_add_test(tc_core, test_is_greater_ok1360);
  // tcase_add_test(tc_core, test_is_greater_ok1361);
  // tcase_add_test(tc_core, test_is_greater_ok1362);
  // tcase_add_test(tc_core, test_is_greater_ok1363);
  // tcase_add_test(tc_core, test_is_greater_ok1364);
  // tcase_add_test(tc_core, test_is_greater_ok1365);
  // tcase_add_test(tc_core, test_is_greater_ok1366);
  // tcase_add_test(tc_core, test_is_greater_ok1367);
  // tcase_add_test(tc_core, test_is_greater_ok1368);
  // tcase_add_test(tc_core, test_is_greater_ok1369);
  // tcase_add_test(tc_core, test_is_greater_ok1370);
  // tcase_add_test(tc_core, test_is_greater_ok1371);
  // tcase_add_test(tc_core, test_is_greater_ok1372);
  // tcase_add_test(tc_core, test_is_greater_ok1373);
  // tcase_add_test(tc_core, test_is_greater_ok1374);
  // tcase_add_test(tc_core, test_is_greater_ok1375);
  // tcase_add_test(tc_core, test_is_greater_ok1376);
  // tcase_add_test(tc_core, test_is_greater_ok1377);
  // tcase_add_test(tc_core, test_is_greater_ok1378);
  // tcase_add_test(tc_core, test_is_greater_ok1379);
  // tcase_add_test(tc_core, test_is_greater_ok1380);
  // tcase_add_test(tc_core, test_is_greater_ok1381);
  // tcase_add_test(tc_core, test_is_greater_ok1382);
  // tcase_add_test(tc_core, test_is_greater_ok1383);
  // tcase_add_test(tc_core, test_is_greater_ok1384);
  // tcase_add_test(tc_core, test_is_greater_ok1385);
  // tcase_add_test(tc_core, test_is_greater_ok1386);
  // tcase_add_test(tc_core, test_is_greater_ok1387);
  // tcase_add_test(tc_core, test_is_greater_ok1388);
  // tcase_add_test(tc_core, test_is_greater_ok1389);
  // tcase_add_test(tc_core, test_is_greater_ok1390);
  // tcase_add_test(tc_core, test_is_greater_ok1391);
  // tcase_add_test(tc_core, test_is_greater_ok1392);
  // tcase_add_test(tc_core, test_is_greater_ok1393);
  // tcase_add_test(tc_core, test_is_greater_ok1394);
  // tcase_add_test(tc_core, test_is_greater_ok1395);
  // tcase_add_test(tc_core, test_is_greater_ok1396);
  // tcase_add_test(tc_core, test_is_greater_ok1397);
  // tcase_add_test(tc_core, test_is_greater_ok1398);
  // tcase_add_test(tc_core, test_is_greater_ok1399);
  // tcase_add_test(tc_core, test_is_greater_ok1400);
  // tcase_add_test(tc_core, test_is_greater_ok1401);
  // tcase_add_test(tc_core, test_is_greater_ok1402);
  // tcase_add_test(tc_core, test_is_greater_ok1403);
  // tcase_add_test(tc_core, test_is_greater_ok1404);
  // tcase_add_test(tc_core, test_is_greater_ok1405);
  // tcase_add_test(tc_core, test_is_greater_ok1406);
  // tcase_add_test(tc_core, test_is_greater_ok1407);
  // tcase_add_test(tc_core, test_is_greater_ok1408);
  // tcase_add_test(tc_core, test_is_greater_ok1409);
  // tcase_add_test(tc_core, test_is_greater_ok1410);
  // tcase_add_test(tc_core, test_is_greater_ok1411);
  // tcase_add_test(tc_core, test_is_greater_ok1412);
  // tcase_add_test(tc_core, test_is_greater_ok1413);
  // tcase_add_test(tc_core, test_is_greater_ok1414);
  // tcase_add_test(tc_core, test_is_greater_ok1415);
  // tcase_add_test(tc_core, test_is_greater_ok1416);
  // tcase_add_test(tc_core, test_is_greater_ok1417);
  // tcase_add_test(tc_core, test_is_greater_ok1418);
  // tcase_add_test(tc_core, test_is_greater_ok1419);
  // tcase_add_test(tc_core, test_is_greater_ok1420);
  // tcase_add_test(tc_core, test_is_greater_ok1421);
  // tcase_add_test(tc_core, test_is_greater_ok1422);
  // tcase_add_test(tc_core, test_is_greater_ok1423);
  // tcase_add_test(tc_core, test_is_greater_ok1424);
  // tcase_add_test(tc_core, test_is_greater_ok1425);
  // tcase_add_test(tc_core, test_is_greater_ok1426);
  // tcase_add_test(tc_core, test_is_greater_ok1427);
  // tcase_add_test(tc_core, test_is_greater_ok1428);
  // tcase_add_test(tc_core, test_is_greater_ok1429);
  // tcase_add_test(tc_core, test_is_greater_ok1430);
  // tcase_add_test(tc_core, test_is_greater_ok1431);
  // tcase_add_test(tc_core, test_is_greater_ok1432);
  // tcase_add_test(tc_core, test_is_greater_ok1433);
  // tcase_add_test(tc_core, test_is_greater_ok1434);
  // tcase_add_test(tc_core, test_is_greater_ok1435);
  // tcase_add_test(tc_core, test_is_greater_ok1436);
  // tcase_add_test(tc_core, test_is_greater_ok1437);
  // tcase_add_test(tc_core, test_is_greater_ok1438);
  // tcase_add_test(tc_core, test_is_greater_ok1439);
  // tcase_add_test(tc_core, test_is_greater_ok1440);
  // tcase_add_test(tc_core, test_is_greater_ok1441);
  // tcase_add_test(tc_core, test_is_greater_ok1442);
  // tcase_add_test(tc_core, test_is_greater_ok1443);
  // tcase_add_test(tc_core, test_is_greater_ok1444);
  // tcase_add_test(tc_core, test_is_greater_ok1445);
  // tcase_add_test(tc_core, test_is_greater_ok1446);
  // tcase_add_test(tc_core, test_is_greater_ok1447);
  // tcase_add_test(tc_core, test_is_greater_ok1448);
  // tcase_add_test(tc_core, test_is_greater_ok1449);
  // tcase_add_test(tc_core, test_is_greater_ok1450);
  // tcase_add_test(tc_core, test_is_greater_ok1451);
  // tcase_add_test(tc_core, test_is_greater_ok1452);
  // tcase_add_test(tc_core, test_is_greater_ok1453);
  // tcase_add_test(tc_core, test_is_greater_ok1454);
  // tcase_add_test(tc_core, test_is_greater_ok1455);
  // tcase_add_test(tc_core, test_is_greater_ok1456);
  // tcase_add_test(tc_core, test_is_greater_ok1457);
  // tcase_add_test(tc_core, test_is_greater_ok1458);
  // tcase_add_test(tc_core, test_is_greater_ok1459);
  // tcase_add_test(tc_core, test_is_greater_ok1460);
  // tcase_add_test(tc_core, test_is_greater_ok1461);
  // tcase_add_test(tc_core, test_is_greater_ok1462);
  // tcase_add_test(tc_core, test_is_greater_ok1463);
  // tcase_add_test(tc_core, test_is_greater_ok1464);
  // tcase_add_test(tc_core, test_is_greater_ok1465);
  // tcase_add_test(tc_core, test_is_greater_ok1466);
  // tcase_add_test(tc_core, test_is_greater_ok1467);
  // tcase_add_test(tc_core, test_is_greater_ok1468);
  // tcase_add_test(tc_core, test_is_greater_ok1469);
  // tcase_add_test(tc_core, test_is_greater_ok1470);
  // tcase_add_test(tc_core, test_is_greater_ok1471);
  // tcase_add_test(tc_core, test_is_greater_ok1472);
  // tcase_add_test(tc_core, test_is_greater_ok1473);
  // tcase_add_test(tc_core, test_is_greater_ok1474);
  // tcase_add_test(tc_core, test_is_greater_ok1475);
  // tcase_add_test(tc_core, test_is_greater_ok1476);
  // tcase_add_test(tc_core, test_is_greater_ok1477);
  // tcase_add_test(tc_core, test_is_greater_ok1478);
  // tcase_add_test(tc_core, test_is_greater_ok1479);
  // tcase_add_test(tc_core, test_is_greater_ok1480);
  // tcase_add_test(tc_core, test_is_greater_ok1481);
  // tcase_add_test(tc_core, test_is_greater_ok1482);
  // tcase_add_test(tc_core, test_is_greater_ok1483);
  // tcase_add_test(tc_core, test_is_greater_ok1484);
  // tcase_add_test(tc_core, test_is_greater_ok1485);
  // tcase_add_test(tc_core, test_is_greater_ok1486);
  // tcase_add_test(tc_core, test_is_greater_ok1487);
  // tcase_add_test(tc_core, test_is_greater_ok1488);
  // tcase_add_test(tc_core, test_is_greater_ok1489);
  // tcase_add_test(tc_core, test_is_greater_ok1490);
  // tcase_add_test(tc_core, test_is_greater_ok1491);
  // tcase_add_test(tc_core, test_is_greater_ok1492);
  // tcase_add_test(tc_core, test_is_greater_ok1493);
  // tcase_add_test(tc_core, test_is_greater_ok1494);
  // tcase_add_test(tc_core, test_is_greater_ok1495);
  // tcase_add_test(tc_core, test_is_greater_ok1496);
  // tcase_add_test(tc_core, test_is_greater_ok1497);
  // tcase_add_test(tc_core, test_is_greater_ok1498);
  // tcase_add_test(tc_core, test_is_greater_ok1499);
  // tcase_add_test(tc_core, test_is_greater_ok1500);
  // tcase_add_test(tc_core, test_is_greater_ok3601);
  // tcase_add_test(tc_core, test_is_greater_ok3602);
  // tcase_add_test(tc_core, test_is_greater_ok3603);
  // tcase_add_test(tc_core, test_is_greater_ok3604);
  // tcase_add_test(tc_core, test_is_greater_ok3605);
  // tcase_add_test(tc_core, test_is_greater_ok3606);
  // tcase_add_test(tc_core, test_is_greater_ok3607);
  // tcase_add_test(tc_core, test_is_greater_ok3608);
  // tcase_add_test(tc_core, test_is_greater_ok3609);
  // tcase_add_test(tc_core, test_is_greater_ok3610);
  // tcase_add_test(tc_core, test_is_greater_ok3611);
  // tcase_add_test(tc_core, test_is_greater_ok3612);
  // tcase_add_test(tc_core, test_is_greater_ok3613);
  // tcase_add_test(tc_core, test_is_greater_ok3614);
  // tcase_add_test(tc_core, test_is_greater_ok3615);
  // tcase_add_test(tc_core, test_is_greater_ok3616);
  // tcase_add_test(tc_core, test_is_greater_ok3617);
  // tcase_add_test(tc_core, test_is_greater_ok3618);
  // tcase_add_test(tc_core, test_is_greater_ok3619);
  // tcase_add_test(tc_core, test_is_greater_ok3620);
  // tcase_add_test(tc_core, test_is_greater_ok3621);
  // tcase_add_test(tc_core, test_is_greater_ok3622);
  // tcase_add_test(tc_core, test_is_greater_ok3623);
  // tcase_add_test(tc_core, test_is_greater_ok3624);
  // tcase_add_test(tc_core, test_is_greater_ok3625);
  // tcase_add_test(tc_core, test_is_greater_ok3626);
  // tcase_add_test(tc_core, test_is_greater_ok3627);
  // tcase_add_test(tc_core, test_is_greater_ok3628);
  // tcase_add_test(tc_core, test_is_greater_ok3629);
  // tcase_add_test(tc_core, test_is_greater_ok3630);
  // tcase_add_test(tc_core, test_is_greater_ok3631);
  // tcase_add_test(tc_core, test_is_greater_ok3632);
  // tcase_add_test(tc_core, test_is_greater_ok3633);
  // tcase_add_test(tc_core, test_is_greater_ok3634);
  // tcase_add_test(tc_core, test_is_greater_ok3635);
  // tcase_add_test(tc_core, test_is_greater_ok3636);
  // tcase_add_test(tc_core, test_is_greater_ok3637);
  // tcase_add_test(tc_core, test_is_greater_ok3638);
  // tcase_add_test(tc_core, test_is_greater_ok3639);
  // tcase_add_test(tc_core, test_is_greater_ok3640);
  // tcase_add_test(tc_core, test_is_greater_ok3641);
  // tcase_add_test(tc_core, test_is_greater_ok3642);
  // tcase_add_test(tc_core, test_is_greater_ok3643);
  // tcase_add_test(tc_core, test_is_greater_ok3644);
  // tcase_add_test(tc_core, test_is_greater_ok3645);
  // tcase_add_test(tc_core, test_is_greater_ok3646);
  // tcase_add_test(tc_core, test_is_greater_ok3647);
  // tcase_add_test(tc_core, test_is_greater_ok3648);
  // tcase_add_test(tc_core, test_is_greater_ok3649);
  // tcase_add_test(tc_core, test_is_greater_ok3650);
  // tcase_add_test(tc_core, test_is_greater_ok3651);
  // tcase_add_test(tc_core, test_is_greater_ok3652);
  // tcase_add_test(tc_core, test_is_greater_ok3653);
  // tcase_add_test(tc_core, test_is_greater_ok3654);
  // tcase_add_test(tc_core, test_is_greater_ok3655);
  // tcase_add_test(tc_core, test_is_greater_ok3656);
  // tcase_add_test(tc_core, test_is_greater_ok3657);
  // tcase_add_test(tc_core, test_is_greater_ok3658);
  // tcase_add_test(tc_core, test_is_greater_ok3659);
  // tcase_add_test(tc_core, test_is_greater_ok3660);
  // tcase_add_test(tc_core, test_is_greater_ok3661);
  // tcase_add_test(tc_core, test_is_greater_ok3662);
  // tcase_add_test(tc_core, test_is_greater_ok3663);
  // tcase_add_test(tc_core, test_is_greater_ok3664);
  // tcase_add_test(tc_core, test_is_greater_ok3665);
  // tcase_add_test(tc_core, test_is_greater_ok3666);
  // tcase_add_test(tc_core, test_is_greater_ok3667);
  // tcase_add_test(tc_core, test_is_greater_ok3668);
  // tcase_add_test(tc_core, test_is_greater_ok3669);
  // tcase_add_test(tc_core, test_is_greater_ok3670);
  // tcase_add_test(tc_core, test_is_greater_ok3671);
  // tcase_add_test(tc_core, test_is_greater_ok3672);
  // tcase_add_test(tc_core, test_is_greater_ok3673);
  // tcase_add_test(tc_core, test_is_greater_ok3674);
  // tcase_add_test(tc_core, test_is_greater_ok3675);
  // tcase_add_test(tc_core, test_is_greater_ok3676);
  // tcase_add_test(tc_core, test_is_greater_ok3677);
  // tcase_add_test(tc_core, test_is_greater_ok3678);
  // tcase_add_test(tc_core, test_is_greater_ok3679);
  // tcase_add_test(tc_core, test_is_greater_ok3680);
  // tcase_add_test(tc_core, test_is_greater_ok3681);
  // tcase_add_test(tc_core, test_is_greater_ok3682);
  // tcase_add_test(tc_core, test_is_greater_ok3683);
  // tcase_add_test(tc_core, test_is_greater_ok3684);
  // tcase_add_test(tc_core, test_is_greater_ok3685);
  // tcase_add_test(tc_core, test_is_greater_ok3686);
  // tcase_add_test(tc_core, test_is_greater_ok3687);
  // tcase_add_test(tc_core, test_is_greater_ok3688);
  // tcase_add_test(tc_core, test_is_greater_ok3689);
  // tcase_add_test(tc_core, test_is_greater_ok3690);
  // tcase_add_test(tc_core, test_is_greater_ok3691);
  // tcase_add_test(tc_core, test_is_greater_ok3692);
  // tcase_add_test(tc_core, test_is_greater_ok3693);
  // tcase_add_test(tc_core, test_is_greater_ok3694);
  // tcase_add_test(tc_core, test_is_greater_ok3695);
  // tcase_add_test(tc_core, test_is_greater_ok3696);
  // tcase_add_test(tc_core, test_is_greater_ok3697);
  // tcase_add_test(tc_core, test_is_greater_ok3698);
  // tcase_add_test(tc_core, test_is_greater_ok3699);
  // tcase_add_test(tc_core, test_is_greater_ok3700);
  // tcase_add_test(tc_core, test_is_greater_ok3701);
  // tcase_add_test(tc_core, test_is_greater_ok3702);
  // tcase_add_test(tc_core, test_is_greater_ok3703);
  // tcase_add_test(tc_core, test_is_greater_ok3704);
  // tcase_add_test(tc_core, test_is_greater_ok3705);
  // tcase_add_test(tc_core, test_is_greater_ok3706);
  // tcase_add_test(tc_core, test_is_greater_ok3707);
  // tcase_add_test(tc_core, test_is_greater_ok3708);
  // tcase_add_test(tc_core, test_is_greater_ok3709);
  // tcase_add_test(tc_core, test_is_greater_ok3710);
  // tcase_add_test(tc_core, test_is_greater_ok3711);
  // tcase_add_test(tc_core, test_is_greater_ok3712);
  // tcase_add_test(tc_core, test_is_greater_ok3713);
  // tcase_add_test(tc_core, test_is_greater_ok3714);
  // tcase_add_test(tc_core, test_is_greater_ok3715);
  // tcase_add_test(tc_core, test_is_greater_ok3716);
  // tcase_add_test(tc_core, test_is_greater_ok3717);
  // tcase_add_test(tc_core, test_is_greater_ok3718);
  // tcase_add_test(tc_core, test_is_greater_ok3719);
  // tcase_add_test(tc_core, test_is_greater_ok3720);
  // tcase_add_test(tc_core, test_is_greater_ok3721);
  // tcase_add_test(tc_core, test_is_greater_ok3722);
  // tcase_add_test(tc_core, test_is_greater_ok3723);
  // tcase_add_test(tc_core, test_is_greater_ok3724);
  // tcase_add_test(tc_core, test_is_greater_ok3725);
  // tcase_add_test(tc_core, test_is_greater_ok3726);
  // tcase_add_test(tc_core, test_is_greater_ok3727);
  // tcase_add_test(tc_core, test_is_greater_ok3728);
  // tcase_add_test(tc_core, test_is_greater_ok3729);
  // tcase_add_test(tc_core, test_is_greater_ok3730);
  // tcase_add_test(tc_core, test_is_greater_ok3731);
  // tcase_add_test(tc_core, test_is_greater_ok3732);
  // tcase_add_test(tc_core, test_is_greater_ok3733);
  // tcase_add_test(tc_core, test_is_greater_ok3734);
  // tcase_add_test(tc_core, test_is_greater_ok3735);
  // tcase_add_test(tc_core, test_is_greater_ok3736);
  // tcase_add_test(tc_core, test_is_greater_ok3737);
  // tcase_add_test(tc_core, test_is_greater_ok3738);
  // tcase_add_test(tc_core, test_is_greater_ok3739);
  // tcase_add_test(tc_core, test_is_greater_ok3740);
  // tcase_add_test(tc_core, test_is_greater_ok3741);
  // tcase_add_test(tc_core, test_is_greater_ok3742);
  // tcase_add_test(tc_core, test_is_greater_ok3743);
  // tcase_add_test(tc_core, test_is_greater_ok3744);
  // tcase_add_test(tc_core, test_is_greater_ok3745);
  // tcase_add_test(tc_core, test_is_greater_ok3746);
  // tcase_add_test(tc_core, test_is_greater_ok3747);
  // tcase_add_test(tc_core, test_is_greater_ok3748);
  // tcase_add_test(tc_core, test_is_greater_ok3749);
  // tcase_add_test(tc_core, test_is_greater_ok3750);
  // tcase_add_test(tc_core, test_is_greater_ok3751);
  // tcase_add_test(tc_core, test_is_greater_ok3752);
  // tcase_add_test(tc_core, test_is_greater_ok3753);
  // tcase_add_test(tc_core, test_is_greater_ok3754);
  // tcase_add_test(tc_core, test_is_greater_ok3755);
  // tcase_add_test(tc_core, test_is_greater_ok3756);
  // tcase_add_test(tc_core, test_is_greater_ok3757);
  // tcase_add_test(tc_core, test_is_greater_ok3758);
  // tcase_add_test(tc_core, test_is_greater_ok3759);
  // tcase_add_test(tc_core, test_is_greater_ok3760);
  // tcase_add_test(tc_core, test_is_greater_ok3761);
  // tcase_add_test(tc_core, test_is_greater_ok3762);
  // tcase_add_test(tc_core, test_is_greater_ok3763);
  // tcase_add_test(tc_core, test_is_greater_ok3764);
  // tcase_add_test(tc_core, test_is_greater_ok3765);
  // tcase_add_test(tc_core, test_is_greater_ok3766);
  // tcase_add_test(tc_core, test_is_greater_ok3767);
  // tcase_add_test(tc_core, test_is_greater_ok3768);
  // tcase_add_test(tc_core, test_is_greater_ok3769);
  // tcase_add_test(tc_core, test_is_greater_ok3770);
  // tcase_add_test(tc_core, test_is_greater_ok3771);
  // tcase_add_test(tc_core, test_is_greater_ok3772);
  // tcase_add_test(tc_core, test_is_greater_ok3773);
  // tcase_add_test(tc_core, test_is_greater_ok3774);
  // tcase_add_test(tc_core, test_is_greater_ok3775);
  // tcase_add_test(tc_core, test_is_greater_ok3776);
  // tcase_add_test(tc_core, test_is_greater_ok3777);
  // tcase_add_test(tc_core, test_is_greater_ok3778);
  // tcase_add_test(tc_core, test_is_greater_ok3779);
  // tcase_add_test(tc_core, test_is_greater_ok3780);
  // tcase_add_test(tc_core, test_is_greater_ok3781);
  // tcase_add_test(tc_core, test_is_greater_ok3782);
  // tcase_add_test(tc_core, test_is_greater_ok3783);
  // tcase_add_test(tc_core, test_is_greater_ok3784);
  // tcase_add_test(tc_core, test_is_greater_ok3785);
  // tcase_add_test(tc_core, test_is_greater_ok3786);
  // tcase_add_test(tc_core, test_is_greater_ok3787);
  // tcase_add_test(tc_core, test_is_greater_ok3788);
  // tcase_add_test(tc_core, test_is_greater_ok3789);
  // tcase_add_test(tc_core, test_is_greater_ok3790);
  // tcase_add_test(tc_core, test_is_greater_ok3791);
  // tcase_add_test(tc_core, test_is_greater_ok3792);
  // tcase_add_test(tc_core, test_is_greater_ok3793);
  // tcase_add_test(tc_core, test_is_greater_ok3794);
  // tcase_add_test(tc_core, test_is_greater_ok3795);
  // tcase_add_test(tc_core, test_is_greater_ok3796);
  // tcase_add_test(tc_core, test_is_greater_ok3797);
  // tcase_add_test(tc_core, test_is_greater_ok3798);
  // tcase_add_test(tc_core, test_is_greater_ok3799);
  // tcase_add_test(tc_core, test_is_greater_ok3800);
  // tcase_add_test(tc_core, test_is_greater_ok3801);
  // tcase_add_test(tc_core, test_is_greater_ok3802);
  // tcase_add_test(tc_core, test_is_greater_ok3803);
  // tcase_add_test(tc_core, test_is_greater_ok3804);
  // tcase_add_test(tc_core, test_is_greater_ok3805);
  // tcase_add_test(tc_core, test_is_greater_ok3806);
  // tcase_add_test(tc_core, test_is_greater_ok3807);
  // tcase_add_test(tc_core, test_is_greater_ok3808);
  // tcase_add_test(tc_core, test_is_greater_ok3809);
  // tcase_add_test(tc_core, test_is_greater_ok3810);
  // tcase_add_test(tc_core, test_is_greater_ok3811);
  // tcase_add_test(tc_core, test_is_greater_ok3812);
  // tcase_add_test(tc_core, test_is_greater_ok3813);
  // tcase_add_test(tc_core, test_is_greater_ok3814);
  // tcase_add_test(tc_core, test_is_greater_ok3815);
  // tcase_add_test(tc_core, test_is_greater_ok3816);
  // tcase_add_test(tc_core, test_is_greater_ok3817);
  // tcase_add_test(tc_core, test_is_greater_ok3818);
  // tcase_add_test(tc_core, test_is_greater_ok3819);
  // tcase_add_test(tc_core, test_is_greater_ok3820);
  // tcase_add_test(tc_core, test_is_greater_ok3821);
  // tcase_add_test(tc_core, test_is_greater_ok3822);
  // tcase_add_test(tc_core, test_is_greater_ok3823);
  // tcase_add_test(tc_core, test_is_greater_ok3824);
  // tcase_add_test(tc_core, test_is_greater_ok3825);
  // tcase_add_test(tc_core, test_is_greater_ok3826);
  // tcase_add_test(tc_core, test_is_greater_ok3827);
  // tcase_add_test(tc_core, test_is_greater_ok3828);
  // tcase_add_test(tc_core, test_is_greater_ok3829);
  // tcase_add_test(tc_core, test_is_greater_ok3830);
  // tcase_add_test(tc_core, test_is_greater_ok3831);
  // tcase_add_test(tc_core, test_is_greater_ok3832);
  // tcase_add_test(tc_core, test_is_greater_ok3833);
  // tcase_add_test(tc_core, test_is_greater_ok3834);
  // tcase_add_test(tc_core, test_is_greater_ok3835);
  // tcase_add_test(tc_core, test_is_greater_ok3836);
  // tcase_add_test(tc_core, test_is_greater_ok3837);
  // tcase_add_test(tc_core, test_is_greater_ok3838);
  // tcase_add_test(tc_core, test_is_greater_ok3839);
  // tcase_add_test(tc_core, test_is_greater_ok3840);
  // tcase_add_test(tc_core, test_is_greater_ok3841);
  // tcase_add_test(tc_core, test_is_greater_ok3842);
  // tcase_add_test(tc_core, test_is_greater_ok3843);
  // tcase_add_test(tc_core, test_is_greater_ok3844);
  // tcase_add_test(tc_core, test_is_greater_ok3845);
  // tcase_add_test(tc_core, test_is_greater_ok3846);
  // tcase_add_test(tc_core, test_is_greater_ok3847);
  // tcase_add_test(tc_core, test_is_greater_ok3848);
  // tcase_add_test(tc_core, test_is_greater_ok3849);
  // tcase_add_test(tc_core, test_is_greater_ok3850);
  // tcase_add_test(tc_core, test_is_greater_ok3851);
  // tcase_add_test(tc_core, test_is_greater_ok3852);
  // tcase_add_test(tc_core, test_is_greater_ok3853);
  // tcase_add_test(tc_core, test_is_greater_ok3854);
  // tcase_add_test(tc_core, test_is_greater_ok3855);
  // tcase_add_test(tc_core, test_is_greater_ok3856);
  // tcase_add_test(tc_core, test_is_greater_ok3857);
  // tcase_add_test(tc_core, test_is_greater_ok3858);
  // tcase_add_test(tc_core, test_is_greater_ok3859);
  // tcase_add_test(tc_core, test_is_greater_ok3860);
  // tcase_add_test(tc_core, test_is_greater_ok3861);
  // tcase_add_test(tc_core, test_is_greater_ok3862);
  // tcase_add_test(tc_core, test_is_greater_ok3863);
  // tcase_add_test(tc_core, test_is_greater_ok3864);
  // tcase_add_test(tc_core, test_is_greater_ok3865);
  // tcase_add_test(tc_core, test_is_greater_ok3866);
  // tcase_add_test(tc_core, test_is_greater_ok3867);
  // tcase_add_test(tc_core, test_is_greater_ok3868);
  // tcase_add_test(tc_core, test_is_greater_ok3869);
  // tcase_add_test(tc_core, test_is_greater_ok3870);
  // tcase_add_test(tc_core, test_is_greater_ok3871);
  // tcase_add_test(tc_core, test_is_greater_ok3872);
  // tcase_add_test(tc_core, test_is_greater_ok3873);
  // tcase_add_test(tc_core, test_is_greater_ok3874);
  // tcase_add_test(tc_core, test_is_greater_ok3875);
  // tcase_add_test(tc_core, test_is_greater_ok3876);
  // tcase_add_test(tc_core, test_is_greater_ok3877);
  // tcase_add_test(tc_core, test_is_greater_ok3878);
  // tcase_add_test(tc_core, test_is_greater_ok3879);
  // tcase_add_test(tc_core, test_is_greater_ok3880);
  // tcase_add_test(tc_core, test_is_greater_ok3881);
  // tcase_add_test(tc_core, test_is_greater_ok3882);
  // tcase_add_test(tc_core, test_is_greater_ok3883);
  // tcase_add_test(tc_core, test_is_greater_ok3884);
  // tcase_add_test(tc_core, test_is_greater_ok3885);
  // tcase_add_test(tc_core, test_is_greater_ok3886);
  // tcase_add_test(tc_core, test_is_greater_ok3887);
  // tcase_add_test(tc_core, test_is_greater_ok3888);
  // tcase_add_test(tc_core, test_is_greater_ok3889);
  // tcase_add_test(tc_core, test_is_greater_ok3890);
  // tcase_add_test(tc_core, test_is_greater_ok3891);
  // tcase_add_test(tc_core, test_is_greater_ok3892);
  // tcase_add_test(tc_core, test_is_greater_ok3893);
  // tcase_add_test(tc_core, test_is_greater_ok3894);
  // tcase_add_test(tc_core, test_is_greater_ok3895);
  // tcase_add_test(tc_core, test_is_greater_ok3896);
  // tcase_add_test(tc_core, test_is_greater_ok3897);
  // tcase_add_test(tc_core, test_is_greater_ok3898);
  // tcase_add_test(tc_core, test_is_greater_ok3899);
  // tcase_add_test(tc_core, test_is_greater_ok3900);
  // tcase_add_test(tc_core, test_is_greater_ok3901);
  // tcase_add_test(tc_core, test_is_greater_ok3902);
  // tcase_add_test(tc_core, test_is_greater_ok3903);
  // tcase_add_test(tc_core, test_is_greater_ok3904);
  // tcase_add_test(tc_core, test_is_greater_ok3905);
  // tcase_add_test(tc_core, test_is_greater_ok3906);
  // tcase_add_test(tc_core, test_is_greater_ok3907);
  // tcase_add_test(tc_core, test_is_greater_ok3908);
  // tcase_add_test(tc_core, test_is_greater_ok3909);
  // tcase_add_test(tc_core, test_is_greater_ok3910);
  // tcase_add_test(tc_core, test_is_greater_ok3911);
  // tcase_add_test(tc_core, test_is_greater_ok3912);
  // tcase_add_test(tc_core, test_is_greater_ok3913);
  // tcase_add_test(tc_core, test_is_greater_ok3914);
  // tcase_add_test(tc_core, test_is_greater_ok3915);
  // tcase_add_test(tc_core, test_is_greater_ok3916);
  // tcase_add_test(tc_core, test_is_greater_ok3917);
  // tcase_add_test(tc_core, test_is_greater_ok3918);
  // tcase_add_test(tc_core, test_is_greater_ok3919);
  // tcase_add_test(tc_core, test_is_greater_ok3920);
  // tcase_add_test(tc_core, test_is_greater_ok3921);
  // tcase_add_test(tc_core, test_is_greater_ok3922);
  // tcase_add_test(tc_core, test_is_greater_ok3923);
  // tcase_add_test(tc_core, test_is_greater_ok3924);
  // tcase_add_test(tc_core, test_is_greater_ok3925);
  // tcase_add_test(tc_core, test_is_greater_ok3926);
  // tcase_add_test(tc_core, test_is_greater_ok3927);
  // tcase_add_test(tc_core, test_is_greater_ok3928);
  // tcase_add_test(tc_core, test_is_greater_ok3929);
  // tcase_add_test(tc_core, test_is_greater_ok3930);
  // tcase_add_test(tc_core, test_is_greater_ok3931);
  // tcase_add_test(tc_core, test_is_greater_ok3932);
  // tcase_add_test(tc_core, test_is_greater_ok3933);
  // tcase_add_test(tc_core, test_is_greater_ok3934);
  // tcase_add_test(tc_core, test_is_greater_ok3935);
  // tcase_add_test(tc_core, test_is_greater_ok3936);
  // tcase_add_test(tc_core, test_is_greater_ok3937);
  // tcase_add_test(tc_core, test_is_greater_ok3938);
  // tcase_add_test(tc_core, test_is_greater_ok3939);
  // tcase_add_test(tc_core, test_is_greater_ok3940);
  // tcase_add_test(tc_core, test_is_greater_ok3941);
  // tcase_add_test(tc_core, test_is_greater_ok3942);
  // tcase_add_test(tc_core, test_is_greater_ok3943);
  // tcase_add_test(tc_core, test_is_greater_ok3944);
  // tcase_add_test(tc_core, test_is_greater_ok3945);
  // tcase_add_test(tc_core, test_is_greater_ok3946);
  // tcase_add_test(tc_core, test_is_greater_ok3947);
  // tcase_add_test(tc_core, test_is_greater_ok3948);
  // tcase_add_test(tc_core, test_is_greater_ok3949);
  // tcase_add_test(tc_core, test_is_greater_ok3950);
  // tcase_add_test(tc_core, test_is_greater_ok3951);
  // tcase_add_test(tc_core, test_is_greater_ok3952);
  // tcase_add_test(tc_core, test_is_greater_ok3953);
  // tcase_add_test(tc_core, test_is_greater_ok3954);
  // tcase_add_test(tc_core, test_is_greater_ok3955);
  // tcase_add_test(tc_core, test_is_greater_ok3956);
  // tcase_add_test(tc_core, test_is_greater_ok3957);
  // tcase_add_test(tc_core, test_is_greater_ok3958);
  // tcase_add_test(tc_core, test_is_greater_ok3959);
  // tcase_add_test(tc_core, test_is_greater_ok3960);
  // tcase_add_test(tc_core, test_is_greater_ok3961);
  // tcase_add_test(tc_core, test_is_greater_ok3962);
  // tcase_add_test(tc_core, test_is_greater_ok3963);
  // tcase_add_test(tc_core, test_is_greater_ok3964);
  // tcase_add_test(tc_core, test_is_greater_ok3965);
  // tcase_add_test(tc_core, test_is_greater_ok3966);
  // tcase_add_test(tc_core, test_is_greater_ok3967);
  // tcase_add_test(tc_core, test_is_greater_ok3968);
  // tcase_add_test(tc_core, test_is_greater_ok3969);
  // tcase_add_test(tc_core, test_is_greater_ok3970);
  // tcase_add_test(tc_core, test_is_greater_ok3971);
  // tcase_add_test(tc_core, test_is_greater_ok3972);
  // tcase_add_test(tc_core, test_is_greater_ok3973);
  // tcase_add_test(tc_core, test_is_greater_ok3974);
  // tcase_add_test(tc_core, test_is_greater_ok3975);
  // tcase_add_test(tc_core, test_is_greater_ok3976);
  // tcase_add_test(tc_core, test_is_greater_ok3977);
  // tcase_add_test(tc_core, test_is_greater_ok3978);
  // tcase_add_test(tc_core, test_is_greater_ok3979);
  // tcase_add_test(tc_core, test_is_greater_ok3980);
  // tcase_add_test(tc_core, test_is_greater_ok3981);
  // tcase_add_test(tc_core, test_is_greater_ok3982);
  // tcase_add_test(tc_core, test_is_greater_ok3983);
  // tcase_add_test(tc_core, test_is_greater_ok3984);
  // tcase_add_test(tc_core, test_is_greater_ok3985);
  // tcase_add_test(tc_core, test_is_greater_ok3986);
  // tcase_add_test(tc_core, test_is_greater_ok3987);
  // tcase_add_test(tc_core, test_is_greater_ok3988);
  // tcase_add_test(tc_core, test_is_greater_ok3989);
  // tcase_add_test(tc_core, test_is_greater_ok3990);
  // tcase_add_test(tc_core, test_is_greater_ok3991);
  // tcase_add_test(tc_core, test_is_greater_ok3992);
  // tcase_add_test(tc_core, test_is_greater_ok3993);
  // tcase_add_test(tc_core, test_is_greater_ok3994);
  // tcase_add_test(tc_core, test_is_greater_ok3995);
  // tcase_add_test(tc_core, test_is_greater_ok3996);
  // tcase_add_test(tc_core, test_is_greater_ok3997);
  // tcase_add_test(tc_core, test_is_greater_ok3998);
  // tcase_add_test(tc_core, test_is_greater_ok3999);
  // tcase_add_test(tc_core, test_is_greater_ok4000);
  // tcase_add_test(tc_core, test_is_greater_ok6001);
  // tcase_add_test(tc_core, test_is_greater_ok6002);
  // tcase_add_test(tc_core, test_is_greater_ok6003);
  // tcase_add_test(tc_core, test_is_greater_ok6004);
  // tcase_add_test(tc_core, test_is_greater_ok6005);
  // tcase_add_test(tc_core, test_is_greater_ok6006);
  // tcase_add_test(tc_core, test_is_greater_ok6007);
  // tcase_add_test(tc_core, test_is_greater_ok6008);
  // tcase_add_test(tc_core, test_is_greater_ok6009);
  // tcase_add_test(tc_core, test_is_greater_ok6010);
  // tcase_add_test(tc_core, test_is_greater_ok6011);
  // tcase_add_test(tc_core, test_is_greater_ok6012);
  // tcase_add_test(tc_core, test_is_greater_ok6013);
  // tcase_add_test(tc_core, test_is_greater_ok6014);
  // tcase_add_test(tc_core, test_is_greater_ok6015);
  // tcase_add_test(tc_core, test_is_greater_ok6016);
  // tcase_add_test(tc_core, test_is_greater_ok6017);
  // tcase_add_test(tc_core, test_is_greater_ok6018);
  // tcase_add_test(tc_core, test_is_greater_ok6019);
  // tcase_add_test(tc_core, test_is_greater_ok6020);
  // tcase_add_test(tc_core, test_is_greater_ok6021);
  // tcase_add_test(tc_core, test_is_greater_ok6022);
  // tcase_add_test(tc_core, test_is_greater_ok6023);
  // tcase_add_test(tc_core, test_is_greater_ok6024);
  // tcase_add_test(tc_core, test_is_greater_ok6025);
  // tcase_add_test(tc_core, test_is_greater_ok6026);
  // tcase_add_test(tc_core, test_is_greater_ok6027);
  // tcase_add_test(tc_core, test_is_greater_ok6028);
  // tcase_add_test(tc_core, test_is_greater_ok6029);
  // tcase_add_test(tc_core, test_is_greater_ok6030);
  // tcase_add_test(tc_core, test_is_greater_ok6031);
  // tcase_add_test(tc_core, test_is_greater_ok6032);
  // tcase_add_test(tc_core, test_is_greater_ok6033);
  // tcase_add_test(tc_core, test_is_greater_ok6034);
  // tcase_add_test(tc_core, test_is_greater_ok6035);
  // tcase_add_test(tc_core, test_is_greater_ok6036);
  // tcase_add_test(tc_core, test_is_greater_ok6037);
  // tcase_add_test(tc_core, test_is_greater_ok6038);
  // tcase_add_test(tc_core, test_is_greater_ok6039);
  // tcase_add_test(tc_core, test_is_greater_ok6040);
  // tcase_add_test(tc_core, test_is_greater_ok6041);
  // tcase_add_test(tc_core, test_is_greater_ok6042);
  // tcase_add_test(tc_core, test_is_greater_ok6043);
  // tcase_add_test(tc_core, test_is_greater_ok6044);
  // tcase_add_test(tc_core, test_is_greater_ok6045);
  // tcase_add_test(tc_core, test_is_greater_ok6046);
  // tcase_add_test(tc_core, test_is_greater_ok6047);
  // tcase_add_test(tc_core, test_is_greater_ok6048);
  // tcase_add_test(tc_core, test_is_greater_ok6049);
  // tcase_add_test(tc_core, test_is_greater_ok6050);
  // tcase_add_test(tc_core, test_is_greater_ok6051);
  // tcase_add_test(tc_core, test_is_greater_ok6052);
  // tcase_add_test(tc_core, test_is_greater_ok6053);
  // tcase_add_test(tc_core, test_is_greater_ok6054);
  // tcase_add_test(tc_core, test_is_greater_ok6055);
  // tcase_add_test(tc_core, test_is_greater_ok6056);
  // tcase_add_test(tc_core, test_is_greater_ok6057);
  // tcase_add_test(tc_core, test_is_greater_ok6058);
  // tcase_add_test(tc_core, test_is_greater_ok6059);
  // tcase_add_test(tc_core, test_is_greater_ok6060);
  // tcase_add_test(tc_core, test_is_greater_ok6061);
  // tcase_add_test(tc_core, test_is_greater_ok6062);
  // tcase_add_test(tc_core, test_is_greater_ok6063);
  // tcase_add_test(tc_core, test_is_greater_ok6064);
  // tcase_add_test(tc_core, test_is_greater_ok6065);
  // tcase_add_test(tc_core, test_is_greater_ok6066);
  // tcase_add_test(tc_core, test_is_greater_ok6067);
  // tcase_add_test(tc_core, test_is_greater_ok6068);
  // tcase_add_test(tc_core, test_is_greater_ok6069);
  // tcase_add_test(tc_core, test_is_greater_ok6070);
  // tcase_add_test(tc_core, test_is_greater_ok6071);
  // tcase_add_test(tc_core, test_is_greater_ok6072);
  // tcase_add_test(tc_core, test_is_greater_ok6073);
  // tcase_add_test(tc_core, test_is_greater_ok6074);
  // tcase_add_test(tc_core, test_is_greater_ok6075);
  // tcase_add_test(tc_core, test_is_greater_ok6076);
  // tcase_add_test(tc_core, test_is_greater_ok6077);
  // tcase_add_test(tc_core, test_is_greater_ok6078);
  // tcase_add_test(tc_core, test_is_greater_ok6079);
  // tcase_add_test(tc_core, test_is_greater_ok6080);
  // tcase_add_test(tc_core, test_is_greater_ok6081);
  // tcase_add_test(tc_core, test_is_greater_ok6082);
  // tcase_add_test(tc_core, test_is_greater_ok6083);
  // tcase_add_test(tc_core, test_is_greater_ok6084);
  // tcase_add_test(tc_core, test_is_greater_ok6085);
  // tcase_add_test(tc_core, test_is_greater_ok6086);
  // tcase_add_test(tc_core, test_is_greater_ok6087);
  // tcase_add_test(tc_core, test_is_greater_ok6088);
  // tcase_add_test(tc_core, test_is_greater_ok6089);
  // tcase_add_test(tc_core, test_is_greater_ok6090);
  // tcase_add_test(tc_core, test_is_greater_ok6091);
  // tcase_add_test(tc_core, test_is_greater_ok6092);
  // tcase_add_test(tc_core, test_is_greater_ok6093);
  // tcase_add_test(tc_core, test_is_greater_ok6094);
  // tcase_add_test(tc_core, test_is_greater_ok6095);
  // tcase_add_test(tc_core, test_is_greater_ok6096);
  // tcase_add_test(tc_core, test_is_greater_ok6097);
  // tcase_add_test(tc_core, test_is_greater_ok6098);
  // tcase_add_test(tc_core, test_is_greater_ok6099);
  // tcase_add_test(tc_core, test_is_greater_ok6100);
  // tcase_add_test(tc_core, test_is_greater_ok6101);
  // tcase_add_test(tc_core, test_is_greater_ok6102);
  // tcase_add_test(tc_core, test_is_greater_ok6103);
  // tcase_add_test(tc_core, test_is_greater_ok6104);
  // tcase_add_test(tc_core, test_is_greater_ok6105);
  // tcase_add_test(tc_core, test_is_greater_ok6106);
  // tcase_add_test(tc_core, test_is_greater_ok6107);
  // tcase_add_test(tc_core, test_is_greater_ok6108);
  // tcase_add_test(tc_core, test_is_greater_ok6109);
  // tcase_add_test(tc_core, test_is_greater_ok6110);
  // tcase_add_test(tc_core, test_is_greater_ok6111);
  // tcase_add_test(tc_core, test_is_greater_ok6112);
  // tcase_add_test(tc_core, test_is_greater_ok6113);
  // tcase_add_test(tc_core, test_is_greater_ok6114);
  // tcase_add_test(tc_core, test_is_greater_ok6115);
  // tcase_add_test(tc_core, test_is_greater_ok6116);
  // tcase_add_test(tc_core, test_is_greater_ok6117);
  // tcase_add_test(tc_core, test_is_greater_ok6118);
  // tcase_add_test(tc_core, test_is_greater_ok6119);
  // tcase_add_test(tc_core, test_is_greater_ok6120);
  // tcase_add_test(tc_core, test_is_greater_ok6121);
  // tcase_add_test(tc_core, test_is_greater_ok6122);
  // tcase_add_test(tc_core, test_is_greater_ok6123);
  // tcase_add_test(tc_core, test_is_greater_ok6124);
  // tcase_add_test(tc_core, test_is_greater_ok6125);
  // tcase_add_test(tc_core, test_is_greater_ok6126);
  // tcase_add_test(tc_core, test_is_greater_ok6127);
  // tcase_add_test(tc_core, test_is_greater_ok6128);
  // tcase_add_test(tc_core, test_is_greater_ok6129);
  // tcase_add_test(tc_core, test_is_greater_ok6130);
  // tcase_add_test(tc_core, test_is_greater_ok6131);
  // tcase_add_test(tc_core, test_is_greater_ok6132);
  // tcase_add_test(tc_core, test_is_greater_ok6133);
  // tcase_add_test(tc_core, test_is_greater_ok6134);
  // tcase_add_test(tc_core, test_is_greater_ok6135);
  // tcase_add_test(tc_core, test_is_greater_ok6136);
  // tcase_add_test(tc_core, test_is_greater_ok6137);
  // tcase_add_test(tc_core, test_is_greater_ok6138);
  // tcase_add_test(tc_core, test_is_greater_ok6139);
  // tcase_add_test(tc_core, test_is_greater_ok6140);
  // tcase_add_test(tc_core, test_is_greater_ok6141);
  // tcase_add_test(tc_core, test_is_greater_ok6142);
  // tcase_add_test(tc_core, test_is_greater_ok6143);
  // tcase_add_test(tc_core, test_is_greater_ok6144);
  // tcase_add_test(tc_core, test_is_greater_ok6145);
  // tcase_add_test(tc_core, test_is_greater_ok6146);
  // tcase_add_test(tc_core, test_is_greater_ok6147);
  // tcase_add_test(tc_core, test_is_greater_ok6148);
  // tcase_add_test(tc_core, test_is_greater_ok6149);
  // tcase_add_test(tc_core, test_is_greater_ok6150);
  // tcase_add_test(tc_core, test_is_greater_ok6151);
  // tcase_add_test(tc_core, test_is_greater_ok6152);
  // tcase_add_test(tc_core, test_is_greater_ok6153);
  // tcase_add_test(tc_core, test_is_greater_ok6154);
  // tcase_add_test(tc_core, test_is_greater_ok6155);
  // tcase_add_test(tc_core, test_is_greater_ok6156);
  // tcase_add_test(tc_core, test_is_greater_ok6157);
  // tcase_add_test(tc_core, test_is_greater_ok6158);
  // tcase_add_test(tc_core, test_is_greater_ok6159);
  // tcase_add_test(tc_core, test_is_greater_ok6160);
  // tcase_add_test(tc_core, test_is_greater_ok6161);
  // tcase_add_test(tc_core, test_is_greater_ok6162);
  // tcase_add_test(tc_core, test_is_greater_ok6163);
  // tcase_add_test(tc_core, test_is_greater_ok6164);
  // tcase_add_test(tc_core, test_is_greater_ok6165);
  // tcase_add_test(tc_core, test_is_greater_ok6166);
  // tcase_add_test(tc_core, test_is_greater_ok6167);
  // tcase_add_test(tc_core, test_is_greater_ok6168);
  // tcase_add_test(tc_core, test_is_greater_ok6169);
  // tcase_add_test(tc_core, test_is_greater_ok6170);
  // tcase_add_test(tc_core, test_is_greater_ok6171);
  // tcase_add_test(tc_core, test_is_greater_ok6172);
  // tcase_add_test(tc_core, test_is_greater_ok6173);
  // tcase_add_test(tc_core, test_is_greater_ok6174);
  // tcase_add_test(tc_core, test_is_greater_ok6175);
  // tcase_add_test(tc_core, test_is_greater_ok6176);
  // tcase_add_test(tc_core, test_is_greater_ok6177);
  // tcase_add_test(tc_core, test_is_greater_ok6178);
  // tcase_add_test(tc_core, test_is_greater_ok6179);
  // tcase_add_test(tc_core, test_is_greater_ok6180);
  // tcase_add_test(tc_core, test_is_greater_ok6181);
  // tcase_add_test(tc_core, test_is_greater_ok6182);
  // tcase_add_test(tc_core, test_is_greater_ok6183);
  // tcase_add_test(tc_core, test_is_greater_ok6184);
  // tcase_add_test(tc_core, test_is_greater_ok6185);
  // tcase_add_test(tc_core, test_is_greater_ok6186);
  // tcase_add_test(tc_core, test_is_greater_ok6187);
  // tcase_add_test(tc_core, test_is_greater_ok6188);
  // tcase_add_test(tc_core, test_is_greater_ok6189);
  // tcase_add_test(tc_core, test_is_greater_ok6190);
  // tcase_add_test(tc_core, test_is_greater_ok6191);
  // tcase_add_test(tc_core, test_is_greater_ok6192);
  // tcase_add_test(tc_core, test_is_greater_ok6193);
  // tcase_add_test(tc_core, test_is_greater_ok6194);
  // tcase_add_test(tc_core, test_is_greater_ok6195);
  // tcase_add_test(tc_core, test_is_greater_ok6196);
  // tcase_add_test(tc_core, test_is_greater_ok6197);
  // tcase_add_test(tc_core, test_is_greater_ok6198);
  // tcase_add_test(tc_core, test_is_greater_ok6199);
  // tcase_add_test(tc_core, test_is_greater_ok6200);
  // tcase_add_test(tc_core, test_is_greater_ok6201);
  // tcase_add_test(tc_core, test_is_greater_ok6202);
  // tcase_add_test(tc_core, test_is_greater_ok6203);
  // tcase_add_test(tc_core, test_is_greater_ok6204);
  // tcase_add_test(tc_core, test_is_greater_ok6205);
  // tcase_add_test(tc_core, test_is_greater_ok6206);
  // tcase_add_test(tc_core, test_is_greater_ok6207);
  // tcase_add_test(tc_core, test_is_greater_ok6208);
  // tcase_add_test(tc_core, test_is_greater_ok6209);
  // tcase_add_test(tc_core, test_is_greater_ok6210);
  // tcase_add_test(tc_core, test_is_greater_ok6211);
  // tcase_add_test(tc_core, test_is_greater_ok6212);
  // tcase_add_test(tc_core, test_is_greater_ok6213);
  // tcase_add_test(tc_core, test_is_greater_ok6214);
  // tcase_add_test(tc_core, test_is_greater_ok6215);
  // tcase_add_test(tc_core, test_is_greater_ok6216);
  // tcase_add_test(tc_core, test_is_greater_ok6217);
  // tcase_add_test(tc_core, test_is_greater_ok6218);
  // tcase_add_test(tc_core, test_is_greater_ok6219);
  // tcase_add_test(tc_core, test_is_greater_ok6220);
  // tcase_add_test(tc_core, test_is_greater_ok6221);
  // tcase_add_test(tc_core, test_is_greater_ok6222);
  // tcase_add_test(tc_core, test_is_greater_ok6223);
  // tcase_add_test(tc_core, test_is_greater_ok6224);
  // tcase_add_test(tc_core, test_is_greater_ok6225);
  // tcase_add_test(tc_core, test_is_greater_ok6226);
  // tcase_add_test(tc_core, test_is_greater_ok6227);
  // tcase_add_test(tc_core, test_is_greater_ok6228);
  // tcase_add_test(tc_core, test_is_greater_ok6229);
  // tcase_add_test(tc_core, test_is_greater_ok6230);
  // tcase_add_test(tc_core, test_is_greater_ok6231);
  // tcase_add_test(tc_core, test_is_greater_ok6232);
  // tcase_add_test(tc_core, test_is_greater_ok6233);
  // tcase_add_test(tc_core, test_is_greater_ok6234);
  // tcase_add_test(tc_core, test_is_greater_ok6235);
  // tcase_add_test(tc_core, test_is_greater_ok6236);
  // tcase_add_test(tc_core, test_is_greater_ok6237);
  // tcase_add_test(tc_core, test_is_greater_ok6238);
  // tcase_add_test(tc_core, test_is_greater_ok6239);
  // tcase_add_test(tc_core, test_is_greater_ok6240);
  // tcase_add_test(tc_core, test_is_greater_ok6241);
  // tcase_add_test(tc_core, test_is_greater_ok6242);
  // tcase_add_test(tc_core, test_is_greater_ok6243);
  // tcase_add_test(tc_core, test_is_greater_ok6244);
  // tcase_add_test(tc_core, test_is_greater_ok6245);
  // tcase_add_test(tc_core, test_is_greater_ok6246);
  // tcase_add_test(tc_core, test_is_greater_ok6247);
  // tcase_add_test(tc_core, test_is_greater_ok6248);
  // tcase_add_test(tc_core, test_is_greater_ok6249);
  // tcase_add_test(tc_core, test_is_greater_ok6250);
  // tcase_add_test(tc_core, test_is_greater_ok6251);
  // tcase_add_test(tc_core, test_is_greater_ok6252);
  // tcase_add_test(tc_core, test_is_greater_ok6253);
  // tcase_add_test(tc_core, test_is_greater_ok6254);
  // tcase_add_test(tc_core, test_is_greater_ok6255);
  // tcase_add_test(tc_core, test_is_greater_ok6256);
  // tcase_add_test(tc_core, test_is_greater_ok6257);
  // tcase_add_test(tc_core, test_is_greater_ok6258);
  // tcase_add_test(tc_core, test_is_greater_ok6259);
  // tcase_add_test(tc_core, test_is_greater_ok6260);
  // tcase_add_test(tc_core, test_is_greater_ok6261);
  // tcase_add_test(tc_core, test_is_greater_ok6262);
  // tcase_add_test(tc_core, test_is_greater_ok6263);
  // tcase_add_test(tc_core, test_is_greater_ok6264);
  // tcase_add_test(tc_core, test_is_greater_ok6265);
  // tcase_add_test(tc_core, test_is_greater_ok6266);
  // tcase_add_test(tc_core, test_is_greater_ok6267);
  // tcase_add_test(tc_core, test_is_greater_ok6268);
  // tcase_add_test(tc_core, test_is_greater_ok6269);
  // tcase_add_test(tc_core, test_is_greater_ok6270);
  // tcase_add_test(tc_core, test_is_greater_ok6271);
  // tcase_add_test(tc_core, test_is_greater_ok6272);
  suite_add_tcase(c, tc_core);
  return c;
}