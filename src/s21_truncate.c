#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  unsigned ost = 0;
  int scale = get_scale(value);
  int sign = get_sign(value);
  if (correct(value) && result) {
    dec_to_null(result);
    while (scale > 0) {
      s21_div_to_10(&value, &ost);
      scale--;
    }
    s21_copy(result, value);
    set_sign(result, sign);
  } else
    flag = 1;
  return flag;
}