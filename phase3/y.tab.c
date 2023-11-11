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
	struct
	{
		int cols;
	} Cols;

#line 289 "y.tab.c"

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
  YYSYMBOL_loop_stmt = 110,                /* loop_stmt  */
  YYSYMBOL_loop_type = 111,                /* loop_type  */
  YYSYMBOL_for_loop = 112,                 /* for_loop  */
  YYSYMBOL_for_expr = 113,                 /* for_expr  */
  YYSYMBOL_for_RHS = 114,                  /* for_RHS  */
  YYSYMBOL_while_loop = 115,               /* while_loop  */
  YYSYMBOL_116_11 = 116,                   /* $@11  */
  YYSYMBOL_expr_stmt = 117,                /* expr_stmt  */
  YYSYMBOL_118_12 = 118,                   /* $@12  */
  YYSYMBOL_LHS = 119,                      /* LHS  */
  YYSYMBOL_myId = 120,                     /* myId  */
  YYSYMBOL_declr_stmt = 121,               /* declr_stmt  */
  YYSYMBOL_declr_body = 122,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 123,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 124,              /* matrix_list  */
  YYSYMBOL_id_list = 125,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 126,              /* ifcond_stmt  */
  YYSYMBOL_127_13 = 127,                   /* $@13  */
  YYSYMBOL_if_body = 128,                  /* if_body  */
  YYSYMBOL_switch_stmt = 129,              /* switch_stmt  */
  YYSYMBOL_130_14 = 130,                   /* $@14  */
  YYSYMBOL_switch_body = 131,              /* switch_body  */
  YYSYMBOL_132_15 = 132,                   /* $@15  */
  YYSYMBOL_cases = 133,                    /* cases  */
  YYSYMBOL_134_16 = 134,                   /* $@16  */
  YYSYMBOL_135_17 = 135,                   /* $@17  */
  YYSYMBOL_RHS = 136,                      /* RHS  */
  YYSYMBOL_constants = 137,                /* constants  */
  YYSYMBOL_extra_consts = 138,             /* extra_consts  */
  YYSYMBOL_array_const = 139,              /* array_const  */
  YYSYMBOL_val_list = 140,                 /* val_list  */
  YYSYMBOL_resultant = 141,                /* resultant  */
  YYSYMBOL_impr = 142,                     /* impr  */
  YYSYMBOL_graph_impr = 143,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 144,              /* matrix_impr  */
  YYSYMBOL_matr_body = 145,                /* matr_body  */
  YYSYMBOL_graph_const = 146,              /* graph_const  */
  YYSYMBOL_graph_type1 = 147,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 148,              /* graph_type2  */
  YYSYMBOL_int_list = 149,                 /* int_list  */
  YYSYMBOL_float_list = 150,               /* float_list  */
  YYSYMBOL_char_list = 151,                /* char_list  */
  YYSYMBOL_bool_list = 152,                /* bool_list  */
  YYSYMBOL_str_list = 153,                 /* str_list  */
  YYSYMBOL_weight_list = 154,              /* weight_list  */
  YYSYMBOL_vect_const = 155,               /* vect_const  */
  YYSYMBOL_vect_list = 156,                /* vect_list  */
  YYSYMBOL_matrix_const = 157,             /* matrix_const  */
  YYSYMBOL_int_float_list = 158,           /* int_float_list  */
  YYSYMBOL_mat_list = 159,                 /* mat_list  */
  YYSYMBOL_arith_op = 160,                 /* arith_op  */
  YYSYMBOL_binary_op = 161,                /* binary_op  */
  YYSYMBOL_unary_op = 162,                 /* unary_op  */
  YYSYMBOL_logical_op = 163,               /* logical_op  */
  YYSYMBOL_call_stmt = 164,                /* call_stmt  */
  YYSYMBOL_func_calls = 165,               /* func_calls  */
  YYSYMBOL_call_head = 166,                /* call_head  */
  YYSYMBOL_arguments = 167,                /* arguments  */
  YYSYMBOL_arg_list = 168                  /* arg_list  */
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
#define YYLAST   1014

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  466

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
       0,   116,   116,   119,   120,   123,   124,   125,   128,   139,
     128,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   162,
     163,   166,   167,   171,   182,   170,   185,   186,   189,   192,
     201,   215,   216,   220,   221,   225,   226,   230,   252,   259,
     260,   261,   262,   271,   290,   290,   291,   294,   295,   296,
     297,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   314,   317,   318,   322,   321,   333,   336,
     339,   340,   341,   342,   346,   347,   348,   349,   350,   351,
     352,   356,   357,   359,   359,   369,   368,   380,   379,   390,
     390,   399,   400,   405,   408,   409,   412,   415,   416,   430,
     431,   432,   433,   434,   435,   438,   438,   451,   466,   465,
     507,   508,   509,   513,   549,   632,   633,   644,   646,   671,
     696,   721,   746,   771,   807,   818,   831,   843,   857,   862,
     869,   869,   884,   885,   888,   888,   903,   903,   906,   906,
     907,   907,   912,   913,   914,   915,   916,   920,   921,   922,
     923,   924,   925,   929,   930,   931,   932,   933,   936,   937,
     940,   941,   942,   943,   944,   947,   948,   949,   950,   951,
     954,   955,   956,   957,   958,   959,   960,   963,   964,   965,
     966,   970,   971,   972,   975,   976,   979,   980,   983,   988,
     995,  1000,  1007,  1012,  1019,  1020,  1023,  1024,  1027,  1028,
    1031,  1032,  1035,  1040,  1045,  1050,  1057,  1060,  1061,  1062,
    1063,  1066,  1069,  1073,  1077,  1081,  1087,  1092,  1100,  1101,
    1104,  1120,  1130,  1144,  1154,  1159,  1163,  1180,  1181,  1184,
    1185
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
  "$@8", "$@9", "$@10", "loop_stmt", "loop_type", "for_loop", "for_expr",
  "for_RHS", "while_loop", "$@11", "expr_stmt", "$@12", "LHS", "myId",
  "declr_stmt", "declr_body", "graph_and_array_list", "matrix_list",
  "id_list", "ifcond_stmt", "$@13", "if_body", "switch_stmt", "$@14",
  "switch_body", "$@15", "cases", "$@16", "$@17", "RHS", "constants",
  "extra_consts", "array_const", "val_list", "resultant", "impr",
  "graph_impr", "matrix_impr", "matr_body", "graph_const", "graph_type1",
  "graph_type2", "int_list", "float_list", "char_list", "bool_list",
  "str_list", "weight_list", "vect_const", "vect_list", "matrix_const",
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

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   516,   516,   289,    29,  -329,    18,  -329,  -329,  -329,
     -19,    -7,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
      36,    40,  -329,  -329,  -329,  -329,    34,  -329,   516,  -329,
    -329,  -329,     0,  -329,   685,  -329,  -329,  -329,   882,  -329,
    -329,   827,  -329,   -14,  -329,   516,    35,    60,    42,   423,
      46,    58,    62,    67,    71,   930,   516,   516,    33,    72,
      73,    75,   516,   -13,   827,    78,   827,  -329,  -329,  -329,
    -329,  -329,    81,  -329,  -329,  -329,   130,  -329,  -329,  -329,
    -329,    74,  -329,  -329,  -329,    82,  -329,    84,    87,  -329,
     882,    86,    92,    35,  -329,  -329,    96,    60,  -329,  -329,
    -329,  -329,  -329,  -329,    95,    99,   101,   545,   744,    56,
     100,   105,    13,   106,  -329,   108,  -329,    90,   109,   110,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,   744,  -329,
    -329,   744,   744,   516,   516,   516,   111,   516,   114,    10,
     130,   119,   120,  -329,  -329,  -329,   744,   744,   744,   122,
     744,   103,  -329,  -329,  -329,  -329,   516,   151,  -329,  -329,
     632,  -329,  -329,   121,  -329,  -329,  -329,  -329,   744,   744,
    -329,   141,  -329,   130,   124,   125,   154,   155,   156,  -329,
     162,   147,   153,   157,   163,   164,    80,  -329,   152,  -329,
    -329,  -329,  -329,  -329,   165,  -329,  -329,  -329,  -329,  -329,
     166,   167,   169,    25,  -329,  -329,   170,  -329,   171,  -329,
     882,   173,  -329,  -329,   484,   186,   744,   174,   175,  -329,
     150,   176,  -329,   168,   -19,  -329,   179,   180,   181,   182,
     184,   185,   187,   188,   189,   191,   193,   195,   196,   198,
     205,  -329,   204,   207,  -329,   212,   216,   218,   217,    16,
     571,   571,  -329,  -329,  -329,   744,   242,   276,   279,   280,
     278,   226,   227,   229,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,   516,   290,   292,   231,   239,   240,   243,
     244,   245,    -3,   250,   744,   744,   744,  -329,  -329,   484,
     774,   251,   252,   254,   774,   255,   256,   774,   257,   774,
     258,   259,   774,   774,   744,  -329,  -329,  -329,   744,  -329,
     301,   247,   262,  -329,  -329,   261,  -329,  -329,  -329,  -329,
    -329,    80,    80,   264,   -19,   268,  -329,   281,   282,   516,
    -329,  -329,  -329,  -329,  -329,   267,  -329,   286,   288,   293,
     294,  -329,  -329,  -329,  -329,   295,    13,    90,  -329,  -329,
    -329,  -329,  -329,  -329,   296,  -329,  -329,   297,  -329,   291,
    -329,  -329,   303,   304,  -329,   298,   305,   359,   364,  -329,
    -329,  -329,   306,   358,  -329,  -329,  -329,   312,   313,  -329,
    -329,    49,   -19,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
     774,   774,   774,  -329,    98,   308,  -329,   310,  -329,  -329,
     -19,   356,   516,   375,   516,   319,  -329,  -329,   320,   322,
     323,   324,   325,   242,   327,  -329,   386,    88,  -329,   328,
      14,   -19,  -329,  -329,  -329,   331,   332,  -329,   392,   330,
     336,   959,  -329,   327,   327,   335,  -329,   -19,   516,   337,
    -329,    90,   338,   150,  -329,  -329,  -329,  -329,   -19,   340,
     341,  -329,  -329,   -19,  -329,  -329
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
      23,     0,     0,   125,    60,     0,    58,    69,    66,    74,
      75,    70,   178,    68,    67,    61,   175,   123,    63,    64,
      65,     0,   179,   177,   176,     0,    62,     0,     0,    42,
       0,    47,     0,    30,    32,    31,     0,    37,    52,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,     0,
     125,   178,   162,     0,   152,     0,   163,   156,   177,   176,
     164,   165,   166,   153,   228,   229,   154,   155,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,   103,   104,   105,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    79,     0,     0,    73,   234,
       0,   235,    45,     0,     9,    29,    34,    36,     0,     0,
     102,   157,   167,   162,   218,   220,     0,     0,     0,   178,
       0,   203,   205,   207,   211,   209,     0,   169,     0,   170,
     171,   172,   173,   174,     0,   101,    93,    95,    97,    99,
       0,     0,     0,   139,   132,   128,     0,   131,     0,   129,
       0,   139,   133,   127,     0,     0,     0,     0,     0,   194,
     195,     0,    78,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   240,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   196,   197,   216,     0,     0,     0,     0,     0,
       0,   224,   225,     0,   168,   221,    94,    96,    98,   100,
     140,   144,   231,     0,     0,     0,     0,   178,     0,     0,
     177,   176,     0,     0,     0,     0,     0,   126,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,    10,    35,     0,   233,
       0,     0,     0,   217,   219,     0,   202,   204,   206,   210,
     208,     0,     0,     0,     0,     0,   138,     0,     0,     0,
     122,   117,   118,   120,   121,     0,   115,     0,     0,     0,
       0,    91,    92,    84,    85,     0,    86,    90,    88,    89,
      87,   180,    82,    83,     0,   192,   182,     0,   183,     0,
     193,   188,     0,     0,   239,     0,     0,   199,   201,   232,
     222,   223,   227,   143,   141,   146,   145,   135,     0,   130,
     119,     0,     0,   184,   186,   191,    80,    81,   181,   187,
       0,     0,     0,   230,     0,     0,   198,     0,   200,   226,
       0,     0,     0,     0,     0,     0,   107,   116,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,   134,     0,
       0,     0,   185,   189,   190,   213,   215,   150,     0,     0,
     137,     0,   106,     0,     0,     0,   148,     0,     0,   113,
     108,   111,   112,   114,   109,   110,   212,   214,     0,     0,
       0,   136,   151,     0,   147,   149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,   397,  -329,  -329,  -329,  -329,     1,   307,  -329,
    -329,  -329,  -329,   302,   -29,  -329,  -329,  -329,  -329,  -329,
     314,    11,   -10,  -329,    22,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,   -46,  -272,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,   183,  -329,   -50,
     238,    15,  -329,  -136,   -36,  -132,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,    -4,   -99,   -47,  -329,
    -329,  -329,   -40,   -52,   -53,   123,  -329,    38,    39,  -109,
     149,   172,   148,   177,  -328,  -329,  -137,  -329,  -206,    41,
    -218,  -329,   -43,  -200,  -329,   -30,  -329,  -329,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,   161,
      80,    81,   189,   355,   350,    83,   276,   277,   278,   279,
      84,   153,   154,   415,   450,   155,   392,    85,   390,   122,
      87,    88,   148,   214,   217,   215,    89,   334,   384,    90,
     335,   386,   411,   427,   459,   445,   229,   124,   185,   126,
     198,    91,   127,    93,    94,   231,   130,   186,   187,   321,
     200,   201,   202,   203,   322,   131,   188,   132,   273,   204,
     133,   134,   135,   136,    96,   137,    98,   171,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    86,    30,    31,    37,    82,   129,   128,    95,   219,
     199,    92,   125,   121,    39,   222,   149,   150,   184,   166,
     191,    97,   166,   166,    86,   115,    86,   104,    82,    40,
      82,    95,   364,    95,    92,   367,    92,   369,    42,    49,
     372,   373,     1,     2,    97,    37,    97,    99,   100,    37,
     160,     3,    73,    44,   -76,   123,   101,   118,    50,    58,
     191,   192,   193,   194,   195,    65,   147,   183,     3,   151,
     152,   105,   107,   159,   104,    73,   320,    73,    64,   224,
     414,  -175,   358,   441,   271,   272,   358,   283,   284,   358,
      65,   358,   345,    46,   358,   358,   162,    47,   164,    48,
     359,    37,   421,   422,   359,   230,   138,   359,   108,   359,
     438,   439,   359,   359,   190,   456,   457,   139,   105,   196,
     197,   140,   107,   323,   324,   380,   381,   141,   418,   419,
     420,   142,   156,   157,   210,   158,   163,   211,   212,   166,
     165,   168,   167,   169,   213,   216,   218,   170,   221,   173,
     174,   336,   227,   228,   176,   178,   233,   326,  -179,   179,
     180,   184,   184,   160,   205,   206,   252,   207,   208,   209,
     234,   291,   290,   223,   257,   258,   220,   289,   287,   225,
     226,   232,   358,   358,   358,   254,   260,   261,   265,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     359,   359,   359,   247,   248,   249,   250,   389,   259,   266,
     183,   183,   262,   263,   264,   267,   274,    66,  -176,   268,
     288,    37,   293,   454,   298,   269,   270,   280,   281,   275,
     282,   286,   297,   285,   284,   283,   294,   295,   296,   299,
     300,   301,   302,   230,   303,   304,   191,   305,   306,   307,
     356,   308,   352,   309,   356,   310,   311,   356,   312,   356,
     357,   325,   356,   356,   357,   313,   314,   357,   315,   357,
     360,   316,   357,   357,   360,   317,   428,   360,   319,   360,
     318,   192,   360,   360,   221,   193,   195,   194,   331,   332,
     347,   348,    12,   333,   337,   351,   338,   339,   340,   341,
      32,    33,   342,   343,   344,   376,   377,    34,    35,    36,
     252,   346,   361,   362,   375,   363,   365,   366,   368,   370,
     371,   378,   379,   382,   383,   385,   391,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     221,    26,    27,    28,    29,   387,   388,   393,   416,   394,
     356,   356,   356,   400,   395,   396,   397,   398,   399,   403,
     357,   357,   357,   405,   430,   401,   402,   404,   407,   196,
     360,   360,   360,   410,   412,   423,   413,   424,   426,   429,
     431,   432,   417,   433,   434,   435,   436,   320,   453,   452,
     437,    86,   440,   443,   444,   449,   446,   447,   448,   464,
     425,   451,   458,    41,   235,  -178,  -177,   463,   292,   177,
     175,   455,   461,   218,   172,   406,   327,   408,   330,   349,
       0,   442,     0,   409,     0,     0,    12,   109,   110,   111,
     112,   113,   374,     0,     0,     0,     0,   460,     0,     0,
     328,     0,     0,     0,     0,     0,   329,     0,   462,   216,
     114,   115,    64,   465,     0,    67,     0,     0,   116,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29,     0,
     117,     0,     0,   118,     0,     0,   119,    12,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,    64,     0,     0,    67,     0,     0,    12,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    69,    70,    71,    26,    27,    28,    29,
       0,   117,     0,     0,   118,     0,     0,   119,    12,   181,
     110,   111,   112,   113,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,    29,     0,     0,    12,   109,   110,   111,   112,   113,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,     0,   117,   182,     0,     0,     0,     0,   119,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,     0,   117,     0,
       0,     0,     0,     0,   119,    12,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,    64,     0,     0,    67,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29,    12,     0,
       0,     0,   118,   251,     0,     0,    32,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,    52,    12,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,    64,     0,     0,    67,    12,   353,   354,
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
      10,    51,     1,     2,     3,    51,    59,    59,    51,   145,
     119,    51,    59,    59,     3,   147,    66,    67,   117,     9,
       4,    51,     9,     9,    74,    28,    76,    56,    74,     0,
      76,    74,   304,    76,    74,   307,    76,   309,    57,    38,
     312,   313,    24,    25,    74,    44,    76,    61,    62,    48,
      63,    33,    51,    60,    67,    59,    55,    60,    58,    48,
       4,     5,     6,     7,     8,    30,    65,   117,    33,    36,
      37,    56,    57,    72,   103,    74,    60,    76,    29,    69,
      31,    68,   300,    69,     4,     5,   304,    62,    63,   307,
      30,   309,   292,    57,   312,   313,    74,    57,    76,    65,
     300,   100,     4,     5,   304,   158,    60,   307,    66,   309,
      22,    23,   312,   313,   118,   443,   444,    59,   103,    63,
      64,    59,   107,   260,   261,   331,   332,    60,   400,   401,
     402,    60,    60,    60,   138,    60,    58,   141,   142,     9,
      59,    59,    68,    59,   143,   144,   145,    60,   147,    63,
      58,   283,   156,   157,    58,    60,   160,   266,    68,    60,
      59,   260,   261,    63,    59,    59,   170,    59,    59,    59,
      67,   224,   224,    59,   178,   179,    65,   224,   224,    60,
      60,    59,   400,   401,   402,    64,    62,    62,    26,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     400,   401,   402,    52,    53,    54,    55,   339,    67,    62,
     260,   261,    58,    58,    58,    62,    64,    31,    68,    62,
     224,   220,   226,   441,   234,    62,    62,    61,    61,    64,
      61,   220,    64,    63,    63,    62,    62,    62,    62,    60,
      60,    60,    60,   296,    60,    60,     4,    60,    60,    60,
     300,    60,   299,    60,   304,    60,    60,   307,    60,   309,
     300,   265,   312,   313,   304,    60,    62,   307,    61,   309,
     300,    59,   312,   313,   304,    59,   412,   307,    61,   309,
      62,     5,   312,   313,   283,     6,     8,     7,    62,    62,
     294,   295,     3,    64,     4,   299,     4,    66,    59,    59,
      11,    12,    59,    59,    59,     4,    59,    18,    19,    20,
     314,    61,    61,    61,   318,    61,    61,    61,    61,    61,
      61,    59,    61,    59,   334,    57,    59,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     339,    52,    53,    54,    55,    64,    64,    61,   391,    61,
     400,   401,   402,    62,    61,    61,    61,    61,    61,    61,
     400,   401,   402,     4,   414,    62,    62,    62,     4,    63,
     400,   401,   402,    15,    62,    67,    63,    67,    22,     4,
      61,    61,   392,    61,    61,    61,    61,    60,   441,   441,
       4,   441,    64,    62,    62,   441,     4,    67,    62,    58,
     410,   441,    67,     6,   166,    68,    68,    67,   225,   107,
     103,   441,   448,   412,   100,   377,   267,   378,   270,   296,
      -1,   431,    -1,   382,    -1,    -1,     3,     4,     5,     6,
       7,     8,   314,    -1,    -1,    -1,    -1,   447,    -1,    -1,
     268,    -1,    -1,    -1,    -1,    -1,   269,    -1,   458,   448,
      27,    28,    29,   463,    -1,    32,    -1,    -1,    35,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    60,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,     3,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    60,    -1,    -1,    63,     3,     4,
       5,     6,     7,     8,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    -1,    57,    58,    -1,    -1,    -1,    -1,    63,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    63,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     3,    -1,
      -1,    -1,    60,    61,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,
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
     100,   101,   102,   105,   110,   117,   119,   120,   121,   126,
     129,   141,   142,   143,   144,   162,   164,   165,   166,    61,
      62,    77,    78,    79,    84,   121,    83,   121,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   102,   119,   136,   137,   138,   139,   142,   143,   144,
     146,   155,   157,   160,   161,   162,   163,   165,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   122,   119,
     119,    36,    37,   111,   112,   115,    60,    60,    60,    77,
      63,    99,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   167,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   119,   137,   138,   147,   148,   156,   102,
     136,     4,     5,     6,     7,     8,    63,    64,   140,   149,
     150,   151,   152,   153,   159,    59,    59,    59,    59,    59,
     136,   136,   136,    77,   123,   125,    77,   124,    77,   123,
      65,    77,   125,    59,    69,    60,    60,   136,   136,   136,
     144,   145,    59,   136,    67,   120,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   136,   168,    64,    76,    82,   136,   136,    67,
      62,    62,    58,    58,    58,    26,    62,    62,    62,    62,
      62,     4,     5,   158,    64,    64,   106,   107,   108,   109,
      61,    61,    61,    62,    63,    63,    91,   102,   136,   138,
     143,   144,   117,   136,    62,    62,    62,    64,    92,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    62,    61,    59,    59,    62,    61,
      60,   149,   154,   156,   156,   136,   149,   150,   151,   153,
     152,    62,    62,    64,   127,   130,   125,     4,     4,    66,
      59,    59,    59,    59,    59,   163,    61,   136,   136,   145,
     104,   136,   138,     4,     5,   103,   119,   142,   160,   163,
     165,    61,    61,    61,   103,    61,    61,   103,    61,   103,
      61,    61,   103,   103,   168,   136,     4,    59,    59,    61,
     158,   158,    59,    92,   128,    57,   131,    64,    64,   125,
     118,    59,   116,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    61,    62,     4,   147,     4,   148,   159,
      15,   132,    62,    63,    31,   113,   162,    92,   103,   103,
     103,     4,     5,    67,    67,    92,    22,   133,   123,     4,
     119,    61,    61,    61,    61,    61,    61,     4,    22,    23,
      64,    69,    92,    62,    62,   135,     4,    67,    62,   102,
     114,   142,   143,   144,   160,   165,   154,   154,    67,   134,
      92,   124,    92,    67,    58,    92
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
     105,   105,   105,   110,   111,   111,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   116,   115,   117,   118,   117,
     117,   117,   117,   119,   119,   120,   120,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     127,   126,   128,   128,   130,   129,   132,   131,   134,   133,
     135,   133,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   138,   138,   138,   138,   138,   139,   139,
     140,   140,   140,   140,   140,   141,   141,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   154,   154,   155,   156,   156,   156,
     156,   157,   158,   158,   158,   158,   159,   159,   160,   160,
     161,   162,   163,   163,   164,   165,   166,   167,   167,   168,
     168
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
       4,     3,     3,     2,     1,     1,     8,     1,     4,     1,
       1,     1,     1,     1,     1,     0,     6,     5,     0,     6,
       5,     5,     5,     1,     3,     1,     4,     3,     2,     2,
       5,     2,     2,     2,     6,     4,     9,     7,     3,     1,
       0,     6,     3,     1,     0,     6,     0,     7,     0,     6,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     6,     5,     5,     6,     8,     6,     6,     5,     8,
       8,     6,     5,     5,     1,     1,     3,     3,     5,     4,
       5,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     7,     5,     7,     5,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     1,     5,     4,     1,     1,
       6,     4,     5,     4,     2,     2,     2,     3,     2,     3,
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
  case 8: /* $@1: %empty  */
