CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Assignment03.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ass03

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
