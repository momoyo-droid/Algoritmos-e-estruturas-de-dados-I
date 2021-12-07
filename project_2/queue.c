#include "queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
    int start, end, n_elem;
    int size_elem;
    void** elements;
};

queue_t* create_queue(int size) {
    queue_t* q = malloc(sizeof(queue_t));
    assert(q != NULL);
    q->elements = malloc(sizeof(void*) * QUEUE_SIZE);
    assert(q->elements != NULL);
    q->n_elem = 0;
    q->start = 0;
    q->end = 0;
    q->size_elem = size;
    return q;
}

bool queue_full(queue_t* q) {
    assert(q != NULL);
    if (q->n_elem == QUEUE_SIZE) return 1;
    return 0;
}

bool push_queue(queue_t* q, void* x) {
    if (queue_full(q) == 1) return 0;
    q->elements[q->end] = malloc(q->size_elem);
    assert(q->elements[q->end] != NULL);
    memcpy(q->elements[q->end], x, q->size_elem);
    q->end = (q->end + 1) % QUEUE_SIZE;
    q->n_elem++;
    return 1;
}

bool queue_empty(queue_t* q) {
    assert(q != NULL);
    if (q->n_elem == 0) return 1;
    return 0;
}

bool pop_queue(queue_t* q, void* x) {
    if (queue_empty(q) == 1) return 0;
    memcpy(x, q->elements[q->start], q->size_elem);
    free(q->elements[q->start]);
    q->start = (q->start + 1) % QUEUE_SIZE;
    q->n_elem--;
    return 0;
}

void free_queue(queue_t* q) {
    while (q->n_elem > 0) {
        free(q->elements[q->end]);
        q->n_elem--;
    }
    free(q->elements);
    if (q != NULL) free(q);
    return;
}