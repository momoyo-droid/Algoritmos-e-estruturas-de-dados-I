#include "treap.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct node {
    int value;
    int priority;
    node_t *left, *right;
};

treap_t* create_treap() {
    treap_t* t = malloc(sizeof(treap_t));
    t->root = NULL;
    return t;
}

node_t* search_in_treap(node_t* p, int id) {
    if (p == NULL) return NULL;
    if (p->value == id)
        return p;  // se o id existir, retorne o node em que ele está
    if (id < p->value)
        return search_in_treap(p->left, id);  // busca o id pela esquerda
    else
        return search_in_treap(p->right, id);  // busca o id pela direita
}

node_t* left_rotation(node_t* p) {
    node_t* q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
}

node_t* right_rotation(node_t* p) {
    node_t* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

node_t* push_bst(node_t* p, int value, int* flag, int priority) {
    if (p == NULL) {
        node_t* new_node;
        new_node = malloc(sizeof(node_t));
        assert(new_node != NULL);
        new_node->value = value;
        new_node->right = NULL;
        new_node->left = NULL;
        new_node->priority = priority;
        return new_node;
    }
    if (value < p->value) {  // se o valor a ser inserido for menor que o
                             // existente, insere no lado esquerdo
        p->left = push_bst(p->left, value, flag, priority);
        if (p->left->priority > p->priority) {  // se a prioridade for maior,
                                                // rotacione para a direita
            p = right_rotation(p);
        }
    } else if (value == p->value) {  // nao permite elementos repetidos na treap
        printf("Elemento ja existente\n");
    } else {
        p->right =
            push_bst(p->right, value, flag,
                     priority);  // se o valor a ser inserido for menor que o
                                 // existente, insere no lado esquerdo
        if (p->right->priority > p->priority) {  // se a prioridade for maior,
                                                 // rotacione para a esquerda
            p = left_rotation(p);
        }
    }
    return p;
}

boolean push_treap(treap_t* tree, int value, int priority) {
    int flag;
    tree->root = push_bst(tree->root, value, &flag, priority);
    return flag;
}

void print_pre_order(node_t* p) {
    if (p == NULL) return;
    printf("(%d, %d) ", p->value, p->priority);
    print_pre_order(p->left);
    print_pre_order(p->right);
}

void print_in_order(node_t* p) {
    if (p == NULL) return;
    print_in_order(p->left);
    printf("(%d, %d) ", p->value, p->priority);
    print_in_order(p->right);
}

void print_pos_order(node_t* p) {
    if (p == NULL) return;
    print_pos_order(p->left);
    print_pos_order(p->right);
    printf("(%d, %d) ", p->value, p->priority);
}

void treap_width(queue_t* q, node_t* arv) {
    while (!queue_empty(q)) {
        node_t* p;
        pop_queue(q, &p);
        printf("(%d, %d) ", p->value, p->priority);
        if (p->left != NULL) push_queue(q, &(p->left));
        if (p->right != NULL) push_queue(q, &(p->right));
    }
}

void print_width(treap_t* tree) {
    queue_t* q = create_queue(sizeof(node_t*));
    push_queue(q, &(tree->root));
    treap_width(q, tree->root);
    free_queue(q);
}

void delete_node(node_t* p) {
    if (p == NULL)
        return;
    else {
        delete_node(p->right);
        delete_node(p->left);
        free(p);
        return;
    }
}

void free_treap(treap_t* tree) {
    node_t* p = tree->root;
    delete_node(p);
    free(tree);
}

node_t* pop_treap(node_t* node, int value) {
    if (node == NULL) {
        printf("Chave nao localizada\n");
        return node;
    }
    if (value < node->value) {  // se o valor for menor que o existente na treap
                                // remova pela esquerda
        node->left = pop_treap(node->left, value);

    } else if (value > node->value) {  // se o valor for maior que o existente
                                       // na treap remova pela direita
        node->right = pop_treap(node->right, value);
    } else if (node->left == NULL) {  // caso em que não há filhos da esquerda
        node_t* aux = node->right;
        free(node);
        node = aux;
    } else if (node->right == NULL) {  // caso em que não há filhos da direita
        node_t* aux = node->left;
        free(node);
        node = aux;
    } else {
        node = left_rotation(node);
        node->left = pop_treap(node->left, value);
    }
    return node;
}