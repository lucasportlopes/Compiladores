#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para criar conteúdo de símbolo
symbol_table_content_t *create_symbol_content(int line, symbol_table_nature_t nature, symbol_table_type_t type) {
    symbol_table_content_t *content = malloc(sizeof(symbol_table_content_t));
    if (!content) {
        fprintf(stderr, "Erro ao alocar memória para o conteúdo do símbolo.\n");
        exit(EXIT_FAILURE);
    }
    content->line = line;
    content->nature = nature;
    content->type = type;
    content->value = NULL; // Supondo que o valor léxico não é necessário aqui
    return content;
}

int main() {
    printf("=== Teste da Tabela de Símbolos ===\n");

    // 1. Criar uma tabela de símbolos
    symbol_table_t *table = symbol_table_create(NULL);
    printf("Tabela de símbolos criada com sucesso.\n");

    // 2. Inserir símbolos na tabela
    symbol_table_content_t *content1 = create_symbol_content(1, SYMBOL_NATURE_VARIABLE, SYMBOL_TYPE_INT);
    symbol_table_insert(table, "variavelX", content1);
    printf("Símbolo 'variavelX' inserido com sucesso.\n");

    symbol_table_content_t *content2 = create_symbol_content(2, SYMBOL_NATURE_FUNCTION, SYMBOL_TYPE_FLOAT);
    symbol_table_insert(table, "funcaoY", content2);
    printf("Símbolo 'funcaoY' inserido com sucesso.\n");

    // 3. Verificar inserções
    symbol_table_entry_t *entry = table->first_entry;
    printf("Verificando inserções:\n");
    while (entry) {
        printf(" - Símbolo: %s, Linha: %d, Natureza: %d, Tipo: %d\n",
               entry->key, entry->content->line, entry->content->nature, entry->content->type);
        entry = entry->next;
    }

    // 4. Liberar a tabela
    symbol_table_free(table);
    printf("Tabela de símbolos liberada com sucesso.\n");

    return 0;
}
