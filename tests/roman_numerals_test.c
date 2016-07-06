#include <stdlib.h>
#include <check.h>
#include "../src/roman_numerals.h"

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


START_TEST (test_MD_minus_LXXVIII_returns_DCLXIV)
{
    char roman_num[16];

    substract("MD", "LXXVIII", roman_num);
    ck_assert_str_eq(roman_num, "MCDXXII");
}
END_TEST


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


// Convert to roman

START_TEST (test_convert_1_to_I)
{
    char roman_val[16];

    convert_to_roman(1, roman_val);

    ck_assert_str_eq(roman_val, "I");
}
END_TEST


START_TEST (test_convert_2_to_II)
{
    char roman_val[16];

    convert_to_roman(2, roman_val);

    ck_assert_str_eq(roman_val, "II");
}
END_TEST

START_TEST (test_convert_3_to_III)
{
    char roman_val[16];

    convert_to_roman(3, roman_val);

    ck_assert_str_eq(roman_val, "III");
}
END_TEST

START_TEST (test_convert_4_to_IV)
{
    char roman_val[16];

    convert_to_roman(4, roman_val);

    ck_assert_str_eq(roman_val, "IV");
}
END_TEST


START_TEST (test_convert_5_to_V)
{
    char roman_val[16];

    convert_to_roman(5, roman_val);

    ck_assert_str_eq(roman_val, "V");
}
END_TEST

START_TEST (test_convert_9_to_IX)
{
    char roman_val[16];

    convert_to_roman(9, roman_val);

    ck_assert_str_eq(roman_val, "IX");
}
END_TEST

START_TEST (test_convert_10_to_X)
{
    char roman_val[16];

    convert_to_roman(10, roman_val);

    ck_assert_str_eq(roman_val, "X");
}
END_TEST

START_TEST (test_convert_40_to_XL)
{
    char roman_val[16];

    convert_to_roman(40, roman_val);

    ck_assert_str_eq(roman_val, "XL");
}
END_TEST

START_TEST (test_convert_50_to_L)
{
    char roman_val[16];

    convert_to_roman(50, roman_val);

    ck_assert_str_eq(roman_val, "L");
}
END_TEST

START_TEST (test_convert_90_to_XC)
{
    char roman_val[16];

    convert_to_roman(90, roman_val);

    ck_assert_str_eq(roman_val, "XC");
}
END_TEST

START_TEST (test_convert_100_to_C)
{
    char roman_val[16];

    convert_to_roman(100, roman_val);

    ck_assert_str_eq(roman_val, "C");
}
END_TEST

START_TEST (test_convert_400_to_CD)
{
    char roman_val[16];

    convert_to_roman(400, roman_val);

    ck_assert_str_eq(roman_val, "CD");
}
END_TEST

START_TEST (test_convert_500_to_D)
{
    char roman_val[16];

    convert_to_roman(500, roman_val);

    ck_assert_str_eq(roman_val, "D");
}
END_TEST

START_TEST (test_convert_900_to_CM)
{
    char roman_val[16];

    convert_to_roman(900, roman_val);

    ck_assert_str_eq(roman_val, "CM");
}
END_TEST

START_TEST (test_convert_1000_to_M)
{
    char roman_val[16];

    convert_to_roman(1000, roman_val);

    ck_assert_str_eq(roman_val, "M");
}
END_TEST

Suite* roman_numerals_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_convert_to_arabic;
    TCase *tc_convert_to_roman;

    s = suite_create("Roman Numerals");

    /* Core test case */
    tc_core = tcase_create("Core");
    tc_convert_to_arabic = tcase_create("convert to arabic");
    tc_convert_to_roman = tcase_create("convert to roman");

    tcase_add_test(tc_core, test_I_plus_I_returns_II);
    tcase_add_test(tc_core, test_I_plus_II_returns_III);
    tcase_add_test(tc_core, test_II_plus_II_returns_IV);
    tcase_add_test(tc_core, test_V_plus_IV_returns_IX);
    tcase_add_test(tc_core, test_XCVIII_plus_LXIX_returns_CLXVII);
    tcase_add_test(tc_core, test_DXXX_plus_MDCCC_returns_MMCCCXXX);

    tcase_add_test(tc_core, test_V_minus_I_returns_IV);
    tcase_add_test(tc_core, test_XXIV_minus_XIV_returns_X);
    tcase_add_test(tc_core, test_DCCVII_minus_XLIII_returns_DCLXIV);
    tcase_add_test(tc_core, test_MD_minus_LXXVIII_returns_DCLXIV);


    suite_add_tcase(s, tc_core);

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

    suite_add_tcase(s, tc_convert_to_arabic);
    suite_add_tcase(s, tc_convert_to_roman);


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
