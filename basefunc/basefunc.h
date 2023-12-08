#include<stdlib.h>
// if 1
#ifndef BASEFUNC_H
// set 0
#define BASEFUNC_H
    extern void Error(const char *info, const int level);
    #define ERROR(str,...) Error(str,(1,##__VA_ARGS__)) 

    extern FILE *OpenFile(const char *file, const char *mode);
    extern size_t GetFileSize(FILE *pf);
    extern void CloseFile(FILE *pf);
    extern char *AllocMem(size_t memlen);
    extern void FreeMem(char *pmem);
#endif