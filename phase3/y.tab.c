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
	int returnStmtCount = 0; //for counting the return statements in a function
	
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
	int dummy_size = 0;
	int newArr[20];
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/

#line 118 "y.tab.c"

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
#line 48 "parser.y"

	char* str;
	struct{
		char* name;
		char* type;
	} details;
	struct
	{
		int cols;
	} Cols;

#line 295 "y.tab.c"

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
  YYSYMBOL_loop_stmt = 111,                /* loop_stmt  */
  YYSYMBOL_loop_type = 112,                /* loop_type  */
  YYSYMBOL_for_loop = 113,                 /* for_loop  */
  YYSYMBOL_for_expr = 114,                 /* for_expr  */
  YYSYMBOL_for_RHS = 115,                  /* for_RHS  */
  YYSYMBOL_while_loop = 116,               /* while_loop  */
  YYSYMBOL_117_12 = 117,                   /* $@12  */
  YYSYMBOL_expr_stmt = 118,                /* expr_stmt  */
  YYSYMBOL_119_13 = 119,                   /* $@13  */
  YYSYMBOL_LHS = 120,                      /* LHS  */
  YYSYMBOL_myId = 121,                     /* myId  */
  YYSYMBOL_declr_stmt = 122,               /* declr_stmt  */
  YYSYMBOL_declr_body = 123,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 124,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 125,              /* matrix_list  */
  YYSYMBOL_id_list = 126,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 127,              /* ifcond_stmt  */
  YYSYMBOL_128_14 = 128,                   /* $@14  */
  YYSYMBOL_if_body = 129,                  /* if_body  */
  YYSYMBOL_switch_stmt = 130,              /* switch_stmt  */
  YYSYMBOL_131_15 = 131,                   /* $@15  */
  YYSYMBOL_switch_body = 132,              /* switch_body  */
  YYSYMBOL_133_16 = 133,                   /* $@16  */
  YYSYMBOL_cases = 134,                    /* cases  */
  YYSYMBOL_135_17 = 135,                   /* $@17  */
  YYSYMBOL_136_18 = 136,                   /* $@18  */
  YYSYMBOL_RHS = 137,                      /* RHS  */
  YYSYMBOL_constants = 138,                /* constants  */
  YYSYMBOL_extra_consts = 139,             /* extra_consts  */
  YYSYMBOL_array_const = 140,              /* array_const  */
  YYSYMBOL_val_list = 141,                 /* val_list  */
  YYSYMBOL_resultant = 142,                /* resultant  */
  YYSYMBOL_impr = 143,                     /* impr  */
  YYSYMBOL_graph_impr = 144,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 145,              /* matrix_impr  */
  YYSYMBOL_matr_body = 146,                /* matr_body  */
  YYSYMBOL_graph_const = 147,              /* graph_const  */
  YYSYMBOL_graph_type1 = 148,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 149,              /* graph_type2  */
  YYSYMBOL_int_list = 150,                 /* int_list  */
  YYSYMBOL_151_19 = 151,                   /* $@19  */
  YYSYMBOL_152_20 = 152,                   /* $@20  */
  YYSYMBOL_float_list = 153,               /* float_list  */
  YYSYMBOL_char_list = 154,                /* char_list  */
  YYSYMBOL_bool_list = 155,                /* bool_list  */
  YYSYMBOL_str_list = 156,                 /* str_list  */
  YYSYMBOL_weight_list = 157,              /* weight_list  */
  YYSYMBOL_vect_const = 158,               /* vect_const  */
  YYSYMBOL_vect_list = 159,                /* vect_list  */
  YYSYMBOL_matrix_const = 160,             /* matrix_const  */
  YYSYMBOL_int_float_list = 161,           /* int_float_list  */
  YYSYMBOL_mat_list = 162,                 /* mat_list  */
  YYSYMBOL_arith_op = 163,                 /* arith_op  */
  YYSYMBOL_binary_op = 164,                /* binary_op  */
  YYSYMBOL_unary_op = 165,                 /* unary_op  */
  YYSYMBOL_logical_op = 166,               /* logical_op  */
  YYSYMBOL_call_stmt = 167,                /* call_stmt  */
  YYSYMBOL_func_calls = 168,               /* func_calls  */
  YYSYMBOL_call_head = 169,                /* call_head  */
  YYSYMBOL_arguments = 170,                /* arguments  */
  YYSYMBOL_arg_list = 171                  /* arg_list  */
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
#define YYLAST   964

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  243
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  469

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
       0,   122,   122,   125,   126,   129,   130,   131,   134,   145,
     134,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   168,
     169,   172,   173,   177,   188,   176,   191,   192,   195,   203,
     212,   236,   237,   241,   242,   246,   247,   251,   273,   280,
     281,   282,   283,   292,   311,   311,   312,   315,   316,   317,
     318,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   335,   338,   339,   343,   342,   354,   357,
     360,   377,   387,   394,   405,   406,   407,   408,   409,   410,
     411,   415,   416,   420,   419,   438,   437,   456,   455,   474,
     473,   491,   505,   504,   526,   529,   530,   533,   536,   537,
     550,   551,   552,   553,   554,   555,   558,   558,   571,   585,
     584,   651,   652,   653,   657,   725,   809,   810,   821,   823,
     868,   913,   958,  1003,  1048,  1104,  1115,  1128,  1140,  1154,
    1159,  1166,  1166,  1181,  1182,  1185,  1185,  1200,  1200,  1203,
    1203,  1204,  1204,  1209,  1210,  1211,  1212,  1213,  1217,  1218,
    1219,  1220,  1221,  1222,  1226,  1227,  1228,  1229,  1230,  1233,
    1237,  1243,  1245,  1247,  1249,  1251,  1255,  1256,  1257,  1258,
    1259,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1272,  1273,
    1274,  1275,  1279,  1282,  1283,  1286,  1287,  1290,  1291,  1294,
    1299,  1306,  1311,  1319,  1318,  1327,  1326,  1336,  1341,  1348,
    1353,  1360,  1365,  1372,  1377,  1384,  1389,  1394,  1399,  1406,
    1409,  1410,  1411,  1412,  1415,  1418,  1422,  1426,  1430,  1436,
    1441,  1449,  1450,  1453,  1469,  1479,  1493,  1503,  1508,  1526,
    1539,  1540,  1543,  1577
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
  "$@8", "$@9", "$@10", "$@11", "loop_stmt", "loop_type", "for_loop",
  "for_expr", "for_RHS", "while_loop", "$@12", "expr_stmt", "$@13", "LHS",
  "myId", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@14", "if_body",
  "switch_stmt", "$@15", "switch_body", "$@16", "cases", "$@17", "$@18",
  "RHS", "constants", "extra_consts", "array_const", "val_list",
  "resultant", "impr", "graph_impr", "matrix_impr", "matr_body",
  "graph_const", "graph_type1", "graph_type2", "int_list", "$@19", "$@20",
  "float_list", "char_list", "bool_list", "str_list", "weight_list",
  "vect_const", "vect_list", "matrix_const", "int_float_list", "mat_list",
  "arith_op", "binary_op", "unary_op", "logical_op", "call_stmt",
  "func_calls", "call_head", "arguments", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-181)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,   519,   519,   150,    29,  -314,    26,  -314,  -314,  -314,
     -17,    -2,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
       4,    17,  -314,  -314,  -314,  -314,    22,  -314,   519,  -314,
    -314,  -314,    20,  -314,   291,  -314,  -314,  -314,   832,  -314,
    -314,   777,  -314,    41,  -314,   519,     5,    53,    38,   426,
      30,    33,    47,    48,    58,   880,   519,   519,    75,    79,
      80,    81,   519,   -26,   777,    56,   777,  -314,  -314,  -314,
    -314,  -314,    83,  -314,  -314,  -314,   134,  -314,  -314,  -314,
    -314,    82,  -314,  -314,  -314,    88,  -314,    90,    91,  -314,
     832,    97,    96,     5,  -314,  -314,   109,    53,  -314,  -314,
    -314,  -314,  -314,  -314,   105,   116,   122,   548,   694,    92,
     119,   124,    18,   125,  -314,   126,  -314,   118,   128,   142,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,   694,  -314,
    -314,   694,   694,   519,   519,   519,   141,   519,   148,    11,
     134,   149,   153,  -314,  -314,  -314,   694,   694,   694,   151,
     694,   155,  -314,  -314,  -314,  -314,   519,   189,  -314,  -314,
     635,  -314,  -314,   156,  -314,  -314,  -314,  -314,   694,   694,
    -314,   158,  -314,   134,   161,   176,   157,   181,   182,  -314,
     220,   185,   186,   191,   193,   196,    43,  -314,   187,  -314,
    -314,  -314,  -314,  -314,   199,  -314,  -314,  -314,  -314,  -314,
     206,   207,   216,    54,  -314,  -314,   197,  -314,   215,  -314,
     832,   221,  -314,  -314,   487,   251,   694,   225,   226,  -314,
     222,   227,  -314,   228,   -17,  -314,   231,   233,   235,   236,
     237,   238,   239,   240,   241,   243,   244,   245,   246,   247,
     248,  -314,  -314,    59,  -314,   253,   254,   252,   255,  -314,
      28,   574,   574,  -314,  -314,  -314,   694,   311,  -314,   312,
     313,   314,   310,   258,   260,   259,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   519,   320,   321,   261,   269,
     288,   289,   290,   297,    -3,   296,   694,   694,   694,  -314,
    -314,   487,   724,   298,   299,   300,   724,   301,   305,   724,
     307,   724,   308,   309,   724,   724,  -314,   694,  -314,  -314,
     694,  -314,   346,   317,   318,  -314,  -314,   319,  -314,  -314,
    -314,  -314,  -314,    43,    43,   322,   -17,   315,  -314,   294,
     323,   519,  -314,  -314,  -314,  -314,  -314,   324,  -314,   325,
     327,   328,   329,  -314,  -314,  -314,  -314,   332,    18,   118,
    -314,  -314,  -314,  -314,  -314,  -314,   334,  -314,  -314,   335,
    -314,   316,  -314,  -314,   337,   338,  -314,   336,   339,   367,
     375,  -314,  -314,  -314,  -314,   342,   369,  -314,  -314,  -314,
     340,   343,  -314,  -314,    24,   -17,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,   724,   724,   724,  -314,   121,   341,  -314,
     344,  -314,  -314,   -17,   360,   519,   403,   519,   348,  -314,
    -314,   349,   351,   352,   354,   356,   311,   358,  -314,   415,
     107,  -314,   357,    13,   -17,  -314,  -314,  -314,   361,   363,
    -314,   416,   355,   364,   909,  -314,   358,   358,   368,  -314,
     -17,   519,   359,  -314,   118,   370,   222,  -314,  -314,  -314,
    -314,   -17,   372,   378,  -314,  -314,   -17,  -314,  -314
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
      23,     0,     0,   126,    60,     0,    58,    69,    66,    74,
      75,    70,   179,    68,    67,    61,   176,   124,    63,    64,
      65,     0,   180,   178,   177,     0,    62,     0,     0,    42,
       0,    47,     0,    30,    32,    31,     0,    37,    52,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,     0,
     126,   179,   163,     0,   153,     0,   164,   157,   178,   177,
     165,   166,   167,   154,   231,   232,   155,   156,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    79,     0,     0,    73,   237,
       0,   238,    45,     0,     9,    29,    34,    36,     0,     0,
     102,   158,   168,   163,   221,   223,     0,     0,     0,   179,
       0,   205,   208,   210,   214,   212,     0,   170,     0,   171,
     172,   173,   174,   175,     0,   101,    93,    95,    97,    99,
       0,     0,     0,   140,   133,   129,     0,   132,     0,   130,
       0,   140,   134,   128,     0,     0,     0,     0,     0,   195,
     196,     0,    78,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,     0,    48,     0,     0,     0,     0,   103,
       0,     0,     0,   197,   198,   219,     0,     0,   206,     0,
       0,     0,     0,   227,   228,     0,   169,   224,    94,    96,
      98,   100,   141,   145,   234,     0,     0,     0,     0,   179,
       0,     0,   178,   177,     0,     0,     0,     0,     0,   127,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,     0,    10,    35,
       0,   236,     0,     0,     0,   220,   222,     0,   203,   207,
     209,   213,   211,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   123,   118,   119,   121,   122,     0,   116,     0,
       0,     0,     0,    91,    92,    84,    85,     0,    86,    90,
      88,    89,    87,   181,    82,    83,     0,   193,   183,     0,
     184,     0,   194,   189,     0,     0,   243,     0,     0,   200,
     202,   235,   204,   225,   226,   230,   144,   142,   147,   146,
     136,     0,   131,   120,     0,     0,   185,   187,   192,    80,
      81,   182,   188,     0,     0,     0,   233,     0,     0,   199,
       0,   201,   229,     0,     0,     0,     0,     0,     0,   108,
     117,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,   135,     0,     0,     0,   186,   190,   191,   216,   218,
     151,     0,     0,   138,     0,   107,     0,     0,     0,   149,
       0,     0,   114,   109,   112,   113,   115,   110,   111,   215,
     217,     0,     0,     0,   137,   152,     0,   148,   150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,   422,  -314,  -314,  -314,  -314,     1,   345,  -314,
    -314,  -314,  -314,   330,   -33,  -314,  -314,  -314,  -314,  -314,
     347,     6,   -10,  -314,   -12,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   -46,  -246,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,   217,  -314,
     -50,   275,   -14,  -314,  -135,    -8,  -133,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,   -47,   -98,   -44,
    -314,  -314,  -314,   -40,   -52,   -53,   146,  -314,    66,    69,
    -101,  -314,  -314,   177,   180,   188,   192,  -313,  -314,  -126,
    -314,  -196,    72,  -230,  -314,   -43,  -187,  -314,   -30,  -314,
    -314,  -314
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,   161,
      80,    81,   189,   357,   352,    83,   278,   279,   280,   281,
     259,    84,   153,   154,   418,   453,   155,   395,    85,   393,
     122,    87,    88,   148,   214,   217,   215,    89,   336,   387,
      90,   337,   389,   414,   430,   462,   448,   229,   124,   185,
     126,   198,    91,   127,    93,    94,   231,   130,   186,   187,
     323,   382,   268,   200,   201,   202,   203,   324,   131,   188,
     132,   275,   204,   133,   134,   135,   136,    96,   137,    98,
     171,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    86,    30,    31,    37,    82,   129,   128,    95,    39,
     219,    92,   123,   121,   222,   125,   149,   150,   199,   184,
     166,    97,   166,   104,    86,   115,    86,   166,    82,    40,
      82,    95,   191,    95,    92,    65,    92,   160,     3,    49,
      42,   -76,   105,   107,    97,    37,    97,   273,   274,    37,
       1,     2,    73,    64,    58,   417,   101,   118,    44,     3,
     366,    46,   162,   369,   164,   371,   147,   183,   374,   375,
     104,   190,   360,   159,    47,    73,   360,    73,    50,   360,
     224,   360,   444,    65,   360,   360,  -176,    48,   322,   105,
     138,   210,   139,   107,   211,   212,   191,   192,   193,   194,
     195,    37,    99,   100,   108,   230,   140,   347,   141,   227,
     228,   151,   152,   233,   163,   361,   285,   286,   142,   361,
     316,   317,   361,   252,   361,   424,   425,   361,   361,   441,
     442,   257,   258,   459,   460,   325,   326,   383,   384,   156,
     157,   158,   165,   166,   213,   216,   218,   168,   221,   169,
     167,   170,   338,    12,   174,   196,   197,   421,   422,   423,
     173,    32,    33,   184,   184,   178,   328,   176,    34,    35,
      36,   293,   292,   360,   360,   360,   179,   290,   289,   295,
     291,   180,   160,   205,   206,   207,  -180,   208,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   209,    26,    27,    28,    29,   220,   223,   392,   225,
     232,   183,   183,   226,   457,   263,   361,   361,   361,   327,
     254,    37,   234,   261,   300,   260,   288,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   262,   264,
     265,   247,   248,   249,   250,   230,   266,   267,   269,   349,
     350,   276,   358,   270,   353,   271,   358,   354,   272,   358,
     287,   358,   359,   277,   358,   358,   359,   282,   283,   359,
     376,   359,   362,   377,   359,   359,   362,   284,   286,   362,
     431,   362,    66,   285,   362,   362,   221,   296,   297,   298,
    -177,   301,   299,   302,    12,   303,   304,   305,   306,   307,
     308,   309,    32,   310,   311,   312,   313,   314,   315,    34,
      35,    36,   318,   319,   320,   191,   321,   192,   195,   193,
     333,   194,   334,   335,   339,   340,   386,   341,   342,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   221,    26,    27,    28,    29,   343,   344,   345,
     378,   419,    52,   358,   358,   358,   346,   348,   390,   363,
     364,   365,   367,   359,   359,   359,   368,   433,   370,   372,
     373,   408,   388,   362,   362,   362,   379,   380,   403,   410,
     381,   385,   429,   394,   413,   420,   396,   391,   397,   398,
     399,   456,   455,   400,    86,   401,   402,   406,   452,   404,
     405,   407,   415,   428,   454,   196,   416,   432,   426,   434,
     435,   427,   436,   437,   458,   438,   218,   439,   322,   440,
     449,   443,   450,   446,   445,   447,   451,  -179,    41,    12,
     109,   110,   111,   112,   113,   461,   467,   177,  -178,   466,
     463,   235,   294,   464,   351,   409,   329,   172,   175,   411,
     330,   465,   216,   114,   115,    64,   468,   412,    67,     0,
     332,   116,     0,   331,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,     0,   117,     0,     0,   118,     0,     0,   119,
      12,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,    64,     0,     0,    67,
       0,     0,    12,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    70,    71,    26,
      27,    28,    29,     0,   117,     0,     0,   118,     0,     0,
     119,    12,   181,   110,   111,   112,   113,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,     0,     0,    12,   109,   110,
     111,   112,   113,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,   117,   182,     0,     0,     0,
       0,   119,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
       0,   117,     0,     0,     0,     0,     0,   119,    12,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,    64,     0,     0,    67,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,     0,     0,     0,     0,   118,   251,    12,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,    64,     0,     0,    67,    12,   355,   356,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    69,    70,    71,    26,    27,    28,    29,
       0,   114,   115,    64,   118,     0,    67,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    69,    70,    71,    26,    27,    28,    29,
      12,     0,     0,     0,   118,     0,     0,     0,     0,     0,
      59,    60,     0,    61,    62,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
       0,    68,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    70,    71,    26,
      27,    28,    29,    72,    42,    12,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      34,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    12,    26,    27,    28,    29,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,   114,     0,    64,     0,
       0,    67,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
      10,    51,     1,     2,     3,    51,    59,    59,    51,     3,
     145,    51,    59,    59,   147,    59,    66,    67,   119,   117,
       9,    51,     9,    56,    74,    28,    76,     9,    74,     0,
      76,    74,     4,    76,    74,    30,    76,    63,    33,    38,
      57,    67,    56,    57,    74,    44,    76,     4,     5,    48,
      24,    25,    51,    29,    48,    31,    55,    60,    60,    33,
     306,    57,    74,   309,    76,   311,    65,   117,   314,   315,
     103,   118,   302,    72,    57,    74,   306,    76,    58,   309,
      69,   311,    69,    30,   314,   315,    68,    65,    60,   103,
      60,   138,    59,   107,   141,   142,     4,     5,     6,     7,
       8,   100,    61,    62,    66,   158,    59,   294,    60,   156,
     157,    36,    37,   160,    58,   302,    62,    63,    60,   306,
      61,    62,   309,   170,   311,     4,     5,   314,   315,    22,
      23,   178,   179,   446,   447,   261,   262,   333,   334,    60,
      60,    60,    59,     9,   143,   144,   145,    59,   147,    59,
      68,    60,   285,     3,    58,    63,    64,   403,   404,   405,
      63,    11,    12,   261,   262,    60,   267,    58,    18,    19,
      20,   224,   224,   403,   404,   405,    60,   224,   224,   226,
     224,    59,    63,    59,    59,    59,    68,    59,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    59,    52,    53,    54,    55,    65,    59,   341,    60,
      59,   261,   262,    60,   444,    58,   403,   404,   405,   266,
      64,   220,    67,    62,   234,    67,   220,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    62,    58,
      58,    52,    53,    54,    55,   298,    26,    62,    62,   296,
     297,    64,   302,    62,   301,    62,   306,   301,    62,   309,
      63,   311,   302,    64,   314,   315,   306,    61,    61,   309,
     317,   311,   302,   320,   314,   315,   306,    61,    63,   309,
     415,   311,    31,    62,   314,   315,   285,    62,    62,    62,
      68,    60,    64,    60,     3,    60,    60,    60,    60,    60,
      60,    60,    11,    60,    60,    60,    60,    60,    60,    18,
      19,    20,    59,    59,    62,     4,    61,     5,     8,     6,
      62,     7,    62,    64,     4,     4,   336,    66,    59,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   341,    52,    53,    54,    55,    59,    59,    59,
       4,   394,    61,   403,   404,   405,    59,    61,    64,    61,
      61,    61,    61,   403,   404,   405,    61,   417,    61,    61,
      61,     4,    57,   403,   404,   405,    59,    59,    62,     4,
      61,    59,    22,    59,    15,   395,    61,    64,    61,    61,
      61,   444,   444,    61,   444,    61,    61,    61,   444,    62,
      62,    62,    62,   413,   444,    63,    63,     4,    67,    61,
      61,    67,    61,    61,   444,    61,   415,    61,    60,     4,
       4,    64,    67,    62,   434,    62,    62,    68,     6,     3,
       4,     5,     6,     7,     8,    67,    58,   107,    68,    67,
     450,   166,   225,   451,   298,   379,   269,   100,   103,   380,
     270,   461,   451,    27,    28,    29,   466,   385,    32,    -1,
     272,    35,    -1,   271,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    63,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,     3,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,
      63,     3,     4,     5,     6,     7,     8,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    -1,    57,    58,    -1,    -1,    -1,
      -1,    63,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    63,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    24,    25,    33,    71,    72,    73,    74,    80,    84,
      85,    86,     3,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      77,    77,    11,    12,    18,    19,    20,    77,    88,    91,
       0,    72,    57,    92,    60,    87,    57,    57,    65,    77,
      58,    93,    61,    89,    90,    91,    75,    81,    91,    13,
      14,    16,    17,    21,    29,    30,    31,    32,    34,    49,
      50,    51,    56,    77,    92,    94,    95,    96,    97,    98,
     100,   101,   102,   105,   111,   118,   120,   121,   122,   127,
     130,   142,   143,   144,   145,   165,   167,   168,   169,    61,
      62,    77,    78,    79,    84,   122,    83,   122,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   102,   120,   137,   138,   139,   140,   143,   144,   145,
     147,   158,   160,   163,   164,   165,   166,   168,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   123,   120,
     120,    36,    37,   112,   113,   116,    60,    60,    60,    77,
      63,    99,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   170,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   120,   138,   139,   148,   149,   159,   102,
     137,     4,     5,     6,     7,     8,    63,    64,   141,   150,
     153,   154,   155,   156,   162,    59,    59,    59,    59,    59,
     137,   137,   137,    77,   124,   126,    77,   125,    77,   124,
      65,    77,   126,    59,    69,    60,    60,   137,   137,   137,
     145,   146,    59,   137,    67,   121,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   137,   171,    64,    76,    82,   137,   137,   110,
      67,    62,    62,    58,    58,    58,    26,    62,   152,    62,
      62,    62,    62,     4,     5,   161,    64,    64,   106,   107,
     108,   109,    61,    61,    61,    62,    63,    63,    91,   102,
     137,   139,   144,   145,   118,   137,    62,    62,    62,    64,
      92,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    59,    59,
      62,    61,    60,   150,   157,   159,   159,   137,   150,   153,
     154,   156,   155,    62,    62,    64,   128,   131,   126,     4,
       4,    66,    59,    59,    59,    59,    59,   166,    61,   137,
     137,   146,   104,   137,   139,     4,     5,   103,   120,   143,
     163,   166,   168,    61,    61,    61,   103,    61,    61,   103,
      61,   103,    61,    61,   103,   103,   137,   137,     4,    59,
      59,    61,   151,   161,   161,    59,    92,   129,    57,   132,
      64,    64,   126,   119,    59,   117,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    61,    62,     4,   148,
       4,   149,   162,    15,   133,    62,    63,    31,   114,   165,
      92,   103,   103,   103,     4,     5,    67,    67,    92,    22,
     134,   124,     4,   120,    61,    61,    61,    61,    61,    61,
       4,    22,    23,    64,    69,    92,    62,    62,   136,     4,
      67,    62,   102,   115,   143,   144,   145,   163,   168,   157,
     157,    67,   135,    92,   125,    92,    67,    58,    92
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
     105,   105,   110,   105,   111,   112,   112,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   117,   116,   118,   119,
     118,   118,   118,   118,   120,   120,   121,   121,   122,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   128,   127,   129,   129,   131,   130,   133,   132,   135,
     134,   136,   134,   137,   137,   137,   137,   137,   138,   138,
     138,   138,   138,   138,   139,   139,   139,   139,   139,   140,
     140,   141,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     144,   144,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149,   151,   150,   152,   150,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   157,   157,   157,   158,
     159,   159,   159,   159,   160,   161,   161,   161,   161,   162,
     162,   163,   163,   164,   165,   166,   166,   167,   168,   169,
     170,   170,   171,   171
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
       4,     3,     0,     4,     2,     1,     1,     8,     1,     4,
       1,     1,     1,     1,     1,     1,     0,     6,     5,     0,
       6,     5,     5,     5,     1,     3,     1,     4,     3,     2,
       2,     5,     2,     2,     2,     6,     4,     9,     7,     3,
       1,     0,     6,     3,     1,     0,     6,     0,     7,     0,
       6,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     6,     5,     5,     6,     8,     6,     6,     5,
       8,     8,     6,     5,     5,     1,     1,     3,     3,     5,
       4,     5,     4,     0,     4,     0,     2,     3,     1,     3,
       1,     3,     1,     3,     1,     7,     5,     7,     5,     3,
       3,     1,     3,     1,     3,     3,     3,     1,     1,     5,
       4,     1,     1,     6,     4,     5,     4,     2,     2,     2,
       3,     2,     1,     3
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
#line 134 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
							{
								printf("%d ERROR: Struct or class name already exists\n", yylineno);
								exit(1);
							}
								
							else class_insert((yyvsp[-1].str));
							
						}
