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
  YYSYMBOL_loop_stmt = 105,                /* loop_stmt  */
  YYSYMBOL_loop_type = 106,                /* loop_type  */
  YYSYMBOL_for_loop = 107,                 /* for_loop  */
  YYSYMBOL_for_expr = 108,                 /* for_expr  */
  YYSYMBOL_for_RHS = 109,                  /* for_RHS  */
  YYSYMBOL_while_loop = 110,               /* while_loop  */
  YYSYMBOL_111_6 = 111,                    /* $@6  */
  YYSYMBOL_expr_stmt = 112,                /* expr_stmt  */
  YYSYMBOL_LHS = 113,                      /* LHS  */
  YYSYMBOL_myId = 114,                     /* myId  */
  YYSYMBOL_declr_stmt = 115,               /* declr_stmt  */
  YYSYMBOL_declr_body = 116,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 117,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 118,              /* matrix_list  */
  YYSYMBOL_id_list = 119,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 120,              /* ifcond_stmt  */
  YYSYMBOL_121_7 = 121,                    /* $@7  */
  YYSYMBOL_if_body = 122,                  /* if_body  */
  YYSYMBOL_switch_stmt = 123,              /* switch_stmt  */
  YYSYMBOL_124_8 = 124,                    /* $@8  */
  YYSYMBOL_switch_body = 125,              /* switch_body  */
  YYSYMBOL_126_9 = 126,                    /* $@9  */
  YYSYMBOL_cases = 127,                    /* cases  */
  YYSYMBOL_RHS = 128,                      /* RHS  */
  YYSYMBOL_constants = 129,                /* constants  */
  YYSYMBOL_extra_consts = 130,             /* extra_consts  */
  YYSYMBOL_array_const = 131,              /* array_const  */
  YYSYMBOL_val_list = 132,                 /* val_list  */
  YYSYMBOL_resultant = 133,                /* resultant  */
  YYSYMBOL_impr = 134,                     /* impr  */
  YYSYMBOL_graph_impr = 135,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 136,              /* matrix_impr  */
  YYSYMBOL_matr_body = 137,                /* matr_body  */
  YYSYMBOL_graph_const = 138,              /* graph_const  */
  YYSYMBOL_graph_type1 = 139,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 140,              /* graph_type2  */
  YYSYMBOL_int_list = 141,                 /* int_list  */
  YYSYMBOL_float_list = 142,               /* float_list  */
  YYSYMBOL_char_list = 143,                /* char_list  */
  YYSYMBOL_bool_list = 144,                /* bool_list  */
  YYSYMBOL_str_list = 145,                 /* str_list  */
  YYSYMBOL_weight_list = 146,              /* weight_list  */
  YYSYMBOL_vect_const = 147,               /* vect_const  */
  YYSYMBOL_vect_list = 148,                /* vect_list  */
  YYSYMBOL_matrix_const = 149,             /* matrix_const  */
  YYSYMBOL_int_float_list = 150,           /* int_float_list  */
  YYSYMBOL_mat_list = 151,                 /* mat_list  */
  YYSYMBOL_arith_op = 152,                 /* arith_op  */
  YYSYMBOL_binary_op = 153,                /* binary_op  */
  YYSYMBOL_unary_op = 154,                 /* unary_op  */
  YYSYMBOL_logical_op = 155,               /* logical_op  */
  YYSYMBOL_call_stmt = 156,                /* call_stmt  */
  YYSYMBOL_func_calls = 157,               /* func_calls  */
  YYSYMBOL_call_head = 158,                /* call_head  */
  YYSYMBOL_arguments = 159,                /* arguments  */
  YYSYMBOL_arg_list = 160                  /* arg_list  */
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
#define YYLAST   1047

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  232
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  455

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
     338,   339,   342,   343,   344,   345,   346,   347,   351,   354,
     355,   358,   361,   362,   376,   377,   378,   379,   380,   381,
     384,   384,   397,   411,   412,   413,   414,   418,   432,   494,
     495,   505,   507,   532,   557,   582,   607,   632,   668,   679,
     692,   704,   718,   723,   730,   730,   745,   746,   749,   749,
     764,   764,   767,   768,   772,   773,   774,   775,   776,   780,
     781,   782,   783,   784,   785,   789,   790,   791,   792,   793,
     797,   798,   801,   802,   803,   804,   805,   808,   809,   810,
     811,   812,   815,   816,   817,   818,   819,   820,   821,   826,
     827,   828,   829,   833,   834,   835,   838,   839,   842,   843,
     846,   847,   850,   851,   854,   855,   858,   859,   862,   863,
     866,   867,   870,   871,   874,   875,   876,   877,   880,   883,
     884,   885,   886,   889,   892,   893,   894,   895,   898,   899,
     902,   903,   906,   922,   932,   946,   956,   961,   965,   982,
     983,   986,   987
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
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "for_RHS",
  "while_loop", "$@6", "expr_stmt", "LHS", "myId", "declr_stmt",
  "declr_body", "graph_and_array_list", "matrix_list", "id_list",
  "ifcond_stmt", "$@7", "if_body", "switch_stmt", "$@8", "switch_body",
  "$@9", "cases", "RHS", "constants", "extra_consts", "array_const",
  "val_list", "resultant", "impr", "graph_impr", "matrix_impr",
  "matr_body", "graph_const", "graph_type1", "graph_type2", "int_list",
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

