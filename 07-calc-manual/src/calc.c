//https://miro.com/app/board/o9J_lZ_aUhE=/
//Link al miro

#include <stdio.h> //printf
#include <stdlib.h> //system
#include "parser.h"

int main()
{
    /* system("cls");
    printf("\t\t%c%c CALCULADORA MANUAL INFIJA %c%c\n\n", 45, 45, 45, 45);
    printf("%c Diccionario%c", 45, 58);

    printf("\n\t %c%c%c %c Asignar", 39, 61, 39, 175);
    printf("\n\t %c%c%c %c Sumar", 39, 43, 39, 175);
    printf("\n\t %c%c%c %c Multiplicar", 39, 42, 39, 175);
    printf("\n\t %c%c%c %c Apertura de bloque", 39, 40, 39, 175);
    printf("\n\t %c%c%c %c Cierre de bloque", 39, 41, 39, 175);
    printf("\n\t %c%c%c %c Definir variable", 39, 36, 39, 175);
    printf("\n\t %c%c%c %c Marcar el final de sentencia", 39, 59, 39, 175);
    printf("\n\t %c%c%c %c Fin del programa", 39, 33, 39, 175);
    printf("\n\n%c Ejemplo de sentencias v%clidas%c", 45, 160, 58);
    printf("\n\t\t%cnum%c3%c", 36, 61, 59);
    printf("\n\t\tnum%c10%c", 43, 59);
    printf("\n\t\t10%c%c3%cnum%c%c", 42, 40, 43, 41, 59);

    printf("\n\n%c Ingrese sentencias%c \n\n", 45, 58); */
    Parser();
}


/*
Léxico: Categorías léxicas o Tokens (LR)
Sintáctico: Categorías sintácticas (LIC)

Una GIC es apropiada para balancear símbolos, por
ejemplo, paréntesis

Identificador → Letra |
                Identificador Letra |
                Identificador GuionBajo Letra

Se dice que la gramática es recursiva a
izquierda porque el no terminal de la
izquierda aparece a la izquierda en la parte
derecha de la producción

Análisis Sintáctico Descendente Recursivo” (ASDR)
Un ASDR es un parser del tipo top-down, es decir, parte del axioma y
va armando el Árbol de Análisis Sintáctico (AAS) con derivación a izquierda.

El AAS queda de modo tal que en las hojas están los terminales y en
los nodos interiores los no terminales.

IMPORTANTE: Match pertenece al scanner y es la única que
hace avanzar mismo

Determinar si una GIC es ambigua es un problema indecidible, es decir, no existe algoritmo que tomando
cualquier GIC conteste por si o no.
Para demostrar que es ambigua basta con encontrar una
cadena que admita dos árboles de derivación diferentes.
*/

/*
Cosa a hacer:
-En la gramatica lexica y sintatica expresarlo como regex y muchnick
-Agregar caso de prueba cuando supera el maximo
-Validar que pasa si el nombre de la variable supera el maximo.
-Detallar en el readme los caminos invalidos, strcopy falle.
-Mejorar la parte del flag keepLastToken

despues del match identificador, guardar el nombre en una variable auxiliar.
entonces la funcion assing recibe el nombre y ahi implemento la logica de asignar el valor a la posicion
-la variable keepLastToken no es necesaria delcrarla como extern
*/