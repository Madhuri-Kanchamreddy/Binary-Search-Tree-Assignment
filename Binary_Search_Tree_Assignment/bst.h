#include <stdint.h>
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct _tree_node_ TreeNode;

struct _tree_node_{
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};

typedef struct _bst_ Bst;

struct _bst_{
    TreeNode *root;
    uint32_t mass;
};

int32_t count = 0;

Bst bst_new();
uint32_t bst_count(const Bst *tree);
uint8_t bst_lookup(const Bst *tree, int32_t key);
Bst* bst_add(Bst *tree, int32_t ele);
Bst* bst_delete(Bst *tree, int32_t ele);
void inorder(Bst *tree);
void preorder(Bst *tree);
void postorder(Bst *tree);
void bst_height(Bst *tree);
void bst_largest(Bst *tree);
void bst_smallest(Bst *tree);
void bst_terminalnodes(Bst *tree);
void bst_ascending_order(Bst *tree);
void bst_descending_order(Bst *tree);
#endif // BST_H_INCLUDED