#define YYPACT_NINF (-318)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-172)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   153,   153,   867,    34,  -318,    69,  -318,  -318,  -318,
     -15,    12,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
      -4,    22,  -318,  -318,  -318,  -318,     2,  -318,   153,  -318,
    -318,  -318,    28,  -318,   670,  -318,  -318,  -318,   915,  -318,
    -318,   812,  -318,   -38,  -318,   153,    67,    61,    32,   408,
      41,    49,    53,    54,    65,   963,   153,   153,    70,    66,
      74,    75,   153,    -2,   812,    71,   812,  -318,  -318,  -318,
    -318,  -318,    68,  -318,  -318,  -318,   121,  -318,  -318,  -318,
    -318,    72,  -318,  -318,  -318,    77,  -318,    78,    79,  -318,
     915,    82,    80,    67,  -318,  -318,    83,    61,  -318,  -318,
    -318,  -318,  -318,  -318,    87,    90,    94,   530,   729,    52,
      92,    98,    13,   102,  -318,   103,  -318,    95,   105,   106,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,   729,  -318,
    -318,   729,   729,   153,   153,   153,   104,   153,   109,     5,
     121,   119,   125,  -318,  -318,  -318,   729,   729,   729,   114,
     729,   -15,  -318,  -318,  -318,  -318,   153,   440,  -318,  -318,
     617,  -318,  -318,   117,  -318,  -318,  -318,  -318,   729,   729,
    -318,   120,  -318,   121,   124,   128,   151,   152,   154,  -318,
     185,   155,   156,   158,   159,   160,    99,  -318,   161,  -318,
    -318,  -318,  -318,  -318,   162,  -318,  -318,  -318,  -318,  -318,
     163,   167,   168,    48,  -318,  -318,   169,  -318,   170,  -318,
     915,   173,  -318,  -318,   469,   192,   729,   175,   176,  -318,
     148,   178,  -318,   166,  -318,  -318,   171,   181,   182,   183,
     186,   187,   189,   190,   191,   193,   194,   196,   198,   202,
     204,  -318,   203,   184,  -318,   208,   210,   214,   219,    17,
     556,   556,  -318,  -318,  -318,   729,   277,   279,   280,   278,
     281,   225,   226,   227,  -318,  -318,  -318,  -318,  -318,   153,
     286,   288,   228,   234,   236,   237,   238,   239,    24,   241,
     729,   729,   729,  -318,   469,   759,   242,   244,   245,   759,
     246,   247,   759,   248,   759,   249,   250,   759,   759,   729,
    -318,  -318,  -318,   729,  -318,   295,   253,   254,  -318,  -318,
     255,  -318,  -318,  -318,  -318,  -318,    99,    99,   256,   -15,
     257,  -318,   260,   261,   153,  -318,  -318,  -318,  -318,  -318,
     258,  -318,   259,   265,   266,   267,  -318,  -318,  -318,  -318,
     268,    13,    95,  -318,  -318,  -318,  -318,  -318,  -318,   269,
    -318,  -318,   270,  -318,   272,  -318,  -318,   273,   274,  -318,
     271,   275,   314,   317,  -318,  -318,  -318,   276,   323,  -318,
    -318,  -318,   282,   283,  -318,    37,   -15,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,   759,   759,   759,  -318,   113,   284,
    -318,   285,  -318,  -318,   -15,   318,   153,   337,   153,   289,
    -318,  -318,   292,   293,   294,   296,   301,   277,   303,  -318,
     339,   322,  -318,   300,     9,   -15,  -318,  -318,  -318,   304,
     305,   298,   306,   310,   992,  -318,   303,   303,   -15,   -15,
     153,   307,  -318,    95,   308,   148,  -318,  -318,  -318,  -318,
     318,   316,  -318,  -318,  -318
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
      23,     0,     0,   119,    60,     0,    58,    69,    66,    74,
      75,    70,   170,    68,    67,    61,   167,   117,    63,    64,
      65,     0,   171,   169,   168,     0,    62,     0,     0,    42,
       0,    47,     0,    30,    32,    31,     0,    37,    52,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     119,   170,   154,     0,   144,     0,   155,   148,   169,   168,
     156,   157,   158,   145,   220,   221,   146,   147,     0,    72,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,    98,    99,   100,     0,     0,     0,     0,
       0,     0,    59,    55,    57,    78,     0,     0,    73,   226,
       0,   227,    45,     0,     9,    29,    34,    36,     0,     0,
      97,   149,   159,   154,   210,   212,     0,     0,     0,   170,
       0,   195,   197,   199,   203,   201,     0,   161,     0,   162,
     163,   164,   165,   166,     0,    96,    92,    93,    94,    95,
       0,     0,     0,   133,   126,   122,     0,   125,     0,   123,
       0,   133,   127,   121,     0,     0,     0,     0,     0,   186,
     187,     0,    77,     0,    76,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,   232,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   188,   189,   208,     0,     0,     0,     0,     0,
       0,   216,   217,     0,   160,   213,   134,   138,   223,     0,
       0,     0,     0,   170,     0,     0,   169,   168,     0,     0,
       0,     0,     0,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     229,    10,    35,     0,   225,     0,     0,     0,   209,   211,
       0,   194,   196,   198,   202,   200,     0,     0,     0,     0,
       0,   132,     0,     0,     0,   116,   112,   113,   114,   115,
       0,   110,     0,     0,     0,     0,    90,    91,    83,    84,
       0,    85,    89,    87,    88,    86,   172,    81,    82,     0,
     184,   174,     0,   175,     0,   185,   180,     0,     0,   231,
       0,     0,   191,   193,   224,   214,   215,   219,   137,   135,
     140,   139,   129,     0,   124,     0,     0,   176,   178,   183,
      79,    80,   173,   179,     0,     0,     0,   222,     0,     0,
     190,     0,   192,   218,     0,     0,     0,     0,     0,     0,
     102,   111,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,   128,     0,     0,     0,   177,   181,   182,   205,
     207,     0,     0,   131,     0,   101,     0,     0,     0,     0,
       0,   108,   103,   106,   107,   109,   104,   105,   204,   206,
     143,     0,   130,   142,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -318,  -318,   350,  -318,  -318,  -318,  -318,    -1,   287,  -318,
    -318,  -318,  -318,   297,   -21,  -318,  -318,  -318,  -318,  -318,
     291,     7,    -7,  -318,   -28,  -318,  -318,  -318,  -318,  -318,
    -318,   -46,  -212,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,   143,   -47,   211,     6,  -318,  -133,   -62,  -130,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,   -70,    10,  -101,
     -50,  -318,  -318,  -318,   -36,   -52,   -53,    91,  -318,    14,
      11,  -108,   118,   126,   122,   127,  -317,  -318,  -139,  -318,
    -203,    16,  -219,  -318,   -43,  -263,  -318,   -25,  -318,  -318,
      86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   255,   120,   102,   103,
       8,    57,   256,   106,     9,    10,    11,    45,    38,    53,
      54,    55,    74,    51,    75,    76,    77,    78,    79,    80,
      81,   189,   350,   345,    83,    84,   153,   154,   409,   442,
     155,   386,    85,   122,    87,    88,   148,   214,   217,   215,
      89,   329,   379,    90,   330,   381,   405,   421,   229,   124,
     185,   126,   198,    91,   127,    93,    94,   231,   130,   186,
     187,   316,   200,   201,   202,   203,   317,   131,   188,   132,
     273,   204,   133,   134,   135,   136,    96,   137,    98,   171,
     253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    37,    43,    86,    82,   129,   128,    95,   125,
      39,   199,   219,   121,   166,    92,   184,   222,   166,   149,
     150,   191,   166,    99,   100,   340,    97,    86,    82,    86,
      82,    95,   354,    95,    40,   104,   354,    49,    92,   354,
      92,   354,    42,    37,   354,   354,   162,    37,   164,    97,
      73,    97,   115,    46,   101,    58,   191,   192,   193,   194,
     195,   160,   105,   107,   147,   161,    64,    48,   408,   123,
     183,   159,    44,    73,   224,    73,   353,   315,   434,    47,
     353,  -167,   104,   353,   118,   353,    50,   359,   353,   353,
     362,    65,   364,     1,     2,   367,   368,    65,   108,    37,
       3,   138,     3,   271,   272,   230,   151,   152,   139,   105,
     279,   280,   140,   107,   141,   196,   197,   415,   416,   448,
     449,   318,   319,   375,   376,   142,   156,   165,   190,   163,
     166,   354,   354,   354,   157,   158,   168,   169,   174,   170,
     167,   176,   213,   216,   218,   173,   221,   178,   210,   331,
     179,   211,   212,   180,   234,   160,    12,   205,   321,   184,
     184,   206,   207,  -171,   208,   209,   227,   228,   223,   220,
     233,   287,   286,   232,   285,   353,   353,   353,   283,   225,
     252,   254,   412,   413,   414,   226,   260,   259,   257,   258,
     261,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   384,    26,    27,    28,    29,   262,
     263,   265,   264,   183,   183,   446,  -168,   266,   267,    37,
     268,   269,   270,    66,   276,   274,   275,   282,   277,   278,
     293,   294,   281,   280,   284,   279,   289,   290,   291,   230,
     292,   295,   296,   297,   347,   310,   298,   299,   351,   300,
     301,   302,   351,   303,   304,   351,   305,   351,   306,   352,
     351,   351,   307,   352,   308,   309,   352,   311,   352,   312,
     355,   352,   352,   422,   355,   320,   313,   355,   221,   355,
     314,   191,   355,   355,   192,   194,   193,   326,   327,   195,
     332,   328,   333,   335,   334,   336,   337,   338,   339,   371,
     342,   343,   341,   356,   346,   357,   358,   360,   361,   363,
     365,   366,   372,   373,   380,   377,   374,   385,   399,   252,
     387,   401,   378,   370,   382,   383,   388,   389,   390,   391,
     392,   393,   397,   221,   394,   395,   396,   398,   404,   196,
     420,   423,   410,   431,   406,   432,   407,   351,   351,   351,
     425,   417,   418,   426,   427,   428,    41,   429,   352,   352,
     352,   424,   430,   315,   433,   438,   436,   437,   288,   355,
     355,   355,   440,   439,   454,  -170,  -169,   235,   452,   411,
     453,   445,   444,   344,   402,   322,   400,    86,   441,     0,
     175,   172,   325,   403,   323,   369,   324,   419,   443,     0,
       0,     0,     0,     0,   177,   218,     0,     0,     0,   447,
       0,    12,   109,   110,   111,   112,   113,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   450,   451,     0,     0,   114,   115,    64,     0,   216,
      67,     0,     0,   116,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    69,    70,    71,
      26,    27,    28,    29,     0,   117,     0,     0,   118,     0,
       0,   119,    12,   109,   110,   111,   112,   113,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,   247,   248,   249,   250,   114,   115,    64,     0,
       0,    67,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29,     0,   117,     0,     0,   118,
       0,     0,   119,    12,   181,   110,   111,   112,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
     109,   110,   111,   112,   113,     0,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,     0,   117,   182,     0,
       0,     0,     0,   119,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,    29,     0,   117,     0,     0,     0,     0,     0,   119,
      12,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,    64,     0,     0,    67,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    70,    71,    26,
      27,    28,    29,    12,     0,     0,     0,   118,   251,     0,
       0,    32,     0,     0,     0,     0,     0,     0,    34,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,    52,    12,   109,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,    64,     0,
       0,    67,    12,   348,   349,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29,     0,   114,   115,    64,   118,
       0,    67,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29,    12,     0,     0,     0,   118,
       0,     0,     0,     0,     0,    59,    60,     0,    61,    62,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,    68,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29,    72,    42,
      12,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,     0,     0,     0,    34,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    12,    26,
      27,    28,    29,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    12,    26,    27,    28,
      29,     0,     0,     0,   143,     0,     0,     0,     0,     0,
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
       1,     2,     3,    10,    51,    51,    59,    59,    51,    59,
       3,   119,   145,    59,     9,    51,   117,   147,     9,    66,
      67,     4,     9,    61,    62,   288,    51,    74,    74,    76,
      76,    74,   295,    76,     0,    56,   299,    38,    74,   302,
      76,   304,    57,    44,   307,   308,    74,    48,    76,    74,
      51,    76,    28,    57,    55,    48,     4,     5,     6,     7,
       8,    63,    56,    57,    65,    67,    29,    65,    31,    59,
     117,    72,    60,    74,    69,    76,   295,    60,    69,    57,
     299,    68,   103,   302,    60,   304,    58,   299,   307,   308,
     302,    30,   304,    24,    25,   307,   308,    30,    66,   100,
      33,    60,    33,     4,     5,   158,    36,    37,    59,   103,
      62,    63,    59,   107,    60,    63,    64,     4,     5,   436,
     437,   260,   261,   326,   327,    60,    60,    59,   118,    58,
       9,   394,   395,   396,    60,    60,    59,    59,    58,    60,
      68,    58,   143,   144,   145,    63,   147,    60,   138,   279,
      60,   141,   142,    59,   161,    63,     3,    59,   266,   260,
     261,    59,    59,    68,    59,    59,   156,   157,    59,    65,
     160,   224,   224,    59,   224,   394,   395,   396,   224,    60,
     170,    64,   394,   395,   396,    60,    62,    67,   178,   179,
      62,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   334,    52,    53,    54,    55,    58,
      58,    26,    58,   260,   261,   434,    68,    62,    62,   220,
      62,    62,    62,    31,    61,    64,    64,   220,    61,    61,
      64,    60,    63,    63,   224,    62,   226,    62,    62,   292,
      62,    60,    60,    60,   294,    61,    60,    60,   295,    60,
      60,    60,   299,    60,    60,   302,    60,   304,    60,   295,
     307,   308,    60,   299,    60,    62,   302,    59,   304,    59,
     295,   307,   308,   406,   299,   265,    62,   302,   279,   304,
      61,     4,   307,   308,     5,     7,     6,    62,    62,     8,
       4,    64,     4,    59,    66,    59,    59,    59,    59,     4,
     290,   291,    61,    61,   294,    61,    61,    61,    61,    61,
      61,    61,    59,    59,    57,    59,    61,    59,     4,   309,
      61,     4,   329,   313,    64,    64,    61,    61,    61,    61,
      61,    61,    61,   334,    62,    62,    62,    62,    15,    63,
      22,     4,   385,     4,    62,    23,    63,   394,   395,   396,
      61,    67,    67,    61,    61,    61,     6,    61,   394,   395,
     396,   408,    61,    60,    64,    67,    62,    62,   225,   394,
     395,   396,    62,    67,    58,    68,    68,   166,   440,   386,
     450,   434,   434,   292,   373,   267,   372,   434,   434,    -1,
     103,   100,   270,   377,   268,   309,   269,   404,   434,    -1,
      -1,    -1,    -1,    -1,   107,   406,    -1,    -1,    -1,   434,
      -1,     3,     4,     5,     6,     7,     8,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,   439,    -1,    -1,    27,    28,    29,    -1,   440,
      32,    -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,    63,     3,     4,     5,     6,     7,     8,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    52,    53,    54,    55,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    60,
      -1,    -1,    63,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    57,    58,    -1,
      -1,    -1,    -1,    63,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    63,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     3,    -1,    -1,    -1,    60,    61,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    61,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,     3,     4,     5,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    27,    28,    29,    60,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    16,    17,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     3,    52,
      53,    54,    55,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     3,    52,    53,    54,
      55,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
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
      99,   100,   101,   104,   105,   112,   113,   114,   115,   120,
     123,   133,   134,   135,   136,   154,   156,   157,   158,    61,
      62,    77,    78,    79,    84,   115,    83,   115,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   101,   113,   128,   129,   130,   131,   134,   135,   136,
     138,   147,   149,   152,   153,   154,   155,   157,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   116,   113,
     113,    36,    37,   106,   107,   110,    60,    60,    60,    77,
      63,    67,    94,    58,    94,    59,     9,    68,    59,    59,
      60,   159,    90,    63,    58,    78,    58,    83,    60,    60,
      59,     4,    58,   113,   129,   130,   139,   140,   148,   101,
     128,     4,     5,     6,     7,     8,    63,    64,   132,   141,
     142,   143,   144,   145,   151,    59,    59,    59,    59,    59,
     128,   128,   128,    77,   117,   119,    77,   118,    77,   117,
      65,    77,   119,    59,    69,    60,    60,   128,   128,   128,
     136,   137,    59,   128,    92,   114,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    52,    53,    54,
      55,    61,   128,   160,    64,    76,    82,   128,   128,    67,
      62,    62,    58,    58,    58,    26,    62,    62,    62,    62,
      62,     4,     5,   150,    64,    64,    61,    61,    61,    62,
      63,    63,    91,   101,   128,   130,   135,   136,   112,   128,
      62,    62,    62,    64,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    62,
      61,    59,    59,    62,    61,    60,   141,   146,   148,   148,
     128,   141,   142,   143,   145,   144,    62,    62,    64,   121,
     124,   119,     4,     4,    66,    59,    59,    59,    59,    59,
     155,    61,   128,   128,   137,   103,   128,   130,     4,     5,
     102,   113,   134,   152,   155,   157,    61,    61,    61,   102,
      61,    61,   102,    61,   102,    61,    61,   102,   102,   160,
     128,     4,    59,    59,    61,   150,   150,    59,    92,   122,
      57,   125,    64,    64,   119,    59,   111,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    61,    62,     4,
     139,     4,   140,   151,    15,   126,    62,    63,    31,   108,
     154,    92,   102,   102,   102,     4,     5,    67,    67,    92,
      22,   127,   117,     4,   113,    61,    61,    61,    61,    61,
      61,     4,    23,    64,    69,    92,    62,    62,    67,    67,
      62,   101,   109,   134,   135,   136,   152,   157,   146,   146,
      92,    92,   118,   127,    58
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
     103,   103,   104,   104,   104,   104,   104,   104,   105,   106,
     106,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     111,   110,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   121,   120,   122,   122,   124,   123,
     126,   125,   127,   127,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   129,   129,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   132,   132,   132,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   146,   147,   148,
     148,   148,   148,   149,   150,   150,   150,   150,   151,   151,
     152,   152,   153,   154,   155,   155,   156,   157,   158,   159,
     159,   160,   160
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
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     8,     1,     4,     1,     1,     1,     1,     1,     1,
       0,     6,     5,     5,     5,     5,     5,     1,     3,     1,
       4,     3,     2,     2,     5,     2,     2,     2,     6,     4,
       9,     7,     3,     1,     0,     6,     3,     1,     0,     6,
       0,     7,     5,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     5,     5,     6,     8,     6,     6,
       5,     8,     8,     6,     5,     5,     1,     1,     3,     3,
       5,     4,     5,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     7,     5,     7,     5,     3,     3,
       1,     3,     1,     3,     3,     3,     1,     1,     5,     4,
       1,     1,     6,     4,     5,     4,     2,     2,     2,     3,
       2,     3,     1
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
#line 1883 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 135 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; }
#line 1889 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 135 "parser.y"
                                                                                                                   {fprintf(fparse, " : CLASS DEFINITION");}
