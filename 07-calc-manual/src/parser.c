#include "../inc/scanner.h"
#include "../inc/parser.h"
#include "../inc/memory.h"
#include "../inc/errors.h" // manejo de errores
#include <string.h>

TOKEN tok; //Token actual

//Prototipos de funciones privadas
static void Match(tipoDeToken);
void ListaSentencias(void);
void Sentencia(void);
void Definicion(void);
number Expresion(void);
number Termino(void);
number Factor(void);

//Definición de función pública
void Parser()
{
    ListaSentencias();
    Match(FDT);
    printf("[Parser] Finalizado de manera exitosa.");
}

//Definiciones de funciones privadas
void ListaSentencias()
{
    do
        Sentencia();
    while (GetNextToken().type != FDT);
}

void Sentencia()
{
    number resultado;
    switch (GetNextToken().type)
    {
    case DEFINICION:
        Match(DEFINICION);
        Definicion(); //Asocia valor a identificador.
        break;
    case IGUAL:
        Match(IGUAL);
        resultado = Expresion();
        if(resultado < 0)
            showError(DESBORDAMIENTO_DE_ENTERO);                //Expresión devuelve un resultado.
        printf("Resultado = %ld \n", (long)resultado); //Muestra resultado de la expresión.
        break;
    default:
        showError(ERROR_DE_SINTAXIS);
        break;
    }
    Match(FDS);
}

void Definicion()
{
    char auxName[MAX_NAME_LENGTH];
    Match(IDENTIFICADOR); //Matcheo IDENTIFICADOR
    strcpy(auxName, tok.data.name);
    Match(IGUAL);                    //Matcheo IGUAL
    Match(CONSTANTE);                //Matcheo CONSTANTE a ser asignada.
    Assign(auxName, tok.data.value); //Asignacion
}

number Expresion(void)
{
    number resultado = Termino();
    if (GetNextToken().type == SUMA)
    {
        Match(SUMA);
        resultado = resultado + Expresion();
    }
    return resultado;
}

number Termino(void)
{
    number resultado = Factor();
    if (GetNextToken().type == PRODUCTO)
    {
        Match(PRODUCTO);
        resultado = resultado * Termino();
    }
    return resultado;
}

number Factor(void)
{
    number resultado;
    switch (GetNextToken().type)
    {
    case IDENTIFICADOR:
        Match(IDENTIFICADOR);
        resultado = GetValue(tok.data.name);
        break;
    case CONSTANTE:
        Match(CONSTANTE);
        resultado = tok.data.value;
        break;
    case PARENIZQUIERDO:
        Match(PARENIZQUIERDO);
        resultado = Expresion();
        Match(PARENDERECHO);
        break;
    default:
        showError(ERROR_DE_SINTAXIS);
    }
    return resultado;
}

//--------------------------------------------------------------------
static void Match(tipoDeToken tipoEsperado)
{
    if ((tok = GetNextToken()).type != tipoEsperado)
    {
        showError(ERROR_DE_SINTAXIS);
    }
    keepLastToken = 0;
}
