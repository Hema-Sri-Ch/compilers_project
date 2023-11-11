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
	int currentFuncIndex = -1; // To be used by call statements to grab func details
	int classIndex = -1; // To be used by call statements to grab func details
	int funcIndex = -1;
	int callClassIndex=-1;
	int callFuncIndex=-1;
	int myIndex = 0; // for argument checking in function calls
	int returnStmtCount = 0;
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

#line 115 "y.tab.c"

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
#line 45 "parser.y"

	char* str;
	struct{
		char* name;
		char* type;
	} details;
	struct
	{
		int cols;
	} Cols;

#line 292 "y.tab.c"

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
  YYSYMBOL_99_6 = 99,                      /* $@6  */
  YYSYMBOL_goto_stmt = 100,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 101,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 102,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 103,              /* remove_body  */
  YYSYMBOL_vect_append = 104,              /* vect_append  */
  YYSYMBOL_return_stmt = 105,              /* return_stmt  */
  YYSYMBOL_106_7 = 106,                    /* $@7  */
  YYSYMBOL_107_8 = 107,                    /* $@8  */
  YYSYMBOL_108_9 = 108,                    /* $@9  */
  YYSYMBOL_109_10 = 109,                   /* $@10  */
  YYSYMBOL_110_11 = 110,                   /* $@11  */
  YYSYMBOL_111_12 = 111,                   /* $@12  */
  YYSYMBOL_loop_stmt = 112,                /* loop_stmt  */
  YYSYMBOL_loop_type = 113,                /* loop_type  */
  YYSYMBOL_for_loop = 114,                 /* for_loop  */
  YYSYMBOL_for_expr = 115,                 /* for_expr  */
  YYSYMBOL_for_RHS = 116,                  /* for_RHS  */
  YYSYMBOL_while_loop = 117,               /* while_loop  */
  YYSYMBOL_118_13 = 118,                   /* $@13  */
  YYSYMBOL_expr_stmt = 119,                /* expr_stmt  */
  YYSYMBOL_120_14 = 120,                   /* $@14  */
  YYSYMBOL_LHS = 121,                      /* LHS  */
  YYSYMBOL_myId = 122,                     /* myId  */
  YYSYMBOL_declr_stmt = 123,               /* declr_stmt  */
  YYSYMBOL_declr_body = 124,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 125,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 126,              /* matrix_list  */
  YYSYMBOL_id_list = 127,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 128,              /* ifcond_stmt  */
  YYSYMBOL_129_15 = 129,                   /* $@15  */
  YYSYMBOL_if_body = 130,                  /* if_body  */
  YYSYMBOL_switch_stmt = 131,              /* switch_stmt  */
  YYSYMBOL_132_16 = 132,                   /* $@16  */
  YYSYMBOL_switch_body = 133,              /* switch_body  */
  YYSYMBOL_134_17 = 134,                   /* $@17  */
  YYSYMBOL_cases = 135,                    /* cases  */
  YYSYMBOL_136_18 = 136,                   /* $@18  */
  YYSYMBOL_137_19 = 137,                   /* $@19  */
  YYSYMBOL_RHS = 138,                      /* RHS  */
  YYSYMBOL_constants = 139,                /* constants  */
  YYSYMBOL_extra_consts = 140,             /* extra_consts  */
  YYSYMBOL_array_const = 141,              /* array_const  */
  YYSYMBOL_val_list = 142,                 /* val_list  */
  YYSYMBOL_resultant = 143,                /* resultant  */
  YYSYMBOL_impr = 144,                     /* impr  */
  YYSYMBOL_graph_impr = 145,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 146,              /* matrix_impr  */
  YYSYMBOL_matr_body = 147,                /* matr_body  */
  YYSYMBOL_graph_const = 148,              /* graph_const  */
  YYSYMBOL_graph_type1 = 149,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 150,              /* graph_type2  */
  YYSYMBOL_int_list = 151,                 /* int_list  */
  YYSYMBOL_float_list = 152,               /* float_list  */
  YYSYMBOL_char_list = 153,                /* char_list  */
  YYSYMBOL_bool_list = 154,                /* bool_list  */
  YYSYMBOL_str_list = 155,                 /* str_list  */
  YYSYMBOL_weight_list = 156,              /* weight_list  */
  YYSYMBOL_vect_const = 157,               /* vect_const  */
  YYSYMBOL_vect_list = 158,                /* vect_list  */
  YYSYMBOL_matrix_const = 159,             /* matrix_const  */
  YYSYMBOL_int_float_list = 160,           /* int_float_list  */
  YYSYMBOL_mat_list = 161,                 /* mat_list  */
  YYSYMBOL_arith_op = 162,                 /* arith_op  */
  YYSYMBOL_binary_op = 163,                /* binary_op  */
  YYSYMBOL_unary_op = 164,                 /* unary_op  */
  YYSYMBOL_logical_op = 165,               /* logical_op  */
  YYSYMBOL_call_stmt = 166,                /* call_stmt  */
  YYSYMBOL_func_calls = 167,               /* func_calls  */
  YYSYMBOL_call_head = 168,                /* call_head  */
  YYSYMBOL_arguments = 169,                /* arguments  */
  YYSYMBOL_arg_list = 170                  /* arg_list  */
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
#define YYLAST   968

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  468

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
       0,   119,   119,   122,   123,   126,   127,   128,   131,   142,
     131,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   165,
     166,   169,   170,   174,   185,   173,   188,   189,   192,   196,
     205,   219,   220,   224,   225,   229,   230,   234,   256,   263,
     264,   265,   266,   275,   294,   294,   295,   298,   299,   300,
     301,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   318,   321,   322,   326,   325,   337,   340,
     343,   347,   350,   357,   367,   368,   369,   370,   371,   372,
     373,   377,   378,   380,   380,   391,   390,   402,   401,   413,
     412,   423,   423,   426,   426,   441,   444,   445,   448,   451,
     452,   466,   467,   468,   469,   470,   471,   474,   474,   487,
     502,   501,   551,   552,   553,   557,   616,   700,   701,   712,
     714,   739,   764,   789,   814,   839,   875,   886,   899,   911,
     925,   930,   937,   937,   952,   953,   956,   956,   971,   971,
     974,   974,   975,   975,   980,   981,   982,   983,   984,   988,
     989,   990,   991,   992,   993,   997,   998,   999,  1000,  1001,
    1004,  1005,  1008,  1009,  1010,  1011,  1012,  1015,  1016,  1017,
    1018,  1019,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1032,
    1033,  1034,  1035,  1039,  1042,  1043,  1046,  1047,  1050,  1051,
    1054,  1059,  1066,  1071,  1078,  1083,  1090,  1091,  1094,  1095,
    1098,  1099,  1102,  1103,  1106,  1111,  1116,  1121,  1128,  1131,
    1132,  1133,  1134,  1137,  1140,  1144,  1148,  1152,  1158,  1163,
    1171,  1172,  1175,  1191,  1201,  1215,  1225,  1230,  1248,  1261,
    1262,  1265,  1299
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
  "unary_stmt", "jump_stmt", "label_stmt", "$@6", "goto_stmt", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "loop_stmt", "loop_type",
  "for_loop", "for_expr", "for_RHS", "while_loop", "$@13", "expr_stmt",
  "$@14", "LHS", "myId", "declr_stmt", "declr_body",
  "graph_and_array_list", "matrix_list", "id_list", "ifcond_stmt", "$@15",
  "if_body", "switch_stmt", "$@16", "switch_body", "$@17", "cases", "$@18",
  "$@19", "RHS", "constants", "extra_consts", "array_const", "val_list",
  "resultant", "impr", "graph_impr", "matrix_impr", "matr_body",
  "graph_const", "graph_type1", "graph_type2", "int_list", "float_list",
  "char_list", "bool_list", "str_list", "weight_list", "vect_const",
  "vect_list", "matrix_const", "int_float_list", "mat_list", "arith_op",
  "binary_op", "unary_op", "logical_op", "call_stmt", "func_calls",
  "call_head", "arguments", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-332)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-182)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   518,   518,   150,    37,  -332,    29,  -332,  -332,  -332,
      -6,     4,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
      15,    28,  -332,  -332,  -332,  -332,     5,  -332,   518,  -332,
    -332,  -332,     3,  -332,   687,  -332,  -332,  -332,   291,  -332,
    -332,   829,  -332,    -4,  -332,   518,     2,    63,    34,   425,
      44,    49,    61,    62,    70,   884,   518,   518,    53,    74,
      75,    77,   518,   -20,   829,    81,   829,  -332,  -332,  -332,
    -332,  -332,    84,  -332,  -332,  -332,   131,  -332,  -332,  -332,
    -332,    79,  -332,  -332,  -332,    90,  -332,    91,    94,  -332,
     291,    88,    97,     2,  -332,  -332,   101,    63,  -332,  -332,
    -332,  -332,  -332,  -332,   100,   105,   108,   547,   746,   120,
     110,   122,    16,   123,  -332,   126,  -332,   118,   128,   142,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   746,  -332,
    -332,   746,   746,   518,   518,   518,   141,   518,   148,    11,
     131,   149,   153,  -332,  -332,  -332,   746,   746,   746,   151,
     746,   147,  -332,  -332,  -332,  -332,   518,   457,  -332,  -332,
     634,  -332,  -332,   152,  -332,  -332,  -332,  -332,   746,   746,
    -332,   155,  -332,   131,   156,   158,   159,   165,   167,  -332,
     200,   166,   170,   171,   172,   173,    92,  -332,   174,  -332,
    -332,  -332,  -332,  -332,   175,  -332,  -332,  -332,  -332,  -332,
     176,   179,   180,    36,  -332,  -332,   181,  -332,   183,  -332,
     291,   185,  -332,  -332,   486,   205,   746,   186,   189,  -332,
     187,   191,  -332,   178,    -6,  -332,   198,   203,   207,   208,
     217,   220,   222,   223,   227,   228,   229,   230,   231,   232,
     233,  -332,  -332,    41,  -332,   184,   201,   234,   236,  -332,
      19,   573,   573,  -332,  -332,  -332,   746,   294,   290,   293,
     296,   292,   239,   242,   241,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,   518,   302,   303,   246,   249,
     254,   255,   256,   257,    -1,   258,   746,   746,   746,  -332,
    -332,   486,   776,   259,   260,   261,   776,   262,   263,   776,
     264,   776,   266,   267,   776,   776,  -332,   746,  -332,  -332,
     746,  -332,   313,   288,   289,  -332,  -332,   295,  -332,  -332,
    -332,  -332,  -332,    92,    92,   298,    -6,   301,  -332,   285,
     287,   518,  -332,  -332,  -332,  -332,  -332,   300,  -332,   299,
     304,   306,   307,  -332,  -332,  -332,  -332,   308,    16,   118,
    -332,  -332,  -332,  -332,  -332,  -332,   309,  -332,  -332,   310,
    -332,   314,  -332,  -332,   315,   316,  -332,   318,   319,   351,
     357,  -332,  -332,  -332,   312,   365,  -332,  -332,  -332,   320,
     322,  -332,  -332,     9,    -6,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,   776,   776,   776,  -332,   102,   251,  -332,   321,
    -332,  -332,    -6,   361,   518,   382,   518,   326,  -332,  -332,
     328,   331,   333,   334,   335,   294,   338,  -332,   395,    89,
    -332,   336,    13,    -6,  -332,  -332,  -332,   339,   342,  -332,
     401,   340,   344,   913,  -332,   338,   338,   341,  -332,    -6,
     518,   343,  -332,   118,   346,   187,  -332,  -332,  -332,  -332,
      -6,   345,   352,  -332,  -332,    -6,  -332,  -332
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
      23,     0,     0,   127,    60,     0,    58,    69,    66,    74,
      75,    70,   180,    68,    67,    61,   177,   125,    63,    64,
      65,     0,   181,   179,   178,     0,    62,     0,     0,    42,
       0,    47,     0,    30,    32,    31,     0,    37,    52,   159,
     160,   161,   162,   163,     0,     0,     0,     0,     0,     0,
     127,   180,   164,     0,   154,     0,   165,   158,   179,   178,
     166,   167,   168,   155,   230,   231,   156,   157,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    79,     0,     0,    73,   236,
       0,   237,    45,     0,     9,    29,    34,    36,     0,     0,
     103,   159,   169,   164,   220,   222,     0,     0,     0,   180,
       0,   205,   207,   209,   213,   211,     0,   171,     0,   172,
     173,   174,   175,   176,     0,   101,    93,    95,    97,    99,
       0,     0,     0,   141,   134,   130,     0,   133,     0,   131,
       0,   141,   135,   129,     0,     0,     0,     0,     0,   196,
     197,     0,    78,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,     0,    48,     0,     0,     0,     0,   104,
       0,     0,     0,   198,   199,   218,     0,     0,     0,     0,
       0,     0,   226,   227,     0,   170,   223,   102,    94,    96,
      98,   100,   142,   146,   233,     0,     0,     0,     0,   180,
       0,     0,   179,   178,     0,     0,     0,     0,     0,   128,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,     0,    10,    35,
       0,   235,     0,     0,     0,   219,   221,     0,   204,   206,
     208,   212,   210,     0,     0,     0,     0,     0,   140,     0,
       0,     0,   124,   119,   120,   122,   123,     0,   117,     0,
       0,     0,     0,    91,    92,    84,    85,     0,    86,    90,
      88,    89,    87,   182,    82,    83,     0,   194,   184,     0,
     185,     0,   195,   190,     0,     0,   242,     0,     0,   201,
     203,   234,   224,   225,   229,   145,   143,   148,   147,   137,
       0,   132,   121,     0,     0,   186,   188,   193,    80,    81,
     183,   189,     0,     0,     0,   232,     0,     0,   200,     0,
     202,   228,     0,     0,     0,     0,     0,     0,   109,   118,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
     136,     0,     0,     0,   187,   191,   192,   215,   217,   152,
       0,     0,   139,     0,   108,     0,     0,     0,   150,     0,
       0,   115,   110,   113,   114,   116,   111,   112,   214,   216,
       0,     0,     0,   138,   153,     0,   149,   151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -332,  -332,   403,  -332,  -332,  -332,  -332,     1,   317,  -332,
    -332,  -332,  -332,   311,   -27,  -332,  -332,  -332,  -332,  -332,
     324,     7,   -10,  -332,   -26,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,   -46,  -246,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   192,
    -332,   -50,   250,   -15,  -332,  -136,   -31,  -133,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   -47,   -98,
     -44,  -332,  -332,  -332,   -40,   -52,   -53,   124,  -332,    42,
      45,  -101,   168,   157,   163,   177,  -331,  -332,  -145,  -332,
    -215,    43,  -228,  -332,   -43,  -173,  -332,   -30,  -332,  -332,
    -332
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,   161,
      80,    81,   189,   357,   352,    83,   278,   279,   280,   281,
     277,   259,    84,   153,   154,   417,   452,   155,   394,    85,
     392,   122,    87,    88,   148,   214,   217,   215,    89,   336,
     386,    90,   337,   388,   413,   429,   461,   447,   229,   124,
     185,   126,   198,    91,   127,    93,    94,   231,   130,   186,
     187,   323,   200,   201,   202,   203,   324,   131,   188,   132,
     274,   204,   133,   134,   135,   136,    96,   137,    98,   171,
     253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    86,    30,    31,    37,    82,   129,   128,    95,   219,
      39,    92,   123,   121,   222,   125,   149,   150,   199,   184,
     166,    97,   166,   191,    86,   166,    86,   115,    82,   104,
      82,    95,    65,    95,    92,     3,    92,    40,    64,    49,
     416,   105,   107,   160,    97,    37,    97,   -76,   162,    37,
     164,    42,    73,     1,     2,    58,   101,    99,   100,   118,
     366,    50,     3,   369,    44,   371,   147,   183,   374,   375,
      48,   190,    46,   159,   360,    73,   104,    73,   360,   322,
     224,   360,   443,   360,  -177,    47,   360,   360,   105,   151,
     152,   210,   107,    65,   211,   212,   272,   273,   285,   286,
     108,    37,   316,   317,   138,   230,   423,   424,   139,   227,
     228,   440,   441,   233,   458,   459,   325,   326,   382,   383,
     140,   347,   141,   252,   191,   192,   193,   194,   195,   361,
     142,   257,   258,   361,   156,   157,   361,   158,   361,   163,
     166,   361,   361,   165,   213,   216,   218,   167,   221,   168,
     169,   173,   338,    12,   170,   174,   420,   421,   422,   176,
     178,    32,    33,   184,   184,   179,   328,   180,    34,    35,
      36,   293,   292,   160,   360,   360,   360,   290,   289,   295,
     291,   205,   206,   196,   197,   207,  -181,   208,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   209,    26,    27,    28,    29,   220,   223,   391,   225,
     232,   183,   183,   226,   234,   456,   254,   263,   261,   327,
     262,    37,   260,   264,   300,   265,   266,   288,   267,   361,
     361,   361,   268,   269,   270,   271,    66,   282,   275,   276,
     283,   284,   299,   318,   287,   230,   286,   285,   296,   349,
     350,   297,   358,   298,   353,  -178,   358,   354,   301,   358,
     319,   358,   359,   302,   358,   358,   359,   303,   304,   359,
     376,   359,   362,   377,   359,   359,   362,   305,   430,   362,
     306,   362,   307,   308,   362,   362,   221,   309,   310,   311,
     312,   313,   314,   315,    12,   192,   320,   321,   191,   193,
     195,   333,    32,   194,   334,   335,   339,   340,   342,    34,
      35,    36,   341,   343,   344,   345,   346,   378,   425,   348,
     363,   364,   365,   367,   368,   370,   385,   372,   373,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   221,    26,    27,    28,    29,   379,   380,   389,
     418,   390,   358,   358,   358,   407,   381,   384,   387,   393,
     395,   409,   359,   359,   359,   396,   432,   397,   398,   399,
     400,   401,   362,   362,   362,   196,   402,   403,   404,   405,
     412,   406,   414,   428,   419,   415,   431,   433,   426,   434,
     455,   454,   435,    86,   436,   437,   438,   451,   322,   439,
     442,   445,   427,   453,   446,   448,   450,   449,   460,    41,
     466,  -180,   465,   457,  -179,   218,   235,   294,   177,   463,
     175,   408,   351,   444,   172,   410,   330,   411,    12,   109,
     110,   111,   112,   113,   332,     0,   329,     0,     0,   462,
       0,     0,     0,     0,     0,     0,     0,   331,     0,     0,
     464,   216,   114,   115,    64,   467,     0,    67,     0,     0,
     116,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,     0,   117,     0,     0,   118,     0,     0,   119,    12,
     109,   110,   111,   112,   113,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,   247,
     248,   249,   250,   114,   115,    64,     0,     0,    67,     0,
       0,    12,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,     0,   117,     0,     0,   118,     0,     0,   119,
      12,   181,   110,   111,   112,   113,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,    12,   109,   110,   111,
     112,   113,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,     0,   117,   182,     0,     0,     0,     0,
     119,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
     117,     0,     0,     0,     0,     0,   119,    12,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,    64,     0,     0,    67,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    69,    70,    71,    26,    27,    28,    29,
      12,     0,     0,     0,   118,   251,     0,     0,    32,     0,
       0,     0,     0,     0,     0,    34,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,     0,     0,     0,     0,     0,    52,    12,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,    64,     0,     0,    67,    12,
     355,   356,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,     0,   114,   115,    64,   118,     0,    67,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,    12,     0,     0,     0,   118,     0,     0,     0,
       0,     0,    59,    60,     0,    61,    62,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,    68,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29,    72,    42,    12,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,   144,   145,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
     114,     0,    64,     0,     0,    67,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
      10,    51,     1,     2,     3,    51,    59,    59,    51,   145,
       3,    51,    59,    59,   147,    59,    66,    67,   119,   117,
       9,    51,     9,     4,    74,     9,    76,    28,    74,    56,
      76,    74,    30,    76,    74,    33,    76,     0,    29,    38,
      31,    56,    57,    63,    74,    44,    76,    67,    74,    48,
      76,    57,    51,    24,    25,    48,    55,    61,    62,    60,
     306,    58,    33,   309,    60,   311,    65,   117,   314,   315,
      65,   118,    57,    72,   302,    74,   103,    76,   306,    60,
      69,   309,    69,   311,    68,    57,   314,   315,   103,    36,
      37,   138,   107,    30,   141,   142,     4,     5,    62,    63,
      66,   100,    61,    62,    60,   158,     4,     5,    59,   156,
     157,    22,    23,   160,   445,   446,   261,   262,   333,   334,
      59,   294,    60,   170,     4,     5,     6,     7,     8,   302,
      60,   178,   179,   306,    60,    60,   309,    60,   311,    58,
       9,   314,   315,    59,   143,   144,   145,    68,   147,    59,
      59,    63,   285,     3,    60,    58,   402,   403,   404,    58,
      60,    11,    12,   261,   262,    60,   267,    59,    18,    19,
      20,   224,   224,    63,   402,   403,   404,   224,   224,   226,
     224,    59,    59,    63,    64,    59,    68,    59,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    59,    52,    53,    54,    55,    65,    59,   341,    60,
      59,   261,   262,    60,    67,   443,    64,    58,    62,   266,
      62,   220,    67,    58,   234,    58,    26,   220,    62,   402,
     403,   404,    62,    62,    62,    62,    31,    61,    64,    64,
      61,    61,    64,    59,    63,   298,    63,    62,    62,   296,
     297,    62,   302,    62,   301,    68,   306,   301,    60,   309,
      59,   311,   302,    60,   314,   315,   306,    60,    60,   309,
     317,   311,   302,   320,   314,   315,   306,    60,   414,   309,
      60,   311,    60,    60,   314,   315,   285,    60,    60,    60,
      60,    60,    60,    60,     3,     5,    62,    61,     4,     6,
       8,    62,    11,     7,    62,    64,     4,     4,    59,    18,
      19,    20,    66,    59,    59,    59,    59,     4,    67,    61,
      61,    61,    61,    61,    61,    61,   336,    61,    61,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   341,    52,    53,    54,    55,    59,    59,    64,
     393,    64,   402,   403,   404,     4,    61,    59,    57,    59,
      61,     4,   402,   403,   404,    61,   416,    61,    61,    61,
      61,    61,   402,   403,   404,    63,    62,    62,    62,    61,
      15,    62,    62,    22,   394,    63,     4,    61,    67,    61,
     443,   443,    61,   443,    61,    61,    61,   443,    60,     4,
      64,    62,   412,   443,    62,     4,    62,    67,    67,     6,
      58,    68,    67,   443,    68,   414,   166,   225,   107,   450,
     103,   379,   298,   433,   100,   380,   269,   384,     3,     4,
       5,     6,     7,     8,   271,    -1,   268,    -1,    -1,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
     460,   450,    27,    28,    29,   465,    -1,    32,    -1,    -1,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    60,    -1,    -1,    63,     3,
       4,     5,     6,     7,     8,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    52,
      53,    54,    55,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,     3,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    63,
       3,     4,     5,     6,     7,     8,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,
      63,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       3,    -1,    -1,    -1,    60,    61,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,     3,
       4,     5,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    27,    28,    29,    60,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      27,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55
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
     100,   101,   102,   105,   112,   119,   121,   122,   123,   128,
     131,   143,   144,   145,   146,   164,   166,   167,   168,    61,
      62,    77,    78,    79,    84,   123,    83,   123,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   102,   121,   138,   139,   140,   141,   144,   145,   146,
     148,   157,   159,   162,   163,   164,   165,   167,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   124,   121,
     121,    36,    37,   113,   114,   117,    60,    60,    60,    77,
      63,    99,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   169,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   121,   139,   140,   149,   150,   158,   102,
     138,     4,     5,     6,     7,     8,    63,    64,   142,   151,
     152,   153,   154,   155,   161,    59,    59,    59,    59,    59,
     138,   138,   138,    77,   125,   127,    77,   126,    77,   125,
      65,    77,   127,    59,    69,    60,    60,   138,   138,   138,
     146,   147,    59,   138,    67,   122,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   138,   170,    64,    76,    82,   138,   138,   111,
      67,    62,    62,    58,    58,    58,    26,    62,    62,    62,
      62,    62,     4,     5,   160,    64,    64,   110,   106,   107,
     108,   109,    61,    61,    61,    62,    63,    63,    91,   102,
     138,   140,   145,   146,   119,   138,    62,    62,    62,    64,
      92,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    59,    59,
      62,    61,    60,   151,   156,   158,   158,   138,   151,   152,
     153,   155,   154,    62,    62,    64,   129,   132,   127,     4,
       4,    66,    59,    59,    59,    59,    59,   165,    61,   138,
     138,   147,   104,   138,   140,     4,     5,   103,   121,   144,
     162,   165,   167,    61,    61,    61,   103,    61,    61,   103,
      61,   103,    61,    61,   103,   103,   138,   138,     4,    59,
      59,    61,   160,   160,    59,    92,   130,    57,   133,    64,
      64,   127,   120,    59,   118,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    61,    62,     4,   149,     4,
     150,   161,    15,   134,    62,    63,    31,   115,   164,    92,
     103,   103,   103,     4,     5,    67,    67,    92,    22,   135,
     125,     4,   121,    61,    61,    61,    61,    61,    61,     4,
      22,    23,    64,    69,    92,    62,    62,   137,     4,    67,
      62,   102,   116,   144,   145,   146,   162,   167,   156,   156,
      67,   136,    92,   126,    92,    67,    58,    92
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
      95,    95,    95,    96,    97,    97,    99,    98,   100,   101,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   106,   105,   107,   105,   108,   105,   109,
     105,   110,   105,   111,   105,   112,   113,   113,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   118,   117,   119,
     120,   119,   119,   119,   119,   121,   121,   122,   122,   123,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   129,   128,   130,   130,   132,   131,   134,   133,
     136,   135,   137,   135,   138,   138,   138,   138,   138,   139,
     139,   139,   139,   139,   139,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   145,
     145,   145,   145,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   156,   156,   157,   158,
     158,   158,   158,   159,   160,   160,   160,   160,   161,   161,
     162,   162,   163,   164,   165,   165,   166,   167,   168,   169,
     169,   170,   170
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
       1,     2,     2,     2,     1,     1,     0,     4,     3,     2,
       6,     6,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     2,     1,     1,     8,     1,
       4,     1,     1,     1,     1,     1,     1,     0,     6,     5,
       0,     6,     5,     5,     5,     1,     3,     1,     4,     3,
       2,     2,     5,     2,     2,     2,     6,     4,     9,     7,
       3,     1,     0,     6,     3,     1,     0,     6,     0,     7,
       0,     6,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     5,     5,     6,     8,     6,     6,
       5,     8,     8,     6,     5,     5,     1,     1,     3,     3,
       5,     4,     5,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     7,     5,     7,     5,     3,     3,
       1,     3,     1,     3,     3,     3,     1,     1,     5,     4,
       1,     1,     6,     4,     5,     4,     2,     2,     2,     3,
       2,     1,     3
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
#line 131 "parser.y"
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
#line 1892 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 142 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1898 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 142 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1904 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 145 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1910 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 146 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1916 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 147 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1922 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 148 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1928 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 149 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1934 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 150 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1940 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 151 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1946 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 152 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1952 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 153 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1958 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 154 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1964 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 155 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1970 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 156 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1976 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 157 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1982 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 158 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1988 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 159 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1994 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 160 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2000 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 161 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 2006 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 162 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2012 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 174 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									printf("Struct or class name already exists\n");
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].str));
								
							}
