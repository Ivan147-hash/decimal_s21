#include "s21_decimal.h"

int greater_num(int a, int b) {
  int flag = 0;
  if (a > b) {
    flag = 1;
  } else if (a < b) {
    flag = 2;
  } else if (a == b) {
    flag = 0;
  }
  return flag;
}