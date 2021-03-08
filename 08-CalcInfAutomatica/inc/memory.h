#define MEMORY_SIZE 200

#ifndef MEMORY_H
#define MEMORY_H

// Definición de la estructura variable
typedef struct variable
{
    char name[10];
    int value;
} variable;

#endif

// Prototipos de funciones públicas para el manejo de memoria.
void Assign(char*, int);
int GetValue(char[]);
