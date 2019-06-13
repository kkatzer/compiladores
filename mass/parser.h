/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IGNORE = 258,
    T_IDENTIFIER = 259,
    T_DOUBLE = 260,
    T_INTEGER = 261,
    T_EQ = 262,
    T_NEQ = 263,
    T_GTE = 264,
    T_GT = 265,
    T_LTE = 266,
    T_LT = 267,
    T_ASSIGNMENT = 268,
    T_LPAR = 269,
    T_RPAR = 270,
    T_DOT = 271,
    T_COMMA = 272,
    T_COLON = 273,
    T_SEMICOLON = 274,
    T_PLUS = 275,
    T_MINUS = 276,
    T_STAR = 277,
    T_DIV = 278,
    T_AND = 279,
    T_OR = 280,
    T_NOT = 281,
    T_PROGRAM = 282,
    T_BEGIN = 283,
    T_END = 284,
    T_LABEL = 285,
    T_VAR = 286,
    T_FUNCTION = 287,
    T_PROCEDURE = 288,
    T_IF = 289,
    T_THEN = 290,
    T_ELSE = 291,
    T_WHILE = 292,
    T_DO = 293,
    T_GOTO = 294,
    T_READ = 295,
    T_WRITE = 296,
    T_FORWARD = 297
  };
#endif
/* Tokens.  */
#define T_IGNORE 258
#define T_IDENTIFIER 259
#define T_DOUBLE 260
#define T_INTEGER 261
#define T_EQ 262
#define T_NEQ 263
#define T_GTE 264
#define T_GT 265
#define T_LTE 266
#define T_LT 267
#define T_ASSIGNMENT 268
#define T_LPAR 269
#define T_RPAR 270
#define T_DOT 271
#define T_COMMA 272
#define T_COLON 273
#define T_SEMICOLON 274
#define T_PLUS 275
#define T_MINUS 276
#define T_STAR 277
#define T_DIV 278
#define T_AND 279
#define T_OR 280
#define T_NOT 281
#define T_PROGRAM 282
#define T_BEGIN 283
#define T_END 284
#define T_LABEL 285
#define T_VAR 286
#define T_FUNCTION 287
#define T_PROCEDURE 288
#define T_IF 289
#define T_THEN 290
#define T_ELSE 291
#define T_WHILE 292
#define T_DO 293
#define T_GOTO 294
#define T_READ 295
#define T_WRITE 296
#define T_FORWARD 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "parser.y" /* yacc.c:1909  */

    char str[TOKEN_SIZE];

#line 142 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
