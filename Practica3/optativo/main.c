#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"

#define MAX 256
#define MAX_LOCAL 5

int main(int argc, char const *argv[]) {
  FILE* entrada,*salida;
  char *linea = NULL;
  int num;
  char *identificador,*numero;
  size_t tam_linea = MAX;
  simboloTabla *simbolo;
  tablaSimbolos *tabla;
  int i,ambito_local = 0;


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
        numero = linea + i + 1 ;
      }
      if(linea[i] == '\n' || linea[i] == '\r'){
        linea[i] = '\0';
        break;
      }
    }

    if (numero){
      num = atoi(numero);
    }
    
    if (numero != NULL && identificador != NULL){
      if(strcmp(identificador,"cierre") == 0 && num == -999 && ambito_local > 0){
        /* Cierre */
        limpiarAmbitoLocal(tabla,ambito_local-1);
        ambito_local--;
        fprintf(salida, "cierre\n");
      }else if (num >= 0){
        /* Variable*/
        if (ambito_local > 0){
          if(insertarAmbitoLocal(tabla,identificador,num,ambito_local -1) == 0){
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
          ambito_local ++;
          if (aperturaAmbitoLocal(tabla,identificador,num,ambito_local-1) == 0){
            
            fprintf(salida, "%s\n",identificador);
          }else{
            fprintf(salida, "-1\t%s\n",identificador);
          }
        }
      
    }else if (identificador != NULL){
      simbolo = NULL;
      /* Buscar identificador */
      if (ambito_local == 0){
        simbolo = buscarAmbitoGlobal(tabla,identificador);
      }else if (ambito_local > 0){
        simbolo = buscarAmbitoLocal(tabla,identificador,ambito_local-1);

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
