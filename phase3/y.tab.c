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
  YYSYMBOL_float_list = 151,               /* float_list  */
  YYSYMBOL_char_list = 152,                /* char_list  */
  YYSYMBOL_bool_list = 153,                /* bool_list  */
  YYSYMBOL_str_list = 154,                 /* str_list  */
  YYSYMBOL_weight_list = 155,              /* weight_list  */
  YYSYMBOL_vect_const = 156,               /* vect_const  */
  YYSYMBOL_vect_list = 157,                /* vect_list  */
  YYSYMBOL_matrix_const = 158,             /* matrix_const  */
  YYSYMBOL_int_float_list = 159,           /* int_float_list  */
  YYSYMBOL_mat_list = 160,                 /* mat_list  */
  YYSYMBOL_arith_op = 161,                 /* arith_op  */
  YYSYMBOL_binary_op = 162,                /* binary_op  */
  YYSYMBOL_unary_op = 163,                 /* unary_op  */
  YYSYMBOL_logical_op = 164,               /* logical_op  */
  YYSYMBOL_call_stmt = 165,                /* call_stmt  */
  YYSYMBOL_func_calls = 166,               /* func_calls  */
  YYSYMBOL_call_head = 167,                /* call_head  */
  YYSYMBOL_arguments = 168,                /* arguments  */
  YYSYMBOL_arg_list = 169                  /* arg_list  */
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
#define YYLAST   967

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  467

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
     166,   169,   170,   174,   185,   173,   188,   189,   192,   195,
     204,   218,   219,   223,   224,   228,   229,   233,   255,   262,
     263,   264,   265,   274,   293,   293,   294,   297,   298,   299,
     300,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   317,   320,   321,   325,   324,   336,   339,
     342,   346,   349,   356,   366,   367,   368,   369,   370,   371,
     372,   376,   377,   379,   379,   390,   389,   401,   400,   411,
     411,   420,   423,   423,   436,   439,   440,   443,   446,   447,
     461,   462,   463,   464,   465,   466,   469,   469,   482,   497,
     496,   546,   547,   548,   552,   611,   695,   696,   707,   709,
     734,   759,   784,   809,   834,   870,   881,   894,   906,   920,
     925,   932,   932,   947,   948,   951,   951,   966,   966,   969,
     969,   970,   970,   975,   976,   977,   978,   979,   983,   984,
     985,   986,   987,   988,   992,   993,   994,   995,   996,   999,
    1000,  1003,  1004,  1005,  1006,  1007,  1010,  1011,  1012,  1013,
    1014,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1027,  1028,
    1029,  1030,  1034,  1037,  1038,  1041,  1042,  1045,  1046,  1049,
    1054,  1061,  1066,  1073,  1078,  1085,  1086,  1089,  1090,  1093,
    1094,  1097,  1098,  1101,  1106,  1111,  1116,  1123,  1126,  1127,
    1128,  1129,  1132,  1135,  1139,  1143,  1147,  1153,  1158,  1166,
    1167,  1170,  1186,  1196,  1210,  1220,  1225,  1243,  1256,  1257,
    1260,  1294
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

