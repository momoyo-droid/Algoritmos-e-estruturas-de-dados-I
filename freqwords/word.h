/*
* program designed to receive a sentence, separate it into words, order each of the words 
* (initially in alphabetical order and later in the order in which they are repeated) 
* starting with the one with the highest repetition rate within the sentence. 
* Finally, it prints each word according to a number k and the number of words contained in the sentence.

** Made by: 
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP) - Campus São Carlos - ICMC. ***

*/

#ifndef word_H
#define word_H

typedef struct w word_t;
typedef struct p phrase_t;

/*
* @resume create the phrase and the number k
* @parameters char* (string), int (integer)
* @return struct phrase_t type pointer
*/
phrase_t *create(char* phrase, int num_k);
/*
* @resume split the words of the sentence
* @parameters struct phrase_t type pointer, int (integer)
* @return void
*/
void split_phrase_in_words(phrase_t *p, int num_k);
/*
* @resume sort the words in alphabetical order and then in order of frequency in which they appear in the sentence
* @parameters struct word_t type pointer, int (integer), struct phrase_t type pointer
* @return void
*/
void sort_words(word_t *vector, int num_k, phrase_t *p);
/*
* @resume prints each word and its frequency according to the number k and the number of words
* @parameters struct word_t type pointer, struct phrase_t type pointer, int (integer) 
* @return void
*/
void print(word_t *vector, phrase_t *p, int num_k);
/*
* @resume deallocates the memory block allocated by the phrase and the struct pointer of the phrase_t type
* @parameters struct phrase_t type pointer
* @return void
*/
void delete_phrase(phrase_t *p);


#endif