CFLAGS = `pkg-config --cflags --libs check`

all: src/roman_numerals.c
	gcc $(CFLAGS) -c src/roman_numerals.c
test:
	gcc $(CFLAGS) -o rmc_tests src/roman_numerals.c tests/roman_numerals_test.c
run-test: test
	./rmc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rmc_tests