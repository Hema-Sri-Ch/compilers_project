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
    GETVAL = 293,                  /* GETVAL  */
    ADJNODE = 294,                 /* ADJNODE  */
    PRINTMATX = 295,               /* PRINTMATX  */
    PRINTARRAY = 296,              /* PRINTARRAY  */
    PRINTVECT = 297,               /* PRINTVECT  */
    PRINTGRAPH = 298,              /* PRINTGRAPH  */
    ADDVAL = 299,                  /* ADDVAL  */
    APPEND = 300,                  /* APPEND  */
    REMOVE = 301,                  /* REMOVE  */
    LENGTH = 302,                  /* LENGTH  */
    SORT = 303,                    /* SORT  */
    CLEAR = 304,                   /* CLEAR  */
    AT = 305,                      /* AT  */
    TRANSPOSE = 306,               /* TRANSPOSE  */
    TRACE = 307,                   /* TRACE  */
    TRAVERSAL = 308,               /* TRAVERSAL  */
    STRLEN = 309,                  /* STRLEN  */
    STRCUT = 310,                  /* STRCUT  */
    STRCMP = 311,                  /* STRCMP  */
    STRJOIN = 312,                 /* STRJOIN  */
    MATXOP = 313,                  /* MATXOP  */
    MAXTOGR = 314,                 /* MAXTOGR  */
    GRTOMATX = 315,                /* GRTOMATX  */
    SHPATH = 316,                  /* SHPATH  */
    SHPATH_VAL = 317,              /* SHPATH_VAL  */
    GOTO = 318,                    /* GOTO  */
    PRINT = 319                    /* PRINT  */
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
#define GETVAL 293
#define ADJNODE 294
#define PRINTMATX 295
#define PRINTARRAY 296
#define PRINTVECT 297
#define PRINTGRAPH 298
#define ADDVAL 299
#define APPEND 300
#define REMOVE 301
#define LENGTH 302
#define SORT 303
#define CLEAR 304
#define AT 305
#define TRANSPOSE 306
#define TRACE 307
#define TRAVERSAL 308
#define STRLEN 309
#define STRCUT 310
#define STRCMP 311
#define STRJOIN 312
#define MATXOP 313
#define MAXTOGR 314
#define GRTOMATX 315
#define SHPATH 316
#define SHPATH_VAL 317
#define GOTO 318
#define PRINT 319

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
	struct{
		char* text;
		char* name;
		char* type;
		char* eleType;
		int dimA;
		int dimB;
	} Details;
	struct
	{
		int cols;
		char* text;
	} Cols;

