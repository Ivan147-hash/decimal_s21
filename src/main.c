#include "s21_decimal.h"

void print_dec(s21_decimal num) {
  for (int i = 3; i >= 0; i--) {
    print_bin(num.bits[i]);
  }
  printf("\n");
}

void print_bin(int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if (i % 8 == 0) printf(" ");
  }
  printf("\n");
}