#line 1896 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 145 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1902 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 145 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1908 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 148 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1914 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 149 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1920 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 150 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1926 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 151 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1932 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 152 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1938 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 153 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1944 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 154 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1950 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 155 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1956 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 156 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1962 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 157 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1968 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 158 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1974 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 159 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1980 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 160 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1986 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 161 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1992 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 162 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1998 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 163 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2004 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 164 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 2010 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 165 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2016 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 177 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									printf("%d ERROR: Struct or class name already exists\n", yylineno);
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].str));
								
							}
#line 2032 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 188 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2038 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 188 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2044 "y.tab.c"
    break;

  case 38: /* function: function_head function_body  */
#line 196 "parser.y"
                                                        {
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
							}
#line 2054 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 203 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2065 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 212 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							if(inClass == 0) {
								int i = func_search((yyvsp[0].str));
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, (yyvsp[0].str));
									exit(1);
								}
								func_insert((yyvsp[0].str), (yyvsp[-1].str));
								currentFuncIndex = func_size - 1;
							}
							else {
								int i = class_func_search((yyvsp[0].str), class_size-1);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, (yyvsp[0].str));
									exit(1);
								}
								class_func_insert(class_size-1, (yyvsp[0].str), (yyvsp[-1].str));
								currentFuncIndex = class_symb[class_size-1].cl_func_size - 1;
							}
						}
