%{
    #include "main.h"
%}

%expect 3

%union {
    char str[TOKEN_SIZE];
}

%token T_IGNORE
%token T_IDENTIFIER
%token T_DOUBLE
%token T_INTEGER

%token T_EQ
%token T_NEQ
%token T_GTE
%token T_GT
%token T_LTE
%token T_LT

%token T_ASSIGNMENT
%token T_LPAR
%token T_RPAR
%token T_DOT
%token T_COMMA
%token T_COLON
%token T_SEMICOLON

%token T_PLUS
%token T_MINUS
%token T_STAR
%token T_DIV

%token T_AND
%token T_OR
%token T_NOT

%token T_PROGRAM
%token T_BEGIN
%token T_END
%token T_LABEL
%token T_VAR
%token T_FUNCTION
%token T_PROCEDURE
%token T_IF
%token T_THEN
%token T_ELSE
%token T_WHILE
%token T_DO
%token T_GOTO
%token T_READ
%token T_WRITE
%token T_FORWARD

%type <str> T_IDENTIFIER
%type <str> T_INTEGER

%type <str> T_PROCEDURE
%type <str> T_FUNCTION

%type <str> addop
%type <str> mulop
%type <str> relop

%type <str> procedure_declaration
%type <str> procedure_heading
%type <str> procedure_identification

%start program

%%

program :
    T_PROGRAM T_IDENTIFIER
    {
        node_push (symbol, $2, "main",
            CAT_PROGRAM_ID, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, NO_LABEL);

        print_line ("INPP", "", "", 1);

    }
    T_LPAR list_ignore T_RPAR T_SEMICOLON
    block T_DOT
    {
        node p = node_pop (symbol);
        while (p->category != CAT_PROGRAM_ID)
            p = node_pop (symbol);

        char* dmem_param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (dmem_param, "%d", p->mem_count);

        print_line ("DMEM", dmem_param, "", 1);
        print_line ("PARA", "", "end.", 1);
    }
    ;

list_ignore :
    T_IDENTIFIER
    | T_IDENTIFIER T_COMMA list_ignore
    ;

block :
    label_declaration_part
    variable_declaration_part
    {
        /*
         * Marca o rÃ³tulo de inÃ­cio do procedimento
         * apÃ³s identificar a seÃ§Ã£o de variÃ¡veis.
         */

        ctrl->label_count++;

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        char* label_comment = malloc (sizeof(char) * TOKEN_SIZE);

        sprintf (label_id, "R%02d", ctrl->label_count);
        if (ctrl->label_count == 1)
            sprintf(label_comment, "main");

        node_push (label, label_id, label_comment,
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        print_line ("DSVS", label_id, "", 1);
    }
    routine_declaration_part
    {
        /*
         * Exibe o rÃ³tulo do programa principal quando
         * todas as rotinas tiverem sido declaradas.
         */

        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);
        print_line (label_nada, "", p->value, 0);
    }
    statement_part
    ;

label_declaration_part :
    | T_LABEL label_list T_SEMICOLON
    ;

label_list :
    label_identifier
    | label_list T_COMMA label_identifier
    ;

label_identifier :
    T_INTEGER
    {
        ctrl->label_count++;

        node_push (symbol, $1, "",
            CAT_STMTLABEL, TYPE_CONTROL,
            ctrl->level, NO_LOCATION, ctrl->label_count);
    }
    ;

variable_declaration_part :
    | T_VAR variable_declaration_list T_SEMICOLON
    ;

variable_declaration_list :
    variable_declaration
    | variable_declaration_list T_SEMICOLON variable_declaration
    ;

variable_declaration :
    T_VAR variable_list T_COLON T_IDENTIFIER
    {
        parser_update_params ($4);
    }
    | variable_list T_COLON T_IDENTIFIER
    {
        parser_update_params ($3);
    }
    ;

variable_list :
    variable_var
    | variable_var T_COMMA variable_list
    ;

variable_var :
    T_IDENTIFIER
    {
        /*
         * Adiciona variÃ¡vel na tabela de sÃ­mbolos.
         */
        node_push (symbol, $1, "",
            CAT_VARIABLE, TYPE_UNDEFINED,
            ctrl->level, ctrl->location, NO_LABEL);

        ctrl->location++;
    }
    ;

routine_declaration_part :
    | routine_declaration_list T_SEMICOLON
    ;

