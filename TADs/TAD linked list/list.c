#include "list.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#define TRUE 1;
#define FALSE 0;


typedef struct node node_t;


struct node{
    number data;
    node_t *next;
};

struct list{
    node_t *head, *tale;
    int size;
};

list_t *create(){
    list_t *l;
    l = (list_t*)malloc(sizeof(list_t));

    assert(l != NULL);
    l->head = NULL;
    l->tale = NULL;
    l->size = 0;

    return l;
}

void free_list(list_t *l){
    if(l != NULL){
        node_t *p = l->head;
        while(p != NULL){
            l->head = p->next;
            free(p);
            p = l->head;
        }
        free(l);
    }
} 

void insert_elem(list_t *l, number n){
    assert(l != NULL);

    if(is_in_the_list(l,n) == 1) // does not allow repeated elements
        return;

    node_t *p = (node_t*)malloc(sizeof(node_t));
    p->data = n;
    p->next = NULL;

    // empty list
    if(l->head == NULL){
        l->head = p;
        l->tale = p;
    }else{ // at least one element
        l->tale->next = p;
        l->tale = p;
    }
    l->size++;
}

number size(list_t *l){
    assert(l != NULL);
    return l->size;
}

void print_list(list_t *l){
    assert(l != NULL);

    node_t *p = l->head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

bool is_in_the_list(list_t *l, number n){
    assert(l != NULL);

    node_t *p = l->head;

    while(p != NULL){
        if(p->data == n){
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

bool remove_elem(list_t *l, number n){
    assert(l != NULL);
   
    node_t *previous = NULL;
    node_t *p = l->head;
  

    while(p != NULL){
        if(p->data == n){
            // remove from head
            if(previous == NULL){ // could also be p == l->head
                l->head = l->head->next;
                free(p); 
            }else if(p == l->tale){ // remove from tale
                l->tale = previous;
                l->tale->next = NULL;
                free(p);
            }else{ // remove from the middle
                previous->next = p->next;
                free(p);
            }
            l->size--;
            return TRUE;
        }else{
            previous = p;
            p = p->next;
        }
    }
    return FALSE;
}