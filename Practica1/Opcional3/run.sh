make clean
make
./ej3 ej3.asm
nasm -g -o ej3.o -f elf32 ej3.asm
gcc -m32 -o opcional_p3 ej3.o alfalib.o
./opcional_p3
