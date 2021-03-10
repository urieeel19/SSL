#ifndef SCANNER_H
#define SCANNER_H
#include "types.h"

#define MAX(x, y) ((x > y) ? x : y)
#define MAX_NAME_LENGTH 21
#define MAX_CONSTANT_DIGITS 30
#define MAX_LEXEME_LENGTH MAX(MAX_NAME_LENGTH, MAX_CONSTANT_DIGITS)
#define MAX_VALUE_INTEGER 2147483647
// Definición de flag público
int keepLastToken;


// Definición tipoDeToken
typedef enum
{
    NAT,
    INICIO,
    FIN,
    IDENTIFICADOR,
    CONSTANTE,
    IGUAL,
    PARENIZQUIERDO,
    PARENDERECHO,
    SUMA,
    PRODUCTO,
    DEFINICION,
    FDS,
    FDT
} tipoDeToken;

// Definición de la estructura TOKEN
typedef struct TOKEN
{
    tipoDeToken type; //Tipo
    union             //string o number
    {
        char name[MAX_NAME_LENGTH];
        number value;
    } data;
} TOKEN;

// Prototipo de funciones públicas
// Función que se encarga de devolver los TOKENs según lo que el scanner analiza.
TOKEN GetNextToken(void);
#endif