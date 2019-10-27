CFLAGS = -ggdb -W -pedantic

CC = gcc

LDADD = -lm

LIB = olib.o

CLEANFILES = core core.* *.core generacion.o ej*.o *.a temp.* *.out typescript* \
		*.[234]c *.[234]h *.bsdi *.sparc *.uw *.asm

PROGS = ej1.a ej2.a ej3.a ej4.a ej5.a ej6.a ej7.a

all: $(PROGS)

ej1.a: ej1.o generacion.o
	$(CC) -o ej1.a ej1.o generacion.o $(LDADD)

ej2.a: ej2.o generacion.o
	$(CC) -o ej2.a ej2.o generacion.o $(LDADD)

ej3.a: ej3.o generacion.o
	$(CC) -o ej3.a ej3.o generacion.o $(LDADD)

ej4.a: ej4.o generacion.o
	$(CC) -o ej4.a ej4.o generacion.o $(LDADD)

ej5.a: ej5.o generacion.o
	$(CC) -o ej5.a ej5.o generacion.o $(LDADD)

ej6.a: ej6.o generacion.o
	$(CC) -o ej6.a ej6.o generacion.o $(LDADD)

ej7.a: ej7.o generacion.o
	$(CC) -o ej7.a ej7.o generacion.o $(LDADD)

clean:
	@ rm -fr ${PROGS} ${CLEANFILES}
