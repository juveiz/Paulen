CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c
EJS = pruebaSintactico

all: $(EJS)

pruebaSintactico:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) pruebaSintactico.c $(LIBS) -o pruebaSintactico

clean:
	rm -rf *.o $(EJS)
