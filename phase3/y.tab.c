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
	#include "symbol_table.c"
	extern int yylineno;
	extern FILE* yyin, *yyout;
    FILE* fparse;
	int yylex(void);
	int yyerror(const char *s);
	
	// flags
	int inClass=0;
	int level=0;  // indicates level of scope
	int inFunc=0;
	int currentFuncIndex; // to be used only at the beginning of the function (right after the funciton head)

#line 89 "y.tab.c"

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
union YYSTYPE
{
#line 19 "parser.y"

	char* str;
	struct{
		int level;
	} level;
	struct{
		char* name;
		char* type;
	} details;
	

#line 266 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_models = 73,                    /* models  */
  YYSYMBOL_model = 74,                     /* model  */
  YYSYMBOL_class = 75,                     /* class  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_77_3 = 77,                      /* $@3  */
  YYSYMBOL_id = 78,                        /* id  */
  YYSYMBOL_class_items = 79,               /* class_items  */
  YYSYMBOL_class_item = 80,                /* class_item  */
  YYSYMBOL_struct = 81,                    /* struct  */
  YYSYMBOL_82_4 = 82,                      /* $@4  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_struct_items = 84,              /* struct_items  */
  YYSYMBOL_function = 85,                  /* function  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_function_head = 87,             /* function_head  */
  YYSYMBOL_func_definition = 88,           /* func_definition  */
  YYSYMBOL_Parameters = 89,                /* Parameters  */
  YYSYMBOL_90_7 = 90,                      /* $@7  */
  YYSYMBOL_fdtype = 91,                    /* fdtype  */
  YYSYMBOL_param_list = 92,                /* param_list  */
  YYSYMBOL_dtype = 93,                     /* dtype  */
  YYSYMBOL_function_body = 94,             /* function_body  */
  YYSYMBOL_95_8 = 95,                      /* $@8  */
  YYSYMBOL_statements = 96,                /* statements  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL_unary_stmt = 98,                /* unary_stmt  */
  YYSYMBOL_jump_stmt = 99,                 /* jump_stmt  */
  YYSYMBOL_label_stmt = 100,               /* label_stmt  */
  YYSYMBOL_goto_stmt = 101,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 102,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 103,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 104,              /* remove_body  */
  YYSYMBOL_vect_append = 105,              /* vect_append  */
  YYSYMBOL_return_stmt = 106,              /* return_stmt  */
  YYSYMBOL_loop_stmt = 107,                /* loop_stmt  */
  YYSYMBOL_loop_type = 108,                /* loop_type  */
  YYSYMBOL_for_loop = 109,                 /* for_loop  */
  YYSYMBOL_for_expr = 110,                 /* for_expr  */
  YYSYMBOL_while_loop = 111,               /* while_loop  */
  YYSYMBOL_expr_stmt = 112,                /* expr_stmt  */
  YYSYMBOL_LHS = 113,                      /* LHS  */
  YYSYMBOL_declr_stmt = 114,               /* declr_stmt  */
  YYSYMBOL_declr_body = 115,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 116,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 117,              /* matrix_list  */
  YYSYMBOL_id_list = 118,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 119,              /* ifcond_stmt  */
  YYSYMBOL_120_9 = 120,                    /* $@9  */
  YYSYMBOL_if_body = 121,                  /* if_body  */
  YYSYMBOL_switch_stmt = 122,              /* switch_stmt  */
  YYSYMBOL_123_10 = 123,                   /* $@10  */
  YYSYMBOL_switch_body = 124,              /* switch_body  */
  YYSYMBOL_125_11 = 125,                   /* $@11  */
  YYSYMBOL_cases = 126,                    /* cases  */
  YYSYMBOL_RHS = 127,                      /* RHS  */
  YYSYMBOL_constants = 128,                /* constants  */
  YYSYMBOL_extra_consts = 129,             /* extra_consts  */
  YYSYMBOL_array_const = 130,              /* array_const  */
  YYSYMBOL_val_list = 131,                 /* val_list  */
  YYSYMBOL_resultant = 132,                /* resultant  */
  YYSYMBOL_impr = 133,                     /* impr  */
  YYSYMBOL_graph_impr = 134,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 135,              /* matrix_impr  */
  YYSYMBOL_matr_body = 136,                /* matr_body  */
  YYSYMBOL_graph_const = 137,              /* graph_const  */
  YYSYMBOL_graph_type1 = 138,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 139,              /* graph_type2  */
  YYSYMBOL_int_list = 140,                 /* int_list  */
  YYSYMBOL_float_list = 141,               /* float_list  */
  YYSYMBOL_char_list = 142,                /* char_list  */
  YYSYMBOL_bool_list = 143,                /* bool_list  */
  YYSYMBOL_str_list = 144,                 /* str_list  */
  YYSYMBOL_weight_list = 145,              /* weight_list  */
  YYSYMBOL_vect_const = 146,               /* vect_const  */
  YYSYMBOL_vect_list = 147,                /* vect_list  */
  YYSYMBOL_matrix_const = 148,             /* matrix_const  */
  YYSYMBOL_int_float_list = 149,           /* int_float_list  */
  YYSYMBOL_mat_list = 150,                 /* mat_list  */
  YYSYMBOL_arith_op = 151,                 /* arith_op  */
  YYSYMBOL_binary_op = 152,                /* binary_op  */
  YYSYMBOL_unary_op = 153,                 /* unary_op  */
  YYSYMBOL_logical_op = 154,               /* logical_op  */
  YYSYMBOL_call_stmt = 155,                /* call_stmt  */
  YYSYMBOL_func_calls = 156,               /* func_calls  */
  YYSYMBOL_arg_list = 157                  /* arg_list  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   894

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  451

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
       0,    92,    92,    92,    95,    96,    99,   100,   101,   104,
     104,   104,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     127,   128,   131,   132,   135,   135,   135,   138,   139,   142,
     142,   155,   158,   165,   166,   166,   170,   171,   174,   175,
     178,   179,   180,   181,   189,   192,   192,   199,   202,   203,
     204,   205,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   222,   225,   226,   229,   232,   235,
     238,   239,   240,   241,   245,   246,   247,   248,   249,   250,
     251,   255,   256,   259,   260,   261,   262,   263,   264,   268,
     271,   272,   275,   278,   279,   280,   281,   282,   283,   284,
     287,   290,   291,   292,   293,   294,   297,   298,   301,   303,
     304,   305,   306,   307,   308,   309,   312,   313,   316,   317,
     320,   321,   324,   324,   327,   328,   331,   331,   334,   334,
     337,   338,   342,   343,   344,   345,   346,   350,   351,   352,
     353,   354,   355,   359,   360,   361,   362,   363,   367,   368,
     371,   372,   373,   374,   375,   378,   379,   380,   381,   382,
     385,   386,   387,   388,   389,   390,   391,   396,   397,   398,
     399,   403,   404,   405,   408,   409,   412,   413,   416,   417,
     420,   421,   424,   425,   428,   429,   432,   433,   436,   437,
     440,   441,   444,   445,   446,   447,   450,   453,   454,   455,
     456,   459,   462,   463,   464,   465,   468,   469,   472,   473,
     476,   479,   482,   483,   486,   489,   490,   493,   494
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
  "$@1", "models", "model", "class", "$@2", "$@3", "id", "class_items",
  "class_item", "struct", "$@4", "$@5", "struct_items", "function", "$@6",
  "function_head", "func_definition", "Parameters", "$@7", "fdtype",
  "param_list", "dtype", "function_body", "$@8", "statements", "statement",
  "unary_stmt", "jump_stmt", "label_stmt", "goto_stmt", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "while_loop",
  "expr_stmt", "LHS", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@9", "if_body", "switch_stmt",
  "$@10", "switch_body", "$@11", "cases", "RHS", "constants",
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

#define YYPACT_NINF (-335)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -335,    20,    62,  -335,   367,   367,   762,  -335,    62,  -335,
    -335,  -335,  -335,   -32,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,   -19,   -14,  -335,  -335,  -335,  -335,    15,  -335,
     367,  -335,  -335,     2,     8,  -335,  -335,  -335,   810,  -335,
      17,  -335,  -335,   810,    -3,    52,    32,  -335,   707,    65,
     367,    96,    69,    -3,  -335,  -335,    75,    52,  -335,   274,
      74,    76,    77,    78,    79,   367,   367,    11,    80,    81,
      83,   367,     6,   707,    86,   707,  -335,  -335,  -335,  -335,
    -335,    91,  -335,  -335,  -335,  -335,  -335,  -335,  -335,    71,
    -335,  -335,  -335,    93,  -335,    97,  -335,    85,   367,   367,
     367,    94,   367,   367,   101,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,   102,   104,   106,   454,   624,    60,
     157,   109,    95,   111,  -335,   113,  -335,   110,   121,   124,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,   624,  -335,
    -335,   624,   624,   100,   125,   141,   142,  -335,  -335,  -335,
     624,   624,   624,   144,   367,     2,  -335,  -335,  -335,  -335,
     152,  -335,  -335,   810,    49,  -335,  -335,   116,  -335,   143,
    -335,   810,   367,   367,  -335,   151,   154,   624,   624,  -335,
     149,  -335,  -335,   153,   156,   162,   163,   164,  -335,   197,
     165,   166,   168,   169,   170,    88,  -335,   155,  -335,  -335,
    -335,  -335,  -335,   167,  -335,  -335,  -335,  -335,  -335,   172,
     173,   176,   396,   565,   194,   624,   177,   178,  -335,   160,
     180,  -335,  -335,  -335,   183,   184,   187,   189,   192,   196,
     199,   205,   207,   208,   210,   212,   213,   216,   223,  -335,
     367,   234,   253,   220,   225,  -335,  -335,  -335,  -335,   228,
     230,    12,   510,   510,  -335,  -335,  -335,   624,   288,   290,
     287,   289,   292,   235,   236,   241,  -335,  -335,  -335,  -335,
    -335,   245,   246,   252,   273,   276,  -335,   275,   280,    -9,
     282,   624,   624,   624,   396,   654,   283,   284,   285,   654,
     286,   293,   654,   294,   654,   295,   296,   654,   654,  -335,
     267,   297,   367,   624,  -335,   347,   299,   303,  -335,  -335,
     302,  -335,  -335,  -335,  -335,  -335,    88,    88,   306,     2,
     312,  -335,  -335,  -335,  -335,  -335,   624,  -335,   313,     2,
     310,   314,   315,   317,  -335,  -335,  -335,  -335,   318,    95,
     110,  -335,  -335,  -335,  -335,  -335,  -335,   320,  -335,  -335,
     322,  -335,   291,  -335,  -335,   311,   323,   324,   316,  -335,
     327,   328,   370,   385,  -335,  -335,  -335,   325,   377,  -335,
    -335,  -335,  -335,    26,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,   654,   654,   654,   367,   390,  -335,   108,   330,
    -335,   353,  -335,  -335,     2,   404,   367,   366,  -335,   369,
     371,   372,  -335,   362,   391,   393,   288,   395,  -335,   459,
     442,   399,     2,  -335,  -335,  -335,   405,   406,   407,   408,
     409,   839,  -335,   367,   395,   395,     2,     2,   410,   110,
     411,   160,  -335,  -335,  -335,  -335,  -335,   404,   412,  -335,
    -335
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     3,     5,     7,
       8,     6,    39,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    24,    26,    27,
      28,    29,     0,     0,    50,    47,    51,    52,     0,    54,
       0,    46,     4,     0,    44,    41,     9,    34,     0,    42,
      55,    40,    43,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,    31,    33,    32,     0,    38,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    24,
       0,     0,   116,    61,     0,    59,    70,    67,    75,    76,
      71,   168,    69,    68,    62,   165,    64,    65,    66,     0,
     169,   167,   166,     0,    63,     0,    45,    49,     0,     0,
       0,     0,     0,     0,     0,    10,    30,    35,    37,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
     116,   168,   152,     0,   142,     0,   153,   146,   167,   166,
     154,   155,   156,   143,   218,   219,   144,   145,     0,    73,
      72,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,    60,    56,    58,    79,
       0,    74,   224,     0,   131,   123,   119,     0,   122,     0,
     120,     0,     0,     0,   118,     0,     0,     0,     0,    98,
     147,   157,   152,   208,   210,     0,     0,     0,   168,     0,
     193,   195,   197,   201,   199,     0,   159,     0,   160,   161,
     162,   163,   164,     0,    97,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
       0,    78,   117,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,   131,   125,   124,    11,    36,     0,
       0,     0,     0,     0,   186,   187,   206,     0,     0,     0,
       0,     0,     0,   214,   215,     0,   158,   211,   132,   136,
     221,   168,     0,     0,   167,   166,   226,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,     0,   223,     0,     0,     0,   207,   209,
       0,   192,   194,   196,   200,   198,     0,     0,     0,     0,
       0,   115,   111,   112,   113,   114,     0,   225,     0,     0,
       0,     0,     0,     0,    91,    92,    84,    85,     0,    86,
      90,    88,    89,    87,   170,    82,    83,     0,   182,   172,
       0,   173,     0,   183,   178,     0,     0,   127,     0,   121,
       0,     0,   189,   191,   222,   212,   213,   217,   135,   133,
     138,   137,   227,     0,   110,   174,   176,   181,    80,    81,
     171,   177,     0,     0,     0,     0,     0,   220,     0,     0,
     188,     0,   190,   216,     0,     0,     0,     0,   103,     0,
       0,     0,   126,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,   175,   179,   180,   129,   203,   205,     0,
       0,     0,   102,     0,     0,     0,     0,     0,   108,   106,
     107,   109,   104,   105,   128,   202,   204,   141,     0,   140,
     139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,   463,  -335,  -335,  -335,  -335,    -4,   415,
    -335,  -335,  -335,  -335,   413,   -37,  -335,  -335,  -335,  -335,
    -335,  -335,   308,     5,   -40,  -335,   -25,  -335,  -335,  -335,
    -335,  -335,  -335,   -51,  -262,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,   248,   -54,     7,  -335,  -101,    42,  -159,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,    35,    -6,  -114,   -59,
    -335,  -335,  -335,   -44,   -63,   -64,   186,  -335,   112,   114,
    -117,   214,   215,   217,   219,  -334,  -335,  -144,  -335,  -203,
     128,  -219,  -335,   -50,  -205,  -335,   -33,   150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    54,   185,   130,    62,
      63,    10,    55,   186,    66,    11,    43,    12,    13,    45,
      53,    40,    59,    60,    83,    58,    84,    85,    86,    87,
      88,    89,    90,   198,   348,   343,    92,    93,   157,   158,
     407,   159,    94,   132,    96,   114,   175,   178,   176,    97,
     329,   379,    98,   330,   381,   405,   420,   228,   134,   194,
     136,   207,    99,   137,   101,   102,   230,   140,   195,   196,
     316,   209,   210,   211,   212,   317,   141,   197,   142,   275,
     213,   143,   144,   145,   146,   104,   147,   288
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    33,    39,    51,    95,   139,   138,    91,   103,   180,
     135,    41,   208,   193,   100,   164,   200,    64,   131,   125,
       3,   153,   154,   255,   256,   105,    64,    61,    44,    95,
       6,    95,    91,   103,    91,   103,    49,   357,    46,   100,
     360,   100,   362,    47,    39,   365,   366,   155,   156,    39,
     105,   128,   105,    56,    82,    74,   107,   406,   166,    50,
     168,    65,    67,   133,   200,   201,   202,   203,   204,    52,
      65,   165,   315,   192,    67,    57,   351,   163,    48,    82,
     351,    82,    61,   351,   338,   351,     4,     5,   351,   351,
     352,   309,   273,   274,   352,     6,    68,   352,   229,   352,
     445,   446,   352,   352,   174,   177,   179,   108,   182,   183,
     232,   250,   414,   415,   109,   110,   111,   251,   318,   319,
     112,   113,   199,   375,   376,   233,   106,   115,   205,   206,
     409,   410,   411,   117,   148,   149,   150,   170,   151,   152,
     160,   161,   219,   162,   167,   220,   221,   173,   193,   193,
     169,   321,   171,   369,   226,   227,   172,   181,   285,   284,
     184,  -165,   187,   283,   188,   189,   164,   222,   214,    39,
     215,   281,   216,   351,   351,   351,  -169,    39,   254,   254,
     217,   259,   260,   218,   252,   223,   253,   352,   352,   352,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   224,   225,   231,   245,   246,   247,   248,   192,   192,
     257,   251,   442,   258,   261,   262,   282,   287,   263,   290,
     264,   265,   266,   267,   276,    75,  -166,   268,   269,   229,
     270,   271,   272,   278,   279,   345,   277,   280,   310,   291,
     292,   349,   293,   294,   295,   349,   254,   296,   349,   297,
     349,   350,   298,   349,   349,   350,   299,   311,   350,   300,
     350,   320,   353,   350,   350,   301,   353,   302,   303,   353,
     304,   353,   305,   306,   353,   353,   307,    14,   119,   120,
     121,   122,   123,   308,   312,   340,   341,   250,   344,   378,
     313,   314,   200,   202,   412,   201,   203,   326,   327,   384,
     204,   124,   125,    74,   331,   332,    76,   370,   254,   126,
     328,   333,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    78,    79,    80,    28,    29,    30,    31,
     287,   127,   334,   408,   128,   335,   367,   336,   349,   349,
     349,   337,   129,   339,   354,   355,   356,   358,   350,   350,
     350,   371,   421,   392,   359,   361,   363,   364,   372,   353,
     353,   353,   373,   374,   418,   377,   368,   441,   440,   380,
      14,   385,   383,   393,   399,   386,   387,    95,   388,   389,
     438,   390,   432,   391,   396,   394,   395,   439,   397,   401,
     398,   179,   404,   205,   413,   416,   447,   448,   443,    14,
     119,   120,   121,   122,   123,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   417,    28,
      29,    30,    31,   124,   125,    74,   419,   422,    76,   177,
     423,   426,   424,   425,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    78,    79,    80,    28,    29,
      30,    31,   427,   127,   428,   315,   128,    14,   190,   120,
     121,   122,   123,   429,   129,   430,   431,   433,   434,   435,
     450,    42,   289,   436,   437,   444,  -168,  -167,   116,   342,
     118,   249,   449,   322,   400,   323,   382,   402,     0,   325,
     324,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   403,    28,    29,    30,    31,
       0,   127,   191,    14,   119,   120,   121,   122,   123,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,   127,    14,   119,
     120,   121,   122,   123,     0,     0,     0,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,    74,     0,     0,    76,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    78,    79,    80,    28,    29,    30,
      31,     0,     0,     0,     0,   128,   286,    14,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,    74,     0,     0,    76,    14,   346,   347,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    78,    79,    80,    28,    29,    30,    31,
       0,   124,   125,    74,   128,     0,    76,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    78,    79,    80,    28,    29,    30,    31,
      14,     0,     0,     0,   128,     0,     0,     0,     0,     0,
      69,    70,     0,    71,    72,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,    74,    61,    75,    76,
       0,    77,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    78,    79,    80,    28,
      29,    30,    31,    81,    50,    14,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    14,    28,    29,    30,    31,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,   124,     0,    74,     0,
       0,    76,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    78,    79,
      80,    28,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,    43,    58,    69,    69,    58,    58,   110,
      69,     6,   129,   127,    58,     9,     4,    54,    69,    28,
       0,    75,    76,   182,   183,    58,    63,    30,    60,    83,
      33,    85,    83,    83,    85,    85,    40,   299,    57,    83,
     302,    85,   304,    57,    48,   307,   308,    36,    37,    53,
      83,    60,    85,    48,    58,    29,    60,    31,    83,    57,
      85,    54,    55,    69,     4,     5,     6,     7,     8,    61,
      63,    65,    60,   127,    67,    58,   295,    81,    63,    83,
     299,    85,    30,   302,   289,   304,    24,    25,   307,   308,
     295,   250,     4,     5,   299,    33,    64,   302,   162,   304,
     434,   435,   307,   308,   108,   109,   110,    11,   112,   113,
     164,    62,     4,     5,    18,    19,    20,    68,   262,   263,
      24,    25,   128,   326,   327,   165,    61,    58,    68,    69,
     392,   393,   394,    58,    60,    59,    59,    66,    60,    60,
      60,    60,   148,    60,    58,   151,   152,    62,   262,   263,
      59,   268,    59,   312,   160,   161,    59,    63,   222,   222,
      59,    66,    60,   222,    60,    59,     9,    67,    59,   173,
      59,   222,    59,   392,   393,   394,    66,   181,   182,   183,
      59,   187,   188,    59,    68,    60,   181,   392,   393,   394,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    60,    60,    59,    52,    53,    54,    55,   262,   263,
      59,    68,   431,    59,    65,    62,   222,   223,    62,   225,
      58,    58,    58,    26,    69,    31,    66,    62,    62,   293,
      62,    62,    62,    61,    61,   294,    69,    61,     4,    62,
      62,   295,    62,    60,    60,   299,   250,    60,   302,    60,
     304,   295,    60,   307,   308,   299,    60,     4,   302,    60,
     304,   267,   295,   307,   308,    60,   299,    60,    60,   302,
      60,   304,    60,    60,   307,   308,    60,     3,     4,     5,
       6,     7,     8,    60,    64,   291,   292,    62,   294,   329,
      62,    61,     4,     6,   395,     5,     7,    62,    62,   339,
       8,    27,    28,    29,    59,    59,    32,   313,   312,    35,
      69,    59,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
     336,    57,    59,   383,    60,    59,    69,    62,   392,   393,
     394,    61,    68,    61,    61,    61,    61,    61,   392,   393,
     394,     4,   406,    62,    61,    61,    61,    61,    59,   392,
     393,   394,    59,    61,   404,    59,    69,   431,   431,    57,
       3,    61,    59,    62,     4,    61,    61,   431,    61,    61,
     431,    61,   422,    61,    68,    62,    62,   431,    61,     4,
      62,   395,    15,    68,     4,    65,   436,   437,   431,     3,
       4,     5,     6,     7,     8,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    65,    52,
      53,    54,    55,    27,    28,    29,    22,    61,    32,   433,
      61,    69,    61,    61,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    61,    57,    61,    60,    60,     3,     4,     5,
       6,     7,     8,     4,    68,    23,    67,    62,    62,    62,
      58,     8,   224,    65,    65,   433,    66,    66,    63,   293,
      67,   173,   447,   269,   372,   270,   336,   373,    -1,   272,
     271,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   377,    52,    53,    54,    55,
      -1,    57,    58,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,     3,     4,     5,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    27,    28,    29,    60,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       3,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    16,    17,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     3,    52,    53,    54,    55,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    27,    -1,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    72,     0,    24,    25,    33,    73,    74,    75,
      81,    85,    87,    88,     3,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    55,    78,    78,    11,    12,    18,    19,    20,    78,
      91,    93,    73,    86,    60,    89,    57,    57,    63,    78,
      57,    94,    61,    90,    76,    82,    93,    58,    95,    92,
      93,    30,    79,    80,    85,   114,    84,   114,    64,    13,
      14,    16,    17,    21,    29,    31,    32,    34,    49,    50,
      51,    56,    78,    94,    96,    97,    98,    99,   100,   101,
     102,   103,   106,   107,   112,   113,   114,   119,   122,   132,
     133,   134,   135,   153,   155,   156,    61,    78,    11,    18,
      19,    20,    24,    25,   115,    58,    79,    58,    84,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    68,
      78,   103,   113,   127,   128,   129,   130,   133,   134,   135,
     137,   146,   148,   151,   152,   153,   154,   156,    60,    59,
      59,    60,    60,   113,   113,    36,    37,   108,   109,   111,
      60,    60,    60,    78,     9,    65,    96,    58,    96,    59,
      66,    59,    59,    62,    78,   116,   118,    78,   117,    78,
     116,    63,    78,    78,    59,    77,    83,    60,    60,    59,
       4,    58,   113,   128,   129,   138,   139,   147,   103,   127,
       4,     5,     6,     7,     8,    68,    69,   131,   140,   141,
     142,   143,   144,   150,    59,    59,    59,    59,    59,   127,
     127,   127,    67,    60,    60,    60,   127,   127,   127,   135,
     136,    59,   113,    94,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    52,    53,    54,    55,    92,
      62,    68,    68,    93,    78,   118,   118,    59,    59,   127,
     127,    65,    62,    62,    58,    58,    58,    26,    62,    62,
      62,    62,    62,     4,     5,   149,    69,    69,    61,    61,
      61,   103,   127,   129,   134,   135,    61,   127,   157,   112,
     127,    62,    62,    62,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,   118,
       4,     4,    64,    62,    61,    60,   140,   145,   147,   147,
     127,   140,   141,   142,   144,   143,    62,    62,    69,   120,
     123,    59,    59,    59,    59,    59,    62,    61,   154,    61,
     127,   127,   136,   105,   127,   129,     4,     5,   104,   113,
     133,   151,   154,   156,    61,    61,    61,   104,    61,    61,
     104,    61,   104,    61,    61,   104,   104,    69,    69,   118,
     127,     4,    59,    59,    61,   149,   149,    59,    94,   121,
      57,   124,   157,    59,    94,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    68,    61,    62,     4,
     138,     4,   139,   150,    15,   125,    31,   110,   153,   104,
     104,   104,   116,     4,     4,     5,    65,    65,    94,    22,
     126,   113,    61,    61,    61,    61,    69,    61,    61,     4,
      23,    67,    94,    62,    62,    62,    65,    65,   103,   133,
     134,   135,   151,   156,   117,   145,   145,    94,    94,   126,
      58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    72,    71,    73,    73,    74,    74,    74,    76,
      77,    75,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    82,    83,    81,    84,    84,    86,
      85,    87,    88,    89,    90,    89,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    95,    94,    94,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    99,    99,   100,   101,   102,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   107,
     108,   108,   109,   110,   110,   110,   110,   110,   110,   110,
     111,   112,   112,   112,   112,   112,   113,   113,   114,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   120,   119,   121,   121,   123,   122,   125,   124,
     126,   126,   127,   127,   127,   127,   127,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   130,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   145,   146,   147,   147,   147,
     147,   148,   149,   149,   149,   149,   150,   150,   151,   151,
     152,   153,   154,   154,   155,   156,   156,   157,   157
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     0,
       0,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     0,     8,     2,     1,     0,
       3,     2,     3,     2,     0,     4,     1,     1,     4,     2,
       1,     1,     1,     4,     1,     0,     4,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     3,     3,     2,
       6,     6,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     8,     1,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     5,     5,     5,     1,     3,     3,     2,
       2,     5,     2,     2,     3,     3,     6,     4,     9,     7,
       3,     1,     0,     6,     3,     1,     0,     6,     0,     7,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     6,     5,     5,     6,     8,     6,     6,     5,     8,
       8,     6,     5,     5,     1,     1,     3,     3,     5,     4,
       5,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     7,     5,     7,     5,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     1,     5,     4,     1,     1,
       6,     4,     5,     4,     2,     5,     4,     3,     1
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
  case 2: /* $@1: %empty  */
#line 92 "parser.y"
                                 {reset();}
#line 1813 "y.tab.c"
    break;

