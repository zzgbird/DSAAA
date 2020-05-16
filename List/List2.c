// # include<stdlib.h>
# include<cursor.h>

struct Node
{
    ElementType Element;
    Position Next;
};

struct  Node CursorSpace[ 11 ];

static Position CursorAlloc( void )
{
    Position P;
    
    P = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;
    
    return P;
}

static void CursorFree( Position P )
{
    CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = P;
}

/* Return true if L is empty */
int IsEmpty( List L )
{
    return CursorSpace[ L ].Next == 0;
}

/* Return true if P is the last position in list l */
/* Parameter L is unused in this implementation */
int IsLast( Position P, List L)
{
    return CursorSpace[ P ].Next == 0;
}





