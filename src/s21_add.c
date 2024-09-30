#include "s21_decimal.h"

int s21_add(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int result = 0;
  int sign = get_sign(num);
  int sign2 = get_sign(num2);
  dec_to_null(res);
  if (correct(num) && correct(num2)) {
    scale_equalize(&num, &num2);
    set_scale(res, get_scale(num));
    result = 0;
    result = add_and_sign(num, num2, res, sign, sign2);
    if (first_unzero_bit(*res) && get_scale(*res)) {
      round_float(res);
    }
    if (first_unzero_bit(*res) && !get_sign(*res)) {
      result = 1;
    } else if (first_unzero_bit(*res) && get_sign(*res)) {
      result = 2;
    }
  } else
    result = 4;
  if (result) {
    dec_to_null(res);
    set_sign(res, 0);
  }
  return result;
}

int add_and_sign(s21_decimal num, s21_decimal num2, s21_decimal *res, int sign,
                 int sign2) {
  int result = 0;
  int tmp = 0;
  s21_decimal tmp1 = num;
  if (sign == 0 && sign2 == 0) {
    tmp = plus(num, num2, res);
    if (tmp == 0) result = 1;
  } else if (sign == 1 && sign2 == 1) {
    tmp = plus(num, num2, res);
    if (tmp == 0) result = 2;
    set_sign(res, 1);
  } else if (sign == 1 && sign2 == 0) {
    set_sign(&tmp1, 0);
    if (s21_is_less(tmp1, num2)) {
      minus(num2, num, res);
    } else {
      minus(num, num2, res);
      if (!s21_zero(*res)) set_sign(res, 1);
    }
  } else if (sign == 0 && sign2 == 1) {
    tmp1 = num2;
    set_sign(&tmp1, 0);
    if (!s21_is_less(tmp1, num)) {
      minus(num2, num, res);
      if (!s21_zero(*res)) set_sign(res, 1);
    } else {
      minus(num, num2, res);
    }
  }
  return result;
}

void round_float(s21_decimal *num) {
  unsigned int remainder = 0;
  unsigned int integer = 0;
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal temp = {{0, 0, 0, 0}};
  s21_div_to_10(num, &remainder);
  temp = *num;
  s21_div_to_10(&temp, &integer);
  if (remainder > 5) {
    plus(*num, one, num);
  } else if (remainder == 5 && integer % 2) {
    plus(*num, one, num);
  }
}

// Сложение двух положительных децималов
int plus(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int tmp = 0;
  int per = 0;
  int flag = 1;
  int finish = 111;
  for (int i = 0; i < finish; i++) {
    tmp = get_bit(num, i) + get_bit(num2, i) + per;
    if (tmp == 2) {
      tmp = 0;
      per = 1;
    } else if (tmp == 3) {
      tmp = 1;
      per = 1;
    } else if (tmp == 0) {
      tmp = 0;
      per = 0;
    } else if (tmp == 1) {
      tmp = 1;
      per = 0;
    }
    set_bit(res, i, tmp);
  }
  return flag;
}

int plus_bigdec(big_decimal num, big_decimal num2, big_decimal *res) {
  int tmp = 0;
  int per = 0;
  int flag = 1;
  int finish = 255;
  for (int i = 0; i < finish; i++) {
    tmp = get_bit_big(num, i) + get_bit_big(num2, i) + per;
    if (tmp == 2) {
      tmp = 0;
      per = 1;
    } else if (tmp == 3) {
      tmp = 1;
      per = 1;
    } else if (tmp == 0) {
      tmp = 0;
      per = 0;
    } else if (tmp == 1) {
      tmp = 1;
      per = 0;
    }
    set_bit_big(res, i, tmp);
  }
  return flag;
}