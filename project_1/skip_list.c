#include "skip_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node node_t;

struct node {
    char word[51];
    char def[141];
    node_t** next;
};

struct skip_list {
    int max_level;
    int curr_level;
    double probability;
    node_t* head;
};

node_t* create_node(const char* word, const char* def, int level) {
    assert(word != NULL && def != NULL);

    node_t* new_node = malloc(sizeof(node_t));

    assert(new_node != NULL);

    strcpy(new_node->word, word);
    strcpy(new_node->def, def);

    new_node->next = malloc((level + 1) * sizeof(node_t*));

    for (int i = 0; i < level + 1; i++) {
        new_node->next[i] = NULL;
    }

    return new_node;
}

sk_t* create_skip_list(int max_level, double probability) {
    if (max_level <= 0 || probability <= 0) {
        printf("OPERACAO INVALIDA\n");
        return NULL;
    }

    sk_t* sk = malloc(sizeof(sk_t));

    assert(sk != NULL);

    sk->curr_level = 0;
    sk->max_level = max_level;
    sk->probability = probability;
    sk->head = create_node(" ", " ", max_level);

    srand(time(0));

    return sk;
}

bool destroy_skip_list(sk_t* skip_list) {
    if (skip_list == NULL) {
        printf("SKIP LIST VAZIA\n");
        return 0;
    }

    node_t *deleted_node, *curr_node = skip_list->head->next[0];

    while (curr_node != NULL) {
        deleted_node = curr_node;
        curr_node = curr_node->next[0];
        free(deleted_node->next);
        free(deleted_node);
    }

    free(skip_list->head->next);
    free(skip_list->head);
    free(skip_list);

    return 1;
}

int gen_random_lvl(sk_t* sk) {
    assert(sk != NULL);

    int level = 0;
    // sorteia o nivel para o node
    double lvl_draw = (double)rand() / RAND_MAX;

    while (lvl_draw < sk->probability && level < sk->max_level) {
        level++;
        lvl_draw = (double)rand() / RAND_MAX;
    }
    return level;
}

bool insert_skip_list(sk_t* sk, const char* word, const char* def) {
    assert(sk != NULL && word != NULL && def != NULL);

    node_t* update[sk->max_level + 1];

    for (int i = 0; i <= sk->max_level; i++) {
        update[i] = NULL;
    }

    node_t* curr_node = sk->head;

    // procura a posicao de insercao em cada nivel da skip list
    // e armazena no vetor auxiliar *update[max_level+1]
    for (int i = sk->curr_level; i >= 0; i--) {
        while (curr_node->next[i] != NULL &&
               strcmp(curr_node->next[i]->word, word) < 0) {
            curr_node = curr_node->next[i];
        }
        update[i] = curr_node;
    }
    curr_node = curr_node->next[0];

    // verifica se a palavra existe na lista
    if (curr_node != NULL && strcmp(curr_node->word, word) == 0) {
        printf("OPERACAO INVALIDA\n");
        return 0;
    }

    // aloca espaço para o novo node que sera inserido na skip list
    // e sorteia quantos niveis ele tera
    int new_level = gen_random_lvl(sk);

    node_t* new_node = create_node(word, def, new_level);

    assert(new_node != NULL);

    // se tiver mais niveis que a skip list
    // atualiza os niveis do array auxiliar
    if (new_level > sk->curr_level) {
        for (int i = sk->curr_level + 1; i <= new_level; i++) {
            update[i] = sk->head;
        }
        sk->curr_level = new_level;
    }

    // insere o novo node
    for (int i = 0; i <= new_level; i++) {
        new_node->next[i] = update[i]->next[i];
        update[i]->next[i] = new_node;
    }
        
    return 1;
}

bool remove_skip_list(sk_t* sk, const char* word) {
    assert(sk != NULL && word != NULL);

    node_t* update[sk->max_level + 1];

    for (int i = 0; i <= sk->max_level; i++) {
        update[i] = NULL;
    }

    node_t* deleted_node = sk->head;

    // procura a posicao do elemento em cada nivel da skip list
    // e armazena no vetor auxiliar *update[max_level+1]
    for (int i = sk->curr_level; i >= 0; i--) {
        while (deleted_node->next[i] != NULL &&
               strcmp(deleted_node->next[i]->word, word) < 0) {
            deleted_node = deleted_node->next[i];
        }
        update[i] = deleted_node;
    }
    deleted_node = deleted_node->next[0];

    // verifica se a palavra existe na lista
    if (deleted_node == NULL || strcmp(deleted_node->word, word) != 0) {
        printf("OPERACAO INVALIDA\n");
        return 0;
    }

    // atualiza os ponteiros next dos nodes anteriores ao node que sera removido
    for (int i = 0; i <= sk->curr_level && update[i]->next[i] == deleted_node;
         i++) {
        update[i]->next[i] = deleted_node->next[i];
    }

    // exclui os niveis que estao nulos
    while (sk->curr_level > 0 && sk->head->next[sk->curr_level] == NULL) {
        sk->curr_level--;
    }

    // remove o node
    free(deleted_node->next);
    free(deleted_node);

    return 1;
}

bool change_defword_skip_list(sk_t* sk, const char* word, const char* new_def) {
    assert(sk != NULL && word != NULL && new_def != NULL);

    node_t* curr_node = sk->head;

    // procura a posicao do elemento em cada nivel da skip list
    // e armazena no vetor auxiliar *update[max_level+1]
    for (int i = sk->curr_level; i >= 0; i--) {
        while (curr_node->next[i] != NULL &&
               strcmp(curr_node->next[i]->word, word) < 0) {
            curr_node = curr_node->next[i];
        }
    }
    curr_node = curr_node->next[0];

    // se encontrou a palavra, altere sua definicao
    if (curr_node != NULL && strcmp(curr_node->word, word) == 0) {
        strcpy(curr_node->def, new_def);
        return 1;
    }

    printf("OPERACAO INVALIDA\n");
    return 0;
}

bool search_skip_list(sk_t* sk, const char* word) {
    assert(sk != NULL && word != NULL);

    node_t* curr_node = sk->head;

    // procura a posicao do elemento em cada nivel da skip list
    // e armazena no vetor auxiliar *update[max_level+1]
    for (int i = sk->curr_level; i >= 0; i--) {
        while (curr_node->next[i] != NULL &&
               strcmp(curr_node->next[i]->word, word) < 0) {
            curr_node = curr_node->next[i];
        }
    }
    curr_node = curr_node->next[0];

    // se encontrada, printa a palavra
    if (curr_node != NULL && strcmp(curr_node->word, word) == 0) {
        printf("%s %s\n", curr_node->word, curr_node->def);
        return 1;
    }

    printf("OPERACAO INVALIDA\n");
    return 0;
}

bool print_skip_list(sk_t* sk, const char character) {
    assert(sk != NULL);

    // procura o elemento iniciado por um determinado character
    node_t* curr_node = sk->head;

    for (int i = sk->curr_level; i >= 0; i--) {
        while (curr_node->next[i] != NULL &&
               curr_node->next[i]->word[0] < character) {
            curr_node = curr_node->next[i];
        }
    }
    curr_node = curr_node->next[0];

    // caso nao haja palavras iniciadas pelo character, imprima
    if (curr_node == NULL || curr_node->word[0] != character) {
        printf("NAO HA PALAVRAS INICIADAS POR %c\n", character);
        return 0;
    }

    // caso haja palavras iniciadas pelo character, imprima
    while (curr_node != NULL && curr_node->word[0] == character) {
        printf("%s %s\n", curr_node->word, curr_node->def);
        curr_node = curr_node->next[0];
    }

    return 1;
}