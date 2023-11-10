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

#line 111 "y.tab.c"

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
#line 41 "parser.y"

	char* str;
	struct{
		char* name;
		char* type;
	} details;
	

#line 285 "y.tab.c"

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
  YYSYMBOL_63_ = 63,                       /* '<'  */
  YYSYMBOL_64_ = 64,                       /* '>'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
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
  YYSYMBOL_88_5 = 88,                      /* $@5  */
  YYSYMBOL_fdtype = 89,                    /* fdtype  */
  YYSYMBOL_param_list = 90,                /* param_list  */
  YYSYMBOL_dtype = 91,                     /* dtype  */
  YYSYMBOL_function_body = 92,             /* function_body  */
  YYSYMBOL_93_6 = 93,                      /* $@6  */
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
  YYSYMBOL_loop_stmt = 105,                /* loop_stmt  */
  YYSYMBOL_loop_type = 106,                /* loop_type  */
  YYSYMBOL_for_loop = 107,                 /* for_loop  */
  YYSYMBOL_for_expr = 108,                 /* for_expr  */
  YYSYMBOL_while_loop = 109,               /* while_loop  */
  YYSYMBOL_expr_stmt = 110,                /* expr_stmt  */
  YYSYMBOL_LHS = 111,                      /* LHS  */
  YYSYMBOL_declr_stmt = 112,               /* declr_stmt  */
  YYSYMBOL_declr_body = 113,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 114,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 115,              /* matrix_list  */
  YYSYMBOL_id_list = 116,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 117,              /* ifcond_stmt  */
  YYSYMBOL_118_7 = 118,                    /* $@7  */
  YYSYMBOL_if_body = 119,                  /* if_body  */
  YYSYMBOL_switch_stmt = 120,              /* switch_stmt  */
  YYSYMBOL_121_8 = 121,                    /* $@8  */
  YYSYMBOL_switch_body = 122,              /* switch_body  */
  YYSYMBOL_123_9 = 123,                    /* $@9  */
  YYSYMBOL_cases = 124,                    /* cases  */
  YYSYMBOL_RHS = 125,                      /* RHS  */
  YYSYMBOL_constants = 126,                /* constants  */
  YYSYMBOL_extra_consts = 127,             /* extra_consts  */
  YYSYMBOL_array_const = 128,              /* array_const  */
  YYSYMBOL_val_list = 129,                 /* val_list  */
  YYSYMBOL_resultant = 130,                /* resultant  */
  YYSYMBOL_impr = 131,                     /* impr  */
  YYSYMBOL_graph_impr = 132,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 133,              /* matrix_impr  */
  YYSYMBOL_matr_body = 134,                /* matr_body  */
  YYSYMBOL_graph_const = 135,              /* graph_const  */
  YYSYMBOL_graph_type1 = 136,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 137,              /* graph_type2  */
  YYSYMBOL_int_list = 138,                 /* int_list  */
  YYSYMBOL_float_list = 139,               /* float_list  */
  YYSYMBOL_char_list = 140,                /* char_list  */
  YYSYMBOL_bool_list = 141,                /* bool_list  */
  YYSYMBOL_str_list = 142,                 /* str_list  */
  YYSYMBOL_weight_list = 143,              /* weight_list  */
  YYSYMBOL_vect_const = 144,               /* vect_const  */
  YYSYMBOL_vect_list = 145,                /* vect_list  */
  YYSYMBOL_matrix_const = 146,             /* matrix_const  */
  YYSYMBOL_int_float_list = 147,           /* int_float_list  */
  YYSYMBOL_mat_list = 148,                 /* mat_list  */
  YYSYMBOL_arith_op = 149,                 /* arith_op  */
  YYSYMBOL_binary_op = 150,                /* binary_op  */
  YYSYMBOL_unary_op = 151,                 /* unary_op  */
  YYSYMBOL_logical_op = 152,               /* logical_op  */
  YYSYMBOL_call_stmt = 153,                /* call_stmt  */
  YYSYMBOL_func_calls = 154,               /* func_calls  */
  YYSYMBOL_call_head = 155,                /* call_head  */
  YYSYMBOL_arguments = 156,                /* arguments  */
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  447

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
       0,   111,   111,   114,   115,   118,   119,   120,   123,   127,
     123,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   150,
     151,   154,   155,   158,   158,   158,   161,   162,   165,   168,
     177,   186,   187,   187,   191,   192,   195,   200,   208,   209,
     210,   211,   220,   239,   239,   240,   243,   244,   245,   246,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   263,   266,   267,   270,   273,   276,   279,   280,
     281,   282,   286,   287,   288,   289,   290,   291,   292,   296,
     297,   300,   301,   302,   303,   304,   305,   309,   312,   313,
     316,   319,   320,   321,   322,   323,   324,   325,   328,   331,
     345,   346,   347,   348,   351,   365,   418,   420,   445,   470,
     495,   520,   545,   581,   587,   595,   602,   611,   616,   623,
     623,   626,   627,   630,   630,   633,   633,   636,   637,   641,
     642,   643,   644,   645,   649,   650,   651,   652,   653,   654,
     658,   659,   660,   661,   662,   666,   667,   670,   671,   672,
     673,   674,   677,   678,   679,   680,   681,   684,   685,   686,
     687,   688,   689,   690,   695,   696,   697,   698,   702,   703,
     704,   707,   708,   711,   712,   715,   716,   719,   720,   723,
     724,   727,   728,   731,   732,   735,   736,   739,   740,   743,
     744,   745,   746,   749,   752,   753,   754,   755,   758,   761,
     762,   763,   764,   767,   768,   771,   772,   775,   791,   801,
     815,   825,   829,   833,   843,   844,   847,   848
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
  "SHPATH_VAL", "GOTO", "'{'", "'}'", "';'", "'('", "')'", "','", "'<'",
  "'>'", "':'", "'.'", "'='", "'['", "']'", "$accept", "program_unit",
  "models", "model", "class", "$@1", "$@2", "id", "class_items",
  "class_item", "struct", "$@3", "$@4", "struct_items", "function",
  "function_head", "func_definition", "Parameters", "$@5", "fdtype",
  "param_list", "dtype", "function_body", "$@6", "statements", "statement",
  "unary_stmt", "jump_stmt", "label_stmt", "goto_stmt", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "while_loop",
  "expr_stmt", "LHS", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@7", "if_body", "switch_stmt",
  "$@8", "switch_body", "$@9", "cases", "RHS", "constants", "extra_consts",
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

