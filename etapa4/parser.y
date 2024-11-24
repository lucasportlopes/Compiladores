%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
#include <string.h>
#include "symbol_stack.h"
extern int get_line_number();
extern void *arvore;
extern symbol_stack_t *stack;
%}

%define parse.error verbose

%code requires { #include "asd.h" }

%union {
    valor_lexico_t valor_lexico;
    asd_tree_t *arvore_t;
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
%type<arvore_t> tipo
%type<arvore_t> escopo_global
%%

escopo_global: abre_escopo programa fecha_escopo {
    $$ = $2;
}

programa:
    lista_funcoes { 
        $$ = $1; 
        arvore = $$; 
    }
    ;

// inicia_pilha: {
//     symbol_table_t *escopo_global = symbol_table_create(NULL);
//     stack = symbol_stack_create(escopo_global);
// } ;

lista_funcoes:
    empty { $$ = NULL; }
    | funcao lista_funcoes {
        $$ = $1;
        if ($2 != NULL) {
            asd_add_child($$, $2);
        }
    }
    ;

funcao: 
    cabecalho_funcao bloco_comandos_funcao fecha_escopo {
        $$ = $1;
        if ($2 != NULL) {
            asd_add_child($$, $2);
        }
    }
    ;

cabecalho_funcao:
    TK_IDENTIFICADOR '=' abre_escopo lista_parametros '>' tipo {
        if (symbol_table_find(stack->table->parent , $1.valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1.valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_FUNCTION, TODO_TYPE, NULL);
        symbol_table_insert(stack->table->parent, $1.valor_token, content);

        symbol_table_type_t type;
        
        if ($6->type == SYMBOL_TYPE_INT) {
            type = SYMBOL_TYPE_INT;
        } else if($6->type == SYMBOL_TYPE_FLOAT) {
            type = SYMBOL_TYPE_FLOAT;
        }

        $$ = asd_new($1.valor_token, type); 
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
    TK_PR_INT { $$ = SYMBOL_TYPE_INT } 
    | TK_PR_FLOAT { $$ = SYMBOL_TYPE_FLOAT }
    ;

lista_parametros: 
    empty { $$ = NULL; }
    | parametro TK_OC_OR lista_parametros { $$ = NULL; }
    | parametro { $$ = NULL; }
    ;

parametro:
    TK_IDENTIFICADOR '<' '-' tipo { $$ = NULL; }
    ;

bloco_comandos_funcao:
    '{' comandos  '}' {  $$ = $2; }
    ;

bloco_comandos: 
    '{' comandos '}' {  $$ = $2; }
    ;

comandos: 
    empty { $$ = NULL; }
    | comando_simples comandos {
        // todo: tentar resolver o problema com mudança nas produções ao invés de usar find_last_declaration
        if ($1 != NULL && $2 != NULL) {
            $$ = $1;
            // se tiver alguma declaração na lista_variaveis, procura 
            // pelo último "<=" para usar como parent para o próximo node
            if (strcmp($1->label, "<=") == 0) {
                asd_tree_t *last_declaration = find_last_declaration($1);

                if (last_declaration != NULL) {
                    asd_add_child(last_declaration, $2);
                }
            } else {
                // caso contrário a lista_variáveis não teve nenhuma inicialização, então apenas adiciona o filho
                asd_add_child($$, $2);
            }        
        } else if ($1 != NULL) {
            $$ = $1;
        } else if ($2 != NULL) {
            $$ = $2;
        } else {
            $$ = NULL;
        }
    }
    ;

comando_simples: 
    declaracao_variavel ';' {  $$ = $1; }
    | atribuicao ';' {  $$ = $1; }
    | fluxo_controle ';' {  $$ = $1; }
    | operacao_retorno ';' {  $$ = $1; }
    | abre_escopo bloco_comandos fecha_escopo ';' { $$ = $2; }
    | chamada_funcao ';'  {  $$ = $1; }
    ;

declaracao_variavel: 
    tipo lista_variaveis { $$ = $2; };
    ;

// TODO: Ajustar tipo
lista_variaveis:
    TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis {
        if (symbol_table_find(stack->table, $1.valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1.valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1.valor_token, content);

        $$ = asd_new("<=", TODO_TYPE); 
        asd_add_child($$, asd_new($1.valor_token, TODO_TYPE)); 
        asd_add_child($$, asd_new($3->label, TODO_TYPE)); 
        if($5 != NULL) {
            asd_add_child($$, $5);
        }
    }
    | TK_IDENTIFICADOR ',' lista_variaveis {
        if (symbol_table_find(stack->table, $1.valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1.valor_token, get_line_number());
        }
        
        // para pegar o tipo vai ser necessário "salvar" o tipo que está na declaracao_variavel de alguma forma
        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);

        symbol_table_insert(stack->table, $1.valor_token, content);
        $$ = $3; 
    }
    | TK_IDENTIFICADOR TK_OC_LE literal {
        if (symbol_table_find(stack->table, $1.valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1.valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1.valor_token, content);

        $$ = asd_new("<=", TODO_TYPE);
        asd_add_child($$, asd_new($1.valor_token, TODO_TYPE)); 
        asd_add_child($$, asd_new($3->label, TODO_TYPE));
    }
    | TK_IDENTIFICADOR { 
        if (symbol_table_find(stack->table, $1.valor_token) != NULL) {
            semantic_error(ERR_DECLARED, $1.valor_token, get_line_number());
        }

        symbol_table_content_t *content = create_content(get_line_number(),  SYMBOL_NATURE_VARIABLE, TODO_TYPE, NULL);
        symbol_table_insert(stack->table, $1.valor_token, content);

        $$ = NULL; 
    }
    ;

atribuicao:
    TK_IDENTIFICADOR '=' expressao { 
        symbol_table_content_t *content = symbol_stack_find(&stack, $1.valor_token);

        if (content == NULL) {
            semantic_error(ERR_UNDECLARED, $1.valor_token, get_line_number());
        } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
            semantic_error(ERR_FUNCTION, $1.valor_token, get_line_number());
        }

        $$ = asd_new("=", content->type); 
        asd_add_child($$, asd_new($1.valor_token, content->type)); 
        asd_add_child($$, $3);
    }
    ;

operacao_retorno: 
    TK_PR_RETURN expressao { $$ = asd_new("return", $2->type); asd_add_child($$, $2); }
    ;

chamada_funcao:
    TK_IDENTIFICADOR '(' lista_argumentos ')' {
        const char *CALL = "call";
        size_t size = strlen(CALL) + strlen($1.valor_token) + 2;
        char *function = (char *)malloc(size);

        if (function) {
            symbol_table_content_t *content = symbol_stack_find(&stack, $1.valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, $1.valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_VARIABLE) {
                semantic_error(ERR_VARIABLE, $1.valor_token, get_line_number());
            }

            sprintf(function, "%s %s", CALL, $1.valor_token); 

            $$ = asd_new(function, content->type);
            asd_add_child($$, $3);
            
            free(function);
        } else {
            fprintf(stderr, "Erro na alocacao de memoria! \n");
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

fluxo_controle:
    TK_PR_IF '(' expressao ')' bloco_comandos {
        $$ = asd_new("if", $3->type); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
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
    }
    ;

expressao_precedencia_6:
    expressao_precedencia_5 { $$ = $1; }
    | expressao_precedencia_6 TK_OC_AND expressao_precedencia_5 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("&", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    ;

expressao_precedencia_5:
    expressao_precedencia_4 { $$ = $1; }
    | expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("==", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_5 TK_OC_NE expressao_precedencia_4 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("!=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    ;

expressao_precedencia_4:
    expressao_precedencia_3 { $$ = $1; }
    | expressao_precedencia_4 '<' expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("<", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_4 '>' expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new(">", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_4 TK_OC_LE expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("<=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_4 TK_OC_GE expressao_precedencia_3 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new(">=", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    ;

expressao_precedencia_3:
    expressao_precedencia_2 { $$ = $1; }
    | expressao_precedencia_3 '+' expressao_precedencia_2 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("+", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_3 '-' expressao_precedencia_2 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("-", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    ;

expressao_precedencia_2:
    expressao_precedencia_1 { $$ = $1; }
    | expressao_precedencia_2 '*' expressao_precedencia_1 {
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("*", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_2 '/' expressao_precedencia_1 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("/", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); 
    }
    | expressao_precedencia_2 '%' expressao_precedencia_1 { 
        symbol_table_type_t type = infer_type($1->type, $3->type);
        $$ = asd_new("%", type); 
        asd_add_child($$, $1); 
        asd_add_child($$, $3); }
    ;

expressao_precedencia_1:
    operandos_simples { $$ = $1; }
    | '(' expressao ')' { $$ = $2; }
    | '-' expressao_precedencia_1 { $$ = asd_new("-", $2->type); asd_add_child($$, $2); }
    | '!' expressao_precedencia_1 {$$ = asd_new("!", $2->type); asd_add_child($$, $2); }
    ;

literal: 
    TK_LIT_INT { $$ = asd_new($1.valor_token, SYMBOL_TYPE_INT); }
    | TK_LIT_FLOAT { $$ = asd_new($1.valor_token, SYMBOL_TYPE_FLOAT); }
    ;

operandos_simples:
        literal { $$ = $1; }
    |   TK_IDENTIFICADOR {
            symbol_table_content_t *content = symbol_stack_find(&stack, $1.valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, $1.valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
                semantic_error(ERR_FUNCTION, $1.valor_token, get_line_number());
            }

            $$ = asd_new($1.valor_token, content->type); 
        }
    |   chamada_funcao { $$ = $1; }
    ;
%%

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}