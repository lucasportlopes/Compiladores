#include <stdio.h>
#include "asd.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
symbol_stack_t *stack = NULL;
void exporta (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  asd_print(arvore);
  asd_print_graphviz(arvore);
  asd_free(arvore);
  yylex_destroy();
  return ret;
}