#include "testes.h"

START_TEST(invalid_dec_s21_add_2) {  // invalid_dec_s21_add_2
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_add_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(s21_add_1) {
  // 1.201
  s21_decimal dec_1 = {{0x4b1, 0x0, 0x0, 0x30000}};
  // 680.33353856233
  s21_decimal dec_2 = {{0x3fe3b4e9, 0x3de0, 0x0, 0xb0000}};
  // 681.53453856233
  s21_decimal dec_check = {{0x366845e9, 0x3dfc, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_2) {
  // 818768636
  s21_decimal dec_1 = {{0x30cd6afc, 0x0, 0x0, 0x0}};
  // -7.0082
  s21_decimal dec_2 = {{0x111c2, 0x0, 0x0, 0x80040000}};
  // 818768628.9918
  s21_decimal dec_check = {{0x582201fe, 0x772, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_3) {
  // -66663588333234884190831529
  s21_decimal dec_1 = {{0x1f0683a9, 0x5d6568b8, 0x372490, 0x80000000}};
  // 5.795764491912618
  s21_decimal dec_2 = {{0x93be05aa, 0x149737, 0x0, 0xf0000}};
  // -66663588333234884190831523.204
  s21_decimal dec_check = {{0x31723584, 0xd4210f39, 0xd766d3ec, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // 7798545866640633824584790
  s21_decimal dec_1 = {{0x50aca456, 0x4bf2ad3, 0x67368, 0x0}};
  // 84093110462311739.643
  s21_decimal dec_2 = {{0xcbc6b0fb, 0x8f06be6b, 0x4, 0x30000}};
  // 7798545950733744286896529.643
  s21_decimal dec_check = {{0xee28a0eb, 0x19c607de, 0x1932ce57, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -2563844.0417138421
  s21_decimal dec_1 = {{0x95a896f5, 0x5b1606, 0x0, 0x800a0000}};
  // 399435139829
  s21_decimal dec_2 = {{0x308af5, 0x5d, 0x0, 0x0}};
  // 399432575984.9582861579
  s21_decimal dec_check = {{0x2a09d0b, 0x8867c3bd, 0xd8, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // 6091552587433.381206876
  s21_decimal dec_1 = {{0x82541b5c, 0x394633d7, 0x14a, 0x90000}};
  // 52
  s21_decimal dec_2 = {{0x34, 0x0, 0x0, 0x0}};
  // 6091552587485.381206876
  s21_decimal dec_check = {{0x9dc5235c, 0x394633e3, 0x14a, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // -78143663018688893886660
  s21_decimal dec_1 = {{0x6c9320c4, 0x2d2c84a0, 0x108c, 0x80000000}};
  // 1933
  s21_decimal dec_2 = {{0x78d, 0x0, 0x0, 0x0}};
  // -78143663018688893884727
  s21_decimal dec_check = {{0x6c931937, 0x2d2c84a0, 0x108c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_8) {
  // 1497461.41
  s21_decimal dec_1 = {{0x8ecf1dd, 0x0, 0x0, 0x20000}};
  // -5851.9
  s21_decimal dec_2 = {{0xe497, 0x0, 0x0, 0x80010000}};
  // 1491609.51
  s21_decimal dec_check = {{0x8e403f7, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_9) {
  // -33603539494929937
  s21_decimal dec_1 = {{0xbaca8611, 0x77623d, 0x0, 0x80000000}};
  // 425194.711
  s21_decimal dec_2 = {{0x1957f4d7, 0x0, 0x0, 0x30000}};
  // -33603539494504742.289
  s21_decimal dec_check = {{0x8dc3bd91, 0xd257c121, 0x1, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_10) {
  // -70656.60749884376109
  s21_decimal dec_1 = {{0x3c47442d, 0x620e4504, 0x0, 0x800e0000}};
  // 35640.175480340763920175435
  s21_decimal dec_2 = {{0x3cf6114b, 0xc8bfdb5a, 0x1d7b19, 0x150000}};
  // -35016.432018502997169824565
  s21_decimal dec_check = {{0x23566335, 0x9556ec66, 0x1cf704, 0x80150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_11) {
  // 43123292118111.2689840152434
  s21_decimal dec_1 = {{0x2d00df72, 0x7fe53cc1, 0x164b51f, 0xd0000}};
  // 248653707620890208950230185
  s21_decimal dec_2 = {{0x1c4b1ca9, 0x7ffd326f, 0xcdae78, 0x0}};
  // 248653707620933332242348296.27
  s21_decimal dec_check = {{0x702a473b, 0xfef70571, 0x50582711, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_12) {
  // -890460020515172132486914964
  s21_decimal dec_1 = {{0x8602394, 0x700d3a0a, 0x2e0923e, 0x80000000}};
  // -570
  s21_decimal dec_2 = {{0x23a, 0x0, 0x0, 0x80000000}};
  // -890460020515172132486915534
  s21_decimal dec_check = {{0x86025ce, 0x700d3a0a, 0x2e0923e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_13) {
  // -81657920
  s21_decimal dec_1 = {{0x4de0040, 0x0, 0x0, 0x80000000}};
  // 447249264863735
  s21_decimal dec_2 = {{0x558ee9f7, 0x196c5, 0x0, 0x0}};
  // 447249183205815
  s21_decimal dec_check = {{0x50b0e9b7, 0x196c5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_14) {
  // -107239874176
  s21_decimal dec_1 = {{0xf7fe9e80, 0x18, 0x0, 0x80000000}};
  // 0.1249
  s21_decimal dec_2 = {{0x4e1, 0x0, 0x0, 0x40000}};
  // -107239874175.8751
  s21_decimal dec_check = {{0x4a0f631f, 0x3cf57, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_15) {
  // 62851849535.569252927982816
  s21_decimal dec_1 = {{0xfe8cce0, 0x972eed84, 0x33fd65, 0xf0000}};
  // -675151061461324769278.0920
  s21_decimal dec_2 = {{0x65923578, 0x1fb11a6f, 0x595b0, 0x80040000}};
  // -675151061398472919742.52274707
  s21_decimal dec_check = {{0x66e4a413, 0x9edf2905, 0xda272fd5, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_16) {
  // -7347438951769
  s21_decimal dec_1 = {{0xb57d1d59, 0x6ae, 0x0, 0x80000000}};
  // 6726687951.6296003019
  s21_decimal dec_2 = {{0x5dd2bdcb, 0xa583f686, 0x3, 0xa0000}};
  // -7340712263817.3703996981
  s21_decimal dec_check = {{0x87238635, 0x6878b7d0, 0xf8b, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_17) {
  // 86439.399
  s21_decimal dec_1 = {{0x526f5e7, 0x0, 0x0, 0x30000}};
  // 28651510055409.188
  s21_decimal dec_2 = {{0x87219624, 0x65ca65, 0x0, 0x30000}};
  // 28651510141848.587
  s21_decimal dec_check = {{0x8c488c0b, 0x65ca65, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_18) {
  // 6957201303955538398420079
  s21_decimal dec_1 = {{0x15641c6f, 0xa36ebb45, 0x5c13e, 0x0}};
  // -16326300549742.72775936
  s21_decimal dec_2 = {{0x4fff2700, 0x814b20f4, 0x58, 0x80080000}};
  // 6957201303939212097870336.2722
  s21_decimal dec_check = {{0xeef3aaa2, 0x132f33bc, 0xe0cc9ed0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_19) {
  // 3365158586.805891275
  s21_decimal dec_1 = {{0xc36bb0cb, 0x2eb371e7, 0x0, 0x90000}};
  // -33375728300482701996059581665
  s21_decimal dec_2 = {{0x6eb0dce1, 0x955de412, 0x6bd7c160, 0x80000000}};
  // -33375728300482701992694423078
  s21_decimal dec_check = {{0xa61c9e26, 0x955de411, 0x6bd7c160, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_20) {
  // -8942592614426683484.960884966
  s21_decimal dec_1 = {{0x6a7688e6, 0x2be0322, 0x1ce523a5, 0x80090000}};
  // 2.2922365
  s21_decimal dec_2 = {{0x15dc47d, 0x0, 0x0, 0x70000}};
  // -8942592614426683482.668648466
  s21_decimal dec_check = {{0xe1d5c812, 0x2be0321, 0x1ce523a5, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(fail_s21_add_1) {
//   // 96608924717759251704717
//   s21_decimal dec_1 = {{0x1f316b8d, 0x2e2856c8, 0x1475, 0x0}};
//   // -846160.44279276789770860656
//   s21_decimal dec_2 = {{0x27db870, 0xf3a4f9bc, 0x45fe24, 0x80140000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_add_2) {
//   // 793485685505029574087528107
//   s21_decimal dec_1 = {{0x3141ceab, 0x33fa1c66, 0x2905b21, 0x0}};
//   // -66.082357
//   s21_decimal dec_2 = {{0x3f05635, 0x0, 0x0, 0x80060000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_add_3) {
//   // 97653541
//   s21_decimal dec_1 = {{0x5d21325, 0x0, 0x0, 0x0}};
//   // 981386804302.66848900729941384
//   s21_decimal dec_2 = {{0x6dae2d88, 0x5e28106d, 0x3d1a69ee, 0x110000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_add_4) {
//   // 6440.5797885857109896257985231
//   s21_decimal dec_1 = {{0x4dc1dacf, 0x6ce8f02a, 0xd01b3a33, 0x190000}};
//   // 8720390296469167408.39
//   s21_decimal dec_2 = {{0xfcce66e7, 0x45f8fd33, 0x2f, 0x20000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_add_5) {
//   // 88483264345542362
//   s21_decimal dec_1 = {{0x63e20eda, 0x13a5b0f, 0x0, 0x0}};
//   // 0.3245812335114
//   s21_decimal dec_2 = {{0xb97dc20a, 0x2f3, 0x0, 0xd0000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_add_6) {
//   // 8402609.60717776800208339
//   s21_decimal dec_1 = {{0xd62455d3, 0xa350e772, 0xb1ee, 0x110000}};
//   // 962799186745260353030442.5
//   s21_decimal dec_2 = {{0xebe55ba9, 0x7c26e0fb, 0x7f6ce, 0x10000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

Suite *suite_add(void) {
  Suite *c = suite_create("s21_add_cases");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, invalid_dec_s21_add_2);
  tcase_add_test(tc, invalid_dec_s21_add_3);
  tcase_add_test(tc, invalid_dec_s21_add_4);
  tcase_add_test(tc, invalid_dec_s21_add_5);
  tcase_add_test(tc, invalid_dec_s21_add_6);
  tcase_add_test(tc, invalid_dec_s21_add_7);
  tcase_add_test(tc, invalid_dec_s21_add_8);
  tcase_add_test(tc, invalid_dec_s21_add_9);
  tcase_add_test(tc, invalid_dec_s21_add_10);
  tcase_add_test(tc, invalid_dec_s21_add_11);
  tcase_add_test(tc, invalid_dec_s21_add_12);
  tcase_add_test(tc, invalid_dec_s21_add_13);
  tcase_add_test(tc, invalid_dec_s21_add_14);
  tcase_add_test(tc, invalid_dec_s21_add_15);
  tcase_add_test(tc, invalid_dec_s21_add_16);
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
  tcase_add_test(tc, s21_add_10);
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_12);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_14);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);
  tcase_add_test(tc, s21_add_17);
  tcase_add_test(tc, s21_add_18);
  tcase_add_test(tc, s21_add_19);
  tcase_add_test(tc, s21_add_20);
  // tcase_add_test(tc, fail_s21_add_1);
  // tcase_add_test(tc, fail_s21_add_2);
  // tcase_add_test(tc, fail_s21_add_3);
  // tcase_add_test(tc, fail_s21_add_4);
  // tcase_add_test(tc, fail_s21_add_5);
  // tcase_add_test(tc, fail_s21_add_6);

  suite_add_tcase(c, tc);
  return c;
}
