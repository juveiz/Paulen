#include "generacion.h"

void lectura_operandos(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Sacamos el primer operando*/
  fprintf(fpasm, "pop dword eax\n");
  /* Si es pasado por referencia, obtenemos el valor*/
  if (es_variable_1 == 1){
    fprintf(fpasm, "mov eax, [eax]\n");
  }
  /* Sacamos el segundo operando*/
  fprintf(fpasm, "pop dword ebx\n");
  /* Si es pasado por referencia, obtenemos el valor*/
  if (es_variable_1 == 1){
    fprintf(fpasm, "mov ebx, [ebx]\n");
  }
}

void lectura_operando(FILE* fpasm, int es_variable){
  /* Sacamos el operando*/
  fprintf(fpasm, "pop dword eax\n");
  /* Si es pasado por referencia, obtenemos el valor*/
  if (es_variable == 1){
    fprintf(fpasm, "mov eax, [eax]\n");
  }
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Sumamos */
  fprintf(fpasm, "add eax, ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Restamos */
  fprintf(fpasm, "sub eax, ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Multiplicamos */
  fprintf(fpasm, "imul ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}
//todo: division por 0
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Extendemos el signo */
  fprintf(fpasm, "cdq\n");
  /* Dividimos */
  fprintf(fpasm, "idiv ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}
void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Realizamos el or */
  fprintf(fpasm, "or eax, ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}
void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /* Realizamos el and */
  fprintf(fpasm, "and eax, ebx\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}
void cambiar_signo(FILE* fpasm, int es_variable){
  /* Obtenemos los operandos en eax */
  lectura_operandos(fpasm,es_variable);
  /* Dividimos */
  fprintf(fpasm, "neg eax\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
  /* Obtenemos los operandos en eax */
  lectura_operandos(fpasm,es_variable);
  /* Ponemos 0 en ebx */
  fprintf(fpasm, "mov ebx 0\n");
  /* Vemos si es 0 */
  fprintf(fpasm, "cmp eax, ebx\n");
  /* Si es 0 saltamos y cambiamos a 1 */
  fprintf(fpasm, "jz cero_no_%d\n",cuantos_no);
  /* Si no lo es, lo cambiamos a 0 */
  fprintf(fpasm, "mov eax 0\n");
  /* Saltamos al final */
  fprintf(fpasm, "jmp fin_no_%d\n",cuantos_no);

  fprintf(fpasm, "cero_no_%d:\n",cuantos_no);
  fprintf(fpasm, "mov eax 1\n");

  fprintf(fpasm, "fin_no_%d:\n"cuantos_no);
  /* Ponemos el nuevo valor */
  fprintf(fpasm, "push dword eax\n");
}
