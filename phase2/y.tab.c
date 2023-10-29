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
    MATXOP = 306                   /* MATXOP  */
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
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '<'  */
  YYSYMBOL_59_ = 59,                       /* '>'  */
  YYSYMBOL_60_ = 60,                       /* '.'  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* '['  */
  YYSYMBOL_63_ = 63,                       /* ']'  */
  YYSYMBOL_64_ = 64,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program_unit = 66,              /* program_unit  */
  YYSYMBOL_models = 67,                    /* models  */
  YYSYMBOL_model = 68,                     /* model  */
  YYSYMBOL_class = 69,                     /* class  */
  YYSYMBOL_id = 70,                        /* id  */
  YYSYMBOL_class_items = 71,               /* class_items  */
  YYSYMBOL_class_item = 72,                /* class_item  */
  YYSYMBOL_struct = 73,                    /* struct  */
  YYSYMBOL_struct_items = 74,              /* struct_items  */
  YYSYMBOL_function = 75,                  /* function  */
  YYSYMBOL_function_head = 76,             /* function_head  */
  YYSYMBOL_fdtype = 77,                    /* fdtype  */
  YYSYMBOL_param_list = 78,                /* param_list  */
  YYSYMBOL_dtype = 79,                     /* dtype  */
  YYSYMBOL_function_body = 80,             /* function_body  */
  YYSYMBOL_statements = 81,                /* statements  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_vect_stmt = 83,                 /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 84,            /* vect_stmt_body  */
  YYSYMBOL_remove_body = 85,               /* remove_body  */
  YYSYMBOL_vect_append = 86,               /* vect_append  */
  YYSYMBOL_return_stmt = 87,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 88,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 89,                 /* loop_type  */
  YYSYMBOL_for_loop = 90,                  /* for_loop  */
  YYSYMBOL_for_expr = 91,                  /* for_expr  */
  YYSYMBOL_while_loop = 92,                /* while_loop  */
  YYSYMBOL_expr_stmt = 93,                 /* expr_stmt  */
  YYSYMBOL_LHS = 94,                       /* LHS  */
  YYSYMBOL_declr_stmt = 95,                /* declr_stmt  */
  YYSYMBOL_declr_body = 96,                /* declr_body  */
  YYSYMBOL_graph_and_array_list = 97,      /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 98,               /* matrix_list  */
  YYSYMBOL_id_list = 99,                   /* id_list  */
  YYSYMBOL_ifcond_stmt = 100,              /* ifcond_stmt  */
  YYSYMBOL_101_1 = 101,                    /* $@1  */
  YYSYMBOL_if_body = 102,                  /* if_body  */
  YYSYMBOL_switch_stmt = 103,              /* switch_stmt  */
  YYSYMBOL_104_2 = 104,                    /* $@2  */
  YYSYMBOL_switch_body = 105,              /* switch_body  */
  YYSYMBOL_cases = 106,                    /* cases  */
  YYSYMBOL_RHS = 107,                      /* RHS  */
  YYSYMBOL_class_struct_items = 108,       /* class_struct_items  */
  YYSYMBOL_constants = 109,                /* constants  */
  YYSYMBOL_extra_consts = 110,             /* extra_consts  */
  YYSYMBOL_array_const = 111,              /* array_const  */
  YYSYMBOL_val_list = 112,                 /* val_list  */
  YYSYMBOL_resultant = 113,                /* resultant  */
  YYSYMBOL_impr = 114,                     /* impr  */
  YYSYMBOL_graph_impr = 115,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 116,              /* matrix_impr  */
  YYSYMBOL_matr_body = 117,                /* matr_body  */
  YYSYMBOL_graph_const = 118,              /* graph_const  */
  YYSYMBOL_graph_type1 = 119,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 120,              /* graph_type2  */
  YYSYMBOL_int_list = 121,                 /* int_list  */
  YYSYMBOL_float_list = 122,               /* float_list  */
  YYSYMBOL_char_list = 123,                /* char_list  */
  YYSYMBOL_bool_list = 124,                /* bool_list  */
  YYSYMBOL_str_list = 125,                 /* str_list  */
  YYSYMBOL_weight_list = 126,              /* weight_list  */
  YYSYMBOL_vect_const = 127,               /* vect_const  */
  YYSYMBOL_vect_list = 128,                /* vect_list  */
  YYSYMBOL_matrix_const = 129,             /* matrix_const  */
  YYSYMBOL_int_float_list = 130,           /* int_float_list  */
  YYSYMBOL_mat_list = 131,                 /* mat_list  */
  YYSYMBOL_arith_op = 132,                 /* arith_op  */
  YYSYMBOL_binary_op = 133,                /* binary_op  */
  YYSYMBOL_unary_op = 134,                 /* unary_op  */
  YYSYMBOL_logical_op = 135,               /* logical_op  */
  YYSYMBOL_call_stmt = 136,                /* call_stmt  */
  YYSYMBOL_func_calls = 137,               /* func_calls  */
  YYSYMBOL_arg_list = 138                  /* arg_list  */
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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   891

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      55,    56,     2,     2,    57,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    54,
      58,    61,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    68,    69,    72,    73,    74,    77,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    96,    97,   100,   101,   104,   107,   108,
     111,   114,   115,   118,   119,   122,   123,   126,   127,   128,
     129,   130,   133,   134,   137,   138,   139,   140,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   155,   158,
     159,   160,   161,   165,   166,   167,   168,   169,   170,   171,
     175,   176,   179,   180,   181,   182,   183,   184,   188,   191,
     192,   195,   198,   199,   202,   205,   206,   207,   208,   209,
     212,   213,   216,   218,   219,   220,   221,   222,   223,   224,
     227,   228,   231,   232,   235,   236,   239,   239,   242,   243,
     246,   246,   249,   252,   253,   257,   258,   259,   260,   261,
     262,   265,   268,   269,   270,   271,   272,   273,   277,   278,
     279,   280,   281,   285,   286,   289,   290,   291,   292,   293,
     296,   297,   298,   299,   302,   303,   304,   305,   306,   307,
     308,   313,   317,   318,   321,   322,   325,   326,   329,   330,
     333,   334,   337,   338,   341,   342,   345,   346,   349,   350,
     353,   354,   357,   358,   359,   360,   363,   366,   367,   368,
     369,   372,   375,   376,   377,   378,   381,   382,   385,   386,
     389,   392,   395,   396,   399,   402,   403,   404,   405,   408,
     409
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
  "STRCUT", "STRCMP", "STRJOIN", "MATXOP", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'<'", "'>'", "'.'", "'='", "'['", "']'", "':'", "$accept",
  "program_unit", "models", "model", "class", "id", "class_items",
  "class_item", "struct", "struct_items", "function", "function_head",
  "fdtype", "param_list", "dtype", "function_body", "statements",
  "statement", "vect_stmt", "vect_stmt_body", "remove_body", "vect_append",
  "return_stmt", "loop_stmt", "loop_type", "for_loop", "for_expr",
  "while_loop", "expr_stmt", "LHS", "declr_stmt", "declr_body",
  "graph_and_array_list", "matrix_list", "id_list", "ifcond_stmt", "$@1",
  "if_body", "switch_stmt", "$@2", "switch_body", "cases", "RHS",
  "class_struct_items", "constants", "extra_consts", "array_const",
  "val_list", "resultant", "impr", "graph_impr", "matrix_impr",
  "matr_body", "graph_const", "graph_type1", "graph_type2", "int_list",
  "float_list", "char_list", "bool_list", "str_list", "weight_list",
  "vect_const", "vect_list", "matrix_const", "int_float_list", "mat_list",
  "arith_op", "binary_op", "unary_op", "logical_op", "call_stmt",
  "func_calls", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-310)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-144)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,   383,   383,   793,    46,  -310,    47,  -310,  -310,  -310,
      43,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,    53,    62,  -310,  -310,  -310,
    -310,    57,  -310,   383,  -310,  -310,  -310,   776,  -310,    24,
      86,   841,    65,   412,    68,    70,    76,    77,    79,   383,
     383,    39,    80,    81,    82,  -310,   122,   170,    85,   170,
    -310,    88,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
      73,  -310,  -310,  -310,    89,    91,    24,  -310,  -310,    96,
      86,    92,   672,  -310,  -310,  -310,  -310,  -310,    84,    95,
      97,    99,   518,   697,    78,     4,   100,   101,   102,  -310,
     103,  -310,   104,   106,   105,   107,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,   697,  -310,  -310,   697,   383,   383,
     383,    98,   383,   383,   114,   108,     5,   115,   116,  -310,
    -310,  -310,   697,   697,   697,   383,  -310,  -310,  -310,  -310,
     241,  -310,   120,  -310,   121,  -310,  -310,  -310,   123,   383,
     697,   697,   697,  -310,   113,  -310,  -310,   124,   125,   127,
     132,   135,  -310,   152,   133,   138,   139,   141,   146,    74,
    -310,   126,  -310,  -310,  -310,  -310,  -310,   144,  -310,  -310,
    -310,   268,  -310,  -310,   168,   172,   -29,  -310,  -310,   173,
    -310,   174,  -310,   841,   383,   383,  -310,   465,   383,   569,
     199,   697,   175,   177,  -310,   182,   180,  -310,   188,   191,
     192,   193,   202,   203,   206,   207,   208,   210,  -310,  -310,
    -310,   197,   212,   211,   215,    15,   543,   543,  -310,  -310,
    -310,   697,   269,   271,   284,   270,   283,   235,   238,   233,
    -310,  -310,   242,  -310,  -310,   383,   294,   296,   243,   244,
    -310,  -310,   249,   250,   264,   265,   266,   267,  -310,   272,
     274,   -11,   275,   697,   697,   697,   465,   727,   277,   278,
     279,   727,   281,   285,   287,   727,   841,   697,  -310,  -310,
     319,   286,   290,  -310,  -310,   292,  -310,  -310,  -310,  -310,
    -310,    74,    74,   295,   727,   273,   276,  -310,   261,   263,
     383,  -310,  -310,  -310,  -310,  -310,   623,   697,  -310,   304,
     298,   303,   305,   307,   308,  -310,  -310,  -310,  -310,   309,
     306,   106,  -310,  -310,  -310,  -310,  -310,  -310,   311,  -310,
    -310,  -310,   289,  -310,   312,   313,   365,   367,  -310,  -310,
    -310,   314,   317,   170,  -310,   352,  -310,   320,   316,  -310,
    -310,   324,  -310,     0,   170,  -310,  -310,  -310,  -310,  -310,
    -310,   727,  -310,    83,   323,  -310,   327,  -310,  -310,  -310,
     328,   388,   370,   383,   391,  -310,   383,   340,  -310,   348,
     346,   351,   354,   269,   353,   396,   371,   372,  -310,   374,
     373,   386,  -310,  -310,   385,   389,   393,   397,   413,   409,
      26,   170,   353,   353,   170,   170,   170,   383,  -310,   390,
    -310,  -310,   395,   422,   423,  -310,  -310,  -310,   352,   424,
    -310,  -310
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     0,     0,    37,    34,    38,
      39,     0,    41,     0,    33,     1,     3,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    21,     0,    43,    90,    47,     0,    45,
      55,   142,    54,    53,    48,   140,    50,    51,    52,    91,
       0,   143,   141,    49,     0,     0,    24,    26,    25,     0,
      29,     0,     0,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,   127,   142,     0,   116,   115,
       0,   128,     0,   120,     0,   141,   129,   130,   131,   117,
     188,   189,   118,   119,     0,    57,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,     0,     0,     0,     0,    46,    42,    44,    58,
       0,   194,     0,    23,     0,    28,    40,    31,     0,     0,
       0,     0,     0,    77,   122,   132,   127,   178,   180,     0,
       0,     0,   142,     0,   163,   165,   167,   171,   169,     0,
     134,     0,   135,   136,   137,   138,   139,     0,    76,    72,
      73,     0,    74,    75,     0,     0,   105,    97,    93,     0,
      96,     0,    94,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,   154,   155,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    27,
      32,    36,     0,     0,     0,     0,     0,     0,   156,   157,
     176,     0,     0,     0,     0,     0,     0,   184,   185,     0,
     133,   181,     0,   106,   110,     0,     0,     0,     0,   105,
      99,    98,   142,     0,     0,     0,   141,     0,   196,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   191,
       0,     0,     0,   177,   179,     0,   162,   164,   166,   170,
     168,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       0,    89,    85,    86,    87,    88,     0,     0,   195,     0,
       0,     0,     0,     0,     0,    70,    71,    63,    64,     0,
      65,    69,    67,    68,    66,   144,    61,    62,     0,   153,
     146,   147,     0,    35,     0,     0,   159,   161,   192,   182,
     183,   187,     0,     0,   107,     0,   111,   101,     0,    95,
     198,     0,   199,     0,     0,   148,   150,   152,    59,    60,
     145,     0,   190,     0,     0,   158,     0,   160,   186,   151,
       0,     0,     0,     0,     0,   197,     0,     0,    82,     0,
       0,     0,     0,     0,     0,   109,     0,     0,   100,     0,
       0,     0,    84,   149,   173,   175,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
     172,   174,     0,     0,     0,   102,    81,   108,   114,     0,
     113,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -310,  -310,   472,  -310,  -310,    -1,   403,  -310,  -310,   400,
     -17,  -310,  -310,   205,     6,   473,   -49,  -310,  -310,     8,
    -255,  -310,  -310,  -310,  -310,  -310,  -310,  -310,   282,   -44,
     -14,  -310,  -117,    93,  -171,  -310,  -310,  -310,  -310,  -310,
    -310,    66,   -25,   -22,   -80,   -37,  -310,  -310,   -39,   -16,
     288,   -32,   221,  -310,   151,   153,   -87,   255,   257,   253,
     260,  -309,  -310,  -126,  -310,  -181,   155,  -233,  -310,   145,
    -198,  -310,    -7,  -194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    95,    75,    76,     8,    79,
       9,    10,    33,   148,   149,    57,    58,    59,    60,   162,
     319,   314,    62,    63,   129,   130,   377,   131,    64,    65,
      66,   124,   187,   190,   188,    67,   295,   344,    68,   296,
     346,   372,   259,    98,    99,   158,   101,   171,    70,   103,
     104,    72,   206,   106,   159,   160,   281,   173,   174,   175,
     176,   282,   107,   161,   108,   239,   177,   109,   110,   111,
     112,    73,   113,   260
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    26,    32,   192,   102,   125,   100,   172,   136,    34,
     138,   105,   157,   135,   198,    69,   328,    89,    97,   164,
     332,    71,    77,   250,   251,    78,    80,    69,   245,    90,
      74,   376,    42,   246,   322,    69,    56,    69,   322,   342,
      32,    71,   322,    71,    93,    61,    35,    81,    56,   126,
      74,    96,    74,    88,    48,    90,    56,     3,    56,    77,
     199,   322,    78,   309,   -90,    61,    80,    61,   163,   323,
     280,     1,     2,   323,   297,   127,   128,   323,   237,   238,
       3,    32,   164,   165,   166,   167,   168,   381,   382,   184,
     118,   156,   185,   410,   411,    37,   323,   119,   120,   121,
     283,   284,   205,   122,   123,    39,   380,   202,   203,   204,
     339,   340,   351,   352,    40,    41,    48,   186,   189,   191,
      82,   194,   195,   114,   115,   222,   223,   224,   322,   349,
     116,   135,   117,   140,   207,   132,   133,   134,   137,   150,
     169,   170,   139,   141,   142,   286,   157,   157,   221,   144,
     151,   146,   152,   153,   178,   179,   193,   180,   102,   182,
     254,   183,   -91,   323,   181,   256,  -143,   408,   196,   197,
     200,   201,   253,    11,   218,   219,   262,   225,   231,   220,
     228,   226,   227,    43,    44,   229,    45,    46,   230,   240,
     232,    47,    32,   249,   249,   233,   234,   257,   235,   248,
      48,    49,    50,   236,    51,   252,   285,   241,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    52,
      53,    54,    37,   320,   243,   156,   156,   320,   244,   316,
      49,   320,   263,   205,   264,   247,   246,   265,   311,   312,
     204,   315,  -141,   266,   249,    69,   267,   268,   269,    69,
     320,   321,   334,    69,   276,   321,   388,   270,   271,   321,
     324,   272,   273,   274,   324,   275,    56,   278,   324,   277,
      56,   279,    69,   164,    56,    32,   165,   167,   321,   208,
     209,   210,   211,   212,   213,   214,   215,   324,   216,   217,
     166,   168,   291,    56,   370,   292,   293,   294,   298,   249,
     299,   245,   300,   301,   302,   379,   208,   209,   210,   211,
     212,   213,   214,   215,   242,   216,   217,   320,   303,   304,
     305,    69,   306,   335,   347,   343,   348,    71,   345,   307,
     308,   310,    69,   325,   326,   327,    74,   329,    71,    69,
     336,   330,    56,   331,   337,   321,   361,    74,   338,   341,
     354,    61,   409,    56,   324,   412,   413,   414,   353,   355,
      56,   356,    61,   357,   358,   359,  -140,   360,   362,   364,
     363,   366,   191,   369,   371,   390,   169,   373,   374,    69,
     375,   385,    69,    69,    69,    71,    11,   383,    71,    71,
      71,   384,   386,   387,    74,   389,   391,    74,    74,    74,
      56,   392,   393,    56,    56,    56,   189,   394,   280,    61,
     395,   396,    61,    61,    61,    11,    83,    84,    85,    86,
      87,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   400,   397,   398,   399,   401,    88,
      89,    90,   402,   416,    50,   404,   403,    91,   417,   405,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    52,    53,    54,    92,   406,   407,    93,    11,    83,
      84,    85,    86,    87,    94,   418,   419,   421,    36,   143,
     145,   333,   261,    38,   420,   255,   313,   365,   287,   290,
     367,   288,    88,    89,    90,   289,   368,    50,   378,     0,
     415,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    52,    53,    54,    92,     0,     0,
      93,    11,   154,    84,    85,    86,    87,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      92,   155,    11,    83,    84,    85,    86,    87,     0,     0,
      94,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    92,    88,    89,    90,     0,
       0,    50,     0,     0,     0,    94,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    52,    53,
      54,     0,     0,     0,    93,   258,    11,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,     0,     0,    50,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    52,    53,    54,    11,     0,     0,    93,   350,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
      11,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    88,    89,    90,     0,   147,    50,
      11,   317,   318,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    52,    53,    54,     0,
       0,     0,    93,     0,    88,    89,    90,     0,     0,    50,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    52,    53,    54,    11,
       0,     0,    93,     0,     0,     0,     0,     0,     0,    43,
      44,     0,    45,    46,     0,     0,    11,    47,     0,     0,
       0,     0,     0,     0,    27,    28,    48,    49,    50,     0,
      51,    29,    30,    31,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    52,    53,    54,    37,    55,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    11,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   120,    43,    49,    43,    94,    57,     3,
      59,    43,    92,     9,     9,    37,   271,    28,    43,     4,
     275,    37,    39,   194,   195,    39,    40,    49,    57,    29,
      37,    31,    33,    62,   267,    57,    37,    59,   271,   294,
      41,    57,   275,    59,    55,    37,     0,    41,    49,    50,
      57,    43,    59,    27,    30,    29,    57,    33,    59,    76,
      55,   294,    76,   261,    60,    57,    80,    59,    93,   267,
      55,    24,    25,   271,   245,    36,    37,   275,     4,     5,
      33,    82,     4,     5,     6,     7,     8,     4,     5,   114,
      11,    92,   117,   402,   403,    52,   294,    18,    19,    20,
     226,   227,   134,    24,    25,    52,   361,   132,   133,   134,
     291,   292,   306,   307,    52,    58,    30,   118,   119,   120,
      55,   122,   123,    55,    54,   150,   151,   152,   361,   300,
      54,     9,    55,    60,   135,    55,    55,    55,    53,    55,
      62,    63,    54,    54,    53,   232,   226,   227,   149,    53,
      55,    59,    55,    54,    54,    54,    58,    54,   197,    54,
     197,    54,    60,   361,    60,   197,    60,   400,    54,    61,
      55,    55,   197,     3,    54,    54,   201,    64,    26,    56,
      53,    57,    57,    13,    14,    53,    16,    17,    53,    63,
      57,    21,   193,   194,   195,    57,    57,   198,    57,   193,
      30,    31,    32,    57,    34,   197,   231,    63,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   267,    56,   226,   227,   271,    56,   266,
      31,   275,    57,   265,    57,    62,    62,    57,   263,   264,
     265,   266,    60,    55,   245,   267,    55,    55,    55,   271,
     294,   267,   277,   275,    57,   271,   373,    55,    55,   275,
     267,    55,    55,    55,   271,    55,   267,    56,   275,    57,
     271,    56,   294,     4,   275,   276,     5,     7,   294,    38,
      39,    40,    41,    42,    43,    44,    45,   294,    47,    48,
       6,     8,    57,   294,   343,    57,    63,    55,     4,   300,
       4,    57,    59,    54,    54,   354,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   361,    54,    54,
      54,   343,    55,     4,    63,    52,    63,   343,    52,    57,
      56,    56,   354,    56,    56,    56,   343,    56,   354,   361,
      54,    56,   343,    56,    54,   361,    57,   354,    56,    54,
      52,   343,   401,   354,   361,   404,   405,   406,    54,    56,
     361,    56,   354,    56,    56,    56,    60,    56,    56,     4,
      57,     4,   373,    56,    22,   376,    62,    57,    62,   401,
      56,    53,   404,   405,   406,   401,     3,    64,   404,   405,
     406,    64,     4,    23,   401,     4,    56,   404,   405,   406,
     401,    53,    56,   404,   405,   406,   407,    56,    55,   401,
      56,    15,   404,   405,   406,     3,     4,     5,     6,     7,
       8,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    61,    64,    64,    63,    52,    27,
      28,    29,    57,    53,    32,    52,    57,    35,    53,    52,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    52,    57,    55,     3,     4,
       5,     6,     7,     8,    62,    53,    53,    53,     6,    76,
      80,   276,   200,    10,   418,   197,   265,   336,   233,   236,
     337,   234,    27,    28,    29,   235,   341,    32,   353,    -1,
     407,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,     3,     4,     5,     6,     7,     8,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,     3,     4,     5,     6,     7,     8,    -1,    -1,
      62,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    62,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    55,    56,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     3,    -1,    -1,    55,    56,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    27,    28,    29,    -1,    56,    32,
       3,     4,     5,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    55,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     3,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    16,    17,    -1,    -1,     3,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    30,    31,    32,    -1,
      34,    18,    19,    20,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    66,    67,    68,    69,    73,    75,
      76,     3,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    70,    70,    11,    12,    18,
      19,    20,    70,    77,    79,     0,    67,    52,    80,    52,
      52,    58,    70,    13,    14,    16,    17,    21,    30,    31,
      32,    34,    49,    50,    51,    53,    70,    80,    81,    82,
      83,    84,    87,    88,    93,    94,    95,   100,   103,   108,
     113,   114,   116,   136,   137,    71,    72,    75,    95,    74,
      95,    79,    55,     4,     5,     6,     7,     8,    27,    28,
      29,    35,    52,    55,    62,    70,    84,   107,   108,   109,
     110,   111,   113,   114,   115,   116,   118,   127,   129,   132,
     133,   134,   135,   137,    55,    54,    54,    55,    11,    18,
      19,    20,    24,    25,    96,    94,    70,    36,    37,    89,
      90,    92,    55,    55,    55,     9,    81,    53,    81,    54,
      60,    54,    53,    71,    53,    74,    59,    56,    78,    79,
      55,    55,    55,    54,     4,    53,    70,   109,   110,   119,
     120,   128,    84,   107,     4,     5,     6,     7,     8,    62,
      63,   112,   121,   122,   123,   124,   125,   131,    54,    54,
      54,    60,    54,    54,   107,   107,    70,    97,    99,    70,
      98,    70,    97,    58,    70,    70,    54,    61,     9,    55,
      55,    55,   107,   107,   107,   116,   117,    70,    38,    39,
      40,    41,    42,    43,    44,    45,    47,    48,    54,    54,
      56,    70,   107,   107,   107,    64,    57,    57,    53,    53,
      53,    26,    57,    57,    57,    57,    57,     4,     5,   130,
      63,    63,    46,    56,    56,    57,    62,    62,    79,    70,
      99,    99,    84,   107,   110,   115,   116,    70,    56,   107,
     138,    93,   107,    57,    57,    57,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    57,    57,    56,    56,
      55,   121,   126,   128,   128,   107,   121,   122,   123,   125,
     124,    57,    57,    63,    55,   101,   104,    99,     4,     4,
      59,    54,    54,    54,    54,    54,    55,    57,    56,   135,
      56,   107,   107,   117,    86,   107,   110,     4,     5,    85,
      94,   114,   132,   135,   137,    56,    56,    56,    85,    56,
      56,    56,    85,    78,   107,     4,    54,    54,    56,   130,
     130,    54,    85,    52,   102,    52,   105,    63,    63,    99,
      56,   138,   138,    54,    52,    56,    56,    56,    56,    56,
      56,    57,    56,    57,     4,   119,     4,   120,   131,    56,
      81,    22,   106,    57,    62,    56,    31,    91,   134,    81,
      85,     4,     5,    64,    64,    53,     4,    23,    97,     4,
      70,    56,    53,    56,    56,    56,    15,    64,    64,    63,
      61,    52,    57,    57,    52,    52,    52,    57,   132,    81,
     126,   126,    81,    81,    81,    98,    53,    53,    53,    53,
     106,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    87,    88,    89,
      89,    90,    91,    91,    92,    93,    93,    93,    93,    93,
      94,    94,    95,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   101,   100,   102,   102,
     104,   103,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   126,   127,   128,   128,   128,
     128,   129,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   134,   135,   135,   136,   137,   137,   137,   137,   138,
     138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     6,     2,     1,
       2,     5,     6,     1,     1,     4,     2,     1,     1,     1,
       4,     1,     3,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     6,
       6,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       1,    10,     1,     4,     7,     5,     5,     5,     5,     5,
       1,     1,     3,     2,     2,     5,     2,     2,     3,     3,
       6,     4,     9,     7,     3,     1,     0,     6,     7,     3,
       0,     6,     8,     7,     6,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     6,     5,     5,     6,     8,
       6,     6,     6,     5,     1,     1,     3,     3,     5,     4,
       5,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     7,     5,     7,     5,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     1,     5,     4,     1,     1,
       6,     4,     5,     4,     2,     5,     4,     7,     6,     3,
       1
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
#line 77 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1740 "y.tab.c"
    break;

  case 27: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 104 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1746 "y.tab.c"
    break;

  case 31: /* function_head: FUNC fdtype id '(' ')'  */
