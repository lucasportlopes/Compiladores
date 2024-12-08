#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "code_generation.h"

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

ILOCOperation *iloc_operation_create(char *opcode, char *source1, char *source2, char *source3, char *label) {
    ILOCOperation *operation = malloc(sizeof(ILOCOperation));

    if (operation == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a operação ILOC\n");
        exit(EXIT_FAILURE);
    }

    operation->opcode = opcode;
    operation->source1 = source1;
    operation->source2 = source2;
    operation->source3 = source3;
    operation->label = label;
    
    return operation;
}

ILOCOperationList *iloc_list_create_node(ILOCOperation *operation) {
    ILOCOperationList *operation_list = malloc(sizeof(ILOCOperationList));

    if (operation_list == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de operações ILOC\n");
        exit(EXIT_FAILURE);
    }

    operation_list->operation = operation;
    operation_list->next = NULL;

    return operation_list;
}

void iloc_insert_list(ILOCOperation *operation, ILOCOperationList *operation_list) {
    ILOCOperationList *new_node = iloc_list_create_node(operation);

    if (operation_list == NULL) {
        operation_list = new_node;
    } else {
        ILOCOperationList *current = operation_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


void iloc_list_destroy(ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;
    ILOCOperationList *next_list = NULL;

    while (current_list != NULL) {
        next_list = current_list->next;
        free(current_list->operation->opcode);
        free(current_list->operation->source1);
        free(current_list->operation->source2);
        free(current_list->operation->source3);
        free(current_list->operation->label);
        free(current_list->operation);
        free(current_list);
        current_list = next_list;
    }
}

ILOCOperationList *iloc_list_concat(ILOCOperationList *list1, ILOCOperationList *list2) {
  // Desenvolver
}

void *iloc_list_insert_list(ILOCOperationList *list, ILOCOperationList *operation_list) {
    // Desenvolver
}

void iloc_list_display(ILOCOperationList *operation_list) {
    // Desenvolver
}