routine_declaration_list :
    routine_declaration
    {
        parser_routine_declaration ();
    }
    | routine_declaration_list T_SEMICOLON routine_declaration
    {
        parser_routine_declaration ();
    }
    ;

routine_declaration :
    procedure_declaration
    | function_declaration
    ;

procedure_declaration :
    procedure_heading T_SEMICOLON
    {
      print_routine(CAT_PROCEDURE, $1);
    }
    block
    | procedure_heading T_SEMICOLON T_FORWARD
    ;

procedure_heading :
    procedure_identification
    {
      strcpy($$,$1);
    }
    | procedure_identification formal_parameter_section
    {
      strcpy($$,$1);
    }
    ;

procedure_identification :
    T_PROCEDURE T_IDENTIFIER
    {
        parser_routine_identification (CAT_PROCEDURE, $2);
        strcpy($$,$2);
    }
    ;

function_declaration :
    function_heading T_SEMICOLON block
    ;

function_heading :
    function_identification T_COLON T_IDENTIFIER
    | function_identification formal_parameter_section
      T_COLON T_IDENTIFIER
    ;

function_identification :
    T_FUNCTION T_IDENTIFIER
    {
        parser_routine_identification (CAT_FUNCTION, $2);
    }
    ;

formal_parameter_section :
    T_LPAR formal_parameter_list T_RPAR
    {
        int c = -4;
        node p = node_get_tail (symbol);
        node q = p;

        while (1) {
            if (p->location == NO_LOCATION)
                p->location = c;

            q = p->prev;
            if (q->location != NO_LOCATION)
                break;

            c--;
            p = q;
        }

        p->param_count = (p->location + 4) * -1;
    }
    ;

formal_parameter_list :
    formal_parameter
    | formal_parameter T_SEMICOLON formal_parameter_list
    ;

formal_parameter :
    T_IDENTIFIER T_COLON T_IDENTIFIER
    {
        node_push (symbol, $1, "",
            CAT_PARAM, type_strtoint ($3),
            ctrl->level, NO_LOCATION, NO_LABEL);
    }
    | T_VAR T_IDENTIFIER T_COLON T_IDENTIFIER
    {
        node_push (symbol, $2, "",
            CAT_PARAMREF, type_strtoint ($4),
            ctrl->level, NO_LOCATION, NO_LABEL);
    }
    ;

statement_part :
    T_BEGIN statement_list T_END
    ;

statement_list :
    statement
    | statement_list T_SEMICOLON statement
    ;

statements :
    statement
    | statement_part
    ;

statement :
    statement_nolabel
    {
        dump_statements();
    }
    | T_INTEGER T_COLON
    {
        node p = node_get (symbol, $1);
        node r = node_get_routine ();

        char* label = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label, "R%02d: ENRT %d %d",
            p->label, p->level, r->mem_count);

        node_push (stmt, get_line (label, "", $1, 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, NO_LABEL);
    }
    statement_nolabel
    {
        dump_statements();
    }
    ;

statement_nolabel :
    assignment
    | call_noparams
    | call
    | goto
    | read
    | write
    | condition
    | while
    ;

