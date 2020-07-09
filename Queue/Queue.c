#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MinQueueSize ( 5 )

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->size == 0;
}

int IsFull(Queue Q)
{
    return Q->Capacity == Q->size;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if(MaxElements < MinQueueSize)
    {
        printf("Queue size too small!!!");
        exit(1);
    }

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
    {
        printf("out of space!!!");
        exit(1);
    }

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
    {
        printf("Out of space!!");
        exit(1);
    }

    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Queue Q)
{
    if(Q != NULL)
    {
        free(Q->Array);
        free(Q);        
    }
}

void MakeEmpty(Queue Q)
{
    Q->size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
    {
        printf("Full Queue!!");
        exit(1);
    }
    else
    {
        Q->size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q))
        return  Q->Array[Q->Front];
    printf("Empty Queue!!!");
    return 0;
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Empty Queue!!");
        exit(1);
    }
    else
    {
        Q->size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = 0;

    if (IsEmpty(Q))
    {
        printf("Empty Queue!");
        exit(1);
    }
    else
    {
        Q->size--;
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
    }
    return X;
}

void PrintQueue(Queue Q)
{
    int A;
    if (IsEmpty(Q))
        printf("Empty Queue!!");
    else
    {
        A = Q->Front;
        while(A <= Q->size)
            printf("%c-", Q->Array[A++]);
    }
}

// Test 
int main()
{
    Queue Q;
    ElementType X1, X2;
    int MaxElements;
    printf("请输入队列的大小：");
    scanf("%c", &MaxElements);
    getchar();    
    Q = CreateQueue(MaxElements);

    printf("请输入队列的元素以'#'结束：");
    while((X1 = getchar()) != '#')
    {
        Enqueue(X1, Q);
    }
    getchar();

    printf("PrintQueue:");
    PrintQueue(Q);

    printf("\n依次取出队列的元素，打印为：");
    while (!IsEmpty(Q))
    {
        X2 = FrontAndDequeue(Q);
        printf("%c-", X2);
    }
}