#line 1895 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 138 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1901 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 139 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1907 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 140 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1913 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 141 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1919 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 142 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1925 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 143 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1931 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 144 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1937 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 145 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1943 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 146 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1949 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 147 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1955 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 148 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1961 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 149 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1967 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 150 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1973 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 151 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1979 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 152 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1985 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 153 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1991 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 154 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1997 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 155 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2003 "y.tab.c"
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
#line 2019 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 178 "parser.y"
                                                                         { var_delete(level); level--;}
#line 2025 "y.tab.c"
    break;

  case 35: /* struct: STRUCT id '{' $@3 struct_items '}' $@4 ';'  */
#line 178 "parser.y"
                                                                                                           {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2031 "y.tab.c"
    break;

  case 39: /* function_head: func_definition Parameters  */
#line 188 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2042 "y.tab.c"
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
#line 2054 "y.tab.c"
    break;

  case 43: /* fdtype: dtype  */
#line 211 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2060 "y.tab.c"
    break;

  case 44: /* fdtype: VOID  */
#line 212 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2066 "y.tab.c"
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
#line 2093 "y.tab.c"
    break;

  case 48: /* param: dtype id '[' ']'  */
#line 243 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].str), "array", (yyvsp[-3].str), -1, -1);
						}
#line 2101 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 250 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2107 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 251 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2113 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 252 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2119 "y.tab.c"
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
#line 2133 "y.tab.c"
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
#line 2155 "y.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 281 "parser.y"
                                      { level++; }
