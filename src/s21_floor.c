#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  unsigned ost = 0;
  int f = 0;
  int scale = get_scale(value);
  int sign = get_sign(value);
  s21_decimal one = {{1, 0, 0, 2147483648u}};
  if (correct(value) && result) {
    dec_to_null(result);
    if (!sign) {
      s21_truncate(value, result);
    } else {
      while (scale > 0) {
        s21_div_to_10(&value, &ost);
        if (ost) {
          f = 1;
        }
        scale--;
      }
      if (f)
        s21_add(value, one, result);
      else
        s21_copy(result, value);
    }
    set_sign(result, sign);
  } else
    flag = 1;
  return flag;
}