assignment :
    T_IDENTIFIER T_ASSIGNMENT expression
    {
        char* mode = malloc (sizeof(char) * TOKEN_SIZE);
        char* comment = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf(comment, "%s :=", $1);
        node p = node_get (symbol, $1);

        node e = node_pop (type);
        if (e->type == TYPE_BOOLEAN)
            yyerror ("atribuição inválida.");

        if (p->category == CAT_PARAMREF)
            strcpy (mode, "ARMI");
        else
            strcpy (mode, "ARMZ");

        node_push (stmt,
            get_line (mode, node_get_pos (symbol, $1), comment, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

call_noparams :
    T_IDENTIFIER opt_semicolon
    {
        node p = node_get (symbol, $1);

        char* param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (param, "%s, %d", p->value, ctrl->level);

        node_push (stmt, get_line ("CHPR", param, $1, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

call :
    T_IDENTIFIER
    {
        node_push (call, $1, "",
            CAT_CALL, TYPE_CONTROL,
            NO_LEVEL, NO_LOCATION, 1);

        node p = node_get (symbol, $1);
        if (p->category == CAT_FUNCTION) {
            node_push (stmt,
                get_line ("AMEM", "1", "", 1), "",
                CAT_STATEMENT, TYPE_CONTROL,
                ctrl->level, ctrl->location, NO_LABEL);
        }

    }
    T_LPAR expression_list T_RPAR opt_semicolon
    {
        node p = node_pop (call);
        p = node_get (symbol, p->token_id);

        char* param = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (param, "%s, %d", p->value, ctrl->level);

        node_push (stmt,
            get_line ("CHPR", param, $1, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

opt_semicolon :
    | T_SEMICOLON
    ;

goto :
    T_GOTO T_INTEGER
    {
        node p = node_get (symbol, $2);
        char* label = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label, "R%02d, %d, %d",
            p->label, p->level, ctrl->level);

        node_push (stmt,
            get_line ("DSVR", label, $2, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

read :
    T_READ T_LPAR read_expression_list T_RPAR
    ;

read_expression_list :
    read_expression
    | read_expression T_COMMA read_expression_list
    ;

read_expression :
    {
        node_push (stmt,
            get_line ("LEIT", "", "read", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    T_IDENTIFIER
    {
        node_push (stmt,
            get_line ("ARMZ", node_get_pos (symbol, $2), $2, 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

write :
    T_WRITE T_LPAR write_expression_list T_RPAR
    ;

write_expression_list :
    write_expression
    | write_expression T_COMMA write_expression_list
    ;

write_expression :
    expression
    {
        node_push (stmt,
            get_line ("IMPR", "", "write", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

condition :
    condition_if statements
    {
        /* RÃ³tulo de fim da condiÃ§Ã£o. */

        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);

        node_push (stmt,
            get_line (label_nada, "", "", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    | condition_if statements T_ELSE
    {
        /* Final do if com else. */

        ctrl->label_count++;

        node p_else = node_pop (label);

        /* Desvio para novo rÃ³tulo de fim do else. */

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVS", label_id, "", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

        /* RÃ³tulo de inÃ­cio do else. */

        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p_else->label);

        node_push (stmt,
            get_line (label_nada, "", "else", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

    }
    statements
    {
        node p = node_pop (label);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p->label);

        node_push (stmt,
            get_line (label_nada, "", "", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

condition_if :
    T_IF expression T_THEN
    {
        node p = node_pop (type);
        if (p->type != TYPE_BOOLEAN)
            yyerror ("expressão em if não é booleana.");

        /*
         * Testa condiÃ§Ã£o e marca o rÃ³tulo de inÃ­cio do else
         * ou do fim do if.
         */
        ctrl->label_count++;

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVF", label_id, "if", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

while :
    T_WHILE
    {
        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);

        sprintf (label_id, "R%02d", ++ctrl->label_count);
        sprintf (label_nada, "R%02d: NADA", ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line (label_nada, "", "while", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    expression T_DO
    {
        node p = node_pop (type);
        if (p->type != TYPE_BOOLEAN)
            yyerror ("expressÃ£o em while nÃ£o Ã© booleana.");

        char* label_id = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_id, "R%02d", ++ctrl->label_count);

        node_push (label, label_id, "",
            CAT_LABEL, TYPE_CONTROL,
            ctrl->level, ctrl->location, ctrl->label_count);

        node_push (stmt,
            get_line ("DSVF", label_id, "do", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    statements
    {
        node p_endwhile = node_pop (label);
        node p_while = node_pop (label);

        char* label_nada = malloc (sizeof(char) * TOKEN_SIZE);
        sprintf (label_nada, "R%02d: NADA", p_endwhile->label);

        node_push (stmt,
            get_line ("DSVS", p_while->token_id, "", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line (label_nada, "", "endwhile", 0), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

expression_list :
    expression
    {
        node c = node_get_tail (call);
        if (strlen (c->token_id))
            c->label++;
    }
    | expression T_COMMA
    {
        node c = node_get_tail (call);
        if (strlen (c->token_id))
            c->label++;
    }
    expression_list
    ;

expression :
    simple_expression
    | simple_expression relop simple_expression
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != q->type)
            yyerror ("comparação relop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, $2, "",
            CAT_STATEMENT, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

simple_expression :
    term
    | simple_expression addop term
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != TYPE_INTEGER ||
            q->type != TYPE_INTEGER)
            yyerror ("addop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, $2, "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

term :
    factor
    | term mulop factor
    {
        node p = node_pop (type);
        node q = node_pop (type);

        if (p->type != TYPE_INTEGER ||
            q->type != TYPE_INTEGER)
            yyerror ("mulop entre tipos inválidos.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt, $2, "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

factor :
    T_IDENTIFIER
    {
        int i = 0;
        char* s = malloc (sizeof(char) * TOKEN_SIZE);

        node p = node_get (symbol, $1);
        node c = node_get_tail (call);

        node_push (type, p->token_id, "",
            CAT_TYPE, p->type,
            ctrl->level, ctrl->location, NO_LABEL);

        /* Ã‰ um chamado sem parÃ¢metros. */

        if (p->category == CAT_FUNCTION
            || p->category == CAT_PROCEDURE) {

            char* param = malloc (sizeof(char) * TOKEN_SIZE);
            sprintf (param, "%s, %d", p->value, ctrl->level);
            strcpy (s, get_line ("CHPR", param, $1, 1));

        /* Ã‰ variÃ¡vel passada por referÃªncia. */

        } else if (p->category == CAT_PARAMREF) {

            node q = node_get (symbol, c->token_id);
            while (i < c->label) {
                if (q->next)
                    q = q->next;
                i++;
            }

            if (q->category != CAT_PARAMREF)
                strcpy (s, get_line ("CRVI",
                    node_get_pos (symbol, $1), $1, 1));

        /* Ã‰ um parÃ¢metro de chamado. */

        } else if (strlen (c->token_id)) {

            p = node_get (symbol, c->token_id);
            while (i < c->label) {
                if (p->next)
                    p = p->next;
                i++;
            }

            if (p->category == CAT_PARAMREF)
                strcpy (s, get_line ("CREN",
                    node_get_pos (symbol, $1), $1, 1));

        }

        if (!strlen (s) )
            strcpy (s, get_line ("CRVL",
                node_get_pos (symbol, $1), $1, 1));

        node_push (stmt, s, "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);

    }
    | call
    | T_INTEGER
    {
        node_push (type, $1, "",
            CAT_TYPE, TYPE_INTEGER,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line("CRCT", $1, $1, 1), $1,
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    | T_LPAR expression T_RPAR
    | T_NOT factor
    {
        node p = node_pop (type);

        if (p->type != TYPE_BOOLEAN)
            yyerror ("not em tipo inválido.");

        node_push (type, p->token_id, "",
            CAT_TYPE, TYPE_BOOLEAN,
            ctrl->level, ctrl->location, NO_LABEL);

        node_push (stmt,
            get_line("NEGA", "", "not", 1), "",
            CAT_STATEMENT, TYPE_CONTROL,
            ctrl->level, ctrl->location, NO_LABEL);
    }
    ;

addop:
    T_PLUS    { strcpy($$, get_line("SOMA", "", "", 1)); }
    | T_MINUS { strcpy($$, get_line("SUBT", "", "", 1)); }
    | T_OR    { strcpy($$, get_line("DISJ", "", "", 1)); }
    ;

mulop :
    T_STAR    { strcpy($$, get_line("MULT", "", "", 1)); }
    | T_DIV   { strcpy($$, get_line("DIVI", "", "", 1)); }
    | T_AND   { strcpy($$, get_line("CONJ", "", "", 1)); }
    ;

relop :
    T_EQ      { strcpy($$, get_line("CMIG", "", "", 1)); }
    | T_NEQ   { strcpy($$, get_line("CMDG", "", "", 1)); }
    | T_LT    { strcpy($$, get_line("CMME", "", "", 1)); }
    | T_GT    { strcpy($$, get_line("CMMA", "", "", 1)); }
    | T_LTE   { strcpy($$, get_line("CMEG", "", "", 1)); }
    | T_GTE   { strcpy($$, get_line("CMAG", "", "", 1)); }
    ;

%%

void yyerror (const char *msg) {
    fprintf(stderr, "\nErro linha %d: %s\n", yyget_lineno(), msg);
}

int main (int argc, char** argv) {

    FILE* fp;
    extern FILE* yyin;

    init();

    ctrl->print_comments = 0;

    if (argc<2 || argc>2) {
          printf("usage compilador <arq>a %d\n", argc);
          return(-1);
       }

    fp=fopen (argv[1], "r");
    if (fp == NULL) {
       printf("usage compilador <arq>b\n");
       return(-1);
    }

    yyin = fp;
    yyparse();

    return 0;
}
