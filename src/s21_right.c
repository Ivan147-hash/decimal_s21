#include "s21_decimal.h"

// Сдвигает децимал побитово вправо
void right(s21_decimal *num) {
  int tmp = get_bit(*num, 64);
  int tmp1 = get_bit(*num, 32);
  for (int i = 2; i >= 0; i--) {
    num->bits[i] >>= 1;
  }
  set_bit(num, 63, tmp);
  set_bit(num, 31, tmp1);
}