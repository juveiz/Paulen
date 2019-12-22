%{
  #include <stdio.h>
  #include "alfa.h"
  #include "alfa.tab.h"
  #include "generacion.h"
  #include "tablasimbolos.h"
  extern FILE* out;
  extern void yyerror(const char * s);
  extern long nline;
  int yylex();
  tablaSimbolos *tabla;
  int ambito = GLOBAL;
  CATEGORIA_SIMBOLO cat_simbolo;
  TIPO tipo;
  CATEGORIA categoria;
  int valor;
  int longitud = 1;
  int num_parametros = 0;
  int num_var_locales = 0;
  int posicion = 0;
  int posicion_parametro = 0;
  int etiqueta = 0;
  int fn_return = 0;
  TIPO fn_tipo;
%}
%union
{
 tipo_atributos atributos;
}
%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador
%type <atributos> if_exp
%type <atributos> if_exp_sentencias
%type <atributos> while
%type <atributos> while_exp
%type <atributos> fn_declaracion
%type <atributos> fn_nombre

%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND
%right TOK_NOT



%%
programa: TOK_MAIN inicioTabla TOK_LLAVEIZQUIERDA declaraciones escritura_TS funciones escritura_main sentencias TOK_LLAVEDERECHA
{fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
  escribir_fin(out);
  deleteTablaSimbolos(tabla);};

inicioTabla: {
  tabla = createTablaSimbolos();
  if (tabla == NULL){
    printf("Error en la tabla de simbolos: No se ha creado la tabla de simbolos\n");
    return -1;
  }
  escribir_cabecera_bss(out);
}

escritura_TS: {
  escribir_subseccion_data(out);
  escribir_segmento_codigo(out);
}

escritura_main: {
  //creo faltan funciones
  escribir_inicio_main(out);
}

