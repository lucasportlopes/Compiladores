#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tmp_counter = 0;
char *generate_temp();
char *generate_temp() {
  char *tmp = malloc(6);
  sprintf(tmp, "r%d", tmp_counter++);
  return tmp;
}