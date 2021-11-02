#ifndef PERSON_H
#define PERSON_H

typedef struct p person_t;

/*
 * @resume create the person
 * @parameters char* (string), key (integer)
 * @return struct person_t type pointer
 */
person_t *create_person(char *name, int key);

/*
 * @resume take the person's name
 * @parameters struct person_t type pointer
 * @return string
 */
char *get_person_name(person_t *p);
/*
 * @resume take the key's person
 * @parameters struct person_t type pointer
 * @return integer
 */
int get_person_key(person_t *p);
/*
 * @resume deallocates memory allocated for program use
 * @parameters struct person_t type pointer
 * @return void
 */
void destroy_person(person_t *p);

#endif