#include "../inc/memory.h"
#include <stdio.h>  //printf
#include <string.h> //strcmp
#include "../inc/errors.h" // manejo de errores

// Declaración de variables
#define MEMORY_SIZE 200
unsigned memoryLastPosition = 0;
variable Memory[MEMORY_SIZE];

// Definición de funciones privadas para el manejo de memoria
unsigned GetPosition(char[]);

// GetPosition devuelve la posición si existe, sino, declara y devuelve esa posición.
unsigned GetPosition(char name[])
{
    for (unsigned i = 0; i <= memoryLastPosition; ++i)
    {
        if (strcmp(Memory[i].name, name) == 0)
        {
            return i;
        }
    }
    strcpy(Memory[memoryLastPosition].name, name);
    ++memoryLastPosition;
    return memoryLastPosition - 1;
}

// Assign le asigna a la posición pasada por parámetro el valor requerido.
void Assign(char name[], number value)
{
    int index = GetPosition(name);
    Memory[index].value = value;
}

//GetValue busca por nombre la variable y devuelve su valor.
number GetValue(char name[])
{
    for (unsigned i = 0; i <= memoryLastPosition; ++i)
    {
        if (strcmp(Memory[i].name, name) == 0)
        {
            return Memory[i].value;
        }
    }
    showError(VARIABLE_INEXISTENTE);
}