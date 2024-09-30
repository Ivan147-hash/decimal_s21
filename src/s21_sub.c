#include "s21_decimal.h"

// Вычитание
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  dec_to_null(result);
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;
  int sign = get_sign(value_1);
  int sign2 = get_sign(value_2);
  if (correct(value_1) && correct(value_2)) {
    scale_equalize(&value_1, &value_2);
    set_scale(result, get_scale(value_1));
    if (sign == 0 && sign2 == 0) {
      tmp1 = value_2;
      if (!s21_is_less(tmp1, value_1)) {
        minus(value_2, value_1, result);
        if (!s21_zero(*result)) set_sign(result, 1);
      } else {
        minus(value_1, value_2, result);
      }
    } else if (sign == 1 && sign2 == 1) {
      set_sign(&tmp1, 0);
      set_sign(&tmp2, 0);
      if (!s21_is_less(tmp1, tmp2)) {
        minus(value_1, value_2, result);
        if (!s21_zero(*result)) set_sign(result, 1);
      } else {
        minus(value_2, value_1, result);
      }
    } else if (sign == 1 && sign2 == 0) {
      plus(value_1, value_2, result);
      set_sign(result, 1);
      if (first_unzero_bit(*result)) res = 2;
    } else if (sign == 0 && sign2 == 1) {
      plus(value_1, value_2, result);
      set_sign(result, 0);
      if (first_unzero_bit(*result)) res = 1;
    }
  } else
    res = 4;
  if (res) {
    dec_to_null(result);
    set_sign(result, 0);
  }
  if (first_unzero_bit(*result) && get_scale(*result)) {
    round_float(result);
  }
  return res;
}

// Заём десятков при вычитании
int loan(s21_decimal *num, int i, int bit_num) {
  for (int j = i + 1; j < 112 && !bit_num; j++) {
    if (get_bit(*num, j) == 1) {
      set_bit(num, j, 0);
      bit_num = 2;
      for (int x = j - 1; x > i; x--) {
        set_bit(num, x, 1);
      }
    }
  }
  return bit_num;
}

// Вычетание
void minus(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int tmp = 0;
  int bit_num = 0;
  for (int i = 0; i < 112; i++) {
    bit_num = get_bit(num, i);
    if (bit_num == 0 && get_bit(num2, i) == 1) {
      bit_num = loan(&num, i, bit_num);
    }
    tmp = bit_num - get_bit(num2, i);
    set_bit(res, i, tmp);
  }
}