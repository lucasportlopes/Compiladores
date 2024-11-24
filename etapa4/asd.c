#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "asd.h"
#include "symbol_table.h"
#define ARQUIVO_SAIDA "saida.dot"

asd_tree_t *asd_new(const char *label, symbol_table_type_t type)
{
  asd_tree_t *ret = NULL;
  ret = calloc(1, sizeof(asd_tree_t));
  if (ret != NULL){
    ret->label = strdup(label);
    ret->number_of_children = 0;
    ret->children = NULL;
    ret->type = type;
  }
  return ret;
}

void asd_free(asd_tree_t *tree)
{
  if (tree != NULL){
    int i;
    for (i = 0; i < tree->number_of_children; i++){
      asd_free(tree->children[i]);
    }
    free(tree->children);
    free(tree->label);
    free(tree);
  }
}

void asd_add_child(asd_tree_t *tree, asd_tree_t *child)
{
  if (tree != NULL && child != NULL){
    tree->number_of_children++;
    tree->children = realloc(tree->children, tree->number_of_children * sizeof(asd_tree_t*));
    tree->children[tree->number_of_children-1] = child;
  }
}

static void _asd_print (FILE *foutput, asd_tree_t *tree, int profundidade)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade*2, "", tree->label, tree->number_of_children);
    for (i = 0; i < tree->number_of_children; i++){
      _asd_print(foutput, tree->children[i], profundidade+1);
    }
  }
}

void asd_print(asd_tree_t *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL){
    _asd_print(foutput, tree, 0);
  }
}

static void _asd_print_graphviz (FILE *foutput, asd_tree_t *tree)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->label);
    for (i = 0; i < tree->number_of_children; i++){
      fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->children[i]);
      _asd_print_graphviz(foutput, tree->children[i]);
    }
  }
}

void asd_print_graphviz(asd_tree_t *tree)
{
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
  if(foutput == NULL){
    printf("Erro: %s não pude abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
  }
  if (tree != NULL){
    fprintf(foutput, "digraph grafo {\n");
    _asd_print_graphviz(foutput, tree);
    fprintf(foutput, "}\n");
    fclose(foutput);
  }
}

void exporta(asd_tree_t *tree)
{
  int i;
  if (tree != NULL) {
    fprintf(stdout, "%p [label=\"%s\"];\n", tree, tree->label);
    
    for (i = 0; i < tree->number_of_children; i++) {
        fprintf(stdout, "%p, %p\n", tree, tree->children[i]);
        exporta(tree->children[i]);
    }
  }
}

asd_tree_t *find_last_declaration(asd_tree_t *node) {
    if (node == NULL) {
        return NULL;
    }

    for (int i = node->number_of_children - 1; i >= 0; i--) {
        if (node->children[i] != NULL && strcmp(node->children[i]->label, "<=") == 0) {
            return find_last_declaration(node->children[i]);
        }
    }

    // se nenhum filho é uma declaração, então o nó encontrado é a única declaração
    return node;
}

asd_tree_t* asd_find_deepest_node(asd_tree_t *node)
{  
  if (node != NULL){
    while (node->children[node->number_of_children - 1] != NULL && node->number_of_children > 2){
      node = node->children[node->number_of_children - 1];
    }
    return node;
  }
}