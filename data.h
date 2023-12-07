#ifndef extern_
    #define extern_ extern
#endif
// All C files will include this where extern_ is replaced with extern.
//  But main.c will remove the extern_; 
// hence, these variables will "belong" to main.c
extern_ int Line;
extern_ int Putback;
extern_ FILE *Infile;
