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
    SHPATHVAL = 310                /* SHPATHVAL  */
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
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '<'  */
  YYSYMBOL_63_ = 63,                       /* '>'  */
  YYSYMBOL_64_ = 64,                       /* '.'  */
  YYSYMBOL_65_ = 65,                       /* '='  */
  YYSYMBOL_66_ = 66,                       /* '['  */
  YYSYMBOL_67_ = 67,                       /* ']'  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program_unit = 70,              /* program_unit  */
  YYSYMBOL_models = 71,                    /* models  */
  YYSYMBOL_model = 72,                     /* model  */
  YYSYMBOL_class = 73,                     /* class  */
  YYSYMBOL_id = 74,                        /* id  */
  YYSYMBOL_class_items = 75,               /* class_items  */
  YYSYMBOL_class_item = 76,                /* class_item  */
  YYSYMBOL_struct = 77,                    /* struct  */
  YYSYMBOL_struct_items = 78,              /* struct_items  */
  YYSYMBOL_function = 79,                  /* function  */
  YYSYMBOL_function_head = 80,             /* function_head  */
  YYSYMBOL_fdtype = 81,                    /* fdtype  */
  YYSYMBOL_param_list = 82,                /* param_list  */
  YYSYMBOL_dtype = 83,                     /* dtype  */
  YYSYMBOL_function_body = 84,             /* function_body  */
  YYSYMBOL_statements = 85,                /* statements  */
  YYSYMBOL_statement = 86,                 /* statement  */
  YYSYMBOL_vect_stmt = 87,                 /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 88,            /* vect_stmt_body  */
  YYSYMBOL_remove_body = 89,               /* remove_body  */
  YYSYMBOL_vect_append = 90,               /* vect_append  */
  YYSYMBOL_return_stmt = 91,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 92,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 93,                 /* loop_type  */
  YYSYMBOL_for_loop = 94,                  /* for_loop  */
  YYSYMBOL_for_expr = 95,                  /* for_expr  */
  YYSYMBOL_while_loop = 96,                /* while_loop  */
  YYSYMBOL_expr_stmt = 97,                 /* expr_stmt  */
  YYSYMBOL_LHS = 98,                       /* LHS  */
  YYSYMBOL_declr_stmt = 99,                /* declr_stmt  */
  YYSYMBOL_declr_body = 100,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 101,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 102,              /* matrix_list  */
  YYSYMBOL_id_list = 103,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 104,              /* ifcond_stmt  */
  YYSYMBOL_105_1 = 105,                    /* $@1  */
  YYSYMBOL_if_body = 106,                  /* if_body  */
  YYSYMBOL_switch_stmt = 107,              /* switch_stmt  */
  YYSYMBOL_108_2 = 108,                    /* $@2  */
  YYSYMBOL_switch_body = 109,              /* switch_body  */
  YYSYMBOL_cases = 110,                    /* cases  */
  YYSYMBOL_RHS = 111,                      /* RHS  */
  YYSYMBOL_class_struct_items = 112,       /* class_struct_items  */
  YYSYMBOL_constants = 113,                /* constants  */
  YYSYMBOL_extra_consts = 114,             /* extra_consts  */
  YYSYMBOL_array_const = 115,              /* array_const  */
  YYSYMBOL_val_list = 116,                 /* val_list  */
  YYSYMBOL_resultant = 117,                /* resultant  */
  YYSYMBOL_impr = 118,                     /* impr  */
  YYSYMBOL_graph_impr = 119,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 120,              /* matrix_impr  */
  YYSYMBOL_matr_body = 121,                /* matr_body  */
  YYSYMBOL_graph_const = 122,              /* graph_const  */
  YYSYMBOL_graph_type1 = 123,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 124,              /* graph_type2  */
  YYSYMBOL_int_list = 125,                 /* int_list  */
  YYSYMBOL_float_list = 126,               /* float_list  */
  YYSYMBOL_char_list = 127,                /* char_list  */
  YYSYMBOL_bool_list = 128,                /* bool_list  */
  YYSYMBOL_str_list = 129,                 /* str_list  */
  YYSYMBOL_weight_list = 130,              /* weight_list  */
  YYSYMBOL_vect_const = 131,               /* vect_const  */
  YYSYMBOL_vect_list = 132,                /* vect_list  */
  YYSYMBOL_matrix_const = 133,             /* matrix_const  */
  YYSYMBOL_int_float_list = 134,           /* int_float_list  */
  YYSYMBOL_mat_list = 135,                 /* mat_list  */
  YYSYMBOL_arith_op = 136,                 /* arith_op  */
  YYSYMBOL_binary_op = 137,                /* binary_op  */
  YYSYMBOL_unary_op = 138,                 /* unary_op  */
  YYSYMBOL_logical_op = 139,               /* logical_op  */
  YYSYMBOL_call_stmt = 140,                /* call_stmt  */
  YYSYMBOL_func_calls = 141,               /* func_calls  */
  YYSYMBOL_arg_list = 142                  /* arg_list  */
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
#define YYLAST   1081

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  444

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      59,    60,     2,     2,    61,     2,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    58,
      62,    65,    63,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    72,    73,    76,    77,    78,    81,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   104,   105,   108,
     109,   112,   115,   116,   119,   122,   123,   126,   127,   130,
     131,   134,   135,   136,   137,   138,   141,   142,   145,   146,
     147,   148,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   163,   166,   167,   168,   169,   173,   174,   175,
     176,   177,   178,   179,   183,   184,   187,   188,   189,   190,
     191,   192,   196,   199,   200,   203,   206,   207,   210,   213,
     214,   215,   216,   217,   220,   221,   224,   226,   227,   228,
     229,   230,   231,   232,   235,   236,   239,   240,   243,   244,
     247,   247,   250,   251,   254,   254,   257,   260,   261,   265,
     266,   267,   268,   269,   270,   273,   276,   277,   278,   279,
     280,   281,   285,   286,   287,   288,   289,   293,   294,   297,
     298,   299,   300,   301,   304,   305,   306,   307,   310,   311,
     312,   313,   314,   315,   316,   321,   322,   323,   324,   328,
     329,   330,   333,   334,   337,   338,   341,   342,   345,   346,
     349,   350,   353,   354,   357,   358,   361,   362,   365,   366,
     369,   370,   371,   372,   375,   378,   379,   380,   381,   384,
     387,   388,   389,   390,   393,   394,   397,   398,   401,   404,
     407,   408,   411,   414,   415,   416,   417,   420,   421
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
  "SHPATHVAL", "'{'", "'}'", "';'", "'('", "')'", "','", "'<'", "'>'",
  "'.'", "'='", "'['", "']'", "':'", "$accept", "program_unit", "models",
  "model", "class", "id", "class_items", "class_item", "struct",
  "struct_items", "function", "function_head", "fdtype", "param_list",
  "dtype", "function_body", "statements", "statement", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "while_loop",
  "expr_stmt", "LHS", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@1", "if_body", "switch_stmt",
  "$@2", "switch_body", "cases", "RHS", "class_struct_items", "constants",
  "extra_consts", "array_const", "val_list", "resultant", "impr",
  "graph_impr", "matrix_impr", "matr_body", "graph_const", "graph_type1",
  "graph_type2", "int_list", "float_list", "char_list", "bool_list",
  "str_list", "weight_list", "vect_const", "vect_list", "matrix_const",
  "int_float_list", "mat_list", "arith_op", "binary_op", "unary_op",
  "logical_op", "call_stmt", "func_calls", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   164,   164,   978,    13,  -326,     0,  -326,  -326,  -326,
     -25,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   -17,
       2,  -326,  -326,  -326,  -326,    11,  -326,   164,  -326,  -326,
    -326,   869,  -326,    -4,    40,  1026,    17,   426,    19,    26,
      31,    33,   109,   164,   164,    44,    45,    53,    58,  -326,
     110,   924,    61,   924,  -326,    72,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,    67,  -326,  -326,  -326,    77,    79,
      -4,  -326,  -326,    80,    40,    76,   734,  -326,  -326,  -326,
    -326,  -326,    82,    84,    87,    90,   540,   763,   103,     8,
      93,    96,    78,  -326,    97,  -326,    98,    99,   102,   106,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   763,  -326,
    -326,   763,   164,   164,   164,    95,   164,   164,   108,   111,
       5,   119,   120,  -326,  -326,  -326,   763,   763,   763,   164,
    -326,  -326,  -326,  -326,   455,  -326,   122,  -326,   123,  -326,
    -326,  -326,   124,   164,   763,   763,   763,  -326,   100,  -326,
    -326,   121,   127,   126,   135,   136,  -326,   168,   134,   138,
     159,   160,   161,    83,  -326,   156,  -326,  -326,  -326,  -326,
    -326,   157,  -326,  -326,  -326,   512,  -326,  -326,   165,   166,
     -38,  -326,  -326,   162,  -326,   163,  -326,  1026,   164,   164,
    -326,   483,   164,   623,   196,   763,   174,   176,  -326,   175,
     180,  -326,   184,   185,   186,   187,   188,   189,   191,   192,
     195,   197,   199,  -326,  -326,  -326,   200,   205,   207,   209,
      15,   569,   569,  -326,  -326,  -326,   763,   256,   268,   269,
     274,   279,   227,   228,   223,  -326,  -326,   232,   233,   234,
     235,  -326,  -326,   164,   291,   293,   237,   240,  -326,  -326,
     245,   252,   254,   255,   257,   258,  -326,   259,   262,    -8,
     263,   763,   763,   763,   483,   816,   264,   266,   267,   816,
     270,   271,   272,   816,   275,  1026,   763,  -326,  -326,   312,
     260,   261,  -326,  -326,   277,  -326,  -326,  -326,  -326,  -326,
      83,    83,   276,   816,   278,   816,   816,   273,   284,  -326,
     280,   281,   164,  -326,  -326,  -326,  -326,  -326,   681,   763,
    -326,   283,   286,   289,   294,   295,   296,  -326,  -326,  -326,
    -326,   299,   298,    99,  -326,  -326,  -326,  -326,  -326,  -326,
     304,  -326,  -326,  -326,   282,  -326,  -326,   305,   292,   324,
     364,  -326,  -326,  -326,   306,   311,  -326,   313,   314,   924,
    -326,   355,  -326,   326,   322,  -326,  -326,   329,  -326,     1,
     924,  -326,  -326,  -326,  -326,  -326,  -326,   816,  -326,    92,
     323,  -326,   327,  -326,  -326,  -326,   816,   816,   335,   390,
     373,   164,   394,  -326,   164,   339,  -326,   347,   345,   349,
     350,   256,   352,   353,   354,   397,   356,   367,  -326,   348,
     358,   361,  -326,  -326,   357,   375,  -326,  -326,   382,   383,
     387,   384,    18,   924,   352,   352,   924,   924,   924,   164,
    -326,   389,  -326,  -326,   391,   392,   393,  -326,  -326,  -326,
     355,   395,  -326,  -326
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
       0,     0,     0,     0,     0,     0,    22,    21,     0,    47,
      94,    51,     0,    49,    59,   146,    58,    57,    52,   144,
      54,    55,    56,    95,     0,   147,   145,    53,     0,     0,
      28,    30,    29,     0,    33,     0,     0,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,   131,
     146,     0,   120,   119,     0,   132,     0,   124,     0,   145,
     133,   134,   135,   121,   196,   197,   122,   123,     0,    61,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,     0,     0,     0,     0,
      50,    46,    48,    62,     0,   202,     0,    27,     0,    32,
      44,    35,     0,     0,     0,     0,     0,    81,   126,   136,
     131,   186,   188,     0,     0,     0,   146,     0,   171,   173,
     175,   179,   177,     0,   138,     0,   139,   140,   141,   142,
     143,     0,    80,    76,    77,     0,    78,    79,     0,     0,
     109,   101,    97,     0,   100,     0,    98,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,   162,   163,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    31,    36,    40,     0,     0,     0,
       0,     0,     0,   164,   165,   184,     0,     0,     0,     0,
       0,     0,   192,   193,     0,   137,   189,     0,     0,     0,
       0,   110,   114,     0,     0,     0,     0,   109,   103,   102,
     146,     0,     0,     0,   145,     0,   204,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   199,     0,
       0,     0,   185,   187,     0,   170,   172,   174,   178,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,    93,    89,    90,    91,    92,     0,     0,
     203,     0,     0,     0,     0,     0,     0,    74,    75,    67,
      68,     0,    69,    73,    71,    72,    70,   148,    65,    66,
       0,   160,   150,   151,     0,   161,    39,     0,     0,   167,
     169,   200,   190,   191,   195,     0,   156,     0,     0,     0,
     111,     0,   115,   105,     0,    99,   206,     0,   207,     0,
       0,   152,   154,   159,    63,    64,   149,     0,   198,     0,
       0,   166,     0,   168,   194,   155,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,   104,     0,
       0,     0,    88,   153,   181,   183,   157,   158,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,   180,   182,     0,     0,     0,   106,    85,   112,
     118,     0,   117,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,   438,  -326,  -326,    -1,   371,  -326,  -326,   363,
     -21,  -326,  -326,   171,     3,   447,   -45,  -326,  -326,    14,
    -200,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   297,   -41,
       6,  -326,  -121,    30,  -188,  -326,  -326,  -326,  -326,  -326,
    -326,    20,    35,   -26,   -87,   -42,  -326,  -326,   -43,   -20,
     303,   -40,   190,  -326,   113,   133,   -90,   246,   301,   265,
     321,  -325,  -326,  -130,  -326,  -187,   151,  -237,  -326,   139,
    -212,  -326,    -7,  -203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    99,    79,    80,     8,    83,
       9,    10,    37,   152,   153,    61,    62,    63,    64,   166,
     331,   326,    66,    67,   133,   134,   395,   135,    68,    69,
      70,   128,   191,   194,   192,    71,   307,   360,    72,   308,
     362,   390,   267,   102,   103,   162,   105,   175,    74,   107,
     108,    76,   210,   110,   163,   164,   290,   177,   178,   179,
     180,   291,   111,   165,   112,   244,   181,   113,   114,   115,
     116,    77,   117,   268
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    30,    36,   196,   106,   104,    38,   109,   176,   161,
     258,   259,   129,    39,   202,    73,   140,   139,   142,   168,
      93,    75,    81,   253,     1,     2,    52,    73,   254,     3,
      94,    41,   394,     3,    78,    73,    46,    73,   334,    43,
      60,    75,   334,    75,    36,    92,   334,    94,    85,    82,
      84,    97,    60,   130,    78,    65,    78,   321,    44,    81,
      60,   100,    60,   335,   203,   309,   334,   335,   334,   334,
      52,   335,   -94,    45,   289,    65,    86,    65,   118,   340,
     131,   132,   101,   344,   119,    36,    82,   242,   243,   120,
      84,   335,   121,   335,   335,   160,   399,   400,   209,   432,
     433,   292,   293,   355,   136,   357,   358,   168,   169,   170,
     171,   172,   137,   352,   353,   367,   368,   138,   141,   139,
     122,   190,   193,   195,   365,   198,   199,   123,   124,   125,
     143,   144,   167,   126,   127,   145,   146,   148,   211,   150,
     334,   154,   -95,   155,   161,   161,   156,   295,   157,   334,
     334,   182,   226,   188,   183,   184,   189,   197,   106,   262,
     186,   264,   185,  -147,   187,   335,   200,    11,   230,   173,
     174,   206,   207,   208,   335,   335,   201,   398,   204,   205,
     223,   224,   231,   233,   225,   430,   403,   404,   232,   227,
     228,   229,   234,   235,   236,   237,    36,   257,   257,   238,
     256,   265,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   260,    25,    26,    27,    28,
     239,   240,   241,   245,   246,   251,   252,    53,   255,   254,
     160,   160,   328,   209,   332,   271,   261,   272,   332,  -145,
     270,   273,   332,   274,   275,   276,   277,   278,   279,    73,
     280,   281,   257,    73,   282,   333,   283,    73,   284,   333,
     168,   285,   332,   333,   332,   332,   286,   287,   336,   288,
     408,   294,   336,   169,    60,   170,   336,    73,    60,    73,
      73,   171,    60,   333,    36,   333,   333,   172,   300,   301,
     302,   303,   304,   305,   306,   310,   336,   311,   336,   336,
     312,   253,    60,   313,    60,    60,   323,   324,   208,   327,
     314,   257,   315,   316,   388,   317,   348,   318,   349,   350,
     319,   347,   320,   322,   337,   397,   338,   339,   380,   359,
     341,   342,   343,    73,   354,   345,   332,   351,   356,    75,
     361,   369,   370,   377,    73,   332,   332,   363,   364,   371,
      75,    73,    78,   379,   372,   373,   374,   333,    60,   375,
      73,    73,  -144,    78,   376,   378,   333,   333,   382,    60,
     336,   385,   173,    65,   386,   387,    60,   389,   431,   336,
     336,   434,   435,   436,    65,    60,    60,   391,   392,   393,
     195,   401,   405,   410,   406,   402,   407,    73,   409,   411,
      73,    73,    73,    75,   412,   413,    75,    75,    75,   414,
     415,   289,   418,   416,   417,   421,    78,   423,   424,    78,
      78,    78,    60,   422,   419,    60,    60,    60,   193,    11,
      87,    88,    89,    90,    91,   420,   425,    65,   426,   427,
      65,    65,    65,   428,    40,   429,   438,   149,   439,   440,
     441,   147,   443,    92,    93,    94,   346,    42,    54,   437,
     442,    95,   381,   325,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    56,    57,    58,    25,    26,
      27,    28,    96,   383,   296,    97,    11,    87,    88,    89,
      90,    91,    98,   212,   213,   214,   215,   216,   217,   218,
     219,   269,   220,   221,   263,   384,   299,   222,   396,     0,
      92,    93,    94,     0,     0,    54,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    56,    57,    58,    25,    26,    27,    28,    96,
     297,     0,    97,    11,   158,    88,    89,    90,    91,    98,
     212,   213,   214,   215,   216,   217,   218,   219,   247,   220,
     221,   298,     0,     0,   222,   248,   249,   250,     0,     0,
       0,     0,    11,    87,    88,    89,    90,    91,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,    27,    28,    96,   159,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,    96,    11,    87,    88,    89,
      90,    91,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,    54,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    56,    57,    58,    25,    26,    27,    28,     0,
       0,     0,    97,   266,    11,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,     0,    54,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      56,    57,    58,    25,    26,    27,    28,    11,     0,     0,
      97,   366,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,    88,    89,
      90,    91,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,    27,    28,
      92,    93,    94,     0,   151,    54,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    56,    57,    58,    25,    26,    27,    28,    11,
     329,   330,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,     0,     0,    54,     0,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    56,    57,    58,    25,    26,
      27,    28,    11,     0,     0,    97,     0,     0,     0,     0,
       0,     0,    47,    48,     0,    49,    50,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,    55,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    56,    57,
      58,    25,    26,    27,    28,    41,    59,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     0,
      49,    50,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,    55,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    56,    57,    58,    25,    26,    27,    28,
      41,    11,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    11,
      25,    26,    27,    28,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   124,    47,    47,     3,    47,    98,    96,
     198,   199,    53,     0,     9,    41,    61,     9,    63,     4,
      28,    41,    43,    61,    24,    25,    30,    53,    66,    33,
      29,    56,    31,    33,    41,    61,    37,    63,   275,    56,
      41,    61,   279,    63,    45,    27,   283,    29,    45,    43,
      44,    59,    53,    54,    61,    41,    63,   269,    56,    80,
      61,    47,    63,   275,    59,   253,   303,   279,   305,   306,
      30,   283,    64,    62,    59,    61,    59,    63,    59,   279,
      36,    37,    47,   283,    58,    86,    80,     4,     5,    58,
      84,   303,    59,   305,   306,    96,     4,     5,   138,   424,
     425,   231,   232,   303,    59,   305,   306,     4,     5,     6,
       7,     8,    59,   300,   301,   318,   319,    59,    57,     9,
      11,   122,   123,   124,   312,   126,   127,    18,    19,    20,
      58,    64,    97,    24,    25,    58,    57,    57,   139,    63,
     377,    59,    64,    59,   231,   232,    59,   237,    58,   386,
     387,    58,   153,   118,    58,    58,   121,    62,   201,   201,
      58,   201,    64,    64,    58,   377,    58,     3,    68,    66,
      67,   136,   137,   138,   386,   387,    65,   377,    59,    59,
      58,    58,    61,    57,    60,   422,   386,   387,    61,   154,
     155,   156,    57,    57,    26,    61,   197,   198,   199,    61,
     197,   202,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   201,    52,    53,    54,    55,
      61,    61,    61,    67,    67,    60,    60,    31,    66,    66,
     231,   232,   274,   273,   275,    61,   201,    61,   279,    64,
     205,    61,   283,    59,    59,    59,    59,    59,    59,   275,
      59,    59,   253,   279,    59,   275,    59,   283,    59,   279,
       4,    61,   303,   283,   305,   306,    61,    60,   275,    60,
     391,   236,   279,     5,   275,     6,   283,   303,   279,   305,
     306,     7,   283,   303,   285,   305,   306,     8,    61,    61,
      67,    59,    59,    59,    59,     4,   303,     4,   305,   306,
      63,    61,   303,    58,   305,   306,   271,   272,   273,   274,
      58,   312,    58,    58,   359,    58,     4,    59,    58,    58,
      61,   286,    60,    60,    60,   370,    60,    60,     4,    56,
      60,    60,    60,   359,    58,    60,   377,    60,    60,   359,
      56,    58,    56,    61,   370,   386,   387,    67,    67,    60,
     370,   377,   359,    61,    60,    60,    60,   377,   359,    60,
     386,   387,    64,   370,    60,    60,   386,   387,     4,   370,
     377,    60,    66,   359,    61,    61,   377,    22,   423,   386,
     387,   426,   427,   428,   370,   386,   387,    61,    66,    60,
     391,    68,    57,   394,     4,    68,    23,   423,     4,    60,
     426,   427,   428,   423,    57,    60,   426,   427,   428,    60,
      60,    59,    15,    60,    60,    67,   423,    56,    61,   426,
     427,   428,   423,    65,    68,   426,   427,   428,   429,     3,
       4,     5,     6,     7,     8,    68,    61,   423,    56,    56,
     426,   427,   428,    56,     6,    61,    57,    84,    57,    57,
      57,    80,    57,    27,    28,    29,   285,    10,    32,   429,
     440,    35,   349,   273,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   350,   238,    59,     3,     4,     5,     6,
       7,     8,    66,    38,    39,    40,    41,    42,    43,    44,
      45,   204,    47,    48,   201,   354,   241,    52,   369,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     239,    -1,    59,     3,     4,     5,     6,     7,     8,    66,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   240,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,    -1,    -1,
      59,    60,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      27,    28,    29,    -1,    60,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
       4,     5,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     3,
      52,    53,    54,    55,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    70,    71,    72,    73,    77,    79,
      80,     3,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    52,    53,    54,    55,    74,
      74,    11,    12,    18,    19,    20,    74,    81,    83,     0,
      71,    56,    84,    56,    56,    62,    74,    13,    14,    16,
      17,    21,    30,    31,    32,    34,    49,    50,    51,    57,
      74,    84,    85,    86,    87,    88,    91,    92,    97,    98,
      99,   104,   107,   112,   117,   118,   120,   140,   141,    75,
      76,    79,    99,    78,    99,    83,    59,     4,     5,     6,
       7,     8,    27,    28,    29,    35,    56,    59,    66,    74,
      88,   111,   112,   113,   114,   115,   117,   118,   119,   120,
     122,   131,   133,   136,   137,   138,   139,   141,    59,    58,
      58,    59,    11,    18,    19,    20,    24,    25,   100,    98,
      74,    36,    37,    93,    94,    96,    59,    59,    59,     9,
      85,    57,    85,    58,    64,    58,    57,    75,    57,    78,
      63,    60,    82,    83,    59,    59,    59,    58,     4,    57,
      74,   113,   114,   123,   124,   132,    88,   111,     4,     5,
       6,     7,     8,    66,    67,   116,   125,   126,   127,   128,
     129,   135,    58,    58,    58,    64,    58,    58,   111,   111,
      74,   101,   103,    74,   102,    74,   101,    62,    74,    74,
      58,    65,     9,    59,    59,    59,   111,   111,   111,   120,
     121,    74,    38,    39,    40,    41,    42,    43,    44,    45,
      47,    48,    52,    58,    58,    60,    74,   111,   111,   111,
      68,    61,    61,    57,    57,    57,    26,    61,    61,    61,
      61,    61,     4,     5,   134,    67,    67,    46,    53,    54,
      55,    60,    60,    61,    66,    66,    83,    74,   103,   103,
      88,   111,   114,   119,   120,    74,    60,   111,   142,    97,
     111,    61,    61,    61,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    61,    61,    60,    60,    59,
     125,   130,   132,   132,   111,   125,   126,   127,   129,   128,
      61,    61,    67,    59,    59,    59,    59,   105,   108,   103,
       4,     4,    63,    58,    58,    58,    58,    58,    59,    61,
      60,   139,    60,   111,   111,   121,    90,   111,   114,     4,
       5,    89,    98,   118,   136,   139,   141,    60,    60,    60,
      89,    60,    60,    60,    89,    60,    82,   111,     4,    58,
      58,    60,   134,   134,    58,    89,    60,    89,    89,    56,
     106,    56,   109,    67,    67,   103,    60,   142,   142,    58,
      56,    60,    60,    60,    60,    60,    60,    61,    60,    61,
       4,   123,     4,   124,   135,    60,    61,    61,    85,    22,
     110,    61,    66,    60,    31,    95,   138,    85,    89,     4,
       5,    68,    68,    89,    89,    57,     4,    23,   101,     4,
      74,    60,    57,    60,    60,    60,    60,    60,    15,    68,
      68,    67,    65,    56,    61,    61,    56,    56,    56,    61,
     136,    85,   130,   130,    85,    85,    85,   102,    57,    57,
      57,    57,   110,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    72,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    94,    95,    95,    96,    97,
      97,    97,    97,    97,    98,    98,    99,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     105,   104,   106,   106,   108,   107,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   131,   132,   132,   132,   132,   133,
     134,   134,   134,   134,   135,   135,   136,   136,   137,   138,
     139,   139,   140,   141,   141,   141,   141,   142,   142
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
       2,     2,     2,     6,     6,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     1,     1,    10,     1,     4,     7,     5,
       5,     5,     5,     5,     1,     1,     3,     2,     2,     5,
       2,     2,     3,     3,     6,     4,     9,     7,     3,     1,
       0,     6,     7,     3,     0,     6,     8,     7,     6,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       5,     5,     6,     8,     6,     6,     5,     8,     8,     6,
       5,     5,     1,     1,     3,     3,     5,     4,     5,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       7,     5,     7,     5,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     1,     5,     4,     1,     1,     6,     4,
       5,     4,     2,     5,     4,     7,     6,     3,     1
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
#line 81 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1797 "y.tab.c"
    break;

  case 31: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 112 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1803 "y.tab.c"
    break;

  case 35: /* function_head: FUNC fdtype id '(' ')'  */