#line 128 "parser.y"
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
#line 1895 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 139 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1901 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 139 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1907 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 142 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1913 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 143 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1919 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 144 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1925 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 145 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1931 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 146 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1937 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 147 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1943 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 148 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1949 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 149 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1955 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 150 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1961 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 151 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1967 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 152 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1973 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 153 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1979 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 154 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1985 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 155 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1991 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 156 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1997 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 157 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2003 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 158 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 2009 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 159 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2015 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 171 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].str))!=-1 || struct_search((yyvsp[-1].str))!=-1)
								{
									printf("Struct or class name already exists\n");
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].str));
								
							}
#line 2031 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 182 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2037 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 182 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2043 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 192 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2054 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 201 "parser.y"
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
#line 2071 "y.tab.c"
    break;

  case 43: /* fdtype: dtype  */
#line 220 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2077 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 221 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2083 "y.tab.c"
    break;

  case 47: /* param: dtype id  */
#line 230 "parser.y"
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
#line 2110 "y.tab.c"
    break;

  case 48: /* param: dtype id '[' ']'  */
#line 252 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2118 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 259 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2124 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 260 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2130 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 261 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2136 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 262 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2150 "y.tab.c"
    break;

  case 53: /* dtype: id  */
#line 271 "parser.y"
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
#line 2172 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 290 "parser.y"
                                      { level++; }
