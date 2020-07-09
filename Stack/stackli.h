#ifndef _Stack_h

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif  /* _Stack_h */