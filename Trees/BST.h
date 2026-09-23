#ifndef _INCLUDE_BST_
#define _INLCUDE_BST_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct _treenode_ TreeNode;
typedef struct _bst_ BST;

struct _treenode_{
    TreeNode *left;
    TreeNode *right;
    int32_t data;
};

struct _bst_ {
    TreeNode *root;
    uint32_t mass;
};


BST bst_new();
BST* bst_insert(BST *tree,int32_t data);
BST* bst_delete_rec(BST *tree, uint32_t key);
uint32_t bst_search(BST *tree,int32_t key);
uint32_t bst_mass(BST *tree);
uint32_t bst_height (BST *tree);
BST* bst_traversal_preorder(BST *tree);
BST* bst_traversal_inorder(BST *tree);
BST* bst_traversal_postorder(BST *tree);
BST* bst_traversal_preorder_iterative(BST *tree);
BST* bst_traversal_inorder_iterative(BST *tree);
BST* bst_traversal_postorder_iterative(BST *tree);
#endif