#include "poly.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct polynomial {
    list_t* coefficients;
    char* polynomial;
    int grau;
};

poly_t* create_polynomial(char* polynomial) {
    poly_t* p = malloc(sizeof(poly_t));

    assert(p != NULL);

    p->coefficients = create_list();
    p->polynomial = polynomial;
    p->grau = 0;

    return p;
}

char* get_polynomial(poly_t* polynomial) {
    assert(polynomial != NULL);

    return polynomial->polynomial;
}

void parse_polynomial(poly_t* p) {
    char* temp = calloc(strlen(p->polynomial) + 1, sizeof(char));
    strcpy(temp, p->polynomial);
    char* aux = strtok(temp + 1, ",");

    do {
        if (aux[strlen(aux) - 1] == ')') {
            aux[strlen(aux) - 1] = '\0';
        }
        p->grau++;
        insert_elem(p->coefficients, atoi(aux));
        aux = strtok(NULL, ",");
    } while (aux != NULL);
    p->grau--;
    
    free(temp);
}

int get_grau(poly_t* p) {
    assert(p != NULL);

    return p->grau;
}

void insert_coeff(poly_t* p, int coeff) {
    assert(p != NULL);

    insert_elem(p->coefficients, coeff);
}

int iterate_poly(poly_t* p) {
    assert(p != NULL);

    return iterate(p->coefficients);
}

void print_poly(poly_t* p) { print_list(p->coefficients); }

void free_poly(poly_t* p) {
    assert(p != NULL);

    if (p->polynomial != NULL) {
        free(p->polynomial);
    }

    free_list(p->coefficients);
    free(p);
}