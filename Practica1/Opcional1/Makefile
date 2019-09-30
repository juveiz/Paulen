CFLAGS = -ggdb -W -pedantic

CC = gcc

LDADD = -lm

LIB = olib.o

CLEANFILES = core core.* *.core generacion.o ej1.o *.a temp.* *.out typescript* \
		*.[234]c *.[234]h *.bsdi *.sparc *.uw opcional_p1

PROGS = ej1

all: $(PROGS)

ej1: ej1.o generacion.o
	$(CC) -o ej1 ej1.o generacion.o $(LDADD)

clean:
	@ rm -fr ${PROGS} ${CLEANFILES}
