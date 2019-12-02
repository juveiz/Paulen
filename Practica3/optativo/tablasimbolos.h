#ifndef _TOKENS_H
#define _TOKENS_H

#include "uthash.h"
#include <stdio.h>

#define TABLA_SIMBOLOS_LOCAL_NIVELES    5

typedef struct _simboloTabla simboloTabla;

typedef struct _tablaSimbolos tablaSimbolos;

char * getIdentificador(simboloTabla * simbolo);

int getValor(simboloTabla * simbolo);

tablaSimbolos * createTablaSimbolos();

void deleteTablaSimbolos(tablaSimbolos * tabla);

simboloTabla * buscarAmbitoGlobal(tablaSimbolos * tabla, char * identificador);

simboloTabla * buscarAmbitoLocal(tablaSimbolos * tabla, char * identificador, int indice);

int insertarAmbitoGlobal(tablaSimbolos * tabla, char * identificador, int valor);

int insertarAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor, int indice);

int aperturaAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor, int indice);

void limpiarAmbitoLocal(tablaSimbolos * tabla, int indice);
#endif
