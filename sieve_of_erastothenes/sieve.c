#include "sieve.h"
#include<stdio.h>
#include<stdlib.h>

struct n{
    int *vec_all_numbers;
};

struct p{
    int *vec_prime_numbers;
    int *index;
    int amount_prime_numbers;
    int limit_num;
};

prime_numbers_t *create(int limit_num, int *index){
    if(index == NULL){
        return NULL;
    }

    prime_numbers_t *p = (prime_numbers_t*)malloc(sizeof(prime_numbers_t));

    if(p == NULL){
        exit(1);
        return NULL;
    }
    
    p->limit_num = limit_num;
    p->index = index;
    
    
    return p;
    
}

void sieve_of_eratosthenes(prime_numbers_t *p){
    all_numbers_t *n = (all_numbers_t*)malloc(LIMIT*sizeof(all_numbers_t));
    n->vec_all_numbers = calloc(LIMIT+1, sizeof(int));
    
    p->vec_prime_numbers = calloc(LIMIT+1, sizeof(int));
    
    p->amount_prime_numbers = 0;
    
    for(int num_prime = 2; num_prime <= LIMIT; num_prime++){ 
        if(n->vec_all_numbers[num_prime] == PRIME_NUMBER){
    
            p->amount_prime_numbers++;
           
            p->vec_prime_numbers[p->amount_prime_numbers] = num_prime; 
          
            for(int multiple = 2*num_prime; multiple <= LIMIT; multiple += num_prime){ // remove multiples from prime number
            
                if(n->vec_all_numbers[multiple] == MULTIPLE){ // skip multiples that have already been marked TRUE
                    continue;
                }
            
                n->vec_all_numbers[multiple] = MULTIPLE; // marks the position of the multiple as TRUE
            
            }
        }
    
    }
   
    print(p);
    free(n->vec_all_numbers);
    free(n);
   
}

void print(prime_numbers_t *p){
    for(int i = 0; i < p->limit_num; i++){
       printf("%d ", p->vec_prime_numbers[p->index[i]]);
       
    }
   
}

void destroy_numbers(prime_numbers_t *p){
    free(p->vec_prime_numbers);
    free(p->index);
    free(p);
}