#line 2178 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 290 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2184 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 310 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2190 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 311 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2196 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 314 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2202 "y.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 322 "parser.y"
                                                        {
								if(label_search((yyvsp[0].str))!=-1) 
								{
									printf("Label name already exists\n");
									exit(1);
								}
								else label_insert((yyvsp[0].str));
							}
#line 2215 "y.tab.c"
    break;

  case 77: /* label_stmt: id $@6 ':' function_body  */
#line 330 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2221 "y.tab.c"
    break;

  case 78: /* goto_stmt: GOTO id ';'  */
#line 333 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2227 "y.tab.c"
    break;

  case 79: /* vect_stmt: vect_stmt_body ';'  */
#line 336 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2233 "y.tab.c"
    break;

  case 93: /* $@7: %empty  */
#line 359 "parser.y"
                                               {if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							}
#line 2247 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN RHS ';' $@7  */
#line 367 "parser.y"
                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2253 "y.tab.c"
    break;

  case 95: /* $@8: %empty  */
#line 369 "parser.y"
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
#line 2268 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN extra_consts ';' $@8  */
#line 378 "parser.y"
                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2274 "y.tab.c"
    break;

  case 97: /* $@9: %empty  */
#line 380 "parser.y"
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
#line 2289 "y.tab.c"
    break;

  case 98: /* return_stmt: RETURN graph_impr ';' $@9  */
