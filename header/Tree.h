#ifndef _TREE_H
#define _TREE_H
#include <stdio.h>
#include <malloc.h>

#define TREE_TYPE    int
#define TREE_SIZE    100
#define ARRAY_SIZE   (TREE_SIZE + 1)

typedef struct TREE_NODE{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;





#endif
