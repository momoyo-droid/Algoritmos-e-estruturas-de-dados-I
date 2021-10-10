#include "person.h"

#include <stdio.h>
#include <stdlib.h>

struct p {
    char *name;
    int age;
    int comorbidity;
    int priority;
};

person_t *create_person(char *name, int age, int comorbidity) {
    person_t *p = (person_t *)malloc(sizeof(person_t));

    if (p == NULL) {
        printf("ERROR");
        return NULL;
    }

    p->name = name;
    p->age = age;
    p->comorbidity = comorbidity;
    p->priority = return_priority(p);

    return p;
}

char *get_person_name(person_t *p) {
    if (p == NULL) {
        printf("ERROR");
        return NULL;
    }

    return p->name;
}

int get_person_age(person_t *p) {
    if (p == NULL) {
        printf("ERROR");
        return ERR;
    }

    return p->age;
}

int get_person_comorbidity(person_t *p) {
    if (p == NULL) {
        printf("ERROR");
        return ERR;
    }

    return p->comorbidity;
}

int return_priority(person_t *p) {
    if (p->age >= AGE_ELDERLY && p->comorbidity == HAS_COMORBIDITY) {
        return VERY_HIGH_PRIORITY;
    } else if (p->age < AGE_ELDERLY && p->comorbidity == HAS_COMORBIDITY) {
        return HIGH_PRIORITY;
    } else if (p->age >= AGE_ELDERLY) {
        return MEDIUM_PRIORITY;
    } else{
        return LOW_PRIORITY;
    }
    
}

int get_person_priority(person_t *p) {
    if (p == NULL) {
        printf("ERROR");
        return ERR;
    }

    return p->priority;
}

void destroy_person(person_t *p) {
    if (p != NULL) {
        free(p->name);
        free(p);
    }
}
