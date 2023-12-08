#include "defs.h"

//*note 使用这种命名法
// void get_next_in_file()
// g_line_num//不需要加数据类型前缀，防止后续的变更。并且IDE可悬浮查看
// g_glass

//*note 高内聚，低耦合。一个函数只做好一个功能，便于整体功能改动及扩展
//*note 先规划好功能再编写，没人有动力重构

// get next Meaning char
static int NextChar()
{
    int c;
    c = fgetc(pFile);
    // skip if Meaningless char
    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
    {
        if ('\n' == c)
        {
            LineNum++;
        }
        c = fgetc(pFile);
    }
    return c;
}

static int CharPos(char *s, int c)
{
    char *p;

    p = strchr(s, c);
    return (p ? p - s : -1);
}

static int ScanInt(int c)
{
    int k, val = 0;

    // Convert each character into an int value
    while ((k = CharPos("0123456789", c)) >= 0)
    {
        val = val * 10 + k;
        c = fgetc(pFile);
    }

    // We hit a non-integer character, put it back.
    fseek(pFile, -1, SEEK_CUR);
    return val;
}

void ScanFile(const char *file)
{
    pFile = OpenFile(file, "r");
    size_t filelen = GetFileSize(pFile);
    ptoken = (TOKEN *)AllocMem(filelen * sizeof(TOKEN));

    TOKEN *pelem = ptoken;
    int c;

    while (1)
    {
        c = NextChar();
        switch (c)
        {
        case EOF:
            return;
        case '+':
            pelem->token = T_PLUS;
            break;
        case '-':
            pelem->token = T_MINUS;
            break;
        case '*':
            pelem->token = T_STAR;
            break;
        case '/':
            pelem->token = T_SLASH;
            break;
        default:
            if (isdigit(c))
            {
                pelem->intvalue = ScanInt(c);
                pelem->token = T_INTLIT;
            }
            else
            {
                ERROR("Unrecognised character");
            }
        }
        g_tokennum++;
        pelem++;
    }

    CloseFile(pFile);
    FreeMem((unsigned char *)ptoken);
    return;
}
