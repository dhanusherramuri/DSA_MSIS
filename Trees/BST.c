#include "BST.h"

BST bst_new(){
    BST tree = {NULL,0}; 
    return tree;
}

static TreeNode* _make_treenode_(int32_t data){
    TreeNode *tnode = (TreeNode*)malloc(sizeof(TreeNode));
    tnode -> data = data;
    tnode -> left = NULL;
    tnode -> right = NULL;
    return tnode;
}

BST* bst_insert(BST *tree,  int32_t data){
    TreeNode *root, *parent;
    root = parent = tree -> root;
    while(root!=NULL && root -> data != data){
        parent = root;
        if(data < root -> data){
            root = root -> left;
        }
        else if( data > root -> data){
            root = root -> right;
        }
    }
    TreeNode *temp = _make_treenode_(data);
    // if(root == NULL){
        if( parent == NULL){
            tree -> root = temp;
        }
        else if(data < parent -> data){
            parent -> left = temp;
        }
        else{
            parent -> right = temp;
        }
        ++tree -> mass;
    // }
    return tree;
}

uint32_t bst_search(BST *tree, int32_t key){
    TreeNode *root = tree -> root;
    while(root != NULL){
        if(key < root -> data){
            root = root -> left;
        }
        else if (key > root -> data){
            root = root -> right;
        }
        else {
            break;
        }
    }
    return (root!=NULL);
}
uint32_t bst_mass(BST *tree){
    return tree -> mass;
}

static uint32_t _height_(TreeNode *node){
    uint32_t height;
    uint32_t lh,rh;
    if(node == NULL){
        return 0;
    }
    else{
        lh = _height_(node -> left);
        rh = _height_(node -> right);
        if(lh > rh){
            height = lh + 1;
        }
        else {
            height = rh + 1;
        }
    }
    return height;
}

uint32_t bst_height(BST *tree){
    return (_height_(tree -> root));
}

static void _preorder_(TreeNode *root){
    if(root){
        printf("%d\t" ,root -> data);
        _preorder_(root -> left);
        _preorder_(root -> right);
    }
}

BST* bst_traversal_preorder(BST *tree){
    _preorder_(tree -> root);
    return tree;
}

static void _inorder_(TreeNode *root){
    if(root){
        _inorder_(root -> left);
        printf("%d\t" ,root -> data);
        _inorder_(root -> right);
    }
}

BST* bst_traversal_inorder(BST *tree){
    _inorder_(tree -> root);
    return tree;
}

static void _postorder_(TreeNode *root){
    if(root){
        _postorder_(root -> left);
        _postorder_(root -> right);
        printf("%d\t" ,root -> data);
    }
}

BST* bst_traversal_postorder(BST *tree){
    _postorder_(tree -> root);
    return tree;
}