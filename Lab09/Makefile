# variable definitions
CC     = g++
CFLAGS = -Wall -Wno-deprecated -pedantic -L/usr/local/lib
LIBS   =

# target to build "all"
all: PrintLetterFreqs PrintLetterCodes

# target for main 
PrintLetterFreqs: BST.o PrintLetterFreqs.o
	${CC} -o $@ $^ ${LIBS}

PrintLetterCodes: BST.o PrintLetterCodes.o
	${CC} -o $@ $^ ${LIBS}

# dependencies for the objects
BST.o: BST.cpp BST.h
PrintLetterFreqs.o: PrintLetterFreqs.cpp BST.h
PrintLetterCodes.o: PrintLetterCodes.cpp BST.h

# target to clean up extra files
clean:
	${RM} PrintLetterFreqs PrintLetterCodes *.o

# generic target to compile a .c file to a .o file with the same name
.cpp.o:
	${CC} ${CFLAGS} -c $<
