#include "Typedef.h"

uint8 callback(CALL_BACK_FUNC pFuncPtr, uint32 param, uint8 *result)
{
    printf("callback\n");
    pFuncPtr(param, result);
    return *result;
}

void TestCallFuncA(uint32 param, uint8 *result)
{
    printf("call func A, param = %c\n", (uint8)param);
    *result = 'A';
}

void TestCallFuncB(uint32 param, uint8 *result)
{
    printf("call func B, param = %c\n", (uint8)param);
    *result = 'B';
}

void TestCallBack()
{
    uint8 ch;
    uint8 ret;
    uint8 *result = &ret;
    scanf("%c", &ch);
    if (('A' == ch) || ('a' == ch))
    {
        callback(TestCallFuncA, (uint32)ch, result);
    }
    else if (('B' == ch) || ('b' == ch))
    {
        callback(TestCallFuncB, (uint32)ch, result);
    }
    else
    {
        ret = 'E';
    }
    printf("result = %c\n", *result);
}
