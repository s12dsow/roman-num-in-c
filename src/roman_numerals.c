#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>

void add(char *first_val, char *second_val, char *roman_num) {
	int sum = convert_to_arabic_num(first_val) + convert_to_arabic_num(second_val);
    
    convert_to_roman(sum, roman_num);
}

void substract(char *first_val, char *second_val, char *roman_num) {
	int diff = convert_to_arabic_num(first_val) - convert_to_arabic_num(second_val);

	convert_to_roman(diff, roman_num);
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
int roman_converter_len = sizeof(ROMAN_TO_ARABIC_CONVERSION) / sizeof(roman_converter);

int convert_to_arabic_num(char *roman_numeral) {
	int arabic_num = 0;
	int len = strlen(roman_numeral);
	int i;
	int j;

	for (i = 0; i < len; i++) {
		for(j = 0; j < roman_converter_len; j++) {

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

void convert_to_roman(int num, char *roman_val) {
	*roman_val = 0;
	int i;
	for(i = 0; i < roman_converter_len; i++) {
		const roman_converter converter = ROMAN_TO_ARABIC_CONVERSION[i];

		while(num >= converter.num) {
			strcat(roman_val, converter.roman);
			num -= converter.num;
		}
	}
}
