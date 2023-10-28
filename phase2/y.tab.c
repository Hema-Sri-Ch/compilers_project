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
    tokenA = 258,                  /* tokenA  */
    id = 259,                      /* id  */
    INT_CONST = 260,               /* INT_CONST  */
    FLOAT_CONST = 261,             /* FLOAT_CONST  */
    CHAR_CONST = 262,              /* CHAR_CONST  */
    STR_CONST = 263,               /* STR_CONST  */
    BOOL_CONST = 264,              /* BOOL_CONST  */
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
    EXP = 284,                     /* EXP  */
    UNARYOP = 285,                 /* UNARYOP  */
    DECLR = 286,                   /* DECLR  */
    EXPR = 287,                    /* EXPR  */
    CALL = 288,                    /* CALL  */
    FUNC = 289,                    /* FUNC  */
    LOOP = 290,                    /* LOOP  */
    null = 291,                    /* null  */
    FOR = 292,                     /* FOR  */
    WHILE = 293                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tokenA 258
#define id 259
#define INT_CONST 260
#define FLOAT_CONST 261
#define CHAR_CONST 262
#define STR_CONST 263
#define BOOL_CONST 264
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
#define EXP 284
#define UNARYOP 285
#define DECLR 286
#define EXPR 287
#define CALL 288
#define FUNC 289
#define LOOP 290
#define null 291
#define FOR 292
#define WHILE 293

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
  YYSYMBOL_tokenA = 3,                     /* tokenA  */
  YYSYMBOL_id = 4,                         /* id  */
  YYSYMBOL_INT_CONST = 5,                  /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 6,                /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 7,                 /* CHAR_CONST  */
  YYSYMBOL_STR_CONST = 8,                  /* STR_CONST  */
  YYSYMBOL_BOOL_CONST = 9,                 /* BOOL_CONST  */
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
  YYSYMBOL_EXP = 29,                       /* EXP  */
  YYSYMBOL_UNARYOP = 30,                   /* UNARYOP  */
  YYSYMBOL_DECLR = 31,                     /* DECLR  */
  YYSYMBOL_EXPR = 32,                      /* EXPR  */
  YYSYMBOL_CALL = 33,                      /* CALL  */
  YYSYMBOL_FUNC = 34,                      /* FUNC  */
  YYSYMBOL_LOOP = 35,                      /* LOOP  */
  YYSYMBOL_null = 36,                      /* null  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program_unit = 54,              /* program_unit  */
  YYSYMBOL_models = 55,                    /* models  */
  YYSYMBOL_model = 56,                     /* model  */
  YYSYMBOL_class = 57,                     /* class  */
  YYSYMBOL_class_items = 58,               /* class_items  */
  YYSYMBOL_class_item = 59,                /* class_item  */
  YYSYMBOL_struct = 60,                    /* struct  */
  YYSYMBOL_struct_items = 61,              /* struct_items  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_function_head = 63,             /* function_head  */
  YYSYMBOL_fdtype = 64,                    /* fdtype  */
  YYSYMBOL_param_list = 65,                /* param_list  */
  YYSYMBOL_dtype = 66,                     /* dtype  */
  YYSYMBOL_function_body = 67,             /* function_body  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_return_stmt = 70,               /* return_stmt  */
  YYSYMBOL_loop_stmt = 71,                 /* loop_stmt  */
  YYSYMBOL_loop_type = 72,                 /* loop_type  */
  YYSYMBOL_for_loop = 73,                  /* for_loop  */
  YYSYMBOL_while_loop = 74,                /* while_loop  */
  YYSYMBOL_while_res = 75,                 /* while_res  */
  YYSYMBOL_expr_stmt = 76,                 /* expr_stmt  */
  YYSYMBOL_declr_stmt = 77,                /* declr_stmt  */
  YYSYMBOL_declr_body = 78,                /* declr_body  */
  YYSYMBOL_graph_and_array_list = 79,      /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 80,               /* matrix_list  */
  YYSYMBOL_id_list = 81,                   /* id_list  */
  YYSYMBOL_ifcond_stmt = 82,               /* ifcond_stmt  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_if_body = 84,                   /* if_body  */
  YYSYMBOL_switch_stmt = 85,               /* switch_stmt  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_switch_body = 87,               /* switch_body  */
  YYSYMBOL_cases = 88,                     /* cases  */
  YYSYMBOL_cond_res = 89,                  /* cond_res  */
  YYSYMBOL_RHS = 90,                       /* RHS  */
  YYSYMBOL_constants = 91,                 /* constants  */
  YYSYMBOL_array_const = 92,               /* array_const  */
  YYSYMBOL_val_list = 93,                  /* val_list  */
  YYSYMBOL_graph_const = 94,               /* graph_const  */
  YYSYMBOL_graph_type1 = 95,               /* graph_type1  */
  YYSYMBOL_graph_type2 = 96,               /* graph_type2  */
  YYSYMBOL_int_list = 97,                  /* int_list  */
  YYSYMBOL_float_list = 98,                /* float_list  */
  YYSYMBOL_char_list = 99,                 /* char_list  */
  YYSYMBOL_bool_list = 100,                /* bool_list  */
  YYSYMBOL_str_list = 101,                 /* str_list  */
  YYSYMBOL_weight_list = 102,              /* weight_list  */
  YYSYMBOL_vect_const = 103,               /* vect_const  */
  YYSYMBOL_vect_list = 104,                /* vect_list  */
  YYSYMBOL_matrix_const = 105,             /* matrix_const  */
  YYSYMBOL_arith_op = 106,                 /* arith_op  */
  YYSYMBOL_binary_op = 107,                /* binary_op  */
  YYSYMBOL_unary_op = 108,                 /* unary_op  */
  YYSYMBOL_logical_op = 109,               /* logical_op  */
  YYSYMBOL_call_stmt = 110,                /* call_stmt  */
  YYSYMBOL_func_calls = 111,               /* func_calls  */
  YYSYMBOL_arg_list = 112                  /* arg_list  */
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
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      42,    43,     2,     2,    44,    51,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    41,
      45,    47,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    79,    80,    83,    84,    85,    88,    91,
      92,    95,    96,    99,   102,   103,   106,   109,   110,   113,
     114,   117,   118,   121,   122,   123,   124,   125,   128,   131,
     132,   133,   134,   137,   138,   139,   140,   141,   142,   143,
     145,   147,   149,   150,   153,   156,   158,   159,   163,   166,
     168,   169,   170,   171,   172,   173,   174,   177,   178,   181,
     182,   185,   186,   189,   189,   192,   193,   196,   196,   199,
     202,   203,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   217,   218,   219,   220,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   237,   238,   241,   242,
     243,   244,   245,   249,   250,   253,   254,   257,   258,   261,
     262,   265,   266,   269,   270,   273,   274,   277,   278,   281,
     282,   285,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   306,   309,
     310,   313,   316,   319,   322,   325,   326,   327,   328,   331,
     332
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
  "\"end of file\"", "error", "\"invalid token\"", "tokenA", "id",
  "INT_CONST", "FLOAT_CONST", "CHAR_CONST", "STR_CONST", "BOOL_CONST",
  "PUNC", "DATATYPE", "VOID", "RETURN", "IF", "ELSE", "CONTINUE", "BREAK",
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

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,    23,    36,   259,    51,  -193,    47,  -193,  -193,  -193,
      21,    24,    29,  -193,  -193,  -193,  -193,  -193,    30,    73,
    -193,  -193,  -193,   229,  -193,    27,    59,    89,    55,   161,
      56,    57,   263,    74,   106,    58,   229,    71,   229,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,    78,    80,    27,  -193,
    -193,    81,    59,    68,    46,  -193,  -193,  -193,  -193,  -193,
    -193,    84,    86,   209,   161,    25,  -193,    88,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   147,   147,
     118,   127,   128,    90,   129,   134,   100,    95,   -14,   101,
     102,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   105,  -193,
     108,  -193,  -193,  -193,   104,   146,   161,   161,   113,   -24,
     115,   116,   120,   131,   219,  -193,   122,   132,   135,   133,
     145,   139,   140,   148,   149,   151,  -193,   141,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
     153,  -193,  -193,  -193,   154,    -9,  -193,  -193,   130,  -193,
     150,  -193,    89,   172,   172,  -193,   161,    40,   195,   169,
     147,  -193,  -193,  -193,   158,   160,   163,   230,   230,    20,
     230,   230,   230,   230,   164,   167,  -193,  -193,   230,  -193,
     161,   202,   213,   222,   212,   221,  -193,  -193,  -193,   172,
     226,   235,   198,   197,  -193,  -193,   204,  -193,   203,   208,
     210,   242,   214,  -193,  -193,    78,    89,   161,  -193,  -193,
    -193,   251,   231,   234,  -193,  -193,  -193,  -193,   230,  -193,
     233,  -193,  -193,  -193,  -193,  -193,   241,   245,  -193,   237,
     240,   172,  -193,   161,  -193,    97,   243,   252,  -193,   249,
     250,   288,   290,  -193,  -193,   229,  -193,   274,  -193,   253,
     254,  -193,  -193,  -193,   255,   147,   229,  -193,   294,   256,
    -193,   257,  -193,   260,   296,   280,   128,   299,  -193,   264,
     268,   266,   202,   269,   295,   262,   265,  -193,   267,   271,
    -193,   270,   278,   279,   281,   275,   282,   269,   229,   229,
     229,   127,   291,  -193,   284,   285,   286,  -193,   287,  -193,
     274,   292,   318,  -193,  -193,   293,   297,   289,   229,   298,
    -193
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
    -193,  -193,   321,  -193,  -193,   283,  -193,  -193,   300,   -11,
    -193,  -193,   124,     9,   323,   -35,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,    28,  -193,   -80,    43,  -137,  -193,
    -193,  -193,  -193,  -193,  -193,    35,   -73,   -22,  -193,  -193,
    -193,  -193,    96,    99,   -56,   157,   159,   162,   165,    61,
     -55,  -149,  -193,   -68,  -193,  -193,   -74,   183,   -23,  -192
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
     141,   141,    20,    46,    49,    46,   194,   195,   209,   210,
     168,   214,   215,   216,   217,   121,   169,    11,   157,   219,
     121,   122,   123,   124,   125,   189,    53,    49,   158,   190,
      12,   252,   120,   254,    55,    56,    57,    58,    59,    60,
      13,    21,   228,    50,    52,   143,   143,    14,    32,   118,
      23,     3,   211,    25,    16,    17,    18,    61,    26,   243,
      62,     1,     2,    34,   126,    27,    50,    28,    87,    63,
      52,     3,    64,   197,   165,   166,   142,   203,    65,   103,
      32,    66,   141,    13,   251,    89,    90,    54,    78,    79,
      14,    55,    56,    57,    58,    59,    60,    16,    17,    18,
      88,    95,   118,   118,   102,   118,   118,   118,   118,    97,
      98,   100,   145,   118,    61,   221,   106,    62,   107,   133,
      34,   148,   150,   153,   196,   152,    63,   205,   154,    64,
     253,   155,   156,   159,   160,    65,   161,   163,    66,   162,
     164,   134,   135,   136,   137,   138,   139,   167,   220,   170,
     171,   192,   176,   118,   172,    55,    56,    57,    58,    59,
      60,   180,   177,   179,    61,   173,   193,    62,   191,   178,
      34,   142,   269,   181,   182,   239,   277,   141,    61,    64,
     186,    62,   183,   184,    34,   185,   187,   188,   190,   200,
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
     238,    99,   304,    24,   297,   303,   306,   260,   310,   222,
     307,   262,   223,   204,     0,     0,     0,   225,   293,   224,
       0,     0,   101
};

