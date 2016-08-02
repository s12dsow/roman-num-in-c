CC=gcc
CFLAGS=-std=c99
LDFLAGS=`pkg-config --cflags --libs check`
SRCS=$(wildcard src/*.c) 
TESTS=tests/run_tests.c

build: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
test:
	$(CC) $(CFLAGS) -o rnc_tests $(SRCS) $(TESTS) -lcheck $(LDFLAGS)
run-test: test
	./rnc_tests

.PHONY: clean
clean:
	rm -f *.o
	rm -f rnc_tests
	rm -rf rnc_tests.dSYM/
