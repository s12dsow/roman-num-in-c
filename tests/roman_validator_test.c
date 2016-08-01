#include <check.h>
#include "../src/roman_validator.h"

START_TEST (test_convert_A_is_invalid)
{
    int num = is_valid_numeral("A");
    ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST (test_convert_IIII_is_invalid)
{
    int num = is_valid_numeral("IIII");
    ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST (test_convert_MMDDCC_is_invalid)
{
    int num = is_valid_numeral("MMDDCC");
    ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST (test_convert_IIZJID_is_invalid)
{
    int num = is_valid_numeral("IIZJID");
    ck_assert_int_eq(num, 0);
}
END_TEST
	
Suite* roman_validator_suite(void)
{
	Suite *s;
	TCase *tc_roman_validator;

	s = suite_create("Roman Numerals Validator");

	tc_roman_validator = tcase_create("Roman Validator");

	tcase_add_test(tc_roman_validator, test_convert_A_is_invalid);
	tcase_add_test(tc_roman_validator, test_convert_IIII_is_invalid);
	tcase_add_test(tc_roman_validator, test_convert_MMDDCC_is_invalid);
	tcase_add_test(tc_roman_validator, test_convert_IIZJID_is_invalid);

	suite_add_tcase(s, tc_roman_validator);

	return s;
}