#include <stdio.h>
#include <stdlib.h>

#include "bt.h"
#include "read_lib.h"

int main() {
    int n_nodes, id, father, child_left, child_right;
    tree_t* tree = create_tree();

    scanf("%d\n", &n_nodes);

    for (int i = 0; i < n_nodes; i++) {
        scanf("%d ", &id);
        scanf("%d ", &father);
        scanf("%d ", &child_left);
        scanf("%d ", &child_right);
        insert_node(tree, id, child_left, child_right, father);
    }

    if (sum_sons(tree)) {
        printf("VERDADEIRO\n");
    } else {
        printf("FALSO\n");
    }
    destroy_tree(tree);

    return EXIT_SUCCESS;
}
