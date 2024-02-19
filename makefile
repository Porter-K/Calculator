#use gcc to make
CC=gcc
#CFLAGS
CFLAGS= -c -Wall

all: prog

prog: calculator.o parse.o solve.o 
	$(CC) calculator.o parse.o solve.o -o calculator

calculator.o: calculator.c 
	$(CC) $(CFLAGS) calculator.c parse.h solve.h parse.c solve.c

parse.o: parse.c 
	$(CC) $(CFLAGS) parse.c

solve.o:
	$(CC) $(CFLAGS) solve.c parse.h

clean:
	rm -rf calculator.o parse.h.gch parse.o solve.h.gch solve.o