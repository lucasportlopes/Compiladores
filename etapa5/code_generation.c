#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int tmp_counter = 0;
static int label_counter = 0;

char *generate_temp() {
  char *tmp = malloc(16 * sizeof(char));
  sprintf(tmp, "r%d", tmp_counter++);
  return tmp;
}

char *generate_label() {
  char *label = malloc(16 * sizeof(char));
  sprintf(label, "L%d", label_counter++);
  return label;
}