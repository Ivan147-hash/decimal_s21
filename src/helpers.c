#include "s21_decimal.h"

// Копирование num2 в num
void s21_copy(s21_decimal *num, s21_decimal num2) {
  for (int i = 0; i < 102; i++) {
    set_bit(num, i, get_bit(num2, i));
  }
}

// Возвращает 1, если num равен 0
int s21_zero(s21_decimal num) {
  int res = 1;
  for (int i = 0; i < 96 && res; i++) {
    if (get_bit(num, i) != 0) res = 0;
  }
  return res;
}

// Проверяет 3 старших бита на 0
int first_unzero_bit(s21_decimal num) {
  int flag = 0;
  for (int i = 111; i > 95 && !flag; i--) {
    if (get_bit(num, i)) flag = 1;
  }
  return flag;
}

// Зануляет децимал
void dec_to_null(s21_decimal *num) {
  for (int i = 0; i < 128; i++) {
    set_bit(num, i, 0);
  }
}

void decimal_to_bigdecimal(s21_decimal value_1, big_decimal *value_2) {
  for (int i = 0; i < 96; i++) {
    set_bit_big(value_2, i, get_bit(value_1, i));
  }
}

void bigdecimal_to_decimal(s21_decimal *value_1, big_decimal value_2) {
  for (int i = 0; i < 112; i++) {
    set_bit(value_1, i, get_bit_big(value_2, i));
  }
}

int overflow(big_decimal value) {
  int flag = 0;
  for (int i = 255; i > 95 && !flag; i--) {
    if (get_bit_big(value, i)) flag = 1;
  }
  return flag;
}

void round_float_big(big_decimal *num) {
  unsigned int remainder = 0;
  unsigned int integer = 0;
  big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  big_div_to_10(num, &remainder);
  temp = *num;
  big_div_to_10(&temp, &integer);
  if (remainder > 5) {
    plus_bigdec(*num, one, num);
  } else if (remainder == 5 && integer % 2) {
    plus_bigdec(*num, one, num);
  }
}