#line 2161 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@5 statements '}'  */
#line 281 "parser.y"
                                                                  {var_delete(level); level--;}
#line 2167 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 301 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2173 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 302 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2179 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 305 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2185 "y.tab.c"
    break;

  case 76: /* label_stmt: id ':' function_body  */
#line 312 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 2191 "y.tab.c"
    break;

  case 77: /* goto_stmt: GOTO id ';'  */
#line 315 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2197 "y.tab.c"
    break;

  case 78: /* vect_stmt: vect_stmt_body ';'  */
#line 318 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2203 "y.tab.c"
    break;

  case 92: /* return_stmt: RETURN RHS ';'  */
#line 342 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 2209 "y.tab.c"
    break;

  case 93: /* return_stmt: RETURN extra_consts ';'  */
#line 343 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2215 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN graph_impr ';'  */
#line 344 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2221 "y.tab.c"
    break;

  case 95: /* return_stmt: RETURN matrix_impr ';'  */
#line 345 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 2227 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 346 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2233 "y.tab.c"
    break;

  case 97: /* return_stmt: RETURN null ';'  */
#line 347 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2239 "y.tab.c"
    break;

  case 98: /* loop_stmt: LOOP loop_type  */
#line 351 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2245 "y.tab.c"
    break;

  case 103: /* for_expr: EXPR LHS '=' for_RHS  */
