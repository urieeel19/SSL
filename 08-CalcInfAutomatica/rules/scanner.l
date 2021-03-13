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
#include "../inc/general.h"


#undef YY_DECL
#define YY_DECL number GetNextToken(void)

void ValidarMaximoConstante();
void ValidarMaximoIdentificador();
%}
%option noyywrap 
DIGIT [0-9]{1,12}
IDENTIFICADOR [a-zA-Z][a-zA-Z | 0-9]{0,10} 
%%      
{DIGIT}                 {
                        ValidarMaximoConstante();
                        yylval.value = atol(yytext);
                        return CONSTANTE;
                        }
{IDENTIFICADOR}         {
                        ValidarMaximoIdentificador();
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

void ValidarMaximoConstante(){
    if(yyleng > MAX_CONSTANT_DIGITS )
        showError(LONGITUD_MAXIMA_CONSTANTE);
}
void ValidarMaximoIdentificador(){
    if (yyleng > MAX_NAME_LENGTH)
        showError(LONGITUD_MAXIMA_IDENTIFICADOR);
}

