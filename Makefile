CC=gcc
CFLAGS=`pkg-config --cflags --libs check`
SRCS=src/roman_calculator.c src/roman_converter.c src/roman_validator.c

build: $(SRCS)
	$(CC) -std=c99 $(CFLAGS) -c $(SRCS)
test:
	$(CC) -std=c99 -o rnc_tests $(SRCS) tests/run_tests.c -lcheck $(CFLAGS)
run-test: test
	./rnc_tests
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/