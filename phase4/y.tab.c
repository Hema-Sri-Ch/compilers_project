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
    FILE* fIR;
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
	char* LeftName;
	int arr_size=0;
	int dimA[20];
	int dimB[20];
	int dummy_size = 0;
	int newArr[20];
	/*
		MY ASSUMPTIONS:
			--> if it is parameter, only type check is feasible, but no attibute check non-standard datatypes
	*/
	
	void printTabs(){
		for(int i=0; i<level; i++){
			fprintf(fIR, "\t");
		}
	}
	
	
	int* splitStringToIntArray(const char* input, int* size) {
    	// Count the number of integers in the string
    	*size = 1; // At least one integer
    		for (const char* c = input; *c != '\0'; ++c) {
    	    if (*c == ',') {
    	        (*size)++;
    	    }
    	}
	
    	// Allocate memory for the integer array
    		int* result = (int*)malloc(*size * sizeof(int));
    	if (result == NULL) {
    	    // Memory allocation failure
    	    *size = 0;
    	    return NULL;
    		}
	
    	// Tokenize the string and convert tokens to integers
    	const char* delimiter = ", ";
    	char* token = strtok((char*)input, delimiter);
    	int i = 0;
	
    	while (token != NULL) {
    	    result[i++] = atoi(token);
    	    token = strtok(NULL, delimiter);
    	}

    	return result;
	}
	
	char** splitString(const char* input, const char* delimiter, size_t* count) {
    // Count the number of elements
    *count = 1; // at least one element even if the string is empty
    for (const char* c = input; *c != '\0'; ++c) {
        if (*c == delimiter[0]) {
            (*count)++;
        }
    }

    // Allocate memory for the array of strings
    char** result = (char**)malloc(*count * sizeof(char*));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy and tokenize the input string
    char* inputCopy = strdup(input); // Duplicate the input string
    char* token = strtok(inputCopy, delimiter);
    size_t i = 0;

    while (token != NULL) {
        result[i] = strdup(token); // Duplicate the token
        token = strtok(NULL, delimiter);
        i++;
    }

    free(inputCopy); // Free the duplicated input string

    return result;
}

void freeStringArray(char** array, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        free(array[i]);
    }
    free(array);
}

#line 196 "y.tab.c"

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
#line 126 "parser.y"

	char* str;
	struct{
		char* str;
		char* text;
	} Str;
	struct{
		char* text;
		char* name;
		char* type;
	} details;
	struct
	{
		int cols;
		char* text;
	} Cols;

