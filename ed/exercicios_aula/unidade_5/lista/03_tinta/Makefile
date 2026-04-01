CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

all: programa

programa: tinta.o main.o
	$(CC) tinta.o main.o $(LDFLAGS) -o out

tinta.o: tinta.c tinta.h
	$(CC) $(CFLAGS) -c tinta.c

main.o: main.c tinta.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o out
