#ifndef SRC_TESTS_TESTES_H_
#define SRC_TESTS_TESTES_H_

#include <check.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

#define MAX_INT 2147483647   // 0b01111111111111111111111111111111
#define MAX_UINT 4294967295  // 0b11111111111111111111111111111111
#define MINUS 2147483648     // 0b10000000000000000000000000000000
#define EXPONENT_20 1310720  // 0b00000000000101000000000000000000
#define TEST_OTHER_ERROR 1
#define TEST_OTHER_OK 0

#define TEST_CONVERSION_OK 0
#define TEST_CONVERSION_ERROR 1

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;
typedef union test_decimal_bytes {
  s21_decimal d;
  struct {
    uint32_t part0;
    uint32_t part1;
    uint32_t part2;
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} test_decimal_bytes;

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_div(void);
Suite *suite_mul(void);
Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);
// Suite *suite_comparison(void);
Suite *suite_floor(void);

Suite *negate_suite1(void);
Suite *negate_suite2(void);
Suite *negate_suite3(void);
Suite *negate_suite0(void);

Suite *floor_suite1(void);
Suite *floor_suite2(void);
Suite *floor_suite3(void);
Suite *floor_suite0(void);

Suite *round_suite1(void);
Suite *round_suite2(void);
Suite *round_suite3(void);
Suite *round_suite0(void);

Suite *truncate_suite1(void);
Suite *truncate_suite2(void);
Suite *truncate_suite3(void);
Suite *truncate_suite0(void);

Suite *suite_round(void);
Suite *suite_truncate(void);

Suite *suite_int_to_decimal(void);
Suite *suite_decimal_to_int(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_from_decimal_to_float(void);

Suite *from_int_to_decimal_suite(void);
// Suite *from_float_to_decimal_suite(void);

void test_negate(s21_decimal decimal, s21_decimal decimal_check);
void test_floor(s21_decimal decimal, s21_decimal decimal_check);
void test_round(s21_decimal decimal, s21_decimal decimal_check);
void test_truncate(s21_decimal decimal, s21_decimal decimal_check);
void test_from_int_to_decimal(int number, s21_decimal decimal_check);
void test_from_float_to_decimal(int f, s21_decimal decimal_check);

int test_decimal_get_sign(s21_decimal value);

#endif