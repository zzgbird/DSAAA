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