#line 362 "parser.y"
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
#line 2262 "y.tab.c"
    break;

  case 104: /* for_RHS: arith_op  */
#line 376 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str);}
#line 2268 "y.tab.c"
    break;

  case 105: /* for_RHS: func_calls  */
#line 377 "parser.y"
                                                             {(yyval.str) = (yyvsp[0].str);}
#line 2274 "y.tab.c"
    break;

  case 106: /* for_RHS: impr  */
#line 378 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2280 "y.tab.c"
    break;

  case 107: /* for_RHS: graph_impr  */
#line 379 "parser.y"
                                                             {(yyval.str) = "improvised";}
#line 2286 "y.tab.c"
    break;

  case 108: /* for_RHS: vect_stmt_body  */
#line 380 "parser.y"
                                                                 {(yyval.str) = "improvised";}
#line 2292 "y.tab.c"
    break;

  case 109: /* for_RHS: matrix_impr  */
#line 381 "parser.y"
                                                              {(yyval.str) = "improvised";}
#line 2298 "y.tab.c"
    break;

  case 110: /* $@6: %empty  */
#line 384 "parser.y"
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
#line 2314 "y.tab.c"
    break;

  case 112: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 397 "parser.y"
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
#line 2333 "y.tab.c"
    break;

  case 113: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 411 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2339 "y.tab.c"
    break;

  case 114: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 412 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2345 "y.tab.c"
    break;

  case 115: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 413 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2351 "y.tab.c"
    break;

  case 116: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 414 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2357 "y.tab.c"
    break;

  case 117: /* LHS: myId  */
