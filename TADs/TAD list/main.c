#include "list.h"
#include<stdlib.h>
#include<stdio.h>

int main(){

    list_t *l = create();

    insert_elem(l, 3);
    insert_elem(l, 22);
    insert_elem(l, 1);
    insert_elem(l, 344);
    insert_elem(l, 31);

    print_list(l);
    printf("\n");

    remove_elem(l, 3);
    print_list(l);
    printf("\n");
    remove_elem(l, 1);
    print_list(l);
    printf("\n");
    remove_elem(l, 31);
    print_list(l);

    free_list(l);




    return 0;
}