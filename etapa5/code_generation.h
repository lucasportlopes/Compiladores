#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

typedef struct {
    char *opcode;
    char *source1;
    char *source2;
    char *source3;
    char *label;
} ILOCOperation;

typedef struct ILOCOperationNode {
    ILOCOperation *operation;
    struct ILOCOperationNode *next;
} ILOCOperationNode;

char *generate_label();

char *generate_temp();

#endif