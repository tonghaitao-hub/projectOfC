/*********************************************************
Date:2018.9.2
Author:tonghaitao
Function:stack
*********************************************************/
#include "Typedef.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct Stack{
    ElemType *base;
    ElemType *top;
    int stacksize;
}Stack;

extern Status InitStack(Stack *S);
extern Status GetTop(Stack *S, ElemType *e);
extern Status Push(Stack *S, ElemType e);
extern Status Pop(Stack *S, ElemType *e);

/***·ºÐÍ¶ÑÕ»***/
#include <assert.h>

#define GENERIC_STACK(STACK_TYPE, SUFFIX, STACK_SIZE)  \
        static STACK_TYPE stack##SUFFIX[STACK_SIZE];   \
        static uint32 top_element##SUFFIX = -1;        \
        uint32 IsEmpty##SUFFIX(void)                   \
        {                                              \
            return top_element##SUFFIX == -1;          \
        }                                              \
        uint32 IsFull##SUFFIX(void)                    \
        {                                              \
            return top_element##SUFFIX == STACK_SIZE;  \
        }                                              \
        void Push##SUFFIX(STACK_TYPE value)            \
        {                                              \
            assert(!IsFull##SUFFIX());                 \
            top_element##SUFFIX += 1;                  \
            stack##SUFFIX[top_element##SUFFIX] = value;\
        }                                              \
        void Pop##SUFFIX(void)                         \
        {                                              \
            assert(!IsEmpty##SUFFIX());                \
            top_element##SUFFIX -= 1;                  \
        }                                              \
        STACK_TYPE Top##SUFFIX(void)                   \
        {                                              \
            assert(!IsEmpty##SUFFIX());                \
            return stack##SUFFIX[top_element##SUFFIX]; \
        }  
extern void TestGenericStack(void);


