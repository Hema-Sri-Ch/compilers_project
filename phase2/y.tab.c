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

/*

--> Remove the undeclared variables in the grammer rule of 'statement' while testing your code. Those variables will be declared by your teammates soon. (line no: 109)

--> Give understandable names to the variables while writting grammar so that others can understand your code

--> compile it with 
		
  		yacc -d parser.y

--> Then compile your lexer with 

		lex lexer.l
  		gcc lex.yy.c y.tab.c

--> write your testcase in 'inp' file

--> test it with command

		./a.out <inp
		
--> This will automatically read from the file 'inp'
*/

	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);

#line 106 "y.tab.c"

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
    id = 258,                      /* id  */
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
    EXP = 283,                     /* EXP  */
    UNARYOP = 284,                 /* UNARYOP  */
    DECLR = 285,                   /* DECLR  */
    EXPR = 286,                    /* EXPR  */
    CALL = 287,                    /* CALL  */
    FUNC = 288,                    /* FUNC  */
    LOOP = 289,                    /* LOOP  */
    null = 290,                    /* null  */
    FOR = 291,                     /* FOR  */
    WHILE = 292                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define id 258
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
#define EXP 283
#define UNARYOP 284
#define DECLR 285
#define EXPR 286
#define CALL 287
#define FUNC 288
#define LOOP 289
#define null 290
#define FOR 291
#define WHILE 292

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
  YYSYMBOL_id = 3,                         /* id  */
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
  YYSYMBOL_EXP = 28,                       /* EXP  */
  YYSYMBOL_UNARYOP = 29,                   /* UNARYOP  */
  YYSYMBOL_DECLR = 30,                     /* DECLR  */
  YYSYMBOL_EXPR = 31,                      /* EXPR  */
  YYSYMBOL_CALL = 32,                      /* CALL  */
  YYSYMBOL_FUNC = 33,                      /* FUNC  */
  YYSYMBOL_LOOP = 34,                      /* LOOP  */
  YYSYMBOL_null = 35,                      /* null  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program_unit = 53,              /* program_unit  */
  YYSYMBOL_models = 54,                    /* models  */
  YYSYMBOL_model = 55,                     /* model  */
  YYSYMBOL_class = 56,                     /* class  */
  YYSYMBOL_class_items = 57,               /* class_items  */
  YYSYMBOL_class_item = 58,                /* class_item  */
  YYSYMBOL_struct = 59,                    /* struct  */
  YYSYMBOL_struct_items = 60,              /* struct_items  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_function_head = 62,             /* function_head  */
  YYSYMBOL_fdtype = 63,                    /* fdtype  */
  YYSYMBOL_param_list = 64,                /* param_list  */
  YYSYMBOL_dtype = 65,                     /* dtype  */
  YYSYMBOL_function_body = 66,             /* function_body  */
  YYSYMBOL_statements = 67,                /* statements  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_return_stmt = 69,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 70,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 71,                 /* loop_type  */
  YYSYMBOL_for_loop = 72,                  /* for_loop  */
  YYSYMBOL_while_loop = 73,                /* while_loop  */
  YYSYMBOL_while_res = 74,                 /* while_res  */
  YYSYMBOL_expr_stmt = 75,                 /* expr_stmt  */
  YYSYMBOL_declr_stmt = 76,                /* declr_stmt  */
  YYSYMBOL_declr_body = 77,                /* declr_body  */
  YYSYMBOL_graph_and_array_list = 78,      /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 79,               /* matrix_list  */
  YYSYMBOL_id_list = 80,                   /* id_list  */
  YYSYMBOL_ifcond_stmt = 81,               /* ifcond_stmt  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_if_body = 83,                   /* if_body  */
  YYSYMBOL_switch_stmt = 84,               /* switch_stmt  */
  YYSYMBOL_85_2 = 85,                      /* $@2  */
  YYSYMBOL_switch_body = 86,               /* switch_body  */
  YYSYMBOL_cases = 87,                     /* cases  */
  YYSYMBOL_cond_res = 88,                  /* cond_res  */
  YYSYMBOL_RHS = 89,                       /* RHS  */
  YYSYMBOL_constants = 90,                 /* constants  */
  YYSYMBOL_array_const = 91,               /* array_const  */
  YYSYMBOL_val_list = 92,                  /* val_list  */
  YYSYMBOL_graph_const = 93,               /* graph_const  */
  YYSYMBOL_graph_type1 = 94,               /* graph_type1  */
  YYSYMBOL_graph_type2 = 95,               /* graph_type2  */
  YYSYMBOL_int_list = 96,                  /* int_list  */
  YYSYMBOL_float_list = 97,                /* float_list  */
  YYSYMBOL_char_list = 98,                 /* char_list  */
  YYSYMBOL_bool_list = 99,                 /* bool_list  */
  YYSYMBOL_str_list = 100,                 /* str_list  */
  YYSYMBOL_weight_list = 101,              /* weight_list  */
  YYSYMBOL_vect_const = 102,               /* vect_const  */
  YYSYMBOL_vect_list = 103,                /* vect_list  */
  YYSYMBOL_matrix_const = 104,             /* matrix_const  */
  YYSYMBOL_arith_op = 105,                 /* arith_op  */
  YYSYMBOL_binary_op = 106,                /* binary_op  */
  YYSYMBOL_unary_op = 107,                 /* unary_op  */
  YYSYMBOL_logical_op = 108,               /* logical_op  */
  YYSYMBOL_call_stmt = 109,                /* call_stmt  */
  YYSYMBOL_func_calls = 110,               /* func_calls  */
  YYSYMBOL_arg_list = 111                  /* arg_list  */
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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      41,    42,     2,     2,    43,    50,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    40,
      44,    46,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    79,    82,    83,    84,    87,    90,
      91,    94,    95,    98,   101,   102,   105,   108,   109,   112,
     113,   116,   117,   120,   121,   122,   123,   124,   127,   130,
     131,   132,   133,   136,   137,   138,   139,   140,   141,   142,
     144,   146,   148,   149,   152,   155,   157,   158,   162,   165,
     167,   168,   169,   170,   171,   172,   173,   176,   177,   180,
     181,   184,   185,   188,   188,   191,   192,   195,   195,   198,
     201,   202,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   216,   217,   218,   219,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   236,   237,   240,   241,
     242,   243,   244,   248,   249,   252,   253,   256,   257,   260,
     261,   264,   265,   268,   269,   272,   273,   276,   277,   280,
     281,   284,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   305,   308,
     309,   312,   315,   318,   321,   324,   325,   326,   327,   330,
     331
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
  "\"end of file\"", "error", "\"invalid token\"", "id", "INT_CONST",
  "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "BOOL_CONST", "PUNC",
  "DATATYPE", "VOID", "RETURN", "IF", "ELSE", "CONTINUE", "BREAK",
  "MATRIX", "GRAPH", "VECT", "SWITCH", "CASE", "DEFAULT", "CLASS",
  "STRUCT", "LOGOP", "ARITHOP", "NOT", "EXP", "UNARYOP", "DECLR", "EXPR",
  "CALL", "FUNC", "LOOP", "null", "FOR", "WHILE", "'{'", "'}'", "';'",
  "'('", "')'", "','", "'<'", "'>'", "'='", "'['", "']'", "':'", "'-'",
  "'.'", "$accept", "program_unit", "models", "model", "class",
  "class_items", "class_item", "struct", "struct_items", "function",
  "function_head", "fdtype", "param_list", "dtype", "function_body",
  "statements", "statement", "return_stmt", "loop_stmt", "loop_type",
  "for_loop", "while_loop", "while_res", "expr_stmt", "declr_stmt",
  "declr_body", "graph_and_array_list", "matrix_list", "id_list",
  "ifcond_stmt", "$@1", "if_body", "switch_stmt", "$@2", "switch_body",
  "cases", "cond_res", "RHS", "constants", "array_const", "val_list",
  "graph_const", "graph_type1", "graph_type2", "int_list", "float_list",
  "char_list", "bool_list", "str_list", "weight_list", "vect_const",
  "vect_list", "matrix_const", "arith_op", "binary_op", "unary_op",
  "logical_op", "call_stmt", "func_calls", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-176)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    25,    58,   260,    63,  -176,     2,  -176,  -176,  -176,
      33,    37,    40,  -176,  -176,  -176,  -176,  -176,    46,    69,
    -176,  -176,  -176,   230,  -176,     8,    65,    90,    55,   162,
      56,    57,   264,    96,   107,     3,   230,    72,   230,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,    74,    80,     8,  -176,
    -176,    81,    65,    76,    47,  -176,  -176,  -176,  -176,  -176,
    -176,    85,    87,   210,   162,    26,  -176,    82,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   148,   148,
     126,   128,   129,    89,   132,   135,   101,    97,   -14,   103,
     105,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   102,  -176,
     109,  -176,  -176,  -176,   108,   144,   162,   162,   114,    19,
     116,   117,   119,   121,   220,  -176,   133,   134,   136,   137,
     146,   140,   141,   147,   149,   150,  -176,   127,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     153,  -176,  -176,  -176,   154,    34,  -176,  -176,   131,  -176,
     151,  -176,    90,   194,   194,  -176,   162,    41,   196,   170,
     148,  -176,  -176,  -176,   159,   161,   164,   231,   231,    10,
     231,   231,   231,   231,   165,   168,  -176,  -176,   231,  -176,
     162,   203,   214,   223,   213,   222,  -176,  -176,  -176,   194,
     227,   236,   199,   198,  -176,  -176,   205,  -176,   204,   209,
     211,   243,   215,  -176,  -176,    74,    90,   162,  -176,  -176,
    -176,   252,   232,   235,  -176,  -176,  -176,  -176,   231,  -176,
     234,  -176,  -176,  -176,  -176,  -176,   242,   246,  -176,   238,
     241,   194,  -176,   162,  -176,    98,   244,   253,  -176,   250,
     251,   289,   291,  -176,  -176,   230,  -176,   275,  -176,   254,
     255,  -176,  -176,  -176,   256,   148,   230,  -176,   295,   257,
    -176,   258,  -176,   261,   297,   281,   129,   300,  -176,   265,
     269,   267,   203,   270,   296,   263,   266,  -176,   268,   272,
    -176,   271,   279,   280,   282,   276,   283,   270,   230,   230,
     230,   128,   292,  -176,   285,   286,   287,  -176,   288,  -176,
     275,   293,   319,  -176,  -176,   294,   298,   290,   230,   299,
    -176
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,     0,    27,    23,    20,    24,    25,     0,     0,
      19,     1,     3,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,    30,    39,
      38,    33,    35,    36,    37,    34,     0,     0,    10,    12,
      11,     0,    15,     0,     0,    94,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,   138,     0,    81,    90,
      91,    93,    92,    82,   139,   140,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    31,    28,    29,   144,     0,     9,
       0,    14,    26,    17,     0,     0,     0,     0,   135,   130,
     132,   131,   134,   133,     0,    95,     0,     0,   136,     0,
       0,   110,   112,   114,   118,   116,    97,     0,    98,    99,
     100,   101,   102,    40,    79,    72,    75,    76,    77,    78,
       0,    80,    73,    74,     0,    62,    54,    50,     0,    53,
       0,    51,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     8,    13,    18,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   137,   103,   104,     0,   121,
       0,     0,     0,     0,     0,     0,    96,    63,    67,     0,
       0,     0,     0,    62,    56,    55,     0,   146,   150,     0,
       0,     0,     0,    46,    47,    74,     0,     0,   142,   127,
     122,     0,     0,     0,   124,   123,   126,   125,     0,   128,
       0,   109,   111,   113,   117,   115,     0,     0,    61,     0,
       0,     0,    48,     0,   145,     0,     0,     0,    21,     0,
       0,   106,   108,   129,   143,     0,    64,     0,    68,    58,
       0,    52,   149,   148,     0,     0,     0,   141,     0,     0,
     105,     0,   107,     0,     0,     0,     0,     0,   147,     0,
       0,     0,     0,     0,    66,     0,     0,    57,     0,     0,
      45,   120,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,    59,     0,    65,
      71,     0,     0,    70,    69,     0,     0,     0,     0,     0,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,   321,  -176,  -176,   301,  -176,  -176,   278,    -5,
    -176,  -176,   125,     9,   323,   -35,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,    28,  -176,   -80,    43,  -137,  -176,
    -176,  -176,  -176,  -176,  -176,    35,   -73,   -22,  -176,  -176,
    -176,  -176,   100,    95,   -56,   157,   160,   163,   158,    59,
     -55,  -149,  -176,   -68,  -176,  -176,   -74,   184,   -23,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    47,    48,     8,    51,     9,
      10,    19,   104,   105,    36,    37,    38,    39,    40,    91,
      92,    93,   202,    41,    42,    86,   146,   149,   147,    43,
     226,   246,    44,   227,   248,   265,   140,   198,    68,    69,
     127,    70,   116,   117,   212,   129,   130,   131,   132,   213,
      71,   119,    72,    73,    74,    75,    76,    45,    77,   199
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    94,   151,    96,   142,   142,   144,    67,   118,   128,
     141,   141,    20,    46,   121,    46,   194,   195,   209,   210,
      49,   214,   215,   216,   217,     1,     2,   157,    11,   219,
     121,   122,   123,   124,   125,     3,    53,   158,    32,    89,
      90,     3,   120,    49,    55,    56,    57,    58,    59,    60,
      13,   211,   228,    50,    52,   143,   143,    14,   252,   118,
     254,    12,   168,    21,    16,    17,    18,    61,   169,   243,
      62,    23,    28,    34,   126,    25,    50,   189,    26,    63,
      52,   190,    64,   197,   165,   166,   142,   203,    65,   103,
      27,    66,   141,    13,   251,    32,    54,    78,    79,    87,
      14,    55,    56,    57,    58,    59,    60,    16,    17,    18,
      88,    95,   118,   118,    97,   118,   118,   118,   118,    98,
     100,   102,   133,   118,    61,   221,   106,    62,   107,   145,
      34,   148,   150,   152,   196,   153,    63,   205,   154,    64,
     253,   155,   161,   156,   159,    65,   160,   164,    66,   162,
     163,   134,   135,   136,   137,   138,   139,   167,   220,   170,
     171,   192,   172,   118,   173,    55,    56,    57,    58,    59,
      60,   180,   176,   177,    61,   186,   179,    62,   191,   178,
      34,   142,   269,   181,   182,   239,   277,   141,    61,    64,
     183,    62,   184,   185,    34,   187,   188,   193,   190,   200,
      63,   201,   206,    64,   207,   286,   208,   121,   168,    65,
     263,   218,    66,   108,   109,   110,   111,   112,   113,   122,
     124,   270,    46,   108,   174,   110,   111,   112,   113,   123,
     125,   229,   143,    46,   108,   174,   110,   111,   112,   113,
     230,   189,    29,    30,   231,   232,   236,   233,   114,   115,
      31,   234,   235,   294,   295,   296,   240,   237,   114,   175,
      32,    33,    34,    13,    35,    46,    46,    46,    23,   114,
      14,    15,   241,   309,    80,   242,   244,    16,    17,    18,
     245,    81,    82,    83,   247,    46,   249,    84,    85,   250,
     255,   256,   257,   259,   258,   261,   264,   266,   268,   271,
     274,   275,   267,   276,   278,   279,   272,   273,   280,   281,
     282,   211,   283,    64,   287,   284,   285,   288,   289,   291,
     290,   298,   305,   292,   299,   300,   301,    22,   308,   302,
     101,   238,   304,    24,   297,   303,   306,   262,   310,   222,
     307,   260,   224,   223,   204,     0,   293,     0,   225,    99
};

