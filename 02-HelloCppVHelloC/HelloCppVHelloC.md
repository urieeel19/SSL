# Trabajo #2 - Niveles del Lenguaje: Hello.cpp v Hello.c
### Objetivo
* Analizar e identificar las diferencias entre hello.cpp y hello.c, en los tres niveles: léxico, sintáctico, y semántico.

### Hello.c

`#include <stdio.h>`<br/>
`int main(){`<br/>
`printf("Hello, World!\n");`<br/>
`}`<br/>
  
### Hello.cpp

`#include <iostream>`<br/>
`int main(){`<br/>
 `std::cout << "Hello, World!";`<br/>
`}`<br/>

### Comparación


|           | Hello.c  | Hello.cpp | Observaciones                                                |   |
|-----------|----------|-----------|--------------------------------------------------------------|---|
|  Lexico   | No existe el ::         |           |                                                              |   |
| Sintaxis  | Expresion subfijo         | Expression infijo           | La sintaxis de C en C++ es permitida, viceversa no           |   |
| Semantica | Invocacion a funcion printf() |Pedido de insercion cout <<   | printf es una funcion, cout una clase, y C no soporta clases |   |
