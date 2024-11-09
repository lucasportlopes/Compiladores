#include <stdio.h>
#include "asd.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  asd_print(arvore);
  asd_print_graphviz(arvore);
  exporta (arvore);
  yylex_destroy();
  return ret;
}