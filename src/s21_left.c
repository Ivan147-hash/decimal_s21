#include "s21_decimal.h"

// Сдвигает децимал побитово влево
void left(s21_decimal *num, int shift) {
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit(*num, 31);
    int tmp1 = get_bit(*num, 63);
    for (int i = 0; i < 3; i++) {
      num->bits[i] <<= 1;
    }
    set_bit(num, 32, tmp);
    set_bit(num, 64, tmp1);
  }
}

// Сдвигает децимал побитово влево залезая в 0 байт
int left_to_div(s21_decimal *num, int shift) {
  int flag = 1;
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit(*num, 31);
    int tmp1 = get_bit(*num, 63);
    int tmp2 = get_bit(*num, 95);
    for (int i = 0; i < 5; i++) {
      num->bits[i] <<= 1;
    }
    set_bit(num, 32, tmp);
    set_bit(num, 64, tmp1);
    set_bit(num, 96, tmp2);
  }
  return flag;
}

int left_for_big(big_decimal *num, int shift) {
  int flag = 1;
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit_big(*num, 31);
    int tmp1 = get_bit_big(*num, 63);
    int tmp2 = get_bit_big(*num, 95);
    int tmp3 = get_bit_big(*num, 127);
    int tmp4 = get_bit_big(*num, 159);
    int tmp5 = get_bit_big(*num, 191);
    int tmp6 = get_bit_big(*num, 223);
    for (int i = 0; i < 9; i++) {
      num->bits[i] <<= 1;
    }
    set_bit_big(num, 32, tmp);
    set_bit_big(num, 64, tmp1);
    set_bit_big(num, 96, tmp2);
    set_bit_big(num, 128, tmp3);
    set_bit_big(num, 160, tmp4);
    set_bit_big(num, 192, tmp5);
    set_bit_big(num, 224, tmp6);
  }
  return flag;
}