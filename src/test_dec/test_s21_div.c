#include "testes.h"

START_TEST(invalid_dec_s21_div_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(s21_div_1) {
  // -577314571099
  s21_decimal dec_1 = {{0x6aa1435b, 0x86, 0x0, 0x80000000}};
  // 5.3
  s21_decimal dec_2 = {{0x35, 0x0, 0x0, 0x10000}};
  // -108927277565.84905660377358491
  s21_decimal dec_check = {{4187512986U, 0xe62d166c, 0x233240d2, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_2) {
  // -4831383097121609
  s21_decimal dec_1 = {{0x9471b49, 0x112a1e, 0x0, 0x80000000}};
  // 63316305617.6556
  s21_decimal dec_2 = {{0xc30c5dac, 0x23fdb, 0x0, 0x40000}};
  // -76305.511668614939027390159076
  s21_decimal dec_check = {{0x696d58e4, 0x2fbf87bb, 0xf68e709c, 0x80180000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_3) {
  // -2746549920729
  s21_decimal dec_1 = {{0x7b21e3d9, 0x27f, 0x0, 0x80000000}};
  // -673
  s21_decimal dec_2 = {{0x2a1, 0x0, 0x0, 0x80000000}};
  // 4081054859.9242199108469539376
  s21_decimal dec_check = {{0x34ba4230, 0x94c8621f, 0x83ddb1d0, 0x130000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_4) {
  // 80620494445
  s21_decimal dec_1 = {{0xc55b1e6d, 0x12, 0x0, 0x0}};
  // -284829
  s21_decimal dec_2 = {{0x4589d, 0x0, 0x0, 0x80000000}};
  // -283048.75713147186557548564226
  s21_decimal dec_check = {{0xa0c90f02, 0x19e17ea, 0x5b753e93, 0x80170000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_5) {
  // 65984703916576616
  s21_decimal dec_1 = {{0x158e8f68, 0xea6cbd, 0x0, 0x0}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -32992351958288308
  s21_decimal dec_check = {{0x8ac747b4, 0x75365e, 0x0, 0x80000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_6) {
  // 331584031307852999135
  s21_decimal dec_1 = {{0xc094e9df, 0xf9a71faa, 0x11, 0x0}};
  // 2104321866
  s21_decimal dec_2 = {{0x7d6d674a, 0x0, 0x0, 0x0}};
  // 157572867851.31614420766561573
  s21_decimal dec_check = {{0xfa801525, 0x3eef74cf, 0x32ea1f44, 0x110000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_7) {
  // -66911244177021875.748358584299
  s21_decimal dec_1 = {{0x3dbff7eb, 0x591fc03, 0xd833af17, 0x800c0000}};
  // -6158199582701589
  s21_decimal dec_2 = {{0x92953815, 0x15e0d9, 0x0, 0x80000000}};
  // 10.865390651672912472105396163
  s21_decimal dec_check = {{0xe4d1a7c3, 0x78ed71ed, 0x231ba3f7, 0x1b0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_8) {
  // -2139023.8
  s21_decimal dec_1 = {{0x146639e, 0x0, 0x0, 0x80010000}};
  // -9854
  s21_decimal dec_2 = {{0x267e, 0x0, 0x0, 0x80000000}};
  // 217.07162573574183072863811650
  s21_decimal dec_check = {{0xa52af842, 0x9cb490d, 0x4623be79, 0x1a0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_9) {
  // 7375134613869737.799565
  s21_decimal dec_1 = {{0x396bef8d, 0xce8da02d, 0x18f, 0x60000}};
  // -6975834
  s21_decimal dec_2 = {{0x6a715a, 0x0, 0x0, 0x80000000}};
  // -1057240555.5908781372327667201
  s21_decimal dec_check = {{0xc1012601, 0x9b0f8ab1, 0x222949f5, 0x80130000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_10) {
  // 3551277782815000529539244520
  s21_decimal dec_1 = {{0x548921e8, 0x5c832ab9, 0xb798c52, 0x0}};
  // -1463.1
  s21_decimal dec_2 = {{0x3927, 0x0, 0x0, 0x80010000}};
  // -2427228339016472236716044.3715
  s21_decimal dec_check = {{0xb260e343, 0x23d867bd, 0x4e6d8fef, 0x80040000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_11) {
  // -88523564080838212233495
  s21_decimal dec_1 = {{0x228aa917, 0xdf3d0194, 0x12be, 0x80000000}};
  // 1.11
  s21_decimal dec_2 = {{0x6f, 0x0, 0x0, 0x20000}};
  // -79750958631385776786932.432432
  s21_decimal dec_check = {{2395674987U, 127776363, 432330813, 2147811328U}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_12) {
  // -851561910764315760
  s21_decimal dec_1 = {{0xcb5c2470, 0xbd15b0b, 0x0, 0x80000000}};
  // -6.453896221913203741
  s21_decimal dec_2 = {{0x6c5f441d, 0x5990d86b, 0x0, 0x80120000}};
  // 131945398792278275.80761382631
  s21_decimal dec_check = {{2324537062U, 430664093, 715277440, 720896}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_13) {
  // -7590806288363.9
  s21_decimal dec_1 = {{0xb91faf37, 0x4509, 0x0, 0x80010000}};
  // 87048123
  s21_decimal dec_2 = {{0x5303fbb, 0x0, 0x0, 0x0}};
  // -87202.412030916508102075905761
  s21_decimal dec_check = {{2193152176U, 3648483813U, 472725222, 2148990976U}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_14) {
  // -2798195773868392
  s21_decimal dec_1 = {{0xb91d0968, 0x9f0f1, 0x0, 0x80000000}};
  // -9031719
  s21_decimal dec_2 = {{0x89d027, 0x0, 0x0, 0x80000000}};
  // 309818737.03869573444435106982
  s21_decimal dec_check = {{0xc5e6dca6, 0xdecef94a, 0x641b9af2, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_15) {
  // -45653714730246
  s21_decimal dec_1 = {{0x9572fd06, 0x2985, 0x0, 0x80000000}};
  // 303
  s21_decimal dec_2 = {{0x12f, 0x0, 0x0, 0x0}};
  // -150672325842.39603960396039604
  s21_decimal dec_check = {{0xaa4ec5b4, 0xf10a972, 0x30af529b, 0x80110000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_16) {
  // 339715051607364840025571070
  s21_decimal dec_1 = {{0xf7953efe, 0xd953e735, 0x1190175, 0x0}};
  // -84337.130335884
  s21_decimal dec_2 = {{0x44b1ee8c, 0x4cb4, 0x0, 0x80090000}};
  // -4028060360299239658342.9061031
  s21_decimal dec_check = {{0xa3a1b9a7, 0xc503d466, 0x82275598, 0x80070000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_17) {  // err
  // 1428
  s21_decimal dec_1 = {{0x594, 0x0, 0x0, 0x0}};
  // -53.323
  s21_decimal dec_2 = {{0xd04b, 0x0, 0x0, 0x80030000}};
  // -26.780188661553175927836018229
  s21_decimal dec_check = {{598378036, 0x52460bf8, 0x56880d88, 0x801b0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_18) {
  // 330293097953235216104291
  s21_decimal dec_1 = {{0x5d5bfb63, 0x39871ca2, 0x45f1, 0x0}};
  // 682186876124867
  s21_decimal dec_2 = {{0x26bfec3, 0x26c72, 0x0, 0x0}};
  // 484168062.31959613756426177435
  s21_decimal dec_check = {{0xa8584b9b, 0x13344248, 0x9c717185, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_19) {
  // -706167845309333123422
  s21_decimal dec_1 = {{0x9cc315e, 0x480c29df, 0x26, 0x80000000}};
  // -636762016360
  s21_decimal dec_2 = {{0x41f94a68, 0x94, 0x0, 0x80000000}};
  // 1108998067.0425131314470479858
  s21_decimal dec_check = {{0xdb2067f2, 0xc8ec8390, 0x23d56ac0, 0x130000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_20) {
  // 5118222.08
  s21_decimal dec_1 = {{0x1e81c980, 0x0, 0x0, 0x20000}};
  // -99.51
  s21_decimal dec_2 = {{0x26df, 0x0, 0x0, 0x80020000}};
  // -51434.248618229323686061702341
  s21_decimal dec_check = {{0x5ab27cc5, 0x9a29150c, 0xa63169cc, 0x80180000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_21) {
  // 346242036
  s21_decimal dec_1 = {{0x14a33bf4, 0x0, 0x0, 0x0}};
  // -1.3380
  s21_decimal dec_2 = {{0x3444, 0x0, 0x0, 0x80040000}};
  // -258775811.65919282511210762332
  s21_decimal dec_check = {{0x2286505c, 0xf01fa673, 0x539d6ef5, 0x80140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_22) {
  // -49.535075042803
  s21_decimal dec_1 = {{0x488d45f3, 0x2d0d, 0x0, 0x800c0000}};
  // 8.1
  s21_decimal dec_2 = {{0x51, 0x0, 0x0, 0x10000}};
  // -6.1154413633090123456790123457
  s21_decimal dec_check = {{0xa44bd3c1, 0xe7571eb5, 0xc599becd, 0x801c0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_23) {
  // -82492870395
  s21_decimal dec_1 = {{0x34f54efb, 0x13, 0x0, 0x80000000}};
  // 6884.5
  s21_decimal dec_2 = {{0x10ced, 0x0, 0x0, 0x10000}};
  // -11982405.460817779068922942843
  s21_decimal dec_check = {{0x84b6d57b, 0x9c6d24ba, 0x26b79d0d, 0x80150000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_24) {
  // -9428365611262248384891834
  s21_decimal dec_1 = {{0x41aa8bba, 0xb953dd17, 0x7cc88, 0x80000000}};
  // -56426.232330306021089298474
  s21_decimal dec_2 = {{0xdf13482a, 0x2f130da2, 0x2eacb8, 0x80150000}};
  // 167091886555012076308.78749764
  s21_decimal dec_check = {{0x789a3444, 0x9c94a95, 0x35fd8454, 0x80000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_25) {
  // 1125256723846633817821833
  s21_decimal dec_1 = {{0x61b2d289, 0x4a0af8e0, 0xee48, 0x0}};
  // 2508375423351466.769674363704
  s21_decimal dec_2 = {{0x33676338, 0x2b9bc0e2, 0x81ae128, 0xc0000}};
  // 448599804.22833456128674096322
  s21_decimal dec_check = {{0x2bd5e4c2, 0x9acb1960, 0x90f34e5b, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_26) {
  // -59698360747263.4074833
  s21_decimal dec_1 = {{0xa99616d1, 0x5ccfd40a, 0x20, 0x80070000}};
  // -2764056953
  s21_decimal dec_2 = {{0xa4c02979, 0x0, 0x0, 0x80000000}};
  // 21598.093585759557785530188386
  s21_decimal dec_check = {{0x9a8cc262, 0x5c7d5748, 0x45c98637, 0x180000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_27) {
  // -83477915383469683
  s21_decimal dec_1 = {{0xc5059673, 0x12892b8, 0x0, 0x80000000}};
  // -138.5825588
  s21_decimal dec_2 = {{0x529a0534, 0x0, 0x0, 0x80070000}};
  // 602369562997776.62208961897159
  s21_decimal dec_check = {{0x53b762c7, 0x34e81bbf, 0xc2a2d7a8, 0xe0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_28) {
  // -69506094.53
  s21_decimal dec_1 = {{0x9e49e22d, 0x1, 0x0, 0x80020000}};
  // -21.5
  s21_decimal dec_2 = {{0xd7, 0x0, 0x0, 0x80010000}};
  // 3232841.6060465116279069767442
  s21_decimal dec_check = {{0xe8a47712, 0x49e03882, 0x68757062, 0x160000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_29) {
  // -587812388.581208276
  s21_decimal dec_1 = {{0xc7f4f0d4, 0x8285440, 0x0, 0x80090000}};
  // 358729.47
  s21_decimal dec_2 = {{0x22360b3, 0x0, 0x0, 0x20000}};
  // -1638.5952026222107595453476404
  s21_decimal dec_check = {{0xed13ae34, 0x40f010ee, 0x34f2244f, 0x80190000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_30) {
  // -5913765730671
  s21_decimal dec_1 = {{0xe7e7d96f, 0x560, 0x0, 0x80000000}};
  // -283
  s21_decimal dec_2 = {{0x11b, 0x0, 0x0, 0x80000000}};
  // 20896698694.950530035335689046
  s21_decimal dec_check = {{0x59ddf356, 0x245b5306, 0x43855812, 0x120000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(fail_s21_div_1) {
//   // 714
//   s21_decimal dec_1 = {{0x2ca, 0x0, 0x0, 0x0}};
//   // 80107886
//   s21_decimal dec_2 = {{0x4c6596e, 0x0, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_2) {
//   // -86908275833242735307
//   s21_decimal dec_1 = {{0x1a1952cb, 0xb6183869, 0x4, 0x80000000}};
//   // -7403013745712946077819535695
//   s21_decimal dec_2 = {{0x6b95014f, 0x4d56844b, 0x17eba123, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_3) {
//   // -1528.8381826
//   s21_decimal dec_1 = {{0x8f423182, 0x3, 0x0, 0x80070000}};
//   // 8385993608576206521
//   s21_decimal dec_2 = {{0x8fe186b9, 0x746108c1, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_4) {
//   // -29788
//   s21_decimal dec_1 = {{0x745c, 0x0, 0x0, 0x80000000}};
//   // 86663
//   s21_decimal dec_2 = {{0x15287, 0x0, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_5) {
//   // 18.93
//   s21_decimal dec_1 = {{0x765, 0x0, 0x0, 0x20000}};
//   // -218904764486746277650.31759
//   s21_decimal dec_2 = {{0xcada534f, 0x1b2aaaa3, 0x121b7d, 0x80050000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_6) {
//   // -0.82477
//   s21_decimal dec_1 = {{0x1422d, 0x0, 0x0, 0x80050000}};
//   // 182770384529786
//   s21_decimal dec_2 = {{0x8bd8697a, 0xa63a, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_7) {
//   // -8
//   s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
//   // -6053
//   s21_decimal dec_2 = {{0x17a5, 0x0, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_8) {
//   // 8
//   s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
//   // -55297151141563812177
//   s21_decimal dec_2 = {{0x83ff4951, 0xff66f1fc, 0x2, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_9) {
//   // -0.234186369649
//   s21_decimal dec_1 = {{0x86986a71, 0x36, 0x0, 0x800c0000}};
//   // 40.03669764833562097943
//   s21_decimal dec_2 = {{0xbc307917, 0xa1456c3, 0xd9, 0x140000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_div_10) {
//   // 0.79
//   s21_decimal dec_1 = {{0x4f, 0x0, 0x0, 0x20000}};
//   // -917678770
//   s21_decimal dec_2 = {{0x36b2aab2, 0x0, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

Suite *suite_div(void) {
  Suite *c = suite_create("s21_div_cases");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, invalid_dec_s21_div_2);
  tcase_add_test(tc, invalid_dec_s21_div_3);
  tcase_add_test(tc, invalid_dec_s21_div_4);
  tcase_add_test(tc, invalid_dec_s21_div_5);
  tcase_add_test(tc, invalid_dec_s21_div_6);
  tcase_add_test(tc, invalid_dec_s21_div_7);
  tcase_add_test(tc, invalid_dec_s21_div_8);
  tcase_add_test(tc, invalid_dec_s21_div_9);
  tcase_add_test(tc, invalid_dec_s21_div_10);
  tcase_add_test(tc, invalid_dec_s21_div_11);
  tcase_add_test(tc, invalid_dec_s21_div_12);
  tcase_add_test(tc, invalid_dec_s21_div_13);
  tcase_add_test(tc, invalid_dec_s21_div_14);
  tcase_add_test(tc, invalid_dec_s21_div_15);
  tcase_add_test(tc, invalid_dec_s21_div_16);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_9);
  tcase_add_test(tc, s21_div_10);
  tcase_add_test(tc, s21_div_11);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, s21_div_18);
  tcase_add_test(tc, s21_div_19);
  tcase_add_test(tc, s21_div_20);
  tcase_add_test(tc, s21_div_21);
  tcase_add_test(tc, s21_div_22);
  tcase_add_test(tc, s21_div_23);
  tcase_add_test(tc, s21_div_24);
  tcase_add_test(tc, s21_div_25);
  tcase_add_test(tc, s21_div_26);
  tcase_add_test(tc, s21_div_27);
  tcase_add_test(tc, s21_div_28);
  tcase_add_test(tc, s21_div_29);
  tcase_add_test(tc, s21_div_30);
  // tcase_add_test(tc, fail_s21_div_1);
  // tcase_add_test(tc, fail_s21_div_2);
  // tcase_add_test(tc, fail_s21_div_3);
  // tcase_add_test(tc, fail_s21_div_4);
  // tcase_add_test(tc, fail_s21_div_5);
  // tcase_add_test(tc, fail_s21_div_6);
  // tcase_add_test(tc, fail_s21_div_7);
  // tcase_add_test(tc, fail_s21_div_8);
  // tcase_add_test(tc, fail_s21_div_9);
  // tcase_add_test(tc, fail_s21_div_10);

  suite_add_tcase(c, tc);
  return c;
}