#define YYPACT_NINF (-336)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   184,   184,   833,    48,  -336,     8,  -336,  -336,  -336,
       0,     3,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,
      18,    25,  -336,  -336,  -336,  -336,     4,  -336,   184,  -336,
    -336,  -336,    34,  -336,    40,  -336,  -336,  -336,   881,  -336,
    -336,   778,  -336,   881,    16,    74,    45,   409,    50,    52,
      55,    53,    60,   929,   184,   184,    54,    61,    62,    63,
     184,    59,   778,    67,   778,  -336,  -336,  -336,  -336,  -336,
      68,  -336,  -336,  -336,   117,  -336,  -336,  -336,    64,  -336,
    -336,  -336,    69,  -336,    70,    71,    72,   184,    76,    16,
    -336,  -336,    79,    74,  -336,  -336,  -336,  -336,  -336,  -336,
      81,    84,    86,   525,   695,   111,  -336,    87,    13,    88,
    -336,    89,  -336,    92,   100,   102,  -336,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,   695,  -336,  -336,   695,   695,   184,
     184,   184,    99,   184,   105,     7,   117,   106,   107,  -336,
    -336,  -336,   695,   695,   695,   116,     0,  -336,  -336,  -336,
    -336,   184,   249,  -336,  -336,   636,  -336,  -336,   103,  -336,
    -336,  -336,  -336,   695,   695,  -336,   118,  -336,   117,   108,
     119,   124,   126,   127,  -336,   160,   128,   129,   130,   134,
     135,    30,  -336,   120,  -336,  -336,  -336,  -336,  -336,   131,
    -336,  -336,  -336,  -336,  -336,   138,   140,   141,   -23,  -336,
    -336,   136,  -336,   137,  -336,   881,   144,  -336,  -336,   467,
     157,   695,   147,   148,  -336,   145,   150,  -336,  -336,  -336,
     143,   153,   156,   158,   180,   183,   186,   189,   191,   192,
     195,   198,   199,   201,   202,  -336,   182,   159,   881,   205,
     207,   208,   214,    17,   581,   581,  -336,  -336,  -336,   695,
     273,   276,   272,   277,   278,   236,   237,   238,  -336,  -336,
    -336,  -336,  -336,   184,   302,   304,   245,   251,   252,   253,
     254,   255,    10,   256,   695,   695,   695,   467,   725,   257,
     258,   259,   725,   260,   261,   725,   262,   725,   263,   264,
     725,   725,   695,  -336,  -336,  -336,  -336,   695,  -336,   311,
     267,   270,  -336,  -336,   269,  -336,  -336,  -336,  -336,  -336,
      30,    30,   274,     0,   275,  -336,   265,   266,   184,  -336,
    -336,  -336,  -336,  -336,   279,     0,   283,   284,   285,   286,
    -336,  -336,  -336,  -336,   287,    13,    92,  -336,  -336,  -336,
    -336,  -336,  -336,   288,  -336,  -336,   289,  -336,   290,  -336,
    -336,   291,   292,  -336,   298,   299,   327,   333,  -336,  -336,
    -336,   271,   325,  -336,  -336,  -336,   300,   295,  -336,    29,
    -336,  -336,  -336,  -336,  -336,  -336,  -336,  -336,   725,   725,
     725,  -336,    39,   301,  -336,   305,  -336,  -336,     0,   329,
     184,   356,   184,   303,  -336,   310,   312,   313,   314,   317,
     273,   319,  -336,   361,   349,  -336,   315,    11,     0,  -336,
    -336,  -336,   320,   321,   322,   323,   324,   958,  -336,   319,
     319,     0,     0,   184,   326,    92,   328,   145,  -336,  -336,
    -336,  -336,   329,   331,  -336,  -336,  -336
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    24,    23,    25,    26,    27,    28,
       0,     0,    48,    45,    49,    50,     0,    52,     0,    44,
       1,     3,    53,    38,    42,    39,     8,    33,     0,    40,
      55,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    23,     0,
       0,   114,    59,     0,    57,    68,    65,    73,    74,    69,
     165,    67,    66,    60,   162,    62,    63,    64,     0,   166,
     164,   163,     0,    61,     0,     0,     0,     0,     0,    30,
      32,    31,     0,    37,    51,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,   114,   165,   149,     0,
     139,     0,   150,   143,   164,   163,   151,   152,   153,   140,
     215,   216,   141,   142,     0,    71,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,    97,
      98,    99,     0,     0,     0,     0,     0,    58,    54,    56,
      77,     0,     0,    72,   221,     0,   222,    43,    47,     9,
      29,    34,    36,     0,     0,    96,   144,   154,   149,   205,
     207,     0,     0,     0,   165,     0,   190,   192,   194,   198,
     196,     0,   156,     0,   157,   158,   159,   160,   161,     0,
      95,    91,    92,    93,    94,     0,     0,     0,   128,   121,
     117,     0,   120,     0,   118,     0,   128,   122,   116,     0,
       0,     0,     0,     0,   181,   182,     0,    76,    75,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   203,     0,
       0,     0,     0,     0,     0,   211,   212,     0,   155,   208,
     129,   133,   218,     0,     0,     0,     0,   165,     0,     0,
     164,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,    46,    10,    35,     0,   220,     0,
       0,     0,   204,   206,     0,   189,   191,   193,   197,   195,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   113,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
      89,    90,    82,    83,     0,    84,    88,    86,    87,    85,
     167,    80,    81,     0,   179,   169,     0,   170,     0,   180,
     175,     0,     0,   226,     0,     0,   186,   188,   219,   209,
     210,   214,   132,   130,   135,   134,   124,     0,   119,     0,
     108,   171,   173,   178,    78,    79,   168,   174,     0,     0,
       0,   217,     0,     0,   185,     0,   187,   213,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,   123,     0,     0,     0,   172,
     176,   177,   200,   202,     0,     0,   126,     0,   100,     0,
       0,     0,     0,     0,   106,   104,   105,   107,   102,   103,
     199,   201,   138,     0,   125,   137,   136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -336,  -336,   379,  -336,  -336,  -336,  -336,    -1,   294,  -336,
    -336,  -336,  -336,   293,   -18,  -336,  -336,  -336,  -336,  -336,
     142,     6,    -7,  -336,    12,  -336,  -336,  -336,  -336,  -336,
    -336,   -46,  -236,  -336,  -336,  -336,  -336,  -336,  -336,  -336,
     177,   -47,   -31,  -336,  -127,   -35,  -130,  -336,  -336,  -336,
    -336,  -336,  -336,  -336,   -42,    -2,   -98,   -45,  -336,  -336,
    -336,   -32,   -50,   -51,   115,  -336,    36,    37,  -105,   146,
     161,   139,   155,  -335,  -336,  -156,  -336,  -213,    38,  -212,
    -336,   -43,  -195,  -336,   -21,  -336,  -336,   125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    54,   249,   116,    98,    99,
       8,    55,   250,   102,     9,    10,    11,    45,    53,    38,
      96,    97,    72,    51,    73,    74,    75,    76,    77,    78,
      79,   184,   344,   339,    81,    82,   149,   150,   403,   151,
      83,   118,    85,   144,   209,   212,   210,    86,   323,   373,
      87,   324,   375,   399,   414,   224,   120,   180,   122,   193,
      88,   123,    90,    91,   226,   126,   181,   182,   310,   195,
     196,   197,   198,   311,   127,   183,   128,   267,   199,   129,
     130,   131,   132,    93,   133,    95,   166,   247
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    37,    43,    84,    80,   125,   124,    92,    39,
     194,   117,   121,   217,   214,   179,   161,   145,   146,    89,
     161,   186,   161,   101,   103,    84,    80,    84,    80,    92,
      94,    92,     1,     2,   265,   266,   100,    49,   111,   273,
      89,     3,    89,   408,   409,   274,    63,    37,    40,     3,
      71,    94,    37,    94,    56,   119,   353,    42,    62,   356,
     402,   358,   143,    44,   361,   362,   178,    48,   101,   155,
     114,    71,   103,    71,   219,    46,   347,   309,   427,  -162,
     347,   100,    47,   347,   157,   347,   159,   334,   347,   347,
     147,   148,    50,   348,   440,   441,   168,   348,   312,   313,
     348,    52,   348,   225,    63,   348,   348,   369,   370,   104,
     134,   135,   185,   137,   136,   186,   187,   188,   189,   190,
     138,   152,   153,   154,   156,   158,   161,   160,   163,   164,
     162,   165,   205,   167,   169,   206,   207,   171,   208,   211,
     213,   173,   216,   325,   174,   175,   200,   201,   202,   228,
     222,   223,   405,   406,   407,   315,   179,   179,  -166,   203,
     229,   204,   215,   246,   218,   248,   220,   221,   281,   280,
     254,   251,   252,   277,   279,   227,   347,   347,   347,   191,
     192,   255,   256,   253,   257,   258,   259,    12,    64,   268,
     260,   261,   262,   348,   348,   348,   263,   264,   378,   270,
     269,   271,   272,   287,   275,   274,   273,   178,   178,   284,
     285,  -163,   286,   288,    37,   438,   289,   278,   290,   283,
     303,   276,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   225,    26,    27,    28,    29,
     291,   345,   341,   292,   302,   345,   293,    37,   345,   294,
     345,   295,   296,   345,   345,   297,   346,   314,   298,   299,
     346,   300,   301,   346,   305,   346,   306,   349,   346,   346,
     307,   349,   216,   415,   349,   308,   349,   186,   188,   349,
     349,   187,   336,   337,   189,   340,   190,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   320,   321,
     246,   241,   242,   243,   244,   364,   326,   322,   327,   328,
     329,   330,   331,   332,   333,   365,   372,   335,   350,   351,
     352,   354,   355,   357,   359,   360,   366,   216,   380,   367,
     368,   393,   374,   371,   376,   377,   404,   395,   379,   191,
     398,   345,   345,   345,   381,   382,   383,   384,   385,   386,
     387,   413,   388,   389,   390,   417,   346,   346,   346,   391,
     416,   392,   400,   401,   418,   424,   410,   349,   349,   349,
     411,   419,   425,   420,   421,   422,   437,   436,   423,   309,
      84,   434,   429,   430,   426,    41,   433,   431,   432,   446,
     304,   412,  -165,   170,  -164,   435,   172,   282,   444,   213,
     445,   338,   394,   319,   396,     0,   439,   316,     0,   397,
       0,   428,    12,   105,   106,   107,   108,   109,   318,     0,
       0,     0,     0,   317,   442,   443,     0,   363,     0,     0,
       0,     0,   211,     0,     0,     0,   110,   111,    62,     0,
       0,    65,     0,     0,   112,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    67,    68,
      69,    26,    27,    28,    29,     0,   113,     0,     0,   114,
      12,   105,   106,   107,   108,   109,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,    62,     0,     0,    65,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    67,    68,    69,    26,
      27,    28,    29,     0,   113,     0,     0,   114,    12,   176,
     106,   107,   108,   109,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,     0,   113,   177,    12,   105,   106,   107,   108,   109,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,     0,   113,    12,
     105,   106,   107,   108,   109,     0,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,    62,     0,     0,    65,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    67,    68,    69,    26,    27,
      28,    29,     0,     0,     0,     0,   114,   245,    12,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,    62,     0,     0,    65,    12,   342,
     343,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    67,    68,    69,    26,    27,    28,
      29,     0,   110,   111,    62,   114,     0,    65,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    67,    68,    69,    26,    27,    28,
      29,    12,     0,     0,     0,   114,     0,     0,     0,     0,
       0,    57,    58,     0,    59,    60,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,     0,    66,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    67,    68,    69,
      26,    27,    28,    29,    70,    42,    12,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    12,    26,    27,    28,    29,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,    34,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    12,    26,    27,    28,    29,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,   140,   141,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,   110,     0,    62,     0,     0,
      65,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    67,    68,    69,
      26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    10,    51,    51,    57,    57,    51,     3,
     115,    57,    57,   143,   141,   113,     9,    64,    65,    51,
       9,     4,     9,    54,    55,    72,    72,    74,    74,    72,
      51,    74,    24,    25,     4,     5,    54,    38,    28,    62,
      72,    33,    74,     4,     5,    68,    30,    48,     0,    33,
      51,    72,    53,    74,    48,    57,   292,    57,    29,   295,
      31,   297,    63,    60,   300,   301,   113,    63,    99,    70,
      60,    72,   103,    74,    67,    57,   288,    60,    67,    66,
     292,    99,    57,   295,    72,   297,    74,   282,   300,   301,
      36,    37,    58,   288,   429,   430,    97,   292,   254,   255,
     295,    61,   297,   154,    30,   300,   301,   320,   321,    64,
      60,    59,   114,    60,    59,     4,     5,     6,     7,     8,
      60,    60,    60,    60,    65,    58,     9,    59,    59,    59,
      66,    60,   134,    61,    58,   137,   138,    58,   139,   140,
     141,    60,   143,   273,    60,    59,    59,    59,    59,   156,
     152,   153,   388,   389,   390,   260,   254,   255,    66,    59,
     161,    59,    63,   165,    59,    62,    60,    60,   219,   219,
      62,   173,   174,   219,   219,    59,   388,   389,   390,    68,
      69,    62,    58,    65,    58,    58,    26,     3,    31,    69,
      62,    62,    62,   388,   389,   390,    62,    62,   328,    61,
      69,    61,    61,    60,    68,    68,    62,   254,   255,    62,
      62,    66,    62,    60,   215,   427,    60,   219,    60,   221,
      61,   215,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   286,    52,    53,    54,    55,
      60,   288,   287,    60,    62,   292,    60,   248,   295,    60,
     297,    60,    60,   300,   301,    60,   288,   259,    60,    60,
     292,    60,    60,   295,    59,   297,    59,   288,   300,   301,
      62,   292,   273,   400,   295,    61,   297,     4,     6,   300,
     301,     5,   284,   285,     7,   287,     8,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    62,    62,
     302,    52,    53,    54,    55,   307,     4,    69,     4,    64,
      59,    59,    59,    59,    59,     4,   323,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    59,   328,   335,    59,
      61,     4,    57,    59,    69,    69,   379,     4,    59,    68,
      15,   388,   389,   390,    61,    61,    61,    61,    61,    61,
      61,    22,    62,    62,    62,   402,   388,   389,   390,    61,
       4,    62,    62,    68,    61,     4,    65,   388,   389,   390,
      65,    61,    23,    61,    61,    61,   427,   427,    61,    60,
     427,   427,    62,    62,    69,     6,    62,    65,    65,    58,
     248,   398,    66,    99,    66,   427,   103,   220,   433,   400,
     442,   286,   366,   264,   367,    -1,   427,   261,    -1,   371,
      -1,   418,     3,     4,     5,     6,     7,     8,   263,    -1,
      -1,    -1,    -1,   262,   431,   432,    -1,   302,    -1,    -1,
      -1,    -1,   433,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    60,
       3,     4,     5,     6,     7,     8,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    60,     3,     4,
       5,     6,     7,     8,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    -1,    57,    58,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    -1,    57,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    60,    61,     3,     4,
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
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     3,    52,    53,    54,    55,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     3,    52,    53,    54,    55,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    27,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    71,    72,    73,    74,    80,    84,
      85,    86,     3,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      77,    77,    11,    12,    18,    19,    20,    77,    89,    91,
       0,    72,    57,    92,    60,    87,    57,    57,    63,    77,
      58,    93,    61,    88,    75,    81,    91,    13,    14,    16,
      17,    21,    29,    30,    31,    32,    34,    49,    50,    51,
      56,    77,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   104,   105,   110,   111,   112,   117,   120,   130,   131,
     132,   133,   151,   153,   154,   155,    90,    91,    78,    79,
      84,   112,    83,   112,    64,     4,     5,     6,     7,     8,
      27,    28,    35,    57,    60,    68,    77,   101,   111,   125,
     126,   127,   128,   131,   132,   133,   135,   144,   146,   149,
     150,   151,   152,   154,    60,    59,    59,    60,    60,    11,
      18,    19,    20,    77,   113,   111,   111,    36,    37,   106,
     107,   109,    60,    60,    60,    77,    65,    94,    58,    94,
      59,     9,    66,    59,    59,    60,   156,    61,    77,    58,
      78,    58,    83,    60,    60,    59,     4,    58,   111,   126,
     127,   136,   137,   145,   101,   125,     4,     5,     6,     7,
       8,    68,    69,   129,   138,   139,   140,   141,   142,   148,
      59,    59,    59,    59,    59,   125,   125,   125,    77,   114,
     116,    77,   115,    77,   114,    63,    77,   116,    59,    67,
      60,    60,   125,   125,   125,   133,   134,    59,    92,    77,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    52,    53,    54,    55,    61,   125,   157,    62,    76,
      82,   125,   125,    65,    62,    62,    58,    58,    58,    26,
      62,    62,    62,    62,    62,     4,     5,   147,    69,    69,
      61,    61,    61,    62,    68,    68,    91,   101,   125,   127,
     132,   133,   110,   125,    62,    62,    62,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    62,    61,    90,    59,    59,    62,    61,    60,
     138,   143,   145,   145,   125,   138,   139,   140,   142,   141,
      62,    62,    69,   118,   121,   116,     4,     4,    64,    59,
      59,    59,    59,    59,   152,    61,   125,   125,   134,   103,
     125,   127,     4,     5,   102,   111,   131,   149,   152,   154,
      61,    61,    61,   102,    61,    61,   102,    61,   102,    61,
      61,   102,   102,   157,   125,     4,    59,    59,    61,   147,
     147,    59,    92,   119,    57,   122,    69,    69,   116,    59,
      92,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    61,    62,     4,   136,     4,   137,   148,    15,   123,
      62,    68,    31,   108,   151,   102,   102,   102,     4,     5,
      65,    65,    92,    22,   124,   114,     4,   111,    61,    61,
      61,    61,    61,    61,     4,    23,    69,    67,    92,    62,
      62,    65,    65,    62,   101,   131,   132,   133,   149,   154,
     143,   143,    92,    92,   115,   124,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    75,    76,
      74,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    81,    82,    80,    83,    83,    84,    85,
      86,    87,    88,    87,    89,    89,    90,    90,    91,    91,
      91,    91,    91,    93,    92,    92,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    97,    97,    98,    99,   100,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   105,   106,   106,
     107,   108,   108,   108,   108,   108,   108,   108,   109,   110,
     110,   110,   110,   110,   111,   111,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   118,
     117,   119,   119,   121,   120,   123,   122,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   143,
     143,   143,   143,   144,   145,   145,   145,   145,   146,   147,
     147,   147,   147,   148,   148,   149,   149,   150,   151,   152,
     152,   153,   154,   155,   156,   156,   157,   157
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     0,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     0,     8,     2,     1,     2,     2,
       3,     2,     0,     4,     1,     1,     4,     2,     1,     1,
       1,     4,     1,     0,     4,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     1,     3,     3,     2,     6,     6,
       5,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       8,     1,     4,     4,     4,     4,     4,     4,     5,     5,
       5,     5,     5,     5,     1,     3,     3,     2,     2,     5,
       2,     2,     2,     6,     4,     9,     7,     3,     1,     0,
       6,     3,     1,     0,     6,     0,     7,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     5,
       5,     6,     8,     6,     6,     5,     8,     8,     6,     5,
       5,     1,     1,     3,     3,     5,     4,     5,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     7,
       5,     7,     5,     3,     3,     1,     3,     1,     3,     3,
       3,     1,     1,     5,     4,     1,     1,     6,     4,     5,
       4,     2,     2,     2,     3,     2,     3,     1
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
#line 123 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							class_insert((yyvsp[-1].str));
						}
