#ifndef C5_S21_DECIMAL_1_S21_DECIMAL_H
#define C5_S21_DECIMAL_1_S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_DECIMAL powl(2.0, 96)
#define MIN_DECIMAL -1 * MAX_DECIMAL
#define MAX_SCALE 28
#define U_MAX_INT 4294967295

typedef struct decimal {
  int bits[4];
} s21_decimal;

typedef struct big_decimal {
  int bits[8];
} big_decimal;

int s21_is_less(s21_decimal d1, s21_decimal d2);   // Сравнение d1 < d2
int s21_is_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 == d2
int less(s21_decimal num,
         s21_decimal num2);  // Сравнение d1 < d2 включая 4й байт
int s21_is_less_or_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 <= d2
int s21_is_greater(s21_decimal d1, s21_decimal d2);  // Сравнение d1 > d2
int s21_is_greater_or_equal(s21_decimal d1,
                            s21_decimal d2);  // Сравнение d1 >= d2
int s21_is_not_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 != d2

int get_scale(s21_decimal num);  // Получаем дробную часть в нужном децимале
int get_sign(s21_decimal num);  // Получаем знак установленный в нужном децимале
void set_scale(s21_decimal *num,
               int scl);  // Устанавливает дробную часть в нужном децимале
void set_sign(s21_decimal *num,
              int sig);  // Устанавливает знак в нужном децимале
void set_bit(s21_decimal *num, int index,
             int bit);  // Устанавливаем бит по индексу
int get_bit(s21_decimal num, int x);  // Получаем нужный бит по индексу х

void right(s21_decimal *num);            // Сдвиг вправо
void left(s21_decimal *num, int shift);  // Сдвиг влево
int correct(s21_decimal num);  // Проверяем децимал на корректность содержания
// void to_null(s21_decimal *num);  //Обнуляет децимал
int s21_zero(s21_decimal num);  // Проверяет децимал на ноль
void s21_copy(s21_decimal *num, s21_decimal num2);  // Копирует num2 в num

int comparison(s21_decimal d1, s21_decimal d2);
int greater_num(int a, int b);
int comparison_bits(s21_decimal d1, s21_decimal d2);
void comparison_reverse(int *flag);
int first_unzero_bit(
    s21_decimal num);  // Проверяем 4й байт на наличие лиших битов
void dec_to_null(s21_decimal *num);  // Зануляем децимал
void round_float(s21_decimal *num);  // Округление децимала
int count_float_dig(float num, unsigned int *re_num);

void print_dec(s21_decimal num);  // Печатает децимал decimal
void print_bin(int num);  // Переводит десятичное число в 32 двоичных

void decimal_to_null_lacie(s21_decimal *decl);
void set_bit_lacie(s21_decimal *decl, int index, int bit);
int check_scale(s21_decimal decimal);
void set_znak(s21_decimal *num, int sign);
void set_scale_lacie(s21_decimal *num, int sign);
int get_num(int *i, int *ind_e, int *ind_tochka, char my_float[24]);
int get_pow(int *i, char my_float[24]);

#endif