#define YYPACT_NINF (-308)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-181)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   517,   517,   149,    27,  -308,    73,  -308,  -308,  -308,
      -9,    -6,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,
      15,    35,  -308,  -308,  -308,  -308,    31,  -308,   517,  -308,
    -308,  -308,    41,  -308,   686,  -308,  -308,  -308,   290,  -308,
    -308,   828,  -308,    -4,  -308,   517,    20,    77,    37,   424,
      25,    52,    57,    54,    83,   883,   517,   517,    32,    87,
      89,    90,   517,   -16,   828,    64,   828,  -308,  -308,  -308,
    -308,  -308,    94,  -308,  -308,  -308,   145,  -308,  -308,  -308,
    -308,    88,  -308,  -308,  -308,    96,  -308,    98,    99,  -308,
     290,    95,   104,    20,  -308,  -308,   107,    77,  -308,  -308,
    -308,  -308,  -308,  -308,   110,   121,   114,   546,   745,    55,
     119,   124,    16,   125,  -308,   126,  -308,   118,   141,   146,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,   745,  -308,
    -308,   745,   745,   517,   517,   517,   148,   517,   147,    11,
     145,   154,   156,  -308,  -308,  -308,   745,   745,   745,   158,
     745,   151,  -308,  -308,  -308,  -308,   517,   456,  -308,  -308,
     633,  -308,  -308,   159,  -308,  -308,  -308,  -308,   745,   745,
    -308,   153,  -308,   145,   160,   163,   168,   170,   171,  -308,
     204,   169,   172,   173,   174,   175,    60,  -308,   176,  -308,
    -308,  -308,  -308,  -308,   177,  -308,  -308,  -308,  -308,  -308,
     178,   181,   182,    62,  -308,  -308,   183,  -308,   184,  -308,
     290,   188,  -308,  -308,   485,   201,   745,   190,   192,  -308,
     165,   195,  -308,   198,    -9,  -308,   185,   199,   206,   207,
     216,   219,   221,   222,   226,   227,   228,   229,   230,   231,
     232,  -308,  -308,    65,  -308,   179,   235,   233,   236,  -308,
      19,   572,   572,  -308,  -308,  -308,   745,   292,   293,   294,
     295,   291,   241,   242,   243,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,   517,   301,   302,   245,   253,   254,
     255,   256,   257,    10,   258,   745,   745,   745,  -308,  -308,
     485,   775,   259,   260,   261,   775,   262,   263,   775,   265,
     775,   266,   285,   775,   775,  -308,   745,  -308,  -308,   745,
    -308,   313,   288,   289,  -308,  -308,   296,  -308,  -308,  -308,
    -308,  -308,    60,    60,   297,    -9,   298,  -308,   286,   300,
     517,  -308,  -308,  -308,  -308,  -308,   299,  -308,   305,   306,
     307,   308,  -308,  -308,  -308,  -308,   309,    16,   118,  -308,
    -308,  -308,  -308,  -308,  -308,   314,  -308,  -308,   315,  -308,
     312,  -308,  -308,   316,   317,  -308,   319,   320,   350,   355,
    -308,  -308,  -308,   318,   303,  -308,  -308,  -308,   322,   323,
    -308,  -308,    59,    -9,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,   775,   775,   775,  -308,   129,   310,  -308,   321,  -308,
    -308,    -9,   338,   517,   381,   517,   326,  -308,  -308,   330,
     332,   333,   334,   336,   292,   339,  -308,   394,   113,  -308,
     340,    13,    -9,  -308,  -308,  -308,   341,   343,  -308,   396,
     342,   344,   912,  -308,   339,   339,   346,  -308,    -9,   517,
     347,  -308,   118,   348,   165,  -308,  -308,  -308,  -308,    -9,
     351,   349,  -308,  -308,    -9,  -308,  -308
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
     165,   166,   167,   154,   229,   230,   155,   156,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    79,     0,     0,    73,   235,
       0,   236,    45,     0,     9,    29,    34,    36,     0,     0,
     102,   158,   168,   163,   219,   221,     0,     0,     0,   179,
       0,   204,   206,   208,   212,   210,     0,   170,     0,   171,
     172,   173,   174,   175,     0,   101,    93,    95,    97,    99,
       0,     0,     0,   140,   133,   129,     0,   132,     0,   130,
       0,   140,   134,   128,     0,     0,     0,     0,     0,   195,
     196,     0,    78,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,     0,    48,     0,     0,     0,     0,   103,
       0,     0,     0,   197,   198,   217,     0,     0,     0,     0,
       0,     0,   225,   226,     0,   169,   222,    94,    96,    98,
     100,   141,   145,   232,     0,     0,     0,     0,   179,     0,
       0,   178,   177,     0,     0,     0,     0,     0,   127,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,    10,    35,     0,
     234,     0,     0,     0,   218,   220,     0,   203,   205,   207,
     211,   209,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   123,   118,   119,   121,   122,     0,   116,     0,     0,
       0,     0,    91,    92,    84,    85,     0,    86,    90,    88,
      89,    87,   181,    82,    83,     0,   193,   183,     0,   184,
       0,   194,   189,     0,     0,   241,     0,     0,   200,   202,
     233,   223,   224,   228,   144,   142,   147,   146,   136,     0,
     131,   120,     0,     0,   185,   187,   192,    80,    81,   182,
     188,     0,     0,     0,   231,     0,     0,   199,     0,   201,
     227,     0,     0,     0,     0,     0,     0,   108,   117,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,   135,
       0,     0,     0,   186,   190,   191,   214,   216,   151,     0,
       0,   138,     0,   107,     0,     0,     0,   149,     0,     0,
     114,   109,   112,   113,   115,   110,   111,   213,   215,     0,
       0,     0,   137,   152,     0,   148,   150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -308,  -308,   402,  -308,  -308,  -308,  -308,     1,   331,  -308,
    -308,  -308,  -308,   304,   -27,  -308,  -308,  -308,  -308,  -308,
     324,     7,   -10,  -308,    28,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,   -46,  -273,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,  -308,   194,  -308,
     -50,   244,   -14,  -308,  -136,   -32,  -133,  -308,  -308,  -308,
    -308,  -308,  -308,  -308,  -308,  -308,  -308,   -47,   -98,   -44,
    -308,  -308,  -308,   -40,   -52,   -53,   123,  -308,    43,    44,
    -101,   157,   164,   155,   166,  -307,  -308,  -122,  -308,  -191,
      56,  -227,  -308,   -43,  -193,  -308,   -30,  -308,  -308,  -308
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,   161,
      80,    81,   189,   356,   351,    83,   277,   278,   279,   280,
     259,    84,   153,   154,   416,   451,   155,   393,    85,   391,
     122,    87,    88,   148,   214,   217,   215,    89,   335,   385,
      90,   336,   387,   412,   428,   460,   446,   229,   124,   185,
     126,   198,    91,   127,    93,    94,   231,   130,   186,   187,
     322,   200,   201,   202,   203,   323,   131,   188,   132,   274,
     204,   133,   134,   135,   136,    96,   137,    98,   171,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    86,    30,    31,    37,    82,   129,   128,    95,   219,
      39,    92,   123,   121,   222,   125,   149,   150,   199,   184,
     166,    97,   166,   191,    86,   166,    86,    40,    82,   104,
      82,    95,   365,    95,    92,   368,    92,   370,   115,    49,
     373,   374,   105,   107,    97,    37,    97,   160,    42,    37,
      65,   -76,    73,     3,    44,    58,   101,    99,   100,   191,
     192,   193,   194,   195,   272,   273,   147,   183,   151,   152,
     118,   190,    46,   159,   359,    73,   104,    73,   359,   321,
     224,   359,   442,   359,  -176,   138,   359,   359,    64,   105,
     415,   210,    47,   107,   211,   212,    48,     1,     2,    50,
     346,    37,   162,   108,   164,   230,     3,    65,   360,   227,
     228,   139,   360,   233,   141,   360,   140,   360,   196,   197,
     360,   360,   163,   252,   284,   285,   315,   316,   419,   420,
     421,   257,   258,   422,   423,   439,   440,   457,   458,   324,
     325,   381,   382,   142,   213,   216,   218,   156,   221,   157,
     158,   337,    12,   165,   166,   168,   167,   169,   173,   170,
      32,    33,   174,   184,   184,   176,   327,    34,    35,    36,
     178,   292,   291,   180,   359,   359,   359,   289,   288,   294,
     290,   179,   160,   205,   206,   207,  -180,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     208,    26,    27,    28,    29,   209,   223,   390,   360,   360,
     360,   183,   183,   220,   225,   455,   226,   232,   234,   326,
     260,    37,   261,   254,   299,   262,   263,   287,   264,   265,
     266,   267,    66,  -177,   268,   269,   270,   271,   317,   281,
     275,   276,   282,   283,   230,   300,   286,   285,   348,   349,
     284,   357,   295,   352,   296,   357,   353,   297,   357,   301,
     357,   358,   298,   357,   357,   358,   302,   303,   358,   375,
     358,   361,   376,   358,   358,   361,   304,   429,   361,   305,
     361,   306,   307,   361,   361,   221,   308,   309,   310,   311,
     312,   313,   314,    12,   318,   319,   191,   320,   192,   195,
     193,    32,   194,   332,   333,   338,   339,   334,    34,    35,
      36,   340,   341,   342,   343,   344,   345,   377,   411,   347,
     362,   363,   364,   366,   367,   384,   369,   371,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   221,    26,    27,    28,    29,   372,   378,   379,   417,
     388,   357,   357,   357,   406,   386,   383,   380,   392,   408,
     427,   358,   358,   358,   389,   431,   394,   395,   396,   397,
     398,   361,   361,   361,   401,   399,   400,   424,   402,   403,
     404,   196,   405,   418,   413,   430,   414,   432,   425,   454,
     453,   433,    86,   434,   435,   436,   450,   437,   438,   321,
     447,   426,   452,   444,   441,   445,   449,   465,    41,   448,
     235,   177,   456,   459,   218,  -179,  -178,   462,   464,   293,
     350,   407,   443,   409,   172,   328,   331,    12,   109,   110,
     111,   112,   113,   329,   175,     0,   330,     0,   461,   410,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     216,   114,   115,    64,   466,     0,    67,     0,     0,   116,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    69,    70,    71,    26,    27,    28,    29,
       0,   117,     0,     0,   118,     0,     0,   119,    12,   109,
     110,   111,   112,   113,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     0,   247,   248,
     249,   250,   114,   115,    64,     0,     0,    67,     0,     0,
      12,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,     0,   117,     0,     0,   118,     0,     0,   119,    12,
     181,   110,   111,   112,   113,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,     0,     0,    12,   109,   110,   111,   112,
     113,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,    29,     0,   117,   182,     0,     0,     0,     0,   119,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,    29,     0,   117,
       0,     0,     0,     0,     0,   119,    12,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,    64,     0,     0,    67,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29,    12,
       0,     0,     0,   118,   251,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,    29,     0,     0,     0,     0,     0,    52,    12,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,    64,     0,     0,    67,    12,   354,
     355,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,     0,   114,   115,    64,   118,     0,    67,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    69,    70,    71,    26,    27,    28,
      29,    12,     0,     0,     0,   118,     0,     0,     0,     0,
       0,    59,    60,     0,    61,    62,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,     0,    68,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    69,    70,    71,
      26,    27,    28,    29,    72,    42,    12,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,   114,
       0,    64,     0,     0,    67,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
      10,    51,     1,     2,     3,    51,    59,    59,    51,   145,
       3,    51,    59,    59,   147,    59,    66,    67,   119,   117,
       9,    51,     9,     4,    74,     9,    76,     0,    74,    56,
      76,    74,   305,    76,    74,   308,    76,   310,    28,    38,
     313,   314,    56,    57,    74,    44,    76,    63,    57,    48,
      30,    67,    51,    33,    60,    48,    55,    61,    62,     4,
       5,     6,     7,     8,     4,     5,    65,   117,    36,    37,
      60,   118,    57,    72,   301,    74,   103,    76,   305,    60,
      69,   308,    69,   310,    68,    60,   313,   314,    29,   103,
      31,   138,    57,   107,   141,   142,    65,    24,    25,    58,
     293,   100,    74,    66,    76,   158,    33,    30,   301,   156,
     157,    59,   305,   160,    60,   308,    59,   310,    63,    64,
     313,   314,    58,   170,    62,    63,    61,    62,   401,   402,
     403,   178,   179,     4,     5,    22,    23,   444,   445,   261,
     262,   332,   333,    60,   143,   144,   145,    60,   147,    60,
      60,   284,     3,    59,     9,    59,    68,    59,    63,    60,
      11,    12,    58,   261,   262,    58,   267,    18,    19,    20,
      60,   224,   224,    59,   401,   402,   403,   224,   224,   226,
     224,    60,    63,    59,    59,    59,    68,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      59,    52,    53,    54,    55,    59,    59,   340,   401,   402,
     403,   261,   262,    65,    60,   442,    60,    59,    67,   266,
      67,   220,    62,    64,   234,    62,    58,   220,    58,    58,
      26,    62,    31,    68,    62,    62,    62,    62,    59,    61,
      64,    64,    61,    61,   297,    60,    63,    63,   295,   296,
      62,   301,    62,   300,    62,   305,   300,    62,   308,    60,
     310,   301,    64,   313,   314,   305,    60,    60,   308,   316,
     310,   301,   319,   313,   314,   305,    60,   413,   308,    60,
     310,    60,    60,   313,   314,   284,    60,    60,    60,    60,
      60,    60,    60,     3,    59,    62,     4,    61,     5,     8,
       6,    11,     7,    62,    62,     4,     4,    64,    18,    19,
      20,    66,    59,    59,    59,    59,    59,     4,    15,    61,
      61,    61,    61,    61,    61,   335,    61,    61,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   340,    52,    53,    54,    55,    61,    59,    59,   392,
      64,   401,   402,   403,     4,    57,    59,    61,    59,     4,
      22,   401,   402,   403,    64,   415,    61,    61,    61,    61,
      61,   401,   402,   403,    62,    61,    61,    67,    62,    62,
      61,    63,    62,   393,    62,     4,    63,    61,    67,   442,
     442,    61,   442,    61,    61,    61,   442,    61,     4,    60,
       4,   411,   442,    62,    64,    62,    62,    58,     6,    67,
     166,   107,   442,    67,   413,    68,    68,   449,    67,   225,
     297,   378,   432,   379,   100,   268,   271,     3,     4,     5,
       6,     7,     8,   269,   103,    -1,   270,    -1,   448,   383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   459,
     449,    27,    28,    29,   464,    -1,    32,    -1,    -1,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    60,    -1,    -1,    63,     3,     4,
       5,     6,     7,     8,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    52,    53,
      54,    55,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
       3,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    60,    -1,    -1,    63,     3,
       4,     5,     6,     7,     8,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,    63,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    63,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
      -1,    -1,    -1,    60,    61,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,     3,     4,
       5,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    27,    28,    29,    60,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     3,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    16,    17,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    27,
      -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55
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
     130,   142,   143,   144,   145,   163,   165,   166,   167,    61,
      62,    77,    78,    79,    84,   122,    83,   122,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   102,   120,   137,   138,   139,   140,   143,   144,   145,
     147,   156,   158,   161,   162,   163,   164,   166,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   123,   120,
     120,    36,    37,   112,   113,   116,    60,    60,    60,    77,
      63,    99,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   168,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   120,   138,   139,   148,   149,   157,   102,
     137,     4,     5,     6,     7,     8,    63,    64,   141,   150,
     151,   152,   153,   154,   160,    59,    59,    59,    59,    59,
     137,   137,   137,    77,   124,   126,    77,   125,    77,   124,
      65,    77,   126,    59,    69,    60,    60,   137,   137,   137,
     145,   146,    59,   137,    67,   121,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   137,   169,    64,    76,    82,   137,   137,   110,
      67,    62,    62,    58,    58,    58,    26,    62,    62,    62,
      62,    62,     4,     5,   159,    64,    64,   106,   107,   108,
     109,    61,    61,    61,    62,    63,    63,    91,   102,   137,
     139,   144,   145,   118,   137,    62,    62,    62,    64,    92,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    59,    59,    62,
      61,    60,   150,   155,   157,   157,   137,   150,   151,   152,
     154,   153,    62,    62,    64,   128,   131,   126,     4,     4,
      66,    59,    59,    59,    59,    59,   164,    61,   137,   137,
     146,   104,   137,   139,     4,     5,   103,   120,   143,   161,
     164,   166,    61,    61,    61,   103,    61,    61,   103,    61,
     103,    61,    61,   103,   103,   137,   137,     4,    59,    59,
      61,   159,   159,    59,    92,   129,    57,   132,    64,    64,
     126,   119,    59,   117,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    61,    62,     4,   148,     4,   149,
     160,    15,   133,    62,    63,    31,   114,   163,    92,   103,
     103,   103,     4,     5,    67,    67,    92,    22,   134,   124,
       4,   120,    61,    61,    61,    61,    61,    61,     4,    22,
      23,    64,    69,    92,    62,    62,   136,     4,    67,    62,
     102,   115,   143,   144,   145,   161,   166,   155,   155,    67,
     135,    92,   125,    92,    67,    58,    92
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
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   155,   155,   156,   157,   157,
     157,   157,   158,   159,   159,   159,   159,   160,   160,   161,
     161,   162,   163,   164,   164,   165,   166,   167,   168,   168,
     169,   169
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
       4,     5,     4,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     7,     5,     7,     5,     3,     3,     1,
       3,     1,     3,     3,     3,     1,     1,     5,     4,     1,
       1,     6,     4,     5,     4,     2,     2,     2,     3,     2,
       1,     3
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
#line 1889 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 142 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1895 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 142 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1901 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 145 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1907 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 146 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1913 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 147 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1919 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 148 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1925 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 149 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1931 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 150 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1937 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 151 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1943 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 152 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1949 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 153 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1955 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 154 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1961 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 155 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1967 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 156 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1973 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 157 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1979 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 158 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1985 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 159 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1991 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 160 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1997 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 161 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 2003 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 162 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2009 "y.tab.c"
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
#line 2025 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 185 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2031 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 185 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2037 "y.tab.c"
    break;

  case 38: /* function: function_head function_body  */
