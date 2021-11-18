#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct dll dll_t;
typedef int boolean;

dll_t* create_dll();
void free_dll(dll_t** l);
void print_dll(dll_t* dll);
void print_dll_rev(dll_t* dll);
boolean push_front_dll(dll_t* sub_list, int num);
int get_size_dll(dll_t* dll);
dll_t* find_sum_sub_lists(dll_t* sub_list_1, dll_t* sub_list_2);
boolean compare_big_num(dll_t* sub_list_1, dll_t* sub_list_2);
boolean is_equal_bn(dll_t* sub_list_1, dll_t* sub_list_2);
boolean is_sml_bn(dll_t* sub_list_1, dll_t* sub_list_2);
void set_flag(dll_t* d, boolean flag);

#endif