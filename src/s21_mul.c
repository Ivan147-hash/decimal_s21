#include "s21_decimal.h"

// Умножение на 10
int mul_to_10(s21_decimal *num) {
  int flag = 0;
  s21_decimal temp = {{0b1010, 0, 0, 0}};
  // s21_decimal tmp = temp;
  s21_decimal tmp1 = {{0, 0, 0, 0}};
  for (int i = 0; i < 102; i++) {
    s21_decimal tmp = temp;
    if (get_bit(*num, i)) {
      for (int j = 0; j < i; j++) {
        left_to_div(&tmp, 1);
      }
      plus(tmp1, tmp, &tmp1);
    }
  }
  s21_copy(num, tmp1);
  return flag;
}

// Умножение
int s21_mul(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int result = 0;
  int over = 0;
  dec_to_null(res);
  if (correct(num) && correct(num2)) {
    if (!s21_zero(num) && !s21_zero(num2)) {
      if (get_sign(num) != get_sign(num2)) {
        set_sign(res, 1);
      }
      over = multiplication(num, num2, res);
    }
    if (over && get_sign(*res)) {
      result = 2;
    } else if (over && !get_sign(*res)) {
      result = 1;
    }
    if (s21_zero(*res)) set_sign(res, 0);
  } else
    result = 4;
  if (result) {
    dec_to_null(res);
    set_sign(res, 0);
  }
  return result;
}

int multiplication(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int flag = 0;
  big_decimal tmp1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  int scale = get_scale(num) + get_scale(num2);
  big_decimal value = {{0, 0, 0, 0, 0, 0, 0, 0}};
  decimal_to_bigdecimal(num2, &value);
  big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  decimal_to_bigdecimal(num2, &tmp);
  set_scale(&num2, 0);
  set_sign(&num2, 0);
  for (int i = 0; i < 96; i++) {
    tmp = value;
    if (get_bit(num, i)) {
      for (int j = 0; j < i; j++) {
        left_for_big(&tmp, 1);
      }
      plus_bigdec(tmp1, tmp, &tmp1);
    }
  }
  while (overflow(tmp1) && scale) {
    round_float_big(&tmp1);
    scale--;
  }
  if (overflow(tmp1)) flag = 1;
  bigdecimal_to_decimal(res, tmp1);
  set_scale(res, scale);
  while (get_scale(*res) > 28) {
    round_float(res);
  }
  return flag;
}