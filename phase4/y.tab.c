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
    GOTO = 311,                    /* GOTO  */
    PRINT = 312                    /* PRINT  */
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
#define PRINT 312

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

#line 381 "y.tab.c"

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
  YYSYMBOL_PRINT = 57,                     /* PRINT  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_66_ = 66,                       /* '<'  */
  YYSYMBOL_67_ = 67,                       /* '>'  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_69_ = 69,                       /* '.'  */
  YYSYMBOL_70_ = 70,                       /* '='  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_program_unit = 72,              /* program_unit  */
  YYSYMBOL_models = 73,                    /* models  */
  YYSYMBOL_model = 74,                     /* model  */
  YYSYMBOL_class = 75,                     /* class  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_id = 78,                        /* id  */
  YYSYMBOL_class_items = 79,               /* class_items  */
  YYSYMBOL_80_3 = 80,                      /* $@3  */
  YYSYMBOL_class_item = 81,                /* class_item  */
  YYSYMBOL_struct = 82,                    /* struct  */
  YYSYMBOL_83_4 = 83,                      /* $@4  */
  YYSYMBOL_84_5 = 84,                      /* $@5  */
  YYSYMBOL_struct_items = 85,              /* struct_items  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_function = 87,                  /* function  */
  YYSYMBOL_function_head = 88,             /* function_head  */
  YYSYMBOL_func_definition = 89,           /* func_definition  */
  YYSYMBOL_Parameters = 90,                /* Parameters  */
  YYSYMBOL_fdtype = 91,                    /* fdtype  */
  YYSYMBOL_param_list = 92,                /* param_list  */
  YYSYMBOL_param = 93,                     /* param  */
  YYSYMBOL_dtype = 94,                     /* dtype  */
  YYSYMBOL_function_body = 95,             /* function_body  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_statements = 97,                /* statements  */
  YYSYMBOL_98_8 = 98,                      /* $@8  */
  YYSYMBOL_statement = 99,                 /* statement  */
  YYSYMBOL_print_stmt = 100,               /* print_stmt  */
  YYSYMBOL_print_body = 101,               /* print_body  */
  YYSYMBOL_print_constants = 102,          /* print_constants  */
  YYSYMBOL_unary_stmt = 103,               /* unary_stmt  */
  YYSYMBOL_jump_stmt = 104,                /* jump_stmt  */
  YYSYMBOL_label_stmt = 105,               /* label_stmt  */
  YYSYMBOL_106_9 = 106,                    /* $@9  */
  YYSYMBOL_goto_stmt = 107,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 108,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 109,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 110,              /* remove_body  */
  YYSYMBOL_vect_append = 111,              /* vect_append  */
  YYSYMBOL_return_stmt = 112,              /* return_stmt  */
  YYSYMBOL_113_10 = 113,                   /* $@10  */
  YYSYMBOL_114_11 = 114,                   /* $@11  */
  YYSYMBOL_115_12 = 115,                   /* $@12  */
  YYSYMBOL_116_13 = 116,                   /* $@13  */
  YYSYMBOL_117_14 = 117,                   /* $@14  */
  YYSYMBOL_loop_stmt = 118,                /* loop_stmt  */
  YYSYMBOL_loop_type = 119,                /* loop_type  */
  YYSYMBOL_for_loop = 120,                 /* for_loop  */
  YYSYMBOL_121_15 = 121,                   /* $@15  */
  YYSYMBOL_122_16 = 122,                   /* $@16  */
  YYSYMBOL_for_in = 123,                   /* for_in  */
  YYSYMBOL_124_17 = 124,                   /* $@17  */
  YYSYMBOL_for_expr = 125,                 /* for_expr  */
  YYSYMBOL_for_RHS = 126,                  /* for_RHS  */
  YYSYMBOL_while_loop = 127,               /* while_loop  */
  YYSYMBOL_128_18 = 128,                   /* $@18  */
  YYSYMBOL_expr_stmt = 129,                /* expr_stmt  */
  YYSYMBOL_130_19 = 130,                   /* $@19  */
  YYSYMBOL_LHS = 131,                      /* LHS  */
  YYSYMBOL_myId = 132,                     /* myId  */
  YYSYMBOL_declr_stmt = 133,               /* declr_stmt  */
  YYSYMBOL_declr_body = 134,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 135,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 136,              /* matrix_list  */
  YYSYMBOL_id_list = 137,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 138,              /* ifcond_stmt  */
  YYSYMBOL_139_20 = 139,                   /* $@20  */
  YYSYMBOL_if_body = 140,                  /* if_body  */
  YYSYMBOL_141_21 = 141,                   /* $@21  */
  YYSYMBOL_switch_stmt = 142,              /* switch_stmt  */
  YYSYMBOL_143_22 = 143,                   /* $@22  */
  YYSYMBOL_switch_body = 144,              /* switch_body  */
  YYSYMBOL_145_23 = 145,                   /* $@23  */
  YYSYMBOL_146_24 = 146,                   /* $@24  */
  YYSYMBOL_cases = 147,                    /* cases  */
  YYSYMBOL_148_25 = 148,                   /* $@25  */
  YYSYMBOL_149_26 = 149,                   /* $@26  */
  YYSYMBOL_RHS = 150,                      /* RHS  */
  YYSYMBOL_constants = 151,                /* constants  */
  YYSYMBOL_extra_consts = 152,             /* extra_consts  */
  YYSYMBOL_array_const = 153,              /* array_const  */
  YYSYMBOL_val_list = 154,                 /* val_list  */
  YYSYMBOL_resultant = 155,                /* resultant  */
  YYSYMBOL_impr = 156,                     /* impr  */
  YYSYMBOL_graph_impr = 157,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 158,              /* matrix_impr  */
  YYSYMBOL_matr_body = 159,                /* matr_body  */
  YYSYMBOL_graph_const = 160,              /* graph_const  */
  YYSYMBOL_graph_type1 = 161,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 162,              /* graph_type2  */
  YYSYMBOL_int_list = 163,                 /* int_list  */
  YYSYMBOL_164_27 = 164,                   /* $@27  */
  YYSYMBOL_165_28 = 165,                   /* $@28  */
  YYSYMBOL_float_list = 166,               /* float_list  */
  YYSYMBOL_char_list = 167,                /* char_list  */
  YYSYMBOL_bool_list = 168,                /* bool_list  */
  YYSYMBOL_str_list = 169,                 /* str_list  */
  YYSYMBOL_weight_list = 170,              /* weight_list  */
  YYSYMBOL_vect_const = 171,               /* vect_const  */
  YYSYMBOL_vect_list = 172,                /* vect_list  */
  YYSYMBOL_vect_item = 173,                /* vect_item  */
  YYSYMBOL_matrix_const = 174,             /* matrix_const  */
  YYSYMBOL_int_float_list = 175,           /* int_float_list  */
  YYSYMBOL_mat_list = 176,                 /* mat_list  */
  YYSYMBOL_arith_op = 177,                 /* arith_op  */
  YYSYMBOL_binary_op = 178,                /* binary_op  */
  YYSYMBOL_unary_op = 179,                 /* unary_op  */
  YYSYMBOL_logical_op = 180,               /* logical_op  */
  YYSYMBOL_call_stmt = 181,                /* call_stmt  */
  YYSYMBOL_func_calls = 182,               /* func_calls  */
  YYSYMBOL_call_head = 183,                /* call_head  */
  YYSYMBOL_arguments = 184,                /* arguments  */
  YYSYMBOL_arg_list = 185                  /* arg_list  */
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
#define YYLAST   1008

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  259
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  505

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      61,    62,     2,     2,    63,     2,    69,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    60,
      66,    70,    67,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   207,   207,   210,   211,   214,   215,   216,   219,   232,
     219,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   255,
     255,   256,   259,   260,   264,   276,   263,   279,   279,   280,
     283,   293,   303,   331,   332,   336,   337,   341,   349,   353,
     402,   416,   417,   418,   419,   438,   465,   465,   466,   469,
     469,   470,   471,   472,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   490,   499,   507,
     513,   522,   531,   534,   535,   539,   538,   553,   556,   559,
     606,   644,   674,   707,   708,   709,   710,   711,   712,   713,
     717,   718,   723,   722,   779,   778,   800,   799,   840,   839,
     878,   918,   917,   943,   946,   947,   950,   950,   950,   954,
     954,   958,   959,   975,   976,   977,   978,   979,   980,   983,
     983,   999,  1014,  1013,  1100,  1115,  1124,  1136,  1210,  1302,
    1303,  1323,  1325,  1373,  1440,  1488,  1546,  1596,  1661,  1684,
    1707,  1732,  1756,  1769,  1777,  1777,  1794,  1794,  1795,  1798,
    1798,  1815,  1815,  1815,  1818,  1818,  1819,  1819,  1824,  1825,
    1826,  1827,  1828,  1832,  1833,  1834,  1835,  1836,  1837,  1841,
    1842,  1843,  1850,  1851,  1854,  1865,  1872,  1874,  1876,  1878,
    1880,  1883,  1884,  1885,  1886,  1887,  1888,  1892,  1909,  1939,
    1953,  1970,  1990,  2016,  2037,  2060,  2069,  2092,  2118,  2136,
    2151,  2162,  2163,  2166,  2175,  2186,  2216,  2245,  2272,  2300,
    2299,  2313,  2312,  2323,  2333,  2341,  2351,  2359,  2369,  2377,
    2387,  2395,  2408,  2418,  2430,  2442,  2452,  2470,  2476,  2477,
    2480,  2489,  2498,  2507,  2512,  2519,  2531,  2546,  2547,  2550,
    2596,  2616,  2650,  2668,  2673,  2698,  2713,  2721,  2724,  2776
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
  "SHPATH_VAL", "GOTO", "PRINT", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'['", "']'", "'<'", "'>'", "':'", "'.'", "'='", "$accept",
  "program_unit", "models", "model", "class", "$@1", "$@2", "id",
  "class_items", "$@3", "class_item", "struct", "$@4", "$@5",
  "struct_items", "$@6", "function", "function_head", "func_definition",
  "Parameters", "fdtype", "param_list", "param", "dtype", "function_body",
  "$@7", "statements", "$@8", "statement", "print_stmt", "print_body",
  "print_constants", "unary_stmt", "jump_stmt", "label_stmt", "$@9",
  "goto_stmt", "vect_stmt", "vect_stmt_body", "remove_body", "vect_append",
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

