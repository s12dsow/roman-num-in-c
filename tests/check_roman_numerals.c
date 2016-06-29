#include "../src/roman_numerals.h"

#test sum2test
    char roman_num[16];
    add("I", "I", roman_num);
	// fail_unless(roman_num == "II", "wrong");
	ck_assert_str_eq(roman_num, "II");
	// fail_unless(add("I", "II") == "III", "wrong");