#line 418 "parser.y"
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
#line 2376 "y.tab.c"
    break;

  case 118: /* LHS: LHS ARROW myId  */
#line 432 "parser.y"
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
#line 2440 "y.tab.c"
    break;

  case 119: /* myId: id  */
#line 494 "parser.y"
                                             {(yyval.str)=(yyvsp[0].str);}
#line 2446 "y.tab.c"
    break;

  case 120: /* myId: id '[' RHS ']'  */
#line 495 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "float");
							if(!a){
								printf("Error: invalid array index\n");
								exit(1);
							}
							(yyval.str) = (yyvsp[-3].str);
						}
#line 2459 "y.tab.c"
    break;

  case 121: /* declr_stmt: DECLR declr_body ';'  */
#line 505 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2465 "y.tab.c"
    break;

  case 122: /* declr_body: DATATYPE id_list  */
#line 508 "parser.y"
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
#line 2494 "y.tab.c"
    break;

  case 123: /* declr_body: GRAPH graph_and_array_list  */
#line 533 "parser.y"
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
#line 2523 "y.tab.c"
    break;

  case 124: /* declr_body: VECT '<' dtype '>' id_list  */
#line 558 "parser.y"
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
#line 2552 "y.tab.c"
    break;

  case 125: /* declr_body: MATRIX matrix_list  */
