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
	
	
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/

#line 107 "y.tab.c"

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
#line 37 "parser.y"

	char* str;
	struct{
		int level;
	} level;
	struct{
		char* name;
		char* type;
	} details;
	

#line 284 "y.tab.c"

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
  YYSYMBOL_function_head = 86,             /* function_head  */
  YYSYMBOL_func_definition = 87,           /* func_definition  */
  YYSYMBOL_Parameters = 88,                /* Parameters  */
  YYSYMBOL_89_6 = 89,                      /* $@6  */
  YYSYMBOL_fdtype = 90,                    /* fdtype  */
  YYSYMBOL_param_list = 91,                /* param_list  */
  YYSYMBOL_dtype = 92,                     /* dtype  */
  YYSYMBOL_function_body = 93,             /* function_body  */
  YYSYMBOL_94_7 = 94,                      /* $@7  */
  YYSYMBOL_statements = 95,                /* statements  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL_unary_stmt = 97,                /* unary_stmt  */
  YYSYMBOL_jump_stmt = 98,                 /* jump_stmt  */
  YYSYMBOL_label_stmt = 99,                /* label_stmt  */
  YYSYMBOL_goto_stmt = 100,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 101,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 102,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 103,              /* remove_body  */
  YYSYMBOL_vect_append = 104,              /* vect_append  */
  YYSYMBOL_return_stmt = 105,              /* return_stmt  */
  YYSYMBOL_loop_stmt = 106,                /* loop_stmt  */
  YYSYMBOL_loop_type = 107,                /* loop_type  */
  YYSYMBOL_for_loop = 108,                 /* for_loop  */
  YYSYMBOL_for_expr = 109,                 /* for_expr  */
  YYSYMBOL_while_loop = 110,               /* while_loop  */
  YYSYMBOL_expr_stmt = 111,                /* expr_stmt  */
  YYSYMBOL_LHS = 112,                      /* LHS  */
  YYSYMBOL_declr_stmt = 113,               /* declr_stmt  */
  YYSYMBOL_declr_body = 114,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 115,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 116,              /* matrix_list  */
  YYSYMBOL_id_list = 117,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 118,              /* ifcond_stmt  */
  YYSYMBOL_119_8 = 119,                    /* $@8  */
  YYSYMBOL_if_body = 120,                  /* if_body  */
  YYSYMBOL_switch_stmt = 121,              /* switch_stmt  */
  YYSYMBOL_122_9 = 122,                    /* $@9  */
  YYSYMBOL_switch_body = 123,              /* switch_body  */
  YYSYMBOL_124_10 = 124,                   /* $@10  */
  YYSYMBOL_cases = 125,                    /* cases  */
  YYSYMBOL_RHS = 126,                      /* RHS  */
  YYSYMBOL_constants = 127,                /* constants  */
  YYSYMBOL_extra_consts = 128,             /* extra_consts  */
  YYSYMBOL_array_const = 129,              /* array_const  */
  YYSYMBOL_val_list = 130,                 /* val_list  */
  YYSYMBOL_resultant = 131,                /* resultant  */
  YYSYMBOL_impr = 132,                     /* impr  */
  YYSYMBOL_graph_impr = 133,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 134,              /* matrix_impr  */
  YYSYMBOL_matr_body = 135,                /* matr_body  */
  YYSYMBOL_graph_const = 136,              /* graph_const  */
  YYSYMBOL_graph_type1 = 137,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 138,              /* graph_type2  */
  YYSYMBOL_int_list = 139,                 /* int_list  */
  YYSYMBOL_float_list = 140,               /* float_list  */
  YYSYMBOL_char_list = 141,                /* char_list  */
  YYSYMBOL_bool_list = 142,                /* bool_list  */
  YYSYMBOL_str_list = 143,                 /* str_list  */
  YYSYMBOL_weight_list = 144,              /* weight_list  */
  YYSYMBOL_vect_const = 145,               /* vect_const  */
  YYSYMBOL_vect_list = 146,                /* vect_list  */
  YYSYMBOL_matrix_const = 147,             /* matrix_const  */
  YYSYMBOL_int_float_list = 148,           /* int_float_list  */
  YYSYMBOL_mat_list = 149,                 /* mat_list  */
  YYSYMBOL_arith_op = 150,                 /* arith_op  */
  YYSYMBOL_binary_op = 151,                /* binary_op  */
  YYSYMBOL_unary_op = 152,                 /* unary_op  */
  YYSYMBOL_logical_op = 153,               /* logical_op  */
  YYSYMBOL_call_stmt = 154,                /* call_stmt  */
  YYSYMBOL_func_calls = 155,               /* func_calls  */
  YYSYMBOL_arg_list = 156                  /* arg_list  */
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
#define YYLAST   961

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  450

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
       0,   110,   110,   110,   113,   114,   117,   118,   119,   122,
     126,   122,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     149,   150,   153,   154,   157,   157,   157,   160,   161,   164,
     167,   176,   184,   185,   185,   189,   190,   193,   231,   271,
     272,   273,   274,   283,   302,   302,   303,   306,   307,   308,
     309,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   326,   329,   330,   333,   336,   339,   342,
     343,   344,   345,   349,   350,   351,   352,   353,   354,   355,
     359,   360,   363,   364,   365,   366,   367,   368,   372,   375,
     376,   379,   382,   383,   384,   385,   386,   387,   388,   391,
     394,   395,   396,   397,   398,   401,   414,   467,   469,   470,
     471,   472,   473,   474,   475,   478,   479,   482,   483,   486,
     487,   490,   490,   493,   494,   497,   497,   500,   500,   503,
     504,   508,   509,   510,   511,   512,   516,   517,   518,   519,
     520,   521,   525,   526,   527,   528,   529,   533,   534,   537,
     538,   539,   540,   541,   544,   545,   546,   547,   548,   551,
     552,   553,   554,   555,   556,   557,   562,   563,   564,   565,
     569,   570,   571,   574,   575,   578,   579,   582,   583,   586,
     587,   590,   591,   594,   595,   598,   599,   602,   603,   606,
     607,   610,   611,   612,   613,   616,   619,   620,   621,   622,
     625,   628,   629,   630,   631,   634,   635,   638,   639,   642,
     645,   648,   649,   652,   655,   656,   659,   660
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
  "class_item", "struct", "$@4", "$@5", "struct_items", "function",
  "function_head", "func_definition", "Parameters", "$@6", "fdtype",
  "param_list", "dtype", "function_body", "$@7", "statements", "statement",
  "unary_stmt", "jump_stmt", "label_stmt", "goto_stmt", "vect_stmt",
  "vect_stmt_body", "remove_body", "vect_append", "return_stmt",
  "loop_stmt", "loop_type", "for_loop", "for_expr", "while_loop",
  "expr_stmt", "LHS", "declr_stmt", "declr_body", "graph_and_array_list",
  "matrix_list", "id_list", "ifcond_stmt", "$@8", "if_body", "switch_stmt",
  "$@9", "switch_body", "$@10", "cases", "RHS", "constants",
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

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-169)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -303,    49,    14,  -303,    71,    71,   829,  -303,    14,  -303,
    -303,  -303,     9,    -2,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,    19,    40,  -303,  -303,  -303,  -303,    39,  -303,
      71,  -303,  -303,    50,  -303,    61,  -303,  -303,  -303,   877,
    -303,  -303,   774,  -303,   877,    31,   104,    74,   453,    83,
      85,    86,    87,    89,   283,    71,    71,    26,    90,    91,
      94,    71,    81,   774,    98,   774,  -303,  -303,  -303,  -303,
    -303,   100,  -303,  -303,  -303,   148,  -303,  -303,  -303,    95,
    -303,  -303,  -303,   101,  -303,   103,   112,    71,   105,    31,
    -303,  -303,   106,   104,  -303,  -303,  -303,  -303,  -303,  -303,
     114,   115,   117,   181,   691,    16,  -303,   118,    32,   119,
    -303,   124,  -303,    99,   131,   132,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,   691,  -303,  -303,   691,   691,    71,
      71,    71,   133,    71,    71,   136,    23,    34,   122,   137,
    -303,  -303,  -303,   691,   691,   691,   139,     9,  -303,  -303,
    -303,  -303,    71,   245,  -303,  -303,  -303,   138,  -303,  -303,
    -303,  -303,   691,   691,  -303,   134,  -303,   148,   140,   143,
     150,   151,   155,  -303,   175,   144,   152,   153,   154,   156,
     102,  -303,   163,  -303,  -303,  -303,  -303,  -303,   173,  -303,
    -303,  -303,  -303,  -303,   184,   185,   187,    -8,  -303,  -303,
     183,  -303,   186,  -303,   877,    71,    71,  -303,   519,   632,
     222,   691,   195,   197,  -303,   194,   199,  -303,  -303,  -303,
     203,   204,   208,   214,   215,   217,   219,   220,   235,   244,
     246,   249,   250,   251,   252,   877,   254,   255,   243,   256,
      29,   577,   577,  -303,  -303,  -303,   691,   314,   316,   317,
     315,   318,   262,   265,   259,  -303,  -303,  -303,  -303,  -303,
      71,   326,   327,   268,   271,  -303,  -303,   275,   278,   280,
     281,   282,  -303,   284,   286,    27,   287,   691,   691,   691,
     519,   721,   288,   289,   290,   721,   291,   292,   721,   295,
     721,   300,   301,   721,   721,  -303,  -303,  -303,   691,  -303,
     338,   304,   305,  -303,  -303,   306,  -303,  -303,  -303,  -303,
    -303,   102,   102,   307,     9,   308,  -303,   299,   303,    71,
    -303,  -303,  -303,  -303,  -303,   691,  -303,   321,     9,   312,
     313,   320,   323,  -303,  -303,  -303,  -303,   324,    32,    99,
    -303,  -303,  -303,  -303,  -303,  -303,   325,  -303,  -303,   328,
    -303,   329,  -303,  -303,   331,   332,   334,   336,   371,   372,
    -303,  -303,  -303,   309,   373,  -303,  -303,  -303,   340,   319,
    -303,  -303,    15,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,   721,   721,   721,  -303,   123,   339,  -303,   341,  -303,
    -303,     9,   368,    71,   392,    71,   344,  -303,   346,   348,
     349,   350,   352,   314,   354,  -303,   411,   393,  -303,   351,
      28,     9,  -303,  -303,  -303,   355,   356,   357,   358,   359,
     906,  -303,   354,   354,     9,     9,    71,   353,    99,   361,
     194,  -303,  -303,  -303,  -303,   368,   366,  -303,  -303,  -303
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     3,     5,     7,
       8,     6,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    24,    26,    27,
      28,    29,     0,     0,    49,    46,    50,    51,     0,    53,
       0,    45,     4,    54,    39,    43,    40,     9,    34,     0,
      41,    56,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    24,
       0,     0,   115,    60,     0,    58,    69,    66,    74,    75,
      70,   167,    68,    67,    61,   164,    63,    64,    65,     0,
     168,   166,   165,     0,    62,     0,     0,     0,     0,    31,
      33,    32,     0,    38,    52,   146,   147,   148,   149,   150,
       0,     0,     0,     0,     0,     0,   115,   167,   151,     0,
     141,     0,   152,   145,   166,   165,   153,   154,   155,   142,
     217,   218,   143,   144,     0,    72,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,     0,     0,     0,     0,    59,    55,
      57,    78,     0,     0,    73,   223,    44,    48,    10,    30,
      35,    37,     0,     0,    97,   146,   156,   151,   207,   209,
       0,     0,     0,   167,     0,   192,   194,   196,   200,   198,
       0,   158,     0,   159,   160,   161,   162,   163,     0,    96,
      92,    93,    94,    95,     0,     0,     0,   130,   122,   118,
       0,   121,     0,   119,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,   183,   184,     0,    77,    76,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,   205,     0,     0,     0,     0,
       0,     0,   213,   214,     0,   157,   210,   131,   135,   220,
       0,     0,     0,     0,   130,   124,   123,   167,     0,     0,
     166,   165,   225,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    11,    36,     0,   222,
       0,     0,     0,   206,   208,     0,   191,   193,   195,   199,
     197,     0,     0,     0,     0,     0,   129,     0,     0,     0,
     114,   110,   111,   112,   113,     0,   224,     0,     0,     0,
       0,     0,     0,    90,    91,    83,    84,     0,    85,    89,
      87,    88,    86,   169,    81,    82,     0,   181,   171,     0,
     172,     0,   182,   177,     0,     0,     0,     0,   188,   190,
     221,   211,   212,   216,   134,   132,   137,   136,   126,     0,
     120,   226,     0,   109,   173,   175,   180,    79,    80,   170,
     176,     0,     0,     0,   219,     0,     0,   187,     0,   189,
     215,     0,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   125,     0,
       0,     0,   174,   178,   179,   202,   204,     0,     0,   128,
       0,   101,     0,     0,     0,     0,     0,   107,   105,   106,
     108,   103,   104,   201,   203,   140,     0,   127,   139,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,  -303,   420,  -303,  -303,  -303,  -303,    -4,   330,
    -303,  -303,  -303,  -303,   333,     1,  -303,  -303,  -303,  -303,
    -303,   188,     3,    -9,  -303,   -16,  -303,  -303,  -303,  -303,
    -303,  -303,   -47,  -199,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,   210,   -48,   -21,  -303,  -131,    -5,  -200,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,   -11,   182,   -99,   -46,  -303,
    -303,  -303,   -33,   -51,   -52,   146,  -303,    69,    70,  -102,
     189,   190,   179,   191,  -302,  -303,  -119,  -303,  -180,    68,
    -223,  -303,   -44,  -212,  -303,   -22,   107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    55,   246,   116,    98,
      99,    10,    56,   247,   102,    11,    12,    13,    46,    54,
      40,    96,    97,    73,    52,    74,    75,    76,    77,    78,
      79,    80,   183,   347,   342,    82,    83,   150,   151,   406,
     152,    84,   118,    86,   145,   208,   211,   209,    87,   324,
     375,    88,   325,   377,   402,   417,   224,   120,   179,   122,
     192,    89,   123,    91,    92,   226,   126,   180,   181,   311,
     194,   195,   196,   197,   312,   127,   182,   128,   264,   198,
     129,   130,   131,   132,    94,   133,   284
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    33,    39,    44,    85,    81,   125,   124,    93,    41,
     213,   117,   121,   193,   178,   275,   276,   146,   147,    90,
     185,   186,   187,   188,   189,    85,    81,    85,    81,    93,
      95,    93,   162,   185,   101,   103,    50,   162,     4,     5,
      90,   162,    90,   162,    63,    39,   405,     6,    72,     3,
      39,    95,    57,    95,   270,   111,   100,   158,    45,   160,
     271,    64,   148,   149,     6,   177,    43,   156,   350,    72,
     326,    72,   350,   337,    14,   350,    47,   350,   101,   351,
     350,   350,   103,   351,   190,   191,   351,   114,   351,   310,
     218,   351,   351,   167,   219,   430,   356,    48,  -164,   359,
     100,   361,    49,   225,   364,   365,   262,   263,    51,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    53,    28,    29,    30,    31,   411,   412,   380,
     443,   444,   313,   314,    64,   207,   210,   212,   104,   215,
     216,   371,   372,   134,   135,   136,   157,   137,   228,   138,
     153,   154,   178,   178,   155,   316,   159,   162,   229,   161,
     164,   163,   165,   168,   170,  -168,   281,   280,   350,   350,
     350,   277,   279,   166,   172,   173,   174,   199,   200,   351,
     351,   351,   220,   201,    14,   175,   106,   107,   108,   109,
     202,   203,   408,   409,   410,   217,   214,   221,   227,   250,
     245,   256,   251,   177,   177,   252,   257,   441,   253,   254,
      39,   274,   274,   255,   258,   259,   260,   273,   261,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   265,    28,    29,    30,    31,   225,   113,   176,
     119,    39,   266,   348,   344,   267,   268,   348,   269,   115,
     348,   272,   348,    65,   271,   348,   348,   287,   349,   288,
    -165,   289,   349,   290,   291,   349,   274,   349,   292,   352,
     349,   349,   418,   352,   293,   294,   352,   295,   352,   296,
     297,   352,   352,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   139,   298,   184,   241,   242,   243,
     244,   140,   141,   142,   299,   308,   300,   143,   144,   301,
     302,   303,   304,   306,   307,   374,   204,   309,   185,   205,
     206,   186,   188,   187,   321,   274,   189,   322,   323,   383,
     327,   328,   329,   270,   330,   222,   223,   331,   407,   332,
     333,   334,   367,   348,   348,   348,   335,   336,   338,   353,
     354,   355,   357,   358,   248,   249,   360,   420,   349,   349,
     349,   362,   363,   368,   369,   376,   373,   370,   378,   352,
     352,   352,   379,   384,   385,   396,   398,   190,   440,   439,
     382,   386,    85,   437,   387,   388,   389,   404,   401,   390,
     416,   391,   415,   392,   393,   394,   419,   438,   395,   212,
     278,   283,   403,   286,   413,   421,   414,   422,   442,   423,
     424,   425,   431,   426,   310,   427,   428,   432,   433,  -167,
     429,   436,   434,   435,   449,   445,   446,  -166,    42,   169,
     285,   447,   210,   305,   448,   341,   171,   397,   315,   399,
     320,   400,   381,     0,     0,     0,     0,   317,     0,   318,
       0,   319,     0,     0,     0,     0,    14,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   339,
     340,     0,   343,     0,     0,     0,     0,     0,     0,     0,
     110,   111,    63,     0,     0,    66,     0,     0,   112,     0,
     366,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    68,    69,    70,    28,    29,    30,    31,     0,
     113,     0,     0,   114,     0,     0,     0,   283,     0,     0,
       0,   115,    14,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,    63,     0,
       0,    66,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    68,    69,
      70,    28,    29,    30,    31,     0,   113,     0,     0,   114,
      14,   105,   106,   107,   108,   109,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,   113,    14,   105,   106,   107,   108,
     109,     0,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,    63,     0,     0,    66,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    68,    69,    70,    28,    29,    30,    31,     0,     0,
       0,     0,   114,   282,    14,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
      63,     0,     0,    66,    14,   345,   346,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      68,    69,    70,    28,    29,    30,    31,     0,   110,   111,
      63,   114,     0,    66,     0,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      68,    69,    70,    28,    29,    30,    31,    14,     0,     0,
       0,   114,     0,     0,     0,     0,     0,    58,    59,     0,
      60,    61,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,     0,    67,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    68,    69,    70,    28,    29,    30,    31,
      71,    43,    14,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      14,    28,    29,    30,    31,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,   110,     0,    63,     0,     0,    66,     0,
       0,     0,     0,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    68,    69,    70,    28,    29,
      30,    31
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,    12,    52,    52,    58,    58,    52,     6,
     141,    58,    58,   115,   113,   215,   216,    65,    66,    52,
       4,     5,     6,     7,     8,    73,    73,    75,    75,    73,
      52,    75,     9,     4,    55,    56,    40,     9,    24,    25,
      73,     9,    75,     9,    29,    49,    31,    33,    52,     0,
      54,    73,    49,    75,    62,    28,    55,    73,    60,    75,
      68,    30,    36,    37,    33,   113,    57,    71,   291,    73,
     270,    75,   295,   285,     3,   298,    57,   300,    99,   291,
     303,   304,   103,   295,    68,    69,   298,    60,   300,    60,
      67,   303,   304,    97,    60,    67,   295,    57,    66,   298,
      99,   300,    63,   155,   303,   304,     4,     5,    58,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    61,    52,    53,    54,    55,     4,     5,   329,
     432,   433,   251,   252,    30,   139,   140,   141,    64,   143,
     144,   321,   322,    60,    59,    59,    65,    60,   157,    60,
      60,    60,   251,   252,    60,   257,    58,     9,   162,    59,
      59,    66,    59,    58,    58,    66,   218,   218,   391,   392,
     393,   218,   218,    61,    60,    60,    59,    59,    59,   391,
     392,   393,    60,    59,     3,     4,     5,     6,     7,     8,
      59,    59,   391,   392,   393,    59,    63,    60,    59,    65,
      62,    26,    62,   251,   252,    62,    62,   430,    58,    58,
     214,   215,   216,    58,    62,    62,    62,   214,    62,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    69,    52,    53,    54,    55,   289,    57,    58,
      58,   245,    69,   291,   290,    61,    61,   295,    61,    68,
     298,    68,   300,    31,    68,   303,   304,    62,   291,    62,
      66,    62,   295,    60,    60,   298,   270,   300,    60,   291,
     303,   304,   403,   295,    60,    60,   298,    60,   300,    60,
      60,   303,   304,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    11,    60,   114,    52,    53,    54,
      55,    18,    19,    20,    60,    62,    60,    24,    25,    60,
      60,    60,    60,    59,    59,   324,   134,    61,     4,   137,
     138,     5,     7,     6,    62,   329,     8,    62,    69,   338,
       4,     4,    64,    62,    59,   153,   154,    59,   382,    59,
      59,    59,     4,   391,   392,   393,    62,    61,    61,    61,
      61,    61,    61,    61,   172,   173,    61,   405,   391,   392,
     393,    61,    61,    59,    59,    57,    59,    61,    69,   391,
     392,   393,    69,    61,    61,     4,     4,    68,   430,   430,
      59,    61,   430,   430,    61,    61,    61,    68,    15,    61,
      22,    62,   401,    62,    62,    61,     4,   430,    62,   403,
     218,   219,    62,   221,    65,    61,    65,    61,   430,    61,
      61,    61,   421,    61,    60,     4,    23,    62,    62,    66,
      69,    62,    65,    65,    58,   434,   435,    66,     8,    99,
     220,   436,   436,   245,   445,   289,   103,   368,   256,   369,
     261,   373,   335,    -1,    -1,    -1,    -1,   258,    -1,   259,
      -1,   260,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
     288,    -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,
     308,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    -1,    60,    -1,    -1,    -1,   335,    -1,    -1,
      -1,    68,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    60,
       3,     4,     5,     6,     7,     8,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    -1,    57,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    32,     3,     4,     5,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    27,    28,
      29,    60,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       3,    52,    53,    54,    55,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    27,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    72,     0,    24,    25,    33,    73,    74,    75,
      81,    85,    86,    87,     3,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    55,    78,    78,    11,    12,    18,    19,    20,    78,
      90,    92,    73,    57,    93,    60,    88,    57,    57,    63,
      78,    58,    94,    61,    89,    76,    82,    92,    13,    14,
      16,    17,    21,    29,    30,    31,    32,    34,    49,    50,
      51,    56,    78,    93,    95,    96,    97,    98,    99,   100,
     101,   102,   105,   106,   111,   112,   113,   118,   121,   131,
     132,   133,   134,   152,   154,   155,    91,    92,    79,    80,
      85,   113,    84,   113,    64,     4,     5,     6,     7,     8,
      27,    28,    35,    57,    60,    68,    78,   102,   112,   126,
     127,   128,   129,   132,   133,   134,   136,   145,   147,   150,
     151,   152,   153,   155,    60,    59,    59,    60,    60,    11,
      18,    19,    20,    24,    25,   114,   112,   112,    36,    37,
     107,   108,   110,    60,    60,    60,    78,    65,    95,    58,
      95,    59,     9,    66,    59,    59,    61,    78,    58,    79,
      58,    84,    60,    60,    59,     4,    58,   112,   127,   128,
     137,   138,   146,   102,   126,     4,     5,     6,     7,     8,
      68,    69,   130,   139,   140,   141,   142,   143,   149,    59,
      59,    59,    59,    59,   126,   126,   126,    78,   115,   117,
      78,   116,    78,   115,    63,    78,    78,    59,    67,    60,
      60,    60,   126,   126,   126,   134,   135,    59,    93,    78,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    52,    53,    54,    55,    62,    77,    83,   126,   126,
      65,    62,    62,    58,    58,    58,    26,    62,    62,    62,
      62,    62,     4,     5,   148,    69,    69,    61,    61,    61,
      62,    68,    68,    92,    78,   117,   117,   102,   126,   128,
     133,   134,    61,   126,   156,   111,   126,    62,    62,    62,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    91,    59,    59,    62,    61,
      60,   139,   144,   146,   146,   126,   139,   140,   141,   143,
     142,    62,    62,    69,   119,   122,   117,     4,     4,    64,
      59,    59,    59,    59,    59,    62,    61,   153,    61,   126,
     126,   135,   104,   126,   128,     4,     5,   103,   112,   132,
     150,   153,   155,    61,    61,    61,   103,    61,    61,   103,
      61,   103,    61,    61,   103,   103,   126,     4,    59,    59,
      61,   148,   148,    59,    93,   120,    57,   123,    69,    69,
     117,   156,    59,    93,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    61,    62,     4,   137,     4,   138,
     149,    15,   124,    62,    68,    31,   109,   152,   103,   103,
     103,     4,     5,    65,    65,    93,    22,   125,   115,     4,
     112,    61,    61,    61,    61,    61,    61,     4,    23,    69,
      67,    93,    62,    62,    65,    65,    62,   102,   132,   133,
     134,   150,   155,   144,   144,    93,    93,   116,   125,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    72,    71,    73,    73,    74,    74,    74,    76,
      77,    75,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    82,    83,    81,    84,    84,    85,
      86,    87,    88,    89,    88,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    94,    93,    93,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    98,    98,    99,   100,   101,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   107,
     107,   108,   109,   109,   109,   109,   109,   109,   109,   110,
     111,   111,   111,   111,   111,   112,   112,   113,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   119,   118,   120,   120,   122,   121,   124,   123,   125,
     125,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   143,
     143,   144,   144,   144,   144,   145,   146,   146,   146,   146,
     147,   148,   148,   148,   148,   149,   149,   150,   150,   151,
     152,   153,   153,   154,   155,   155,   156,   156
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     0,
       0,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     0,     8,     2,     1,     2,
       2,     3,     2,     0,     4,     1,     1,     4,     2,     1,
       1,     1,     4,     1,     0,     4,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     3,     3,     2,     6,
       6,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     8,     1,     4,     4,     4,     4,     4,     4,     5,
       5,     5,     5,     5,     5,     1,     3,     3,     2,     2,
       5,     2,     2,     3,     3,     6,     4,     9,     7,     3,
       1,     0,     6,     3,     1,     0,     6,     0,     7,     5,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       6,     5,     5,     6,     8,     6,     6,     5,     8,     8,
       6,     5,     5,     1,     1,     3,     3,     5,     4,     5,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     7,     5,     7,     5,     3,     3,     1,     3,     1,
       3,     3,     3,     1,     1,     5,     4,     1,     1,     6,
       4,     5,     4,     2,     5,     4,     3,     1
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
#line 110 "parser.y"
                                 {reset();}
