#include "roman_validator.h"
#include <regex.h>
#include <stdio.h>

static char valid_pattern[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

int is_valid_numeral(const char *roman_num) {

	if(roman_num && roman_num[0]) {
		regex_t regex_compiled;
		int status;

		regcomp(&regex_compiled, valid_pattern, REG_EXTENDED);

		status = regexec(&regex_compiled, roman_num, (size_t) 0, NULL, 0);

		regfree(&regex_compiled);

		if (status == REG_NOMATCH) {
			return 0;
		}
		return 1;
	}
}