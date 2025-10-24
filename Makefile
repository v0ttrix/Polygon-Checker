CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2
DEBUGFLAGS = -std=c99 -Wall -Wextra -g -DDEBUG
LIBS = -lm
TARGET = polygon_checker
SRCDIR = PolygonChecker
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/triangleSolver.c $(SRCDIR)/rectangleSolver.c

.PHONY: all clean debug run

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o $(TARGET)

debug: $(SOURCES)
	$(CC) $(DEBUGFLAGS) $(SOURCES) $(LIBS) -o $(TARGET)_debug

clean:
	rm -f $(TARGET) $(TARGET)_debug

run: $(TARGET)
	./$(TARGET)
