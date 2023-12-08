#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus //! only defined in cpp file
extern "C"         //! only valid in cpp file
{
#endif
    //* do something here
    // char *pa = "ae""de";

#ifdef __cplusplus
}
#endif

#define LOG_(...) printf(__VA_ARGS__)

#define LOG3(fmt, ...) printf(fmt, ##__VA_ARGS__)

#define FUNC(...) func((123, ##__VA_ARGS__))

#define STR(x,y) x##y

void func(int value)
{
    printf("the input value is %d\n", value);
}

int main(void)
{
    LOG_("aeiou\n");

    //!,##clear , __VA_ARGS__ is empty,so it's equal printf(fmt)
    LOG3("Variable parameters is 0\n");
    //! use Variable parameters
    LOG3("fefe%s\n", "a?");

    printf("test"
           "the result is %d"
           "ddd"
           "\n",
           (1, 2));

    FUNC();
    FUNC(456);

    int ab=1;
    STR(a,b)=2;
    return 0;
}