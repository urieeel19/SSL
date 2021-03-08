%{
/* scanner.l
 - Reglas léxicas y TOKENs. Compilable de Flex.
 - Rubin Uriel - 1438724 - UTN FRBA
 - 04/03/2021
*/

#include <stdlib.h> //atoi()
#include <stdio.h>  //printf()
#include <string.h>  //strcpy()
#include "token.h" //Incluyo el header generado por bison
#define MAX_NAME_LENGTH 20
#undef YY_DECL
#define YY_DECL int GetNextToken(void)
YY_DECL;
void AddBuffer();
%}
%option noyywrap

%%

[0-9]+                  {
                        yylval.value = atoi(yytext);
                        return CONSTANTE;
                        }

[a-zA-Z][a-zA-Z | 0-9]*  {
                        AddBuffer(); //Copio a yylval lo que ingreso a yytext
                        return IDENTIFICADOR;
                        }

\+                      return SUMA;
        
\*                      return PRODUCTO;

\$                      return DEFINICION;

\=                      return IGUAL;
                        
\;                      return FDS;

\(                      return PARENIZQUIERDO;

\)                      return PARENDERECHO;

\!                      return FDT;

[\s\t\n]                ;

.                       return NAT;

%%

void AddBuffer()
{
    if(strlen(yytext) > MAX_NAME_LENGTH)
        exit(5);
    else
        strcpy(yylval.name, yytext);
}