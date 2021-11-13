/* program made with skip list structure for dictionaries data (word and
definition)
** Made by:
*** Ana Cristina Silva de Oliveira - 11965630 - University of São Paulo (USP)
- Campus São Carlos - ICMC. ***
*/

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

typedef struct skip_list sk_t;
typedef int bool;

// cria e aloca dinamicamente, com base no nivel, a skip list
sk_t* create_skip_list(int max_level, double probability);
// desaloca a memorica alocada anteriormente
bool destroy_skip_list(sk_t* sk);
// insere na lista palavras nao repetidas
bool insert_skip_list(sk_t* sk, const char* word, const char* def);
// remove determinada palavra escolhida pelo usuario
bool remove_skip_list(sk_t* sk, const char* word);
// troca a definicao de uma determinada palavra selecionada pelo usuario
bool change_defword_skip_list(sk_t* sk, const char* word, const char* new_def);
// procura na skip list determinada palavra selecionada pelo usuario
bool search_skip_list(sk_t* sk, const char* word);
// imprime determinadas palavras iniciadas com um character escolhido pelo usuario
bool print_skip_list(sk_t* sk, const char character);

#endif