#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_lib.h"
#include "skip_list.h"

#define MAX_LEVEL 50

int main() {
    char* word;
    char* def;
    char command[10];
    char character;

    sk_t* skip_list = create_skip_list(MAX_LEVEL, 0.5);

    assert(skip_list != NULL);

    while (!feof(stdin)) {
        scanf("%s ", command);

        if (strcmp(command, "insercao") == 0) {
            word = read_until(stdin, ' ');
            def = read_until(stdin, '\n');
            insert_skip_list(skip_list, word, def);
            free(word);
            free(def);

        } else if (strcmp(command, "alteracao") == 0) {
            word = read_until(stdin, ' ');
            def = read_until(stdin, '\n');
            change_defword_skip_list(skip_list, word, def);
            free(word);
            free(def);

        } else if (strcmp(command, "remocao") == 0) {
            word = read_until(stdin, '\n');
            remove_skip_list(skip_list, word);
            free(word);

        } else if (strcmp(command, "busca") == 0) {
            word = read_until(stdin, '\n');
            search_skip_list(skip_list, word);
            free(word);

        } else {
            scanf("%c ", &character);
            print_skip_list(skip_list, character);
        }
    }

    destroy_skip_list(skip_list);

    return EXIT_SUCCESS;
}