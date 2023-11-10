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
	int inStruct=0;
	int level=0;  // indicates level of scope
	int inFunc=0;
	int currentFuncIndex; // To be used by call statements to grab func details
	int classIndex = -1; // To be used by call statements to grab func details
	int funcIndex = -1;
	
	int dataType;
	/*
		dataType = 0 --> standard
		dataType = 1 --> array
		dataType = 2 --> vector
		dataType = 3 --> matrix
		dataType = 4 --> graph
		dataType = 5 --> struct
		dataType = 6 --> class
	*/
	
	char* arr[20];
	int arr_size=0;
	int dimA[20];
	int dimB[20];
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/

#line 112 "y.tab.c"

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
    SHPATH_VAL = 310,              /* SHPATH_VAL  */
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
#define SHPATH_VAL 310
#define GOTO 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser.y"

	char* str;
	struct{
		char* name;
		char* type;
	} details;
	

#line 286 "y.tab.c"

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
  YYSYMBOL_SHPATH_VAL = 55,                /* SHPATH_VAL  */
  YYSYMBOL_GOTO = 56,                      /* GOTO  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_65_ = 65,                       /* '<'  */
  YYSYMBOL_66_ = 66,                       /* '>'  */
  YYSYMBOL_67_ = 67,                       /* ':'  */
  YYSYMBOL_68_ = 68,                       /* '.'  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program_unit = 71,              /* program_unit  */
  YYSYMBOL_models = 72,                    /* models  */
  YYSYMBOL_model = 73,                     /* model  */
  YYSYMBOL_class = 74,                     /* class  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_id = 77,                        /* id  */
  YYSYMBOL_class_items = 78,               /* class_items  */
  YYSYMBOL_class_item = 79,                /* class_item  */
  YYSYMBOL_struct = 80,                    /* struct  */
  YYSYMBOL_81_3 = 81,                      /* $@3  */
  YYSYMBOL_82_4 = 82,                      /* $@4  */
  YYSYMBOL_struct_items = 83,              /* struct_items  */
  YYSYMBOL_function = 84,                  /* function  */
  YYSYMBOL_function_head = 85,             /* function_head  */
  YYSYMBOL_func_definition = 86,           /* func_definition  */
  YYSYMBOL_Parameters = 87,                /* Parameters  */
  YYSYMBOL_fdtype = 88,                    /* fdtype  */
  YYSYMBOL_param_list = 89,                /* param_list  */
  YYSYMBOL_param = 90,                     /* param  */
  YYSYMBOL_dtype = 91,                     /* dtype  */
  YYSYMBOL_function_body = 92,             /* function_body  */
  YYSYMBOL_93_5 = 93,                      /* $@5  */
  YYSYMBOL_statements = 94,                /* statements  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_unary_stmt = 96,                /* unary_stmt  */
  YYSYMBOL_jump_stmt = 97,                 /* jump_stmt  */
  YYSYMBOL_label_stmt = 98,                /* label_stmt  */
  YYSYMBOL_goto_stmt = 99,                 /* goto_stmt  */
  YYSYMBOL_vect_stmt = 100,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 101,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 102,              /* remove_body  */
  YYSYMBOL_vect_append = 103,              /* vect_append  */
  YYSYMBOL_return_stmt = 104,              /* return_stmt  */
  YYSYMBOL_105_6 = 105,                    /* $@6  */
  YYSYMBOL_106_7 = 106,                    /* $@7  */
  YYSYMBOL_107_8 = 107,                    /* $@8  */
  YYSYMBOL_108_9 = 108,                    /* $@9  */
  YYSYMBOL_loop_stmt = 109,                /* loop_stmt  */
  YYSYMBOL_loop_type = 110,                /* loop_type  */
  YYSYMBOL_for_loop = 111,                 /* for_loop  */
  YYSYMBOL_for_expr = 112,                 /* for_expr  */
  YYSYMBOL_for_RHS = 113,                  /* for_RHS  */
  YYSYMBOL_while_loop = 114,               /* while_loop  */
  YYSYMBOL_115_10 = 115,                   /* $@10  */
  YYSYMBOL_expr_stmt = 116,                /* expr_stmt  */
  YYSYMBOL_LHS = 117,                      /* LHS  */
  YYSYMBOL_myId = 118,                     /* myId  */
  YYSYMBOL_declr_stmt = 119,               /* declr_stmt  */
  YYSYMBOL_declr_body = 120,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 121,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 122,              /* matrix_list  */
  YYSYMBOL_id_list = 123,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 124,              /* ifcond_stmt  */
  YYSYMBOL_125_11 = 125,                   /* $@11  */
  YYSYMBOL_if_body = 126,                  /* if_body  */
  YYSYMBOL_switch_stmt = 127,              /* switch_stmt  */
  YYSYMBOL_128_12 = 128,                   /* $@12  */
  YYSYMBOL_switch_body = 129,              /* switch_body  */
  YYSYMBOL_130_13 = 130,                   /* $@13  */
  YYSYMBOL_cases = 131,                    /* cases  */
  YYSYMBOL_RHS = 132,                      /* RHS  */
  YYSYMBOL_constants = 133,                /* constants  */
  YYSYMBOL_extra_consts = 134,             /* extra_consts  */
  YYSYMBOL_array_const = 135,              /* array_const  */
  YYSYMBOL_val_list = 136,                 /* val_list  */
  YYSYMBOL_resultant = 137,                /* resultant  */
  YYSYMBOL_impr = 138,                     /* impr  */
  YYSYMBOL_graph_impr = 139,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 140,              /* matrix_impr  */
  YYSYMBOL_matr_body = 141,                /* matr_body  */
  YYSYMBOL_graph_const = 142,              /* graph_const  */
  YYSYMBOL_graph_type1 = 143,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 144,              /* graph_type2  */
  YYSYMBOL_int_list = 145,                 /* int_list  */
  YYSYMBOL_float_list = 146,               /* float_list  */
  YYSYMBOL_char_list = 147,                /* char_list  */
  YYSYMBOL_bool_list = 148,                /* bool_list  */
  YYSYMBOL_str_list = 149,                 /* str_list  */
  YYSYMBOL_weight_list = 150,              /* weight_list  */
  YYSYMBOL_vect_const = 151,               /* vect_const  */
  YYSYMBOL_vect_list = 152,                /* vect_list  */
  YYSYMBOL_matrix_const = 153,             /* matrix_const  */
  YYSYMBOL_int_float_list = 154,           /* int_float_list  */
  YYSYMBOL_mat_list = 155,                 /* mat_list  */
  YYSYMBOL_arith_op = 156,                 /* arith_op  */
  YYSYMBOL_binary_op = 157,                /* binary_op  */
  YYSYMBOL_unary_op = 158,                 /* unary_op  */
  YYSYMBOL_logical_op = 159,               /* logical_op  */
  YYSYMBOL_call_stmt = 160,                /* call_stmt  */
  YYSYMBOL_func_calls = 161,               /* func_calls  */
  YYSYMBOL_call_head = 162,                /* call_head  */
  YYSYMBOL_arguments = 163,                /* arguments  */
  YYSYMBOL_arg_list = 164                  /* arg_list  */
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1022

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  459

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
      60,    61,     2,     2,    62,     2,    68,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    59,
      65,    69,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
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
       0,   112,   112,   115,   116,   119,   120,   121,   124,   135,
     124,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   158,
     159,   162,   163,   167,   178,   166,   181,   182,   185,   188,
     197,   206,   207,   211,   212,   216,   217,   221,   243,   250,
     251,   252,   253,   262,   281,   281,   282,   285,   286,   287,
     288,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   305,   308,   309,   312,   315,   318,   321,
     322,   323,   324,   328,   329,   330,   331,   332,   333,   334,
     338,   339,   341,   341,   351,   350,   362,   361,   372,   372,
     381,   382,   387,   390,   391,   394,   397,   398,   412,   413,
     414,   415,   416,   417,   420,   420,   433,   447,   448,   449,
     450,   454,   468,   530,   531,   541,   543,   568,   593,   618,
     643,   668,   704,   715,   728,   740,   754,   759,   766,   766,
     781,   782,   785,   785,   800,   800,   803,   804,   809,   810,
     811,   812,   813,   817,   818,   819,   820,   821,   822,   826,
     827,   828,   829,   830,   833,   834,   837,   838,   839,   840,
     841,   844,   845,   846,   847,   848,   851,   852,   853,   854,
     855,   856,   857,   860,   861,   862,   863,   867,   868,   869,
     872,   873,   876,   877,   880,   881,   884,   885,   888,   889,
     892,   893,   896,   897,   900,   901,   904,   905,   908,   909,
     910,   911,   914,   917,   918,   919,   920,   923,   926,   927,
     928,   929,   932,   933,   936,   937,   940,   956,   966,   980,
     990,   995,   999,  1016,  1017,  1020,  1021
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
  "SHPATH_VAL", "GOTO", "'{'", "'}'", "';'", "'('", "')'", "','", "'['",
  "']'", "'<'", "'>'", "':'", "'.'", "'='", "$accept", "program_unit",
  "models", "model", "class", "$@1", "$@2", "id", "class_items",
  "class_item", "struct", "$@3", "$@4", "struct_items", "function",
  "function_head", "func_definition", "Parameters", "fdtype", "param_list",
  "param", "dtype", "function_body", "$@5", "statements", "statement",
  "unary_stmt", "jump_stmt", "label_stmt", "goto_stmt", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt", "$@6",
  "$@7", "$@8", "$@9", "loop_stmt", "loop_type", "for_loop", "for_expr",
  "for_RHS", "while_loop", "$@10", "expr_stmt", "LHS", "myId",
  "declr_stmt", "declr_body", "graph_and_array_list", "matrix_list",
  "id_list", "ifcond_stmt", "$@11", "if_body", "switch_stmt", "$@12",
  "switch_body", "$@13", "cases", "RHS", "constants", "extra_consts",
  "array_const", "val_list", "resultant", "impr", "graph_impr",
  "matrix_impr", "matr_body", "graph_const", "graph_type1", "graph_type2",
  "int_list", "float_list", "char_list", "bool_list", "str_list",
  "weight_list", "vect_const", "vect_list", "matrix_const",
  "int_float_list", "mat_list", "arith_op", "binary_op", "unary_op",
  "logical_op", "call_stmt", "func_calls", "call_head", "arguments",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-302)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-176)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,   251,   251,   871,    24,  -302,    28,  -302,  -302,  -302,
     -22,   -14,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
      10,    15,  -302,  -302,  -302,  -302,    11,  -302,   251,  -302,
    -302,  -302,    21,  -302,   674,  -302,  -302,  -302,   919,  -302,
    -302,   816,  -302,    35,  -302,   251,   -12,    57,    37,   412,
      46,    53,    89,    74,    85,   967,   251,   251,    72,    93,
     108,   109,   251,    -5,   816,   112,   816,  -302,  -302,  -302,
    -302,  -302,   114,  -302,  -302,  -302,   172,  -302,  -302,  -302,
    -302,   116,  -302,  -302,  -302,   123,  -302,   126,   127,  -302,
     919,   125,   128,   -12,  -302,  -302,   131,    57,  -302,  -302,
    -302,  -302,  -302,  -302,   130,   132,   135,   534,   733,    86,
     134,   137,    13,   139,  -302,   140,  -302,   136,   141,   144,
    -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,   733,  -302,
    -302,   733,   733,   251,   251,   251,   143,   251,   146,     5,
     172,   149,   150,  -302,  -302,  -302,   733,   733,   733,   147,
     733,   -22,  -302,  -302,  -302,  -302,   251,   444,  -302,  -302,
     621,  -302,  -302,   148,  -302,  -302,  -302,  -302,   733,   733,
    -302,   124,  -302,   172,   153,   154,   159,   160,   162,  -302,
     185,   161,   163,   164,   166,   167,   106,  -302,   157,  -302,
    -302,  -302,  -302,  -302,   158,  -302,  -302,  -302,  -302,  -302,
     169,   170,   171,    73,  -302,  -302,   173,  -302,   174,  -302,
     919,   176,  -302,  -302,   473,   193,   733,   177,   178,  -302,
     165,   179,  -302,   180,  -302,  -302,   175,   182,   186,   190,
     191,   195,   197,   198,   200,   202,   206,   208,   209,   211,
     213,  -302,   183,   192,  -302,   220,   221,   222,   224,    38,
     560,   560,  -302,  -302,  -302,   733,   230,   297,   301,   302,
     300,   248,   249,   250,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,   251,   308,   309,   253,   256,   257,   261,
     263,   264,     6,   266,   733,   733,   733,  -302,   473,   763,
     267,   268,   269,   763,   270,   271,   763,   272,   763,   273,
     274,   763,   763,   733,  -302,  -302,  -302,   733,  -302,   320,
     279,   280,  -302,  -302,   281,  -302,  -302,  -302,  -302,  -302,
     106,   106,   282,   -22,   286,  -302,   283,   284,   251,  -302,
    -302,  -302,  -302,  -302,   285,  -302,   288,   289,   293,   294,
    -302,  -302,  -302,  -302,   295,    13,   136,  -302,  -302,  -302,
    -302,  -302,  -302,   296,  -302,  -302,   298,  -302,   299,  -302,
    -302,   304,   305,  -302,   307,   310,   321,   341,  -302,  -302,
    -302,   306,   343,  -302,  -302,  -302,   314,   315,  -302,    55,
     -22,  -302,  -302,  -302,  -302,  -302,  -302,  -302,   763,   763,
     763,  -302,   133,   303,  -302,   312,  -302,  -302,   -22,   338,
     251,   367,   251,   316,  -302,  -302,   319,   323,   326,   327,
     328,   230,   322,  -302,   377,   370,  -302,   330,     8,   -22,
    -302,  -302,  -302,   333,   334,   331,   332,   335,    75,  -302,
     322,   322,   -22,   -22,   251,   336,  -302,   136,   337,   165,
    -302,  -302,  -302,  -302,   338,   342,  -302,  -302,  -302
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    24,    23,    25,    26,    27,    28,
       0,     0,    49,    44,    50,    51,     0,    53,     0,    43,
       1,     3,    54,    38,     0,    39,     8,    33,     0,    40,
      56,     0,    41,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      23,     0,     0,   123,    60,     0,    58,    69,    66,    74,
      75,    70,   174,    68,    67,    61,   171,   121,    63,    64,
      65,     0,   175,   173,   172,     0,    62,     0,     0,    42,
       0,    47,     0,    30,    32,    31,     0,    37,    52,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
     123,   174,   158,     0,   148,     0,   159,   152,   173,   172,
     160,   161,   162,   149,   224,   225,   150,   151,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    78,     0,     0,    73,   230,
       0,   231,    45,     0,     9,    29,    34,    36,     0,     0,
     101,   153,   163,   158,   214,   216,     0,     0,     0,   174,
       0,   199,   201,   203,   207,   205,     0,   165,     0,   166,
     167,   168,   169,   170,     0,   100,    92,    94,    96,    98,
       0,     0,     0,   137,   130,   126,     0,   129,     0,   127,
       0,   137,   131,   125,     0,     0,     0,     0,     0,   190,
     191,     0,    77,     0,    76,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   236,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   212,     0,     0,     0,     0,     0,
       0,   220,   221,     0,   164,   217,    93,    95,    97,    99,
     138,   142,   227,     0,     0,     0,     0,   174,     0,     0,
     173,   172,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,    10,    35,     0,   229,     0,
       0,     0,   213,   215,     0,   198,   200,   202,   206,   204,
       0,     0,     0,     0,     0,   136,     0,     0,     0,   120,
     116,   117,   118,   119,     0,   114,     0,     0,     0,     0,
      90,    91,    83,    84,     0,    85,    89,    87,    88,    86,
     176,    81,    82,     0,   188,   178,     0,   179,     0,   189,
     184,     0,     0,   235,     0,     0,   195,   197,   228,   218,
     219,   223,   141,   139,   144,   143,   133,     0,   128,     0,
       0,   180,   182,   187,    79,    80,   177,   183,     0,     0,
       0,   226,     0,     0,   194,     0,   196,   222,     0,     0,
       0,     0,     0,     0,   106,   115,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,   132,     0,     0,     0,
     181,   185,   186,   209,   211,     0,     0,   135,     0,   105,
       0,     0,     0,     0,     0,   112,   107,   110,   111,   113,
     108,   109,   208,   210,   147,     0,   134,   146,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -302,  -302,   384,  -302,  -302,  -302,  -302,    -1,   311,  -302,
    -302,  -302,  -302,   317,    -8,  -302,  -302,  -302,  -302,  -302,
     325,     7,    -7,  -302,   -17,  -302,  -302,  -302,  -302,  -302,
    -302,   -46,  -223,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -302,  -302,   181,   -47,   237,    44,
    -302,  -133,   -37,  -131,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,   -44,    23,   -94,   -50,  -302,  -302,  -302,   -36,   -52,
     -53,   115,  -302,    32,    49,  -108,   145,   155,   151,   168,
    -301,  -302,  -101,  -302,  -168,    47,  -243,  -302,   -43,  -267,
    -302,   -25,  -302,  -302,   117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,    80,
      81,   189,   354,   349,    83,   276,   277,   278,   279,    84,
     153,   154,   413,   446,   155,   390,    85,   122,    87,    88,
     148,   214,   217,   215,    89,   333,   383,    90,   334,   385,
     409,   425,   229,   124,   185,   126,   198,    91,   127,    93,
      94,   231,   130,   186,   187,   320,   200,   201,   202,   203,
     321,   131,   188,   132,   273,   204,   133,   134,   135,   136,
      96,   137,    98,   171,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    37,    43,    86,    82,   129,   128,    95,   125,
      39,   199,   219,   121,   166,    92,   222,   166,    65,   149,
     150,     3,   166,   184,    40,   344,    97,    86,    82,    86,
      82,    95,   358,    95,   115,    42,   358,    49,    92,   358,
      92,   358,   191,    37,   358,   358,    44,    37,   104,    97,
      73,    97,     1,     2,   101,    58,   357,   162,   160,   164,
     357,     3,   161,   357,   147,   357,   118,    46,   357,   357,
     183,   159,    47,    73,   224,    73,    48,   438,    12,    50,
     363,  -171,   123,   366,    64,   368,   412,    65,   371,   372,
     191,   192,   193,   194,   195,   104,    99,   100,   319,    37,
     105,   107,   114,   108,    64,   230,   138,    67,   151,   152,
     271,   272,   139,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,   358,   358,   358,   141,   283,   284,   419,   420,   452,
     453,   190,   213,   216,   218,   142,   221,   105,   140,   196,
     197,   107,   335,   156,   234,   357,   357,   357,   325,   322,
     323,   210,   379,   380,   211,   212,   184,   184,   157,   158,
     163,   291,   290,   165,   289,   416,   417,   418,   287,   227,
     228,   166,   168,   233,   167,   169,   174,   170,   173,   176,
     178,   259,   179,   252,   180,   450,   205,   160,   206,   207,
     208,   257,   258,   209,  -175,   223,   232,   388,   220,   225,
     226,   265,   254,   183,   183,   260,   261,   262,   263,    37,
     264,   274,   275,   266,    66,   267,   268,   286,   269,   270,
     280,   281,   282,  -172,   191,   298,   285,   284,   283,   294,
     295,   296,   299,   230,   297,   313,   300,   288,   351,   293,
     301,   302,   355,   314,    12,   303,   355,   304,   305,   355,
     306,   355,   307,   356,   355,   355,   308,   356,   309,   310,
     356,   311,   356,   312,   359,   356,   356,   426,   359,   315,
     316,   359,   221,   359,   317,   318,   359,   359,   324,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   192,    26,    27,    28,    29,   193,   195,   194,
     330,   331,   336,   337,   332,   339,   340,   346,   347,   338,
     341,   350,   342,   343,   375,   403,   382,   345,   360,   361,
     362,   364,   365,   367,   369,   370,   252,   221,   376,   377,
     374,   381,   378,   384,   389,   405,   414,   386,   387,   391,
     392,   355,   355,   355,   393,   394,   395,   396,   408,   397,
     424,   398,   356,   356,   356,   428,   399,   400,   401,   196,
     421,   427,   402,   359,   359,   359,   410,   429,   411,   422,
     430,   435,   319,   415,   431,   449,   448,   432,   433,   434,
      41,    86,   445,   436,   437,   440,   441,   444,   442,   443,
     458,   423,   447,   235,  -174,  -173,   292,   456,   404,   218,
     457,   348,   326,   451,   175,    12,   109,   110,   111,   112,
     113,   329,   439,   327,   177,   172,   406,     0,   407,     0,
     373,     0,     0,     0,     0,   454,   455,   328,     0,   114,
     115,    64,     0,   216,    67,     0,     0,   116,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29,     0,   117,
       0,     0,   118,     0,     0,   119,    12,   109,   110,   111,
     112,   113,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,   247,   248,   249,   250,
     114,   115,    64,     0,     0,    67,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29,     0,
     117,     0,     0,   118,     0,     0,   119,    12,   181,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,   109,   110,   111,   112,   113,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
       0,   117,   182,     0,     0,     0,     0,   119,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,     0,   117,     0,     0,
       0,     0,     0,   119,    12,   109,   110,   111,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
      64,     0,     0,    67,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      69,    70,    71,    26,    27,    28,    29,    12,     0,     0,
       0,   118,   251,     0,     0,    32,     0,     0,     0,     0,
       0,     0,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,    52,    12,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,    64,     0,     0,    67,    12,   352,   353,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29,     0,
     114,   115,    64,   118,     0,    67,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29,    12,
       0,     0,     0,   118,     0,     0,     0,     0,     0,    59,
      60,     0,    61,    62,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
      68,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,    72,    42,    12,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,     0,    34,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    12,    26,    27,    28,    29,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      12,    26,    27,    28,    29,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,   144,   145,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    10,    51,    51,    59,    59,    51,    59,
       3,   119,   145,    59,     9,    51,   147,     9,    30,    66,
      67,    33,     9,   117,     0,   292,    51,    74,    74,    76,
      76,    74,   299,    76,    28,    57,   303,    38,    74,   306,
      76,   308,     4,    44,   311,   312,    60,    48,    56,    74,
      51,    76,    24,    25,    55,    48,   299,    74,    63,    76,
     303,    33,    67,   306,    65,   308,    60,    57,   311,   312,
     117,    72,    57,    74,    69,    76,    65,    69,     3,    58,
     303,    68,    59,   306,    29,   308,    31,    30,   311,   312,
       4,     5,     6,     7,     8,   103,    61,    62,    60,   100,
      56,    57,    27,    66,    29,   158,    60,    32,    36,    37,
       4,     5,    59,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   398,   399,   400,    60,    62,    63,     4,     5,   440,
     441,   118,   143,   144,   145,    60,   147,   103,    59,    63,
      64,   107,   283,    60,   161,   398,   399,   400,   266,   260,
     261,   138,   330,   331,   141,   142,   260,   261,    60,    60,
      58,   224,   224,    59,   224,   398,   399,   400,   224,   156,
     157,     9,    59,   160,    68,    59,    58,    60,    63,    58,
      60,    67,    60,   170,    59,   438,    59,    63,    59,    59,
      59,   178,   179,    59,    68,    59,    59,   338,    65,    60,
      60,    26,    64,   260,   261,    62,    62,    58,    58,   220,
      58,    64,    64,    62,    31,    62,    62,   220,    62,    62,
      61,    61,    61,    68,     4,    60,    63,    63,    62,    62,
      62,    62,    60,   296,    64,    62,    60,   224,   298,   226,
      60,    60,   299,    61,     3,    60,   303,    60,    60,   306,
      60,   308,    60,   299,   311,   312,    60,   303,    60,    60,
     306,    60,   308,    60,   299,   311,   312,   410,   303,    59,
      59,   306,   283,   308,    62,    61,   311,   312,   265,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     5,    52,    53,    54,    55,     6,     8,     7,
      62,    62,     4,     4,    64,    59,    59,   294,   295,    66,
      59,   298,    59,    59,     4,     4,   333,    61,    61,    61,
      61,    61,    61,    61,    61,    61,   313,   338,    59,    59,
     317,    59,    61,    57,    59,     4,   389,    64,    64,    61,
      61,   398,   399,   400,    61,    61,    61,    61,    15,    61,
      22,    62,   398,   399,   400,   412,    62,    62,    61,    63,
      67,     4,    62,   398,   399,   400,    62,    61,    63,    67,
      61,     4,    60,   390,    61,   438,   438,    61,    61,    61,
       6,   438,   438,    23,    64,    62,    62,    62,    67,    67,
      58,   408,   438,   166,    68,    68,   225,   444,   376,   410,
     454,   296,   267,   438,   103,     3,     4,     5,     6,     7,
       8,   270,   429,   268,   107,   100,   377,    -1,   381,    -1,
     313,    -1,    -1,    -1,    -1,   442,   443,   269,    -1,    27,
      28,    29,    -1,   444,    32,    -1,    -1,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    60,    -1,    -1,    63,     3,     4,     5,     6,
       7,     8,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    53,    54,    55,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    60,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      -1,    57,    58,    -1,    -1,    -1,    -1,    63,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    63,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,    -1,    -1,
      -1,    60,    61,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,     3,     4,     5,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      27,    28,    29,    60,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    13,
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
       3,    52,    53,    54,    55,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    71,    72,    73,    74,    80,    84,
      85,    86,     3,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      77,    77,    11,    12,    18,    19,    20,    77,    88,    91,
       0,    72,    57,    92,    60,    87,    57,    57,    65,    77,
      58,    93,    61,    89,    90,    91,    75,    81,    91,    13,
      14,    16,    17,    21,    29,    30,    31,    32,    34,    49,
      50,    51,    56,    77,    92,    94,    95,    96,    97,    98,
      99,   100,   101,   104,   109,   116,   117,   118,   119,   124,
     127,   137,   138,   139,   140,   158,   160,   161,   162,    61,
      62,    77,    78,    79,    84,   119,    83,   119,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   101,   117,   132,   133,   134,   135,   138,   139,   140,
     142,   151,   153,   156,   157,   158,   159,   161,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   120,   117,
     117,    36,    37,   110,   111,   114,    60,    60,    60,    77,
      63,    67,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   163,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   117,   133,   134,   143,   144,   152,   101,
     132,     4,     5,     6,     7,     8,    63,    64,   136,   145,
     146,   147,   148,   149,   155,    59,    59,    59,    59,    59,
     132,   132,   132,    77,   121,   123,    77,   122,    77,   121,
      65,    77,   123,    59,    69,    60,    60,   132,   132,   132,
     140,   141,    59,   132,    92,   118,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   132,   164,    64,    76,    82,   132,   132,    67,
      62,    62,    58,    58,    58,    26,    62,    62,    62,    62,
      62,     4,     5,   154,    64,    64,   105,   106,   107,   108,
      61,    61,    61,    62,    63,    63,    91,   101,   132,   134,
     139,   140,   116,   132,    62,    62,    62,    64,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    62,    61,    59,    59,    62,    61,    60,
     145,   150,   152,   152,   132,   145,   146,   147,   149,   148,
      62,    62,    64,   125,   128,   123,     4,     4,    66,    59,
      59,    59,    59,    59,   159,    61,   132,   132,   141,   103,
     132,   134,     4,     5,   102,   117,   138,   156,   159,   161,
      61,    61,    61,   102,    61,    61,   102,    61,   102,    61,
      61,   102,   102,   164,   132,     4,    59,    59,    61,   154,
     154,    59,    92,   126,    57,   129,    64,    64,   123,    59,
     115,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    61,    62,     4,   143,     4,   144,   155,    15,   130,
      62,    63,    31,   112,   158,    92,   102,   102,   102,     4,
       5,    67,    67,    92,    22,   131,   121,     4,   117,    61,
      61,    61,    61,    61,    61,     4,    23,    64,    69,    92,
      62,    62,    67,    67,    62,   101,   113,   138,   139,   140,
     156,   161,   150,   150,    92,    92,   122,   131,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    75,    76,
      74,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    81,    82,    80,    83,    83,    84,    85,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    93,    92,    92,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    97,    97,    98,    99,   100,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   105,   104,   106,   104,   107,   104,   108,   104,
     104,   104,   109,   110,   110,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   115,   114,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   125,   124,
     126,   126,   128,   127,   130,   129,   131,   131,   132,   132,
     132,   132,   132,   133,   133,   133,   133,   133,   133,   134,
     134,   134,   134,   134,   135,   135,   136,   136,   136,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     150,   150,   151,   152,   152,   152,   152,   153,   154,   154,
     154,   154,   155,   155,   156,   156,   157,   158,   159,   159,
     160,   161,   162,   163,   163,   164,   164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     0,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     0,     8,     2,     1,     2,     2,
       3,     2,     3,     1,     1,     3,     1,     2,     4,     1,
       1,     1,     4,     1,     0,     4,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     3,     3,     2,     6,
       6,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     3,     2,     1,     1,     8,     1,     4,     1,     1,
       1,     1,     1,     1,     0,     6,     5,     5,     5,     5,
       5,     1,     3,     1,     4,     3,     2,     2,     5,     2,
       2,     2,     6,     4,     9,     7,     3,     1,     0,     6,
       3,     1,     0,     6,     0,     7,     5,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     6,     5,     5,
       6,     8,     6,     6,     5,     8,     8,     6,     5,     5,
       1,     1,     3,     3,     5,     4,     5,     4,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     7,     5,
       7,     5,     3,     3,     1,     3,     1,     3,     3,     3,
       1,     1,     5,     4,     1,     1,     6,     4,     5,     4,
       2,     2,     2,     3,     2,     3,     1
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
  case 8: /* $@1: %empty  */
