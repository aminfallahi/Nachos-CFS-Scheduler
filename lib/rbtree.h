
#ifndef RBTREE_H
#define RBTREE_H

#include "../threads/thread.h"

//typedef int ElementType;
#define NegInfinity (-10000)
 
 
struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;
 
RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(Thread* X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(Thread* X, RedBlackTree T);
RedBlackTree Remove(Thread* X, RedBlackTree T);
Thread* Retrieve(Position P);
void PrintTree(RedBlackTree T);


#endif /* RBTREE_H */

