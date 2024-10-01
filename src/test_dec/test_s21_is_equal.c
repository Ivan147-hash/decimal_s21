#include "testes.h"

s21_decimal max = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};  //
s21_decimal middle = {{MAX_INT, MAX_INT, MAX_INT, 0}};
s21_decimal null = {{0, 0, 0, 0}};
s21_decimal null_minus = {{0, 0, 0, MINUS}};
s21_decimal middle_minus = {{MAX_INT, MAX_INT, MAX_INT, MINUS}};
s21_decimal max_minus = {{MAX_UINT, MAX_UINT, MAX_UINT, MINUS}};
s21_decimal middle_fractions = {{MAX_INT, MAX_INT, MAX_INT, EXPONENT_20}};
#define TEST_COMPARISON_TRUE 1
#define TEST_COMPARISON_FALSE 0

START_TEST(_is_equal) {
  ck_assert_int_eq(0, s21_is_equal(middle, max));
  ck_assert_int_eq(0, s21_is_equal(middle, middle_fractions));
  ck_assert_int_eq(1, s21_is_equal(null, null_minus));
  ck_assert_int_eq(0, s21_is_equal(middle_minus, max_minus));
}
END_TEST

START_TEST(test_is_equal_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok82) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok84) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok85) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok86) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok87) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok88) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok89) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok90) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok91) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok92) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok93) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok94) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok95) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok96) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok97) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok98) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok99) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok100) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok101) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -305820564510.46084593589468994
  s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok102) {
  // -305820564510.46084593589468994
  s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok103) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 305820564510.46084593589468994
  s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok104) {
  // 305820564510.46084593589468994
  s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok105) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok106) {
  // 5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok107) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5077779.6717425679610094186071
  s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok108) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok109) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok110) {
  // 20786105945010.405849433600269
  s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok111) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok112) {
  // -20786105945010.405849433600269
  s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok114) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok118) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok120) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok122) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok124) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok126) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok128) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok130) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok132) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok134) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok136) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok138) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok140) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok142) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok144) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok146) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok148) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok150) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok152) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok154) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok156) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok158) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok160) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok162) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok164) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok166) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok168) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok169) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok170) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok171) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok172) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok173) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok174) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok175) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok176) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok177) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok178) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok179) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok180) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok181) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok182) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok183) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok184) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok185) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok186) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok187) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok188) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok189) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok190) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok191) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok192) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok193) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok194) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok195) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok196) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok197) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok198) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok199) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}

START_TEST(test_is_equal_ok200) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
}
// START_TEST(test_is_equal_ok1000) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1001) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1002) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1003) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1004) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1005) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1006) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1007) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1008) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1009) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1010) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1011) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1012) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1013) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1014) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1015) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1016) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1017) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1018) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1019) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1020) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1021) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1022) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1023) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1024) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1025) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1026) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1027) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1028) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1029) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1030) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1031) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1032) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1033) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1034) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1035) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1036) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1037) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1038) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1039) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1040) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1041) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1042) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1043) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1044) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1045) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1046) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1047) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1048) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1049) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1050) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1051) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1052) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1053) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1054) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1055) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1056) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1057) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1058) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1059) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1060) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1061) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1062) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1063) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1064) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1065) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1066) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1067) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1068) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1069) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1070) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1071) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1072) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1073) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1074) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1075) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1076) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1077) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1078) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1079) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1080) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1081) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1082) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1083) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1084) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1085) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1086) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1087) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1088) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1089) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1090) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1091) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1092) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1093) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1094) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1095) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1096) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1097) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1098) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1099) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1100) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1101) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1102) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1103) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1104) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1105) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1106) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1107) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1108) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1109) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1110) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1111) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1112) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1113) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1114) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1115) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1116) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1117) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1118) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1119) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1120) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1121) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1122) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1123) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1124) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1125) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1126) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1127) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1128) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1129) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1130) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1131) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1132) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1133) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1134) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1135) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1136) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1137) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1138) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1139) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1140) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1141) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1142) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1143) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1144) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1145) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1146) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1147) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1148) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1149) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1150) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1151) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1152) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1153) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1154) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1155) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1156) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1157) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1158) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1159) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1160) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1161) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1162) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1163) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1164) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1165) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1166) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1167) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1168) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1169) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1170) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1171) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1172) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1173) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1174) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1175) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1176) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1177) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1178) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1179) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1180) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1181) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1182) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1183) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1184) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1185) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1186) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1187) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1188) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1189) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1190) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1191) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1192) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1193) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1194) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1195) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1196) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1197) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1198) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1199) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok1200) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2000) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2001) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2002) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2003) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2004) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2005) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2006) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2007) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2008) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2009) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2010) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2011) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2012) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2013) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2014) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2015) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2016) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2017) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2018) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2019) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2020) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2021) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2022) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2023) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2024) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2025) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2026) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2027) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2028) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2029) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2030) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2031) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2032) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2033) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2034) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2035) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2036) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2037) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2038) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2039) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2040) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2041) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2042) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2043) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2044) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2045) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2046) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2047) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2048) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2049) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2050) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2051) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2052) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2053) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2054) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2055) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2056) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2057) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2058) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2059) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2060) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2061) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2062) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2063) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2064) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2065) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2066) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2067) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2068) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2069) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2070) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2071) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2072) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2073) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2074) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2075) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2076) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2077) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2078) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2079) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2080) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2081) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2082) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2083) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2084) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2085) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2086) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2087) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2088) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2089) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2090) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2091) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2092) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2093) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2094) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2095) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2096) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2097) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2098) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2099) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2100) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2101) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2102) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2103) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2104) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2105) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2106) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2107) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2108) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2109) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2110) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2111) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2112) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2113) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2114) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2115) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2116) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2117) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2118) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2119) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2120) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2121) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2122) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2123) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2124) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2125) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2126) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2127) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2128) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2129) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2130) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2131) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2132) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2133) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2134) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2135) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2136) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2137) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2138) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2139) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2140) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2141) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2142) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2143) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2144) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2145) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2146) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2147) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2148) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2149) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2150) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2151) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2152) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2153) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2154) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2155) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2156) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2157) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2158) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2159) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2160) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2161) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2162) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2163) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2164) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2165) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2166) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2167) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2168) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2169) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2170) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2171) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2172) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2173) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2174) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2175) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2176) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2177) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2178) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2179) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2180) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2181) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2182) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2183) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2184) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2185) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2186) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2187) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2188) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2189) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2190) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2191) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2192) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2193) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2194) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2195) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2196) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2197) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2198) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2199) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok2200) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }
// START_TEST(test_is_equal_ok4000) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4001) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4002) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4003) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4004) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4005) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4006) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4007) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4008) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4009) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4010) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4011) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4012) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4013) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4014) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4015) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4016) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4017) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4018) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4019) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4020) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4021) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4022) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4023) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4024) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4025) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4026) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4027) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4028) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4029) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4030) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4031) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4032) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4033) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4034) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4035) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4036) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4037) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4038) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4039) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4040) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4041) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4042) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4043) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4044) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4045) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4046) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4047) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4048) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4049) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4050) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4051) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4052) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4053) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4054) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4055) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4056) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4057) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4058) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4059) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4060) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4061) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4062) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4063) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4064) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4065) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4066) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4067) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4068) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4069) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4070) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4071) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4072) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4073) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4074) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4075) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4076) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4077) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4078) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4079) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4080) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4081) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4082) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4083) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4084) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4085) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4086) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4087) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4088) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4089) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4090) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4091) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4092) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4093) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4094) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4095) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4096) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4097) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4098) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4099) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4100) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4101) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4102) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4103) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4104) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4105) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4106) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4107) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4108) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4109) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4110) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4111) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4112) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4113) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4114) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4115) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4116) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4117) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4118) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4119) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4120) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4121) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4122) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4123) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4124) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4125) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4126) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4127) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4128) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4129) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4130) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4131) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4132) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4133) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4134) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4135) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4136) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4137) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4138) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4139) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4140) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4141) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4142) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4143) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4144) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4145) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4146) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4147) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4148) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4149) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4150) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4151) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4152) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4153) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4154) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4155) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4156) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4157) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4158) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4159) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4160) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4161) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4162) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4163) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4164) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4165) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4166) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4167) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4168) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4169) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4170) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4171) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4172) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4173) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4174) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4175) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4176) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4177) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4178) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4179) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4180) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4181) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4182) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4183) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4184) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4185) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4186) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4187) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4188) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4189) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4190) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4191) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4192) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4193) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4194) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4195) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4196) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4197) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4198) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4199) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok4200) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6075) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6076) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6077) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6078) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6079) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6080) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6081) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6082) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6083) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6084) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6085) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6086) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6087) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6088) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6089) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6090) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6091) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6092) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6093) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6094) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6095) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6096) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6097) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6098) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6099) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6100) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6101) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6102) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6103) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6104) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6105) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6106) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6107) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6108) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6109) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6110) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6111) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6112) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6113) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6114) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6115) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6116) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6117) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6118) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6119) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6120) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6121) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6122) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6123) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6124) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6125) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6126) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6127) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6128) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6129) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6130) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6131) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6132) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6133) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6134) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6135) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6136) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6137) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6138) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6139) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6140) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6141) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6142) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6143) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6144) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6145) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6146) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6147) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6148) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6149) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6150) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6151) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6152) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6153) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6154) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6155) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6156) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6157) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6158) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6159) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6160) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6161) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6162) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6163) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6164) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6165) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6166) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6167) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6168) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6169) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6170) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6171) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6172) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6173) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6174) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6175) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6176) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6177) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6178) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6179) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6180) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6181) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6182) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6183) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6184) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6185) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6186) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6187) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6188) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6189) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6190) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6191) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6192) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6193) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6194) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6195) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6196) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6197) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6198) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6199) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6200) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6201) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6202) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6203) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6204) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6205) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6206) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6207) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6208) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6209) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6210) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6211) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6212) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6213) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6214) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6215) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6216) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6217) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6218) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6219) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6220) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6221) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6222) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6223) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6224) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6225) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6226) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6227) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6228) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6229) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6230) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6231) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6232) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6233) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6234) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6235) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6236) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6237) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6238) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6239) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6240) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6241) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6242) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6243) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6244) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6245) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6246) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6247) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6248) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6249) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6250) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6251) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6252) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6253) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6254) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6255) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6256) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6257) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6258) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6259) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6260) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6261) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6262) {
//   // -305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x80110000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6263) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 305820564510.46084593589468994
//   s21_decimal decimal2 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6264) {
//   // 305820564510.46084593589468994
//   s21_decimal decimal1 = {{0x64B0BF42, 0x2A3886D9, 0x62D0E25A, 0x110000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6265) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6266) {
//   // 5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x160000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6267) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -5077779.6717425679610094186071
//   s21_decimal decimal2 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6268) {
//   // -5077779.6717425679610094186071
//   s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6269) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // 20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6270) {
//   // 20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0xF0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6271) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

