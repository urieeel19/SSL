### Trabajo #6 - Operaciones de Strings

Este trabajo tiene dos partes, una de análisis comparativo y otra de desarrollo.
El análisis comparativo es sobre el tipo de dato String en el lenguaje de programación C versus otro lenguaje de programación a elección; mientras que el desarrollo está basado en los ejercicios 20 y 21 del Capítulo #1 del Volumen #1 de [MUCH2012], que a continuación transcribe:

``` Investigue y construya, en LENGUAJE C, la función que realiza cada operación solicitada:
Ejercicio 20
* (a) Calcula la longitud de una cadena;
* (b) Determina si una cadena dada es vacía.
* (c) Concatena dos cadenas.
 Ejercicio 20
Construya un programa de testeo para cada función del ejercicio anterior.
```
## Objetivos

1. **Parte I** — Análisis Comparativo del tipo String en Lenguajes de Programación:
Realizar un análisis comparativo de dato String en el lenguaje C versus un
lenguaje de programación a elección. El análisis debe contener, por lo menos,
los siguientes ítems:

1. ¿El tipo es parte del lenguaje en algún nivel?
2. ¿El tipo es parte de la biblioteca?
3. ¿Qué alfabeto usa?
4. ¿Cómo se resuelve la alocación de memoria?
5. ¿El tipo tiene mutabilidad o es inmutable?
6. ¿El tipo es un first class citizen?
7. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos?
8. ¿Y cuando son retornados por una función?

Las anteriores preguntas son disparadores para realizar una análisis profundo.
2. **Parte II** — Biblioteca para el Tipo String: Desarrollar una biblioteca con las siguientes operaciones de strings:
1. GetLength ó GetLongitud
2. IsEmpty ó IsVacía
3. Power ó Potenciar
4. Una operación a definir libremente.

Notar que en vez de la operación concatenar que propone [MUCH2012] se debe desarrollar Power ó Potenciar que repite un string n veces.
La parte pública de la biblioteca se desarrolla en el header "String.h" , el cual no debe incluir <string.h> . El programa que prueba la biblioteca, por supuesto, incluye a "String.h" , pero sí puede incluir <string.h> para facilitar las comparaciones.

## Temas
* Strings.
* Alocación.
* Tipos.

## Tareas
1. Parte I
a. Escribir el AnálisisComparativo.md con la comparación de strings en C versus otro lenguaje de programación a elección.

2. Parte II
a.Para cada operación, escribir en Strings.md la especificación matemática de la operación, con conjuntos de salida y de llegada, y con especificación de la operación.
b. Escribir el Makefile .
c. Por cada operación:
i. Escribir las pruebas en StringsTest.c .
ii. Escribir los prototipos en String.h .
iii. Escribir en String.h comentarios con las precondiciones y poscondiciones de cada función, arriba de cada prototipo.
iv. Escribir las implementaciones en Strings.c .

## Restricciones

* Las pruebas deben utilizar assert .
* Los proptotipos de utilizar const cuando corresponde.
* Por lo menos una operación debe implementarse con recursividad.
* Las implementaciones no deben utilizar funciones estándar, declaradas en <string.h>

## Productos
DD-Strings
|-- readme.md
|-- AnálisisComparativo.md
|-- String.md
|-- Makefile
|-- StringTest.c
|-- String.h
`-- String.c.
