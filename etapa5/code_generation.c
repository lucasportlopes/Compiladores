#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "code_generation.h"
#include "instructions.h"

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
    // ILOCOperationList *result = NULL;
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    // ILOCOperationList *current = list1;
    // while (current != NULL) {
    //     printf("no while curr é %s\n", current->operation->opcode);
    //     iloc_insert_list(current->operation, result);
    //     current = current->next;
    // }

    // current = list2;
    // while (current != NULL) {
    //     iloc_insert_list(current->operation, result);
    //     current = current->next;
    // }
    
    // return result;
    ILOCOperationList *result = list1;

    ILOCOperationList *current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;

    return result;
}

void *iloc_list_insert_list(ILOCOperationList *list, ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;

    while (current_list != NULL) {
        iloc_insert_list(current_list->operation, list);
        current_list = current_list->next;
    }
}

void iloc_list_display(ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;

    while (current_list != NULL) {
        if (current_list->operation->label != NULL) {
            printf("%s:\n", current_list->operation->label);
        }

        if (strcmp(current_list->operation->opcode, ADD) == 0 || 
            strcmp(current_list->operation->opcode, SUB) == 0 || 
            strcmp(current_list->operation->opcode, MULT) == 0 || 
            strcmp(current_list->operation->opcode, DIV) == 0 || 
            strcmp(current_list->operation->opcode, ADDI) == 0 || 
            strcmp(current_list->operation->opcode, SUBI) == 0 || 
            strcmp(current_list->operation->opcode, RSUBI) == 0 || 
            strcmp(current_list->operation->opcode, MULTI) == 0 || 
            strcmp(current_list->operation->opcode, DIVI) == 0 || 
            strcmp(current_list->operation->opcode, RDIVI) == 0 || 
            strcmp(current_list->operation->opcode, LSHIFT) == 0 || 
            strcmp(current_list->operation->opcode, LSHIFTI) == 0 || 
            strcmp(current_list->operation->opcode, RSHIFT) == 0 || 
            strcmp(current_list->operation->opcode, RSHIFTI) == 0 || 
            strcmp(current_list->operation->opcode, AND) == 0 || 
            strcmp(current_list->operation->opcode, ANDI) == 0 || 
            strcmp(current_list->operation->opcode, OR) == 0 || 
            strcmp(current_list->operation->opcode, ORI) == 0 || 
            strcmp(current_list->operation->opcode, XOR) == 0 || 
            strcmp(current_list->operation->opcode, XORI) == 0 ||
            strcmp(current_list->operation->opcode, CMP_LT) == 0 || 
            strcmp(current_list->operation->opcode, CMP_LE) == 0 || 
            strcmp(current_list->operation->opcode, CMP_EQ) == 0 || 
            strcmp(current_list->operation->opcode, CMP_GE) == 0 || 
            strcmp(current_list->operation->opcode, CMP_GT) == 0 || 
            strcmp(current_list->operation->opcode, CMP_NE) == 0 ||
            strcmp(current_list->operation->opcode, LOADAI) == 0 || 
            strcmp(current_list->operation->opcode, LOADA0) == 0 ||
            strcmp(current_list->operation->opcode, CLOADAI) == 0 || 
            strcmp(current_list->operation->opcode, CLOADA0) == 0) {
            printf("%s %s, %s => %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2, current_list->operation->source3);
        } else if (
            strcmp(current_list->operation->opcode, LOADI) == 0 || 
            strcmp(current_list->operation->opcode, LOAD) == 0 || 
            strcmp(current_list->operation->opcode, CLOAD) == 0 || 
            strcmp(current_list->operation->opcode, STORE) == 0 || 
            strcmp(current_list->operation->opcode, CSTORE) == 0 || 
            strcmp(current_list->operation->opcode, I2I) == 0 || 
            strcmp(current_list->operation->opcode, C2C) == 0 || 
            strcmp(current_list->operation->opcode, C2I) == 0 || 
            strcmp(current_list->operation->opcode, I2C) == 0) {
            printf("%s %s => %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2);
        } else if (
            strcmp(current_list->operation->opcode, STOREAI) == 0 || 
            strcmp(current_list->operation->opcode, STOREAO) == 0 || 
            strcmp(current_list->operation->opcode, CSTOREAI) == 0 || 
            strcmp(current_list->operation->opcode, CSTOREAO) == 0 ||
            strcmp(current_list->operation->opcode, CBR) == 0) {
            printf("%s %s => %s, %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2, current_list->operation->source3);
        } else if (
            strcmp(current_list->operation->opcode, JUMPI) == 0 || 
            strcmp(current_list->operation->opcode, JUMP) == 0) {
            printf("%s => %s\n", current_list->operation->opcode, current_list->operation->source1);
        }

        current_list = current_list->next;
    }
}
