#include <check.h>
#include "../src/roman_calculator.h"
#include "roman_calculator_test.h"


// Test Add
START_TEST (test_I_plus_I_returns_II)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("I", "I", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "II");
}
END_TEST

START_TEST (test_I_plus_II_returns_III)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("I", "II", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "III");
}
END_TEST

START_TEST (test_II_plus_II_returns_IV)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("II", "II", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "IV");
}
END_TEST

START_TEST (test_V_plus_IV_returns_IX)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("V", "IV", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "IX");
}
END_TEST

START_TEST (test_XCVIII_plus_LXIX_returns_CLXVII)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("XCVIII", "LXIX", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "CLXVII");
}
END_TEST

START_TEST (test_DXXX_plus_MDCCC_returns_MMCCCXXX)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("DXXX", "MDCCC", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "MMCCCXXX");
}
END_TEST

// Test Substract

START_TEST (test_V_minus_I_returns_IV)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("V", "I", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "IV");
}
END_TEST


START_TEST (test_XXIV_minus_XIV_returns_X)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("XXIV", "XIV", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "X");
}
END_TEST

START_TEST (test_DCCVII_minus_XLIII_returns_DCLXIV)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("DCCVII", "XLIII", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "DCLXIV");
}
END_TEST


START_TEST (test_MD_minus_LXXVIII_returns_MCDXXII)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("MD", "LXXVIII", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "MCDXXII");
}
END_TEST

START_TEST (test_MDCCC_minus_DXXX_returns_MCCLXX)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("MDCCC", "DXXX", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "MCCLXX");
}
END_TEST

// Test invalid

START_TEST (test_XXXXXX_plus_ZZZZZ_returns_empty_string)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("XXXXXX", "ZZZZZ", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

START_TEST (test_IIIX_minus_MDXMD_returns_empty_string)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("IIIX", "MDXMD", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

START_TEST (test_roman_num_does_not_blow_up_on_NULL_input)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add(NULL, NULL, roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

START_TEST (test_roman_num_as_NULL_does_not_blow_up_in_add)
{
    int buffer_len = 16;

    add("II", "IV", NULL, buffer_len);
}
END_TEST

START_TEST (test_roman_num_as_NULL_does_not_blow_up_in_subtract)
{
    int buffer_len = 16;

    substract("II", "IV", NULL, buffer_len);
}
END_TEST

START_TEST (test_MMM_plus_MMM_returns_invalid)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    add("MMM", "MMM", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

START_TEST (test_I_minus_IV_returns_invalid)
{
    int buffer_len = 16;
    char roman_num[buffer_len];

    substract("I", "IV", roman_num, buffer_len);
    ck_assert_str_eq(roman_num, "");
}
END_TEST

Suite* roman_calculator_suite(void)
{
    Suite *s;
    TCase *tc_calculator;
    TCase *tc_invalid;

    s = suite_create("Roman Calculator");

    tc_calculator = tcase_create("Calculator");
    tc_invalid = tcase_create("Invalid");

    // Test Add
    tcase_add_test(tc_calculator, test_I_plus_I_returns_II);
    tcase_add_test(tc_calculator, test_I_plus_II_returns_III);
    tcase_add_test(tc_calculator, test_II_plus_II_returns_IV);
    tcase_add_test(tc_calculator, test_V_plus_IV_returns_IX);
    tcase_add_test(tc_calculator, test_XCVIII_plus_LXIX_returns_CLXVII);
    tcase_add_test(tc_calculator, test_DXXX_plus_MDCCC_returns_MMCCCXXX);

    // Test Substract
    tcase_add_test(tc_calculator, test_V_minus_I_returns_IV);
    tcase_add_test(tc_calculator, test_XXIV_minus_XIV_returns_X);
    tcase_add_test(tc_calculator, test_DCCVII_minus_XLIII_returns_DCLXIV);
    tcase_add_test(tc_calculator, test_MD_minus_LXXVIII_returns_MCDXXII);
    tcase_add_test(tc_calculator, test_MDCCC_minus_DXXX_returns_MCCLXX);

    // Test Invalid
    tcase_add_test(tc_invalid, test_XXXXXX_plus_ZZZZZ_returns_empty_string);
    tcase_add_test(tc_invalid, test_IIIX_minus_MDXMD_returns_empty_string);
    tcase_add_test(tc_invalid, test_roman_num_does_not_blow_up_on_NULL_input);
    tcase_add_test(tc_invalid, test_roman_num_as_NULL_does_not_blow_up_in_add);
    tcase_add_test(tc_invalid, test_roman_num_as_NULL_does_not_blow_up_in_subtract);
    tcase_add_test(tc_invalid, test_MMM_plus_MMM_returns_invalid);
    tcase_add_test(tc_invalid, test_I_minus_IV_returns_invalid);

    suite_add_tcase(s, tc_calculator);
    suite_add_tcase(s, tc_invalid);


    return s;
}

