CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
NAME=COMP8005A1.out
BUILDDIR=/bin
VPATH=src
SRC=src/

project: process.o thread.o main.o
	$(CC) $(CFLAGS) main.o process.o thread.o -o $(NAME)

clean:
	rm -f *.o *.bak *.out ex

process.o: process.c process.h
	$(CC) $(CFLAGS) -O -c process.c

thread.o: thread.c thread.h
	$(CC) $(CFLAGS) -O -c thread.c

main.o: main.c
	$(CC) $(CFLAGS) -O -c main.c
