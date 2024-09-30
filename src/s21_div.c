#include "s21_decimal.h"

void s21_div_to_10(s21_decimal *num, unsigned *rest) {
  uint64_t p_rest = 0;
  int div = 10;
  int scale = get_scale(*num);
  int sign = get_sign(*num);
  set_scale(num, 0);
  set_sign(num, 0);
  *rest = 0;
  for (int i = 3; i >= 0; i--) {
    p_rest = *rest * 4294967296 + (unsigned int)num->bits[i];
    num->bits[i] = p_rest / div;
    *rest = p_rest - div * (unsigned int)num->bits[i];
  }
  if (scale) {
    set_scale(num, (scale - 1));
  }
  set_sign(num, sign);
}

// Деление без остатка
void del(s21_decimal num1, s21_decimal num2, s21_decimal *res,
         s21_decimal *res2) {
  s21_decimal q = {{0, 0, 0, 0}};
  s21_decimal s = {{0, 0, 0, 0}};
  int i = 0;
  if (!s21_zero(num2)) {
    set_sign(&num1, 0);
    set_sign(&num2, 0);
    s21_decimal tmp1 = num1;
    s21_decimal tmp2 = num2;
    s21_decimal temp = tmp2;
    dec_to_null(res);
    dec_to_null(res2);
    while (!s21_zero(tmp1) && !less(tmp1, num2)) {
      tmp2 = num2;
      i = 0;
      while (less(tmp2, tmp1)) {
        left_to_div(&tmp2, 1);
        i++;
      }
      dec_to_null(&q);
      if (i <= 1) {
        set_bit(&q, 0, 1);
      } else {
        set_bit(&q, 0, 0);
        set_bit(&q, 1, 1);
        left(&q, i - 2);
      }
      plus(s, q, &s);
      temp = num2;
      left_to_div(&temp, i - 1);
      s21_sub(tmp1, temp, &tmp1);
    }
    plus(*res, s, res);
    dec_to_null(&temp);
    multiplication(num2, *res, &temp);
    minus(num1, temp, res2);
  } else {
    dec_to_null(res);
    dec_to_null(res2);
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  dec_to_null(result);
  int flag = 0;
  int sign = 0;
  int corr = 1;
  if (!correct(value_1) || !correct(value_2)) corr = 0;
  if (!s21_zero(value_2) && corr) {
    if (get_sign(value_1) != get_sign(value_2)) {
      sign = 1;
    }
    int scale = get_scale(value_1) - get_scale(value_2);
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);
    s21_decimal integer = {{0, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    del(value_1, value_2, &integer, &remainder);
    s21_add(*result, integer, result);
    while (!s21_zero(remainder) && scale < 30) {
      if (!first_unzero_bit(*result) && scale < 30) {
        mul_to_10(&remainder);
        del(remainder, value_2, &integer, &remainder);
        flag = mul_to_10(result);
        plus(*result, integer, result);
        scale++;
      } else
        dec_to_null(&remainder);
    }
    if (scale < 0) {
      while (scale) {
        mul_to_10(result);
        scale++;
      }
    }
    if (first_unzero_bit(*result) && !scale) {
      if (get_sign(*result))
        flag = 2;
      else
        flag = 1;
    }
    while (scale > 28) {
      round_float(result);
      scale--;
    }
    set_scale(result, scale);
  } else {
    if (!corr)
      flag = 4;
    else
      flag = 3;
  }
  if (first_unzero_bit(*result) && get_scale(*result)) {
    round_float(result);
  }
  set_sign(result, sign);
  if (flag) {
    dec_to_null(result);
  }
  return flag;
}

// Деление на 10
void big_div_to_10(big_decimal *num, unsigned *rest) {
  uint64_t p_rest = 0;
  int div = 10;
  *rest = 0;
  for (int i = 7; i >= 0; i--) {
    p_rest = *rest * 4294967296 + (unsigned int)num->bits[i];
    num->bits[i] = p_rest / div;
    *rest = p_rest - div * (unsigned int)num->bits[i];
  }
}