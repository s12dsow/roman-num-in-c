#include "roman_converter.h"
#include "roman_calculator.h"

void add(char *first_roman_string_input, char *second_roman_string_input, char *roman_num) {
	int sum = convert_to_arabic_num(first_roman_string_input) + convert_to_arabic_num(second_roman_string_input);
    
    convert_to_roman(sum, roman_num);
}

void substract(char *first_roman_string_input, char *second_roman_string_input, char *roman_num) {
	int diff = convert_to_arabic_num(first_roman_string_input) - convert_to_arabic_num(second_roman_string_input);

	convert_to_roman(diff, roman_num);
}