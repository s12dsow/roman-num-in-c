#include <stdlib.h>
#include <check.h>
#include "../src/roman_numerals.h"

START_TEST (test_I_plus_I_returns_II)
{
    char roman_num[16];

    add("I", "I", roman_num);
    ck_assert_str_eq(roman_num, "II");
}
END_TEST


Suite* roman_numerals_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_I_plus_I_returns_II);
    suite_add_tcase(s, tc_core);

    return s;

}

 int main(void)
 {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numerals_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
