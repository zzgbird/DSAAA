#ifndef _AvlTree_H

struct  AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int Elementype;

AvlTree MakeEmpty( AvlTree T );
Position Find( Elementype X, AvlTree T);
Position FindMin( AvlTree T );
Position FindMax( AvlTree T );
AvlTree Insert( Elementype X, AvlTree T );
AvlTree Delete( Elementype X, AvlTree T );
Elementype Retrieve( Position P );

#endif  /* _AvlTree_H */