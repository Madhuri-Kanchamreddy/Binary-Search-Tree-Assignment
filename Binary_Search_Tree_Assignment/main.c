#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bst.h"
#include "bst.c"

void test_new(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    assert(bst_count(tree) == 0);
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    assert(bst_count(tree) == 6);
}

void test_delete(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_delete(tree, 70);
    assert(bst_count(tree) == 5);
}

void test_search(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    assert(bst_lookup(tree, 20) == 1);
}

void test_inorder(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    inorder(tree);
}

void test_preorder(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    preorder(tree);
}

void test_postorder(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    postorder(tree);
}

void test_height(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_height(tree);
}

void test_terminalnodes(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_terminalnodes(tree);
}

void test_max(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_largest(tree);
}

void test_min(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_smallest(tree);
}

void test_ascending(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_ascending_order(tree);
}

void test_descending(){
    Bst tree1 = bst_new();
    Bst *tree = &tree1;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    bst_descending_order(tree);
}

int main()
{
    test_new();
    test_delete();
    test_search();
    test_inorder();
    test_preorder();
    test_postorder();
    test_height();
    test_terminalnodes();
    test_max();
    test_min();
    test_ascending();
    test_descending();
    return 0;
}
