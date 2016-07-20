CFLAGS = `pkg-config --cflags --libs check`

build: src/roman_numerals.c
	gcc -std=c99 $(CFLAGS) -c src/roman_numerals.c
test:
	gcc -std=c99 -o rnc_tests src/roman_numerals.c tests/roman_numerals_test.c -lcheck $(CFLAGS)
run-test: test
	./rnc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/