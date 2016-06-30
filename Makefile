CFLAGS = `pkg-config --cflags --libs check`

all: src/roman_numerals.c
	gcc $(CFLAGS) -c src/roman_numerals.c
test:
	gcc $(CFLAGS) -o rnc_tests src/roman_numerals.c tests/roman_numerals_test.c
run-test: test
	./rnc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -f rnc_tests.dSYM/