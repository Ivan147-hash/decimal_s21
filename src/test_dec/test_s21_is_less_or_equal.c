#include "testes.h"

s21_decimal max3 = {{MAX_UINT, MAX_UINT, MAX_UINT, 0}};  //
s21_decimal middle3 = {{MAX_INT, MAX_INT, MAX_INT, 0}};
s21_decimal null3 = {{0, 0, 0, 0}};
s21_decimal null_minus3 = {{0, 0, 0, MINUS}};
s21_decimal middle_minus3 = {{MAX_INT, MAX_INT, MAX_INT, MINUS}};
s21_decimal max_minus3 = {{MAX_UINT, MAX_UINT, MAX_UINT, MINUS}};
s21_decimal middle_fractions3 = {{MAX_INT, MAX_INT, MAX_INT, EXPONENT_20}};
#define TEST_COMPARISON_TRUE 1
#define TEST_COMPARISON_FALSE 0

START_TEST(_is_less_or_equal_0) {
  ck_assert_int_eq(0, s21_is_less_or_equal(middle3, null3));
  ck_assert_int_eq(1, s21_is_less_or_equal(middle_minus3, null3));
  ck_assert_int_eq(1, s21_is_less_or_equal(max_minus3, middle3));
  ck_assert_int_eq(0, s21_is_less_or_equal(middle3, middle_fractions3));
  ck_assert_int_eq(1, s21_is_less_or_equal(null3, null_minus3));
}
END_TEST

START_TEST(_is_less_or_equal_1) {
  int true_res = 1;
  s21_decimal val1 = {{0xB45A02CB, 0x60D2EF7B, 0x90F3B813, 0x800A0000}};

  // 10000000000010100000000000000000   scale - 10
  // 10010000111100111011100000010011
  // 01100000110100101110111101111011
  // 10110100010110100000001011001011

  s21_decimal val2 = {{0x6522ACEC, 0x9E32FBE7, 0xF9C405E1, 0x800C0000}};

  // 10000000000011000000000000000000   scale - 12
  // 11111001110001000000010111100001
  // 10011110001100101111101111100111
  // 01100101001000101010110011101100

  int s21_res = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(test_is_less_or_equal_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;
  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
}

START_TEST(test_is_less_or_equal_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok82) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok84) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok85) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok86) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok87) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok88) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok89) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok90) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok91) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok92) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok93) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok94) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok95) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok96) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok97) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok98) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok99) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok100) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok101) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4.7074769154693434325056864883
  s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok102) {
  // -4.7074769154693434325056864883
  s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok103) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4.7074769154693434325056864883
  s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok104) {
  // 4.7074769154693434325056864883
  s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok105) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24054676222594164633554651068
  s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok106) {
  // 24054676222594164633554651068
  s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok107) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24054676222594164633554651068
  s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok108) {
  // -24054676222594164633554651068
  s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok109) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 30667538544853.855676101018067
  s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok110) {
  // 30667538544853.855676101018067
  s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok111) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -30667538544853.855676101018067
  s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok112) {
  // -30667538544853.855676101018067
  s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok114) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok118) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok120) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok122) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok124) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok126) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok128) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok130) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok132) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok134) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok136) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok138) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok140) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok142) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok144) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok146) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok148) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok150) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok152) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok154) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok156) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok158) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok160) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok162) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok164) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok166) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok168) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok169) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok170) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok171) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok172) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok173) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok174) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok175) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok176) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok177) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok178) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok179) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok180) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok181) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok182) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok183) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok184) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok185) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok186) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok187) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok188) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok189) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok190) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok191) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok192) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok193) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok194) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok195) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok196) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok197) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok198) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok199) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

START_TEST(test_is_less_or_equal_ok200) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
  ;
}

// START_TEST(test_is_less_or_equal_ok201) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok202) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok203) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok204) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok205) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok206) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok207) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok208) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok209) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok210) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok211) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok212) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok213) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok214) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok215) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok216) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok217) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok218) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok219) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok220) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok221) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok222) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok223) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok224) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok225) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok226) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok227) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok228) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok229) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok230) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok231) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok232) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok233) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok234) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok235) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok236) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok237) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok238) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok239) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok240) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok241) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok242) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok243) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok244) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok245) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok246) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok247) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok248) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok249) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok250) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok251) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok252) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok253) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok254) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok255) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok256) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok257) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok258) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok259) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok260) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok261) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok262) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok263) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok264) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok265) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok266) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok267) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok268) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok269) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok270) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok271) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok272) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok273) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok274) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok275) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok276) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok277) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok278) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok279) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok280) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok281) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok282) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok283) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok284) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok285) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok286) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok287) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok288) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok289) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok290) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok291) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok292) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok293) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok294) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok295) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok296) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok297) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok298) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok299) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok300) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
//   ;
// }

