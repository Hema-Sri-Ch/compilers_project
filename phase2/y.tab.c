/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);

#line 82 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ARROW = 264,                   /* ARROW  */
    PUNC = 265,                    /* PUNC  */
    DATATYPE = 266,                /* DATATYPE  */
    VOID = 267,                    /* VOID  */
    RETURN = 268,                  /* RETURN  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    CONTINUE = 271,                /* CONTINUE  */
    BREAK = 272,                   /* BREAK  */
    MATRIX = 273,                  /* MATRIX  */
    GRAPH = 274,                   /* GRAPH  */
    VECT = 275,                    /* VECT  */
    SWITCH = 276,                  /* SWITCH  */
    CASE = 277,                    /* CASE  */
    DEFAULT = 278,                 /* DEFAULT  */
    CLASS = 279,                   /* CLASS  */
    STRUCT = 280,                  /* STRUCT  */
    LOGOP = 281,                   /* LOGOP  */
    ARITHOP = 282,                 /* ARITHOP  */
    NOT = 283,                     /* NOT  */
    UNARYOP = 284,                 /* UNARYOP  */
    DECLR = 285,                   /* DECLR  */
    EXPR = 286,                    /* EXPR  */
    CALL = 287,                    /* CALL  */
    FUNC = 288,                    /* FUNC  */
    LOOP = 289,                    /* LOOP  */
    null = 290,                    /* null  */
    FOR = 291,                     /* FOR  */
    WHILE = 292,                   /* WHILE  */
    APPEND = 293,                  /* APPEND  */
    REMOVE = 294,                  /* REMOVE  */
    LENGTH = 295,                  /* LENGTH  */
    SORT = 296,                    /* SORT  */
    CLEAR = 297,                   /* CLEAR  */
    AT = 298,                      /* AT  */
    TRANSPOSE = 299,               /* TRANSPOSE  */
    TRACE = 300,                   /* TRACE  */
    TRAVERSAL = 301,               /* TRAVERSAL  */
    STRLEN = 302,                  /* STRLEN  */
    STRCUT = 303,                  /* STRCUT  */
    STRCMP = 304,                  /* STRCMP  */
    STRJOIN = 305,                 /* STRJOIN  */
    MATXOP = 306,                  /* MATXOP  */
    MAXTOGR = 307,                 /* MAXTOGR  */
    GRTOMATX = 308,                /* GRTOMATX  */
    SHPATH = 309,                  /* SHPATH  */
    SHPATHVAL = 310,               /* SHPATHVAL  */
    GOTO = 311                     /* GOTO  */
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
#define ARROW 264
#define PUNC 265
#define DATATYPE 266
#define VOID 267
#define RETURN 268
#define IF 269
#define ELSE 270
#define CONTINUE 271
#define BREAK 272
#define MATRIX 273
#define GRAPH 274
#define VECT 275
#define SWITCH 276
#define CASE 277
#define DEFAULT 278
#define CLASS 279
#define STRUCT 280
#define LOGOP 281
#define ARITHOP 282
#define NOT 283
#define UNARYOP 284
#define DECLR 285
#define EXPR 286
#define CALL 287
#define FUNC 288
#define LOOP 289
#define null 290
#define FOR 291
#define WHILE 292
#define APPEND 293
#define REMOVE 294
#define LENGTH 295
#define SORT 296
#define CLEAR 297
#define AT 298
#define TRANSPOSE 299
#define TRACE 300
#define TRAVERSAL 301
#define STRLEN 302
#define STRCUT 303
#define STRCMP 304
#define STRJOIN 305
#define MATXOP 306
#define MAXTOGR 307
#define GRTOMATX 308
#define SHPATH 309
#define SHPATHVAL 310
#define GOTO 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_newid = 3,                      /* newid  */
  YYSYMBOL_INT_CONST = 4,                  /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 5,                /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 6,                 /* CHAR_CONST  */
  YYSYMBOL_STR_CONST = 7,                  /* STR_CONST  */
  YYSYMBOL_BOOL_CONST = 8,                 /* BOOL_CONST  */
  YYSYMBOL_ARROW = 9,                      /* ARROW  */
  YYSYMBOL_PUNC = 10,                      /* PUNC  */
  YYSYMBOL_DATATYPE = 11,                  /* DATATYPE  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_MATRIX = 18,                    /* MATRIX  */
  YYSYMBOL_GRAPH = 19,                     /* GRAPH  */
  YYSYMBOL_VECT = 20,                      /* VECT  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_CLASS = 24,                     /* CLASS  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_LOGOP = 26,                     /* LOGOP  */
  YYSYMBOL_ARITHOP = 27,                   /* ARITHOP  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_UNARYOP = 29,                   /* UNARYOP  */
  YYSYMBOL_DECLR = 30,                     /* DECLR  */
  YYSYMBOL_EXPR = 31,                      /* EXPR  */
  YYSYMBOL_CALL = 32,                      /* CALL  */
  YYSYMBOL_FUNC = 33,                      /* FUNC  */
  YYSYMBOL_LOOP = 34,                      /* LOOP  */
  YYSYMBOL_null = 35,                      /* null  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_APPEND = 38,                    /* APPEND  */
  YYSYMBOL_REMOVE = 39,                    /* REMOVE  */
  YYSYMBOL_LENGTH = 40,                    /* LENGTH  */
  YYSYMBOL_SORT = 41,                      /* SORT  */
  YYSYMBOL_CLEAR = 42,                     /* CLEAR  */
  YYSYMBOL_AT = 43,                        /* AT  */
  YYSYMBOL_TRANSPOSE = 44,                 /* TRANSPOSE  */
  YYSYMBOL_TRACE = 45,                     /* TRACE  */
  YYSYMBOL_TRAVERSAL = 46,                 /* TRAVERSAL  */
  YYSYMBOL_STRLEN = 47,                    /* STRLEN  */
  YYSYMBOL_STRCUT = 48,                    /* STRCUT  */
  YYSYMBOL_STRCMP = 49,                    /* STRCMP  */
  YYSYMBOL_STRJOIN = 50,                   /* STRJOIN  */
  YYSYMBOL_MATXOP = 51,                    /* MATXOP  */
  YYSYMBOL_MAXTOGR = 52,                   /* MAXTOGR  */
  YYSYMBOL_GRTOMATX = 53,                  /* GRTOMATX  */
  YYSYMBOL_SHPATH = 54,                    /* SHPATH  */
  YYSYMBOL_SHPATHVAL = 55,                 /* SHPATHVAL  */
  YYSYMBOL_GOTO = 56,                      /* GOTO  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '<'  */
  YYSYMBOL_64_ = 64,                       /* '>'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program_unit = 71,              /* program_unit  */
  YYSYMBOL_models = 72,                    /* models  */
  YYSYMBOL_model = 73,                     /* model  */
  YYSYMBOL_class = 74,                     /* class  */
  YYSYMBOL_id = 75,                        /* id  */
  YYSYMBOL_class_items = 76,               /* class_items  */
  YYSYMBOL_class_item = 77,                /* class_item  */
  YYSYMBOL_struct = 78,                    /* struct  */
  YYSYMBOL_struct_items = 79,              /* struct_items  */
  YYSYMBOL_function = 80,                  /* function  */
  YYSYMBOL_function_head = 81,             /* function_head  */
  YYSYMBOL_fdtype = 82,                    /* fdtype  */
  YYSYMBOL_param_list = 83,                /* param_list  */
  YYSYMBOL_dtype = 84,                     /* dtype  */
  YYSYMBOL_function_body = 85,             /* function_body  */
  YYSYMBOL_statements = 86,                /* statements  */
  YYSYMBOL_statement = 87,                 /* statement  */
  YYSYMBOL_unary_stmt = 88,                /* unary_stmt  */
  YYSYMBOL_jump_stmt = 89,                 /* jump_stmt  */
  YYSYMBOL_label_stmt = 90,                /* label_stmt  */
  YYSYMBOL_goto_stmt = 91,                 /* goto_stmt  */
  YYSYMBOL_vect_stmt = 92,                 /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 93,            /* vect_stmt_body  */
  YYSYMBOL_remove_body = 94,               /* remove_body  */
  YYSYMBOL_vect_append = 95,               /* vect_append  */
  YYSYMBOL_return_stmt = 96,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 97,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 98,                 /* loop_type  */
  YYSYMBOL_for_loop = 99,                  /* for_loop  */
  YYSYMBOL_for_expr = 100,                 /* for_expr  */
  YYSYMBOL_while_loop = 101,               /* while_loop  */
  YYSYMBOL_expr_stmt = 102,                /* expr_stmt  */
  YYSYMBOL_LHS = 103,                      /* LHS  */
  YYSYMBOL_declr_stmt = 104,               /* declr_stmt  */
  YYSYMBOL_declr_body = 105,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 106,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 107,              /* matrix_list  */
  YYSYMBOL_id_list = 108,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 109,              /* ifcond_stmt  */
  YYSYMBOL_110_1 = 110,                    /* $@1  */
  YYSYMBOL_if_body = 111,                  /* if_body  */
  YYSYMBOL_switch_stmt = 112,              /* switch_stmt  */
  YYSYMBOL_113_2 = 113,                    /* $@2  */
  YYSYMBOL_switch_body = 114,              /* switch_body  */
  YYSYMBOL_cases = 115,                    /* cases  */
  YYSYMBOL_RHS = 116,                      /* RHS  */
  YYSYMBOL_constants = 117,                /* constants  */
  YYSYMBOL_extra_consts = 118,             /* extra_consts  */
  YYSYMBOL_array_const = 119,              /* array_const  */
  YYSYMBOL_val_list = 120,                 /* val_list  */
  YYSYMBOL_resultant = 121,                /* resultant  */
  YYSYMBOL_impr = 122,                     /* impr  */
  YYSYMBOL_graph_impr = 123,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 124,              /* matrix_impr  */
  YYSYMBOL_matr_body = 125,                /* matr_body  */
  YYSYMBOL_graph_const = 126,              /* graph_const  */
  YYSYMBOL_graph_type1 = 127,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 128,              /* graph_type2  */
  YYSYMBOL_int_list = 129,                 /* int_list  */
  YYSYMBOL_float_list = 130,               /* float_list  */
  YYSYMBOL_char_list = 131,                /* char_list  */
  YYSYMBOL_bool_list = 132,                /* bool_list  */
  YYSYMBOL_str_list = 133,                 /* str_list  */
  YYSYMBOL_weight_list = 134,              /* weight_list  */
  YYSYMBOL_vect_const = 135,               /* vect_const  */
  YYSYMBOL_vect_list = 136,                /* vect_list  */
  YYSYMBOL_matrix_const = 137,             /* matrix_const  */
  YYSYMBOL_int_float_list = 138,           /* int_float_list  */
  YYSYMBOL_mat_list = 139,                 /* mat_list  */
  YYSYMBOL_arith_op = 140,                 /* arith_op  */
  YYSYMBOL_binary_op = 141,                /* binary_op  */
  YYSYMBOL_unary_op = 142,                 /* unary_op  */
  YYSYMBOL_logical_op = 143,               /* logical_op  */
  YYSYMBOL_call_stmt = 144,                /* call_stmt  */
  YYSYMBOL_func_calls = 145,               /* func_calls  */
  YYSYMBOL_arg_list = 146                  /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   994

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  440

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    61,     2,     2,    62,     2,    66,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    59,
      63,    67,    64,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    73,    74,    77,    78,    79,    82,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   105,   106,   109,
     110,   113,   116,   117,   120,   123,   124,   127,   128,   131,
     132,   135,   136,   137,   138,   139,   142,   143,   146,   147,
     148,   149,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   166,   169,   170,   173,   176,   179,
     182,   183,   184,   185,   189,   190,   191,   192,   193,   194,
     195,   199,   200,   203,   204,   205,   206,   207,   208,   212,
     215,   216,   219,   222,   223,   224,   225,   226,   227,   228,
     231,   234,   235,   236,   237,   238,   241,   242,   245,   247,
     248,   249,   250,   251,   252,   253,   256,   257,   260,   261,
     264,   265,   268,   268,   271,   272,   275,   275,   278,   281,
     282,   286,   287,   288,   289,   290,   294,   295,   296,   297,
     298,   299,   303,   304,   305,   306,   307,   311,   312,   315,
     316,   317,   318,   319,   322,   323,   324,   325,   326,   329,
     330,   331,   332,   333,   334,   335,   340,   341,   342,   343,
     347,   348,   349,   352,   353,   356,   357,   360,   361,   364,
     365,   368,   369,   372,   373,   376,   377,   380,   381,   384,
     385,   388,   389,   390,   391,   394,   397,   398,   399,   400,
     403,   406,   407,   408,   409,   412,   413,   416,   417,   420,
     423,   426,   427,   430,   433,   434,   437,   438
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "newid", "INT_CONST",
  "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "BOOL_CONST", "ARROW", "PUNC",
  "DATATYPE", "VOID", "RETURN", "IF", "ELSE", "CONTINUE", "BREAK",
  "MATRIX", "GRAPH", "VECT", "SWITCH", "CASE", "DEFAULT", "CLASS",
  "STRUCT", "LOGOP", "ARITHOP", "NOT", "UNARYOP", "DECLR", "EXPR", "CALL",
  "FUNC", "LOOP", "null", "FOR", "WHILE", "APPEND", "REMOVE", "LENGTH",
  "SORT", "CLEAR", "AT", "TRANSPOSE", "TRACE", "TRAVERSAL", "STRLEN",
  "STRCUT", "STRCMP", "STRJOIN", "MATXOP", "MAXTOGR", "GRTOMATX", "SHPATH",
  "SHPATHVAL", "GOTO", "'{'", "'}'", "';'", "'('", "')'", "','", "'<'",
  "'>'", "':'", "'.'", "'='", "'['", "']'", "$accept", "program_unit",
  "models", "model", "class", "id", "class_items", "class_item", "struct",
  "struct_items", "function", "function_head", "fdtype", "param_list",
  "dtype", "function_body", "statements", "statement", "unary_stmt",
  "jump_stmt", "label_stmt", "goto_stmt", "vect_stmt", "vect_stmt_body",
  "remove_body", "vect_append", "return_stmt", "loop_stmt", "loop_type",
  "for_loop", "for_expr", "while_loop", "expr_stmt", "LHS", "declr_stmt",
  "declr_body", "graph_and_array_list", "matrix_list", "id_list",
  "ifcond_stmt", "$@1", "if_body", "switch_stmt", "$@2", "switch_body",
  "cases", "RHS", "constants", "extra_consts", "array_const", "val_list",
  "resultant", "impr", "graph_impr", "matrix_impr", "matr_body",
  "graph_const", "graph_type1", "graph_type2", "int_list", "float_list",
  "char_list", "bool_list", "str_list", "weight_list", "vect_const",
  "vect_list", "matrix_const", "int_float_list", "mat_list", "arith_op",
  "binary_op", "unary_op", "logical_op", "call_stmt", "func_calls",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-318)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-159)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   500,   500,   891,    34,  -318,    66,  -318,  -318,  -318,
     -16,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,   -10,
       0,  -318,  -318,  -318,  -318,    -3,  -318,   500,  -318,  -318,
    -318,   780,  -318,     2,    23,   939,     5,   411,    15,    10,
      18,    22,    42,   126,   500,   500,     1,    49,    54,    58,
     500,  -318,     6,   836,    26,   836,  -318,  -318,  -318,  -318,
    -318,    20,  -318,  -318,  -318,  -318,  -318,  -318,  -318,    28,
    -318,  -318,  -318,    67,  -318,    71,    78,     2,  -318,  -318,
      80,    23,    75,   182,  -318,  -318,  -318,  -318,  -318,    87,
      88,    90,   527,   697,   115,   143,    94,    89,    95,  -318,
     100,  -318,    96,   104,   105,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,   697,  -318,  -318,   697,   697,   500,   500,
     500,    97,   500,   500,   106,   111,   107,   108,   112,  -318,
    -318,  -318,   697,   697,   697,   114,   500,   -16,  -318,  -318,
    -318,  -318,   558,  -318,  -318,   127,  -318,   128,  -318,  -318,
    -318,   110,   500,   697,   697,  -318,   123,  -318,  -318,   132,
     133,   131,   138,   139,  -318,   172,   137,   141,   147,   148,
     149,    82,  -318,   144,  -318,  -318,  -318,  -318,  -318,   145,
    -318,  -318,  -318,  -318,  -318,   154,   155,   156,   -42,  -318,
    -318,   151,  -318,   165,  -318,   939,   500,   500,  -318,   469,
     638,   208,   697,   178,   179,  -318,   180,   183,  -318,  -318,
    -318,   184,   188,   193,   195,   197,   198,   202,   204,   205,
     206,   209,   211,   213,   214,   217,  -318,  -318,  -318,   218,
     220,   222,    21,   583,   583,  -318,  -318,  -318,   697,   275,
     279,   280,   282,   283,   230,   235,   229,  -318,  -318,  -318,
    -318,  -318,   500,   295,   296,   237,   240,  -318,  -318,   244,
     245,   246,   247,   249,  -318,   248,   251,    -4,   253,   697,
     697,   697,   469,   727,   254,   256,   258,   727,   259,   281,
     727,   288,   727,   289,   290,   727,   727,   939,   697,  -318,
     305,   285,   286,  -318,  -318,   291,  -318,  -318,  -318,  -318,
    -318,    82,    82,   294,   -16,   297,  -318,   271,   274,   500,
    -318,  -318,  -318,  -318,  -318,   697,  -318,   298,   -16,   299,
     304,   306,   307,  -318,  -318,  -318,  -318,   308,    89,    96,
    -318,  -318,  -318,  -318,  -318,  -318,   309,  -318,  -318,   310,
    -318,   293,  -318,  -318,   311,   312,  -318,   314,   315,   352,
     354,  -318,  -318,  -318,   316,   344,  -318,   350,  -318,   326,
     321,  -318,  -318,    19,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,   727,   727,   727,  -318,   101,   301,  -318,   313,
    -318,  -318,   -16,   372,   367,   500,   387,   500,   331,  -318,
     332,   334,   335,   336,   337,   275,   339,  -318,   338,   340,
    -318,   341,   333,   -16,  -318,  -318,  -318,   342,   345,   -16,
     -16,   346,   284,  -318,   339,   339,   350,   343,   500,   355,
      96,   356,   180,  -318,  -318,  -318,  -318,  -318,  -318,  -318
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,    23,    24,    25,    26,     0,
       0,    41,    38,    42,    43,     0,    45,     0,    37,     1,
       3,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    21,     0,
       0,    47,   106,    51,     0,    49,    60,    57,    65,    66,
      61,   157,    59,    58,    52,   154,    54,    55,    56,     0,
     158,   156,   155,     0,    53,     0,     0,    28,    30,    29,
       0,    33,     0,     0,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,   106,   157,   141,     0,   131,
       0,   142,   135,   156,   155,   143,   144,   145,   132,   207,
     208,   133,   134,     0,    63,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,     0,     0,     0,     0,     0,     0,    50,    46,
      48,    69,     0,    64,   213,     0,    27,     0,    32,    44,
      35,     0,     0,     0,     0,    88,   136,   146,   141,   197,
     199,     0,     0,     0,   157,     0,   182,   184,   186,   190,
     188,     0,   148,     0,   149,   150,   151,   152,   153,     0,
      87,    83,    84,    85,    86,     0,     0,     0,   121,   113,
     109,     0,   112,     0,   110,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,   173,   174,     0,    68,   107,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    31,    36,    40,
       0,     0,     0,     0,     0,   175,   176,   195,     0,     0,
       0,     0,     0,     0,   203,   204,     0,   147,   200,   122,
     126,   210,     0,     0,     0,     0,   121,   115,   114,   157,
       0,     0,   156,   155,   215,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   212,
       0,     0,     0,   196,   198,     0,   181,   183,   185,   189,
     187,     0,     0,     0,     0,     0,   120,     0,     0,     0,
     105,   101,   102,   103,   104,     0,   214,     0,     0,     0,
       0,     0,     0,    81,    82,    74,    75,     0,    76,    80,
      78,    79,    77,   159,    72,    73,     0,   171,   161,     0,
     162,     0,   172,   167,     0,     0,    39,     0,     0,   178,
     180,   211,   201,   202,   206,   125,   123,     0,   127,   117,
       0,   111,   216,     0,   100,   163,   165,   170,    70,    71,
     160,   166,     0,     0,     0,   209,     0,     0,   177,     0,
     179,   205,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
     116,     0,     0,     0,   164,   168,   169,   192,   194,     0,
       0,   119,     0,    92,     0,     0,   130,     0,     0,    98,
      96,    97,    99,    94,    95,   191,   193,   129,   128,   118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -318,  -318,   403,  -318,  -318,    -1,   324,  -318,  -318,   351,
     -29,  -318,  -318,   129,     7,    -7,     9,  -318,  -318,  -318,
    -318,  -318,  -318,   -35,  -192,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,   212,   -36,    24,  -318,  -117,     3,  -184,  -318,
    -318,  -318,  -318,  -318,  -318,     4,   -30,   -86,   -40,  -318,
    -318,  -318,   -20,   -39,   -43,   152,  -318,    65,    68,   -93,
     175,   181,   176,   185,  -317,  -318,  -127,  -318,  -187,    70,
    -241,  -318,   -32,  -207,  -318,    -2,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,   105,    86,    87,     8,    90,
       9,    10,    37,   161,   162,    63,    64,    65,    66,    67,
      68,    69,    70,   174,   337,   332,    72,    73,   139,   140,
     398,   141,    74,   107,    76,   134,   199,   202,   200,    77,
     314,   366,    78,   315,   368,   394,   215,   109,   170,   111,
     183,    79,   112,    81,    82,   217,   115,   171,   172,   301,
     185,   186,   187,   188,   302,   116,   173,   117,   256,   189,
     118,   119,   120,   121,    84,   122,   276
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    30,    36,    42,   114,    75,    71,   110,   113,    83,
      38,   184,   106,   204,    88,   146,   169,   108,   135,   136,
     262,    80,   267,   268,   100,   176,   263,    75,    71,    75,
      71,    83,    53,    83,    39,     3,    46,   137,   138,    85,
      62,    41,   340,    80,    36,    80,   340,    43,    52,   340,
     397,   340,    92,    53,   340,   340,   103,    44,    88,   145,
      45,    85,    62,    85,    62,    93,   168,    89,    91,   124,
     327,   147,   148,   175,   150,   123,   341,   125,   316,   151,
     341,   300,   126,   341,   149,   341,   254,   255,   341,   341,
       1,     2,    36,   195,   152,   346,   196,   197,   349,     3,
     351,   216,   127,   354,   355,   403,   404,   435,   436,   142,
     219,    89,   213,   214,   143,    91,   303,   304,   144,   176,
     177,   178,   179,   180,   362,   363,   153,   198,   201,   203,
     154,   206,   207,   240,   241,   371,   155,   128,   157,   159,
     220,   340,   340,   340,   129,   130,   131,   163,   164,   165,
     132,   133,   146,   190,   191,  -154,   306,   169,   169,   192,
     205,   239,  -158,   193,   194,   208,   273,   210,   211,   271,
     272,   238,   212,   218,   269,   341,   341,   341,   209,   270,
     275,   433,   278,   181,   182,    11,   236,   237,   242,   245,
     400,   401,   402,    31,   243,   244,   246,   247,   248,   249,
      33,    34,    35,   250,    36,   266,   266,   168,   168,   251,
     252,   253,   265,   257,   258,   259,   260,   261,   305,   264,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   263,    25,    26,    27,    28,   216,    54,
     279,   280,   334,   160,   282,   281,  -155,   338,   283,   329,
     330,   338,   333,   284,   338,   285,   338,   286,   287,   338,
     338,   266,   288,   339,   289,   290,   291,   339,   357,   292,
     339,   293,   339,   294,   295,   339,   339,   296,   410,   176,
     297,   342,   298,   299,   177,   342,   178,    11,   342,   179,
     342,   180,   311,   342,   342,   275,    36,   312,   313,   317,
     318,   319,   262,   320,   321,   322,   323,   365,   324,   358,
     325,    99,   326,    52,   328,   343,    55,   344,   266,   345,
     347,   374,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    57,    58,    59,    25,    26,    27,    28,
     369,   399,   348,   370,   359,   360,   338,   338,   338,   350,
     352,   353,   361,   364,   367,   382,   387,   373,   389,   392,
     375,   412,   339,   339,   339,   376,   405,   377,   378,   379,
     380,   381,   393,   383,   384,   385,   408,   386,   406,   432,
     342,   342,   342,   431,   181,   407,    75,   429,   395,   396,
     409,   411,   413,   414,   203,   415,   416,   417,   418,   300,
     422,   438,   430,   419,   424,   420,   423,   425,   428,    40,
     421,   156,   426,   427,    11,    94,    95,    96,    97,    98,
     434,  -157,  -156,   277,   388,   307,   356,   201,   390,   310,
     437,   439,   308,   331,   391,     0,     0,   309,    99,   100,
      52,   372,   158,    55,     0,     0,   101,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      57,    58,    59,    25,    26,    27,    28,     0,   102,     0,
       0,   103,    11,    94,    95,    96,    97,    98,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,    52,     0,
       0,    55,     0,    11,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    57,    58,
      59,    25,    26,    27,    28,     0,   102,     0,     0,   103,
      11,   166,    95,    96,    97,    98,     0,   104,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,     0,   102,   167,    11,    94,    95,    96,
      97,    98,     0,     0,     0,   104,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,     0,     0,     0,
     232,   233,   234,   235,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,    27,    28,     0,
     102,    11,    94,    95,    96,    97,    98,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,    52,     0,     0,
      55,     0,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    57,    58,    59,
      25,    26,    27,    28,     0,     0,     0,     0,   103,   274,
      11,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,    52,     0,     0,    55,
      11,   335,   336,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    57,    58,    59,    25,
      26,    27,    28,     0,    99,   100,    52,   103,     0,    55,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    57,    58,    59,    25,
      26,    27,    28,    11,     0,     0,     0,   103,     0,     0,
       0,     0,     0,    47,    48,     0,    49,    50,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,    56,     0,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    57,
      58,    59,    25,    26,    27,    28,    60,    41,    61,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,    49,    50,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,     0,
      56,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    57,    58,    59,    25,    26,
      27,    28,    60,    41,    11,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,     0,     0,     0,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    11,    25,    26,    27,    28,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    10,    47,    41,    41,    47,    47,    41,
       3,   104,    47,   130,    43,     9,   102,    47,    54,    55,
      62,    41,   206,   207,    28,     4,    68,    63,    63,    65,
      65,    63,    30,    65,     0,    33,    37,    36,    37,    41,
      41,    57,   283,    63,    45,    65,   287,    57,    29,   290,
      31,   292,    45,    30,   295,   296,    60,    57,    87,    60,
      63,    63,    63,    65,    65,    60,   102,    43,    44,    59,
     277,    65,    63,   103,    65,    60,   283,    59,   262,    59,
     287,    60,    60,   290,    58,   292,     4,     5,   295,   296,
      24,    25,    93,   123,    66,   287,   126,   127,   290,    33,
     292,   144,    60,   295,   296,     4,     5,   424,   425,    60,
     146,    87,   142,   143,    60,    91,   243,   244,    60,     4,
       5,     6,     7,     8,   311,   312,    59,   128,   129,   130,
      59,   132,   133,   163,   164,   319,    58,    11,    58,    64,
     147,   382,   383,   384,    18,    19,    20,    60,    60,    59,
      24,    25,     9,    59,    59,    66,   249,   243,   244,    59,
      63,   162,    66,    59,    59,    59,   209,    60,    60,   209,
     209,    61,    60,    59,   209,   382,   383,   384,    67,   209,
     210,   422,   212,    68,    69,     3,    59,    59,    65,    58,
     382,   383,   384,    11,    62,    62,    58,    58,    26,    62,
      18,    19,    20,    62,   205,   206,   207,   243,   244,    62,
      62,    62,   205,    69,    69,    61,    61,    61,   248,    68,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    68,    52,    53,    54,    55,   281,    31,
      62,    62,   282,    61,    60,    62,    66,   283,    60,   279,
     280,   287,   282,    60,   290,    60,   292,    60,    60,   295,
     296,   262,    60,   283,    60,    60,    60,   287,   298,    60,
     290,    60,   292,    60,    60,   295,   296,    60,   395,     4,
      62,   283,    62,    61,     5,   287,     6,     3,   290,     7,
     292,     8,    62,   295,   296,   325,   297,    62,    69,     4,
       4,    64,    62,    59,    59,    59,    59,   314,    59,     4,
      62,    27,    61,    29,    61,    61,    32,    61,   319,    61,
      61,   328,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      69,   373,    61,    69,    59,    59,   382,   383,   384,    61,
      61,    61,    61,    59,    57,    62,     4,    59,     4,    15,
      61,   397,   382,   383,   384,    61,    65,    61,    61,    61,
      61,    61,    22,    62,    62,    61,     4,    62,    65,   422,
     382,   383,   384,   422,    68,   392,   422,   422,    62,    68,
      23,     4,    61,    61,   395,    61,    61,    61,    61,    60,
      67,    58,   422,    65,    62,    65,   413,    62,    62,     6,
      69,    87,   419,   420,     3,     4,     5,     6,     7,     8,
     422,    66,    66,   211,   359,   250,   297,   428,   360,   253,
     426,   428,   251,   281,   364,    -1,    -1,   252,    27,    28,
      29,   325,    91,    32,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    60,     3,     4,     5,     6,     7,     8,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,     3,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    60,
       3,     4,     5,     6,     7,     8,    -1,    68,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    -1,    57,    58,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    68,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    -1,
      57,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
       3,     4,     5,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    27,    28,    29,    60,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     3,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    16,    17,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    16,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     3,    52,    53,    54,    55,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    71,    72,    73,    74,    78,    80,
      81,     3,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    52,    53,    54,    55,    75,
      75,    11,    12,    18,    19,    20,    75,    82,    84,     0,
      72,    57,    85,    57,    57,    63,    75,    13,    14,    16,
      17,    21,    29,    30,    31,    32,    34,    49,    50,    51,
      56,    58,    75,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    96,    97,   102,   103,   104,   109,   112,   121,
     122,   123,   124,   142,   144,   145,    76,    77,    80,   104,
      79,   104,    84,    60,     4,     5,     6,     7,     8,    27,
      28,    35,    57,    60,    68,    75,    93,   103,   116,   117,
     118,   119,   122,   123,   124,   126,   135,   137,   140,   141,
     142,   143,   145,    60,    59,    59,    60,    60,    11,    18,
      19,    20,    24,    25,   105,   103,   103,    36,    37,    98,
      99,   101,    60,    60,    60,    75,     9,    65,    86,    58,
      86,    59,    66,    59,    59,    58,    76,    58,    79,    64,
      61,    83,    84,    60,    60,    59,     4,    58,   103,   117,
     118,   127,   128,   136,    93,   116,     4,     5,     6,     7,
       8,    68,    69,   120,   129,   130,   131,   132,   133,   139,
      59,    59,    59,    59,    59,   116,   116,   116,    75,   106,
     108,    75,   107,    75,   106,    63,    75,    75,    59,    67,
      60,    60,    60,   116,   116,   116,   124,   125,    59,   103,
      85,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    52,    53,    54,    55,    59,    59,    61,    75,
     116,   116,    65,    62,    62,    58,    58,    58,    26,    62,
      62,    62,    62,    62,     4,     5,   138,    69,    69,    61,
      61,    61,    62,    68,    68,    84,    75,   108,   108,    93,
     116,   118,   123,   124,    61,   116,   146,   102,   116,    62,
      62,    62,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    62,    62,    61,
      60,   129,   134,   136,   136,   116,   129,   130,   131,   133,
     132,    62,    62,    69,   110,   113,   108,     4,     4,    64,
      59,    59,    59,    59,    59,    62,    61,   143,    61,   116,
     116,   125,    95,   116,   118,     4,     5,    94,   103,   122,
     140,   143,   145,    61,    61,    61,    94,    61,    61,    94,
      61,    94,    61,    61,    94,    94,    83,   116,     4,    59,
      59,    61,   138,   138,    59,    85,   111,    57,   114,    69,
      69,   108,   146,    59,    85,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    61,    62,     4,   127,     4,
     128,   139,    15,    22,   115,    62,    68,    31,   100,   142,
      94,    94,    94,     4,     5,    65,    65,    85,     4,    23,
     106,     4,   103,    61,    61,    61,    61,    61,    61,    65,
      65,    69,    67,    85,    62,    62,    85,    85,    62,    93,
     122,   123,   124,   140,   145,   134,   134,   115,    58,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    91,    92,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    97,
      98,    98,    99,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   102,   102,   102,   102,   103,   103,   104,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     108,   108,   110,   109,   111,   111,   113,   112,   114,   115,
     115,   116,   116,   116,   116,   116,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   135,   136,   136,   136,   136,
     137,   138,   138,   138,   138,   139,   139,   140,   140,   141,
     142,   143,   143,   144,   145,   145,   146,   146
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     6,     2,     1,     2,     5,     6,     1,     1,     4,
       2,     1,     1,     1,     4,     1,     3,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     3,     3,     2,
       6,     6,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     8,     1,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     5,     5,     5,     1,     3,     3,     2,
       2,     5,     2,     2,     3,     3,     6,     4,     9,     7,
       3,     1,     0,     6,     3,     1,     0,     6,     6,     5,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       6,     5,     5,     6,     8,     6,     6,     5,     8,     8,
       6,     5,     5,     1,     1,     3,     3,     5,     4,     5,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     7,     5,     7,     5,     3,     3,     1,     3,     1,
       3,     3,     3,     1,     1,     5,     4,     1,     1,     6,
       4,     5,     4,     2,     5,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* class: CLASS id '{' class_items '}' ';'  */
