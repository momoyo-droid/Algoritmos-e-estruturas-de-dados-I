#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
    int data;
    node_t* next;
    node_t* prev;
};

struct dll {
    node_t* head;
    node_t* tail;
    int n_nodes;
    boolean flag;
};

node_t* create_node(int number) {
    node_t* node = malloc(sizeof(node_t));

    assert(node != NULL);

    node->data = number;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

dll_t* create_dll() {
    dll_t* dll = malloc(sizeof(dll_t));

    assert(dll != NULL);

    dll->head = NULL;
    dll->tail = NULL;
    dll->n_nodes = 0;
    dll->flag = 0;

    return dll;
}

void free_dll(dll_t** dll) {
    assert((*dll) != NULL);

    node_t* deleted_node = ((*dll))->head;

    while (deleted_node != NULL) {
        ((*dll))->head = ((*dll))->head->next;
        free(deleted_node);
        deleted_node = ((*dll))->head;
    }
    free((*dll));

    *dll = NULL;
}

void print_dll(dll_t* dll) {
    assert(dll != NULL);

    node_t* node = dll->head;

    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

void print_dll_rev(dll_t* dll) {
    assert(dll != NULL);

    node_t* node = dll->tail;

    while (node != NULL) {
        printf("%d", node->data);
        node = node->prev;
    }
    printf("\n");
}

boolean push_front_dll(dll_t* sub_list, int num) {
    assert(sub_list != NULL);

    node_t* new_node = create_node(num);

    new_node->next = sub_list->head;

    if (sub_list->head == NULL) {
        sub_list->head = new_node;
        sub_list->tail = new_node;
    } else {
        sub_list->head->prev = new_node;
        new_node->next = sub_list->head;
        sub_list->head = new_node;
    }

    sub_list->n_nodes++;

    return 1;
}

int get_size_dll(dll_t* dll) {
    assert(dll != NULL);

    return dll->n_nodes;
}

dll_t* find_sum_sub_lists(dll_t* sub_list_1, dll_t* sub_list_2) {
    assert(sub_list_1 != NULL && sub_list_2 != NULL);

    dll_t* dll_result = create_dll();
    node_t *node_1 = sub_list_1->head, *node_2 = sub_list_2->head;
    int carry = 0, sum = 0;
    
    // realiza a soma entre os digitos e adiciona na lista resultante que conterá
    // os valores finais
    while (node_1 != NULL && node_2 != NULL) {
        sum = node_1->data + node_2->data + carry;
        push_front_dll(dll_result, sum % 10);

        if (sum > 9) {
            carry = 1;
        } else {
            carry = 0;
        }
        node_1 = node_1->next;
        node_2 = node_2->next;
    }
    // caso onde o inicio da lista dois é vazio
    while (node_1 != NULL && node_2 == NULL) {
        sum = node_1->data + carry;
        push_front_dll(dll_result, sum);

        if (sum > 9) {
            carry = 1;
        } else {
            carry = 0;
        }

        node_1 = node_1->next;
    }
    // caso onde o inicio da lista um é vazio
    while (node_2 != NULL && node_1 == NULL) {
        sum = node_2->data + carry;
        push_front_dll(dll_result, sum);

        if (sum > 9) {
            carry = 1;
        } else {
            carry = 0;
        }

        node_2 = node_2->next;
    }
    // se o carry ainda persistir, insere na lista resultante 
    if (carry == 1) {
        push_front_dll(dll_result, carry);
    }

    return dll_result;
}

boolean compare_big_num(dll_t* sub_list_1, dll_t* sub_list_2) {
    assert(sub_list_1 != NULL && sub_list_2 != NULL);
    // flags para verificar quais numeros sao negativos
    if (sub_list_1->flag && !sub_list_2->flag) {
        return 0;
    }

    if (sub_list_2->flag && !sub_list_1->flag) {
        return 1;
    }
    // percorre a lista e compara qual numero é maior
    while (sub_list_1->head != NULL && sub_list_2->head != NULL) {
        if (sub_list_1->head->data > sub_list_2->head->data) {
            return !sub_list_1->flag;
        }
        if (sub_list_2->head->data > sub_list_1->head->data) {
            return !sub_list_2->flag;
        }
        sub_list_1->head = sub_list_1->head->next;
        sub_list_2->head = sub_list_2->head->next;
    }
    return 0;
}

boolean is_equal_bn(dll_t* sub_list_1, dll_t* sub_list_2) {
    assert(sub_list_1 != NULL && sub_list_2 != NULL);
    int count_equal_num = 0;
    int size_sub_list_1 = get_size_dll(sub_list_1);
    int size_sub_list_2 = get_size_dll(sub_list_2);
    node_t *node_1 = sub_list_1->head, *node_2 = sub_list_2->head;
    // verifica se os numeros sao iguais, contabiliza e compara com o tamanho de ambas as listas
    while (node_1 != NULL && node_2 != NULL) {
        if (node_1->data == node_2->data) {
            count_equal_num++;
        }
        if (count_equal_num == size_sub_list_1 &&
            count_equal_num == size_sub_list_2) {
            return 1;
        }
        node_1 = node_1->next;
        node_2 = node_2->next;
    }

    return 0;
}

boolean is_sml_bn(dll_t* sub_list_1, dll_t* sub_list_2) {
    assert(sub_list_1 != NULL && sub_list_2 != NULL);
    // verifica de acordo com as funcoes anteriores, qual numero é menor
    return !compare_big_num(sub_list_1, sub_list_2) &&
           !is_equal_bn(sub_list_1, sub_list_2);
}

void set_flag(dll_t* d, boolean flag) {
    assert(d != NULL);

    d->flag = flag;
}