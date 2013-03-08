CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=Assignment04.cpp JLSorts.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ass04

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
