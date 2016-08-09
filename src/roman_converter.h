#ifndef ROMAN_CONVERTER_H
#define ROMAN_CONVERTER_H

int convert_to_arabic_num(const char *roman_numeral);
void convert_to_roman(int arabic_num, char *roman_val, const int buffer_len);

#endif
