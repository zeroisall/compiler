#include "defs.h"
#include "data.h"
#include "decl.h"
static int aaa=2;
// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c)
{
    char *p;

    p = strchr(s, c);
    return (p ? p - s : -1);
}

// Put back an unwanted character
static void putback(int c)
{
    Putback = c;
}

// Get the next character from the input file.
static int next(void)
{
    int c;

    if (Putback)
    {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if ('\n' == c)
    {
        Line++;
    }

    return c;
}

// skip whitespace newlines and so on that we don't need
static int skip(void)
{
    int c;

    c = next();
    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
    {
        c = next();
    }

    return c;
}

// Scan and return an integer literal
// value from the input file. Store
// the value as a string in Text.
static int scanint(int c)
{
    int k, val = 0;

    // Convert each character into an int value
    while ((k = chrpos("0123456789", c)) >= 0)
    {
        val = val * 10 + k;
        c = next();
    }

    // We hit a non-integer character, put it back.
    putback(c);
    return val;
}

// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.
int scan(TOKEN *t)
{
    int c;

    c = skip();
    switch (c)
    {
    case EOF:
        return 0;
        break;
    case '+':
        t->token = T_PLUS;
        break;
    case '-':
        t->token = T_MINUS;
        break;
    case '*':
        t->token = T_STAR;
        break;
    case '/':
        t->token = T_SLASH;
        break;
    default:
        // If it's a digit, scan the
        // literal integer value
        if (isdigit(c))
        {
            t->intvalue = scanint(c);
            t->token = T_INTLIT;
            break;
        }
        else
        {
            printf("Unrecognised character %c on line %d\n", c, Line);
            exit(1);
        }
    }

    return 1;
}
