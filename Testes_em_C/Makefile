CC=gcc
CFLAGS=-fprofile-arcs -ftest-coverage -Iinclude
LDFLAGS=-lcmocka -lgcov

SRC=$(wildcard src/*.c)
TESTS=$(wildcard tests/test_*.c)
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) -o main $^ $(LDFLAGS)

test: $(TESTS)
	$(CC) -o test $^ $(OBJ) $(LDFLAGS) -Iinclude
	./test

coverage: test
	gcov src/*.c

clean:
	rm -f *.o *.gcda *.gcno main test *.gcov

