typedef int elem;
typedef struct node node_t;

typedef union {
    elem atom;
    node_t *sub_list;
} info_t;

struct node {
    int type;
    info_t data;
    node_t *next;
};

void destroy(node_t *p);
node_t *atom(elem x);
node_t *sub_list(node_t *sub_list);
node_t *concat(node_t *p, node_t *q);
info_t head(node_t *p, int *type);
node_t *tail(node_t *p);
void print_gen_list(node_t *p);