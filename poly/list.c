#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "poly.h"

#define TRUE 1;
#define FALSE 0;

typedef struct node node_t;

struct node {
    int coeff;
    node_t *next;
};

struct list {
    node_t *head, *tail, *ite;
    int size;
};

node_t *create_node(int x) {
    node_t *new_node = malloc(sizeof(node_t));

    assert(new_node != NULL);

    new_node->coeff = x;
    new_node->next = NULL;

    return new_node;
}

list_t *create_list() {
    list_t *l = malloc(sizeof(list_t));

    assert(l != NULL);
    l->head = NULL;
    l->tail = NULL;
    l->ite = NULL;
    l->size = 0;

    return l;
}

void free_list(list_t *l) {
    if (l != NULL) {
        node_t *p = l->head;
        while (p != NULL) {
            l->head = p->next;
            free(p);
            p = l->head;
        }
        free(l);
    }
}

void insert_elem(list_t *l, int x) {
    assert(l != NULL);

    node_t *new_node = create_node(x);
    // empty list
    if (l->head == NULL) {
        l->head = new_node;
        l->ite = l->head;
        l->tail = new_node;
    } else {  // at least one element
        l->tail->next = new_node;
        l->tail = new_node;
    }
    l->size++;
}

void print_list(list_t *l) {
    assert(l != NULL);

    node_t *node = l->head;
    printf("(");
    for (int i = 0; i < l->size; i++) {
        printf("%d", node->coeff);
        if (i < l->size - 1) {
            printf(",");
        }
        node = node->next;
    }
    printf(")");
}

int iterate(list_t *l) {
    assert(l != NULL);

    node_t *node = l->ite;
    l->ite = l->ite->next;

    if (l->ite == NULL) {
        l->ite = l->head;
    }

    return node->coeff;
}