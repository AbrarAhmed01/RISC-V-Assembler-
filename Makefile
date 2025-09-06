CC=gcc
CFLAGS=-Wall -std=c99 -g

all: project

project: main.o assembler.o loadmem.o simulator.o
	$(CC) -o project main.o assembler.o loadmem.o simulator.o

assembler.o: assembler.c assembler.h
	$(CC) $(CFLAGS) -c assembler.c

loadmem.o: loadmem.c loadmem.h
	$(CC) $(CFLAGS) -c loadmem.c

simulator.o: simulator.c simulator.h
	$(CC) $(CFLAGS) -c simulator.c

main.o: main.c assembler.h loadmem.h simulator.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm project main.o assembler.o loadmem.o simulator.o