#line 2092 "y.tab.c"
    break;

  case 43: /* fdtype: dtype  */
#line 241 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2098 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 242 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2104 "y.tab.c"
    break;

  case 47: /* param: dtype id  */
#line 251 "parser.y"
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
#line 2131 "y.tab.c"
    break;

  case 48: /* param: dtype id '[' ']'  */
#line 273 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2139 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 280 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2145 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 281 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2151 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 282 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2157 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 283 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2171 "y.tab.c"
    break;

  case 53: /* dtype: id  */
#line 292 "parser.y"
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
#line 2193 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 311 "parser.y"
                                      { level++; }
#line 2199 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 311 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2205 "y.tab.c"
    break;

  case 68: /* statement: return_stmt  */
#line 328 "parser.y"
                                                              {fprintf(fparse," : RETURN STATEMENT");}
#line 2211 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 331 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2217 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 332 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2223 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 335 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2229 "y.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 343 "parser.y"
                                                        {
								if(label_search((yyvsp[0].str))!=-1) 
								{
									printf("%d ERROR: Label name already exists\n", yylineno);
									exit(1);
								}
								else label_insert((yyvsp[0].str));
							}
#line 2242 "y.tab.c"
    break;

  case 77: /* label_stmt: id $@6 ':' function_body  */