#line 379 "y.tab.c"

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
  YYSYMBOL_79_3 = 79,                      /* $@3  */
  YYSYMBOL_class_item = 80,                /* class_item  */
  YYSYMBOL_struct = 81,                    /* struct  */
  YYSYMBOL_82_4 = 82,                      /* $@4  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_struct_items = 84,              /* struct_items  */
  YYSYMBOL_85_6 = 85,                      /* $@6  */
  YYSYMBOL_function = 86,                  /* function  */
  YYSYMBOL_function_head = 87,             /* function_head  */
  YYSYMBOL_func_definition = 88,           /* func_definition  */
  YYSYMBOL_Parameters = 89,                /* Parameters  */
  YYSYMBOL_fdtype = 90,                    /* fdtype  */
  YYSYMBOL_param_list = 91,                /* param_list  */
  YYSYMBOL_param = 92,                     /* param  */
  YYSYMBOL_dtype = 93,                     /* dtype  */
  YYSYMBOL_function_body = 94,             /* function_body  */
  YYSYMBOL_95_7 = 95,                      /* $@7  */
  YYSYMBOL_statements = 96,                /* statements  */
  YYSYMBOL_97_8 = 97,                      /* $@8  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_unary_stmt = 99,                /* unary_stmt  */
  YYSYMBOL_jump_stmt = 100,                /* jump_stmt  */
  YYSYMBOL_label_stmt = 101,               /* label_stmt  */
  YYSYMBOL_102_9 = 102,                    /* $@9  */
  YYSYMBOL_goto_stmt = 103,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 104,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 105,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 106,              /* remove_body  */
  YYSYMBOL_vect_append = 107,              /* vect_append  */
  YYSYMBOL_return_stmt = 108,              /* return_stmt  */
  YYSYMBOL_109_10 = 109,                   /* $@10  */
  YYSYMBOL_110_11 = 110,                   /* $@11  */
  YYSYMBOL_111_12 = 111,                   /* $@12  */
  YYSYMBOL_112_13 = 112,                   /* $@13  */
  YYSYMBOL_113_14 = 113,                   /* $@14  */
  YYSYMBOL_loop_stmt = 114,                /* loop_stmt  */
  YYSYMBOL_loop_type = 115,                /* loop_type  */
  YYSYMBOL_for_loop = 116,                 /* for_loop  */
  YYSYMBOL_117_15 = 117,                   /* $@15  */
  YYSYMBOL_118_16 = 118,                   /* $@16  */
  YYSYMBOL_for_in = 119,                   /* for_in  */
  YYSYMBOL_120_17 = 120,                   /* $@17  */
  YYSYMBOL_for_expr = 121,                 /* for_expr  */
  YYSYMBOL_for_RHS = 122,                  /* for_RHS  */
  YYSYMBOL_while_loop = 123,               /* while_loop  */
  YYSYMBOL_124_18 = 124,                   /* $@18  */
  YYSYMBOL_expr_stmt = 125,                /* expr_stmt  */
  YYSYMBOL_126_19 = 126,                   /* $@19  */
  YYSYMBOL_LHS = 127,                      /* LHS  */
  YYSYMBOL_myId = 128,                     /* myId  */
  YYSYMBOL_declr_stmt = 129,               /* declr_stmt  */
  YYSYMBOL_declr_body = 130,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 131,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 132,              /* matrix_list  */
  YYSYMBOL_id_list = 133,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 134,              /* ifcond_stmt  */
  YYSYMBOL_135_20 = 135,                   /* $@20  */
  YYSYMBOL_if_body = 136,                  /* if_body  */
  YYSYMBOL_137_21 = 137,                   /* $@21  */
  YYSYMBOL_switch_stmt = 138,              /* switch_stmt  */
  YYSYMBOL_139_22 = 139,                   /* $@22  */
  YYSYMBOL_switch_body = 140,              /* switch_body  */
  YYSYMBOL_141_23 = 141,                   /* $@23  */
  YYSYMBOL_142_24 = 142,                   /* $@24  */
  YYSYMBOL_cases = 143,                    /* cases  */
  YYSYMBOL_144_25 = 144,                   /* $@25  */
  YYSYMBOL_145_26 = 145,                   /* $@26  */
  YYSYMBOL_RHS = 146,                      /* RHS  */
  YYSYMBOL_constants = 147,                /* constants  */
  YYSYMBOL_extra_consts = 148,             /* extra_consts  */
  YYSYMBOL_array_const = 149,              /* array_const  */
  YYSYMBOL_val_list = 150,                 /* val_list  */
  YYSYMBOL_resultant = 151,                /* resultant  */
  YYSYMBOL_impr = 152,                     /* impr  */
  YYSYMBOL_graph_impr = 153,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 154,              /* matrix_impr  */
  YYSYMBOL_matr_body = 155,                /* matr_body  */
  YYSYMBOL_graph_const = 156,              /* graph_const  */
  YYSYMBOL_graph_type1 = 157,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 158,              /* graph_type2  */
  YYSYMBOL_int_list = 159,                 /* int_list  */
  YYSYMBOL_160_27 = 160,                   /* $@27  */
  YYSYMBOL_161_28 = 161,                   /* $@28  */
  YYSYMBOL_float_list = 162,               /* float_list  */
  YYSYMBOL_char_list = 163,                /* char_list  */
  YYSYMBOL_bool_list = 164,                /* bool_list  */
  YYSYMBOL_str_list = 165,                 /* str_list  */
  YYSYMBOL_weight_list = 166,              /* weight_list  */
  YYSYMBOL_vect_const = 167,               /* vect_const  */
  YYSYMBOL_vect_list = 168,                /* vect_list  */
  YYSYMBOL_vect_item = 169,                /* vect_item  */
  YYSYMBOL_matrix_const = 170,             /* matrix_const  */
  YYSYMBOL_int_float_list = 171,           /* int_float_list  */
  YYSYMBOL_mat_list = 172,                 /* mat_list  */
  YYSYMBOL_arith_op = 173,                 /* arith_op  */
  YYSYMBOL_binary_op = 174,                /* binary_op  */
  YYSYMBOL_unary_op = 175,                 /* unary_op  */
  YYSYMBOL_logical_op = 176,               /* logical_op  */
  YYSYMBOL_call_stmt = 177,                /* call_stmt  */
  YYSYMBOL_func_calls = 178,               /* func_calls  */
  YYSYMBOL_call_head = 179,                /* call_head  */
  YYSYMBOL_arguments = 180,                /* arguments  */
  YYSYMBOL_arg_list = 181                  /* arg_list  */
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
#define YYLAST   1033

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  253
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  492

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
       0,   206,   206,   209,   210,   213,   214,   215,   218,   231,
     218,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   254,
     254,   255,   258,   259,   263,   274,   262,   277,   277,   278,
     281,   291,   301,   329,   330,   334,   335,   339,   347,   351,
     400,   414,   415,   416,   417,   436,   463,   463,   464,   467,
     467,   468,   469,   470,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   487,   490,   491,   495,
     494,   509,   512,   515,   562,   600,   630,   663,   664,   665,
     666,   667,   668,   669,   673,   674,   679,   678,   735,   734,
     756,   755,   796,   795,   834,   874,   873,   899,   902,   903,
     906,   906,   906,   910,   910,   914,   915,   931,   932,   933,
     934,   935,   936,   939,   939,   955,   970,   969,  1054,  1069,
    1076,  1088,  1162,  1254,  1255,  1275,  1277,  1325,  1389,  1437,
    1491,  1541,  1606,  1629,  1652,  1677,  1701,  1714,  1722,  1722,
    1739,  1739,  1740,  1743,  1743,  1760,  1760,  1760,  1763,  1763,
    1764,  1764,  1769,  1770,  1771,  1772,  1773,  1777,  1778,  1779,
    1780,  1781,  1782,  1786,  1787,  1788,  1795,  1796,  1799,  1810,
    1817,  1819,  1821,  1823,  1825,  1828,  1829,  1830,  1831,  1832,
    1833,  1837,  1854,  1884,  1900,  1917,  1937,  1961,  1982,  2005,
    2014,  2028,  2045,  2063,  2082,  2093,  2094,  2097,  2098,  2101,
    2121,  2141,  2158,  2178,  2177,  2191,  2190,  2201,  2211,  2219,
    2229,  2237,  2247,  2255,  2265,  2273,  2286,  2296,  2308,  2320,
    2330,  2348,  2354,  2355,  2358,  2367,  2376,  2385,  2390,  2397,
    2409,  2424,  2425,  2428,  2474,  2494,  2528,  2546,  2551,  2576,
    2591,  2599,  2602,  2654
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
  "models", "model", "class", "$@1", "$@2", "id", "class_items", "$@3",
  "class_item", "struct", "$@4", "$@5", "struct_items", "$@6", "function",
  "function_head", "func_definition", "Parameters", "fdtype", "param_list",
  "param", "dtype", "function_body", "$@7", "statements", "$@8",
  "statement", "unary_stmt", "jump_stmt", "label_stmt", "$@9", "goto_stmt",
  "vect_stmt", "vect_stmt_body", "remove_body", "vect_append",
  "return_stmt", "$@10", "$@11", "$@12", "$@13", "$@14", "loop_stmt",
  "loop_type", "for_loop", "$@15", "$@16", "for_in", "$@17", "for_expr",
  "for_RHS", "while_loop", "$@18", "expr_stmt", "$@19", "LHS", "myId",
  "declr_stmt", "declr_body", "graph_and_array_list", "matrix_list",
  "id_list", "ifcond_stmt", "$@20", "if_body", "$@21", "switch_stmt",
  "$@22", "switch_body", "$@23", "$@24", "cases", "$@25", "$@26", "RHS",
  "constants", "extra_consts", "array_const", "val_list", "resultant",
  "impr", "graph_impr", "matrix_impr", "matr_body", "graph_const",
  "graph_type1", "graph_type2", "int_list", "$@27", "$@28", "float_list",
  "char_list", "bool_list", "str_list", "weight_list", "vect_const",
  "vect_list", "vect_item", "matrix_const", "int_float_list", "mat_list",
  "arith_op", "binary_op", "unary_op", "logical_op", "call_stmt",
  "func_calls", "call_head", "arguments", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-286)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-191)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   197,   197,   853,    69,  -286,    17,  -286,  -286,  -286,
      18,   -20,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
      33,    38,  -286,  -286,  -286,  -286,    16,  -286,   197,  -286,
    -286,  -286,    51,  -286,   294,  -286,  -286,  -286,   901,  -286,
    -286,   798,  -286,    35,  -286,   197,    24,    91,    57,   447,
      65,    67,    68,    75,    76,   949,   197,   197,    62,    78,
      80,    81,   197,    -7,   798,    85,    86,  -286,  -286,  -286,
    -286,  -286,    92,  -286,  -286,  -286,   141,  -286,  -286,  -286,
    -286,    84,  -286,  -286,  -286,    98,  -286,   100,    93,  -286,
     901,    99,   105,   107,  -286,  -286,   109,   110,  -286,  -286,
    -286,  -286,  -286,  -286,   111,   113,   118,   569,   715,    66,
     116,   119,    20,   121,  -286,   122,  -286,   117,   125,   127,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,   123,   715,  -286,
    -286,   715,   715,   197,   197,   197,   128,   197,   133,    13,
     141,   135,   136,  -286,  -286,  -286,   715,   715,   715,   138,
     715,   120,  -286,  -286,   798,  -286,   197,   479,  -286,  -286,
     656,  -286,  -286,   134,  -286,    24,  -286,    91,   715,   715,
    -286,   132,  -286,   141,  -286,  -286,   143,   144,   -25,  -286,
    -286,   177,  -286,  -286,  -286,  -286,  -286,    96,  -286,   140,
     145,   147,   148,   149,   150,    40,  -286,  -286,  -286,  -286,
    -286,   152,   153,   154,   142,   155,   157,   158,   160,   142,
     155,   901,  -286,   157,  -286,   508,  -286,   715,   161,   162,
    -286,   159,   166,  -286,   156,    18,  -286,  -286,   146,   170,
     173,   174,   193,   195,   196,   199,   200,   201,   203,   204,
     206,   209,   214,  -286,  -286,    44,  -286,   198,  -286,   217,
    -286,   221,   218,  -286,    34,  -286,  -286,  -286,   595,   715,
    -286,  -286,  -286,   -17,  -286,   212,   279,   280,   281,   285,
      96,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,   284,
     197,   197,   289,   197,   228,   236,   237,   239,   240,   241,
     272,   247,   715,   715,   715,  -286,  -286,   508,   745,   248,
     249,   254,   745,   255,   256,   745,   257,   745,   258,   259,
     745,   745,  -286,   715,  -286,  -286,   715,  -286,   317,     2,
       6,  -286,   261,   103,   264,  -286,  -286,  -286,  -286,  -286,
      15,    18,   267,   262,   265,  -286,   286,   266,   197,  -286,
    -286,  -286,  -286,  -286,   290,    -2,  -286,   291,   292,   293,
     295,  -286,  -286,  -286,  -286,   296,    20,   117,  -286,  -286,
     123,  -286,  -286,  -286,   297,  -286,  -286,   299,  -286,   263,
    -286,  -286,   283,   300,  -286,   302,   303,   357,   360,   309,
    -286,  -286,  -286,  -286,  -286,   311,   356,  -286,  -286,  -286,
    -286,   368,   310,   370,   157,  -286,  -286,   316,    18,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,   745,   745,   745,  -286,
     108,   312,  -286,   313,  -286,   377,  -286,  -286,   361,   318,
     380,   321,    18,  -286,  -286,   328,   329,   330,   331,   332,
     390,   335,   334,    18,   393,    94,  -286,   336,   338,  -286,
      49,  -286,  -286,  -286,  -286,  -286,   115,  -286,  -286,   395,
     339,  -286,   398,   197,  -286,  -286,   342,   344,   340,  -286,
    -286,   345,    22,  -286,  -286,    18,   341,    18,  -286,   978,
    -286,    18,   352,   343,  -286,   117,   346,   159,  -286,   123,
    -286,  -286
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    24,    23,    25,    26,    27,    28,
       0,     0,    51,    46,    52,    53,     0,    55,     0,    45,
       1,     3,    56,    40,     0,    41,     8,    34,     0,    42,
      58,     0,    43,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      23,     0,     0,   133,    63,     0,    59,    72,    69,    77,
      78,    73,   188,    71,    70,    64,   185,   131,    66,    67,
      68,     0,   189,   187,   186,     0,    65,   190,     0,    44,
       0,    49,     0,    29,    33,    32,     0,    37,    54,   167,
     168,   169,   170,   171,     0,     0,     0,     0,     0,     0,
     133,   188,   172,     0,   162,     0,   173,   166,   187,   186,
     174,   175,   176,   163,   241,   242,   164,   165,     0,    75,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,   107,   108,   109,     0,     0,     0,     0,
       0,     0,    62,    57,     0,    82,     0,     0,    76,   247,
       0,   248,    47,     0,     9,     0,    35,     0,     0,     0,
     105,   167,   177,   172,   232,   233,     0,     0,     0,   231,
     188,     0,   215,   218,   220,   224,   222,     0,   179,     0,
     180,   181,   182,   183,   184,     0,   104,    96,    98,   100,
     102,     0,     0,     0,   147,   140,   136,     0,   139,     0,
     137,     0,   147,   141,   135,     0,   110,     0,     0,     0,
     205,   206,     0,    81,     0,     0,    60,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,   252,     0,    50,     0,    30,     0,
      38,     0,     0,   106,     0,   207,   208,   229,     0,     0,
     216,   237,   238,     0,   178,     0,     0,     0,     0,     0,
       0,   234,    97,    99,   101,   103,   148,   153,   244,     0,
       0,     0,     0,     0,     0,   188,     0,     0,   187,   186,
       0,     0,     0,     0,     0,   134,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,    10,    36,     0,   246,     0,     0,
       0,   230,     0,     0,     0,   213,   217,   219,   221,   223,
       0,     0,     0,     0,     0,   146,     0,     0,     0,   130,
     125,   126,   128,   129,     0,     0,   123,     0,     0,     0,
       0,    94,    95,    87,    88,     0,    89,    93,    91,    92,
      90,   191,    85,    86,     0,   203,   193,     0,   194,     0,
     204,   199,     0,     0,   253,     0,     0,   210,   212,     0,
     245,   235,   236,   240,   214,     0,   152,   149,   155,   154,
     143,     0,     0,     0,   138,   127,   111,     0,     0,   195,
     197,   202,    83,    84,   192,   198,     0,     0,     0,   243,
       0,     0,   209,     0,   211,     0,   239,   150,     0,     0,
       0,     0,     0,   113,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,   112,
       0,   196,   200,   201,   226,   228,     0,   151,   160,     0,
       0,   145,     0,     0,   114,   115,     0,     0,     0,   158,
     156,     0,     0,   225,   227,     0,     0,     0,   144,     0,
     161,     0,     0,   121,   116,   119,   120,   122,   117,   118,
     159,   157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -286,  -286,   406,  -286,  -286,  -286,  -286,    11,   242,  -286,
    -286,  -286,  -286,  -286,   238,  -286,   -47,  -286,  -286,  -286,
    -286,  -286,   319,     5,   -10,  -286,   -54,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,   -49,  -228,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,   126,  -286,   -50,   250,   -38,
    -286,   273,  -286,  -140,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,     4,  -102,   -53,  -286,
    -286,  -286,   -40,   -55,   -56,   124,  -286,    45,    32,   306,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,   163,
    -286,   164,  -286,  -285,  -286,   -46,  -269,  -286,   -30,  -286,
    -286,  -286
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   257,   120,   102,   175,
     103,     8,    57,   259,   106,   177,     9,    10,    11,    45,
      38,    53,    54,    55,    74,    51,    75,   164,    76,    77,
      78,    79,   161,    80,    81,   190,   365,   360,    83,   282,
     283,   284,   285,   263,    84,   153,   154,   300,   432,   354,
     450,   464,   484,   155,   408,    85,   405,   122,    87,    88,
     148,   215,   218,   216,    89,   341,   397,   443,    90,   342,
     399,   428,   477,   445,   476,   468,   230,   124,   185,   126,
     199,    91,   127,    93,    94,   232,   130,   186,   187,   329,
     394,   270,   201,   202,   203,   204,   330,   131,   188,   189,
     132,   273,   205,   133,   134,   135,   136,    96,   137,    98,
     171,   255
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    86,    82,   129,   128,    95,   125,   223,    39,   104,
     121,    92,    30,    31,    37,   184,   149,   150,   105,   107,
     162,    97,   166,   368,    86,    82,   115,   368,    95,   166,
     368,   166,   368,   267,    92,   368,   368,   268,   192,   369,
      44,     1,     2,   369,    97,   333,   369,   334,   369,    49,
       3,   369,   369,    58,    65,    37,   160,     3,   118,    37,
     -79,   387,    73,   123,   275,   388,   101,   183,   389,    40,
     192,   193,   194,   195,   196,    42,   147,   333,    64,   395,
     463,    48,   225,   159,   374,    73,   407,   377,  -185,   379,
      46,   479,   382,   383,   328,    47,    99,   100,   151,   152,
     271,   272,   231,   280,   281,   322,   323,   391,   392,    50,
     236,    37,   438,   439,    86,    82,   459,   460,    95,   466,
     467,    65,   191,   108,    92,   138,   139,   140,   104,   197,
     198,   368,   368,   368,    97,   141,   142,   105,   156,   107,
     157,   158,   211,   163,   -61,   212,   213,   369,   369,   369,
     166,   165,   167,   170,   214,   217,   219,   168,   222,   169,
     228,   229,   173,   174,   234,   -31,   184,   176,   -39,   299,
     298,   178,   297,   179,   254,    73,   295,   180,   206,   160,
     207,   208,   261,   262,   209,  -189,   210,   235,   435,   436,
     437,  -190,   224,   221,   488,   226,   227,   233,   256,   264,
      12,   265,   266,   269,   274,   289,   307,   275,   404,   276,
     277,   278,   279,   286,   287,   288,   335,   290,   183,   291,
     305,   292,   293,   302,   303,   306,   294,  -186,   304,   296,
     308,   301,    37,   309,   310,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   231,    26,
      27,    28,    29,   311,   362,   312,   313,   324,   366,   314,
     315,   316,   366,   317,   318,   366,   319,   366,   367,   320,
     366,   366,   367,   332,   321,   367,   325,   367,   370,   327,
     367,   367,   370,   326,   336,   370,   337,   370,   343,   338,
     370,   370,   339,   346,   348,   349,   350,    12,   351,   352,
     353,   344,   345,    66,   347,    32,   357,   358,   356,   371,
     372,   361,    34,    35,    36,   373,   375,   376,   378,   380,
     381,   386,   390,   393,   398,   416,   400,   384,   401,   403,
     385,   396,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   417,    26,    27,    28,    29,
     402,   406,   409,   410,   411,    52,   412,   413,   414,   222,
     415,   421,   418,   419,   423,   420,   366,   366,   366,   425,
     426,   427,   429,   430,   431,   433,   367,   367,   367,   440,
     441,   442,   446,   444,   447,   448,   370,   370,   370,   451,
     452,   453,   454,   455,   192,   328,   456,   458,   434,   469,
     461,   462,   471,   473,   465,   474,   470,   475,   481,   478,
     491,  -188,    41,   472,  -187,   260,   237,   258,   220,   172,
     424,     0,   449,   487,   486,   200,   355,     0,   359,    86,
     483,   331,   422,   457,     0,     0,     0,     0,     0,   485,
       0,     0,     0,     0,   340,     0,     0,     0,     0,   489,
      12,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,   482,     0,     0,
       0,   490,     0,     0,   114,   115,    64,     0,     0,    67,
       0,     0,   116,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    70,    71,    26,
      27,    28,    29,     0,   117,     0,     0,   118,     0,     0,
     119,    12,   109,   110,   111,   112,   113,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,   249,   250,   251,   252,   114,   115,    64,     0,     0,
      67,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    69,    70,    71,
      26,    27,    28,    29,     0,   117,     0,     0,   118,     0,
       0,   119,    12,   181,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,   109,
     110,   111,   112,   113,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,     0,   117,   182,     0,     0,
       0,     0,   119,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,     0,   117,     0,     0,     0,     0,     0,   119,    12,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,    64,     0,     0,    67,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    69,    70,    71,    26,    27,
      28,    29,     0,     0,     0,     0,   118,   253,    12,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,    64,     0,     0,    67,    12,   363,
     364,     0,     0,    13,    14,    15,    16,    17,    18,    19,
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
     143,     0,     0,     0,     0,     0,     0,   144,   145,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,   114,     0,    64,     0,     0,
      67,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    69,    70,    71,
      26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
      10,    51,    51,    59,    59,    51,    59,   147,     3,    56,
      59,    51,     1,     2,     3,   117,    66,    67,    56,    57,
      74,    51,     9,   308,    74,    74,    28,   312,    74,     9,
     315,     9,   317,    58,    74,   320,   321,    62,     4,   308,
      60,    24,    25,   312,    74,    62,   315,    64,   317,    38,
      33,   320,   321,    48,    30,    44,    63,    33,    60,    48,
      67,    59,    51,    59,    62,    59,    55,   117,    62,     0,
       4,     5,     6,     7,     8,    57,    65,    62,    29,    64,
      31,    65,    69,    72,   312,    74,   355,   315,    68,   317,
      57,    69,   320,   321,    60,    57,    61,    62,    36,    37,
       4,     5,   158,    63,    64,    61,    62,     4,     5,    58,
     164,   100,     4,     5,   164,   164,    22,    23,   164,     4,
       5,    30,   118,    66,   164,    60,    59,    59,   175,    63,
      64,   416,   417,   418,   164,    60,    60,   175,    60,   177,
      60,    60,   138,    58,    58,   141,   142,   416,   417,   418,
       9,    59,    68,    60,   143,   144,   145,    59,   147,    59,
     156,   157,    63,    58,   160,    58,   268,    58,    58,   225,
     225,    60,   225,    60,   170,   164,   225,    59,    59,    63,
      59,    59,   178,   179,    59,    68,    59,    67,   416,   417,
     418,    68,    59,    65,   479,    60,    60,    59,    64,    67,
       3,    58,    58,    26,    64,    63,    60,    62,   348,    62,
      62,    62,    62,    61,    61,    61,     4,    62,   268,    62,
      64,    63,    62,    62,    62,   235,   221,    68,    62,   225,
      60,   227,   221,    60,    60,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   304,    52,
      53,    54,    55,    60,   307,    60,    60,    59,   308,    60,
      60,    60,   312,    60,    60,   315,    60,   317,   308,    60,
     320,   321,   312,   269,    60,   315,    59,   317,   308,    61,
     320,   321,   312,    62,     5,   315,     6,   317,     4,     8,
     320,   321,     7,     4,    66,    59,    59,     3,    59,    59,
      59,   290,   291,    31,   293,    11,   302,   303,    61,    61,
      61,   307,    18,    19,    20,    61,    61,    61,    61,    61,
      61,     4,    61,    59,    57,    62,    64,   323,    63,    63,
     326,   341,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    62,    52,    53,    54,    55,
      64,    61,    61,    61,    61,    61,    61,    61,    61,   348,
      61,     4,    62,    61,     4,    62,   416,   417,   418,    60,
      59,    15,     4,    63,     4,    59,   416,   417,   418,    67,
      67,     4,    64,    22,     4,    64,   416,   417,   418,    61,
      61,    61,    61,    61,     4,    60,    62,     4,   408,     4,
      64,    63,     4,    61,   450,    61,    67,    67,    67,    64,
      58,    68,     6,   463,    68,   177,   166,   175,   145,   100,
     388,    -1,   432,   479,   479,   119,   300,    -1,   304,   479,
     479,   268,   387,   443,    -1,    -1,    -1,    -1,    -1,   479,
      -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,   479,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,    -1,   477,    -1,    -1,
      -1,   481,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,
      63,     3,     4,     5,     6,     7,     8,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    53,    54,    55,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,    63,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    -1,    57,    58,    -1,    -1,
      -1,    -1,    63,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    63,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
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
       0,    24,    25,    33,    71,    72,    73,    74,    81,    86,
      87,    88,     3,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      77,    77,    11,    12,    18,    19,    20,    77,    90,    93,
       0,    72,    57,    94,    60,    89,    57,    57,    65,    77,
      58,    95,    61,    91,    92,    93,    75,    82,    93,    13,
      14,    16,    17,    21,    29,    30,    31,    32,    34,    49,
      50,    51,    56,    77,    94,    96,    98,    99,   100,   101,
     103,   104,   105,   108,   114,   125,   127,   128,   129,   134,
     138,   151,   152,   153,   154,   175,   177,   178,   179,    61,
      62,    77,    78,    80,    86,   129,    84,   129,    66,     4,
       5,     6,     7,     8,    27,    28,    35,    57,    60,    63,
      77,   105,   127,   146,   147,   148,   149,   152,   153,   154,
     156,   167,   170,   173,   174,   175,   176,   178,    60,    59,
      59,    60,    60,    11,    18,    19,    20,    77,   130,   127,
     127,    36,    37,   115,   116,   123,    60,    60,    60,    77,
      63,   102,    96,    58,    97,    59,     9,    68,    59,    59,
      60,   180,    92,    63,    58,    79,    58,    85,    60,    60,
      59,     4,    58,   127,   147,   148,   157,   158,   168,   169,
     105,   146,     4,     5,     6,     7,     8,    63,    64,   150,
     159,   162,   163,   164,   165,   172,    59,    59,    59,    59,
      59,   146,   146,   146,    77,   131,   133,    77,   132,    77,
     131,    65,    77,   133,    59,    69,    60,    60,   146,   146,
     146,   154,   155,    59,   146,    67,    96,   128,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    52,
      53,    54,    55,    61,   146,   181,    64,    76,    78,    83,
      84,   146,   146,   113,    67,    58,    58,    58,    62,    26,
     161,     4,     5,   171,    64,    62,    62,    62,    62,    62,
      63,    64,   109,   110,   111,   112,    61,    61,    61,    63,
      62,    62,    63,    62,    93,   105,   146,   148,   153,   154,
     117,   146,    62,    62,    62,    64,    94,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    62,    59,    59,    62,    61,    60,   159,
     166,   169,   146,    62,    64,     4,     5,     6,     8,     7,
     171,   135,   139,     4,    77,    77,     4,    77,    66,    59,
      59,    59,    59,    59,   119,   125,    61,   146,   146,   155,
     107,   146,   148,     4,     5,   106,   127,   152,   173,   176,
     178,    61,    61,    61,   106,    61,    61,   106,    61,   106,
      61,    61,   106,   106,   146,   146,     4,    59,    59,    62,
      61,     4,     5,    59,   160,    64,    94,   136,    57,   140,
      64,    63,    64,    63,   133,   126,    61,   176,   124,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    61,
      62,     4,   157,     4,   158,    60,    59,    15,   141,     4,
      63,     4,   118,    59,    94,   106,   106,   106,     4,     5,
      67,    67,     4,   137,    22,   143,    64,     4,    64,    94,
     120,    61,    61,    61,    61,    61,    62,    94,     4,    22,
      23,    64,    63,    31,   121,   175,     4,     5,   145,     4,
      67,     4,   127,    61,    61,    67,   144,   142,    64,    69,
      94,    67,    94,   105,   122,   152,   153,   154,   173,   178,
      94,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    75,    76,
      74,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    79,
      78,    78,    80,    80,    82,    83,    81,    85,    84,    84,
      86,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    95,    94,    94,    97,
      96,    96,    96,    96,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,   100,   100,   102,
     101,   103,   104,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   109,   108,   110,   108,
     111,   108,   112,   108,   108,   113,   108,   114,   115,   115,
     117,   118,   116,   120,   119,   121,   121,   122,   122,   122,
     122,   122,   122,   124,   123,   125,   126,   125,   125,   125,
     125,   127,   127,   128,   128,   129,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   135,   134,
     137,   136,   136,   139,   138,   141,   142,   140,   144,   143,
     145,   143,   146,   146,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   151,   151,   151,   151,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   153,   153,
     153,   153,   154,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158,   160,   159,   161,   159,   162,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   166,   166,   167,
     168,   168,   169,   169,   170,   171,   171,   171,   171,   172,
     172,   173,   173,   174,   175,   176,   176,   177,   178,   179,
     180,   180,   181,   181
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     0,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     1,     1,     0,     0,     8,     0,     3,     1,
       2,     2,     3,     2,     3,     1,     1,     3,     1,     2,
       4,     1,     1,     1,     4,     1,     0,     4,     2,     0,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     0,
       4,     3,     2,     6,     6,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     0,     4,     2,     1,     1,
       0,     0,     7,     0,     5,     1,     4,     1,     1,     1,
       1,     1,     1,     0,     6,     5,     0,     6,     5,     5,
       5,     1,     3,     1,     4,     3,     2,     2,     5,     2,
       2,     2,     6,     4,     9,     7,     3,     1,     0,     6,
       0,     4,     1,     0,     6,     0,     0,     8,     0,     6,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     6,     5,     5,     6,     8,     6,     6,     5,
       8,     8,     6,     5,     5,     1,     1,     3,     3,     5,
       4,     5,     4,     0,     4,     0,     2,     3,     1,     3,
       1,     3,     1,     3,     1,     7,     5,     7,     5,     3,
       3,     1,     1,     1,     3,     3,     3,     1,     1,     5,
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
#line 218 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							if(class_search((yyvsp[-1].Str).str)!=-1 || struct_search((yyvsp[-1].Str).str)!=-1)
							{
								printf("%d ERROR: Struct or class name already exists\n", yylineno);
								exit(1);
							}
								
							else class_insert((yyvsp[-1].Str).str);
							
							fprintf(fIR, "class %s {\n", (yyvsp[-1].Str).text);
							
						}
