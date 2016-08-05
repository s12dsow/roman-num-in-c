#include <check.h>
#include "../src/roman_calculator.h"

// Test Add
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

START_TEST (test_II_plus_II_returns_IV)
{
    char roman_num[16];

    add("II", "II", roman_num);
    ck_assert_str_eq(roman_num, "IV");
}
END_TEST

START_TEST (test_V_plus_IV_returns_IX)
{
    char roman_num[16];

    add("V", "IV", roman_num);
    ck_assert_str_eq(roman_num, "IX");
}
END_TEST

START_TEST (test_XCVIII_plus_LXIX_returns_CLXVII)
{
    char roman_num[16];

    add("XCVIII", "LXIX", roman_num);
    ck_assert_str_eq(roman_num, "CLXVII");
}
END_TEST

START_TEST (test_DXXX_plus_MDCCC_returns_MMCCCXXX)
{
    char roman_num[16];

    add("DXXX", "MDCCC", roman_num);
    ck_assert_str_eq(roman_num, "MMCCCXXX");
}
END_TEST

// Test Substract

START_TEST (test_V_minus_I_returns_IV)
{
    char roman_num[16];

    substract("V", "I", roman_num);
    ck_assert_str_eq(roman_num, "IV");
}
END_TEST


START_TEST (test_XXIV_minus_XIV_returns_X)
{
    char roman_num[16];

    substract("XXIV", "XIV", roman_num);
    ck_assert_str_eq(roman_num, "X");
}
END_TEST

START_TEST (test_DCCVII_minus_XLIII_returns_DCLXIV)
{
    char roman_num[16];

    substract("DCCVII", "XLIII", roman_num);
    ck_assert_str_eq(roman_num, "DCLXIV");
}
END_TEST


START_TEST (test_MD_minus_LXXVIII_returns_MCDXXII)
{
    char roman_num[16];

    substract("MD", "LXXVIII", roman_num);
    ck_assert_str_eq(roman_num, "MCDXXII");
}
END_TEST

START_TEST (test_MDCCC_minus_DXXX_returns_MCCLXX)
{
    char roman_num[16];

    substract("MDCCC", "DXXX", roman_num);
    ck_assert_str_eq(roman_num, "MCCLXX");
}
END_TEST

START_TEST (test_XXXXXX_plus_ZZZZZ_returns_empty_string)
{
    char roman_num[16];

    add("XXXXXX", "ZZZZZ", roman_num);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

START_TEST (test_IIIX_minus_MDXMD_returns_empty_string)
{
    char roman_num[16];

    add("IIIX", "MDXMD", roman_num);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

Suite* roman_calculator_suite(void)
{
    Suite *s;
    TCase *tc_calculator;
    TCase *tc_invalid;

    s = suite_create("Roman Calculator");

    /* Core test case */
    tc_calculator = tcase_create("Calculator");
    tc_invalid = tcase_create("Invalid");

    tcase_add_test(tc_calculator, test_I_plus_I_returns_II);
    tcase_add_test(tc_calculator, test_I_plus_II_returns_III);
    tcase_add_test(tc_calculator, test_II_plus_II_returns_IV);
    tcase_add_test(tc_calculator, test_V_plus_IV_returns_IX);
    tcase_add_test(tc_calculator, test_XCVIII_plus_LXIX_returns_CLXVII);
    tcase_add_test(tc_calculator, test_DXXX_plus_MDCCC_returns_MMCCCXXX);

    tcase_add_test(tc_calculator, test_V_minus_I_returns_IV);
    tcase_add_test(tc_calculator, test_XXIV_minus_XIV_returns_X);
    tcase_add_test(tc_calculator, test_DCCVII_minus_XLIII_returns_DCLXIV);
    tcase_add_test(tc_calculator, test_MD_minus_LXXVIII_returns_MCDXXII);
    tcase_add_test(tc_calculator, test_MDCCC_minus_DXXX_returns_MCCLXX);

    tcase_add_test(tc_invalid, test_XXXXXX_plus_ZZZZZ_returns_empty_string);
    tcase_add_test(tc_invalid, test_IIIX_minus_MDXMD_returns_empty_string);

    suite_add_tcase(s, tc_calculator);
    suite_add_tcase(s, tc_invalid);


    return s;
}