#line 1858 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 127 "parser.y"
                                                                  {level--; inClass = 0;}
#line 1864 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 127 "parser.y"
                                                                                              {fprintf(fparse, " : CLASS DEFINITION");}
#line 1870 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 130 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1876 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 131 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1882 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 132 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1888 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 133 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1894 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 134 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1900 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 135 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1906 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 136 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1912 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 137 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1918 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 138 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1924 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 139 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1930 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 140 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1936 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 141 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1942 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 142 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1948 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 143 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1954 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 144 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1960 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 145 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1966 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 146 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1972 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 147 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 1978 "y.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 158 "parser.y"
                                                       {level++; struct_insert((yyvsp[-1].str));}
#line 1984 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 158 "parser.y"
                                                                                                      {level--;}
#line 1990 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 158 "parser.y"
                                                                                                                    {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1996 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 168 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2007 "y.tab.c"
    break;

  case 40: /* func_definition: FUNC fdtype id  */
#line 177 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							if(inClass == 0) func_insert((yyvsp[0].str), (yyvsp[-1].str));
							else class_func_insert(class_size-1, (yyvsp[0].str), (yyvsp[-1].str));
							funcIndex = func_size-1;
						}
#line 2019 "y.tab.c"
    break;

  case 42: /* $@5: %empty  */
