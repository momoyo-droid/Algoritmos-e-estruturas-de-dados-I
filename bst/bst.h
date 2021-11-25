#ifndef TREE_H
#define TREE_H

typedef int boolean;
typedef struct node node_t;
typedef struct tree {
    node_t* root;
} tree_t;

tree_t* create_tree();
boolean tree_is_empty(tree_t* tree);
void destroy_tree(node_t* root);
void print_tree(node_t* root);
int height_of_tree(node_t* root);
node_t* search_in_tree(node_t* root, int key);
boolean insert_key_tree(node_t** root, int key);
boolean remove_key_tree(node_t** root, int key);
void pre_order(node_t* root);
void in_order(node_t* root);
void post_order(node_t* root);

#endif