  case 3: /* program_unit: $@1 models  */
#line 92 "parser.y"
                                                   {reset();}
#line 1819 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 104 "parser.y"
                                                       {level++;}
#line 1825 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 104 "parser.y"
                                                                                  {level--;}
#line 1831 "y.tab.c"
    break;

  case 11: /* class: CLASS id '{' $@2 class_items '}' $@3 ';'  */
#line 104 "parser.y"
                                                                                                 {fprintf(fparse, " : CLASS DEFINITION");}
#line 1837 "y.tab.c"
    break;

  case 12: /* id: newid  */
#line 107 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1843 "y.tab.c"
    break;

  case 13: /* id: APPEND  */
#line 108 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1849 "y.tab.c"
    break;

  case 14: /* id: REMOVE  */
#line 109 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1855 "y.tab.c"
    break;

  case 15: /* id: LENGTH  */
#line 110 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1861 "y.tab.c"
    break;

  case 16: /* id: SORT  */
#line 111 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1867 "y.tab.c"
    break;

  case 17: /* id: CLEAR  */
#line 112 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1873 "y.tab.c"
    break;

  case 18: /* id: AT  */
#line 113 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1879 "y.tab.c"
    break;

  case 19: /* id: TRANSPOSE  */
#line 114 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1885 "y.tab.c"
    break;

