#include "s21_decimal.h"

// Получаем нужный бит по индексу х
int get_bit(s21_decimal num, int x) {
  int n_int = x / 32;
  int n_num = x % 32;
  int res = (num.bits[n_int] & (1u << n_num)) >> x;
  return res;
}

// Получаем знак установленный в нужном децимале
int get_sign(s21_decimal num) { return get_bit(num, 127); }

// Получаем дробную часть в нужном децимале
int get_scale(s21_decimal num) {
  int scale = 0;
  for (int i = 119; i >= 112; i--) {
    scale <<= 1;
    scale |= get_bit(num, i);
  }
  return scale;
}

int get_bit_big(big_decimal num, int x) {
  int n_int = x / 32;
  int n_num = x % 32;
  int res = (num.bits[n_int] & (1u << n_num)) >> x;
  return res;
}