#line 122 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1809 "y.tab.c"
    break;

  case 36: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 123 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1815 "y.tab.c"
    break;

  case 60: /* statement: BREAK ';'  */
#line 159 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 1821 "y.tab.c"
    break;

  case 61: /* statement: CONTINUE ';'  */
#line 160 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 1827 "y.tab.c"
    break;

  case 62: /* vect_stmt: vect_stmt_body ';'  */
#line 163 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 1833 "y.tab.c"
    break;

  case 76: /* return_stmt: RETURN RHS ';'  */
#line 187 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1839 "y.tab.c"
    break;

  case 77: /* return_stmt: RETURN extra_consts ';'  */
#line 188 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 1845 "y.tab.c"
    break;

  case 78: /* return_stmt: RETURN graph_impr ';'  */
#line 189 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 1851 "y.tab.c"
    break;

  case 79: /* return_stmt: RETURN matrix_impr ';'  */
#line 190 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 1857 "y.tab.c"
    break;

  case 80: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 191 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 1863 "y.tab.c"
    break;

  case 81: /* return_stmt: RETURN null ';'  */
#line 192 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 1869 "y.tab.c"
    break;

  case 82: /* loop_stmt: LOOP loop_type  */
#line 196 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1875 "y.tab.c"
    break;

  case 89: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 213 "parser.y"
                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1881 "y.tab.c"
    break;

  case 90: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 214 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1887 "y.tab.c"
    break;

  case 91: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 215 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1893 "y.tab.c"
    break;

  case 92: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 216 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1899 "y.tab.c"
    break;

  case 93: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 217 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1905 "y.tab.c"
    break;

  case 96: /* declr_stmt: DECLR declr_body ';'  */
#line 224 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1911 "y.tab.c"
    break;

  case 110: /* $@1: %empty  */
#line 247 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1917 "y.tab.c"
    break;

  case 114: /* $@2: %empty  */
#line 254 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1923 "y.tab.c"
    break;

  case 202: /* call_stmt: func_calls ';'  */
#line 411 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1929 "y.tab.c"
    break;


#line 1933 "y.tab.c"

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

#line 424 "parser.y"


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




