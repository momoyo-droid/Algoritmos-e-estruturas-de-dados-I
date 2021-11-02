#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct node node_t;

struct node {
    person_t *p;
    node_t *next;
};

struct list {
    node_t *head, *tail;
    int size;
};

node_t *create_node(person_t *p) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    assert(new_node != NULL);

    new_node->p = p;
    new_node->next = NULL;

    return new_node;
}

list_t *create_list() {
    list_t *l = (list_t *)malloc(sizeof(list_t));

    assert(l != NULL);

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void free_list(list_t *l) {
    assert(l != NULL);

    node_t *deleted_node = l->head;
    while (deleted_node != NULL) {
        l->head = deleted_node->next;
        destroy_person(deleted_node->p);
        deleted_node->next = NULL;
        free(deleted_node);

        deleted_node = l->head;
    }
    free(l);
}

bool list_search(list_t *l, int key) {
    assert(l != NULL);

    node_t *curr_node = l->head;
    while (curr_node != NULL) {
        if (get_person_key(curr_node->p) == key) {
            return TRUE;
        }
        curr_node = curr_node->next;
    }
    return FALSE;
}

void insert_ordered(list_t *l, person_t *p) {
    assert(l != NULL && p != NULL);

    if (list_search(l, get_person_key(p))) {
        printf("INVALIDO\n");
        return;
    }

    node_t *new_node = create_node(p);

    if (l->head == NULL ||
        get_person_key(l->head->p) >= get_person_key(new_node->p)) {
        new_node->next = l->head;
        l->head = new_node;
    } else {
        node_t *curr_node = l->head;
        while (curr_node->next != NULL && get_person_key(curr_node->next->p) <
                                              get_person_key(new_node->p)) {
            curr_node = curr_node->next;
        }
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }

    l->size++;
}

void print_list(list_t *l) {
    assert(l != NULL);
    
    if(l->head == NULL){
        printf("VAZIA\n");
        return;
    } 
    
    node_t *node = l->head;

    for (int i = 0; i < l->size; i++) {
        printf("%d, %s; ", get_person_key(node->p), get_person_name(node->p));
        node = node->next;
    }
    printf("\n");
}

bool remove_elem(list_t *l, int key) {
    assert(l != NULL);

    node_t *prev_node = NULL;
    node_t *curr_node = l->head;

    while (curr_node != NULL) {
        if (key == get_person_key(curr_node->p)) {
            if (prev_node != NULL) {
                prev_node->next = curr_node->next;
            } else {
                l->head = curr_node->next;
            }
            if (curr_node == l->tail) {
                l->tail = prev_node;
            }

            destroy_person(curr_node->p);
            free(curr_node);
            l->size--;
            return TRUE;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    return printf("INVALIDO\n");
}
