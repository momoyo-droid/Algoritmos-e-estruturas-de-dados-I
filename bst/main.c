#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"
#include "read_lib.h"

int main() {
    int number;
    char* command = NULL;
    char* print_type = NULL;
    tree_t* tree = create_tree();

    while (!feof(stdin)) {
        command = read_until(stdin, ' ');
        if (strcmp(command, "insercao") == 0) {
            number = read_int_until(stdin, '\n');
            insert_key_tree(&tree->root, number);
        } else if (strcmp(command, "impressao") == 0) {
            print_type = read_until(stdin, '\n');
            if (strcmp(print_type, "pre-ordem") == 0) {
                if (!tree_is_empty(tree)) {
                    pre_order(tree->root);
                    printf("\n");
                } else {
                    printf("VAZIA\n");
                }
                free(print_type);
            } else if (strcmp(print_type, "em-ordem") == 0) {
                if (!tree_is_empty(tree)) {
                    in_order(tree->root);
                    printf("\n");
                } else {
                    printf("VAZIA\n");
                }
                free(print_type);

            } else {
                if (!tree_is_empty(tree)) {
                    post_order(tree->root);
                    printf("\n");
                } else {
                    printf("VAZIA\n");
                }
                free(print_type);
            }
        }
        free(command);
    }

    destroy_tree(tree->root);

    return EXIT_SUCCESS;
}