static const yytype_int16 yycheck[] =
{
      23,    36,    82,    38,    78,    79,    79,    29,    63,    65,
      78,    79,     3,    36,     4,    38,   153,   154,   167,   168,
      25,   170,   171,   172,   173,    23,    24,    41,     3,   178,
       4,     5,     6,     7,     8,    33,    27,    51,    30,    36,
      37,    33,    64,    48,     3,     4,     5,     6,     7,     8,
       3,    41,   189,    25,    26,    78,    79,    10,   233,   114,
     235,     3,    43,     0,    17,    18,    19,    26,    49,   218,
      29,    38,     3,    32,    48,    38,    48,    43,    38,    38,
      52,    47,    41,    42,   106,   107,   160,   160,    47,    42,
      44,    50,   160,     3,   231,    30,    41,    41,    41,     3,
      10,     3,     4,     5,     6,     7,     8,    17,    18,    19,
       3,    39,   167,   168,    40,   170,   171,   172,   173,    39,
      39,    45,    40,   178,    26,   181,    41,    29,    41,     3,
      32,     3,     3,    44,   156,     3,    38,   160,     3,    41,
      42,    40,    40,    46,    41,    47,    41,     3,    50,    40,
      42,     3,     4,     5,     6,     7,     8,    43,   180,    43,
      43,   152,    43,   218,    43,     3,     4,     5,     6,     7,
       8,    25,    39,    39,    26,    48,    39,    29,    47,    43,
      32,   255,   255,    43,    43,   207,   266,   255,    26,    41,
      43,    29,    43,    43,    32,    42,    42,     3,    47,     3,
      38,    31,    43,    41,    43,   279,    42,     4,    43,    47,
     245,    43,    50,     3,     4,     5,     6,     7,     8,     5,
       7,   256,   245,     3,     4,     5,     6,     7,     8,     6,
       8,     4,   255,   256,     3,     4,     5,     6,     7,     8,
       4,    43,    12,    13,    45,    40,     3,    43,    38,    39,
      20,    42,    41,   288,   289,   290,     4,    42,    38,    39,
      30,    31,    32,     3,    34,   288,   289,   290,    38,    38,
      10,    11,    40,   308,    10,    40,    42,    17,    18,    19,
      38,    17,    18,    19,    38,   308,    48,    23,    24,    48,
      46,    38,    42,     4,    43,     4,    21,    43,    42,     4,
      39,     4,    47,    22,     4,    40,    49,    49,    39,    42,
      14,    41,    49,    41,    43,    49,    48,    38,    38,    43,
      38,    29,     3,    40,    39,    39,    39,     6,    38,    41,
      52,   206,    39,    10,   291,   300,    42,   242,    39,   182,
      42,   241,   184,   183,   160,    -1,   287,    -1,   185,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    24,    33,    53,    54,    55,    56,    59,    61,
      62,     3,     3,     3,    10,    11,    17,    18,    19,    63,
      65,     0,    54,    38,    66,    38,    38,    44,     3,    12,
      13,    20,    30,    31,    32,    34,    66,    67,    68,    69,
      70,    75,    76,    81,    84,   109,   110,    57,    58,    61,
      76,    60,    76,    65,    41,     3,     4,     5,     6,     7,
       8,    26,    29,    38,    41,    47,    50,    89,    90,    91,
      93,   102,   104,   105,   106,   107,   108,   110,    41,    41,
      10,    17,    18,    19,    23,    24,    77,     3,     3,    36,
      37,    71,    72,    73,    67,    39,    67,    40,    39,    57,
      39,    60,    45,    42,    64,    65,    41,    41,     3,     4,
       5,     6,     7,     8,    38,    39,    94,    95,   102,   103,
      89,     4,     5,     6,     7,     8,    48,    92,    96,    97,
      98,    99,   100,    40,     3,     4,     5,     6,     7,     8,
      88,   105,   108,   110,    88,     3,    78,    80,     3,    79,
       3,    78,    44,     3,     3,    40,    46,    41,    51,    41,
      41,    40,    40,    42,     3,    89,    89,    43,    43,    49,
      43,    43,    43,    43,     4,    39,    39,    39,    43,    39,
      25,    43,    43,    43,    43,    43,    48,    42,    42,    43,
      47,    47,    65,     3,    80,    80,    89,    42,    89,   111,
       3,    31,    74,    88,   109,   110,    43,    43,    42,   103,
     103,    41,    96,   101,   103,   103,   103,   103,    43,   103,
      89,    96,    97,    98,   100,    99,    82,    85,    80,     4,
       4,    45,    40,    43,    42,    41,     3,    42,    64,    89,
       4,    40,    40,   103,    42,    38,    83,    38,    86,    48,
      48,    80,   111,    42,   111,    46,    38,    42,    43,     4,
      94,     4,    95,    67,    21,    87,    43,    47,    42,    88,
      67,     4,    49,    49,    39,     4,    22,    78,     4,    40,
      39,    42,    14,    49,    49,    48,   108,    43,    38,    38,
      38,    43,    40,   101,    67,    67,    67,    79,    29,    39,
      39,    39,    41,    87,    39,     3,    42,    42,    38,    67,
      39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      69,    70,    71,    71,    72,    73,    74,    74,    75,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    79,
      79,    80,    80,    82,    81,    83,    83,    85,    84,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   106,   107,   108,   109,   110,   110,   110,   110,   111,
     111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     2,
       1,     1,     1,     6,     2,     1,     2,     5,     6,     1,
       1,     4,     2,     1,     1,     1,     4,     1,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     1,    17,     7,     1,     1,     5,     3,
       2,     2,     5,     2,     2,     3,     3,     6,     4,     9,
       7,     3,     1,     0,     6,     7,     3,     0,     6,     8,
       7,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     3,     3,     5,     4,     5,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     7,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     6,     4,     5,     2,     5,     4,     7,     6,     3,
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
#line 87 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1541 "y.tab.c"
    break;

  case 13: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 98 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1547 "y.tab.c"
    break;

  case 17: /* function_head: FUNC fdtype id '(' ')'  */
#line 108 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1553 "y.tab.c"
    break;

  case 18: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 109 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1559 "y.tab.c"
    break;

  case 40: /* return_stmt: RETURN RHS ';'  */
#line 144 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1565 "y.tab.c"
    break;

  case 41: /* loop_stmt: LOOP loop_type  */
#line 146 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1571 "y.tab.c"
    break;

  case 48: /* expr_stmt: EXPR id '=' RHS ';'  */
#line 162 "parser.y"
                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1577 "y.tab.c"
    break;

  case 49: /* declr_stmt: DECLR declr_body ';'  */
#line 165 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1583 "y.tab.c"
    break;

  case 63: /* $@1: %empty  */
#line 188 "parser.y"
                                                              {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1589 "y.tab.c"
    break;

  case 67: /* $@2: %empty  */
#line 195 "parser.y"
                                                                  {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1595 "y.tab.c"
    break;

  case 144: /* call_stmt: func_calls ';'  */
#line 321 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1601 "y.tab.c"
    break;


#line 1605 "y.tab.c"

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

#line 334 "parser.y"


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




