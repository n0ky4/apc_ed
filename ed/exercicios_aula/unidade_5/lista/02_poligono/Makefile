CC = gcc

CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -g -fsanitize=address
LDFLAGS = -lm -fsanitize=address

all: programa

programa: poligono.o main.o
	$(CC) poligono.o main.o $(LDFLAGS) -o out

poligono.o: poligono.c poligono.h
	$(CC) $(CFLAGS) -c poligono.c

main.o: main.c poligono.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o out
