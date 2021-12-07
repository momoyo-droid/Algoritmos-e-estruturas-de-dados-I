#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_lib.h"
#include "treap.h"

int main(void) {
    int n_operations, value, priority;
    char *command = NULL, *mode = NULL;
    treap_t* tree = create_treap();

    n_operations = read_int_until(stdin, '\n');

    for (int i = 0; i < n_operations; i++) {
        command = read_until(stdin, ' ');
        if (strcmp(command, "insercao") == 0) {
            value = read_int_until(stdin, ' ');
            priority = read_int_until(stdin, '\n');
            push_treap(tree, value, priority);
        } else if (strcmp(command, "remocao") == 0) {
            value = read_int_until(stdin, '\n');
            tree->root = pop_treap(tree->root, value);
        } else if (strcmp(command, "buscar") == 0) {
            value = read_int_until(stdin, '\n');
            if (search_in_treap(tree->root, value)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(command, "impressao") == 0) {
            mode = read_until(stdin, '\n');
            if (!strcmp(mode, "ordem")) {
                print_in_order(tree->root);
                printf("\n");
            } else if (!strcmp(mode, "posordem")) {
                print_pos_order(tree->root);
                printf("\n");
            } else if (!strcmp(mode, "preordem")) {
                print_pre_order(tree->root);
                printf("\n");
            } else if (!strcmp(mode, "largura")) {
                print_width(tree);
                printf("\n");
            }
            free(mode);
        }
        free(command);
    }
    free_treap(tree);
    return EXIT_SUCCESS;
}