#line 351 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2248 "y.tab.c"
    break;

  case 78: /* goto_stmt: GOTO id ';'  */
#line 354 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2254 "y.tab.c"
    break;

  case 79: /* vect_stmt: vect_stmt_body ';'  */
#line 357 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2260 "y.tab.c"
    break;

  case 80: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 360 "parser.y"
                                                                           { 
							if((yyvsp[-5].str)[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							char* myType;
							strncpy(myType, (yyvsp[-5].str) + 1, strlen((yyvsp[-5].str)));
							if(strcmp(myType, (yyvsp[-1].str))){
								int a = !strcmp(myType, "float") && (!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool"));
								int b = !strcmp(myType, "int") && (!strcmp((yyvsp[-1].str), "bool"));
								int c = !strcmp(myType, "bool") && (!strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "char") || !strcmp((yyvsp[-1].str), "string"));
								if(!(a || b || c)){
									printf("%d ERROR: appending the wrong dtype; expected %s; given %s\n", yylineno, myType, (yyvsp[-1].str));
								}
							} 
							(yyval.str) = (yyvsp[-5].str);
						}
#line 2282 "y.tab.c"
    break;

  case 81: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 377 "parser.y"
                                                                                           {
							if((yyvsp[-5].str)[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							if(!strcmp("int", (yyvsp[-1].str)) || !strcmp("float", (yyvsp[-1].str)) || !strcmp("bool", (yyvsp[-1].str))){
								printf("%d ERROR: appending the wrong dtype\n", yylineno);
							} 
							(yyval.str) = (yyvsp[-5].str);
						}
#line 2297 "y.tab.c"
    break;

  case 82: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 387 "parser.y"
                                                                             {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2309 "y.tab.c"
    break;

  case 83: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 394 "parser.y"
                                                                              {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2321 "y.tab.c"
    break;

  case 84: /* remove_body: INT_CONST  */
#line 405 "parser.y"
                                                    {(yyval.str)="int";}
#line 2327 "y.tab.c"
    break;

  case 85: /* remove_body: FLOAT_CONST  */
#line 406 "parser.y"
                                                              {(yyval.str)="float";}
#line 2333 "y.tab.c"
    break;

  case 86: /* remove_body: LHS  */
#line 407 "parser.y"
                                                      {(yyval.str)=(yyvsp[0].details).type;}
#line 2339 "y.tab.c"
    break;

  case 87: /* remove_body: func_calls  */
#line 408 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2345 "y.tab.c"
    break;

  case 88: /* remove_body: arith_op  */
#line 409 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2351 "y.tab.c"
    break;

  case 89: /* remove_body: logical_op  */
#line 410 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2357 "y.tab.c"
    break;

  case 90: /* remove_body: impr  */
#line 411 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 2363 "y.tab.c"
    break;

  case 91: /* vect_append: RHS  */
#line 415 "parser.y"
                                              {(yyval.str)=(yyvsp[0].str);}
#line 2369 "y.tab.c"
    break;

  case 92: /* vect_append: extra_consts  */
#line 416 "parser.y"
                                                               {(yyval.str)=(yyvsp[0].str);}
#line 2375 "y.tab.c"
    break;

  case 93: /* $@7: %empty  */
#line 420 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{		
									if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							}
#line 2396 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN RHS ';' $@7  */
#line 436 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2402 "y.tab.c"
    break;

  case 95: /* $@8: %empty  */
#line 438 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n", yylineno);
									}
								}
								else
								{
									if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
						 	}
#line 2423 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN extra_consts ';' $@8  */
#line 454 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2429 "y.tab.c"
    break;

  case 97: /* $@9: %empty  */
#line 456 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
						 	}
#line 2450 "y.tab.c"
    break;

  case 98: /* return_stmt: RETURN graph_impr ';' $@9  */
#line 472 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2456 "y.tab.c"
    break;

  case 99: /* $@10: %empty  */
#line 474 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							}
#line 2477 "y.tab.c"
    break;

  case 100: /* return_stmt: RETURN matrix_impr ';' $@10  */
#line 490 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2483 "y.tab.c"
    break;

  case 101: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 492 "parser.y"
                                                {	returnStmtCount++;
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("%d ERROR : func type and return type are mismatched\n",yylineno);
								}
							}
						}
