#include "word.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct p{
    char* phrase;
    int num_k;
    int amount_words;
};

struct w{
    char *word;
    int frequency_word;
};

phrase_t *create(char *phrase, int num_k){
    if(phrase == NULL){
        return NULL;
    }

    phrase_t *p = (phrase_t*)malloc(sizeof(phrase_t));

    if(p == NULL){
        exit(1);
        return NULL;
    }
    
    p->phrase = phrase;
    p->num_k = num_k;
    
    return p;

}

void split_phrase_in_words(phrase_t *p, int num_k){
    word_t *vector_words = (word_t*)malloc(200*sizeof(word_t));
    int i = 0;
    p->amount_words = 0;

    vector_words[i].word = strtok(p->phrase, " "); // taking the first word of the sentence
    
    while(vector_words[i].word != NULL){
        p->amount_words++;
        i++;
        vector_words[i].word = strtok(NULL, " "); // allocating space in the vector for the next word
    }
    sort_words(vector_words, num_k, p);  
    
    free(vector_words);
}

int  sort_rep_words(const void *x, const void *y){
    int word_1 = ((word_t*)x)->frequency_word;
    int word_2 = ((word_t*)y)->frequency_word;
    return (word_2 - word_1);
}

int sort_alphabetic_words(const void *a, const void *b){
    char **word_1 = &((word_t*)a)->word;
    char **word_2 = &((word_t*)b)->word;
    return strcmp(*word_1, *word_2);
}

void sort_words(word_t *vector_words, int num_k, phrase_t *p){
    
    vector_words->frequency_word = 0;
    // initializing the counter for each of the words within the vector
    for(int i = 0; i < p->amount_words; i++){
        vector_words[i].frequency_word = 0;
    }
    
    qsort(vector_words, p->amount_words, sizeof(word_t), sort_alphabetic_words);
    
    for(int i = 0; i < p->amount_words; i += vector_words[i].frequency_word){
        vector_words[i].frequency_word = 1;
        int j = i+1; // j keeps the position beside the index i
        while(j < p->amount_words && strcmp(vector_words[i].word, vector_words[j].word) == 0){
            vector_words[i].frequency_word++;
            j++;
        }
        
    }
    
    qsort(vector_words, p->amount_words, sizeof(word_t), sort_rep_words);
    print(vector_words,p, num_k);
    
}

void print(word_t *vector_words, phrase_t *p, int num_k){
    for(int i = 0; i < p->amount_words && i < num_k; i++){
        if(vector_words[i].frequency_word == 0){ // for repeated word cases
            continue;
        }        
        printf("%s %d\n", vector_words[i].word, vector_words[i].frequency_word);
        
    }
}

void delete_phrase(phrase_t *p){
    free(p->phrase);
    free(p);
}