#line 389 "parser.y"
                                                   {fprintf(fparse, " : RETURN STATEMENT");}
#line 2295 "y.tab.c"
    break;

  case 99: /* $@10: %empty  */
#line 390 "parser.y"
                                                                        {if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("error\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex-1].type)){
									printf("error\n");
								}
							}
							}
#line 2309 "y.tab.c"
    break;

  case 100: /* return_stmt: RETURN matrix_impr ';' $@10  */
#line 398 "parser.y"
                                                           {fprintf(fparse, " : RETURN STATEMENT");}
#line 2315 "y.tab.c"
    break;

  case 101: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 399 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2321 "y.tab.c"
    break;

  case 102: /* return_stmt: RETURN null ';'  */
#line 400 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2327 "y.tab.c"
    break;

  case 103: /* loop_stmt: LOOP loop_type  */
#line 405 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2333 "y.tab.c"
    break;

  case 108: /* for_expr: EXPR LHS '=' for_RHS  */
#line 416 "parser.y"
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
#line 2350 "y.tab.c"
    break;

  case 109: /* for_RHS: arith_op  */
#line 430 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2356 "y.tab.c"
    break;

  case 110: /* for_RHS: func_calls  */
#line 431 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2362 "y.tab.c"
    break;

  case 111: /* for_RHS: impr  */
