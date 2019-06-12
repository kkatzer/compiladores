/* -------------------------------------------------------------------
 *            Arquivo: main.h
 * -------------------------------------------------------------------
 *            Autores: Kevin Katzer e Lucas Rosa Silva
 *               Data: 06/2019
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prototipos e vaiaveis globais do compilador
 *
 * ------------------------------------------------------------------- */
#ifndef MAIN_H
#define MAIN_H

#define YY_NO_INPUT

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define TAM_TOKEN      16
#define NO_LABEL       -1
#define NO_LEVEL       -1
#define NO_LOCATION    -100

#define INDENT_INSTR   5
#define INDENT_PARAM   1
#define INDENT_COMMT   25

#define CAT_UNDEFINED  0
#define CAT_PROGRAM_ID 1
#define CAT_FUNCTION   2
#define CAT_PROCEDURE  3
#define CAT_STMTLABEL  4
#define CAT_VARIABLE   5
#define CAT_CALL       6
#define CAT_PARAM      7
#define CAT_PARAMREF   8
#define CAT_ROUTINE    9
#define CAT_LABEL      10
#define CAT_STATEMENT  11
#define CAT_TYPE       12

#define TYPE_UNDEFINED 0
#define TYPE_CONTROL   1
#define TYPE_BOOLEAN   2
#define TYPE_INTEGER   3

void yyerror (const char *);
extern int yylex ();
extern int yyget_lineno ();
int yylineno;

typedef enum simbolos {
  simb_program, simb_var, simb_begin, simb_end,
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_label, simb_type, simb_array, simb_of, simb_procedures,
  simb_function, simb_goto, simb_if, simb_then, simb_else,
  simb_while, simb_do, simb_mais, simb_menos, simb_or,
  simb_multiplicacao, simb_div, simb_and, simb_not,
  simb_igual, simb_nigual, simb_maigual, simb_meigual,
  simb_menor, simb_maior,
} simbolos;

typedef struct symbol symbol;

struct symbol {
  char name[TAM_TOKEN];
  char value[TAM_TOKEN];

  int category;
  int type;

  int location;

  int label;
  int level;
  int param_count;
  int mem_count;

  symbol *next;
};

/* -------------------------------------------------------------------
 * variaveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];


int nivel_lexico;
int desloc;
int nl;
int label_count;


simbolos simbolo, relacao;
char token[TAM_TOKEN];
symbol *topo;


/* -------------------------------------------------------------------
 * funcoes
 * ------------------------------------------------------------------- */

void geraCodigo (char* rot, char* comando, char* params);
int imprimeErro ( char* erro );

//Tabela de Simbolos (global)
void empilhaSimbolo (char* name, char* value, int category, int type, int location, int label, int level);
symbol *desempilhaSimbolo (int tipo);
symbol *getSimbolo(char *nome);

int strtoint (char* type);
void parser_update_params (char* str_type);
symbol *get_routine();

#include "parser.tab.h"

#endif
