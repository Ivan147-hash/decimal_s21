#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  unsigned remainder = 0;
  unsigned integer = 0;
  int f = 0;
  unsigned rem = 0;
  int scale = get_scale(value);
  int scl = scale;
  int sign = get_sign(value);
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal temp = {{0, 0, 0, 0}};
  s21_decimal temp1 = value;
  if (correct(value) && result) {
    dec_to_null(result);
    while (scl > 0) {
      s21_div_to_10(&temp1, &rem);
      scl--;
    }
    while (scale > 0) {
      s21_div_to_10(&value, &remainder);
      temp = value;
      s21_div_to_10(&temp, &integer);
      if (remainder) {
        if (scale > 1) f = 1;
        if (remainder > 5)
          plus(value, one, &value);
        else if (remainder == 5 && integer % 2)
          plus(value, one, &value);
        else if (remainder == 5 && f)
          plus(value, one, &value);
      }
      scale--;
    }
    if (rem < 5 && remainder > 5) {
      minus(value, one, &value);
    } else if (rem < 5 && remainder == 5 && integer % 2) {
      minus(value, one, &value);
    } else if (rem < 5 && remainder == 5 && f) {
      minus(value, one, &value);
    }
    s21_copy(result, value);
    set_sign(result, sign);
  } else
    flag = 1;
  return flag;
}