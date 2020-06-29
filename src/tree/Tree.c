#include "Tree.h"
#include <assert.h>
//静态数组实现二叉树
static TREE_TYPE tree[ARRAY_SIZE];

//left child
static int Tree_LeftChild(int current)
{
    return current * 2;
}

//right child
static int Tree_RightChild(int current)
{
    return current * 2 + 1;
}

//insert
void Tree_Insert(TREE_TYPE value)
{
    int current;
    //确保值为非0，因为0用于提示一个未使用的节点
    assert(0 != value);

    //从根节点开始
    current = 1;

    //从合适的子树开始，直到达到一个叶节点

    while (tree[current] != 0)
    {
        //根据情况，进入叶节点或右子树
        if (value < tree[current])
        {
            current = Tree_LeftChild(current);
        }
        else
        {
            assert(value != tree[current]);
            current = Tree_RightChild(current);
        }
        assert(current < ARRAY_SIZE);
    }

    tree[current] = value;
}

//fine
TREE_TYPE *Tree_Find(TREE_TYPE value)
{
    int current;

    //从根节点开始，直到找到那个，进入合适的子树
    current = 1;
    while (current < ARRAY_SIZE && tree[current] != value)
    {
        //根据情况，进入左子树或右子树
        if (value < tree[current])
        {
            current = Tree_LeftChild(current);
        }
        else
        {
            current = Tree_RightChild(current);
        }
        if (current < ARRAY_SIZE)
        {
            return tree + current;
        }
        else
        {
            return NULL;
        }
    }
}

static void Tree_DoPreOrderTraverse(int current, void (*tree_callback)(TREE_TYPE value))
{
    if (current < ARRAY_SIZE && tree[current] != 0)
    {
        tree_callback(tree[current]);
        Tree_DoPreOrderTraverse(Tree_LeftChild(current), tree_callback);
        Tree_DoPreOrderTraverse(Tree_RightChild(current), tree_callback);
    }
}

void Tree_PreOrderTraverse(void (*tree_callback)(TREE_TYPE value))
{
    Tree_DoPreOrderTraverse(1, callback);
}


////////////////////////////////////////////////////////////////////////////////////////////
static TreeNode *tree_link;

//insert
void InsertInLinkTree(TREE_TYPE value)
{
    TreeNode *current;
    TreeNode **link;

    //start from root of tree
    link = &tree_link;
    //find the rigth son of tree
    while ((current = *link) != NULL)
    {
        if (value < current->value)
        {
            link = &current->left;
        }
        else
        {
            link = &current->right;
        }
    }
    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

//find
TREE_TYPE *FindInLinkTree(TREE_TYPE value)
{
    TreeNode *current;
    current = tree_link;
    while (current != NULL && current->value != value)
    {
        if (value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current != NULL)
        {
            return &current->value;
        }
        else
        {
            return NULL;
        }
    }
}