// START_TEST(test_is_less_or_equal_ok1000) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1001) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1002) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1003) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1004) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1005) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1006) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1007) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1008) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1009) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1010) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1011) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1012) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1013) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1014) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1015) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1016) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1017) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1018) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1019) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1020) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1021) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1022) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1023) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1024) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1025) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1026) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1027) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1028) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1029) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1030) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1031) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1032) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1033) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1034) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1035) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1036) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1037) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1038) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1039) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1040) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1041) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1042) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1043) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1044) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1045) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1046) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1047) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1048) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1049) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1050) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1051) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1052) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1053) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1054) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1055) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1056) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1057) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1058) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1059) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1060) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1061) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1062) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1063) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1064) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1065) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1066) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1067) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1068) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1069) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1070) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1071) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1072) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1073) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1074) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1075) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1076) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1077) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1078) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1079) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1080) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1081) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1082) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1083) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1084) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1085) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1086) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1087) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1088) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1089) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1090) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1091) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1092) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1093) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1094) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1095) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1096) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1097) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1098) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1099) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1100) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1101) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1102) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1103) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1104) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1105) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1106) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1107) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1108) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1109) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1110) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1111) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1112) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1113) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1114) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1115) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1116) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1117) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1118) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1119) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1120) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1121) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1122) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1123) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1124) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1125) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1126) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1127) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1128) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1129) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1130) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1131) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1132) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1133) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1134) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1135) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1136) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1137) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1138) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1139) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1140) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1141) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1142) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1143) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1144) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1145) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1146) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1147) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1148) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1149) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1150) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1151) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1152) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1153) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1154) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1155) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1156) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1157) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1158) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1159) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1160) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1161) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1162) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1163) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1164) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1165) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1166) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1167) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1168) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1169) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1170) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1171) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1172) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1173) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1174) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1175) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1176) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1177) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1178) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1179) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1180) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1181) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1182) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1183) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1184) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1185) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1186) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1187) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1188) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1189) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1190) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1191) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1192) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1193) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1194) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1195) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1196) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1197) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1198) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1199) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1200) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1201) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1202) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1203) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1204) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1205) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1206) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1207) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1208) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1209) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1210) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1211) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1212) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1213) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1214) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1215) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1216) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1217) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1218) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1219) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1220) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1221) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1222) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1223) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1224) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1225) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1226) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1227) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1228) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1229) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1230) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1231) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1232) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1233) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1234) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1235) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1236) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1237) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1238) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1239) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1240) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1241) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1242) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1243) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1244) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1245) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1246) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1247) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1248) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1249) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1250) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1251) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1252) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1253) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1254) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1255) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1256) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1257) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1258) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1259) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1260) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1261) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1262) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1263) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1264) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1265) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1266) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1267) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1268) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1269) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1270) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1271) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1272) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1273) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1274) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1275) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1276) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1277) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1278) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1279) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1280) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1281) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1282) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1283) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1284) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1285) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1286) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1287) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1288) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1289) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1290) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1291) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1292) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1293) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1294) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1295) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1296) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1297) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1298) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1299) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok1300) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2000) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2001) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2002) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2003) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2004) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2005) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2006) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2007) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2008) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2009) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2010) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2011) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2012) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2013) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2014) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2015) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2016) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2017) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2018) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2019) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2020) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2021) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2022) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2023) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2024) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2025) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2026) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2027) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2028) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2029) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2030) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2031) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2032) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2033) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2034) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2035) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2036) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2037) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2038) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2039) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2040) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2041) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2042) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2043) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2044) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2045) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2046) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2047) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2048) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2049) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2050) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2051) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2052) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2053) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2054) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2055) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2056) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2057) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2058) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2059) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2060) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2061) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2062) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2063) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2064) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2065) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2066) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2067) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2068) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2069) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2070) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2071) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2072) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2073) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2074) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2075) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2076) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2077) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2078) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2079) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2080) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2081) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2082) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2083) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2084) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2085) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2086) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2087) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2088) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2089) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2090) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2091) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2092) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2093) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2094) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2095) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2096) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2097) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2098) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2099) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2100) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2101) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2102) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2103) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2104) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2105) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2106) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2107) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2108) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2109) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2110) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2111) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2112) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2113) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2114) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2115) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2116) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2117) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2118) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2119) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2120) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2121) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2122) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2123) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2124) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2125) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2126) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2127) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2128) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2129) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2130) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2131) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2132) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2133) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2134) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2135) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2136) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2137) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2138) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2139) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2140) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2141) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2142) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2143) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2144) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2145) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2146) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2147) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2148) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2149) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2150) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2151) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2152) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2153) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2154) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2155) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2156) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2157) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2158) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2159) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2160) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2161) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2162) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2163) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2164) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2165) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2166) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2167) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2168) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2169) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2170) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2171) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2172) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2173) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2174) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2175) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2176) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2177) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2178) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2179) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2180) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2181) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2182) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2183) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2184) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2185) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2186) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2187) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2188) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2189) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2190) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2191) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2192) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2193) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2194) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2195) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2196) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2197) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2198) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2199) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2200) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2201) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2202) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2203) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2204) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2205) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2206) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2207) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2208) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2209) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2210) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2211) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2212) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2213) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2214) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2215) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2216) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2217) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2218) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2219) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2220) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2221) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2222) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2223) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2224) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2225) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2226) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2227) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2228) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2229) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2230) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2231) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2232) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2233) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2234) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2235) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2236) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2237) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2238) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2239) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2240) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2241) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2242) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2243) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2244) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2245) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2246) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2247) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2248) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2249) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2250) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2251) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2252) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2253) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2254) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2255) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2256) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2257) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2258) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2259) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2260) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2261) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2262) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2263) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2264) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2265) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2266) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2267) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2268) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2269) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2270) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2271) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2272) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2273) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2274) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2275) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2276) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2277) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2278) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2279) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2280) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2281) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2282) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2283) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2284) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2285) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2286) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2287) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2288) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2289) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2290) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2291) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2292) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2293) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2294) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2295) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2296) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2297) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2298) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2299) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok2300) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6000) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6001) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6002) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6003) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6004) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6005) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6006) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6007) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6008) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6009) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6010) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6011) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6012) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6013) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6014) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6015) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6016) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6017) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6018) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6019) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6020) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6021) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6022) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6023) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6024) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6025) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6026) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6027) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6028) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6029) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6030) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6031) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6032) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6033) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6034) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6035) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6036) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6037) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6038) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6039) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6040) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6041) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6042) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6043) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6044) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6045) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6046) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6047) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6048) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6049) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6050) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6051) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6052) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6053) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6054) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6055) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6056) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6057) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6058) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6059) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6060) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6061) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6062) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6063) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6064) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6065) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6066) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6067) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6068) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6069) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6070) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6071) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6072) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6073) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6074) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6075) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6076) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6077) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6078) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6079) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6080) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6081) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6082) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6083) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6084) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6085) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6086) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6087) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6088) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6089) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6090) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6091) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6092) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6093) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6094) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6095) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6096) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6097) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6098) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6099) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6100) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6101) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6102) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6103) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6104) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6105) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6106) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6107) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6108) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6109) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6110) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6111) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6112) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6113) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6114) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6115) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6116) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6117) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6118) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6119) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6120) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6121) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6122) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6123) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6124) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6125) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6126) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6127) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6128) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6129) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6130) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6131) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6132) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6133) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6134) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6135) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6136) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6137) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6138) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6139) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6140) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6141) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6142) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6143) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6144) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6145) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6146) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6147) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6148) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6149) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6150) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6151) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6152) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6153) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6154) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6155) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6156) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6157) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6158) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6159) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6160) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6161) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6162) {
//   // 79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6163) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -79228162514264337593543950335
//   s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6164) {
//   // -79228162514264337593543950335
//   s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6165) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6166) {
//   // 52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6167) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -52818775009509558395695966890
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6168) {
//   // -52818775009509558395695966890
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6169) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6170) {
//   // 52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6171) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -52818775009509558395695966891
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6172) {
//   // -52818775009509558395695966891
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6173) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6174) {
//   // 5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6175) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -5.281877500950955839569596690
//   s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6176) {
//   // -5.281877500950955839569596690
//   s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6177) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6178) {
//   // 5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6179) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -5281877500950955839569596689
//   s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6180) {
//   // -5281877500950955839569596689
//   s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6181) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6182) {
//   // 5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6183) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -5281877500950955839569596689.0
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6184) {
//   // -5281877500950955839569596689.0
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6185) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6186) {
//   // 7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6187) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -7922816251426433759354395033
//   s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6188) {
//   // -7922816251426433759354395033
//   s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6189) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6190) {
//   // 7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6191) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -7922816251426433759354395034
//   s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6192) {
//   // -7922816251426433759354395034
//   s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6193) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6194) {
//   // 1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6195) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.2297829382473034409
//   s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6196) {
//   // -1.2297829382473034409
//   s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6197) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6198) {
//   // 1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6199) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.2297829382473034410
//   s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6200) {
//   // -1.2297829382473034410
//   s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6201) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6202) {
//   // 1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6203) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.2297829382473034411
//   s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6204) {
//   // -1.2297829382473034411
//   s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6205) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6206) {
//   // 1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6207) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6208) {
//   // -1
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6209) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6210) {
//   // 1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6211) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.0
//   s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6212) {
//   // -1.0
//   s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6213) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6214) {
//   // 1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6215) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.22
//   s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6216) {
//   // -1.22
//   s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6217) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6218) {
//   // 1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6219) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.230001
//   s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6220) {
//   // -1.230001
//   s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6221) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6222) {
//   // 1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6223) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1.23000
//   s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6224) {
//   // -1.23000
//   s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6225) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6226) {
//   // 1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6227) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1431655765
//   s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6228) {
//   // -1431655765
//   s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6229) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6230) {
//   // 1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6231) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1431655765.00000
//   s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6232) {
//   // -1431655765.00000
//   s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6233) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6234) {
//   // 1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6235) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1431655765.000000000000000001
//   s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6236) {
//   // -1431655765.000000000000000001
//   s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6237) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6238) {
//   // 1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6239) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -1431655764.999999999999999999
//   s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6240) {
//   // -1431655764.999999999999999999
//   s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6241) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6242) {
//   // 0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6243) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -0.9999999999999999999999999999
//   s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6244) {
//   // -0.9999999999999999999999999999
//   s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6245) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6246) {
//   // 0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6247) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -0.0000000000000000000000000001
//   s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6248) {
//   // -0.0000000000000000000000000001
//   s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6249) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6250) {
//   // 0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6251) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -0
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6252) {
//   // -0
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6253) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6254) {
//   // -0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6255) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 0.00000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6256) {
//   // 0.00000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6257) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6258) {
//   // -0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6259) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 0.0000000000000000000000000000
//   s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6260) {
//   // 0.0000000000000000000000000000
//   s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6261) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6262) {
//   // -4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6263) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 4.7074769154693434325056864883
//   s21_decimal decimal2 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6264) {
//   // 4.7074769154693434325056864883
//   s21_decimal decimal1 = {{0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6265) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6266) {
//   // 24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x0}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6267) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -24054676222594164633554651068
//   s21_decimal decimal2 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6268) {
//   // -24054676222594164633554651068
//   s21_decimal decimal1 = {{0xCE5807BC, 0xF2D773B6, 0x4DB98FD2, 0x80000000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6269) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // 30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6270) {
//   // 30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_FALSE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6271) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(test_is_less_or_equal_ok6272) {
//   // -30667538544853.855676101018067
//   s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   // -30667538544853.855676101018067
//   s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
//   int check = TEST_COMPARISON_TRUE;

//   ck_assert_int_eq(check, s21_is_less_or_equal(decimal1, decimal2));
// }

// START_TEST(less_or_equal_1) {
//   int error = 0;
//   float a = 1.2;
//   float b = 0.3;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_less_or_equal(a_dec, b_dec);
//   ck_assert_int_eq(res, 0);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(less_or_equal_2) {
//   int error = 0;
//   float a = 1.2;
//   float b = 1.2;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_less_or_equal(a_dec, b_dec);
//   ck_assert_int_eq(res, 1);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(less_or_equal_3) {
//   int error = 0;
//   float a = -1.2;
//   float b = 1.2;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_less_or_equal(a_dec, b_dec);
//   ck_assert_int_eq(res, 1);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

// START_TEST(less_or_equal_4) {
//   int error = 0;
//   float a = 0;
//   float b = 0;
//   s21_decimal a_dec;
//   error = s21_from_float_to_decimal(a, &a_dec);
//   s21_decimal b_dec;
//   error = s21_from_float_to_decimal(b, &b_dec);
//   int res = 0;
//   res = s21_is_less_or_equal(a_dec, b_dec);
//   ck_assert_int_eq(res, 1);
//   ck_assert_int_eq(error, 0);
// }
// END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *c = suite_create("s21_is_less_or_equal_cases");
  TCase *tc_core = tcase_create("s21_is_less_or_equal_tc");

  tcase_add_test(tc_core, _is_less_or_equal_0);
  tcase_add_test(tc_core, _is_less_or_equal_1);
  // tcase_add_test(tc_core, less_or_equal_4);
  // tcase_add_test(tc_core, less_or_equal_3);
  // tcase_add_test(tc_core, less_or_equal_2);
  // tcase_add_test(tc_core, less_or_equal_1);
  tcase_add_test(tc_core, test_is_less_or_equal_ok1);
  tcase_add_test(tc_core, test_is_less_or_equal_ok2);
  tcase_add_test(tc_core, test_is_less_or_equal_ok3);
  tcase_add_test(tc_core, test_is_less_or_equal_ok4);
  tcase_add_test(tc_core, test_is_less_or_equal_ok5);
  tcase_add_test(tc_core, test_is_less_or_equal_ok6);
  tcase_add_test(tc_core, test_is_less_or_equal_ok7);
  tcase_add_test(tc_core, test_is_less_or_equal_ok8);
  tcase_add_test(tc_core, test_is_less_or_equal_ok9);
  tcase_add_test(tc_core, test_is_less_or_equal_ok10);
  tcase_add_test(tc_core, test_is_less_or_equal_ok11);
  tcase_add_test(tc_core, test_is_less_or_equal_ok12);
  tcase_add_test(tc_core, test_is_less_or_equal_ok13);
  tcase_add_test(tc_core, test_is_less_or_equal_ok14);
  tcase_add_test(tc_core, test_is_less_or_equal_ok15);
  tcase_add_test(tc_core, test_is_less_or_equal_ok16);
  tcase_add_test(tc_core, test_is_less_or_equal_ok17);
  tcase_add_test(tc_core, test_is_less_or_equal_ok18);
  tcase_add_test(tc_core, test_is_less_or_equal_ok19);
  tcase_add_test(tc_core, test_is_less_or_equal_ok20);
  tcase_add_test(tc_core, test_is_less_or_equal_ok21);
  tcase_add_test(tc_core, test_is_less_or_equal_ok22);
  tcase_add_test(tc_core, test_is_less_or_equal_ok23);
  tcase_add_test(tc_core, test_is_less_or_equal_ok24);
  tcase_add_test(tc_core, test_is_less_or_equal_ok25);
  tcase_add_test(tc_core, test_is_less_or_equal_ok26);
  tcase_add_test(tc_core, test_is_less_or_equal_ok27);
  tcase_add_test(tc_core, test_is_less_or_equal_ok28);
  tcase_add_test(tc_core, test_is_less_or_equal_ok29);
  tcase_add_test(tc_core, test_is_less_or_equal_ok30);
  tcase_add_test(tc_core, test_is_less_or_equal_ok31);
  tcase_add_test(tc_core, test_is_less_or_equal_ok32);
  tcase_add_test(tc_core, test_is_less_or_equal_ok33);
  tcase_add_test(tc_core, test_is_less_or_equal_ok34);
  tcase_add_test(tc_core, test_is_less_or_equal_ok35);
  tcase_add_test(tc_core, test_is_less_or_equal_ok36);
  tcase_add_test(tc_core, test_is_less_or_equal_ok37);
  tcase_add_test(tc_core, test_is_less_or_equal_ok38);
  tcase_add_test(tc_core, test_is_less_or_equal_ok39);
  tcase_add_test(tc_core, test_is_less_or_equal_ok40);
  tcase_add_test(tc_core, test_is_less_or_equal_ok41);
  tcase_add_test(tc_core, test_is_less_or_equal_ok42);
  tcase_add_test(tc_core, test_is_less_or_equal_ok43);
  tcase_add_test(tc_core, test_is_less_or_equal_ok44);
  tcase_add_test(tc_core, test_is_less_or_equal_ok45);
  tcase_add_test(tc_core, test_is_less_or_equal_ok46);
  tcase_add_test(tc_core, test_is_less_or_equal_ok47);
  tcase_add_test(tc_core, test_is_less_or_equal_ok48);
  tcase_add_test(tc_core, test_is_less_or_equal_ok49);
  tcase_add_test(tc_core, test_is_less_or_equal_ok50);
  tcase_add_test(tc_core, test_is_less_or_equal_ok51);
  tcase_add_test(tc_core, test_is_less_or_equal_ok52);
  tcase_add_test(tc_core, test_is_less_or_equal_ok53);
  tcase_add_test(tc_core, test_is_less_or_equal_ok54);
  tcase_add_test(tc_core, test_is_less_or_equal_ok55);
  tcase_add_test(tc_core, test_is_less_or_equal_ok56);
  tcase_add_test(tc_core, test_is_less_or_equal_ok57);
  tcase_add_test(tc_core, test_is_less_or_equal_ok58);
  tcase_add_test(tc_core, test_is_less_or_equal_ok59);
  tcase_add_test(tc_core, test_is_less_or_equal_ok60);
  tcase_add_test(tc_core, test_is_less_or_equal_ok61);
  tcase_add_test(tc_core, test_is_less_or_equal_ok62);
  tcase_add_test(tc_core, test_is_less_or_equal_ok63);
  tcase_add_test(tc_core, test_is_less_or_equal_ok64);
  tcase_add_test(tc_core, test_is_less_or_equal_ok65);
  tcase_add_test(tc_core, test_is_less_or_equal_ok66);
  tcase_add_test(tc_core, test_is_less_or_equal_ok67);
  tcase_add_test(tc_core, test_is_less_or_equal_ok68);
  tcase_add_test(tc_core, test_is_less_or_equal_ok69);
  tcase_add_test(tc_core, test_is_less_or_equal_ok70);
  tcase_add_test(tc_core, test_is_less_or_equal_ok71);
  tcase_add_test(tc_core, test_is_less_or_equal_ok72);
  tcase_add_test(tc_core, test_is_less_or_equal_ok73);
  tcase_add_test(tc_core, test_is_less_or_equal_ok74);
  tcase_add_test(tc_core, test_is_less_or_equal_ok75);
  tcase_add_test(tc_core, test_is_less_or_equal_ok76);
  tcase_add_test(tc_core, test_is_less_or_equal_ok77);
  tcase_add_test(tc_core, test_is_less_or_equal_ok78);
  tcase_add_test(tc_core, test_is_less_or_equal_ok79);
  tcase_add_test(tc_core, test_is_less_or_equal_ok80);
  tcase_add_test(tc_core, test_is_less_or_equal_ok81);
  tcase_add_test(tc_core, test_is_less_or_equal_ok82);
  tcase_add_test(tc_core, test_is_less_or_equal_ok83);
  tcase_add_test(tc_core, test_is_less_or_equal_ok84);
  tcase_add_test(tc_core, test_is_less_or_equal_ok85);
  tcase_add_test(tc_core, test_is_less_or_equal_ok86);
  tcase_add_test(tc_core, test_is_less_or_equal_ok87);
  tcase_add_test(tc_core, test_is_less_or_equal_ok88);
  tcase_add_test(tc_core, test_is_less_or_equal_ok89);
  tcase_add_test(tc_core, test_is_less_or_equal_ok90);
  tcase_add_test(tc_core, test_is_less_or_equal_ok91);
  tcase_add_test(tc_core, test_is_less_or_equal_ok92);
  tcase_add_test(tc_core, test_is_less_or_equal_ok93);
  tcase_add_test(tc_core, test_is_less_or_equal_ok94);
  tcase_add_test(tc_core, test_is_less_or_equal_ok95);
  tcase_add_test(tc_core, test_is_less_or_equal_ok96);
  tcase_add_test(tc_core, test_is_less_or_equal_ok97);
  tcase_add_test(tc_core, test_is_less_or_equal_ok98);
  tcase_add_test(tc_core, test_is_less_or_equal_ok99);
  tcase_add_test(tc_core, test_is_less_or_equal_ok100);
  tcase_add_test(tc_core, test_is_less_or_equal_ok101);
  tcase_add_test(tc_core, test_is_less_or_equal_ok102);
  tcase_add_test(tc_core, test_is_less_or_equal_ok103);
  tcase_add_test(tc_core, test_is_less_or_equal_ok104);
  tcase_add_test(tc_core, test_is_less_or_equal_ok105);
  tcase_add_test(tc_core, test_is_less_or_equal_ok106);
  tcase_add_test(tc_core, test_is_less_or_equal_ok107);
  tcase_add_test(tc_core, test_is_less_or_equal_ok108);
  tcase_add_test(tc_core, test_is_less_or_equal_ok109);
  tcase_add_test(tc_core, test_is_less_or_equal_ok110);
  tcase_add_test(tc_core, test_is_less_or_equal_ok111);
  tcase_add_test(tc_core, test_is_less_or_equal_ok112);
  tcase_add_test(tc_core, test_is_less_or_equal_ok113);
  tcase_add_test(tc_core, test_is_less_or_equal_ok114);
  tcase_add_test(tc_core, test_is_less_or_equal_ok115);
  tcase_add_test(tc_core, test_is_less_or_equal_ok116);
  tcase_add_test(tc_core, test_is_less_or_equal_ok117);
  tcase_add_test(tc_core, test_is_less_or_equal_ok118);
  tcase_add_test(tc_core, test_is_less_or_equal_ok119);
  tcase_add_test(tc_core, test_is_less_or_equal_ok120);
  tcase_add_test(tc_core, test_is_less_or_equal_ok121);
  tcase_add_test(tc_core, test_is_less_or_equal_ok122);
  tcase_add_test(tc_core, test_is_less_or_equal_ok123);
  tcase_add_test(tc_core, test_is_less_or_equal_ok124);
  tcase_add_test(tc_core, test_is_less_or_equal_ok125);
  tcase_add_test(tc_core, test_is_less_or_equal_ok126);
  tcase_add_test(tc_core, test_is_less_or_equal_ok127);
  tcase_add_test(tc_core, test_is_less_or_equal_ok128);
  tcase_add_test(tc_core, test_is_less_or_equal_ok129);
  tcase_add_test(tc_core, test_is_less_or_equal_ok130);
  tcase_add_test(tc_core, test_is_less_or_equal_ok131);
  tcase_add_test(tc_core, test_is_less_or_equal_ok132);
  tcase_add_test(tc_core, test_is_less_or_equal_ok133);
  tcase_add_test(tc_core, test_is_less_or_equal_ok134);
  tcase_add_test(tc_core, test_is_less_or_equal_ok135);
  tcase_add_test(tc_core, test_is_less_or_equal_ok136);
  tcase_add_test(tc_core, test_is_less_or_equal_ok137);
  tcase_add_test(tc_core, test_is_less_or_equal_ok138);
  tcase_add_test(tc_core, test_is_less_or_equal_ok139);
  tcase_add_test(tc_core, test_is_less_or_equal_ok140);
  tcase_add_test(tc_core, test_is_less_or_equal_ok141);
  tcase_add_test(tc_core, test_is_less_or_equal_ok142);
  tcase_add_test(tc_core, test_is_less_or_equal_ok143);
  tcase_add_test(tc_core, test_is_less_or_equal_ok144);
  tcase_add_test(tc_core, test_is_less_or_equal_ok145);
  tcase_add_test(tc_core, test_is_less_or_equal_ok146);
  tcase_add_test(tc_core, test_is_less_or_equal_ok147);
  tcase_add_test(tc_core, test_is_less_or_equal_ok148);
  tcase_add_test(tc_core, test_is_less_or_equal_ok149);
  tcase_add_test(tc_core, test_is_less_or_equal_ok150);
  tcase_add_test(tc_core, test_is_less_or_equal_ok151);
  tcase_add_test(tc_core, test_is_less_or_equal_ok152);
  tcase_add_test(tc_core, test_is_less_or_equal_ok153);
  tcase_add_test(tc_core, test_is_less_or_equal_ok154);
  tcase_add_test(tc_core, test_is_less_or_equal_ok155);
  tcase_add_test(tc_core, test_is_less_or_equal_ok156);
  tcase_add_test(tc_core, test_is_less_or_equal_ok157);
  tcase_add_test(tc_core, test_is_less_or_equal_ok158);
  tcase_add_test(tc_core, test_is_less_or_equal_ok159);
  tcase_add_test(tc_core, test_is_less_or_equal_ok160);
  tcase_add_test(tc_core, test_is_less_or_equal_ok161);
  tcase_add_test(tc_core, test_is_less_or_equal_ok162);
  tcase_add_test(tc_core, test_is_less_or_equal_ok163);
  tcase_add_test(tc_core, test_is_less_or_equal_ok164);
  tcase_add_test(tc_core, test_is_less_or_equal_ok165);
  tcase_add_test(tc_core, test_is_less_or_equal_ok166);
  tcase_add_test(tc_core, test_is_less_or_equal_ok167);
  tcase_add_test(tc_core, test_is_less_or_equal_ok168);
  tcase_add_test(tc_core, test_is_less_or_equal_ok169);
  tcase_add_test(tc_core, test_is_less_or_equal_ok170);
  tcase_add_test(tc_core, test_is_less_or_equal_ok171);
  tcase_add_test(tc_core, test_is_less_or_equal_ok172);
  tcase_add_test(tc_core, test_is_less_or_equal_ok173);
  tcase_add_test(tc_core, test_is_less_or_equal_ok174);
  tcase_add_test(tc_core, test_is_less_or_equal_ok175);
  tcase_add_test(tc_core, test_is_less_or_equal_ok176);
  tcase_add_test(tc_core, test_is_less_or_equal_ok177);
  tcase_add_test(tc_core, test_is_less_or_equal_ok178);
  tcase_add_test(tc_core, test_is_less_or_equal_ok179);
  tcase_add_test(tc_core, test_is_less_or_equal_ok180);
  tcase_add_test(tc_core, test_is_less_or_equal_ok181);
  tcase_add_test(tc_core, test_is_less_or_equal_ok182);
  tcase_add_test(tc_core, test_is_less_or_equal_ok183);
  tcase_add_test(tc_core, test_is_less_or_equal_ok184);
  tcase_add_test(tc_core, test_is_less_or_equal_ok185);
  tcase_add_test(tc_core, test_is_less_or_equal_ok186);
  tcase_add_test(tc_core, test_is_less_or_equal_ok187);
  tcase_add_test(tc_core, test_is_less_or_equal_ok188);
  tcase_add_test(tc_core, test_is_less_or_equal_ok189);
  tcase_add_test(tc_core, test_is_less_or_equal_ok190);
  tcase_add_test(tc_core, test_is_less_or_equal_ok191);
  tcase_add_test(tc_core, test_is_less_or_equal_ok192);
  tcase_add_test(tc_core, test_is_less_or_equal_ok193);
  tcase_add_test(tc_core, test_is_less_or_equal_ok194);
  tcase_add_test(tc_core, test_is_less_or_equal_ok195);
  tcase_add_test(tc_core, test_is_less_or_equal_ok196);
  tcase_add_test(tc_core, test_is_less_or_equal_ok197);
  tcase_add_test(tc_core, test_is_less_or_equal_ok198);
  tcase_add_test(tc_core, test_is_less_or_equal_ok199);
  tcase_add_test(tc_core, test_is_less_or_equal_ok200);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok201);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok202);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok203);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok204);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok205);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok206);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok207);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok208);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok209);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok210);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok211);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok212);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok213);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok214);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok215);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok216);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok217);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok218);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok219);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok220);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok221);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok222);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok223);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok224);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok225);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok226);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok227);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok228);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok229);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok230);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok231);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok232);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok233);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok234);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok235);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok236);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok237);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok238);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok239);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok240);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok241);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok242);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok243);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok244);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok245);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok246);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok247);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok248);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok249);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok250);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok251);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok252);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok253);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok254);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok255);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok256);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok257);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok258);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok259);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok260);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok261);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok262);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok263);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok264);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok265);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok266);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok267);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok268);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok269);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok270);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok271);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok272);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok273);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok274);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok275);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok276);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok277);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok278);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok279);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok280);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok281);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok282);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok283);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok284);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok285);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok286);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok287);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok288);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok289);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok290);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok291);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok292);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok293);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok294);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok295);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok296);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok297);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok298);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok299);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok300);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1000);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1001);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1002);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1003);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1004);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1005);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1006);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1007);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1008);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1009);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1010);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1011);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1012);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1013);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1014);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1015);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1016);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1017);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1018);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1019);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1020);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1021);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1022);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1023);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1024);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1025);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1026);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1027);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1028);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1029);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1030);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1031);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1032);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1033);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1034);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1035);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1036);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1037);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1038);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1039);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1040);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1041);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1042);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1043);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1044);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1045);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1046);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1047);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1048);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1049);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1050);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1051);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1052);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1053);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1054);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1055);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1056);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1057);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1058);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1059);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1060);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1061);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1062);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1063);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1064);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1065);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1066);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1067);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1068);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1069);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1070);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1071);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1072);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1073);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1074);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1075);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1076);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1077);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1078);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1079);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1080);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1081);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1082);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1083);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1084);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1085);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1086);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1087);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1088);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1089);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1090);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1091);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1092);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1093);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1094);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1095);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1096);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1097);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1098);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1099);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1100);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1101);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1102);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1103);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1104);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1105);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1106);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1107);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1108);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1109);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1110);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1111);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1112);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1113);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1114);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1115);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1116);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1117);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1118);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1119);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1120);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1121);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1122);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1123);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1124);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1125);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1126);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1127);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1128);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1129);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1130);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1131);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1132);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1133);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1134);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1135);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1136);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1137);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1138);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1139);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1140);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1141);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1142);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1143);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1144);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1145);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1146);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1147);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1148);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1149);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1150);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1151);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1152);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1153);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1154);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1155);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1156);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1157);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1158);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1159);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1160);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1161);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1162);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1163);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1164);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1165);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1166);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1167);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1168);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1169);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1170);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1171);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1172);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1173);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1174);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1175);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1176);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1177);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1178);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1179);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1180);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1181);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1182);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1183);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1184);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1185);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1186);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1187);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1188);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1189);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1190);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1191);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1192);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1193);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1194);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1195);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1196);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1197);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1198);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1199);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1200);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1201);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1202);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1203);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1204);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1205);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1206);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1207);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1208);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1209);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1210);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1211);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1212);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1213);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1214);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1215);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1216);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1217);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1218);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1219);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1220);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1221);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1222);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1223);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1224);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1225);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1226);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1227);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1228);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1229);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1230);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1231);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1232);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1233);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1234);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1235);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1236);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1237);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1238);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1239);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1240);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1241);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1242);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1243);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1244);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1245);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1246);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1247);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1248);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1249);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1250);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1251);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1252);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1253);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1254);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1255);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1256);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1257);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1258);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1259);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1260);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1261);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1262);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1263);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1264);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1265);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1266);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1267);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1268);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1269);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1270);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1271);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1272);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1273);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1274);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1275);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1276);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1277);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1278);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1279);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1280);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1281);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1282);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1283);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1284);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1285);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1286);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1287);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1288);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1289);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1290);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1291);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1292);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1293);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1294);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1295);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1296);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1297);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1298);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1299);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok1300);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2000);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2001);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2002);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2003);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2004);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2005);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2006);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2007);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2008);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2009);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2010);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2011);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2012);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2013);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2014);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2015);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2016);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2017);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2018);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2019);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2020);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2021);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2022);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2023);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2024);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2025);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2026);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2027);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2028);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2029);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2030);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2031);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2032);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2033);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2034);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2035);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2036);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2037);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2038);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2039);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2040);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2041);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2042);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2043);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2044);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2045);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2046);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2047);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2048);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2049);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2050);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2051);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2052);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2053);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2054);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2055);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2056);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2057);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2058);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2059);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2060);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2061);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2062);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2063);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2064);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2065);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2066);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2067);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2068);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2069);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2070);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2071);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2072);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2073);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2074);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2075);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2076);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2077);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2078);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2079);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2080);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2081);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2082);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2083);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2084);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2085);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2086);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2087);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2088);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2089);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2090);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2091);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2092);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2093);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2094);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2095);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2096);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2097);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2098);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2099);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2100);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2101);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2102);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2103);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2104);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2105);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2106);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2107);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2108);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2109);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2110);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2111);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2112);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2113);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2114);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2115);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2116);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2117);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2118);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2119);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2120);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2121);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2122);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2123);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2124);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2125);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2126);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2127);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2128);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2129);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2130);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2131);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2132);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2133);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2134);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2135);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2136);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2137);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2138);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2139);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2140);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2141);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2142);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2143);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2144);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2145);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2146);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2147);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2148);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2149);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2150);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2151);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2152);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2153);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2154);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2155);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2156);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2157);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2158);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2159);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2160);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2161);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2162);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2163);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2164);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2165);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2166);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2167);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2168);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2169);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2170);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2171);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2172);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2173);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2174);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2175);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2176);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2177);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2178);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2179);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2180);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2181);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2182);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2183);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2184);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2185);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2186);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2187);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2188);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2189);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2190);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2191);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2192);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2193);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2194);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2195);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2196);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2197);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2198);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2199);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2200);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2201);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2202);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2203);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2204);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2205);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2206);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2207);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2208);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2209);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2210);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2211);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2212);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2213);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2214);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2215);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2216);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2217);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2218);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2219);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2220);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2221);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2222);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2223);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2224);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2225);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2226);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2227);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2228);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2229);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2230);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2231);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2232);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2233);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2234);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2235);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2236);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2237);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2238);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2239);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2240);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2241);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2242);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2243);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2244);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2245);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2246);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2247);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2248);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2249);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2250);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2251);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2252);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2253);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2254);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2255);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2256);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2257);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2258);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2259);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2260);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2261);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2262);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2263);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2264);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2265);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2266);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2267);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2268);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2269);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2270);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2271);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2272);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2273);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2274);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2275);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2276);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2277);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2278);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2279);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2280);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2281);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2282);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2283);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2284);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2285);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2286);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2287);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2288);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2289);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2290);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2291);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2292);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2293);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2294);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2295);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2296);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2297);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2298);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2299);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok2300);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6000);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6001);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6002);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6003);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6004);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6005);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6006);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6007);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6008);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6009);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6010);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6011);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6012);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6013);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6014);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6015);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6016);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6017);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6018);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6019);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6020);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6021);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6022);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6023);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6024);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6025);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6026);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6027);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6028);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6029);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6030);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6031);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6032);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6033);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6034);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6035);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6036);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6037);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6038);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6039);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6040);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6041);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6042);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6043);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6044);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6045);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6046);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6047);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6048);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6049);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6050);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6051);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6052);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6053);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6054);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6055);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6056);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6057);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6058);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6059);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6060);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6061);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6062);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6063);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6064);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6065);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6066);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6067);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6068);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6069);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6070);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6071);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6072);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6073);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6074);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6075);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6076);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6077);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6078);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6079);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6080);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6081);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6082);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6083);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6084);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6085);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6086);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6087);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6088);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6089);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6090);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6091);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6092);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6093);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6094);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6095);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6096);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6097);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6098);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6099);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6100);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6101);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6102);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6103);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6104);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6105);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6106);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6107);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6108);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6109);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6110);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6111);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6112);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6113);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6114);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6115);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6116);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6117);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6118);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6119);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6120);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6121);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6122);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6123);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6124);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6125);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6126);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6127);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6128);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6129);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6130);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6131);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6132);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6133);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6134);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6135);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6136);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6137);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6138);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6139);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6140);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6141);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6142);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6143);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6144);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6145);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6146);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6147);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6148);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6149);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6150);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6151);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6152);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6153);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6154);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6155);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6156);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6157);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6158);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6159);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6160);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6161);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6162);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6163);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6164);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6165);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6166);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6167);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6168);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6169);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6170);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6171);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6172);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6173);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6174);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6175);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6176);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6177);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6178);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6179);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6180);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6181);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6182);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6183);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6184);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6185);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6186);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6187);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6188);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6189);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6190);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6191);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6192);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6193);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6194);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6195);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6196);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6197);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6198);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6199);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6200);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6201);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6202);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6203);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6204);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6205);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6206);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6207);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6208);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6209);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6210);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6211);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6212);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6213);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6214);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6215);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6216);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6217);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6218);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6219);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6220);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6221);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6222);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6223);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6224);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6225);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6226);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6227);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6228);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6229);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6230);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6231);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6232);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6233);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6234);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6235);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6236);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6237);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6238);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6239);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6240);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6241);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6242);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6243);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6244);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6245);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6246);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6247);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6248);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6249);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6250);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6251);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6252);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6253);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6254);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6255);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6256);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6257);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6258);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6259);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6260);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6261);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6262);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6263);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6264);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6265);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6266);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6267);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6268);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6269);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6270);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6271);
  // tcase_add_test(tc_core, test_is_less_or_equal_ok6272);
  suite_add_tcase(c, tc_core);
  return c;
}