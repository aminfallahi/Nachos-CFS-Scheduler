
#ifndef RBTREE_H
#define RBTREE_H

 
typedef int ElementType;
#define NegInfinity (-10000)
 
 
struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;
 
RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(ElementType X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
//RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
RedBlackTree Remove(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
void PrintTree(RedBlackTree T);


#endif /* RBTREE_H */

