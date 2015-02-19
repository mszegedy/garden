CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=./main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=garden

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)
%.o: %.cc
	(cd $(dir $<); $(CC) $(CFLAGS) $(patsubst %.o,%.cc,$(notdir $<)))
clean:
	find . -name *.o -print0 | xargs -0 rm
