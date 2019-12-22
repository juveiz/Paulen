./alfa ./ejemplos/ejemplo1.txt ./ejemplos/ejemplo1.asm
nasm -felf32 ./ejemplos/ejemplo1.asm
gcc -m32 -o ./ejemplos/ejemplo1 ./ejemplos/ejemplo1.o alfalib.o

./alfa ./ejemplos/suma.txt ./ejemplos/suma.asm
nasm -felf32 ./ejemplos/suma.asm
gcc -m32 -o ./ejemplos/suma ./ejemplos/suma.o alfalib.o

./alfa ./ejemplos/boolean.txt ./ejemplos/boolean.asm
nasm -felf32 ./ejemplos/boolean.asm
gcc -m32 -o ./ejemplos/boolean ./ejemplos/boolean.o alfalib.o

./alfa ./ejemplos/ejemplo2.txt ./ejemplos/ejemplo2.asm
nasm -felf32 ./ejemplos/ejemplo2.asm
gcc -m32 -o ./ejemplos/ejemplo2 ./ejemplos/ejemplo2.o alfalib.o

./alfa ./ejemplos/anidado.txt ./ejemplos/anidado.asm
nasm -felf32 ./ejemplos/anidado.asm
gcc -m32 -o ./ejemplos/anidado ./ejemplos/anidado.o alfalib.o
