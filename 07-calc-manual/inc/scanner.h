#ifndef SCANNER_H
#define SCANNER_H
#include "types.h"

#define MAX(x, y) ((x > y) ? x : y)
#define MAX_NAME_LENGTH 10
#define MAX_CONSTANT_DIGITS 8
#define MAX_LEXEME_LENGTH MAX(MAX_NAME_LENGTH, MAX_CONSTANT_DIGITS)
// Definición de flag público
int keepLastToken;


// Definición tipoDeToken
typedef enum
{
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