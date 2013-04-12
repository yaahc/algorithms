CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=matrixPrinting.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ass208

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
