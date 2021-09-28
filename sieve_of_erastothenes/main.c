#include<stdio.h>
#include<stdlib.h>
#include "sieve.h"

#define INDEX_LIMIT 300

int main(){
    prime_numbers_t *p;
    int limit_num;
    int* index = (int*)malloc(INDEX_LIMIT*sizeof(int));
    int i = 0;
    
    scanf("%d", &limit_num);
    
    while(!feof(stdin)){
        
        scanf("%d", &index[i]); 
       
        i++;
    
    }    

    p = create(limit_num, index);
    sieve_of_eratosthenes(p);
    destroy_numbers(p);
   
   return 0;

}