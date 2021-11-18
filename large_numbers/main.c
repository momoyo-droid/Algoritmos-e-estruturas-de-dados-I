#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "big_num.h"
#include "doubly_linked_list.h"
#include "read_lib.h"

int main() {
    int n_cases;
    char* command = NULL;
    char* big_num_1 = NULL;
    char* big_num_2 = NULL;

    dll_t* dll_result = NULL;
    bn_t* bn;

    scanf("%d\n", &n_cases);

    for (int i = 0; i < n_cases; i++) {
        command = read_until(stdin, ' ');
        dll_t* sub_list_1 = create_dll();
        dll_t* sub_list_2 = create_dll();
        if (strcmp(command, "SUM") == 0) {
            big_num_1 = read_until(stdin, ' ');
            big_num_2 = read_until(stdin, '\n');
            bn = create_big_n(big_num_1, big_num_2);
            sub_list_1 = get_sub_list_1(sub_list_1, bn);
            sub_list_2 = get_sub_list_2(sub_list_2, bn);
            dll_result = find_sum_sub_lists(sub_list_1, sub_list_2);
            print_dll(dll_result);

            free_dll(&dll_result);
            free(command);
            free(big_num_1);
            free(big_num_2);

        } else if (strcmp(command, "BIG") == 0) {
            big_num_1 = read_until(stdin, ' ');
            big_num_2 = read_until(stdin, '\n');
            bn = create_big_n(big_num_1, big_num_2);
            sub_list_1 = get_sub_list_1(sub_list_1, bn);
            sub_list_2 = get_sub_list_2(sub_list_2, bn);
            printf("%d\n", compare_big_num(sub_list_1, sub_list_2));

            free(command);
            free(big_num_1);
            free(big_num_2);
        } else if (strcmp(command, "SML") == 0) {
            big_num_1 = read_until(stdin, ' ');
            big_num_2 = read_until(stdin, '\n');
            bn = create_big_n(big_num_1, big_num_2);
            sub_list_1 = get_sub_list_1(sub_list_1, bn);
            sub_list_2 = get_sub_list_2(sub_list_2, bn);
            printf("%d\n", is_sml_bn(sub_list_1, sub_list_2));

            free(command);
            free(big_num_1);
            free(big_num_2);
        } else {
            big_num_1 = read_until(stdin, ' ');
            big_num_2 = read_until(stdin, '\n');

            bn = create_big_n(big_num_1, big_num_2);
            sub_list_1 = get_sub_list_1(sub_list_1, bn);
            sub_list_2 = get_sub_list_2(sub_list_2, bn);

            printf("%d\n", is_equal_bn(sub_list_1, sub_list_2));
            free(command);
            free(big_num_1);
            free(big_num_2);
        }
        destroy_bn(&bn, &sub_list_1, &sub_list_2);
    }

    return EXIT_SUCCESS;
}