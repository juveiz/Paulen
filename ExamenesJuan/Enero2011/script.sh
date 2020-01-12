make clean
make

./alfa ./ejemplos/ej1.alf ./ejemplos/ej1.asm
nasm -felf32 ./ejemplos/ej1.asm
gcc -m32 -o ./ejemplos/ej1 ./ejemplos/ej1.o alfalib.o

./alfa ./ejemplos/ej2.alf ./ejemplos/ej2.asm
nasm -felf32 ./ejemplos/ej2.asm
gcc -m32 -o ./ejemplos/ej2 ./ejemplos/ej2.o alfalib.o

./alfa ./ejemplos/ej3.alf ./ejemplos/ej3.asm
nasm -felf32 ./ejemplos/ej3.asm
gcc -m32 -o ./ejemplos/ej3 ./ejemplos/ej3.o alfalib.o

./alfa ./ejemplos/ej4.alf ./ejemplos/ej4.asm
nasm -felf32 ./ejemplos/ej4.asm
gcc -m32 -o ./ejemplos/ej4 ./ejemplos/ej4.o alfalib.o

./alfa ./ejemplos/ej5.alf ./ejemplos/ej5.asm
nasm -felf32 ./ejemplos/ej5.asm
gcc -m32 -o ./ejemplos/ej5 ./ejemplos/ej5.o alfalib.o

./alfa ./ejemplos/ej6.alf ./ejemplos/ej6.asm
nasm -felf32 ./ejemplos/ej6.asm
gcc -m32 -o ./ejemplos/ej6 ./ejemplos/ej6.o alfalib.o