#line 192 "parser.y"
                                                                      {currentFuncIndex = -1;}
#line 2043 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 195 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2054 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 204 "parser.y"
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
#line 223 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2077 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 224 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2083 "y.tab.c"
    break;

  case 47: /* param: dtype id  */
#line 233 "parser.y"
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
#line 255 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2118 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 262 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2124 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 263 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2130 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 264 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2136 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 265 "parser.y"
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
#line 274 "parser.y"
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
#line 2172 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 293 "parser.y"
                                      { level++; }
#line 2178 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 293 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2184 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 313 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2190 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 314 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2196 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 317 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2202 "y.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 325 "parser.y"
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
#line 333 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2221 "y.tab.c"
    break;

  case 78: /* goto_stmt: GOTO id ';'  */
#line 336 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2227 "y.tab.c"
    break;

  case 79: /* vect_stmt: vect_stmt_body ';'  */
#line 339 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2233 "y.tab.c"
    break;

  case 80: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 342 "parser.y"
                                                                           { 
					if(strcmp((yyvsp[-5].str),(yyvsp[-1].str))){printf("ERROR: appending the wrong dtype\n");} 
					(yyval.str) = (yyvsp[-5].str);
				}
#line 2242 "y.tab.c"
    break;

  case 81: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 346 "parser.y"
                                                                                           {
						
						}
