
#include "read_lib.h"

#include<stdio.h>
#include<stdlib.h>

#define ERROR 404
#define NONE_CHAR -2
#define INITIAL_SIZE 32
#define TRUE 1
#define FALSE 0

typedef int bool;


char read_c(FILE* input, bool *is_end_line){
    char first_c = fgetc(input);

    if(first_c == '\r'){
        char second_c = fgetc(input);
        if(second_c != '\n') ungetc(second_c, input);
    }

    *is_end_line = (first_c == '\n' || first_c == EOF || first_c == '\r');

    return first_c;
}

string_t read_string(FILE* input, char possible_final_ref){
    int n_bytes = INITIAL_SIZE;
    int size = 0;
    bool has_finished = FALSE;
    
    string_t str = malloc(n_bytes*sizeof(char));   
    
    do{
        if(size == n_bytes){
            n_bytes *= 2;
            str = realloc(str, n_bytes*sizeof(char));
        }

        bool is_end_line = FALSE;
        char curr_c = read_c(input, &is_end_line);
        bool is_final_ref = (possible_final_ref != NONE_CHAR && curr_c == possible_final_ref);
        has_finished = (is_final_ref || is_end_line);

        if(has_finished){
            str[size] = '\0';

        }else{
            str[size] = curr_c;
        }    

        size++;
    }while(!has_finished);

    if(str[0] == '\0'){
        free(str);
        return NULL;
    }

    if(size < n_bytes){
        str = realloc(str, size*sizeof(char));
    }

    return str;
}


string_t read_all(FILE* input){
    return read_string(input, NONE_CHAR);
}

string_t read_until(FILE* input, char final_ref){
    return read_string(input, final_ref);
}


bool ignore(FILE* input, char initial_ref){
    bool has_finished = FALSE;
    bool is_end_line = FALSE;
    
    do{

        char curr_c = read_c(input, &is_end_line);
        
        has_finished = (curr_c == initial_ref || is_end_line);

    }while(!has_finished);

    return is_end_line;
}

string_t read_from(FILE* input, char initial_ref){
    bool line_has_finished = ignore(input, initial_ref);
    
    if(line_has_finished) return NULL;
    
    return read_all(input);
}

string_t read_from_to(FILE* input, char initial_ref, char final_ref){
    bool line_has_finished = ignore(input, initial_ref);
    
    if(line_has_finished) return NULL;
    
    return read_until(input, final_ref);
}

int read_int(FILE* input){
    string_t num_str = read_string(input, NONE_CHAR);

    if(num_str == NULL) return ERROR;

    int num = atoi(num_str);

    free(num_str);

    return num;

}

float read_float_until(FILE *input, char final_ref) {
	
	string_t num_str = read_until(input, final_ref);

	if (num_str == NULL) return ERROR;

	float num = atof(num_str);
	free(num_str);

	return num;
}



void print_string(string_t str){
    printf("%s\n", (str) ? str : "NULL");
}