#line 124 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
							{
								printf("Struct or class name already exists\n");
								exit(1);
							}
								
							else class_insert((yyvsp[-1].str));
							
						}
#line 1884 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 135 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1890 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 135 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1896 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 138 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1902 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 139 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1908 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 140 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1914 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 141 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1920 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 142 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1926 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 143 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1932 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 144 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1938 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 145 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1944 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 146 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1950 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 147 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1956 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 148 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1962 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 149 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1968 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 150 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1974 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 151 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1980 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 152 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1986 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 153 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1992 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 154 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1998 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 155 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2004 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 167 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									printf("Struct or class name already exists\n");
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].str));
								
							}
#line 2020 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 178 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2026 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 178 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2032 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 188 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2043 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 197 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							if(inClass == 0) func_insert((yyvsp[0].str), (yyvsp[-1].str));
							else class_func_insert(class_size-1, (yyvsp[0].str), (yyvsp[-1].str));
							currentFuncIndex = func_size-1;
						}
#line 2055 "y.tab.c"
    break;

  case 43: /* fdtype: dtype  */
#line 211 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2061 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 212 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2067 "y.tab.c"
    break;

  case 47: /* param: dtype id  */
#line 221 "parser.y"
                                                   {
							if(inClass == 0) add_args((yyvsp[-1].str));
							else class_add_args(class_size-1, (yyvsp[-1].str));
							if(dataType == 0) var_insert(0, level, (yyvsp[0].str), (yyvsp[-1].str), "", -1, -1);
							else if(dataType == 2){
								strncpy((yyvsp[-1].str), (yyvsp[-1].str) + 1, strlen((yyvsp[-1].str))-1);
								var_insert(0, level, (yyvsp[0].str), "vect", (yyvsp[-1].str), -1, -1);
							}
							else if(dataType == 3) {
								var_insert(0, level, (yyvsp[0].str), "matrix", "", -1, -1);
							}
							else if(dataType == 4) {
								var_insert(0, level, (yyvsp[0].str), "graph", "", -1, -1);
							}
							else if(dataType == 5){
								var_insert(0, level, (yyvsp[0].str), (yyvsp[-1].str), "", -1, -1);
							}
							else if(dataType == 6) {
								var_insert(0, level, (yyvsp[0].str), (yyvsp[-1].str), "", -1, -1);
							}

						}
