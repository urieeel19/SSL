#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

char tablaDeErrores[][100] = {
    "[Memory] No existe esa variable en la memoria",
    "[Parser] Error en la sintaxis.",
    "[Scanner] El caracter no pertenece al alfabeto soportado.",
    "[Scanner] La longitud del LEXEMA es demasiada larga.",
    "[Scanner] La longitud del IDENTIFICIADOR es demasiada larga.",
    "[Scanner] La longitud de la CONSTANTE es demasiada larga.",
    "[Memory] El resultado de la operación supera al valor maximo."
};

void showError(Errors numError)
{   
    printf("\n\nCódigo de error: %d\nMensaje: %s\n\n",numError, tablaDeErrores[numError]);
    exit(EXIT_FAILURE);
}