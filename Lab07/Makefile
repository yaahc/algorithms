# variable definitions
CC     = g++
CFLAGS =
LIBS   =

# target to build "all"
all: BSTinserting BSTdeleting

# target for building Inserting 
BSTinserting: BST.o BSTinserting.o
	${CC} -o $@ $^ ${LIBS}

# target for building Deleting 
BSTdeleting: BST.o BSTdeleting.o
	${CC} -o $@ $^ ${LIBS}

# dependencies for the objects
BST.o: BST.cpp BST.h
BSTinserting.o: BSTinserting.cpp BST.h
BSTdeleting.o: BSTdeleting.cpp BST.h

# target to clean up extra files
clean:
	${RM} BSTinserting BSTdeleting *.o 

# generic target to compile a .cpp file to a .o file with the same name
.c.o:
	${CC} ${CFLAGS} -c $<
