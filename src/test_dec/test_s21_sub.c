#include "testes.h"

// START_TEST(invalid_dec_s21_sub_1) {
//   // ссылка на результат - NULL
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
//   int result_value = s21_sub(dec_1, dec_2, NULL);

//   ck_assert_int_eq(result_value, 1);
// }

// START_TEST(invalid_dec_s21_sub_2) {
//   // степень 56 (допустимое значение от 0 до 28)
//   // биты 0-15 не пустые
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_3) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_4) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_5) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_6) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_7) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_8) {
//   // Все биты имеют максимальное значение
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_9) {
//   // степень 56 (допустимое значение от 0 до 28)
//   // биты 0-15 не пустые
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_10) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_11) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_12) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_13) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_14) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_15) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_sub_16) {
//   // Все биты имеют максимальное значение
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_sub(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

START_TEST(s21_sub_1) {
  // -38178469410
  s21_decimal dec_1 = {{0xe39d3622, 0x8, 0x0, 0x80000000}};
  // 362065596622989.326694
  s21_decimal dec_2 = {{0xa7267966, 0xa0ab65d2, 0x13, 0x60000}};
  // -362103775092399.326694
  s21_decimal dec_check = {{0x4266c5e6, 0xa13308f0, 0x13, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_2) {
  // -0.9627812234
  s21_decimal dec_1 = {{0x3ddcc18a, 0x2, 0x0, 0x800a0000}};
  // -14201087.8
  s21_decimal dec_2 = {{0x876e9fe, 0x0, 0x0, 0x80010000}};
  // 14201086.8372187766
  s21_decimal dec_check = {{0xe391aa76, 0x1f88621, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // 9675
  s21_decimal dec_1 = {{0x25cb, 0x0, 0x0, 0x0}};
  // 54271747531353452276
  s21_decimal dec_2 = {{0xf2016ef4, 0xf12bfad5, 0x2, 0x0}};
  // -54271747531353442601
  s21_decimal dec_check = {{0xf2014929, 0xf12bfad5, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 0.297159242156
  s21_decimal dec_1 = {{0x301231ac, 0x45, 0x0, 0xc0000}};
  // -358113940266701472154
  s21_decimal dec_2 = {{0xb832c19a, 0x69d44b4d, 0x13, 0x80000000}};
  // 358113940266701472154.29715924
  s21_decimal dec_check = {{0xe84fc7d4, 0x2c29953f, 0x73b67da8, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // 4184.12832113
  s21_decimal dec_1 = {{0x6b592571, 0x61, 0x0, 0x80000}};
  // 6244691872309392
  s21_decimal dec_2 = {{0xa0c7e090, 0x162f83, 0x0, 0x0}};
  // -6244691872305207.87167887
  s21_decimal dec_check = {{0xfad56a8f, 0x8adf769a, 0x843c, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // 538246604535.90630
  s21_decimal dec_1 = {{0x567e0666, 0xbf393e, 0x0, 0x50000}};
  // 5428137456772083110034
  s21_decimal dec_2 = {{0xec4c5092, 0x428a316d, 0x126, 0x0}};
  // -5428137456233836505498.09370
  s21_decimal dec_check = {{0x9bf2c0da, 0x1ced2171, 0x1c10148, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_7) {
  // -77338.079211330108504865
  s21_decimal dec_1 = {{0xf175bb21, 0x8173e7ff, 0x1060, 0x80120000}};
  // 319102443.22758
  s21_decimal dec_2 = {{0xaec70dc6, 0x1d05, 0x0, 0x50000}};
  // -319179781.306791330108504865
  s21_decimal dec_check = {{0xd03d7b21, 0x9d8530a2, 0x10804f2, 0x80120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_8) {
  // -326473674138622
  s21_decimal dec_1 = {{0x136023fe, 0x128ed, 0x0, 0x80000000}};
  // -79228162514264337592696670433
  s21_decimal dec_2 = {{0xcd7f88e1, 0xffffffff, 0xffffffff, 0x80000000}};
  // 79228162514264011119022531811
  s21_decimal dec_check = {{0xba1f64e3, 0xfffed712, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // -305451936607932
  s21_decimal dec_1 = {{0x922d6ebc, 0x115ce, 0x0, 0x80000000}};
  // -9287581741526
  s21_decimal dec_2 = {{0x6f02b1d6, 0x872, 0x0, 0x80000000}};
  // -296164354866406
  s21_decimal dec_check = {{0x232abce6, 0x10d5c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // -46785954
  s21_decimal dec_1 = {{0x2c9e5a2, 0x0, 0x0, 0x80000000}};
  // 9034923.043461673888
  s21_decimal dec_2 = {{0x928633a0, 0x7d627ea3, 0x0, 0xc0000}};
  // -55820877.043461673888
  s21_decimal dec_check = {{0x5a4a53a0, 0x6ab97eb, 0x3, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // 36449697824092786.328
  s21_decimal dec_1 = {{0x5f610e98, 0xf9d7570d, 0x1, 0x30000}};
  // -27318654803.194
  s21_decimal dec_2 = {{0x9eb71cfa, 0x18d8, 0x0, 0x80030000}};
  // 36449725142747589.522
  s21_decimal dec_check = {{0xfe182b92, 0xf9d76fe5, 0x1, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // -49751
  s21_decimal dec_1 = {{0xc257, 0x0, 0x0, 0x80000000}};
  // 2834483978753
  s21_decimal dec_2 = {{0xf4692201, 0x293, 0x0, 0x0}};
  // -2834484028504
  s21_decimal dec_check = {{0xf469e458, 0x293, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // 477.7
  s21_decimal dec_1 = {{0x12a9, 0x0, 0x0, 0x10000}};
  // 8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x0}};
  // 469.7
  s21_decimal dec_check = {{0x1259, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // 34.28882640711
  s21_decimal dec_1 = {{0x5954ef47, 0x31e, 0x0, 0xb0000}};
  // -151874517632
  s21_decimal dec_2 = {{0x5c6d3a80, 0x23, 0x0, 0x80000000}};
  // 151874517666.28882640711
  s21_decimal dec_check = {{0x4d58ef47, 0x503ba32e, 0x337, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // 1613.662201
  s21_decimal dec_1 = {{0x602e87f9, 0x0, 0x0, 0x60000}};
  // 41181220052794962
  s21_decimal dec_2 = {{0xf8a9fe52, 0x924e19, 0x0, 0x0}};
  // -41181220052793348.337799
  s21_decimal dec_check = {{0x84b03087, 0x703bca8f, 0x8b8, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // 574.5
  s21_decimal dec_1 = {{0x1671, 0x0, 0x0, 0x10000}};
  // 75301279032584333300565746384
  s21_decimal dec_2 = {{0x4c8722d0, 0xe73bb663, 0xf34fc213, 0x0}};
  // -75301279032584333300565745810
  s21_decimal dec_check = {{0x4c872092, 0xe73bb663, 0xf34fc213, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_17) {
  // 1347279633393062286713583844
  s21_decimal dec_1 = {{0xdfce78e4, 0x4604db45, 0x45a718f, 0x0}};
  // 8420180505
  s21_decimal dec_2 = {{0xf5e1c219, 0x1, 0x0, 0x0}};
  // 1347279633393062278293403339
  s21_decimal dec_check = {{0xe9ecb6cb, 0x4604db43, 0x45a718f, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_18) {
  // 22914203
  s21_decimal dec_1 = {{0x15da49b, 0x0, 0x0, 0x0}};
  // -72829597737090
  s21_decimal dec_2 = {{0xf64d6082, 0x423c, 0x0, 0x80000000}};
  // 72829620651293
  s21_decimal dec_check = {{0xf7ab051d, 0x423c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_19) {
  // 19997190542706777
  s21_decimal dec_1 = {{0xbecdc859, 0x470b56, 0x0, 0x0}};
  // 308349356588999177392396
  s21_decimal dec_2 = {{0x3e9bd10c, 0xa6f100c9, 0x414b, 0x0}};
  // -308349336591808634685619
  s21_decimal dec_check = {{0x7fce08b3, 0xa6a9f572, 0x414b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_20) {
  // -96875413493285809425021.88
  s21_decimal dec_1 = {{0x2fac192c, 0xab39b482, 0x8036a, 0x80020000}};
  // -79228162514264337592900215344
  s21_decimal dec_2 = {{0xd9a16230, 0xffffffff, 0xffffffff, 0x80000000}};
  // 79228065638850844307090790322
  s21_decimal dec_check = {{0x592757b2, 0x5f9157cb, 0xffffeb7c, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(fail_s21_sub_1) {
//   // 5817500175.313708004
//   s21_decimal dec_1 = {{0x4658a3e4, 0x50bbe996, 0x0, 0x90000}};
//   // -93482317170687687947610.69
//   s21_decimal dec_2 = {{0x5145d76d, 0xa825d3b0, 0x7bb90, 0x80020000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_sub_2) {
//   // 9.74480010636604220118984
//   s21_decimal dec_1 = {{0x486817c8, 0xaacf819e, 0xce5a, 0x170000}};
//   // -83929721289852656
//   s21_decimal dec_2 = {{0x79446f0, 0x12a2da3, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_sub_3) {
//   // -8018763932102.793660221
//   s21_decimal dec_1 = {{0xed90873d, 0xb2b44f03, 0x1b2, 0x80090000}};
//   // -9197150985716934517.6959878488
//   s21_decimal dec_2 = {{0xb2028558, 0xb21ca359, 0x292d0cc3, 0x800a0000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_sub_4) {
//   // 83706.6158
//   s21_decimal dec_1 = {{0x31e49dae, 0x0, 0x0, 0x40000}};
//   // -808673226066189838293644980
//   s21_decimal dec_2 = {{0xd823b6b4, 0x6d35151a, 0x29ceb37, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_sub_5) {
//   // 8984.5024788972
//   s21_decimal dec_1 = {{0xacc991ec, 0x51b6, 0x0, 0xa0000}};
//   // -96080134174988853823
//   s21_decimal dec_2 = {{0x5014623f, 0x356134fa, 0x5, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(fail_s21_sub_6) {
//   // -4.0934055
//   s21_decimal dec_1 = {{0x2709aa7, 0x0, 0x0, 0x80070000}};
//   // -9497312589867150164169
//   s21_decimal dec_2 = {{0xc4a340c9, 0xd9b05990, 0x202, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 3; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

Suite *suite_sub(void) {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

  // tcase_add_test(tc, invalid_dec_s21_sub_1);
  // tcase_add_test(tc, invalid_dec_s21_sub_2);
  // tcase_add_test(tc, invalid_dec_s21_sub_3);
  // tcase_add_test(tc, invalid_dec_s21_sub_4);
  // tcase_add_test(tc, invalid_dec_s21_sub_5);
  // tcase_add_test(tc, invalid_dec_s21_sub_6);
  // tcase_add_test(tc, invalid_dec_s21_sub_7);
  // tcase_add_test(tc, invalid_dec_s21_sub_8);
  // tcase_add_test(tc, invalid_dec_s21_sub_9);
  // tcase_add_test(tc, invalid_dec_s21_sub_10);
  // tcase_add_test(tc, invalid_dec_s21_sub_11);
  // tcase_add_test(tc, invalid_dec_s21_sub_12);
  // tcase_add_test(tc, invalid_dec_s21_sub_13);
  // tcase_add_test(tc, invalid_dec_s21_sub_14);
  // tcase_add_test(tc, invalid_dec_s21_sub_15);
  // tcase_add_test(tc, invalid_dec_s21_sub_16);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);
  // tcase_add_test(tc, fail_s21_sub_1);
  // tcase_add_test(tc, fail_s21_sub_2);
  // tcase_add_test(tc, fail_s21_sub_3);
  // tcase_add_test(tc, fail_s21_sub_4);
  // tcase_add_test(tc, fail_s21_sub_5);
  // tcase_add_test(tc, fail_s21_sub_6);

  suite_add_tcase(c, tc);
  return c;
}
