#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tad.h"

int main(){
    char *name = (char*)malloc(20*sizeof(char));
    char *address = (char*)malloc(20*sizeof(char));
    
    scanf("%s %s", name, address);

    person_t *p = create(name, address);
    print(p);
    destroy(p);

    return 0;
}