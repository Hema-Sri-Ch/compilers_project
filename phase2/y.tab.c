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
  YYSYMBOL_MATXOP = 48,                    /* MATXOP  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_56_ = 56,                       /* '>'  */
  YYSYMBOL_57_ = 57,                       /* '.'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_62_ = 62,                       /* '+'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program_unit = 64,              /* program_unit  */
  YYSYMBOL_models = 65,                    /* models  */
  YYSYMBOL_model = 66,                     /* model  */
  YYSYMBOL_class = 67,                     /* class  */
  YYSYMBOL_id = 68,                        /* id  */
  YYSYMBOL_class_items = 69,               /* class_items  */
  YYSYMBOL_class_item = 70,                /* class_item  */
  YYSYMBOL_struct = 71,                    /* struct  */
  YYSYMBOL_struct_items = 72,              /* struct_items  */
  YYSYMBOL_function = 73,                  /* function  */
  YYSYMBOL_function_head = 74,             /* function_head  */
  YYSYMBOL_fdtype = 75,                    /* fdtype  */
  YYSYMBOL_param_list = 76,                /* param_list  */
  YYSYMBOL_dtype = 77,                     /* dtype  */
  YYSYMBOL_function_body = 78,             /* function_body  */
  YYSYMBOL_statements = 79,                /* statements  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_vect_stmt = 81,                 /* vect_stmt  */
  YYSYMBOL_remove_body = 82,               /* remove_body  */
  YYSYMBOL_vect_append = 83,               /* vect_append  */
  YYSYMBOL_return_stmt = 84,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 85,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 86,                 /* loop_type  */
  YYSYMBOL_for_loop = 87,                  /* for_loop  */
  YYSYMBOL_for_expr = 88,                  /* for_expr  */
  YYSYMBOL_while_loop = 89,                /* while_loop  */
  YYSYMBOL_expr_stmt = 90,                 /* expr_stmt  */
  YYSYMBOL_declr_stmt = 91,                /* declr_stmt  */
  YYSYMBOL_declr_body = 92,                /* declr_body  */
  YYSYMBOL_graph_and_array_list = 93,      /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 94,               /* matrix_list  */
  YYSYMBOL_id_list = 95,                   /* id_list  */
  YYSYMBOL_ifcond_stmt = 96,               /* ifcond_stmt  */
  YYSYMBOL_97_1 = 97,                      /* $@1  */
  YYSYMBOL_if_body = 98,                   /* if_body  */
  YYSYMBOL_switch_stmt = 99,               /* switch_stmt  */
  YYSYMBOL_100_2 = 100,                    /* $@2  */
  YYSYMBOL_switch_body = 101,              /* switch_body  */
  YYSYMBOL_cases = 102,                    /* cases  */
  YYSYMBOL_RHS = 103,                      /* RHS  */
  YYSYMBOL_constants = 104,                /* constants  */
  YYSYMBOL_extra_consts = 105,             /* extra_consts  */
  YYSYMBOL_array_const = 106,              /* array_const  */
  YYSYMBOL_val_list = 107,                 /* val_list  */
  YYSYMBOL_string_impr = 108,              /* string_impr  */
  YYSYMBOL_vect_impr = 109,                /* vect_impr  */
  YYSYMBOL_graph_impr = 110,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 111,              /* matrix_impr  */
  YYSYMBOL_graph_const = 112,              /* graph_const  */
  YYSYMBOL_graph_type1 = 113,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 114,              /* graph_type2  */
  YYSYMBOL_int_list = 115,                 /* int_list  */
  YYSYMBOL_float_list = 116,               /* float_list  */
  YYSYMBOL_char_list = 117,                /* char_list  */
  YYSYMBOL_bool_list = 118,                /* bool_list  */
  YYSYMBOL_str_list = 119,                 /* str_list  */
  YYSYMBOL_weight_list = 120,              /* weight_list  */
  YYSYMBOL_vect_const = 121,               /* vect_const  */
  YYSYMBOL_vect_list = 122,                /* vect_list  */
  YYSYMBOL_matrix_const = 123,             /* matrix_const  */
  YYSYMBOL_mat_list = 124,                 /* mat_list  */
  YYSYMBOL_arith_op = 125,                 /* arith_op  */
  YYSYMBOL_binary_op = 126,                /* binary_op  */
  YYSYMBOL_unary_op = 127,                 /* unary_op  */
  YYSYMBOL_logical_op = 128,               /* logical_op  */
  YYSYMBOL_call_stmt = 129,                /* call_stmt  */
  YYSYMBOL_func_calls = 130,               /* func_calls  */
  YYSYMBOL_arg_list = 131                  /* arg_list  */
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   783

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  384

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      52,    53,     2,    62,    54,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    51,
      55,    58,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    66,    69,    70,    71,    74,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    91,    92,    95,    96,    99,   102,   103,   106,   109,
     110,   113,   114,   117,   118,   121,   122,   123,   124,   125,
     128,   129,   132,   133,   134,   135,   138,   139,   140,   141,
     142,   143,   144,   145,   148,   149,   150,   151,   154,   155,
     156,   157,   160,   161,   162,   165,   166,   167,   170,   173,
     174,   177,   180,   181,   184,   187,   188,   189,   192,   194,
     195,   196,   197,   198,   199,   200,   203,   204,   207,   208,
     211,   212,   215,   215,   218,   219,   222,   222,   225,   228,
     229,   233,   234,   235,   236,   237,   238,   239,   242,   243,
     244,   245,   246,   247,   251,   252,   253,   254,   255,   259,
     260,   263,   264,   265,   266,   267,   270,   273,   274,   277,
     280,   281,   282,   286,   287,   290,   291,   294,   295,   298,
     299,   302,   303,   306,   307,   310,   311,   314,   315,   318,
     319,   322,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   343,   346,
     347,   351,   352,   355,   358,   361,   364,   367,   368,   369,
     370,   373,   374
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
  "STRCUT", "MATXOP", "'{'", "'}'", "';'", "'('", "')'", "','", "'<'",
  "'>'", "'.'", "'='", "'['", "']'", "':'", "'+'", "$accept",
  "program_unit", "models", "model", "class", "id", "class_items",
  "class_item", "struct", "struct_items", "function", "function_head",
  "fdtype", "param_list", "dtype", "function_body", "statements",
  "statement", "vect_stmt", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "while_loop",
  "expr_stmt", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@1", "if_body", "switch_stmt",
  "$@2", "switch_body", "cases", "RHS", "constants", "extra_consts",
  "array_const", "val_list", "string_impr", "vect_impr", "graph_impr",
  "matrix_impr", "graph_const", "graph_type1", "graph_type2", "int_list",
  "float_list", "char_list", "bool_list", "str_list", "weight_list",
  "vect_const", "vect_list", "matrix_const", "mat_list", "arith_op",
  "binary_op", "unary_op", "logical_op", "call_stmt", "func_calls",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    45,    45,   725,    31,  -216,    -9,  -216,  -216,  -216,
      -6,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,    -2,    15,  -216,  -216,  -216,  -216,    48,
    -216,    45,  -216,  -216,  -216,   537,  -216,    -7,    88,   736,
      69,   252,    71,    75,     9,    45,    45,    59,  -216,    72,
     662,    80,   662,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,    77,    81,    -7,  -216,  -216,    82,    88,    83,   492,
    -216,  -216,  -216,  -216,  -216,    84,    85,    89,   555,   446,
      65,  -216,    76,    92,  -216,    93,  -216,  -216,  -216,    94,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   446,
     446,    45,    45,    45,    79,    45,    45,    95,    90,    55,
      98,    99,  -216,  -216,  -216,    78,  -216,  -216,  -216,  -216,
      96,  -216,   101,  -216,  -216,  -216,    87,    45,   446,   446,
     446,   -25,   100,   103,   104,   105,   603,  -216,   107,   112,
     113,   110,   115,   109,   128,   114,   116,   122,   124,   125,
     151,  -216,   120,  -216,  -216,  -216,  -216,  -216,   121,    54,
    -216,  -216,  -216,   129,   130,    52,  -216,  -216,   108,  -216,
     126,  -216,   736,    45,    45,  -216,   252,   344,    45,   139,
     446,   132,   135,   136,   137,  -216,  -216,  -216,   138,   143,
     145,   146,   205,     6,   205,   205,   205,   205,   147,   149,
     205,  -216,  -216,   205,  -216,    23,   446,   151,   185,   199,
     207,   198,   155,  -216,  -216,   164,   165,   166,   167,   168,
    -216,  -216,    45,   218,   220,   170,   173,  -216,  -216,   177,
     178,   179,  -216,   180,   182,   187,   209,   210,   680,   475,
     213,   215,   736,   446,  -216,   446,  -216,   227,   181,   211,
    -216,  -216,  -216,  -216,   205,  -216,  -216,   216,  -216,  -216,
    -216,  -216,  -216,   219,   221,   475,   222,   226,   475,   223,
     232,  -216,   224,   225,    45,  -216,  -216,  -216,   446,  -216,
     395,   235,   238,   617,  -216,   249,  -216,  -216,  -216,  -216,
     250,  -216,  -216,   254,   255,  -216,   256,   257,   217,   303,
     308,  -216,  -216,   258,  -216,   260,  -216,  -216,   262,   662,
    -216,   295,  -216,   264,   261,  -216,  -216,  -216,   269,    46,
     662,  -216,   275,   276,  -216,  -216,  -216,  -216,   324,   268,
    -216,   270,  -216,  -216,  -216,  -216,   280,   328,   312,    45,
     335,  -216,    45,   287,  -216,   292,  -216,  -216,   290,   151,
     293,   330,   285,   294,  -216,   296,   299,   304,  -216,   300,
     309,   310,   311,   307,    11,   662,   293,   662,   662,   662,
      45,  -216,   313,  -216,   315,   321,   323,  -216,  -216,  -216,
     295,   326,  -216,  -216
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    35,    32,    36,    37,     0,
      39,     0,    31,     1,     3,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
      45,     0,    43,    53,    52,    51,    46,    48,    49,    50,
      47,     0,     0,    22,    24,    23,     0,    27,     0,     0,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   126,   113,     0,   101,     0,   114,   102,   106,     0,
     107,   115,   116,   117,   103,   171,   172,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    70,     0,    44,    40,    42,   176,
       0,    21,     0,    26,    38,    29,     0,     0,     0,     0,
       0,   160,   162,   161,   164,   163,     0,   118,   165,     0,
       0,   166,     0,   113,     0,   140,   142,   144,   148,   146,
       0,   120,     0,   121,   122,   123,   124,   125,     0,     0,
      65,    66,    67,     0,     0,    91,    83,    79,     0,    82,
       0,    80,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,    25,    30,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   167,
       0,   133,   134,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   168,     0,     0,     0,     0,     0,
      92,    96,     0,     0,     0,     0,    91,    85,    84,     0,
       0,     0,   178,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   174,     0,   152,     0,     0,     0,
     154,   153,   156,   155,     0,   157,   158,     0,   139,   141,
     143,   147,   145,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,    75,    76,    77,     0,   177,
       0,     0,     0,     0,   113,     0,    62,    64,    58,    59,
       0,    61,    60,     0,     0,    33,     0,     0,     0,   136,
     138,   159,   175,   170,   127,     0,   131,   132,     0,     0,
      93,     0,    97,    87,     0,    81,   181,   180,     0,     0,
       0,    63,     0,     0,    56,    57,   173,   130,     0,     0,
     135,     0,   137,   169,   128,   129,     0,     0,     0,     0,
       0,   179,     0,     0,    72,     0,    54,    55,     0,     0,
       0,    95,     0,     0,    86,     0,     0,     0,    74,   150,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,    73,     0,   149,     0,     0,     0,    88,    71,    94,
     100,     0,    99,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,   356,  -216,  -216,    -1,   314,  -216,  -216,   327,
     -28,  -216,  -216,   153,     2,   364,   -44,  -216,  -216,  -190,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,   200,   -21,  -216,
     -99,     8,  -161,  -216,  -216,  -216,  -216,  -216,  -216,     0,
     -20,   169,   228,  -216,  -216,  -216,  -216,   229,  -216,  -216,
     111,   117,   -69,   201,   184,   197,   202,    47,   -34,  -140,
    -216,   119,  -215,  -216,    97,   175,  -216,   -32,  -158
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,   143,    62,    63,     8,    66,
       9,    10,    31,   126,   127,    50,    51,    52,    53,   290,
     285,    54,    55,   112,   113,   343,   114,    56,    57,   107,
     166,   169,   167,    58,   269,   310,    59,   270,   312,   338,
     233,    84,    85,    86,   152,    87,    88,    89,    90,    91,
     139,   140,   248,   154,   155,   156,   157,   249,   141,   142,
      93,   158,    94,    95,    96,    97,    60,    98,   234
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    24,    30,    61,   171,    32,   116,    92,   118,    64,
     145,   153,   227,   228,     1,     2,    65,    67,    61,   101,
      61,    83,    44,     3,   291,     3,   102,   103,   104,   192,
      40,    33,   105,   106,    49,    64,   193,    75,    30,    76,
      82,    68,    65,    35,   108,   109,    67,    37,    11,    49,
     291,    49,   246,   291,   250,   251,   252,   253,   247,   144,
     255,   271,   215,   256,    38,   216,   217,   218,    30,   145,
     146,   147,   148,   149,    76,   305,   342,   138,   308,   163,
     164,   212,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   215,   110,   111,   216,   217,   218,   219,
     165,   168,   170,    39,   173,   174,   222,   177,   189,   190,
     191,   223,   178,   315,   301,   181,   182,    44,   183,   184,
     316,    69,   318,    99,   150,   151,   188,   100,   119,   115,
     117,   120,   122,   159,   172,   138,   128,   129,   258,   124,
     187,   130,    92,   160,   161,   162,   175,   185,   176,   371,
     179,   180,   186,   206,   194,   145,   229,   195,   196,   197,
     237,   200,   201,   202,   203,   204,   205,   224,   207,    45,
     208,    30,   226,   226,   225,    82,   209,   235,   210,   211,
     213,   214,   220,   221,   238,   223,   257,   239,   240,   241,
     146,   138,   242,   138,   138,   138,   138,   243,   244,   138,
     245,   192,   138,   254,   287,   147,   149,   292,    11,   198,
     132,   133,   134,   135,   148,   263,   264,   265,   266,   267,
     268,   226,   272,   296,   273,   297,   274,   222,   275,   276,
     277,   298,   299,   292,   278,   279,   292,   284,   289,   280,
     354,    30,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   138,   136,    11,    70,    71,    72,    73,
      74,    79,   300,   282,   289,   336,   293,   289,   294,   302,
     303,   328,   309,   226,   304,   306,   345,    61,    75,   307,
      76,   311,   138,    46,   313,   314,   319,   320,    61,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      77,    78,   322,   323,    79,   324,   325,   329,    49,   326,
     327,    80,   331,   334,    81,   335,   337,   150,   339,    49,
     340,   372,   341,   374,   375,   376,   346,   347,   348,   349,
     351,   350,   352,    61,   353,    61,    61,    61,   170,   355,
     357,   356,   358,   359,   360,   247,   361,    11,    70,    71,
      72,    73,    74,   365,   366,   362,   363,   364,   367,   368,
     369,   370,    34,   378,    49,   379,    49,    49,    49,   168,
      75,   380,    76,   381,    36,    46,   383,   121,   377,   236,
     382,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    77,   260,   123,   295,    79,   232,    11,    70,
      71,    72,    73,    74,   230,   231,    81,   286,   262,   259,
     330,   281,   261,   373,     0,     0,   344,   332,     0,     0,
       0,    75,   333,    76,     0,     0,    46,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    77,     0,     0,     0,    79,   317,    11,
      70,    71,    72,    73,    74,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,    76,     0,     0,    46,    11,   288,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    77,    11,     0,     0,    79,     0,
       0,    75,    25,    76,     0,     0,    46,     0,    81,    27,
      28,    29,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      11,     0,     0,     0,     0,   125,     0,     0,     0,    41,
      42,     0,     0,     0,     0,     0,     0,    43,    11,   131,
     132,   133,   134,   135,     0,     0,    44,    45,    46,     0,
      47,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    35,    48,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,   136,   137,    11,   198,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
      11,   198,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     0,   136,   199,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    11,   136,   321,     0,     0,
       0,     0,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,    43,    11,    70,    71,    72,    73,    74,     0,
       0,    44,    45,    46,     0,    47,     0,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,    35,     0,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    11,   283,
       0,     0,     0,     0,     0,    25,    26,     0,     0,    11,
       0,     0,    27,    28,    29,     0,    25,     0,     0,     0,
       0,     0,     0,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    35,   103,     3,    50,    41,    52,    37,
       4,    80,   173,   174,    23,    24,    37,    38,    50,    10,
      52,    41,    29,    32,   239,    32,    17,    18,    19,    54,
      31,     0,    23,    24,    35,    63,    61,    26,    39,    28,
      41,    39,    63,    49,    45,    46,    67,    49,     3,    50,
     265,    52,   192,   268,   194,   195,   196,   197,    52,    79,
     200,   222,    39,   203,    49,    42,    43,    44,    69,     4,
       5,     6,     7,     8,    28,   265,    30,    78,   268,    99,
     100,   150,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    39,    35,    36,    42,    43,    44,    45,
     101,   102,   103,    55,   105,   106,    54,    52,   128,   129,
     130,    59,    57,   274,   254,    37,    38,    29,    40,    41,
     278,    52,   280,    52,    59,    60,   127,    52,    51,    57,
      50,    50,    50,    57,    55,   136,    52,    52,   207,    56,
      53,    52,   176,    51,    51,    51,    51,    51,    58,   364,
      52,    52,    51,    25,    54,     4,   176,    54,    54,    54,
     180,    54,    50,    50,    54,    50,    57,    59,    54,    30,
      54,   172,   173,   174,   172,   176,    54,   178,    54,    54,
      60,    60,    53,    53,    52,    59,   206,    52,    52,    52,
       5,   192,    54,   194,   195,   196,   197,    54,    53,   200,
      54,    54,   203,    54,   238,     6,     8,   239,     3,     4,
       5,     6,     7,     8,     7,    60,    52,    52,    52,    52,
      52,   222,     4,   243,     4,   245,    56,    54,    51,    51,
      51,     4,    51,   265,    54,    53,   268,   238,   239,    52,
     339,   242,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   254,    49,     3,     4,     5,     6,     7,
       8,    52,    51,    53,   265,   309,    53,   268,    53,    53,
      51,    54,    49,   274,    53,    53,   320,   309,    26,    53,
      28,    49,   283,    31,    60,    60,    51,    49,   320,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    53,    53,    52,    51,    51,     4,   309,    53,
      53,    59,     4,    53,    62,    53,    21,    59,    54,   320,
      59,   365,    53,   367,   368,   369,    51,    51,     4,    61,
      50,    61,     4,   365,    22,   367,   368,   369,   339,     4,
      53,   342,    50,    53,    14,    52,    61,     3,     4,     5,
       6,     7,     8,    49,    54,    61,    60,    58,    49,    49,
      49,    54,     6,    50,   365,    50,   367,   368,   369,   370,
      26,    50,    28,    50,    10,    31,    50,    63,   370,   179,
     380,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   209,    67,   242,    52,    53,     3,     4,
       5,     6,     7,     8,   176,   176,    62,   238,   211,   208,
     299,   236,   210,   366,    -1,    -1,   319,   300,    -1,    -1,
      -1,    26,   303,    28,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    52,    53,     3,
       4,     5,     6,     7,     8,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    31,     3,     4,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     3,    -1,    -1,    52,    -1,
      -1,    26,    10,    28,    -1,    -1,    31,    -1,    62,    17,
      18,    19,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    20,     3,     4,
       5,     6,     7,     8,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    20,     3,     4,     5,     6,     7,     8,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     3,    49,
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,     3,
      -1,    -1,    17,    18,    19,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    24,    32,    64,    65,    66,    67,    71,    73,
      74,     3,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    68,    68,    10,    11,    17,    18,    19,
      68,    75,    77,     0,    65,    49,    78,    49,    49,    55,
      68,    12,    13,    20,    29,    30,    31,    33,    50,    68,
      78,    79,    80,    81,    84,    85,    90,    91,    96,    99,
     129,   130,    69,    70,    73,    91,    72,    91,    77,    52,
       4,     5,     6,     7,     8,    26,    28,    48,    49,    52,
      59,    62,    68,   103,   104,   105,   106,   108,   109,   110,
     111,   112,   121,   123,   125,   126,   127,   128,   130,    52,
      52,    10,    17,    18,    19,    23,    24,    92,    68,    68,
      35,    36,    86,    87,    89,    57,    79,    50,    79,    51,
      50,    69,    50,    72,    56,    53,    76,    77,    52,    52,
      52,     4,     5,     6,     7,     8,    49,    50,    68,   113,
     114,   121,   122,    68,   103,     4,     5,     6,     7,     8,
      59,    60,   107,   115,   116,   117,   118,   119,   124,    57,
      51,    51,    51,   103,   103,    68,    93,    95,    68,    94,
      68,    93,    55,    68,    68,    51,    58,    52,    57,    52,
      52,    37,    38,    40,    41,    51,    51,    53,    68,   103,
     103,   103,    54,    61,    54,    54,    54,    54,     4,    50,
      54,    50,    50,    54,    50,    57,    25,    54,    54,    54,
      54,    54,   115,    60,    60,    39,    42,    43,    44,    45,
      53,    53,    54,    59,    59,    77,    68,    95,    95,   103,
     105,   110,    53,   103,   131,    68,    90,   103,    52,    52,
      52,    52,    54,    54,    53,    54,   122,    52,   115,   120,
     122,   122,   122,   122,    54,   122,   122,   103,   115,   116,
     117,   119,   118,    60,    52,    52,    52,    52,    52,    97,
     100,    95,     4,     4,    56,    51,    51,    51,    54,    53,
      52,   128,    53,    49,    68,    83,   104,   121,     4,    68,
      82,   125,   130,    53,    53,    76,   103,   103,     4,    51,
      51,   122,    53,    51,    53,    82,    53,    53,    82,    49,
      98,    49,   101,    60,    60,    95,   131,    53,   131,    51,
      49,    50,    53,    53,    51,    51,    53,    53,    54,     4,
     113,     4,   114,   124,    53,    53,    79,    21,   102,    54,
      59,    53,    30,    88,   127,    79,    51,    51,     4,    61,
      61,    50,     4,    22,    93,     4,    68,    53,    50,    53,
      14,    61,    61,    60,    58,    49,    54,    49,    49,    49,
      54,   125,    79,   120,    79,    79,    79,    94,    50,    50,
      50,    50,   102,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    70,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    85,    86,
      86,    87,    88,    88,    89,    90,    90,    90,    91,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    97,    96,    98,    98,   100,    99,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     111,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   124,
     124,   125,   125,   126,   127,   128,   129,   130,   130,   130,
     130,   131,   131
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     6,     2,     1,     2,     5,
       6,     1,     1,     4,     2,     1,     1,     1,     4,     1,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     7,     6,     6,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     3,     2,     1,
       1,    10,     1,     4,     7,     5,     5,     5,     3,     2,
       2,     5,     2,     2,     3,     3,     6,     4,     9,     7,
       3,     1,     0,     6,     7,     3,     0,     6,     8,     7,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     5,     6,     6,
       6,     5,     5,     3,     3,     5,     4,     5,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     7,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       4,     1,     1,     6,     4,     5,     2,     5,     4,     7,
       6,     3,     1
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
#line 74 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1684 "y.tab.c"
    break;

  case 25: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 99 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1690 "y.tab.c"
    break;

  case 29: /* function_head: FUNC fdtype id '(' ')'  */
