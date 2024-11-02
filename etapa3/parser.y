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
    valor_lexico valor_lexico;
}

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_ERRO

%%

programa: 
    lista_funcoes 
    ;

lista_funcoes:
    empty
    | lista_funcoes funcao
    ;

empty: ;

tipo: 
    TK_PR_INT | TK_PR_FLOAT 
    ;

funcao: 
    cabecalho_funcao bloco_comandos 
    ;

cabecalho_funcao: 
    TK_IDENTIFICADOR '=' lista_parametros '>' tipo
    ;

lista_parametros: 
    empty
    | lista_parametros TK_OC_OR parametro
    | parametro 
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

literal: 
    TK_LIT_INT 
    | TK_LIT_FLOAT
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

operandos_simples:
        literal
    |   TK_IDENTIFICADOR
    |   chamada_funcao
    ;

%%

typedef struct {
    int linha;
    int tipo_token;
    char *valor_token;
} valor_lexico;

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}