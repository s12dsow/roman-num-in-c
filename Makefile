CFLAGS = `pkg-config --cflags --libs check`

build: src/roman_calculator.c src/roman_converter.c
	gcc -std=c99 $(CFLAGS) -c src/roman_calculator.c src/roman_converter.c
test:
	gcc -std=c99 -o rnc_tests src/roman_calculator.c src/roman_converter.c tests/roman_calculator_test.c tests/roman_converter_test.c -lcheck $(CFLAGS)
run-test: test
	./rnc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/