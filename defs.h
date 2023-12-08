#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "basefunc.h"

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

// global variable
//*note 多个文件都包含此语句，只有一个文件是定义，
//*note 其他的都是隐式extern,因此此处不能赋值
TOKEN *ptoken;
size_t g_tokennum;
FILE *pFile;
size_t LineNum;

extern void ScanFile(const char *file);