#line 403 "y.tab.c"

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
  YYSYMBOL_GETVAL = 38,                    /* GETVAL  */
  YYSYMBOL_ADJNODE = 39,                   /* ADJNODE  */
  YYSYMBOL_PRINTMATX = 40,                 /* PRINTMATX  */
  YYSYMBOL_PRINTARRAY = 41,                /* PRINTARRAY  */
  YYSYMBOL_PRINTVECT = 42,                 /* PRINTVECT  */
  YYSYMBOL_PRINTGRAPH = 43,                /* PRINTGRAPH  */
  YYSYMBOL_ADDVAL = 44,                    /* ADDVAL  */
  YYSYMBOL_APPEND = 45,                    /* APPEND  */
  YYSYMBOL_REMOVE = 46,                    /* REMOVE  */
  YYSYMBOL_LENGTH = 47,                    /* LENGTH  */
  YYSYMBOL_SORT = 48,                      /* SORT  */
  YYSYMBOL_CLEAR = 49,                     /* CLEAR  */
  YYSYMBOL_AT = 50,                        /* AT  */
  YYSYMBOL_TRANSPOSE = 51,                 /* TRANSPOSE  */
  YYSYMBOL_TRACE = 52,                     /* TRACE  */
  YYSYMBOL_TRAVERSAL = 53,                 /* TRAVERSAL  */
  YYSYMBOL_STRLEN = 54,                    /* STRLEN  */
  YYSYMBOL_STRCUT = 55,                    /* STRCUT  */
  YYSYMBOL_STRCMP = 56,                    /* STRCMP  */
  YYSYMBOL_STRJOIN = 57,                   /* STRJOIN  */
  YYSYMBOL_MATXOP = 58,                    /* MATXOP  */
  YYSYMBOL_MAXTOGR = 59,                   /* MAXTOGR  */
  YYSYMBOL_GRTOMATX = 60,                  /* GRTOMATX  */
  YYSYMBOL_SHPATH = 61,                    /* SHPATH  */
  YYSYMBOL_SHPATH_VAL = 62,                /* SHPATH_VAL  */
  YYSYMBOL_GOTO = 63,                      /* GOTO  */
  YYSYMBOL_PRINT = 64,                     /* PRINT  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_67_ = 67,                       /* ';'  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* ','  */
  YYSYMBOL_71_ = 71,                       /* '['  */
  YYSYMBOL_72_ = 72,                       /* ']'  */
  YYSYMBOL_73_ = 73,                       /* '<'  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '.'  */
  YYSYMBOL_76_ = 76,                       /* ':'  */
  YYSYMBOL_77_ = 77,                       /* '='  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_program_unit = 79,              /* program_unit  */
  YYSYMBOL_models = 80,                    /* models  */
  YYSYMBOL_model = 81,                     /* model  */
  YYSYMBOL_class = 82,                     /* class  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_id = 85,                        /* id  */
  YYSYMBOL_class_items = 86,               /* class_items  */
  YYSYMBOL_87_3 = 87,                      /* $@3  */
  YYSYMBOL_class_item = 88,                /* class_item  */
  YYSYMBOL_struct = 89,                    /* struct  */
  YYSYMBOL_90_4 = 90,                      /* $@4  */
  YYSYMBOL_91_5 = 91,                      /* $@5  */
  YYSYMBOL_struct_items = 92,              /* struct_items  */
  YYSYMBOL_93_6 = 93,                      /* $@6  */
  YYSYMBOL_function = 94,                  /* function  */
  YYSYMBOL_function_head = 95,             /* function_head  */
  YYSYMBOL_func_definition = 96,           /* func_definition  */
  YYSYMBOL_Parameters = 97,                /* Parameters  */
  YYSYMBOL_fdtype = 98,                    /* fdtype  */
  YYSYMBOL_param_list = 99,                /* param_list  */
  YYSYMBOL_param = 100,                    /* param  */
  YYSYMBOL_dtype = 101,                    /* dtype  */
  YYSYMBOL_function_body = 102,            /* function_body  */
  YYSYMBOL_103_7 = 103,                    /* $@7  */
  YYSYMBOL_statements = 104,               /* statements  */
  YYSYMBOL_105_8 = 105,                    /* $@8  */
  YYSYMBOL_statement = 106,                /* statement  */
  YYSYMBOL_independent_funcs = 107,        /* independent_funcs  */
  YYSYMBOL_print_stmt = 108,               /* print_stmt  */
  YYSYMBOL_print_body = 109,               /* print_body  */
  YYSYMBOL_print_constants = 110,          /* print_constants  */
  YYSYMBOL_unary_stmt = 111,               /* unary_stmt  */
  YYSYMBOL_jump_stmt = 112,                /* jump_stmt  */
  YYSYMBOL_label_stmt = 113,               /* label_stmt  */
  YYSYMBOL_114_9 = 114,                    /* $@9  */
  YYSYMBOL_goto_stmt = 115,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 116,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 117,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 118,              /* remove_body  */
  YYSYMBOL_vect_append = 119,              /* vect_append  */
  YYSYMBOL_return_stmt = 120,              /* return_stmt  */
  YYSYMBOL_121_10 = 121,                   /* $@10  */
  YYSYMBOL_122_11 = 122,                   /* $@11  */
  YYSYMBOL_123_12 = 123,                   /* $@12  */
  YYSYMBOL_124_13 = 124,                   /* $@13  */
  YYSYMBOL_125_14 = 125,                   /* $@14  */
  YYSYMBOL_loop_stmt = 126,                /* loop_stmt  */
  YYSYMBOL_loop_type = 127,                /* loop_type  */
  YYSYMBOL_for_loop = 128,                 /* for_loop  */
  YYSYMBOL_129_15 = 129,                   /* $@15  */
  YYSYMBOL_130_16 = 130,                   /* $@16  */
  YYSYMBOL_for_in = 131,                   /* for_in  */
  YYSYMBOL_132_17 = 132,                   /* $@17  */
  YYSYMBOL_for_expr = 133,                 /* for_expr  */
  YYSYMBOL_for_RHS = 134,                  /* for_RHS  */
  YYSYMBOL_while_loop = 135,               /* while_loop  */
  YYSYMBOL_136_18 = 136,                   /* $@18  */
  YYSYMBOL_expr_stmt = 137,                /* expr_stmt  */
  YYSYMBOL_138_19 = 138,                   /* $@19  */
  YYSYMBOL_LHS = 139,                      /* LHS  */
  YYSYMBOL_myId = 140,                     /* myId  */
  YYSYMBOL_declr_stmt = 141,               /* declr_stmt  */
  YYSYMBOL_declr_body = 142,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 143,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 144,              /* matrix_list  */
  YYSYMBOL_id_list = 145,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 146,              /* ifcond_stmt  */
  YYSYMBOL_147_20 = 147,                   /* $@20  */
  YYSYMBOL_if_body = 148,                  /* if_body  */
  YYSYMBOL_149_21 = 149,                   /* $@21  */
  YYSYMBOL_switch_stmt = 150,              /* switch_stmt  */
  YYSYMBOL_151_22 = 151,                   /* $@22  */
  YYSYMBOL_switch_body = 152,              /* switch_body  */
  YYSYMBOL_153_23 = 153,                   /* $@23  */
  YYSYMBOL_154_24 = 154,                   /* $@24  */
  YYSYMBOL_cases = 155,                    /* cases  */
  YYSYMBOL_156_25 = 156,                   /* $@25  */
  YYSYMBOL_157_26 = 157,                   /* $@26  */
  YYSYMBOL_RHS = 158,                      /* RHS  */
  YYSYMBOL_constants = 159,                /* constants  */
  YYSYMBOL_extra_consts = 160,             /* extra_consts  */
  YYSYMBOL_array_const = 161,              /* array_const  */
  YYSYMBOL_val_list = 162,                 /* val_list  */
  YYSYMBOL_resultant = 163,                /* resultant  */
  YYSYMBOL_impr = 164,                     /* impr  */
  YYSYMBOL_graph_impr = 165,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 166,              /* matrix_impr  */
  YYSYMBOL_matr_body = 167,                /* matr_body  */
  YYSYMBOL_graph_const = 168,              /* graph_const  */
  YYSYMBOL_graph_type1 = 169,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 170,              /* graph_type2  */
  YYSYMBOL_int_list = 171,                 /* int_list  */
  YYSYMBOL_172_27 = 172,                   /* $@27  */
  YYSYMBOL_173_28 = 173,                   /* $@28  */
  YYSYMBOL_float_list = 174,               /* float_list  */
  YYSYMBOL_char_list = 175,                /* char_list  */
  YYSYMBOL_bool_list = 176,                /* bool_list  */
  YYSYMBOL_str_list = 177,                 /* str_list  */
  YYSYMBOL_weight_list = 178,              /* weight_list  */
  YYSYMBOL_vect_const = 179,               /* vect_const  */
  YYSYMBOL_vect_list = 180,                /* vect_list  */
  YYSYMBOL_vect_item = 181,                /* vect_item  */
  YYSYMBOL_matrix_const = 182,             /* matrix_const  */
  YYSYMBOL_int_float_list = 183,           /* int_float_list  */
  YYSYMBOL_mat_list = 184,                 /* mat_list  */
  YYSYMBOL_arith_op = 185,                 /* arith_op  */
  YYSYMBOL_binary_op = 186,                /* binary_op  */
  YYSYMBOL_unary_op = 187,                 /* unary_op  */
  YYSYMBOL_logical_op = 188,               /* logical_op  */
  YYSYMBOL_call_stmt = 189,                /* call_stmt  */
  YYSYMBOL_func_calls = 190,               /* func_calls  */
  YYSYMBOL_call_head = 191,                /* call_head  */
  YYSYMBOL_arguments = 192,                /* arguments  */
  YYSYMBOL_arg_list = 193                  /* arg_list  */
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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  116
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  554

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      68,    69,     2,     2,    70,     2,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    67,
      73,    77,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   223,   223,   226,   227,   230,   231,   232,   235,   248,
     235,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   273,   273,   274,   277,   278,   282,   294,   281,   297,
     297,   298,   301,   311,   321,   349,   350,   354,   355,   359,
     367,   371,   420,   434,   435,   436,   437,   456,   483,   483,
     484,   487,   487,   488,   489,   490,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     509,   527,   536,   545,   554,   567,   576,   584,   590,   599,
     608,   611,   612,   616,   615,   630,   633,   636,   683,   721,
     751,   784,   785,   786,   787,   788,   789,   790,   794,   795,
     800,   799,   856,   855,   877,   876,   917,   916,   955,   995,
     994,  1020,  1023,  1024,  1027,  1027,  1027,  1031,  1031,  1035,
    1036,  1052,  1053,  1054,  1055,  1056,  1057,  1060,  1060,  1076,
    1091,  1090,  1181,  1196,  1205,  1217,  1299,  1397,  1398,  1418,
    1420,  1468,  1535,  1583,  1641,  1691,  1756,  1779,  1802,  1828,
    1849,  1871,  1889,  1902,  1910,  1910,  1927,  1927,  1928,  1931,
    1931,  1948,  1948,  1948,  1951,  1951,  1952,  1952,  1957,  1958,
    1959,  1960,  1961,  1965,  1966,  1967,  1968,  1969,  1970,  1974,
    1975,  1976,  1983,  1984,  1987,  1999,  2006,  2008,  2010,  2012,
    2014,  2017,  2018,  2019,  2020,  2021,  2022,  2026,  2043,  2073,
    2087,  2103,  2123,  2149,  2170,  2193,  2202,  2225,  2248,  2274,
    2292,  2307,  2317,  2344,  2345,  2348,  2357,  2368,  2398,  2427,
    2454,  2482,  2481,  2495,  2494,  2505,  2515,  2523,  2533,  2541,
    2551,  2559,  2569,  2577,  2590,  2600,  2612,  2624,  2634,  2652,
    2658,  2659,  2662,  2671,  2680,  2689,  2694,  2701,  2713,  2728,
    2729,  2732,  2778,  2798,  2832,  2850,  2855,  2880,  2895,  2904,
    2907,  2957
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
  "FUNC", "LOOP", "null", "FOR", "WHILE", "GETVAL", "ADJNODE", "PRINTMATX",
  "PRINTARRAY", "PRINTVECT", "PRINTGRAPH", "ADDVAL", "APPEND", "REMOVE",
  "LENGTH", "SORT", "CLEAR", "AT", "TRANSPOSE", "TRACE", "TRAVERSAL",
  "STRLEN", "STRCUT", "STRCMP", "STRJOIN", "MATXOP", "MAXTOGR", "GRTOMATX",
  "SHPATH", "SHPATH_VAL", "GOTO", "PRINT", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'['", "']'", "'<'", "'>'", "'.'", "':'", "'='", "$accept",
  "program_unit", "models", "model", "class", "$@1", "$@2", "id",
  "class_items", "$@3", "class_item", "struct", "$@4", "$@5",
  "struct_items", "$@6", "function", "function_head", "func_definition",
  "Parameters", "fdtype", "param_list", "param", "dtype", "function_body",
  "$@7", "statements", "$@8", "statement", "independent_funcs",
  "print_stmt", "print_body", "print_constants", "unary_stmt", "jump_stmt",
  "label_stmt", "$@9", "goto_stmt", "vect_stmt", "vect_stmt_body",
  "remove_body", "vect_append", "return_stmt", "$@10", "$@11", "$@12",
  "$@13", "$@14", "loop_stmt", "loop_type", "for_loop", "$@15", "$@16",
  "for_in", "$@17", "for_expr", "for_RHS", "while_loop", "$@18",
  "expr_stmt", "$@19", "LHS", "myId", "declr_stmt", "declr_body",
  "graph_and_array_list", "matrix_list", "id_list", "ifcond_stmt", "$@20",
  "if_body", "$@21", "switch_stmt", "$@22", "switch_body", "$@23", "$@24",
  "cases", "$@25", "$@26", "RHS", "constants", "extra_consts",
  "array_const", "val_list", "resultant", "impr", "graph_impr",
  "matrix_impr", "matr_body", "graph_const", "graph_type1", "graph_type2",
  "int_list", "$@27", "$@28", "float_list", "char_list", "bool_list",
  "str_list", "weight_list", "vect_const", "vect_list", "vect_item",
  "matrix_const", "int_float_list", "mat_list", "arith_op", "binary_op",
  "unary_op", "logical_op", "call_stmt", "func_calls", "call_head",
  "arguments", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-296)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-207)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,  1292,  1292,  1030,    54,  -296,    26,  -296,  -296,  -296,
     -28,    17,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,    46,    63,  -296,  -296,  -296,  -296,    25,  -296,
    1292,  -296,  -296,  -296,    66,  -296,   810,  -296,  -296,  -296,
    1085,  -296,  -296,   967,  -296,    27,  -296,  1292,    44,    72,
      65,   514,    69,    76,    85,    89,    95,  1140,  1292,  1292,
      30,    97,    99,   101,   102,   103,  1292,   104,     0,   967,
     110,   111,   119,  -296,  -296,  -296,  -296,  -296,  -296,   121,
    -296,  -296,  -296,   169,  -296,  -296,  -296,  -296,   117,  -296,
    -296,  -296,   127,  -296,   128,   129,  -296,  1085,   125,   132,
     135,  -296,  -296,   136,   139,  -296,  -296,  -296,  -296,  -296,
    -296,   138,   140,   142,   652,   870,    28,   141,   143,    15,
     147,  -296,   149,  -296,   144,   145,   150,   154,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,   152,   870,  -296,  -296,   870,
     870,  1292,  1292,  1292,   130,  1292,   155,     9,   169,   158,
     160,  -296,  -296,  -296,  1207,  1207,   870,   870,   870,   162,
     681,   870,   131,  -296,  -296,   967,  -296,  -296,  1292,  1317,
    -296,  -296,   750,  -296,  -296,   159,  -296,    44,  -296,    72,
     870,   870,  -296,   156,  -296,   169,  -296,  -296,    42,    53,
     -40,  -296,  -296,   192,  -296,  -296,  -296,  -296,  -296,   116,
    -296,   161,   164,   165,   166,   167,   170,    64,  -296,  -296,
    -296,  1335,  -296,  -296,   172,   173,   175,   178,   180,   182,
     183,   185,   178,   180,  1085,  -296,   182,  -296,   583,  -296,
     870,    -6,  -296,    -5,   186,   188,  -296,   184,   191,  -296,
      77,  -296,  -296,  -296,   196,   -28,  -296,  -296,   195,   201,
     202,   206,   208,   209,   210,   211,   212,   214,   216,   217,
     220,   223,   225,   226,   227,   229,   230,   232,  -296,  -296,
      79,  -296,   163,  -296,   197,  -296,   236,   233,  -296,    19,
     234,  -296,   238,  -296,  -296,   681,   870,  -296,  -296,  -296,
       3,  -296,   305,   307,   309,   308,   311,   116,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,   315,  1292,  1292,  1237,
    1292,   247,   256,   257,   263,   265,   267,   304,   269,  -296,
    -296,   870,   870,   870,   272,   681,  -296,  -296,   907,   907,
     274,   275,   907,   583,   907,   278,   279,   280,   907,   281,
     282,   907,   283,   907,   284,   285,   907,   907,  -296,   870,
    -296,  -296,   870,  -296,   332,    36,    37,   337,   289,  -296,
     290,   146,   293,  -296,  -296,  -296,  -296,  -296,    10,   -28,
     296,   291,   295,  -296,   299,    11,   297,  1292,  -296,  -296,
    -296,  -296,  -296,   298,    -3,  -296,   306,   312,   313,  -296,
    -296,  -296,  -296,   292,    15,   145,  -296,  -296,   152,   314,
    -296,  -296,   303,   316,  -296,  -296,   317,  -296,  -296,  -296,
     319,  -296,  -296,   321,  -296,   310,  -296,  -296,   324,   327,
    -296,   322,   329,  -296,  -296,   335,    55,    59,  -296,  -296,
    -296,  -296,  -296,   338,   359,  -296,  -296,  -296,  -296,   400,
     336,   339,  1267,   182,  -296,  -296,   341,   -28,  -296,  -296,
    -296,   907,  -296,   907,  -296,  -296,  -296,  -296,   907,   907,
     907,  -296,   151,   402,  -296,  -296,  -296,  -296,   390,   342,
     409,  1292,   347,    20,   -28,  -296,  -296,   351,   352,   354,
     355,   357,   358,   362,   363,   -28,   417,   137,  -296,   356,
      29,   364,   365,  -296,    50,  -296,   907,  -296,  -296,  -296,
    -296,  -296,   157,  -296,  -296,   430,   366,  -296,  -296,   436,
    1292,  1292,  -296,  -296,   372,   374,   375,   369,  -296,  -296,
     376,    43,    12,  -296,  -296,  -296,   -28,   370,   -28,  -296,
    -296,  1176,  -296,   -28,   383,   378,  -296,   145,   380,   184,
    -296,   152,  -296,  -296
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
       0,     0,    11,    30,    29,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,    23,    25,    26,
      27,    28,     0,     0,    53,    48,    54,    55,     0,    57,
       0,    47,     1,     3,    58,    42,     0,    43,     8,    36,
       0,    44,    60,     0,    45,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    23,     0,     0,     0,   147,    65,
       0,    61,     0,    78,    74,    71,    91,    92,    75,   204,
      73,    72,    66,   201,   145,    68,    69,    70,     0,   205,
     203,   202,     0,    67,   206,     0,    46,     0,    51,     0,
      31,    35,    34,     0,    39,    56,   183,   184,   185,   186,
     187,     0,     0,     0,     0,     0,     0,   147,   204,   188,
       0,   178,     0,   189,     0,   182,   203,   202,   190,   191,
     192,   179,   259,   260,   180,   181,     0,    77,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,     0,
       0,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    59,     0,    79,    96,     0,     0,
      90,   265,     0,   266,    49,     0,     9,     0,    37,     0,
       0,     0,   119,   183,   193,   188,   250,   251,     0,     0,
       0,   249,   204,     0,   233,   236,   238,   242,   240,     0,
     195,     0,   196,   197,   198,   199,   200,     0,   118,   110,
     112,     0,   114,   116,     0,     0,     0,   163,   154,   150,
       0,   153,     0,   151,     0,   163,   155,   149,     0,   124,
       0,     0,   206,     0,     0,     0,   223,   224,     0,    95,
       0,    87,    88,    89,     0,     0,    62,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,   271,
       0,    52,     0,    32,     0,    40,     0,     0,   120,     0,
       0,   225,     0,   226,   247,     0,     0,   234,   255,   256,
       0,   194,     0,     0,     0,     0,     0,     0,   252,   111,
     113,   115,   117,   164,   169,   262,     0,     0,     0,     0,
       0,     0,   204,     0,     0,   203,   202,     0,     0,    83,
      84,     0,     0,     0,     0,     0,   148,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
      10,    38,     0,   264,     0,     0,     0,     0,     0,   248,
       0,     0,     0,   231,   235,   237,   239,   241,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,   144,   139,
     140,   142,   143,     0,     0,   137,     0,     0,     0,    85,
      86,   101,   102,     0,   103,   107,   105,   106,   104,     0,
      81,    82,     0,     0,   108,   109,     0,   207,    99,   100,
       0,   220,   209,     0,   210,     0,   221,   215,     0,     0,
     270,     0,     0,   228,   230,     0,     0,     0,   263,   253,
     254,   258,   232,     0,   168,   165,   171,   170,   157,     0,
       0,     0,     0,   152,   141,   125,     0,     0,   211,   213,
     219,     0,   218,     0,    97,    98,   208,   214,     0,     0,
       0,   261,     0,     0,   227,   229,   257,   166,     0,     0,
       0,     0,     0,     0,     0,   127,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,   126,     0,   222,     0,   212,   216,   217,
     244,   246,     0,   167,   176,     0,     0,   160,   161,     0,
       0,     0,   128,   129,     0,     0,     0,     0,   174,   172,
       0,     0,     0,    80,   243,   245,     0,     0,     0,   158,
     159,     0,   177,     0,     0,   135,   130,   133,   134,   136,
     131,   132,   175,   173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -296,  -296,   445,  -296,  -296,  -296,  -296,    38,   273,  -296,
    -296,  -296,  -296,  -296,   276,  -296,   -49,  -296,  -296,  -296,
    -296,  -296,   360,     5,   -10,  -296,   -66,  -296,  -296,  -296,
    -296,  -296,   126,  -296,  -296,  -296,  -296,  -296,  -296,   -51,
      45,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,   153,
    -296,   -52,   286,   -47,  -296,   318,  -296,  -149,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
      33,  -110,   -54,  -296,  -296,   -34,   -31,   -57,   -58,   133,
    -296,  -296,  -296,  -274,  -296,  -296,  -296,  -296,  -296,  -296,
      94,  -296,  -296,   168,  -296,   171,  -296,  -295,  -296,   -48,
     -91,  -296,   -11,  -296,  -296,  -296
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    58,   282,   127,   109,   187,
     110,     8,    59,   284,   113,   189,     9,    10,    11,    47,
      40,    55,    56,    57,    79,    53,    80,   175,    81,    82,
      83,   250,   251,    84,    85,    86,   172,    87,    88,   202,
     403,   413,    90,   309,   310,   311,   312,   288,    91,   161,
     162,   327,   484,   393,   504,   522,   546,   163,   457,    92,
     454,   129,    94,    95,   156,   228,   231,   229,    96,   379,
     445,   495,    97,   380,   447,   478,   538,   497,   537,   527,
     246,   131,   197,   133,   211,   134,   135,   100,   101,   248,
     138,   198,   199,   212,   442,   297,   213,   214,   215,   216,
     366,   139,   200,   201,   140,   300,   217,   141,   142,   143,
     144,   103,   145,   105,   183,   280
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    93,    89,   137,   136,   102,   236,   132,    41,   111,
     128,   112,   114,   173,   196,   365,   157,   158,   178,    98,
     178,   178,    99,   204,   178,   122,   294,    93,    89,   178,
     295,   102,   204,   205,   206,   207,   208,    44,   178,    32,
      33,    39,   104,   406,   406,    98,   290,   406,    99,   406,
       1,     2,   178,   406,    42,    60,   406,   292,   406,     3,
     252,   406,   406,   329,   330,   125,   159,   160,   104,   221,
     221,   171,   195,   371,    67,   372,   -93,     3,    51,    66,
     371,   521,   443,   451,    39,    46,   238,   364,    39,   541,
    -201,    78,   502,   436,   130,   108,   106,   107,    50,   209,
     210,   518,    67,   433,   434,   155,   302,   435,   291,   256,
     247,    48,    93,    93,   169,   540,   253,    78,   195,   293,
     298,   299,   474,    93,    89,   302,   475,   102,    49,   435,
     241,   243,    52,    99,    99,   307,   308,   146,   111,   115,
     112,    98,   114,   147,    99,    39,   334,   335,   358,   359,
     439,   440,   148,   242,   242,   492,   493,   149,   203,   515,
     516,   525,   526,   150,   104,   164,   406,   165,   406,   166,
     167,   168,   170,   406,   406,   406,   174,   -63,   178,   224,
     326,   325,   225,   226,   324,   196,   176,   322,   177,   227,
     230,   232,   179,   235,   180,   181,   185,   182,   186,   244,
     245,   -33,   188,   234,   254,   -41,   190,   255,   191,   192,
     218,   406,   171,    78,   219,   279,   220,   222,   296,   221,
    -205,   223,   237,   286,   287,   252,   239,  -206,   240,   249,
     360,   281,   289,   301,   302,   303,   304,   305,   453,   321,
     306,   313,   314,   195,   315,   337,   550,   407,   407,   316,
     317,   407,   318,   407,   319,   320,   331,   407,   332,  -202,
     407,   333,   407,   338,   361,   407,   407,   385,   336,   339,
     340,   323,    39,   328,   341,   247,   342,   343,   344,   345,
     346,   253,   347,   195,   348,   349,   404,   404,   350,   415,
     404,   351,   404,   352,   353,   354,   404,   355,   356,   404,
     357,   404,   363,   456,   404,   404,   362,   405,   405,   373,
     367,   405,   374,   405,   368,   375,   376,   405,   377,   381,
     405,   387,   405,   388,   389,   405,   405,   408,   408,   370,
     390,   408,   391,   408,   392,    68,   432,   408,   395,   399,
     408,   204,   408,   410,   411,   408,   408,   417,   418,   419,
     421,   422,   424,   426,   427,   382,   383,   364,   386,   438,
     441,   446,   461,   448,   396,   397,   449,   455,   452,   444,
     407,   450,   407,   463,   477,   458,   414,   407,   407,   407,
     468,   459,   460,   462,   409,   464,   465,   412,   466,   416,
     467,   471,   430,   420,   469,   431,   423,   470,   425,   472,
     483,   428,   429,   473,   479,   476,   494,   480,   485,   404,
     481,   404,   496,   499,   498,   407,   404,   404,   404,   501,
     505,   514,   506,   507,   508,   235,   509,   510,   517,   500,
     405,   511,   405,   512,   528,   519,   520,   405,   405,   405,
     530,   533,   529,   534,   535,   536,   543,   486,   539,   553,
     408,    43,   408,  -204,   404,  -203,   523,   408,   408,   408,
     283,   400,   437,   369,   257,   285,   398,   184,   531,   532,
       0,   233,     0,     0,   503,   405,     0,     0,   378,     0,
     394,     0,     0,   549,   548,   513,     0,     0,     0,    93,
     545,     0,     0,     0,     0,   408,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,   488,     0,
     547,     0,     0,   489,   490,   491,     0,    12,   116,   117,
     118,   119,   120,     0,     0,     0,   542,     0,   544,     0,
     551,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,   121,   122,    66,     0,     0,    69,     0,     0,   123,
       0,   524,    13,     0,     0,     0,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      73,    74,    75,    28,    29,    30,    31,     0,     0,   124,
       0,     0,   125,     0,     0,   126,    12,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,    66,     0,     0,    69,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    73,
      74,    75,    28,    29,    30,    31,     0,     0,   124,     0,
       0,   125,     0,     0,   126,    12,   193,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,   116,   117,   118,   119,   120,
      13,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,     0,   124,   194,    13,
       0,     0,     0,   126,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,     0,   124,     0,     0,     0,
       0,     0,   126,    12,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,    66,
       0,     0,    69,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    73,    74,    75,    28,
      29,    30,    31,    12,     0,     0,     0,     0,   125,   278,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    12,   116,   117,   118,   119,   120,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,    66,
       0,     0,    69,     0,     0,     0,     0,     0,    13,     0,
      12,   401,   402,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    73,    74,    75,    28,
      29,    30,    31,     0,   121,   122,    66,     0,   125,    69,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    73,    74,    75,    28,    29,    30,    31,
      12,     0,     0,     0,     0,   125,     0,     0,     0,     0,
      61,    62,     0,    63,    64,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
       0,    70,     0,     0,     0,    13,     0,     0,    71,    72,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    73,    74,    75,    28,    29,    30,    31,
      76,    77,    44,    12,     0,     0,     0,     0,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    28,
      29,    30,    31,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    12,    28,    29,    30,    31,     0,     0,
       0,   151,     0,     0,     0,     0,     0,     0,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    12,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,   121,     0,    66,     0,     0,    69,     0,
      12,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    73,    74,    75,    28,    29,    30,    31,    69,
      12,   384,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    73,    74,    75,    28,    29,    30,    31,
      12,   482,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    12,    28,    29,    30,    31,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      13,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,   258,   259,   260,     0,     0,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   258,   259,     0,   274,   275,   276,   277,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,     0,     0,     0,   274,   275,   276,   277
};