#line 2094 "y.tab.c"
    break;

  case 48: /* param: dtype id '[' ']'  */
#line 243 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2102 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 250 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2108 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 251 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2114 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 252 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2120 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 253 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2134 "y.tab.c"
    break;

  case 53: /* dtype: id  */
#line 262 "parser.y"
                                                     {
							int i = struct_search((yyvsp[0].str));
							if(i < 0) {
								i = class_search((yyvsp[0].str));
								if(i < 0){
									printf("Error: Using undefined datatype %s\n", (yyvsp[0].str));
								}
								else{
									dataType = 6;
									(yyval.str) = (yyvsp[0].str);
								}
							}
							else{
								dataType = 5;
								(yyval.str) = (yyvsp[0].str);
							}
						}
#line 2156 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 281 "parser.y"
                                      { level++; }
#line 2162 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 281 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2168 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 301 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2174 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 302 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2180 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 305 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2186 "y.tab.c"
    break;

  case 76: /* label_stmt: id ':' function_body  */
#line 312 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 2192 "y.tab.c"
    break;

  case 77: /* goto_stmt: GOTO id ';'  */
#line 315 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2198 "y.tab.c"
    break;

  case 78: /* vect_stmt: vect_stmt_body ';'  */
#line 318 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2204 "y.tab.c"
    break;

  case 92: /* $@6: %empty  */
