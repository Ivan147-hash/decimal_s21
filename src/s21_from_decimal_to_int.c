#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  if ((!dst) || src.bits[1] != 0 || src.bits[2] != 0 || src.bits[0] >> 31 != 0)
    flag = 1;
  else {
    int scale;
    *dst = src.bits[0];
    scale = get_scale(src);
    while (scale) {
      *dst = *dst / 10;
      scale--;
    }
    if (src.bits[3] >> 31) *dst = *dst * (-1);
  }
  return flag;
}