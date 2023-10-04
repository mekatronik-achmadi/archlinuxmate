EXECUTABLE=gtkwav2c

CC=gcc
INCDIR=-I./

OPT=-O0
WARN=-Wall

PTHREAD=-pthread
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

CFLAGS=$(OPT) $(WARN) $(PTHREAD) $(GTKLIB) -pipe
LDFLAGS=$(OPT) $(WARN) $(PTHREAD) $(GTKLIB) -export-dynamic

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm -f wavarray.c wavarray.m

.PHONY: all clean