#line 341 "parser.y"
                                               {if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							}
#line 2218 "y.tab.c"
    break;

  case 93: /* return_stmt: RETURN RHS ';' $@6  */
#line 349 "parser.y"
                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2224 "y.tab.c"
    break;

  case 94: /* $@7: %empty  */
#line 351 "parser.y"
                                                 {
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
						 }
#line 2239 "y.tab.c"
    break;

  case 95: /* return_stmt: RETURN extra_consts ';' $@7  */
#line 360 "parser.y"
                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2245 "y.tab.c"
    break;

  case 96: /* $@8: %empty  */
#line 362 "parser.y"
                                                {
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
						 }
#line 2260 "y.tab.c"
    break;

  case 97: /* return_stmt: RETURN graph_impr ';' $@8  */
#line 371 "parser.y"
                                                   {fprintf(fparse, " : RETURN STATEMENT");}
#line 2266 "y.tab.c"
    break;

  case 98: /* $@9: %empty  */
#line 372 "parser.y"
                                                                        {if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							}
#line 2280 "y.tab.c"
    break;

  case 99: /* return_stmt: RETURN matrix_impr ';' $@9  */
#line 380 "parser.y"
                                                           {fprintf(fparse, " : RETURN STATEMENT");}
#line 2286 "y.tab.c"
    break;

  case 100: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 381 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2292 "y.tab.c"
    break;

  case 101: /* return_stmt: RETURN null ';'  */
