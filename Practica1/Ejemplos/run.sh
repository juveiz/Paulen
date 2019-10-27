make clean
make

echo Ejercicio 1
./ej1.a ej1.asm
nasm -g -o ej1.o -f elf32 ej1.asm
gcc -m32 -o ejercicio1.a ej1.o alfalib.o


echo Ejercicio 2
./ej2.a ej2.asm
nasm -g -o ej2.o -f elf32 ej2.asm
gcc -m32 -o ejercicio2.a ej2.o alfalib.o


echo Ejercicio 3
./ej3.a ej3.asm
nasm -g -o ej3.o -f elf32 ej3.asm
gcc -m32 -o ejercicio3.a ej3.o alfalib.o


echo Ejercicio 4
./ej4.a ej4.asm
nasm -g -o ej4.o -f elf32 ej4.asm
gcc -m32 -o ejercicio4.a ej4.o alfalib.o


echo Ejercicio 5
./ej5.a ej5.asm
nasm -g -o ej5.o -f elf32 ej5.asm
gcc -m32 -o ejercicio5.a ej5.o alfalib.o

echo Ejercicio 6
./ej6.a ej6.asm
nasm -g -o ej6.o -f elf32 ej6.asm
gcc -m32 -o ejercicio6.a ej6.o alfalib.o


echo Ejercicio 7
./ej7.a ej7.asm
nasm -g -o ej7.o -f elf32 ej7.asm
gcc -m32 -o ejercicio7.a ej7.o alfalib.o
