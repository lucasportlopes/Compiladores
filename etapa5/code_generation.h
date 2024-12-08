#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

typedef struct {
    char *opcode;
    char *source1;
    char *source2;
    char *source3;
    char *label;
} ILOCOperation;

typedef struct ILOCOperationList {
    ILOCOperation *operation;
    struct ILOCOperationList *next;
} ILOCOperationList;

char *generate_label();

char *generate_temp();

// Function to create a new ILOC operation
ILOCOperation *iloc_operation_create(char *opcode, char *source1, char *source2, char *source3, char *label);

// Function to create a new ILOC operation list
ILOCOperationList *iloc_list_create_node(ILOCOperation *operation);

// Function to concatenate two ILOC operation lists
ILOCOperationList *iloc_list_concat(ILOCOperationList *list1, ILOCOperationList *list2);

// Function to insert an list of ILOC operations in an ILOC operation list
void *iloc_list_insert_list(ILOCOperationList *list, ILOCOperationList *operation_list);

// Function to insert an ILOC operation in an ILOC operation list
void iloc_list_insert(ILOCOperation *operation, ILOCOperationList *operation_list);

// Function to destroy an ILOC operation list
void iloc_list_destroy(ILOCOperationList *operation_list);

// Function to display an ILOC operation list
void iloc_list_display(ILOCOperationList *operation_list);

#endif