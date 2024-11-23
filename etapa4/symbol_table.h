#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

// Definições de erros semânticos
#define ERR_UNDECLARED 10 // Símbolo não declarado
#define ERR_DECLARED 11   // Símbolo já declarado
#define ERR_VARIABLE 20   // Uso inválido de variável
#define ERR_FUNCTION 21   // Uso inválido de função

#include "asd.h"

// Enum para a natureza do símbolo
typedef enum {
    SYMBOL_NATURE_VARIABLE,
    SYMBOL_NATURE_FUNCTION
} symbol_table_nature_t;

// Enum para o tipo do dado
typedef enum {
    SYMBOL_TYPE_INT,
    SYMBOL_TYPE_FLOAT
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

/**
 * @brief Cria uma nova tabela de símbolos.
 * @param parent Ponteiro para o escopo pai ou NULL se for a tabela global.
 * @return Ponteiro para a nova tabela de símbolos.
 */
symbol_table_t *symbol_table_create(symbol_table_t *parent);

/**
 * @brief Libera a memória associada a uma tabela de símbolos.
 * @param table Ponteiro para a tabela de símbolos a ser liberada.
 */
void symbol_table_free(symbol_table_t *table);

/**
 * @brief Insere um símbolo na tabela de símbolos.
 * @param table Ponteiro para a tabela onde o símbolo será inserido.
 * @param key Nome (lexema) do símbolo.
 * @param content Ponteiro para o conteúdo associado ao símbolo.
 */
void symbol_table_insert(symbol_table_t *table, char *key, symbol_table_content_t *content);

/**
 * @brief Procura um símbolo na tabela de símbolos e seus escopos pais.
 * @param table Ponteiro para a tabela de símbolos inicial.
 * @param key Nome (lexema) do símbolo a ser buscado.
 * @return Ponteiro para a entrada do símbolo encontrado ou NULL se não encontrado.
 */
symbol_table_entry_t *symbol_table_find(symbol_table_t *table, const char *key);

#endif // _SYMBOL_TABLE_H_
