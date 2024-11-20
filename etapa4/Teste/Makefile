CC = gcc
CFLAGS = -g

all: main

main: main.o symbol_table.o
	$(CC) $(CFLAGS) -o main main.o symbol_table.o

main.o: main.c symbol_table.h
	$(CC) $(CFLAGS) -c main.c

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(CFLAGS) -c symbol_table.c

clean:
	rm -f *.o main
