#include "tablasimbolos.h"

typedef struct _simboloTabla{
    char * identificador;
    int valor;
    UT_hash_handle hh;
} simboloTabla;

typedef struct _tablaSimbolos{
  simboloTabla ** global;
  simboloTabla ** local;
} tablaSimbolos;

/*Funciones para simboloTabla*/
char * getIdentificador(simboloTabla * simbolo){
  return simbolo->identificador;
}

int getValor(simboloTabla * simbolo){
  return simbolo->valor;
}

simboloTabla *find_simbolo(simboloTabla ** tabla, char * identificador) {
    simboloTabla *s;
    if (*tabla == NULL){
      return NULL;
    }
    HASH_FIND_STR( *tabla, identificador, s);
    return s;
}

int add_simbolo(simboloTabla ** tabla, char * identificador, int valor) {
  simboloTabla * elemento;

  if (find_simbolo(tabla, identificador) != NULL ) return -1;

  elemento = (simboloTabla *) malloc(sizeof(simboloTabla));
  if(elemento == NULL) return -1;

  elemento->identificador = (char *) malloc(sizeof(char)*(strlen(identificador) + 1));
  if(elemento->identificador == NULL){
    free(elemento);
    return -1;
  }
  strcpy(elemento->identificador, identificador);
  elemento->valor = valor;

  HASH_ADD_STR(*tabla, identificador, elemento);



  return 0;
}

void delete_simbolo(simboloTabla ** tabla, simboloTabla * elemento) {
    HASH_DEL(*tabla, elemento);
    free(elemento);
}

void delete_all(simboloTabla ** tabla) {
  simboloTabla *elemento, *tmp;

  HASH_ITER(hh, *tabla, elemento, tmp) {
    HASH_DEL( *tabla,elemento);
    free(elemento->identificador);
    free(elemento);
  }
}

/*Funciones para tablaSimbolos*/
tablaSimbolos * createTablaSimbolos(){
  tablaSimbolos * tabla;

  tabla = (tablaSimbolos *) malloc(sizeof(tablaSimbolos));
  if(tabla == NULL) return NULL;

  tabla->global = (simboloTabla ** ) malloc(sizeof(simboloTabla *));
  if(tabla->global == NULL) {
    free(tabla);
    return NULL;
  }

  tabla->local = (simboloTabla ** ) malloc(sizeof(simboloTabla *));
  if(tabla->local == NULL) {
    free(tabla->global);
    free(tabla);
    return NULL;
  }

  *(tabla->global) = NULL;
  *(tabla->local) = NULL;
  return tabla;
}

void deleteTablaSimbolos(tablaSimbolos * tabla) {
  delete_all(tabla->global);
  free(tabla->global);
  delete_all(tabla->local);
  free(tabla->local);
  free(tabla);
}

simboloTabla * buscarAmbitoGlobal(tablaSimbolos * tabla, char * identificador){
  return find_simbolo(tabla->global, identificador);
}

simboloTabla * buscarAmbitoLocal(tablaSimbolos * tabla, char * identificador){
  simboloTabla * s;
  s = find_simbolo(tabla->local, identificador);
  if( s == NULL)
    return find_simbolo(tabla->global, identificador);

  return s;
}

int insertarAmbitoGlobal(tablaSimbolos * tabla, char * identificador, int valor){
  return add_simbolo(tabla->global, identificador, valor);
}

int insertarAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor){
  return add_simbolo(tabla->local, identificador, valor);
}

int aperturaAmbitoLocal(tablaSimbolos * tabla, char * identificador, int valor){
  if(insertarAmbitoGlobal(tabla,identificador, valor) == -1) return -1;
  if(insertarAmbitoLocal(tabla, identificador, valor) == -1){
    delete_simbolo(tabla->global, find_simbolo(tabla->global, identificador));
    return -1;
  }
  return 0;
}

void limpiarAmbitoLocal(tablaSimbolos * tabla){
  delete_all(tabla->local);
  *(tabla->local)=NULL;
}
