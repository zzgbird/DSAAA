#include <stdio.h>
#include <stdlib.h>
#include "stackli.h"

struct Node
{
    ElementType Element;
    PtrNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct  Node));
    if (S == NULL)
    {
        printf("Out of Space!!!");
        exit -1;
    }
    S->Next == NULL;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
        Error("Must use CreateStack first");
    else
    {
        while(!IsEmpty(S))
            Pop(S);
    }
}

void Push(ElementType X, Stack S)
{
    PtrNode Tmp;
    Tmp = malloc(sizeof(struct  Node));
    if (Tmp == NULL)
    {
        printf("Out of Space!!!");
        exit -1;
    }
    else
    {
        Tmp->Element = X;
        Tmp->Next = S->Next;
        S->Next = Tmp;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return 0;  /* Return value used to avoid warning */    
}

void Pop(Stack S)
{
    PtrNode FirstCell;

    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}

