#ifndef BinaryTree_H
#define BinertTree_H
#define STACKSIZE 300

struct BTree
{    
    int vertex;
    struct Btree *left;
    struct Btree *right;
};

typedef struct Btree *btlink;
void insert_btree(btlink *, int);
btlink insert_btree_recursive(btlink, int);
void delete_btree(btlink *, int);
btlink search_btree_recursive(btlink, int);
btlink search_btree_nonrecursive(btlink, int);
void prefix_recursive(btlink);
void infix_recursive(btlink);
void suffix_revursive(btlink);
void prefix_nonrecursive(btlink);
void infix_nonrecursive(btlink);
void suffix_nonrevursive(btlink);
void destory_tree(btlink);
void bfs(btlink);

#endif