#line 583 "parser.y"
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
#line 2581 "y.tab.c"
    break;

  case 126: /* declr_body: DATATYPE graph_and_array_list  */
#line 608 "parser.y"
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
#line 2610 "y.tab.c"
    break;

  case 127: /* declr_body: id id_list  */
#line 633 "parser.y"
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
#line 2648 "y.tab.c"
    break;

  case 128: /* graph_and_array_list: id '[' INT_CONST ']' ',' graph_and_array_list  */
#line 669 "parser.y"
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
#line 2663 "y.tab.c"
    break;

  case 129: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 680 "parser.y"
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
#line 2678 "y.tab.c"
    break;

  case 130: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']' ',' matrix_list  */
#line 693 "parser.y"
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
#line 2694 "y.tab.c"
    break;

  case 131: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 705 "parser.y"
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
#line 2710 "y.tab.c"
    break;

  case 132: /* id_list: id ',' id_list  */
#line 719 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-2].str);
								arr_size++;
							}
#line 2719 "y.tab.c"
    break;

  case 133: /* id_list: id  */
#line 724 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].str);
								arr_size++;
							}
#line 2728 "y.tab.c"
    break;

  case 134: /* $@7: %empty  */
#line 730 "parser.y"
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
#line 2745 "y.tab.c"
    break;

  case 138: /* $@8: %empty  */
