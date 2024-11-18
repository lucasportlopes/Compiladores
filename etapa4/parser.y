%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
#include <string.h>
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
%type<arvore_t> lista_argumentos
%type<arvore_t> lista_variaveis
%%

programa: 
    lista_funcoes { $$ = $1; arvore = $$; }
    ;

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
    cabecalho_funcao bloco_comandos {
        $$ = $1;
        if ($2 != NULL) {
            asd_add_child($$, $2);
        }
    }
    ;

cabecalho_funcao:
    TK_IDENTIFICADOR '=' lista_parametros '>' tipo { $$ = asd_new($1.valor_token); }
    ;

empty: ;

tipo: 
    TK_PR_INT | TK_PR_FLOAT
    ;

lista_parametros: 
    empty { $$ = NULL; }
    | parametro TK_OC_OR lista_parametros { $$ = NULL; }
    | parametro { $$ = NULL; }
    ;

parametro:
    TK_IDENTIFICADOR '<' '-' tipo { $$ = NULL; }
    ;

bloco_comandos: 
    '{' comandos '}' {  $$ = $2; }
    ;

comandos: 
    empty { $$ = NULL; }
    | comando_simples comandos {
        if ($1 != NULL && $2 != NULL) {
            $$ = $1;
            asd_add_child($$, $2);        
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
    | bloco_comandos ';' {  $$ = $1; }
    | chamada_funcao ';'  {  $$ = $1; }
    ;

declaracao_variavel: 
    tipo lista_variaveis { $$ = $2; };
    ;

lista_variaveis:
    TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis {
        $$ = asd_new("<="); 
        asd_add_child($$, asd_new($1.valor_token)); 
        asd_add_child($$, asd_new($3->label)); 
        if($5 != NULL) {
            asd_add_child($$, $5);
        }
    }
    | TK_IDENTIFICADOR ',' lista_variaveis { $$ = $3; }
    | TK_IDENTIFICADOR TK_OC_LE literal {
        $$ = asd_new("<=");
        asd_add_child($$, asd_new($1.valor_token)); 
        asd_add_child($$, asd_new($3->label));
    }
    | TK_IDENTIFICADOR { $$ = NULL; }
    ;

atribuicao:
    TK_IDENTIFICADOR '=' expressao { 
        $$ = asd_new("="); 
        asd_add_child($$, asd_new($1.valor_token)); 
        asd_add_child($$, $3);
    }
    ;

operacao_retorno: 
    TK_PR_RETURN expressao { $$ = asd_new("return"); asd_add_child($$, $2); }
    ;

chamada_funcao:
    TK_IDENTIFICADOR '(' lista_argumentos ')' {
        const char *CALL = "call";
        size_t size = strlen(CALL) + strlen($1.valor_token) + 2;
        char *function = (char *)malloc(size);

        if (function) {
            sprintf(function, "%s %s", CALL, $1.valor_token); 

            $$ = asd_new(function);
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
        $$ = asd_new("if"); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
    }
    | TK_PR_IF '(' expressao ')' bloco_comandos TK_PR_ELSE bloco_comandos { 
        $$ = asd_new("if"); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
        if ($7 != NULL) { 
            asd_add_child($$, $7); 
        }  
    }
    | TK_PR_WHILE '(' expressao ')' bloco_comandos { 
        $$ = asd_new("while"); 
        asd_add_child($$, $3); 
        if ($5 != NULL) { 
            asd_add_child($$, $5); 
        } 
    }
    ;

expressao:
    expressao_precedencia_6 { $$ = $1; }
    | expressao TK_OC_OR expressao_precedencia_6 { $$ = asd_new("|"); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_6:
    expressao_precedencia_5 { $$ = $1; }
    | expressao_precedencia_6 TK_OC_AND expressao_precedencia_5 { $$ = asd_new("&"); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_5:
    expressao_precedencia_4 { $$ = $1; }
    | expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4 { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_5 TK_OC_NE expressao_precedencia_4 { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_4:
    expressao_precedencia_3 { $$ = $1; }
    | expressao_precedencia_4 '<' expressao_precedencia_3 { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_4 '>' expressao_precedencia_3 { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_4 TK_OC_LE expressao_precedencia_3 { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_4 TK_OC_GE expressao_precedencia_3 { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_3:
    expressao_precedencia_2 { $$ = $1; }
    | expressao_precedencia_3 '+' expressao_precedencia_2 { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_3 '-' expressao_precedencia_2 { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_2:
    expressao_precedencia_1 { $$ = $1; }
    | expressao_precedencia_2 '*' expressao_precedencia_1 { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_2 '/' expressao_precedencia_1 { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | expressao_precedencia_2 '%' expressao_precedencia_1 { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); }
    ;

expressao_precedencia_1:
    operandos_simples { $$ = $1; }
    | '(' expressao ')' { $$ = $2; }
    | '-' expressao_precedencia_1 { $$ = asd_new("-"); asd_add_child($$, $2); }
    | '!' expressao_precedencia_1 { $$ = asd_new("!"); asd_add_child($$, $2); }
    ;

literal: 
    TK_LIT_INT { $$ = asd_new($1.valor_token); }
    | TK_LIT_FLOAT { $$ = asd_new($1.valor_token); }
    ;

operandos_simples:
        literal { $$ = $1; }
    |   TK_IDENTIFICADOR { $$ = asd_new($1.valor_token); }
    |   chamada_funcao { $$ = $1; }
    ;

%%

void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}