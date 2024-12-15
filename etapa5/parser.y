%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
#include <string.h>
#include "symbol_stack.h"
#include "code_generation.h"
extern int get_line_number();
extern void *arvore;
extern symbol_stack_t *stack;
%}

%define parse.error verbose

%code requires { #include "asd.h" }

%union {
    valor_lexico_t *valor_lexico;
    asd_tree_t *arvore_t;
    symbol_table_type_t symbol_table_type;
}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token TK_ERRO

%type<arvore_t> operandos_simples
%type<arvore_t> expressao_precedencia_1
%type<arvore_t> expressao_precedencia_2
%type<arvore_t> expressao_precedencia_3
%type<arvore_t> expressao_precedencia_4
%type<arvore_t> expressao_precedencia_5
%type<arvore_t> expressao_precedencia_6
%type<arvore_t> expressao
%type<arvore_t> fluxo_controle
%type<arvore_t> chamada_funcao
%type<arvore_t> operacao_retorno
%type<arvore_t> atribuicao
%type<arvore_t> declaracao_variavel
%type<arvore_t> comando_simples
%type<arvore_t> comandos
%type<arvore_t> bloco_comandos
%type<arvore_t> bloco_comandos_funcao
%type<arvore_t> parametro
%type<arvore_t> lista_parametros
%type<arvore_t> cabecalho_funcao
%type<arvore_t> funcao
%type<arvore_t> lista_funcoes
%type<arvore_t> programa
%type<arvore_t> literal
%type<arvore_t> lista_argumentos
%type<arvore_t> lista_variaveis
%type<symbol_table_type> tipo
%%

programa:
    abre_escopo lista_funcoes finaliza_pilha { 
        $$ = $2; 
        arvore = $$; 
        $$->code = $2->code;
        iloc_list_display($$->code);
    }
    ;

finaliza_pilha: {
    symbol_stack_free(&stack);
};

lista_funcoes:
    empty { $$ = NULL; }
    | funcao lista_funcoes {
        $$ = $1;
        if ($2 != NULL) {
            asd_add_child($$, $2);
        }
        //$$->code = iloc_list_concat($1->code, $2->code);
        $$->code = $1->code;
    }
    ;

funcao: 
    cabecalho_funcao bloco_comandos_funcao fecha_escopo {
        $$ = $1;
        if ($2 != NULL) {
            asd_add_child($$, $2);
            $$->code = $2->code;
        }
    }
    ;

cabecalho_funcao:
    TK_IDENTIFICADOR '=' abre_escopo lista_parametros '>' tipo {
        symbol_table_content_t *function_declared = symbol_stack_find(&stack, $1->valor_token);

        if (function_declared != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }

        symbol_table_type_t type;
        
        if ($6 == SYMBOL_TYPE_INT) {
            type = SYMBOL_TYPE_INT;
        } else if($6 == SYMBOL_TYPE_FLOAT) {
            type = SYMBOL_TYPE_FLOAT;
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_FUNCTION, type, NULL);
        symbol_stack_insert_at_bottom(&stack, $1->valor_token, content);

        $$ = asd_new($1->valor_token, type);
        }
    ;

abre_escopo: {
    open_scope(&stack);
} ; 

fecha_escopo: {
    close_scope(&stack);
} ;

empty: ;

tipo: 
    TK_PR_INT { $$ = SYMBOL_TYPE_INT; } 
    | TK_PR_FLOAT { $$ = SYMBOL_TYPE_FLOAT; }
    ;

lista_parametros: 
    empty { $$ = NULL; }
    | parametro TK_OC_OR lista_parametros { $$ = NULL; }
    | parametro { $$ = NULL; }
    ;

parametro:
    TK_IDENTIFICADOR '<' '-' tipo {
        if (symbol_table_find(stack->table, $1->valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(), SYMBOL_NATURE_VARIABLE, $4, NULL);
        symbol_table_insert(stack->table, $1->valor_token, content);

        $$ = NULL; 
    }
    ;

bloco_comandos_funcao:
    '{' comandos  '}' {  
        $$ = $2; 
        $$->code = $2->code; 
    }
    ;

bloco_comandos: 
    '{' comandos '}' {  
        $$ = $2;
        $$->code = $2->code;
    }
    ;

comandos: 
    empty { $$ = NULL; }
    | comando_simples comandos {
        if ($1 != NULL && $2 != NULL) {
            $$ = $1;
            asd_tree_t *deepest_node = asd_find_deepest_node($$);

            if (deepest_node != NULL) {
                asd_add_child(deepest_node, $2);     
            }
            $$->code = iloc_list_concat($1->code, $2->code);
        } else if ($1 != NULL) {
            $$ = $1;
            $$->code = $1->code;
        } else if ($2 != NULL) {
            $$ = $2;
            $$->code = $2->code;
        } else {
            $$ = NULL;
        }
    }
    ;

comando_simples: 
    declaracao_variavel ';' {  $$ = $1; }
    | atribuicao ';' {  
        $$ = $1; 
        $$->code = $1->code;
    }
    | fluxo_controle ';' {  
        $$ = $1; 
        $$->code = $1->code;
    }
    | operacao_retorno ';' {  $$ = $1; }
    | abre_escopo bloco_comandos fecha_escopo ';' { 
        $$ = $2; 
        $$->code = $2->code;
    }
    | chamada_funcao ';'  {  $$ = $1; }
    ;

declaracao_variavel: 
    tipo lista_variaveis { 
        $$ = $2; 

        symbol_table_entry_t *entry = stack->table->first_entry;

        while (entry != NULL) {
            if (entry->content->type == TODO_TYPE) {
                entry->content->type = $1;
            }
            entry = entry->next;
        }
    };
    ;

lista_variaveis:
    TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis {
        if (symbol_table_find(stack->table, $1->valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1->valor_token, content);

        $$ = asd_new("<=", UNKNOWN_TYPE); 
        asd_add_child($$, asd_new($1->valor_token, TODO_TYPE)); 
        asd_add_child($$, asd_new($3->label, UNKNOWN_TYPE)); 
        if($5 != NULL) {
            asd_add_child($$, $5);
        }
    }
    | TK_IDENTIFICADOR ',' lista_variaveis {
        if (symbol_table_find(stack->table, $1->valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }
        
        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);

        symbol_table_insert(stack->table, $1->valor_token, content);
        $$ = $3; 
    }
    | TK_IDENTIFICADOR TK_OC_LE literal {
        if (symbol_table_find(stack->table, $1->valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1->valor_token, content);

        $$ = asd_new("<=", UNKNOWN_TYPE);
        asd_add_child($$, asd_new($1->valor_token, TODO_TYPE)); 
        asd_add_child($$, asd_new($3->label, UNKNOWN_TYPE));
    }
    | TK_IDENTIFICADOR { 
        if (symbol_table_find(stack->table, $1->valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1->valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1->valor_token, content);

        $$ = NULL; 
    }
    ;

atribuicao:
    TK_IDENTIFICADOR '=' expressao { 
        symbol_table_content_t *content = symbol_stack_find(&stack, $1->valor_token);

        if (content == NULL) {
            semantic_error(ERR_UNDECLARED, $1->valor_token, get_line_number());
        } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
            semantic_error(ERR_FUNCTION, $1->valor_token, get_line_number());
        }

        $$ = asd_new("=", content->type); 
        asd_add_child($$, asd_new($1->valor_token, content->type)); 
        asd_add_child($$, $3);
        
        $$->local = generate_temp();
        char buffer[20];
        sprintf(buffer, "%d", content->displacement);

        ILOCOperation *store_op = iloc_operation_create("storeAI", $3->local, "rfp", buffer, NULL);
        $$->code = iloc_list_concat($3->code, iloc_list_create_node(store_op));
        //iloc_list_display($$->code);
        //printf("%s %s => %s, %s\n", store_op->opcode, store_op->source1, store_op->source2, store_op->source3);
    }
    ;

operacao_retorno: 
    TK_PR_RETURN expressao { $$ = asd_new("return", $2->type); asd_add_child($$, $2); }
    ;

chamada_funcao:
    TK_IDENTIFICADOR '(' lista_argumentos ')' {
        const char *CALL = "call";
        size_t size = strlen(CALL) + strlen($1->valor_token) + 2;
        char *function = (char *)malloc(size);

        if (function) {
            symbol_table_content_t *content = symbol_stack_find(&stack, $1->valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, $1->valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_VARIABLE) {
                semantic_error(ERR_VARIABLE, $1->valor_token, get_line_number());
            }

            sprintf(function, "%s %s", CALL, $1->valor_token); 

            $$ = asd_new(function, content->type);
            asd_add_child($$, $3);
            
            free(function);
        } else {
            // fprintf(stderr, "Erro na alocacao de memoria! \n");
        }
    }
    ;

lista_argumentos:
    expressao { 
        $$ = $1;
    }
    | expressao ',' lista_argumentos { 
        $$ = $1;
        asd_add_child($$, $3); 
    }
    ;

// TODO
fluxo_controle:
    TK_PR_IF '(' expressao ')' bloco_comandos {
        $$ = asd_new("if", $3->type); 
        asd_add_child($$, $3); 
        
        char *temp1 = generate_temp();
        char *temp2 = generate_temp();

        char *label1 = generate_label();
        char *label2 = generate_label();


        ILOCOperation *zero = iloc_operation_create("loadI", "0", temp1, NULL, NULL); // Carrega 0 será usado para comparar com a expressão
        ILOCOperation *op = iloc_operation_create("cmp_NE", $3->local, temp1, temp2, NULL); // Compara a expressão com 0
        ILOCOperation *cbr_op = iloc_operation_create("cbr", $3->local, label1, label2, NULL); // Se a expressão for diferente de 0, vai para label1, senão vai para label2
        
        // Implementatação de condicional usando NOP
        ILOCOperation *label1_op = iloc_operation_create("nop", NULL, NULL, NULL, label1);
        ILOCOperation *label2_op = iloc_operation_create("nop", NULL, NULL, NULL, label2);

        ILOCOperationList *block_code = NULL;
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
            block_code = $5->code;
        }
        
        $$->code = iloc_list_concat(
            $3->code,
            iloc_list_concat(
                iloc_list_create_node(zero),
                iloc_list_concat(
                    iloc_list_create_node(op),
                    iloc_list_concat(
                        iloc_list_create_node(cbr_op),
                        iloc_list_concat(
                            iloc_list_create_node(label1_op),
                            iloc_list_concat(
                                block_code,
                                iloc_list_create_node(label2_op)
                            )
                        )
                    )
                )
            )
        );
    }
    | TK_PR_IF '(' expressao ')' bloco_comandos TK_PR_ELSE bloco_comandos { 
        $$ = asd_new("if", $3->type); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
        if ($7 != NULL) { 
            asd_add_child($$, $7); 
        }  
    }
    | TK_PR_WHILE '(' expressao ')' bloco_comandos { 
        $$ = asd_new("while", $3->type); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
    }
    ;

expressao:
    expressao_precedencia_6 { $$ = $1; }
    | expressao TK_OC_OR expressao_precedencia_6 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("|", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("or", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    ;

expressao_precedencia_6:
    expressao_precedencia_5 { $$ = $1; }
    | expressao_precedencia_6 TK_OC_AND expressao_precedencia_5 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("&", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3);
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("and", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    ;

expressao_precedencia_5:
    expressao_precedencia_4 { $$ = $1; }
    | expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("==", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3);
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_EQ", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    | expressao_precedencia_5 TK_OC_NE expressao_precedencia_4 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("!=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3);
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_NE", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    ;

expressao_precedencia_4:
    expressao_precedencia_3 { $$ = $1; }
    | expressao_precedencia_4 '<' expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("<", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_LT", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    | expressao_precedencia_4 '>' expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new(">", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3);
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_GT", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    | expressao_precedencia_4 TK_OC_LE expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("<=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3);
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_LE", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    | expressao_precedencia_4 TK_OC_GE expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new(">=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("cmp_GE", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(op), $3->code));
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    ;

expressao_precedencia_3:
    expressao_precedencia_2 { $$ = $1; }
    | expressao_precedencia_3 '+' expressao_precedencia_2 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("+", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *add_op = iloc_operation_create("add", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat(iloc_list_concat($1->code, $3->code), iloc_list_create_node(add_op));
        //iloc_list_display($$->code);
        //printf("os sources do codigo 1 e 3 são %s e %s\n", $1->code->operation->source1, $3->code->operation->source1);
        //printf("%s %s, %s => %s\n", add_op->opcode, add_op->source1, add_op->source2, add_op->source3);
    }
    | expressao_precedencia_3 '-' expressao_precedencia_2 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("-", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *sub_op = iloc_operation_create("sub", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(sub_op), $3->code));
        //printf("%s %s, %s => %s\n", sub_op->opcode, sub_op->source1, sub_op->source2, sub_op->source3);
    }
    ;

expressao_precedencia_2:
    expressao_precedencia_1 { $$ = $1; }
    | expressao_precedencia_2 '*' expressao_precedencia_1 {
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("*", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *mult_op = iloc_operation_create("mult", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(mult_op), $3->code));
        //printf("%s %s, %s => %s\n", mult_op->opcode, mult_op->source1, mult_op->source2, mult_op->source3);
    }
    | expressao_precedencia_2 '/' expressao_precedencia_1 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("/", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->local = generate_temp();
        ILOCOperation *div_op = iloc_operation_create("div", $1->local, $3->local, $$->local, NULL);
        $$->code = iloc_list_concat($1->code, iloc_list_concat(iloc_list_create_node(div_op), $3->code));
        //printf("%s %s, %s => %s\n", div_op->opcode, div_op->source1, div_op->source2, div_op->source3);
    }
    | expressao_precedencia_2 '%' expressao_precedencia_1 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("%", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
        $$->code = NULL;
        $$->local = NULL;
        }
    ;

expressao_precedencia_1:
    operandos_simples { $$ = $1; }
    | '(' expressao ')' { $$ = $2; }
    | '-' expressao_precedencia_1 { $$ = asd_new("-", $2->type); asd_add_child($$, $2); 
        $$->local = generate_temp();
        char *loadReg = generate_temp();
        ILOCOperation *loadI_op = iloc_operation_create("loadI", "-1", NULL, loadReg, NULL);
        //printf("%s %s => %s\n", loadI_op->opcode, loadI_op->source1, loadI_op->source3);
        ILOCOperation *mult_op = iloc_operation_create("mult", loadReg, $2->local, $$->local, NULL);
        $$->code = iloc_list_concat(iloc_list_create_node(mult_op), $2->code);
        //printf("%s %s, %s => %s\n", mult_op->opcode, mult_op->source1, mult_op->source2, mult_op->source3);
    	}
    | '!' expressao_precedencia_1 {
        $$ = asd_new("!", $2->type); asd_add_child($$, $2); 
        $$->local = generate_temp();
        ILOCOperation *op = iloc_operation_create("xorI", $2->local, "-1", $$->local, NULL);
        $$->code = iloc_list_concat(iloc_list_create_node(op), $2->code);
        //printf("%s %s, %s => %s\n", op->opcode, op->source1, op->source2, op->source3);
    }
    ;

literal: 
    TK_LIT_INT { 
        $$ = asd_new($1->valor_token, SYMBOL_TYPE_INT);
        $$->local = generate_temp();
        ILOCOperation *loadI_op = iloc_operation_create("loadI", $$->label, $$->local, NULL, NULL);
        $$->code = iloc_list_create_node(loadI_op);
        //printf("%s %s => %s\n", loadI_op->opcode, loadI_op->source1, loadI_op->source2); 
    }
    | TK_LIT_FLOAT { $$ = asd_new($1->valor_token, SYMBOL_TYPE_FLOAT); }
    ;

operandos_simples:
        literal { $$ = $1; }
    |   TK_IDENTIFICADOR {
            symbol_table_content_t *content = symbol_stack_find(&stack, $1->valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, $1->valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
                semantic_error(ERR_FUNCTION, $1->valor_token, get_line_number());
            }
            $$ = asd_new($1->valor_token, content->type); 
            $$->local = generate_temp();
            char buffer[20];
            sprintf(buffer, "%d", content->displacement);
            ILOCOperation *loadAI_op = iloc_operation_create("loadAI", "rfp", buffer, $$->local, NULL);
            $$->code = iloc_list_create_node(loadAI_op);
            //printf("%s %s, %s => %s\n", loadAI_op->opcode, loadAI_op->source1, loadAI_op->source2, loadAI_op->source3);
        }
    |   chamada_funcao { 
        $$ = $1; 
    }
    ;
%%

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}
