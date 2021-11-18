#ifndef BIG_NUM_H
#define BIG_NUM_H

#include "doubly_linked_list.h"

typedef struct big_n bn_t;

bn_t* create_big_n(char* bn_1, char* bn_2);
dll_t* get_sub_list_1(dll_t* d, bn_t* bn_1);
dll_t* get_sub_list_2(dll_t* d, bn_t* bn_2);
void destroy_bn(bn_t** bn, dll_t** dll_1, dll_t** dll_2);

#endif