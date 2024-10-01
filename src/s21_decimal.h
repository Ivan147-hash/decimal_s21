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

int s21_add(s21_decimal num, s21_decimal num2, s21_decimal *res);  // Сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Вычитание
int s21_mul(s21_decimal num, s21_decimal num2, s21_decimal *res);  // Умножение
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // Деление

int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_is_less(s21_decimal d1, s21_decimal d2);   // Сравнение d1 < d2
int s21_is_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 == d2
int less(s21_decimal num,
         s21_decimal num2);  // Сравнение d1 < d2 включая 4й байт
int s21_is_less_or_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 <= d2
int s21_is_greater(s21_decimal d1, s21_decimal d2);  // Сравнение d1 > d2
int s21_is_greater_or_equal(s21_decimal d1,
                            s21_decimal d2);  // Сравнение d1 >= d2
int s21_is_not_equal(s21_decimal d1, s21_decimal d2);  // Сравнение d1 != d2

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

void del(s21_decimal num, s21_decimal num2, s21_decimal *res,
         s21_decimal *res2);  // Деление с остатком
int loan(s21_decimal *num, int i, int bit_num);  // Заём десятков при вычитании
void s21_div_to_10(s21_decimal *num, unsigned *rest);  // Делит число на 10
int mul_to_10(s21_decimal *num);  // Доумножает число на 10
int left_to_div(s21_decimal *num, int shift);  // Сдвиг влево включая 4й бит
int multiplication(s21_decimal num, s21_decimal num2, s21_decimal *res);

void minus(s21_decimal num, s21_decimal num2,
           s21_decimal *res);  // Вычитание двух положительных децималов
int plus(s21_decimal num, s21_decimal num2,
         s21_decimal *res);  // Сложение двух положительных децималов
int add_and_sign(s21_decimal num, s21_decimal num2, s21_decimal *res, int sign,
                 int sign2);  // Сложение и установка знака
void increase(s21_decimal *big, s21_decimal *small, s21_decimal *tmp,
              int *scaleS);  // Понижение скейла

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

int scale_equalize(
    s21_decimal *num,
    s21_decimal *num2);  // Эта функция должна выравнивать дробную часть
void scale_inc(s21_decimal *num);  // Доумножает число на 10, но не больше 29

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

void set_bit_big(big_decimal *num, int index, int bit);
int get_bit_big(big_decimal num, int x);
void decimal_to_bigdecimal(s21_decimal value_1, big_decimal *value_2);
void bigdecimal_to_decimal(s21_decimal *value_1, big_decimal value_2);
void print_dec_big(big_decimal num);
int plus_bigdec(big_decimal num, big_decimal num2, big_decimal *res);
int left_for_big(big_decimal *num, int shift);
void big_div_to_10(big_decimal *num, unsigned *rest);
void round_float_big(big_decimal *num);
int overflow(big_decimal value);
void dec_to_doub(s21_decimal src, long double *dst);

void decimal_to_null_lacie(s21_decimal *decl);
void set_bit_lacie(s21_decimal *decl, int index, int bit);
int check_scale(s21_decimal decimal);
void set_znak(s21_decimal *num, int sign);
void set_scale_lacie(s21_decimal *num, int sign);
int get_num(int *i, int *ind_e, int *ind_tochka, char my_float[24]);
int get_pow(int *i, char my_float[24]);

#endif
