#include <stdio.h>
#include "asd.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void *stack = NULL;
void exporta (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  printf("\n\n\t\tRET IS %d\n\n", ret);
  exporta (arvore);
  asd_print(arvore);
  asd_print_graphviz(arvore);
  asd_free(arvore);
  yylex_destroy();
  return ret;
}