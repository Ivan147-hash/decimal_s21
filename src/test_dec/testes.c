#include "testes.h"

int main(void) {
  int fail = 0;
  Suite *s[] = {suite_add(),
                suite_sub(),
                suite_div(),
                suite_mul(),
                suite_is_less(),
                suite_is_less_or_equal(),
                suite_is_greater(),
                suite_is_greater_or_equal(),
                suite_is_equal(),
                suite_is_not_equal(),

                negate_suite1(),
                negate_suite0(),

                floor_suite1(),
                floor_suite0(),

                round_suite1(),
                round_suite0(),

                truncate_suite1(),
                truncate_suite0(),

                suite_int_to_decimal(),
                suite_decimal_to_int(),
                suite_from_float_to_decimal(),
                suite_from_decimal_to_float(),
                NULL};
  for (int i = 0; s[i] != NULL; i++) {
    SRunner *runner = srunner_create(s[i]);
    srunner_run_all(runner, CK_NORMAL);
    fail += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  printf("FAIL: %d\n", fail);
  return 0;
}

// int test_decimal_get_sign(s21_decimal value) {
//     test_decimal_bytes decimal_bytes;
//     decimal_bytes.d = value;
//     return decimal_bytes.parts.sign;
// }