CC = gcc
CFLAGS = -Wall

OBJ = *.c *.h

build :
	$(CC) $(CFLAGS) -o p3 $(OBJ)

test : build
	./p3 < tests/test1.in > /tmp/test1.out
	diff /tmp/test1.out tests/test1.out
	rm /tmp/test1.out