#line 2028 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 185 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2034 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 185 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2040 "y.tab.c"
    break;

  case 38: /* function: function_head function_body  */
#line 192 "parser.y"
                                                                      {currentFuncIndex = -1; if(returnStmtCount==0)printf("%d ERROR : Expected atlease one return statement\n", yylineno);
									returnStmtCount = 0;}
#line 2047 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 196 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2058 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 205 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							if(inClass == 0) {
								func_insert((yyvsp[0].str), (yyvsp[-1].str));
								currentFuncIndex = func_size - 1;
							}
							else {
								class_func_insert(class_size-1, (yyvsp[0].str), (yyvsp[-1].str));
								currentFuncIndex = class_symb[class_size-1].cl_func_size - 1;
							}
						}
#line 2075 "y.tab.c"
    break;

  case 43: /* fdtype: dtype  */
#line 224 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2081 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 225 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2087 "y.tab.c"
    break;

  case 47: /* param: dtype id  */
#line 234 "parser.y"
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
#line 2114 "y.tab.c"
    break;

  case 48: /* param: dtype id '[' ']'  */
#line 256 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2122 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 263 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2128 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 264 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2134 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 265 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2140 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 266 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2154 "y.tab.c"
    break;

  case 53: /* dtype: id  */
#line 275 "parser.y"
                                                     {
							int i = struct_search((yyvsp[0].str));
							if(i < 0) {
								i = class_search((yyvsp[0].str));
								if(i < 0){
									printf("%d Error: Using undefined datatype %s\n", yylineno, (yyvsp[0].str));
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
#line 2176 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 294 "parser.y"
                                      { level++; }
#line 2182 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 294 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2188 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 314 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2194 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 315 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2200 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 318 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2206 "y.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 326 "parser.y"
                                                        {
								if(label_search((yyvsp[0].str))!=-1) 
								{
									printf("Label name already exists\n");
									exit(1);
								}
								else label_insert((yyvsp[0].str));
							}
#line 2219 "y.tab.c"
    break;

  case 77: /* label_stmt: id $@6 ':' function_body  */
#line 334 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2225 "y.tab.c"
    break;

  case 78: /* goto_stmt: GOTO id ';'  */
#line 337 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2231 "y.tab.c"
    break;

  case 79: /* vect_stmt: vect_stmt_body ';'  */
#line 340 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2237 "y.tab.c"
    break;

  case 80: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 343 "parser.y"
                                                                           { 
					if(strcmp((yyvsp[-5].str),(yyvsp[-1].str))){printf("ERROR: appending the wrong dtype\n");} 
					(yyval.str) = (yyvsp[-5].str);
				}
#line 2246 "y.tab.c"
    break;

  case 81: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 347 "parser.y"
                                                                                           {
						
						}
#line 2254 "y.tab.c"
    break;

  case 82: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 350 "parser.y"
                                                                             {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2266 "y.tab.c"
    break;

  case 83: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 357 "parser.y"
                                                                              {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2278 "y.tab.c"
    break;

  case 84: /* remove_body: INT_CONST  */
#line 367 "parser.y"
                                                    {(yyval.str)="int";}
#line 2284 "y.tab.c"
    break;

  case 85: /* remove_body: FLOAT_CONST  */
#line 368 "parser.y"
                                                              {(yyval.str)="float";}
#line 2290 "y.tab.c"
    break;

  case 86: /* remove_body: LHS  */
#line 369 "parser.y"
                                                      {(yyval.str)=(yyvsp[0].details).type;}
#line 2296 "y.tab.c"
    break;

  case 87: /* remove_body: func_calls  */
#line 370 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2302 "y.tab.c"
    break;

  case 88: /* remove_body: arith_op  */
#line 371 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2308 "y.tab.c"
    break;

  case 89: /* remove_body: logical_op  */
#line 372 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2314 "y.tab.c"
    break;

  case 90: /* remove_body: impr  */
#line 373 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 2320 "y.tab.c"
    break;

  case 93: /* $@7: %empty  */
#line 380 "parser.y"
                                               { returnStmtCount++;
					if(inClass==0){		
						if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("%d ERROR : func type and return type are mismatched\n",yylineno);}
					}
					else{
						if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
							printf("%d ERROR : func type and return type are mismatched\n",yylineno);
						}
					}
				}
#line 2335 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN RHS ';' $@7  */
#line 389 "parser.y"
                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2341 "y.tab.c"
    break;

  case 95: /* $@8: %empty  */
#line 391 "parser.y"
                                                 {	returnStmtCount++;
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("%d ERROR : func type and return type are mismatched\n",yylineno);}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
						 }
#line 2356 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN extra_consts ';' $@8  */
#line 400 "parser.y"
                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2362 "y.tab.c"
    break;

  case 97: /* $@9: %empty  */
#line 402 "parser.y"
                                                {	returnStmtCount++;
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("%d ERROR : func type and return type are mismatched\n",yylineno);}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n", yylineno);
								}
							}
						 }
