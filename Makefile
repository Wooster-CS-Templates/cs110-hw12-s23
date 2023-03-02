CFLAGS=-std=c99 -Wall
CC=gcc

reverse: reverse.o main.o
	$(CC) $(CFLAGS) reverse.o main.o -o reverse

test: test.o reverse.o
	$(CC) $(CFLAGS) reverse.o test.o -o test

main.o: main.c reverse.h
	$(CC) $(CFLAGS) -c main.c

reverse.o: reverse.h reverse.c
	$(CC) $(CFLAGS) -c reverse.c

test.o: reverse.h tests/test.c
	$(CC) $(CFLAGS) -c tests/test.c

gh-test-reverse: clean test
	./test

clean:
	rm -f test reverse *.o
