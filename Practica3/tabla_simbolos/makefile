CC = gcc
CFLAGS = -g -Wall
LIBS = tablasimbolos.c uthash.h
EJS = main_simbolos

all: $(EJS)

main_simbolos:
	$(CC) $(CFLAGS) main.c $(LIBS) -o main_simbolos

clean:
	rm -rf *.o $(EJS)