#line 187 "parser.y"
                                                      {level++;}
#line 2025 "y.tab.c"
    break;

  case 43: /* Parameters: '(' $@5 param_list ')'  */
#line 187 "parser.y"
                                                                               {level--;}
#line 2031 "y.tab.c"
    break;

  case 44: /* fdtype: dtype  */
#line 191 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2037 "y.tab.c"
    break;

  case 45: /* fdtype: VOID  */
#line 192 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2043 "y.tab.c"
    break;

  case 46: /* param_list: dtype id ',' param_list  */
#line 195 "parser.y"
                                                                  {
							if(inClass == 0) add_args((yyvsp[-3].str));
							else class_add_args(class_size-1, (yyvsp[-3].str)); 
							var_insert(0, level, (yyvsp[-2].str), (yyvsp[-3].str), "", -1, -1);	
						}
#line 2053 "y.tab.c"
    break;

  case 47: /* param_list: dtype id  */
#line 200 "parser.y"
                                                           {
							if(inClass == 0) add_args((yyvsp[-1].str));
							else class_add_args(class_size-1, (yyvsp[-1].str)); 
							var_insert(0, level, (yyvsp[0].str), (yyvsp[-1].str), "", -1, -1);
						}
#line 2063 "y.tab.c"
    break;

  case 48: /* dtype: DATATYPE  */
