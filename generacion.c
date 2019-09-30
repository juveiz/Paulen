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

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  /*Comprobamos si es variable*/
  /*Si es variable, la escribimos como tal*/
  if (es_variable == 1){
    fprintf(fpasm, "push dword _%s\n",nombre);
  }
  else{
    fprintf(fpasm, "push dword %s\n", nombre);
  }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
  /*Sacamos el valor de la pila*/
  fprintf(fpasm, "pop dword eax\n");
    /*Si es una referencia, sacamos el valor*/
  if (es_variable == 1){
    fprintf(fpasm, "mov %s, [eax]\n", nombre);
  }
  else{
    fprintf(fpasm, "mov %s, eax\n", nombre);
  }
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

  fprintf(fpasm, "fin_no_%d:\n"cuantos_no);
  /* Ponemos el nuevo valor */
  fprintf(fpasm, "push dword eax\n");
}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tje igual_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_igual_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "igual_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_igual_%d:\n",etiqueta);
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tjne distinto_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_distinto_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "dstinto_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_distinto_%d:\n",etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tjle menor_igual_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_menor_igual_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "menor_igual_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_menor_igual_%d:\n",etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tjge mayor_igual_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_mayor_igual_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "mayor_igual_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_mayor_igual_%d:\n",etiqueta);
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tjl menor_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_menor_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "menor_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_menor_%d:\n",etiqueta);
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  /* Obtenemos los operandos en eax y en ebx*/
  lectura_operandos(fpasm,es_variable_1,es_variable_2);
  /*Comparamos eax y ebx*/
  fprintf(fpasm, "\tcmp eax,ebx\n");
  printf(fpasm, "\tjg mayor_%d\n",etiqueta);
  /*Si no se cumple la comparacion, ponemos 0 en la pila*/
  fprintf(fpasm, "\tpush dword 0\n");
  /*Saltamos a la etiqueta fin*/
  fprintf(fpasm, "\tjmp fin_mayor_%d\n",etiqueta);
  /*Si se cumple la comparacion, ponemos 1 en la pila*/
  fprintf(fpasm, "mayor_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_mayor_%d:\n",etiqueta);
}

void leer(FILE* fpasm, char* nombre, int tipo){
  /*Introducimos la direccion*/
  fprintf(fpasm, "\tpush dword _%s\n",nombre);
  /*Diferenciamos entre int y booleano*/
  if(tipo==ENTERO){
    fprintf(fpasm, "\tcall scan_int\n");
  }
  if(tipo==BOOLEAN){
    fprintf(fpasm, "\tcall scan_boolean\n");
  }
  /*Restauramos el puntero a pila*/
  if(tipo==BOOLEAN||tipo==ENTERO) fprintf(fpasm, "\tadd esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, int tipo){
  /*Introducimos la direccion*/
  lectura_operando(fpasm,es_variable);
  fprintf(fpasm, "\tpush dword eax\n");
  /*Diferenciamos entre int y booleano*/
  if(tipo==ENTERO){
    fprintf(fpasm, "\tcall print_int\n");
  }
  if(tipo==BOOLEAN){
    fprintf(fpasm, "\tcall print_boolean\n");
  }
  /*Restauramos el puntero a pila*/
  if(tipo==BOOLEAN||tipo==ENTERO) fprintf(fpasm, "\tadd esp, 4\n");
}
