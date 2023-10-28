/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    newid = 258,                   /* newid  */
    INT_CONST = 259,               /* INT_CONST  */
    FLOAT_CONST = 260,             /* FLOAT_CONST  */
    CHAR_CONST = 261,              /* CHAR_CONST  */
    STR_CONST = 262,               /* STR_CONST  */
    BOOL_CONST = 263,              /* BOOL_CONST  */
    PUNC = 264,                    /* PUNC  */
    DATATYPE = 265,                /* DATATYPE  */
    VOID = 266,                    /* VOID  */
    RETURN = 267,                  /* RETURN  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    CONTINUE = 270,                /* CONTINUE  */
    BREAK = 271,                   /* BREAK  */
    MATRIX = 272,                  /* MATRIX  */
    GRAPH = 273,                   /* GRAPH  */
    VECT = 274,                    /* VECT  */
    SWITCH = 275,                  /* SWITCH  */
    CASE = 276,                    /* CASE  */
    DEFAULT = 277,                 /* DEFAULT  */
    CLASS = 278,                   /* CLASS  */
    STRUCT = 279,                  /* STRUCT  */
    LOGOP = 280,                   /* LOGOP  */
    ARITHOP = 281,                 /* ARITHOP  */
    NOT = 282,                     /* NOT  */
    UNARYOP = 283,                 /* UNARYOP  */
    DECLR = 284,                   /* DECLR  */
    EXPR = 285,                    /* EXPR  */
    CALL = 286,                    /* CALL  */
    FUNC = 287,                    /* FUNC  */
    LOOP = 288,                    /* LOOP  */
    null = 289,                    /* null  */
    FOR = 290,                     /* FOR  */
    WHILE = 291,                   /* WHILE  */
    APPEND = 292,                  /* APPEND  */
    REMOVE = 293,                  /* REMOVE  */
    LENGTH = 294,                  /* LENGTH  */
    SORT = 295,                    /* SORT  */
    CLEAR = 296,                   /* CLEAR  */
    AT = 297,                      /* AT  */
    TRANSPOSE = 298,               /* TRANSPOSE  */
    TRACE = 299,                   /* TRACE  */
    TRAVERSAL = 300,               /* TRAVERSAL  */
    STRLEN = 301,                  /* STRLEN  */
    STRCUT = 302,                  /* STRCUT  */
    MATXOP = 303                   /* MATXOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define newid 258
#define INT_CONST 259
#define FLOAT_CONST 260
#define CHAR_CONST 261
#define STR_CONST 262
#define BOOL_CONST 263
#define PUNC 264
#define DATATYPE 265
#define VOID 266
#define RETURN 267
#define IF 268
#define ELSE 269
#define CONTINUE 270
#define BREAK 271
#define MATRIX 272
#define GRAPH 273
#define VECT 274
#define SWITCH 275
#define CASE 276
#define DEFAULT 277
#define CLASS 278
#define STRUCT 279
#define LOGOP 280
#define ARITHOP 281
#define NOT 282
#define UNARYOP 283
#define DECLR 284
#define EXPR 285
#define CALL 286
#define FUNC 287
#define LOOP 288
#define null 289
#define FOR 290
#define WHILE 291
#define APPEND 292
#define REMOVE 293
#define LENGTH 294
#define SORT 295
#define CLEAR 296
#define AT 297
#define TRANSPOSE 298
#define TRACE 299
#define TRAVERSAL 300
#define STRLEN 301
#define STRCUT 302
#define MATXOP 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