#line 208 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2069 "y.tab.c"
    break;

  case 49: /* dtype: MATRIX  */
#line 209 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2075 "y.tab.c"
    break;

  case 50: /* dtype: GRAPH  */
#line 210 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2081 "y.tab.c"
    break;

  case 51: /* dtype: VECT '<' dtype '>'  */
#line 211 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2095 "y.tab.c"
    break;

  case 52: /* dtype: id  */
#line 220 "parser.y"
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
#line 2117 "y.tab.c"
    break;

  case 53: /* $@6: %empty  */
#line 239 "parser.y"
                                      { level++; }
#line 2123 "y.tab.c"
    break;

  case 54: /* function_body: '{' $@6 statements '}'  */
#line 239 "parser.y"
                                                                  {var_delete(); level--;}
#line 2129 "y.tab.c"
    break;

  case 70: /* statement: BREAK ';'  */
#line 259 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2135 "y.tab.c"
    break;

  case 71: /* statement: CONTINUE ';'  */
#line 260 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2141 "y.tab.c"
    break;

  case 72: /* unary_stmt: unary_op ';'  */
#line 263 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2147 "y.tab.c"
    break;

  case 75: /* label_stmt: id ':' function_body  */
#line 270 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 2153 "y.tab.c"
    break;

  case 76: /* goto_stmt: GOTO id ';'  */
