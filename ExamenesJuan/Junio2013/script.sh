make clean
make

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

./alfa ./ejemplos/condicionales.alfa ./ejemplos/condicionales.asm
nasm -felf32 ./ejemplos/condicionales.asm
gcc -m32 -o ./ejemplos/condicionales ./ejemplos/condicionales.o alfalib.o

./alfa ./ejemplos/factorial.alfa ./ejemplos/factorial.asm
nasm -felf32 ./ejemplos/factorial.asm
gcc -m32 -o ./ejemplos/factorial ./ejemplos/factorial.o alfalib.o

./alfa ./ejemplos/vectores.alfa ./ejemplos/vectores.asm
nasm -felf32 ./ejemplos/vectores.asm
gcc -m32 -o ./ejemplos/vectores ./ejemplos/vectores.o alfalib.o

./alfa ./ejemplos/funciones.alfa ./ejemplos/funciones.asm
nasm -felf32 ./ejemplos/funciones.asm
gcc -m32 -o ./ejemplos/funciones ./ejemplos/funciones.o alfalib.o

./alfa ./ejemplos/funciones_vectores.alfa ./ejemplos/funciones_vectores.asm
nasm -felf32 ./ejemplos/funciones_vectores.asm
gcc -m32 -o ./ejemplos/funciones_vectores ./ejemplos/funciones_vectores.o alfalib.o

./alfa ./ejemplos/fibonacci.alfa ./ejemplos/fibonacci.asm
nasm -felf32 ./ejemplos/fibonacci.asm
gcc -m32 -o ./ejemplos/fibonacci ./ejemplos/fibonacci.o alfalib.o
