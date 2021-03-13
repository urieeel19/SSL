#define MAX_NAME_LENGTH 10

#ifndef MEMORY_H
#define MEMORY_H

#include "general.h"
// Definición de la estructura variable
typedef struct variable
{
    char name[MAX_NAME_LENGTH];
    number value;
} variable;

#endif

// Prototipos de funciones públicas para el manejo de memoria.
void Assign(char[], number);
number GetValue(char[]);