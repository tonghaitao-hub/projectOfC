#include "Stack.h"
#include <stdlib.h>
Status InitStack(Stack *S)
{
    S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (NULL == S->base)
    {
        return OVERFLOW;
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(Stack *S, ElemType *e)
{
    if (S->top == S->base)
    {
        return ERROR;
    }
    *e = *(S->top - 1);
    return OK;
}

Status Push(Stack *S, ElemType e)
{
    if ((S->top - S->base) >= S->stacksize)
    {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * 
                    sizeof(ElemType));
        if (NULL == S->base)
        {
            return OVERFLOW;
        }
        S->top = S->base + S->stacksize;//之所以重新赋值，是因为重新申请的内存起始地址有可能会改变
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}

Status Pop(Stack *S, ElemType *e)
{
    if (S->top == S->base)
    {
        return ERROR;
    }
    *e = *--S->top;
    return OK;
}



/*********泛型堆栈********/
GENERIC_STACK(int, _int, 10);
GENERIC_STACK(float, _float, 5);
void TestGenericStack()
{
    Push_int(5);
    Push_int(22);
    Push_float(25.3);
    //清空整数堆栈，并打印这些值
    while(!IsEmpty_int())
    {
        printf("Popping %d\n", Top_int());
        Pop_int();
    }

    while(!IsEmpty_float())
    {
        printf("Popping %f\n", Top_float());
        Pop_float();
    }
    return;
}