#line 2377 "y.tab.c"
    break;

  case 98: /* return_stmt: RETURN graph_impr ';' $@9  */
#line 411 "parser.y"
                                                   {fprintf(fparse, " : RETURN STATEMENT");}
#line 2383 "y.tab.c"
    break;

  case 99: /* $@10: %empty  */
#line 413 "parser.y"
                                                {	returnStmtCount++;
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("%d ERROR : func type and return type are mismatched\n",yylineno);}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
							}
#line 2398 "y.tab.c"
    break;

  case 100: /* return_stmt: RETURN matrix_impr ';' $@10  */
#line 422 "parser.y"
                                                           {fprintf(fparse, " : RETURN STATEMENT");}
#line 2404 "y.tab.c"
    break;

  case 101: /* $@11: %empty  */
#line 423 "parser.y"
                                                                            {
							 returnStmtCount++;
							}
#line 2412 "y.tab.c"
    break;

  case 102: /* return_stmt: RETURN vect_stmt_body ';' $@11  */
#line 425 "parser.y"
                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 2418 "y.tab.c"
    break;

  case 103: /* $@12: %empty  */
#line 426 "parser.y"
                                                                 {
							returnStmtCount++;
							if(inClass==0){
								if(strcmp("void",func_symb[currentFuncIndex].type)){printf("%d ERROR : func type and return type are mismatched\n", yylineno);}
							}
							else{
								if(strcmp("void",class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
							}
#line 2434 "y.tab.c"
    break;

  case 104: /* return_stmt: RETURN null ';' $@12  */
#line 436 "parser.y"
                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2440 "y.tab.c"
    break;

  case 105: /* loop_stmt: LOOP loop_type  */
#line 441 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2446 "y.tab.c"
    break;

  case 110: /* for_expr: EXPR LHS '=' for_RHS  */
#line 452 "parser.y"
                                                                       {
							if(strcmp((yyvsp[-2].details).type, (yyvsp[0].str))){
								int a = !strcmp((yyvsp[-2].details).type, "int") || !strcmp((yyvsp[-2].details).type, "float") || !strcmp((yyvsp[-2].details).type, "bool");
								int b = !strcmp((yyvsp[0].str), "int") || !strcmp((yyvsp[0].str), "float") || !strcmp((yyvsp[0].str), "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", (yyvsp[-2].details).name, (yyvsp[-2].details).type, (yyvsp[0].str));
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
						}
#line 2463 "y.tab.c"
    break;

  case 111: /* for_RHS: arith_op  */
#line 466 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2469 "y.tab.c"
    break;

  case 112: /* for_RHS: func_calls  */
#line 467 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2475 "y.tab.c"
    break;

  case 113: /* for_RHS: impr  */
#line 468 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2481 "y.tab.c"
    break;

  case 114: /* for_RHS: graph_impr  */
#line 469 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2487 "y.tab.c"
    break;

  case 115: /* for_RHS: vect_stmt_body  */
#line 470 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2493 "y.tab.c"
    break;

  case 116: /* for_RHS: matrix_impr  */
#line 471 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2499 "y.tab.c"
    break;

  case 117: /* $@13: %empty  */
#line 474 "parser.y"
                                                          {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
						}
#line 2515 "y.tab.c"
    break;

  case 119: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 487 "parser.y"
                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].str))){
								int a = !strcmp((yyvsp[-3].details).type, "int") || !strcmp((yyvsp[-3].details).type, "float") || !strcmp((yyvsp[-3].details).type, "bool");
								int b = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-1].str), "bool");
							
								if(!(a && b)){
									printf("%s:%s != <name>:%s\n", (yyvsp[-3].details).name, (yyvsp[-3].details).type, (yyvsp[-1].str));
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 2534 "y.tab.c"
    break;

  case 120: /* $@14: %empty  */
#line 502 "parser.y"
                                                        {
								int dimAval, dimBval;
								int ind = var_search((yyvsp[-3].details).name);
								if(ind==-1) 
								{
									ind = class_declr_search((yyvsp[-3].details).name, class_size-1);
									dimAval = class_symb[class_size-1].declr_list[ind].dim_A;
									dimBval = class_symb[class_size-1].declr_list[ind].dim_B;
								}
								else
								{
									dimAval = var_symb[ind].dim_A;
									dimBval = var_symb[ind].dim_B;
								}
								
								 

								if(strcmp("graph", (yyvsp[-3].details).type)==0)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(dimA[i]>dimAval)
										{
											printf("%d ERROR: Vertex used is not present in the graph\n", yylineno);
											exit(1);
										}
									}
									arr_size=0;
								}
								else if(strcmp("matrix", (yyvsp[-3].details).type)==0)
								{
									if(arr_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										exit(1);
									}
									for(int i=0; i<arr_size; i++)
									{
										if(dimA[i]!=dimBval)
										{
											printf("%d ERROR: Number of columns mismatch\n", yylineno);
											exit(1);
										}
									}
									arr_size=0;
								}
							}
