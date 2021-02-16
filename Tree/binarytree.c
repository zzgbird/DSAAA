#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// nodestack define
static btlink stack[STACKSIZE];
static int sp = -1;
static int empty(void)
{
    return sp == -1;
}

static void push(btlink item)
{
    stack[++sp] = item;
}

static btlink pop(void)
{
    return stack[sp--];
}

static btlink top(void)
{
    return stack[sp];
}

// nodestack define ok

// statusstack define
static int stack2[STACKSIZE];
static int sp2 = -1;
static empty2(void){
    return sp2 == -1;
}
static void push2(int status){
    stack2[++sp2] = status;
}
static int pop2(void){
    return stack2[sp2--];
}
static int top2(void){
    return stack2[sp2];
}
static void change2(int newstatus){
    stack2[sp2] == newstatus;
}
// statusstack define ok

void insert_tree(btlink *btree, int vertex){
    btlink cur = *btree, parent = NULL;
    btlink new = malloc(sizeof(struct BTree));
    new->vertex = vertex;
    new->left = new->right = NULL;

    if (!cur){
        *btree = new;
        return;
    }
    while(cur){
        parent = cur;
        if (cur->vertex >= vertex)
            cur = cur->left;
        else 
            cur = cur->right;    
    }
    if (parent->vertex >= vertex)
        parent->left = new;
    else 
        parent->right = new;
}