#line 2500 "y.tab.c"
    break;

  case 102: /* $@11: %empty  */
#line 505 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp("void",func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp("void",class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
							}
#line 2521 "y.tab.c"
    break;

  case 103: /* return_stmt: RETURN null ';' $@11  */
#line 521 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2527 "y.tab.c"
    break;

  case 104: /* loop_stmt: LOOP loop_type  */
#line 526 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2533 "y.tab.c"
    break;

  case 109: /* for_expr: EXPR LHS '=' for_RHS  */
#line 537 "parser.y"
                                                                       {
							if(strcmp((yyvsp[-2].details).type, (yyvsp[0].str))){
								int a = !strcmp((yyvsp[-2].details).type, "int") || !strcmp((yyvsp[-2].details).type, "float") || !strcmp((yyvsp[-2].details).type, "bool");
								int b = !strcmp((yyvsp[0].str), "int") || !strcmp((yyvsp[0].str), "float") || !strcmp((yyvsp[0].str), "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
						}
#line 2549 "y.tab.c"
    break;

  case 110: /* for_RHS: arith_op  */
#line 550 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2555 "y.tab.c"
    break;

  case 111: /* for_RHS: func_calls  */
#line 551 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2561 "y.tab.c"
    break;

  case 112: /* for_RHS: impr  */
#line 552 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2567 "y.tab.c"
    break;

  case 113: /* for_RHS: graph_impr  */
#line 553 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2573 "y.tab.c"
    break;

  case 114: /* for_RHS: vect_stmt_body  */
#line 554 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2579 "y.tab.c"
    break;

  case 115: /* for_RHS: matrix_impr  */
#line 555 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2585 "y.tab.c"
    break;

  case 116: /* $@12: %empty  */
#line 558 "parser.y"
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
#line 2601 "y.tab.c"
    break;

  case 118: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 571 "parser.y"
                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].str))){
								int a = !strcmp((yyvsp[-3].details).type, "int") || !strcmp((yyvsp[-3].details).type, "float") || !strcmp((yyvsp[-3].details).type, "bool");
								int b = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float") || !strcmp((yyvsp[-1].str), "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 2619 "y.tab.c"
    break;

  case 119: /* $@13: %empty  */
#line 585 "parser.y"
                                                        {
								int dimAval, dimBval;
								char* element_type;
								int ind = var_search((yyvsp[-3].details).name);
								if(ind==-1) 
								{
									ind = class_declr_search((yyvsp[-3].details).name, class_size-1);
									dimAval = class_symb[class_size-1].declr_list[ind].dim_A;
									dimBval = class_symb[class_size-1].declr_list[ind].dim_B;
									element_type = class_symb[class_size-1].declr_list[ind].ele_type;
								}
								else
								{
									dimAval = var_symb[ind].dim_A;
									dimBval = var_symb[ind].dim_B;
									element_type = var_symb[ind].ele_type;
								}
								 

								if(strcmp("graph", (yyvsp[-3].details).type)==0)
								{
									for(int i=0; i<dummy_size; i++)
									{
										if(newArr[i]>dimAval)
										{
											printf("%d ERROR: Vertex used is not present in the graph\n", yylineno);
											exit(1);
										}
									}
									dummy_size=0;
								}
								else if(strcmp("matrix", (yyvsp[-3].details).type)==0)
								{
									if(dummy_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										exit(1);
									}
									for(int i=0; i<dummy_size; i++)
									{
										if(newArr[i]!=dimBval)
										{
											printf("%d ERROR: Number of columns mismatch\n", yylineno);
											exit(1);
										}
									}
									dummy_size=0;
								}
								else if(strcmp("array", (yyvsp[-3].details).type)==0)
								{
									if(strcmp(element_type, (yyvsp[-1].str))!=0 && strcmp((yyvsp[-1].str), "any")!=0)
									{
										printf("%d ERROR: Element-type mismatch in array\n", yylineno);
										exit(1);
									}
									if(dummy_size!=dimAval)
									{
										printf("%d ERROR: Array length is not matching\n", yylineno);
										exit(1);
									}
									
									dummy_size=0;
								}
							}
#line 2688 "y.tab.c"
    break;

  case 120: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@13  */
#line 649 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2694 "y.tab.c"
    break;

  case 121: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 651 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2700 "y.tab.c"
    break;

  case 122: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 652 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2706 "y.tab.c"
    break;

  case 123: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 653 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2712 "y.tab.c"
    break;

  case 124: /* LHS: myId  */
#line 657 "parser.y"
                                                       {

							classIndex = -1;
							int i = var_search((yyvsp[0].str));
							int j, l;
							if(inClass) j = class_declr_search((yyvsp[0].str), class_size-1);
							else j = -1;
							int k = func_search((yyvsp[0].str));
							if(inClass) l = class_func_search((yyvsp[0].str), class_size-1);
							else l = -1;
							
							if(i<0 && j<0 && k<0 && l<0){
								printf("%d Error: Accessing undeclared identifier/function %s\n", yylineno, (yyvsp[0].str));
							}
							
							// class declare variable (class attirbute)
							if(j>=0) {
								(yyval.details).name = (yyvsp[0].str);
								// $$.type = class_symb[class_size-1].declr_list[i].type;
								if(strcmp(class_symb[class_size-1].declr_list[j].type, "vect") == 0) {
								    char* result;
									char* A = "*";
								    result = (char*)malloc(strlen(A) + strlen(class_symb[class_size-1].declr_list[j].ele_type) + 1);
								    strcpy(result, A);
								    strcat(result, class_symb[class_size-1].declr_list[j].ele_type);
										    // dataType = 2;
				   				     (yyval.details).type = result;
								}
								else {
									(yyval.details).type = class_symb[class_size-1].declr_list[j].type;
								}
								classIndex=class_size-1;
							}
							
							// declare variable
							else if(i>=0){
								(yyval.details).name = (yyvsp[0].str);
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
							
							// class function
							else if(l >= 0){
								(yyval.details).name = (yyvsp[0].str);
								(yyval.details).type = class_symb[class_size-1].func_list[l].type;
								classIndex = class_size-1;
								funcIndex = l;
							}
							
							// normal funciton
							else if(k >= 0){
								(yyval.details).name = (yyvsp[0].str);
								(yyval.details).type = func_symb[k].type;
								funcIndex = k;
							}
							
							
						}
#line 2785 "y.tab.c"
    break;

  case 125: /* LHS: LHS ARROW myId  */
#line 725 "parser.y"
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
#line 2871 "y.tab.c"
    break;

  case 126: /* myId: id  */
#line 809 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2877 "y.tab.c"
    break;

  case 127: /* myId: id '[' RHS ']'  */
#line 810 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2890 "y.tab.c"
    break;

  case 128: /* declr_stmt: DECLR declr_body ';'  */
#line 821 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2896 "y.tab.c"
    break;

  case 129: /* declr_body: DATATYPE id_list  */
#line 824 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
									}
								}
								arr_size =0;
							}