#line 2586 "y.tab.c"
    break;

  case 121: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@14  */
#line 549 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2592 "y.tab.c"
    break;

  case 122: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 551 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2598 "y.tab.c"
    break;

  case 123: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 552 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2604 "y.tab.c"
    break;

  case 124: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 553 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2610 "y.tab.c"
    break;

  case 125: /* LHS: myId  */
#line 557 "parser.y"
                                                       {
							// indicates it is independent function(for call statements)
							classIndex = -1; // stores index of LHS dataType(class)
							int i = var_search((yyvsp[0].str));
							// printf("%s - %d\n", $1, i);
							if(i < 0){
							
								if(inClass){
									i = class_declr_search((yyvsp[0].str), class_size-1); // search in current class
									if(i < 0){
										// statement is in class, yet LHS not in symbol table
										printf("%d Error: Accessing undeclared identifier %s\n", yylineno, (yyvsp[0].str));
										exit(1);
									}
									
									else{
										(yyval.details).name = (yyvsp[0].str);
										// $$.type = class_symb[class_size-1].declr_list[i].type;
										if(strcmp(class_symb[class_size-1].declr_list[i].type, "vect") == 0){
										    char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(class_symb[class_size-1].declr_list[i].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, class_symb[class_size-1].declr_list[i].ele_type);
										    // dataType = 2;
						   				     (yyval.details).type = result;
										}
										else {
											(yyval.details).type = class_symb[class_size-1].declr_list[i].type;
										}
										classIndex=class_size-1;
									}
								}
								
								else{
									// statement not in class & LHS not in symbol table
									printf("%d Error: Accessing undeclared identifier %s\n", yylineno, (yyvsp[0].str));
									exit(1);
								}
							}
							
							else{
								// myId exists in var_symb ==> declared inside function
								(yyval.details).name = (yyvsp[0].str);
								// $$.type = var_symb[i].type;
								if(!strcmp(var_symb[i].type, "vect")){
									char* result;
									char* A = "*";
									result = (char*)malloc(strlen(A) + strlen(var_symb[i].ele_type) + 1);
									 strcpy(result, A);
					     			    	strcat(result, var_symb[i].ele_type);
										    // dataType = 2;
						   			(yyval.details).type = result;
								}
								else{
									(yyval.details).type = var_symb[i].type;
								}
							}
						}
