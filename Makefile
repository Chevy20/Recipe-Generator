CC=g++
CFLAGS1= -Wall -g -c
CFLAGS2= -g

# Link the two object files together.

test: test.o
	${CC} ${CFLAGS2} -o test test.o

# Compile each source file to an object.

test.o: test.cpp
	${CC} ${CFLAGS1} -o test.o test.cpp
