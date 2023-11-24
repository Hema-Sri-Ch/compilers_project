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
    PRINTMATX = 294,               /* PRINTMATX  */
    PRINTARRAY = 295,              /* PRINTARRAY  */
    PRINTVECT = 296,               /* PRINTVECT  */
    PRINTGRAPH = 297,              /* PRINTGRAPH  */
    ADDVAL = 298,                  /* ADDVAL  */
    APPEND = 299,                  /* APPEND  */
    REMOVE = 300,                  /* REMOVE  */
    LENGTH = 301,                  /* LENGTH  */
    SORT = 302,                    /* SORT  */
    CLEAR = 303,                   /* CLEAR  */
    AT = 304,                      /* AT  */
    TRANSPOSE = 305,               /* TRANSPOSE  */
    TRACE = 306,                   /* TRACE  */
    TRAVERSAL = 307,               /* TRAVERSAL  */
    STRLEN = 308,                  /* STRLEN  */
    STRCUT = 309,                  /* STRCUT  */
    STRCMP = 310,                  /* STRCMP  */
    STRJOIN = 311,                 /* STRJOIN  */
    MATXOP = 312,                  /* MATXOP  */
    MAXTOGR = 313,                 /* MAXTOGR  */
    GRTOMATX = 314,                /* GRTOMATX  */
    SHPATH = 315,                  /* SHPATH  */
    SHPATH_VAL = 316,              /* SHPATH_VAL  */
    GOTO = 317,                    /* GOTO  */
    PRINT = 318                    /* PRINT  */
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
#define PRINTMATX 294
#define PRINTARRAY 295
#define PRINTVECT 296
#define PRINTGRAPH 297
#define ADDVAL 298
#define APPEND 299
#define REMOVE 300
#define LENGTH 301
#define SORT 302
#define CLEAR 303
#define AT 304
#define TRANSPOSE 305
#define TRACE 306
#define TRAVERSAL 307
#define STRLEN 308
#define STRCUT 309
#define STRCMP 310
#define STRJOIN 311
#define MATXOP 312
#define MAXTOGR 313
#define GRTOMATX 314
#define SHPATH 315
#define SHPATH_VAL 316
#define GOTO 317
#define PRINT 318

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

#line 393 "y.tab.c"

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
  YYSYMBOL_PRINTMATX = 39,                 /* PRINTMATX  */
  YYSYMBOL_PRINTARRAY = 40,                /* PRINTARRAY  */
  YYSYMBOL_PRINTVECT = 41,                 /* PRINTVECT  */
  YYSYMBOL_PRINTGRAPH = 42,                /* PRINTGRAPH  */
  YYSYMBOL_ADDVAL = 43,                    /* ADDVAL  */
  YYSYMBOL_APPEND = 44,                    /* APPEND  */
  YYSYMBOL_REMOVE = 45,                    /* REMOVE  */
  YYSYMBOL_LENGTH = 46,                    /* LENGTH  */
  YYSYMBOL_SORT = 47,                      /* SORT  */
  YYSYMBOL_CLEAR = 48,                     /* CLEAR  */
  YYSYMBOL_AT = 49,                        /* AT  */
  YYSYMBOL_TRANSPOSE = 50,                 /* TRANSPOSE  */
  YYSYMBOL_TRACE = 51,                     /* TRACE  */
  YYSYMBOL_TRAVERSAL = 52,                 /* TRAVERSAL  */
  YYSYMBOL_STRLEN = 53,                    /* STRLEN  */
  YYSYMBOL_STRCUT = 54,                    /* STRCUT  */
  YYSYMBOL_STRCMP = 55,                    /* STRCMP  */
  YYSYMBOL_STRJOIN = 56,                   /* STRJOIN  */
  YYSYMBOL_MATXOP = 57,                    /* MATXOP  */
  YYSYMBOL_MAXTOGR = 58,                   /* MAXTOGR  */
  YYSYMBOL_GRTOMATX = 59,                  /* GRTOMATX  */
  YYSYMBOL_SHPATH = 60,                    /* SHPATH  */
  YYSYMBOL_SHPATH_VAL = 61,                /* SHPATH_VAL  */
  YYSYMBOL_GOTO = 62,                      /* GOTO  */
  YYSYMBOL_PRINT = 63,                     /* PRINT  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* ','  */
  YYSYMBOL_70_ = 70,                       /* '['  */
  YYSYMBOL_71_ = 71,                       /* ']'  */
  YYSYMBOL_72_ = 72,                       /* '<'  */
  YYSYMBOL_73_ = 73,                       /* '>'  */
  YYSYMBOL_74_ = 74,                       /* '.'  */
  YYSYMBOL_75_ = 75,                       /* ':'  */
  YYSYMBOL_76_ = 76,                       /* '='  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_program_unit = 78,              /* program_unit  */
  YYSYMBOL_models = 79,                    /* models  */
  YYSYMBOL_model = 80,                     /* model  */
  YYSYMBOL_class = 81,                     /* class  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_id = 84,                        /* id  */
  YYSYMBOL_class_items = 85,               /* class_items  */
  YYSYMBOL_86_3 = 86,                      /* $@3  */
  YYSYMBOL_class_item = 87,                /* class_item  */
  YYSYMBOL_struct = 88,                    /* struct  */
  YYSYMBOL_89_4 = 89,                      /* $@4  */
  YYSYMBOL_90_5 = 90,                      /* $@5  */
  YYSYMBOL_struct_items = 91,              /* struct_items  */
  YYSYMBOL_92_6 = 92,                      /* $@6  */
  YYSYMBOL_function = 93,                  /* function  */
  YYSYMBOL_function_head = 94,             /* function_head  */
  YYSYMBOL_func_definition = 95,           /* func_definition  */
  YYSYMBOL_Parameters = 96,                /* Parameters  */
  YYSYMBOL_fdtype = 97,                    /* fdtype  */
  YYSYMBOL_param_list = 98,                /* param_list  */
  YYSYMBOL_param = 99,                     /* param  */
  YYSYMBOL_dtype = 100,                    /* dtype  */
  YYSYMBOL_function_body = 101,            /* function_body  */
  YYSYMBOL_102_7 = 102,                    /* $@7  */
  YYSYMBOL_statements = 103,               /* statements  */
  YYSYMBOL_104_8 = 104,                    /* $@8  */
  YYSYMBOL_statement = 105,                /* statement  */
  YYSYMBOL_independent_funcs = 106,        /* independent_funcs  */
  YYSYMBOL_print_stmt = 107,               /* print_stmt  */
  YYSYMBOL_print_body = 108,               /* print_body  */
  YYSYMBOL_print_constants = 109,          /* print_constants  */
  YYSYMBOL_unary_stmt = 110,               /* unary_stmt  */
  YYSYMBOL_jump_stmt = 111,                /* jump_stmt  */
  YYSYMBOL_label_stmt = 112,               /* label_stmt  */
  YYSYMBOL_113_9 = 113,                    /* $@9  */
  YYSYMBOL_goto_stmt = 114,                /* goto_stmt  */
  YYSYMBOL_vect_stmt = 115,                /* vect_stmt  */
  YYSYMBOL_vect_stmt_body = 116,           /* vect_stmt_body  */
  YYSYMBOL_remove_body = 117,              /* remove_body  */
  YYSYMBOL_vect_append = 118,              /* vect_append  */
  YYSYMBOL_return_stmt = 119,              /* return_stmt  */
  YYSYMBOL_120_10 = 120,                   /* $@10  */
  YYSYMBOL_121_11 = 121,                   /* $@11  */
  YYSYMBOL_122_12 = 122,                   /* $@12  */
  YYSYMBOL_123_13 = 123,                   /* $@13  */
  YYSYMBOL_124_14 = 124,                   /* $@14  */
  YYSYMBOL_loop_stmt = 125,                /* loop_stmt  */
  YYSYMBOL_loop_type = 126,                /* loop_type  */
  YYSYMBOL_for_loop = 127,                 /* for_loop  */
  YYSYMBOL_128_15 = 128,                   /* $@15  */
  YYSYMBOL_129_16 = 129,                   /* $@16  */
  YYSYMBOL_for_in = 130,                   /* for_in  */
  YYSYMBOL_131_17 = 131,                   /* $@17  */
  YYSYMBOL_for_expr = 132,                 /* for_expr  */
  YYSYMBOL_for_RHS = 133,                  /* for_RHS  */
  YYSYMBOL_while_loop = 134,               /* while_loop  */
  YYSYMBOL_135_18 = 135,                   /* $@18  */
  YYSYMBOL_expr_stmt = 136,                /* expr_stmt  */
  YYSYMBOL_137_19 = 137,                   /* $@19  */
  YYSYMBOL_LHS = 138,                      /* LHS  */
  YYSYMBOL_myId = 139,                     /* myId  */
  YYSYMBOL_declr_stmt = 140,               /* declr_stmt  */
  YYSYMBOL_declr_body = 141,               /* declr_body  */
  YYSYMBOL_graph_and_array_list = 142,     /* graph_and_array_list  */
  YYSYMBOL_matrix_list = 143,              /* matrix_list  */
  YYSYMBOL_id_list = 144,                  /* id_list  */
  YYSYMBOL_ifcond_stmt = 145,              /* ifcond_stmt  */
  YYSYMBOL_146_20 = 146,                   /* $@20  */
  YYSYMBOL_if_body = 147,                  /* if_body  */
  YYSYMBOL_148_21 = 148,                   /* $@21  */
  YYSYMBOL_switch_stmt = 149,              /* switch_stmt  */
  YYSYMBOL_150_22 = 150,                   /* $@22  */
  YYSYMBOL_switch_body = 151,              /* switch_body  */
  YYSYMBOL_152_23 = 152,                   /* $@23  */
  YYSYMBOL_153_24 = 153,                   /* $@24  */
  YYSYMBOL_cases = 154,                    /* cases  */
  YYSYMBOL_155_25 = 155,                   /* $@25  */
  YYSYMBOL_156_26 = 156,                   /* $@26  */
  YYSYMBOL_RHS = 157,                      /* RHS  */
  YYSYMBOL_constants = 158,                /* constants  */
  YYSYMBOL_extra_consts = 159,             /* extra_consts  */
  YYSYMBOL_array_const = 160,              /* array_const  */
  YYSYMBOL_val_list = 161,                 /* val_list  */
  YYSYMBOL_resultant = 162,                /* resultant  */
  YYSYMBOL_impr = 163,                     /* impr  */
  YYSYMBOL_graph_impr = 164,               /* graph_impr  */
  YYSYMBOL_matrix_impr = 165,              /* matrix_impr  */
  YYSYMBOL_matr_body = 166,                /* matr_body  */
  YYSYMBOL_graph_const = 167,              /* graph_const  */
  YYSYMBOL_graph_type1 = 168,              /* graph_type1  */
  YYSYMBOL_graph_type2 = 169,              /* graph_type2  */
  YYSYMBOL_int_list = 170,                 /* int_list  */
  YYSYMBOL_171_27 = 171,                   /* $@27  */
  YYSYMBOL_172_28 = 172,                   /* $@28  */
  YYSYMBOL_float_list = 173,               /* float_list  */
  YYSYMBOL_char_list = 174,                /* char_list  */
  YYSYMBOL_bool_list = 175,                /* bool_list  */
  YYSYMBOL_str_list = 176,                 /* str_list  */
  YYSYMBOL_weight_list = 177,              /* weight_list  */
  YYSYMBOL_vect_const = 178,               /* vect_const  */
  YYSYMBOL_vect_list = 179,                /* vect_list  */
  YYSYMBOL_vect_item = 180,                /* vect_item  */
  YYSYMBOL_matrix_const = 181,             /* matrix_const  */
  YYSYMBOL_int_float_list = 182,           /* int_float_list  */
  YYSYMBOL_mat_list = 183,                 /* mat_list  */
  YYSYMBOL_arith_op = 184,                 /* arith_op  */
  YYSYMBOL_binary_op = 185,                /* binary_op  */
  YYSYMBOL_unary_op = 186,                 /* unary_op  */
  YYSYMBOL_logical_op = 187,               /* logical_op  */
  YYSYMBOL_call_stmt = 188,                /* call_stmt  */
  YYSYMBOL_func_calls = 189,               /* func_calls  */
  YYSYMBOL_call_head = 190,                /* call_head  */
  YYSYMBOL_arguments = 191,                /* arguments  */
  YYSYMBOL_arg_list = 192                  /* arg_list  */
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
#define YYLAST   1333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  116
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  550

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      67,    68,     2,     2,    69,     2,    74,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    75,    66,
      72,    76,    73,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   213,   213,   216,   217,   220,   221,   222,   225,   238,
     225,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   263,   263,   264,   267,   268,   272,   284,   271,   287,
     287,   288,   291,   301,   311,   339,   340,   344,   345,   349,
     357,   361,   410,   424,   425,   426,   427,   446,   473,   473,
     474,   477,   477,   478,   479,   480,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     499,   517,   526,   535,   544,   557,   566,   574,   580,   589,
     598,   601,   602,   606,   605,   620,   623,   626,   673,   711,
     741,   774,   775,   776,   777,   778,   779,   780,   784,   785,
     790,   789,   846,   845,   867,   866,   907,   906,   945,   985,
     984,  1010,  1013,  1014,  1017,  1017,  1017,  1021,  1021,  1025,
    1026,  1042,  1043,  1044,  1045,  1046,  1047,  1050,  1050,  1066,
    1081,  1080,  1168,  1183,  1192,  1204,  1280,  1374,  1375,  1395,
    1397,  1445,  1512,  1560,  1618,  1668,  1733,  1756,  1779,  1805,
    1826,  1848,  1866,  1879,  1887,  1887,  1904,  1904,  1905,  1908,
    1908,  1925,  1925,  1925,  1928,  1928,  1929,  1929,  1934,  1935,
    1936,  1937,  1938,  1942,  1943,  1944,  1945,  1946,  1947,  1951,
    1952,  1953,  1960,  1961,  1964,  1976,  1983,  1985,  1987,  1989,
    1991,  1994,  1995,  1996,  1997,  1998,  1999,  2003,  2020,  2050,
    2064,  2080,  2100,  2126,  2147,  2170,  2179,  2202,  2228,  2246,
    2261,  2271,  2298,  2299,  2302,  2311,  2322,  2352,  2381,  2408,
    2436,  2435,  2449,  2448,  2459,  2469,  2477,  2487,  2495,  2505,
    2513,  2523,  2531,  2544,  2554,  2566,  2578,  2588,  2606,  2612,
    2613,  2616,  2625,  2634,  2643,  2648,  2655,  2667,  2682,  2683,
    2686,  2732,  2752,  2786,  2804,  2809,  2834,  2849,  2858,  2861,
    2911
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
  "FUNC", "LOOP", "null", "FOR", "WHILE", "GETVAL", "PRINTMATX",
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