#line 2021 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 231 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; fprintf(fIR, "};\n");}
#line 2027 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 231 "parser.y"
                                                                                                                                        {fprintf(fparse, " : CLASS DEFINITION");}
#line 2033 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 234 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2039 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 235 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2045 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 236 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2051 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 237 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2057 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 238 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2063 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 239 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2069 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 240 "parser.y"
                                                     {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2075 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 241 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2081 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 242 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2087 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 243 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2093 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 244 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2099 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 245 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2105 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 246 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2111 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 247 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2117 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 248 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2123 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 249 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2129 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 250 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2135 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 251 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2141 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 254 "parser.y"
                                                     {fprintf(fIR, "\n");}
#line 2147 "y.tab.c"
    break;

  case 31: /* class_items: class_item  */
#line 255 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2153 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 263 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].Str).str)!=-1 || struct_search((yyvsp[-1].Str).str)!=-1)
								{
									printf("%d ERROR: Struct or class name already exists\n", yylineno);
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].Str).str);
								fprintf(fIR, "struct %s {\n", (yyvsp[-1].Str).text);
							}
#line 2169 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 274 "parser.y"
                                                                         { var_delete(level); level--; fprintf(fIR, "};\n");}
#line 2175 "y.tab.c"
    break;

  case 36: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 274 "parser.y"
                                                                                                                                 {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2181 "y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 277 "parser.y"
                                             {fprintf(fIR, "\n");}
#line 2187 "y.tab.c"
    break;

  case 39: /* struct_items: declr_stmt  */
#line 278 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2193 "y.tab.c"
    break;

  case 40: /* function: function_head function_body  */
#line 282 "parser.y"
                                                        {
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
								var_delete(level);
								level--;
							}
#line 2205 "y.tab.c"
    break;

  case 41: /* function_head: func_definition Parameters  */
#line 291 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
//							fprintf(fIR, ")\n");
						}
#line 2217 "y.tab.c"
    break;

  case 42: /* func_definition: FUNC fdtype id  */
#line 301 "parser.y"
                                                 {
							(yyval.details).name = (yyvsp[0].Str).str;
							(yyval.details).type = (yyvsp[-1].Str).str;
							if(inClass == 0) {
								int i = func_search((yyvsp[0].Str).str);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, (yyvsp[0].Str).str);
									exit(1);
								}
								func_insert((yyvsp[0].Str).str, (yyvsp[-1].Str).str);
								currentFuncIndex = func_size - 1;
							}
							else {
								int i = class_func_search((yyvsp[0].Str).str, class_size-1);
								if(i >= 0) {
									printf("%d ERROR : function name %s already declared\n", yylineno, (yyvsp[0].Str).str);
									exit(1);
								}
								class_func_insert(class_size-1, (yyvsp[0].Str).str, (yyvsp[-1].Str).str);
								currentFuncIndex = class_symb[class_size-1].cl_func_size - 1;
							}
							
							printTabs();
							fprintf(fIR, "%s %s ", (yyvsp[-1].Str).text, (yyvsp[0].Str).text);
							level++;
						}
