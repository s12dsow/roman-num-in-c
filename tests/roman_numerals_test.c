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

START_TEST (test_I_plus_II_returns_III)
{
    char roman_num[16];

    add("I", "II", roman_num);
    ck_assert_str_eq(roman_num, "III");
}
END_TEST


// Test Converter

START_TEST (test_convert_I_to_1)
{
    int num = convert_to_arabic_num("I");
    ck_assert_int_eq(num, 1);
}
END_TEST

START_TEST (test_convert_II_to_2)
{

    int num = convert_to_arabic_num("II");
    ck_assert_int_eq(num, 2);
}
END_TEST

START_TEST (test_convert_IV_to_4)
{

    int num = convert_to_arabic_num("IV");
    ck_assert_int_eq(num, 4);
}
END_TEST


START_TEST (test_convert_V_to_5)
{

    int num = convert_to_arabic_num("V");
    ck_assert_int_eq(num, 5);
}
END_TEST

START_TEST (test_convert_VI_to_6)
{

    int num = convert_to_arabic_num("VI");
    ck_assert_int_eq(num, 6);
}
END_TEST

START_TEST (test_convert_IX_to_9)
{

    int num = convert_to_arabic_num("IX");
    ck_assert_int_eq(num, 9);
}
END_TEST

START_TEST (test_convert_X_to_10)
{

    int num = convert_to_arabic_num("X");
    ck_assert_int_eq(num, 10);
}
END_TEST

START_TEST (test_convert_XL_to_40)
{

    int num = convert_to_arabic_num("XL");
    ck_assert_int_eq(num, 40);
}
END_TEST

START_TEST (test_convert_L_to_50)
{

    int num = convert_to_arabic_num("L");
    ck_assert_int_eq(num, 50);
}
END_TEST

START_TEST (test_convert_XC_to_90)
{

    int num = convert_to_arabic_num("XC");
    ck_assert_int_eq(num, 90);
}
END_TEST

Suite* roman_numerals_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_convert;

    s = suite_create("Roman Numerals");

    /* Core test case */
    tc_core = tcase_create("Core");
    tc_convert = tcase_create("convert");

    tcase_add_test(tc_core, test_I_plus_I_returns_II);
    // tcase_add_test(tc_core, test_I_plus_II_returns_III);
    suite_add_tcase(s, tc_core);

    tcase_add_test(tc_convert, test_convert_I_to_1);
    tcase_add_test(tc_convert, test_convert_II_to_2);
    tcase_add_test(tc_convert, test_convert_IV_to_4);
    tcase_add_test(tc_convert, test_convert_V_to_5);
    tcase_add_test(tc_convert, test_convert_VI_to_6);
    tcase_add_test(tc_convert, test_convert_IX_to_9);
    tcase_add_test(tc_convert, test_convert_X_to_10);
    tcase_add_test(tc_convert, test_convert_XL_to_40);
    tcase_add_test(tc_convert, test_convert_L_to_50);
    tcase_add_test(tc_convert, test_convert_XC_to_90);







    suite_add_tcase(s, tc_convert);

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
