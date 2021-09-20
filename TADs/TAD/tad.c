#include<stdio.h>
#include<stdlib.h>
#include "tad.h"

struct p{
    char *name;
    char *address;
};

person_t *create(char *name, char *address){
    if(name == NULL || address == NULL){
        return NULL;
    }
    
    person_t *p;
    p = (person_t*)malloc(sizeof(person_t));

    if(p == NULL){
        return NULL;
    }
        
    p->name = name;
    p->address = address;

    return p;
}

void print(person_t *p){
    if(p != NULL)
        printf("name: %s; address: %s ", p->name, p->address);
}

void destroy(person_t *p){
    if(p != NULL){
        free(p);
        p = NULL;
    }
}