#line 1841 "y.tab.c"
    break;

  case 3: /* program_unit: $@1 models  */
#line 110 "parser.y"
                                                   {reset();}
#line 1847 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 122 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							class_insert((yyvsp[-1].str));
						}
#line 1857 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 126 "parser.y"
                                                                  {level--; inClass = 0;}
#line 1863 "y.tab.c"
    break;

  case 11: /* class: CLASS id '{' $@2 class_items '}' $@3 ';'  */
#line 126 "parser.y"
                                                                                              {fprintf(fparse, " : CLASS DEFINITION");}
#line 1869 "y.tab.c"
    break;

  case 12: /* id: newid  */
#line 129 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1875 "y.tab.c"
    break;

  case 13: /* id: APPEND  */
#line 130 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1881 "y.tab.c"
    break;

  case 14: /* id: REMOVE  */
#line 131 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1887 "y.tab.c"
    break;

  case 15: /* id: LENGTH  */
#line 132 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1893 "y.tab.c"
    break;

  case 16: /* id: SORT  */
#line 133 "parser.y"
                                                       {(yyval.str)=(yyvsp[0].str);}
#line 1899 "y.tab.c"
    break;

  case 17: /* id: CLEAR  */
#line 134 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1905 "y.tab.c"
    break;

  case 18: /* id: AT  */