declaraciones:  declaracion {fprintf(out,";R2:\t<declaraciones> ::= <declaracion>\n");}
              | declaracion declaraciones {fprintf(out,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");};

declaracion: clase identificadores TOK_PUNTOYCOMA {fprintf(out,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");};

clase:  clase_escalar {fprintf(out,";R5:\t<clase> ::= <clase_escalar>\n"); categoria = ESCALAR;}
      | clase_vector {fprintf(out,";R7:\t<clase> ::= <clase_vector>\n"); categoria = VECTOR;};

clase_escalar: tipo
               {
                 fprintf(out,";R9:\t<clase_escalar> ::= <tipo>\n");
                 longitud = 1;
              };

tipo:   TOK_INT {fprintf(out,";R10:\t<tipo> ::= int\n"); tipo = ENTERO;}
      | TOK_BOOLEAN {fprintf(out,";R11:\t<tipo> ::= boolean\n"); tipo = BOOLEANO;};

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO
              {fprintf(out,";R15\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");
                longitud = $4.valor_entero;
                if(longitud < 1 ||longitud > MAX_TAMANIO_VECTOR){
                  printf("****Error semantico en lin %li: El tamanyo del vector excede los limites permitidos (1,64).\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }};

identificadores:   identificador {fprintf(out,";R18:\t<identificadores> ::= <identificador>\n");}
                  | identificador TOK_COMA identificadores {fprintf(out,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");};

funciones: funcion funciones {fprintf(out,";R20:\t<funciones> ::= <function> <funciones>\n");};
          |/*vacio*/{fprintf(out,";R21:\t<funciones> ::= \n");};

funcion: fn_declaracion sentencias TOK_LLAVEDERECHA
         {
           fprintf(out,";R22:\t<function> ::= function <tipo> <identificador> (<parametro_funcion>) {<declaraciones_funcion> <sentencias>}\n");
           if (fn_return < 1){
             printf("****Funcion %s sin sentencia de retorno\n", $1.lexema);
             deleteTablaSimbolos(tabla);
             return -1;
           }
           limpiarAmbitoLocal(tabla);
           simboloTabla * simboloTabla;
           SIMBOLO * simbolo;
           if( (simboloTabla = buscarAmbitoGlobal(tabla,$1.lexema)) == NULL) {
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
           }
           simbolo = getValor(simboloTabla);
           simbolo->num_parametros=num_parametros;
           ambito = GLOBAL;
        };

fn_declaracion: fn_nombre TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion
                {
                  simboloTabla * simboloTabla;
                  SIMBOLO * simbolo;
                  if((simboloTabla = buscarAmbitoLocal(tabla,$1.lexema)) == NULL) {
                    printf("****Error en la tabla de simbolos\n");
                    deleteTablaSimbolos(tabla);
                    return -1;
                  }
                  simbolo = getValor(simboloTabla);
                  simbolo->num_parametros = num_parametros;
                  simbolo->num_var_locales = num_var_locales;
                  strcpy($$.lexema, $1.lexema);
                  declararFuncion(out, $1.lexema, num_var_locales);
                  //TODO donde poner esto, exp: identificador
                  for(int i = 0; i<num_parametros; i++) {
                    escribirParametro(out, i, num_parametros);
                  }
                };

fn_nombre: TOK_FUNCTION tipo TOK_IDENTIFICADOR
           {
             if (buscarAmbitoGlobal(tabla,$3.lexema) == NULL){
             SIMBOLO *sim;
             sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
             if(sim == NULL){
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             }
             sim->identificador = (char*)malloc(sizeof(char)*(strlen($3.lexema) + 1));
             if (sim->identificador == NULL){
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             }
             strcpy(sim->identificador,$3.lexema);
             strcpy($$.lexema, $3.lexema);
             sim->cat_simbolo = FUNCION;
             sim->tipo = tipo;
             sim->num_parametros = 0;
             sim->num_var_locales = 0;
             posicion = 1;
             num_var_locales = 0;
             posicion_parametro = 0;
             num_parametros = 0;
             fn_return = 0;
             fn_tipo = tipo;
             ambito = LOCAL;
             if( aperturaAmbitoLocal(tabla, $3.lexema, sim) == -1) {
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             };
            }
             else {
               printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
               deleteTablaSimbolos(tabla);
               return -1;
             }
           };

parametros_funcion:  parametro_funcion resto_parametros_funcion {fprintf(out,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                    |/*vacio*/{fprintf(out,";R24:\t<parametros_funcion> ::= \n");};

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(out,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");};
                         |/*vacio*/{fprintf(out,";R26:\t<resto_parametros_funcion> ::= \n");};

parametro_funcion: tipo idpf
                   {
                     fprintf(out,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                     num_parametros++;
                     posicion_parametro++;
                  };

idpf: TOK_IDENTIFICADOR
      {
        if (buscarAmbitoLocal(tabla,$1.lexema) == NULL){
          SIMBOLO *sim;
          sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
          if(sim == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          sim->identificador = (char*)malloc(sizeof(char)*(strlen($1.lexema) + 1));
          if (sim->identificador == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          strcpy(sim->identificador,$1.lexema);
          sim->cat_simbolo = PARAMETRO;
          sim->tipo = tipo;
          sim->categoria = ESCALAR;
          sim->valor = valor;
          sim->longitud = longitud;
          sim->posicion = posicion_parametro;
          if (insertarAmbitoLocal(tabla, $1.lexema, sim) == -1){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
        }else{
          printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
    };

declaraciones_funcion: declaraciones {fprintf(out,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                      |/*vacio*/{fprintf(out,";R29:\t<declaraciones_funcion> ::= \n");};

sentencias:  sentencia {fprintf(out,";R30:\t<sentencias> ::= <sentencia>\n");}
           | sentencia sentencias {fprintf(out,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");};

sentencia:  sentencia_simple TOK_PUNTOYCOMA {fprintf(out,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
          | bloque {fprintf(out,";R33:\t<sentencia> ::= <bloque>\n");};

sentencia_simple:  asignacion {fprintf(out,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                 | lectura {fprintf(out,";R35:\t<sentencia_simple> ::= <lectura>\n");}
                 | escritura {fprintf(out,";R36:\t<sentencia_simple> ::= <escritura>\n");}
                 | retorno_funcion {fprintf(out,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");};

bloque:  condicional {fprintf(out,";R40:\t<bloque> ::= <condicional>\n");}
       | bucle {fprintf(out,";R41:\t<bloque> ::= <condicional>\n");};

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp
            {fprintf(out,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
              simboloTabla *simbolo;
              SIMBOLO *sim_aux;
              if (ambito == GLOBAL){
                if((simbolo = buscarAmbitoGlobal(tabla,$1.lexema)) == NULL){
                  printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
              }else{
                if((simbolo = buscarAmbitoLocal(tabla,$1.lexema)) == NULL){
                  printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
              }
              sim_aux = getValor(simbolo);
              if(sim_aux == NULL){
                printf("****Error en la tabla de simbolos\n");
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->cat_simbolo == FUNCION){
                printf("****Error en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->categoria == VECTOR){
                printf("****Error en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->tipo != $3.tipo){
                printf("****Error en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              asignar(out,$1.lexema,$3.es_direccion);
            }
           | elemento_vector TOK_ASIGNACION exp
            {fprintf(out,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
            simboloTabla *simbolo;
            SIMBOLO *sim_aux;
            // Revisar
            if (ambito == GLOBAL){
              if((simbolo = buscarAmbitoGlobal(tabla,$1.lexema)) == NULL){
                printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
                deleteTablaSimbolos(tabla);
                return -1;
              }
            }else{
              printf("****Error en lin %li: Acceso a vector en ambito local (%s)\n",nline,$1.lexema);
              deleteTablaSimbolos(tabla);
              return -1;
            }
            sim_aux = getValor(simbolo);
            if(sim_aux == NULL){
              printf("****Error en la tabla de simbolos\n");
              deleteTablaSimbolos(tabla);
              return -1;
            }
            if($1.tipo != $3.tipo){
              printf("****Error en lin %li: Asignacion incompatible\n",nline);
              deleteTablaSimbolos(tabla);
              return -1;
            }
            char valor[MAX_INT];
            sprintf(valor,"%d",$1.valor_entero);
            escribir_operando(out,valor,0);
            escribir_elemento_vector(out,$1.lexema,sim_aux->longitud,$3.es_direccion);
            asignarDestinoEnPila(out,$3.es_direccion);
          };

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
          {fprintf(out,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
          simboloTabla *simbolo;
          SIMBOLO *sim_aux;
          if (ambito == GLOBAL){
            if((simbolo = buscarAmbitoGlobal(tabla,$1.lexema)) == NULL){
              printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
              deleteTablaSimbolos(tabla);
              return -1;
            }
          }else{
            printf("****Error en lin %li: Acceso a vector en ambito local (%s)\n",nline,$1.lexema);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          sim_aux = getValor(simbolo);
          if(sim_aux == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if(sim_aux->cat_simbolo == FUNCION){
            printf("****Error en lin %li: Intento de indexacion de una variable que no es de tipo vector\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if(sim_aux->categoria == ESCALAR){
            printf("****Error en lin %li: Intento de indexacion de una variable que no es de tipo vector\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if($3.tipo != ENTERO){
            printf("****Error en lin %li: El indice en una operacion de indexacion tiene que ser de tipo entero\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          // Pensar si queremos que dar un numero que no corresponde de Error
          $$.tipo = sim_aux->tipo;
          $$.es_direccion = 1;
          $$.valor_entero = $3.valor_entero;
          escribir_elemento_vector(out,sim_aux->identificador,sim_aux->longitud,$3.es_direccion);
        };

condicional:  if_exp sentencias TOK_LLAVEDERECHA
              {
                fprintf(out,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                ifthen_fin(out, $$.etiqueta);
            }
            | if_exp_sentencias TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
              {
                fprintf(out,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                ifthenelse_fin(out, $1.etiqueta);
            };

if_exp_sentencias: if_exp sentencias TOK_LLAVEDERECHA
                   {
                     $$.etiqueta = $1.etiqueta;
                     ifthenelse_fin_then(out, $$.etiqueta);
                   }

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
        {
          if($3.tipo != BOOLEANO) {
            printf("****Error en lin %li: Tipo incorrecto \n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }

          $$.etiqueta = etiqueta++;

          ifthen_inicio(out,$3.es_direccion, $$.etiqueta);
        }

bucle: while_exp sentencias TOK_LLAVEDERECHA
      {
        fprintf(out,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        while_fin(out, $1.etiqueta);
      };

while_exp: while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
           {
             if($2.tipo != BOOLEANO) {
               printf("****Error en lin %li: Tipo incorrecto \n",nline);
               deleteTablaSimbolos(tabla);
               return -1;
             }

             $$.etiqueta = $1.etiqueta;

             while_exp_pila(out, $2.es_direccion, $$.etiqueta);
           }

while: TOK_WHILE TOK_PARENTESISIZQUIERDO
       {
         $$.etiqueta = etiqueta++;
         while_inicio(out, $$.etiqueta);
       }

lectura: TOK_SCANF TOK_IDENTIFICADOR
{
  fprintf(out,";R54:\t<lectura> ::= scanf <identificador>\n");
  simboloTabla * simboloTabla;
  SIMBOLO * simbolo;
  if(ambito == GLOBAL) simboloTabla = buscarAmbitoGlobal(tabla, $2.lexema);
  else simboloTabla = buscarAmbitoLocal(tabla, $2.lexema);

  if(simboloTabla == NULL) {
    printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$2.lexema);
    deleteTablaSimbolos(tabla);
    return -1;
  }
  simbolo = getValor(simboloTabla);
  if(simbolo->cat_simbolo == FUNCION || simbolo->categoria == VECTOR){
    printf("****Error en lin %li: Categoria o clase incorrecta de (%s)\n",nline,$2.lexema);
    deleteTablaSimbolos(tabla);
    return -1;
  }

  /* TODO
    Si el identificador en una variable global, su dirección es su lexema
    Si el identificador es un parámetro o una variable local, su dirección se expresa en función de ebp y la
    posición del parámetro o variable local
  */
  if(ambito == GLOBAL){

  }
  else if(buscarAmbitoLocal(tabla, $2.lexema) != NULL){

  }
  else if(buscarAmbitoGlobal(tabla, $2.lexema) != NULL){

  }
  leer(out, $2.lexema, $2.tipo);
  };

escritura: TOK_PRINTF exp
            {fprintf(out,";R56:\t<escritura> ::= printf <exp>\n");
            operandoEnPilaAArgumento(out,$2.es_direccion);
            escribir(out,0,$2.tipo);
              };

retorno_funcion: TOK_RETURN exp
                 {
                   fprintf(out,";R61:\t<retorno_funcion> ::= return <exp>\n");
                   if(fn_tipo != $2.tipo) {
                     printf("****Error en lin %li: Tipo incorrecto en retorno\n",nline);
                   }
                   fn_return ++;
                   retornarFuncion(out,$2.es_direccion);
                };

exp:  exp TOK_MAS exp
      {
        fprintf(out,";R72:\t<exp> ::= <exp> + <exp>\n");
        if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
          printf("****Error en lin %li: No se pueden sumar booleanos\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        sumar(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    }
    | exp TOK_MENOS exp
      {
        fprintf(out,";R73:\t<exp> ::= <exp> - <exp>\n");
        if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
          printf("****Error en lin %li: No se pueden restar booleanos\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        restar(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    }
    | exp TOK_DIVISION exp
      {
        fprintf(out,";R74:\t<exp> ::= <exp> / <exp>\n");
        if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
          printf("****Error en lin %li: No se pueden dividir booleanos\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        dividir(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    }
    | exp TOK_ASTERISCO exp
      {
        fprintf(out,";R75:\t<exp> ::= <exp> * <exp>\n");
        if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
          printf("****Error en lin %li: No se pueden multiplicar booleanos\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        multiplicar(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    }
    | TOK_MENOS exp
      {
        fprintf(out,";R76:\t<exp> ::= - <exp>\n");
        if($2.tipo == BOOLEANO) {
          printf("****Error en lin %li: Tipo incorrecto\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        cambiar_signo(out, $2.es_direccion);
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    }
    | exp TOK_AND exp
      {
        fprintf(out,";R77:\t<exp> ::= <exp> && <exp>\n");
        if(($1.tipo == ENTERO) || ($3.tipo == ENTERO)) {
          printf("****Error en lin %li: Tipo incorrecto\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        y(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
    }
    | exp TOK_OR exp
      {
        fprintf(out,";R:78\t<exp> ::= <exp> || <exp>\n");
        if(($1.tipo == ENTERO) || ($3.tipo == ENTERO)) {
          printf("****Error en lin %li: Tipo incorrecto\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        o(out, $1.es_direccion, $3.es_direccion);
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
    }
    | TOK_NOT exp
      {
        fprintf(out,";R79:\t<exp> ::= ! <exp>\n");
        if($2.tipo == ENTERO) {
          printf("****Error en lin %li: Tipo incorrecto\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        no(out, $2.es_direccion, etiqueta);
        etiqueta++;
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
    }
    | TOK_IDENTIFICADOR
      {fprintf(out,";R80:\t<exp> ::= <identificador>\n");
      simboloTabla *simbolo;
      SIMBOLO *sim_aux;
      if (ambito == GLOBAL){
        if((simbolo = buscarAmbitoGlobal(tabla,$1.lexema)) == NULL){
          printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }else{
        if((simbolo = buscarAmbitoLocal(tabla,$1.lexema)) == NULL){
          printf("****Error en lin %li: Acceso a variable no declarada (%s)\n",nline,$1.lexema);
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }
      sim_aux = getValor(simbolo);
      if(sim_aux == NULL){
        printf("****Error en la tabla de simbolos\n");
        deleteTablaSimbolos(tabla);
        return -1;
      }
      if(sim_aux->cat_simbolo == FUNCION){
        printf("****Error en lin %li: Asignacion incompatible\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
      if(sim_aux->categoria == VECTOR){
        printf("****Error en lin %li: Asignacion incompatible\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
      $$.tipo = sim_aux->tipo;
      $$.es_direccion = 1;
      escribir_operando(out,$1.lexema,1);
    }
    | constante
      {fprintf(out,";R81:\t<exp> ::= <constante>\n");
      $$.tipo = $1.tipo;
      $$.es_direccion = $1.es_direccion;}
    | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
      {fprintf(out,";R82:\t<exp> ::= ( <exp> )\n");
      $$.tipo = $2.tipo;
      $$.es_direccion = $2.es_direccion;
    }
    | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO
    {
      fprintf(out,";R83:\t<exp> ::= ( <comparacion> )\n");
      $$.tipo = $2.tipo;
      $$.es_direccion = $2.es_direccion;
    }
    | elemento_vector {fprintf(out,";R85:\t<exp> ::= <elemento_vector>\n");}
    | TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
      {
        simboloTabla * simboloTabla;
        SIMBOLO * simbolo;
        fprintf(out,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
        if((simboloTabla = buscarAmbitoGlobal(tabla, $1.lexema)) == NULL) {
          printf("****Error en lin %li: La funcion no existe\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        simbolo = getValor(simboloTabla);
        llamarFuncion(out, $1.lexema, simbolo->num_parametros);
        limpiarPila(out, simbolo->num_parametros);
    };

lista_expresiones: exp resto_lista_expresiones {fprintf(out,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
                  |/*vacio*/{fprintf(out,";R90:\t<lista_expresiones> ::= \n");};

resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(out,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
                        |/*vacio*/{fprintf(out,";R92:\t<resto_lista_expresiones> ::= \n");};

comparacion:  exp TOK_IGUAL exp
              {
                fprintf(out,";R93:\t<comparacion> ::= <exp> == <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                igual(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            }
            | exp TOK_DISTINTO exp
              {
                fprintf(out,";R94:\t<comparacion> ::= <exp> != <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                distinto(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            }
            | exp TOK_MENORIGUAL exp
              {
                fprintf(out,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                menor_igual(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            }
            | exp TOK_MAYORIGUAL exp
              {
                fprintf(out,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                mayor_igual(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            }
            | exp TOK_MENOR exp
              {
                fprintf(out,";R97:\t<comparacion> ::= <exp> < <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                menor(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            }
            | exp TOK_MAYOR exp
              {
                fprintf(out,";R98:\t<comparacion> ::= <exp> > <exp>\n");
                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)) {
                  printf("****Error en lin %li: No se pueden comparar booleanos\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                mayor(out, $1.es_direccion , $3.es_direccion ,etiqueta);
                etiqueta ++;
                $$.tipo = BOOLEANO;
                $$.es_direccion = 0;
            };

constante:  constante_logica
            {fprintf(out,";R99:\t<constante> ::= <constante_logica>\n");
            $$.tipo = $1.tipo;
            $$.es_direccion = $1.es_direccion;}
         | constante_entera {fprintf(out,";R100:\t<constante> ::= <constante_entera>\n");};

constante_logica:  TOK_TRUE {fprintf(out,";R102:\t<constante_logica> ::= true\n");}
                 | TOK_FALSE {fprintf(out,";R103:\t<constante_logica> ::= false\n");};

constante_entera: TOK_CONSTANTE_ENTERA
  {fprintf(out,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
    $$.tipo = ENTERO;
    $$.es_direccion = 0;
    $$.valor_entero = $1.valor_entero;
    char valor[MAX_INT];
    sprintf(valor,"%d",$$.valor_entero);
    escribir_operando(out,valor,0);
    };

identificador: TOK_IDENTIFICADOR
    {fprintf(out,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    if (ambito == GLOBAL){
      if (buscarAmbitoGlobal(tabla,$1.lexema) == NULL){
        SIMBOLO *sim;
        sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
        if(sim == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        sim->identificador = (char*)malloc(sizeof(char)*(strlen($1.lexema) + 1));
        if (sim->identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim->identificador,$1.lexema);
        sim->cat_simbolo = cat_simbolo;
        sim->tipo = tipo;
        sim->categoria = categoria;
        sim->valor = valor;
        sim->longitud = longitud;
        sim->num_parametros = num_parametros;
        sim->posicion = posicion;
        if (insertarAmbitoGlobal(tabla, $1.lexema, sim) == -1){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        declarar_variable(out,$1.lexema,sim->tipo,sim->longitud);
      }else{
        printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
    }else{
      if (buscarAmbitoLocal(tabla,$1.lexema) == NULL){
        if (categoria != ESCALAR){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        SIMBOLO *sim;
        sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
        if(sim == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        posicion ++;
        num_var_locales ++;
        sim->identificador = (char*)malloc(sizeof(char)*(strlen($1.lexema) + 1));
        if (sim->identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim->identificador,$1.lexema);
        sim->cat_simbolo = cat_simbolo;
        sim->tipo = tipo;
        sim->categoria = categoria;
        sim->valor = valor;
        sim->longitud = longitud;
        // Revisar las dos siguientes
        sim->num_parametros = num_parametros;
        sim->posicion = posicion;
        if (insertarAmbitoLocal(tabla, $1.lexema, sim) == -1){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }else{
        printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
    }
    };