#line 432 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2368 "y.tab.c"
    break;

  case 112: /* for_RHS: graph_impr  */
#line 433 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2374 "y.tab.c"
    break;

  case 113: /* for_RHS: vect_stmt_body  */
#line 434 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2380 "y.tab.c"
    break;

  case 114: /* for_RHS: matrix_impr  */
#line 435 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2386 "y.tab.c"
    break;

  case 115: /* $@11: %empty  */
#line 438 "parser.y"
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
#line 2402 "y.tab.c"
    break;

  case 117: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 451 "parser.y"
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
#line 2421 "y.tab.c"
    break;

  case 118: /* $@12: %empty  */
#line 466 "parser.y"
                                                        {
								if(classIndex==-1)
								{
									if(strcmp("graph", (yyvsp[-3].details).type)==0)
									{
										int ind = var_search((yyvsp[-3].details).name);
										int dimAval = var_symb[ind].dim_A;
										for(int i=0; i<arr_size; i++)
										{
											if(dimA[i]>dimAval)
											{
												printf("ERROR: Vertex used is not present in the graph\n");
												exit(1);
											}
										}
										arr_size=0;
									}
									else if(strcmp("matrix", (yyvsp[-3].details).type)==0)
									{
										int ind = var_search((yyvsp[-3].details).name);
										int rows = var_symb[ind].dim_A;
										int columns = var_symb[ind].dim_B;
										if(arr_size!=rows) 
										{
											printf("ERROR: Number of rows mismatch\n");
											exit(1);
										}
										for(int i=0; i<arr_size; i++)
										{
											if(dimA[i]!=columns)
											{
												printf("ERROR: Number of columns mismatch\n");
												exit(1);
											}
										}
										arr_size=0;
									}
								}
							}
