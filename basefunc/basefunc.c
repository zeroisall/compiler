#include <stdio.h>
#include <stdlib.h>
#include "basefunc.h"

void Error(const char *info, const int level)
{
    if (1 == level) // stop routine
    {
        fprintf(stderr, "%s", info);
        exit(EXIT_FAILURE);
    }
    else if (2 == level)
    {
        fprintf(stderr, "%s", info);
        while (1)
        {
            /* code */
        }
    }
    else
    {
    }
    return;
}

// open given file with given mode("r","w"...)
FILE *OpenFile(const char *file, const char *mode)
{
    FILE *pf = fopen(file, mode);
    if (NULL == pf)
    {
        ERROR("fail to open file\n", 2);
    }
    else
    {
        return pf;
    }
}

void CloseFile(FILE *pf)
{
    int rt;
    if (NULL == pf)
    {
        ERROR("invalid input para in func CloseFile\n");
    }

    rt = fclose(pf);
    if (EOF == rt)
    {
        ERROR("fail to close file in func CloseFile\n");
    }
    return;
}

size_t GetFileSize(FILE *pf)
{
    if (NULL == pf)
    {
        ERROR("invalid input para in func CloseFile\n");
    }

    size_t filelen;
    fseek(pf, 0, SEEK_END);
    filelen = ftell(pf);
    fseek(pf, 0, SEEK_SET);
}

char *AllocMem(size_t memlen)
{
    char *pmem;
    pmem = NULL;
    pmem = (char *)malloc(memlen);
    if (NULL == pmem)
    {
        ERROR("fail malloc memory\n");
    }
    else
    {
        return pmem;
    }
}
void FreeMem(char *pmem)
{
    if (NULL == pmem)
    {
        ERROR("fail malloc memory\n");
    }
    else
    {
        free(pmem);
    }

    return;
}

// main for module test
#ifndef MOD_USE
int main(void)
{
    printf("%s %s %s\n", __FILE__, __DATE__, __TIME__);
    FILE *pf = OpenFile("t", "r");
    return 0;
}
#endif