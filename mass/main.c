#include "main.h"

void init() {

    ctrl = (control) malloc(sizeof(struct _control));
    ctrl->level = 0;
    ctrl->location = 0;
    ctrl->label_count = -1;

    symbol = (node) malloc (sizeof(struct _node));
    label = (node) malloc (sizeof(struct _node));
    stmt = (node) malloc (sizeof(struct _node));
    call = (node) malloc (sizeof(struct _node));
    type = (node) malloc (sizeof(struct _node));

}

char* get_line(char* instruction, char* params,
    char* comment, int indent_line) {

    int indent;
    int linesize;
    char* line;

    line = malloc(sizeof(char) * TOKEN_SIZE);

    if (indent_line)
        indent = INDENT_INSTR;
    else
        indent = 0;

    linesize = sprintf(line, "%*s%s", indent, "", instruction);
    linesize += sprintf(line + strlen(line), "%*s%s", INDENT_PARAM, " ", params);

    if (strlen(comment) && ctrl->print_comments)
        sprintf(line + strlen(line), "%*s# %s\n", INDENT_COMMT - linesize, " ", comment);
    else
        sprintf(line + strlen(line), "\n");

    return line;
}

FILE* fp=NULL;
void print_line(char* instruction, char* params,
    char* comment, int indent_line) {

    if (fp == NULL) {
      fp = fopen ("MEPA", "w");
    }

    fprintf(fp, "%s", get_line(instruction, params, comment, indent_line));

}

void print_help() {

    printf("\nUso: compiler [-c] <arquivo>\n\n");
    printf("    -c Exibir comentÃ¡rios no cÃ³digo gerado.\n");
    printf("\n");

}

void node_print (node p) {

    printf(" %8ld %8ld %9s %5s %3d %4d %5d %8d %5d\n",
        (long int) p, (long int) p->next, p->token_id, p->value, p->category, p->type,
        p->level, p->location, p->label);

}

void node_print_all (node p) {

    printf("-----------------------------------------------------------------\n");
    printf("   memory     next  token_id value cat type level location label \n");
    printf("-----------------------------------------------------------------\n");

    while (p != NULL) {
        node_print (p);
        p = p->next;
    }

    printf("-----------------------------------------------------------------\n");

}

void node_push (node l, char *id, char* value,
    int category, int type,
    int level, int location,
    int label) {

    node p = (node) malloc (sizeof(struct _node));

    strcpy (p->token_id, id);
    strcpy (p->value, value);

    p->category = category;
    p->type = type;

    p->level = level;
    p->location = location;
    p->label = label;

    p->mem_count = 0;
    p->param_count = 0;

    node l_tail = node_get_tail (l);
    p->prev = l_tail;
    p->next = NULL;
    l_tail->next = p;

}

node node_pop (node l) {
    node p;
    node l_tail = node_get_tail (l);

    p = l_tail;
    if (l_tail->prev)
        l_tail = l_tail->prev;
    l_tail->next = NULL;

    return p;
}

node node_get_tail (node l) {
    while (l->next != NULL)
        l = l->next;
    return l;
}

node node_get (node l, char* token_id) {
    l = node_get_tail (l);
    while (l) {
        if (strcmp(l->token_id, token_id) == 0)
            return l;
        l = l->prev;
    }

    printf("\nErro linha %d: Identificador '%s' desconhecido.\n\n",
        yylineno, token_id);
    exit(1);
}

node node_get_symbol (char* token_id) {
    node l = node_get_tail (symbol);
    while (l) {
        if (strcmp(l->token_id, token_id) == 0
            && l->level == ctrl->level)
            return l;
        l = l->prev;
    }

    printf("\nErro linha %d: Identificador '%s' desconhecido.\n\n",
        yylineno, token_id);
    exit(1);
}

char* node_get_symbol_pos (char* token_id) {

    node p = (node) malloc(sizeof(struct _node));
    p = node_get_symbol (token_id);

    char* pos = (char*) malloc(sizeof(char) * TOKEN_SIZE);
    sprintf(pos, "%d,%d", p->level, p->location);

    return pos;
}

