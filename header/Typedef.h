/*********************************************************
Date:2018.9.2
Author:tonghaitao
Function:typedef
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <stddef.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <float.h>

#define ENLINKQUEUE 0
#define ENSQQUEUE 0
#define ENSTACK 0
#define ENDOULINKQUEUE 0
#define DOSHOPPING 0
#define CALLBACK 0
#define ARRAYSORT 0
#define GENERICSTACK 0
#define REVIEWPROGRAMER 1
#define MODE(a, b) (a)%(b)
#define DIV(a, b) (a)/(b)
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXQSIZE 100

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef long long int int64;
typedef unsigned long long int uint64;

typedef int Status;
typedef int ElemType;
typedef void (*CALL_BACK_FUNC)(uint32 param, uint8 *result);
/*typedef enum
{
    FALSE = 0,
    TRUE = 1
}RESULT;
*/
extern uint8 callback(CALL_BACK_FUNC pFuncPtr, uint32 param, uint8 *result);
extern void TestCallFuncA(uint32 param, uint8 *result);
extern void TestCallFuncB(uint32 param, uint8 *result);
extern void TestCallBack();