static const yytype_int16 yycheck[] =
{
      10,    53,    53,    61,    61,    53,   155,    61,     3,    58,
      61,    58,    59,    79,   124,   289,    68,    69,     9,    53,
       9,     9,    53,     4,     9,    28,    66,    79,    79,     9,
      70,    79,     4,     5,     6,     7,     8,    65,     9,     1,
       2,     3,    53,   338,   339,    79,     4,   342,    79,   344,
      24,    25,     9,   348,     0,    50,   351,     4,   353,    33,
     170,   356,   357,    69,    69,    68,    36,    37,    79,    75,
      75,    71,   124,    70,    30,    72,    76,    33,    40,    29,
      70,    31,    72,    72,    46,    68,    77,    68,    50,    77,
      75,    53,    72,   367,    61,    57,    69,    70,    73,    71,
      72,    72,    30,    67,    67,    67,    70,    70,    66,   175,
     168,    65,   164,   165,    76,    72,   170,    79,   170,    66,
       4,     5,    67,   175,   175,    70,    67,   175,    65,    70,
     164,   165,    66,   164,   165,    71,    72,    68,   187,    74,
     187,   175,   189,    67,   175,   107,    69,    70,    69,    70,
       4,     5,    67,   164,   165,     4,     5,    68,   125,    22,
      23,     4,     5,    68,   175,    68,   461,    68,   463,    68,
      68,    68,    68,   468,   469,   470,    66,    66,     9,   146,
     238,   238,   149,   150,   238,   295,    67,   238,    67,   151,
     152,   153,    75,   155,    67,    67,    71,    68,    66,   166,
     167,    66,    66,    73,   171,    66,    68,    76,    68,    67,
      67,   506,    71,   175,    67,   182,    67,    67,    26,    75,
      75,    67,    67,   190,   191,   335,    68,    75,    68,    67,
      67,    72,    76,    72,    70,    70,    70,    70,   387,   234,
      70,    69,    69,   295,    69,   255,   541,   338,   339,    71,
      70,   342,    70,   344,    71,    70,    70,   348,    70,    75,
     351,    70,   353,    68,    67,   356,   357,   319,    72,    68,
      68,   238,   234,   240,    68,   333,    68,    68,    68,    68,
      68,   335,    68,   335,    68,    68,   338,   339,    68,   343,
     342,    68,   344,    68,    68,    68,   348,    68,    68,   351,
      68,   353,    69,   394,   356,   357,    70,   338,   339,     4,
      76,   342,     5,   344,    76,     6,     8,   348,     7,     4,
     351,    74,   353,    67,    67,   356,   357,   338,   339,   296,
      67,   342,    67,   344,    67,    31,     4,   348,    69,    67,
     351,     4,   353,    69,    69,   356,   357,    69,    69,    69,
      69,    69,    69,    69,    69,   317,   318,    68,   320,    69,
      67,    65,    70,    72,   331,   332,    71,    69,    71,   379,
     461,    72,   463,    70,    15,    69,   343,   468,   469,   470,
      70,    69,    69,    69,   339,    69,    69,   342,    69,   344,
      69,    69,   359,   348,    70,   362,   351,    70,   353,    70,
     452,   356,   357,    68,     4,    67,     4,    71,    67,   461,
      71,   463,    22,     4,    72,   506,   468,   469,   470,    72,
      69,     4,    70,    69,    69,   387,    69,    69,    72,   481,
     461,    69,   463,    70,     4,    71,    71,   468,   469,   470,
       4,    69,    76,    69,    69,    76,    76,   457,    72,    66,
     461,     6,   463,    75,   506,    75,   504,   468,   469,   470,
     187,   335,   368,   295,   178,   189,   333,   107,   520,   521,
      -1,   153,    -1,    -1,   484,   506,    -1,    -1,   307,    -1,
     327,    -1,    -1,   541,   541,   495,    -1,    -1,    -1,   541,
     541,    -1,    -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,   463,    -1,
     541,    -1,    -1,   468,   469,   470,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,   536,    -1,   538,    -1,
     541,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,
      -1,   506,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    68,    -1,    -1,    71,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    66,    38,
      -1,    -1,    -1,    71,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     3,    -1,    -1,    -1,    -1,    68,    69,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,     3,     4,     5,     6,     7,     8,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
       3,     4,     5,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    27,    28,    29,    -1,    68,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       3,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      13,    14,    -1,    16,    17,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     3,    59,
      60,    61,    62,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     3,    59,    60,    61,    62,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,     3,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    27,    -1,    29,    -1,    -1,    32,    -1,
       3,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    32,
       3,     4,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       3,     4,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     3,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    38,    39,    -1,    59,    60,    61,    62,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    79,    80,    81,    82,    89,    94,
      95,    96,     3,    38,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
      61,    62,    85,    85,    11,    12,    18,    19,    20,    85,
      98,   101,     0,    80,    65,   102,    68,    97,    65,    65,
      73,    85,    66,   103,    69,    99,   100,   101,    83,    90,
     101,    13,    14,    16,    17,    21,    29,    30,    31,    32,
      34,    41,    42,    56,    57,    58,    63,    64,    85,   102,
     104,   106,   107,   108,   111,   112,   113,   115,   116,   117,
     120,   126,   137,   139,   140,   141,   146,   150,   163,   164,
     165,   166,   187,   189,   190,   191,    69,    70,    85,    86,
      88,    94,   141,    92,   141,    74,     4,     5,     6,     7,
       8,    27,    28,    35,    65,    68,    71,    85,   117,   139,
     158,   159,   160,   161,   163,   164,   165,   166,   168,   179,
     182,   185,   186,   187,   188,   190,    68,    67,    67,    68,
      68,    11,    18,    19,    20,    85,   142,   139,   139,    36,
      37,   127,   128,   135,    68,    68,    68,    68,    68,    85,
      68,    71,   114,   104,    66,   105,    67,    67,     9,    75,
      67,    67,    68,   192,   100,    71,    66,    87,    66,    93,
      68,    68,    67,     4,    66,   139,   159,   160,   169,   170,
     180,   181,   117,   158,     4,     5,     6,     7,     8,    71,
      72,   162,   171,   174,   175,   176,   177,   184,    67,    67,
      67,    75,    67,    67,   158,   158,   158,    85,   143,   145,
      85,   144,    85,   143,    73,    85,   145,    67,    77,    68,
      68,   163,   190,   163,   158,   158,   158,   166,   167,    67,
     109,   110,   159,   160,   158,    76,   104,   140,    38,    39,
      40,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    59,    60,    61,    62,    69,   158,
     193,    72,    84,    86,    91,    92,   158,   158,   125,    76,
       4,    66,     4,    66,    66,    70,    26,   173,     4,     5,
     183,    72,    70,    70,    70,    70,    70,    71,    72,   121,
     122,   123,   124,    69,    69,    69,    71,    70,    70,    71,
      70,   101,   117,   158,   160,   165,   166,   129,   158,    69,
      69,    70,    70,    70,    69,    70,    72,   102,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      67,    67,    70,    69,    68,   171,   178,    76,    76,   181,
     158,    70,    72,     4,     5,     6,     8,     7,   183,   147,
     151,     4,    85,    85,     4,   139,    85,    74,    67,    67,
      67,    67,    67,   131,   137,    69,   158,   158,   167,    67,
     110,     4,     5,   118,   139,   164,   185,   188,   190,   118,
      69,    69,   118,   119,   158,   160,   118,    69,    69,    69,
     118,    69,    69,   118,    69,   118,    69,    69,   118,   118,
     158,   158,     4,    67,    67,    70,   171,   178,    69,     4,
       5,    67,   172,    72,   102,   148,    65,   152,    72,    71,
      72,    72,    71,   145,   138,    69,   188,   136,    69,    69,
      69,    70,    69,    70,    69,    69,    69,    69,    70,    70,
      70,    69,    70,    68,    67,    67,    67,    15,   153,     4,
      71,    71,     4,   139,   130,    67,   102,   118,   118,   118,
     118,   118,     4,     5,     4,   149,    22,   155,    72,     4,
     139,    72,    72,   102,   132,    69,    70,    69,    69,    69,
      69,    69,    70,   102,     4,    22,    23,    72,    72,    71,
      71,    31,   133,   187,   118,     4,     5,   157,     4,    76,
       4,   139,   139,    69,    69,    69,    76,   156,   154,    72,
      72,    77,   102,    76,   102,   117,   134,   164,   165,   166,
     185,   190,   102,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    83,    84,
      82,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    87,    86,    86,    88,    88,    90,    91,    89,    93,
      92,    92,    94,    95,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   103,   102,
     102,   105,   104,   104,   104,   104,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   109,   109,   110,   110,
     111,   112,   112,   114,   113,   115,   116,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     121,   120,   122,   120,   123,   120,   124,   120,   120,   125,
     120,   126,   127,   127,   129,   130,   128,   132,   131,   133,
     133,   134,   134,   134,   134,   134,   134,   136,   135,   137,
     138,   137,   137,   137,   137,   139,   139,   140,   140,   141,
     142,   142,   142,   142,   142,   142,   143,   143,   144,   144,
     144,   144,   145,   145,   147,   146,   149,   148,   148,   151,
     150,   153,   154,   152,   156,   155,   157,   155,   158,   158,
     158,   158,   158,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   160,   160,   161,   161,   162,   162,   162,   162,
     162,   163,   163,   163,   163,   163,   163,   164,   164,   164,
     164,   164,   164,   164,   165,   165,   165,   165,   165,   166,
     166,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   172,   171,   173,   171,   174,   174,   175,   175,   176,
     176,   177,   177,   178,   178,   178,   178,   179,   180,   180,
     181,   181,   182,   183,   183,   183,   183,   184,   184,   185,
     185,   186,   187,   188,   188,   189,   190,   191,   192,   192,
     193,   193
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     0,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     1,     1,     0,     0,     8,     0,
       3,     1,     2,     2,     3,     2,     3,     1,     1,     3,
       1,     2,     4,     1,     1,     1,     4,     1,     0,     4,
       2,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
      10,     5,     5,     4,     4,     5,     3,     1,     1,     1,
       2,     1,     1,     0,     4,     3,     2,     6,     6,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     0,
       4,     2,     1,     1,     0,     0,     7,     0,     5,     1,
       4,     1,     1,     1,     1,     1,     1,     0,     6,     5,
       0,     6,     5,     5,     5,     1,     3,     1,     4,     3,
       2,     2,     5,     2,     2,     2,     6,     4,     9,     9,
       7,     7,     3,     1,     0,     6,     0,     4,     1,     0,
       6,     0,     0,     8,     0,     6,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     5,
       5,     6,     8,     6,     6,     5,     8,     8,     6,     6,
       5,     5,     8,     1,     1,     3,     3,     5,     4,     5,
       4,     0,     4,     0,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     7,     5,     7,     5,     3,     3,     1,
       1,     1,     3,     3,     3,     1,     1,     5,     4,     1,
       1,     6,     4,     5,     4,     2,     2,     2,     3,     2,
       3,     1
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
#line 235 "parser.y"
                                                       {
							level++; 
							inClass = 1;
							if(class_search((yyvsp[-1].Str).str)!=-1 || struct_search((yyvsp[-1].Str).str)!=-1)
							{
								printf("%d ERROR: Struct or class name already exists\n", yylineno);
								exit(1);
							}
								
							else class_insert((yyvsp[-1].Str).str);
							
							fprintf(fIR, "class %s {\npublic:", (yyvsp[-1].Str).text);
							
						}
#line 2156 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 248 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; fprintf(fIR, "};\n");}
#line 2162 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 248 "parser.y"
                                                                                                                                        {fprintf(fparse, " : CLASS DEFINITION");}
#line 2168 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 251 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2174 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 252 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2180 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 253 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2186 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 254 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2192 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 255 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2198 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 256 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2204 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 257 "parser.y"
                                                     {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2210 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 258 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2216 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 259 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2222 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 260 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2228 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 261 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2234 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 262 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2240 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 263 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2246 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 264 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2252 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 265 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2258 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 266 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2264 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 267 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2270 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 268 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2276 "y.tab.c"
    break;

  case 29: /* id: ADDVAL  */
#line 269 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2282 "y.tab.c"
    break;

  case 30: /* id: GETVAL  */
#line 270 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2288 "y.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 273 "parser.y"
                                                     {fprintf(fIR, "\n");}
#line 2294 "y.tab.c"
    break;

  case 33: /* class_items: class_item  */
#line 274 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2300 "y.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 282 "parser.y"
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
#line 2317 "y.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 294 "parser.y"
                                                                         { var_delete(level); level--; fprintf(fIR, "};\n"); inStruct = 0;}
#line 2323 "y.tab.c"
    break;

  case 38: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 294 "parser.y"
                                                                                                                                               {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2329 "y.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 297 "parser.y"
                                             {fprintf(fIR, "\n");}
#line 2335 "y.tab.c"
    break;

  case 41: /* struct_items: declr_stmt  */
#line 298 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2341 "y.tab.c"
    break;

  case 42: /* function: function_head function_body  */
#line 302 "parser.y"
                                                        {
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
								var_delete(level);
								level--;
							}
#line 2353 "y.tab.c"
    break;

  case 43: /* function_head: func_definition Parameters  */
#line 311 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
//							fprintf(fIR, ")\n");
						}
#line 2365 "y.tab.c"
    break;

  case 44: /* func_definition: FUNC fdtype id  */
#line 321 "parser.y"
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
#line 2396 "y.tab.c"
    break;

  case 45: /* Parameters: '(' ')'  */
#line 349 "parser.y"
                                                  {fprintf(fIR, "()\n");}
#line 2402 "y.tab.c"
    break;

  case 46: /* Parameters: '(' param_list ')'  */
#line 350 "parser.y"
                                                                     {fprintf(fIR, "( %s )\n", (yyvsp[-1].Str).text);}
#line 2408 "y.tab.c"
    break;

  case 47: /* fdtype: dtype  */
#line 354 "parser.y"
                                                {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2414 "y.tab.c"
    break;

  case 48: /* fdtype: VOID  */
#line 355 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text = (yyvsp[0].str);}
#line 2420 "y.tab.c"
    break;

  case 49: /* param_list: param_list ',' param  */
#line 359 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+strlen(", ")+1);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
//							free(myText);
						}
#line 2433 "y.tab.c"
    break;

  case 50: /* param_list: param  */
#line 367 "parser.y"
                                                       {(yyval.Str).text = (yyvsp[0].Str).text;}
#line 2439 "y.tab.c"
    break;

  case 51: /* param: dtype id  */
#line 371 "parser.y"
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
#line 2493 "y.tab.c"
    break;

  case 52: /* param: dtype id '[' ']'  */
#line 420 "parser.y"
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
#line 2508 "y.tab.c"
    break;

  case 53: /* dtype: DATATYPE  */
#line 434 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str); dataType = 0;}
#line 2514 "y.tab.c"
    break;

  case 54: /* dtype: MATRIX  */
#line 435 "parser.y"
                                                         {(yyval.Str).str = (yyvsp[0].str); dataType = 3; (yyval.Str).text = "matrix";}
#line 2520 "y.tab.c"
    break;

  case 55: /* dtype: GRAPH  */
#line 436 "parser.y"
                                                        {(yyval.Str).str = (yyvsp[0].str); dataType = 4; (yyval.Str).text = "graph";}
#line 2526 "y.tab.c"
    break;

  case 56: /* dtype: VECT '<' dtype '>'  */
#line 437 "parser.y"
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
#line 2550 "y.tab.c"
    break;

  case 57: /* dtype: id  */
#line 456 "parser.y"
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
#line 2580 "y.tab.c"
    break;

  case 58: /* $@7: %empty  */
#line 483 "parser.y"
                                      {printTabs(); level++; fprintf(fIR, "{\n");}
#line 2586 "y.tab.c"
    break;

  case 59: /* function_body: '{' $@7 statements '}'  */
#line 483 "parser.y"
                                                                                                  {var_delete(level); level--; printTabs(); fprintf(fIR, "}\n");}
#line 2592 "y.tab.c"
    break;

  case 60: /* function_body: '{' '}'  */
#line 484 "parser.y"
                                                          { printTabs(); fprintf(fIR, "{ }\n");}
#line 2598 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 487 "parser.y"
                                                    {fprintf(fIR, "\n");}
#line 2604 "y.tab.c"
    break;

  case 63: /* statements: statement  */
#line 488 "parser.y"
                                                            {fprintf(fIR, "\n");}
#line 2610 "y.tab.c"
    break;

  case 73: /* statement: return_stmt  */
#line 500 "parser.y"
                                                              {fprintf(fparse," : RETURN STATEMENT");}
#line 2616 "y.tab.c"
    break;

  case 76: /* statement: BREAK ';'  */
#line 503 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2622 "y.tab.c"
    break;

  case 77: /* statement: CONTINUE ';'  */
#line 504 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2628 "y.tab.c"
    break;

  case 80: /* independent_funcs: resultant '.' ADDVAL '(' remove_body ',' remove_body ',' remove_body ')'  */
#line 509 "parser.y"
                                                                                                           {
							if(strcmp((yyvsp[-9].Str).str, "matrix")){
								printf("%d Error: Only matrix can call addVal function\n", yylineno);
								exit(1);
							}
							
							int a = !strcmp((yyvsp[-5].Str).str, "int");
							int b = !strcmp((yyvsp[-3].Str).str, "int");
							int c = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "bool");
							
							if(!(a && b && c)){
								printf("%d Error: Invalid argument types for addVal function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.addValue(%s, %s, %s);\n", (yyvsp[-9].Str).text, (yyvsp[-5].Str).text, (yyvsp[-3].Str).text, (yyvsp[-1].Str).text);
						}
#line 2651 "y.tab.c"
    break;

  case 81: /* independent_funcs: resultant '.' PRINTMATX '(' ')'  */
#line 527 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-4].Str).str, "matrix")){
								printf("%d Error: Only matrix can call printMatrix function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printMatrix();\n", (yyvsp[-4].Str).text);
						}
#line 2665 "y.tab.c"
    break;

  case 82: /* independent_funcs: resultant '.' PRINTGRAPH '(' ')'  */
#line 536 "parser.y"
                                                                                   {
							if(strcmp((yyvsp[-4].Str).str, "graph")){
								printf("%d Error: Only graph can call printGraph function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printGraph();\n", (yyvsp[-4].Str).text);
						}
#line 2679 "y.tab.c"
    break;

  case 83: /* independent_funcs: PRINTARRAY '(' resultant ')'  */
#line 545 "parser.y"
                                                                               {
							if((yyvsp[-1].Str).text[0] == '#'){
								printf("%d Error: Invalid argument for printArray function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printArray(%s);\n", (yyvsp[-1].Str).text);
						}
#line 2693 "y.tab.c"
    break;

  case 84: /* independent_funcs: PRINTVECT '(' resultant ')'  */
#line 554 "parser.y"
                                                                              {
							if((yyvsp[-1].Str).str[0] != '*'){
								printf("%d Error: Invalid argument for printVect function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printVect(%s);\n", (yyvsp[-1].Str).text);
						}
#line 2707 "y.tab.c"
    break;

  case 85: /* print_stmt: PRINT '(' print_body ')' ';'  */
#line 568 "parser.y"
                                                 {
							fprintf(fparse, " : PRINT STATEMENT");
							printTabs();
							fprintf(fIR, "cout << %s << endl;", (yyvsp[-2].Str).text);
							
						 }
#line 2718 "y.tab.c"
    break;

  case 86: /* print_body: print_body ',' print_constants  */
#line 577 "parser.y"
                                                        {
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, " << ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
#line 2730 "y.tab.c"
    break;

  case 87: /* print_body: print_constants  */
#line 585 "parser.y"
                                                        {
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 2738 "y.tab.c"
    break;

  case 88: /* print_constants: constants  */
#line 590 "parser.y"
                                            {
							int a = !(strcmp((yyvsp[0].Str).str, "int")) || !(strcmp((yyvsp[0].Str).str, "float")) || !(strcmp((yyvsp[0].Str).str, "char")) || !(strcmp((yyvsp[0].Str).str, "string")) || !(strcmp((yyvsp[0].Str).str, "bool"));

							if(!a){
								printf("%d Error: Invalid argument as print object\n", yylineno);
								exit(1);
							}
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 2752 "y.tab.c"
    break;

  case 89: /* print_constants: extra_consts  */
#line 599 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[0].Str).text)+3);
							strcpy(myText, "\"");
							strcat(myText, (yyvsp[0].Str).text);
							strcat(myText, "\"");
							(yyval.Str).text = myText;
						}
#line 2764 "y.tab.c"
    break;

  case 90: /* unary_stmt: unary_op ';'  */
#line 608 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT"); printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text);}
#line 2770 "y.tab.c"
    break;

  case 93: /* $@9: %empty  */
#line 616 "parser.y"
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
#line 2786 "y.tab.c"
    break;

  case 94: /* label_stmt: id $@9 ':' function_body  */
#line 627 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2792 "y.tab.c"
    break;

  case 95: /* goto_stmt: GOTO id ';'  */
#line 630 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT"); printTabs(); fprintf(fIR, "goto %s;", (yyvsp[-1].Str).text);}
#line 2798 "y.tab.c"
    break;

  case 96: /* vect_stmt: vect_stmt_body ';'  */
#line 633 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2804 "y.tab.c"
    break;

  case 97: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 636 "parser.y"
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
#line 2856 "y.tab.c"
    break;

  case 98: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 683 "parser.y"
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
#line 2899 "y.tab.c"
    break;

  case 99: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 721 "parser.y"
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
#line 2934 "y.tab.c"
    break;

  case 100: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 751 "parser.y"
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
#line 2969 "y.tab.c"
    break;

  case 101: /* remove_body: INT_CONST  */
#line 784 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 2975 "y.tab.c"
    break;

  case 102: /* remove_body: FLOAT_CONST  */
#line 785 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 2981 "y.tab.c"
    break;

  case 103: /* remove_body: LHS  */
#line 786 "parser.y"
                                                      {(yyval.Str).str=(yyvsp[0].Details).type; (yyval.Str).text = (yyvsp[0].Details).text;}
#line 2987 "y.tab.c"
    break;

  case 104: /* remove_body: func_calls  */
#line 787 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2993 "y.tab.c"
    break;

  case 105: /* remove_body: arith_op  */
#line 788 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2999 "y.tab.c"
    break;

  case 106: /* remove_body: logical_op  */
#line 789 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3005 "y.tab.c"
    break;

  case 107: /* remove_body: impr  */
#line 790 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3011 "y.tab.c"
    break;

  case 108: /* vect_append: RHS  */
#line 794 "parser.y"
                                              {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3017 "y.tab.c"
    break;

  case 109: /* vect_append: extra_consts  */
#line 795 "parser.y"
                                                               {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3023 "y.tab.c"
    break;

  case 110: /* $@10: %empty  */
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
#line 3082 "y.tab.c"
    break;

  case 111: /* return_stmt: RETURN RHS ';' $@10  */
#line 854 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3088 "y.tab.c"
    break;

  case 112: /* $@11: %empty  */
#line 856 "parser.y"
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
#line 3112 "y.tab.c"
    break;

  case 113: /* return_stmt: RETURN extra_consts ';' $@11  */
#line 875 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3118 "y.tab.c"
    break;

  case 114: /* $@12: %empty  */
#line 877 "parser.y"
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
#line 3161 "y.tab.c"
    break;

  case 115: /* return_stmt: RETURN graph_impr ';' $@12  */
#line 915 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3167 "y.tab.c"
    break;

  case 116: /* $@13: %empty  */
#line 917 "parser.y"
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
#line 3209 "y.tab.c"
    break;

  case 117: /* return_stmt: RETURN matrix_impr ';' $@13  */
#line 954 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3215 "y.tab.c"
    break;

  case 118: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 956 "parser.y"
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
#line 3258 "y.tab.c"
    break;

  case 119: /* $@14: %empty  */
#line 995 "parser.y"
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
#line 3282 "y.tab.c"
    break;

  case 120: /* return_stmt: RETURN null ';' $@14  */
#line 1014 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3288 "y.tab.c"
    break;

  case 121: /* loop_stmt: LOOP loop_type  */
#line 1020 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 3294 "y.tab.c"
    break;

  case 124: /* $@15: %empty  */
#line 1027 "parser.y"
                                                  {printTabs(); fprintf(fIR, "for(");}
#line 3300 "y.tab.c"
    break;

  case 125: /* $@16: %empty  */
#line 1027 "parser.y"
                                                                                                 {fprintf(fIR, ") ");}
#line 3306 "y.tab.c"
    break;

  case 127: /* $@17: %empty  */
#line 1031 "parser.y"
                                                                   {fprintf(fIR, "%s; ", (yyvsp[-1].Str).text);}
#line 3312 "y.tab.c"
    break;

  case 129: /* for_expr: unary_op  */
#line 1035 "parser.y"
                                                   {fprintf(fIR, "%s ", (yyvsp[0].Str).text);}
#line 3318 "y.tab.c"
    break;

  case 130: /* for_expr: EXPR LHS '=' for_RHS  */
#line 1036 "parser.y"
                                                                       {
							if(strcmp((yyvsp[-2].Details).type, (yyvsp[0].Str).str)){
								int a = !strcmp((yyvsp[-2].Details).type, "int") || !strcmp((yyvsp[-2].Details).type, "float") || !strcmp((yyvsp[-2].Details).type, "bool");
								int b = !strcmp((yyvsp[0].Str).str, "int") || !strcmp((yyvsp[0].Str).str, "float") || !strcmp((yyvsp[0].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
								
								fprintf(fIR, "%s = %s", (yyvsp[-2].Details).text, (yyvsp[0].Str).text);
							}
						}
#line 3336 "y.tab.c"
    break;

  case 131: /* for_RHS: arith_op  */
#line 1052 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3342 "y.tab.c"
    break;

  case 132: /* for_RHS: func_calls  */
#line 1053 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3348 "y.tab.c"
    break;

  case 133: /* for_RHS: impr  */
#line 1054 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3354 "y.tab.c"
    break;

  case 134: /* for_RHS: graph_impr  */
#line 1055 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3360 "y.tab.c"
    break;

  case 135: /* for_RHS: vect_stmt_body  */
#line 1056 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3366 "y.tab.c"
    break;

  case 136: /* for_RHS: matrix_impr  */
#line 1057 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3372 "y.tab.c"
    break;

  case 137: /* $@18: %empty  */
#line 1060 "parser.y"
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
#line 3390 "y.tab.c"
    break;

  case 139: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 1076 "parser.y"
                                                               {
							if(strcmp((yyvsp[-3].Details).type, (yyvsp[-1].Str).str)){
								int a = !strcmp((yyvsp[-3].Details).type, "int") || !strcmp((yyvsp[-3].Details).type, "float") || !strcmp((yyvsp[-3].Details).type, "bool");
								int b = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3409 "y.tab.c"
    break;

  case 140: /* $@19: %empty  */
#line 1091 "parser.y"
                                                        {
								int dimAval, dimBval;
								dimAval = (yyvsp[-3].Details).dimA;
								dimBval = (yyvsp[-3].Details).dimB;
								char* element_type;
								element_type = (yyvsp[-3].Details).eleType;
								/*int ind = var_search($2.name);
								
								if(ind==-1) 
								{
									ind = class_declr_search($2.name, class_size-1);
									dimAval = class_symb[class_size-1].declr_list[ind].dim_A;
									dimBval = class_symb[class_size-1].declr_list[ind].dim_B;
									element_type = class_symb[class_size-1].declr_list[ind].ele_type;
								}
								else
								{
									dimAval = var_symb[ind].dim_A;
									dimBval = var_symb[ind].dim_B;
									element_type = var_symb[ind].ele_type;
								}*/
								 

								if(strcmp("graph", (yyvsp[-3].Details).type)==0)
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
								else if(strcmp("matrix", (yyvsp[-3].Details).type)==0)
								{
									
									if(dimAval != -1 && dummy_size!=dimAval) 
									{
										printf("%d ERROR: Number of rows mismatch\n", yylineno);
										printf("dummy_size: %d, dimAval: %d\n", dummy_size, dimAval); 
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
									fprintf(fIR, "%s.vals = %s;", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
								}
								else if(strcmp((yyvsp[-3].Details).type, "array") == 0)
								{
									if(strcmp(element_type, (yyvsp[-1].Str).str) && strcmp((yyvsp[-1].Str).str, "any")!=0)
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
									fprintf(fIR, "%s = %s;", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
								}
								
								else if(strcmp((yyvsp[-3].Details).type, (yyvsp[-1].Str).str)){
									printf("%d Error: Expression statement type mismatch %s != %s\n", yylineno, (yyvsp[-3].Details).type, (yyvsp[-1].Str).str);
									exit(1);
								}
								
								else{
									printTabs();
									fprintf(fIR, "%s = %s;", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
								}
								
								
							}
#line 3502 "y.tab.c"
    break;

  case 141: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@19  */
#line 1179 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 3508 "y.tab.c"
    break;

  case 142: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 1181 "parser.y"
                                                                              {
							if(strcmp((yyvsp[-3].Details).type, (yyvsp[-1].Str).str)){
								int a = !strcmp((yyvsp[-3].Details).type, "int") || !strcmp((yyvsp[-3].Details).type, "float") || !strcmp((yyvsp[-3].Details).type, "bool");
								int b = !strcmp((yyvsp[-1].Str).str, "int") || !strcmp((yyvsp[-1].Str).str, "float") || !strcmp((yyvsp[-1].Str).str, "bool");
							
								if(!(a && b)){
									printf("%d Error: Expression statement, type mismatch\n", yylineno);
									exit(1);
								}
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
							
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3528 "y.tab.c"
    break;

  case 143: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 1196 "parser.y"
                                                                               {
							if(strcmp((yyvsp[-3].Details).type, (yyvsp[-1].Str).str)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3542 "y.tab.c"
    break;

  case 144: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 1205 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-3].Details).type, (yyvsp[-1].Str).str)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].Details).text, (yyvsp[-1].Str).text);
						}
#line 3556 "y.tab.c"
    break;

  case 145: /* LHS: myId  */
#line 1217 "parser.y"
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
								(yyval.Details).name = (yyvsp[0].Str).str;
								(yyval.Details).dimA = class_symb[class_size-1].declr_list[j].dim_A;
								(yyval.Details).dimB = class_symb[class_size-1].declr_list[j].dim_B;
								(yyval.Details).eleType = class_symb[class_size-1].declr_list[j].ele_type;
								if(strcmp(class_symb[class_size-1].declr_list[j].type, "vect") == 0) {
								    char* result;
									char* A = "*";
								    result = (char*)malloc(strlen(A) + strlen(class_symb[class_size-1].declr_list[j].ele_type) + 1);
								    strcpy(result, A);
								    strcat(result, class_symb[class_size-1].declr_list[j].ele_type);
										    // dataType = 2;
				   				     (yyval.Details).type = result;
								}
								
								else {
									(yyval.Details).type = class_symb[class_size-1].declr_list[j].type;
								}
								// printf("%s : %s\n", $$.name, $$.type);
								classIndex=class_size-1;
							}
							
							// declare variable
							else if(i>=0){
								(yyval.Details).name = (yyvsp[0].Str).str;
								(yyval.Details).dimA = var_symb[i].dim_A;
								(yyval.Details).dimB = var_symb[i].dim_B;
								(yyval.Details).eleType = var_symb[i].ele_type;
								if(!strcmp(var_symb[i].type, "vect")){
									char* result;
									char* A = "*";
									result = (char*)malloc(strlen(A) + strlen(var_symb[i].ele_type) + 1);
									strcpy(result, A);
					     	    	strcat(result, var_symb[i].ele_type);
										    // dataType = 2;
						   			(yyval.Details).type = result;
								}
								
								else{
									(yyval.Details).type = var_symb[i].type;
								}
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// class function
							else if(l >= 0){
								(yyval.Details).name = (yyvsp[0].Str).str;
								(yyval.Details).type = class_symb[class_size-1].func_list[l].type;
								classIndex = class_size-1;
								funcIndex = l;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// normal funciton
							else if(k >= 0){
								(yyval.Details).name = (yyvsp[0].Str).str;
								(yyval.Details).type = func_symb[k].type;
								funcIndex = k;
								// printf("%s : %s\n", $$.name, $$.type);
							}
							
							// printf("%d:: LHS.name - %s; LHS.type - %s\n", yylineno, $$.name, $$.type);
							
							(yyval.Details).text = (yyvsp[0].Str).text;
							LeftName = (yyvsp[0].Str).text;
							
						}
#line 3643 "y.tab.c"
    break;

  case 146: /* LHS: LHS ARROW myId  */
#line 1299 "parser.y"
                                                                 {
						
							char* dType = (yyvsp[-2].Details).type;
							
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
										printf("%d Error: Accessing undefined function/attribute %s of class %s\n", yylineno,(yyvsp[0].Str).str, (yyvsp[-2].Details).type);
										// printClassNode(class_symb[i]);
										exit(1);
									}
									
									if(j >= 0){
										(yyval.Details).name = (yyvsp[0].Str).str;
										(yyval.Details).type = class_symb[i].declr_list[j].type;
										(yyval.Details).dimA = class_symb[i].declr_list[j].dim_A;
										(yyval.Details).dimB = class_symb[i].declr_list[j].dim_B;
										(yyval.Details).eleType = class_symb[i].declr_list[j].ele_type;
										if(strcmp(class_symb[i].declr_list[j].type, "vect") == 0){
										    char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(class_symb[i].declr_list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, class_symb[i].declr_list[j].type);
										    // dataType = 2;
						   				     (yyval.Details).type = result;
										}
										
										else {
											(yyval.Details).type = class_symb[i].declr_list[j].type;	
										}
									}
								
									else if(k >= 0){
									
										// set global variables of required indices for call statements
										funcIndex = k;
										classIndex = i;
										(yyval.Details).name = (yyvsp[0].Str).str;
										(yyval.Details).type = "func"; // can be ignored
									}
								}
							}
							
							else {
								// item defined in struct, now check its attributes
								int j = struct_declr_search((yyvsp[0].Str).str, i);
								if(j < 0){
								
									// item is not attribute of this struct
									printf("%d Error: Accessing undefined attribute of struct %s\n", yylineno, (yyvsp[-2].Details).name);
									exit(1);
								}
								
								else{
									(yyval.Details).name = (yyvsp[0].Str).str;
									(yyval.Details).dimA = struct_symb[i].list[j].dim_A;
									(yyval.Details).dimB = struct_symb[i].list[j].dim_B;
									(yyval.Details).eleType = struct_symb[i].list[j].ele_type;
									if(!strcmp(struct_symb[i].list[j].type, "vect")){
										char* result;
										    char* A = "*";
										    result = (char*)malloc(strlen(A) + strlen(struct_symb[i].list[j].ele_type) + 1);
										    strcpy(result, A);
										    strcat(result, struct_symb[i].list[j].ele_type);
										    // dataType = 2;
						   				     (yyval.Details).type = result;
									}
									
									else{
										(yyval.Details).type = struct_symb[i].list[j].type;
									}
								}
							}
							
							char* myText = (char*)malloc(strlen((yyvsp[-2].Details).text)+strlen((yyvsp[0].Str).text)+2);
							strcpy(myText, (yyvsp[-2].Details).text);
							strcat(myText, ".");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Details).text = myText;
							LeftName = (yyval.Details).text;
						}
#line 3743 "y.tab.c"
    break;

  case 147: /* myId: id  */
#line 1397 "parser.y"
                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3749 "y.tab.c"
    break;

  case 148: /* myId: id '[' RHS ']'  */
#line 1398 "parser.y"
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
#line 3769 "y.tab.c"
    break;

  case 149: /* declr_stmt: DECLR declr_body ';'  */
#line 1418 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT"); fprintf(fIR, ";");}
#line 3775 "y.tab.c"
    break;

  case 150: /* declr_body: DATATYPE id_list  */
#line 1421 "parser.y"
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
#line 3827 "y.tab.c"
    break;

  case 151: /* declr_body: GRAPH graph_and_array_list  */
#line 1469 "parser.y"
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
#line 3898 "y.tab.c"
    break;

  case 152: /* declr_body: VECT '<' dtype '>' id_list  */
#line 1536 "parser.y"
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
#line 3950 "y.tab.c"
    break;

  case 153: /* declr_body: MATRIX matrix_list  */
#line 1584 "parser.y"
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
#line 4012 "y.tab.c"
    break;

  case 154: /* declr_body: DATATYPE graph_and_array_list  */
#line 1642 "parser.y"
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
#line 4066 "y.tab.c"
    break;

  case 155: /* declr_body: id id_list  */
#line 1692 "parser.y"
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
#line 4133 "y.tab.c"
    break;

  case 156: /* graph_and_array_list: graph_and_array_list ',' id '[' INT_CONST ']'  */
#line 1757 "parser.y"
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
								strcat(myText, "]");
								
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 4160 "y.tab.c"
    break;

  case 157: /* graph_and_array_list: id '[' INT_CONST ']'  */
#line 1780 "parser.y"
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
#line 4185 "y.tab.c"
    break;

  case 158: /* matrix_list: matrix_list ',' id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1803 "parser.y"
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
#line 4214 "y.tab.c"
    break;

  case 159: /* matrix_list: matrix_list ',' id '[' LHS ']' '[' LHS ']'  */
#line 1829 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-8].Str).text)+strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].Details).text)+strlen((yyvsp[-1].Details).text)+7);
								strcpy(myText, (yyvsp[-8].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].Details).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Details).text);
								strcat(myText, ")");
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 4237 "y.tab.c"
    break;

  case 160: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1850 "parser.y"
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
#line 4263 "y.tab.c"
    break;

  case 161: /* matrix_list: id '[' LHS ']' '[' LHS ']'  */
#line 1872 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].Details).text)+strlen((yyvsp[-1].Details).text)+5);
								strcpy(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].Details).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Details).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
							}
#line 4283 "y.tab.c"
    break;

  case 162: /* id_list: id_list ',' id  */
#line 1890 "parser.y"
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
#line 4300 "y.tab.c"
    break;

  case 163: /* id_list: id  */
#line 1903 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].Str).str;
								arr_size++;
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 4310 "y.tab.c"
    break;

  case 164: /* $@20: %empty  */
#line 1910 "parser.y"
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
#line 4329 "y.tab.c"
    break;

  case 166: /* $@21: %empty  */
#line 1927 "parser.y"
                                                             {fprintf(fIR, "else ");}
#line 4335 "y.tab.c"
    break;

  case 169: /* $@22: %empty  */
#line 1931 "parser.y"
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
#line 4354 "y.tab.c"
    break;

  case 171: /* $@23: %empty  */
#line 1948 "parser.y"
                                              {switch_insert(level); level++; fprintf(fIR, "{\n");}
#line 4360 "y.tab.c"
    break;

  case 172: /* $@24: %empty  */
#line 1948 "parser.y"
                                                                                                                      {printTabs(); fprintf(fIR, "default:\n");}
#line 4366 "y.tab.c"
    break;

  case 173: /* switch_body: '{' $@23 cases DEFAULT ':' $@24 function_body '}'  */
#line 1948 "parser.y"
                                                                                                                                                                                   { var_delete(level); level--; switch_delete(); printTabs(); fprintf(fIR, "}\n");}
#line 4372 "y.tab.c"
    break;

  case 174: /* $@25: %empty  */
#line 1951 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4378 "y.tab.c"
    break;

  case 176: /* $@26: %empty  */
#line 1952 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4384 "y.tab.c"
    break;

  case 178: /* RHS: constants  */
#line 1957 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4390 "y.tab.c"
    break;

  case 179: /* RHS: arith_op  */
#line 1958 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4396 "y.tab.c"
    break;

  case 180: /* RHS: logical_op  */
#line 1959 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4402 "y.tab.c"
    break;

  case 181: /* RHS: func_calls  */
#line 1960 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4408 "y.tab.c"
    break;

  case 182: /* RHS: impr  */
#line 1961 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4414 "y.tab.c"
    break;

  case 183: /* constants: INT_CONST  */
#line 1965 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 4420 "y.tab.c"
    break;

  case 184: /* constants: FLOAT_CONST  */
#line 1966 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 4426 "y.tab.c"
    break;

  case 185: /* constants: CHAR_CONST  */
#line 1967 "parser.y"
                                                             {(yyval.Str).str="char"; (yyval.Str).text = (yyvsp[0].str);}
#line 4432 "y.tab.c"
    break;

  case 186: /* constants: STR_CONST  */
#line 1968 "parser.y"
                                                            {(yyval.Str).str="string"; (yyval.Str).text = (yyvsp[0].str);}
#line 4438 "y.tab.c"
    break;

  case 187: /* constants: BOOL_CONST  */
#line 1969 "parser.y"
                                                             {(yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].str);}
#line 4444 "y.tab.c"
    break;

  case 188: /* constants: LHS  */
#line 1970 "parser.y"
                                                      {(yyval.Str).str = (yyvsp[0].Details).type; (yyval.Str).text = (yyvsp[0].Details).text;}
#line 4450 "y.tab.c"
    break;

  case 189: /* extra_consts: array_const  */
#line 1974 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4456 "y.tab.c"
    break;

  case 190: /* extra_consts: graph_const  */
#line 1975 "parser.y"
                                                             {(yyval.Str).str="graph"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4462 "y.tab.c"
    break;

  case 191: /* extra_consts: vect_const  */
#line 1976 "parser.y"
                                                            {
							char* myType = (char*)malloc(strlen((yyvsp[0].Str).str)+2);
							strcpy(myType, "*");
							strcat(myType, (yyvsp[0].Str).str);
							(yyval.Str).str = myType;
							 (yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 4474 "y.tab.c"
    break;

  case 192: /* extra_consts: matrix_const  */
#line 1983 "parser.y"
                                                              {(yyval.Str).str="matrix"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4480 "y.tab.c"
    break;

  case 193: /* extra_consts: '{' '}'  */
#line 1984 "parser.y"
                                                         {(yyval.Str).str="1"; (yyval.Str).text = "{}";}
#line 4486 "y.tab.c"
    break;

  case 194: /* array_const: '[' val_list ']'  */
#line 1988 "parser.y"
                                                        {
								
								(yyval.Str).str = (yyvsp[-1].Str).text;
								
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								
								(yyval.Str).text = myText;
							}
#line 4502 "y.tab.c"
    break;

  case 195: /* array_const: '[' ']'  */
#line 2000 "parser.y"
                                                        {
								(yyval.Str).str = "any";
								(yyval.Str).text = "{}";
							}
#line 4511 "y.tab.c"
    break;

  case 196: /* val_list: int_list  */
#line 2007 "parser.y"
                                                        { (yyval.Str).str = "int"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4517 "y.tab.c"
    break;

  case 197: /* val_list: float_list  */
#line 2009 "parser.y"
                                                        { (yyval.Str).str  = "float"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4523 "y.tab.c"
    break;

  case 198: /* val_list: char_list  */
#line 2011 "parser.y"
                                                        { (yyval.Str).str = "char"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4529 "y.tab.c"
    break;

  case 199: /* val_list: bool_list  */
#line 2013 "parser.y"
                                                        { (yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4535 "y.tab.c"
    break;

  case 200: /* val_list: str_list  */
#line 2015 "parser.y"
                                                        { (yyval.Str).str = "string"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4541 "y.tab.c"
    break;

  case 201: /* resultant: LHS  */
#line 2017 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].Details).type; (yyval.Str).text = (yyvsp[0].Details).text;}
#line 4547 "y.tab.c"
    break;

  case 202: /* resultant: matrix_impr  */
#line 2018 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4553 "y.tab.c"
    break;

  case 203: /* resultant: graph_impr  */
#line 2019 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4559 "y.tab.c"
    break;

  case 204: /* resultant: vect_stmt_body  */
#line 2020 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4565 "y.tab.c"
    break;

  case 205: /* resultant: impr  */
#line 2021 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4571 "y.tab.c"
    break;

  case 206: /* resultant: func_calls  */
#line 2022 "parser.y"
                                                            {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4577 "y.tab.c"
    break;

  case 207: /* impr: resultant '.' LENGTH '(' ')'  */
#line 2026 "parser.y"
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
#line 4599 "y.tab.c"
    break;

  case 208: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 2043 "parser.y"
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
#line 4634 "y.tab.c"
    break;

  case 209: /* impr: resultant '.' TRACE '(' ')'  */
#line 2073 "parser.y"
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
#line 4653 "y.tab.c"
    break;

  case 210: /* impr: resultant '.' STRLEN '(' ')'  */
#line 2088 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								if(strcmp((yyvsp[-4].Str).str, "string"))
								{
									printf("%d ERROR: Method defined for string datatype only\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen(".size()") + strlen((yyvsp[-4].Str).text));
								strcpy(myText, (yyvsp[-4].Str).text);
								strcpy(myText, ".size()");
								
								strcpy((yyval.Str).text, myText);
								free(myText);
							}
#line 4673 "y.tab.c"
    break;

  case 211: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 2104 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								if(strcmp((yyvsp[-3].Str).str, "string") || strcmp((yyvsp[-1].Str).str, "string"))
								{
									printf("%d ERROR: Arguments have to be strings\n", yylineno);
									exit(1);
								}
								
								
								char* myText = (char*)malloc(strlen("strcmpr(, )") + strlen((yyvsp[-3].Str).text) + strlen((yyvsp[-1].Str).text));
								strcpy(myText, "strcmpr(");
								strcat(myText, (yyvsp[-3].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
								
							}
#line 4697 "y.tab.c"
    break;

  case 212: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 2124 "parser.y"
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
#line 4727 "y.tab.c"
    break;

  case 213: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 2150 "parser.y"
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
#line 4750 "y.tab.c"
    break;

  case 214: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 2171 "parser.y"
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
#line 4777 "y.tab.c"
    break;

  case 215: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 2194 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
							}
#line 4790 "y.tab.c"
    break;

  case 216: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 2203 "parser.y"
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
#line 4817 "y.tab.c"
    break;

  case 217: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 2226 "parser.y"
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
#line 4844 "y.tab.c"
    break;

  case 218: /* graph_impr: resultant '.' ADJNODE '(' remove_body ')'  */
#line 2249 "parser.y"
                                                        {
								(yyval.Str).str = "*int";
								if(strcmp((yyvsp[-5].Str).str,"graph"))
								{
									printf("%d ERROR: Adjacent Nodes are defined only for graph datatype\n", yylineno);
									exit(1);
								}
								if(strcmp((yyvsp[-1].Str).str, "int"))
								{
									printf("%d ERROR: Argument has to be an integer\n", yylineno);
									exit(1);
								}
								
								char* myText = (char*)malloc(strlen((yyvsp[-5].Str).text)+strlen("adjNodes.()")+strlen((yyvsp[-1].Str).text)+1);
								strcpy(myText, (yyvsp[-5].Str).text);
								strcat(myText, ".");
								strcat(myText, (yyvsp[-3].str));
								strcat(myText, "(");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, ")");
								(yyval.Str).text = myText;
							}
#line 4871 "y.tab.c"
    break;

  case 219: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 2275 "parser.y"
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
#line 4893 "y.tab.c"
    break;

  case 220: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 2293 "parser.y"
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
#line 4912 "y.tab.c"
    break;

  case 221: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 2308 "parser.y"
                                                        {
								(yyval.Str).str = "graph";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
							}
#line 4925 "y.tab.c"
    break;

  case 222: /* matrix_impr: resultant '.' GETVAL '(' remove_body ',' remove_body ')'  */
#line 2317 "parser.y"
                                                                                                           {
							if(strcmp((yyvsp[-7].Str).str, "matrix")){
								printf("%d Error: Only matrix can call getVal function\n", yylineno);
								exit(1);
							}
							
							int a = !(strcmp((yyvsp[-3].Str).str, "int"));
							int b = !(strcmp((yyvsp[-1].Str).str, "int"));
							
							if(!(a && b)){
								printf("%d Error: invalid arguments in getVal function\n", yylineno);
								exit(1);
							}
							
							char* myText = (char*)malloc(strlen((yyvsp[-7].Str).text)+strlen(".getValue(, )")+strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].Str).text)+1);
							strcpy(myText, (yyvsp[-7].Str).text);
							strcat(myText, ".getValue(");
							strcat(myText, (yyvsp[-3].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							
							(yyval.Str).str = "int";
							(yyval.Str).text = myText;
						}
#line 4955 "y.tab.c"
    break;

  case 223: /* matr_body: RHS  */
#line 2344 "parser.y"
                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4961 "y.tab.c"
    break;

  case 224: /* matr_body: matrix_impr  */
#line 2345 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4967 "y.tab.c"
    break;

  case 225: /* graph_const: '{' graph_type1 '}'  */
#line 2348 "parser.y"
                                                              {
								printTabs();
								fprintf(fIR, "%s.setFlag(0);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4981 "y.tab.c"
    break;

  case 226: /* graph_const: '{' graph_type2 '}'  */
#line 2357 "parser.y"
                                                                      {
								printTabs();
								fprintf(fIR, "%s.setFlag(1);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4995 "y.tab.c"
    break;

  case 227: /* graph_type1: graph_type1 INT_CONST ':' int_list ';'  */
#line 2369 "parser.y"
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
#line 5029 "y.tab.c"
    break;

  case 228: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 2399 "parser.y"
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
#line 5060 "y.tab.c"
    break;

  case 229: /* graph_type2: graph_type2 INT_CONST ':' weight_list ';'  */
#line 2428 "parser.y"
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
#line 5091 "y.tab.c"
    break;

  case 230: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 2455 "parser.y"
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
#line 5120 "y.tab.c"
    break;

  case 231: /* $@27: %empty  */
#line 2482 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 5129 "y.tab.c"
    break;

  case 232: /* int_list: int_list ',' INT_CONST $@27  */
#line 2486 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5142 "y.tab.c"
    break;

  case 233: /* $@28: %empty  */
#line 2495 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 5151 "y.tab.c"
    break;

  case 234: /* int_list: INT_CONST $@28  */
#line 2499 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								(yyval.Str).text = (yyvsp[-1].str);
							}
#line 5160 "y.tab.c"
    break;

  case 235: /* float_list: float_list ',' FLOAT_CONST  */
#line 2506 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5174 "y.tab.c"
    break;

  case 236: /* float_list: FLOAT_CONST  */
#line 2516 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5184 "y.tab.c"
    break;

  case 237: /* char_list: char_list ',' CHAR_CONST  */
#line 2524 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5198 "y.tab.c"
    break;

  case 238: /* char_list: CHAR_CONST  */
#line 2534 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5208 "y.tab.c"
    break;

  case 239: /* bool_list: bool_list ',' BOOL_CONST  */
#line 2542 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5222 "y.tab.c"
    break;

  case 240: /* bool_list: BOOL_CONST  */
#line 2552 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5232 "y.tab.c"
    break;

  case 241: /* str_list: str_list ',' STR_CONST  */
#line 2560 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5246 "y.tab.c"
    break;

  case 242: /* str_list: STR_CONST  */
#line 2570 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5256 "y.tab.c"
    break;

  case 243: /* weight_list: weight_list ',' '(' INT_CONST ',' INT_CONST ')'  */
#line 2578 "parser.y"
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
#line 5273 "y.tab.c"
    break;

  case 244: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 2591 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5287 "y.tab.c"
    break;

  case 245: /* weight_list: weight_list ',' '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2601 "parser.y"
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
#line 5303 "y.tab.c"
    break;

  case 246: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2613 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5317 "y.tab.c"
    break;

  case 247: /* vect_const: '{' vect_list '}'  */
#line 2624 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[-1].Str).str;
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 5330 "y.tab.c"
    break;

  case 248: /* vect_list: vect_list ',' vect_item  */
#line 2634 "parser.y"
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
#line 5353 "y.tab.c"
    break;

  case 249: /* vect_list: vect_item  */
#line 2652 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[0].Str).str;
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 5362 "y.tab.c"
    break;

  case 250: /* vect_item: constants  */
#line 2658 "parser.y"
                                                    {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5368 "y.tab.c"
    break;

  case 251: /* vect_item: extra_consts  */
#line 2659 "parser.y"
                                                               {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5374 "y.tab.c"
    break;

  case 252: /* matrix_const: '[' mat_list ']'  */
#line 2662 "parser.y"
                                                   {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Cols).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Cols).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 5386 "y.tab.c"
    break;

  case 253: /* int_float_list: int_float_list ',' INT_CONST  */
#line 2672 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5399 "y.tab.c"
    break;

  case 254: /* int_float_list: int_float_list ',' FLOAT_CONST  */
#line 2681 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5412 "y.tab.c"
    break;

  case 255: /* int_float_list: INT_CONST  */
#line 2690 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5421 "y.tab.c"
    break;

  case 256: /* int_float_list: FLOAT_CONST  */
#line 2695 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5430 "y.tab.c"
    break;

  case 257: /* mat_list: mat_list '[' int_float_list ']' ';'  */
#line 2702 "parser.y"
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
#line 5446 "y.tab.c"
    break;

  case 258: /* mat_list: '[' int_float_list ']' ';'  */
#line 2714 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-2].Cols).text);
								strcat(myText, "}");
								(yyval.Cols).text = myText;
								
							}
#line 5462 "y.tab.c"
    break;

  case 261: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 2732 "parser.y"
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
#line 5511 "y.tab.c"
    break;

  case 262: /* unary_op: UNARYOP '(' RHS ')'  */
#line 2778 "parser.y"
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
#line 5534 "y.tab.c"
    break;

  case 263: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 2798 "parser.y"
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
#line 5573 "y.tab.c"
    break;

  case 264: /* logical_op: NOT '(' RHS ')'  */
#line 2832 "parser.y"
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
#line 5593 "y.tab.c"
    break;

  case 265: /* call_stmt: func_calls ';'  */
#line 2850 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1; printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text); }
#line 5599 "y.tab.c"
    break;

  case 266: /* func_calls: call_head arguments  */
#line 2855 "parser.y"
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
							(yyval.Str).text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
#line 5626 "y.tab.c"
    break;

  case 267: /* call_head: CALL LHS  */
#line 2880 "parser.y"
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
							
							(yyval.Str).text = (yyvsp[0].Details).text;
						}
#line 5644 "y.tab.c"
    break;

  case 268: /* arguments: '(' arg_list ')'  */
#line 2895 "parser.y"
                                                           {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text) + 3);
							strcpy(myText, "(");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							(yyval.Str).text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
#line 5658 "y.tab.c"
    break;

  case 269: /* arguments: '(' ')'  */
#line 2904 "parser.y"
                                                          {(yyval.Str).text = "()";}
#line 5664 "y.tab.c"
    break;

  case 270: /* arg_list: arg_list ',' RHS  */
#line 2907 "parser.y"
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
							(yyval.Str).text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
#line 5719 "y.tab.c"
    break;

  case 271: /* arg_list: RHS  */
#line 2957 "parser.y"
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
#line 5775 "y.tab.c"
    break;


#line 5779 "y.tab.c"

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

#line 3010 "parser.y"


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




