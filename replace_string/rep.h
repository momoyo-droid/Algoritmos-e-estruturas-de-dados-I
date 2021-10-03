/*
* program in which we receive a string with a grammatical error, a substring contained in the sentence, 
* and the corrective string. We must grammatically correct the string and return it without errors.

** Made by: 
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP) - Campus São Carlos - ICMC. ***

*/

#ifndef rep_H
#define rep_H

#define TRUE 1
#define FALSE 0

typedef struct s str_t;
typedef struct w word_t;
typedef int bool;


/*
* @resume create the string, substring and corrective string
* @parameters char* (string)
* @return struct str_t type pointer
*/
str_t *create(char* text_original, char* error, char* correction);
/*
* @resume checks if the substring exists in the string and returns true or false
* @parameters char* (string), struct str_t type pointer
* @return boolean value
*/
bool verify_if_sub_string_exist(char *string, str_t *s);
/*
* @resume split the words of the sentence
* @parameters char* (string),struct str_t type pointer
* @return void
*/
void split_phrase_in_words(str_t *s);
/*
* @resume correct the received word
* @parameters char* (string), struct str_t type pointer
* @return corrected string
*/
char* correction_word(char* string, str_t *s);
/*
* @resume deallocates the memory block allocated by the phrase and the struct pointer of the str_t type
* @parameters struct str_t type pointer
* @return void
*/
void destroy(str_t *s);


#endif