#define YYPACT_NINF (-290)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-207)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,  1253,  1253,   995,    47,  -290,    -1,  -290,  -290,  -290,
      11,    -4,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,    38,    50,  -290,  -290,  -290,  -290,    57,  -290,
    1253,  -290,  -290,  -290,    56,  -290,   779,  -290,  -290,  -290,
    1049,  -290,  -290,   933,  -290,     0,  -290,  1253,    43,   105,
      66,   488,    74,    80,    89,   106,   107,  1103,  1253,  1253,
      68,   111,   115,   119,   121,   124,  1253,   128,   -49,   933,
     125,   133,   136,  -290,  -290,  -290,  -290,  -290,  -290,   137,
    -290,  -290,  -290,   197,  -290,  -290,  -290,  -290,   140,  -290,
    -290,  -290,   141,  -290,   149,   150,  -290,  1049,   148,   155,
     156,  -290,  -290,   158,   159,  -290,  -290,  -290,  -290,  -290,
    -290,   163,   164,   166,   624,   838,   221,   152,   168,    10,
     169,  -290,   172,  -290,   165,   170,   174,   175,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,   173,   838,  -290,  -290,   838,
     838,  1253,  1253,  1253,   161,  1253,   177,     6,   197,   179,
     182,  -290,  -290,  -290,  1169,  1169,   838,   838,   838,   184,
     652,   838,   176,  -290,  -290,   933,  -290,  -290,  1253,   341,
    -290,  -290,   720,  -290,  -290,   181,  -290,    43,  -290,   105,
     838,   838,  -290,   178,  -290,   197,  -290,  -290,    25,    31,
     -19,  -290,  -290,   228,  -290,  -290,  -290,  -290,  -290,   123,
    -290,   186,   190,   191,   192,   193,   196,    61,  -290,  -290,
    -290,  1272,  -290,  -290,   187,   199,   200,   202,   204,   207,
     208,   211,   202,   204,  1049,  -290,   207,  -290,   556,  -290,
     838,   -43,  -290,   -35,   212,   215,  -290,   203,   218,  -290,
      69,  -290,  -290,  -290,   222,    11,  -290,  -290,   229,   231,
     233,   234,   237,   238,   241,   243,   245,   247,   249,   250,
     252,   254,   255,   259,   260,   262,   264,  -290,  -290,    81,
    -290,   223,  -290,   266,  -290,   226,   265,  -290,    26,   261,
    -290,   263,  -290,  -290,   652,   838,  -290,  -290,  -290,   -33,
    -290,   331,   335,   338,   333,   339,   123,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,   343,  1253,  1253,  1199,  1253,
     272,   284,   285,   286,   287,   288,   324,   293,  -290,  -290,
     838,   838,   838,   290,   652,  -290,  -290,   874,   294,   295,
     874,   556,   874,   296,   297,   298,   874,   300,   301,   874,
     302,   874,   303,   304,   874,   874,  -290,   838,  -290,  -290,
     838,  -290,   369,    -5,     8,   370,   309,  -290,   313,   153,
     311,  -290,  -290,  -290,  -290,  -290,   -13,    11,   318,   325,
     328,  -290,   332,    28,   334,  1253,  -290,  -290,  -290,  -290,
    -290,   337,    -8,  -290,   340,   342,   347,  -290,  -290,  -290,
    -290,   348,    10,   170,  -290,  -290,   173,  -290,  -290,   349,
     351,  -290,  -290,   352,  -290,  -290,  -290,   353,  -290,  -290,
     354,  -290,   355,  -290,  -290,   360,   361,  -290,   363,   367,
    -290,  -290,   344,    37,    53,  -290,  -290,  -290,  -290,  -290,
     350,   394,  -290,  -290,  -290,  -290,   419,   362,   368,  1228,
     207,  -290,  -290,   371,    11,  -290,  -290,  -290,   874,   874,
    -290,  -290,  -290,  -290,   874,   874,   874,  -290,   157,   435,
    -290,  -290,  -290,  -290,   418,   372,   437,  1253,   374,    36,
      11,  -290,  -290,   380,   373,   381,   383,   388,   389,   390,
     391,    11,   455,   143,  -290,   392,    40,   396,   397,  -290,
      49,  -290,   874,  -290,  -290,  -290,  -290,  -290,   167,  -290,
    -290,   457,   387,  -290,  -290,   464,  1253,  1253,  -290,  -290,
     401,   404,   405,   399,  -290,  -290,   406,    45,     9,  -290,
    -290,  -290,    11,   400,    11,  -290,  -290,  1139,  -290,    11,
     411,   408,  -290,   170,   409,   203,  -290,   173,  -290,  -290
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
     192,   179,   258,   259,   180,   181,     0,    77,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,     0,
       0,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    59,     0,    79,    96,     0,     0,
      90,   264,     0,   265,    49,     0,     9,     0,    37,     0,
       0,     0,   119,   183,   193,   188,   249,   250,     0,     0,
       0,   248,   204,     0,   232,   235,   237,   241,   239,     0,
     195,     0,   196,   197,   198,   199,   200,     0,   118,   110,
     112,     0,   114,   116,     0,     0,     0,   163,   154,   150,
       0,   153,     0,   151,     0,   163,   155,   149,     0,   124,
       0,     0,   206,     0,     0,     0,   222,   223,     0,    95,
       0,    87,    88,    89,     0,     0,    62,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   270,     0,
      52,     0,    32,     0,    40,     0,     0,   120,     0,     0,
     224,     0,   225,   246,     0,     0,   233,   254,   255,     0,
     194,     0,     0,     0,     0,     0,     0,   251,   111,   113,
     115,   117,   164,   169,   261,     0,     0,     0,     0,     0,
       0,   204,     0,     0,   203,   202,     0,     0,    83,    84,
       0,     0,     0,     0,     0,   148,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     0,    10,    38,
       0,   263,     0,     0,     0,     0,     0,   247,     0,     0,
       0,   230,   234,   236,   238,   240,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,   144,   139,   140,   142,
     143,     0,     0,   137,     0,     0,     0,    85,    86,   101,
     102,     0,   103,   107,   105,   106,   104,    81,    82,     0,
       0,   108,   109,     0,   207,    99,   100,     0,   219,   209,
       0,   210,     0,   220,   215,     0,     0,   269,     0,     0,
     227,   229,     0,     0,     0,   262,   252,   253,   257,   231,
       0,   168,   165,   171,   170,   157,     0,     0,     0,     0,
     152,   141,   125,     0,     0,   211,   213,   218,     0,     0,
      97,    98,   208,   214,     0,     0,     0,   260,     0,     0,
     226,   228,   256,   166,     0,     0,     0,     0,     0,     0,
       0,   127,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,   126,
       0,   221,     0,   212,   216,   217,   243,   245,     0,   167,
     176,     0,     0,   160,   161,     0,     0,     0,   128,   129,
       0,     0,     0,     0,   174,   172,     0,     0,     0,    80,
     242,   244,     0,     0,     0,   158,   159,     0,   177,     0,
       0,   135,   130,   133,   134,   136,   131,   132,   175,   173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -290,  -290,   472,  -290,  -290,  -290,  -290,    41,   310,  -290,
    -290,  -290,  -290,  -290,   299,  -290,   -47,  -290,  -290,  -290,
    -290,  -290,   377,     2,   -10,  -290,   -66,  -290,  -290,  -290,
    -290,  -290,   171,  -290,  -290,  -290,  -290,  -290,  -290,   -51,
    -289,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,   183,
    -290,   -52,   320,    12,  -290,   336,  -290,  -148,  -290,  -290,
    -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,
      18,  -115,   -55,  -290,  -290,   -39,   -31,   -57,   -58,   180,
    -290,  -290,  -290,  -276,  -290,  -290,  -290,  -290,  -290,  -290,
     134,  -290,  -290,   205,  -290,   195,  -290,  -254,  -290,   -45,
    -195,  -290,   -12,  -290,  -290,  -290
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,     7,    58,   281,   127,   109,   187,
     110,     8,    59,   283,   113,   189,     9,    10,    11,    47,
      40,    55,    56,    57,    79,    53,    80,   175,    81,    82,
      83,   250,   251,    84,    85,    86,   172,    87,    88,   202,
     401,   410,    90,   308,   309,   310,   311,   287,    91,   161,
     162,   326,   480,   391,   500,   518,   542,   163,   454,    92,
     451,   129,    94,    95,   156,   228,   231,   229,    96,   377,
     442,   491,    97,   378,   444,   474,   534,   493,   533,   523,
     246,   131,   197,   133,   211,   134,   135,   100,   101,   248,
     138,   198,   199,   212,   439,   296,   213,   214,   215,   216,
     364,   139,   200,   201,   140,   299,   217,   141,   142,   143,
     144,   103,   145,   105,   183,   279
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    93,    89,   137,   136,    41,   132,   236,   102,   196,
     128,   111,   363,   173,    98,   178,   157,   158,   178,   178,
     122,   171,    99,     1,     2,   328,   -93,    93,    89,   289,
     204,   221,     3,   329,   102,   291,   369,   178,   370,   221,
      98,   104,    32,    33,    39,   178,   293,    42,    99,   178,
     294,   409,    60,   413,   178,   252,   369,   417,   440,   125,
     420,   430,   422,    46,   301,   425,   426,   104,   106,   107,
     112,   114,   195,    67,   431,    44,     3,   432,    66,   130,
     517,    51,   238,   404,  -201,   537,   404,    39,   404,   433,
     290,    39,   404,   362,    78,   404,   292,   404,   108,   448,
     404,   404,    48,   470,   159,   160,   301,   498,   155,   256,
     247,   514,    93,    93,    49,   253,   536,   169,   195,   471,
      78,    52,   432,    93,    89,   241,   243,   297,   298,    50,
     102,   306,   307,    99,    99,    67,    98,   333,   334,   115,
     111,   146,   405,   203,    99,   405,   147,   405,    39,   356,
     357,   405,   242,   242,   405,   148,   405,   436,   437,   405,
     405,   488,   489,   104,   224,   511,   512,   225,   226,   483,
     484,   521,   522,   149,   150,   485,   486,   487,   164,   196,
     325,   324,   165,   323,   244,   245,   166,   321,   167,   254,
     174,   168,   227,   230,   232,   170,   235,   453,   -63,   112,
     278,   114,   176,   177,   404,   404,   178,   180,   285,   286,
     404,   404,   404,   520,   179,   181,    78,   182,   185,   252,
     186,   -33,   171,   188,   -41,   204,   205,   206,   207,   208,
     190,   191,   192,   234,   218,   219,   320,   450,   220,   221,
     222,   223,   195,   237,  -205,   336,   239,  -206,   404,   240,
     249,   255,   280,   288,   295,   312,   322,   300,   327,   301,
     302,   303,   304,   405,   405,   305,   383,   313,   314,   405,
     405,   405,   315,   316,   247,    39,   317,  -202,   318,   253,
     319,   330,   195,   546,   331,   402,   412,   332,   402,   358,
     402,   209,   210,   335,   402,   360,   337,   402,   338,   402,
     339,   340,   402,   402,   341,   342,   403,   405,   343,   403,
     344,   403,   345,   368,   346,   403,   347,   348,   403,   349,
     403,   350,   351,   403,   403,   406,   352,   353,   406,   354,
     406,   355,   359,   361,   406,   371,   365,   406,   366,   406,
     372,   374,   406,   406,   373,   385,   375,   379,   394,   395,
     386,   387,   388,   389,   390,    68,   397,   380,   381,   411,
     384,   393,   407,   408,   414,   415,   416,   441,   418,   419,
     421,   423,   424,   429,   204,   427,   362,   438,   428,   258,
     259,   435,   443,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   445,   479,   446,   273,
     274,   275,   276,   447,   449,   452,   402,   402,   455,   473,
     456,   469,   402,   402,   402,   457,   472,   458,   459,   460,
     461,   462,   463,   475,   464,   496,   235,   403,   403,   465,
     466,   467,   476,   403,   403,   403,   468,   481,   477,   490,
     492,   495,   502,   494,   482,   497,   406,   406,   501,   503,
     402,   504,   406,   406,   406,   519,   505,   506,   507,   510,
     508,   524,   525,   513,   527,   528,   515,   516,   526,   529,
     499,   403,   530,   531,   532,   539,   549,   535,    43,   545,
     544,   509,  -204,  -203,   184,    93,   541,     0,   284,   233,
     406,    12,   116,   117,   118,   119,   120,   282,   257,   367,
     434,   376,     0,     0,     0,   398,   543,     0,     0,   392,
       0,     0,   396,     0,     0,   121,   122,    66,     0,     0,
      69,     0,   538,   123,   540,   547,    13,     0,     0,   548,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    73,    74,    75,    28,    29,    30,    31,
       0,     0,   124,     0,     0,   125,     0,     0,   126,    12,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   122,    66,     0,     0,    69,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    73,    74,    75,    28,    29,    30,    31,     0,     0,
     124,     0,     0,   125,     0,     0,   126,    12,   193,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,   116,   117,   118,   119,
     120,     0,    13,     0,     0,     0,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,     0,   124,   194,
      13,     0,     0,     0,   126,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,     0,   124,     0,     0,     0,
       0,     0,   126,    12,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,    66,
       0,     0,    69,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    73,    74,    75,    28,    29,
      30,    31,    12,     0,     0,     0,     0,   125,   277,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    12,   116,   117,   118,   119,   120,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   122,    66,     0,     0,
      69,     0,     0,     0,     0,     0,    13,    12,   399,   400,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    73,    74,    75,    28,    29,    30,    31,
       0,   121,   122,    66,     0,   125,    69,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    73,
      74,    75,    28,    29,    30,    31,    12,     0,     0,     0,
       0,   125,     0,     0,     0,     0,    61,    62,     0,    63,
      64,     0,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,     0,    70,     0,     0,
       0,    13,     0,    71,    72,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    73,    74,
      75,    28,    29,    30,    31,    76,    77,    44,    12,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    12,    28,    29,    30,    31,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    12,    28,    29,    30,
      31,     0,     0,     0,   151,     0,     0,     0,     0,     0,
       0,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    12,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,   121,     0,    66,     0,
       0,    69,    12,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    73,    74,    75,    28,    29,    30,
      31,    69,    12,   382,     0,     0,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    73,    74,    75,    28,    29,    30,
      31,    12,   478,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    12,    28,    29,    30,
      31,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,    13,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     258,    28,    29,    30,    31,     0,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,     0,     0,     0,
     273,   274,   275,   276
};