#line 109 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1696 "y.tab.c"
    break;

  case 30: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 110 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1702 "y.tab.c"
    break;

  case 53: /* statement: vect_stmt  */
#line 145 "parser.y"
                                                            {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 1708 "y.tab.c"
    break;

  case 65: /* return_stmt: RETURN RHS ';'  */
#line 165 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1714 "y.tab.c"
    break;

  case 66: /* return_stmt: RETURN extra_consts ';'  */
#line 166 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 1720 "y.tab.c"
    break;

  case 67: /* return_stmt: RETURN graph_impr ';'  */
#line 167 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 1726 "y.tab.c"
    break;

  case 68: /* loop_stmt: LOOP loop_type  */
#line 170 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1732 "y.tab.c"
    break;

  case 75: /* expr_stmt: EXPR id '=' RHS ';'  */
#line 187 "parser.y"
                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1738 "y.tab.c"
    break;

  case 76: /* expr_stmt: EXPR id '=' extra_consts ';'  */
#line 188 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1744 "y.tab.c"
    break;

  case 77: /* expr_stmt: EXPR id '=' graph_impr ';'  */
#line 189 "parser.y"
                                                                             {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1750 "y.tab.c"
    break;

  case 78: /* declr_stmt: DECLR declr_body ';'  */
#line 192 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1756 "y.tab.c"
    break;

  case 92: /* $@1: %empty  */
#line 215 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1762 "y.tab.c"
    break;

  case 96: /* $@2: %empty  */
#line 222 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1768 "y.tab.c"
    break;

  case 176: /* call_stmt: func_calls ';'  */
#line 364 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1774 "y.tab.c"
    break;


#line 1778 "y.tab.c"

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

#line 377 "parser.y"


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