#line 749 "parser.y"
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
#line 2762 "y.tab.c"
    break;

  case 140: /* $@9: %empty  */
#line 764 "parser.y"
                                              {level++;}
#line 2768 "y.tab.c"
    break;

  case 141: /* switch_body: '{' $@9 cases DEFAULT ':' function_body '}'  */
#line 764 "parser.y"
                                                                                             { var_delete(level); level--;}
#line 2774 "y.tab.c"
    break;

  case 144: /* RHS: constants  */
#line 772 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 2780 "y.tab.c"
    break;

  case 145: /* RHS: arith_op  */
#line 773 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 2786 "y.tab.c"
    break;

  case 146: /* RHS: logical_op  */
#line 774 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2792 "y.tab.c"
    break;

  case 147: /* RHS: func_calls  */
#line 775 "parser.y"
                                                             {(yyval.str)=(yyvsp[0].str);}
#line 2798 "y.tab.c"
    break;

  case 148: /* RHS: impr  */
#line 776 "parser.y"
                                                       {(yyval.str) = "improvised";}
#line 2804 "y.tab.c"
    break;

  case 149: /* constants: INT_CONST  */
#line 780 "parser.y"
                                                    {(yyval.str)="int";}
#line 2810 "y.tab.c"
    break;

  case 150: /* constants: FLOAT_CONST  */
#line 781 "parser.y"
                                                              {(yyval.str)="float";}
#line 2816 "y.tab.c"
    break;

  case 151: /* constants: CHAR_CONST  */
#line 782 "parser.y"
                                                             {(yyval.str)="char";}
#line 2822 "y.tab.c"
    break;

  case 152: /* constants: STR_CONST  */
#line 783 "parser.y"
                                                            {(yyval.str)="string";}
#line 2828 "y.tab.c"
    break;

  case 153: /* constants: BOOL_CONST  */
#line 784 "parser.y"
                                                             {(yyval.str) = "bool";}
#line 2834 "y.tab.c"
    break;

  case 154: /* constants: LHS  */
#line 785 "parser.y"
                                                      {(yyval.str) = (yyvsp[0].details).type;}
#line 2840 "y.tab.c"
    break;

  case 222: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 906 "parser.y"
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
#line 2859 "y.tab.c"
    break;

  case 223: /* unary_op: UNARYOP '(' RHS ')'  */
#line 922 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 2872 "y.tab.c"
    break;

  case 224: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 932 "parser.y"
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
#line 2891 "y.tab.c"
    break;

  case 225: /* logical_op: NOT '(' RHS ')'  */
#line 946 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].str), "int") || !strcmp((yyvsp[-1].str), "bool")|| !strcmp((yyvsp[-1].str), "float")){
								(yyval.str) = "int";
							}
							else{
								printf("Error: Invalid argument for arithmetic operation\n");
							}
						}
#line 2904 "y.tab.c"
    break;

  case 226: /* call_stmt: func_calls ';'  */
#line 956 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 2910 "y.tab.c"
    break;

  case 227: /* func_calls: call_head arguments  */
#line 961 "parser.y"
                                                              {(yyval.str) = (yyvsp[-1].str);}
#line 2916 "y.tab.c"
    break;

  case 228: /* call_head: CALL LHS  */
#line 965 "parser.y"
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
#line 2936 "y.tab.c"
    break;


#line 2940 "y.tab.c"

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

#line 990 "parser.y"


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




