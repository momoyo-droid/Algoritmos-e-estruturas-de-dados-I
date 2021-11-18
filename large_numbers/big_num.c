#include "big_num.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct big_n {
    char* bn_1;
    char* bn_2;
};

bn_t* create_big_n(char* bn_1, char* bn_2) {
    assert(bn_1 != NULL && bn_2 != NULL);

    bn_t* big_num = malloc(sizeof(bn_t));

    assert(big_num != NULL);

    big_num->bn_1 = bn_1;
    big_num->bn_2 = bn_2;

    return big_num;
}

dll_t* get_sub_list_1(dll_t* sub_list_1, bn_t* big_num) {
    int i = 0;
    // verificando numeros negativos
    if (big_num->bn_1[0] == '-') {
        set_flag(sub_list_1, 1);
        i++;
    }

    // transfere os digitos para a lista 1
    for (; i < strlen(big_num->bn_1); i++) {
        push_front_dll(sub_list_1, big_num->bn_1[i] - '0');
    }

    return sub_list_1;
}
dll_t* get_sub_list_2(dll_t* sub_list_2, bn_t* big_num) {
    int i = 0;
    // verificando numeros negativos
    if (big_num->bn_2[0] == '-') {
        set_flag(sub_list_2, 1);
        i++;
    }

    int j = 0;
    // tratando numeros com zeros a esquerda
    while (big_num->bn_2[j] == '0') {
        j++;
    }

    // transfere os digitos para a lista 2
    for (int k = j+i; k < strlen(big_num->bn_2); k++) {
        push_front_dll(sub_list_2, big_num->bn_2[k] - '0');
    }

    return sub_list_2;
}

void destroy_bn(bn_t** bn, dll_t** dll_1, dll_t** dll_2) {
    assert(bn != NULL);

    free_dll(dll_1);
    free_dll(dll_2);

    free((*bn));

    *dll_1 = NULL;
    *dll_2 = NULL;
    *bn = NULL;
}
