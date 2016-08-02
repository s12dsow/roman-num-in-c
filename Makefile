CC=gcc
CFLAGS=`pkg-config --cflags --libs check`
SRCS=$(wildcard src/*.c) 
TESTS=tests/run_tests.c

build: $(SRCS)
	$(CC) -std=c99 $(CFLAGS) -c $(SRCS)
test:
	$(CC) -std=c99 -o rnc_tests $(SRCS) $(TESTS) -lcheck $(CFLAGS)
run-test: test
	./rnc_tests

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.a
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/