  case 20: /* id: TRACE  */
#line 115 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1891 "y.tab.c"
    break;

  case 21: /* id: TRAVERSAL  */
#line 116 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1897 "y.tab.c"
    break;

  case 22: /* id: STRLEN  */
#line 117 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1903 "y.tab.c"
    break;

  case 23: /* id: STRCUT  */
#line 118 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1909 "y.tab.c"
    break;

  case 24: /* id: STRJOIN  */
#line 119 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1915 "y.tab.c"
    break;

  case 25: /* id: STRCMP  */
#line 120 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1921 "y.tab.c"
    break;

  case 26: /* id: MAXTOGR  */
#line 121 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1927 "y.tab.c"
    break;

  case 27: /* id: GRTOMATX  */
#line 122 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1933 "y.tab.c"
    break;

  case 28: /* id: SHPATH  */
#line 123 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1939 "y.tab.c"
    break;

  case 29: /* id: SHPATHVAL  */
#line 124 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1945 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 135 "parser.y"
                                                       {level++;}
#line 1951 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 135 "parser.y"
                                                                                   {level--;}
#line 1957 "y.tab.c"
    break;

  case 36: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 135 "parser.y"
                                                                                                 {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1963 "y.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 142 "parser.y"
                                                        {

							// inFunc = 0 indicates reading the function for the first time
							if(inFunc==0) currentFuncIndex = func_search((yyvsp[0].details).name); 
							if(level) func_set(-1, var_size, currentFuncIndex);
						}
#line 1974 "y.tab.c"
    break;

  case 40: /* function: function_head $@6 function_body  */
#line 148 "parser.y"
                                                              {
							func_delete(func_search((yyvsp[-2].details).name));
							printFuncDetails(currentFuncIndex);
							inFunc=0;
						}
#line 1984 "y.tab.c"
    break;

  case 41: /* function_head: func_definition Parameters  */
#line 155 "parser.y"
                                                             { (yyval.details)=(yyvsp[-1].details); fprintf(fparse, " : FUNCTION HEAD");}
#line 1990 "y.tab.c"
    break;

  case 42: /* func_definition: FUNC fdtype id  */
#line 158 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							func_insert((yyvsp[0].str), (yyvsp[-1].str));
						}
#line 2000 "y.tab.c"
    break;

