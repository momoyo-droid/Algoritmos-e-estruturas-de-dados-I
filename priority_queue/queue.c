#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE_Q 20

struct q {
    int start, end;
    int num_persons;
    person_t **p;
};

queue_t *create_queue() {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));

    if (q == NULL) {
        exit(1);
        return NULL;
    }

    q->start = 0;
    q->end = 0;
    q->num_persons = 0;
    q->p = NULL;

    return q;
}

int queue_is_empty(queue_t *q) {
    if (q == NULL) {
        exit(1);
        return ERR;
    }

    if (q->num_persons == 0) {
        return TRUE;
    }

    return ERR;
}

int queue_is_full(queue_t *q) {
    if (q == NULL) {
        exit(1);
        return FALSE;
    }

    if (q->num_persons == SIZE_Q) {
        return TRUE;
    }

    return FALSE;
}

int insert_in_queue(queue_t *q, person_t *p) {
    q->p =
        (person_t **)realloc(q->p, (q->num_persons + 1) * sizeof(person_t *));

    if (queue_is_full(q)) {
        printf("FILA CHEIA");
        return TRUE;
    } else {
        q->p[q->end] = p;
        q->end++;
        q->num_persons++;
    }

    return TRUE;
}

void compare_priority(queue_t *q, person_t *p) {
    person_t *swap;

    // compare the priority of the last and the penultimate individual, to the
    // beginning
    for (int i = q->end - 1; i >= q->start + 1; i--) {
        int j = i - 1;
        while (j >= q->start &&
               get_person_priority(q->p[i]) < get_person_priority(q->p[j])) {
            swap = q->p[j];
            q->p[j] = q->p[i];
            q->p[i] = swap;
            j--;
        }
    }
}

int remove_from_queue(queue_t *q) {
    if (queue_is_empty(q) == TRUE) {
        return FALSE;
    }

    person_t *p = q->p[q->start];

    printf("%s %d %d\n", get_person_name(p), get_person_age(p),
           get_person_comorbidity(p));
    destroy_person(p);

    // after the first person leaves the queue, I move people forward
    for (int i = 1; i < q->num_persons; i++) {
        p = q->p[i];
        q->p[i - 1] = p;
    }

    q->num_persons--;
    q->end--;

    q->p =
        (person_t **)realloc(q->p, (q->num_persons + 1) * sizeof(person_t *));

    return TRUE;
}

void print_queue(queue_t *q) {
    for (int i = 0; i < q->num_persons; i++) {
        printf("%s %d\n", get_person_name(q->p[i]),
               get_person_priority(q->p[i]));
    }
}

void destroy_queue(queue_t *q) {
    for (int i = 0; i < q->num_persons; i++) {
        destroy_person(q->p[i]);
    }

    if (q != NULL && q->p != NULL) {
        free(q->p);
        free(q);
    }
}
