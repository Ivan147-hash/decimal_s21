#include "s21_decimal.h"

// Проверяем децимал на корректность содержания
int correct(s21_decimal num) {
  int flag = 1;
  for (int i = 126; i >= 120 && flag; i--) {
    if (get_bit(num, i) == 1) flag = 0;
  }
  for (int i = 96; i <= 111 && flag; i++) {
    if (get_bit(num, i) == 1) flag = 0;
  }
  if (get_scale(num) > 28) flag = 0;
  return flag;
}