#line 2250 "y.tab.c"
    break;

  case 82: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 349 "parser.y"
                                                                             {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2262 "y.tab.c"
    break;

  case 83: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 356 "parser.y"
                                                                              {
							if((yyvsp[-4].str)[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-4].str);
						}
#line 2274 "y.tab.c"
    break;

  case 84: /* remove_body: INT_CONST  */
#line 366 "parser.y"
                                                    {(yyval.str)="int";}
#line 2280 "y.tab.c"
    break;

  case 85: /* remove_body: FLOAT_CONST  */
#line 367 "parser.y"
                                                              {(yyval.str)="float";}
#line 2286 "y.tab.c"
    break;

  case 86: /* remove_body: LHS  */
#line 368 "parser.y"
                                                      {(yyval.str)=(yyvsp[0].details).type;}
#line 2292 "y.tab.c"
    break;

  case 87: /* remove_body: func_calls  */
#line 369 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2298 "y.tab.c"
    break;

  case 88: /* remove_body: arith_op  */
#line 370 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2304 "y.tab.c"
    break;

  case 89: /* remove_body: logical_op  */
#line 371 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2310 "y.tab.c"
    break;

  case 90: /* remove_body: impr  */
#line 372 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 2316 "y.tab.c"
    break;

  case 93: /* $@7: %empty  */
#line 379 "parser.y"
                                               {
					if(inClass==0){		
						if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("ERROR : func type and return type are mismatched\n");}
					}
					else{
						if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
							printf("ERROR : func type and return type are mismatched\n");
						}
					}
				}
