#ifndef _QueueL_H

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Queue;
typedef int ElementType;

Queue CreateQueue();
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void MakeEmpty(Queue Q);
void DisposeQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void PrintQueue(Queue Q);

#endif  /* _QueueL_H */