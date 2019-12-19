%{
#include "alfa.h"
FILE* out;
long nline = 1, ncolumn = 1;
int is_morpho = 0;
extern YYSTYPE yylval;
%}
%option noyywrap
puntoycoma ";"
coma ","
parentesisizquierdo "("
parentesisderecho ")"
corcheteizquierdo "["
corchetederecho "]"
llaveizquierda "{"
llavederecha "}"
asignacion "="
mas "+"
menos "-"
division "/"
asterisco "*"
and "&&"
or "||"
not "!"
igual "=="
distinto "!="
menorigual "<="
mayorigual ">="
menor "<"
mayor ">"

%%
"//".* {ncolumn+=yyleng; }

main { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MAIN;}
int { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_INT; }
boolean { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_BOOLEAN;}
array { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_ARRAY; }
function { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_FUNCTION;}
if { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_IF; }
else { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_ELSE;}
while { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_WHILE; }
scanf { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_SCANF;}
printf { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_PRINTF; }
return { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_RETURN;}

{puntoycoma} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_PUNTOYCOMA; }
{coma} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_COMA; }
{parentesisizquierdo} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_PARENTESISIZQUIERDO; }
{parentesisderecho} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_PARENTESISDERECHO; }
{corcheteizquierdo} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_CORCHETEIZQUIERDO; }
{corchetederecho} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_CORCHETEDERECHO; }
{llaveizquierda} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_LLAVEIZQUIERDA; }
{llavederecha} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_LLAVEDERECHA; }
{asignacion} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_ASIGNACION; }
{mas} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MAS; }
{menos} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MENOS; }
{division} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_DIVISION; }
{asterisco} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_ASTERISCO; }
{and} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_AND; }
{or} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_OR; }
{not} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_NOT; }
{igual} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_IGUAL; }
{distinto} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_DISTINTO; }
{menorigual} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MENORIGUAL; }
{mayorigual} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MAYORIGUAL; }
{menor} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MENOR; }
{mayor} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_MAYOR; }

true { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_TRUE; }
false { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng; return TOK_FALSE; }

\n { nline++; ncolumn = 1;}
\t { ncolumn+=yyleng; }
" " { ncolumn+=yyleng; }

[a-zA-Z][a-zA-Z0-9]{0,99} { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng;
                            strcpy(yylval.atributos.lexema,yytext);
                            return TOK_IDENTIFICADOR; }
[a-zA-Z][a-zA-Z0-9]{100,} { is_morpho = 1; return TOK_ERROR;}
[0-9]+ { fprintf(out,";D:\t%s\n", yytext); ncolumn+=yyleng;
          yylval.atributos.valor_entero = atoi(yytext);
          return TOK_CONSTANTE_ENTERA; }

. { is_morpho = 1; return TOK_ERROR; }
%%
