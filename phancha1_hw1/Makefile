CC = cc
CFLAGS = -std=c99 -pedantic -Wall
OBJECTS = hw1.o

all: hw1

hw1.o: hw1.c
	$(CC) $(CFLAGS) -c hw1.c

hw1: $(OBJECTS)
	$(CC) $(OBJECTS) -o hw1

clean:
	rm -f *.o hw1