#line 135 "parser.y"
                                                     {(yyval.str)=(yyvsp[0].str);}
#line 1911 "y.tab.c"
    break;

  case 19: /* id: TRANSPOSE  */
#line 136 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1917 "y.tab.c"
    break;

  case 20: /* id: TRACE  */
#line 137 "parser.y"
                                                        {(yyval.str)=(yyvsp[0].str);}
#line 1923 "y.tab.c"
    break;

  case 21: /* id: TRAVERSAL  */
#line 138 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1929 "y.tab.c"
    break;

  case 22: /* id: STRLEN  */
#line 139 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1935 "y.tab.c"
    break;

  case 23: /* id: STRCUT  */
#line 140 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1941 "y.tab.c"
    break;

  case 24: /* id: STRJOIN  */
#line 141 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1947 "y.tab.c"
    break;

  case 25: /* id: STRCMP  */
#line 142 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1953 "y.tab.c"
    break;

  case 26: /* id: MAXTOGR  */
#line 143 "parser.y"
                                                          {(yyval.str)=(yyvsp[0].str);}
#line 1959 "y.tab.c"
    break;

  case 27: /* id: GRTOMATX  */
#line 144 "parser.y"
                                                           {(yyval.str)=(yyvsp[0].str);}
#line 1965 "y.tab.c"
    break;

  case 28: /* id: SHPATH  */