#line 2945 "y.tab.c"
    break;

  case 130: /* declr_body: GRAPH graph_and_array_list  */
#line 869 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], -1);
									}
								}
								arr_size=0;
							}
#line 2994 "y.tab.c"
    break;

  case 131: /* declr_body: VECT '<' dtype '>' id_list  */
#line 914 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d : Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], (yyvsp[-4].str), (yyvsp[-2].str), -1, -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].str), -1, -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].str), -1, -1);
									}
								}
								arr_size=0;
							}
#line 3043 "y.tab.c"
    break;

  case 132: /* declr_body: MATRIX matrix_list  */
#line 959 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], (yyvsp[-1].str), "" , dimA[i], dimB[i]);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], dimB[i]);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", dimA[i], dimB[i]);
									}
								}
								arr_size=0;
							}
#line 3092 "y.tab.c"
    break;

  case 133: /* declr_body: DATATYPE graph_and_array_list  */
#line 1004 "parser.y"
                                                        {
								if(currentFuncIndex!=-1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										if(var_search(arr[i])!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										var_insert(1, level, arr[i], "array", (yyvsp[-1].str) , dimA[i], -1);
									}
								}
								else if(inClass==1)
								{
									for(int i=0; i<arr_size; i++)
									{
										if(class_declr_search(arr[i], class_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_class_declrs(arr[i], "array", 1, level, (yyvsp[-1].str), dimA[i], -1);
									}
								}
								else
								{
									for(int i=0; i<arr_size; i++)
									{
										if(struct_declr_search(arr[i], struct_size-1)!=-1)
										{
											printf("%d ERROR: Variable already declared\n", yylineno);
											exit(1);
										}
										add_struct_declrs(arr[i], "array", 1, level, (yyvsp[-1].str), dimA[i], -1);
									}
								}
								arr_size=0;
							}
#line 3141 "y.tab.c"
    break;

  case 134: /* declr_body: id id_list  */
#line 1049 "parser.y"
                                                        {
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									if(currentFuncIndex!=-1)
									{
										for(int i=0; i<arr_size; i++)
										{
											if(inClass==1 && class_declr_search(arr[i], class_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											if(var_search(arr[i])!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											var_insert(1, level, arr[i], (yyvsp[-1].str), "", -1, -1);
										}
									}
									else if(inClass==1)
									{
										for(int i=0; i<arr_size; i++)
										{
											if(class_declr_search(arr[i], class_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											add_class_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
										}
									}
									else
									{
										for(int i=0; i<arr_size; i++)
										{
											if(struct_declr_search(arr[i], struct_size-1)!=-1)
											{
												printf("%d ERROR: Variable already declared\n", yylineno);
												exit(1);
											}
											add_struct_declrs(arr[i], (yyvsp[-1].str), 1, level, "", -1, -1);
										}
									}
									arr_size =0;
								}
								else
								{
									arr_size=0;
									printf("%d ERROR: No struct or class with that name is defined\n", yylineno);
									exit(1);
								}
							}
#line 3199 "y.tab.c"
    break;

  case 135: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 1105 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-5].str);
								dimA[arr_size] = atoi((yyvsp[-3].str));
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
							}
#line 3214 "y.tab.c"
    break;

  case 136: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 1116 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-3].str);
								dimA[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
							}
#line 3229 "y.tab.c"
    break;

  case 137: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 1129 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-8].str);
								dimA[arr_size] = atoi((yyvsp[-6].str));
								dimB[arr_size] = atoi((yyvsp[-3].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
							}
#line 3245 "y.tab.c"
    break;

  case 138: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1141 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].str);
								dimA[arr_size] = atoi((yyvsp[-4].str));
								dimB[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
							}
