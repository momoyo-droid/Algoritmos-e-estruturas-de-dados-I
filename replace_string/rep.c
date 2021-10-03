#include "rep.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct w
{  
    char *word;

};

struct s
{
    char *original_string;
    char *sub_string;
    char *corrective_str;
 
};

str_t *create(char *original_string, char *sub_string, char *corrective_str)
{
    if (original_string == NULL || sub_string == NULL || corrective_str == NULL)
    {
        exit(1);
        return NULL;
    }

    str_t *s = (str_t *)malloc(sizeof(str_t));

    
    if (s == NULL)
    {
        exit(1);
        return NULL;
    }

    s->original_string = original_string;
    s->sub_string = sub_string;
    s->corrective_str = corrective_str;

    return s;
}

void split_phrase_in_words(str_t *s)
{
    word_t *vector_words = (word_t*)malloc(200*sizeof(word_t));
    int i = 0;
    
    vector_words[i].word = strtok(s->original_string, " "); // taking the first word of the sentence
    
    while(vector_words[i].word != NULL)
    {
        verify_if_sub_string_exist(vector_words[i].word, s);
        i++;
        vector_words[i].word = strtok(NULL, " "); // allocating space in the vector for the next word
    }
    
    free(vector_words);
}

char* correction_word(char* string, str_t *s)
{
    int size_str = strlen(string), size_sub = strlen(s->sub_string);
    int size_corrective_str = strlen(s->corrective_str);
    int index_sub_str = 0, index_corrective_str = 0;
    int count_characters = 0, first_error_occurrence = 0;
    
    char* corrected_string = (char *)malloc((size_str)*sizeof(char));
    
    for(int i = 0; i < size_str; i++)
    {

        if(string[i] == s->sub_string[index_sub_str])
        {
            count_characters++; 
            index_sub_str++;
        }
        else 
        {
            count_characters = 0;
            corrected_string[index_corrective_str] = string[i]; // first part of the word to be corrected.
            index_corrective_str++;
           
        }
        if(count_characters == size_sub) 
        {
            first_error_occurrence = i - strlen(s->sub_string) + 1; // keep the position of the first occurrence of the error
            
            break;
        }
        
   
    
    }

    
    for(int i = 0; i < size_corrective_str; i++)
    { 
        corrected_string[index_corrective_str++] = s->corrective_str[i]; // insert the corrected characters
        
    }
    
    for(int i = first_error_occurrence + size_sub; i < size_str; i++)
    { 
       corrected_string[index_corrective_str++] = string[i]; // insert the final part of the word
       
    }

    corrected_string[index_corrective_str] = '\0'; // adds a '\0' to determine that the string has ended
     
 

    return corrected_string;
}

bool verify_if_sub_string_exist(char *string, str_t *s)
{
    /* if the string exists, print it corrected. if not, print the other words of the sentence */
    if(strstr(string, s->sub_string))
    {
        printf("%s ", correction_word(string, s));
        return TRUE;
    }else
    {
        printf("%s ", string);
        return FALSE;
    }
    
}

void destroy(str_t *s)
{
    free(s->original_string);
    free(s->sub_string);
    free(s->corrective_str);
    
    free(s);


}