  case 44: /* $@7: %empty  */
#line 166 "parser.y"
                                                      {level++;}
#line 2006 "y.tab.c"
    break;

  case 45: /* Parameters: '(' $@7 param_list ')'  */
#line 166 "parser.y"
                                                                               {level--;}
#line 2012 "y.tab.c"
    break;

  case 46: /* fdtype: dtype  */
#line 170 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2018 "y.tab.c"
    break;

  case 47: /* fdtype: VOID  */
#line 171 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2024 "y.tab.c"
    break;

  case 48: /* param_list: dtype id ',' param_list  */
#line 174 "parser.y"
                                                                  {add_args((yyvsp[-3].str));}
#line 2030 "y.tab.c"
    break;

  case 49: /* param_list: dtype id  */
#line 175 "parser.y"
                                                           {add_args((yyvsp[-1].str));}
#line 2036 "y.tab.c"
    break;

  case 50: /* dtype: DATATYPE  */
#line 178 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2042 "y.tab.c"
    break;

  case 51: /* dtype: MATRIX  */
#line 179 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str);}
#line 2048 "y.tab.c"
    break;

  case 52: /* dtype: GRAPH  */
#line 180 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str);}
#line 2054 "y.tab.c"
    break;

  case 53: /* dtype: VECT '<' dtype '>'  */
#line 181 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    (yyval.str) = result;
						}