#line 2248 "y.tab.c"
    break;

  case 43: /* Parameters: '(' ')'  */
#line 329 "parser.y"
                                                  {fprintf(fIR, "()\n");}
#line 2254 "y.tab.c"
    break;

  case 44: /* Parameters: '(' param_list ')'  */
#line 330 "parser.y"
                                                                     {fprintf(fIR, "( %s )\n", (yyvsp[-1].Str).text);}
#line 2260 "y.tab.c"
    break;

  case 45: /* fdtype: dtype  */
#line 334 "parser.y"
                                                {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2266 "y.tab.c"
    break;

  case 46: /* fdtype: VOID  */
#line 335 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text = (yyvsp[0].str);}
#line 2272 "y.tab.c"
    break;

  case 47: /* param_list: param_list ',' param  */
#line 339 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+strlen(", ")+1);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
//							free(myText);
						}
#line 2285 "y.tab.c"
    break;

  case 48: /* param_list: param  */
#line 347 "parser.y"
                                                       {(yyval.Str).text = (yyvsp[0].Str).text;}
#line 2291 "y.tab.c"
    break;

  case 49: /* param: dtype id  */
#line 351 "parser.y"
                                                   {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+strlen((yyvsp[0].Str).text)+2);
							strcpy(myText, (yyvsp[-1].Str).text);
							strcat(myText, " ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
//							free(myText);
							// fprintf(fIR, "%s %s ", $1.text, $2.text);
							if(inClass == 0) add_args((yyvsp[-1].Str).str);
							else class_add_args(class_size-1, (yyvsp[-1].Str).str);
							if(dataType == 0) var_insert(0, level, (yyvsp[0].Str).str, (yyvsp[-1].Str).str, "", -1, -1);
							else if(dataType == 2){
							
							
								char* myType = (char*)malloc(strlen((yyvsp[-1].Str).str)+1);
								strncpy(myType, (yyvsp[-1].Str).str + 1, strlen((yyvsp[-1].Str).str));
								myType[strlen((yyvsp[-1].Str).str)] = '\0';
								var_insert(0, level, (yyvsp[0].Str).str, "vect", myType, -1, -1);
								free(myType);
							}
							else if(dataType == 3) {
								var_insert(0, level, (yyvsp[0].Str).str, "matrix", "", -1, -1);
								(yyval.Str).text = "matrix";
							}
							else if(dataType == 4) {
								var_insert(0, level, (yyvsp[0].Str).str, "graph", "", -1, -1);
								(yyval.Str).text = "graph";
							}
							else if(dataType == 5){
								var_insert(0, level, (yyvsp[0].Str).str, (yyvsp[-1].Str).str, "", -1, -1);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+strlen((yyvsp[0].Str).text)+1);
								
								strcpy(myText, (yyvsp[-1].Str).text);
								strcat(myText, " ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
							else if(dataType == 6) {
								var_insert(0, level, (yyvsp[0].Str).str, (yyvsp[-1].Str).str, "", -1, -1);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+strlen((yyvsp[0].Str).text)+1);
							
								strcpy(myText, (yyvsp[-1].Str).text);
								strcat(myText, " ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
							

						}
#line 2345 "y.tab.c"
    break;

  case 50: /* param: dtype id '[' ']'  */
#line 400 "parser.y"
                                                                   {
							var_insert(0, level, (yyvsp[-2].Str).str, "array", (yyvsp[-3].Str).str, -1, -1);
							char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-2].Str).text)+4);
							strcpy(myText, (yyvsp[-3].Str).text);
							strcat(myText, " ");
							strcat(myText, (yyvsp[-2].Str).text);
							char* A = "[]";
							strcat(myText, A);
							(yyval.Str).text = myText;
						}
#line 2360 "y.tab.c"
    break;

  case 51: /* dtype: DATATYPE  */
#line 414 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str); dataType = 0;}
#line 2366 "y.tab.c"
    break;

  case 52: /* dtype: MATRIX  */
#line 415 "parser.y"
                                                         {(yyval.Str).str = (yyvsp[0].str); dataType = 3; (yyval.Str).text = "matrix";}
#line 2372 "y.tab.c"
    break;

  case 53: /* dtype: GRAPH  */
#line 416 "parser.y"
                                                        {(yyval.Str).str = (yyvsp[0].str); dataType = 4; (yyval.Str).text = "graph";}
#line 2378 "y.tab.c"
    break;

  case 54: /* dtype: VECT '<' dtype '>'  */
#line 417 "parser.y"
                                                                     { 
							char* result;
							char* A = "*";
						    result = (char*)malloc(strlen(A) + strlen((yyvsp[-1].Str).str) + 1);
						    strcpy(result, A);
						    strcat(result, (yyvsp[-1].Str).str);
						    dataType = 2;
						    (yyval.Str).str = result;
						    
						    
						    char* myText = (char*)malloc(strlen("vector<>")+strlen((yyvsp[-1].Str).text)+1);
						    char* B = "vector<";
						    strcpy(myText, B);
						    strcat(myText, (yyvsp[-1].Str).text);
						    strcat(myText, ">");
						    (yyval.Str).text = myText;
//						    free(result);
//						    free(myText);
						}
#line 2402 "y.tab.c"
    break;

  case 55: /* dtype: id  */
#line 436 "parser.y"
                                                     {
							int i = struct_search((yyvsp[0].Str).str);
							if(i < 0) {
								i = class_search((yyvsp[0].Str).str);
								if(i < 0){
									printf("%d Error: Using undefined datatype %s\n", yylineno, (yyvsp[0].Str).str);
								}
								else{
									dataType = 6;
									(yyval.Str).str = (yyvsp[0].Str).str;
									char* myText = (char*)malloc(strlen("class ")+strlen((yyvsp[0].Str).text)+1);
									strcpy(myText, "class ");
									strcat(myText, (yyvsp[0].Str).text);
									(yyval.Str).text = myText;
								}
							}
							else{
								dataType = 5;
								(yyval.Str).str = (yyvsp[0].Str).str;
								char* myText = (char*)malloc(strlen("struct ")+strlen((yyvsp[0].Str).text)+1);
								strcpy(myText, "struct ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
						}
#line 2432 "y.tab.c"
    break;

  case 56: /* $@7: %empty  */
#line 463 "parser.y"
                                      {printTabs(); level++; fprintf(fIR, "{\n");}
#line 2438 "y.tab.c"
    break;

  case 57: /* function_body: '{' $@7 statements '}'  */
#line 463 "parser.y"
                                                                                                  {var_delete(level); level--; printTabs(); fprintf(fIR, "}\n");}
#line 2444 "y.tab.c"
    break;

  case 58: /* function_body: '{' '}'  */
#line 464 "parser.y"
                                                          { printTabs(); fprintf(fIR, "{ }\n");}
#line 2450 "y.tab.c"
    break;

  case 59: /* $@8: %empty  */
#line 467 "parser.y"
                                                    {fprintf(fIR, "\n");}
#line 2456 "y.tab.c"
    break;

  case 61: /* statements: statement  */
#line 468 "parser.y"
                                                            {fprintf(fIR, "\n");}
#line 2462 "y.tab.c"
    break;

  case 71: /* statement: return_stmt  */
#line 480 "parser.y"
                                                              {fprintf(fparse," : RETURN STATEMENT");}
#line 2468 "y.tab.c"
    break;

  case 74: /* statement: BREAK ';'  */
#line 483 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2474 "y.tab.c"
    break;

  case 75: /* statement: CONTINUE ';'  */
#line 484 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2480 "y.tab.c"
    break;

  case 76: /* unary_stmt: unary_op ';'  */
#line 487 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT"); printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text);}
#line 2486 "y.tab.c"
    break;

  case 79: /* $@9: %empty  */
#line 495 "parser.y"
                                                        {
								if(label_search((yyvsp[0].Str).str)!=-1) 
								{
									printf("%d ERROR: Label name already exists\n", yylineno);
									exit(1);
								}
								else label_insert((yyvsp[0].Str).str);
								
								printTabs();
								fprintf(fIR, "%s: ", (yyvsp[0].Str).text);
							}
#line 2502 "y.tab.c"
    break;

  case 80: /* label_stmt: id $@9 ':' function_body  */
#line 506 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2508 "y.tab.c"
    break;

  case 81: /* goto_stmt: GOTO id ';'  */
#line 509 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT"); printTabs(); fprintf(fIR, "goto %s;", (yyvsp[-1].Str).text);}
#line 2514 "y.tab.c"
    break;

  case 82: /* vect_stmt: vect_stmt_body ';'  */
#line 512 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2520 "y.tab.c"
    break;

  case 83: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 515 "parser.y"
                                                                            { 
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if((yyvsp[-5].Str).str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								char* myType = (char*)malloc(strlen((yyvsp[-5].Str).str)+1);
								strncpy(myType, (yyvsp[-5].Str).str + 1, strlen((yyvsp[-5].Str).str));
								myType[strlen((yyvsp[-5].Str).str)] = '\0';
								if(strcmp(myType, (yyvsp[-1].Str).str)){
									int a = !strcmp(myType, "float") && (!strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "bool"));
									int b = !strcmp(myType, "int") && (!strcmp((yyvsp[-1].Str).str, "bool"));
									int c = !strcmp(myType, "bool") && (!strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "char") || !strcmp((yyvsp[-1].Str).str, "string"));
									if(!(a || b || c)){
										printf("%d ERROR: appending the wrong dtype; expected %s; given %s\n", yylineno, myType, (yyvsp[-1].Str).str);
										free(myType);
										exit(1);
									}
								}
								
								else{
									// printf("%d::resultant: %s; appending: %s\n", yylineno, $1, $5);
									(yyval.Str).str = (yyvsp[-5].Str).str;
									
								}
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, (yyvsp[-5].Str).text);
								strcat(myText, ";temp.push_back(");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ");");
								strcat(myText, (yyvsp[-5].Str).text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								(yyval.Str).text = (yyvsp[-5].Str).text;
								
								free(myType);
								free(myText);
							}
							
						}
#line 2572 "y.tab.c"
    break;

  case 84: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 562 "parser.y"
                                                                                           {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if((yyvsp[-5].Str).str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							
							else{
								if(!(!strcmp("int", (yyvsp[-1].Str).str) || !strcmp("float", (yyvsp[-1].Str).str) || !strcmp("bool", (yyvsp[-1].Str).str))){
									printf("%d ERROR: providing invalid index type %s to vector remove\n", yylineno, (yyvsp[-1].Str).str);
									exit(1);
								} else {
									(yyval.Str).str = (yyvsp[-5].Str).str;
									
									char* myType = (char*)malloc(strlen((yyvsp[-5].Str).str)+1);
									strncpy(myType, (yyvsp[-5].Str).str + 1, strlen((yyvsp[-5].Str).str));
									myType[strlen((yyvsp[-5].Str).str)] = '\0';
								
								
									char* myText = (char*)malloc(512);
									strcpy(myText, "{vector<");
									strcat(myText, myType);
									strcat(myText, "> temp = ");
									strcat(myText, (yyvsp[-5].Str).text);
									strcat(myText, ";temp.erase(temp.begin()+");
									strcat(myText, (yyvsp[-1].Str).text);
									strcat(myText, ");");
									strcat(myText, (yyvsp[-5].Str).text);
									strcat(myText, " = temp;}");
									printTabs();
									fprintf(fIR, "%s\n", myText);
									(yyval.Str).text = (yyvsp[-5].Str).text;
									
									free(myType);
									free(myText);
								}
							}
						}
#line 2615 "y.tab.c"
    break;

  case 85: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 600 "parser.y"
                                                                             {
							// printf("%d::Initial resultant - %s\n",yylineno, $1);
							if((yyvsp[-4].Str).str[0] != '*'){
								printf("%d Error: invalid type for sort\n", yylineno);
								exit(1);
							}
							else {
								(yyval.Str).str = (yyvsp[-4].Str).str;
								
								char* myType = (char*)malloc(strlen((yyvsp[-4].Str).str)+1);
								strncpy(myType, (yyvsp[-4].Str).str + 1, strlen((yyvsp[-4].Str).str));
								myType[strlen((yyvsp[-4].Str).str)] = '\0';
								
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ";sort(temp.begin(), temp.end());");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								(yyval.Str).text = (yyvsp[-4].Str).text;
								
								free(myType);
								free(myText);
							}
						}
