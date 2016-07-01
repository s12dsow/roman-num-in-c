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

		if(strncmp(val + i, "M", 1) == 0) {
			arabic_num += 1000;
		}

		if(strncmp(val + i, "CM", 2) == 0) {
			arabic_num += 900;
			i += 1;
		}

		else if(strncmp(val + i, "D", 1) == 0) {
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

void convert_to_roman_num(int num, char *roman_val) {
	*roman_val = 0;

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