static const yytype_int16 yycheck[] =
{
      10,    53,    53,    61,    61,     3,    61,   155,    53,   124,
      61,    58,   288,    79,    53,     9,    68,    69,     9,     9,
      28,    70,    53,    24,    25,    68,    75,    79,    79,     4,
       4,    74,    33,    68,    79,     4,    69,     9,    71,    74,
      79,    53,     1,     2,     3,     9,    65,     0,    79,     9,
      69,   340,    50,   342,     9,   170,    69,   346,    71,    67,
     349,    66,   351,    67,    69,   354,   355,    79,    68,    69,
      58,    59,   124,    30,    66,    64,    33,    69,    29,    61,
      31,    40,    76,   337,    74,    76,   340,    46,   342,   365,
      65,    50,   346,    67,    53,   349,    65,   351,    57,    71,
     354,   355,    64,    66,    36,    37,    69,    71,    67,   175,
     168,    71,   164,   165,    64,   170,    71,    76,   170,    66,
      79,    65,    69,   175,   175,   164,   165,     4,     5,    72,
     175,    70,    71,   164,   165,    30,   175,    68,    69,    73,
     187,    67,   337,   125,   175,   340,    66,   342,   107,    68,
      69,   346,   164,   165,   349,    66,   351,     4,     5,   354,
     355,     4,     5,   175,   146,    22,    23,   149,   150,   458,
     459,     4,     5,    67,    67,   464,   465,   466,    67,   294,
     238,   238,    67,   238,   166,   167,    67,   238,    67,   171,
      65,    67,   151,   152,   153,    67,   155,   392,    65,   187,
     182,   189,    66,    66,   458,   459,     9,    66,   190,   191,
     464,   465,   466,   502,    74,    66,   175,    67,    70,   334,
      65,    65,    70,    65,    65,     4,     5,     6,     7,     8,
      67,    67,    66,    72,    66,    66,   234,   385,    66,    74,
      66,    66,   294,    66,    74,   255,    67,    74,   502,    67,
      66,    75,    71,    75,    26,    68,   238,    71,   240,    69,
      69,    69,    69,   458,   459,    69,   318,    68,    68,   464,
     465,   466,    70,    69,   332,   234,    69,    74,    70,   334,
      69,    69,   334,   537,    69,   337,   341,    69,   340,    66,
     342,    70,    71,    71,   346,    69,    67,   349,    67,   351,
      67,    67,   354,   355,    67,    67,   337,   502,    67,   340,
      67,   342,    67,   295,    67,   346,    67,    67,   349,    67,
     351,    67,    67,   354,   355,   337,    67,    67,   340,    67,
     342,    67,    66,    68,   346,     4,    75,   349,    75,   351,
       5,     8,   354,   355,     6,    73,     7,     4,   330,   331,
      66,    66,    66,    66,    66,    31,    66,   316,   317,   341,
     319,    68,    68,    68,    68,    68,    68,   377,    68,    68,
      68,    68,    68,     4,     4,   357,    67,    66,   360,    38,
      39,    68,    64,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    71,   449,    70,    58,
      59,    60,    61,    71,    70,    68,   458,   459,    68,    15,
      68,    67,   464,   465,   466,    68,    66,    69,    69,    68,
      68,    68,    68,     4,    69,   477,   385,   458,   459,    69,
      69,    68,    70,   464,   465,   466,    69,    66,    70,     4,
      22,     4,    69,    71,   454,    71,   458,   459,    68,    68,
     502,    68,   464,   465,   466,   500,    68,    68,    68,     4,
      69,     4,    75,    71,   516,   517,    70,    70,     4,    68,
     480,   502,    68,    68,    75,    75,    65,    71,     6,   537,
     537,   491,    74,    74,   107,   537,   537,    -1,   189,   153,
     502,     3,     4,     5,     6,     7,     8,   187,   178,   294,
     366,   306,    -1,    -1,    -1,   334,   537,    -1,    -1,   326,
      -1,    -1,   332,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,   532,    35,   534,   537,    38,    -1,    -1,   539,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    67,    -1,    -1,    70,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      64,    -1,    -1,    67,    -1,    -1,    70,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    -1,    -1,    64,    65,
      38,    -1,    -1,    -1,    70,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     3,    -1,    -1,    -1,    -1,    67,    68,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,     3,     4,     5,     6,     7,     8,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,     3,     4,     5,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    27,    28,    29,    -1,    67,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     3,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    13,    14,    -1,    16,
      17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     3,    58,    59,    60,    61,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,    58,    59,    60,
      61,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,     3,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    -1,    27,    -1,    29,    -1,
      -1,    32,     3,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    32,     3,     4,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     3,     4,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      38,    58,    59,    60,    61,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    25,    33,    78,    79,    80,    81,    88,    93,
      94,    95,     3,    38,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    58,    59,
      60,    61,    84,    84,    11,    12,    18,    19,    20,    84,
      97,   100,     0,    79,    64,   101,    67,    96,    64,    64,
      72,    84,    65,   102,    68,    98,    99,   100,    82,    89,
     100,    13,    14,    16,    17,    21,    29,    30,    31,    32,
      34,    40,    41,    55,    56,    57,    62,    63,    84,   101,
     103,   105,   106,   107,   110,   111,   112,   114,   115,   116,
     119,   125,   136,   138,   139,   140,   145,   149,   162,   163,
     164,   165,   186,   188,   189,   190,    68,    69,    84,    85,
      87,    93,   140,    91,   140,    73,     4,     5,     6,     7,
       8,    27,    28,    35,    64,    67,    70,    84,   116,   138,
     157,   158,   159,   160,   162,   163,   164,   165,   167,   178,
     181,   184,   185,   186,   187,   189,    67,    66,    66,    67,
      67,    11,    18,    19,    20,    84,   141,   138,   138,    36,
      37,   126,   127,   134,    67,    67,    67,    67,    67,    84,
      67,    70,   113,   103,    65,   104,    66,    66,     9,    74,
      66,    66,    67,   191,    99,    70,    65,    86,    65,    92,
      67,    67,    66,     4,    65,   138,   158,   159,   168,   169,
     179,   180,   116,   157,     4,     5,     6,     7,     8,    70,
      71,   161,   170,   173,   174,   175,   176,   183,    66,    66,
      66,    74,    66,    66,   157,   157,   157,    84,   142,   144,
      84,   143,    84,   142,    72,    84,   144,    66,    76,    67,
      67,   162,   189,   162,   157,   157,   157,   165,   166,    66,
     108,   109,   158,   159,   157,    75,   103,   139,    38,    39,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    58,    59,    60,    61,    68,   157,   192,
      71,    83,    85,    90,    91,   157,   157,   124,    75,     4,
      65,     4,    65,    65,    69,    26,   172,     4,     5,   182,
      71,    69,    69,    69,    69,    69,    70,    71,   120,   121,
     122,   123,    68,    68,    68,    70,    69,    69,    70,    69,
     100,   116,   157,   159,   164,   165,   128,   157,    68,    68,
      69,    69,    69,    68,    69,    71,   101,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    69,    66,    66,
      69,    68,    67,   170,   177,    75,    75,   180,   157,    69,
      71,     4,     5,     6,     8,     7,   182,   146,   150,     4,
      84,    84,     4,   138,    84,    73,    66,    66,    66,    66,
      66,   130,   136,    68,   157,   157,   166,    66,   109,     4,
       5,   117,   138,   163,   184,   187,   189,    68,    68,   117,
     118,   157,   159,   117,    68,    68,    68,   117,    68,    68,
     117,    68,   117,    68,    68,   117,   117,   157,   157,     4,
      66,    66,    69,   170,   177,    68,     4,     5,    66,   171,
      71,   101,   147,    64,   151,    71,    70,    71,    71,    70,
     144,   137,    68,   187,   135,    68,    68,    68,    69,    69,
      68,    68,    68,    68,    69,    69,    69,    68,    69,    67,
      66,    66,    66,    15,   152,     4,    70,    70,     4,   138,
     129,    66,   101,   117,   117,   117,   117,   117,     4,     5,
       4,   148,    22,   154,    71,     4,   138,    71,    71,   101,
     131,    68,    69,    68,    68,    68,    68,    68,    69,   101,
       4,    22,    23,    71,    71,    70,    70,    31,   132,   186,
     117,     4,     5,   156,     4,    75,     4,   138,   138,    68,
      68,    68,    75,   155,   153,    71,    71,    76,   101,    75,
     101,   116,   133,   163,   164,   165,   184,   189,   101,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    80,    82,    83,
      81,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    86,    85,    85,    87,    87,    89,    90,    88,    92,
      91,    91,    93,    94,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   102,   101,
     101,   104,   103,   103,   103,   103,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   106,   107,   108,   108,   109,   109,
     110,   111,   111,   113,   112,   114,   115,   116,   116,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     120,   119,   121,   119,   122,   119,   123,   119,   119,   124,
     119,   125,   126,   126,   128,   129,   127,   131,   130,   132,
     132,   133,   133,   133,   133,   133,   133,   135,   134,   136,
     137,   136,   136,   136,   136,   138,   138,   139,   139,   140,
     141,   141,   141,   141,   141,   141,   142,   142,   143,   143,
     143,   143,   144,   144,   146,   145,   148,   147,   147,   150,
     149,   152,   153,   151,   155,   154,   156,   154,   157,   157,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   161,   161,
     161,   162,   162,   162,   162,   162,   162,   163,   163,   163,
     163,   163,   163,   163,   164,   164,   164,   164,   165,   165,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     171,   170,   172,   170,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   177,   177,   178,   179,   179,   180,
     180,   181,   182,   182,   182,   182,   183,   183,   184,   184,
     185,   186,   187,   187,   188,   189,   190,   191,   191,   192,
     192
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
       5,     6,     8,     6,     6,     5,     8,     8,     6,     5,
       5,     8,     1,     1,     3,     3,     5,     4,     5,     4,
       0,     4,     0,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     7,     5,     7,     5,     3,     3,     1,     1,
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
#line 225 "parser.y"
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
#line 2130 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 238 "parser.y"
                                                                  { var_delete(level); level--; inClass = 0; fprintf(fIR, "};\n");}
#line 2136 "y.tab.c"
    break;

  case 10: /* class: CLASS id '{' $@1 class_items '}' $@2 ';'  */
#line 238 "parser.y"
                                                                                                                                        {fprintf(fparse, " : CLASS DEFINITION");}
#line 2142 "y.tab.c"
    break;

  case 11: /* id: newid  */
#line 241 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2148 "y.tab.c"
    break;

  case 12: /* id: APPEND  */
#line 242 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2154 "y.tab.c"
    break;

  case 13: /* id: REMOVE  */
#line 243 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2160 "y.tab.c"
    break;

  case 14: /* id: LENGTH  */
#line 244 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2166 "y.tab.c"
    break;

  case 15: /* id: SORT  */
#line 245 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2172 "y.tab.c"
    break;

  case 16: /* id: CLEAR  */
#line 246 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2178 "y.tab.c"
    break;

  case 17: /* id: AT  */
#line 247 "parser.y"
                                                     {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2184 "y.tab.c"
    break;

  case 18: /* id: TRANSPOSE  */
#line 248 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2190 "y.tab.c"
    break;

  case 19: /* id: TRACE  */
#line 249 "parser.y"
                                                        {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2196 "y.tab.c"
    break;

  case 20: /* id: TRAVERSAL  */
#line 250 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2202 "y.tab.c"
    break;

  case 21: /* id: STRLEN  */
#line 251 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2208 "y.tab.c"
    break;

  case 22: /* id: STRCUT  */
#line 252 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2214 "y.tab.c"
    break;

  case 23: /* id: STRJOIN  */
#line 253 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2220 "y.tab.c"
    break;

  case 24: /* id: STRCMP  */
#line 254 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2226 "y.tab.c"
    break;

  case 25: /* id: MAXTOGR  */
#line 255 "parser.y"
                                                          {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2232 "y.tab.c"
    break;

  case 26: /* id: GRTOMATX  */
#line 256 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2238 "y.tab.c"
    break;

  case 27: /* id: SHPATH  */
#line 257 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2244 "y.tab.c"
    break;

  case 28: /* id: SHPATH_VAL  */
#line 258 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2250 "y.tab.c"
    break;

  case 29: /* id: ADDVAL  */
#line 259 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2256 "y.tab.c"
    break;

  case 30: /* id: GETVAL  */
#line 260 "parser.y"
                                                         {(yyval.Str).str=(yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str);}
#line 2262 "y.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 263 "parser.y"
                                                     {fprintf(fIR, "\n");}
#line 2268 "y.tab.c"
    break;

  case 33: /* class_items: class_item  */
#line 264 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2274 "y.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 272 "parser.y"
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
#line 2291 "y.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 284 "parser.y"
                                                                         { var_delete(level); level--; fprintf(fIR, "};\n"); inStruct = 0;}
#line 2297 "y.tab.c"
    break;

  case 38: /* struct: STRUCT id '{' $@4 struct_items '}' $@5 ';'  */
#line 284 "parser.y"
                                                                                                                                               {fprintf(fparse, " : STRUCT DEFINITION");}
#line 2303 "y.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 287 "parser.y"
                                             {fprintf(fIR, "\n");}
#line 2309 "y.tab.c"
    break;

  case 41: /* struct_items: declr_stmt  */
#line 288 "parser.y"
                                                             {fprintf(fIR, "\n");}
#line 2315 "y.tab.c"
    break;

  case 42: /* function: function_head function_body  */
#line 292 "parser.y"
                                                        {
								currentFuncIndex = -1; 
								if(returnStmtCount==0)	printf("%d ERROR : Expected atlease one return statement\n", yylineno);
								returnStmtCount = 0;
								var_delete(level);
								level--;
							}
#line 2327 "y.tab.c"
    break;

  case 43: /* function_head: func_definition Parameters  */
#line 301 "parser.y"
                                                             { 
							(yyval.details)=(yyvsp[-1].details); 
							// if(inClass == 0) printFuncDetails(-1, func_size-1);
							// else printFuncDetails(class_size-1, -1); 
							fprintf(fparse, " : FUNCTION HEAD");
//							fprintf(fIR, ")\n");
						}
#line 2339 "y.tab.c"
    break;

  case 44: /* func_definition: FUNC fdtype id  */
#line 311 "parser.y"
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
#line 2370 "y.tab.c"
    break;

  case 45: /* Parameters: '(' ')'  */
#line 339 "parser.y"
                                                  {fprintf(fIR, "()\n");}
#line 2376 "y.tab.c"
    break;

  case 46: /* Parameters: '(' param_list ')'  */
#line 340 "parser.y"
                                                                     {fprintf(fIR, "( %s )\n", (yyvsp[-1].Str).text);}
#line 2382 "y.tab.c"
    break;

  case 47: /* fdtype: dtype  */
#line 344 "parser.y"
                                                {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2388 "y.tab.c"
    break;

  case 48: /* fdtype: VOID  */
#line 345 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text = (yyvsp[0].str);}
#line 2394 "y.tab.c"
    break;

  case 49: /* param_list: param_list ',' param  */
#line 349 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+strlen(", ")+1);
							strcpy(myText, (yyvsp[-2].Str).text);
							strcat(myText, ", ");
							strcat(myText, (yyvsp[0].Str).text);
							(yyval.Str).text = myText;
//							free(myText);
						}
#line 2407 "y.tab.c"
    break;

  case 50: /* param_list: param  */
#line 357 "parser.y"
                                                       {(yyval.Str).text = (yyvsp[0].Str).text;}
#line 2413 "y.tab.c"
    break;

  case 51: /* param: dtype id  */
#line 361 "parser.y"
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
#line 2467 "y.tab.c"
    break;

  case 52: /* param: dtype id '[' ']'  */
#line 410 "parser.y"
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
#line 2482 "y.tab.c"
    break;

  case 53: /* dtype: DATATYPE  */
#line 424 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].str); (yyval.Str).text=(yyvsp[0].str); dataType = 0;}
#line 2488 "y.tab.c"
    break;

  case 54: /* dtype: MATRIX  */
#line 425 "parser.y"
                                                         {(yyval.Str).str = (yyvsp[0].str); dataType = 3; (yyval.Str).text = "matrix";}
#line 2494 "y.tab.c"
    break;

  case 55: /* dtype: GRAPH  */
#line 426 "parser.y"
                                                        {(yyval.Str).str = (yyvsp[0].str); dataType = 4; (yyval.Str).text = "graph";}
#line 2500 "y.tab.c"
    break;

  case 56: /* dtype: VECT '<' dtype '>'  */
#line 427 "parser.y"
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
#line 2524 "y.tab.c"
    break;

  case 57: /* dtype: id  */
#line 446 "parser.y"
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
#line 2554 "y.tab.c"
    break;

  case 58: /* $@7: %empty  */
#line 473 "parser.y"
                                      {printTabs(); level++; fprintf(fIR, "{\n");}
#line 2560 "y.tab.c"
    break;

  case 59: /* function_body: '{' $@7 statements '}'  */
#line 473 "parser.y"
                                                                                                  {var_delete(level); level--; printTabs(); fprintf(fIR, "}\n");}
#line 2566 "y.tab.c"
    break;

  case 60: /* function_body: '{' '}'  */
#line 474 "parser.y"
                                                          { printTabs(); fprintf(fIR, "{ }\n");}
#line 2572 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 477 "parser.y"
                                                    {fprintf(fIR, "\n");}
#line 2578 "y.tab.c"
    break;

  case 63: /* statements: statement  */
#line 478 "parser.y"
                                                            {fprintf(fIR, "\n");}
#line 2584 "y.tab.c"
    break;

  case 73: /* statement: return_stmt  */
#line 490 "parser.y"
                                                              {fprintf(fparse," : RETURN STATEMENT");}
#line 2590 "y.tab.c"
    break;

  case 76: /* statement: BREAK ';'  */
#line 493 "parser.y"
                                                            {fprintf(fparse, " : BREAK STATEMENT");}
#line 2596 "y.tab.c"
    break;

  case 77: /* statement: CONTINUE ';'  */
#line 494 "parser.y"
                                                               {fprintf(fparse, " : CONTINUE STATEMENT");}
#line 2602 "y.tab.c"
    break;

  case 80: /* independent_funcs: resultant '.' ADDVAL '(' remove_body ',' remove_body ',' remove_body ')'  */
#line 499 "parser.y"
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
#line 2625 "y.tab.c"
    break;

  case 81: /* independent_funcs: resultant '.' PRINTMATX '(' ')'  */
#line 517 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-4].Str).str, "matrix")){
								printf("%d Error: Only matrix can call printMatrix function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printMatrix();\n", (yyvsp[-4].Str).text);
						}
#line 2639 "y.tab.c"
    break;

  case 82: /* independent_funcs: resultant '.' PRINTGRAPH '(' ')'  */
#line 526 "parser.y"
                                                                                   {
							if(strcmp((yyvsp[-4].Str).str, "graph")){
								printf("%d Error: Only graph can call printGraph function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "%s.printGraph();\n", (yyvsp[-4].Str).text);
						}
#line 2653 "y.tab.c"
    break;

  case 83: /* independent_funcs: PRINTARRAY '(' resultant ')'  */
#line 535 "parser.y"
                                                                               {
							if((yyvsp[-1].Str).text[0] == '#'){
								printf("%d Error: Invalid argument for printArray function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printArray(%s);\n", (yyvsp[-1].Str).text);
						}
#line 2667 "y.tab.c"
    break;

  case 84: /* independent_funcs: PRINTVECT '(' resultant ')'  */
#line 544 "parser.y"
                                                                              {
							if((yyvsp[-1].Str).str[0] != '*'){
								printf("%d Error: Invalid argument for printVect function\n", yylineno);
								exit(1);
							}
							
							printTabs();
							fprintf(fIR, "printVect(%s);\n", (yyvsp[-1].Str).text);
						}
#line 2681 "y.tab.c"
    break;

  case 85: /* print_stmt: PRINT '(' print_body ')' ';'  */
#line 558 "parser.y"
                                                 {
							fprintf(fparse, " : PRINT STATEMENT");
							printTabs();
							fprintf(fIR, "cout << %s << endl;", (yyvsp[-2].Str).text);
							
						 }
#line 2692 "y.tab.c"
    break;

  case 86: /* print_body: print_body ',' print_constants  */
#line 567 "parser.y"
                                                        {
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].Str).text)+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, " << ");
								strcat(myText, (yyvsp[0].Str).text);
								(yyval.Str).text = myText;
							}
#line 2704 "y.tab.c"
    break;

  case 87: /* print_body: print_constants  */
#line 575 "parser.y"
                                                        {
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 2712 "y.tab.c"
    break;

  case 88: /* print_constants: constants  */
#line 580 "parser.y"
                                            {
							int a = !(strcmp((yyvsp[0].Str).str, "int")) || !(strcmp((yyvsp[0].Str).str, "float")) || !(strcmp((yyvsp[0].Str).str, "char")) || !(strcmp((yyvsp[0].Str).str, "string")) || !(strcmp((yyvsp[0].Str).str, "bool"));

							if(!a){
								printf("%d Error: Invalid argument as print object\n", yylineno);
								exit(1);
							}
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 2726 "y.tab.c"
    break;

  case 89: /* print_constants: extra_consts  */
#line 589 "parser.y"
                                                               {
							char* myText = (char*)malloc(strlen((yyvsp[0].Str).text)+3);
							strcpy(myText, "\"");
							strcat(myText, (yyvsp[0].Str).text);
							strcat(myText, "\"");
							(yyval.Str).text = myText;
						}
#line 2738 "y.tab.c"
    break;

  case 90: /* unary_stmt: unary_op ';'  */
#line 598 "parser.y"
                                                       {fprintf(fparse, " : UNARY STATEMENT"); printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text);}
#line 2744 "y.tab.c"
    break;

  case 93: /* $@9: %empty  */
#line 606 "parser.y"
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
#line 2760 "y.tab.c"
    break;

  case 94: /* label_stmt: id $@9 ':' function_body  */
#line 617 "parser.y"
                                                                          {fprintf(fparse, " : LABEL");}
#line 2766 "y.tab.c"
    break;

  case 95: /* goto_stmt: GOTO id ';'  */
#line 620 "parser.y"
                                                      {fprintf(fparse, " : GOTO STATEMENT"); printTabs(); fprintf(fIR, "goto %s;", (yyvsp[-1].Str).text);}
#line 2772 "y.tab.c"
    break;

  case 96: /* vect_stmt: vect_stmt_body ';'  */
#line 623 "parser.y"
                                                             {fprintf(fparse, " : INDEPENDENT METHOD");}
#line 2778 "y.tab.c"
    break;

  case 97: /* vect_stmt_body: resultant '.' APPEND '(' vect_append ')'  */
#line 626 "parser.y"
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
#line 2830 "y.tab.c"
    break;

  case 98: /* vect_stmt_body: resultant '.' REMOVE '(' remove_body ')'  */
#line 673 "parser.y"
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
#line 2873 "y.tab.c"
    break;

  case 99: /* vect_stmt_body: resultant '.' SORT '(' ')'  */
#line 711 "parser.y"
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
#line 2908 "y.tab.c"
    break;

  case 100: /* vect_stmt_body: resultant '.' CLEAR '(' ')'  */
#line 741 "parser.y"
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
#line 2943 "y.tab.c"
    break;

  case 101: /* remove_body: INT_CONST  */
#line 774 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 2949 "y.tab.c"
    break;

  case 102: /* remove_body: FLOAT_CONST  */
#line 775 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 2955 "y.tab.c"
    break;

  case 103: /* remove_body: LHS  */
#line 776 "parser.y"
                                                      {(yyval.Str).str=(yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 2961 "y.tab.c"
    break;

  case 104: /* remove_body: func_calls  */
#line 777 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2967 "y.tab.c"
    break;

  case 105: /* remove_body: arith_op  */
#line 778 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2973 "y.tab.c"
    break;

  case 106: /* remove_body: logical_op  */
#line 779 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2979 "y.tab.c"
    break;

  case 107: /* remove_body: impr  */
#line 780 "parser.y"
                                                       {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2985 "y.tab.c"
    break;

  case 108: /* vect_append: RHS  */
#line 784 "parser.y"
                                              {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2991 "y.tab.c"
    break;

  case 109: /* vect_append: extra_consts  */
#line 785 "parser.y"
                                                               {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 2997 "y.tab.c"
    break;

  case 110: /* $@10: %empty  */
#line 790 "parser.y"
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
#line 3056 "y.tab.c"
    break;

  case 111: /* return_stmt: RETURN RHS ';' $@10  */
#line 844 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3062 "y.tab.c"
    break;

  case 112: /* $@11: %empty  */
#line 846 "parser.y"
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
#line 3086 "y.tab.c"
    break;

  case 113: /* return_stmt: RETURN extra_consts ';' $@11  */
#line 865 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3092 "y.tab.c"
    break;

  case 114: /* $@12: %empty  */
#line 867 "parser.y"
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
#line 3135 "y.tab.c"
    break;

  case 115: /* return_stmt: RETURN graph_impr ';' $@12  */
#line 905 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3141 "y.tab.c"
    break;

  case 116: /* $@13: %empty  */
#line 907 "parser.y"
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
#line 3183 "y.tab.c"
    break;

  case 117: /* return_stmt: RETURN matrix_impr ';' $@13  */
#line 944 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3189 "y.tab.c"
    break;

  case 118: /* return_stmt: RETURN vect_stmt_body ';'  */
#line 946 "parser.y"
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
#line 3232 "y.tab.c"
    break;

  case 119: /* $@14: %empty  */
#line 985 "parser.y"
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
#line 3256 "y.tab.c"
    break;

  case 120: /* return_stmt: RETURN null ';' $@14  */
#line 1004 "parser.y"
                                                        {fprintf(fparse, " : RETURN STATEMENT");}
#line 3262 "y.tab.c"
    break;

  case 121: /* loop_stmt: LOOP loop_type  */
#line 1010 "parser.y"
                                                         {fprintf(fparse, " : LOOP");}
#line 3268 "y.tab.c"
    break;

  case 124: /* $@15: %empty  */
#line 1017 "parser.y"
                                                  {printTabs(); fprintf(fIR, "for(");}
#line 3274 "y.tab.c"
    break;

  case 125: /* $@16: %empty  */
#line 1017 "parser.y"
                                                                                                 {fprintf(fIR, ") ");}
#line 3280 "y.tab.c"
    break;

  case 127: /* $@17: %empty  */
#line 1021 "parser.y"
                                                                   {fprintf(fIR, "%s; ", (yyvsp[-1].Str).text);}
#line 3286 "y.tab.c"
    break;

  case 129: /* for_expr: unary_op  */
#line 1025 "parser.y"
                                                   {fprintf(fIR, "%s ", (yyvsp[0].Str).text);}
#line 3292 "y.tab.c"
    break;

  case 130: /* for_expr: EXPR LHS '=' for_RHS  */
#line 1026 "parser.y"
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
#line 3310 "y.tab.c"
    break;

  case 131: /* for_RHS: arith_op  */
#line 1042 "parser.y"
                                                   {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3316 "y.tab.c"
    break;

  case 132: /* for_RHS: func_calls  */
#line 1043 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3322 "y.tab.c"
    break;

  case 133: /* for_RHS: impr  */
#line 1044 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3328 "y.tab.c"
    break;

  case 134: /* for_RHS: graph_impr  */
#line 1045 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3334 "y.tab.c"
    break;

  case 135: /* for_RHS: vect_stmt_body  */
#line 1046 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3340 "y.tab.c"
    break;

  case 136: /* for_RHS: matrix_impr  */
#line 1047 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text; }
#line 3346 "y.tab.c"
    break;

  case 137: /* $@18: %empty  */
#line 1050 "parser.y"
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
#line 3364 "y.tab.c"
    break;

  case 139: /* expr_stmt: EXPR LHS '=' RHS ';'  */
#line 1066 "parser.y"
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
#line 3383 "y.tab.c"
    break;

  case 140: /* $@19: %empty  */
#line 1081 "parser.y"
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
									fprintf(fIR, "%s.vals = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
								}
								else if((yyvsp[-3].details).type[0] == '#')
								{
									if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str) && strcmp((yyvsp[-1].Str).str, "any")!=0)
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
#line 3473 "y.tab.c"
    break;

  case 141: /* expr_stmt: EXPR LHS '=' extra_consts ';' $@19  */
#line 1166 "parser.y"
                                                        {fprintf(fparse, " : EXPRESSION STATEMENT");}
#line 3479 "y.tab.c"
    break;

  case 142: /* expr_stmt: EXPR LHS '=' graph_impr ';'  */
#line 1168 "parser.y"
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
#line 3499 "y.tab.c"
    break;

  case 143: /* expr_stmt: EXPR LHS '=' matrix_impr ';'  */
#line 1183 "parser.y"
                                                                               {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)){
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							printTabs();
							fprintf(fIR, "%s = %s;\n", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
							fprintf(fparse, " : EXPRESSION STATEMENT");
						}
#line 3513 "y.tab.c"
    break;

  case 144: /* expr_stmt: EXPR LHS '=' vect_stmt_body ';'  */
#line 1192 "parser.y"
                                                                                  {
							if(strcmp((yyvsp[-3].details).type, (yyvsp[-1].Str).str)) {
								printf("%d Error: Expression statement, type mismatch\n", yylineno);
								exit(1);
							}
							fprintf(fparse, " : EXPRESSION STATEMENT");
							printTabs();
							fprintf(fIR, "%s = %s;", (yyvsp[-3].details).text, (yyvsp[-1].Str).text);
						}
#line 3527 "y.tab.c"
    break;

  case 145: /* LHS: myId  */
#line 1204 "parser.y"
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
#line 3608 "y.tab.c"
    break;

  case 146: /* LHS: LHS ARROW myId  */
#line 1280 "parser.y"
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
#line 3704 "y.tab.c"
    break;

  case 147: /* myId: id  */
#line 1374 "parser.y"
                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 3710 "y.tab.c"
    break;

  case 148: /* myId: id '[' RHS ']'  */
#line 1375 "parser.y"
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
#line 3730 "y.tab.c"
    break;

  case 149: /* declr_stmt: DECLR declr_body ';'  */
#line 1395 "parser.y"
                                                               {fprintf(fparse, " : DECLARATION STATEMENT"); fprintf(fIR, ";");}
#line 3736 "y.tab.c"
    break;

  case 150: /* declr_body: DATATYPE id_list  */
#line 1398 "parser.y"
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
#line 3788 "y.tab.c"
    break;

  case 151: /* declr_body: GRAPH graph_and_array_list  */
#line 1446 "parser.y"
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
#line 3859 "y.tab.c"
    break;

  case 152: /* declr_body: VECT '<' dtype '>' id_list  */
#line 1513 "parser.y"
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
#line 3911 "y.tab.c"
    break;

  case 153: /* declr_body: MATRIX matrix_list  */
#line 1561 "parser.y"
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
#line 3973 "y.tab.c"
    break;

  case 154: /* declr_body: DATATYPE graph_and_array_list  */
#line 1619 "parser.y"
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
#line 4027 "y.tab.c"
    break;

  case 155: /* declr_body: id id_list  */
#line 1669 "parser.y"
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
#line 4094 "y.tab.c"
    break;

  case 156: /* graph_and_array_list: graph_and_array_list ',' id '[' INT_CONST ']'  */
#line 1734 "parser.y"
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
#line 4121 "y.tab.c"
    break;

  case 157: /* graph_and_array_list: id '[' INT_CONST ']'  */
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
								
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, "[");
								strcat(myText, (yyvsp[-1].str));
								strcat(myText, "]");
								
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 4146 "y.tab.c"
    break;

  case 158: /* matrix_list: matrix_list ',' id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1780 "parser.y"
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
#line 4175 "y.tab.c"
    break;

  case 159: /* matrix_list: matrix_list ',' id '[' LHS ']' '[' LHS ']'  */
#line 1806 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-8].Str).text)+strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].details).text)+strlen((yyvsp[-1].details).text)+7);
								strcpy(myText, (yyvsp[-8].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].details).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].details).text);
								strcat(myText, ")");
								//strcpy($$.text, myText);
								//free(myText);
								(yyval.Str).text = myText;
							}
#line 4198 "y.tab.c"
    break;

  case 160: /* matrix_list: id '[' INT_CONST ']' '[' INT_CONST ']'  */
#line 1827 "parser.y"
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
#line 4224 "y.tab.c"
    break;

  case 161: /* matrix_list: id '[' LHS ']' '[' LHS ']'  */
#line 1849 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[-6].Str).str;
								
								arr_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-6].Str).text)+strlen((yyvsp[-4].details).text)+strlen((yyvsp[-1].details).text)+5);
								strcpy(myText, (yyvsp[-6].Str).text);
								strcat(myText, "(");
								strcat(myText, (yyvsp[-4].details).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[-1].details).text);
								strcat(myText, ")");
								
								(yyval.Str).text = myText;
							}
