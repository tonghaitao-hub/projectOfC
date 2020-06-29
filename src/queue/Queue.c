#include "Typedef.h"
#include "Queue.h"
/**single link queue**/
Status InitLinkQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->rear)
    {
        return OVERFLOW;
    }
    Q->front->next = NULL;
    return OK;
}

Status DestroyLinkQueue(LinkQueue *Q)
{
    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status DeLinkQueue(LinkQueue *Q, ElemType *e)
{
    QueuePtr tempPtr;
    if(Q->rear == Q->front)
    {
        return ERROR;
    }
    tempPtr = Q->front->next;
    *e = tempPtr->data;
    Q->front->next = tempPtr->next;
    if (Q->rear == tempPtr)
    {
        Q->rear = Q->front;
    }
    free(tempPtr);
    return OK;
}

Status EnLinkQueue(LinkQueue *Q, ElemType e)
{
    QueuePtr tempPtr;
    tempPtr = (QueuePtr)malloc(sizeof(QNode));
    if (!tempPtr)
    {
        return OVERFLOW;
    }
    tempPtr->data = e;
    tempPtr->next = NULL;
    Q->rear->next = tempPtr;
    Q->rear = tempPtr;
    return OK;
}

/**sequential queue**/
Status InitSqQueue(SqQueue *Q)
{
    Q->base = (ElemType *)malloc(MAXQSIZE * sizeof(ElemType));
    if (!Q->base)
    {
        return OVERFLOW;
    }
    Q->front = Q->rear = 0;
    return OK;
}

Status SqQueueLength(SqQueue *Q)
{
    return MODE(Q->rear - Q->front + MAXQSIZE, MAXQSIZE);  
}

Status EnSqQueue(SqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXQSIZE == Q->front)
    {
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = MODE(Q->rear + 1, MAXQSIZE);
    return OK;
}

Status DeSqQueue(SqQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = MODE(Q->front + 1, MAXQSIZE);
    return OK;
}

/**double link queue**/
Status InitDouLinkQueue(DouLinkQueue *DQ)
{
    DQ->head = DQ->tail = (DQueuePtr)malloc(sizeof(DQNode));
    if (!DQ->head)
    {
        return OVERFLOW;
    }
    DQ->head->fwd = NULL;
    DQ->head->bwd = NULL;
    return OK;
}
Status DestroyDouLinkQueue(DouLinkQueue * DQ)
{
    uint32 destoryCnt = 0;
    if (NULL == DQ->head)
    {
        printf("the queue is NULL\n");
    }
    while(NULL != DQ->head)
    {
        destoryCnt++;
        DQ->tail = DQ->head->fwd;
        free(DQ->head);
        printf("destoryCnt = %d\n", destoryCnt);
        DQ->head = DQ->tail;
    }
    return OK;
}
Status EnDouLinkQueue(DouLinkQueue * DQ, ElemType elem)
{
    DQueuePtr tempPtr;
    tempPtr = (DQueuePtr)malloc(sizeof(DQNode));
    if (NULL == tempPtr)
    {
        return OVERFLOW;
    }
    if (NULL != DQ->head->fwd)
    {
        tempPtr->fwd = NULL;
        tempPtr->bwd = DQ->tail;
        tempPtr->data = elem;
        DQ->tail->fwd = tempPtr;
        DQ->tail = tempPtr;
        DQ->head->bwd = DQ->tail;
    }
    else
    {
        tempPtr->fwd = NULL;
        tempPtr->bwd = NULL;
        tempPtr->data = elem;
        DQ->tail = tempPtr;
        DQ->head->fwd = tempPtr;
        DQ->head->bwd = DQ->tail;
    }
    return TRUE;
}

Status DeDouLinkQueue(DouLinkQueue * DQ, ElemType *elem)
{
    DQueuePtr tempPtr;
    if (DQ->head == DQ->tail)
    {
        return OVERFLOW;
    }
    tempPtr = DQ->head->fwd;
    *elem = tempPtr->data;
    if (DQ->tail == DQ->head->fwd)
    {
        DQ->head->fwd = NULL;
        DQ->head->bwd = NULL;
        DQ->tail = DQ->head;
    }
    else
    {
        DQ->head->fwd = tempPtr->fwd;
        tempPtr->fwd->bwd = NULL;  
    }
    free(tempPtr);
    return TRUE;
}

void TestDouLinkQueue()
{
    DouLinkQueue tempDQ;
    DouLinkQueue * tempDQPtr = &tempDQ;
    InitDouLinkQueue(tempDQPtr);
    uint32 iterator;
    ElemType elem;
    for (iterator = 0; iterator < 10; iterator++)
    {
        elem = iterator;
        EnDouLinkQueue(tempDQPtr, iterator);
        printf("EnDouLinkQueue, elem = %d\n", elem);
    }
    for (iterator = 0; iterator < 10; iterator++)
    {
        DeDouLinkQueue(tempDQPtr, &elem);
        printf("DeDouLinkQueue, elem = %d\n", elem);
    }
    printf("destory queue\n");
    DestroyDouLinkQueue(tempDQPtr);
    
}