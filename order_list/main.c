#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "person.h"
#include "read_lib.h"

int main() {
    char *name = NULL;
    char command[10];
    int key;

    person_t *p;
    list_t *l = create_list();

    while (!feof(stdin)) {
        scanf("%s ", command);

        if (strcmp(command, "INSERE") == 0) {
            key = read_int_until(stdin, ' ');
            name = read_until(stdin, '\n');
            p = create_person(name, key);
            insert_ordered(l, p);
        } else if (strcmp(command, "REMOVE") == 0) {
            key = read_int_until(stdin, '\n');
            remove_elem(l, key);
        } else if (strcmp(command, "IMPRIMIR") == 0) {
            print_list(l);
        }
    }
    
    free_list(l);

    return EXIT_SUCCESS;
}