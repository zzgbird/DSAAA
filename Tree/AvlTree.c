#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"

struct AvlNode
{
    Elementype Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
}

static int Height( Position P )
{
    if (P == NULL)
        return -1;
    else 
        return P->Height;
}

/**
 * This function can be called only if k2 has a left child
 * Perform a rotate between a node(k2) and its left child
 * Update heights, then return new root
 */
static Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;

    k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;

    k1->Height = Maxx(Height(k1->Left), Height(k1->Right)) + 1;
    
    return k1;    /* new root */
}

/**
 * This function can be called only if k1 has a right child
 * Perform a rotate between a node(k2) and its right child
 * Update heights, then return new root
 */
static Position SingleRotateWithRight(Position k1)
{
    Position k2;
    k2 = k1->Right;
    k1->Right = k2->Left;
    k2->Left = k1;

    k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;

    k2->Height = Max(Height(k2->Left), Height(k2->Right));

    return k2;  /* new root */
}


/**
 * This function can be called only if k3 has left 
 * child and k3's left child has a right child
 * Do the left-right double rotation
 * Update heights, then return new root
 */

static Position DoubleRotateWithLeft(Position k3)
{
    /* Rotate between k1 and k2 */
    k3->Left = SingleRotateWithRight(k3->Left);

    /* Rotate between k3 and k2 */
    return SingleRotateWithLeft(k3);
}

/**
 * This function can be called only if k1 has right child
 * and k1's right child has a left child
 * Do the right-left double rotation
 * Update heights, then return new root
 */
static Position DoubleRotateWithRight(Position k1)
{
    /* Rotate between k2 and k3 */
    k1->Right = SingleRotateWithLeft(k1->Right);

    /* Rotate between k1 and k2 */
    return SingleRotateWithRight(k1);
}

AvlTree Insert( Elementype X, AvlTree T )
{
    if ( T == NULL )
    {
        /* create and return a one node tree */
        T = malloc(sizeof(struct AvlNode));
        T->Element = X;
        T->Left = T->Right = NULL;
    }

    else if ( X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if ( Height(T->Left) - Height(T->Right) == 2 )
            if ( X < T->Left->Element )
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if ( X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if ( Height(T->Right) - Height(T->Left) == 2 )
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else 
                T = DoubleRotateWithRight(T);    
    }
    /* Else X is in the tree already, we'll do nothing */
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}


