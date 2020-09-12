#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

#define SpaceSize 20

/*
回顾链表的指针实现的两个重要的特点：
1：数据储存在一组结构体中，每一个结构体包含有数据域以及指向下一个结构体的指针。
2：一个新的结构体可以通过调用malloc而从系统全局内存（global memory)得到，并可以调用free而被释放
游标法必须能够模仿实现这两种特性，需要满足条件1的逻辑方法是要有一个全局的结构体数组。
为了模拟特性2，让 CursorSpace 数组中的单元代行 malloc 和 free 的职能，
为此我们保留一个表（即freelist），该表将用单元0作为表头。
*/

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize + 1];

void InitializeCursorSpace()
{
    int Slot;
    for (Slot = 0; Slot < SpaceSize + 1; Slot++)
    {
        if (Slot != SpaceSize)
            CursorSpace[Slot].Next = Slot + 1;
        else
            CursorSpace[Slot].Next = 0;
    }
}

static Position CursorAlloc()
{
    Position P;

    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

List MakeEmpty(List L)
{
    if (L != 0)
        CursorSpace[L].Next = 0;
    return L;
}

/* Return true if L is empty */
int IsEmpty(List L)
{
    return CursorSpace[L].Next == 0;
}

/* Return true if P is the last position in list l */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L)
{
    return CursorSpace[P].Next == 0;
}

/* Find the pre position fo X in L*/
Position FindPrevious(List L, ElementType X)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;
    return P;    
    
}

/* Return Position of X in L; 0 if not found */
/* Use a header node */
Position Find(List L, ElementType X)
{
    Position P;
    P = CursorSpace[L].Next;
    while (P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

/* Delete first occurrence of X from a list */
/* Asumme use of a header node */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) /* Assumption of header use */
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(List L, ElementType X, Position P)
{
    Position TmpCell;
    TmpCell = CursorAlloc();
    if (TmpCell == 0)
        printf("Out of space!!!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

void InsertToTail(List L, ElementType X)
{
    Position Last;
    Last = L;
    /*遍历链表最后一个节点*/
    while(CursorSpace[Last].Next != 0)
        Last = CursorSpace[Last].Next;
    Insert(L, X, Last);    
}

void DeleteList(List L)
{
    Position P, Tmp;
    P = CursorSpace[L].Next;
    CursorSpace[L].Next = 0;

    while( P != 0 )
    {
        Tmp = CursorSpace[P].Next;
        CursorFree(P);
        P = Tmp;
    }
}

void PrintList(List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while (CursorSpace[P].Next)
    {
        printf("%c-", CursorSpace[P].Element);
        P = CursorSpace[P].Next;
    }
    
    printf("%c\n", CursorSpace[P].Element);
}


int main()
{
    InitializeCursorSpace();
    ElementType Elem, De, PreElem, Ins;
    Position Tmp;
    List L;
    L = CursorAlloc();

    if(L == 0)
        printf("No Space for Allocion");
    L = MakeEmpty(L);
    printf("请输入链表元素以'#'结束：");
    while((Elem = getchar()) != '#')
    {
        InsertToTail(L, Elem);
    }
    getchar();
    PrintList(L);

    printf("请输入要删除的元素：");
    scanf("%c", &De);
    getchar();
    Delete(De, L);
    PrintList(L);

    printf("请输入你将要插在哪个元素后：");
    scanf("%c", &PreElem);
    getchar();
    Tmp = Find(L, PreElem);

    printf("请输入你要插入的元素：");
    scanf("%c", &Ins);
    getchar();
    Insert(L, Ins, Tmp);
    PrintList(L);

    DeleteList(L);
    CursorFree(L);
    return 0;
}
