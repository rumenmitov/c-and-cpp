CC = gcc
CFLAGS = -Wall

OBJ = ./src/*.c ./src/*.h

build : 
	$(CC) $(CFLAGS) -o p4 $(OBJ)

test : build
	./p4 < tests/test1.in > /tmp/test1.out
	diff --side-by-side /tmp/test1.out tests/test1.out
	rm /tmp/test1.out
