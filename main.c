#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

//! 此main函数作为scan模块的测试函数
//!  We will start with a language that has only five lexical elements

static void init()
{
    Line = 1;
    Putback = '\n';
}

// Print out a usage if started incorrectly
static void usage(char *prog)
{
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(EXIT_FAILURE);
    return;
}

// List of printable tokens
char *tokstr[] = {"+", "-", "*", "/", "intlit"};

// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static void scanfile()
{
    struct token T;

    while (scan(&T))
    {
        printf("Token %s", tokstr[T.token]);
        if (T.token == T_INTLIT)
            printf(", value %d", T.intvalue);
        printf("\n");
    }
}
static int skip(void)
{
    return 1;
}

int aaa=1;

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        usage(argv[0]);
    }

    init();
    
    if ((Infile = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }
    scanfile();
    return 1;
}