#line 273 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2159 "y.tab.c"
    break;

  case 77: /* vect_stmt: vect_stmt_body ';'  */
#line 276 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2165 "y.tab.c"
    break;

  case 91: /* return_stmt: RETURN RHS ';'  */
#line 300 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 2171 "y.tab.c"
    break;

  case 92: /* return_stmt: RETURN extra_consts ';'  */
#line 301 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2177 "y.tab.c"
    break;

  case 93: /* return_stmt: RETURN graph_impr ';'  */
#line 302 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2183 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN matrix_impr ';'  */
#line 303 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 2189 "y.tab.c"
    break;

  case 95: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 304 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2195 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN null ';'  */
#line 305 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2201 "y.tab.c"
    break;

  case 97: /* loop_stmt: LOOP loop_type  */
#line 309 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2207 "y.tab.c"
    break;

  case 109: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 331 "parser.y"
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
#line 2226 "y.tab.c"
    break;

  case 110: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 345 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2232 "y.tab.c"
    break;

  case 111: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 346 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2238 "y.tab.c"
    break;

  case 112: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 347 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2244 "y.tab.c"
    break;

  case 113: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 348 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2250 "y.tab.c"
    break;

  case 114: /* LHS: id  */
#line 351 "parser.y"
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
#line 2269 "y.tab.c"
    break;

  case 115: /* LHS: LHS ARROW id  */
