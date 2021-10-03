#include "read_lib.h"
#include "rep.h"
#include<stdlib.h>
#include<string.h>


int main()
{
    char* original_string; 
    char* sub_string;
    char* correction;
    
    int i = 0;
    
    str_t *s;
    
    while(!feof(stdin))
    {
        original_string = read_until(stdin, '\n');
        i++;
        sub_string = read_until(stdin, '\n');
        correction = read_until(stdin, '\n');
       
        
        s = create(original_string, sub_string, correction);
        split_phrase_in_words(s); 
        destroy(s);
        printf("\n");

    }


 

    return 0;
}