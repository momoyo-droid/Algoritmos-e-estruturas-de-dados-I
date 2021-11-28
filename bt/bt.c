#include "bt.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int left, right;
    int info;
} node_t;

struct tree {
    node_t* nodes[25];
};

tree_t* create_tree() {
    tree_t* tree = malloc(sizeof(tree_t));
    memset(tree->nodes, 0, 25 * sizeof(node_t*));
    return tree;
}

void destroy_tree(tree_t* tree) {
    for (int i = 0; i < 25; i++) {
        if (tree->nodes[i] != NULL) {
            free(tree->nodes[i]);
        }
    }
    free(tree);
}

boolean insert_node(tree_t* tree, int id, int left, int right, int father) {
    tree->nodes[id] = (node_t*)malloc(sizeof(node_t));
    tree->nodes[id]->info = father;
    tree->nodes[id]->left = left;
    tree->nodes[id]->right = right;

    return 1;
}

boolean sum_recursive(int id, tree_t* tree) {
    if(id == -1) return 1;
    
    if (tree->nodes[id]->left == -1 &&
        tree->nodes[id]->right == -1) {  // is leaf
        return 1;
    }
    
    int left_data, right_data;

    if (tree->nodes[id]->left == -1) {
        left_data = 0;
    } else {
        left_data = tree->nodes[tree->nodes[id]->left]->info;
    }

    if (tree->nodes[id]->right == -1) {
        right_data = 0;
    } else {
        right_data = tree->nodes[tree->nodes[id]->right]->info;
    }

    return left_data + right_data == tree->nodes[id]->info &&
           sum_recursive(tree->nodes[id]->left, tree) &&
           sum_recursive(tree->nodes[id]->right, tree);
}

boolean sum_sons(tree_t* tree) {
    assert(tree != NULL);
    return sum_recursive(0, tree);
}