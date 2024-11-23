#ifndef _ARVORE_H_
#define _ARVORE_H_

#include "symbol_table.h"

typedef enum {
  IDENTIFICADOR,
  LITERAL,
} tipo_lexico_enum;

typedef struct asd_tree {
  char *label;
  int number_of_children;
  struct asd_tree **children;
  symbol_table_type_t type;
} asd_tree_t;

typedef struct valor_lexico {
    int linha;
    tipo_lexico_enum tipo_token;
    char *valor_token;
} valor_lexico_t;

/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
asd_new(const char *label, symbol_table_type_t type);

/*
 * Função asd_tree, libera recursivamente o nó e seus filhos.
 */
void asd_free(asd_tree_t *tree);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */
void asd_add_child(asd_tree_t *tree, asd_tree_t *child);

/*
 * Função asd_print, imprime recursivamente a árvore.
 */
void asd_print(asd_tree_t *tree);

/*
 * Função asd_print_graphviz, idem, em formato DOT
 */
void asd_print_graphviz (asd_tree_t *tree);

asd_tree_t *find_last_declaration(asd_tree_t *node);
#endif //_ARVORE_H_