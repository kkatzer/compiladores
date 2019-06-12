%{
    #include "main.h"
    #define SAVE(s); strcpy(yylval.str, s);
%}

%option batch
%option case-insensitive
%option nounput
%option noyywrap
%option yylineno

%%

"="                     { return T_EQ; }
"<>"                    { return T_NEQ; }
">="                    { return T_GTE; }
">"                     { return T_GT; }
"<="                    { return T_LTE; }
"<"                     { return T_LT; }

":="                    { return T_ASSIGNMENT; }
"("                     { return T_LPAR; }
")"                     { return T_RPAR; }
"."                     { return T_DOT; }
","                     { return T_COMMA; }
":"                     { return T_COLON; }
";"                     { return T_SEMICOLON; }

"+"                     { return T_PLUS; }
"-"                     { return T_MINUS; }
"*"                     { return T_STAR; }
"div"                   { return T_DIV; }

"and"                   { return T_AND; }
"or"                    { return T_OR; }
"not"                   { return T_NOT; }

"program"               { return T_PROGRAM; }
"begin"                 { return T_BEGIN; }
"end"                   { return T_END; }
"label"                 { return T_LABEL; }
"var"                   { return T_VAR; }
"function"              { return T_FUNCTION; }
"procedure"             { return T_PROCEDURE; }
"if"                    { return T_IF; }
"then"                  { return T_THEN; }
"else"                  { return T_ELSE; }
"while"                 { return T_WHILE; }
"do"                    { return T_DO; }
"read"                  { return T_READ; }
"goto"                  { return T_GOTO; }
"write"                 { return T_WRITE; }

[a-zA-Z_][a-zA-Z0-9_]*  { SAVE(yytext); return T_IDENTIFIER; }
[0-9]+\.[0-9]*          { SAVE(yytext); return T_DOUBLE; }
[0-9]+                  { SAVE(yytext); return T_INTEGER; }

[ \t\n]                 ;
.                       {
                            fprintf (stderr, "Erro de sintaxe:  "
                                "caractere '%s' inesperado na linha %d.",
                                yytext, yylineno);
                        }

%%
