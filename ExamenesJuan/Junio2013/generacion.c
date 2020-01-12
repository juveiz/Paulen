#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){
        fprintf(fpasm, "segment .bss\n");
        fprintf(fpasm, "\t__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
        fprintf(fpasm, "segment .data\n");
        fprintf(fpasm, "\tmensaje_1 db \"Division por cero\",10,0\n");
        fprintf(fpasm, "\tmensaje_2 db \"Indice incorrecto de vector\",10,0\n");
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
        fprintf(fpasm, "_%s resd %d\n",nombre,tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
        fprintf(fpasm, "segment .text\n");
        fprintf(fpasm, "\tglobal main\n");
        fprintf(fpasm, "\textern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n");
        fprintf(fpasm, "\textern print_endofline, print_blank, print_string\n");
        fprintf(fpasm, "\textern alfa_malloc, alfa_free, ld_float\n");
}

void escribir_inicio_main(FILE* fpasm){
        fprintf(fpasm, "\t; -----------------------\n");
        fprintf(fpasm, "\t; PROCEDIMIENTO PRINCIPAL\n");
        fprintf(fpasm, "\t; -----------------------\n");
        fprintf(fpasm, "main:\n");
        fprintf(fpasm, "\tmov dword [__esp], esp\n\n");
}

void escribir_fin(FILE* fpasm){
        fprintf(fpasm, "\tjmp fin\n");
        fprintf(fpasm, "error_1:\n");
        fprintf(fpasm, "\tpush dword mensaje_1\n");
        fprintf(fpasm, "\tcall print_string\n");
        fprintf(fpasm, "\tadd esp, 4\n");
        fprintf(fpasm, "\tjmp fin\n");

        fprintf(fpasm, "error_2:\n");
        fprintf(fpasm, "\tpush dword mensaje_2\n");
        fprintf(fpasm, "\tcall print_string\n");
        fprintf(fpasm, "\tadd esp, 4\n");
        fprintf(fpasm, "\tjmp fin\n");

        fprintf(fpasm, "fin:\n");
        fprintf(fpasm, "\tmov dword esp, [__esp]\n");
        fprintf(fpasm, "\tret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
        /*Comprobamos si es variable*/
        /*Si es variable, la escribimos como tal*/
        if (es_variable == 1) {
                fprintf(fpasm, "\tpush dword _%s\n",nombre);
        }
        else{
                fprintf(fpasm, "\tpush dword %s\n", nombre);
        }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
        /*Sacamos el valor de la pila*/
        fprintf(fpasm, "\tpop dword eax\n");
        /*Si es una referencia, sacamos el valor*/
        if (es_variable == 1) {
                fprintf(fpasm, "\tmov eax, [eax]\n");
                fprintf(fpasm, "\tmov [_%s], eax\n", nombre);
        }
        else{
                fprintf(fpasm, "\tmov [_%s], eax\n", nombre);
        }
}

void lectura_operandos(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Sacamos el primer operando*/
        fprintf(fpasm, "\tpop dword ebx\n");
        /* Si es pasado por referencia, obtenemos el valor*/
        if (es_variable_2 == 1) {
                fprintf(fpasm, "\tmov ebx, [ebx]\n");
        }
        /* Sacamos el segundo operando*/
        fprintf(fpasm, "\tpop dword eax\n");
        /* Si es pasado por referencia, obtenemos el valor*/
        if (es_variable_1 == 1) {
                fprintf(fpasm, "\tmov eax, [eax]\n");
        }
}

void lectura_operando(FILE* fpasm, int es_variable){
        /* Sacamos el operando*/
        fprintf(fpasm, "\tpop dword eax\n");
        /* Si es pasado por referencia, obtenemos el valor*/
        if (es_variable == 1) {
                fprintf(fpasm, "\tmov eax, [eax]\n");
        }
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Sumamos */
        fprintf(fpasm, "\tadd eax, ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Restamos */
        fprintf(fpasm, "\tsub eax, ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Multiplicamos */
        fprintf(fpasm, "\timul ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Extendemos el signo */
        fprintf(fpasm, "\tcdq\n");
        /*Comprobamos que el divisor no sea 0*/
        fprintf(fpasm, "\tcmp ebx, 0\n");
        fprintf(fpasm, "\tje error_1\n");
        /* Dividimos */
        fprintf(fpasm, "\tidiv ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void modulo(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Extendemos el signo */
        fprintf(fpasm, "\tcdq\n");
        /*Comprobamos que el divisor no sea 0*/
        fprintf(fpasm, "\tcmp ebx, 0\n");
        fprintf(fpasm, "\tje error_1\n");
        /* Dividimos */
        fprintf(fpasm, "\tidiv ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword edx\n");
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Realizamos el or */
        fprintf(fpasm, "\tor eax, ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable_1,es_variable_2);
        /* Realizamos el and */
        fprintf(fpasm, "\tand eax, ebx\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void cambiar_signo(FILE* fpasm, int es_variable){
        /* Obtenemos los operandos en eax */
        lectura_operando(fpasm,es_variable);
        /* Dividimos */
        fprintf(fpasm, "\tneg eax\n");
        /* Guardamos el valor en la pila*/
        fprintf(fpasm, "\tpush dword eax\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
        /* Obtenemos los operandos en eax */
        lectura_operando(fpasm,es_variable);
        /* Ponemos 0 en ebx */
        fprintf(fpasm, "\tmov ebx, 0\n");
        /* Vemos si es 0 */
        fprintf(fpasm, "\tcmp eax, ebx\n");
        /* Si es 0 saltamos y cambiamos a 1 */
        fprintf(fpasm, "\tjz cero_no_%d\n",cuantos_no);
        /* Si no lo es, lo cambiamos a 0 */
        fprintf(fpasm, "\tmov eax, 0\n");
        /* Saltamos al final */
        fprintf(fpasm, "\tjmp fin_no_%d\n",cuantos_no);

        fprintf(fpasm, "cero_no_%d:\n",cuantos_no);
        fprintf(fpasm, "\tmov eax, 1\n");

        fprintf(fpasm, "fin_no_%d:\n",cuantos_no);
        /* Ponemos el nuevo valor */
        fprintf(fpasm, "\tpush dword eax\n");
}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tje igual_%d\n",etiqueta);
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
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tjne distinto_%d\n",etiqueta);
        /*Si no se cumple la comparacion, ponemos 0 en la pila*/
        fprintf(fpasm, "\tpush dword 0\n");
        /*Saltamos a la etiqueta fin*/
        fprintf(fpasm, "\tjmp fin_distinto_%d\n",etiqueta);
        /*Si se cumple la comparacion, ponemos 1 en la pila*/
        fprintf(fpasm, "distinto_%d:\n",etiqueta);
        fprintf(fpasm, "\tpush dword 1\n");

        fprintf(fpasm, "fin_distinto_%d:\n",etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
        /* Obtenemos los operandos en eax y en ebx*/
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tjle menor_igual_%d\n",etiqueta);
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
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tjge mayor_igual_%d\n",etiqueta);
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
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tjl menor_%d\n",etiqueta);
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
        lectura_operandos(fpasm,es_variable1,es_variable2);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,ebx\n");
        fprintf(fpasm, "\tjg mayor_%d\n",etiqueta);
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
        if(tipo==ENTERO) {
                fprintf(fpasm, "\tcall scan_int\n");
        }
        if(tipo==BOOLEANO) {
                fprintf(fpasm, "\tcall scan_boolean\n");
        }
        /*Restauramos el puntero a pila*/
        if(tipo==BOOLEANO||tipo==ENTERO) fprintf(fpasm, "\tadd esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, int tipo){
        /*Introducimos la direccion*/
        //lectura_operando(fpasm,es_variable);
        //fprintf(fpasm, "\tpush dword eax\n");
        /*Diferenciamos entre int y booleano*/
        if(tipo==ENTERO) {
                fprintf(fpasm, "\tcall print_int\n");
        }
        if(tipo==BOOLEANO) {
                fprintf(fpasm, "\tcall print_boolean\n");
        }
        /*Restauramos el puntero a pila*/
        if(tipo==BOOLEANO||tipo==ENTERO) fprintf(fpasm, "\tadd esp, 4\n");
        fprintf(fpasm, "\tcall print_endofline\n");
}


void ifthenelse_inicio(FILE* fpasm, int exp_es_variable, int etiqueta){
        /*Introducimos la direccion*/
        lectura_operando(fpasm, exp_es_variable);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,0\n");
        /* Si no se cumple la condicion saltamos */
        fprintf(fpasm, "\tje if_fin_%d\n",etiqueta);
}

void ifthen_inicio(FILE* fpasm, int exp_es_variable, int etiqueta){
        /*Introducimos la direccion*/
        lectura_operando(fpasm, exp_es_variable);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,0\n");
        /* Si no se cumple la condicion saltamos */
        fprintf(fpasm, "\tje if_fin_%d\n",etiqueta);
}

void ifthen_fin(FILE* fpasm, int etiqueta){
        fprintf(fpasm, "if_fin_%d:\n",etiqueta);
}

void ifthenelse_fin_then(FILE* fpasm, int etiqueta){
        fprintf(fpasm, "\tjmp else_fin_%d\n",etiqueta);
        fprintf(fpasm, "if_fin_%d:\n",etiqueta);
}

void ifthenelse_fin(FILE* fpasm, int etiqueta){
        fprintf(fpasm, "else_fin_%d:\n",etiqueta);
}

void while_inicio(FILE* fpasm, int etiqueta){
        fprintf(fpasm, "while_%d:\n",etiqueta);
}

void while_exp_pila(FILE* fpasm, int exp_es_variable, int etiqueta){
        /*Introducimos la direccion*/
        lectura_operando(fpasm, exp_es_variable);
        /*Comparamos eax y ebx*/
        fprintf(fpasm, "\tcmp eax,0\n");
        /* Si no se cumple la condicion saltamos */
        fprintf(fpasm, "\tje while_fin_%d\n",etiqueta);
}
void while_fin(FILE* fpasm, int etiqueta){
        fprintf(fpasm, "\tjmp while_%d\n",etiqueta);
        fprintf(fpasm, "while_fin_%d:\n",etiqueta);
}

void escribir_elemento_vector(FILE* fpasm, char* nombre_vector, int tam_max, int exp_es_direccion){
        lectura_operando(fpasm, exp_es_direccion);
        /*Si eax<0 o eax>=tam_max error*/
        fprintf(fpasm, "\tcmp eax,0\n");
        fprintf(fpasm, "\tjl error_2\n");
        fprintf(fpasm, "\tcmp eax,%d\n",tam_max);
        fprintf(fpasm, "\tjge error_2\n");
        fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
        fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
        fprintf(fpasm, "\tpush dword eax\n");
}

void declararFuncion(FILE* fd_asm, char* nombre_funcion, int num_var_loc){
        fprintf(fd_asm, "_%s:\n", nombre_funcion);
        fprintf(fd_asm, "\tpush dword ebp\n");
        fprintf(fd_asm, "\tmov dword ebp, esp\n");
        fprintf(fd_asm, "\tsub esp, %d\n", num_var_loc*4);
}

void retornarFuncion(FILE* fd_asm, int es_variable){
        lectura_operando(fd_asm, es_variable);
        fprintf(fd_asm, "\tmov dword esp,ebp\n");
        fprintf(fd_asm, "\tpop dword ebp\n");
        fprintf(fd_asm, "\tret\n");
}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
        int d_ebp;
        d_ebp = 4*( 1 + (num_total_parametros - pos_parametro));
        fprintf(fpasm, "\tlea eax, [ebp + %d]\n", d_ebp);
        fprintf(fpasm, "\tpush dword eax\n");
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
        int d_ebp;
        d_ebp = 4*posicion_variable_local;
        fprintf(fpasm, "\tlea eax, [ebp - %d]\n", d_ebp);
        fprintf(fpasm, "\tpush dword eax\n");
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){
        lectura_operandos(fpasm, es_variable, 0);
        fprintf(fpasm, "\tmov dword [ebx], eax\n");
}

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){
        if(es_variable == 1) {
                fprintf(fd_asm, "\tpop dword eax\n");
                fprintf(fd_asm, "\tmov eax, [eax]\n");
                fprintf(fd_asm, "\tpush dword eax\n");
        }
}

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){
        fprintf(fd_asm, "\tcall _%s\n", nombre_funcion);
}

void limpiarPila(FILE * fd_asm, int num_argumentos){
        fprintf(fd_asm, "\tadd esp, %d\n",num_argumentos*4);
        fprintf(fd_asm, "\tpush dword eax\n");
}