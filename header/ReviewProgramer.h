/*********************************************************
Date:2019.2.18
Author:tonghaitao
Function:review programer
*********************************************************/
#ifndef _REVIEWPROGRAMER_H
#define _REVIEWPROGRAMER_H

#include "Typedef.h"
#include <stdlib.h>

/*1*/
#define REARRANGE
#define MAX_COLS 20  //所能处理的最大列号
#define MAX_INPUT1 1000 //每个输入行的最大长度

extern int32 ReadColNum(int32 columns[], uint32 max);
extern void RearRange(char *output, char const *input, uint32 n_columns, int const columns[]);
extern uint32 CallRearRange(void);
/*2*/
extern void InputAndOutput(void);
/*3*/
extern uint32 CheckSum();
/*4*/
#define MAX 100000000
extern int8 GetLongestRowAndPrint();
/*5*/
extern uint32 GetBraceNumInProgramer(void);
/*6*/
extern void GetTypeRange(void);
/*7*/
extern void StaticOutput();
/*8*/
extern void TestSwitchDefault();
/*9*/
extern void CallCalcSqrRoot();
/*10*/
extern uint32 CalcPrimesInRange(uint32 max);
/*11*/
extern void CalcPrimesInPrimes(uint32 max);
/*12*/
extern void IsWhatTriangle(uint32 a, uint32 b, uint32 c);
/*13*/
extern void CopynChar(uint8 *src, uint8 *dst, int n);
/*14*/
extern void PrintNeighborSame();
/*15*/
extern uint32 SubStr(int8 dst[], int8 src[], int start, int len);
/*16*/
extern void DeleteBlank(char string[]);
/*17*/
extern void StandardInAndOutput(void);
/*18*/
extern void SecretStandardInAndOutput(void);
/*19*/
extern uint32 ReverseBits(uint32 value);
/*20*/
extern uint32 CharOffSet(uint32 bitNumber);
extern uint32 BitOffSet(uint32 bitNumber);
extern void SetBit(uint8 bitArray[], uint32 bitNumber);
extern void ClrBit(uint8 bitArray[], uint32 bitNumber);
extern void AssignBit(uint8 bitArray[], uint32 bitNumber, int value);
extern int32 TestBit(uint8 bitArray[], uint32 bitNumber);
/*21*/
extern int32 StoreBitField(int32 orgValue, int32 valueToStore, uint32 startBit, uint32 endBit);
/*22*/
extern int8 const *FindChar(int8 const *source, int8 const *chars);
/*23*/
extern int32 DelSubStr(int8 *srcStr, int8 const *subStr);
/*24*/
extern void ReverseString(uint8 *string);
/*25*/
extern void PrintPrimesInMax();
/*26*/
#define MAX_BIT_NUMBER ((MAX - 3) / 2)
#define MAX_SIZE_ARRAY (MAX_BIT_NUMBER / CHAR_BIT + 1)
//extern void StorePrimesByBits();
extern void StorePrimesByBits(uint8 *array);
/*27*/
extern void CalcTotalPrimesInMax();
/*28*///通过名字查找电话号码
#define NAME_LENGTH  30
#define ADDR_LENGTH  100
#define PHONE_LENGTH 12
#define MAX_PERSONS  100

int8 const *LookUpAddr(int8 const *name);
int8 const *LookUpPhoNum(int8 const *name);

/*29*///通过可变参数计算不同个数数值的平均值
extern float Average(uint32 nValues, ...);

/*30*///计算数组和指针所占内存的大小
extern uint32 SizeOfPtr(uint32 *ptr);

/*31*///fibonacci函数的第n个数，包括迭代和递归实现
extern uint64 FibonacciByRecursion(uint64 n);
extern uint64 FibonacciByIterate(uint64 n);
/*32*///厄米多项式
extern uint32 Hermite(uint32 n, uint32 x);
/*33*///最大公约数
extern uint32 GreatestCommonDivisor(uint32 m, uint32 n);
/*34*///
extern uint32 AsciiToInteger(int8 *string);
/*35*///检查任意数目的整型参数并返回它们中的最大值
extern int32 MaxList(uint32 x, ...);
/*36*///实现一个小型的printf函数
extern void myPrintf(int8 *string, ...);
/*37*///
extern void testPrintf();
/*38*////
#define LONG 1000
extern void WrittenAmount(uint64 amount, int8 *buffer);
/*39*////stack
typedef int32 ElementType;
typedef struct{
    ElementType *base;
    ElementType *top;
    uint32 stacksize;
}STACK_T;

typedef enum{
    RET_OK = 0,
    RET_FALSE,
    RET_OVERFLOW,
    RET_EMPTY,
    RET_FULL
}RESULT;

#define STACK_SIZE 10//
/*../src/reviewprogramer/ReviewProgramer.c: In function ‘Init_Stack’:
../src/reviewprogramer/ReviewProgramer.c:1330:37: error: expected ‘)’ before ‘;’ token
*/
#define STACK_INC 2
extern RESULT Init_Stack(STACK_T *S);
extern RESULT Push_Stack(STACK_T *S, ElementType e);
extern RESULT Pop_Stack(STACK_T *S, ElementType *e);
extern RESULT IsEmpty_Stack(STACK_T *S);
extern RESULT IsFull_Stack(STACK_T *S);
extern RESULT GetTop_Stack(STACK_T *S, ElementType *e);
extern RESULT Delete_Stack(STACK_T *S);
/*
40: sequential queue。
*/
typedef struct{
    ElementType *base;
    uint32 front;
    uint32 rear;
}SeqQueue;

