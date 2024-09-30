#include "s21_decimal.h"

int s21_is_equal(s21_decimal d1, s21_decimal d2) {  // ==
  int res = comparison(d1, d2) == 0;
  return res ? 1 : 0;
}

int s21_is_greater(s21_decimal d1, s21_decimal d2) {  // >
  int res = comparison(d1, d2) == 1;
  return res ? 1 : 0;
}

int s21_is_less_or_equal(s21_decimal d1, s21_decimal d2) {  // <=
  int res = (comparison(d1, d2) == 2) || (comparison(d1, d2) == 0);
  return res ? 1 : 0;
}

int s21_is_less(s21_decimal d1, s21_decimal d2) {  // <
  int res = comparison(d1, d2) == 2;
  return res ? 1 : 0;
}

int s21_is_greater_or_equal(s21_decimal d1, s21_decimal d2) {  // >=
  int res = (comparison(d1, d2) == 1) || (comparison(d1, d2) == 0);
  return res ? 1 : 0;
}

int s21_is_not_equal(s21_decimal d1, s21_decimal d2) {  // !=
  int res = comparison(d1, d2) == 0;
  return res ? 0 : 1;
}