#line 4244 "y.tab.c"
    break;

  case 162: /* id_list: id_list ',' id  */
#line 1867 "parser.y"
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
#line 4261 "y.tab.c"
    break;

  case 163: /* id_list: id  */
#line 1880 "parser.y"
                                                        {
								arr[arr_size] = (yyvsp[0].Str).str;
								arr_size++;
								(yyval.Str).text = (yyvsp[0].Str).text;
							}
#line 4271 "y.tab.c"
    break;

  case 164: /* $@20: %empty  */
#line 1887 "parser.y"
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
#line 4290 "y.tab.c"
    break;

  case 166: /* $@21: %empty  */
#line 1904 "parser.y"
                                                             {fprintf(fIR, "else ");}
#line 4296 "y.tab.c"
    break;

  case 169: /* $@22: %empty  */
#line 1908 "parser.y"
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
#line 4315 "y.tab.c"
    break;

  case 171: /* $@23: %empty  */
#line 1925 "parser.y"
                                              {switch_insert(level); level++; fprintf(fIR, "{\n");}
#line 4321 "y.tab.c"
    break;

  case 172: /* $@24: %empty  */
#line 1925 "parser.y"
                                                                                                                      {printTabs(); fprintf(fIR, "default:\n");}
#line 4327 "y.tab.c"
    break;

  case 173: /* switch_body: '{' $@23 cases DEFAULT ':' $@24 function_body '}'  */