#define MAXQUEUESIZE 10
extern RESULT InitQueue_Seq(SeqQueue *SQ);
extern RESULT EnQueue_Seq(SeqQueue *SQ, ElementType e);
extern RESULT DeQueue_Seq(SeqQueue *SQ, ElementType *e);
extern uint32 QueueLength_Seq(SeqQueue *SQ);
extern RESULT DeleteQueue_Seq(SeqQueue *SQ);
/*
41: single link queue。
*/
typedef struct SLQNode{
    ElementType data;
    struct SLQNode *next;
}SLQNode, *SLQNodePtr;
typedef struct{
    SLQNodePtr front;
    SLQNodePtr rear;
}SLQueue;

extern RESULT InitQueue_SingleLink(SLQueue *SLQ);
extern RESULT EnQueue_SingleLink(SLQueue *SLQ, ElementType e);
extern RESULT DeQueue_SingleLink(SLQueue *SLQ, ElementType *e);
extern RESULT DeleteQueue_SingleLink(SLQueue *SLQ);
extern uint8 QueueCount_SingleLink(SLQueue *SLQ);

/*
42: link stack。
*/
typedef struct StackNode{
    ElementType data;
    struct StackNode *next;
}StackNode, *StackNodePtr;
typedef struct{
    StackNodePtr top;
    uint32 count;
}LinkStack;
extern RESULT InitStack_Link(LinkStack *LStack);
extern RESULT PushStack_link(LinkStack *LStack, ElementType e);
extern RESULT PopStack_Link(LinkStack *LStack, ElementType *e);
extern RESULT GetTopStack_Link(LinkStack *LStack, ElementType *e);
extern RESULT DeleteStack_Link(LinkStack *LStack);

/*
43: double link queue
*/
typedef struct DLQNode{
    ElementType data;
    struct DLQNode *fwd;
    struct DLQNode *bwd;
}DLQNode, *DLQNodePtr;
typedef struct{
    DLQNodePtr head;
    DLQNodePtr tail;
}DLinkQueue;

extern RESULT InitQueue_DoubleLink(DLinkQueue *DLQ);
extern RESULT EnQueue_DoubleLink(DLinkQueue *DLQ, ElementType e);
extern RESULT DeQueue_DoubleLink(DLinkQueue *DLQ, ElementType *e);
extern RESULT DeleteQueue_DoubleLink(DLinkQueue *DLQ);
extern uint8 QueueCount_DoubleLink(DLinkQueue *DLQ);

/*
44: 转换表
*/
typedef double (*OPER_FUNC)(double, double);
extern double Add(double, double);
extern double Sub(double, double);
extern double Mul(double, double);
extern double Div(double, double);
enum
{
    OP_ADD = 0,
    OP_SUB,
    OP_MUL,
    OP_DIV
};
extern OPER_FUNC gOperFunc[];

/*
45.回调函数
*/
typedef uint32 (*PFUNC_CB_T)(uint32 param);
extern uint32 FunctionA(uint32 param);
extern uint32 FunctionB(uint32 param);
extern uint32 CallBackFunc1(PFUNC_CB_T pCallBack, uint32 param);
extern uint32 CallBackFunc2(uint32 (*ptr)(), uint32 param);
/*
46.声明返回指向同类型函数的指针的函数
*/
typedef uint32 (*FUNCPTR)();
typedef FUNCPTR (*PTRFUNCPTR)();

/*
47.8.7问题4测试某个字符串是否是回文
*/

extern uint32 IsPalindrome(int8 *buf);
/*
48.8.7问题7测试数组和指针对效率的影响
*/
#define SIZE 100000L
extern void Try1();
extern void Try2();
extern void Try3();
extern void Try4();
extern double CalcTimeWaste(clock_t start, clock_t end);
/*
49.8.7问题8测试数组和指针不相同
*/
extern void Print();
extern uint32 gA[];
extern uint32 *gB;
/*
50.8.8编程练习3计算美国公民收入所得税
*/
extern double SingleTax(double income);
/*
51.8.8编程练习3判断是否是单位矩阵
*/
extern uint32 Identify_Matrix(uint32 matrix[][10]);

/*
52.8.8编程练习4判断是否是单位矩阵(任意大小的矩阵)
*/
uint32 Identify_Matrix_nRow(uint32 *matrix, uint32 n);

/*
53.8.8编程练习5矩阵乘法
*/
void Matrix_Multiply(uint32 *M1, uint32 *M2, uint32 *RM, uint32 x, uint32 y, uint32 z);

/*
54.8.8编程练习伪数组位置确定
*/
#define VA_LIST va_list
#define VA_START(var_list, var_first) va_start(var_list, var_first)
#define VA_END(var_list) va_end(var_list)
#define VA_ARG(var_list, type) va_arg(var_list, type)
extern int32 Array_Offset(int32 arrayinfo[], ...);
/*
55.8.8编程练习国际象棋8皇后不能互相攻击
*/
extern void DBG_PRINT();
extern int32 conflicts(int32 row, int32 col);
extern void Place_Queen(int32 row);
extern void Board_Init();

#endif
