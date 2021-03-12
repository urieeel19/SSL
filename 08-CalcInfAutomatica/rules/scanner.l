%{
/* scanner.l
 - Reglas léxicas y TOKENs. Compilable de Flex.
 - Rubin Uriel - UTN FRBA
 - 16/03/2021
*/

#include <stdlib.h> //atoi()
#include <stdio.h>  //printf()
#include <string.h>  //strcpy()
#include "token.h" //Incluyo el header generado por bison
#include "../inc/errors.h"
#include "../inc/types.h"

#define MAX(x, y) ((x > y) ? x : y)
#define MAX_NAME_LENGTH 10
#define MAX_CONSTANT_DIGITS 12
#define MAX_LEXEME_LENGTH MAX(MAX_NAME_LENGTH, MAX_CONSTANT_DIGITS)

void ValidarMaximoConstante(char*);
void ValidarMaximoIdentificador(char*);
#undef YY_DECL
#define YY_DECL number GetNextToken(void)
%}
%option noyywrap

%%      

[0-9]{1,30}              {
                        ValidarMaximoConstante(yytext);
                        yylval.value = atol(yytext);
                        return CONSTANTE;
                        }

[a-zA-Z][a-zA-Z | 0-9]{0,20}     {
                        ValidarMaximoIdentificador(yytext);
                        strcpy(yylval.name, yytext); //Copio a yylval lo que ingreso a yytext
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

.                       {
                        showError(ERROR_LEXICO);
                        }

%%

void ValidarMaximoConstante(char* entrada){
    if(strlen(entrada) > MAX_CONSTANT_DIGITS )
        showError(LONGITUD_MAXIMA_CONSTANTE);
}
void ValidarMaximoIdentificador(char* entrada){
    if (strlen(entrada) > MAX_NAME_LENGTH)
        showError(LONGITUD_MAXIMA_IDENTIFICADOR);
}

