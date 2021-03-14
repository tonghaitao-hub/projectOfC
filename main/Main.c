//#include <stdarg.h>
#include <strings.h>
#include <stdio.h>
#include "SLink.h"
#include "DLink.h"
#include "Utils.h"
#include "Test.h"

int main()
{
    DBGPRINTF("fw start\n");
#if PTRDIFFWITHARRAY
    //extern u32 *a;
    //extern u32 b[];

    extern u32 a[5];
    extern u32 *b;

    u32 x, y;
    u32 *ptrA = a;
    u32 *ptrA3 = &a + 3;
    u32 *ptrB3 = b + 3;
    x = a[3];
    y = b[3];
    DBGPRINTF("a[3] = %d\nb[3] = %d\nptrA = %p\nptrA[3] = %p\nptrB[3] = %p\n", x, y, ptrA, ptrA3, ptrB3);
    u32 *ptrAA = &a;
    u32 *ptrBB = &b;
    DBGPRINTF("ptr&a = %p, value.%d\n", ptrAA, *ptrAA);
    DBGPRINTF("ptr&b = %p, value.%d\n", ptrBB, *ptrBB);
#endif
#if BINARY_OCTONARY_DECIMAL
    u32 octo = 0175;
    u32 bin = 0b101;//0B101;
    u32 decimal = 165;
    u32 hex = 0x122;
    DBGPRINTF("octo 0175:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", octo, octo, octo);
    DBGPRINTF("bin 0B101:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", bin, bin, bin);
    DBGPRINTF("deci  165:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", decimal, decimal, decimal);
    DBGPRINTF("hex 0x122:decimal.%-6d, oct.0%-6o, hex.0x%-6x\n", hex, hex, hex);
#endif

#if CHAR_DIFF_WITH_STRING
    char string[] = "dadlkasdfljasd";
    u32 strsize = sizeof(string);
    u32 c = 'yes';
    DBGPRINTF("string.%s, strsize.%d\n", string, strsize);
    DBGPRINTF("c.%s, %c, %d\n", &c, c, c);
#endif

#if IS_SUPPORT_NESTED_COMMENTS
    //char *string = /*/**/"*/"/*"/**/;//另外一种检测是否支持嵌套注释的方法是/*/*/0*/**/1,如果支持则结果为1，如果不支持则为0*1,结果为0
    char *support = "*/";
    char *notsupport = "/*";
    char *result = NULL;
    if (strcmp(string, support) == 0)
    {
        result = "support";
    }
    else if (strcmp(string, notsupport) == 0)
    {
        result = "not support";
    }
    else
    {
        DBGPRINTF("error string\n");
    }
    DBGPRINTF("nested comments is %s\n", result);//如果不允许嵌套注释，输出为*/,允许则输出/*
#endif
#if TEMP_TEST
    int a = 0xffffffff;
    int b = -0x1;
    float f = 0;
    typedef union _mbyte {
        struct {
            char call_id : 7;
            char rsv : 1;
        } bits;
        char config;
    } mbyte;
    mbyte byte;
    byte.config = 0x7f;
    DBGPRINTF("a.%d, a.%#x, byte.bits.call_id.%d, config.%d\n", a, a, byte.bits.call_id, byte.config);
    DBGPRINTF("b.%d, b.%#x, byte.bits.call_id.%d, config.%d\n", b, b, byte.bits.call_id, byte.config);
    DBGPRINTF("f.%g\n", f);
#endif
#if VAR_TYPE_FLOAT_DOUBLE_INT
    typedef union _float_type {
        float f;
        struct {
            u32 nMant : 23;     //尾数
            u32 nExp  : 8;       //指数
            u32 nSign : 1;      //符号位
        } ui;
    } float_type;
    float_type ft;
    ft.f = 19.22233333;
    DBGPRINTF("float.%f, nSign.%#x, nExp.%#x, nMant.%#x\n", ft.f, ft.ui.nSign, ft.ui.nExp, ft.ui.nMant);
#endif

    DBGPRINTF("\rfw end\n");
    return 0;
}





