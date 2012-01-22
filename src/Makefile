CC=gcc
CFLAGS=-W -Wall -pedantic
PFLAG=-lpthread -pthread
NAME=COMP8005A1.out
BUILDDIR=/bin
VPATH=src
SRC=src/

project: prime.o process.o thread.o main.o
	$(CC) $(CFLAGS) $(PFLAG) main.o process.o thread.o prime.o -o $(NAME)

clean:
	rm -f *.o *.bak *.out ex

prime.o: prime.c prime.h
	$(CC) $(CFLAGS) -O -c prime.c

process.o: process.c process.h
	$(CC) $(CFLAGS) -O -c process.c

thread.o: thread.c thread.h
	$(CC) $(CFLAGS) -O -c thread.c

main.o: main.c
	$(CC) $(CFLAGS) -O -c main.c
