#include "s21_decimal.h"

// Сравнение num < num2
int less(s21_decimal num, s21_decimal num2) {
  int less = 0;
  int flag = 0;
  int sign1 = get_sign(num);
  int sign2 = get_sign(num2);
  if (sign1 == 0 && sign2 == 0) {
    for (int i = 111; i >= 0 && !flag; i--) {
      if (get_bit(num, i) < get_bit(num2, i)) {
        less = 1;
        flag = 1;
      } else if (get_bit(num, i) > get_bit(num2, i)) {
        less = 0;
        flag = 1;
      }
    }
  }
  for (int i = 111; i >= 0 && !flag; i--) {
    if (get_bit(num, i) != get_bit(num2, i)) {
      less = 0;
      flag = 1;
    }
  }
  return less;
}