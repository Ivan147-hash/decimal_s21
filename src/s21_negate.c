#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (correct(value) && result) {
    *result = value;
    set_sign(result, !get_sign(value));
  } else
    flag = 1;
  return flag;
}