/*
* program based on the "Riddle of Erastosthenes" algorithm, in which a list of prime numbers is constructed. 
* on input, we receive a threshold number and the positions in the list in which prime values ​​are found. 
* according to the limit number provided by the user, prints on the screen the requested positions that contain prime values

** Made by: 
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP) - Campus São Carlos - ICMC. ***

*/

#ifndef sieve_H
#define sieve_H

#define LIMIT 10000
#define MULTIPLE 1
#define PRIME_NUMBER 0

typedef struct n all_numbers_t;
typedef struct p prime_numbers_t;


/*
* @resume create the limit_num and the index
* @parameters int (integer), int* (integer pointer)
* @return struct prime_numbers_t type pointer
*/
prime_numbers_t *create(int limit_num, int *index);
/*
* @resume performs the eratosthenes sieve algorithm
* @parameters struct prime_numbers_t type pointer
* @return void
*/
void sieve_of_eratosthenes(prime_numbers_t *p);
/*
* @resume prints on the screen each prime number that occupies the position requested by the user
* @parameters struct prime_numbers_t type pointer
* @return void
*/
void print(prime_numbers_t *p);
/*
* @resume deallocates the memory block allocated by the vectors and the struct pointer of the prime_numbers_t type
* @parameters struct phrase_t type pointer
* @return void
*/
void destroy_numbers(prime_numbers_t *p);

#endif