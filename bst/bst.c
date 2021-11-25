#include "bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    node_t *left, *right;
    int key;
};

tree_t* create_tree() {
    tree_t* tree = malloc(sizeof(tree_t));
    assert(tree != NULL);
    tree->root = NULL;
    return tree;
}

boolean tree_is_empty(tree_t* tree) {
    assert(tree != NULL);
    if (tree->root == NULL) {
        return 1;
    }
    return 0;
}

void destroy_tree(node_t* root) {
    if (root != NULL) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }
}

void print_tree(node_t* root) {
    if (root != NULL) {
        printf("%d", root->key);
        print_tree(root->left);
        printf(",");
        print_tree(root->right);
    } else {
        printf("NULL");
    }
}

int height(node_t* root) {
    assert(root != NULL);
    int height_left = 1 + height(root->left);
    int height_right = 1 + height(root->right);

    if (height_left > height_right) {
        return height_left;
    } else {
        return height_right;
    }
}

node_t* search_in_tree(node_t* root, int key) {
    assert(root != NULL);
    if (root->key == key) {
        return root;
    } else if (key < root->key) {
        return search_in_tree(root->left, key);
    } else {
        return search_in_tree(root->right, key);
    }
}

boolean insert_key_tree(node_t** root, int key) {
    if (*root == NULL) {
        *root = malloc(sizeof(node_t));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 1;
    } else if (key == (*root)->key) {
        return 0;
    } else if (key < (*root)->key) {
        return insert_key_tree(&(*root)->left, key);
    } else {
        return insert_key_tree(&(*root)->right, key);
    }
}

boolean remove_key_tree(node_t** root, int key) {
    assert(*root != NULL);
    if (key < (*root)->key) {
        return remove_key_tree(&(*root)->left, key);
    } else if (key > (*root)->key) {
        return remove_key_tree(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return 1;
        } else if ((*root)->left == NULL) {
            node_t* aux = *root;
            *root = (*root)->right;
            free(aux);
            return 1;
        } else if ((*root)->right == NULL) {
            node_t* aux = *root;
            *root = (*root)->left;
            free(aux);
            return 1;
        } else {
            node_t* aux = (*root)->left;
            while (aux->right != NULL) {
                aux = aux->right;
            }
            (*root)->key = aux->key;
            return remove_key_tree(&(*root)->left, aux->key);
        }
    }
}

void pre_order(node_t* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node_t* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->key);
        in_order(root->right);
    }
}

void post_order(node_t* root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->key);
    }
}