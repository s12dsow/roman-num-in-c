CFLAGS = `pkg-config --cflags --libs check`

build: src/roman_calculator.c src/roman_converter.c
	gcc -std=c99 $(CFLAGS) -c src/roman_calculator.c src/roman_converter.c src/roman_validator.c
test:
	gcc -std=c99 -o rnc_tests src/roman_calculator.c src/roman_converter.c src/roman_validator.c tests/run_tests.c -lcheck $(CFLAGS)
run-test: test
	./rnc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/