#line 2067 "y.tab.c"
    break;

  case 54: /* dtype: id  */
#line 189 "parser.y"
                                                     {(yyval.str) = (yyvsp[0].str);}
#line 2073 "y.tab.c"
    break;

  case 55: /* $@8: %empty  */
#line 192 "parser.y"
                                      {
								level++; 
								if(inFunc==0) {
									inFunc=0;
									func_set(var_size, -1, currentFuncIndex);
								} 
						}
#line 2085 "y.tab.c"
    break;

  case 56: /* function_body: '{' $@8 statements '}'  */
#line 198 "parser.y"
                                                                 {var_delete(); level--;}
#line 2091 "y.tab.c"
    break;

  case 72: /* statement: BREAK ';'  */
#line 218 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2097 "y.tab.c"
    break;

  case 73: /* statement: CONTINUE ';'  */
#line 219 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2103 "y.tab.c"
    break;

  case 74: /* unary_stmt: unary_op ';'  */
#line 222 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2109 "y.tab.c"
    break;

  case 77: /* label_stmt: id ':' function_body  */
#line 229 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 2115 "y.tab.c"
    break;

  case 78: /* goto_stmt: GOTO id ';'  */
#line 232 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2121 "y.tab.c"
    break;

  case 79: /* vect_stmt: vect_stmt_body ';'  */