#line 3261 "y.tab.c"
    break;

  case 139: /* id_list: id ',' id_list  */
#line 1155 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 3270 "y.tab.c"
    break;

  case 140: /* id_list: id  */
#line 1160 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 3279 "y.tab.c"
    break;

  case 141: /* $@14: %empty  */
#line 1166 "parser.y"
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
#line 3296 "y.tab.c"
    break;

  case 145: /* $@15: %empty  */
#line 1185 "parser.y"
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
#line 3313 "y.tab.c"
    break;

  case 147: /* $@16: %empty  */
#line 1200 "parser.y"
                                              {switch_insert(level); level++;}
#line 3319 "y.tab.c"
    break;

  case 148: /* switch_body: '{' $@16 cases DEFAULT ':' function_body '}'  */
#line 1200 "parser.y"
                                                                                                                   { var_delete(level); level--; switch_delete();}
#line 3325 "y.tab.c"
    break;

  case 149: /* $@17: %empty  */
#line 1203 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str));}
#line 3331 "y.tab.c"
    break;

  case 151: /* $@18: %empty  */
#line 1204 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str));}
#line 3337 "y.tab.c"
    break;

  case 153: /* RHS: constants  */
#line 1209 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 3343 "y.tab.c"
    break;

  case 154: /* RHS: arith_op  */
#line 1210 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 3349 "y.tab.c"
    break;

  case 155: /* RHS: logical_op  */
#line 1211 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3355 "y.tab.c"
    break;

  case 156: /* RHS: func_calls  */
#line 1212 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3361 "y.tab.c"
    break;

  case 157: /* RHS: impr  */
#line 1213 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3367 "y.tab.c"
    break;

  case 158: /* constants: INT_CONST  */
#line 1217 "parser.y"
                                                    {(yyval.str)="int";}
#line 3373 "y.tab.c"
    break;

  case 159: /* constants: FLOAT_CONST  */
#line 1218 "parser.y"
                                                              {(yyval.str)="float";}
#line 3379 "y.tab.c"
    break;

  case 160: /* constants: CHAR_CONST  */
#line 1219 "parser.y"
                                                             {(yyval.str)="char";}
#line 3385 "y.tab.c"
    break;

  case 161: /* constants: STR_CONST  */
#line 1220 "parser.y"
                                                            {(yyval.str)="string";}
#line 3391 "y.tab.c"
    break;

  case 162: /* constants: BOOL_CONST  */
#line 1221 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 3397 "y.tab.c"
    break;

  case 163: /* constants: LHS  */
#line 1222 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 3403 "y.tab.c"
    break;

  case 164: /* extra_consts: array_const  */
#line 1226 "parser.y"
                                             {(yyval.str) = (yyvsp[0].str);}
#line 3409 "y.tab.c"
    break;

  case 165: /* extra_consts: graph_const  */
#line 1227 "parser.y"
                                                             {(yyval.str)="graph";}
#line 3415 "y.tab.c"
    break;

  case 166: /* extra_consts: vect_const  */
#line 1228 "parser.y"
                                                            {(yyval.str)="vect";}
#line 3421 "y.tab.c"
    break;

  case 167: /* extra_consts: matrix_const  */
#line 1229 "parser.y"
                                                              {(yyval.str)="matrix";}
#line 3427 "y.tab.c"
    break;

  case 168: /* extra_consts: '{' '}'  */
#line 1230 "parser.y"
                                                         {(yyval.str)="1";}
#line 3433 "y.tab.c"
    break;

  case 169: /* array_const: '[' val_list ']'  */
#line 1234 "parser.y"
                                                        {
								(yyval.str) = (yyvsp[-1].str);
							}
#line 3441 "y.tab.c"
    break;

  case 170: /* array_const: '[' ']'  */
#line 1238 "parser.y"
                                                        {
								(yyval.str) = "any";
							}
#line 3449 "y.tab.c"
    break;

  case 171: /* val_list: int_list  */
#line 1244 "parser.y"
                                                        { (yyval.str) = "int";}
#line 3455 "y.tab.c"
    break;

  case 172: /* val_list: float_list  */
#line 1246 "parser.y"
                                                        { (yyval.str)  = "float";}
#line 3461 "y.tab.c"
    break;

  case 173: /* val_list: char_list  */
#line 1248 "parser.y"
                                                        { (yyval.str) = "char";}
#line 3467 "y.tab.c"
    break;

  case 174: /* val_list: bool_list  */
#line 1250 "parser.y"
                                                        { (yyval.str) = "bool";}
#line 3473 "y.tab.c"
    break;

  case 175: /* val_list: str_list  */
#line 1252 "parser.y"
                                                        { (yyval.str) = "string";}
#line 3479 "y.tab.c"
    break;

  case 176: /* resultant: LHS  */
#line 1255 "parser.y"
                                             {(yyval.str) = (yyvsp[0].details).type;}
#line 3485 "y.tab.c"
    break;

  case 177: /* resultant: matrix_impr  */
#line 1256 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3491 "y.tab.c"
    break;

  case 178: /* resultant: graph_impr  */
#line 1257 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 3497 "y.tab.c"
    break;

  case 179: /* resultant: vect_stmt_body  */
#line 1258 "parser.y"
                                                                 {(yyval.str) = (yyvsp[0].str);}
#line 3503 "y.tab.c"
    break;

  case 180: /* resultant: impr  */
#line 1259 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3509 "y.tab.c"
    break;

  case 181: /* impr: resultant '.' LENGTH '(' ')'  */
#line 1263 "parser.y"
                                                                      {(yyval.str) = "int";}
#line 3515 "y.tab.c"
    break;

  case 182: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 1264 "parser.y"
                                                                                      {(yyval.str) = "0";}
#line 3521 "y.tab.c"
    break;

  case 183: /* impr: resultant '.' TRACE '(' ')'  */
#line 1265 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3527 "y.tab.c"
    break;

  case 184: /* impr: resultant '.' STRLEN '(' ')'  */
#line 1266 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3533 "y.tab.c"
    break;

  case 185: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 1267 "parser.y"
                                                                             {(yyval.str) = "bool";}