#line 382 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2298 "y.tab.c"
    break;

  case 102: /* loop_stmt: LOOP loop_type  */
#line 387 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2304 "y.tab.c"
    break;

  case 107: /* for_expr: EXPR LHS '=' for_RHS  */
#line 398 "parser.y"
                                                                       {
							if(strcmp((yyvsp[-2].details).type, (yyvsp[0].str))){
								int a = !strcmp((yyvsp[-2].details).type, "int") || !strcmp((yyvsp[-2].details).type, "float") || !strcmp((yyvsp[-2].details).type, "bool");
								int b = !strcmp((yyvsp[0].str), "int") || !strcmp((yyvsp[0].str), "float") || !strcmp((yyvsp[0].str), "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", (yyvsp[-2].details).name, (yyvsp[-2].details).type, (yyvsp[0].str));
									printf("Error: Expression statement, type mismatch\n");
									exit(1);
								}
							}
						}
#line 2321 "y.tab.c"
    break;

  case 108: /* for_RHS: arith_op  */
#line 412 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2327 "y.tab.c"
    break;

  case 109: /* for_RHS: func_calls  */
#line 413 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2333 "y.tab.c"
    break;

  case 110: /* for_RHS: impr  */
#line 414 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2339 "y.tab.c"
    break;

  case 111: /* for_RHS: graph_impr  */
