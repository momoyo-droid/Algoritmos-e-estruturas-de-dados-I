#ifndef LIST_H
#define LIST_H

typedef int number;
typedef int bool;
typedef struct list list_t;

/*
* @resume dynamically allocates a list and initializes the members of the struct
* @parameters void
* @return list
*/
list_t *create();

/*
* @resume frees dynamic allocated memory by a created list
* @parameters pointer to list structure
* @return void
*/
void free_list(list_t *l);

/*
* @resume inserts an element into a dynamically allocated list
* @parameters list and a number (element)
* @return void
*/
void insert_elem(list_t *l, number n);

/*
* @resume checks if the list is not null and counts the number of elements within it
* @parameters list
* @return size of list
*/
number size(list_t *l);

/*
* @resume checks that the list is not null and prints the elements within it
* @parameters list
* @return void
*/
void print_list(list_t *l);

/*
* @resume performs a search for an element within the list. this element cannot be repeated. 
* returns true if the element is inside the list and false if not
* @parameters list and a number (element)
* @return true or false
*/
bool is_in_the_list(list_t *l, number n);

/*
* @resume fetches and removes an element from the list. returns true if removed and false if not
* @parameters list and a number (element)
* @return true or false
*/
bool remove_elem(list_t *l, number n);














#endif


