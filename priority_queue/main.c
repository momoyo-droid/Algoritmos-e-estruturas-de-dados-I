#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "queue.h"
#include "read_lib.h"

#define TRUE 1

int main() {
    person_t *p;
    queue_t *q = create_queue();

    char command[6];
    char *name;
    int age, comorbidity;
    int n_commands;

    scanf("%d\n", &n_commands);

    for (int i = 0; i < n_commands; i++) {
        scanf("%[A-Z]6s", command);
        getchar();

        if (strcmp(command, "ENTRA") == 0) {
            name = read_until(stdin, ' ');
            age = read_int_until(stdin, ' ');
            comorbidity = read_int_until(stdin, '\n');

            p = create_person(name, age, comorbidity);
            insert_in_queue(q, p);
            compare_priority(q, p);
        
        } else if (strcmp(command, "SAI") == 0) {
            getchar();
            
            if (queue_is_empty(q) == TRUE) {
                printf("FILA VAZIA\n");
            } else {
                remove_from_queue(q);
            }
        }
    }

    destroy_queue(q);

    return EXIT_SUCCESS;
}