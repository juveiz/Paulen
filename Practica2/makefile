CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c
EJS = pruebaMorfo

all: $(EJS)

pruebaMorfo:
	$(CC) $(CFLAGS) main.c $(LIBS) -o pruebaMorfo

clean:
	rm -rf *.o $(EJS)
