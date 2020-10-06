#include <stdio.h>
#include <stdlib.h>

#define N 16

typedef struct AvlNode *tlink;
struct AvlNode
{
    int vertex;
    tlink left;
    tlink right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a:b;
}

int height(tlink node)
{
    return node ? node->height:-1;
}

tlink single_left_rotate(tlink k1)  //RR rithgt right
{
    tlink k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;

    return k2;
}

tlink single_right_rotate(tlink k2)  //LL left left
{
    tlink k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;

    return k1;
}

tlink double_rotate_left(tlink k1)  //RL right left
{
    k1->right = single_right_rotate(k1->right);
    return single_left_rotate(k1);
}

tlink double_rotate_right(tlink k2) //LR left right
{
    k2->left = single_left_rotate(k2->left);
    return single_right_rotate(k2);
}

tlink insert_node(tlink tree, int vertex)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(struct AvlNode));
        if (tree == NULL)
            printf("out of space!\n"), exit(1);
        tree->vertex = vertex;
        tree->left = tree->right = NULL;
    }

    else if (vertex < tree->vertex)
    {
        tree->left = insert_node(tree->left, vertex);
        if (height(tree->left) - height(tree->right) > 1)
        {
            if (vertex < tree->left->vertex)  // l-l
                tree = single_right_rotate(tree);
            else  // l-r
                tree = double_rotate_right(tree);
        }
    }

    else if (vertex > tree->vertex)
    {
        tree->right = insert_node(tree->right, vertex);
        if (height(tree->right) - height(tree->left) > 1)
        {
            if (vertex > tree->right->vertex)  // r-r
                tree = single_left_rotate(tree);
            else // r-l
                tree = double_rotate_left(tree);
        }
    }

    /* else vertex is already exists in tree, we'll do nothing */

    tree->height = max(height(tree->left), height(tree->right)) + 1;
    return tree;    
}

void infix(tlink root)
{
    if (root)
    {
        infix(root->left);
        printf("%d(%d) ", root->vertex, root->height);
        infix(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int data[N]={3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    tlink tree = NULL;
    int i;
    for (i=0; i<N; i++)
        tree = insert_node(tree, data[i]);
    infix(tree);
    printf("\n");
    return 0;
}