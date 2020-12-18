#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "bst.h"

Bst bst_new(){
    Bst bst = {NULL, 0};
    return bst;
}

uint32_t bst_count(const Bst *tree){
    assert(tree != NULL);
    return tree->mass;
}

static TreeNode* _get_new_node(int32_t ele){
    TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Bst* bst_add(Bst *tree, int32_t ele){
    assert(tree != NULL);
    TreeNode *current, *parent;
    current = parent = tree->root;
    while(current != NULL && ele != current->data){
        parent = current;
        if(ele < current->data)
            current = current->left;
        else if(ele > current->data)
            current = current->right;
    }
    if(current == NULL){
        TreeNode *newnode = _get_new_node(ele);
        if(parent == NULL)
            tree->root = newnode;
        else if(ele < parent->data)
            parent->left = newnode;
        else if(ele > parent->data)
            parent->right = newnode;
        ++tree->mass;
    }
    return tree;
}

uint8_t bst_lookup(const Bst *tree, int32_t key){
    assert(tree != NULL);
    TreeNode *current = tree->root;
    while(current != NULL && key != current->data){
        if(key < current->data)
            current = current->left;
        else if(key > current->data)
            current = current->right;
    }
    return (current != NULL);
}

static TreeNode* _findMin_(TreeNode *node){
    if(node->left == NULL)
        return node;
    else
        return (_findMin_(node->left));
}

static TreeNode* _delete_(Bst *tree, TreeNode *node, int32_t ele){
    TreeNode *temp;
    if(node == NULL)
        return node;
    else if(ele < node->data)
        node->left = _delete_(tree, node->left, ele);
    else if(ele > node->data)
        node->right = _delete_(tree, node->right, ele);
    else if(node->left && node->right){
        temp = _findMin_(node->right);
        node->data = temp->data;
        node->right = _delete_(tree, node->right, node->data);
    }
    else{
        temp = node;
        if(node->right == NULL)
            node = node->left;
        else
            node = node->right;
        free(temp);
        --tree->mass;
    }
    return node;
}

Bst* bst_delete(Bst *tree, int32_t key){
    assert(tree != NULL);
    tree->root = _delete_(tree, tree->root, key);
    return tree;
}

static void _inorder_(TreeNode *node){
    if(node){
        _inorder_(node->left);
        printf("%d\t", node->data);
        _inorder_(node->right);
    }
}

void inorder(Bst *tree){
    assert(tree != NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode *node){
    if(node){
        printf("%d\t", node->data);
        _preorder_(node->left);
        _preorder_(node->right);
    }
}

void preorder(Bst *tree){
    assert(tree != NULL);
    _preorder_(tree->root);
}

static void _postorder_(TreeNode *node){
    if(node){
        _postorder_(node->left);
        _postorder_(node->right);
        printf("%d\t", node->data);
    }
}

void postorder(Bst *tree){
    assert(tree != NULL);
    _postorder_(tree->root);
}

static int32_t _height_(TreeNode *node){
    if(node){
        int32_t lheight = _height_(node->left);
        int32_t rheight = _height_(node->right);

        if(lheight >= rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

void bst_height(Bst *tree){
    assert(tree!=NULL);
    int32_t height = _height_(tree->root);
    printf("\n%d\n", height);
}

static int32_t _terminalnodes_(TreeNode *node){
    if(node){
        _terminalnodes_(node->left);
        if((node->left == NULL) && (node->right == NULL))
            count++;
        _terminalnodes_(node->right);
    }
    return count;
}

void bst_terminalnodes(Bst *tree){
    assert(tree != NULL);
    int32_t count = _terminalnodes_(tree->root);
    printf("No. of terminal nodes : %d\n", count);
}

void bst_smallest(Bst *tree){
    assert(tree != NULL);
    TreeNode *node = tree->root;
    while(node != NULL && node->left != NULL)
        node = node->left;
    printf("Smallest element : %d\n", node->data);
}

void bst_largest(Bst *tree){
    assert(tree != NULL);
    TreeNode *node = tree->root;
    while(node != NULL && node->right != NULL)
        node = node->right;
    printf("Largest element : %d\n", node->data);
}

void bst_ascending_order(Bst *tree){
    assert(tree != NULL);
    _inorder_(tree->root);
}

static void _revinorder_(TreeNode *node){
    if(node){
        _revinorder_(node->right);
        printf("%d\t", node->data);
        _revinorder_(node->left);
    }
}

void bst_descending_order(Bst *tree){
    assert(tree != NULL);
    _revinorder_(tree->root);
}