#line 2674 "y.tab.c"
    break;

  case 126: /* LHS: LHS ARROW myId  */
#line 616 "parser.y"
                                                                 {
							char* dType = (yyvsp[-2].details).type;
							
							// check if dType is declared in struct or in class
							int i = struct_search(dType);
							if(i < 0){
								i = class_search(dType);
								if(i < 0){
									
									// item is not defined in class and struct
									printf("%d Error: Accessing undefined datatype %s\n", yylineno, dType);
									exit(1);
								}
								
								else{
									
									int j = class_declr_search((yyvsp[0].str), i);
									int k = class_func_search((yyvsp[0].str), i);
									if(j < 0 && k < 0){
										printf("%d Error: Accessing undefined function/attribute %s of class %s\n", yylineno,(yyvsp[0].str), (yyvsp[-2].details).type);
										// printClassNode(class_symb[i]);
										exit(1);
									}
									
									if(j >= 0){
										(yyval.details).name = (yyvsp[0].str);
										(yyval.details).type = class_symb[i].declr_list[j].type;
										
										if(strcmp(class_symb[i].declr_list[j].type, "vect") == 0){
										    char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(class_symb[i].declr_list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, class_symb[i].declr_list[j].type);
										    // dataType = 2;
						   				     (yyval.details).type = result;
										}
										else {
											(yyval.details).type = class_symb[i].declr_list[j].type;	
										}
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
								// item defined in struct, now check its attributes
								int j = struct_declr_search((yyvsp[0].str), i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("%d Error: Accessing undefined attribute of struct %s\n", yylineno, (yyvsp[-2].details).name);
									exit(1);
								}
								
								else{
									(yyval.details).name = (yyvsp[0].str);
									// $$.type = struct_symb[i].list[j].type;
									if(!strcmp(struct_symb[i].list[j].type, "vect")){
										char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(struct_symb[i].list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, struct_symb[i].list[j].ele_type);
										    // dataType = 2;
						   				     (yyval.details).type = result;
									}
									else{
										(yyval.details).type = struct_symb[i].list[j].type;
									}
								}
							}
						}
#line 2760 "y.tab.c"
    break;

  case 127: /* myId: id  */
#line 700 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2766 "y.tab.c"
    break;

  case 128: /* myId: id '[' RHS ']'  */
#line 701 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2779 "y.tab.c"
    break;

  case 129: /* declr_stmt: DECLR declr_body ';'  */
#line 712 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2785 "y.tab.c"
    break;

  case 130: /* declr_body: DATATYPE id_list  */
#line 715 "parser.y"
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
#line 2814 "y.tab.c"
    break;

  case 131: /* declr_body: GRAPH graph_and_array_list  */
#line 740 "parser.y"
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
#line 2843 "y.tab.c"
    break;

  case 132: /* declr_body: VECT '<' dtype '>' id_list  */
#line 765 "parser.y"
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
#line 2872 "y.tab.c"
    break;

  case 133: /* declr_body: MATRIX matrix_list  */
#line 790 "parser.y"
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
#line 2901 "y.tab.c"
    break;

  case 134: /* declr_body: DATATYPE graph_and_array_list  */
#line 815 "parser.y"
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
#line 2930 "y.tab.c"
    break;

  case 135: /* declr_body: id id_list  */
#line 840 "parser.y"
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
#line 2968 "y.tab.c"
    break;

  case 136: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 876 "parser.y"
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
#line 2983 "y.tab.c"
    break;

  case 137: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 887 "parser.y"
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
#line 2998 "y.tab.c"
    break;

  case 138: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 900 "parser.y"
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
#line 3014 "y.tab.c"
    break;

  case 139: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 912 "parser.y"
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
#line 3030 "y.tab.c"
    break;

  case 140: /* id_list: id ',' id_list  */
#line 926 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 3039 "y.tab.c"
    break;

  case 141: /* id_list: id  */
#line 931 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 3048 "y.tab.c"
    break;

  case 142: /* $@15: %empty  */
#line 937 "parser.y"
                                                         {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 3065 "y.tab.c"
    break;

  case 146: /* $@16: %empty  */
#line 956 "parser.y"
                                                             {
							int a = !strcmp((yyvsp[-1].str), "int") || 
									!strcmp((yyvsp[-1].str), "float") || 
									!strcmp((yyvsp[-1].str), "bool") ||
									!strcmp((yyvsp[-1].str), "string") ||
									!strcmp((yyvsp[-1].str), "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 3082 "y.tab.c"
    break;

  case 148: /* $@17: %empty  */
#line 971 "parser.y"
                                              {switch_insert(level); level++;}
#line 3088 "y.tab.c"
    break;

  case 149: /* switch_body: '{' $@17 cases DEFAULT ':' function_body '}'  */
#line 971 "parser.y"
                                                                                                                   { var_delete(level); level--; switch_delete();}
#line 3094 "y.tab.c"
    break;

  case 150: /* $@18: %empty  */
#line 974 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str));}
#line 3100 "y.tab.c"
    break;

  case 152: /* $@19: %empty  */
#line 975 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str));}
#line 3106 "y.tab.c"
    break;

  case 154: /* RHS: constants  */
#line 980 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 3112 "y.tab.c"
    break;

  case 155: /* RHS: arith_op  */
#line 981 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 3118 "y.tab.c"
    break;

  case 156: /* RHS: logical_op  */
#line 982 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3124 "y.tab.c"
    break;

  case 157: /* RHS: func_calls  */
#line 983 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3130 "y.tab.c"
    break;

  case 158: /* RHS: impr  */
#line 984 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3136 "y.tab.c"
    break;

  case 159: /* constants: INT_CONST  */
#line 988 "parser.y"
                                                    {(yyval.str)="int";}
#line 3142 "y.tab.c"
    break;

  case 160: /* constants: FLOAT_CONST  */
#line 989 "parser.y"
                                                              {(yyval.str)="float";}
#line 3148 "y.tab.c"
    break;

  case 161: /* constants: CHAR_CONST  */
#line 990 "parser.y"
                                                             {(yyval.str)="char";}
#line 3154 "y.tab.c"
    break;

  case 162: /* constants: STR_CONST  */
#line 991 "parser.y"
                                                            {(yyval.str)="string";}
#line 3160 "y.tab.c"
    break;

  case 163: /* constants: BOOL_CONST  */
#line 992 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 3166 "y.tab.c"
    break;

  case 164: /* constants: LHS  */
#line 993 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 3172 "y.tab.c"
    break;

  case 165: /* extra_consts: array_const  */
#line 997 "parser.y"
                                             {(yyval.str) = "2";}
#line 3178 "y.tab.c"
    break;

  case 166: /* extra_consts: graph_const  */
#line 998 "parser.y"
                                                             {(yyval.str)="graph";}
#line 3184 "y.tab.c"
    break;

  case 167: /* extra_consts: vect_const  */
#line 999 "parser.y"
                                                            {(yyval.str)="vect";}
#line 3190 "y.tab.c"
    break;

  case 168: /* extra_consts: matrix_const  */
#line 1000 "parser.y"
                                                              {(yyval.str)="matrix";}
#line 3196 "y.tab.c"
    break;

  case 169: /* extra_consts: '{' '}'  */
#line 1001 "parser.y"
                                                         {(yyval.str)="1";}
#line 3202 "y.tab.c"
    break;

  case 177: /* resultant: LHS  */
#line 1015 "parser.y"
                                             {(yyval.str) = (yyvsp[0].details).type;}
#line 3208 "y.tab.c"
    break;

  case 178: /* resultant: matrix_impr  */
#line 1016 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3214 "y.tab.c"
    break;

  case 179: /* resultant: graph_impr  */
#line 1017 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 3220 "y.tab.c"
    break;

  case 180: /* resultant: vect_stmt_body  */
#line 1018 "parser.y"
                                                                 {(yyval.str) = (yyvsp[0].str);}
#line 3226 "y.tab.c"
    break;

  case 181: /* resultant: impr  */
#line 1019 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3232 "y.tab.c"
    break;

  case 182: /* impr: resultant '.' LENGTH '(' ')'  */
#line 1023 "parser.y"
                                                                      {(yyval.str) = "int";}
#line 3238 "y.tab.c"
    break;

  case 183: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 1024 "parser.y"
                                                                                      {(yyval.str) = "0";}
#line 3244 "y.tab.c"
    break;

  case 184: /* impr: resultant '.' TRACE '(' ')'  */
#line 1025 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3250 "y.tab.c"
    break;

  case 185: /* impr: resultant '.' STRLEN '(' ')'  */
#line 1026 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3256 "y.tab.c"
    break;

  case 186: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 1027 "parser.y"
                                                                             {(yyval.str) = "bool";}
#line 3262 "y.tab.c"
    break;

  case 187: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 1028 "parser.y"
                                                                                                          {(yyval.str) = "string";}
#line 3268 "y.tab.c"
    break;

  case 188: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 1029 "parser.y"
                                                                             {(yyval.str) =  "string";}
#line 3274 "y.tab.c"
    break;

  case 189: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 1032 "parser.y"
                                                                                     {(yyval.str) = "vect";}
#line 3280 "y.tab.c"
    break;

  case 190: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 1033 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3286 "y.tab.c"
    break;

  case 191: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 1034 "parser.y"
                                                                                                          {(yyval.str) = "vect";}
#line 3292 "y.tab.c"
    break;

  case 192: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 1035 "parser.y"
                                                                                                               {(yyval.str) = "int";}
#line 3298 "y.tab.c"
    break;

  case 193: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 1039 "parser.y"
                                                                                {if(strcmp((yyvsp[-3].str),"matrix") || strcmp((yyvsp[-1].str),"matrix")){
											printf("%d, ERROR : argument is not a matrix\n",yylineno);exit(1);}
											(yyval.str) = "matrix";}
#line 3306 "y.tab.c"
    break;

  case 194: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 1042 "parser.y"
                                                                                  {(yyval.str) = "matrix";}
#line 3312 "y.tab.c"
    break;

  case 195: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 1043 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3318 "y.tab.c"
    break;

  case 196: /* matr_body: RHS  */
#line 1046 "parser.y"
                                              {(yyval.str) = (yyvsp[0].str);}
#line 3324 "y.tab.c"
    break;

  case 197: /* matr_body: matrix_impr  */
#line 1047 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3330 "y.tab.c"
    break;

  case 200: /* graph_type1: INT_CONST ':' int_list ';' graph_type1  */
#line 1055 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3339 "y.tab.c"
    break;

  case 201: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 1060 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3348 "y.tab.c"
    break;

  case 202: /* graph_type2: INT_CONST ':' weight_list ';' graph_type2  */
#line 1067 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3357 "y.tab.c"
    break;

  case 203: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 1072 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3366 "y.tab.c"
    break;

  case 204: /* int_list: INT_CONST ',' int_list  */
#line 1079 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-2].str));
								arr_size++;
							}
#line 3375 "y.tab.c"
    break;

  case 205: /* int_list: INT_CONST  */
#line 1084 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[0].str));
								arr_size++;
							}
#line 3384 "y.tab.c"
    break;

  case 214: /* weight_list: '(' INT_CONST ',' INT_CONST ')' ',' weight_list  */
#line 1107 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3393 "y.tab.c"
    break;

  case 215: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 1112 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3402 "y.tab.c"
    break;

  case 216: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list  */
#line 1117 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3411 "y.tab.c"
    break;

  case 217: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 1122 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3420 "y.tab.c"
    break;

  case 224: /* int_float_list: INT_CONST ',' int_float_list  */
#line 1141 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3428 "y.tab.c"
    break;

  case 225: /* int_float_list: FLOAT_CONST ',' int_float_list  */
#line 1145 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3436 "y.tab.c"
    break;

  case 226: /* int_float_list: INT_CONST  */
#line 1149 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3444 "y.tab.c"
    break;

  case 227: /* int_float_list: FLOAT_CONST  */
#line 1153 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3452 "y.tab.c"
    break;

  case 228: /* mat_list: '[' int_float_list ']' ';' mat_list  */
#line 1159 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-3].Cols).cols;
								arr_size++;
							}
#line 3461 "y.tab.c"
    break;

  case 229: /* mat_list: '[' int_float_list ']' ';'  */
#line 1164 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-2].Cols).cols;
								arr_size++;
							}
#line 3470 "y.tab.c"
    break;

  case 232: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 1175 "parser.y"
                                                                      {
							if(!strcmp((yyvsp[-3].str), "int") || !strcmp((yyvsp[-3].str), "bool")|| !strcmp((yyvsp[-3].str), "float")){
								if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool") || !strcmp((yyvsp[-1].str), "float")){
									if(!strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-3].str), "float")) (yyval.str) = "float";
									else (yyval.str) = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3489 "y.tab.c"
    break;

  case 233: /* unary_op: UNARYOP '(' RHS ')'  */