#line 365 "parser.y"
                                                               {
							char* dType = var_symb[var_search((yyvsp[-2].details).name)].type;
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
										currentFuncIndex = k;
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
#line 2325 "y.tab.c"
    break;

  case 116: /* declr_stmt: DECLR declr_body ';'  */
#line 418 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2331 "y.tab.c"
    break;

  case 117: /* declr_body: DATATYPE id_list  */
#line 421 "parser.y"
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
#line 2360 "y.tab.c"
    break;

  case 118: /* declr_body: GRAPH graph_and_array_list  */
#line 446 "parser.y"
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
#line 2389 "y.tab.c"
    break;

  case 119: /* declr_body: VECT '<' dtype '>' id_list  */
#line 471 "parser.y"
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
#line 2418 "y.tab.c"
    break;

  case 120: /* declr_body: MATRIX matrix_list  */
#line 496 "parser.y"
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
#line 2447 "y.tab.c"
    break;

  case 121: /* declr_body: DATATYPE graph_and_array_list  */
#line 521 "parser.y"
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
#line 2476 "y.tab.c"
    break;

  case 122: /* declr_body: id id_list  */
#line 546 "parser.y"
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
#line 2514 "y.tab.c"
    break;

  case 123: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 582 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-5].str);
								dimA[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 2524 "y.tab.c"
    break;

  case 124: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 588 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-3].str);
								dimA[arr_size] = atoi((yyvsp[-1].str));
								arr_size++;
							}
