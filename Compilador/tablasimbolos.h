#ifndef _TOKENS_H
#define _TOKENS_H

#include "uthash.h"
#include <stdio.h>
#include "alfa.h"

typedef struct _simboloTabla simboloTabla;

typedef struct _tablaSimbolos tablaSimbolos;

char * getIdentificador(simboloTabla * simbolo);

SIMBOLO * getValor(simboloTabla * simbolo);

CATEGORIA_SIMBOLO getCategoriaSimbolo(simboloTabla * simbolo);

CATEGORIA getCategoria(simboloTabla * simbolo);

tablaSimbolos * createTablaSimbolos();

void deleteTablaSimbolos(tablaSimbolos * tabla);

simboloTabla * buscarAmbitoGlobal(tablaSimbolos * tabla, char * identificador);

simboloTabla * buscarAmbitoLocal(tablaSimbolos * tabla, char * identificador);

int insertarAmbitoGlobal(tablaSimbolos * tabla, char * identificador, SIMBOLO * valor);

int insertarAmbitoLocal(tablaSimbolos * tabla, char * identificador, SIMBOLO * valor);

int aperturaAmbitoLocal(tablaSimbolos * tabla, char * identificador, SIMBOLO * valor);

void limpiarAmbitoLocal(tablaSimbolos * tabla);
#endif
