#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  int znak = 0;
  if (!dst)
    flag = 1;
  else {
    dec_to_null(dst);
    if (src < 0) {
      znak = 1;
      src *= -1;
    }
    dst->bits[0] = src;
    set_sign(dst, znak);
  }
  return flag;
}