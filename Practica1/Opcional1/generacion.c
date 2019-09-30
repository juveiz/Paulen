#include "generacion.h"

void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
}

void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "\t__esp resd 1\n");
}

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "\t; -----------------------\n");
  fprintf(fpasm, "\t; PROCEDIMIENTO PRINCIPAL\n");
  fprintf(fpasm, "\t; -----------------------\n");
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "\tmov dword [__esp], esp\n\n");
}

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\tmov dword esp, [__esp]\n");
  fprintf(fpasm, "\tret\n");
}

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "\tglobal main\n");
  fprintf(fpasm, "\textern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n");
  fprintf(fpasm, "\textern print_endofline, print_blank, print_string\n");
  fprintf(fpasm, "\textern alfa_malloc, alfa_free, ld_float\n");
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
  fprintf(fpasm, "_%s resd %d\n",nombre,tamano);
}


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
  lectura_operando(fpasm,es_variable);
  /* Dividimos */
  fprintf(fpasm, "neg eax\n");
  /* Guardamos el valor en la pila*/
  fprintf(fpasm, "push dword eax\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
  /* Obtenemos los operandos en eax */
  lectura_operando(fpasm,es_variable);
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

  fprintf(fpasm, "fin_no_%d:\n",cuantos_no);
  /* Ponemos el nuevo valor */
  fprintf(fpasm, "push dword eax\n");
}

void leer(FILE* fpasm, char* nombre, int tipo){
  fprintf(fpasm, "push dword _%s\n",nombre);

  if (tipo == ENTERO) {
    fprintf(fpasm, "call scan_int\n");
  }else{
    fprintf(fpasm, "call scan_boolean\n");
  }
  fprintf(fpasm, "add esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, int tipo){
  fprintf(fpasm, "pop dword eax\n");

  if (es_variable == 1) {
    fprintf(fpasm, "push dword [eax]\n");
  }else{
    fprintf(fpasm, "push dword eax\n");
  }


  if (tipo == ENTERO) {
    fprintf(fpasm, "call print_int\n");
  }else{
    fprintf(fpasm, "call print_boolean\n");
  }
  fprintf(fpasm, "add esp, 4\n");
}

void suma_iterativa(FILE *fpasm, char *nombre1, char *nombre2) {
  leer(fpasm, nombre1, ENTERO);
  leer(fpasm, nombre2, ENTERO);

  fprintf(fpasm, "mov dword ecx,[_x]\n");
  fprintf(fpasm, "mov dword ebx,[_y]\n");
  fprintf(fpasm, "while:\n");
  fprintf(fpasm, "cmp ebx,0\n");
  fprintf(fpasm, "jz fin\n");
  fprintf(fpasm, "add ecx,ebx\n");
  fprintf(fpasm, "mov dword [_x], ecx\n");
  fprintf(fpasm, "push dword ecx\n");

  escribir(fpasm,0,ENTERO);
  fprintf(fpasm, "call print_endofline\n");
  leer(fpasm, nombre2, ENTERO);

  fprintf(fpasm, "mov dword ebx,[_y]\n");
  fprintf(fpasm, "jmp while\n");
  fprintf(fpasm, "fin:\n");

}
