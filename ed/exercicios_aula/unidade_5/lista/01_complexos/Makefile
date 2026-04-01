CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

all: programa

programa: complexos.o main.o
	$(CC) complexos.o main.o $(LDFLAGS) -o out

complexos.o: complexos.c complexos.h
	$(CC) $(CFLAGS) -c complexos.c

main.o: main.c complexos.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o out
