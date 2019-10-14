make clean
make
./ej2 ej2.asm
nasm -g -o ej2.o -f elf32 ej2.asm
gcc -m32 -o opcional_p2 ej2.o alfalib.o
./opcional_p2
