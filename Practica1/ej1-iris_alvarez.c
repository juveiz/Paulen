#include "alfa.h"


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

void uno_si_mayor_de_10(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  fprintf(fpasm, "\n");
  fprintf(fpasm, "uno_si_mayor_de_10_%d:\n", etiqueta);
  fprintf(fpasm, "\n; CARGAR OPERANDOS Y SUMAR\n");
  fprintf(fpasm, "\tpop dword eax\n");
  fprintf(fpasm,"\tpop dword ebx\n");
  fprintf(fpasm, "\tadd eax,ebx\n");

  fprintf(fpasm, "\n; COMPARAR RESULTADO CON 10\n");
  fprintf(fpasm, "\tcmp eax,10\n");
  fprintf(fpasm, "\tjg mayor_%d\n",etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp fin_%d\n",etiqueta);

  fprintf(fpasm, "mayor_%d:\n",etiqueta);
  fprintf(fpasm, "\tpush dword 1\n");

  fprintf(fpasm, "fin_%d:\n",etiqueta);

  fprintf(fpasm, "; IMPRIMIR VALOR EN PILA\n");
  fprintf(fpasm, "\tcall print_int\n\n");
}
