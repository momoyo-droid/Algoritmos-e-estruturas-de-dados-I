#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "poly.h"
#include "read_lib.h"

poly_t *calc_coeff(poly_t *p[], int n) {
    int g = 0;
    int counter = 0;

    poly_t *p_result = create_polynomial(NULL);

    while (counter < n) {
        int coeff = 0;
        counter = 0;
        for (int i = 0; i < n; i++) {
            if (get_grau(p[i]) >= g) {
                coeff += iterate_poly(p[i]);
            } else {
                counter++;
            }
        }
        if (counter < n) {
            insert_coeff(p_result, coeff);
        }
        g++;
    }
    return p_result;
}

int main() {
    char *polynomial = NULL;
    int t_cases;
    int n_polynomials;
    poly_t *p[11];
    poly_t *result;

    t_cases = read_int_until(stdin, '\n');

    for (int i = 0; i < t_cases; i++) {
        n_polynomials = read_int_until(stdin, '\n');
        for (int j = 0; j < n_polynomials; j++) {
            polynomial = read_until(stdin, '\n');
            p[j] = create_polynomial(polynomial);
            parse_polynomial(p[j]);
        }
        result = calc_coeff(p, n_polynomials);
        print_poly(result);
        free_poly(result);
        if (i < t_cases - 1) {
            printf("\n");
        }
        for (int i = 0; i < n_polynomials; i++) {
            free_poly(p[i]);
        }
    }

        return EXIT_SUCCESS;
}