// START_TEST(test_is_equal_ok6272) {
//   // -20786105945010.405849433600269
//   s21_decimal decimal1 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   // -20786105945010.405849433600269
//   s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_equal(decimal1, decimal2));
// }

Suite *suite_is_equal(void) {
  Suite *c = suite_create("s21_is_equal_cases");
  TCase *tc_core = tcase_create("s21_is_equal_tc");

  tcase_add_test(tc_core, _is_equal);
  tcase_add_test(tc_core, test_is_equal_ok1);
  tcase_add_test(tc_core, test_is_equal_ok2);
  tcase_add_test(tc_core, test_is_equal_ok3);
  tcase_add_test(tc_core, test_is_equal_ok4);
  tcase_add_test(tc_core, test_is_equal_ok5);
  tcase_add_test(tc_core, test_is_equal_ok6);
  tcase_add_test(tc_core, test_is_equal_ok7);
  tcase_add_test(tc_core, test_is_equal_ok8);
  tcase_add_test(tc_core, test_is_equal_ok9);
  tcase_add_test(tc_core, test_is_equal_ok10);
  tcase_add_test(tc_core, test_is_equal_ok11);
  tcase_add_test(tc_core, test_is_equal_ok12);
  tcase_add_test(tc_core, test_is_equal_ok13);
  tcase_add_test(tc_core, test_is_equal_ok14);
  tcase_add_test(tc_core, test_is_equal_ok15);
  tcase_add_test(tc_core, test_is_equal_ok16);
  tcase_add_test(tc_core, test_is_equal_ok17);
  tcase_add_test(tc_core, test_is_equal_ok18);
  tcase_add_test(tc_core, test_is_equal_ok19);
  tcase_add_test(tc_core, test_is_equal_ok20);
  tcase_add_test(tc_core, test_is_equal_ok21);
  tcase_add_test(tc_core, test_is_equal_ok22);
  tcase_add_test(tc_core, test_is_equal_ok23);
  tcase_add_test(tc_core, test_is_equal_ok24);
  tcase_add_test(tc_core, test_is_equal_ok25);
  tcase_add_test(tc_core, test_is_equal_ok26);
  tcase_add_test(tc_core, test_is_equal_ok27);
  tcase_add_test(tc_core, test_is_equal_ok28);
  tcase_add_test(tc_core, test_is_equal_ok29);
  tcase_add_test(tc_core, test_is_equal_ok30);
  tcase_add_test(tc_core, test_is_equal_ok31);
  tcase_add_test(tc_core, test_is_equal_ok32);
  tcase_add_test(tc_core, test_is_equal_ok33);
  tcase_add_test(tc_core, test_is_equal_ok34);
  tcase_add_test(tc_core, test_is_equal_ok35);
  tcase_add_test(tc_core, test_is_equal_ok36);
  tcase_add_test(tc_core, test_is_equal_ok37);
  tcase_add_test(tc_core, test_is_equal_ok38);
  tcase_add_test(tc_core, test_is_equal_ok39);
  tcase_add_test(tc_core, test_is_equal_ok40);
  tcase_add_test(tc_core, test_is_equal_ok41);
  tcase_add_test(tc_core, test_is_equal_ok42);
  tcase_add_test(tc_core, test_is_equal_ok43);
  tcase_add_test(tc_core, test_is_equal_ok44);
  tcase_add_test(tc_core, test_is_equal_ok45);
  tcase_add_test(tc_core, test_is_equal_ok46);
  tcase_add_test(tc_core, test_is_equal_ok47);
  tcase_add_test(tc_core, test_is_equal_ok48);
  tcase_add_test(tc_core, test_is_equal_ok49);
  tcase_add_test(tc_core, test_is_equal_ok50);
  tcase_add_test(tc_core, test_is_equal_ok51);
  tcase_add_test(tc_core, test_is_equal_ok52);
  tcase_add_test(tc_core, test_is_equal_ok53);
  tcase_add_test(tc_core, test_is_equal_ok54);
  tcase_add_test(tc_core, test_is_equal_ok55);
  tcase_add_test(tc_core, test_is_equal_ok56);
  tcase_add_test(tc_core, test_is_equal_ok57);
  tcase_add_test(tc_core, test_is_equal_ok58);
  tcase_add_test(tc_core, test_is_equal_ok59);
  tcase_add_test(tc_core, test_is_equal_ok60);
  tcase_add_test(tc_core, test_is_equal_ok61);
  tcase_add_test(tc_core, test_is_equal_ok62);
  tcase_add_test(tc_core, test_is_equal_ok63);
  tcase_add_test(tc_core, test_is_equal_ok64);
  tcase_add_test(tc_core, test_is_equal_ok65);
  tcase_add_test(tc_core, test_is_equal_ok66);
  tcase_add_test(tc_core, test_is_equal_ok67);
  tcase_add_test(tc_core, test_is_equal_ok68);
  tcase_add_test(tc_core, test_is_equal_ok69);
  tcase_add_test(tc_core, test_is_equal_ok70);
  tcase_add_test(tc_core, test_is_equal_ok71);
  tcase_add_test(tc_core, test_is_equal_ok72);
  tcase_add_test(tc_core, test_is_equal_ok73);
  tcase_add_test(tc_core, test_is_equal_ok74);
  tcase_add_test(tc_core, test_is_equal_ok75);
  tcase_add_test(tc_core, test_is_equal_ok76);
  tcase_add_test(tc_core, test_is_equal_ok77);
  tcase_add_test(tc_core, test_is_equal_ok78);
  tcase_add_test(tc_core, test_is_equal_ok79);
  tcase_add_test(tc_core, test_is_equal_ok80);
  tcase_add_test(tc_core, test_is_equal_ok81);
  tcase_add_test(tc_core, test_is_equal_ok82);
  tcase_add_test(tc_core, test_is_equal_ok83);
  tcase_add_test(tc_core, test_is_equal_ok84);
  tcase_add_test(tc_core, test_is_equal_ok85);
  tcase_add_test(tc_core, test_is_equal_ok86);
  tcase_add_test(tc_core, test_is_equal_ok87);
  tcase_add_test(tc_core, test_is_equal_ok88);
  tcase_add_test(tc_core, test_is_equal_ok89);
  tcase_add_test(tc_core, test_is_equal_ok90);
  tcase_add_test(tc_core, test_is_equal_ok91);
  tcase_add_test(tc_core, test_is_equal_ok92);
  tcase_add_test(tc_core, test_is_equal_ok93);
  tcase_add_test(tc_core, test_is_equal_ok94);
  tcase_add_test(tc_core, test_is_equal_ok95);
  tcase_add_test(tc_core, test_is_equal_ok96);
  tcase_add_test(tc_core, test_is_equal_ok97);
  tcase_add_test(tc_core, test_is_equal_ok98);
  tcase_add_test(tc_core, test_is_equal_ok99);
  tcase_add_test(tc_core, test_is_equal_ok100);
  tcase_add_test(tc_core, test_is_equal_ok101);
  tcase_add_test(tc_core, test_is_equal_ok102);
  tcase_add_test(tc_core, test_is_equal_ok103);
  tcase_add_test(tc_core, test_is_equal_ok104);
  tcase_add_test(tc_core, test_is_equal_ok105);
  tcase_add_test(tc_core, test_is_equal_ok106);
  tcase_add_test(tc_core, test_is_equal_ok107);
  tcase_add_test(tc_core, test_is_equal_ok108);
  tcase_add_test(tc_core, test_is_equal_ok109);
  tcase_add_test(tc_core, test_is_equal_ok110);
  tcase_add_test(tc_core, test_is_equal_ok111);
  tcase_add_test(tc_core, test_is_equal_ok112);
  tcase_add_test(tc_core, test_is_equal_ok113);
  tcase_add_test(tc_core, test_is_equal_ok114);
  tcase_add_test(tc_core, test_is_equal_ok115);
  tcase_add_test(tc_core, test_is_equal_ok116);
  tcase_add_test(tc_core, test_is_equal_ok117);
  tcase_add_test(tc_core, test_is_equal_ok118);
  tcase_add_test(tc_core, test_is_equal_ok119);
  tcase_add_test(tc_core, test_is_equal_ok120);
  tcase_add_test(tc_core, test_is_equal_ok121);
  tcase_add_test(tc_core, test_is_equal_ok122);
  tcase_add_test(tc_core, test_is_equal_ok123);
  tcase_add_test(tc_core, test_is_equal_ok124);
  tcase_add_test(tc_core, test_is_equal_ok125);
  tcase_add_test(tc_core, test_is_equal_ok126);
  tcase_add_test(tc_core, test_is_equal_ok127);
  tcase_add_test(tc_core, test_is_equal_ok128);
  tcase_add_test(tc_core, test_is_equal_ok129);
  tcase_add_test(tc_core, test_is_equal_ok130);
  tcase_add_test(tc_core, test_is_equal_ok131);
  tcase_add_test(tc_core, test_is_equal_ok132);
  tcase_add_test(tc_core, test_is_equal_ok133);
  tcase_add_test(tc_core, test_is_equal_ok134);
  tcase_add_test(tc_core, test_is_equal_ok135);
  tcase_add_test(tc_core, test_is_equal_ok136);
  tcase_add_test(tc_core, test_is_equal_ok137);
  tcase_add_test(tc_core, test_is_equal_ok138);
  tcase_add_test(tc_core, test_is_equal_ok139);
  tcase_add_test(tc_core, test_is_equal_ok140);
  tcase_add_test(tc_core, test_is_equal_ok141);
  tcase_add_test(tc_core, test_is_equal_ok142);
  tcase_add_test(tc_core, test_is_equal_ok143);
  tcase_add_test(tc_core, test_is_equal_ok144);
  tcase_add_test(tc_core, test_is_equal_ok145);
  tcase_add_test(tc_core, test_is_equal_ok146);
  tcase_add_test(tc_core, test_is_equal_ok147);
  tcase_add_test(tc_core, test_is_equal_ok148);
  tcase_add_test(tc_core, test_is_equal_ok149);
  tcase_add_test(tc_core, test_is_equal_ok150);
  tcase_add_test(tc_core, test_is_equal_ok151);
  tcase_add_test(tc_core, test_is_equal_ok152);
  tcase_add_test(tc_core, test_is_equal_ok153);
  tcase_add_test(tc_core, test_is_equal_ok154);
  tcase_add_test(tc_core, test_is_equal_ok155);
  tcase_add_test(tc_core, test_is_equal_ok156);
  tcase_add_test(tc_core, test_is_equal_ok157);
  tcase_add_test(tc_core, test_is_equal_ok158);
  tcase_add_test(tc_core, test_is_equal_ok159);
  tcase_add_test(tc_core, test_is_equal_ok160);
  tcase_add_test(tc_core, test_is_equal_ok161);
  tcase_add_test(tc_core, test_is_equal_ok162);
  tcase_add_test(tc_core, test_is_equal_ok163);
  tcase_add_test(tc_core, test_is_equal_ok164);
  tcase_add_test(tc_core, test_is_equal_ok165);
  tcase_add_test(tc_core, test_is_equal_ok166);
  tcase_add_test(tc_core, test_is_equal_ok167);
  tcase_add_test(tc_core, test_is_equal_ok168);
  tcase_add_test(tc_core, test_is_equal_ok169);
  tcase_add_test(tc_core, test_is_equal_ok170);
  tcase_add_test(tc_core, test_is_equal_ok171);
  tcase_add_test(tc_core, test_is_equal_ok172);
  tcase_add_test(tc_core, test_is_equal_ok173);
  tcase_add_test(tc_core, test_is_equal_ok174);
  tcase_add_test(tc_core, test_is_equal_ok175);
  tcase_add_test(tc_core, test_is_equal_ok176);
  tcase_add_test(tc_core, test_is_equal_ok177);
  tcase_add_test(tc_core, test_is_equal_ok178);
  tcase_add_test(tc_core, test_is_equal_ok179);
  tcase_add_test(tc_core, test_is_equal_ok180);
  tcase_add_test(tc_core, test_is_equal_ok181);
  tcase_add_test(tc_core, test_is_equal_ok182);
  tcase_add_test(tc_core, test_is_equal_ok183);
  tcase_add_test(tc_core, test_is_equal_ok184);
  tcase_add_test(tc_core, test_is_equal_ok185);
  tcase_add_test(tc_core, test_is_equal_ok186);
  tcase_add_test(tc_core, test_is_equal_ok187);
  tcase_add_test(tc_core, test_is_equal_ok188);
  tcase_add_test(tc_core, test_is_equal_ok189);
  tcase_add_test(tc_core, test_is_equal_ok190);
  tcase_add_test(tc_core, test_is_equal_ok191);
  tcase_add_test(tc_core, test_is_equal_ok192);
  tcase_add_test(tc_core, test_is_equal_ok193);
  tcase_add_test(tc_core, test_is_equal_ok194);
  tcase_add_test(tc_core, test_is_equal_ok195);
  tcase_add_test(tc_core, test_is_equal_ok196);
  tcase_add_test(tc_core, test_is_equal_ok197);
  tcase_add_test(tc_core, test_is_equal_ok198);
  tcase_add_test(tc_core, test_is_equal_ok199);
  tcase_add_test(tc_core, test_is_equal_ok200);
  // tcase_add_test(tc_core, test_is_equal_ok1000);
  // tcase_add_test(tc_core, test_is_equal_ok1001);
  // tcase_add_test(tc_core, test_is_equal_ok1002);
  // tcase_add_test(tc_core, test_is_equal_ok1003);
  // tcase_add_test(tc_core, test_is_equal_ok1004);
  // tcase_add_test(tc_core, test_is_equal_ok1005);
  // tcase_add_test(tc_core, test_is_equal_ok1006);
  // tcase_add_test(tc_core, test_is_equal_ok1007);
  // tcase_add_test(tc_core, test_is_equal_ok1008);
  // tcase_add_test(tc_core, test_is_equal_ok1009);
  // tcase_add_test(tc_core, test_is_equal_ok1010);
  // tcase_add_test(tc_core, test_is_equal_ok1011);
  // tcase_add_test(tc_core, test_is_equal_ok1012);
  // tcase_add_test(tc_core, test_is_equal_ok1013);
  // tcase_add_test(tc_core, test_is_equal_ok1014);
  // tcase_add_test(tc_core, test_is_equal_ok1015);
  // tcase_add_test(tc_core, test_is_equal_ok1016);
  // tcase_add_test(tc_core, test_is_equal_ok1017);
  // tcase_add_test(tc_core, test_is_equal_ok1018);
  // tcase_add_test(tc_core, test_is_equal_ok1019);
  // tcase_add_test(tc_core, test_is_equal_ok1020);
  // tcase_add_test(tc_core, test_is_equal_ok1021);
  // tcase_add_test(tc_core, test_is_equal_ok1022);
  // tcase_add_test(tc_core, test_is_equal_ok1023);
  // tcase_add_test(tc_core, test_is_equal_ok1024);
  // tcase_add_test(tc_core, test_is_equal_ok1025);
  // tcase_add_test(tc_core, test_is_equal_ok1026);
  // tcase_add_test(tc_core, test_is_equal_ok1027);
  // tcase_add_test(tc_core, test_is_equal_ok1028);
  // tcase_add_test(tc_core, test_is_equal_ok1029);
  // tcase_add_test(tc_core, test_is_equal_ok1030);
  // tcase_add_test(tc_core, test_is_equal_ok1031);
  // tcase_add_test(tc_core, test_is_equal_ok1032);
  // tcase_add_test(tc_core, test_is_equal_ok1033);
  // tcase_add_test(tc_core, test_is_equal_ok1034);
  // tcase_add_test(tc_core, test_is_equal_ok1035);
  // tcase_add_test(tc_core, test_is_equal_ok1036);
  // tcase_add_test(tc_core, test_is_equal_ok1037);
  // tcase_add_test(tc_core, test_is_equal_ok1038);
  // tcase_add_test(tc_core, test_is_equal_ok1039);
  // tcase_add_test(tc_core, test_is_equal_ok1040);
  // tcase_add_test(tc_core, test_is_equal_ok1041);
  // tcase_add_test(tc_core, test_is_equal_ok1042);
  // tcase_add_test(tc_core, test_is_equal_ok1043);
  // tcase_add_test(tc_core, test_is_equal_ok1044);
  // tcase_add_test(tc_core, test_is_equal_ok1045);
  // tcase_add_test(tc_core, test_is_equal_ok1046);
  // tcase_add_test(tc_core, test_is_equal_ok1047);
  // tcase_add_test(tc_core, test_is_equal_ok1048);
  // tcase_add_test(tc_core, test_is_equal_ok1049);
  // tcase_add_test(tc_core, test_is_equal_ok1050);
  // tcase_add_test(tc_core, test_is_equal_ok1051);
  // tcase_add_test(tc_core, test_is_equal_ok1052);
  // tcase_add_test(tc_core, test_is_equal_ok1053);
  // tcase_add_test(tc_core, test_is_equal_ok1054);
  // tcase_add_test(tc_core, test_is_equal_ok1055);
  // tcase_add_test(tc_core, test_is_equal_ok1056);
  // tcase_add_test(tc_core, test_is_equal_ok1057);
  // tcase_add_test(tc_core, test_is_equal_ok1058);
  // tcase_add_test(tc_core, test_is_equal_ok1059);
  // tcase_add_test(tc_core, test_is_equal_ok1060);
  // tcase_add_test(tc_core, test_is_equal_ok1061);
  // tcase_add_test(tc_core, test_is_equal_ok1062);
  // tcase_add_test(tc_core, test_is_equal_ok1063);
  // tcase_add_test(tc_core, test_is_equal_ok1064);
  // tcase_add_test(tc_core, test_is_equal_ok1065);
  // tcase_add_test(tc_core, test_is_equal_ok1066);
  // tcase_add_test(tc_core, test_is_equal_ok1067);
  // tcase_add_test(tc_core, test_is_equal_ok1068);
  // tcase_add_test(tc_core, test_is_equal_ok1069);
  // tcase_add_test(tc_core, test_is_equal_ok1070);
  // tcase_add_test(tc_core, test_is_equal_ok1071);
  // tcase_add_test(tc_core, test_is_equal_ok1072);
  // tcase_add_test(tc_core, test_is_equal_ok1073);
  // tcase_add_test(tc_core, test_is_equal_ok1074);
  // tcase_add_test(tc_core, test_is_equal_ok1075);
  // tcase_add_test(tc_core, test_is_equal_ok1076);
  // tcase_add_test(tc_core, test_is_equal_ok1077);
  // tcase_add_test(tc_core, test_is_equal_ok1078);
  // tcase_add_test(tc_core, test_is_equal_ok1079);
  // tcase_add_test(tc_core, test_is_equal_ok1080);
  // tcase_add_test(tc_core, test_is_equal_ok1081);
  // tcase_add_test(tc_core, test_is_equal_ok1082);
  // tcase_add_test(tc_core, test_is_equal_ok1083);
  // tcase_add_test(tc_core, test_is_equal_ok1084);
  // tcase_add_test(tc_core, test_is_equal_ok1085);
  // tcase_add_test(tc_core, test_is_equal_ok1086);
  // tcase_add_test(tc_core, test_is_equal_ok1087);
  // tcase_add_test(tc_core, test_is_equal_ok1088);
  // tcase_add_test(tc_core, test_is_equal_ok1089);
  // tcase_add_test(tc_core, test_is_equal_ok1090);
  // tcase_add_test(tc_core, test_is_equal_ok1091);
  // tcase_add_test(tc_core, test_is_equal_ok1092);
  // tcase_add_test(tc_core, test_is_equal_ok1093);
  // tcase_add_test(tc_core, test_is_equal_ok1094);
  // tcase_add_test(tc_core, test_is_equal_ok1095);
  // tcase_add_test(tc_core, test_is_equal_ok1096);
  // tcase_add_test(tc_core, test_is_equal_ok1097);
  // tcase_add_test(tc_core, test_is_equal_ok1098);
  // tcase_add_test(tc_core, test_is_equal_ok1099);
  // tcase_add_test(tc_core, test_is_equal_ok1100);
  // tcase_add_test(tc_core, test_is_equal_ok1101);
  // tcase_add_test(tc_core, test_is_equal_ok1102);
  // tcase_add_test(tc_core, test_is_equal_ok1103);
  // tcase_add_test(tc_core, test_is_equal_ok1104);
  // tcase_add_test(tc_core, test_is_equal_ok1105);
  // tcase_add_test(tc_core, test_is_equal_ok1106);
  // tcase_add_test(tc_core, test_is_equal_ok1107);
  // tcase_add_test(tc_core, test_is_equal_ok1108);
  // tcase_add_test(tc_core, test_is_equal_ok1109);
  // tcase_add_test(tc_core, test_is_equal_ok1110);
  // tcase_add_test(tc_core, test_is_equal_ok1111);
  // tcase_add_test(tc_core, test_is_equal_ok1112);
  // tcase_add_test(tc_core, test_is_equal_ok1113);
  // tcase_add_test(tc_core, test_is_equal_ok1114);
  // tcase_add_test(tc_core, test_is_equal_ok1115);
  // tcase_add_test(tc_core, test_is_equal_ok1116);
  // tcase_add_test(tc_core, test_is_equal_ok1117);
  // tcase_add_test(tc_core, test_is_equal_ok1118);
  // tcase_add_test(tc_core, test_is_equal_ok1119);
  // tcase_add_test(tc_core, test_is_equal_ok1120);
  // tcase_add_test(tc_core, test_is_equal_ok1121);
  // tcase_add_test(tc_core, test_is_equal_ok1122);
  // tcase_add_test(tc_core, test_is_equal_ok1123);
  // tcase_add_test(tc_core, test_is_equal_ok1124);
  // tcase_add_test(tc_core, test_is_equal_ok1125);
  // tcase_add_test(tc_core, test_is_equal_ok1126);
  // tcase_add_test(tc_core, test_is_equal_ok1127);
  // tcase_add_test(tc_core, test_is_equal_ok1128);
  // tcase_add_test(tc_core, test_is_equal_ok1129);
  // tcase_add_test(tc_core, test_is_equal_ok1130);
  // tcase_add_test(tc_core, test_is_equal_ok1131);
  // tcase_add_test(tc_core, test_is_equal_ok1132);
  // tcase_add_test(tc_core, test_is_equal_ok1133);
  // tcase_add_test(tc_core, test_is_equal_ok1134);
  // tcase_add_test(tc_core, test_is_equal_ok1135);
  // tcase_add_test(tc_core, test_is_equal_ok1136);
  // tcase_add_test(tc_core, test_is_equal_ok1137);
  // tcase_add_test(tc_core, test_is_equal_ok1138);
  // tcase_add_test(tc_core, test_is_equal_ok1139);
  // tcase_add_test(tc_core, test_is_equal_ok1140);
  // tcase_add_test(tc_core, test_is_equal_ok1141);
  // tcase_add_test(tc_core, test_is_equal_ok1142);
  // tcase_add_test(tc_core, test_is_equal_ok1143);
  // tcase_add_test(tc_core, test_is_equal_ok1144);
  // tcase_add_test(tc_core, test_is_equal_ok1145);
  // tcase_add_test(tc_core, test_is_equal_ok1146);
  // tcase_add_test(tc_core, test_is_equal_ok1147);
  // tcase_add_test(tc_core, test_is_equal_ok1148);
  // tcase_add_test(tc_core, test_is_equal_ok1149);
  // tcase_add_test(tc_core, test_is_equal_ok1150);
  // tcase_add_test(tc_core, test_is_equal_ok1151);
  // tcase_add_test(tc_core, test_is_equal_ok1152);
  // tcase_add_test(tc_core, test_is_equal_ok1153);
  // tcase_add_test(tc_core, test_is_equal_ok1154);
  // tcase_add_test(tc_core, test_is_equal_ok1155);
  // tcase_add_test(tc_core, test_is_equal_ok1156);
  // tcase_add_test(tc_core, test_is_equal_ok1157);
  // tcase_add_test(tc_core, test_is_equal_ok1158);
  // tcase_add_test(tc_core, test_is_equal_ok1159);
  // tcase_add_test(tc_core, test_is_equal_ok1160);
  // tcase_add_test(tc_core, test_is_equal_ok1161);
  // tcase_add_test(tc_core, test_is_equal_ok1162);
  // tcase_add_test(tc_core, test_is_equal_ok1163);
  // tcase_add_test(tc_core, test_is_equal_ok1164);
  // tcase_add_test(tc_core, test_is_equal_ok1165);
  // tcase_add_test(tc_core, test_is_equal_ok1166);
  // tcase_add_test(tc_core, test_is_equal_ok1167);
  // tcase_add_test(tc_core, test_is_equal_ok1168);
  // tcase_add_test(tc_core, test_is_equal_ok1169);
  // tcase_add_test(tc_core, test_is_equal_ok1170);
  // tcase_add_test(tc_core, test_is_equal_ok1171);
  // tcase_add_test(tc_core, test_is_equal_ok1172);
  // tcase_add_test(tc_core, test_is_equal_ok1173);
  // tcase_add_test(tc_core, test_is_equal_ok1174);
  // tcase_add_test(tc_core, test_is_equal_ok1175);
  // tcase_add_test(tc_core, test_is_equal_ok1176);
  // tcase_add_test(tc_core, test_is_equal_ok1177);
  // tcase_add_test(tc_core, test_is_equal_ok1178);
  // tcase_add_test(tc_core, test_is_equal_ok1179);
  // tcase_add_test(tc_core, test_is_equal_ok1180);
  // tcase_add_test(tc_core, test_is_equal_ok1181);
  // tcase_add_test(tc_core, test_is_equal_ok1182);
  // tcase_add_test(tc_core, test_is_equal_ok1183);
  // tcase_add_test(tc_core, test_is_equal_ok1184);
  // tcase_add_test(tc_core, test_is_equal_ok1185);
  // tcase_add_test(tc_core, test_is_equal_ok1186);
  // tcase_add_test(tc_core, test_is_equal_ok1187);
  // tcase_add_test(tc_core, test_is_equal_ok1188);
  // tcase_add_test(tc_core, test_is_equal_ok1189);
  // tcase_add_test(tc_core, test_is_equal_ok1190);
  // tcase_add_test(tc_core, test_is_equal_ok1191);
  // tcase_add_test(tc_core, test_is_equal_ok1192);
  // tcase_add_test(tc_core, test_is_equal_ok1193);
  // tcase_add_test(tc_core, test_is_equal_ok1194);
  // tcase_add_test(tc_core, test_is_equal_ok1195);
  // tcase_add_test(tc_core, test_is_equal_ok1196);
  // tcase_add_test(tc_core, test_is_equal_ok1197);
  // tcase_add_test(tc_core, test_is_equal_ok1198);
  // tcase_add_test(tc_core, test_is_equal_ok1199);
  // tcase_add_test(tc_core, test_is_equal_ok1200);
  // tcase_add_test(tc_core, test_is_equal_ok2000);
  // tcase_add_test(tc_core, test_is_equal_ok2001);
  // tcase_add_test(tc_core, test_is_equal_ok2002);
  // tcase_add_test(tc_core, test_is_equal_ok2003);
  // tcase_add_test(tc_core, test_is_equal_ok2004);
  // tcase_add_test(tc_core, test_is_equal_ok2005);
  // tcase_add_test(tc_core, test_is_equal_ok2006);
  // tcase_add_test(tc_core, test_is_equal_ok2007);
  // tcase_add_test(tc_core, test_is_equal_ok2008);
  // tcase_add_test(tc_core, test_is_equal_ok2009);
  // tcase_add_test(tc_core, test_is_equal_ok2010);
  // tcase_add_test(tc_core, test_is_equal_ok2011);
  // tcase_add_test(tc_core, test_is_equal_ok2012);
  // tcase_add_test(tc_core, test_is_equal_ok2013);
  // tcase_add_test(tc_core, test_is_equal_ok2014);
  // tcase_add_test(tc_core, test_is_equal_ok2015);
  // tcase_add_test(tc_core, test_is_equal_ok2016);
  // tcase_add_test(tc_core, test_is_equal_ok2017);
  // tcase_add_test(tc_core, test_is_equal_ok2018);
  // tcase_add_test(tc_core, test_is_equal_ok2019);
  // tcase_add_test(tc_core, test_is_equal_ok2020);
  // tcase_add_test(tc_core, test_is_equal_ok2021);
  // tcase_add_test(tc_core, test_is_equal_ok2022);
  // tcase_add_test(tc_core, test_is_equal_ok2023);
  // tcase_add_test(tc_core, test_is_equal_ok2024);
  // tcase_add_test(tc_core, test_is_equal_ok2025);
  // tcase_add_test(tc_core, test_is_equal_ok2026);
  // tcase_add_test(tc_core, test_is_equal_ok2027);
  // tcase_add_test(tc_core, test_is_equal_ok2028);
  // tcase_add_test(tc_core, test_is_equal_ok2029);
  // tcase_add_test(tc_core, test_is_equal_ok2030);
  // tcase_add_test(tc_core, test_is_equal_ok2031);
  // tcase_add_test(tc_core, test_is_equal_ok2032);
  // tcase_add_test(tc_core, test_is_equal_ok2033);
  // tcase_add_test(tc_core, test_is_equal_ok2034);
  // tcase_add_test(tc_core, test_is_equal_ok2035);
  // tcase_add_test(tc_core, test_is_equal_ok2036);
  // tcase_add_test(tc_core, test_is_equal_ok2037);
  // tcase_add_test(tc_core, test_is_equal_ok2038);
  // tcase_add_test(tc_core, test_is_equal_ok2039);
  // tcase_add_test(tc_core, test_is_equal_ok2040);
  // tcase_add_test(tc_core, test_is_equal_ok2041);
  // tcase_add_test(tc_core, test_is_equal_ok2042);
  // tcase_add_test(tc_core, test_is_equal_ok2043);
  // tcase_add_test(tc_core, test_is_equal_ok2044);
  // tcase_add_test(tc_core, test_is_equal_ok2045);
  // tcase_add_test(tc_core, test_is_equal_ok2046);
  // tcase_add_test(tc_core, test_is_equal_ok2047);
  // tcase_add_test(tc_core, test_is_equal_ok2048);
  // tcase_add_test(tc_core, test_is_equal_ok2049);
  // tcase_add_test(tc_core, test_is_equal_ok2050);
  // tcase_add_test(tc_core, test_is_equal_ok2051);
  // tcase_add_test(tc_core, test_is_equal_ok2052);
  // tcase_add_test(tc_core, test_is_equal_ok2053);
  // tcase_add_test(tc_core, test_is_equal_ok2054);
  // tcase_add_test(tc_core, test_is_equal_ok2055);
  // tcase_add_test(tc_core, test_is_equal_ok2056);
  // tcase_add_test(tc_core, test_is_equal_ok2057);
  // tcase_add_test(tc_core, test_is_equal_ok2058);
  // tcase_add_test(tc_core, test_is_equal_ok2059);
  // tcase_add_test(tc_core, test_is_equal_ok2060);
  // tcase_add_test(tc_core, test_is_equal_ok2061);
  // tcase_add_test(tc_core, test_is_equal_ok2062);
  // tcase_add_test(tc_core, test_is_equal_ok2063);
  // tcase_add_test(tc_core, test_is_equal_ok2064);
  // tcase_add_test(tc_core, test_is_equal_ok2065);
  // tcase_add_test(tc_core, test_is_equal_ok2066);
  // tcase_add_test(tc_core, test_is_equal_ok2067);
  // tcase_add_test(tc_core, test_is_equal_ok2068);
  // tcase_add_test(tc_core, test_is_equal_ok2069);
  // tcase_add_test(tc_core, test_is_equal_ok2070);
  // tcase_add_test(tc_core, test_is_equal_ok2071);
  // tcase_add_test(tc_core, test_is_equal_ok2072);
  // tcase_add_test(tc_core, test_is_equal_ok2073);
  // tcase_add_test(tc_core, test_is_equal_ok2074);
  // tcase_add_test(tc_core, test_is_equal_ok2075);
  // tcase_add_test(tc_core, test_is_equal_ok2076);
  // tcase_add_test(tc_core, test_is_equal_ok2077);
  // tcase_add_test(tc_core, test_is_equal_ok2078);
  // tcase_add_test(tc_core, test_is_equal_ok2079);
  // tcase_add_test(tc_core, test_is_equal_ok2080);
  // tcase_add_test(tc_core, test_is_equal_ok2081);
  // tcase_add_test(tc_core, test_is_equal_ok2082);
  // tcase_add_test(tc_core, test_is_equal_ok2083);
  // tcase_add_test(tc_core, test_is_equal_ok2084);
  // tcase_add_test(tc_core, test_is_equal_ok2085);
  // tcase_add_test(tc_core, test_is_equal_ok2086);
  // tcase_add_test(tc_core, test_is_equal_ok2087);
  // tcase_add_test(tc_core, test_is_equal_ok2088);
  // tcase_add_test(tc_core, test_is_equal_ok2089);
  // tcase_add_test(tc_core, test_is_equal_ok2090);
  // tcase_add_test(tc_core, test_is_equal_ok2091);
  // tcase_add_test(tc_core, test_is_equal_ok2092);
  // tcase_add_test(tc_core, test_is_equal_ok2093);
  // tcase_add_test(tc_core, test_is_equal_ok2094);
  // tcase_add_test(tc_core, test_is_equal_ok2095);
  // tcase_add_test(tc_core, test_is_equal_ok2096);
  // tcase_add_test(tc_core, test_is_equal_ok2097);
  // tcase_add_test(tc_core, test_is_equal_ok2098);
  // tcase_add_test(tc_core, test_is_equal_ok2099);
  // tcase_add_test(tc_core, test_is_equal_ok2100);
  // tcase_add_test(tc_core, test_is_equal_ok2101);
  // tcase_add_test(tc_core, test_is_equal_ok2102);
  // tcase_add_test(tc_core, test_is_equal_ok2103);
  // tcase_add_test(tc_core, test_is_equal_ok2104);
  // tcase_add_test(tc_core, test_is_equal_ok2105);
  // tcase_add_test(tc_core, test_is_equal_ok2106);
  // tcase_add_test(tc_core, test_is_equal_ok2107);
  // tcase_add_test(tc_core, test_is_equal_ok2108);
  // tcase_add_test(tc_core, test_is_equal_ok2109);
  // tcase_add_test(tc_core, test_is_equal_ok2110);
  // tcase_add_test(tc_core, test_is_equal_ok2111);
  // tcase_add_test(tc_core, test_is_equal_ok2112);
  // tcase_add_test(tc_core, test_is_equal_ok2113);
  // tcase_add_test(tc_core, test_is_equal_ok2114);
  // tcase_add_test(tc_core, test_is_equal_ok2115);
  // tcase_add_test(tc_core, test_is_equal_ok2116);
  // tcase_add_test(tc_core, test_is_equal_ok2117);
  // tcase_add_test(tc_core, test_is_equal_ok2118);
  // tcase_add_test(tc_core, test_is_equal_ok2119);
  // tcase_add_test(tc_core, test_is_equal_ok2120);
  // tcase_add_test(tc_core, test_is_equal_ok2121);
  // tcase_add_test(tc_core, test_is_equal_ok2122);
  // tcase_add_test(tc_core, test_is_equal_ok2123);
  // tcase_add_test(tc_core, test_is_equal_ok2124);
  // tcase_add_test(tc_core, test_is_equal_ok2125);
  // tcase_add_test(tc_core, test_is_equal_ok2126);
  // tcase_add_test(tc_core, test_is_equal_ok2127);
  // tcase_add_test(tc_core, test_is_equal_ok2128);
  // tcase_add_test(tc_core, test_is_equal_ok2129);
  // tcase_add_test(tc_core, test_is_equal_ok2130);
  // tcase_add_test(tc_core, test_is_equal_ok2131);
  // tcase_add_test(tc_core, test_is_equal_ok2132);
  // tcase_add_test(tc_core, test_is_equal_ok2133);
  // tcase_add_test(tc_core, test_is_equal_ok2134);
  // tcase_add_test(tc_core, test_is_equal_ok2135);
  // tcase_add_test(tc_core, test_is_equal_ok2136);
  // tcase_add_test(tc_core, test_is_equal_ok2137);
  // tcase_add_test(tc_core, test_is_equal_ok2138);
  // tcase_add_test(tc_core, test_is_equal_ok2139);
  // tcase_add_test(tc_core, test_is_equal_ok2140);
  // tcase_add_test(tc_core, test_is_equal_ok2141);
  // tcase_add_test(tc_core, test_is_equal_ok2142);
  // tcase_add_test(tc_core, test_is_equal_ok2143);
  // tcase_add_test(tc_core, test_is_equal_ok2144);
  // tcase_add_test(tc_core, test_is_equal_ok2145);
  // tcase_add_test(tc_core, test_is_equal_ok2146);
  // tcase_add_test(tc_core, test_is_equal_ok2147);
  // tcase_add_test(tc_core, test_is_equal_ok2148);
  // tcase_add_test(tc_core, test_is_equal_ok2149);
  // tcase_add_test(tc_core, test_is_equal_ok2150);
  // tcase_add_test(tc_core, test_is_equal_ok2151);
  // tcase_add_test(tc_core, test_is_equal_ok2152);
  // tcase_add_test(tc_core, test_is_equal_ok2153);
  // tcase_add_test(tc_core, test_is_equal_ok2154);
  // tcase_add_test(tc_core, test_is_equal_ok2155);
  // tcase_add_test(tc_core, test_is_equal_ok2156);
  // tcase_add_test(tc_core, test_is_equal_ok2157);
  // tcase_add_test(tc_core, test_is_equal_ok2158);
  // tcase_add_test(tc_core, test_is_equal_ok2159);
  // tcase_add_test(tc_core, test_is_equal_ok2160);
  // tcase_add_test(tc_core, test_is_equal_ok2161);
  // tcase_add_test(tc_core, test_is_equal_ok2162);
  // tcase_add_test(tc_core, test_is_equal_ok2163);
  // tcase_add_test(tc_core, test_is_equal_ok2164);
  // tcase_add_test(tc_core, test_is_equal_ok2165);
  // tcase_add_test(tc_core, test_is_equal_ok2166);
  // tcase_add_test(tc_core, test_is_equal_ok2167);
  // tcase_add_test(tc_core, test_is_equal_ok2168);
  // tcase_add_test(tc_core, test_is_equal_ok2169);
  // tcase_add_test(tc_core, test_is_equal_ok2170);
  // tcase_add_test(tc_core, test_is_equal_ok2171);
  // tcase_add_test(tc_core, test_is_equal_ok2172);
  // tcase_add_test(tc_core, test_is_equal_ok2173);
  // tcase_add_test(tc_core, test_is_equal_ok2174);
  // tcase_add_test(tc_core, test_is_equal_ok2175);
  // tcase_add_test(tc_core, test_is_equal_ok2176);
  // tcase_add_test(tc_core, test_is_equal_ok2177);
  // tcase_add_test(tc_core, test_is_equal_ok2178);
  // tcase_add_test(tc_core, test_is_equal_ok2179);
  // tcase_add_test(tc_core, test_is_equal_ok2180);
  // tcase_add_test(tc_core, test_is_equal_ok2181);
  // tcase_add_test(tc_core, test_is_equal_ok2182);
  // tcase_add_test(tc_core, test_is_equal_ok2183);
  // tcase_add_test(tc_core, test_is_equal_ok2184);
  // tcase_add_test(tc_core, test_is_equal_ok2185);
  // tcase_add_test(tc_core, test_is_equal_ok2186);
  // tcase_add_test(tc_core, test_is_equal_ok2187);
  // tcase_add_test(tc_core, test_is_equal_ok2188);
  // tcase_add_test(tc_core, test_is_equal_ok2189);
  // tcase_add_test(tc_core, test_is_equal_ok2190);
  // tcase_add_test(tc_core, test_is_equal_ok2191);
  // tcase_add_test(tc_core, test_is_equal_ok2192);
  // tcase_add_test(tc_core, test_is_equal_ok2193);
  // tcase_add_test(tc_core, test_is_equal_ok2194);
  // tcase_add_test(tc_core, test_is_equal_ok2195);
  // tcase_add_test(tc_core, test_is_equal_ok2196);
  // tcase_add_test(tc_core, test_is_equal_ok2197);
  // tcase_add_test(tc_core, test_is_equal_ok2198);
  // tcase_add_test(tc_core, test_is_equal_ok2199);
  // tcase_add_test(tc_core, test_is_equal_ok2200);
  // tcase_add_test(tc_core, test_is_equal_ok4000);
  // tcase_add_test(tc_core, test_is_equal_ok4001);
  // tcase_add_test(tc_core, test_is_equal_ok4002);
  // tcase_add_test(tc_core, test_is_equal_ok4003);
  // tcase_add_test(tc_core, test_is_equal_ok4004);
  // tcase_add_test(tc_core, test_is_equal_ok4005);
  // tcase_add_test(tc_core, test_is_equal_ok4006);
  // tcase_add_test(tc_core, test_is_equal_ok4007);
  // tcase_add_test(tc_core, test_is_equal_ok4008);
  // tcase_add_test(tc_core, test_is_equal_ok4009);
  // tcase_add_test(tc_core, test_is_equal_ok4010);
  // tcase_add_test(tc_core, test_is_equal_ok4011);
  // tcase_add_test(tc_core, test_is_equal_ok4012);
  // tcase_add_test(tc_core, test_is_equal_ok4013);
  // tcase_add_test(tc_core, test_is_equal_ok4014);
  // tcase_add_test(tc_core, test_is_equal_ok4015);
  // tcase_add_test(tc_core, test_is_equal_ok4016);
  // tcase_add_test(tc_core, test_is_equal_ok4017);
  // tcase_add_test(tc_core, test_is_equal_ok4018);
  // tcase_add_test(tc_core, test_is_equal_ok4019);
  // tcase_add_test(tc_core, test_is_equal_ok4020);
  // tcase_add_test(tc_core, test_is_equal_ok4021);
  // tcase_add_test(tc_core, test_is_equal_ok4022);
  // tcase_add_test(tc_core, test_is_equal_ok4023);
  // tcase_add_test(tc_core, test_is_equal_ok4024);
  // tcase_add_test(tc_core, test_is_equal_ok4025);
  // tcase_add_test(tc_core, test_is_equal_ok4026);
  // tcase_add_test(tc_core, test_is_equal_ok4027);
  // tcase_add_test(tc_core, test_is_equal_ok4028);
  // tcase_add_test(tc_core, test_is_equal_ok4029);
  // tcase_add_test(tc_core, test_is_equal_ok4030);
  // tcase_add_test(tc_core, test_is_equal_ok4031);
  // tcase_add_test(tc_core, test_is_equal_ok4032);
  // tcase_add_test(tc_core, test_is_equal_ok4033);
  // tcase_add_test(tc_core, test_is_equal_ok4034);
  // tcase_add_test(tc_core, test_is_equal_ok4035);
  // tcase_add_test(tc_core, test_is_equal_ok4036);
  // tcase_add_test(tc_core, test_is_equal_ok4037);
  // tcase_add_test(tc_core, test_is_equal_ok4038);
  // tcase_add_test(tc_core, test_is_equal_ok4039);
  // tcase_add_test(tc_core, test_is_equal_ok4040);
  // tcase_add_test(tc_core, test_is_equal_ok4041);
  // tcase_add_test(tc_core, test_is_equal_ok4042);
  // tcase_add_test(tc_core, test_is_equal_ok4043);
  // tcase_add_test(tc_core, test_is_equal_ok4044);
  // tcase_add_test(tc_core, test_is_equal_ok4045);
  // tcase_add_test(tc_core, test_is_equal_ok4046);
  // tcase_add_test(tc_core, test_is_equal_ok4047);
  // tcase_add_test(tc_core, test_is_equal_ok4048);
  // tcase_add_test(tc_core, test_is_equal_ok4049);
  // tcase_add_test(tc_core, test_is_equal_ok4050);
  // tcase_add_test(tc_core, test_is_equal_ok4051);
  // tcase_add_test(tc_core, test_is_equal_ok4052);
  // tcase_add_test(tc_core, test_is_equal_ok4053);
  // tcase_add_test(tc_core, test_is_equal_ok4054);
  // tcase_add_test(tc_core, test_is_equal_ok4055);
  // tcase_add_test(tc_core, test_is_equal_ok4056);
  // tcase_add_test(tc_core, test_is_equal_ok4057);
  // tcase_add_test(tc_core, test_is_equal_ok4058);
  // tcase_add_test(tc_core, test_is_equal_ok4059);
  // tcase_add_test(tc_core, test_is_equal_ok4060);
  // tcase_add_test(tc_core, test_is_equal_ok4061);
  // tcase_add_test(tc_core, test_is_equal_ok4062);
  // tcase_add_test(tc_core, test_is_equal_ok4063);
  // tcase_add_test(tc_core, test_is_equal_ok4064);
  // tcase_add_test(tc_core, test_is_equal_ok4065);
  // tcase_add_test(tc_core, test_is_equal_ok4066);
  // tcase_add_test(tc_core, test_is_equal_ok4067);
  // tcase_add_test(tc_core, test_is_equal_ok4068);
  // tcase_add_test(tc_core, test_is_equal_ok4069);
  // tcase_add_test(tc_core, test_is_equal_ok4070);
  // tcase_add_test(tc_core, test_is_equal_ok4071);
  // tcase_add_test(tc_core, test_is_equal_ok4072);
  // tcase_add_test(tc_core, test_is_equal_ok4073);
  // tcase_add_test(tc_core, test_is_equal_ok4074);
  // tcase_add_test(tc_core, test_is_equal_ok4075);
  // tcase_add_test(tc_core, test_is_equal_ok4076);
  // tcase_add_test(tc_core, test_is_equal_ok4077);
  // tcase_add_test(tc_core, test_is_equal_ok4078);
  // tcase_add_test(tc_core, test_is_equal_ok4079);
  // tcase_add_test(tc_core, test_is_equal_ok4080);
  // tcase_add_test(tc_core, test_is_equal_ok4081);
  // tcase_add_test(tc_core, test_is_equal_ok4082);
  // tcase_add_test(tc_core, test_is_equal_ok4083);
  // tcase_add_test(tc_core, test_is_equal_ok4084);
  // tcase_add_test(tc_core, test_is_equal_ok4085);
  // tcase_add_test(tc_core, test_is_equal_ok4086);
  // tcase_add_test(tc_core, test_is_equal_ok4087);
  // tcase_add_test(tc_core, test_is_equal_ok4088);
  // tcase_add_test(tc_core, test_is_equal_ok4089);
  // tcase_add_test(tc_core, test_is_equal_ok4090);
  // tcase_add_test(tc_core, test_is_equal_ok4091);
  // tcase_add_test(tc_core, test_is_equal_ok4092);
  // tcase_add_test(tc_core, test_is_equal_ok4093);
  // tcase_add_test(tc_core, test_is_equal_ok4094);
  // tcase_add_test(tc_core, test_is_equal_ok4095);
  // tcase_add_test(tc_core, test_is_equal_ok4096);
  // tcase_add_test(tc_core, test_is_equal_ok4097);
  // tcase_add_test(tc_core, test_is_equal_ok4098);
  // tcase_add_test(tc_core, test_is_equal_ok4099);
  // tcase_add_test(tc_core, test_is_equal_ok4100);
  // tcase_add_test(tc_core, test_is_equal_ok4101);
  // tcase_add_test(tc_core, test_is_equal_ok4102);
  // tcase_add_test(tc_core, test_is_equal_ok4103);
  // tcase_add_test(tc_core, test_is_equal_ok4104);
  // tcase_add_test(tc_core, test_is_equal_ok4105);
  // tcase_add_test(tc_core, test_is_equal_ok4106);
  // tcase_add_test(tc_core, test_is_equal_ok4107);
  // tcase_add_test(tc_core, test_is_equal_ok4108);
  // tcase_add_test(tc_core, test_is_equal_ok4109);
  // tcase_add_test(tc_core, test_is_equal_ok4110);
  // tcase_add_test(tc_core, test_is_equal_ok4111);
  // tcase_add_test(tc_core, test_is_equal_ok4112);
  // tcase_add_test(tc_core, test_is_equal_ok4113);
  // tcase_add_test(tc_core, test_is_equal_ok4114);
  // tcase_add_test(tc_core, test_is_equal_ok4115);
  // tcase_add_test(tc_core, test_is_equal_ok4116);
  // tcase_add_test(tc_core, test_is_equal_ok4117);
  // tcase_add_test(tc_core, test_is_equal_ok4118);
  // tcase_add_test(tc_core, test_is_equal_ok4119);
  // tcase_add_test(tc_core, test_is_equal_ok4120);
  // tcase_add_test(tc_core, test_is_equal_ok4121);
  // tcase_add_test(tc_core, test_is_equal_ok4122);
  // tcase_add_test(tc_core, test_is_equal_ok4123);
  // tcase_add_test(tc_core, test_is_equal_ok4124);
  // tcase_add_test(tc_core, test_is_equal_ok4125);
  // tcase_add_test(tc_core, test_is_equal_ok4126);
  // tcase_add_test(tc_core, test_is_equal_ok4127);
  // tcase_add_test(tc_core, test_is_equal_ok4128);
  // tcase_add_test(tc_core, test_is_equal_ok4129);
  // tcase_add_test(tc_core, test_is_equal_ok4130);
  // tcase_add_test(tc_core, test_is_equal_ok4131);
  // tcase_add_test(tc_core, test_is_equal_ok4132);
  // tcase_add_test(tc_core, test_is_equal_ok4133);
  // tcase_add_test(tc_core, test_is_equal_ok4134);
  // tcase_add_test(tc_core, test_is_equal_ok4135);
  // tcase_add_test(tc_core, test_is_equal_ok4136);
  // tcase_add_test(tc_core, test_is_equal_ok4137);
  // tcase_add_test(tc_core, test_is_equal_ok4138);
  // tcase_add_test(tc_core, test_is_equal_ok4139);
  // tcase_add_test(tc_core, test_is_equal_ok4140);
  // tcase_add_test(tc_core, test_is_equal_ok4141);
  // tcase_add_test(tc_core, test_is_equal_ok4142);
  // tcase_add_test(tc_core, test_is_equal_ok4143);
  // tcase_add_test(tc_core, test_is_equal_ok4144);
  // tcase_add_test(tc_core, test_is_equal_ok4145);
  // tcase_add_test(tc_core, test_is_equal_ok4146);
  // tcase_add_test(tc_core, test_is_equal_ok4147);
  // tcase_add_test(tc_core, test_is_equal_ok4148);
  // tcase_add_test(tc_core, test_is_equal_ok4149);
  // tcase_add_test(tc_core, test_is_equal_ok4150);
  // tcase_add_test(tc_core, test_is_equal_ok4151);
  // tcase_add_test(tc_core, test_is_equal_ok4152);
  // tcase_add_test(tc_core, test_is_equal_ok4153);
  // tcase_add_test(tc_core, test_is_equal_ok4154);
  // tcase_add_test(tc_core, test_is_equal_ok4155);
  // tcase_add_test(tc_core, test_is_equal_ok4156);
  // tcase_add_test(tc_core, test_is_equal_ok4157);
  // tcase_add_test(tc_core, test_is_equal_ok4158);
  // tcase_add_test(tc_core, test_is_equal_ok4159);
  // tcase_add_test(tc_core, test_is_equal_ok4160);
  // tcase_add_test(tc_core, test_is_equal_ok4161);
  // tcase_add_test(tc_core, test_is_equal_ok4162);
  // tcase_add_test(tc_core, test_is_equal_ok4163);
  // tcase_add_test(tc_core, test_is_equal_ok4164);
  // tcase_add_test(tc_core, test_is_equal_ok4165);
  // tcase_add_test(tc_core, test_is_equal_ok4166);
  // tcase_add_test(tc_core, test_is_equal_ok4167);
  // tcase_add_test(tc_core, test_is_equal_ok4168);
  // tcase_add_test(tc_core, test_is_equal_ok4169);
  // tcase_add_test(tc_core, test_is_equal_ok4170);
  // tcase_add_test(tc_core, test_is_equal_ok4171);
  // tcase_add_test(tc_core, test_is_equal_ok4172);
  // tcase_add_test(tc_core, test_is_equal_ok4173);
  // tcase_add_test(tc_core, test_is_equal_ok4174);
  // tcase_add_test(tc_core, test_is_equal_ok4175);
  // tcase_add_test(tc_core, test_is_equal_ok4176);
  // tcase_add_test(tc_core, test_is_equal_ok4177);
  // tcase_add_test(tc_core, test_is_equal_ok4178);
  // tcase_add_test(tc_core, test_is_equal_ok4179);
  // tcase_add_test(tc_core, test_is_equal_ok4180);
  // tcase_add_test(tc_core, test_is_equal_ok4181);
  // tcase_add_test(tc_core, test_is_equal_ok4182);
  // tcase_add_test(tc_core, test_is_equal_ok4183);
  // tcase_add_test(tc_core, test_is_equal_ok4184);
  // tcase_add_test(tc_core, test_is_equal_ok4185);
  // tcase_add_test(tc_core, test_is_equal_ok4186);
  // tcase_add_test(tc_core, test_is_equal_ok4187);
  // tcase_add_test(tc_core, test_is_equal_ok4188);
  // tcase_add_test(tc_core, test_is_equal_ok4189);
  // tcase_add_test(tc_core, test_is_equal_ok4190);
  // tcase_add_test(tc_core, test_is_equal_ok4191);
  // tcase_add_test(tc_core, test_is_equal_ok4192);
  // tcase_add_test(tc_core, test_is_equal_ok4193);
  // tcase_add_test(tc_core, test_is_equal_ok4194);
  // tcase_add_test(tc_core, test_is_equal_ok4195);
  // tcase_add_test(tc_core, test_is_equal_ok4196);
  // tcase_add_test(tc_core, test_is_equal_ok4197);
  // tcase_add_test(tc_core, test_is_equal_ok4198);
  // tcase_add_test(tc_core, test_is_equal_ok4199);
  // tcase_add_test(tc_core, test_is_equal_ok4200);
  // tcase_add_test(tc_core, test_is_equal_ok6075);
  // tcase_add_test(tc_core, test_is_equal_ok6076);
  // tcase_add_test(tc_core, test_is_equal_ok6077);
  // tcase_add_test(tc_core, test_is_equal_ok6078);
  // tcase_add_test(tc_core, test_is_equal_ok6079);
  // tcase_add_test(tc_core, test_is_equal_ok6080);
  // tcase_add_test(tc_core, test_is_equal_ok6081);
  // tcase_add_test(tc_core, test_is_equal_ok6082);
  // tcase_add_test(tc_core, test_is_equal_ok6083);
  // tcase_add_test(tc_core, test_is_equal_ok6084);
  // tcase_add_test(tc_core, test_is_equal_ok6085);
  // tcase_add_test(tc_core, test_is_equal_ok6086);
  // tcase_add_test(tc_core, test_is_equal_ok6087);
  // tcase_add_test(tc_core, test_is_equal_ok6088);
  // tcase_add_test(tc_core, test_is_equal_ok6089);
  // tcase_add_test(tc_core, test_is_equal_ok6090);
  // tcase_add_test(tc_core, test_is_equal_ok6091);
  // tcase_add_test(tc_core, test_is_equal_ok6092);
  // tcase_add_test(tc_core, test_is_equal_ok6093);
  // tcase_add_test(tc_core, test_is_equal_ok6094);
  // tcase_add_test(tc_core, test_is_equal_ok6095);
  // tcase_add_test(tc_core, test_is_equal_ok6096);
  // tcase_add_test(tc_core, test_is_equal_ok6097);
  // tcase_add_test(tc_core, test_is_equal_ok6098);
  // tcase_add_test(tc_core, test_is_equal_ok6099);
  // tcase_add_test(tc_core, test_is_equal_ok6100);
  // tcase_add_test(tc_core, test_is_equal_ok6101);
  // tcase_add_test(tc_core, test_is_equal_ok6102);
  // tcase_add_test(tc_core, test_is_equal_ok6103);
  // tcase_add_test(tc_core, test_is_equal_ok6104);
  // tcase_add_test(tc_core, test_is_equal_ok6105);
  // tcase_add_test(tc_core, test_is_equal_ok6106);
  // tcase_add_test(tc_core, test_is_equal_ok6107);
  // tcase_add_test(tc_core, test_is_equal_ok6108);
  // tcase_add_test(tc_core, test_is_equal_ok6109);
  // tcase_add_test(tc_core, test_is_equal_ok6110);
  // tcase_add_test(tc_core, test_is_equal_ok6111);
  // tcase_add_test(tc_core, test_is_equal_ok6112);
  // tcase_add_test(tc_core, test_is_equal_ok6113);
  // tcase_add_test(tc_core, test_is_equal_ok6114);
  // tcase_add_test(tc_core, test_is_equal_ok6115);
  // tcase_add_test(tc_core, test_is_equal_ok6116);
  // tcase_add_test(tc_core, test_is_equal_ok6117);
  // tcase_add_test(tc_core, test_is_equal_ok6118);
  // tcase_add_test(tc_core, test_is_equal_ok6119);
  // tcase_add_test(tc_core, test_is_equal_ok6120);
  // tcase_add_test(tc_core, test_is_equal_ok6121);
  // tcase_add_test(tc_core, test_is_equal_ok6122);
  // tcase_add_test(tc_core, test_is_equal_ok6123);
  // tcase_add_test(tc_core, test_is_equal_ok6124);
  // tcase_add_test(tc_core, test_is_equal_ok6125);
  // tcase_add_test(tc_core, test_is_equal_ok6126);
  // tcase_add_test(tc_core, test_is_equal_ok6127);
  // tcase_add_test(tc_core, test_is_equal_ok6128);
  // tcase_add_test(tc_core, test_is_equal_ok6129);
  // tcase_add_test(tc_core, test_is_equal_ok6130);
  // tcase_add_test(tc_core, test_is_equal_ok6131);
  // tcase_add_test(tc_core, test_is_equal_ok6132);
  // tcase_add_test(tc_core, test_is_equal_ok6133);
  // tcase_add_test(tc_core, test_is_equal_ok6134);
  // tcase_add_test(tc_core, test_is_equal_ok6135);
  // tcase_add_test(tc_core, test_is_equal_ok6136);
  // tcase_add_test(tc_core, test_is_equal_ok6137);
  // tcase_add_test(tc_core, test_is_equal_ok6138);
  // tcase_add_test(tc_core, test_is_equal_ok6139);
  // tcase_add_test(tc_core, test_is_equal_ok6140);
  // tcase_add_test(tc_core, test_is_equal_ok6141);
  // tcase_add_test(tc_core, test_is_equal_ok6142);
  // tcase_add_test(tc_core, test_is_equal_ok6143);
  // tcase_add_test(tc_core, test_is_equal_ok6144);
  // tcase_add_test(tc_core, test_is_equal_ok6145);
  // tcase_add_test(tc_core, test_is_equal_ok6146);
  // tcase_add_test(tc_core, test_is_equal_ok6147);
  // tcase_add_test(tc_core, test_is_equal_ok6148);
  // tcase_add_test(tc_core, test_is_equal_ok6149);
  // tcase_add_test(tc_core, test_is_equal_ok6150);
  // tcase_add_test(tc_core, test_is_equal_ok6151);
  // tcase_add_test(tc_core, test_is_equal_ok6152);
  // tcase_add_test(tc_core, test_is_equal_ok6153);
  // tcase_add_test(tc_core, test_is_equal_ok6154);
  // tcase_add_test(tc_core, test_is_equal_ok6155);
  // tcase_add_test(tc_core, test_is_equal_ok6156);
  // tcase_add_test(tc_core, test_is_equal_ok6157);
  // tcase_add_test(tc_core, test_is_equal_ok6158);
  // tcase_add_test(tc_core, test_is_equal_ok6159);
  // tcase_add_test(tc_core, test_is_equal_ok6160);
  // tcase_add_test(tc_core, test_is_equal_ok6161);
  // tcase_add_test(tc_core, test_is_equal_ok6162);
  // tcase_add_test(tc_core, test_is_equal_ok6163);
  // tcase_add_test(tc_core, test_is_equal_ok6164);
  // tcase_add_test(tc_core, test_is_equal_ok6165);
  // tcase_add_test(tc_core, test_is_equal_ok6166);
  // tcase_add_test(tc_core, test_is_equal_ok6167);
  // tcase_add_test(tc_core, test_is_equal_ok6168);
  // tcase_add_test(tc_core, test_is_equal_ok6169);
  // tcase_add_test(tc_core, test_is_equal_ok6170);
  // tcase_add_test(tc_core, test_is_equal_ok6171);
  // tcase_add_test(tc_core, test_is_equal_ok6172);
  // tcase_add_test(tc_core, test_is_equal_ok6173);
  // tcase_add_test(tc_core, test_is_equal_ok6174);
  // tcase_add_test(tc_core, test_is_equal_ok6175);
  // tcase_add_test(tc_core, test_is_equal_ok6176);
  // tcase_add_test(tc_core, test_is_equal_ok6177);
  // tcase_add_test(tc_core, test_is_equal_ok6178);
  // tcase_add_test(tc_core, test_is_equal_ok6179);
  // tcase_add_test(tc_core, test_is_equal_ok6180);
  // tcase_add_test(tc_core, test_is_equal_ok6181);
  // tcase_add_test(tc_core, test_is_equal_ok6182);
  // tcase_add_test(tc_core, test_is_equal_ok6183);
  // tcase_add_test(tc_core, test_is_equal_ok6184);
  // tcase_add_test(tc_core, test_is_equal_ok6185);
  // tcase_add_test(tc_core, test_is_equal_ok6186);
  // tcase_add_test(tc_core, test_is_equal_ok6187);
  // tcase_add_test(tc_core, test_is_equal_ok6188);
  // tcase_add_test(tc_core, test_is_equal_ok6189);
  // tcase_add_test(tc_core, test_is_equal_ok6190);
  // tcase_add_test(tc_core, test_is_equal_ok6191);
  // tcase_add_test(tc_core, test_is_equal_ok6192);
  // tcase_add_test(tc_core, test_is_equal_ok6193);
  // tcase_add_test(tc_core, test_is_equal_ok6194);
  // tcase_add_test(tc_core, test_is_equal_ok6195);
  // tcase_add_test(tc_core, test_is_equal_ok6196);
  // tcase_add_test(tc_core, test_is_equal_ok6197);
  // tcase_add_test(tc_core, test_is_equal_ok6198);
  // tcase_add_test(tc_core, test_is_equal_ok6199);
  // tcase_add_test(tc_core, test_is_equal_ok6200);
  // tcase_add_test(tc_core, test_is_equal_ok6201);
  // tcase_add_test(tc_core, test_is_equal_ok6202);
  // tcase_add_test(tc_core, test_is_equal_ok6203);
  // tcase_add_test(tc_core, test_is_equal_ok6204);
  // tcase_add_test(tc_core, test_is_equal_ok6205);
  // tcase_add_test(tc_core, test_is_equal_ok6206);
  // tcase_add_test(tc_core, test_is_equal_ok6207);
  // tcase_add_test(tc_core, test_is_equal_ok6208);
  // tcase_add_test(tc_core, test_is_equal_ok6209);
  // tcase_add_test(tc_core, test_is_equal_ok6210);
  // tcase_add_test(tc_core, test_is_equal_ok6211);
  // tcase_add_test(tc_core, test_is_equal_ok6212);
  // tcase_add_test(tc_core, test_is_equal_ok6213);
  // tcase_add_test(tc_core, test_is_equal_ok6214);
  // tcase_add_test(tc_core, test_is_equal_ok6215);
  // tcase_add_test(tc_core, test_is_equal_ok6216);
  // tcase_add_test(tc_core, test_is_equal_ok6217);
  // tcase_add_test(tc_core, test_is_equal_ok6218);
  // tcase_add_test(tc_core, test_is_equal_ok6219);
  // tcase_add_test(tc_core, test_is_equal_ok6220);
  // tcase_add_test(tc_core, test_is_equal_ok6221);
  // tcase_add_test(tc_core, test_is_equal_ok6222);
  // tcase_add_test(tc_core, test_is_equal_ok6223);
  // tcase_add_test(tc_core, test_is_equal_ok6224);
  // tcase_add_test(tc_core, test_is_equal_ok6225);
  // tcase_add_test(tc_core, test_is_equal_ok6226);
  // tcase_add_test(tc_core, test_is_equal_ok6227);
  // tcase_add_test(tc_core, test_is_equal_ok6228);
  // tcase_add_test(tc_core, test_is_equal_ok6229);
  // tcase_add_test(tc_core, test_is_equal_ok6230);
  // tcase_add_test(tc_core, test_is_equal_ok6231);
  // tcase_add_test(tc_core, test_is_equal_ok6232);
  // tcase_add_test(tc_core, test_is_equal_ok6233);
  // tcase_add_test(tc_core, test_is_equal_ok6234);
  // tcase_add_test(tc_core, test_is_equal_ok6235);
  // tcase_add_test(tc_core, test_is_equal_ok6236);
  // tcase_add_test(tc_core, test_is_equal_ok6237);
  // tcase_add_test(tc_core, test_is_equal_ok6238);
  // tcase_add_test(tc_core, test_is_equal_ok6239);
  // tcase_add_test(tc_core, test_is_equal_ok6240);
  // tcase_add_test(tc_core, test_is_equal_ok6241);
  // tcase_add_test(tc_core, test_is_equal_ok6242);
  // tcase_add_test(tc_core, test_is_equal_ok6243);
  // tcase_add_test(tc_core, test_is_equal_ok6244);
  // tcase_add_test(tc_core, test_is_equal_ok6245);
  // tcase_add_test(tc_core, test_is_equal_ok6246);
  // tcase_add_test(tc_core, test_is_equal_ok6247);
  // tcase_add_test(tc_core, test_is_equal_ok6248);
  // tcase_add_test(tc_core, test_is_equal_ok6249);
  // tcase_add_test(tc_core, test_is_equal_ok6250);
  // tcase_add_test(tc_core, test_is_equal_ok6251);
  // tcase_add_test(tc_core, test_is_equal_ok6252);
  // tcase_add_test(tc_core, test_is_equal_ok6253);
  // tcase_add_test(tc_core, test_is_equal_ok6254);
  // tcase_add_test(tc_core, test_is_equal_ok6255);
  // tcase_add_test(tc_core, test_is_equal_ok6256);
  // tcase_add_test(tc_core, test_is_equal_ok6257);
  // tcase_add_test(tc_core, test_is_equal_ok6258);
  // tcase_add_test(tc_core, test_is_equal_ok6259);
  // tcase_add_test(tc_core, test_is_equal_ok6260);
  // tcase_add_test(tc_core, test_is_equal_ok6261);
  // tcase_add_test(tc_core, test_is_equal_ok6262);
  // tcase_add_test(tc_core, test_is_equal_ok6263);
  // tcase_add_test(tc_core, test_is_equal_ok6264);
  // tcase_add_test(tc_core, test_is_equal_ok6265);
  // tcase_add_test(tc_core, test_is_equal_ok6266);
  // tcase_add_test(tc_core, test_is_equal_ok6267);
  // tcase_add_test(tc_core, test_is_equal_ok6268);
  // tcase_add_test(tc_core, test_is_equal_ok6269);
  // tcase_add_test(tc_core, test_is_equal_ok6270);
  // tcase_add_test(tc_core, test_is_equal_ok6271);
  // tcase_add_test(tc_core, test_is_equal_ok6272);

  suite_add_tcase(c, tc_core);  // suite_add_tcase
  return c;
}
