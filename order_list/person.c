#include "person.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct p {
    char *name;
    int key;
};

person_t *create_person(char *name, int key) {
    assert(name != NULL);

    person_t *p = (person_t *)malloc(sizeof(person_t));

    assert(p != NULL);

    p->name = name;
    p->key = key;

    return p;
}

char *get_person_name(person_t *p) {
    assert(p != NULL);

    return p->name;
}
int get_person_key(person_t *p) {
    assert(p != NULL);

    return p->key;
}

void destroy_person(person_t *p) {
    assert(p != NULL);
    free(p->name);
    free(p);
}