#define YYPACT_NINF (-300)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-197)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,   272,   272,   828,    37,  -300,    39,  -300,  -300,  -300,
      61,    14,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
      68,    82,  -300,  -300,  -300,  -300,    44,  -300,   272,  -300,
    -300,  -300,    23,  -300,   659,  -300,  -300,  -300,   876,  -300,
    -300,   772,  -300,     4,  -300,   272,    18,   112,    76,   460,
      86,    94,    98,    99,   100,   924,   272,   272,    52,   101,
     102,   103,   272,   105,   -15,   772,   108,   119,  -300,  -300,
    -300,  -300,  -300,  -300,   111,  -300,  -300,  -300,   150,  -300,
    -300,  -300,  -300,   113,  -300,  -300,  -300,   120,  -300,   121,
     125,  -300,   876,   127,   130,   131,  -300,  -300,   133,   135,
    -300,  -300,  -300,  -300,  -300,  -300,   136,   138,   149,   584,
     688,    92,   132,   151,    33,   152,  -300,   153,  -300,   116,
     154,   155,  -300,  -300,  -300,  -300,  -300,  -300,  -300,   141,
     688,  -300,  -300,   688,   688,   272,   272,   272,   129,   272,
     156,    21,   150,   158,   159,  -300,  -300,  -300,   688,   688,
     688,   157,   611,   688,   160,  -300,  -300,   772,  -300,   272,
     334,  -300,  -300,   197,  -300,  -300,   166,  -300,    18,  -300,
     112,   688,   688,  -300,   165,  -300,   150,  -300,  -300,    35,
      36,    -3,  -300,  -300,   195,  -300,  -300,  -300,  -300,  -300,
     109,  -300,   189,   193,   198,   199,   200,   201,    51,  -300,
    -300,  -300,  -300,  -300,   161,   204,   205,   196,   207,   208,
     216,   209,   196,   207,   876,  -300,   208,  -300,   522,  -300,
     688,   221,   222,  -300,   218,   227,  -300,    60,  -300,  -300,
    -300,   203,    61,  -300,  -300,   233,   234,   236,   238,   239,
     243,   246,   248,   262,   267,   268,   269,   270,   271,   273,
    -300,  -300,    62,  -300,   162,  -300,   275,  -300,   276,   278,
    -300,    32,   265,  -300,   274,  -300,  -300,   611,   688,  -300,
    -300,  -300,    38,  -300,   337,   333,   339,   338,   340,   109,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,   344,   272,
     272,   345,   272,   283,   291,   292,   293,   294,   295,   325,
     296,   688,   688,   688,   297,   611,  -300,  -300,   522,   719,
     298,   299,   301,   719,   302,   303,   719,   304,   719,   306,
     307,   719,   719,  -300,   688,  -300,  -300,   688,  -300,   366,
      -1,    16,   367,   329,  -300,   330,   124,   331,  -300,  -300,
    -300,  -300,  -300,    42,    61,   341,   332,   336,  -300,   342,
     346,   272,  -300,  -300,  -300,  -300,  -300,   347,    24,  -300,
     349,   350,   351,  -300,  -300,   352,  -300,  -300,  -300,  -300,
     355,    33,   116,  -300,  -300,   141,  -300,  -300,  -300,   356,
    -300,  -300,   357,  -300,   335,  -300,  -300,   343,   358,  -300,
     360,   361,  -300,  -300,   359,    17,    27,  -300,  -300,  -300,
    -300,  -300,   348,   381,  -300,  -300,  -300,  -300,   397,   363,
     398,   208,  -300,  -300,   365,    61,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,   719,   719,   719,  -300,   126,   419,  -300,
    -300,  -300,  -300,   406,   364,   426,   368,    61,  -300,  -300,
     369,   370,   372,   373,   377,   378,    61,   436,   110,  -300,
     379,   383,  -300,    80,  -300,  -300,  -300,  -300,  -300,   134,
    -300,  -300,   441,   380,  -300,   445,   272,  -300,  -300,   388,
     389,   385,  -300,  -300,   390,    22,  -300,  -300,    61,   386,
      61,  -300,   953,  -300,    61,   399,   387,  -300,   116,   391,
     218,  -300,   141,  -300,  -300
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    24,    23,    25,    26,    27,    28,
       0,     0,    51,    46,    52,    53,     0,    55,     0,    45,
       1,     3,    56,    40,     0,    41,     8,    34,     0,    42,
      58,     0,    43,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      23,     0,     0,     0,   139,    63,     0,    59,    76,    72,
      69,    83,    84,    73,   194,    71,    70,    64,   191,   137,
      66,    67,    68,     0,   195,   193,   192,     0,    65,   196,
       0,    44,     0,    49,     0,    29,    33,    32,     0,    37,
      54,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,   139,   194,   178,     0,   168,     0,   179,   172,
     193,   192,   180,   181,   182,   169,   247,   248,   170,   171,
       0,    75,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,     0,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,    62,    57,     0,    88,     0,
       0,    82,   253,     0,   254,    47,     0,     9,     0,    35,
       0,     0,     0,   111,   173,   183,   178,   238,   239,     0,
       0,     0,   237,   194,     0,   221,   224,   226,   230,   228,
       0,   185,     0,   186,   187,   188,   189,   190,     0,   110,
     102,   104,   106,   108,     0,     0,     0,   153,   146,   142,
       0,   145,     0,   143,     0,   153,   147,   141,     0,   116,
       0,     0,     0,   211,   212,     0,    87,     0,    79,    80,
      81,     0,     0,    60,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   258,     0,    50,     0,    30,     0,    38,     0,     0,
     112,     0,     0,   213,     0,   214,   235,     0,     0,   222,
     243,   244,     0,   184,     0,     0,     0,     0,     0,     0,
     240,   103,   105,   107,   109,   154,   159,   250,     0,     0,
       0,     0,     0,     0,   194,     0,     0,   193,   192,     0,
       0,     0,     0,     0,     0,     0,   140,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,    10,    36,     0,   252,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   219,   223,
     225,   227,   229,     0,     0,     0,     0,     0,   152,     0,
       0,     0,   136,   131,   132,   134,   135,     0,     0,   129,
       0,     0,     0,    77,    78,     0,   100,   101,    93,    94,
       0,    95,    99,    97,    98,    96,   197,    91,    92,     0,
     209,   199,     0,   200,     0,   210,   205,     0,     0,   259,
       0,     0,   216,   218,     0,     0,     0,   251,   241,   242,
     246,   220,     0,   158,   155,   161,   160,   149,     0,     0,
       0,   144,   133,   117,     0,     0,   201,   203,   208,    89,
      90,   198,   204,     0,     0,     0,   249,     0,     0,   215,
     217,   245,   156,     0,     0,     0,     0,     0,   119,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,   118,     0,   202,   206,   207,   232,   234,     0,
     157,   166,     0,     0,   151,     0,     0,   120,   121,     0,
       0,     0,   164,   162,     0,     0,   231,   233,     0,     0,
       0,   150,     0,   167,     0,     0,   127,   122,   125,   126,
     128,   123,   124,   165,   163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -300,  -300,   451,  -300,  -300,  -300,  -300,     6,   281,  -300,
    -300,  -300,  -300,  -300,   289,  -300,   -37,  -300,  -300,  -300,
    -300,  -300,   371,    10,   -10,  -300,   -61,  -300,  -300,  -300,
    -300,   146,  -300,  -300,  -300,  -300,  -300,  -300,   -49,  -258,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,   163,  -300,
     -50,   305,   -34,  -300,   323,  -300,  -143,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,    25,
    -107,   -41,  -300,  -300,  -300,   -40,   -54,   -56,   164,  -300,
    -300,  -300,  -256,  -300,  -300,  -300,  -300,  -300,  -300,   128,
    -300,  -300,   202,  -300,   186,  -300,  -299,  -300,   -47,  -285,
    -300,   -30,  -300,  -300,  -300
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    56,   264,   122,   104,   178,
     105,     8,    57,   266,   108,   180,     9,    10,    11,    45,
      38,    53,    54,    55,    75,    51,    76,   167,    77,    78,
     237,   238,    79,    80,    81,   164,    82,    83,   193,   380,
     375,    85,   291,   292,   293,   294,   270,    86,   155,   156,
     309,   447,   367,   463,   477,   497,   157,   425,    87,   422,
     124,    89,    90,   150,   218,   221,   219,    91,   354,   414,
     456,    92,   355,   416,   443,   490,   458,   489,   481,   233,
     126,   188,   128,   202,    93,   129,    95,    96,   235,   132,
     189,   190,   203,   411,   279,   204,   205,   206,   207,   341,
     133,   191,   192,   134,   282,   208,   135,   136,   137,   138,
      98,   139,   100,   174,   262
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    88,    84,   131,    97,   130,   226,    30,    31,    37,
     123,    94,   187,    39,   165,   340,   151,   152,   127,   106,
     383,    99,   107,   109,   383,    88,    84,   383,    97,   383,
     169,   169,   383,   383,   384,    94,   195,    40,   384,   272,
     274,   384,   169,   384,    49,    99,   384,   384,    65,   163,
      37,     3,   117,   -85,    37,   239,   276,    74,    58,   402,
     277,   103,   284,     1,     2,   389,   101,   102,   392,   186,
     394,   149,     3,   397,   398,    44,   403,   439,   161,   404,
     284,    74,    50,   424,   125,   120,   405,   440,   153,   154,
     404,   228,   492,   339,   273,   275,   195,   196,   197,   198,
     199,   346,  -191,   347,   234,   346,   243,   412,    37,    64,
      48,   476,   186,   280,   281,   289,   290,    88,    84,    42,
      97,   240,   314,   315,   333,   334,    46,    94,   408,   409,
     453,   454,   472,   473,   383,   383,   383,    99,   479,   480,
      47,   106,    65,   110,   107,   194,   109,   140,   384,   384,
     384,   217,   220,   222,   141,   225,   200,   201,   142,   169,
     143,   144,   158,   159,   160,   214,   162,   166,   215,   216,
     187,   168,   308,    74,   307,   450,   451,   452,   -61,   304,
     171,   172,   170,   231,   232,  -195,   173,   306,   241,   177,
     -31,   176,   179,   501,   -39,   224,   163,   181,   261,   182,
      12,   111,   112,   113,   114,   115,   268,   269,   239,   183,
    -196,   209,   210,   211,   212,   213,   227,   236,   421,   229,
     230,   278,   335,   295,   116,   117,    64,   186,   242,    67,
      37,   263,   317,   271,   303,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    70,    71,    26,
      27,    28,    29,   305,   283,   310,   284,   234,   120,   260,
     298,   285,   286,   287,   288,   186,   296,   297,   316,   381,
     299,   300,   302,   381,   240,    12,   381,   377,   381,   382,
     301,   381,   381,   382,   311,   312,   382,  -192,   382,   385,
     313,   382,   382,   385,   318,   319,   385,   320,   385,   321,
     322,   385,   385,   345,   323,   357,   358,   324,   360,   325,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   326,    26,    27,    28,    29,   327,   328,
     329,   330,   331,   342,   332,   336,   370,   371,   349,   337,
     338,   348,   343,   376,   413,   350,   351,   352,   356,   359,
     361,   362,   363,   364,   365,   366,    66,   373,   369,   399,
     386,   387,   400,   388,   390,   391,   393,   225,   395,   396,
     401,   195,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   381,   381,   381,   256,   257,   258,   259,
     339,   410,   407,   382,   382,   382,   442,   417,   433,   415,
     418,   444,   446,   385,   385,   385,   434,   419,   441,   423,
     420,   426,   427,   428,   429,   449,   478,   430,   431,   432,
     438,   435,   436,   455,   437,   448,   485,   445,   457,   459,
     460,   464,   465,   461,   466,   467,   500,   462,   499,   468,
     471,   469,    88,   496,   474,   482,   470,   475,   483,   484,
     486,   487,   498,   488,   494,   491,  -194,    41,   504,   265,
    -193,   374,   502,    12,   111,   112,   113,   114,   115,   267,
     223,   406,   368,   175,   244,   353,     0,   372,   493,   344,
     495,     0,     0,     0,   503,     0,     0,   116,   117,    64,
       0,     0,    67,     0,     0,   118,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    69,
      70,    71,    26,    27,    28,    29,     0,     0,   119,     0,
       0,   120,     0,     0,   121,    12,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     117,    64,     0,     0,    67,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29,     0,     0,
     119,     0,     0,   120,     0,     0,   121,    12,   184,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,   111,   112,   113,   114,   115,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
       0,     0,   119,   185,     0,     0,     0,     0,   121,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    12,    26,    27,    28,    29,     0,     0,   119,
      32,     0,     0,     0,     0,   121,     0,    34,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,   111,   112,   113,   114,   115,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,   116,   117,    64,     0,     0,
      67,    52,    12,   378,   379,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    69,    70,    71,
      26,    27,    28,    29,     0,     0,   116,   117,    64,   120,
       0,    67,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    69,    70,
      71,    26,    27,    28,    29,    12,     0,     0,     0,     0,
     120,     0,     0,     0,     0,    59,    60,     0,    61,    62,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,     0,    68,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    69,    70,    71,    26,    27,    28,    29,    72,    73,
      42,    12,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    12,
      26,    27,    28,    29,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    12,    26,    27,
      28,    29,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
     116,     0,    64,     0,     0,    67,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    69,    70,    71,    26,    27,    28,    29
};

