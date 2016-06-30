#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>

void add(char *first_val, char *second_val, char *roman_num) {
	int first_value = convert_to_arabic_num(first_val);
	int second_value = convert_to_arabic_num(second_val);

	int sum = first_value + second_value;
    
    convert_to_roman_num(sum, roman_num);

	printf("roman num %s\n", roman_num);
    
}

int convert_to_arabic_num(char *val) {
	int arabic_num = 0;
	int len = strlen(val);

	for (int i = 0; i < len; i++) {

		if(strncmp(val + i, "D", 1) == 0) {
			arabic_num += 500;
		}

		else if(strncmp(val + i, "CD", 2) == 0) {
			arabic_num += 400;
			i += 1;
		}

		else if(strncmp(val + i, "C", 1) == 0) {
			arabic_num += 100;
		}

		else if(strncmp(val + i, "XC", 2) == 0) {
			arabic_num += 90;
			i += 1;
		}

		else if(strncmp(val + i, "L", 1) == 0) {
			arabic_num += 50;
		}

		else if(strncmp(val + i, "XL", 2) == 0) {
			arabic_num += 40;
			i += 1;
		}

		else if(strncmp(val + i, "X", 1) == 0) {
			arabic_num += 10;
		}

		else if(strncmp(val + i, "IX", 2) == 0) {
			arabic_num += 9;
			i += 1;
		}
		else if(strncmp(val + i, "V", 1) == 0) {

			arabic_num += 5;
		}

		else if(strncmp(val + i, "IV", 2) == 0) {

			arabic_num += 4;
			i += 1;
		}

		else if(strncmp(val + i, "I", 1) == 0) {

			arabic_num += 1;
		}
	} 
	return arabic_num;
}

void convert_to_roman_num(int num, char *roman_num) {

	int value = num;
	
	*roman_num = 0;

	if(value % 1 == 0) {
		strcat(roman_num, "I");
		value -= 1;
	}
	if(value % 1 == 0) {
		strcat(roman_num, "I");
		value -= 1;
	}
}
