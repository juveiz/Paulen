#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"

#define GLOBAL 0
#define LOCAL 1
#define MAX 256

int main(int argc, char const *argv[]) {
  FILE* entrada,*salida;
  char *linea = NULL;
  int num,flag = GLOBAL;
  char *identificador,*numero;
  size_t tam_linea = MAX;
  simboloTabla *simbolo;
  tablaSimbolos *tabla;
  int i;


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

  tabla = createTablaSimbolos();
  if (tabla == NULL){
    fclose(entrada);
    fclose(salida);
    printf("Error al crear la tabla de simbolos\n");
    return 1;
  }

  linea = (char*)malloc(sizeof(char) * MAX);
  if (linea == NULL){
    fclose(entrada);
    fclose(salida);
    deleteTablaSimbolos(tabla);
    printf("Error al crear memoria\n");
    return 1;
  }
  while(getline(&linea,&tam_linea,entrada) != -1){
    identificador = linea;
    numero = NULL;

    for(i=0; i < tam_linea;i++){
      if (linea[i] == '\t' || linea[i] == ' '){
        linea[i] = '\0';
        numero = &linea[i+1];
      }
      if(linea[i] == '\n'){
        linea[i] = '\0';
        break;
      }
    }

    if (numero){
      num = atoi(numero);
    }
    
    if (numero != NULL && identificador != NULL){
      if(strcmp(identificador,"cierre") == 0 && num == -999){
        /* Cierre */
        limpiarAmbitoLocal(tabla);
        fprintf(salida, "cierre\n");
      }else if (num >= 0){
        /* Variable*/
        if (flag == LOCAL){
          if(insertarAmbitoLocal(tabla,identificador,num) == 0){
            fprintf(salida, "%s\n",identificador);
          }else{
            fprintf(salida, "-1\t%s\n",identificador);
          }
        }else{
          if(insertarAmbitoGlobal(tabla,identificador,num) == 0){
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
          if (aperturaAmbitoLocal(tabla,identificador,num) == 0){
            flag = LOCAL;
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
          simbolo = buscarAmbitoGlobal(tabla,identificador);
      }else if (flag == LOCAL){
        simbolo = buscarAmbitoLocal(tabla,identificador);
      }else{
        fprintf(salida, "Error en la ejecucion del programa\n");
      }

      if (simbolo == NULL){
        fprintf(salida, "%s\t-1\n",identificador);
      }else{
        fprintf(salida, "%s\t%d\n",identificador,getValor(simbolo));
      }


    }else{
      fprintf(salida, "Error en la lectura de linea\n");
    }

  }
  fclose(entrada);
  fclose(salida);
  free(linea);
  deleteTablaSimbolos(tabla);
  return 0;
}
