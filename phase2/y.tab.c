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
    STRCMP = 303,                  /* STRCMP  */
    STRJOIN = 304,                 /* STRJOIN  */
    MATXOP = 305                   /* MATXOP  */
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
#define STRCMP 303
#define STRJOIN 304
#define MATXOP 305

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
  YYSYMBOL_PUNC = 9,                       /* PUNC  */
  YYSYMBOL_DATATYPE = 10,                  /* DATATYPE  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_MATRIX = 17,                    /* MATRIX  */
  YYSYMBOL_GRAPH = 18,                     /* GRAPH  */
  YYSYMBOL_VECT = 19,                      /* VECT  */
  YYSYMBOL_SWITCH = 20,                    /* SWITCH  */
  YYSYMBOL_CASE = 21,                      /* CASE  */
  YYSYMBOL_DEFAULT = 22,                   /* DEFAULT  */
  YYSYMBOL_CLASS = 23,                     /* CLASS  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_LOGOP = 25,                     /* LOGOP  */
  YYSYMBOL_ARITHOP = 26,                   /* ARITHOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_UNARYOP = 28,                   /* UNARYOP  */
  YYSYMBOL_DECLR = 29,                     /* DECLR  */
  YYSYMBOL_EXPR = 30,                      /* EXPR  */
  YYSYMBOL_CALL = 31,                      /* CALL  */
  YYSYMBOL_FUNC = 32,                      /* FUNC  */
  YYSYMBOL_LOOP = 33,                      /* LOOP  */
  YYSYMBOL_null = 34,                      /* null  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_APPEND = 37,                    /* APPEND  */
  YYSYMBOL_REMOVE = 38,                    /* REMOVE  */
  YYSYMBOL_LENGTH = 39,                    /* LENGTH  */
  YYSYMBOL_SORT = 40,                      /* SORT  */
  YYSYMBOL_CLEAR = 41,                     /* CLEAR  */
  YYSYMBOL_AT = 42,                        /* AT  */
  YYSYMBOL_TRANSPOSE = 43,                 /* TRANSPOSE  */
  YYSYMBOL_TRACE = 44,                     /* TRACE  */
  YYSYMBOL_TRAVERSAL = 45,                 /* TRAVERSAL  */
  YYSYMBOL_STRLEN = 46,                    /* STRLEN  */
  YYSYMBOL_STRCUT = 47,                    /* STRCUT  */
  YYSYMBOL_STRCMP = 48,                    /* STRCMP  */
  YYSYMBOL_STRJOIN = 49,                   /* STRJOIN  */
  YYSYMBOL_MATXOP = 50,                    /* MATXOP  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '<'  */
  YYSYMBOL_58_ = 58,                       /* '>'  */
  YYSYMBOL_59_ = 59,                       /* '.'  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_61_ = 61,                       /* '['  */
  YYSYMBOL_62_ = 62,                       /* ']'  */
  YYSYMBOL_63_ = 63,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program_unit = 65,              /* program_unit  */
  YYSYMBOL_models = 66,                    /* models  */
  YYSYMBOL_model = 67,                     /* model  */
  YYSYMBOL_class = 68,                     /* class  */
  YYSYMBOL_id = 69,                        /* id  */
  YYSYMBOL_class_items = 70,               /* class_items  */
  YYSYMBOL_class_item = 71,                /* class_item  */
  YYSYMBOL_struct = 72,                    /* struct  */
  YYSYMBOL_struct_items = 73,              /* struct_items  */
  YYSYMBOL_function = 74,                  /* function  */
  YYSYMBOL_function_head = 75,             /* function_head  */
  YYSYMBOL_fdtype = 76,                    /* fdtype  */
  YYSYMBOL_param_list = 77,                /* param_list  */
  YYSYMBOL_dtype = 78,                     /* dtype  */
  YYSYMBOL_function_body = 79,             /* function_body  */
  YYSYMBOL_statements = 80,                /* statements  */
  YYSYMBOL_statement = 81,                 /* statement  */
  YYSYMBOL_vect_stmt = 82,                 /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 83,            /* vect_stmt_body  */
  YYSYMBOL_vect_res = 84,                  /* vect_res  */
  YYSYMBOL_remove_body = 85,               /* remove_body  */
  YYSYMBOL_vect_append = 86,               /* vect_append  */
  YYSYMBOL_return_stmt = 87,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 88,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 89,                 /* loop_type  */
  YYSYMBOL_for_loop = 90,                  /* for_loop  */
  YYSYMBOL_for_expr = 91,                  /* for_expr  */
  YYSYMBOL_while_loop = 92,                /* while_loop  */
  YYSYMBOL_expr_stmt = 93,                 /* expr_stmt  */
  YYSYMBOL_declr_stmt = 94,                /* declr_stmt  */
  YYSYMBOL_declr_body = 95,                /* declr_body  */
  YYSYMBOL_graph_and_array_list = 96,      /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 97,               /* matrix_list  */
  YYSYMBOL_id_list = 98,                   /* id_list  */
  YYSYMBOL_ifcond_stmt = 99,               /* ifcond_stmt  */
  YYSYMBOL_100_1 = 100,                    /* $@1  */
  YYSYMBOL_if_body = 101,                  /* if_body  */
  YYSYMBOL_switch_stmt = 102,              /* switch_stmt  */
  YYSYMBOL_103_2 = 103,                    /* $@2  */
  YYSYMBOL_switch_body = 104,              /* switch_body  */
  YYSYMBOL_cases = 105,                    /* cases  */
  YYSYMBOL_RHS = 106,                      /* RHS  */
  YYSYMBOL_constants = 107,                /* constants  */
  YYSYMBOL_extra_consts = 108,             /* extra_consts  */
  YYSYMBOL_array_const = 109,              /* array_const  */
  YYSYMBOL_val_list = 110,                 /* val_list  */
  YYSYMBOL_resultant = 111,                /* resultant  */
  YYSYMBOL_impr = 112,                     /* impr  */
  YYSYMBOL_graph_impr = 113,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 114,              /* matrix_impr  */
  YYSYMBOL_matr_body = 115,                /* matr_body  */
  YYSYMBOL_graph_const = 116,              /* graph_const  */
  YYSYMBOL_graph_type1 = 117,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 118,              /* graph_type2  */
  YYSYMBOL_int_list = 119,                 /* int_list  */
  YYSYMBOL_float_list = 120,               /* float_list  */
  YYSYMBOL_char_list = 121,                /* char_list  */
  YYSYMBOL_bool_list = 122,                /* bool_list  */
  YYSYMBOL_str_list = 123,                 /* str_list  */
  YYSYMBOL_weight_list = 124,              /* weight_list  */
  YYSYMBOL_vect_const = 125,               /* vect_const  */
  YYSYMBOL_vect_list = 126,                /* vect_list  */
  YYSYMBOL_matrix_const = 127,             /* matrix_const  */
  YYSYMBOL_mat_list = 128,                 /* mat_list  */
  YYSYMBOL_arith_op = 129,                 /* arith_op  */
  YYSYMBOL_binary_op = 130,                /* binary_op  */
  YYSYMBOL_unary_op = 131,                 /* unary_op  */
  YYSYMBOL_logical_op = 132,               /* logical_op  */
  YYSYMBOL_call_stmt = 133,                /* call_stmt  */
  YYSYMBOL_func_calls = 134,               /* func_calls  */
  YYSYMBOL_arg_list = 135                  /* arg_list  */
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
#define YYLAST   794

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      54,    55,     2,     2,    56,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    53,
      57,    60,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    73,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    95,    96,    99,   100,   103,   106,   107,
     110,   113,   114,   117,   118,   121,   122,   125,   126,   127,
     128,   129,   132,   133,   136,   137,   138,   139,   142,   143,
     144,   145,   146,   147,   148,   149,   152,   155,   156,   157,
     158,   162,   163,   167,   168,   169,   170,   171,   172,   173,
     177,   178,   181,   182,   183,   184,   188,   191,   192,   195,
     198,   199,   202,   205,   206,   207,   208,   211,   213,   214,
     215,   216,   217,   218,   219,   222,   223,   226,   227,   230,
     231,   234,   234,   237,   238,   241,   241,   244,   247,   248,
     252,   253,   254,   255,   256,   259,   260,   261,   262,   263,
     264,   268,   269,   270,   271,   272,   276,   277,   280,   281,
     282,   283,   284,   287,   288,   289,   292,   293,   294,   295,
     296,   297,   298,   303,   307,   308,   311,   312,   315,   316,
     319,   320,   323,   324,   327,   328,   331,   332,   335,   336,
     339,   340,   343,   344,   347,   348,   351,   354,   355,   356,
     357,   360,   363,   364,   365,   366,   369,   370,   373,   376,
     379,   382,   385,   386,   387,   388,   391,   392
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
  "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "BOOL_CONST", "PUNC",
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
  "statement", "vect_stmt", "vect_stmt_body", "vect_res", "remove_body",
  "vect_append", "return_stmt", "loop_stmt", "loop_type", "for_loop",
  "for_expr", "while_loop", "expr_stmt", "declr_stmt", "declr_body",
  "graph_and_array_list", "matrix_list", "id_list", "ifcond_stmt", "$@1",
  "if_body", "switch_stmt", "$@2", "switch_body", "cases", "RHS",
  "constants", "extra_consts", "array_const", "val_list", "resultant",
  "impr", "graph_impr", "matrix_impr", "matr_body", "graph_const",
  "graph_type1", "graph_type2", "int_list", "float_list", "char_list",
  "bool_list", "str_list", "weight_list", "vect_const", "vect_list",
  "matrix_const", "mat_list", "arith_op", "binary_op", "unary_op",
  "logical_op", "call_stmt", "func_calls", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-238)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   153,   153,   732,    21,  -238,    -5,  -238,  -238,  -238,
     -17,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,   -13,    -8,  -238,  -238,  -238,
    -238,     3,  -238,   153,  -238,  -238,  -238,   638,  -238,    29,
      20,   745,    10,   357,    22,    25,    71,   153,   153,    56,
    -238,  -238,   685,    35,   685,  -238,    50,    49,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,    68,    75,    29,  -238,  -238,
      77,    20,    73,   536,  -238,  -238,  -238,  -238,  -238,    82,
      89,    91,    92,    95,   213,   561,    62,    93,    97,  -238,
      98,  -238,    96,    99,   100,   101,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,   561,   561,   153,   153,   153,   102,
     153,   153,   104,    88,   -30,   106,   107,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,    37,  -238,   109,  -238,   111,  -238,
    -238,  -238,   110,   153,   561,   561,   561,   561,   561,   103,
    -238,  -238,   112,   113,   118,   119,   120,   114,   149,  -238,
     121,   125,   127,   129,   131,   108,  -238,   126,  -238,  -238,
    -238,  -238,  -238,   143,   130,  -238,  -238,    54,  -238,  -238,
     151,   152,   -26,  -238,  -238,   115,  -238,   147,  -238,   745,
     153,   153,  -238,   357,   435,   153,   180,   561,   157,   158,
     159,   168,  -238,  -238,  -238,   167,   170,   169,   172,   173,
    -238,   176,   175,     8,   409,   409,  -238,  -238,  -238,   561,
     233,   234,   235,   236,   232,   182,   184,  -238,  -238,   195,
     209,   212,   214,   216,   217,   218,  -238,  -238,   153,   272,
     273,   220,   224,  -238,  -238,   228,   229,   230,   231,  -238,
     237,   239,   238,   241,   242,   357,   590,   243,   244,   745,
     561,  -238,   561,   561,   561,   281,   248,   249,  -238,  -238,
     250,  -238,  -238,  -238,  -238,  -238,   251,   253,   590,   252,
     590,   254,   255,   256,   590,   240,   245,  -238,   225,   226,
     153,  -238,  -238,  -238,  -238,   561,  -238,   488,   259,   257,
     258,  -238,  -238,  -238,  -238,   114,   260,    99,  -238,  -238,
    -238,  -238,  -238,  -238,   262,   263,   264,   266,   247,   286,
     310,  -238,   261,   261,   268,  -238,   269,  -238,  -238,  -238,
     270,   685,  -238,   304,  -238,   271,   267,  -238,  -238,  -238,
     274,    74,   685,  -238,  -238,  -238,  -238,  -238,  -238,   326,
     275,  -238,   276,  -238,  -238,  -238,  -238,  -238,   590,   285,
     329,   318,   153,   337,  -238,   153,   287,  -238,   291,   289,
     233,   298,   290,   339,   292,   293,  -238,   295,   299,   307,
    -238,   311,  -238,   315,   317,   319,   313,    94,   685,   298,
     685,   685,   685,   153,  -238,   320,  -238,   321,   322,   323,
    -238,  -238,  -238,   304,   324,  -238,  -238
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
      43,    61,    47,     0,    45,    55,    62,     0,    54,    53,
      48,    50,    51,    52,    49,     0,     0,    24,    26,    25,
       0,    29,     0,     0,   115,   116,   117,   118,   119,     0,
       0,    22,    21,     0,     0,     0,     0,   120,     0,   110,
       0,   121,     0,   114,     0,   134,   122,   123,   124,   111,
     176,   177,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      46,    42,    44,    56,     0,   181,     0,    23,     0,    28,
      40,    31,     0,     0,     0,     0,     0,     0,     0,   115,
     125,   120,   168,   170,     0,     0,     0,   120,     0,   134,
     155,   157,   159,   163,   161,     0,   127,     0,   128,   129,
     130,   131,   132,     0,     0,    72,    73,     0,    74,    75,
       0,     0,   100,    92,    88,     0,    91,     0,    89,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,    27,    32,    36,     0,     0,     0,     0,
     146,   147,     0,     0,     0,     0,   148,   149,   166,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   171,     0,
       0,     0,     0,     0,     0,     0,   101,   105,     0,     0,
       0,     0,   100,    94,    93,     0,     0,     0,   134,   183,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,   167,   169,
       0,   154,   156,   158,   162,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,    83,    84,    85,    86,     0,   182,     0,     0,     0,
       0,    70,    71,    63,    64,    65,     0,    69,    67,    68,
      66,    59,    60,    35,     0,     0,     0,     0,     0,   151,
     153,   180,   173,   175,     0,   136,     0,   145,   138,   139,
       0,     0,   102,     0,   106,    96,     0,    90,   186,   185,
       0,     0,     0,    57,    58,   178,   140,   142,   144,     0,
       0,   150,     0,   152,   172,   174,   143,   137,     0,     0,
       0,     0,     0,     0,   184,     0,     0,    80,     0,     0,
       0,     0,     0,   104,     0,     0,    95,     0,     0,     0,
      82,   165,   141,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,    81,     0,   164,     0,     0,     0,
      97,    79,   103,   109,     0,   108,   107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -238,  -238,   365,  -238,  -238,    -1,   325,  -238,  -238,   316,
     -23,  -238,  -238,   135,     7,   368,   -46,  -238,  -238,  -238,
    -238,  -211,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   200,
      15,  -238,  -105,     6,  -155,  -238,  -238,  -238,  -238,  -238,
    -238,    -3,   -20,   -71,   -36,  -238,  -238,  -238,  -218,   208,
     -39,   139,  -238,   116,   117,   -75,  -140,   197,   196,   206,
      41,  -238,   -66,  -238,  -171,  -237,  -238,    90,  -229,  -238,
     -32,  -159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,   147,    66,    67,     8,    70,
       9,    10,    33,   132,   133,    52,    53,    54,    55,    56,
      57,   296,   290,    58,    59,   117,   118,   356,   119,    60,
      61,   112,   173,   176,   174,    62,   275,   322,    63,   276,
     324,   351,   240,    89,   143,    91,   157,    92,    93,    94,
     149,   202,    96,   144,   145,   256,   159,   160,   161,   162,
     257,    97,   146,    98,   163,    99,   100,   101,   102,    64,
     103,   241
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    26,    32,   178,    95,    65,   120,    90,   122,   298,
      34,   158,   150,   142,   288,   216,    68,   299,     1,     2,
      65,    35,    65,    88,   184,   233,   234,     3,   297,   185,
     228,   298,    42,   298,    37,   229,    51,   298,    39,   299,
      32,   299,    87,    40,    68,   299,   113,   114,    72,    46,
     297,    51,   297,    51,    69,    71,   297,   314,    46,   316,
      41,     3,   255,   320,    73,   148,   150,   151,   152,   153,
     154,   262,    32,   277,   188,   189,   104,   190,   191,   105,
     215,   106,    69,   141,   170,   171,    71,   121,   107,   108,
     109,   115,   116,   220,   110,   111,   221,   222,   223,   201,
     224,   225,    80,   123,   355,   172,   175,   177,   124,   180,
     181,   298,   150,   151,   196,   197,   198,   199,   200,   299,
      79,   125,    80,   155,   156,   327,   328,   126,   330,   128,
     297,   130,   195,   142,   142,   261,   134,   362,   258,   259,
     384,   344,   345,   135,   238,   136,   137,   236,   183,   138,
     165,   166,   164,   168,   169,   167,    11,   182,  -135,   179,
     186,   187,   192,   235,   193,   194,   203,   244,   204,   205,
     206,   207,   208,  -133,   209,   219,   230,   210,    32,   232,
     232,   211,    87,   212,   242,   213,   231,   214,   217,   260,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   141,   141,   218,   226,   227,   229,   292,
      47,   245,   246,   247,   300,   201,    11,   139,    75,    76,
      77,    78,   248,   249,   251,   291,   250,   232,   252,   253,
     304,   254,   305,   306,   200,  -134,   300,   150,   300,   151,
     154,   152,   300,   153,   266,   295,   267,   366,    32,   268,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   269,    84,   140,   270,   295,   271,   295,
     272,   273,   274,   295,    86,   349,   278,   279,   280,   232,
     228,   281,   282,   283,   284,   308,   358,   325,   326,    65,
     340,   321,   287,   285,   286,    85,   323,   289,   301,   302,
      65,   309,   310,   339,   312,   311,   313,   315,   332,   317,
     318,   319,   331,   333,   342,   334,   300,   335,   336,   337,
      51,   338,   155,   346,   347,   350,   348,   352,   353,   354,
     359,    51,   385,   364,   387,   388,   389,   363,   360,   361,
     365,   367,   369,   370,   371,   372,    65,   295,    65,    65,
      65,   177,   255,   373,   368,   374,   375,   376,   378,   377,
      11,    74,    75,    76,    77,    78,   380,   379,   381,   383,
     382,    36,   391,   392,   393,   394,   396,    51,    38,    51,
      51,    51,   175,    79,   303,    80,   243,   129,    48,   390,
     395,   237,   127,   307,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    81,    82,    83,    84,   263,
     265,    85,    11,    74,    75,    76,    77,    78,    86,   264,
     386,   357,     0,     0,     0,   341,     0,   343,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    74,
      75,    76,    77,    78,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      84,    79,     0,    80,     0,     0,    48,     0,     0,     0,
      86,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    81,    82,    83,     0,     0,     0,    85,
     239,    11,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,    80,     0,     0,    48,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    81,    82,    83,    11,
       0,     0,    85,   329,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    74,    75,    76,    77,    78,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    79,     0,    80,
       0,   131,    48,    11,   293,   294,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    81,
      82,    83,     0,     0,     0,    85,    79,     0,    80,     0,
       0,    48,     0,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    81,    82,
      83,    11,     0,     0,    85,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,    48,
       0,    49,     0,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    11,    37,
      50,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,    49,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    11,    37,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    11,    29,
      30,    31,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,    29,    30,    31,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   108,    43,    37,    52,    43,    54,   246,
       3,    86,     4,    84,   243,   155,    39,   246,    23,    24,
      52,     0,    54,    43,    54,   180,   181,    32,   246,    59,
      56,   268,    33,   270,    51,    61,    37,   274,    51,   268,
      41,   270,    43,    51,    67,   274,    47,    48,    41,    29,
     268,    52,   270,    54,    39,    40,   274,   268,    29,   270,
      57,    32,    54,   274,    54,    85,     4,     5,     6,     7,
       8,   211,    73,   228,    37,    38,    54,    40,    41,    54,
     155,    10,    67,    84,   104,   105,    71,    52,    17,    18,
      19,    35,    36,    39,    23,    24,    42,    43,    44,   138,
      46,    47,    28,    53,    30,   106,   107,   108,    59,   110,
     111,   348,     4,     5,   134,   135,   136,   137,   138,   348,
      26,    53,    28,    61,    62,   280,   285,    52,   287,    52,
     348,    58,   133,   204,   205,   210,    54,   348,   204,   205,
     377,   312,   313,    54,   183,    54,    54,   183,    60,    54,
      53,    53,    59,    53,    53,    59,     3,    53,    59,    57,
      54,    54,    53,   183,    53,    55,    63,   187,    56,    56,
      52,    52,    52,    59,    25,    45,    61,    56,   179,   180,
     181,    56,   183,    56,   185,    56,   179,    56,    62,   209,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   204,   205,    62,    55,    55,    61,   245,
      30,    54,    54,    54,   246,   254,     3,     4,     5,     6,
       7,     8,    54,    56,    55,   245,    56,   228,    56,    56,
     250,    56,   252,   253,   254,    59,   268,     4,   270,     5,
       8,     6,   274,     7,    62,   246,    62,   352,   249,    54,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    54,    51,    52,    54,   268,    54,   270,
      54,    54,    54,   274,    61,   321,     4,     4,    58,   280,
      56,    53,    53,    53,    53,     4,   332,    62,    62,   321,
       4,    51,    54,    56,    55,    54,    51,    55,    55,    55,
     332,    53,    53,    56,    53,    55,    53,    55,    51,    55,
      55,    55,    53,    55,     4,    55,   348,    55,    55,    55,
     321,    55,    61,    55,    55,    21,    56,    56,    61,    55,
       4,   332,   378,     4,   380,   381,   382,    52,    63,    63,
      22,     4,    55,    52,    55,    55,   378,   348,   380,   381,
     382,   352,    54,    14,   355,    63,    63,    62,    51,    60,
       3,     4,     5,     6,     7,     8,    51,    56,    51,    56,
      51,     6,    52,    52,    52,    52,    52,   378,    10,   380,
     381,   382,   383,    26,   249,    28,   186,    71,    31,   383,
     393,   183,    67,   254,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   212,
     214,    54,     3,     4,     5,     6,     7,     8,    61,   213,
     379,   331,    -1,    -1,    -1,   309,    -1,   310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    26,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,
      61,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      55,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     3,
      -1,    -1,    54,    55,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    26,    -1,    28,
      -1,    55,    31,     3,     4,     5,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    26,    -1,    28,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     3,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     3,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     3,    51,    -1,    -1,    -1,
      -1,    -1,    10,    11,    -1,    -1,    -1,    -1,     3,    17,
      18,    19,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    24,    32,    65,    66,    67,    68,    72,    74,
      75,     3,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    69,    69,    10,    11,    17,
      18,    19,    69,    76,    78,     0,    66,    51,    79,    51,
      51,    57,    69,    12,    13,    20,    29,    30,    31,    33,
      52,    69,    79,    80,    81,    82,    83,    84,    87,    88,
      93,    94,    99,   102,   133,   134,    70,    71,    74,    94,
      73,    94,    78,    54,     4,     5,     6,     7,     8,    26,
      28,    48,    49,    50,    51,    54,    61,    69,   106,   107,
     108,   109,   111,   112,   113,   114,   116,   125,   127,   129,
     130,   131,   132,   134,    54,    54,    10,    17,    18,    19,
      23,    24,    95,    69,    69,    35,    36,    89,    90,    92,
      80,    52,    80,    53,    59,    53,    52,    70,    52,    73,
      58,    55,    77,    78,    54,    54,    54,    54,    54,     4,
      52,    69,   107,   108,   117,   118,   126,    69,   106,   114,
       4,     5,     6,     7,     8,    61,    62,   110,   119,   120,
     121,   122,   123,   128,    59,    53,    53,    59,    53,    53,
     106,   106,    69,    96,    98,    69,    97,    69,    96,    57,
      69,    69,    53,    60,    54,    59,    54,    54,    37,    38,
      40,    41,    53,    53,    55,    69,   106,   106,   106,   106,
     106,   114,   115,    63,    56,    56,    52,    52,    52,    25,
      56,    56,    56,    56,    56,   119,   120,    62,    62,    45,
      39,    42,    43,    44,    46,    47,    55,    55,    56,    61,
      61,    78,    69,    98,    98,   106,   108,   113,   114,    55,
     106,   135,    69,    93,   106,    54,    54,    54,    54,    56,
      56,    55,    56,    56,    56,    54,   119,   124,   126,   126,
     106,   119,   120,   121,   123,   122,    62,    62,    54,    54,
      54,    54,    54,    54,    54,   100,   103,    98,     4,     4,
      58,    53,    53,    53,    53,    56,    55,    54,   132,    55,
      86,   106,   108,     4,     5,    69,    85,   112,   129,   132,
     134,    55,    55,    77,   106,   106,   106,   115,     4,    53,
      53,    55,    53,    53,    85,    55,    85,    55,    55,    55,
      85,    51,   101,    51,   104,    62,    62,    98,   135,    55,
     135,    53,    51,    55,    55,    55,    55,    55,    55,    56,
       4,   117,     4,   118,   128,   128,    55,    55,    56,    80,
      21,   105,    56,    61,    55,    30,    91,   131,    80,     4,
      63,    63,    85,    52,     4,    22,    96,     4,    69,    55,
      52,    55,    55,    14,    63,    63,    62,    60,    51,    56,
      51,    51,    51,    56,   129,    80,   124,    80,    80,    80,
      97,    52,    52,    52,    52,   105,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    89,    89,    90,
      91,    91,    92,    93,    93,    93,    93,    94,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,   100,    99,   101,   101,   103,   102,   104,   105,   105,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   126,   126,   126,
     126,   127,   128,   128,   128,   128,   129,   129,   130,   131,
     132,   133,   134,   134,   134,   134,   135,   135
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     6,     2,     1,
       2,     5,     6,     1,     1,     4,     2,     1,     1,     1,
       4,     1,     3,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     6,     6,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     1,    10,
       1,     4,     7,     5,     5,     5,     5,     3,     2,     2,
       5,     2,     2,     3,     3,     6,     4,     9,     7,     3,
       1,     0,     6,     7,     3,     0,     6,     8,     7,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     6,     5,     5,
       6,     8,     6,     6,     6,     5,     1,     1,     3,     3,
       5,     4,     5,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     7,     5,     3,     3,     1,     3,
       1,     3,     5,     4,     5,     4,     1,     1,     6,     4,
       5,     2,     5,     4,     7,     6,     3,     1
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
#line 76 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1699 "y.tab.c"
    break;

  case 27: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 103 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1705 "y.tab.c"
    break;

  case 31: /* function_head: FUNC fdtype id '(' ')'  */
