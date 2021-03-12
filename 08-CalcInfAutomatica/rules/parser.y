%{
/* parser.y
 - Reglas sintácticas, producciones. Compilable de Bison.
 - Rubin Uriel - UTN FRBA
 - 16/03/2021
*/

#include "memory.h"
#include "scanner.h"
#include "parser.h"
#include <stdio.h> //printf
#include <stdlib.h> 
#include "../inc/errors.h"
#include "../inc/types.h"


#define MAX_LEXEME_LENGTH MAX(MAX_NAME_LENGTH, MAX_CONSTANT_DIGITS)
/* Prototipos de funciones privadas */
static void mostrarResultado(number);
static number yylex();
static void yyerror(char *);

%}

%union 
{
  int value;
  char name[21];
}

/* Definición de tokens */
%token <value> CONSTANTE
%token <name> IDENTIFICADOR
%token SUMA
%token PRODUCTO
%token IGUAL
%token DEFINICION
%token FDS
%token FDT
%token NAT
%token PARENDERECHO
%token PARENIZQUIERDO
/* Definición de no-terminales */
%type <value> definicion
%type <value> expresion
%type <value> termino
%type <value> factor
%start parser

%%
parser: listaSentencias FDT { YYACCEPT;}
      | FDT{ YYACCEPT;}
;

listaSentencias: sentencia FDS
          | sentencia FDS listaSentencias
;

sentencia: DEFINICION definicion
         | IGUAL expresion { mostrarResultado($2); }
;

definicion: IDENTIFICADOR IGUAL CONSTANTE { Assign($1, $3); }

expresion: termino { $$ = $1; }
         | expresion SUMA termino { $$ = $1 + $3; }
;

termino: factor { $$ = $1; }
       | termino PRODUCTO factor { $$ = $1 * $3; }
;

factor: IDENTIFICADOR { int aux = GetValue($1); $$=aux;}
      | CONSTANTE { $$ = $1; }
      | PARENIZQUIERDO expresion PARENDERECHO { $$ = $2; }
;

%%

/* Definición de funciones privadas */
// yyerror es utilizada para mostrar que ocurrió un error y cerrar el programa.
void yyerror(char * stringError){
  showError(atoi( stringError ));
}

number yylex(void){   
    return GetNextToken();
}

/* Definición de funciones públicas */
// Definición de Parser()
void Parser(void){
  switch(yyparse()){
    case 0:
      return;
    default:
      yyerror("1");
      return;
  }
}
// yyparse lee tokens y ejecuta acciones. Retorna al matchear FDT

// mostrarResultado imprime por pantalla el resultado de la expresión parseada.
static void mostrarResultado(number valor) {
    printf("Resultado: %ld\n", (long)valor);
}   