#line 415 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2345 "y.tab.c"
    break;

  case 112: /* for_RHS: vect_stmt_body  */
#line 416 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2351 "y.tab.c"
    break;

  case 113: /* for_RHS: matrix_impr  */
#line 417 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2357 "y.tab.c"
    break;

  case 114: /* $@10: %empty  */
#line 420 "parser.y"
                                                          {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
						}
#line 2373 "y.tab.c"
    break;

  case 116: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 433 "parser.y"
                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].str))){
								int a = !strcmp((yyvsp[-3].details).type, "int") || !strcmp((yyvsp[-3].details).type, "float") || !strcmp((yyvsp[-3].details).type, "bool");
								int b = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-1].str), "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", (yyvsp[-3].details).name, (yyvsp[-3].details).type, (yyvsp[-1].str));
									printf("Error: Expression statement, type mismatch\n");
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 2392 "y.tab.c"
    break;

  case 117: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 447 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2398 "y.tab.c"
    break;

  case 118: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 448 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2404 "y.tab.c"
    break;

  case 119: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 449 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2410 "y.tab.c"
    break;

  case 120: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 450 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2416 "y.tab.c"
    break;

  case 121: /* LHS: myId  */
#line 454 "parser.y"
                                                       {
							// printf("%s\n", $1);
							classIndex = -1; // indicates it is independent function(for call statements)
							int i = var_search((yyvsp[0].str));
							printf("%s - %d\n", (yyvsp[0].str), i);
							if( i < 0){
								printf("Error: Accessing undeclared identifier %s\n", (yyvsp[0].str));
								exit(1);
							}
							else{
								(yyval.details).name = (yyvsp[0].str);
								(yyval.details).type = var_symb[i].type;
							}
						}
