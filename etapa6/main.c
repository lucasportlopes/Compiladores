#include <stdio.h>
#include "asd.h"
#include "code_generation.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
symbol_stack_t *stack = NULL;
void exporta (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  // exporta (arvore);
  //asd_print(arvore);
  //asd_print_graphviz(arvore);
  asd_tree_t arvoreIloc = *((asd_tree_t *)arvore);
  ILOCOperationList *operations = arvoreIloc.code;
  // iloc_list_display(operations);
  asm_list_display(operations);
  asd_free(arvore);
  yylex_destroy();
  return ret;
}