node node_get_routine () {
    node r = node_get_tail (symbol);
    while (1) {
        if (r->category == CAT_PROGRAM_ID)
            return r;
        if ((r->category == CAT_PROCEDURE
            || r->category == CAT_FUNCTION
            || r->category == CAT_PROGRAM_ID)
            && (r->level == ctrl->level))
            return r;
        r = r->prev;
    }
}

char* node_get_label (node l, char* token_id) {

    node p = (node) malloc(sizeof(struct _node));
    p = node_get(l, token_id);

    char* label = (char*) malloc(sizeof(char) * TOKEN_SIZE);
    sprintf(label, "R%02d", p->label);
    return label;

}

char* node_get_pos (node l, char* token_id) {

    node p = node_get_tail (l);

    while (p) {
        if (strcmp(p->token_id, token_id) == 0
            && p->level <= ctrl->level)
            break;
        p = p->prev;
    }

    char* pos = (char*) malloc(sizeof(char) * TOKEN_SIZE);
    sprintf(pos, "%d, %d", p->level, p->location);

    return pos;
}

int cat_strtotint (char* cat) {
printf("cat: %s", cat);
    if (strcmp("procedure", cat) == 0)
        return CAT_PROCEDURE;

    else if (strcmp("function", cat) == 0)
        return CAT_FUNCTION;

    return CAT_UNDEFINED;

}

int type_strtoint (char* type) {

    if (strcmp("integer", type) == 0)
        return TYPE_INTEGER;

    else if (strcmp("boolean", type) == 0)
        return TYPE_BOOLEAN;

    return TYPE_UNDEFINED;

}

void dump_statements () {
    node s;
    s = stmt;
    while (s) {
        if (strlen (s->token_id) )
            printf("%s", s->token_id);
        strcpy (s->token_id, "");
        s = s->next;
    }
}

void parser_update_params (char* str_type) {

    /*
     * Atualiza o tipo das variÃ¡veis empilhadas de
     * acordo com o formato 'a, b, c :integer;'
     */

    int c = 0;
    int type = type_strtoint (str_type);

    node p = node_get_tail (symbol);
    while (p->type == TYPE_UNDEFINED) {
        p->type = type;
        p = p->prev;
        c++;
    }

    char* count = malloc (sizeof(char) * TOKEN_SIZE);
    sprintf(count, "%d", c);
    print_line ("AMEM", count, "", 1);

    node r = node_get_routine ();
    r->mem_count += c;
}

void parser_routine_identification (int category, char* identifier) {

    /* Entra no procedimento. */

    char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
    char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);

    ctrl->label_count++;
    ctrl->level++;
    ctrl->location = 0;

    sprintf (label_id, "R%02d", ctrl->label_count);
    sprintf (label_nada, "R%02d: ENPR %d",
        ctrl->label_count, ctrl->level);

    node_push (symbol, identifier, label_id,
        category, TYPE_CONTROL,
        ctrl->level, NO_LOCATION, ctrl->label_count);

    print_line (label_nada, "", identifier, 0);

}

void parser_routine_declaration () {

    /* Desempilha variÃ¡veis locais. */

    node p = node_get_tail (symbol);
    node q = p;
    while (1) {
        if (q->level == ctrl->level && q->location >= 0)
            p = node_pop (symbol);
        else
            break;
        q = node_get_tail (symbol);
    }

    node_push (symbol, p->token_id, p->value,
        p->category, p->type,
        p->level, p->location, p->label);

    /* Desaloca posiÃ§Ãµes de memÃ³ria utilizadas. */

    p = node_get_routine ();

    if (p->mem_count) {
        char* dmem_param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (dmem_param, "%d", p->mem_count);
        print_line ("DMEM", dmem_param, "", 1);
    }

    /* Retorna do procedimento. */

    char* rtpr_param = malloc (sizeof(char) * TOKEN_SIZE);
    sprintf (rtpr_param, "%d, %d", p->level, p->param_count);
    print_line ("RTPR", rtpr_param, "end", 1);

    ctrl->level--;

}
