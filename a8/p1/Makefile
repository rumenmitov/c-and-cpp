CC = gcc
CFLAGS = -Wall

OBJ = *.c *.h

build :
	$(CC) $(CFLAGS) -o p1 $(OBJ)

test : build
	./p1 < tests/test1.in > /tmp/test1.out
	diff /tmp/test1.out tests/test1.out
	rm /tmp/test1.out
	./p1 < tests/test2.in > /tmp/test2.out
	diff /tmp/test2.out tests/test2.out
	rm /tmp/test2.out

