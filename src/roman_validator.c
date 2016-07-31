#include "roman_validator.h"
#include <regex.h>
#include <stdio.h>

char valid_pattern[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

int is_valid_numeral(char *roman_num) {
	regex_t regex_compiled;
	int status;

	regcomp(&regex_compiled, valid_pattern, REG_EXTENDED);

	// nmatch value is number of substrings in string that the regex function should try to match with subexpressions in roman num
	status = regexec(&regex_compiled, roman_num, (size_t) 0, NULL, 0);

	regfree(&regex_compiled);

	return (status != REG_NOMATCH);
}