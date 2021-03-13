#ifndef SCANNER_H
#define SCANNER_H
#include "general.h"

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