#include <stdio.h>
#include <stdlib.h>
#include "stackar.h"

#define EmptyTOS ( -1 )
#define MiniStackSize ( 5 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

Stack CreateStack(int MaxElements)
{
    Stack S;

    if(MaxElements < MiniStackSize)
        Error("Stack size is too small");
    
    S = malloc(sizeof(struct StackRecord));
    if(S == NULL)
    {
        printf("Out of space!!!");
        exit -1;
    }

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
    {
        printf("Out of space !!!");
        exit -1;
    }

    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DepositeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        Error("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty Stack");
    else
        S->TopOfStack--;        
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty Stack");
    return 0;
}


