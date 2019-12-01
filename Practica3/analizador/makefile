CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c
EJS = pruebaSintactico

all: $(EJS)

pruebaSintactico:
	$(CC) $(CFLAGS) pruebaSintactico.c $(LIBS) -o pruebaSintactico

clean:
	rm -rf *.o $(EJS)