#line 145 "parser.y"
                                                         {(yyval.str)=(yyvsp[0].str);}
#line 1971 "y.tab.c"
    break;

  case 29: /* id: SHPATHVAL  */
#line 146 "parser.y"
                                                            {(yyval.str)=(yyvsp[0].str);}
#line 1977 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 157 "parser.y"
                                                       {level++;}
#line 1983 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 157 "parser.y"
                                                                                   {level--;}
#line 1989 "y.tab.c"
    break;

  case 36: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 157 "parser.y"
                                                                                                 {fprintf(fparse, " : STRUCT DEFINITION");}
#line 1995 "y.tab.c"
    break;

  case 40: /* function_head: func_definition Parameters  */
#line 167 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							if(inClass == 0) printFuncDetails(-1, func_size-1);
							else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
						}
#line 2006 "y.tab.c"
    break;

  case 41: /* func_definition: FUNC fdtype id  */
#line 176 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].str);
							(yyval.details).type = (yyvsp[-1].str);
							if(inClass == 0) func_insert((yyvsp[0].str), (yyvsp[-1].str));
							else class_func_insert(class_size-1, (yyvsp[0].str), (yyvsp[-1].str));
						}
#line 2017 "y.tab.c"
    break;

  case 43: /* $@6: %empty  */
