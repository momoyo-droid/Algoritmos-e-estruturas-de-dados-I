#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef int boolean;
typedef struct tree tree_t;

tree_t* create_tree();
void destroy_tree(tree_t* root);
boolean insert_node(tree_t* tree, int id, int left, int right, int father);
boolean sum_sons(tree_t* tree);

#endif