#line 2331 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN RHS ';' $@7  */
#line 388 "parser.y"
                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2337 "y.tab.c"
    break;

  case 95: /* $@8: %empty  */
#line 390 "parser.y"
                                                 {
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("ERROR : func type and return type are mismatched\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("ERROR : func type and return type are mismatched\n");
								}
							}
						 }
#line 2352 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN extra_consts ';' $@8  */
#line 399 "parser.y"
                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2358 "y.tab.c"
    break;

  case 97: /* $@9: %empty  */
#line 401 "parser.y"
                                                {
							if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("ERROR : func type and return type are mismatched\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("ERROR : func type and return type are mismatched\n");
								}
							}
						 }
#line 2373 "y.tab.c"
    break;

  case 98: /* return_stmt: RETURN graph_impr ';' $@9  */
#line 410 "parser.y"
                                                   {fprintf(fparse, " : RETURN STATEMENT");}
#line 2379 "y.tab.c"
    break;

  case 99: /* $@10: %empty  */
#line 411 "parser.y"
                                                                        {if(inClass==0){
								if(strcmp((yyvsp[-1].str),func_symb[currentFuncIndex].type)){printf("ERROR : func type and return type are mismatched\n");}
							}
							else{
								if(strcmp((yyvsp[-1].str),class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("ERROR : func type and return type are mismatched\n");
								}
							}
							}
#line 2393 "y.tab.c"
    break;

  case 100: /* return_stmt: RETURN matrix_impr ';' $@10  */
#line 419 "parser.y"
                                                           {fprintf(fparse, " : RETURN STATEMENT");}
#line 2399 "y.tab.c"
    break;

  case 101: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 420 "parser.y"
                                                                           {
							fprintf(fparse, " : RETURN STATEMENT");
						}
#line 2407 "y.tab.c"
    break;

  case 102: /* $@11: %empty  */
#line 423 "parser.y"
                                                                 {if(inClass==0){
								if(strcmp("void",func_symb[currentFuncIndex].type)){printf("ERROR : func type and return type are mismatched\n");}
							}
							else{
								if(strcmp("void",class_symb[class_size-1].func_list[currentFuncIndex].type)){
									printf("ERROR : func type and return type are mismatched\n");
								}
							}
							}
#line 2421 "y.tab.c"
    break;

  case 103: /* return_stmt: RETURN null ';' $@11  */
#line 431 "parser.y"
                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2427 "y.tab.c"
    break;

  case 104: /* loop_stmt: LOOP loop_type  */
#line 436 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2433 "y.tab.c"
    break;

  case 109: /* for_expr: EXPR LHS '=' for_RHS  */
#line 447 "parser.y"
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
#line 2450 "y.tab.c"
    break;

  case 110: /* for_RHS: arith_op  */
#line 461 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2456 "y.tab.c"
    break;

  case 111: /* for_RHS: func_calls  */
#line 462 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2462 "y.tab.c"
    break;

  case 112: /* for_RHS: impr  */
#line 463 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2468 "y.tab.c"
    break;

  case 113: /* for_RHS: graph_impr  */
#line 464 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2474 "y.tab.c"
    break;

  case 114: /* for_RHS: vect_stmt_body  */
#line 465 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2480 "y.tab.c"
    break;

  case 115: /* for_RHS: matrix_impr  */
#line 466 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2486 "y.tab.c"
    break;

  case 116: /* $@12: %empty  */
#line 469 "parser.y"
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
#line 2502 "y.tab.c"
    break;

  case 118: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 482 "parser.y"
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
#line 2521 "y.tab.c"
    break;

  case 119: /* $@13: %empty  */
#line 497 "parser.y"
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
#line 2573 "y.tab.c"
    break;

  case 120: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@13  */
#line 544 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2579 "y.tab.c"
    break;

  case 121: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 546 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2585 "y.tab.c"
    break;

  case 122: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 547 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2591 "y.tab.c"
    break;

  case 123: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 548 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2597 "y.tab.c"
    break;

  case 124: /* LHS: myId  */
#line 552 "parser.y"
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
#line 2661 "y.tab.c"
    break;

  case 125: /* LHS: LHS ARROW myId  */
#line 611 "parser.y"
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
#line 2747 "y.tab.c"
    break;

  case 126: /* myId: id  */
#line 695 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2753 "y.tab.c"
    break;

  case 127: /* myId: id '[' RHS ']'  */
#line 696 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2766 "y.tab.c"
    break;

  case 128: /* declr_stmt: DECLR declr_body ';'  */
#line 707 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2772 "y.tab.c"
    break;

  case 129: /* declr_body: DATATYPE id_list  */
#line 710 "parser.y"
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
#line 2801 "y.tab.c"
    break;

  case 130: /* declr_body: GRAPH graph_and_array_list  */
#line 735 "parser.y"
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
#line 2830 "y.tab.c"
    break;

  case 131: /* declr_body: VECT '<' dtype '>' id_list  */
#line 760 "parser.y"
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
#line 2859 "y.tab.c"
    break;

  case 132: /* declr_body: MATRIX matrix_list  */
#line 785 "parser.y"
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
#line 2888 "y.tab.c"
    break;

  case 133: /* declr_body: DATATYPE graph_and_array_list  */
#line 810 "parser.y"
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
#line 2917 "y.tab.c"
    break;

  case 134: /* declr_body: id id_list  */
#line 835 "parser.y"
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
#line 2955 "y.tab.c"
    break;

  case 135: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 871 "parser.y"
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
#line 2970 "y.tab.c"
    break;

  case 136: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 882 "parser.y"
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
#line 2985 "y.tab.c"
    break;

  case 137: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 895 "parser.y"
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
#line 3001 "y.tab.c"
    break;

  case 138: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 907 "parser.y"
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
#line 3017 "y.tab.c"
    break;

  case 139: /* id_list: id ',' id_list  */
#line 921 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 3026 "y.tab.c"
    break;

  case 140: /* id_list: id  */
#line 926 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 3035 "y.tab.c"
    break;

  case 141: /* $@14: %empty  */
#line 932 "parser.y"
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
#line 3052 "y.tab.c"
    break;

  case 145: /* $@15: %empty  */
#line 951 "parser.y"
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
#line 3069 "y.tab.c"
    break;

  case 147: /* $@16: %empty  */
#line 966 "parser.y"
                                              {switch_insert(level); level++;}
#line 3075 "y.tab.c"
    break;

  case 148: /* switch_body: '{' $@16 cases DEFAULT ':' function_body '}'  */
#line 966 "parser.y"
                                                                                                                   { var_delete(level); level--; switch_delete();}
#line 3081 "y.tab.c"
    break;

  case 149: /* $@17: %empty  */
#line 969 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str));}
#line 3087 "y.tab.c"
    break;

  case 151: /* $@18: %empty  */
#line 970 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str));}
#line 3093 "y.tab.c"
    break;

  case 153: /* RHS: constants  */
#line 975 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 3099 "y.tab.c"
    break;

  case 154: /* RHS: arith_op  */
#line 976 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 3105 "y.tab.c"
    break;

  case 155: /* RHS: logical_op  */
#line 977 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3111 "y.tab.c"
    break;

  case 156: /* RHS: func_calls  */
#line 978 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 3117 "y.tab.c"
    break;

  case 157: /* RHS: impr  */
#line 979 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3123 "y.tab.c"
    break;

  case 158: /* constants: INT_CONST  */
#line 983 "parser.y"
                                                    {(yyval.str)="int";}
#line 3129 "y.tab.c"
    break;

  case 159: /* constants: FLOAT_CONST  */
#line 984 "parser.y"
                                                              {(yyval.str)="float";}
#line 3135 "y.tab.c"
    break;

  case 160: /* constants: CHAR_CONST  */
#line 985 "parser.y"
                                                             {(yyval.str)="char";}
#line 3141 "y.tab.c"
    break;

  case 161: /* constants: STR_CONST  */
#line 986 "parser.y"
                                                            {(yyval.str)="string";}
#line 3147 "y.tab.c"
    break;

  case 162: /* constants: BOOL_CONST  */
#line 987 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 3153 "y.tab.c"
    break;

  case 163: /* constants: LHS  */
#line 988 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 3159 "y.tab.c"
    break;

  case 164: /* extra_consts: array_const  */
#line 992 "parser.y"
                                             {(yyval.str) = "2";}
#line 3165 "y.tab.c"
    break;

  case 165: /* extra_consts: graph_const  */
#line 993 "parser.y"
                                                             {(yyval.str)="graph";}
#line 3171 "y.tab.c"
    break;

  case 166: /* extra_consts: vect_const  */
#line 994 "parser.y"
                                                            {(yyval.str)="vect";}
#line 3177 "y.tab.c"
    break;

  case 167: /* extra_consts: matrix_const  */
#line 995 "parser.y"
                                                              {(yyval.str)="matrix";}
#line 3183 "y.tab.c"
    break;

  case 168: /* extra_consts: '{' '}'  */
#line 996 "parser.y"
                                                         {(yyval.str)="1";}
#line 3189 "y.tab.c"
    break;

  case 176: /* resultant: LHS  */
#line 1010 "parser.y"
                                             {(yyval.str) = (yyvsp[0].details).type;}
#line 3195 "y.tab.c"
    break;

  case 177: /* resultant: matrix_impr  */
#line 1011 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3201 "y.tab.c"
    break;

  case 178: /* resultant: graph_impr  */
#line 1012 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 3207 "y.tab.c"
    break;

  case 179: /* resultant: vect_stmt_body  */
#line 1013 "parser.y"
                                                                 {(yyval.str) = (yyvsp[0].str);}
#line 3213 "y.tab.c"
    break;

  case 180: /* resultant: impr  */
#line 1014 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 3219 "y.tab.c"
    break;

  case 181: /* impr: resultant '.' LENGTH '(' ')'  */
#line 1018 "parser.y"
                                                                      {(yyval.str) = "int";}
#line 3225 "y.tab.c"
    break;

  case 182: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 1019 "parser.y"
                                                                                      {(yyval.str) = "0";}
#line 3231 "y.tab.c"
    break;

  case 183: /* impr: resultant '.' TRACE '(' ')'  */
#line 1020 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3237 "y.tab.c"
    break;

  case 184: /* impr: resultant '.' STRLEN '(' ')'  */
#line 1021 "parser.y"
                                                                              {(yyval.str) = "int";}
#line 3243 "y.tab.c"
    break;

  case 185: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 1022 "parser.y"
                                                                             {(yyval.str) = "bool";}
#line 3249 "y.tab.c"
    break;

  case 186: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 1023 "parser.y"
                                                                                                          {(yyval.str) = "string";}
#line 3255 "y.tab.c"
    break;

  case 187: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 1024 "parser.y"
                                                                             {(yyval.str) =  "string";}
#line 3261 "y.tab.c"
    break;

  case 188: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 1027 "parser.y"
                                                                                     {(yyval.str) = "vect";}
#line 3267 "y.tab.c"
    break;

  case 189: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 1028 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3273 "y.tab.c"
    break;

  case 190: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 1029 "parser.y"
                                                                                                          {(yyval.str) = "vect";}
#line 3279 "y.tab.c"
    break;

  case 191: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 1030 "parser.y"
                                                                                                               {(yyval.str) = "int";}
#line 3285 "y.tab.c"
    break;

  case 192: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 1034 "parser.y"
                                                                                {if(strcmp((yyvsp[-3].str),"matrix") || strcmp((yyvsp[-1].str),"matrix")){
											printf("%d, ERROR : argument is not a matrix\n",yylineno);exit(1);}
											(yyval.str) = "matrix";}
#line 3293 "y.tab.c"
    break;

  case 193: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 1037 "parser.y"
                                                                                  {(yyval.str) = "matrix";}
#line 3299 "y.tab.c"
    break;

  case 194: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 1038 "parser.y"
                                                                                {(yyval.str) = "matrix";}
#line 3305 "y.tab.c"
    break;

  case 195: /* matr_body: RHS  */
#line 1041 "parser.y"
                                              {(yyval.str) = (yyvsp[0].str);}
#line 3311 "y.tab.c"
    break;

  case 196: /* matr_body: matrix_impr  */
#line 1042 "parser.y"
                                                              {(yyval.str) = (yyvsp[0].str);}
#line 3317 "y.tab.c"
    break;

  case 199: /* graph_type1: INT_CONST ':' int_list ';' graph_type1  */
#line 1050 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3326 "y.tab.c"
    break;

  case 200: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 1055 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3335 "y.tab.c"
    break;

  case 201: /* graph_type2: INT_CONST ':' weight_list ';' graph_type2  */
#line 1062 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-4].str));
								arr_size++;
							}
