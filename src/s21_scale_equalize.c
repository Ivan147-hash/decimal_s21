#include "s21_decimal.h"

void scale_inc(s21_decimal *num) {
  if ((get_scale(*num) + 1) < 29) {
    if (!first_unzero_bit(*num)) {
      set_scale(num, (get_scale(*num) + 1));
      mul_to_10(num);
    }
  } else {
    while (get_scale(*num) > 28) {
      round_float(num);
    }
  }
}

// Эта функция должна выравнивать дробную часть
int scale_equalize(s21_decimal *num, s21_decimal *num2) {
  s21_decimal *big = NULL;
  s21_decimal *small = NULL;
  s21_decimal tmp = {{0, 0, 0, 0}};
  int per = 0;
  int out = 1;
  if (get_scale(*num) != get_scale(*num2)) {
    ;
    if (get_scale(*num) > get_scale(*num2)) {
      big = num;
      small = num2;
      per = 1;
    } else {
      big = num2;
      small = num;
    }
    int scaleB = get_scale(*big);
    int scaleS = get_scale(*small);
    // int scale = scaleB - scaleS;
    increase(big, small, &tmp, &scaleS);
    set_scale(&tmp, scaleS);
    int scale2 = scaleB - scaleS;
    while (scale2) {
      round_float(big);
      set_scale(big, scaleS);
      scale2--;
    }
    if (per) {
      num = big;
      num2 = &tmp;
    } else {
      num = &tmp;
      num2 = big;
    }
    out = 0;
  } else if (get_scale(*num) > 28 && get_scale(*num2) > 28) {
    while (get_scale(*num) > 28 && get_scale(*num2) > 28) {
      round_float(num);
      round_float(num2);
    }
  }
  return out;
}

void increase(s21_decimal *big, s21_decimal *small, s21_decimal *tmp,
              int *scaleS) {
  int scaleB = get_scale(*big);
  int scale = scaleB - *scaleS;
  int flag = 1;
  while (scale && flag) {
    for (int i = 0; i < 4; i++) {
      tmp->bits[i] = small->bits[i];
    }
    scale_inc(small);
    if (!first_unzero_bit(*small)) {
      s21_copy(tmp, *small);
      *scaleS = get_scale(*small);
      scale--;
    } else {
      round_float(small);
      *scaleS = get_scale(*small);
      flag = 0;
    }
  }
}