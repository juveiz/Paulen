CFLAGS = -ggdb -W -pedantic 

CC = gcc

LDADD = -lm 

LIB = olib.o

CLEANFILES = core core.* *.core generacion.o ej2.o *.a temp.* *.out typescript* \
		*.[234]c *.[234]h *.bsdi *.sparc *.uw opcional_p2 *.asm

PROGS = ej2

all: $(PROGS)

ej2: ej2.o generacion.o
	$(CC) -o ej2 ej2.o generacion.o $(LDADD)

clean:
	@ rm -fr ${PROGS} ${CLEANFILES}
