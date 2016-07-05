#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>

void add(char *first_val, char *second_val, char *roman_num) {
	int sum = convert_to_arabic_num(first_val) + convert_to_arabic_num(second_val);
    
    convert_to_roman_num(sum, roman_num);
}

typedef struct {
	char *roman;
	int num;
} roman_converter;

static const roman_converter ROMAN_TO_ARABIC_CONVERSION[] = {
	{ .roman = "M", .num = 1000 },
	{ .roman = "CM", .num = 900 },
	{ .roman = "D", .num = 500 },
	{ .roman = "CD", .num = 400 },
	{ .roman = "C", .num = 100 },
	{ .roman = "XC", .num = 90 },
	{ .roman = "L", .num = 50 },
	{ .roman = "XL", .num = 40 },
	{ .roman = "X", .num = 10 },
	{ .roman = "IX", .num = 9 },
	{ .roman = "V", .num = 5 },
	{ .roman = "IV", .num = 4 },
	{ .roman = "I", .num = 1 }
};


int convert_to_arabic_num(char *roman_numeral) {
	int arabic_num = 0;
	int len = strlen(roman_numeral);
	int roman_converter_len = sizeof(ROMAN_TO_ARABIC_CONVERSION) / sizeof(roman_converter);

	for (int i = 0; i < len; i++) {
		for(int j = 0; j < roman_converter_len; j++) {

			const roman_converter converter = ROMAN_TO_ARABIC_CONVERSION[j];
			int roman_len = strlen(converter.roman);

			if(strncmp(roman_numeral + i, converter.roman, roman_len) == 0) {

				arabic_num += converter.num;
				i += roman_len - 1;
			}
		}

	}
	return arabic_num;
}

void convert_to_roman_num(int num, char *roman_val) {
	*roman_val = 0;

	while(num >= 1000) {
		strcat(roman_val, "M");
		num -= 1000;
	}

	if(num >= 900) {
		strcat(roman_val, "CM");
		num -= 900;
	}

	if(num >= 500) {
		strcat(roman_val, "D");
		num -= 500;
	}

	if(num >= 400) {
		strcat(roman_val, "CD");
		num -= 400;
	}

	while(num >= 100) {
		strcat(roman_val, "C");
		num -= 100;
	}

	if(num >= 90) {
		strcat(roman_val, "XC");
		num -= 90;
	}

	if(num >= 50) {
		strcat(roman_val, "L");
		num -= 50;
	}

	if(num >= 40) {
		strcat(roman_val, "XL");
		num -= 40;
	}

	while(num >= 10) {
		strcat(roman_val, "X");
		num -= 10;
	}

	if(num >= 9) {
		strcat(roman_val, "IX");
		num -= 9;
	}

	if(num >= 5) {
		strcat(roman_val, "V");
		num -= 5;
	}

	if(num >= 4) {
		strcat(roman_val, "IV");
		num -= 4;
	}

	while(num >= 1) {
		strcat(roman_val, "I");
		num -= 1;
	}
}