#line 1925 "parser.y"
                                                                                                                                                                                   { var_delete(level); level--; switch_delete(); printTabs(); fprintf(fIR, "}\n");}
#line 4333 "y.tab.c"
    break;

  case 174: /* $@25: %empty  */
#line 1928 "parser.y"
                                                                {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4339 "y.tab.c"
    break;

  case 176: /* $@26: %empty  */
#line 1929 "parser.y"
                                                                  {add_case(level-1, (yyvsp[0].str)); printTabs(); fprintf(fIR, "case %s:\n", (yyvsp[0].str)); }
#line 4345 "y.tab.c"
    break;

  case 178: /* RHS: constants  */
#line 1934 "parser.y"
                                                            {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4351 "y.tab.c"
    break;

  case 179: /* RHS: arith_op  */
#line 1935 "parser.y"
                                                           {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4357 "y.tab.c"
    break;

  case 180: /* RHS: logical_op  */
#line 1936 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4363 "y.tab.c"
    break;

  case 181: /* RHS: func_calls  */
#line 1937 "parser.y"
                                                             {(yyval.Str).str=(yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4369 "y.tab.c"
    break;

  case 182: /* RHS: impr  */
#line 1938 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4375 "y.tab.c"
    break;

  case 183: /* constants: INT_CONST  */
#line 1942 "parser.y"
                                                    {(yyval.Str).str="int"; (yyval.Str).text = (yyvsp[0].str);}
#line 4381 "y.tab.c"
    break;

  case 184: /* constants: FLOAT_CONST  */
#line 1943 "parser.y"
                                                              {(yyval.Str).str="float"; (yyval.Str).text = (yyvsp[0].str);}
#line 4387 "y.tab.c"
    break;

  case 185: /* constants: CHAR_CONST  */
#line 1944 "parser.y"
                                                             {(yyval.Str).str="char"; (yyval.Str).text = (yyvsp[0].str);}
#line 4393 "y.tab.c"
    break;

  case 186: /* constants: STR_CONST  */
#line 1945 "parser.y"
                                                            {(yyval.Str).str="string"; (yyval.Str).text = (yyvsp[0].str);}
#line 4399 "y.tab.c"
    break;

  case 187: /* constants: BOOL_CONST  */
#line 1946 "parser.y"
                                                             {(yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].str);}
#line 4405 "y.tab.c"
    break;

  case 188: /* constants: LHS  */
#line 1947 "parser.y"
                                                      {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4411 "y.tab.c"
    break;

  case 189: /* extra_consts: array_const  */
#line 1951 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4417 "y.tab.c"
    break;

  case 190: /* extra_consts: graph_const  */
#line 1952 "parser.y"
                                                             {(yyval.Str).str="graph"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4423 "y.tab.c"
    break;

  case 191: /* extra_consts: vect_const  */
#line 1953 "parser.y"
                                                            {
							char* myType = (char*)malloc(strlen((yyvsp[0].Str).str)+2);
							strcpy(myType, "*");
							strcat(myType, (yyvsp[0].Str).str);
							(yyval.Str).str = myType;
							 (yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 4435 "y.tab.c"
    break;

  case 192: /* extra_consts: matrix_const  */
#line 1960 "parser.y"
                                                              {(yyval.Str).str="matrix"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4441 "y.tab.c"
    break;

  case 193: /* extra_consts: '{' '}'  */
#line 1961 "parser.y"
                                                         {(yyval.Str).str="1"; (yyval.Str).text = "{}";}
#line 4447 "y.tab.c"
    break;

  case 194: /* array_const: '[' val_list ']'  */
#line 1965 "parser.y"
                                                        {
								
								(yyval.Str).str = (yyvsp[-1].Str).text;
								
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								
								(yyval.Str).text = myText;
							}
#line 4463 "y.tab.c"
    break;

  case 195: /* array_const: '[' ']'  */
#line 1977 "parser.y"
                                                        {
								(yyval.Str).str = "any";
								(yyval.Str).text = "{}";
							}
#line 4472 "y.tab.c"
    break;

  case 196: /* val_list: int_list  */
#line 1984 "parser.y"
                                                        { (yyval.Str).str = "int"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4478 "y.tab.c"
    break;

  case 197: /* val_list: float_list  */
#line 1986 "parser.y"
                                                        { (yyval.Str).str  = "float"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4484 "y.tab.c"
    break;

  case 198: /* val_list: char_list  */
#line 1988 "parser.y"
                                                        { (yyval.Str).str = "char"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4490 "y.tab.c"
    break;

  case 199: /* val_list: bool_list  */
#line 1990 "parser.y"
                                                        { (yyval.Str).str = "bool"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4496 "y.tab.c"
    break;

  case 200: /* val_list: str_list  */
#line 1992 "parser.y"
                                                        { (yyval.Str).str = "string"; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4502 "y.tab.c"
    break;

  case 201: /* resultant: LHS  */
#line 1994 "parser.y"
                                             {(yyval.Str).str = (yyvsp[0].details).type; (yyval.Str).text = (yyvsp[0].details).text;}
#line 4508 "y.tab.c"
    break;

  case 202: /* resultant: matrix_impr  */
#line 1995 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4514 "y.tab.c"
    break;

  case 203: /* resultant: graph_impr  */
#line 1996 "parser.y"
                                                             {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4520 "y.tab.c"
    break;

  case 204: /* resultant: vect_stmt_body  */
#line 1997 "parser.y"
                                                                 {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4526 "y.tab.c"
    break;

  case 205: /* resultant: impr  */
#line 1998 "parser.y"
                                                       {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4532 "y.tab.c"
    break;

  case 206: /* resultant: func_calls  */
#line 1999 "parser.y"
                                                            {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 4538 "y.tab.c"
    break;

  case 207: /* impr: resultant '.' LENGTH '(' ')'  */
#line 2003 "parser.y"
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
#line 4560 "y.tab.c"
    break;

  case 208: /* impr: resultant '.' AT '(' remove_body ')'  */
#line 2020 "parser.y"
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
#line 4595 "y.tab.c"
    break;

  case 209: /* impr: resultant '.' TRACE '(' ')'  */
#line 2050 "parser.y"
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
#line 4614 "y.tab.c"
    break;

  case 210: /* impr: resultant '.' STRLEN '(' ')'  */
#line 2065 "parser.y"
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
#line 4634 "y.tab.c"
    break;

  case 211: /* impr: STRCMP '(' RHS ',' RHS ')'  */
#line 2081 "parser.y"
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
#line 4658 "y.tab.c"
    break;

  case 212: /* impr: resultant '.' STRCUT '(' remove_body ',' remove_body ')'  */
#line 2101 "parser.y"
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
#line 4688 "y.tab.c"
    break;

  case 213: /* impr: STRJOIN '(' RHS ',' RHS ')'  */
#line 2127 "parser.y"
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
#line 4711 "y.tab.c"
    break;

  case 214: /* graph_impr: resultant '.' TRAVERSAL '(' remove_body ')'  */
#line 2148 "parser.y"
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
#line 4738 "y.tab.c"
    break;

  case 215: /* graph_impr: resultant '.' GRTOMATX '(' ')'  */
#line 2171 "parser.y"
                                                        {
								(yyval.Str).str = "matrix";
								if(strcmp((yyvsp[-4].Str).str,"graph"))
								{
									printf("%d ERROR: Method applicable only for graph datatype\n", yylineno);
									exit(1);
								}
							}
#line 4751 "y.tab.c"
    break;

  case 216: /* graph_impr: resultant '.' SHPATH '(' remove_body ',' remove_body ')'  */
#line 2180 "parser.y"
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
#line 4778 "y.tab.c"
    break;

  case 217: /* graph_impr: resultant '.' SHPATH_VAL '(' remove_body ',' remove_body ')'  */
#line 2203 "parser.y"
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
#line 4805 "y.tab.c"
    break;

  case 218: /* matrix_impr: MATXOP '(' matr_body ',' matr_body ')'  */
#line 2229 "parser.y"
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
#line 4827 "y.tab.c"
    break;

  case 219: /* matrix_impr: resultant '.' TRANSPOSE '(' ')'  */
#line 2247 "parser.y"
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
#line 4846 "y.tab.c"
    break;

  case 220: /* matrix_impr: resultant '.' MAXTOGR '(' ')'  */
#line 2262 "parser.y"
                                                        {
								(yyval.Str).str = "graph";
								if(strcmp((yyvsp[-4].Str).str, "matrix"))
								{
									printf("%d ERROR: Method defined for matrix datatype only\n", yylineno);
									exit(1);
								}
							}
#line 4859 "y.tab.c"
    break;

  case 221: /* matrix_impr: resultant '.' GETVAL '(' remove_body ',' remove_body ')'  */
#line 2271 "parser.y"
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
#line 4889 "y.tab.c"
    break;

  case 222: /* matr_body: RHS  */
#line 2298 "parser.y"
                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4895 "y.tab.c"
    break;

  case 223: /* matr_body: matrix_impr  */
#line 2299 "parser.y"
                                                              {(yyval.Str).str = (yyvsp[0].Str).str;}
#line 4901 "y.tab.c"
    break;

  case 224: /* graph_const: '{' graph_type1 '}'  */
#line 2302 "parser.y"
                                                              {
								printTabs();
								fprintf(fIR, "%s.setFlag(0);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4915 "y.tab.c"
    break;

  case 225: /* graph_const: '{' graph_type2 '}'  */
#line 2311 "parser.y"
                                                                      {
								printTabs();
								fprintf(fIR, "%s.setFlag(1);\n", LeftName);
								char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-1].Str).text);
								strcat(myText, "}");
								(yyval.Str).text = myText;
							}
#line 4929 "y.tab.c"
    break;

  case 226: /* graph_type1: graph_type1 INT_CONST ':' int_list ';'  */
#line 2323 "parser.y"
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
#line 4963 "y.tab.c"
    break;

  case 227: /* graph_type1: INT_CONST ':' int_list ';'  */
#line 2353 "parser.y"
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
#line 4994 "y.tab.c"
    break;

  case 228: /* graph_type2: graph_type2 INT_CONST ':' weight_list ';'  */
#line 2382 "parser.y"
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
#line 5025 "y.tab.c"
    break;

  case 229: /* graph_type2: INT_CONST ':' weight_list ';'  */
#line 2409 "parser.y"
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
#line 5054 "y.tab.c"
    break;

  case 230: /* $@27: %empty  */
#line 2436 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 5063 "y.tab.c"
    break;

  case 231: /* int_list: int_list ',' INT_CONST $@27  */
#line 2440 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								char* myText = (char*)malloc(strlen((yyvsp[-3].Str).text)+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].Str).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5076 "y.tab.c"
    break;

  case 232: /* $@28: %empty  */
#line 2449 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[0].str));
								dummy_size++;
							}
#line 5085 "y.tab.c"
    break;

  case 233: /* int_list: INT_CONST $@28  */
#line 2453 "parser.y"
                                                        {
								(yyval.Str).str = "int";
								(yyval.Str).text = (yyvsp[-1].str);
							}
#line 5094 "y.tab.c"
    break;

  case 234: /* float_list: float_list ',' FLOAT_CONST  */
#line 2460 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5108 "y.tab.c"
    break;

  case 235: /* float_list: FLOAT_CONST  */
#line 2470 "parser.y"
                                                        {
								(yyval.Str).str = "float";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5118 "y.tab.c"
    break;

  case 236: /* char_list: char_list ',' CHAR_CONST  */
#line 2478 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5132 "y.tab.c"
    break;

  case 237: /* char_list: CHAR_CONST  */
#line 2488 "parser.y"
                                                        {
								(yyval.Str).str = "char";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5142 "y.tab.c"
    break;

  case 238: /* bool_list: bool_list ',' BOOL_CONST  */
#line 2496 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5156 "y.tab.c"
    break;

  case 239: /* bool_list: BOOL_CONST  */
#line 2506 "parser.y"
                                                        {
								(yyval.Str).str = "bool";
								dummy_size;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5166 "y.tab.c"
    break;

  case 240: /* str_list: str_list ',' STR_CONST  */
#line 2514 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Str).text)+strlen((yyvsp[0].str))+3);
								strcpy(myText, (yyvsp[-2].Str).text);
								strcat(myText, ", ");
								strcat(myText, (yyvsp[0].str));
								(yyval.Str).text = myText;
							}
#line 5180 "y.tab.c"
    break;

  case 241: /* str_list: STR_CONST  */
#line 2524 "parser.y"
                                                        {
								(yyval.Str).str = "string";
								dummy_size++;
								(yyval.Str).text = (yyvsp[0].str);
							}
#line 5190 "y.tab.c"
    break;

  case 242: /* weight_list: weight_list ',' '(' INT_CONST ',' INT_CONST ')'  */
#line 2532 "parser.y"
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
#line 5207 "y.tab.c"
    break;

  case 243: /* weight_list: '(' INT_CONST ',' INT_CONST ')'  */
#line 2545 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5221 "y.tab.c"
    break;

  case 244: /* weight_list: weight_list ',' '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2555 "parser.y"
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
#line 5237 "y.tab.c"
    break;

  case 245: /* weight_list: '(' INT_CONST ',' FLOAT_CONST ')'  */
#line 2567 "parser.y"
                                                        {
								newArr[dummy_size] = atoi((yyvsp[-3].str));
								dummy_size++;
								char* myText = (char*)malloc(strlen((yyvsp[-3].str))+strlen((yyvsp[-1].str))+3);
								strcpy(myText, (yyvsp[-3].str));
								strcat(myText, ",");
								strcat(myText, (yyvsp[-1].str));
								(yyval.Str).text = myText;
							}
#line 5251 "y.tab.c"
    break;

  case 246: /* vect_const: '{' vect_list '}'  */
#line 2578 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[-1].Str).str;
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 5264 "y.tab.c"
    break;

  case 247: /* vect_list: vect_list ',' vect_item  */
#line 2588 "parser.y"
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
#line 5287 "y.tab.c"
    break;

  case 248: /* vect_list: vect_item  */
#line 2606 "parser.y"
                                                            {
							(yyval.Str).str = (yyvsp[0].Str).str;
							(yyval.Str).text = (yyvsp[0].Str).text;
						}
#line 5296 "y.tab.c"
    break;

  case 249: /* vect_item: constants  */
#line 2612 "parser.y"
                                                    {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5302 "y.tab.c"
    break;

  case 250: /* vect_item: extra_consts  */
#line 2613 "parser.y"
                                                               {(yyval.Str).str = (yyvsp[0].Str).str; (yyval.Str).text = (yyvsp[0].Str).text;}
#line 5308 "y.tab.c"
    break;

  case 251: /* matrix_const: '[' mat_list ']'  */
#line 2616 "parser.y"
                                                   {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Cols).text)+3);
							strcpy(myText, "{");
							strcat(myText, (yyvsp[-1].Cols).text);
							strcat(myText, "}");
							(yyval.Str).text = myText;
						}
#line 5320 "y.tab.c"
    break;

  case 252: /* int_float_list: int_float_list ',' INT_CONST  */
#line 2626 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5333 "y.tab.c"
    break;

  case 253: /* int_float_list: int_float_list ',' FLOAT_CONST  */
#line 2635 "parser.y"
                                                        {
								(yyval.Cols).cols = (yyvsp[-2].Cols).cols+1;
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+strlen((yyvsp[0].str))+2);
								strcpy(myText, (yyvsp[-2].Cols).text);
								strcat(myText, ",");
								strcat(myText, (yyvsp[0].str));
								(yyval.Cols).text = myText;
							}
#line 5346 "y.tab.c"
    break;

  case 254: /* int_float_list: INT_CONST  */
#line 2644 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5355 "y.tab.c"
    break;

  case 255: /* int_float_list: FLOAT_CONST  */
#line 2649 "parser.y"
                                                        {
								(yyval.Cols).cols=1;
								(yyval.Cols).text = (yyvsp[0].str);
							}
#line 5364 "y.tab.c"
    break;

  case 256: /* mat_list: mat_list '[' int_float_list ']' ';'  */
#line 2656 "parser.y"
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
#line 5380 "y.tab.c"
    break;

  case 257: /* mat_list: '[' int_float_list ']' ';'  */
#line 2668 "parser.y"
                                                        {
								newArr[dummy_size]=(yyvsp[-2].Cols).cols;
								dummy_size++;
								
								char* myText = (char*)malloc(strlen((yyvsp[-2].Cols).text)+3);
								strcpy(myText, "{");
								strcat(myText, (yyvsp[-2].Cols).text);
								strcat(myText, "}");
								(yyval.Cols).text = myText;
								
							}
#line 5396 "y.tab.c"
    break;

  case 260: /* binary_op: ARITHOP '(' RHS ',' RHS ')'  */
#line 2686 "parser.y"
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
#line 5445 "y.tab.c"
    break;

  case 261: /* unary_op: UNARYOP '(' RHS ')'  */
#line 2732 "parser.y"
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
#line 5468 "y.tab.c"
    break;

  case 262: /* logical_op: '(' RHS LOGOP RHS ')'  */
#line 2752 "parser.y"
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
#line 5507 "y.tab.c"
    break;

  case 263: /* logical_op: NOT '(' RHS ')'  */
#line 2786 "parser.y"
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
#line 5527 "y.tab.c"
    break;

  case 264: /* call_stmt: func_calls ';'  */
#line 2804 "parser.y"
                                                         {fprintf(fparse, " : CALL STATEMENT"); classIndex = -1; printTabs(); fprintf(fIR, "%s;", (yyvsp[-1].Str).text); }
#line 5533 "y.tab.c"
    break;

  case 265: /* func_calls: call_head arguments  */
#line 2809 "parser.y"
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
#line 5560 "y.tab.c"
    break;

  case 266: /* call_head: CALL LHS  */
#line 2834 "parser.y"
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
#line 5578 "y.tab.c"
    break;

  case 267: /* arguments: '(' arg_list ')'  */
#line 2849 "parser.y"
                                                           {
							char* myText = (char*)malloc(strlen((yyvsp[-1].Str).text) + 3);
							strcpy(myText, "(");
							strcat(myText, (yyvsp[-1].Str).text);
							strcat(myText, ")");
							(yyval.Str).text = myText;
							// strcpy($$.text, myText);
							// free(myText);
						}
#line 5592 "y.tab.c"
    break;

  case 268: /* arguments: '(' ')'  */
#line 2858 "parser.y"
                                                          {(yyval.Str).text = "()";}
#line 5598 "y.tab.c"
    break;

  case 269: /* arg_list: arg_list ',' RHS  */
#line 2861 "parser.y"
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
#line 5653 "y.tab.c"
    break;

  case 270: /* arg_list: RHS  */
#line 2911 "parser.y"
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
#line 5709 "y.tab.c"
    break;


#line 5713 "y.tab.c"

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

#line 2964 "parser.y"


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