#line 185 "parser.y"
                                                      {level++;}
#line 2023 "y.tab.c"
    break;

  case 44: /* Parameters: '(' $@6 param_list ')'  */
#line 185 "parser.y"
                                                                               {level--;}
#line 2029 "y.tab.c"
    break;

  case 45: /* fdtype: dtype  */
#line 189 "parser.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 2035 "y.tab.c"
    break;

  case 46: /* fdtype: VOID  */
#line 190 "parser.y"
                                                       {(yyval.str) = (yyvsp[0].str);}
#line 2041 "y.tab.c"
    break;

  case 47: /* param_list: dtype id ',' param_list  */
#line 193 "parser.y"
                                                                  {
							if(inClass == 0) add_args((yyvsp[-3].str));
							else class_add_args(class_size-1, (yyvsp[-3].str)); 
							var_insert(0, (yyvsp[-2].str), (yyvsp[-3].str), level, dataType);
							if(dataType == 1){
								/* arrays are useless here */
								array_insert((yyvsp[-2].str), "", -1);
							}
							
							else if(dataType == 2){
								// vector
								vect_insert((yyvsp[-2].str), "", -1);
							}
							
							else if(dataType == 3){
								// matrix
								matrix_insert((yyvsp[-2].str), -1, -1);
							}
							
							else if(dataType == 4){
								// graph
								graph_insert((yyvsp[-2].str), -1, -1);
							}
							
							else if(dataType == 5){
								// struct
								
								/* we store what kind of structs are there, but
									there is no symbol table for each type of struct */
							}
							
							else if(dataType == 6){
								// class
								
								/* we store what kind of classes are there, but
									there is no symbol table for each type of class */
							}
						}