#line 2534 "y.tab.c"
    break;

  case 125: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 596 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-8].str);
								dimA[arr_size] = atoi((yyvsp[-6].str));
								dimB[arr_size] = atoi((yyvsp[-3].str));
								arr_size++;
							}
#line 2545 "y.tab.c"
    break;

  case 126: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 603 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].str);
								dimA[arr_size] = atoi((yyvsp[-4].str));
								dimB[arr_size] = atoi((yyvsp[-1].str));
								arr_size++;
							}
#line 2556 "y.tab.c"
    break;

  case 127: /* id_list: id ',' id_list  */
#line 612 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 2565 "y.tab.c"
    break;

  case 128: /* id_list: id  */
#line 617 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 2574 "y.tab.c"
    break;

  case 129: /* $@7: %empty  */
#line 623 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2580 "y.tab.c"
    break;

  case 133: /* $@8: %empty  */
#line 630 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2586 "y.tab.c"
    break;

  case 135: /* $@9: %empty  */
#line 633 "parser.y"
                                              {level++;}
#line 2592 "y.tab.c"
    break;

  case 136: /* switch_body: '{' $@9 cases DEFAULT ':' function_body '}'  */
#line 633 "parser.y"
                                                                                             {level--;}
#line 2598 "y.tab.c"
    break;

  case 139: /* RHS: constants  */
#line 641 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 2604 "y.tab.c"
    break;

  case 140: /* RHS: arith_op  */
#line 642 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2610 "y.tab.c"
    break;

  case 141: /* RHS: logical_op  */
#line 643 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2616 "y.tab.c"
    break;

  case 142: /* RHS: func_calls  */
#line 644 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2622 "y.tab.c"
    break;

  case 143: /* RHS: impr  */
#line 645 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2628 "y.tab.c"
    break;

  case 144: /* constants: INT_CONST  */
#line 649 "parser.y"
                                                    {(yyval.str)="int";}
#line 2634 "y.tab.c"
    break;

  case 145: /* constants: FLOAT_CONST  */
#line 650 "parser.y"
                                                              {(yyval.str)="float";}
#line 2640 "y.tab.c"
    break;

  case 146: /* constants: CHAR_CONST  */
#line 651 "parser.y"
                                                             {(yyval.str)="char";}
#line 2646 "y.tab.c"
    break;

  case 147: /* constants: STR_CONST  */
#line 652 "parser.y"
                                                            {(yyval.str)="string";}
#line 2652 "y.tab.c"
    break;

  case 148: /* constants: BOOL_CONST  */
#line 653 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 2658 "y.tab.c"
    break;

  case 149: /* constants: LHS  */
#line 654 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 2664 "y.tab.c"
    break;

  case 217: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 775 "parser.y"
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
#line 2683 "y.tab.c"
    break;

  case 218: /* unary_op: UNARYOP '(' RHS ')'  */
#line 791 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 2696 "y.tab.c"
    break;

  case 219: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 801 "parser.y"
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
#line 2715 "y.tab.c"
    break;

  case 220: /* logical_op: NOT '(' RHS ')'  */
#line 815 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 2728 "y.tab.c"
    break;

  case 221: /* call_stmt: func_calls ';'  */
#line 825 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 2734 "y.tab.c"
    break;

  case 222: /* func_calls: call_head arguments  */
#line 829 "parser.y"
                                                              {(yyval.str) = (yyvsp[-1].str);}
#line 2740 "y.tab.c"
    break;

  case 223: /* call_head: CALL LHS  */
#line 833 "parser.y"
                                                    {
							if(classIndex == -1){
								(yyval.str) = func_symb[currentFuncIndex].type;
							}
							else{
								(yyval.str) = class_symb[classIndex].func_list[currentFuncIndex].type;
							}
						}
#line 2753 "y.tab.c"
    break;


#line 2757 "y.tab.c"

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

#line 851 "parser.y"


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




