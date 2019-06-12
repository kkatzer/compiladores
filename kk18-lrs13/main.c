
/* -------------------------------------------------------------------
 *            Aquivo: main.c
 * -------------------------------------------------------------------
 *            Autores: Kevin Katzer e Lucas Rosa Silva
 *               Data: 06/2019
 *
 * -------------------------------------------------------------------
 *
 * Funcoes auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/* -------------------------------------------------------------------
 *  variaveis globais
 * ------------------------------------------------------------------- */

FILE* fp=NULL;
void geraCodigo (char* rot, char* comando, char* params) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }

  if ( rot == NULL ) {
    fprintf(fp, "     %s %s\n", comando, params); fflush(fp);
  } else {
    fprintf(fp, "%s: %s %s\n", rot, comando, params); fflush(fp);
  }
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

void empilhaSimbolo (char *name, char *value, int category, int type, int location, int label, int level) {
  symbol *s = (symbol *)malloc(sizeof(struct symbol));
  strcpy(s->name, name);
  strcpy(s->value, value);
  s->category = category;
  s->type = type;

  s->location = location;

  s->label = label;
  s->level = level;

  s->param_count = 0;
  s->mem_count = 0;

  s->next = topo;
  topo = s;
}

symbol *desempilhaSimbolo (int tipo) {
  symbol *pop = topo;
  symbol *ret;
  if (tipo == TYPE_UNDEFINED) {
    topo = topo->next;
    return pop;
  } else {
    while (pop->next->type != tipo) {
      if (pop->next == NULL) {
        exit(0);
      }
      pop = pop->next;
    }
    ret = pop->next;
    pop->next = pop->next->next;
    return ret;
  }
}

symbol *getSimbolo(char *nome) {
  symbol *s = topo;
  while (s) {
    if (strcmp(s->name, nome) == 0)
      return s;
    s = s->next;
  }
  imprimeErro("Identificador desconhecido.");
  exit(1);
}

int strtoint (char* type) {

    if (strcmp("integer", type) == 0)
        return TYPE_INTEGER;

    else if (strcmp("boolean", type) == 0)
        return TYPE_BOOLEAN;

    return TYPE_UNDEFINED;

}

void parser_update_params (char* str_type) {

    /*
     * Atualiza o tipo das variaveis empilhadas de
     * acordo com o formato 'a, b, c :integer;'
     */

    int c = 0;
    int type = strtoint (str_type);

    symbol *p = topo;
    while (p->type == TYPE_UNDEFINED) {
        p->type = type;
        p = p->next;
        c++;
    }

    char *count = malloc (sizeof(char) * TAM_TOKEN);
    sprintf(count, "%d", c);
    geraCodigo (NULL, "AMEM", count);

    symbol *r = get_routine();
    r->mem_count += c;
}

symbol *get_routine() {
  symbol *r = topo;
  while (r != NULL) {
    if (r->category == CAT_PROGRAM_ID)
      return r;
      if ((r->category == CAT_PROCEDURE
          || r->category == CAT_FUNCTION
          || r->category == CAT_PROGRAM_ID)
          && (r->level == nivel_lexico))
      return r;
    r = r->next;
  }
  exit(0);
}