#line 2465 "y.tab.c"
    break;

  case 119: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@12  */
#line 505 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2471 "y.tab.c"
    break;

  case 120: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 507 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2477 "y.tab.c"
    break;

  case 121: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 508 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2483 "y.tab.c"
    break;

  case 122: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 509 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2489 "y.tab.c"
    break;

  case 123: /* LHS: myId  */
#line 513 "parser.y"
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
										printf("Error: Accessing undeclared identifier %s\n", (yyvsp[0].str));
										exit(1);
									}
									
									else{
										(yyval.details).name = (yyvsp[0].str);
										(yyval.details).type = class_symb[class_size-1].declr_list[i].type;
										classIndex=class_size-1;
									}
								}
								
								else{
									// statement not in class & LHS not in symbol table
									printf("Error: Accessing undeclared identifier %s\n", (yyvsp[0].str));
									exit(1);
								}
							}
							
							else{
								// myId exists in var_symb ==> declared inside function
								(yyval.details).name = (yyvsp[0].str);
								(yyval.details).type = var_symb[i].type;
							}
						}
#line 2530 "y.tab.c"
    break;

  case 124: /* LHS: LHS ARROW myId  */
#line 549 "parser.y"
                                                                 {
							int ind = var_search((yyvsp[-2].details).name);
							char* dType;
							if(ind < 0){
								if(inClass){
									ind = class_declr_search((yyvsp[-2].details).name, class_size-1); // search in current class
									if(ind < 0){
										// statement is in class, yet LHS not in symbol table
										printf("Error: Accessing undeclared identifier %s\n", (yyvsp[-2].details).name);
										exit(1);
									}
									
									else{
										dType = class_symb[class_size-1].declr_list[ind].type;
										classIndex=class_size-1;
									}
								}
								
								else{
									// statement not in class & LHS not in symbol table
									printf("Error: Accessing undeclared identifier %s\n", (yyvsp[-2].details).name);
									exit(1);
								}
							}
							else dType = var_symb[ind].type;
							
							// check if dType is declared in struct or in class
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
								// item defined in struct, now check its attributes
								int j = struct_declr_search((yyvsp[0].str), i);
								printf("%s AND %s\n", (yyvsp[0].str), struct_symb[i].name);
								printStructNode(struct_symb[i]);
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
#line 2615 "y.tab.c"
    break;

  case 125: /* myId: id  */
#line 632 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2621 "y.tab.c"
    break;

  case 126: /* myId: id '[' RHS ']'  */
#line 633 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("Error: invalid array index\n");
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2634 "y.tab.c"
    break;

  case 127: /* declr_stmt: DECLR declr_body ';'  */
#line 644 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2640 "y.tab.c"
    break;

  case 128: /* declr_body: DATATYPE id_list  */
#line 647 "parser.y"
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
#line 2669 "y.tab.c"
    break;

  case 129: /* declr_body: GRAPH graph_and_array_list  */
#line 672 "parser.y"
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
#line 2698 "y.tab.c"
    break;

  case 130: /* declr_body: VECT '<' dtype '>' id_list  */
#line 697 "parser.y"
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
#line 2727 "y.tab.c"
    break;

  case 131: /* declr_body: MATRIX matrix_list  */
#line 722 "parser.y"
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
#line 2756 "y.tab.c"
    break;

  case 132: /* declr_body: DATATYPE graph_and_array_list  */
#line 747 "parser.y"
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
#line 2785 "y.tab.c"
    break;

  case 133: /* declr_body: id id_list  */
#line 772 "parser.y"
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
#line 2823 "y.tab.c"
    break;

  case 134: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 808 "parser.y"
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
#line 2838 "y.tab.c"
    break;

  case 135: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 819 "parser.y"
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
#line 2853 "y.tab.c"
    break;

  case 136: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 832 "parser.y"
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
#line 2869 "y.tab.c"
    break;

  case 137: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 844 "parser.y"
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
#line 2885 "y.tab.c"
    break;

  case 138: /* id_list: id ',' id_list  */
#line 858 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 2894 "y.tab.c"
    break;

  case 139: /* id_list: id  */
#line 863 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 2903 "y.tab.c"
    break;

  case 140: /* $@13: %empty  */
#line 869 "parser.y"
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
#line 2920 "y.tab.c"
    break;

  case 144: /* $@14: %empty  */
#line 888 "parser.y"
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
#line 2937 "y.tab.c"
    break;

  case 146: /* $@15: %empty  */
#line 903 "parser.y"
                                              {switch_insert(level); level++;}
#line 2943 "y.tab.c"
    break;

  case 147: /* switch_body: '{' $@15 cases DEFAULT ':' function_body '}'  */
#line 903 "parser.y"
                                                                                                                   { var_delete(level); level--; switch_delete();}
#line 2949 "y.tab.c"
    break;

  case 148: /* $@16: %empty  */
#line 906 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str));}
#line 2955 "y.tab.c"
    break;

  case 150: /* $@17: %empty  */
#line 907 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str));}
#line 2961 "y.tab.c"
    break;

  case 152: /* RHS: constants  */
#line 912 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 2967 "y.tab.c"
    break;

  case 153: /* RHS: arith_op  */
#line 913 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2973 "y.tab.c"
    break;

  case 154: /* RHS: logical_op  */
#line 914 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2979 "y.tab.c"
    break;

  case 155: /* RHS: func_calls  */
#line 915 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2985 "y.tab.c"
    break;

  case 156: /* RHS: impr  */
#line 916 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2991 "y.tab.c"
    break;

  case 157: /* constants: INT_CONST  */
#line 920 "parser.y"
                                                    {(yyval.str)="int";}
#line 2997 "y.tab.c"
    break;

  case 158: /* constants: FLOAT_CONST  */
#line 921 "parser.y"
                                                              {(yyval.str)="float";}
#line 3003 "y.tab.c"
    break;

  case 159: /* constants: CHAR_CONST  */
#line 922 "parser.y"
                                                             {(yyval.str)="char";}
#line 3009 "y.tab.c"
    break;

  case 160: /* constants: STR_CONST  */
#line 923 "parser.y"
                                                            {(yyval.str)="string";}
#line 3015 "y.tab.c"
    break;

  case 161: /* constants: BOOL_CONST  */
#line 924 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 3021 "y.tab.c"
    break;

  case 162: /* constants: LHS  */
#line 925 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 3027 "y.tab.c"
    break;

  case 163: /* extra_consts: array_const  */
#line 929 "parser.y"
                                             {(yyval.str) = "2";}
#line 3033 "y.tab.c"
    break;

  case 164: /* extra_consts: graph_const  */
#line 930 "parser.y"
                                                             {(yyval.str)="graph";}
#line 3039 "y.tab.c"
    break;

  case 165: /* extra_consts: vect_const  */
#line 931 "parser.y"
                                                            {(yyval.str)="vect";}
#line 3045 "y.tab.c"
    break;

  case 166: /* extra_consts: matrix_const  */
#line 932 "parser.y"
                                                              {(yyval.str)="matrix";}
#line 3051 "y.tab.c"
    break;

  case 167: /* extra_consts: '{' '}'  */
#line 933 "parser.y"
                                                         {(yyval.str)="1";}
#line 3057 "y.tab.c"
    break;

  case 180: /* impr: resultant '.' LENGTH '(' ')'  */
#line 954 "parser.y"
                                                                      {(yyval.str) = "int";}
#line 3063 "y.tab.c"
    break;

  case 181: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 955 "parser.y"
                                                                                      {(yyval.str) = "0";}
#line 3069 "y.tab.c"
    break;

  case 182: /* impr: resultant '.' TRACE '(' ')'  */
#line 956 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3075 "y.tab.c"
    break;

  case 183: /* impr: resultant '.' STRLEN '(' ')'  */
#line 957 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3081 "y.tab.c"
    break;

  case 184: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 958 "parser.y"
                                                                             {(yyval.str) = "bool";}
#line 3087 "y.tab.c"
    break;

  case 185: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 959 "parser.y"
                                                                                                          {(yyval.str) = "string";}
#line 3093 "y.tab.c"
    break;

  case 186: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 960 "parser.y"
                                                                             {(yyval.str) =  "string";}
#line 3099 "y.tab.c"
    break;

  case 187: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 963 "parser.y"
                                                                                     {(yyval.str) = "vect";}
#line 3105 "y.tab.c"
    break;

  case 188: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 964 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3111 "y.tab.c"
    break;

  case 189: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 965 "parser.y"
                                                                                                          {(yyval.str) = "vect";}
#line 3117 "y.tab.c"
    break;

  case 190: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 966 "parser.y"
                                                                                                               {(yyval.str) = "int";}
#line 3123 "y.tab.c"
    break;

  case 191: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 970 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3129 "y.tab.c"
    break;

  case 192: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 971 "parser.y"
                                                                                  {(yyval.str) = "matrix";}
#line 3135 "y.tab.c"
    break;

  case 193: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 972 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3141 "y.tab.c"
    break;

  case 198: /* graph_type1: INT_CONST ':' int_list ';' graph_type1  */
#line 984 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3150 "y.tab.c"
    break;

  case 199: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 989 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3159 "y.tab.c"
    break;

  case 200: /* graph_type2: INT_CONST ':' weight_list ';' graph_type2  */
#line 996 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3168 "y.tab.c"
    break;

  case 201: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 1001 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3177 "y.tab.c"
    break;

  case 202: /* int_list: INT_CONST ',' int_list  */
#line 1008 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-2].str));
								arr_size++;
							}