#line 2084 "y.tab.c"
    break;

  case 48: /* param_list: dtype id  */
#line 231 "parser.y"
                                                           {
							add_args((yyvsp[-1].str)); 
							var_insert(0, (yyvsp[0].str), (yyvsp[-1].str), level, dataType);
							if(dataType == 1){
								/* arrays are useless here */
								array_insert((yyvsp[0].str), "", -1);
							}
							
							else if(dataType == 2){
								// vector
								vect_insert((yyvsp[0].str), "", -1);
							}
							
							else if(dataType == 3){
								// matrix
								matrix_insert((yyvsp[0].str), -1, -1);
							}
							
							else if(dataType == 4){
								// graph
								graph_insert((yyvsp[0].str), -1, -1);
							}
							
							else if(dataType == 5){
								// struct
								
								/* we store what kind of structs are there, but
									there is no symbol table for each type of struct */
							}
							
							else if(dataType == 6){
								// class
								
								/* we store what kind of classes are there, but
									there is no symbol table for each type of class */
							}
						}
#line 2126 "y.tab.c"
    break;

  case 49: /* dtype: DATATYPE  */
#line 271 "parser.y"
                                                   {(yyval.str) = (yyvsp[0].str); dataType = 0;}
#line 2132 "y.tab.c"
    break;

  case 50: /* dtype: MATRIX  */