#line 2435 "y.tab.c"
    break;

  case 122: /* LHS: LHS ARROW myId  */
#line 468 "parser.y"
                                                                 {
							int ind = var_search((yyvsp[-2].details).name);
							
							if(ind < 0){
								printf("Error: Accessing undefined identifier %s\n", (yyvsp[-2].details).name);
								exit(1);
							}
							char* dType = var_symb[ind].type;
							int i = struct_search(dType);
							if(i < 0){
								i = class_search(dType);
								if(i < 0){
									
									// item is not defined in class and struct
									printf("Error: Accessing undefined datatype %s\n", (yyvsp[-2].details).name);
									exit(1);
								}
								
								else{
									
									int j = class_declr_search((yyvsp[0].str), i);
									int k = class_func_search((yyvsp[0].str), i);
									if(j < 0 && k < 0){
										printf("Error: Accessing undefined function/attribute of class %s\n", (yyvsp[-2].details).name);
										exit(1);
									}
									
									if(j >= 0){
										(yyval.details).name = (yyvsp[0].str);
										(yyval.details).type = class_symb[i].declr_list[j].type;
									}
								
									else if(k >= 0){
									
										// set global variables of required indices for call statements
										funcIndex = k;
										classIndex = i;
										(yyval.details).name = (yyvsp[0].str);
										(yyval.details).type = "func"; // can be ignored
									}
								}
							}
							
							else {
								// item defined in struct
								int j = struct_declr_search((yyvsp[0].str), i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("Error: Accessing undefined attribute of struct %s\n", (yyvsp[-2].details).name);
									exit(1);
								}
								
								else{
									(yyval.details).name = (yyvsp[0].str);
									(yyval.details).type = struct_symb[i].list[j].type;
								}
							}
						}
#line 2499 "y.tab.c"
    break;

  case 123: /* myId: id  */
#line 530 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2505 "y.tab.c"
    break;

  case 124: /* myId: id '[' RHS ']'  */
#line 531 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("Error: invalid array index\n");
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2518 "y.tab.c"
    break;

  case 125: /* declr_stmt: DECLR declr_body ';'  */
#line 541 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2524 "y.tab.c"
    break;

  case 126: /* declr_body: DATATYPE id_list  */
#line 544 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
									}
								}
								arr_size =0;
							}
#line 2553 "y.tab.c"
    break;

  case 127: /* declr_body: GRAPH graph_and_array_list  */
#line 569 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], -1);
									}
								}
								arr_size=0;
							}
#line 2582 "y.tab.c"
    break;

  case 128: /* declr_body: VECT '<' dtype '>' id_list  */
#line 594 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], (yyvsp[-4].str), (yyvsp[-2].str), -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].str), -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].str), -1, -1);
									}
								}
								arr_size=0;
							}
#line 2611 "y.tab.c"
    break;

  case 129: /* declr_body: MATRIX matrix_list  */
#line 619 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , dimA[i], dimB[i]);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], dimB[i]);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], dimB[i]);
									}
								}
								arr_size=0;
							}
#line 2640 "y.tab.c"
    break;

  case 130: /* declr_body: DATATYPE graph_and_array_list  */
#line 644 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										var_insert(1, level, arr[i], "array", (yyvsp[-1].str) , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										add_class_declrs(arr[i], "array", 1, level, (yyvsp[-1].str), -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										add_struct_declrs(arr[i], "array", 1, level, (yyvsp[-1].str), -1, -1);
									}
								}
								arr_size=0;
							}
#line 2669 "y.tab.c"
    break;

  case 131: /* declr_body: id id_list  */
#line 669 "parser.y"
                                                        {
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									if(currentFuncIndex!=-1)
									{
										for(int i=0; i<arr_size; i++)
										{
											var_insert(1, level, arr[i], (yyvsp[-1].str), "", -1, -1);
										}
									}
									else if(inClass==1)
									{
										for(int i=0; i<arr_size; i++)
										{
											add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
										}
									}
									else
									{
										for(int i=0; i<arr_size; i++)
										{
											add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
										}
									}
									arr_size =0;
								}
								else
								{
									arr_size=0;
									printf("No struct or class with that name is defined\n");
									exit(1);
								}
							}
#line 2707 "y.tab.c"
    break;

  case 132: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 705 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-5].str);
								dimA[arr_size] = atoi((yyvsp[-3].str));
								if(dimA[arr_size]<=0)
								{
									printf("Number of vertices in a graph has to be greater than 0\n");
									exit(1);
								}
								arr_size++;
							}
#line 2722 "y.tab.c"
    break;

  case 133: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 716 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-3].str);
								dimA[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0)
								{
									printf("Number of vertices in a graph has to be greater than 0\n");
									exit(1);
								}
								arr_size++;
							}
#line 2737 "y.tab.c"
    break;

  case 134: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 729 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-8].str);
								dimA[arr_size] = atoi((yyvsp[-6].str));
								dimB[arr_size] = atoi((yyvsp[-3].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("No of rows or columns has to be positive\n");
									exit(1);
								}
								arr_size++;
							}
#line 2753 "y.tab.c"
    break;

  case 135: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 741 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].str);
								dimA[arr_size] = atoi((yyvsp[-4].str));
								dimB[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("No of rows or columns has to be positive\n");
									exit(1);
								}
								arr_size++;
							}
#line 2769 "y.tab.c"
    break;

  case 136: /* id_list: id ',' id_list  */
#line 755 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 2778 "y.tab.c"
    break;

  case 137: /* id_list: id  */
#line 760 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 2787 "y.tab.c"
    break;

  case 138: /* $@11: %empty  */
