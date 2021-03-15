![](/08-CalcInfAutomatica/imgs/Banner.png)

---

**¿De qué trata este trabajo?** [Link al documento.](https://josemariasola.github.io/ssl/assignments/2020/Ssl%20Assignments.pdf#page=53)

---

# Tabla de Contenidos

- <!--ts-->

  - [Tabla de contenidos](#tabla-de-contenidos)
  - [Síntesis](#síntesis)
  - [Calculadora](#calculadora) - [Descripción del lenguaje utilizado](#descripción-del-lenguaje-utilizado) - [Scanner](#scanner) - [La función del analizador léxico](#la-funcion-del-analizador-lexico) - [Gramática Léxica](#gramática-léxica) - [Lista de tokens](#lista-de-tokens) - [Parser](#parser) - [Bison](#bison) - [La función del analizador sintáctico](#la-funcion-del-analizador-sintactico) - [Gramática Sintáctica](#gramática-sintáctica) - [Memoria](#memoria) - [Assign()](#assign) - [GetValue()](#getvalue) - [Makefile](#makefile) - [Compilación](#compilación) - [Test](#test) - [Clean](#clean) - [Códigos de errores](#errores) - [Inconvenientes encontrados](#inconvenientes-encontrados) - [Miro](#miro)
    <!--te-->

# Síntesis

Este trabajo práctico es un programa de consola desarrollado en lenguaje C, con herramientas como **Flex** y **Bison**, que permite realizar tanto el análisis léxico, y sintáctico de las distintas sentencias ingresadas por el usuario. Cuenta con un lenguaje propio, definido para poder realizar estas evaluaciones, y arroja un resultado preciso de la operación.

Otra funcionalidad con la que cuenta este programa es la de almacenar variables con sus relativos nombres en una “memoria”, pudiendo acceder a los valores asociados para realizar posteriormente la evaluación de la sentencia.

Cabe destacar que las variables tienen un maximo de 200 variables disponibles para usar.

- [Parser](#parser)
- [Scanner](#scanner)
- [Memory](#memoria)
- [Errors](#errores)
- [General](#general)

---

# Calculadora

## Descripción del lenguaje utilizado

- Operaciones en el dominio de los números Naturales incluyendo al 0.
- Todos los identificadores son declarados explícitamente y con una longitud máxima de N caracteres, cuyo N se puede definir previo a la compilación y que por default comienza en 10.
- Los identificadores deben comenzar con una letra y están compuestos de letras y dígitos.
- Las constantes son secuencias de hasta M dígitos, cuyo M se puede definir previo a la compilación y que por default comienza en 8.
- Hay dos tipos de sentencias:
  - **Definición** > Este tipo de sentencia almacena el valor pasado en una variable.
  - **Expresión** > Esta sentencia realiza la evaluación de una expresión simple o compuesta.
- Las variables ya existentes pueden modificar su valor. El procedimiento es el mismo que al definir una nueva variable.
- Cada sentencia termina con un ‘’ ; ‘’, el cual hace referencia a un token llamado “FDS” (Fin de sentencia). Para confirmar el ingreso de la sentencia se presiona “ENTER” ( “\n” ).
- El final de texto (FDT) será dado por el char ' ! '.

---

![](/08-CalcInfAutomatica/imgs/Banner1.png)

## Scanner

El **Scanner** es la sección del programa encargada de realizar el análisis léxico de las cadenas de caracteres que son ingresadas por el usuario.

### La función del Analizador Léxico `yylex()`

La función del analizador léxico, `yylex`, reconoce tokens desde el flujo de entrada y se los devuelve al analizador. Bison no crea esta función automáticamente; debe escribirse de manera que `yyparse` pueda llamarla.

En programas simples, `yylex` se define a menudo al final del archivo de la gramática de
Bison. En programas un poco más complejos, lo habitual es crear un programa en Flex
que genere automáticamente esta función y enlazar Flex y Bison.

### Gramática Léxica

```c
<token> -> uno de <identificador> <constante> <suma> <multiplicación> <igual> <definición> <fds> <fdt>
<identificador> -> <letra> {<letra o dígito>}
<constante> -> <dígito> {<dígito>}
<letra o dígito> -> uno de <letra> <dígito>
<letra> -> una de a-Z
<dígito> -> uno de 0-9
<suma> -> +
<multiplicación> -> *
<igual> -> =
<definición> -> $
<parenizquierdo> -> (
<parenderecho> -> )
<fds> -> ;
<fdt> -> !
```

La gramática léxica, junto a los `TOKEN` que corresponden, se especifican en el archivo `scanner.l` ubicado en la carpeta `rules\`.

```c
DIGIT [0-9]{1,30}
IDENTIFICADOR [a-zA-Z][a-zA-Z | 0-9]{0,30} 
      
{DIGIT}                 {
                        ValidarMaximoConstante();
                        yylval.value = atol(yytext);
                        return CONSTANTE;
                        }
{IDENTIFICADOR}         {
                        ValidarMaximoIdentificador();
                        strcpy(yylval.name, yytext); //Copio a yylval lo que ingreso a yytext
                        return IDENTIFICADOR;
                        }

\+                      return SUMA;
        
\*                      return PRODUCTO;

\$                      return DEFINICION;

\=                      return IGUAL;
                        
\;                      return FDS;

\(                      return PARENIZQUIERDO;

\)                      return PARENDERECHO;

\!                      return FDT;

[\s\t\n]                ;

.                       {
                        showError(ERROR_LEXICO);
                        }
```

### Lista de tokens

| En la entrada  | Nombre del Token |
| :------------- | ---------------- |
| =              | IGUAL            |
| (              | PARENIZQUIERDO   |
| )              | PARENDERECHO     |
| +              | SUMA             |
| \*             | MULTIPLICACION   |
| ;              | FDS              |
| $              | DEF              |
| !              | FDT              |
| val1 (ejemplo) | IDENTIFICADOR    |
| 123 (ejemplo)  | CONSTANTE        |

---

![](/08-CalcInfAutomatica/imgs/Banner2.png)

## Parser

El **Parser** es la sección del programa encargada de realizar el análisis sintáctico de las sentencias ingresadas. Trabaja abstrayéndose de los caracteres ingresados. Para esto utiliza **TOKENS**.

### Bison

El fuente de **Bison** se convierte en una función en C llamada `yyparse`. Aquí describimos las convenciones de interfaz de `yyparse` y las otras funciones que éste necesita usar.

Es necesario tener en cuenta que el analizador utiliza muchos identificadores en C comenzando con
‘yy’ e ‘YY’ para propósito interno.

Si utiliza tales identificadores (a parte de aquellos descritos en el manual) en una acción o en código C adicional en el archivo de la gramática, es probable que se encuentre con problemas.  

### La Función del Analizador `yyparse()`
Se llama a la función yyparse para hacer que el análisis comience. Esta función lee tokens, ejecuta acciones, y por último retorna cuando se encuentre con el final del fichero o un error de sintaxis del que no puede recuperarse. Usted puede también escribir acciones que ordenen a yyparse retornar inmediatamente sin leer más allá. 

El valor devuelto por yyparse es 0 si el análisis tuvo éxito (el retorno se debe al final del fichero). El valor es 1 si el análisis falló (el retorno es debido a un error de sintaxis). 

### Gramática Sintáctica

```c
<Parser>     -> <listaSentencias> FDT
              | FDT
<listaSentencias> -> Sentencia FDS { <Sentencia> FDS }
<Sentencia> -> DEF <Definición>
               IGUAL <Expresión>
<Definición> -> ID IGUAL CONSTANTE
<Expresión>  -> <Término>
              | <Expresión> SUMA <Término> 
<Término>    -> <Factor> 
              | <Término> MULTIPLICACION <Factor>
<Factor>     -> CONSTANTE
              | IDENTIFICADOR
              | PARENIZQUIERDO <Expresión> PARENDERECHO

```



---

![](/08-CalcInfAutomatica/imgs/Banner3.png)

## Memoria
Esta calculadora cuenta con la funcionalidad de almacenar en memoria variables con su nombre y valor correspondiente, este modulo trabajo con memoria estatica, es decir, su longitud maximo estan preestablecidos. Esto lo realiza gracias al código desarrollado en `memory.h` y `memory.c`. Donde están definidas las siguientes funciones:

- `void Assign(unsigned, int);`
- `int GetValue(char[]);`

---

### `Assign()`

Es la responsable de asignar a una posición su valor.

### `GetValue()`

Obtiene el valor de un nombre de memoria. Lo hace iterando el array y retorna su valor para ser operado en una evaluación. En caso de no existir el nombre buscado en memoria, muestra un mensaje de error ( [Ver tabla de errores](#errores)) y sale del programa.
---

![](/08-CalcInfAutomatica/imgs/Banner5.png)

## Makefile

A la hora de querer ejecutar nuestro programa en nuestro PC, debemos abrir la terminal del sistema en la carpeta con el siguiente path:

```
08-CalcInfAutomatica/src/
```

Aquí dentro se encuentra junto a los archivos con extensión `.c`, otro llamado `makefile` el cuál a través de unas rutinas ya definidas en él, nos permitirá tanto compilar, testear y limpiar el repositorio del proyecto.

### Compilación

Para proceder a la compilación de los archivos necesarios, debemos ejecutar el comando `make` desde la línea de comandos, lo que iniciará la rutina por default llamada `TARGET`, que se encarga de compilar el programa, dejando como producto el ejecutable del mismo en la siguiente ubicación:

```
08-CalcInfAutomatica/bin/
```

Como _ventaja_ de realizar la compilación a través de este método, obtenemos un mejor tiempo de compilación a la hora de estar realizando cambios en algunos de los archivos del proyecto. Gracias a la comparación que realiza `make` de los archivos `.o`, es posible compilar únicamente los archivos que fueron modificados y no recompilar el proyecto desde 0.

### Test

La rutina que se ejecuta con el comando `make test`, nos permite con un input preestablecido en el archivo `entrada.txt` ubicado en la carpeta `/test`, obtener una salida que será escrita en `obtenido.txt` la cual posteriormente será comparada automáticamente utilizando el comando `diff`. Este nos advierte si encuentra una diferencia entre `obtenido.txt` y `esperado.txt`. Dándonos la posibilidad de identificar en caso de que falle, dónde lo está haciendo.

### Clean

Utilizaremos el comando `make clean` para limpiar de nuestro repositorio los archivos `.o`, `.d` y `.exe`.

### Run

Por último, utilizaremos el comando `make run` para ejecutar directamente el archivo `Calculadora.exe` y realizar la entrada manual sentencias..

### Errores
Los errores estas definidos en una enumeracion para una mejor claridad del codigo al ser compartido con otro desarrollador.

| Código de error | Descripción                                                  |
| --------------- | ------------------------------------------------------------ |
| VARIABLE_INEXISTENTE               | [Memory] No existe esa variable en la memoria. |
| ERROR_DE_SINTAXIS               | [Parser] Error en la sintaxis. |
| ERROR_LEXICO               | [Scanner] El caracter no pertenece al alfabeto soportado. |
| LONGITUD_MAXIMA_LEXEME               | [Scanner] La longitud del LEXEMA es demasiada larga.              |
| LONGITUD_MAXIMA_IDENTIFICADOR               | [Scanner] La longitud del IDENTIFICIADOR es demasiada larga. |
| LONGITUD_MAXIMA_CONSTANTE               | [Scanner] La longitud de la CONSTANTE es demasiada larga. |
| DESBORDAMIENTO_DE_ENTERO               | El resultado de la operación supera al valor maximo.              |
---

![](/08-CalcInfAutomatica/imgs/Banner4.png)

## Inconvenientes encontrados

A la hora de encontrarnos con algunos problemas ya sean lógicos, conceptuales, o de cualquier otro tipo, recurrimos a la discusión de los mismos y el uso de herramientas gráficas para buscar una posible solución de una manera más fácil.

Para ello utilizamos tanto _OneNote_ como _Miró_.

Pueden acceder a la pizarra de _Miró_ a través del siguiente link: [Link al documento.](https://miro.com/app/board/o9J_lZ_aUhE=/)

![](/08-CalcInfAutomatica/imgs/Miro.jpg)
