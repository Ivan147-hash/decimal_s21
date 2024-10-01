#include "s21_decimal.h"

int get_num(int *i, int *ind_e, int *ind_tochka, char my_float[24]) {
  int num = 0;
  for (; my_float[*i] != 'e'; *i += 1) {
    if (my_float[*i] == '.') *ind_tochka = *i;
    num *= 10;
    num += my_float[*i] - '0';
  }
  *ind_e = *i;
  *i += 1;
  return num;
}

int get_pow(int *i, char my_float[24]) {
  int pow = 0;
  int pow_sign = 0;
  if (my_float[*i] == '-') {
    pow_sign = 1;
    *i += 1;
  } else
    *i += 1;
  for (; my_float[*i]; *i += 1) {
    pow *= 10;
    pow += my_float[*i] - '0';
  }
  if (pow_sign) pow *= -1;
  return pow;
}