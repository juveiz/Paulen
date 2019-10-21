CFLAGS = -ggdb -W -pedantic

CC = gcc

LDADD = -lm

LIB = olib.o

CLEANFILES = core core.* *.core generacion.o ej3.o *.a temp.* *.out typescript* \
		*.[234]c *.[234]h *.bsdi *.sparc *.uw opcional_p3 *.asm

PROGS = ej3

all: $(PROGS)

ej3: ej3.o generacion.o
	$(CC) -o ej3 ej3.o generacion.o $(LDADD)

clean:
	@ rm -fr ${PROGS} ${CLEANFILES}
