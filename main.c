#include "defs.h"

void init()
{
    LineNum = 0;
    pFile = NULL;
    ptoken = NULL;
    g_tokennum = 0;
    
    return;
}

int main(int argc, char *argv[])
{
    // make sure the routine is compiled and run corretly
    fprintf(stdout, "main running %s %s\n", __DATE__, __TIME__);

    // funciton input check
    if (2 != argc)
    {
        ERROR("invalid input para of func main\n");
    }

    init();

    // Test case1: 2 + 3 * 5 - 8 / 3
    ScanFile(argv[1]);

    return 1;
}