#line 82 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1786 "y.tab.c"
    break;

  case 31: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 113 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1792 "y.tab.c"
    break;

  case 35: /* function_head: FUNC fdtype id '(' ')'  */
#line 123 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1798 "y.tab.c"
    break;

  case 36: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 124 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1804 "y.tab.c"
    break;

  case 62: /* statement: BREAK ';'  */
#line 162 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 1810 "y.tab.c"
    break;

  case 63: /* statement: CONTINUE ';'  */
#line 163 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 1816 "y.tab.c"
    break;

  case 64: /* unary_stmt: unary_op ';'  */
#line 166 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 1822 "y.tab.c"
    break;

  case 67: /* label_stmt: id ':' function_body  */
#line 173 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 1828 "y.tab.c"
    break;

  case 68: /* goto_stmt: GOTO id ';'  */
#line 176 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 1834 "y.tab.c"
    break;

  case 69: /* vect_stmt: vect_stmt_body ';'  */
#line 179 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 1840 "y.tab.c"
    break;

  case 83: /* return_stmt: RETURN RHS ';'  */
#line 203 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1846 "y.tab.c"
    break;

  case 84: /* return_stmt: RETURN extra_consts ';'  */
#line 204 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 1852 "y.tab.c"
    break;

  case 85: /* return_stmt: RETURN graph_impr ';'  */