#line 3344 "y.tab.c"
    break;

  case 202: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 1067 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3353 "y.tab.c"
    break;

  case 203: /* int_list: INT_CONST ',' int_list  */
#line 1074 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-2].str));
								arr_size++;
							}
#line 3362 "y.tab.c"
    break;

  case 204: /* int_list: INT_CONST  */
#line 1079 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[0].str));
								arr_size++;
							}
#line 3371 "y.tab.c"
    break;

  case 213: /* weight_list: '(' INT_CONST ',' INT_CONST ')' ',' weight_list  */
#line 1102 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3380 "y.tab.c"
    break;

  case 214: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 1107 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3389 "y.tab.c"
    break;

  case 215: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')' ',' weight_list  */
#line 1112 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-5].str));
								arr_size++;
							}
#line 3398 "y.tab.c"
    break;

  case 216: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 1117 "parser.y"
                                                        {
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 3407 "y.tab.c"
    break;

  case 223: /* int_float_list: INT_CONST ',' int_float_list  */
#line 1136 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3415 "y.tab.c"
    break;

  case 224: /* int_float_list: FLOAT_CONST ',' int_float_list  */
#line 1140 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[0].Cols).cols+1;
							}
#line 3423 "y.tab.c"
    break;

  case 225: /* int_float_list: INT_CONST  */