#line 2650 "y.tab.c"
    break;

  case 86: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 630 "parser.y"
                                                                              {
							// printf("%d::Initial resultant - %s\n", yylineno, $1);
							if((yyvsp[-4].Str).str[0] != '*'){
								printf("%d Error: invalid type for clear\n", yylineno);
								exit(1);
							}
							else{
								(yyval.Str).str = (yyvsp[-4].Str).str;
								
								char* myType = (char*)malloc(strlen((yyvsp[-4].Str).str)+1);
								strncpy(myType, (yyvsp[-4].Str).str + 1, strlen((yyvsp[-4].Str).str));
								myType[strlen((yyvsp[-4].Str).str)] = '\0';
								
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{vector<");
								strcat(myText, myType);
								strcat(myText, "> temp = ");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ";temp.clear();");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, " = temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								(yyval.Str).text = (yyvsp[-4].Str).text;
								
								free(myType);
								free(myText);
							}
						}
#line 2685 "y.tab.c"
    break;

  case 87: /* remove_body: INT_CONST  */
#line 663 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 2691 "y.tab.c"
    break;

  case 88: /* remove_body: FLOAT_CONST  */
#line 664 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 2697 "y.tab.c"
    break;

  case 89: /* remove_body: LHS  */
#line 665 "parser.y"
                                                      {(yyval.Str).str=(yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 2703 "y.tab.c"
    break;

  case 90: /* remove_body: func_calls  */
#line 666 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2709 "y.tab.c"
    break;

  case 91: /* remove_body: arith_op  */
#line 667 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2715 "y.tab.c"
    break;

  case 92: /* remove_body: logical_op  */
#line 668 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2721 "y.tab.c"
    break;

  case 93: /* remove_body: impr  */
#line 669 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2727 "y.tab.c"
    break;

  case 94: /* vect_append: RHS  */
#line 673 "parser.y"
                                              {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2733 "y.tab.c"
    break;

  case 95: /* vect_append: extra_consts  */
#line 674 "parser.y"
                                                               {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2739 "y.tab.c"
    break;

  case 96: /* $@10: %empty  */
#line 679 "parser.y"
                                                        {	returnStmtCount++;
							
								if(inClass == 0){
									char* A = (yyvsp[-1].Str).str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = (yyvsp[-1].Str).str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								
								}
								printTabs();
								fprintf(fIR, "return %s;", (yyvsp[-1].Str).text);
							
							/*	if(inClass==0)
								{		
									if(strcmp($2.str,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								else
								{
									if(strcmp($2.str,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}*/
							}
#line 2798 "y.tab.c"
    break;

  case 97: /* return_stmt: RETURN RHS ';' $@10  */
#line 733 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2804 "y.tab.c"
    break;

  case 98: /* $@11: %empty  */
#line 735 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass==0)
								{
									if(strcmp((yyvsp[-1].Str).str,func_symb[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n", yylineno);
									}
								}
								else
								{
									if(strcmp((yyvsp[-1].Str).str,class_symb[class_size-1].func_list[currentFuncIndex].type))
									{
										printf("%d ERROR : func type and return type are mismatched\n",yylineno);
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", (yyvsp[-1].Str).text);
						 	}
#line 2828 "y.tab.c"
    break;

  case 99: /* return_stmt: RETURN extra_consts ';' $@11  */
#line 754 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2834 "y.tab.c"
    break;

  case 100: /* $@12: %empty  */
#line 756 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass == 0){
									char* A = (yyvsp[-1].Str).str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = (yyvsp[-1].Str).str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", (yyvsp[-1].Str).text);
						 	}
#line 2877 "y.tab.c"
    break;

  case 101: /* return_stmt: RETURN graph_impr ';' $@12  */
#line 794 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2883 "y.tab.c"
    break;

  case 102: /* $@13: %empty  */
#line 796 "parser.y"
                                                        {	returnStmtCount++;
								if(inClass == 0){
									char* A = (yyvsp[-1].Str).str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = (yyvsp[-1].Str).str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								printTabs();
								fprintf(fIR, "return %s;", (yyvsp[-1].Str).text);
							}
#line 2925 "y.tab.c"
    break;

  case 103: /* return_stmt: RETURN matrix_impr ';' $@13  */
#line 833 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2931 "y.tab.c"
    break;

  case 104: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 835 "parser.y"
                                                {	returnStmtCount++;
							if(inClass == 0){
									char* A = (yyvsp[-1].Str).str;
									char* B = func_symb[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								else {
									char* A = (yyvsp[-1].Str).str;
									char* B = class_symb[class_size-1].func_list[currentFuncIndex].type;
									
									if(strcmp(A, B)){
										int a = !strcmp(A, "int") || !strcmp(A, "float") || !strcmp(A, "bool");
										int b = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool");
										
										int c = !strcmp(A, "bool");
										int d = !strcmp(B, "int") || !strcmp(B, "float") || !strcmp(B, "bool") || !strcmp(B, "char") || !strcmp(B, "string");
										
										if(!(a&&b  ||  c&&d) ){
											printf("%d Warning: return type mismatched\n", yylineno);
										}
									}
								}
								
								printTabs();
								fprintf(fIR, "return %s;", (yyvsp[-1].Str).text);
						}
#line 2974 "y.tab.c"
    break;

  case 105: /* $@14: %empty  */
#line 874 "parser.y"
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
								
								printTabs();
								fprintf(fIR, "return NULL;");
							}
#line 2998 "y.tab.c"
    break;

  case 106: /* return_stmt: RETURN null ';' $@14  */
#line 893 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3004 "y.tab.c"
    break;

  case 107: /* loop_stmt: LOOP loop_type  */
#line 899 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 3010 "y.tab.c"
    break;

  case 110: /* $@15: %empty  */
#line 906 "parser.y"
                                                  {printTabs(); fprintf(fIR, "for(");}
#line 3016 "y.tab.c"
    break;

  case 111: /* $@16: %empty  */
#line 906 "parser.y"
                                                                                                 {fprintf(fIR, ") ");}
#line 3022 "y.tab.c"
    break;

  case 113: /* $@17: %empty  */
#line 910 "parser.y"
                                                                   {fprintf(fIR, "%s; ", (yyvsp[-1].Str).text);}
#line 3028 "y.tab.c"
    break;

  case 115: /* for_expr: unary_op  */
#line 914 "parser.y"
                                                   {fprintf(fIR, "%s ", (yyvsp[0].Str).text);}
#line 3034 "y.tab.c"
    break;

  case 116: /* for_expr: EXPR LHS '=' for_RHS  */
#line 915 "parser.y"
                                                                       {
							if(strcmp((yyvsp[-2].details).type, (yyvsp[0].Str).str)){
								int a = !strcmp((yyvsp[-2].details).type, "int") || !strcmp((yyvsp[-2].details).type, "float") || !strcmp((yyvsp[-2].details).type, "bool");
								int b = !strcmp((yyvsp[0].Str).str, "int") || !strcmp((yyvsp[0].Str).str, "float") || !strcmp((yyvsp[0].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
								
								fprintf(fIR, "%s = %s", (yyvsp[-2].details).text, (yyvsp[0].Str).text);
							}
						}
#line 3052 "y.tab.c"
    break;

  case 117: /* for_RHS: arith_op  */
#line 931 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3058 "y.tab.c"
    break;

  case 118: /* for_RHS: func_calls  */
#line 932 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3064 "y.tab.c"
    break;

  case 119: /* for_RHS: impr  */
#line 933 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3070 "y.tab.c"
    break;

  case 120: /* for_RHS: graph_impr  */
#line 934 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3076 "y.tab.c"
    break;

  case 121: /* for_RHS: vect_stmt_body  */
#line 935 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3082 "y.tab.c"
    break;

  case 122: /* for_RHS: matrix_impr  */
#line 936 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3088 "y.tab.c"
    break;

  case 123: /* $@18: %empty  */
#line 939 "parser.y"
                                                          {
							int a = !strcmp((yyvsp[-1].Str).str, "int") || 
									!strcmp((yyvsp[-1].Str).str, "float") || 
									!strcmp((yyvsp[-1].Str).str, "bool") ||
									!strcmp((yyvsp[-1].Str).str, "string") ||
									!strcmp((yyvsp[-1].Str).str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "while(%s) ", (yyvsp[-1].Str).text);
						}
#line 3106 "y.tab.c"
    break;

  case 125: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 955 "parser.y"
                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
								int a = !strcmp((yyvsp[-3].details).type, "int") || !strcmp((yyvsp[-3].details).type, "float") || !strcmp((yyvsp[-3].details).type, "bool");
								int b = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3125 "y.tab.c"
    break;

  case 126: /* $@19: %empty  */
#line 970 "parser.y"
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
									printTabs();
									fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
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
									printTabs();
									fprintf(fIR, "%s.vals = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
								}
								else if(strcmp("array", (yyvsp[-3].details).type)==0)
								{
									if(strcmp(element_type, (yyvsp[-1].Str).str)!=0 && strcmp((yyvsp[-1].Str).str, "any")!=0)
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
									printTabs();
									fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
								}
								
								else if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
									printf("%d Error: Expression statement type mismatch %s != %s\n", yylineno, (yyvsp[-3].details).type, (yyvsp[-1].Str).str);
									exit(1);
								}
								
								else{
									printTabs();
									fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
								}
								
								
							}
#line 3212 "y.tab.c"
    break;

  case 127: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@19  */
#line 1052 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 3218 "y.tab.c"
    break;

  case 128: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 1054 "parser.y"
                                                                              {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
								int a = !strcmp((yyvsp[-3].details).type, "int") || !strcmp((yyvsp[-3].details).type, "float") || !strcmp((yyvsp[-3].details).type, "bool");
								int b = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3238 "y.tab.c"
    break;

  case 129: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 1069 "parser.y"
                                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3250 "y.tab.c"
    break;

  case 130: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 1076 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
						}
#line 3264 "y.tab.c"
    break;

  case 131: /* LHS: myId  */
#line 1088 "parser.y"
                                                       {
							classIndex = -1;
							int i = var_search((yyvsp[0].Str).str);
							int j, l;
							if(inClass) j = class_declr_search((yyvsp[0].Str).str, class_size-1);
							else j = -1;
							int k = func_search((yyvsp[0].Str).str);
							if(inClass) l = class_func_search((yyvsp[0].Str).str, class_size-1);
							else l = -1;
							
							if(i<0 && j<0 && k<0 && l<0){
								printf("%d Error: Accessing undeclared identifier/function %s\n", yylineno, (yyvsp[0].Str).str);
							}
							
							// class declare variable (class attirbute)
							if(j>=0) {
								(yyval.details).name = (yyvsp[0].Str).str;
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
								// printf("%s : %s\n", $$.name, $$.type);
								classIndex=class_size-1;
							}
							
							// declare variable
							else if(i>=0){
								(yyval.details).name = (yyvsp[0].Str).str;
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
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// class function
							else if(l >= 0){
								(yyval.details).name = (yyvsp[0].Str).str;
								(yyval.details).type = class_symb[class_size-1].func_list[l].type;
								classIndex = class_size-1;
								funcIndex = l;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// normal funciton
							else if(k >= 0){
								(yyval.details).name = (yyvsp[0].Str).str;
								(yyval.details).type = func_symb[k].type;
								funcIndex = k;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// printf("%d:: LHS.name - %s; LHS.type - %s\n", yylineno, $$.name, $$.type);
							
							(yyval.details).text = (yyvsp[0].Str).text;
							LeftName = (yyvsp[0].Str).text;
							
						}
#line 3343 "y.tab.c"
    break;

  case 132: /* LHS: LHS ARROW myId  */
#line 1162 "parser.y"
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
									
									int j = class_declr_search((yyvsp[0].Str).str, i);
									int k = class_func_search((yyvsp[0].Str).str, i);
									if(j < 0 && k < 0){
										printf("%d Error: Accessing undefined function/attribute %s of class %s\n", yylineno,(yyvsp[0].Str).str, (yyvsp[-2].details).type);
										// printClassNode(class_symb[i]);
										exit(1);
									}
									
									if(j >= 0){
										(yyval.details).name = (yyvsp[0].Str).str;
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
										(yyval.details).name = (yyvsp[0].Str).str;
										(yyval.details).type = "func"; // can be ignored
									}
								}
							}
							
							else {
								// item defined in struct, now check its attributes
								int j = struct_declr_search((yyvsp[0].Str).str, i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("%d Error: Accessing undefined attribute of struct %s\n", yylineno, (yyvsp[-2].details).name);
									exit(1);
								}
								
								else{
									(yyval.details).name = (yyvsp[0].Str).str;
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
							
							char* myText = (char*)malloc(strlen((yyvsp[-2].details).text)+strlen((yyvsp[0].Str).text)+2);
							strcpy(myText, (yyvsp[-2].details).text);
							strcat(myText, ".");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.details).text = myText;
							LeftName = (yyvsp[-2].details).text;
						}
#line 3437 "y.tab.c"
    break;

  case 133: /* myId: id  */
#line 1254 "parser.y"
                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3443 "y.tab.c"
    break;

  case 134: /* myId: id '[' RHS ']'  */
#line 1255 "parser.y"
                                                                {
							int a = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float");
							if(!a){
								printf("%d Error: invalid array index\n", yylineno);
								exit(1);
							}
							(yyval.Str).str = (yyvsp[-3].Str).str;
							
							char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].Str).text)+3);
							strcpy(myText, (yyvsp[-3].Str).text);
							strcat(myText, "[");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, "]");
							(yyval.Str).text = myText;
						}
#line 3463 "y.tab.c"
    break;

  case 135: /* declr_stmt: DECLR declr_body ';'  */
#line 1275 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT"); fprintf(fIR, ";");}
#line 3469 "y.tab.c"
    break;

  case 136: /* declr_body: DATATYPE id_list  */
#line 1278 "parser.y"
                                                        {
								if(currentFuncIndex!=-1) // inside class and inside function
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
								else if(inClass==1) // inside class outside function
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
								else // independent function
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
								printTabs();
								fprintf(fIR, "%s %s", (yyvsp[-1].str), (yyvsp[0].Str).text);
								
							}
#line 3521 "y.tab.c"
    break;

  case 137: /* declr_body: GRAPH graph_and_array_list  */
#line 1326 "parser.y"
                                                        {
								if(currentFuncIndex!=-1) // inside class and inside function
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
									for(int i=0; i<strlen((yyvsp[0].Str).text); i++){
										if((yyvsp[0].Str).text[i] == '[') (yyvsp[0].Str).text[i] = '(';
										
										if((yyvsp[0].Str).text[i] == ']') (yyvsp[0].Str).text[i] = ')';
									}
								}
								else if(inClass==1) // inside class outside function
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
									printTabs();
									for(int i=0; i<strlen((yyvsp[0].Str).text); i++){
										if((yyvsp[0].Str).text[i] == '[') (yyvsp[0].Str).text[i] = '{';
									
										if((yyvsp[0].Str).text[i] == ']') (yyvsp[0].Str).text[i] = '}';
									}
								}
								else // independent function
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
									for(int i=0; i<strlen((yyvsp[0].Str).text); i++){
									if((yyvsp[0].Str).text[i] == '[') (yyvsp[0].Str).text[i] = '(';
									
									if((yyvsp[0].Str).text[i] == ']') (yyvsp[0].Str).text[i] = ')';
								}
								}
								arr_size=0;
								
								printTabs();
								fprintf(fIR, "graph %s", (yyvsp[0].Str).text);
							}
#line 3589 "y.tab.c"
    break;

  case 138: /* declr_body: VECT '<' dtype '>' id_list  */
#line 1390 "parser.y"
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
										var_insert(1, level, arr[i], (yyvsp[-4].str), (yyvsp[-2].Str).str, -1, -1);
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
										add_class_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].Str).str, -1, -1);
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
										add_struct_declrs(arr[i], (yyvsp[-4].str), 1, level, (yyvsp[-2].Str).str, -1, -1);
									}
								}
								arr_size=0;
								printTabs();
								fprintf(fIR, "vector<%s> %s", (yyvsp[-2].Str).text, (yyvsp[0].Str).text);
								
							}
