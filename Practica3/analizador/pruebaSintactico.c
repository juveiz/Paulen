#include <stdio.h>
#include "tokens.h"

int yylex();
int yyparse();

void yyerror(const char * s) {
  extern long nline, ncolumn;
  extern int is_morpho;
  if (!is_morpho) {
    printf("****Error sintactico en [lin %ld, col %ld]\n", nline, ncolumn);
  }
}

int main(int argc, char const *argv[]) {
  extern FILE* yyin;
  extern FILE* out;
  extern char* yytext;
  extern int yyleng;
  extern long nline, ncolumn;
  extern int is_morpho;


  if (argc < 3){
    printf("No hay suficientes parametros.Programa entrada salida\n");
    return 1;
  }

  yyin = fopen(argv[1],"r");
  if (yyin == NULL){
    printf("Error al abrir el archivo entrada\n");
    return 1;
  }

  out = fopen(argv[2],"w");
  if (out == NULL){
    fclose(yyin);
    printf("Error al abrir el archivo salida\n");
    return 1;
  }

  if(yyparse()!=0) {
    if(is_morpho){
      fprintf(stderr, "****Error en [lin %li, col %li]: ", nline, ncolumn);
      if (yyleng > 100){
        fprintf(stderr, "identificador demasiado largo (%s)\n", yytext);
      }else{
        fprintf(stderr, "simbolo no permitido (%s)\n", yytext);
      }
    }
    fclose(yyin);
    fclose(out);
    return 1;
    }

  fclose(yyin);
  fclose(out);
  return 0;
}
