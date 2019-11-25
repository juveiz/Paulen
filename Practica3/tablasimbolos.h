#ifndef _TOKENS_H
#define _TOKENS_H

#include "uthash.h"
#include <stdio.h>

typedef struct _simboloTabla simboloTabla;

typedef struct _tablaSimbolos tablaSimbolos;


tablaSimbolos * createTablaSimbolos();

void deleteTablaSimbolos(tablaSimbolos * tabla);

simboloTabla * buscarAmbitoGlobal(tablaSimbolos * tabla, char * identificador);

simboloTabla * buscarAmbitoLocal(tablaSimbolos * tabla, char * identificador);

int insertarAmbitoGlobal(tablaSimbolos * tabla, char * identificador, int valor);

int insertarAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor);

int aperturaAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor);

void limpiarAmbitoLocal(tablaSimbolos * tabla);
#endif