static const yytype_int16 yycheck[] =
{
      10,    51,    51,    59,    51,    59,   149,     1,     2,     3,
      59,    51,   119,     3,    75,   271,    66,    67,    59,    56,
     319,    51,    56,    57,   323,    75,    75,   326,    75,   328,
       9,     9,   331,   332,   319,    75,     4,     0,   323,     4,
       4,   326,     9,   328,    38,    75,   331,   332,    30,    64,
      44,    33,    28,    68,    48,   162,    59,    51,    48,    60,
      63,    55,    63,    24,    25,   323,    62,    63,   326,   119,
     328,    65,    33,   331,   332,    61,    60,    60,    72,    63,
      63,    75,    59,   368,    59,    61,   342,    60,    36,    37,
      63,    70,    70,    61,    59,    59,     4,     5,     6,     7,
       8,    63,    69,    65,   160,    63,   167,    65,   102,    29,
      66,    31,   162,     4,     5,    64,    65,   167,   167,    58,
     167,   162,    62,    63,    62,    63,    58,   167,     4,     5,
       4,     5,    22,    23,   433,   434,   435,   167,     4,     5,
      58,   178,    30,    67,   178,   120,   180,    61,   433,   434,
     435,   145,   146,   147,    60,   149,    64,    65,    60,     9,
      61,    61,    61,    61,    61,   140,    61,    59,   143,   144,
     277,    60,   228,   167,   228,   433,   434,   435,    59,   228,
      60,    60,    69,   158,   159,    69,    61,   228,   163,    59,
      59,    64,    59,   492,    59,    66,    64,    61,   173,    61,
       3,     4,     5,     6,     7,     8,   181,   182,   315,    60,
      69,    60,    60,    60,    60,    60,    60,    60,   361,    61,
      61,    26,    60,    62,    27,    28,    29,   277,    68,    32,
     224,    65,   242,    68,   224,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,   228,    65,   230,    63,   313,    61,    62,
      64,    63,    63,    63,    63,   315,    62,    62,    65,   319,
      63,    63,    63,   323,   315,     3,   326,   318,   328,   319,
      64,   331,   332,   323,    63,    63,   326,    69,   328,   319,
      63,   331,   332,   323,    61,    61,   326,    61,   328,    61,
      61,   331,   332,   278,    61,   299,   300,    61,   302,    61,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    61,    52,    53,    54,    55,    61,    61,
      61,    61,    61,    68,    61,    60,   311,   312,     5,    63,
      62,     4,    68,   318,   354,     6,     8,     7,     4,     4,
      67,    60,    60,    60,    60,    60,    31,    60,    62,   334,
      62,    62,   337,    62,    62,    62,    62,   361,    62,    62,
       4,     4,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   433,   434,   435,    52,    53,    54,    55,
      61,    60,    62,   433,   434,   435,    15,    65,    63,    58,
      64,     4,     4,   433,   434,   435,    63,    65,    60,    62,
      64,    62,    62,    62,    62,   425,   463,    62,    62,    62,
      61,    63,    62,     4,    63,    60,   476,    64,    22,    65,
       4,    62,    62,    65,    62,    62,   492,   447,   492,    62,
       4,    63,   492,   492,    65,     4,   456,    64,    68,     4,
      62,    62,   492,    68,    68,    65,    69,     6,    59,   178,
      69,   315,   492,     3,     4,     5,     6,     7,     8,   180,
     147,   343,   309,   102,   169,   289,    -1,   313,   488,   277,
     490,    -1,    -1,    -1,   494,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    64,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    61,    -1,    -1,    64,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    64,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     3,    52,    53,    54,    55,    -1,    -1,    58,
      11,    -1,    -1,    -1,    -1,    64,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    27,    28,    29,    -1,    -1,
      32,    62,     3,     4,     5,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    27,    28,    29,    61,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    13,    14,    -1,    16,    17,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     3,
      52,    53,    54,    55,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     3,    52,    53,
      54,    55,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
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
       0,    24,    25,    33,    72,    73,    74,    75,    82,    87,
      88,    89,     3,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      78,    78,    11,    12,    18,    19,    20,    78,    91,    94,
       0,    73,    58,    95,    61,    90,    58,    58,    66,    78,
      59,    96,    62,    92,    93,    94,    76,    83,    94,    13,
      14,    16,    17,    21,    29,    30,    31,    32,    34,    49,
      50,    51,    56,    57,    78,    95,    97,    99,   100,   103,
     104,   105,   107,   108,   109,   112,   118,   129,   131,   132,
     133,   138,   142,   155,   156,   157,   158,   179,   181,   182,
     183,    62,    63,    78,    79,    81,    87,   133,    85,   133,
      67,     4,     5,     6,     7,     8,    27,    28,    35,    58,
      61,    64,    78,   109,   131,   150,   151,   152,   153,   156,
     157,   158,   160,   171,   174,   177,   178,   179,   180,   182,
      61,    60,    60,    61,    61,    11,    18,    19,    20,    78,
     134,   131,   131,    36,    37,   119,   120,   127,    61,    61,
      61,    78,    61,    64,   106,    97,    59,    98,    60,     9,
      69,    60,    60,    61,   184,    93,    64,    59,    80,    59,
      86,    61,    61,    60,     4,    59,   131,   151,   152,   161,
     162,   172,   173,   109,   150,     4,     5,     6,     7,     8,
      64,    65,   154,   163,   166,   167,   168,   169,   176,    60,
      60,    60,    60,    60,   150,   150,   150,    78,   135,   137,
      78,   136,    78,   135,    66,    78,   137,    60,    70,    61,
      61,   150,   150,   150,   158,   159,    60,   101,   102,   151,
     152,   150,    68,    97,   132,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    52,    53,    54,    55,
      62,   150,   185,    65,    77,    79,    84,    85,   150,   150,
     117,    68,     4,    59,     4,    59,    59,    63,    26,   165,
       4,     5,   175,    65,    63,    63,    63,    63,    63,    64,
      65,   113,   114,   115,   116,    62,    62,    62,    64,    63,
      63,    64,    63,    94,   109,   150,   152,   157,   158,   121,
     150,    63,    63,    63,    62,    63,    65,    95,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    60,    60,    63,    62,    61,
     163,   170,    68,    68,   173,   150,    63,    65,     4,     5,
       6,     8,     7,   175,   139,   143,     4,    78,    78,     4,
      78,    67,    60,    60,    60,    60,    60,   123,   129,    62,
     150,   150,   159,    60,   102,   111,   150,   152,     4,     5,
     110,   131,   156,   177,   180,   182,    62,    62,    62,   110,
      62,    62,   110,    62,   110,    62,    62,   110,   110,   150,
     150,     4,    60,    60,    63,   163,   170,    62,     4,     5,
      60,   164,    65,    95,   140,    58,   144,    65,    64,    65,
      64,   137,   130,    62,   180,   128,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    62,    63,    61,    60,
      60,    60,    15,   145,     4,    64,     4,   122,    60,    95,
     110,   110,   110,     4,     5,     4,   141,    22,   147,    65,
       4,    65,    95,   124,    62,    62,    62,    62,    62,    63,
      95,     4,    22,    23,    65,    64,    31,   125,   179,     4,
       5,   149,     4,    68,     4,   131,    62,    62,    68,   148,
     146,    65,    70,    95,    68,    95,   109,   126,   156,   157,
     158,   177,   182,    95,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    74,    76,    77,
      75,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    80,
      79,    79,    81,    81,    83,    84,    82,    86,    85,    85,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    96,    95,    95,    98,
      97,    97,    97,    97,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   101,   101,
     102,   102,   103,   104,   104,   106,   105,   107,   108,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   113,   112,   114,   112,   115,   112,   116,   112,
     112,   117,   112,   118,   119,   119,   121,   122,   120,   124,
     123,   125,   125,   126,   126,   126,   126,   126,   126,   128,
     127,   129,   130,   129,   129,   129,   129,   131,   131,   132,
     132,   133,   134,   134,   134,   134,   134,   134,   135,   135,
     136,   136,   137,   137,   139,   138,   141,   140,   140,   143,
     142,   145,   146,   144,   148,   147,   149,   147,   150,   150,
     150,   150,   150,   151,   151,   151,   151,   151,   151,   152,
     152,   152,   152,   152,   153,   153,   154,   154,   154,   154,
     154,   155,   155,   155,   155,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   157,   157,   157,   157,   158,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   164,
     163,   165,   163,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   170,   170,   171,   172,   172,   173,   173,
     174,   175,   175,   175,   175,   176,   176,   177,   177,   178,
     179,   180,   180,   181,   182,   183,   184,   184,   185,   185
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
       1,     1,     1,     1,     2,     2,     1,     5,     3,     1,
       1,     1,     2,     1,     1,     0,     4,     3,     2,     6,
       6,     5,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     0,     4,     2,     1,     1,     0,     0,     7,     0,
       5,     1,     4,     1,     1,     1,     1,     1,     1,     0,
       6,     5,     0,     6,     5,     5,     5,     1,     3,     1,
       4,     3,     2,     2,     5,     2,     2,     2,     6,     4,
       9,     7,     3,     1,     0,     6,     0,     4,     1,     0,
       6,     0,     0,     8,     0,     6,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     5,
       5,     6,     8,     6,     6,     5,     8,     8,     6,     5,
       5,     1,     1,     3,     3,     5,     4,     5,     4,     0,
       4,     0,     2,     3,     1,     3,     1,     3,     1,     3,
       1,     7,     5,     7,     5,     3,     3,     1,     1,     1,
       3,     3,     3,     1,     1,     5,     4,     1,     1,     6,
       4,     5,     4,     2,     2,     2,     3,     2,     1,     3
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
#line 219 "parser.y"
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
#line 2025 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 232 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; fprintf(fIR, "};\n");}
#line 2031 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 232 "parser.y"
                                                                                                                                        {fprintf(fparse, " : CLASS DEFINITION");}
#line 2037 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 235 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2043 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 236 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2049 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 237 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2055 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 238 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2061 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 239 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2067 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 240 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2073 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 241 "parser.y"
                                                     {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2079 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 242 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2085 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 243 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2091 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 244 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2097 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 245 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2103 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 246 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2109 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 247 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2115 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 248 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2121 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 249 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2127 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 250 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2133 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 251 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2139 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 252 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2145 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 255 "parser.y"
                                                     {fprintf(fIR, "\n");}
#line 2151 "y.tab.c"
    break;

  case 31: /* class_items: class_item  */
#line 256 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2157 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 264 "parser.y"
                                                        {
								level++; 
								if(class_search((yyvsp[-1].Str).str)!=-1 || struct_search((yyvsp[-1].Str).str)!=-1)
								{
									printf("%d ERROR: Struct or class name already exists\n", yylineno);
									exit(1);
								}
								
								else struct_insert((yyvsp[-1].Str).str);
								fprintf(fIR, "struct %s {\n", (yyvsp[-1].Str).text);
								inStruct = 1;
							}
#line 2174 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 276 "parser.y"
                                                                         { var_delete(level); level--; fprintf(fIR, "};\n"); inStruct = 0;}
#line 2180 "y.tab.c"
    break;

  case 36: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 276 "parser.y"
                                                                                                                                               {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2186 "y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 279 "parser.y"
                                             {fprintf(fIR, "\n");}
#line 2192 "y.tab.c"
    break;

  case 39: /* struct_items: declr_stmt  */
#line 280 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2198 "y.tab.c"
    break;

  case 40: /* function: function_head function_body  */
#line 284 "parser.y"
                                                        {
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
								var_delete(level);
								level--;
							}
#line 2210 "y.tab.c"
    break;

  case 41: /* function_head: func_definition Parameters  */
#line 293 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
//							fprintf(fIR, ")\n");
						}
#line 2222 "y.tab.c"
    break;

  case 42: /* func_definition: FUNC fdtype id  */
#line 303 "parser.y"
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
#line 2253 "y.tab.c"
    break;

  case 43: /* Parameters: '(' ')'  */
#line 331 "parser.y"
                                                  {fprintf(fIR, "()\n");}
#line 2259 "y.tab.c"
    break;

  case 44: /* Parameters: '(' param_list ')'  */
#line 332 "parser.y"
                                                                     {fprintf(fIR, "( %s )\n", (yyvsp[-1].Str).text);}
#line 2265 "y.tab.c"
    break;

  case 45: /* fdtype: dtype  */
#line 336 "parser.y"
                                                {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2271 "y.tab.c"
    break;

  case 46: /* fdtype: VOID  */
#line 337 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text = (yyvsp[0].str);}
#line 2277 "y.tab.c"
    break;

  case 47: /* param_list: param_list ',' param  */
#line 341 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+strlen(", ")+1);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
//							free(myText);
						}
#line 2290 "y.tab.c"
    break;

  case 48: /* param_list: param  */
#line 349 "parser.y"
                                                       {(yyval.Str).text = (yyvsp[0].Str).text;}
#line 2296 "y.tab.c"
    break;

  case 49: /* param: dtype id  */
#line 353 "parser.y"
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
#line 2350 "y.tab.c"
    break;

  case 50: /* param: dtype id '[' ']'  */
#line 402 "parser.y"
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
#line 2365 "y.tab.c"
    break;

  case 51: /* dtype: DATATYPE  */
#line 416 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str); dataType = 0;}
#line 2371 "y.tab.c"
    break;

  case 52: /* dtype: MATRIX  */
#line 417 "parser.y"
                                                         {(yyval.Str).str = (yyvsp[0].str); dataType = 3; (yyval.Str).text = "matrix";}
#line 2377 "y.tab.c"
    break;

  case 53: /* dtype: GRAPH  */
#line 418 "parser.y"
                                                        {(yyval.Str).str = (yyvsp[0].str); dataType = 4; (yyval.Str).text = "graph";}
#line 2383 "y.tab.c"
    break;

  case 54: /* dtype: VECT '<' dtype '>'  */
#line 419 "parser.y"
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
#line 2407 "y.tab.c"
    break;

  case 55: /* dtype: id  */
#line 438 "parser.y"
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
#line 2437 "y.tab.c"
    break;

  case 56: /* $@7: %empty  */
#line 465 "parser.y"
                                      {printTabs(); level++; fprintf(fIR, "{\n");}
#line 2443 "y.tab.c"
    break;

  case 57: /* function_body: '{' $@7 statements '}'  */
#line 465 "parser.y"
                                                                                                  {var_delete(level); level--; printTabs(); fprintf(fIR, "}\n");}
#line 2449 "y.tab.c"
    break;

  case 58: /* function_body: '{' '}'  */
#line 466 "parser.y"
                                                          { printTabs(); fprintf(fIR, "{ }\n");}
#line 2455 "y.tab.c"
    break;

  case 59: /* $@8: %empty  */
#line 469 "parser.y"
                                                    {fprintf(fIR, "\n");}
#line 2461 "y.tab.c"
    break;

  case 61: /* statements: statement  */
#line 470 "parser.y"
                                                            {fprintf(fIR, "\n");}
#line 2467 "y.tab.c"
    break;

  case 71: /* statement: return_stmt  */
#line 482 "parser.y"
                                                              {fprintf(fparse," : RETURN STATEMENT");}
#line 2473 "y.tab.c"
    break;

  case 74: /* statement: BREAK ';'  */
#line 485 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2479 "y.tab.c"
    break;

  case 75: /* statement: CONTINUE ';'  */
#line 486 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2485 "y.tab.c"
    break;

  case 77: /* print_stmt: PRINT '(' print_body ')' ';'  */
#line 491 "parser.y"
                                                 {
							fprintf(fparse, " : PRINT STATEMENT");
							printTabs();
							fprintf(fIR, "cout << %s << endl;", (yyvsp[-2].Str).text);
							
						 }
#line 2496 "y.tab.c"
    break;

  case 78: /* print_body: print_body ',' print_constants  */
#line 500 "parser.y"
                                                        {
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, " << ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
#line 2508 "y.tab.c"
    break;

  case 79: /* print_body: print_constants  */
#line 508 "parser.y"
                                                        {
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 2516 "y.tab.c"
    break;

  case 80: /* print_constants: constants  */
#line 513 "parser.y"
                                            {
							int a = !(strcmp((yyvsp[0].Str).str, "int")) || !(strcmp((yyvsp[0].Str).str, "float")) || !(strcmp((yyvsp[0].Str).str, "char")) || !(strcmp((yyvsp[0].Str).str, "string")) || !(strcmp((yyvsp[0].Str).str, "bool"));

							if(!a){
								printf("%d Error: Invalid argument as print object\n", yylineno);
								exit(1);
							}
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 2530 "y.tab.c"
    break;

  case 81: /* print_constants: extra_consts  */
#line 522 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[0].Str).text)+3);
							strcpy(myText, "\"");
							strcat(myText, (yyvsp[0].Str).text);
							strcat(myText, "\"");
							(yyval.Str).text = myText;
						}
#line 2542 "y.tab.c"
    break;

  case 82: /* unary_stmt: unary_op ';'  */
#line 531 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT"); printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text);}
#line 2548 "y.tab.c"
    break;

  case 85: /* $@9: %empty  */
#line 539 "parser.y"
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
#line 2564 "y.tab.c"
    break;

  case 86: /* label_stmt: id $@9 ':' function_body  */
#line 550 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2570 "y.tab.c"
    break;

  case 87: /* goto_stmt: GOTO id ';'  */
#line 553 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT"); printTabs(); fprintf(fIR, "goto %s;", (yyvsp[-1].Str).text);}
#line 2576 "y.tab.c"
    break;

  case 88: /* vect_stmt: vect_stmt_body ';'  */
#line 556 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2582 "y.tab.c"
    break;

  case 89: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 559 "parser.y"
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
#line 2634 "y.tab.c"
    break;

  case 90: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 606 "parser.y"
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
#line 2677 "y.tab.c"
    break;

  case 91: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 644 "parser.y"
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
#line 2712 "y.tab.c"
    break;

  case 92: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 674 "parser.y"
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
#line 2747 "y.tab.c"
    break;

  case 93: /* remove_body: INT_CONST  */
#line 707 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 2753 "y.tab.c"
    break;

  case 94: /* remove_body: FLOAT_CONST  */
#line 708 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 2759 "y.tab.c"
    break;

  case 95: /* remove_body: LHS  */
#line 709 "parser.y"
                                                      {(yyval.Str).str=(yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 2765 "y.tab.c"
    break;

  case 96: /* remove_body: func_calls  */
#line 710 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2771 "y.tab.c"
    break;

  case 97: /* remove_body: arith_op  */
#line 711 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2777 "y.tab.c"
    break;

  case 98: /* remove_body: logical_op  */
#line 712 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2783 "y.tab.c"
    break;

  case 99: /* remove_body: impr  */
#line 713 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2789 "y.tab.c"
    break;

  case 100: /* vect_append: RHS  */
#line 717 "parser.y"
                                              {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2795 "y.tab.c"
    break;

  case 101: /* vect_append: extra_consts  */
#line 718 "parser.y"
                                                               {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2801 "y.tab.c"
    break;

  case 102: /* $@10: %empty  */
#line 723 "parser.y"
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
#line 2860 "y.tab.c"
    break;

  case 103: /* return_stmt: RETURN RHS ';' $@10  */
#line 777 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2866 "y.tab.c"
    break;

  case 104: /* $@11: %empty  */
#line 779 "parser.y"
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
#line 2890 "y.tab.c"
    break;

  case 105: /* return_stmt: RETURN extra_consts ';' $@11  */
#line 798 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2896 "y.tab.c"
    break;

  case 106: /* $@12: %empty  */
#line 800 "parser.y"
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
#line 2939 "y.tab.c"
    break;

  case 107: /* return_stmt: RETURN graph_impr ';' $@12  */
#line 838 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2945 "y.tab.c"
    break;

  case 108: /* $@13: %empty  */
#line 840 "parser.y"
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
#line 2987 "y.tab.c"
    break;

  case 109: /* return_stmt: RETURN matrix_impr ';' $@13  */
#line 877 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 2993 "y.tab.c"
    break;

  case 110: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 879 "parser.y"
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
#line 3036 "y.tab.c"
    break;

  case 111: /* $@14: %empty  */
#line 918 "parser.y"
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
#line 3060 "y.tab.c"
    break;

  case 112: /* return_stmt: RETURN null ';' $@14  */
#line 937 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3066 "y.tab.c"
    break;

  case 113: /* loop_stmt: LOOP loop_type  */
#line 943 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 3072 "y.tab.c"
    break;

  case 116: /* $@15: %empty  */
#line 950 "parser.y"
                                                  {printTabs(); fprintf(fIR, "for(");}
#line 3078 "y.tab.c"
    break;

  case 117: /* $@16: %empty  */
#line 950 "parser.y"
                                                                                                 {fprintf(fIR, ") ");}
#line 3084 "y.tab.c"
    break;

  case 119: /* $@17: %empty  */
#line 954 "parser.y"
                                                                   {fprintf(fIR, "%s; ", (yyvsp[-1].Str).text);}
#line 3090 "y.tab.c"
    break;

  case 121: /* for_expr: unary_op  */
#line 958 "parser.y"
                                                   {fprintf(fIR, "%s ", (yyvsp[0].Str).text);}
#line 3096 "y.tab.c"
    break;

  case 122: /* for_expr: EXPR LHS '=' for_RHS  */
#line 959 "parser.y"
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
#line 3114 "y.tab.c"
    break;

  case 123: /* for_RHS: arith_op  */
#line 975 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3120 "y.tab.c"
    break;

  case 124: /* for_RHS: func_calls  */
#line 976 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3126 "y.tab.c"
    break;

  case 125: /* for_RHS: impr  */
#line 977 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3132 "y.tab.c"
    break;

  case 126: /* for_RHS: graph_impr  */
#line 978 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3138 "y.tab.c"
    break;

  case 127: /* for_RHS: vect_stmt_body  */
#line 979 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3144 "y.tab.c"
    break;

  case 128: /* for_RHS: matrix_impr  */
#line 980 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3150 "y.tab.c"
    break;

  case 129: /* $@18: %empty  */
#line 983 "parser.y"
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
#line 3168 "y.tab.c"
    break;

  case 131: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 999 "parser.y"
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
#line 3187 "y.tab.c"
    break;

  case 132: /* $@19: %empty  */
#line 1014 "parser.y"
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
									// printTabs();
									// fprintf(fIR, "%s = %s;", $2.text, $4.text);
								}
								else if(strcmp("matrix", (yyvsp[-3].details).type)==0)
								{
									
									if(dimAval != -1 && dummy_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										exit(1);
									}
									for(int i=0; i<dummy_size; i++)
									{
										if(dimBval != -1 && newArr[i]!=dimBval)
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
									if(dimAval != -1 && dummy_size!=dimAval)
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
#line 3276 "y.tab.c"
    break;

  case 133: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@19  */
#line 1098 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 3282 "y.tab.c"
    break;

  case 134: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 1100 "parser.y"
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
#line 3302 "y.tab.c"
    break;

  case 135: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 1115 "parser.y"
                                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3316 "y.tab.c"
    break;

  case 136: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 1124 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
						}
#line 3330 "y.tab.c"
    break;

  case 137: /* LHS: myId  */
#line 1136 "parser.y"
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
#line 3409 "y.tab.c"
    break;

  case 138: /* LHS: LHS ARROW myId  */
#line 1210 "parser.y"
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
#line 3503 "y.tab.c"
    break;

  case 139: /* myId: id  */
#line 1302 "parser.y"
                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3509 "y.tab.c"
    break;

  case 140: /* myId: id '[' RHS ']'  */
#line 1303 "parser.y"
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
#line 3529 "y.tab.c"
    break;

  case 141: /* declr_stmt: DECLR declr_body ';'  */
#line 1323 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT"); fprintf(fIR, ";");}
#line 3535 "y.tab.c"
    break;

  case 142: /* declr_body: DATATYPE id_list  */
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
#line 3587 "y.tab.c"
    break;

  case 143: /* declr_body: GRAPH graph_and_array_list  */
#line 1374 "parser.y"
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
								
								
								
								else // in struct
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
									if((yyvsp[0].Str).text[i] == '[') (yyvsp[0].Str).text[i] = '{';
									
									if((yyvsp[0].Str).text[i] == ']') (yyvsp[0].Str).text[i] = '}';
								}
								}
								arr_size=0;
								
								printTabs();
								fprintf(fIR, "graph %s", (yyvsp[0].Str).text);
							}
#line 3658 "y.tab.c"
    break;

  case 144: /* declr_body: VECT '<' dtype '>' id_list  */
#line 1441 "parser.y"
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
#line 3710 "y.tab.c"
    break;

  case 145: /* declr_body: MATRIX matrix_list  */
#line 1489 "parser.y"
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
								else // in struct
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
									for(int i=0; i<strlen((yyvsp[0].Str).text); i++){
										if((yyvsp[0].Str).text[i] == '(') (yyvsp[0].Str).text[i] = '{';
										if((yyvsp[0].Str).text[i] == ')') (yyvsp[0].Str).text[i] = '}';
									}
								}
								arr_size=0;
								printTabs();
								fprintf(fIR, "matrix %s", (yyvsp[0].Str).text);
							}
#line 3772 "y.tab.c"
    break;

  case 146: /* declr_body: DATATYPE graph_and_array_list  */
#line 1547 "parser.y"
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
#line 3826 "y.tab.c"
    break;

  case 147: /* declr_body: id id_list  */
#line 1597 "parser.y"
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
#line 3893 "y.tab.c"
    break;

  case 148: /* graph_and_array_list: graph_and_array_list ',' id '[' INT_CONST ']'  */
#line 1662 "parser.y"
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
#line 3920 "y.tab.c"
    break;

  case 149: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 1685 "parser.y"
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
#line 3945 "y.tab.c"
    break;

  case 150: /* matrix_list: matrix_list ',' id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1708 "parser.y"
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
#line 3974 "y.tab.c"
    break;

  case 151: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1733 "parser.y"
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
#line 4000 "y.tab.c"
    break;

  case 152: /* id_list: id_list ',' id  */
#line 1757 "parser.y"
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
#line 4017 "y.tab.c"
    break;

  case 153: /* id_list: id  */
#line 1770 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].Str).str;
								arr_size++;
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 4027 "y.tab.c"
    break;

  case 154: /* $@20: %empty  */
#line 1777 "parser.y"
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
#line 4046 "y.tab.c"
    break;

  case 156: /* $@21: %empty  */
#line 1794 "parser.y"
                                                             {fprintf(fIR, "else ");}
#line 4052 "y.tab.c"
    break;

  case 159: /* $@22: %empty  */
#line 1798 "parser.y"
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
#line 4071 "y.tab.c"
    break;

  case 161: /* $@23: %empty  */
#line 1815 "parser.y"
                                              {switch_insert(level); level++; fprintf(fIR, "{\n");}
#line 4077 "y.tab.c"
    break;

  case 162: /* $@24: %empty  */
#line 1815 "parser.y"
                                                                                                                      {printTabs(); fprintf(fIR, "default:\n");}
#line 4083 "y.tab.c"
    break;

  case 163: /* switch_body: '{' $@23 cases DEFAULT ':' $@24 function_body '}'  */
#line 1815 "parser.y"
                                                                                                                                                                                   { var_delete(level); level--; switch_delete(); printTabs(); fprintf(fIR, "}\n");}
#line 4089 "y.tab.c"
    break;

  case 164: /* $@25: %empty  */
#line 1818 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4095 "y.tab.c"
    break;

  case 166: /* $@26: %empty  */
#line 1819 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4101 "y.tab.c"
    break;

  case 168: /* RHS: constants  */
#line 1824 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4107 "y.tab.c"
    break;

  case 169: /* RHS: arith_op  */
#line 1825 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4113 "y.tab.c"
    break;

  case 170: /* RHS: logical_op  */
#line 1826 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4119 "y.tab.c"
    break;

  case 171: /* RHS: func_calls  */
#line 1827 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4125 "y.tab.c"
    break;

  case 172: /* RHS: impr  */
#line 1828 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4131 "y.tab.c"
    break;

  case 173: /* constants: INT_CONST  */
#line 1832 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 4137 "y.tab.c"
    break;

  case 174: /* constants: FLOAT_CONST  */
#line 1833 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 4143 "y.tab.c"
    break;

  case 175: /* constants: CHAR_CONST  */
#line 1834 "parser.y"
                                                             {(yyval.Str).str="char"; (yyval.Str).text = (yyvsp[0].str);}
#line 4149 "y.tab.c"
    break;

  case 176: /* constants: STR_CONST  */
#line 1835 "parser.y"
                                                            {(yyval.Str).str="string"; (yyval.Str).text = (yyvsp[0].str);}
#line 4155 "y.tab.c"
    break;

  case 177: /* constants: BOOL_CONST  */
#line 1836 "parser.y"
                                                             {(yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].str);}
#line 4161 "y.tab.c"
    break;

  case 178: /* constants: LHS  */
#line 1837 "parser.y"
                                                      {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4167 "y.tab.c"
    break;

  case 179: /* extra_consts: array_const  */
#line 1841 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4173 "y.tab.c"
    break;

  case 180: /* extra_consts: graph_const  */
#line 1842 "parser.y"
                                                             {(yyval.Str).str="graph"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4179 "y.tab.c"
    break;

  case 181: /* extra_consts: vect_const  */
#line 1843 "parser.y"
                                                            {
							char* myType = (char*)malloc(strlen((yyvsp[0].Str).str)+2);
							strcpy(myType, "*");
							strcat(myType, (yyvsp[0].Str).str);
							(yyval.Str).str = myType;
							 (yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 4191 "y.tab.c"
    break;

  case 182: /* extra_consts: matrix_const  */
#line 1850 "parser.y"
                                                              {(yyval.Str).str="matrix"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4197 "y.tab.c"
    break;

  case 183: /* extra_consts: '{' '}'  */
#line 1851 "parser.y"
                                                         {(yyval.Str).str="1"; (yyval.Str).text = "{}";}
#line 4203 "y.tab.c"
    break;

  case 184: /* array_const: '[' val_list ']'  */
#line 1855 "parser.y"
                                                        {
								(yyval.Str).str = (yyvsp[-1].Str).str;
								
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								
								(yyval.Str).text = myText;
							}
#line 4218 "y.tab.c"
    break;

  case 185: /* array_const: '[' ']'  */
#line 1866 "parser.y"
                                                        {
								(yyval.Str).str = "any";
								(yyval.Str).text = "{}";
							}
#line 4227 "y.tab.c"
    break;

  case 186: /* val_list: int_list  */
#line 1873 "parser.y"
                                                        { (yyval.Str).str = "int"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4233 "y.tab.c"
    break;

  case 187: /* val_list: float_list  */
#line 1875 "parser.y"
                                                        { (yyval.Str).str  = "float"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4239 "y.tab.c"
    break;

  case 188: /* val_list: char_list  */
#line 1877 "parser.y"
                                                        { (yyval.Str).str = "char"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4245 "y.tab.c"
    break;

  case 189: /* val_list: bool_list  */
#line 1879 "parser.y"
                                                        { (yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4251 "y.tab.c"
    break;

  case 190: /* val_list: str_list  */
#line 1881 "parser.y"
                                                        { (yyval.Str).str = "string"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4257 "y.tab.c"
    break;

  case 191: /* resultant: LHS  */
#line 1883 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4263 "y.tab.c"
    break;

  case 192: /* resultant: matrix_impr  */
#line 1884 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4269 "y.tab.c"
    break;

  case 193: /* resultant: graph_impr  */
#line 1885 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4275 "y.tab.c"
    break;

  case 194: /* resultant: vect_stmt_body  */
#line 1886 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4281 "y.tab.c"
    break;

  case 195: /* resultant: impr  */
#line 1887 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4287 "y.tab.c"
    break;

  case 196: /* resultant: func_calls  */
#line 1888 "parser.y"
                                                            {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4293 "y.tab.c"
    break;

  case 197: /* impr: resultant '.' LENGTH '(' ')'  */
#line 1892 "parser.y"
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
#line 4315 "y.tab.c"
    break;

  case 198: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 1909 "parser.y"
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
#line 4350 "y.tab.c"
    break;

  case 199: /* impr: resultant '.' TRACE '(' ')'  */
#line 1939 "parser.y"
                                                                              {
							//printf("%d::Initial resultant type: %s\n",yylineno, $1);
							if(strcmp("matrix", (yyvsp[-4].Str).str)){
								printf("%d Error: invalid type for trace\n", yylineno);
								exit(1);
							}else{
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(strlen((yyvsp[-4].Str).text)+strlen("trace()"));
								strcpy(myText, "trace(");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
						}
#line 4369 "y.tab.c"
    break;

  case 200: /* impr: resultant '.' STRLEN '(' ')'  */
#line 1954 "parser.y"
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
#line 4390 "y.tab.c"
    break;

  case 201: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 1971 "parser.y"
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
#line 4414 "y.tab.c"
    break;

  case 202: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 1991 "parser.y"
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
								
								char* myText = (char*)malloc(strlen((yyvsp[-7].Str).text) + strlen(".substr(, )") + 2*strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text) + 2);
								strcpy(myText, (yyvsp[-7].Str).text);
								strcat(myText, ".substr(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ", (");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "-");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ")+1)");
								
								(yyval.Str).text = myText;
							}
#line 4444 "y.tab.c"
    break;

  case 203: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 2017 "parser.y"
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
#line 4467 "y.tab.c"
    break;

  case 204: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 2038 "parser.y"
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
#line 4494 "y.tab.c"
    break;

  case 205: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 2061 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
							}
#line 4507 "y.tab.c"
    break;

  case 206: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 2070 "parser.y"
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
								char* myText = (char*)malloc(strlen((yyvsp[-7].Str).text)+strlen("shortest_path()")+3);
								strcpy(myText, "shortest_path(");
								strcat(myText, (yyvsp[-7].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4534 "y.tab.c"
    break;

  case 207: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 2093 "parser.y"
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
								char* myText = (char*)malloc(strlen((yyvsp[-7].Str).text)+strlen("shortest_path_value()")+3);
								strcpy(myText, "shortest_path_value(");
								strcat(myText, (yyvsp[-7].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4561 "y.tab.c"
    break;

  case 208: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 2119 "parser.y"
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
#line 4583 "y.tab.c"
    break;

  case 209: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 2137 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen((yyvsp[-4].Str).text)+strlen("transpose()"));
								strcpy(myText, "transpose(");
								strcat(myText, (yyvsp[-4].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4602 "y.tab.c"
    break;

  case 210: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 2152 "parser.y"
                                                        {
								(yyval.Str).str = "graph";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
							}
#line 4615 "y.tab.c"
    break;

  case 211: /* matr_body: RHS  */
#line 2162 "parser.y"
                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4621 "y.tab.c"
    break;

  case 212: /* matr_body: matrix_impr  */
#line 2163 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4627 "y.tab.c"
    break;

  case 213: /* graph_const: '{' graph_type1 '}'  */
#line 2166 "parser.y"
                                                              {
								printTabs();
								fprintf(fIR, "%s.setFlag(0);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4641 "y.tab.c"
    break;

  case 214: /* graph_const: '{' graph_type2 '}'  */
#line 2175 "parser.y"
                                                                      {
								printTabs();
								fprintf(fIR, "%s.setFlag(1);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4655 "y.tab.c"
    break;

  case 215: /* graph_type1: graph_type1 INT_CONST ':' int_list ';'  */
#line 2187 "parser.y"
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

								char* myText = (char*)malloc(strlen((yyvsp[-4].Str).text)+strlen(": ; ")+strlen((yyvsp[-3].str))+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-4].Str).text);
								strcat(myText, " ");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, ": ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ";");

								(yyval.Str).text = myText;
								
							}
#line 4689 "y.tab.c"
    break;

  case 216: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 2217 "parser.y"
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


								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen(": ; ")+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ": ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "; ");

								(yyval.Str).text = myText;
							}
#line 4720 "y.tab.c"
    break;

  case 217: /* graph_type2: graph_type2 INT_CONST ':' weight_list ';'  */
#line 2246 "parser.y"
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

								char* myText = (char*)malloc(strlen((yyvsp[-4].Str).text)+strlen(": ; ")+strlen((yyvsp[-3].str))+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-4].Str).text);
								strcat(myText, " ");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, ": ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ";");

								(yyval.Str).text = myText;
							}
#line 4751 "y.tab.c"
    break;

  case 218: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 2273 "parser.y"
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

								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen(": ; ")+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ": ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "; ");

								(yyval.Str).text = myText;
							}
#line 4780 "y.tab.c"
    break;

  case 219: /* $@27: %empty  */
#line 2300 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 4789 "y.tab.c"
    break;

  case 220: /* int_list: int_list ',' INT_CONST $@27  */
#line 2304 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4802 "y.tab.c"
    break;

  case 221: /* $@28: %empty  */
#line 2313 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 4811 "y.tab.c"
    break;

  case 222: /* int_list: INT_CONST $@28  */
#line 2317 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								(yyval.Str).text = (yyvsp[-1].str);
							}
#line 4820 "y.tab.c"
    break;

  case 223: /* float_list: float_list ',' FLOAT_CONST  */
#line 2324 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4834 "y.tab.c"
    break;

  case 224: /* float_list: FLOAT_CONST  */
#line 2334 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4844 "y.tab.c"
    break;

  case 225: /* char_list: char_list ',' CHAR_CONST  */
#line 2342 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4858 "y.tab.c"
    break;

  case 226: /* char_list: CHAR_CONST  */
#line 2352 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4868 "y.tab.c"
    break;

  case 227: /* bool_list: bool_list ',' BOOL_CONST  */
#line 2360 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4882 "y.tab.c"
    break;

  case 228: /* bool_list: BOOL_CONST  */
#line 2370 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4892 "y.tab.c"
    break;

  case 229: /* str_list: str_list ',' STR_CONST  */
#line 2378 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 4906 "y.tab.c"
    break;

  case 230: /* str_list: STR_CONST  */
#line 2388 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 4916 "y.tab.c"
    break;

  case 231: /* weight_list: weight_list ',' '(' INT_CONST ',' INT_CONST ')'  */
#line 2396 "parser.y"
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
#line 4933 "y.tab.c"
    break;

  case 232: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 2409 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4947 "y.tab.c"
    break;

  case 233: /* weight_list: weight_list ',' '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2419 "parser.y"
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
#line 4963 "y.tab.c"
    break;

  case 234: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2431 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 4977 "y.tab.c"
    break;

  case 235: /* vect_const: '{' vect_list '}'  */
#line 2442 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[-1].Str).str;
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 4990 "y.tab.c"
    break;

  case 236: /* vect_list: vect_list ',' vect_item  */
#line 2452 "parser.y"
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
#line 5013 "y.tab.c"
    break;

  case 237: /* vect_list: vect_item  */
#line 2470 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[0].Str).str;
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 5022 "y.tab.c"
    break;

  case 238: /* vect_item: constants  */
#line 2476 "parser.y"
                                                    {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5028 "y.tab.c"
    break;

  case 239: /* vect_item: extra_consts  */
#line 2477 "parser.y"
                                                               {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5034 "y.tab.c"
    break;

  case 240: /* matrix_const: '[' mat_list ']'  */
#line 2480 "parser.y"
                                                   {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Cols).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Cols).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 5046 "y.tab.c"
    break;

  case 241: /* int_float_list: int_float_list ',' INT_CONST  */
#line 2490 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5059 "y.tab.c"
    break;

  case 242: /* int_float_list: int_float_list ',' FLOAT_CONST  */
#line 2499 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5072 "y.tab.c"
    break;

  case 243: /* int_float_list: INT_CONST  */
#line 2508 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5081 "y.tab.c"
    break;

  case 244: /* int_float_list: FLOAT_CONST  */
#line 2513 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5090 "y.tab.c"
    break;

  case 245: /* mat_list: mat_list '[' int_float_list ']' ';'  */
#line 2520 "parser.y"
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
#line 5106 "y.tab.c"
    break;

  case 246: /* mat_list: '[' int_float_list ']' ';'  */
#line 2532 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-2].Cols).text);
								strcat(myText, "}");
								(yyval.Cols).text = myText;
								
							}
#line 5122 "y.tab.c"
    break;

  case 249: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 2550 "parser.y"
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
#line 5171 "y.tab.c"
    break;

  case 250: /* unary_op: UNARYOP '(' RHS ')'  */
#line 2596 "parser.y"
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
#line 5194 "y.tab.c"
    break;

  case 251: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 2616 "parser.y"
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
#line 5233 "y.tab.c"
    break;

  case 252: /* logical_op: NOT '(' RHS ')'  */
#line 2650 "parser.y"
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
#line 5253 "y.tab.c"
    break;

  case 253: /* call_stmt: func_calls ';'  */
#line 2668 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1; printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text); }
#line 5259 "y.tab.c"
    break;

  case 254: /* func_calls: call_head arguments  */
#line 2673 "parser.y"
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
#line 5286 "y.tab.c"
    break;

  case 255: /* call_head: CALL LHS  */
#line 2698 "parser.y"
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
#line 5304 "y.tab.c"
    break;

  case 256: /* arguments: '(' arg_list ')'  */
#line 2713 "parser.y"
                                                           {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text) + 3);
							strcpy(myText, "(");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							strcpy((yyval.Str).text, myText);
							free(myText);
						}
#line 5317 "y.tab.c"
    break;

  case 257: /* arguments: '(' ')'  */
#line 2721 "parser.y"
                                                          {(yyval.Str).text = "()";}
#line 5323 "y.tab.c"
    break;

  case 258: /* arg_list: RHS  */
#line 2724 "parser.y"
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
#line 5380 "y.tab.c"
    break;

  case 259: /* arg_list: arg_list ',' RHS  */
#line 2776 "parser.y"
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
#line 5434 "y.tab.c"
    break;


#line 5438 "y.tab.c"

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

#line 2827 "parser.y"


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
 	
 	int valid=0;
 	for (int i=0; i<func_size; i++){
 		if(!strcmp(func_symb[i].name, "main")) valid=1;
 	}
 	if(valid==0){
 		printf("ERROR: 'main' function function is not declared\n");
 		exit(1);
 	}

	fclose(fparse);
 	fclose(ft);
 	fclose(fp);
 }