static const yytype_int16 yycheck[] =
{
      23,    36,    82,    38,    78,    79,    79,    29,    63,    65,
      78,    79,     3,    36,    25,    38,   153,   154,   167,   168,
      44,   170,   171,   172,   173,     5,    50,     4,    42,   178,
       5,     6,     7,     8,     9,    44,    27,    48,    52,    48,
       4,   233,    64,   235,     4,     5,     6,     7,     8,     9,
       4,     0,   189,    25,    26,    78,    79,    11,    31,   114,
      39,    34,    42,    39,    18,    19,    20,    27,    39,   218,
      30,    24,    25,    33,    49,    45,    48,     4,     4,    39,
      52,    34,    42,    43,   106,   107,   160,   160,    48,    43,
      31,    51,   160,     4,   231,    37,    38,    42,    42,    42,
      11,     4,     5,     6,     7,     8,     9,    18,    19,    20,
       4,    40,   167,   168,    46,   170,   171,   172,   173,    41,
      40,    40,     4,   178,    27,   181,    42,    30,    42,    41,
      33,     4,     4,     4,   156,    45,    39,   160,     4,    42,
      43,    41,    47,    42,    42,    48,    41,    43,    51,    41,
       4,     4,     5,     6,     7,     8,     9,    44,   180,    44,
      44,   152,    40,   218,    44,     4,     5,     6,     7,     8,
       9,    26,    40,    40,    27,    44,     4,    30,    48,    44,
      33,   255,   255,    44,    44,   207,   266,   255,    27,    42,
      49,    30,    44,    44,    33,    44,    43,    43,    48,     4,
      39,    32,    44,    42,    44,   279,    43,     5,    44,    48,
     245,    44,    51,     4,     5,     6,     7,     8,     9,     6,
       8,   256,   245,     4,     5,     6,     7,     8,     9,     7,
       9,     5,   255,   256,     4,     5,     6,     7,     8,     9,
       5,    44,    13,    14,    46,    41,     4,    44,    39,    40,
      21,    43,    42,   288,   289,   290,     5,    43,    39,    40,
      31,    32,    33,     4,    35,   288,   289,   290,    39,    39,
      11,    12,    41,   308,    11,    41,    43,    18,    19,    20,
      39,    18,    19,    20,    39,   308,    49,    24,    25,    49,
      47,    39,    43,     5,    44,     5,    22,    44,    43,     5,
      40,     5,    48,    23,     5,    41,    50,    50,    40,    43,
      15,    42,    50,    42,    44,    50,    49,    39,    39,    44,
      39,    30,     4,    41,    40,    40,    40,     6,    39,    42,
     206,    48,    40,    10,   291,   300,    43,   241,    40,   182,
      43,   242,   183,   160,    -1,    -1,    -1,   185,   287,   184,
      -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    25,    34,    54,    55,    56,    57,    60,    62,
      63,     4,     4,     4,    11,    12,    18,    19,    20,    64,
      66,     0,    55,    39,    67,    39,    39,    45,     4,    13,
      14,    21,    31,    32,    33,    35,    67,    68,    69,    70,
      71,    76,    77,    82,    85,   110,   111,    58,    59,    62,
      77,    61,    77,    66,    42,     4,     5,     6,     7,     8,
       9,    27,    30,    39,    42,    48,    51,    90,    91,    92,
      94,   103,   105,   106,   107,   108,   109,   111,    42,    42,
      11,    18,    19,    20,    24,    25,    78,     4,     4,    37,
      38,    72,    73,    74,    68,    40,    68,    41,    40,    58,
      40,    61,    46,    43,    65,    66,    42,    42,     4,     5,
       6,     7,     8,     9,    39,    40,    95,    96,   103,   104,
      90,     5,     6,     7,     8,     9,    49,    93,    97,    98,
      99,   100,   101,    41,     4,     5,     6,     7,     8,     9,
      89,   106,   109,   111,    89,     4,    79,    81,     4,    80,
       4,    79,    45,     4,     4,    41,    47,    42,    52,    42,
      42,    41,    41,    43,     4,    90,    90,    44,    44,    50,
      44,    44,    44,    44,     5,    40,    40,    40,    44,    40,
      26,    44,    44,    44,    44,    44,    49,    43,    43,    44,
      48,    48,    66,     4,    81,    81,    90,    43,    90,   112,
       4,    32,    75,    89,   110,   111,    44,    44,    43,   104,
     104,    42,    97,   102,   104,   104,   104,   104,    44,   104,
      90,    97,    98,    99,   101,   100,    83,    86,    81,     5,
       5,    46,    41,    44,    43,    42,     4,    43,    65,    90,
       5,    41,    41,   104,    43,    39,    84,    39,    87,    49,
      49,    81,   112,    43,   112,    47,    39,    43,    44,     5,
      95,     5,    96,    68,    22,    88,    44,    48,    43,    89,
      68,     5,    50,    50,    40,     5,    23,    79,     5,    41,
      40,    43,    15,    50,    50,    49,   109,    44,    39,    39,
      39,    44,    41,   102,    68,    68,    68,    80,    30,    40,
      40,    40,    42,    88,    40,     4,    43,    43,    39,    68,
      40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      70,    71,    72,    72,    73,    74,    75,    75,    76,    77,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    83,    82,    84,    84,    86,    85,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   105,   106,
     106,   107,   108,   109,   110,   111,   111,   111,   111,   112,
     112
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
#line 88 "parser.y"
                                                                           {fprintf(fparse, " : CLASS DEFINITION");}
#line 1546 "y.tab.c"
    break;

  case 13: /* struct: STRUCT id '{' struct_items '}' ';'  */
#line 99 "parser.y"
                                                                             {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1552 "y.tab.c"
    break;

  case 17: /* function_head: FUNC fdtype id '(' ')'  */
#line 109 "parser.y"
                                                         {fprintf(fparse, " : FUNCTION HEAD");}
#line 1558 "y.tab.c"
    break;

  case 18: /* function_head: FUNC fdtype id '(' param_list ')'  */
#line 110 "parser.y"
                                                                                    {fprintf(fparse, " : FUNCTION HEAD");}
#line 1564 "y.tab.c"
    break;

  case 40: /* return_stmt: RETURN RHS ';'  */
#line 145 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 1570 "y.tab.c"
    break;

  case 41: /* loop_stmt: LOOP loop_type  */
#line 147 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 1576 "y.tab.c"
    break;

  case 48: /* expr_stmt: EXPR id '=' RHS ';'  */
#line 163 "parser.y"
                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 1582 "y.tab.c"
    break;

  case 49: /* declr_stmt: DECLR declr_body ';'  */
#line 166 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 1588 "y.tab.c"
    break;

  case 63: /* $@1: %empty  */
#line 189 "parser.y"
                                                              {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1594 "y.tab.c"
    break;

  case 67: /* $@2: %empty  */
#line 196 "parser.y"
                                                                  {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 1600 "y.tab.c"
    break;

  case 144: /* call_stmt: func_calls ';'  */
#line 322 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 1606 "y.tab.c"
    break;


#line 1610 "y.tab.c"

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

#line 335 "parser.y"


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




