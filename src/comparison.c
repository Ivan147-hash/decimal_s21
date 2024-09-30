#include "s21_decimal.h"

int comparison(
    s21_decimal d1,
    s21_decimal d2) {  // 0, 1, 2, если dec1 = dec2, dec1 > dec2, dec1 < dec2
  int flag = 0;
  int scale_dif = (get_scale(d1) - get_scale(d2));
  scale_equalize(&d1, &d2);
  flag = greater_num(!get_sign(d1), !get_sign(d2));
  if (flag == 0) {
    if (scale_dif >= 0) {
      flag = comparison_bits(d1, d2);
    } else {
      scale_dif = -scale_dif;
      flag = comparison_bits(d2, d1);
      comparison_reverse(&flag);
    }
    if (get_sign(d1) && get_sign(d2)) {
      comparison_reverse(&flag);
    }
  } else {
    if (d1.bits[0] == 0 && d1.bits[1] == 0 && d1.bits[2] == 0 &&
        d2.bits[0] == 0 && d2.bits[1] == 0 && d2.bits[2] == 0) {
      flag = 0;
    }
  }
  return flag;
}

void comparison_reverse(int *flag) {
  if (*flag == 1) {
    *flag = 2;
  } else if (*flag == 2) {
    *flag = 1;
  }
}

int comparison_bits(s21_decimal d1, s21_decimal d2) {
  int bit1 = 0;
  int bit2 = 0;
  int flag = 0;
  for (int i = 95; i >= 0 && !flag; --i) {
    bit1 = get_bit(d1, i);
    bit2 = get_bit(d2, i);
    if (bit1 > bit2) {
      flag = 1;
    } else if (bit1 < bit2) {
      flag = 2;
    }
  }
  return flag;
}