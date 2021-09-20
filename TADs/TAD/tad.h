typedef struct p person_t;

person_t *create(char *name, char *address);
void print(person_t *p);
void destroy(person_t *p);