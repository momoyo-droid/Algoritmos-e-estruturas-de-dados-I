#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 100

typedef int bool;
typedef struct queue queue_t;

queue_t* create_queue(int size);
bool queue_empty(queue_t* q);
bool push_queue(queue_t* q, void* x);
bool pop_queue(queue_t* q, void* x);
void free_queue(queue_t* q);

#endif