#line 766 "parser.y"
                                                         {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 2804 "y.tab.c"
    break;

  case 142: /* $@12: %empty  */
#line 785 "parser.y"
                                                             {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("Error : Invalid conditional argument\n");
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 2821 "y.tab.c"
    break;

  case 144: /* $@13: %empty  */
#line 800 "parser.y"
                                              {level++;}
#line 2827 "y.tab.c"
    break;

  case 145: /* switch_body: '{' $@13 cases DEFAULT ':' function_body '}'  */
#line 800 "parser.y"
                                                                                             { var_delete(level); level--;}
#line 2833 "y.tab.c"
    break;

  case 148: /* RHS: constants  */
#line 809 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 2839 "y.tab.c"
    break;

  case 149: /* RHS: arith_op  */
#line 810 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2845 "y.tab.c"
    break;

  case 150: /* RHS: logical_op  */
#line 811 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2851 "y.tab.c"
    break;

  case 151: /* RHS: func_calls  */
#line 812 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2857 "y.tab.c"
    break;

  case 152: /* RHS: impr  */
#line 813 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2863 "y.tab.c"
    break;

  case 153: /* constants: INT_CONST  */
#line 817 "parser.y"
                                                    {(yyval.str)="int";}
#line 2869 "y.tab.c"
    break;

  case 154: /* constants: FLOAT_CONST  */
#line 818 "parser.y"
                                                              {(yyval.str)="float";}
#line 2875 "y.tab.c"
    break;

  case 155: /* constants: CHAR_CONST  */
#line 819 "parser.y"
                                                             {(yyval.str)="char";}
#line 2881 "y.tab.c"
    break;

  case 156: /* constants: STR_CONST  */
#line 820 "parser.y"
                                                            {(yyval.str)="string";}
#line 2887 "y.tab.c"
    break;

  case 157: /* constants: BOOL_CONST  */
#line 821 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 2893 "y.tab.c"
    break;

  case 158: /* constants: LHS  */
#line 822 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 2899 "y.tab.c"
    break;

  case 159: /* extra_consts: array_const  */
#line 826 "parser.y"
                                             {(yyval.str) = "2";}
#line 2905 "y.tab.c"
    break;

  case 160: /* extra_consts: graph_const  */
#line 827 "parser.y"
                                                             {(yyval.str)="graph";}
#line 2911 "y.tab.c"
    break;

  case 161: /* extra_consts: vect_const  */
#line 828 "parser.y"
                                                            {(yyval.str)="vect";}
#line 2917 "y.tab.c"
    break;

  case 162: /* extra_consts: matrix_const  */
#line 829 "parser.y"
                                                              {(yyval.str)="matrix";}
#line 2923 "y.tab.c"
    break;

  case 163: /* extra_consts: '{' '}'  */
#line 830 "parser.y"
                                                         {(yyval.str)="1";}
#line 2929 "y.tab.c"
    break;

  case 176: /* impr: resultant '.' LENGTH '(' ')'  */
#line 851 "parser.y"
                                                                      {(yyval.str) = "int";}
#line 2935 "y.tab.c"
    break;

  case 177: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 852 "parser.y"
                                                                                      {(yyval.str) = "0";}
#line 2941 "y.tab.c"
    break;

  case 178: /* impr: resultant '.' TRACE '(' ')'  */
#line 853 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 2947 "y.tab.c"
    break;

  case 179: /* impr: resultant '.' STRLEN '(' ')'  */
#line 854 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 2953 "y.tab.c"
    break;

  case 180: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 855 "parser.y"
                                                                             {(yyval.str) = "bool";}
#line 2959 "y.tab.c"
    break;

  case 181: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 856 "parser.y"
                                                                                                          {(yyval.str) = "string";}
#line 2965 "y.tab.c"
    break;

  case 182: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 857 "parser.y"
                                                                             {(yyval.str) =  "string";}
#line 2971 "y.tab.c"
    break;

  case 183: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 860 "parser.y"
                                                                                     {(yyval.str) = "vect";}
#line 2977 "y.tab.c"
    break;

  case 184: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 861 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 2983 "y.tab.c"
    break;

  case 185: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 862 "parser.y"
                                                                                                          {(yyval.str) = "vect";}
#line 2989 "y.tab.c"
    break;

  case 186: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 863 "parser.y"
                                                                                                               {(yyval.str) = "int";}
#line 2995 "y.tab.c"
    break;

  case 187: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 867 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3001 "y.tab.c"
    break;

  case 188: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 868 "parser.y"
                                                                                  {(yyval.str) = "matrix";}
#line 3007 "y.tab.c"
    break;

  case 189: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 869 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3013 "y.tab.c"
    break;

  case 226: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 940 "parser.y"
                                                                      {
							if(!strcmp((yyvsp[-3].str), "int") || !strcmp((yyvsp[-3].str), "bool")|| !strcmp((yyvsp[-3].str), "float")){
								if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool") || !strcmp((yyvsp[-1].str), "float")){
									if(!strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-3].str), "float")) (yyval.str) = "float";
									else (yyval.str) = "int";
								}
								else{
									printf("Error: Invalid argument for arithmetic operation\n");
								}
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3032 "y.tab.c"
    break;

  case 227: /* unary_op: UNARYOP '(' RHS ')'  */
#line 956 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3045 "y.tab.c"
    break;

  case 228: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 966 "parser.y"
                                                                {
							if(!strcmp((yyvsp[-3].str), "int") || !strcmp((yyvsp[-3].str), "bool")|| !strcmp((yyvsp[-3].str), "float")){
								if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool") || !strcmp((yyvsp[-1].str), "float")){
									if(!strcmp((yyvsp[-3].str), "float") || !strcmp((yyvsp[-1].str), "float")) (yyval.str) = "float";
									else (yyval.str) = "int";
								}
								else{
									printf("Error: Invalid argument for arithmetic operation\n");
								}
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3064 "y.tab.c"
    break;

  case 229: /* logical_op: NOT '(' RHS ')'  */
#line 980 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3077 "y.tab.c"
    break;

  case 230: /* call_stmt: func_calls ';'  */
#line 990 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 3083 "y.tab.c"
    break;

  case 231: /* func_calls: call_head arguments  */
#line 995 "parser.y"
                                                              {(yyval.str) = (yyvsp[-1].str);}
#line 3089 "y.tab.c"
    break;

  case 232: /* call_head: CALL LHS  */
#line 999 "parser.y"
                                                    {
							if(classIndex == -1){
								(yyval.str) = func_symb[funcIndex].type;
								
								// restore index to -1 (to be redegined by LHS)
								funcIndex = -1;
							}
							else{
								(yyval.str) = class_symb[classIndex].func_list[funcIndex].type;
								
								// restore indices to -1 (to be redefined by LHS)
								classIndex = -1;
								funcIndex = -1;
							}
						}
#line 3109 "y.tab.c"
    break;


#line 3113 "y.tab.c"

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

#line 1024 "parser.y"


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