#line 3539 "y.tab.c"
    break;

  case 186: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 1268 "parser.y"
                                                                                                          {(yyval.str) = "string";}
#line 3545 "y.tab.c"
    break;

  case 187: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 1269 "parser.y"
                                                                             {(yyval.str) =  "string";}
#line 3551 "y.tab.c"
    break;

  case 188: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 1272 "parser.y"
                                                                                     {(yyval.str) = "vect";}
#line 3557 "y.tab.c"
    break;

  case 189: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 1273 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3563 "y.tab.c"
    break;

  case 190: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 1274 "parser.y"
                                                                                                          {(yyval.str) = "vect";}
#line 3569 "y.tab.c"
    break;

  case 191: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 1275 "parser.y"
                                                                                                               {(yyval.str) = "int";}
#line 3575 "y.tab.c"
    break;

  case 192: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 1279 "parser.y"
                                                                                {if(strcmp((yyvsp[-3].str),"matrix") || strcmp((yyvsp[-1].str),"matrix")){
											printf("%d, ERROR : argument is not a matrix\n",yylineno);exit(1);}
											(yyval.str) = "matrix";}
#line 3583 "y.tab.c"
    break;

  case 193: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 1282 "parser.y"
                                                                                  {(yyval.str) = "matrix";}
#line 3589 "y.tab.c"
    break;

  case 194: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 1283 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3595 "y.tab.c"
    break;

  case 195: /* matr_body: RHS  */
#line 1286 "parser.y"
                                              {(yyval.str) = (yyvsp[0].str);}
#line 3601 "y.tab.c"
    break;

  case 196: /* matr_body: matrix_impr  */
#line 1287 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3607 "y.tab.c"
    break;

  case 199: /* graph_type1: INT_CONST ':' int_list ';' graph_type1  */
#line 1295 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-4].str));
								dummy_size++;
							}
#line 3616 "y.tab.c"
    break;

  case 200: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 1300 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
							}
#line 3625 "y.tab.c"
    break;

  case 201: /* graph_type2: INT_CONST ':' weight_list ';' graph_type2  */
#line 1307 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-4].str));
								dummy_size++;
							}
#line 3634 "y.tab.c"
    break;

  case 202: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 1312 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
							}
#line 3643 "y.tab.c"
    break;

  case 203: /* $@19: %empty  */
#line 1319 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-2].str));
								dummy_size++;
							}
#line 3652 "y.tab.c"
    break;

  case 204: /* int_list: INT_CONST ',' int_list $@19  */
#line 1323 "parser.y"
                                                        {
								(yyval.str) = "int";
							}
#line 3660 "y.tab.c"
    break;

  case 205: /* $@20: %empty  */
#line 1327 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 3669 "y.tab.c"
    break;

  case 206: /* int_list: INT_CONST $@20  */
#line 1331 "parser.y"
                                                        {
								(yyval.str) = "int";
							}
#line 3677 "y.tab.c"
    break;

  case 207: /* float_list: FLOAT_CONST ',' float_list  */
#line 1337 "parser.y"
                                                        {
								(yyval.str) = "float";
								dummy_size++;
							}
#line 3686 "y.tab.c"
    break;

  case 208: /* float_list: FLOAT_CONST  */
#line 1342 "parser.y"
                                                        {
								(yyval.str) = "float";
								dummy_size++;
							}
#line 3695 "y.tab.c"
    break;

  case 209: /* char_list: CHAR_CONST ',' char_list  */
#line 1349 "parser.y"
                                                        {
								(yyval.str) = "char";
								dummy_size;
							}
#line 3704 "y.tab.c"
    break;

  case 210: /* char_list: CHAR_CONST  */
#line 1354 "parser.y"
                                                        {
								(yyval.str) = "char";
								dummy_size++;
							}
#line 3713 "y.tab.c"
    break;

  case 211: /* bool_list: BOOL_CONST ',' bool_list  */
#line 1361 "parser.y"
                                                        {
								(yyval.str) = "bool";
								dummy_size;
							}
#line 3722 "y.tab.c"
    break;

  case 212: /* bool_list: BOOL_CONST  */
#line 1366 "parser.y"
                                                        {
								(yyval.str) = "bool";
								dummy_size;
							}
#line 3731 "y.tab.c"
    break;

  case 213: /* str_list: STR_CONST ',' str_list  */
#line 1373 "parser.y"
                                                        {
								(yyval.str) = "string";
								dummy_size;
							}
#line 3740 "y.tab.c"
    break;

  case 214: /* str_list: STR_CONST  */
#line 1378 "parser.y"
                                                        {
								(yyval.str) = "string";
								dummy_size++;
							}
#line 3749 "y.tab.c"
    break;

  case 215: /* weight_list: '(' INT_CONST ',' INT_CONST ')' ',' weight_list  */
#line 1385 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-5].str));
								dummy_size++;
							}
#line 3758 "y.tab.c"
    break;

  case 216: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 1390 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
							}
#line 3767 "y.tab.c"
    break;

  case 217: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list  */
#line 1395 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-5].str));
								dummy_size++;
							}
#line 3776 "y.tab.c"
    break;

  case 218: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 1400 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
							}
#line 3785 "y.tab.c"
    break;

  case 225: /* int_float_list: INT_CONST ',' int_float_list  */
#line 1419 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3793 "y.tab.c"
    break;

  case 226: /* int_float_list: FLOAT_CONST ',' int_float_list  */
#line 1423 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3801 "y.tab.c"
    break;

  case 227: /* int_float_list: INT_CONST  */
#line 1427 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3809 "y.tab.c"
    break;

  case 228: /* int_float_list: FLOAT_CONST  */
#line 1431 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3817 "y.tab.c"
    break;

  case 229: /* mat_list: '[' int_float_list ']' ';' mat_list  */
#line 1437 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-3].Cols).cols;
								dummy_size++;
							}
#line 3826 "y.tab.c"
    break;

  case 230: /* mat_list: '[' int_float_list ']' ';'  */
#line 1442 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
							}
#line 3835 "y.tab.c"
    break;

  case 233: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 1453 "parser.y"
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
#line 3854 "y.tab.c"
    break;

  case 234: /* unary_op: UNARYOP '(' RHS ')'  */
#line 1469 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3867 "y.tab.c"
    break;

  case 235: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 1479 "parser.y"
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
#line 3886 "y.tab.c"
    break;

  case 236: /* logical_op: NOT '(' RHS ')'  */
#line 1493 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3899 "y.tab.c"
    break;

  case 237: /* call_stmt: func_calls ';'  */
#line 1503 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 3905 "y.tab.c"
    break;

  case 238: /* func_calls: call_head arguments  */
#line 1508 "parser.y"
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
#line 3925 "y.tab.c"
    break;

  case 239: /* call_head: CALL LHS  */
#line 1526 "parser.y"
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
#line 3941 "y.tab.c"
    break;

  case 242: /* arg_list: RHS  */
#line 1543 "parser.y"
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
#line 3980 "y.tab.c"
    break;

  case 243: /* arg_list: arg_list ',' RHS  */
#line 1577 "parser.y"
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
#line 4016 "y.tab.c"
    break;


#line 4020 "y.tab.c"

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

#line 1610 "parser.y"


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




