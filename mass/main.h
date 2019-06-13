#ifndef MAIN_H
#define MAIN_H

#define YY_NO_INPUT

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define TOKEN_SIZE     256
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

typedef struct _node *node;
struct _node {

    char token_id[TOKEN_SIZE];
    char value[TOKEN_SIZE];

    int category;
    int type;

    int level;
    int location;

    int label;
    int mem_count;
    int param_count;

    node prev;
    node next;

};

typedef struct _control *control;
struct _control {

    int print_comments;

    int level;
    int location;
    int label_count;
};

control ctrl;

node symbol;
node label;
node stmt;
node call;
node type;

char* get_line (char* instruction, char* params,
    char* comment, int indent_line);
void print_line (char* instruction, char* params,
    char* comment, int indent_line);

void print_help ();
void init ();
int type_strtoint (char* c);
void dump_statements();

void node_print (node p);
void node_print_all (node p);

node node_get (node l, char* token_id);
node node_get_tail  (node l);
node node_get_routine ();
node node_get_symbol (char* token_id);

char* node_get_label (node l, char* token_id);
char* node_get_pos (node l, char* token_id);
char* node_get_symbol_pos (char* token_id);

void node_push (node l, char *id, char* value,
    int category, int type,
    int level, int location,
    int label);
node node_pop (node p);

void parser_update_params (char* str_type);
void parser_routine_declaration ();
void parser_routine_identification (int category, char* identifier);
void parser_forward_identification (int category, char* identifier);

#include "parser.h"

#endif
