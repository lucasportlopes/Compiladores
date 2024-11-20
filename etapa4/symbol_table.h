#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define ERR_UNDECLARED 10
#define ERR_DECLARED 11
#define ERR_VARIABLE 20
#define ERR_FUNCTION 21

#include "asd.h"

// Enum para a natureza do símbolo
typedef enum {
    SYMBOL_NATURE_VARIABLE,  // Variável
    SYMBOL_NATURE_FUNCTION   // Função
} symbol_table_nature_t;

// Enum para o tipo do dado
typedef enum {
    SYMBOL_TYPE_INT,   // Inteiro
    SYMBOL_TYPE_FLOAT  // Float
} symbol_table_type_t;

// Estrutura para o conteúdo de uma entrada na tabela de símbolos
typedef struct {
    int line;                         // Linha no código onde foi declarado
    symbol_table_nature_t nature;     // Natureza: variável ou função
    symbol_table_type_t type;         // Tipo do dado: int ou float
    valor_lexico_t *value;            // Valor léxico associado ao símbolo
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

#endif // _SYMBOL_TABLE_H_
