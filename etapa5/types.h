#ifndef _TYPES_H_
#define _TYPES_H_

// Enum para o tipo do dado
typedef enum {
    SYMBOL_TYPE_INT,
    SYMBOL_TYPE_FLOAT,
    TODO_TYPE,
    UNKNOWN_TYPE,
} symbol_table_type_t;

typedef enum {
  IDENTIFICADOR,
  LITERAL,
} tipo_lexico_enum;

typedef struct valor_lexico {
    int linha;
    tipo_lexico_enum tipo_token;
    char *valor_token;
} valor_lexico_t;

// Enum para a natureza do símbolo
typedef enum {
    SYMBOL_NATURE_VARIABLE,
    SYMBOL_NATURE_FUNCTION
} symbol_table_nature_t;

// Estrutura para o conteúdo de uma entrada na tabela de símbolos
typedef struct {
    int line;                         // Linha no código onde foi declarado
    symbol_table_nature_t nature;     // Natureza: variável ou função
    symbol_table_type_t type;         // Tipo do dado: int ou float
    valor_lexico_t *value;            // Valor léxico associado ao símbolo
    int displacement;
} symbol_table_content_t;

// Estrutura para uma entrada na tabela de símbolos
typedef struct symbol_table_entry_t {
    char *key;                            // Chave única (nome do símbolo)
    symbol_table_content_t *content;      // Conteúdo associado ao símbolo
    struct symbol_table_entry_t *next;    // Próxima entrada na lista encadeada
} symbol_table_entry_t;

// Estrutura para a tabela de símbolos
typedef struct symbol_table_t {
    symbol_table_entry_t *first_entry;    // Ponteiro para a primeira entrada
    struct symbol_table_t *parent;       // Ponteiro para a tabela de símbolos pai (escopo superior)
} symbol_table_t;

typedef struct symbol_stack_t {
    symbol_table_t *table;
    struct symbol_stack_t *next;
} symbol_stack_t;

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

#endif //_TYPES_H_