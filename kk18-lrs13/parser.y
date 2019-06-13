
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
%token NIGUAL READ WRITE

%type <str> IDENT
%type <str> NUMERO
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
                nivel_lexico++;
                desloc = 0;

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
                empilhaSimbolo(token, "", CAT_VARIABLE, TYPE_UNDEFINED, desloc, NO_LABEL, nivel_lexico);
                desloc++;
              }
            | IDENT
              {
                empilhaSimbolo(token, "", CAT_VARIABLE, TYPE_UNDEFINED, desloc, NO_LABEL, nivel_lexico);
                desloc++;
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
       | read
       | write
       | condition
       | while
;

atribuicao : IDENT ATRIBUICAO expression
             {
                symbol* s = getSimbolo($1);
                geraCodigo(NULL, "ARMZ", get_pos(s));
             }

;

read : READ ABRE_PARENTESES read_expression_list FECHA_PARENTESES
;

read_expression_list : read_expression
                     | read_expression VIRGULA read_expression_list
;

read_expression : {
                    geraCodigo(NULL, "LEIT", "");
                  }
                  IDENT
                  {
                    symbol *s = getSimbolo($2);
                    geraCodigo(NULL, "ARMZ", get_pos(s));
                  }

write : WRITE ABRE_PARENTESES write_expression_list FECHA_PARENTESES
;

write_expression_list : write_expression
                      | write_expression VIRGULA write_expression_list

write_expression : expression
                   {
                     geraCodigo(NULL, "IMPR", "");
                   }

condition : condition_if comandos
            {
              /* Rotulo de fim da condicao */

              symbol *s = desempilhaLabel();
              char *labelFim = (char *)malloc(sizeof(char) * TAM_TOKEN);
              sprintf(labelFim, "R%02d", s->label);

              geraCodigo(labelFim, "NADA", "");
            }
            | condition_if comandos ELSE
            {
              /* final do if com else */
              label_count++;

              symbol *s_else = desempilhaLabel();

              /* desvio para rótulo de fim do else */
              char *label_id = (char *)malloc(sizeof(char)*TAM_TOKEN);
              sprintf(label_id, "R%02d", label_count);

              empilhaLabel(label_id, CAT_LABEL, TYPE_CONTROL, desloc, NO_LABEL, nivel_lexico);

              geraCodigo(NULL, "DSVS", label_id);

              /* Rótulo de início do else */

              char *labelFim = (char *)malloc(sizeof(char) * TAM_TOKEN);
              sprintf(labelFim, "R%02d", s_else->label);

              geraCodigo(labelFim, "NADA", "");
            }
            comandos
            {
              symbol *s = desempilhaLabel();
              char *labelFim = (char *)malloc(sizeof(char) * TAM_TOKEN);
              sprintf(labelFim, "R%02d", s->label);

              geraCodigo(labelFim, "NADA", "");
            }
;

condition_if : IF expression THEN
               {
                 symbol *t = desempilhaTipo();
                 if (t->type != TYPE_BOOLEAN)
                    yyerror("Expressão em if não é booleana");

                 label_count++;

                 char *label_id = (char *)malloc(sizeof(char) * TAM_TOKEN);
                 sprintf(label_id, "R%02d", label_count);

                 empilhaLabel(label_id, CAT_LABEL, TYPE_CONTROL, desloc, NO_LABEL, nivel_lexico);

                 geraCodigo(NULL, "DSVF", label_id);
               }

while : WHILE
        {
          char *label_id = (char *)malloc(sizeof(char) * TAM_TOKEN);

          label_count++;

          sprintf(label_id, "R%02d", label_count);

          empilhaLabel(label_id, CAT_LABEL, TYPE_CONTROL, desloc, NO_LABEL, nivel_lexico);
          geraCodigo(label_id, "NADA", "");
        }
        expression DO
        {
          symbol *t = desempilhaTipo();
          if (t->type != TYPE_BOOLEAN)
            yyerror("Expressão em if não é booleana");

          label_count++;

          char *label_id = (char *)malloc(sizeof(char) * TAM_TOKEN);
          sprintf(label_id, "R%02d", label_count);

          empilhaLabel(label_id, CAT_LABEL, TYPE_CONTROL, desloc, label_count, nivel_lexico);
          geraCodigo(NULL, "DSVF", label_id);
        }
        comando_composto
        {
          symbol *endw = desempilhaLabel();
          symbol *w = desempilhaLabel();

          char *labelFim = (char *)malloc(sizeof(char) * TAM_TOKEN);
          sprintf(labelFim, "R%02d", endw->label);

          geraCodigo(NULL, "DSVS", w->name);
          geraCodigo(labelFim, "NADA", "");
        }
;

expression : simple_expression
           | simple_expression relop simple_expression
           {
              //Checa se são do mesmo tipo antes de comparar
              symbol *p = desempilhaTipo();
              symbol *q = desempilhaTipo();

              if (p->type != q->type)
                yyerror("Comparação relop entre tipos diferentes.");
              geraCodigo(NULL, $2, "");

              empilhaTipo($2, CAT_STATEMENT, TYPE_BOOLEAN, NO_LOCATION, NO_LABEL, NO_LEVEL);
           }
;

simple_expression : term
                  | simple_expression addop term
                  {
                     //Checa se são inteiros antes de fazer addop
                    symbol *p = desempilhaTipo();
                    symbol *q = desempilhaTipo();

                    if (p->type != TYPE_INTEGER ||
                        q->type != TYPE_INTEGER)
                        yyerror("Addop entre tipos inválidos.");
                    geraCodigo(NULL, $2, "");

                    empilhaTipo($2, CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
                  }
;

term : factor
     | term mulop factor
     {
        //Checa se são inteiros antes de fazer addop
       symbol *p = desempilhaTipo();
       symbol *q = desempilhaTipo();

       if (p->type != TYPE_INTEGER ||
           q->type != TYPE_INTEGER)
           yyerror("Mulop entre tipos inválidos.");
       geraCodigo(NULL, $2, "");

       empilhaTipo($2, CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
     }
;

factor : NUMERO
       {
         geraCodigo(NULL, "CRCT", token);
         empilhaTipo($1, CAT_STATEMENT, TYPE_INTEGER, NO_LOCATION, NO_LABEL, NO_LEVEL);
       }
       | ABRE_PARENTESES expression FECHA_PARENTESES
       | NOT factor {
         symbol *s = desempilhaSimbolo();

         if (s->type != TYPE_BOOLEAN)
            yyerror("Not em tipo inválido.");

         geraCodigo(NULL, "NEGA", "");

         empilhaTipo(s->name, CAT_STATEMENT, s->type, NO_LOCATION, NO_LABEL, NO_LEVEL);
       }
       | IDENT
       {
         symbol *s = getSimbolo($1);

         geraCodigo(NULL, "CRVL", get_pos(s));
         empilhaTipo(s->name, CAT_STATEMENT, s->type, NO_LOCATION, NO_LABEL, NO_LEVEL);
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
   nivel_lexico = 0;
   desloc = 0;

   yyin=fp;
   yyparse();

   return 0;
}
