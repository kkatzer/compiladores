/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ABRE_PARENTESES = 259,
     FECHA_PARENTESES = 260,
     VIRGULA = 261,
     PONTO_E_VIRGULA = 262,
     DOIS_PONTOS = 263,
     PONTO = 264,
     T_BEGIN = 265,
     T_END = 266,
     VAR = 267,
     IDENT = 268,
     ATRIBUICAO = 269,
     LABEL = 270,
     TYPE = 271,
     ARRAY = 272,
     OF = 273,
     PROCEDURE = 274,
     FUNCTION = 275,
     GOTO = 276,
     IF = 277,
     THEN = 278,
     ELSE = 279,
     WHILE = 280,
     DO = 281,
     MAIS = 282,
     MENOS = 283,
     OR = 284,
     MULTIPLICACAO = 285,
     DIV = 286,
     AND = 287,
     NOT = 288,
     NUMERO = 289,
     IGUAL = 290,
     MAIGUAL = 291,
     MEIGUAL = 292,
     MAIOR = 293,
     MENOR = 294,
     NIGUAL = 295
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ABRE_PARENTESES 259
#define FECHA_PARENTESES 260
#define VIRGULA 261
#define PONTO_E_VIRGULA 262
#define DOIS_PONTOS 263
#define PONTO 264
#define T_BEGIN 265
#define T_END 266
#define VAR 267
#define IDENT 268
#define ATRIBUICAO 269
#define LABEL 270
#define TYPE 271
#define ARRAY 272
#define OF 273
#define PROCEDURE 274
#define FUNCTION 275
#define GOTO 276
#define IF 277
#define THEN 278
#define ELSE 279
#define WHILE 280
#define DO 281
#define MAIS 282
#define MENOS 283
#define OR 284
#define MULTIPLICACAO 285
#define DIV 286
#define AND 287
#define NOT 288
#define NUMERO 289
#define IGUAL 290
#define MAIGUAL 291
#define MEIGUAL 292
#define MAIOR 293
#define MENOR 294
#define NIGUAL 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "parser.y"
{
  char str[TAM_TOKEN];
}
/* Line 1529 of yacc.c.  */
#line 133 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

