#include "s21_decimal.h"

// Устанавливаем бит по индексу
void set_bit(s21_decimal *num, int index, int bit) {
  int num_ind = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    num->bits[num_ind] |= (1u << num_bit);
  } else {
    num->bits[num_ind] &= (~((1u) << num_bit));
  }
}

// Устанавливает знак в нужном децимале
void set_sign(s21_decimal *num, int sig) { set_bit(num, 127, sig); }

// Устанавливает дробную часть в нужном децимале
void set_scale(s21_decimal *num, int scl) {
  for (int i = 112; i < 120; i++) {
    set_bit(num, i, scl & 1);
    scl >>= 1;
  }
}

// Устанавливает бит в биг децимал
void set_bit_big(big_decimal *num, int index, int bit) {
  int num_ind = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    num->bits[num_ind] |= (1u << num_bit);
  } else {
    num->bits[num_ind] &= (~((1u) << num_bit));
  }
}