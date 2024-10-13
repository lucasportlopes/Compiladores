%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
%}

%define parse.error verbose

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
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_ERRO

%%

programa: funcao 
    | empty ;

empty: ;

tipo: TK_PR_INT | TK_PR_FLOAT ;

funcao: cabecalho_funcao corpo_funcao ;

cabecalho_funcao: TK_IDENTIFICADOR '=' lista_parametros '>'  tipo;

lista_parametros: lista_parametros TK_OC_OR parametros 
    | parametros ;

parametros: lista_parametros 
    | empty ;

parametro: TK_IDENTIFICADOR '<' '-' tipo;

corpo_funcao: bloco_comandos ;

bloco_comandos: '{' comandos '}' ;

comandos: comandos comando_simples 
    | empty ;

comando_simples: declaracao_variaveis 
    | atribuicao
    | fluxo_controle
    | operacao_retorno
    | bloco_comandos
    | chamada_funcoes ;

declaracao_variaveis: tipo lista_variaveis ;

atribuicao: TK_IDENTIFICADOR '=' expressao ;

operacao_retorno: TK_PR_RETURN expressao ;

chamada_funcoes: TK_IDENTIFICADOR '(' argumentos ')' ;

argumentos: lista_argumentos 
    | empty ;

lista_argumentos: lista_argumentos ',' expressao
    | expressao ;

lista_variaveis: lista_variaveis ',' TK_IDENTIFICADOR inicializacao_opcional
               | TK_IDENTIFICADOR inicializacao_opcional ;

inicializacao_opcional: TK_OC_LE literal
    | empty ;

literal: TK_LIT_INT 
       | TK_LIT_FLOAT 

fluxo_controle: 

expressao: (Toda a parte 3.4)
%%

void yyerror(const char *mensagem) {
    printf("Erro %s\n", mensagem);
}