%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
extern int get_line_number();
%}

%define parse.error verbose

%union {
    valor_lexico_t valor_lexico;
    asd_tree_t *arvore;
}
%code requires { #include "asd.h" }

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

%type<arvore> operandos_simples
%type<arvore> expressao_precedencia_1
%type<arvore> expressao_precedencia_2
%type<arvore> expressao_precedencia_3
%type<arvore> expressao_precedencia_4
%type<arvore> expressao_precedencia_5
%type<arvore> expressao_precedencia_6
%type<arvore> expressao
%type<arvore> fluxo_controle
%type<arvore> chamada_funcao
%type<arvore> operacao_retorno
%type<arvore> atribuicao
%type<arvore> declaracao_variavel
%type<arvore> comando_simples
%type<arvore> comandos
%type<arvore> bloco_comandos
%type<arvore> parametro
%type<arvore> lista_parametros
%type<arvore> cabecalho_funcao
%type<arvore> funcao
%type<arvore> lista_funcoes
%type<arvore> programa
%type<arvore> literal

%%

programa: 
    lista_funcoes { 
        /* $$ = s1; */ 
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
    expressao_precedencia_6
    | expressao TK_OC_OR expressao_precedencia_6
    ;

expressao_precedencia_6:
    expressao_precedencia_5
    | expressao_precedencia_6 TK_OC_AND expressao_precedencia_5
    ;

expressao_precedencia_5:
    expressao_precedencia_4
    | expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4
    | expressao_precedencia_5 TK_OC_NE expressao_precedencia_4
    ;

expressao_precedencia_4:
    expressao_precedencia_3
    | expressao_precedencia_4 '<' expressao_precedencia_3
    | expressao_precedencia_4 '>' expressao_precedencia_3
    | expressao_precedencia_4 TK_OC_LE expressao_precedencia_3
    | expressao_precedencia_4 TK_OC_GE expressao_precedencia_3
    ;

expressao_precedencia_3:
    expressao_precedencia_2
    | expressao_precedencia_3 '+' expressao_precedencia_2
    | expressao_precedencia_3 '-' expressao_precedencia_2
    ;

expressao_precedencia_2:
    expressao_precedencia_1
    | expressao_precedencia_2 '*' expressao_precedencia_1
    | expressao_precedencia_2 '/' expressao_precedencia_1
    | expressao_precedencia_2 '%' expressao_precedencia_1
    ;

expressao_precedencia_1:
    operandos_simples
    | '(' expressao ')'
    | '-' expressao_precedencia_1
    | '!' expressao_precedencia_1 
    ;

literal: 
    TK_LIT_INT 
    | TK_LIT_FLOAT
    ;

operandos_simples:
        literal { $$ = asd_new($1->label); }
    |   TK_IDENTIFICADOR { $$ = asd_new($1.valor_token); }
    |   chamada_funcao
    ;

%%

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}