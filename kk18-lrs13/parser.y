
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int num_vars;

%}

%union {
  char str[TAM_TOKEN];
}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token LABEL TYPE ARRAY OF PROCEDURE
%token FUNCTION GOTO IF THEN ELSE
%token WHILE DO MAIS MENOS OR
%token MULTIPLICACAO DIV AND NOT NUMERO
%token IGUAL MAIGUAL MEIGUAL MAIOR MENOR
%token NIGUAL

%type <str> IDENT
%type <str> relop
%type <str> addop
%type <str> mulop

%%

program    : PROGRAM IDENT
             {
             empilhaSimbolo(token, "main", CAT_PROGRAM_ID, TYPE_CONTROL, NO_LOCATION, NO_LABEL, NO_LEVEL);
             geraCodigo (NULL, "INPP", "");
             }
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             while (topo->category != CAT_PROGRAM_ID) {
               desempilhaSimbolo(TYPE_UNDEFINED);
             }

             if (topo->mem_count > 0) {
               char *dmem_param = malloc (sizeof(char) * TAM_TOKEN);
               sprintf (dmem_param, "%d", topo->mem_count);

               geraCodigo (NULL, "DMEM", dmem_param);
             }

             geraCodigo (NULL, "PARA", "");
             }
;

bloco       :
              parte_declara_vars
              {
                //Rotulo de inicio de procedimento
                label_count++;

                char* label_id = (char *)malloc (sizeof(char) * TAM_TOKEN);
                /* char* label_comment = (char *)malloc (sizeof(char) * TAM_TOKEN); */

                sprintf(label_id, "R%02d", label_count);
                /* if (label_count == 1)
                  sprintf(label_comment, "main"); */

                /* empilhaSimbolo(label_id, label_comment, CAT_LABEL, TYPE_CONTROL, nl, label_count, nivel_lexico); */

                geraCodigo(NULL, "DSVS", label_id);

                /* desempilhaSimbolo(); */
                /* sprintf(label_id, "R%02d", label_count); */
                geraCodigo(label_id, "NADA", "");
              }


              comando_composto
              ;




parte_declara_vars:  var
;


var         : { } VAR declara_vars
            |
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : { }
              lista_id_var DOIS_PONTOS
              tipo
              {
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
              {
                parser_update_params(token);
              }
;

lista_id_var: lista_id_var VIRGULA IDENT
              {
                empilhaSimbolo(token, "", CAT_VARIABLE, TYPE_UNDEFINED, nl, NO_LABEL, nivel_lexico);
                nl++;
              }
            | IDENT
              {
                empilhaSimbolo(token, "", CAT_VARIABLE, TYPE_UNDEFINED, nl, NO_LABEL, nivel_lexico);
                nl++;
              }
;


lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END

comandos: comando
        | comandos PONTO_E_VIRGULA comando
;

comando: atribuicao
       | call_noparams
       | call
       | read
       | write
       | condition
       | while
;

atribuicao : IDENT ATRIBUICAO expression
             {
                char* com = (char *)malloc(sizeof(char) * TAM_TOKEN);
                symbol* s = getSimbolo($1);
                sprintf(com, "%d", s->location);
                if (s->category == CAT_PARAMREF)
                  geraCodigo(NULL, "ARMI", com);
                else
                  geraCodigo(NULL, "ARMZ", com);
             }

;

call_noparams : {}
;

call : {}
;

read : {}
;

write : {}
;

condition : {}
;

while : {}
;

expression : simple_expression
           {
             //Não usa
             desempilhaSimbolo(TYPE_UNDEFINED);
           }
           | simple_expression relop simple_expression
           {
              //Checa se são do mesmo tipo antes de comparar
              symbol *p = desempilhaSimbolo(TYPE_UNDEFINED);
              symbol *q = desempilhaSimbolo(TYPE_UNDEFINED);

              if (p->type != q->type)
                yyerror("Comparação relop entre tipos diferentes.");
              geraCodigo(NULL, $2, "");

              empilhaSimbolo("", "", CAT_STATEMENT, TYPE_BOOLEAN, NO_LOCATION, NO_LABEL, NO_LEVEL);
           }
;

simple_expression : term
                  | simple_expression addop term
                  {
                     //Checa se são inteiros antes de fazer addop
                    symbol *p = desempilhaSimbolo(TYPE_UNDEFINED);
                    symbol *q = desempilhaSimbolo(TYPE_UNDEFINED);

                    if (p->type != TYPE_INTEGER ||
                        q->type != TYPE_INTEGER)
                        yyerror("Addop entre tipos inválidos.");
                    geraCodigo(NULL, $2, "");

                    empilhaSimbolo("", "", CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
                  }
;

term : factor
     | term mulop factor
     {
        //Checa se são inteiros antes de fazer addop
       symbol *p = desempilhaSimbolo(TYPE_UNDEFINED);
       symbol *q = desempilhaSimbolo(TYPE_UNDEFINED);

       if (p->type != TYPE_INTEGER ||
           q->type != TYPE_INTEGER)
           yyerror("Mulop entre tipos inválidos.");
       geraCodigo(NULL, $2, "");

       empilhaSimbolo("", "", CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
     }
;

factor : NUMERO
       {
         geraCodigo(NULL, "CRCT", token);
         empilhaSimbolo("", "", CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
       }
       | ABRE_PARENTESES expression FECHA_PARENTESES
       | NOT factor {
         symbol *s = desempilhaSimbolo(TYPE_UNDEFINED);

         if (s->type != TYPE_BOOLEAN)
            yyerror("Not em tipo inválido.");

         geraCodigo(NULL, "NEGA", "");

         empilhaSimbolo("", "", CAT_STATEMENT, TYPE_BOOLEAN, NO_LOCATION, NO_LABEL, NO_LEVEL);
       }
;

relop : IGUAL { strcpy($$, "CMIG"); }
      | NIGUAL { strcpy($$, "CMDG"); }
      | MEIGUAL { strcpy($$, "CMEG"); }
      | MAIGUAL { strcpy($$, "CMAG"); }
      | MENOR { strcpy($$, "CMME"); }
      | MAIOR { strcpy($$, "CMMA"); }
;

addop : MAIS { strcpy($$, "SOMA"); }
      | MENOS { strcpy($$, "SUBT"); }
      | OR { strcpy($$, "DISJ"); }
;

mulop : MULTIPLICACAO { strcpy($$, "MULT"); }
      | DIV { strcpy($$, "DIVI"); }
      | AND { strcpy($$, "CONJ"); }
;
%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }

   label_count = -1;
   nl = 0;
   nivel_lexico = 0;

   yyin=fp;
   yyparse();

   return 0;
}
