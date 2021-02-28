//#include <stdarg.h>
//#include <strings.h>
#include <stdio.h>
#include "SLink.h"
#include "DLink.h"
#include "Utils.h"
#include "Test.h"
extern u32 *a;
extern u32 b[];

//extern u32 a[5];
//extern u32 *b;

int main()
{
    DBGPRINTF("fw start\n");
    u32 x, y;
    x = a[3];
    y = b[3];
    DBGPRINTF("a[3] = %d\nb[3] = %d\n", x, y);

    DBGPRINTF("\rfw end\n");
    return 0;
}





