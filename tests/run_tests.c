#include <stdlib.h>
#include "roman_calculator_test.c"
#include "roman_converter_test.c"

int main(void)
{
    int number_failed;
    Suite *roman_calculator;
    Suite *roman_converter;
    SRunner *sr;

    roman_calculator = roman_calculator_suite();
    roman_converter = roman_converter_suite();

    sr = srunner_create(roman_calculator);
    srunner_add_suite(sr, roman_converter);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