#line 205 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 1858 "y.tab.c"
    break;

  case 86: /* return_stmt: RETURN matrix_impr ';'  */
#line 206 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 1864 "y.tab.c"
    break;

  case 87: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 207 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 1870 "y.tab.c"
    break;

  case 88: /* return_stmt: RETURN null ';'  */
#line 208 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 1876 "y.tab.c"
    break;

  case 89: /* loop_stmt: LOOP loop_type  */
#line 212 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1882 "y.tab.c"
    break;

  case 101: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 234 "parser.y"
                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1888 "y.tab.c"
    break;

  case 102: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 235 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1894 "y.tab.c"
    break;

  case 103: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 236 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1900 "y.tab.c"
    break;

  case 104: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 237 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1906 "y.tab.c"
    break;

  case 105: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 238 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1912 "y.tab.c"
    break;

  case 108: /* declr_stmt: DECLR declr_body ';'  */
#line 245 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1918 "y.tab.c"
    break;

  case 122: /* $@1: %empty  */
#line 268 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1924 "y.tab.c"
    break;

  case 126: /* $@2: %empty  */
#line 275 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1930 "y.tab.c"
    break;

  case 213: /* call_stmt: func_calls ';'  */
#line 430 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1936 "y.tab.c"
    break;


#line 1940 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 441 "parser.y"


/*
int main(){
	yyparse();
	return 0;
}
*/


int yyerror(const char *msg)
{
	/*
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	printf( " : invalid statement");
	return 0;
	*/
	printf("Parsing Failed\nLine Number: %d, %s\n",yylineno,msg);
	fprintf(fparse, " : invalid statement");
	exit(0);
}

int main() {
 	FILE* fp = fopen("input.txt", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