#line 114 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1752 "y.tab.c"
    break;

  case 32: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 115 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1758 "y.tab.c"
    break;

  case 56: /* statement: BREAK ';'  */
#line 151 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 1764 "y.tab.c"
    break;

  case 57: /* statement: CONTINUE ';'  */
#line 152 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 1770 "y.tab.c"
    break;

  case 58: /* vect_stmt: vect_stmt_body ';'  */
#line 155 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 1776 "y.tab.c"
    break;

  case 72: /* return_stmt: RETURN RHS ';'  */
#line 179 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1782 "y.tab.c"
    break;

  case 73: /* return_stmt: RETURN extra_consts ';'  */
#line 180 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 1788 "y.tab.c"
    break;

  case 74: /* return_stmt: RETURN graph_impr ';'  */
#line 181 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 1794 "y.tab.c"
    break;

  case 75: /* return_stmt: RETURN matrix_impr ';'  */
#line 182 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 1800 "y.tab.c"
    break;

  case 76: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 183 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 1806 "y.tab.c"
    break;

  case 77: /* return_stmt: RETURN null ';'  */
#line 184 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 1812 "y.tab.c"
    break;

  case 78: /* loop_stmt: LOOP loop_type  */
#line 188 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1818 "y.tab.c"
    break;

  case 85: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 205 "parser.y"
                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1824 "y.tab.c"
    break;

  case 86: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 206 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1830 "y.tab.c"
    break;

  case 87: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 207 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1836 "y.tab.c"
    break;

  case 88: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 208 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1842 "y.tab.c"
    break;

  case 89: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 209 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1848 "y.tab.c"
    break;

  case 92: /* declr_stmt: DECLR declr_body ';'  */
#line 216 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1854 "y.tab.c"
    break;

  case 106: /* $@1: %empty  */
#line 239 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1860 "y.tab.c"
    break;

  case 110: /* $@2: %empty  */
#line 246 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1866 "y.tab.c"
    break;

  case 194: /* call_stmt: func_calls ';'  */
#line 399 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1872 "y.tab.c"
    break;


#line 1876 "y.tab.c"

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

#line 412 "parser.y"


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




