make
./ej1 ej1.asm
nasm -g -o ej1.o -f elf32 ej1.asm
gcc -m32 -o opcional_p1 ej1.o alfalib.o
./opcional_p1
