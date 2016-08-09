CC=gcc
CFLAGS=-std=c99
LDFLAGS=`pkg-config --cflags --libs check`
objects=$(patsubst %.c,%.o,$(wildcard src/*.c))
tests=$(patsubst %.c,%.o,$(wildcard tests/*.c))

build: $(objects) $(tests)
	$(CC) $(CFLAGS) -o rnc_tests $(objects) $(tests) -lcheck $(LDFLAGS)

test: build
	./rnc_tests

.PHONY: clean
clean:
	rm -f src/*.o tests/*.o
	rm -f rnc_tests