#line 235 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2127 "y.tab.c"
    break;

  case 93: /* return_stmt: RETURN RHS ';'  */
#line 259 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 2133 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN extra_consts ';'  */
#line 260 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2139 "y.tab.c"
    break;

  case 95: /* return_stmt: RETURN graph_impr ';'  */
#line 261 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2145 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN matrix_impr ';'  */
#line 262 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 2151 "y.tab.c"
    break;

  case 97: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 263 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2157 "y.tab.c"
    break;

  case 98: /* return_stmt: RETURN null ';'  */
#line 264 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2163 "y.tab.c"
    break;

  case 99: /* loop_stmt: LOOP loop_type  */
#line 268 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2169 "y.tab.c"
    break;

  case 111: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 290 "parser.y"
                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2175 "y.tab.c"
    break;

  case 112: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 291 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2181 "y.tab.c"
    break;

  case 113: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 292 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2187 "y.tab.c"
    break;

  case 114: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 293 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2193 "y.tab.c"
    break;

  case 115: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 294 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2199 "y.tab.c"
    break;

  case 118: /* declr_stmt: DECLR declr_body ';'  */
#line 301 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2205 "y.tab.c"
    break;

  case 132: /* $@9: %empty  */
#line 324 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2211 "y.tab.c"
    break;

  case 136: /* $@10: %empty  */
#line 331 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2217 "y.tab.c"
    break;

  case 138: /* $@11: %empty  */
#line 334 "parser.y"
                                              {level++;}
#line 2223 "y.tab.c"
    break;

  case 139: /* switch_body: '{' $@11 cases DEFAULT ':' function_body '}'  */
#line 334 "parser.y"
                                                                                             {level--;}
#line 2229 "y.tab.c"
    break;

  case 224: /* call_stmt: func_calls ';'  */
#line 486 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT");}
#line 2235 "y.tab.c"
    break;


#line 2239 "y.tab.c"

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

#line 497 "parser.y"


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
 	FILE* fp = fopen("inp.txt", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




