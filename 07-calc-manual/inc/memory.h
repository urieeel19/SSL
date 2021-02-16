#define MEMORY_SIZE 200
#define VARIABLE_SIZE 10

#ifndef MEMORY_H
#define MEMORY_H

// Declaracion de la memoria
//extern int memoryLastPosition;
struct variable
{
    char name[VARIABLE_SIZE];
    int value;
};

typedef struct variable variable;

#endif

//FUNCIONES PARA MANEJO DE MEMORIA
unsigned GetPosition(char[]);
void Assign(unsigned, int);
int GetValue(char[]);

//FUNCIONES PARA DEBUG
void mostrarMemoria();