#line 3641 "y.tab.c"
    break;

  case 139: /* declr_body: MATRIX matrix_list  */
#line 1438 "parser.y"
                                                        {
								if(currentFuncIndex!=-1) // inside class and inside function
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
								else if(inClass==1) // inside class and outside function
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
									
									
									for(int i=0; i<strlen((yyvsp[0].Str).text); i++){
										if((yyvsp[0].Str).text[i] == '(') (yyvsp[0].Str).text[i] = '{';
										if((yyvsp[0].Str).text[i] == ')') (yyvsp[0].Str).text[i] = '}';
									}
								}
								else // independent function
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
								printTabs();
								fprintf(fIR, "matrix %s", (yyvsp[0].Str).text);
							}
#line 3699 "y.tab.c"
    break;

  case 140: /* declr_body: DATATYPE graph_and_array_list  */
#line 1492 "parser.y"
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
								printTabs();
								fprintf(fIR, "%s %s", (yyvsp[-1].str), (yyvsp[0].Str).text);
								
								
								
							}
#line 3753 "y.tab.c"
    break;

  case 141: /* declr_body: id id_list  */
#line 1542 "parser.y"
                                                        {
								if(class_search((yyvsp[-1].Str).str)!=-1 || struct_search((yyvsp[-1].Str).str)!=-1)
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
											var_insert(1, level, arr[i], (yyvsp[-1].Str).str, "", -1, -1);
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
											add_class_declrs(arr[i], (yyvsp[-1].Str).str, 1, level, "", -1, -1);
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
											add_struct_declrs(arr[i], (yyvsp[-1].Str).str, 1, level, "", -1, -1);
										}
									}
									arr_size =0;
									printTabs();
									{
										int a = class_search((yyvsp[-1].Str).str);
										int b = struct_search((yyvsp[-1].Str).str);
										if(a > b) fprintf(fIR, "class %s ", (yyvsp[-1].Str).text);
										else fprintf(fIR, "struct %s ", (yyvsp[-1].Str).text);
									}
									
									fprintf(fIR, "%s", (yyvsp[0].Str).text);
								}
								else
								{
									arr_size=0;
									printf("%d ERROR: No struct or class with that name is defined\n", yylineno);
									exit(1);
								}
							}
#line 3820 "y.tab.c"
    break;

  case 142: /* graph_and_array_list: graph_and_array_list ',' id '[' INT_CONST ']'  */
#line 1607 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-3].Str).str;
								dimA[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-5].Str).text)+strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+5);
								strcpy(myText, (yyvsp[-5].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, "[");
								strcat(myText, (yyvsp[-1].str));
								strcat(myText, "], ");
								
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 3847 "y.tab.c"
    break;

  case 143: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 1630 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-3].Str).str;
								dimA[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0)
								{
									printf("%d ERROR: Dimension(s) has to be greater than 0\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, "[");
								strcat(myText, (yyvsp[-1].str));
								strcat(myText, "]");
								
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 3872 "y.tab.c"
    break;

  case 144: /* matrix_list: matrix_list ',' id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1653 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								dimA[arr_size] = atoi((yyvsp[-4].str));
								dimB[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-8].Str).text)+strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].str))+strlen((yyvsp[-1].str))+7);
								strcpy(myText, (yyvsp[-8].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].str));
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].str));
								strcat(myText, ")");
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 3901 "y.tab.c"
    break;

  case 145: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1678 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								dimA[arr_size] = atoi((yyvsp[-4].str));
								dimB[arr_size] = atoi((yyvsp[-1].str));
								if(dimA[arr_size]<=0 || dimB[arr_size]<=0)
								{
									printf("%d ERROR: No of rows or columns has to be positive\n", yylineno);
									exit(1);
								}
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].str))+strlen((yyvsp[-1].str))+5);
								strcpy(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].str));
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].str));
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
							}
#line 3927 "y.tab.c"
    break;

  case 146: /* id_list: id_list ',' id  */
#line 1702 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].Str).str;
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+2);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].Str).text);
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 3944 "y.tab.c"
    break;

  case 147: /* id_list: id  */
#line 1715 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].Str).str;
								arr_size++;
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 3954 "y.tab.c"
    break;

  case 148: /* $@20: %empty  */
#line 1722 "parser.y"
                                                         {
							int a = !strcmp((yyvsp[-1].Str).str, "int") || 
									!strcmp((yyvsp[-1].Str).str, "float") || 
									!strcmp((yyvsp[-1].Str).str, "bool") ||
									!strcmp((yyvsp[-1].Str).str, "string") ||
									!strcmp((yyvsp[-1].Str).str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "if(%s)", (yyvsp[-1].Str).text);
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 3973 "y.tab.c"
    break;

  case 150: /* $@21: %empty  */
#line 1739 "parser.y"
                                                             {fprintf(fIR, "else ");}
#line 3979 "y.tab.c"
    break;

  case 153: /* $@22: %empty  */
#line 1743 "parser.y"
                                                             {
							int a = !strcmp((yyvsp[-1].Str).str, "int") || 
									!strcmp((yyvsp[-1].Str).str, "float") || 
									!strcmp((yyvsp[-1].Str).str, "bool") ||
									!strcmp((yyvsp[-1].Str).str, "string") ||
									!strcmp((yyvsp[-1].Str).str, "char")
									;
							if(!a) {
								printf("%d Error : Invalid conditional argument\n", yylineno);
							}
							printTabs();
							fprintf(fIR, "switch (%s)", (yyvsp[-1].Str).text);
							fprintf(fparse, " : CONDITIONAL STATEMENT");
						}
#line 3998 "y.tab.c"
    break;

  case 155: /* $@23: %empty  */
#line 1760 "parser.y"
                                              {switch_insert(level); level++; fprintf(fIR, "{\n");}
#line 4004 "y.tab.c"
    break;

  case 156: /* $@24: %empty  */
#line 1760 "parser.y"
                                                                                                                      {printTabs(); fprintf(fIR, "default:\n");}
#line 4010 "y.tab.c"
    break;

  case 157: /* switch_body: '{' $@23 cases DEFAULT ':' $@24 function_body '}'  */
#line 1760 "parser.y"
                                                                                                                                                                                   { var_delete(level); level--; switch_delete(); printTabs(); fprintf(fIR, "}\n");}
#line 4016 "y.tab.c"
    break;

  case 158: /* $@25: %empty  */
#line 1763 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4022 "y.tab.c"
    break;

  case 160: /* $@26: %empty  */
#line 1764 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4028 "y.tab.c"
    break;

  case 162: /* RHS: constants  */
#line 1769 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4034 "y.tab.c"
    break;

  case 163: /* RHS: arith_op  */
#line 1770 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4040 "y.tab.c"
    break;

  case 164: /* RHS: logical_op  */
#line 1771 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4046 "y.tab.c"
    break;

  case 165: /* RHS: func_calls  */
#line 1772 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4052 "y.tab.c"
    break;

  case 166: /* RHS: impr  */
#line 1773 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4058 "y.tab.c"
    break;

  case 167: /* constants: INT_CONST  */
#line 1777 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 4064 "y.tab.c"
    break;

  case 168: /* constants: FLOAT_CONST  */
#line 1778 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 4070 "y.tab.c"
    break;

  case 169: /* constants: CHAR_CONST  */
#line 1779 "parser.y"
                                                             {(yyval.Str).str="char"; (yyval.Str).text = (yyvsp[0].str);}
#line 4076 "y.tab.c"
    break;

  case 170: /* constants: STR_CONST  */
#line 1780 "parser.y"
                                                            {(yyval.Str).str="string"; (yyval.Str).text = (yyvsp[0].str);}
#line 4082 "y.tab.c"
    break;

  case 171: /* constants: BOOL_CONST  */
#line 1781 "parser.y"
                                                             {(yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].str);}
#line 4088 "y.tab.c"
    break;

  case 172: /* constants: LHS  */
