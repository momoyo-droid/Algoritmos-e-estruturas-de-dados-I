#ifndef LIST_H
#define LIST_H

#include "person.h"

typedef int bool;
typedef struct list list_t;

/*
 * @resume dynamically allocates a list and initializes the members of the
 * struct
 * @parameters void
 * @return list
 */
list_t *create_list();

/*
 * @resume frees dynamic allocated memory by a created list
 * @parameters pointer to list structure
 * @return void
 */
void free_list(list_t *l);

/*
 * @resume checks if the list is not null and counts the number of elements
 * within it
 * @parameters list
 * @return size of list
 */
int size(list_t *l);

/*
 * @resume checks that the list is not null and prints the elements within it
 * @parameters list
 * @return void
 */
void print_list(list_t *l);

bool list_search(list_t *l, int key);

/*
 * @resume insert elements ordered
 * @parameters list_t, person_t
 * @return void
 */
void insert_ordered(list_t *l, person_t *p);

/*
 * @resume fetches and removes an element from the list. returns true if removed
 * and false if not
 * @parameters list and a number (element)
 * @return true or false
 */
bool remove_elem(list_t *l, int key);

#endif
