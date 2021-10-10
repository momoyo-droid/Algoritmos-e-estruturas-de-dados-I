/*
* program made with the priority queue structure for people with aggravating
* health conditions for COVID-19

** Made by:
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP)
- Campus São Carlos - ICMC. ***

*/

#ifndef PERSON_H
#define PERSON_H

#define ERR -1

#define HAS_COMORBIDITY 1
#define HAS_NO_COMORBIDITY 0
#define AGE_ELDERLY 60
#define VERY_HIGH_PRIORITY 1
#define HIGH_PRIORITY 2
#define MEDIUM_PRIORITY 3
#define LOW_PRIORITY 4

typedef struct p person_t;

/*
 * @resume create the person
 * @parameters char* (string), age (integer), comorbidity (integer)
 * @return struct person_t type pointer
 */
person_t *create_person(char *name, int age, int comorbidity);

/*
 * @resume take the person's name
 * @parameters struct person_t type pointer
 * @return string
 */
char *get_person_name(person_t *p);
/*
 * @resume take the age's name
 * @parameters struct person_t type pointer
 * @return integer
 */
int get_person_age(person_t *p);
/*
 * @resume take the comorbidity's name
 * @parameters struct person_t type pointer
 * @return integer
 */
int get_person_comorbidity(person_t *p);
/*
 * @resume calculates the priority of the person who will be placed in the queue
 * @parameters struct person_t type pointer
 * @return integer
 */
int return_priority(person_t *p);
/*
 * @resume take the priority's name
 * @parameters struct person_t type pointer
 * @return integer
 */
int get_person_priority(person_t *p);
/*
 * @resume deallocates memory allocated for program use
 * @parameters struct person_t type pointer
 * @return void
 */
void destroy_person(person_t *p);

#endif