#define MAX(x, y) ((x > y) ? x : y)
#define MAX_NAME_LENGTH 10
#define MAX_CONSTANT_DIGITS 8
#define MAX_LEXEME_LENGTH MAX(MAX_NAME_LENGTH, MAX_CONSTANT_DIGITS)
typedef int number;
/*
valor maximo de int = 2147483647
valor maximo de long int = 9223372036854775807
en limits.h estan definidos los limties
*/