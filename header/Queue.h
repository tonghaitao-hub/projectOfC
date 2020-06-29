/*******************************************************
Date:2018.9.2
Author:tonghaitao
Function:Queue(include single link,double link, sequential)
*******************************************************/
#include "Typedef.h"
#include <stdlib.h>
/**single link queue**/
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

/**sequential queue**/
typedef struct{
    ElemType *base;
    int front;
    int rear;
}SqQueue;

/**double link queue**/
typedef struct DQNode{
    struct DQNode *fwd;
    struct DQNode *bwd;
    ElemType data;
}DQNode, *DQueuePtr;
typedef struct{
    DQueuePtr head;
    DQueuePtr tail;
}DouLinkQueue;
extern Status InitLinkQueue(LinkQueue *Q);
extern Status DestroyLinkQueue(LinkQueue *Q);
extern Status EnLinkQueue(LinkQueue *Q, ElemType e);
extern Status DeLinkQueue(LinkQueue *Q, ElemType *e);

extern Status InitSqQueue(SqQueue *Q);
extern Status SqQueueLength(SqQueue *Q);
extern Status EnSqQueue(SqQueue *Q, ElemType e);
extern Status DeSqQueue(SqQueue *Q, ElemType *e);

extern Status InitDouLinkQueue(DouLinkQueue *DQ);
extern Status DestroyDouLinkQueue(DouLinkQueue *DQ);
extern Status EnDouLinkQueue(DouLinkQueue *DQ, ElemType elem);
extern Status DeDouLinkQueue(DouLinkQueue *DQ, ElemType *elem);
extern void TestDouLinkQueue();