#line 1191 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3502 "y.tab.c"
    break;

  case 234: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 1201 "parser.y"
                                                                {
							if(!strcmp((yyvsp[-3].str), "int") || !strcmp((yyvsp[-3].str), "bool")|| !strcmp((yyvsp[-3].str), "float")){
								if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool") || !strcmp((yyvsp[-1].str), "float")){
									if(!strcmp((yyvsp[-3].str), "float") || !strcmp((yyvsp[-1].str), "float")) (yyval.str) = "float";
									else (yyval.str) = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3521 "y.tab.c"
    break;

  case 235: /* logical_op: NOT '(' RHS ')'  */
#line 1215 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3534 "y.tab.c"
    break;

  case 236: /* call_stmt: func_calls ';'  */
#line 1225 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 3540 "y.tab.c"
    break;

  case 237: /* func_calls: call_head arguments  */
#line 1230 "parser.y"
                                                              {
							(yyval.str) = (yyvsp[-1].str);
							
							int num;
							if(callClassIndex == -1) num = func_symb[callFuncIndex].param_no;
							else num = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							if(myIndex < num) {
								printf("%d Error : Too few functional arguments;\n Expected number of arguments: %d;\n Provided number of arguments: %d\n", yylineno  , num, myIndex);
								exit(1);
							}
							// restore indices to -1 (to be redefined by LHS)
							callClassIndex = -1;
							callFuncIndex = -1;
							myIndex = 0;
						}
#line 3560 "y.tab.c"
    break;

  case 238: /* call_head: CALL LHS  */
#line 1248 "parser.y"
                                                    {
							callClassIndex = classIndex;
							callFuncIndex = funcIndex;
							if(callClassIndex == -1){
								(yyval.str) = func_symb[callFuncIndex].type;
							}
							else{
								(yyval.str) = class_symb[callClassIndex].func_list[callFuncIndex].type;
							}
							myIndex = 0;
						}
#line 3576 "y.tab.c"
    break;

  case 241: /* arg_list: RHS  */
#line 1265 "parser.y"
                                              {

							// tot size; list
							
							int maxSize;
							if(callClassIndex == -1) maxSize = func_symb[callFuncIndex].param_no;
							else maxSize = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							
							if(myIndex >= maxSize){
								printf("%d Error: Excess functional arguments for function %s\n", yylineno, func_symb[callFuncIndex].name);
								exit(1);
							}
							
							else{
								char* myType;
								if(callClassIndex == -1) myType = func_symb[callFuncIndex].args[myIndex];
								else myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
								
								if(strcmp(myType, (yyvsp[0].str))){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp((yyvsp[0].str), "int") || !strcmp((yyvsp[0].str), "float") || !strcmp((yyvsp[0].str), "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex+1, myType, (yyvsp[0].str));
										// exit(1);
									}
									
									else myIndex++;
								}
								
								else myIndex++;
							}
						}
#line 3615 "y.tab.c"
    break;

  case 242: /* arg_list: arg_list ',' RHS  */
#line 1299 "parser.y"
                                                                   {
							int maxSize;
							if(callClassIndex == -1) maxSize = func_symb[callFuncIndex].param_no;
							else maxSize = class_symb[callClassIndex].func_list[callFuncIndex].param_no;
							
							if(myIndex >= maxSize){
								printf("%d Error: Excess functional arguments for function %s\n", yylineno, func_symb[callFuncIndex].name);
								exit(1);
							}
							
							else{
								char* myType;
								if(callClassIndex == -1) myType = func_symb[callFuncIndex].args[myIndex];
								else myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
								
								if(strcmp(myType, (yyvsp[0].str))){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp((yyvsp[0].str), "int") || !strcmp((yyvsp[0].str), "float") || !strcmp((yyvsp[0].str), "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex, myType, (yyvsp[0].str));
										// exit(1);
									}
									
									else myIndex++;
								}
								
								else myIndex++;
							}
						}
#line 3651 "y.tab.c"
    break;


#line 3655 "y.tab.c"

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

#line 1332 "parser.y"


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




