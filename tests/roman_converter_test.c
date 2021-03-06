#include <check.h>
#include "../src/roman_converter.h"
#include "roman_converter_test.h"


// Test Convert to Arabic

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
    int num = convert_to_arabic_num("XCVIII");
    ck_assert_int_eq(num, 98);
}
END_TEST

START_TEST (test_convert_C_to_100)
{
    int num = convert_to_arabic_num("C");
    ck_assert_int_eq(num, 100);
}
END_TEST

START_TEST (test_convert_CD_to_400)
{
    int num = convert_to_arabic_num("CD");
    ck_assert_int_eq(num, 400);
}
END_TEST

START_TEST (test_convert_CD_to_500)
{
    int num = convert_to_arabic_num("D");
    ck_assert_int_eq(num, 500);
}
END_TEST

START_TEST (test_convert_CM_to_900)
{
    int num = convert_to_arabic_num("CM");
    ck_assert_int_eq(num, 900);
}
END_TEST


START_TEST (test_convert_M_to_1000)
{
    int num = convert_to_arabic_num("M");
    ck_assert_int_eq(num, 1000);
}
END_TEST


// Convert to Roman

START_TEST (test_convert_1_to_I)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(1, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "I");
}
END_TEST


START_TEST (test_convert_2_to_II)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(2, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "II");
}
END_TEST

START_TEST (test_convert_3_to_III)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(3, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "III");
}
END_TEST

START_TEST (test_convert_4_to_IV)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(4, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "IV");
}
END_TEST


START_TEST (test_convert_5_to_V)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(5, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "V");
}
END_TEST

START_TEST (test_convert_9_to_IX)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(9, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "IX");
}
END_TEST

START_TEST (test_convert_10_to_X)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(10, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "X");
}
END_TEST

START_TEST (test_convert_40_to_XL)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(40, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "XL");
}
END_TEST

START_TEST (test_convert_50_to_L)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(50, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "L");
}
END_TEST

START_TEST (test_convert_90_to_XC)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(90, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "XC");
}
END_TEST

START_TEST (test_convert_100_to_C)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(100, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "C");
}
END_TEST

START_TEST (test_convert_400_to_CD)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(400, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "CD");
}
END_TEST

START_TEST (test_convert_500_to_D)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(500, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "D");
}
END_TEST

START_TEST (test_convert_900_to_CM)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(900, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "CM");
}
END_TEST

START_TEST (test_convert_1000_to_M)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(1000, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "M");
}
END_TEST

// Invalid

START_TEST (test_convert_4000_is_invalid)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(4000, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "");
}
END_TEST

START_TEST (test_convert_negative_values_is_invalid)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(-20, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "");
}
END_TEST

START_TEST (test_convert_zero_is_invalid)
{
    const int buffer_len = 16;
    char roman_val[buffer_len];

    convert_to_roman(0, roman_val, buffer_len);

    ck_assert_str_eq(roman_val, "");
}
END_TEST

Suite* roman_converter_suite(void)
{
    Suite *s;
    TCase *tc_convert_to_arabic;
    TCase *tc_convert_to_roman;
    TCase *tc_invalid;

    s = suite_create("Roman Numerals Converter");

    tc_convert_to_arabic = tcase_create("Convert to Arabic");
    tc_convert_to_roman = tcase_create("Convert to Roman");
    tc_invalid = tcase_create("Invalid");

    // Convert to arabic test case
    tcase_add_test(tc_convert_to_arabic, test_convert_I_to_1);
    tcase_add_test(tc_convert_to_arabic, test_convert_II_to_2);
    tcase_add_test(tc_convert_to_arabic, test_convert_IV_to_4);
    tcase_add_test(tc_convert_to_arabic, test_convert_V_to_5);
    tcase_add_test(tc_convert_to_arabic, test_convert_VI_to_6);
    tcase_add_test(tc_convert_to_arabic, test_convert_IX_to_9);
    tcase_add_test(tc_convert_to_arabic, test_convert_X_to_10);
    tcase_add_test(tc_convert_to_arabic, test_convert_XL_to_40);
    tcase_add_test(tc_convert_to_arabic, test_convert_L_to_50);
    tcase_add_test(tc_convert_to_arabic, test_convert_XC_to_90);
    tcase_add_test(tc_convert_to_arabic, test_convert_C_to_100);
    tcase_add_test(tc_convert_to_arabic, test_convert_CD_to_400);
    tcase_add_test(tc_convert_to_arabic, test_convert_CD_to_500);
    tcase_add_test(tc_convert_to_arabic, test_convert_CM_to_900);
    tcase_add_test(tc_convert_to_arabic, test_convert_M_to_1000);


    // Convert to roman test case
    tcase_add_test(tc_convert_to_roman, test_convert_1_to_I);
    tcase_add_test(tc_convert_to_roman, test_convert_2_to_II);
    tcase_add_test(tc_convert_to_roman, test_convert_3_to_III);
    tcase_add_test(tc_convert_to_roman, test_convert_4_to_IV);
    tcase_add_test(tc_convert_to_roman, test_convert_5_to_V);
    tcase_add_test(tc_convert_to_roman, test_convert_9_to_IX);
    tcase_add_test(tc_convert_to_roman, test_convert_10_to_X);
    tcase_add_test(tc_convert_to_roman, test_convert_40_to_XL);
    tcase_add_test(tc_convert_to_roman, test_convert_50_to_L);
    tcase_add_test(tc_convert_to_roman, test_convert_90_to_XC);
    tcase_add_test(tc_convert_to_roman, test_convert_100_to_C);
    tcase_add_test(tc_convert_to_roman, test_convert_400_to_CD);
    tcase_add_test(tc_convert_to_roman, test_convert_500_to_D);
    tcase_add_test(tc_convert_to_roman, test_convert_900_to_CM);
    tcase_add_test(tc_convert_to_roman, test_convert_1000_to_M);

    // Test invalid
    tcase_add_test(tc_convert_to_roman, test_convert_4000_is_invalid);
    tcase_add_test(tc_convert_to_roman, test_convert_negative_values_is_invalid);
    tcase_add_test(tc_convert_to_roman, test_convert_zero_is_invalid);

    suite_add_tcase(s, tc_convert_to_roman);
    suite_add_tcase(s, tc_convert_to_arabic);
    suite_add_tcase(s, tc_invalid);

    return s;
}