#line 113 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1711 "y.tab.c"
    break;

  case 32: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 114 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1717 "y.tab.c"
    break;

  case 56: /* vect_stmt: vect_stmt_body ';'  */
#line 152 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 1723 "y.tab.c"
    break;

  case 72: /* return_stmt: RETURN RHS ';'  */
#line 181 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1729 "y.tab.c"
    break;

  case 73: /* return_stmt: RETURN extra_consts ';'  */
#line 182 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 1735 "y.tab.c"
    break;

  case 74: /* return_stmt: RETURN graph_impr ';'  */
#line 183 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 1741 "y.tab.c"
    break;

  case 75: /* return_stmt: RETURN matrix_impr ';'  */
#line 184 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 1747 "y.tab.c"
    break;

  case 76: /* loop_stmt: LOOP loop_type  */
#line 188 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1753 "y.tab.c"
    break;

  case 83: /* expr_stmt: EXPR id '=' RHS ';'  */
#line 205 "parser.y"
                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1759 "y.tab.c"
    break;

  case 84: /* expr_stmt: EXPR id '=' extra_consts ';'  */
#line 206 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1765 "y.tab.c"
    break;

  case 85: /* expr_stmt: EXPR id '=' graph_impr ';'  */
#line 207 "parser.y"
                                                                             {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1771 "y.tab.c"
    break;

  case 86: /* expr_stmt: EXPR id '=' matrix_impr ';'  */
#line 208 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1777 "y.tab.c"
    break;

  case 87: /* declr_stmt: DECLR declr_body ';'  */
#line 211 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1783 "y.tab.c"
    break;

  case 101: /* $@1: %empty  */
#line 234 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1789 "y.tab.c"
    break;

  case 105: /* $@2: %empty  */
#line 241 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1795 "y.tab.c"
    break;

  case 181: /* call_stmt: func_calls ';'  */
#line 382 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1801 "y.tab.c"
    break;


#line 1805 "y.tab.c"

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

#line 395 "parser.y"


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