#line 272 "parser.y"
                                                         {(yyval.str) = (yyvsp[0].str); dataType = 3;}
#line 2138 "y.tab.c"
    break;

  case 51: /* dtype: GRAPH  */
#line 273 "parser.y"
                                                        {(yyval.str) = (yyvsp[0].str); dataType = 4;}
#line 2144 "y.tab.c"
    break;

  case 52: /* dtype: VECT '<' dtype '>'  */
#line 274 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].str)) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].str));
						    dataType = 2;
						    (yyval.str) = result;
						}
#line 2158 "y.tab.c"
    break;

  case 53: /* dtype: id  */
#line 283 "parser.y"
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
#line 2180 "y.tab.c"
    break;

  case 54: /* $@7: %empty  */
#line 302 "parser.y"
                                      { level++; }
#line 2186 "y.tab.c"
    break;

  case 55: /* function_body: '{' $@7 statements '}'  */
#line 302 "parser.y"
                                                                  {var_delete(); level--;}
#line 2192 "y.tab.c"
    break;

  case 71: /* statement: BREAK ';'  */
#line 322 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2198 "y.tab.c"
    break;

  case 72: /* statement: CONTINUE ';'  */
#line 323 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2204 "y.tab.c"
    break;

  case 73: /* unary_stmt: unary_op ';'  */
