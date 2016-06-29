#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>

int convert_to_arabic_num(char *roman_num);
void convert_to_roman_num(int num, char *roman_num);

void add(char *first_val, char *second_val, char *roman_num) {
	int first_value = convert_to_arabic_num(first_val);
	int second_value = convert_to_arabic_num(second_val);

	int sum = first_value + second_value;
    
    convert_to_roman_num(sum, roman_num);

	printf("roman num %s\n", roman_num);

    
}

int convert_to_arabic_num(char *roman_num) {
	int arabic_num = 0;
	// printf("%s\n", roman_num);

	if(strcmp(roman_num, "I") == 0) {
		arabic_num += 1;
		// printf("arabic num %i\n", arabic_num);
	}
	return arabic_num;
}

void convert_to_roman_num(int num, char *roman_num) {
	
	*roman_num = 0;


	// printf("%i\n", num);

	if(num % 1 == 0) {
		strcat(roman_num, "I");
		num -= 1;
		// printf("num %i\n", num);
	}
	if(num % 1 == 0) {
		strcat(roman_num, "I");
		num -= 1;
		// printf("num second round %i\n", num);
	}

	// printf("roman num%s\n", roman_num);
}