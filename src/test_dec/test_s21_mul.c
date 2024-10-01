#include "testes.h"

// START_TEST(invalid_dec_s21_mul_1) {
//   // ссылка на результат - NULL
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
//   int result_value = s21_mul(dec_1, dec_2, NULL);

//   ck_assert_int_eq(result_value, 1);
// }

// START_TEST(invalid_dec_s21_mul_2) {
//   // степень 56 (допустимое значение от 0 до 28)
//   // биты 0-15 не пустые
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_3) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_4) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_5) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_6) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_7) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_8) {
//   // Все биты имеют максимальное значение
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_9) {
//   // степень 56 (допустимое значение от 0 до 28)
//   // биты 0-15 не пустые
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_10) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_11) {
//   // степень 29 (допустимое значение от 0 до 28)
//   s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_12) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_13) {
//   // степень 28
//   // биты 0-15 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_14) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_15) {
//   // степень 28
//   // биты 24-30 не пустые
//   s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

// START_TEST(invalid_dec_s21_mul_16) {
//   // Все биты имеют максимальное значение
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
//   s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
//   s21_decimal result;
//   int result_value = s21_mul(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST

START_TEST(s21_mul_1) {
  // 37570461778924.05759
  s21_decimal dec_1 = {{0xd60411ff, 0x3423b597, 0x0, 0x50000}};
  // 982051015327880.9
  s21_decimal dec_2 = {{0xb3330559, 0x22e3b3, 0x0, 0x10000}};
  // 36896110136329713185667174884
  s21_decimal dec_check = {{0xf35451e4, 0x4dbc631f, 0x7737bf3a, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_2) {
  // 39627993431906.28968296056
  s21_decimal dec_1 = {{0xf341ee78, 0xc868e51d, 0x34727, 0xb0000}};
  // -1945876
  s21_decimal dec_2 = {{0x1db114, 0x0, 0x0, 0x80000000}};
  // -77111161347304083343.120562651
  s21_decimal dec_check = {{0xfefc79db, 0xc807ae7f, 0xf928db90, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_3) {
  // 6072300945865502.1
  s21_decimal dec_1 = {{0x6079cf2d, 0xd7bb41, 0x0, 0x10000}};
  // 865.0
  s21_decimal dec_2 = {{0x21ca, 0x0, 0x0, 0x10000}};
  // 5252540318173659316.50
  s21_decimal dec_check = {{0xd3d24682, 0x795d2f05, 0x1c, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_4) {
  // -498
  s21_decimal dec_1 = {{0x1f2, 0x0, 0x0, 0x80000000}};
  // 38
  s21_decimal dec_2 = {{0x26, 0x0, 0x0, 0x0}};
  // -18924
  s21_decimal dec_check = {{0x49ec, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_5) {
  // -4270144
  s21_decimal dec_1 = {{0x412840, 0x0, 0x0, 0x80000000}};
  // -46324007859062712
  s21_decimal dec_2 = {{0x910307b8, 0xa49370, 0x0, 0x80000000}};
  // 197810184215329485270528
  s21_decimal dec_check = {{0xafaeae00, 0x4fc34491, 0x29e3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_6) {
  // 8444919600
  s21_decimal dec_1 = {{0xf75b3f30, 0x1, 0x0, 0x0}};
  // 27183161
  s21_decimal dec_2 = {{0x19ec839, 0x0, 0x0, 0x0}};
  // 229559609118855600
  s21_decimal dec_check = {{0x8c4e91b0, 0x32f8f3f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_7) {
  // 8501.189862288360
  s21_decimal dec_1 = {{0x81e8ebe8, 0x1e33c9, 0x0, 0xc0000}};
  // 690837757346789891125
  s21_decimal dec_2 = {{0x72ea9c35, 0x734cc017, 0x25, 0x0}};
  // 5872942939242556216384454.1078
  s21_decimal dec_check = {{0xf20cea96, 0xce1a7cb2, 0xbdc3d86a, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_8) {
  // -7197656808152480
  s21_decimal dec_1 = {{0x1143dda0, 0x19923b, 0x0, 0x80000000}};
  // 456628436567
  s21_decimal dec_2 = {{0x512cfe57, 0x6a, 0x0, 0x0}};
  // -3286654775252490402143736160
  s21_decimal dec_check = {{0xeb751160, 0x607e823d, 0xa9ea838, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_9) {
  // -626183921553.309
  s21_decimal dec_1 = {{0xce354f9d, 0x23982, 0x0, 0x80030000}};
  // 3358958591127
  s21_decimal dec_2 = {{0x11889c97, 0x30e, 0x0, 0x0}};
  // -2103325862927082688064889.243
  s21_decimal dec_check = {{0xd65da19b, 0x8063ea01, 0x6cbd493, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_10) {
  // -2169056
  s21_decimal dec_1 = {{0x2118e0, 0x0, 0x0, 0x80000000}};
  // 9170349533060119
  s21_decimal dec_2 = {{0x62625c17, 0x209462, 0x0, 0x0}};
  // -19891001676781249477664
  s21_decimal dec_check = {{0x2da9bc20, 0x4b19bdfd, 0x436, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_11) {
  // -5896
  s21_decimal dec_1 = {{0x1708, 0x0, 0x0, 0x80000000}};
  // 83009161857359
  s21_decimal dec_2 = {{0x139b094f, 0x4b7f, 0x0, 0x0}};
  // -489422018310988664
  s21_decimal dec_check = {{0x8aae6378, 0x6cac6bb, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_12) {
  // -8031926
  s21_decimal dec_1 = {{0x7a8eb6, 0x0, 0x0, 0x80000000}};
  // 667601537542612.60699333
  s21_decimal dec_2 = {{0xf34586c5, 0x133f710b, 0xe23, 0x80000}};
  // -5362126147028486306037.5090536
  s21_decimal dec_check = {{0x9301b568, 0xdff34b0e, 0xad4277c8, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_13) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // -551807
  s21_decimal dec_2 = {{0x86b7f, 0x0, 0x0, 0x80000000}};
  // -2207228
  s21_decimal dec_check = {{0x21adfc, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_14) {
  // -8831769792680922
  s21_decimal dec_1 = {{0xa53b13da, 0x1f6072, 0x0, 0x80000000}};
  // -7981
  s21_decimal dec_2 = {{0x1f2d, 0x0, 0x0, 0x80000000}};
  // 70486354715386438482
  s21_decimal dec_check = {{0x32c9e352, 0xd231d629, 0x3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_15) {
  // -49
  s21_decimal dec_1 = {{0x31, 0x0, 0x0, 0x80000000}};
  // -17323598051760545
  s21_decimal dec_2 = {{0x7c1b59a1, 0x3d8bb8, 0x0, 0x80000000}};
  // 848856304536266705
  s21_decimal dec_check = {{0xc13c27d1, 0xbc7be4f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_16) {
  // -7406573
  s21_decimal dec_1 = {{0x7103ed, 0x0, 0x0, 0x80000000}};
  // 81484828498387
  s21_decimal dec_2 = {{0x2a41d9d3, 0x4a1c, 0x0, 0x0}};
  // -603523330665783697751
  s21_decimal dec_check = {{0xaa72157, 0xb79197a3, 0x20, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_17) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // 471.886207038907864363408929
  s21_decimal dec_2 = {{0x28f59e21, 0x8ab869c7, 0x18655ca, 0x180000}};
  // 1415.658621116723593090226787
  s21_decimal dec_check = {{0x7ae0da63, 0xa0293d55, 0x493015f, 0x180000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_18) {
  // 93461614391
  s21_decimal dec_1 = {{0xc2bf0f37, 0x15, 0x0, 0x0}};
  // 3458616605
  s21_decimal dec_2 = {{0xce264d1d, 0x0, 0x0, 0x0}};
  // 323247891462819562555
  s21_decimal dec_check = {{0xb62443b, 0x85f734a5, 0x11, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_19) {
  // -4361.2984527438
  s21_decimal dec_1 = {{0x70734a4e, 0x27aa, 0x0, 0x800a0000}};
  // -77277.7751121087278
  s21_decimal dec_2 = {{0x31e5cb2e, 0xab97545, 0x0, 0x800d0000}};
  // 337031441.02792313013821583734
  s21_decimal dec_check = {{0xee993176, 0xcabeafc5, 0x6ce6965e, 0x140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_20) {
  // 4601785856.8622
  s21_decimal dec_1 = {{0x5e1d01ae, 0x29da, 0x0, 0x40000}};
  // -5.06
  s21_decimal dec_2 = {{0x1fa, 0x0, 0x0, 0x80020000}};
  // -23285036435.722732
  s21_decimal dec_check = {{0x55551ec, 0x52b99e, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_21) {
  // -8756758.8887595268487145218433
  s21_decimal dec_1 = {{0xc4426181, 0x8ffa737f, 0x1af23639, 0x80160000}};
  // 75.20359
  s21_decimal dec_2 = {{0x72c067, 0x0, 0x0, 0x50000}};
  // -658539705.19912706572471892775
  s21_decimal dec_check = {{2679686657U, 273143600, 3399812993U, 2148859904U}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_22) {
  // -30533899063070815003
  s21_decimal dec_1 = {{0x1df7f31b, 0xa7be336c, 0x1, 0x80000000}};
  // -56.19617
  s21_decimal dec_2 = {{0x55bfa1, 0x0, 0x0, 0x80050000}};
  // 1715888182511168241947.13851
  s21_decimal dec_check = {{0x8f4808fb, 0x79e1f4ae, 0x8def58, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_23) {
  // -84.067
  s21_decimal dec_1 = {{0x14863, 0x0, 0x0, 0x80030000}};
  // -920841907922652793.69861783
  s21_decimal dec_2 = {{0x156f5a97, 0xfc44f4bc, 0x4c2b95, 0x80080000}};
  // 77412416673333652407.861705115
  s21_decimal dec_check = {{0x96f0f99b, 0xbaa46fae, 0xfa220cdc, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_24) {
  // -9821.48378531458604774848
  s21_decimal dec_1 = {{0xe602b5c0, 0x5ecb053b, 0xcffa, 0x80140000}};
  // 28796664
  s21_decimal dec_2 = {{0x1b766f8, 0x0, 0x0, 0x0}};
  // -282825968547.15226871610093507
  s21_decimal dec_check = {{0x4e3a2fc3, 0xabb2cf74, 0x5b62d0d7, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_25) {
  // -2010
  s21_decimal dec_1 = {{0x7da, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 10050
  s21_decimal dec_check = {{0x2742, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_26) {
  // 803743169.02439381157225537263
  s21_decimal dec_1 = {{0xf3459eef, 0xe216b245, 0x3b413a1, 0x140000}};
  // -207035828636594.3014096323627
  s21_decimal dec_2 = {{0xaeb7442b, 0x98564019, 0x6b08f6b, 0x800d0000}};
  // -166403633009967646174785.91666
  s21_decimal dec_check = {{1039121122, 2067208, 1286378900, 2147942400U}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_27) {
  // 601131
  s21_decimal dec_1 = {{0x92c2b, 0x0, 0x0, 0x0}};
  // 6764190487428
  s21_decimal dec_2 = {{0xe92bd384, 0x626, 0x0, 0x0}};
  // 4066164591898081068
  s21_decimal dec_check = {{0x225b372c, 0x386deb27, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_28) {
  // 0.4189452174973
  s21_decimal dec_1 = {{0x6ecf067d, 0x3cf, 0x0, 0xd0000}};
  // 9043050256980711025
  s21_decimal dec_2 = {{0xed571671, 0x7d7f5e4b, 0x0, 0x0}};
  // 3788542656749798637.9794250177
  s21_decimal dec_check = {{0xa85a79c1, 0x80460170, 0x7a6a1721, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_29) {
  // -263747404034587108.522
  s21_decimal dec_1 = {{0x68fe24aa, 0x4c3b0293, 0xe, 0x80030000}};
  // 85570.4397237456915531962566
  s21_decimal dec_2 = {{0xd218c6, 0x53134032, 0x2c3d274, 0x160000}};
  // -22568981339236037388340.692515
  s21_decimal dec_check = {{0xfa4e0623, 0xf0711e5e, 0x48ec9fb1, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_30) {
  // 157948.487693098170252501696
  s21_decimal dec_1 = {{0xad1ba2c0, 0xacc51f58, 0x82a6e4, 0x150000}};
  // -1186853158344
  s21_decimal dec_2 = {{0x55f5fdc8, 0x114, 0x0, 0x80000000}};
  // -187461661474211977.93462906586
  s21_decimal dec_check = {{0x4fb4eeda, 0x23f22d60, 0x3c927717, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_mul_1) {
  // 7355483152551885180022454755
  s21_decimal dec_1 = {{0xb64a79e3, 0xaf11b6d4, 0x17c45024, 0x0}};
  // -994684183040165203.75614091
  s21_decimal dec_2 = {{0xaf9eba8b, 0xc2cd5461, 0x524741, 0x80080000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_2) {
  // -28194429218666802591697373
  s21_decimal dec_1 = {{0x387a09dd, 0x120f214c, 0x175267, 0x80000000}};
  // 10836984902908967
  s21_decimal dec_2 = {{0x2b92fc27, 0x26802e, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_3) {
  // -54388908755895362453538686.648
  s21_decimal dec_1 = {{0x9bd146b8, 0x9ce5ca11, 0xafbd736b, 0x80030000}};
  // -90727334120401624241758
  s21_decimal dec_2 = {{0xcc42165e, 0x56b0f87c, 0x1336, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_4) {
  // 529524602350714130227071427
  s21_decimal dec_1 = {{0xaf8d09c3, 0x3670c729, 0x1b60332, 0x0}};
  // -689501900829468358940669.684
  s21_decimal dec_2 = {{0x62c5b6f4, 0xf0cbcc77, 0x23a57b4, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_5) {
  // -536908988029846638571218930
  s21_decimal dec_1 = {{0xcf36e7f2, 0x8ffc9210, 0x1bc1ee6, 0x80000000}};
  // 585.9376
  s21_decimal dec_2 = {{0x596830, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_6) {
  // -243083720985874103679616626
  s21_decimal dec_1 = {{0xe9348672, 0xeb603d43, 0xc912fa, 0x80000000}};
  // -43843
  s21_decimal dec_2 = {{0xab43, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_7) {
  // 368824101977807699526270
  s21_decimal dec_1 = {{0x6ac7427e, 0xfea02af9, 0x4e19, 0x0}};
  // 3332821560839257
  s21_decimal dec_2 = {{0xfd3bcc59, 0xbd72e, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_8) {
  // -79228162514264337592264949823
  s21_decimal dec_1 = {{0xb3c4003f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 79228162514264337592880670723
  s21_decimal dec_2 = {{0xd8772803, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_9) {
  // -517552547247103501087039365
  s21_decimal dec_1 = {{0xdb85f85, 0xce16d3c0, 0x1ac1c03, 0x80000000}};
  // -322286518689401554745.0
  s21_decimal dec_2 = {{0x2eb6c83a, 0xb63d3c02, 0xae, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_10) {
  // -67370369370587137032184603
  s21_decimal dec_1 = {{0xd285e31b, 0xaa8ba2a, 0x37ba3b, 0x80000000}};
  // -8521043763718291
  s21_decimal dec_2 = {{0x1aa6e893, 0x1e45d8, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *suite_mul(void) {
  Suite *c = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("s21_mul_tc");

  // tcase_add_test(tc, invalid_dec_s21_mul_1);
  // tcase_add_test(tc, invalid_dec_s21_mul_2);
  // tcase_add_test(tc, invalid_dec_s21_mul_3);
  // tcase_add_test(tc, invalid_dec_s21_mul_4);
  // tcase_add_test(tc, invalid_dec_s21_mul_5);
  // tcase_add_test(tc, invalid_dec_s21_mul_6);
  // tcase_add_test(tc, invalid_dec_s21_mul_7);
  // tcase_add_test(tc, invalid_dec_s21_mul_8);
  // tcase_add_test(tc, invalid_dec_s21_mul_9);
  // tcase_add_test(tc, invalid_dec_s21_mul_10);
  // tcase_add_test(tc, invalid_dec_s21_mul_11);
  // tcase_add_test(tc, invalid_dec_s21_mul_12);
  // tcase_add_test(tc, invalid_dec_s21_mul_13);
  // tcase_add_test(tc, invalid_dec_s21_mul_14);
  // tcase_add_test(tc, invalid_dec_s21_mul_15);
  // tcase_add_test(tc, invalid_dec_s21_mul_16);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_29);
  tcase_add_test(tc, s21_mul_30);
  tcase_add_test(tc, fail_s21_mul_1);
  tcase_add_test(tc, fail_s21_mul_2);
  tcase_add_test(tc, fail_s21_mul_3);
  tcase_add_test(tc, fail_s21_mul_4);
  tcase_add_test(tc, fail_s21_mul_5);
  tcase_add_test(tc, fail_s21_mul_6);
  tcase_add_test(tc, fail_s21_mul_7);
  tcase_add_test(tc, fail_s21_mul_8);
  tcase_add_test(tc, fail_s21_mul_9);
  tcase_add_test(tc, fail_s21_mul_10);

  suite_add_tcase(c, tc);
  return c;
}
