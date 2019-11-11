CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c
EJS = ejemplo

all: $(EJS)

ejemplo:
	$(CC) $(CFLAGS) main.c $(LIBS) -o ejemplo

clean:
	rm -rf *.o $(EJS) 