#line 1782 "parser.y"
                                                      {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4094 "y.tab.c"
    break;

  case 173: /* extra_consts: array_const  */
#line 1786 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4100 "y.tab.c"
    break;

  case 174: /* extra_consts: graph_const  */
#line 1787 "parser.y"
                                                             {(yyval.Str).str="graph";}
#line 4106 "y.tab.c"
    break;

  case 175: /* extra_consts: vect_const  */
#line 1788 "parser.y"
                                                            {
							char* myType = (char*)malloc(strlen((yyvsp[0].Str).str)+2);
							strcpy(myType, "*");
							strcat(myType, (yyvsp[0].Str).str);
							(yyval.Str).str = myType;
							 (yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 4118 "y.tab.c"
    break;

  case 176: /* extra_consts: matrix_const  */
#line 1795 "parser.y"
                                                              {(yyval.Str).str="matrix"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4124 "y.tab.c"
    break;

  case 177: /* extra_consts: '{' '}'  */
#line 1796 "parser.y"
                                                         {(yyval.Str).str="1"; (yyval.Str).text = "{}";}
#line 4130 "y.tab.c"
    break;

  case 178: /* array_const: '[' val_list ']'  */
#line 1800 "parser.y"
                                                        {
								(yyval.Str).str = (yyvsp[-1].Str).str;
								
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								
								(yyval.Str).text = myText;
							}
#line 4145 "y.tab.c"
    break;

  case 179: /* array_const: '[' ']'  */
#line 1811 "parser.y"
                                                        {
								(yyval.Str).str = "any";
								(yyval.Str).text = "{}";
							}
#line 4154 "y.tab.c"
    break;

  case 180: /* val_list: int_list  */
#line 1818 "parser.y"
                                                        { (yyval.Str).str = "int"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4160 "y.tab.c"
    break;

  case 181: /* val_list: float_list  */
#line 1820 "parser.y"
                                                        { (yyval.Str).str  = "float"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4166 "y.tab.c"
    break;

  case 182: /* val_list: char_list  */
#line 1822 "parser.y"
                                                        { (yyval.Str).str = "char"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4172 "y.tab.c"
    break;

  case 183: /* val_list: bool_list  */
#line 1824 "parser.y"
                                                        { (yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4178 "y.tab.c"
    break;

  case 184: /* val_list: str_list  */
#line 1826 "parser.y"
                                                        { (yyval.Str).str = "string"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4184 "y.tab.c"
    break;

  case 185: /* resultant: LHS  */
#line 1828 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4190 "y.tab.c"
    break;

  case 186: /* resultant: matrix_impr  */
#line 1829 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4196 "y.tab.c"
    break;

  case 187: /* resultant: graph_impr  */
#line 1830 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4202 "y.tab.c"
    break;

  case 188: /* resultant: vect_stmt_body  */
#line 1831 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4208 "y.tab.c"
    break;

  case 189: /* resultant: impr  */
#line 1832 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4214 "y.tab.c"
    break;

  case 190: /* resultant: func_calls  */
#line 1833 "parser.y"
                                                            {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4220 "y.tab.c"
    break;

  case 191: /* impr: resultant '.' LENGTH '(' ')'  */
#line 1837 "parser.y"
                                                                      {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if((yyvsp[-4].Str).str[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							} else {
								(yyval.Str).str = "int";
								
								
								char* myText = (char*)malloc(strlen((yyvsp[-4].Str).text)+8);
								strcpy(myText, (yyvsp[-4].Str).text);
								strcat(myText, ".size()");
								strcpy((yyval.Str).text, myText);
								free(myText);;
								
							}
						}
#line 4242 "y.tab.c"
    break;

  case 192: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 1854 "parser.y"
                                                                                      {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if((yyvsp[-5].Str).str[0] != '*'){
								printf("%d Error: invalid type for 'at'\n", yylineno);
								exit(1);
							}
							else {
								if (!(!strcmp("int", (yyvsp[-1].Str).str) || !strcmp("float", (yyvsp[-1].Str).str) || !strcmp("bool", (yyvsp[-1].Str).str))){
									printf("%d ERROR: appending the wrong dtype\n", yylineno);
									exit(1);
								}
								else{
									char* myType = (char*)malloc(strlen((yyvsp[-5].Str).str)+1);
									strncpy(myType, (yyvsp[-5].Str).str + 1, strlen((yyvsp[-5].Str).str));
									myType[strlen((yyvsp[-5].Str).str)] = '\0';
									strcpy((yyval.Str).str, myType);
									char* myText = (char*)malloc(strlen((yyvsp[-5].Str).text) + strlen((yyvsp[-1].Str).text) + 3);
									strcpy(myText, (yyvsp[-5].Str).text);
									strcat(myText, "[");
									strcat(myText, (yyvsp[-1].Str).text);
									strcat(myText, "]");
									strcpy((yyval.Str).text, myText);
									
									free(myType);
									free(myText);
								}
							} 
							
							// printf("%d::resultant - %s, index - %s, returning - %s\n", yylineno, $1, $5, $$);
						}
#line 4277 "y.tab.c"
    break;

  case 193: /* impr: resultant '.' TRACE '(' ')'  */
#line 1884 "parser.y"
                                                                              {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if(strcmp("matrix", (yyvsp[-4].Str).str)){
								printf("%d Error: invalid type for trace\n", yylineno);
								exit(1);
							}else{
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(128);
								strcpy(myText, "{matrix _temp = ");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ";_flag = _temp.trace();}\n");
								printTabs();
								fprintf(fIR, "%s", myText);
								(yyval.Str).text = "_flag";
							}
						}
#line 4298 "y.tab.c"
    break;

  case 194: /* impr: resultant '.' STRLEN '(' ')'  */
#line 1901 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								if(strcmp((yyvsp[-4].Str).str, "string"))
								{
									printf("%d ERROR: Method defined for string datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen("strlen()") + strlen((yyvsp[-4].Str).text));
								strcpy(myText, "strlen(");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ")");
								
								strcpy((yyval.Str).text, myText);
								free(myText);
							}
#line 4319 "y.tab.c"
    break;

  case 195: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 1918 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								if(strcmp((yyvsp[-3].Str).str, "string") || strcmp((yyvsp[-1].Str).str, "string"))
								{
									printf("%d ERROR: Arguments have to be strings\n", yylineno);
									exit(1);
								}
								
								
								char* myText = (char*)malloc(strlen("strcmp(, )") + strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text));
								strcpy(myText, "strcmp(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
								
							}
#line 4343 "y.tab.c"
    break;

  case 196: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 1938 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								if(strcmp((yyvsp[-7].Str).str, "string"))
								{
									printf("%d ERROR: Method defined for string datatype only\n", yylineno);
									exit(1);
								}
								if(strcmp((yyvsp[-3].Str).str, "int") || strcmp((yyvsp[-1].Str).str, "int"))
								{
									printf("%d ERROR: Arguments have to be intergers\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen((yyvsp[-7].Str).text) + strlen(".substr(, )") + strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text) + 1);
								strcpy(myText, (yyvsp[-7].Str).text);
								strcat(myText, ".substr(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
							}
#line 4371 "y.tab.c"
    break;

  case 197: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 1962 "parser.y"
                                                        {
								(yyval.Str).str =  "string";
								if(strcmp((yyvsp[-3].Str).str, "string") || strcmp((yyvsp[-1].Str).str, "string"))
								{
									printf("%d ERROR: Arguments have to be strings\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc( strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text) + 4);
								strcpy(myText, "(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, "+");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
								
							}
#line 4394 "y.tab.c"
    break;

  case 198: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 1983 "parser.y"
                                                        {
								(yyval.Str).str = "*int";
								if(strcmp((yyvsp[-5].Str).str,"graph"))
								{
									printf("%d ERROR: Traversals are defined only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp((yyvsp[-1].Str).str, "int"))
								{
									printf("%d ERROR: Argument has to be an integer\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen((yyvsp[-5].Str).text)+strlen("bfs.()")+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-5].Str).text);
								strcat(myText, ".");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, "(");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4421 "y.tab.c"
    break;

  case 199: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 2006 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
							}
#line 4434 "y.tab.c"
    break;

  case 200: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 2015 "parser.y"
                                                        {
								(yyval.Str).str = "*int";
								if(strcmp((yyvsp[-7].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp((yyvsp[-3].Str).str,"int") || strcmp((yyvsp[-1].Str).str, "int"))
								{
									printf("%d ERROR: Arguments should be integers\n", yylineno);
									exit(1);
								}
							}
#line 4452 "y.tab.c"
    break;

  case 201: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 2029 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								if(strcmp((yyvsp[-7].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp((yyvsp[-3].Str).str,"int") || strcmp((yyvsp[-1].Str).str, "int"))
								{
									printf("%d ERROR: Arguments should be integers\n", yylineno);
									exit(1);
								}
							}
#line 4470 "y.tab.c"
    break;

  case 202: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 2046 "parser.y"
                                                        {
								if(strcmp((yyvsp[-3].Str).str,"matrix") || strcmp((yyvsp[-1].Str).str,"matrix"))
								{
									printf("%d, ERROR : argument is not a matrix\n",yylineno);
									exit(1);
								}
								(yyval.Str).str = "matrix";
								char* myText = (char*)malloc(128);
							
								strcpy(myText, (yyvsp[-5].str));
								strcat(myText, "(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4492 "y.tab.c"
    break;

  case 203: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 2064 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(256);
								strcpy(myText, "{matrix _temp = ");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, "; _temp = _temp.transpose(); ");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, " = _temp;}");
								printTabs();
								fprintf(fIR, "%s\n", myText);
								(yyval.Str).text = (yyvsp[-4].Str).text;
							}
#line 4515 "y.tab.c"
    break;

  case 204: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 2083 "parser.y"
                                                        {
								(yyval.Str).str = "graph";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
							}
#line 4528 "y.tab.c"
    break;

  case 205: /* matr_body: RHS  */
#line 2093 "parser.y"
                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4534 "y.tab.c"
    break;

  case 206: /* matr_body: matrix_impr  */
#line 2094 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4540 "y.tab.c"
    break;

  case 207: /* graph_const: '{' graph_type1 '}'  */
#line 2097 "parser.y"
                                                              {printTabs();fprintf(fIR, "%s.setFlag(0);\n", LeftName);}
#line 4546 "y.tab.c"
    break;

  case 208: /* graph_const: '{' graph_type2 '}'  */
#line 2098 "parser.y"
                                                                      {printTabs();fprintf(fIR, "%s.setFlag(1);\n", LeftName);}
#line 4552 "y.tab.c"
    break;

  case 209: /* graph_type1: INT_CONST ':' int_list ';' graph_type1  */
#line 2102 "parser.y"
                                                        {
								
								newArr[dummy_size] = atoi((yyvsp[-4].str));
								dummy_size++;
								int size;
								int* intArray = splitStringToIntArray((yyvsp[-2].Str).text, &size);
								
								if (intArray != NULL) {
       								for (int i = 0; i < size; ++i) {
       									printTabs();
          							 	fprintf(fIR, "%s.addEdge(%s, %d);\n", LeftName, (yyvsp[-4].str), intArray[i]);
        							}

       								free(intArray); // Don't forget to free the allocated memory
    							} else {
        							printf("Memory allocation failed.\n");
							    }
								
							}
#line 4576 "y.tab.c"
    break;

  case 210: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 2122 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								int size;
								int* intArray = splitStringToIntArray((yyvsp[-1].Str).text, &size);
								
								if (intArray != NULL) {
       								for (int i = 0; i < size; ++i) {
       									printTabs();
          							 	fprintf(fIR, "%s.addEdge(%s, %d);\n", LeftName, (yyvsp[-3].str), intArray[i]);
        							}

       								free(intArray); // Don't forget to free the allocated memory
    							} else {
        							printf("Memory allocation failed.\n");
							    }
							}
#line 4598 "y.tab.c"
    break;

  case 211: /* graph_type2: INT_CONST ':' weight_list ';' graph_type2  */
#line 2142 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-4].str));
								dummy_size++;
								size_t count;
								const char* delimiter = ",";
   								char** result = splitString((yyvsp[-2].Str).text, delimiter, &count);

    							// Print the result
    							for (size_t i = 0; i < count; i=i+2) {
    								printTabs();
       								fprintf(fIR, "%s.addWeightedEdge(%s, %s, %s);\n", LeftName, (yyvsp[-4].str), result[i], result[i+1]);
    							}

    							// Free the allocated memory
    							freeStringArray(result, count);
							}
#line 4619 "y.tab.c"
    break;

  case 212: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 2159 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								size_t count;
								const char* delimiter = ",";
   								char** result = splitString((yyvsp[-1].Str).text, delimiter, &count);

    							// Print the result
    							for (size_t i = 0; i < count; i=i+2) {
    								printTabs();
       								fprintf(fIR, "%s.addWeightedEdge(%s, %s, %s);\n", LeftName, (yyvsp[-3].str), result[i], result[i+1]);
    							}

    							// Free the allocated memory
    							freeStringArray(result, count);
							}
#line 4640 "y.tab.c"
    break;

  case 213: /* $@27: %empty  */
#line 2178 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 4649 "y.tab.c"
    break;

  case 214: /* int_list: int_list ',' INT_CONST $@27  */
#line 2182 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4662 "y.tab.c"
    break;

  case 215: /* $@28: %empty  */
#line 2191 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 4671 "y.tab.c"
    break;

  case 216: /* int_list: INT_CONST $@28  */
#line 2195 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								(yyval.Str).text = (yyvsp[-1].str);
							}
#line 4680 "y.tab.c"
    break;

  case 217: /* float_list: float_list ',' FLOAT_CONST  */
#line 2202 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4694 "y.tab.c"
    break;

  case 218: /* float_list: FLOAT_CONST  */
#line 2212 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4704 "y.tab.c"
    break;

  case 219: /* char_list: char_list ',' CHAR_CONST  */
#line 2220 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4718 "y.tab.c"
    break;

  case 220: /* char_list: CHAR_CONST  */
#line 2230 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4728 "y.tab.c"
    break;

  case 221: /* bool_list: bool_list ',' BOOL_CONST  */
#line 2238 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4742 "y.tab.c"
    break;

  case 222: /* bool_list: BOOL_CONST  */
#line 2248 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4752 "y.tab.c"
    break;

  case 223: /* str_list: str_list ',' STR_CONST  */
#line 2256 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4766 "y.tab.c"
    break;

  case 224: /* str_list: STR_CONST  */
#line 2266 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4776 "y.tab.c"
    break;

  case 225: /* weight_list: weight_list ',' '(' INT_CONST ',' INT_CONST ')'  */
#line 2274 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+5);
								strcpy(myText, (yyvsp[-6].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4793 "y.tab.c"
    break;

  case 226: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 2287 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4807 "y.tab.c"
    break;

  case 227: /* weight_list: weight_list ',' '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2297 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+5);
								strcpy(myText, (yyvsp[-6].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4823 "y.tab.c"
    break;

  case 228: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2309 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4837 "y.tab.c"
    break;

  case 229: /* vect_const: '{' vect_list '}'  */
#line 2320 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[-1].Str).str;
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 4850 "y.tab.c"
    break;

  case 230: /* vect_list: vect_list ',' vect_item  */
#line 2330 "parser.y"
                                                                  {
							(yyval.Str).str = (yyvsp[-2].Str).str;
							if(strcmp((yyvsp[0].Str).str, (yyvsp[-2].Str).str)){
								int a = !strcmp((yyvsp[0].Str).str, "int") || !strcmp((yyvsp[0].Str).str, "float") || !strcmp((yyvsp[0].Str).str, "bool");
								int b = !strcmp((yyvsp[-2].Str).str, "int") || !strcmp((yyvsp[-2].Str).str, "float") || !strcmp((yyvsp[-2].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: vector element type mis-matched\n\n", yylineno);
									exit(1);
								}
							}
							
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+3);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
						}
#line 4873 "y.tab.c"
    break;

  case 231: /* vect_list: vect_item  */
#line 2348 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[0].Str).str;
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 4882 "y.tab.c"
    break;

  case 232: /* vect_item: constants  */
#line 2354 "parser.y"
                                                    {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4888 "y.tab.c"
    break;

  case 233: /* vect_item: extra_consts  */
#line 2355 "parser.y"
                                                               {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4894 "y.tab.c"
    break;

  case 234: /* matrix_const: '[' mat_list ']'  */
#line 2358 "parser.y"
                                                   {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Cols).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Cols).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 4906 "y.tab.c"
    break;

  case 235: /* int_float_list: int_float_list ',' INT_CONST  */
#line 2368 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 4919 "y.tab.c"
    break;

  case 236: /* int_float_list: int_float_list ',' FLOAT_CONST  */
#line 2377 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 4932 "y.tab.c"
    break;

  case 237: /* int_float_list: INT_CONST  */
#line 2386 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 4941 "y.tab.c"
    break;

  case 238: /* int_float_list: FLOAT_CONST  */
#line 2391 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 4950 "y.tab.c"
    break;

  case 239: /* mat_list: mat_list '[' int_float_list ']' ';'  */
#line 2398 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-4].Cols).text)+strlen((yyvsp[-2].Cols).text)+4);
								strcpy(myText, (yyvsp[-4].Cols).text);
								strcat(myText, ",{");
								strcat(myText, (yyvsp[-2].Cols).text);
								strcat(myText, "}");
								(yyval.Cols).text = myText;
							}
#line 4966 "y.tab.c"
    break;

  case 240: /* mat_list: '[' int_float_list ']' ';'  */
#line 2410 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-2].Cols).text);
								strcat(myText, "}");
								(yyval.Cols).text = myText;
								
							}
#line 4982 "y.tab.c"
    break;

  case 243: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 2428 "parser.y"
                                                                      {
							if(!strcmp((yyvsp[-3].Str).str, "int") || !strcmp((yyvsp[-3].Str).str, "bool")|| !strcmp((yyvsp[-3].Str).str, "float")){
								if(!strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "bool") || !strcmp((yyvsp[-1].Str).str, "float")){
									if(!strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-3].Str).str, "float")) (yyval.Str).str = "float";
									else (yyval.Str).str = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
									exit(1);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							if(!strcmp((yyvsp[-5].str), "exp")) {
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].Str).text)+7);
								strcpy(myText, "pow(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
							
							else{
								char* symb = (char*)malloc(2);
								if(!strcmp((yyvsp[-5].str), "add")) symb = "+";
								else if(!strcmp((yyvsp[-5].str), "sub")) symb = "-";
								else if(!strcmp((yyvsp[-5].str), "mul")) symb = "*";
								else if(!strcmp((yyvsp[-5].str), "div")) symb = "/";
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text) + 4);
								strcpy(myText, "(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, symb);
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							
							}
							
							
						}
#line 5031 "y.tab.c"
    break;

  case 244: /* unary_op: UNARYOP '(' RHS ')'  */
#line 2474 "parser.y"
                                                              {
							if(!strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "bool")|| !strcmp((yyvsp[-1].Str).str, "float")){
								(yyval.Str).str = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* symb = (char*)malloc(3);
							if(!strcmp((yyvsp[-3].str), "incr")) symb = "++";
							else if(!strcmp((yyvsp[-3].str), "decr")) symb = "--";
							
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+strlen(symb)+1);
							strcpy(myText, (yyvsp[-1].Str).text);
							strcat(myText, symb);
							(yyval.Str).text = myText;
						}
#line 5054 "y.tab.c"
    break;

  case 245: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 2494 "parser.y"
                                                                {
							if(!strcmp((yyvsp[-3].Str).str, "int") || !strcmp((yyvsp[-3].Str).str, "bool")|| !strcmp((yyvsp[-3].Str).str, "float")){
								if(!strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "bool") || !strcmp((yyvsp[-1].Str).str, "float")){
									if(!strcmp((yyvsp[-3].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "float")) (yyval.Str).str = "float";
									else (yyval.Str).str = "int";
								}
								else{
									printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
									exit(1);
								}
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* symb = (char*)malloc(3);
							if(!strcmp((yyvsp[-2].str), "or")) symb = "||";
							else if(!strcmp((yyvsp[-2].str), "and")) symb = "&&";
							else if(!strcmp((yyvsp[-2].str), "lt")) symb = "<";
							else if(!strcmp((yyvsp[-2].str), "lte")) symb = "<=";
							else if(!strcmp((yyvsp[-2].str), "gt")) symb = ">";
							else if(!strcmp((yyvsp[-2].str), "get")) symb = ">=";
							else if(!strcmp((yyvsp[-2].str), "eq")) symb = "=";
							else if(!strcmp((yyvsp[-2].str), "neq")) symb = "!=";
							
							char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].Str).text)+strlen(symb)+3);
							strcpy(myText, "(");
							strcat(myText, (yyvsp[-3].Str).text);
							strcat(myText, symb);
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							(yyval.Str).text = myText;
						}
#line 5093 "y.tab.c"
    break;

  case 246: /* logical_op: NOT '(' RHS ')'  */
#line 2528 "parser.y"
                                                                  {
							if(!strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "bool")|| !strcmp((yyvsp[-1].Str).str, "float")){
								(yyval.Str).str = "int";
							}
							else{
								printf("%d Error: Invalid argument for arithmetic operation\n", yylineno);
								exit(1);
							}
							
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+4);
							strcpy(myText, "!(");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							(yyval.Str).text = myText;
						}
#line 5113 "y.tab.c"
    break;

  case 247: /* call_stmt: func_calls ';'  */
#line 2546 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1; printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text); }
#line 5119 "y.tab.c"
    break;

  case 248: /* func_calls: call_head arguments  */
#line 2551 "parser.y"
                                                              {
							(yyval.Str).str = (yyvsp[-1].Str).str;
							
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
							
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text) + strlen((yyvsp[0].Str).text) + 1);
							strcpy(myText, (yyvsp[-1].Str).text);
							strcat(myText, (yyvsp[0].Str).text);
							
							strcpy((yyval.Str).text, myText);
							free(myText);
						}
#line 5146 "y.tab.c"
    break;

  case 249: /* call_head: CALL LHS  */
#line 2576 "parser.y"
                                                    {
							callClassIndex = classIndex;
							callFuncIndex = funcIndex;
							if(callClassIndex == -1){
								(yyval.Str).str = func_symb[callFuncIndex].type;
							}
							else{
								(yyval.Str).str = class_symb[callClassIndex].func_list[callFuncIndex].type;
							}
							myIndex = 0;
							
							(yyval.Str).text = (yyvsp[0].details).text;
						}
#line 5164 "y.tab.c"
    break;

  case 250: /* arguments: '(' arg_list ')'  */
#line 2591 "parser.y"
                                                           {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text) + 3);
							strcpy(myText, "(");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							strcpy((yyval.Str).text, myText);
							free(myText);
						}
#line 5177 "y.tab.c"
    break;

  case 251: /* arguments: '(' ')'  */
#line 2599 "parser.y"
                                                          {(yyval.Str).text = "()";}
#line 5183 "y.tab.c"
    break;

  case 252: /* arg_list: RHS  */
#line 2602 "parser.y"
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
								char* myType = NULL;
								if(callClassIndex == -1) {
									int k = strlen(func_symb[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = func_symb[callFuncIndex].args[myIndex];
									myType[k] = '\0';
								}
								else {
									int k = strlen(class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
									myType[k]='\0';
								}
								
								if(strcmp(myType, (yyvsp[0].Str).str)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp((yyvsp[0].Str).str, "int") || !strcmp((yyvsp[0].Str).str, "float") || !strcmp((yyvsp[0].Str).str, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex+1, myType, (yyvsp[0].Str).str);
										free(myType);
										exit(1);
									}
									
									else {
										myIndex++;
										free(myType);
									}
								}
								
								else myIndex++;
								free(myType);
								
							}
							
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 5240 "y.tab.c"
    break;

  case 253: /* arg_list: arg_list ',' RHS  */
#line 2654 "parser.y"
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
								if(callClassIndex == -1) {
									int k = strlen(func_symb[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = func_symb[callFuncIndex].args[myIndex];
									myType[k] = '\0';
								}
								else {
									int k = strlen(class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex]);
									myType = (char*)malloc(k+1);
									myType = class_symb[callClassIndex].func_list[callFuncIndex].args[myIndex];
									myType[k]='\0';
								}
								
								if(strcmp(myType, (yyvsp[0].Str).str)){
									// type mismatched. Now check if it is ignorable or not
									int a = !strcmp(myType, "int") || !strcmp(myType, "float") || !strcmp(myType, "bool");
									int b = !strcmp((yyvsp[0].Str).str, "int") || !strcmp((yyvsp[0].Str).str, "float") || !strcmp((yyvsp[0].Str).str, "bool");
									
									if(!(a && b)){
										printf("%d Error: for argument-%d expected argument type: %s, given argument type %s\n", yylineno, myIndex, myType, (yyvsp[0].Str).str);
										free(myType);
										exit(1);
									}
									
									else myIndex++;
								}
								
								else myIndex++;
								free(myType);
							}
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text) + strlen((yyvsp[0].Str).text) + 3);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							strcpy((yyval.Str).text, myText);
							free(myText);
						}
#line 5294 "y.tab.c"
    break;


#line 5298 "y.tab.c"

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

#line 2705 "parser.y"


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
 	FILE* fp = fopen("inp.vgm", "r");
    yyin = fp;
    fparse = fopen("parsed.txt", "w");
 	FILE* ft = fopen("tokens.txt", "w");
 	yyout = ft;
 	fIR = fopen("IR.cpp", "w");
 	fprintf(fIR, "#include <bits/stdc++.h>\n#include \"improvisations.h\"\nusing namespace std;\n\n");
 	

 	yyparse();

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




