#include "word.h"
#include "read_lib.h"
#include<stdlib.h>

#define SIZE_W 400

int main(){
    phrase_t *p;
    int amount_phrases = 0, num_k = 0;
    char* phrase;
    
    while(!feof(stdin)){
        if(amount_phrases != 0) printf("\n");
        
        phrase = read_until(stdin, '\n'); // read until you find a \n
    
        amount_phrases++;
        scanf("%d\n", &num_k);
        
        p = create(phrase, num_k);
      
        split_phrase_in_words(p, num_k);
       
        delete_phrase(p);
        
    }
    
    return 0;
}