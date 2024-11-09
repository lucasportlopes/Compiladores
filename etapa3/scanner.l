%{
// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
#include "parser.tab.h"
%}

%option yylineno
%option noyywrap

WHITESPACE[ ]
TAB[\t]
SPECIAL[-!*/%+-<>{}()=,;]

%%

"//".* { }

int { return TK_PR_INT; }
float { return TK_PR_FLOAT; }
if { return TK_PR_IF; }
else { return TK_PR_ELSE; }
while { return TK_PR_WHILE; }
return { return TK_PR_RETURN; }

[0-9]+ { 
    printf("TK_LIT_INT Linha %d: %s\n", yylineno, yytext);
    yylval.valor_lexico.valor_token = strdup(yytext);
    yylval.valor_lexico.linha = yylineno; 
    yylval.valor_lexico.tipo_token = 0;
    return TK_LIT_INT;
}

[0-9]*\.[0-9]+ { 
    printf("TK_LIT_FLOAT Linha %d: %s\n", yylineno, yytext);
    yylval.valor_lexico.valor_token = strdup(yytext);
    yylval.valor_lexico.linha = yylineno;
    yylval.valor_lexico.tipo_token = 0;
    return TK_LIT_FLOAT;
}

[a-z_][a-zA-Z0-9_]* { 
    printf("TK_IDENTIFICADOR Linha %d: %s\n", yylineno, yytext);
    yylval.valor_lexico.valor_token = strdup(yytext);
    yylval.valor_lexico.linha = yylineno;
    yylval.valor_lexico.tipo_token = 1;
    return TK_IDENTIFICADOR; 
}

"<=" { return TK_OC_LE; }
">=" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&" { return TK_OC_AND; }
"|" { return TK_OC_OR; }

{SPECIAL} { return yytext[0]; }

{WHITESPACE}|{TAB} {}

\n {}

. { return TK_ERRO; }

%%

int get_line_number(void) {
    return yylineno;
}