#line 1144 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3431 "y.tab.c"
    break;

  case 226: /* int_float_list: FLOAT_CONST  */
#line 1148 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
							}
#line 3439 "y.tab.c"
    break;

  case 227: /* mat_list: '[' int_float_list ']' ';' mat_list  */
#line 1154 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-3].Cols).cols;
								arr_size++;
							}
#line 3448 "y.tab.c"
    break;

  case 228: /* mat_list: '[' int_float_list ']' ';'  */
#line 1159 "parser.y"
                                                        {
								dimA[arr_size]=(yyvsp[-2].Cols).cols;
								arr_size++;
							}
#line 3457 "y.tab.c"
    break;

  case 231: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 1170 "parser.y"
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
#line 3476 "y.tab.c"
    break;

  case 232: /* unary_op: UNARYOP '(' RHS ')'  */
#line 1186 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3489 "y.tab.c"
    break;

  case 233: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 1196 "parser.y"
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
#line 3508 "y.tab.c"
    break;

  case 234: /* logical_op: NOT '(' RHS ')'  */
#line 1210 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
							}
						}
#line 3521 "y.tab.c"
    break;

  case 235: /* call_stmt: func_calls ';'  */
#line 1220 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 3527 "y.tab.c"
    break;

  case 236: /* func_calls: call_head arguments  */
#line 1225 "parser.y"
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
#line 3547 "y.tab.c"
    break;

  case 237: /* call_head: CALL LHS  */
#line 1243 "parser.y"
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
#line 3563 "y.tab.c"
    break;

  case 240: /* arg_list: RHS  */
#line 1260 "parser.y"
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
#line 3602 "y.tab.c"
    break;

  case 241: /* arg_list: arg_list ',' RHS  */
#line 1294 "parser.y"
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
#line 3638 "y.tab.c"
    break;


#line 3642 "y.tab.c"

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

#line 1327 "parser.y"


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




