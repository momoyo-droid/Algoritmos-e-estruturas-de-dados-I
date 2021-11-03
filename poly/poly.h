#ifndef POLY_H
#define POLY_H

typedef struct polynomial poly_t;

poly_t* create_polynomial(char* polynomial);
char* get_polynomial(poly_t* polynomial);
void parse_polynomial(poly_t* p);
int get_grau(poly_t* p);
int iterate_poly(poly_t* p);
void insert_coeff(poly_t* p, int coeff);
void print_poly(poly_t* p);
void free_poly(poly_t* p);

#endif