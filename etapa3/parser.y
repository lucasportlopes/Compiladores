%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
extern int get_line_number();
extern void *arvore;
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
%type<arvore_t> parametro
%type<arvore_t> lista_parametros
%type<arvore_t> cabecalho_funcao
%type<arvore_t> funcao
%type<arvore_t> lista_funcoes
%type<arvore_t> programa
%type<arvore_t> literal

%%

programa: 
    lista_funcoes { 
        $$ = $1;  arvore = $$;
        }
    ;

lista_funcoes:
    empty { 
        /* $$ = NULL; */
         }
    | lista_funcoes funcao { 
        /* $$ = $1; */ 
        /* asd_add_child($$, $2); */
    }
    ;

empty: { 
    /* $$ = NULL */ 
    };

tipo: 
    TK_PR_INT | TK_PR_FLOAT 
    ;

funcao: 
    cabecalho_funcao bloco_comandos {
        /* $$ = $1;*/
        /* asd_add_child($$, $2); */
    }
    ;

cabecalho_funcao: 
    TK_IDENTIFICADOR '=' lista_parametros '>' tipo
    ;

lista_parametros: 
    empty { 
        /* $$ = NULL; */
        }
    | lista_parametros TK_OC_OR parametro {
        /* $$ = $1;*/
        /* asd_add_child($$, $3); */
    }
    | parametro  { 
        /* $$ = $1 */
        }
    ;

parametro:
    TK_IDENTIFICADOR '<' '-' tipo 
    ;

bloco_comandos: 
    '{' comandos '}' 
    ;

comandos: 
    empty
    | comandos comando_simples 
    ;

comando_simples: 
    declaracao_variavel ';'
    | atribuicao ';'
    | fluxo_controle ';'
    | operacao_retorno ';'
    | bloco_comandos ';'
    | chamada_funcao ';' 
    ;

declaracao_variavel: 
    tipo lista_variaveis 
    ;

lista_variaveis: 
    lista_variaveis ',' TK_IDENTIFICADOR inicializacao_opcional
    | TK_IDENTIFICADOR inicializacao_opcional 
    ;

inicializacao_opcional: 
    TK_OC_LE literal
    | empty 
    ;

atribuicao:
    TK_IDENTIFICADOR '=' expressao 
    ;

operacao_retorno: 
    TK_PR_RETURN expressao 
    ;

chamada_funcao: 
    TK_IDENTIFICADOR '(' lista_argumentos ')' 
    ;

lista_argumentos: 
    lista_argumentos ',' expressao
    | expressao 
    ;

fluxo_controle:
    TK_PR_IF '(' expressao ')' bloco_comandos
    | TK_PR_IF '(' expressao ')' bloco_comandos TK_PR_ELSE bloco_comandos
    | TK_PR_WHILE '(' expressao ')' bloco_comandos
    ;

expressao:
    expressao_precedencia_6 { $$ = $1; }
    | expressao TK_OC_OR expressao_precedencia_6
    ;

expressao_precedencia_6:
    expressao_precedencia_5 { $$ = $1; }
    | expressao_precedencia_6 TK_OC_AND expressao_precedencia_5
    ;

expressao_precedencia_5:
    expressao_precedencia_4 { $$ = $1; }
    | expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4
    | expressao_precedencia_5 TK_OC_NE expressao_precedencia_4
    ;

expressao_precedencia_4:
    expressao_precedencia_3 { $$ = $1; }
    | expressao_precedencia_4 '<' expressao_precedencia_3
    | expressao_precedencia_4 '>' expressao_precedencia_3
    | expressao_precedencia_4 TK_OC_LE expressao_precedencia_3
    | expressao_precedencia_4 TK_OC_GE expressao_precedencia_3
    ;

expressao_precedencia_3:
    expressao_precedencia_2 { $$ = $1; }
    | expressao_precedencia_3 '+' expressao_precedencia_2
    | expressao_precedencia_3 '-' expressao_precedencia_2
    ;

expressao_precedencia_2:
    expressao_precedencia_1 {  $$ = $1; }
    | expressao_precedencia_2 '*' expressao_precedencia_1
    | expressao_precedencia_2 '/' expressao_precedencia_1
    | expressao_precedencia_2 '%' expressao_precedencia_1
    ;

expressao_precedencia_1:
    operandos_simples { $$ = $1; }
    | '(' expressao ')' { $$ = $2; }
    | '-' expressao_precedencia_1
    | '!' expressao_precedencia_1 
    ;

literal: 
    TK_LIT_INT { 
        /* $$ = asd_new_lexico($1); */
        $$ = asd_new("test_int"); 
        }
    | TK_LIT_FLOAT { 
        /* $$ = asd_new_lexico($1); */ 
        $$ = asd_new("test_float"); 
        }
    ;

operandos_simples:
        literal { 
            /* $$ = asd_new_lexico($1); */
            $$ = asd_new("test_literal"); 
            }
    |   TK_IDENTIFICADOR { 
            $$ = asd_new("test_identificador"); 
            /* $$ = asd_new_lexico($1); */ 
        }
    |   chamada_funcao
    ;

%%

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}