#line 326 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT");}
#line 2210 "y.tab.c"
    break;

  case 76: /* label_stmt: id ':' function_body  */
#line 333 "parser.y"
                                                               {fprintf(fparse, " : LABEL");}
#line 2216 "y.tab.c"
    break;

  case 77: /* goto_stmt: GOTO id ';'  */
#line 336 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT");}
#line 2222 "y.tab.c"
    break;

  case 78: /* vect_stmt: vect_stmt_body ';'  */
#line 339 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2228 "y.tab.c"
    break;

  case 92: /* return_stmt: RETURN RHS ';'  */
#line 363 "parser.y"
                                                {fprintf(fparse, " : RETURN STATEMENT");}
#line 2234 "y.tab.c"
    break;

  case 93: /* return_stmt: RETURN extra_consts ';'  */
#line 364 "parser.y"
                                                                          {fprintf(fparse, " : RETURN STATEMENT");}
#line 2240 "y.tab.c"
    break;

  case 94: /* return_stmt: RETURN graph_impr ';'  */
#line 365 "parser.y"
                                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2246 "y.tab.c"
    break;

  case 95: /* return_stmt: RETURN matrix_impr ';'  */
#line 366 "parser.y"
                                                                         {fprintf(fparse, " : RETURN STATEMENT");}
#line 2252 "y.tab.c"
    break;

  case 96: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 367 "parser.y"
                                                                            {fprintf(fparse, " : RETURN STATEMENT");}
#line 2258 "y.tab.c"
    break;

  case 97: /* return_stmt: RETURN null ';'  */
#line 368 "parser.y"
                                                                  {fprintf(fparse, " : RETURN STATEMENT");}
#line 2264 "y.tab.c"
    break;

  case 98: /* loop_stmt: LOOP loop_type  */
#line 372 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 2270 "y.tab.c"
    break;

  case 110: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 394 "parser.y"
                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2276 "y.tab.c"
    break;

  case 111: /* expr_stmt: EXPR LHS '=' extra_consts ';'  */
#line 395 "parser.y"
                                                                                {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2282 "y.tab.c"
    break;

  case 112: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 396 "parser.y"
                                                                              {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2288 "y.tab.c"
    break;

  case 113: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 397 "parser.y"
                                                                               {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2294 "y.tab.c"
    break;

  case 114: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 398 "parser.y"
                                                                                  {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 2300 "y.tab.c"
    break;

  case 115: /* LHS: id  */
#line 401 "parser.y"
                                                     {
							// printf("%s\n", $1);
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
#line 2318 "y.tab.c"
    break;

  case 116: /* LHS: LHS ARROW id  */
#line 414 "parser.y"
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
#line 2374 "y.tab.c"
    break;

  case 117: /* declr_stmt: DECLR declr_body ';'  */
#line 467 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT");}
#line 2380 "y.tab.c"
    break;

  case 131: /* $@8: %empty  */
#line 490 "parser.y"
                                                         {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2386 "y.tab.c"
    break;

  case 135: /* $@9: %empty  */
#line 497 "parser.y"
                                                             {fprintf(fparse, " : CONDITIONAL STATEMENT");}
#line 2392 "y.tab.c"
    break;

  case 137: /* $@10: %empty  */
#line 500 "parser.y"
                                              {level++;}
#line 2398 "y.tab.c"
    break;

  case 138: /* switch_body: '{' $@10 cases DEFAULT ':' function_body '}'  */
#line 500 "parser.y"
                                                                                             {level--;}
#line 2404 "y.tab.c"
    break;

  case 223: /* call_stmt: func_calls ';'  */
#line 652 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1;}
#line 2410 "y.tab.c"
    break;


#line 2414 "y.tab.c"

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

#line 663 "parser.y"


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




