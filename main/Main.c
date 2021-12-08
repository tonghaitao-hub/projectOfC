//#include <stdarg.h>
//#include <string.h>
#include <stdio.h>
#include "SLink.h"
#include "DLink.h"
#include "Utils.h"
#include "Test.h"
u32 strong_weak_symbol = 40;
void strong_weak_symb_func()
{
    DBGPRINTF("call func strong_weak_symb_func in main.c\n");
}

int main(int argc, char *argv[])
{
    DBGPRINTF("fw start\n");
    //test();//practice
    test1(argc, argv);//cÓïÑÔÊµÀý¾«½²
    DBGPRINTF("\rfw end\n");
    return 0;
}





