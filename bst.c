#include <stdio.h>
#include <stdlib.h>


typedef struct BST {
    int value;
    struct BST *parent;
    struct BST *left;
    struct BST *right;
} BST;


BST *BST_create(int value)
{
    BST *new_tree = malloc(sizeof(BST));
    new_tree->value = value;
    return new_tree;
};


// Root: Return the root of the Tree
BST *BST_root(BST *tree)
{
    if (tree->parent) {
        return BST_root(tree->parent);
    } else {
        return tree;
    };
};


// Parent(v): Return the parent of node v
BST *BST_parent(BST *node)
{
    return node->parent;
};


// Children(v): Return an iterator of the children of node v
BST *BST_children(BST *node)
{
    BST *return_tree = BST_create(0);
    if (node->left && node->right) {
        *return_tree->left = *node->left;
        *return_tree->left = *node->right;
    } else if (node->left) {
        *return_tree->left = *node->left;
    } else if (node->right) {
        *return_tree->right = *node->right;
    };
    return return_tree;
};


// Is_internal(v): Test wheather node v is internal
int BST_internal(BST *node)
{
    BST *children = BST_children(node);
    if (children->left || children->right) {
        return 1;
    } else {
        return 0;
    };
};


// Is_external(v): Test wheather node v is external
int BST_external(BST *node)
{
    BST *children = BST_children(node);
    if (children->left || children->right) {
        return 0;
    } else {
        return 1;
    };
};


// Is_root(v): Test wheather node v is the root
int BST_is_root(BST *node)
{
    if (node->parent) {
        return 0;
    } else {
        return 1;
    };
};


// Size: Return the number of nodes in the Tree


// Elements: Return an iterator of all emelments in the tree
// Positions: Return an iterator of all the nodes found in the tree
// Swap_elements(v, w): Swap the elements stored at nodes v and w
// Replace_element(v, e): Replace the element stored at node v with e


// Insert Value
void BST_insert(BST *tree, int value)
{
      if (value < tree->value) {
          if (tree->left) {
              BST_insert(tree->left, value);
          } else {
              tree->left = BST_create(value);
              tree->left->parent = tree;
          };
      } else {
          if (tree->right) {
              BST_insert(tree->left, value);
          } else {
              tree->right = BST_create(value);
              tree->right->parent = tree;
          };
      };
};


// Destroy Tree
void BST_destroy(BST *tree)
{

};


int main()
{
    BST *tree = BST_create(7);
    BST_insert(tree, 9);
    BST_insert(tree, 4);
    BST_insert(tree, 1);
    BST_insert(tree, 6);
    BST_insert(tree, 10);
    BST_insert(tree, 3);
    BST_insert(tree, 5);
    printf("Root: %d\n", tree->value);
    printf("%d\n", tree->right->value);
    printf("%d\n", tree->left->value);
    return 0;
};
