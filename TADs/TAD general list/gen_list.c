#include "gen_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroy(node_t *p) {
    node_t *aux;

    while (p != NULL) {
        if (p->type == 1) {
            destroy(p->data.sub_list);
        }
        aux = p;
        p = p->next;
        free(aux);
    }
}

node_t *atom(elem x) {
    node_t *p = (node_t *)malloc(sizeof(node_t));
    p->type = 0;
    p->next = NULL;
    p->data.atom = x;
    return p;
}

node_t *sub_list(node_t *sub_list) {
    node_t *p = (node_t *)malloc(sizeof(node_t));
    p->type = 1;
    p->next = NULL;
    p->data.sub_list = sub_list;
    return p;
}

node_t *concat(node_t *p, node_t *q) {
    assert(p != NULL);
    p->next = q;
    return p;
}

info_t head(node_t *p, int *type) {
    assert(p != NULL);
    *type = p->type;
    return p->data;
}

node_t *tail(node_t *p) {
    assert(p != NULL);
    return p->next;
}

void print(node_t *p) {
    if (p == NULL) return;

    printf("(");

    while (p != NULL) {
        if (p->type == 0) {
            printf("%d", p->data.atom);
        } else {
            print(p->data.sub_list);
        }

        if (p->next != NULL) {
            printf(", ");
        }
        p = p->next;
    }
    printf(")");
}

void print_gen_list(node_t *p) {
    print(p);
    printf("\n");
}