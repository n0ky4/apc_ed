CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

all: programa

programa: matriz.o main.o
	$(CC) matriz.o main.o $(LDFLAGS) -o out

matriz.o: matriz.c matriz.h
	$(CC) $(CFLAGS) -c matriz.c

main.o: main.c matriz.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o out
