CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=matrixChaining.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ass08

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