#line 3186 "y.tab.c"
    break;

  case 203: /* int_list: INT_CONST  */
#line 1013 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[0].str));
								arr_size++;
							}
#line 3195 "y.tab.c"
    break;

  case 212: /* weight_list: '(' INT_CONST ',' INT_CONST ')' ',' weight_list  */
#line 1036 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3204 "y.tab.c"
    break;

  case 213: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 1041 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3213 "y.tab.c"
    break;

  case 214: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list  */
#line 1046 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3222 "y.tab.c"
    break;

  case 215: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 1051 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3231 "y.tab.c"
    break;

  case 222: /* int_float_list: INT_CONST ',' int_float_list  */
#line 1070 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3239 "y.tab.c"
    break;

  case 223: /* int_float_list: FLOAT_CONST ',' int_float_list  */
#line 1074 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3247 "y.tab.c"
    break;

  case 224: /* int_float_list: INT_CONST  */
#line 1078 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3255 "y.tab.c"
    break;

  case 225: /* int_float_list: FLOAT_CONST  */
#line 1082 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3263 "y.tab.c"
    break;

  case 226: /* mat_list: '[' int_float_list ']' ';' mat_list  */
#line 1088 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-3].Cols).cols;
								arr_size++;
							}
#line 3272 "y.tab.c"
    break;

  case 227: /* mat_list: '[' int_float_list ']' ';'  */
#line 1093 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-2].Cols).cols;
								arr_size++;
							}
#line 3281 "y.tab.c"
    break;

  case 230: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 1104 "parser.y"
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
#line 3300 "y.tab.c"
    break;

  case 231: /* unary_op: UNARYOP '(' RHS ')'  */
#line 1120 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3313 "y.tab.c"
    break;

  case 232: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 1130 "parser.y"
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
#line 3332 "y.tab.c"
    break;

  case 233: /* logical_op: NOT '(' RHS ')'  */
#line 1144 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 3345 "y.tab.c"
    break;

  case 234: /* call_stmt: func_calls ';'  */
#line 1154 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 3351 "y.tab.c"
    break;

  case 235: /* func_calls: call_head arguments  */
#line 1159 "parser.y"
                                                              {(yyval.str) = (yyvsp[-1].str);}
#line 3357 "y.tab.c"
    break;

  case 236: /* call_head: CALL LHS  */
#line 1163 "parser.y"
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
#line 3377 "y.tab.c"
    break;


#line 3381 "y.tab.c"

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

#line 1188 "parser.y"


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




