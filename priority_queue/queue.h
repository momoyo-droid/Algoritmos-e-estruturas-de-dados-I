/*
* program made with the priority queue structure for people with aggravating
* health conditions for COVID-19

** Made by:
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP)
- Campus São Carlos - ICMC. ***

*/

#include "person.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct q queue_t;

/*
 * @resume create the queue
 * @parameters void
 * @return struct queue_t type pointer
 */
queue_t *create_queue();
/*
 * @resume check if the queue is empty
 * @parameters struct queue_t type pointer
 * @return boolean
 */
int queue_is_empty(queue_t *q);
/*
 * @resume check if the queue is full
 * @parameters struct queue_t type pointer
 * @return boolean
 */
int queue_is_full(queue_t *q);
/*
 * @resume put the person in the queue if the queue is not full
 * @parameters struct queue_t type pointer, struct person_t type pointer
 * @return boolean
 */
int insert_in_queue(queue_t *q, person_t *p);
/*
 * @resume compares the priority of people in the queue and sorts them by
 * priority
 * @parameters struct queue_t type pointer, struct person_t type pointer
 * @return void
 */
void compare_priority(queue_t *q, person_t *p);
/*
 * @resume remove a person from the queue and dynamically deallocate them
 * @parameters struct queue_t type pointer
 * @return boolean
 */
int remove_from_queue(queue_t *q);
/*
 * @resume prints the people in the queue and their priority
 * @parameters struct queue_t type pointer
 * @return void
 */
void print_queue(queue_t *q);
/*
 * @resume deallocates memory allocated for program use
 * @parameters struct queue_t type pointer
 * @return void
 */
void destroy_queue(queue_t *q);

#endif