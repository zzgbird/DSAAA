#include <stdlib.h>
#include <stdio.h>
#define ElementType int;

/* compliment Queue use LinkList */

typedef struct Node
{
    ElementType data;
    struct Node Next;
}QNode, *PtrQNode;

typedef struct
{
    PtrQNode front;
    PtrQNode rear;
}Queue;

Queue* CreateQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if (Q == NULL)
    {
        printf("Out of Space!!!");
        return NULL;
    }
    else
    {
        Q->front = Q->rear = NULL;
        return Q;
    }
}

int IsEmpty(Queue* Q)
{
    return Q->front == NULL;
}

void AddQ(Queue* Q, ElementType X)
{
    PtrQNode qNode = (PtrQNode)malloc(sizeof(QNode));
    PtrQNode Tmp = Q->Rare;
    Q->Rare->data = X;
    Tmp->next = Q->Rare;
}

ElementType DeleteQ(Queue* Q)
{

}

void PrintQ(Queue* Q)
{

}

int main()
{

}