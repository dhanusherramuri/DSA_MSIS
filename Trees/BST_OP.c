#include "BST.h"

#include <stdio.h>
#include <stdint.h>

void test_bst(void)
{
    BST tree = bst_new();

    // TreeNode *root = NULL;

    /* Insert elements */
    bst_insert(&tree,  50);
    bst_insert(&tree,  30);
    bst_insert(&tree,  70);
    bst_insert(&tree,  20);
    bst_insert(&tree,  40);
    bst_insert(&tree,  60);
    bst_insert(&tree,  80);
    


    /* Search */
    printf("Searching for 20: %d", bst_search(&tree,90));
    
    /* Mass and height */
    printf("\nMass: %u", bst_mass(&tree));
    printf("\nHeight: %u", bst_height(&tree));
    
    /* Traversals */
    printf("\nPreorder: \t");
    bst_traversal_preorder(&tree);
    
    printf("\nInorder:\t");
    bst_traversal_inorder(&tree);
    
    printf("\nPostorder:\t");
    bst_traversal_postorder(&tree);
    
    /* DELETION */
    bst_delete_rec(&tree,  20);


    /* Mass and height */
    printf("\nMass: %u", bst_mass(&tree));
    printf("\nHeight: %u", bst_height(&tree));
    
    /* Traversals */
    printf("\nPreorder: \t");
    bst_traversal_preorder(&tree);
    
    printf("\nInorder:\t");
    bst_traversal_inorder(&tree);
    
    printf("\nPostorder:\t");
    bst_traversal_postorder(&tree);
}

int main(void)
{
    test_bst();

    return 0;
}
