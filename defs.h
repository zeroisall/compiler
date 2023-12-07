#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// tokens
enum etoken
{
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT
};

// token struct
typedef struct token
{
    int token;
    int intvalue;
} TOKEN;