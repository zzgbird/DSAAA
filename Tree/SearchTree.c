#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree
MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position Find( ElementType X, SearchTree T )
{
    if ( T == NULL )
        return NULL;
    if ( X < T->Element )
        return Find( X, T->Left );
    else if ( X > T->Element )
        return Find( X, T->Right );
    else 
        return T;    
}

Position FindMin( SearchTree T )
{
    if ( T == NULL )
        return NULL;
    else if ( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );    
}

Position FindMax( SearchTree T )
{
    if ( T != NULL )
        while ( T->Right != NULL )
            T = T->Right;
    return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    if ( T == NULL )
    {
        /* create and return a one-node tree */
        T = malloc( sizeof( struct TreeNode ) );
        if ( T == NULL )
        {
            printf("out of space!!!");
            eixt(-1);
        }
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert( X, T->Left );
    else if ( X > T->Right )
        T->Right = Inset( X, T->Right );
    /* Else X is in the tree already; we'll do nothing */
    return T;  /* Do not forget this line!! */
}

SearchTree Delete( ElementType X, SearchTree T )
{
    Position TmpCell;

    if ( T == NULL )
        Error("Element not found!");
    else if ( X < T->Element )
        T->Left = Delete( X, T->Left );
    else if ( X > T->Element )
        T->Right = Delete( X, T->Right );
    else if ( T->Left && T->Right )
    {
        /* Replace wiht smallest in right subtree */
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(TmpCell->Element, T->Right);
    }
    else   /* One or zero children */
    {
        TmpCell = T;
        if ( T->Left == NULL)
            T = T->Right;
        else if ( T->Right == NULL )
            T = T->Left;
        free(TmpCell);
    }
    return T;
}


