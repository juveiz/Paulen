#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"

#define GLOBAL 0
#define LOCAL 1

int main(int argc, char const *argv[]) {
  FILE* entrada,*salida;
  char *linea = NULL;
  int tam_linea,res,num,flag = GLOBAL;
  char *identificador,*numero;
  simboloTabla *simbolo;

  if (argc < 3){
    printf("No hay suficientes parametros.Programa entrada salida\n");
    return 1;
  }

  entrada = fopen(argv[1],"r");
  if (entrada == NULL){
    printf("Error al abrir el archivo entrada\n");
    return 1;
  }

  salida = fopen(argv[2],"w");
  if (salida == NULL){
    fclose(entrada);
    printf("Error al abrir el archivo salida\n");
    return 1;
  }
  while((res = getline(&linea,&tam_linea,entrada)) != -1){
    int i;
    identificador = linea;
    numero = NULL;

    for(i=0; i < tam_linea;i++){
      if (linea[i] == '\t'){
        linea[i] = '\0';
        numero = linea + 1;
      }
      if(linea[i] == '\n'){
        linea[i] = '\0';
      }
    }

    if (numero){
      num = atoi(numero);
    }

    if (numero != NULL && identificador != NULL){
      if(strcmp(identificador,"cierre") == 0 && num == -999){
        /* Cierre */
        cerrarAmbitoLocal();
        fprintf(salida, "cierre\n");
      }else if (num >= 0){
        /* Variable*/
        if (flag == LOCAL){
          if(insertarVariableLoacal() == 0){
            fprintf(salida, "%s\n",identificador);
          }else{
            fprintf(salida, "-1\t%s\n",identificador);
          }
        }else{
          if(insertarVariableGlobal() == 0){
            fprintf(salida, "%s\n",identificador);
          }else{
            fprintf(salida, "-1\t%s\n",identificador);
            }
          }

      }else if (num < 0){
        /* Funcion*/
        if (flag == LOCAL){
          fprintf(salida, "No se puede anidar funciones\n");
        }else{
          if (insertarFUncion() == 0){
            fprintf(salida, "%s\n",identificador);
          }else{
            fprintf(salida, "-1\t%s\n",identificador);
          }
        }
      }
    }else if (identificador != NULL){
      simbolo = NULL;
      /* Buscar identificador */
      if (flag == GLOBAL){
          simbolo = buscarSimboloGlobal();
      }else if (flag == LOCAL){
        simbolo = buscarSimboloLocal();
      }else{
        fprintf(salida, "Error en la ejecucion del programa\n");
      }

      if (simbolo == NULL){
        fprintf(salida, "%s\t-1\n",identificador);
      }else{
        fprintf(salida, "%s\t%d\n",identificador,getId(simbolo));
      }


    }else{
      fprintf(salida, "Error en la lectura de linea\n");
    }

  }

  fclose(entrada);
  fclose(salida);
  return 0;
}
