#ifndef TREAP_H
#define TREAP_H

typedef struct node node_t;
typedef int boolean;

typedef struct treap {
    node_t* root;
} treap_t;

treap_t* create_treap();
node_t* search_in_treap(node_t* node, int id);
boolean push_treap(treap_t* tree, int value, int priority);
void print_pre_order(node_t* node);
void print_in_order(node_t* node);
void print_pos_order(node_t* node);
void print_width(treap_t* tree);
void free_treap(treap_t* tree);
node_t* pop_treap(node_t* root, int value);

#endif