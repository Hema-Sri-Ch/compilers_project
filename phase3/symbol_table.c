#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct id_node
{
    int vp_flag; // v = 1; p = 0
    char* name;
    char* type;
    int level;
    int dtype_flag; // standard = -1, class =0, struct =1
};

struct struct_node
{
    struct id_node list[20];
    char* name;
    int list_size;
};

struct func_node
{
    char* name;
    char* type;
    int var_start;
    int param_start;
    char* args[20];
    int param_no;
};

struct class_node
{
    char* name;
    struct id_node declr_list[20];
    int declr_size;
    struct func_node func_list[20];
    int cl_func_size;
};

struct array_node
{
	char* name;
    char* ele_type;
    int size;
};

struct vect_node
{
	char* name;
    char* ele_type;
    int size;
};

struct matrix_node
{
	char* name;
    int row_dim;
    int col_dim;
};

struct graph_node
{
	char* name;
    int vert_no;
    int weight_type;
};

struct switch_cases
{
    int case_list[50];
    int case_size;
    int level;
};

struct id_node var_symb[100];
struct func_node func_symb[50];
struct vect_node vect_symb[20];
struct array_node arr_symb[20];
struct matrix_node matrix_symb[20];
struct graph_node graph_symb[20];
struct struct_node struct_symb[20];
struct class_node class_symb[20];
struct switch_cases switch_symb[10];

int var_size=0;
int func_size=0;
int vect_size=0;
int array_size=0;
int matrix_size=0;
int graph_size=0;
int struct_size=0;
int class_size=0;
int switch_size=0;


void reset(){
	var_size=0;
	func_size=0;
	vect_size=0;
	array_size=0;
	matrix_size=0;
	graph_size=0;
	struct_size=0;
	class_size=0;
	switch_size=0;
}


// VARIABLE & PARAMETER SYMBOL TABLE

void PrintIdnode(struct id_node node){
	printf("Name: %s\n", node.name);
	printf("type: %s\n", node.type);
	/*int vp_flag; // v = 1; p = 0
    char* name;
    char* type;
    int level;
    int dtype_flag; // standard = -1, class =0, struct =1, func=2*/
}

void var_insert(int Flag, char* Name, char* Type, int Level, int Dtype_flag)
{
    var_symb[var_size].vp_flag = Flag;
    var_symb[var_size].name = Name;
    var_symb[var_size].type = Type;
    var_symb[var_size].level = Level;
    var_symb[var_size].dtype_flag = Dtype_flag;
    PrintIdnode(var_symb[var_size]);
    var_size++;
}


int var_search(char* Name)
{
    // int ind = func_symb[func_size-1].param_start;
    int ind = 0;
    for(int i=ind; i<var_size; i++)
    {
        if(strcmp(Name, var_symb[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

void var_delete()
{
    int cur_level = var_symb[var_size-1].level;
    while(var_size>0)
    {
        if(var_symb[var_size-1].level==cur_level)
        {
            if(strcmp(var_symb[var_size-1].type,"array")==0) array_size--;
            if(strcmp(var_symb[var_size-1].type,"vector")==0) vect_size--;
            if(strcmp(var_symb[var_size-1].type,"matrix")==0) matrix_size--;
            if(strcmp(var_symb[var_size-1].type,"graph")==0) graph_size--;
            var_size--;
        }
        else break;
    }
}


// FUNCTION SYMBOL TABLE

void printFuncDetails(int ind){
	printf("Name: %s\n", func_symb[ind].name);
	printf("Type: %s\n", func_symb[ind].type);
	printf("Args: ");
	for(int i=0; i<func_symb[ind].param_no; i++) printf("%s, ", func_symb[ind].args[i]); 
	printf("\n");
}

void func_insert(char* Name, char* Type) // to insert function details at begining
{
    func_symb[func_size].name = Name;
    func_symb[func_size].type = Type;
    func_symb[func_size].var_start = 0;
    func_symb[func_size].param_start = 0;
    func_symb[func_size].param_no =0;
    func_size++;
}

void add_args(char* arg) // to insert function argument details at beginning
{
    int param_no = func_symb[func_size-1].param_no;
    func_symb[func_size-1].args[param_no] = arg;
    func_symb[func_size-1].param_no++;
}

int func_search(char* Name) // returns index of the function from its symbol table
{
    for(int i=0; i<func_size; i++)
    {
        if(strcmp(Name, func_symb[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

void func_set(int Var_start, int Param_start, int ind) // sets level of scopes while executing call statements
{

    if(Var_start != -1) func_symb[ind].var_start = Var_start;
    if(Param_start != -1) func_symb[ind].param_start = Param_start;
}

void func_delete(int ind) // sets level of scopes after ending function execution
{
    func_symb[ind].var_start=-1;
    func_symb[ind].param_start=-1;
}

// CLASS SYMBOL TABLE

void class_insert(char* Name)
{
    class_symb[class_size].name = Name;
    class_symb[class_size].declr_size=0;
    class_symb[class_size].cl_func_size=0;
    class_size++;
}

void add_class_declrs(int ind, char* Name, char* Type, int Dtype_flag)
{
    int declr_size = class_symb[ind].declr_size;

    class_symb[ind].declr_list[declr_size].vp_flag =-1;
    class_symb[ind].declr_list[declr_size].name = Name;
    class_symb[ind].declr_list[declr_size].type = Type;
    class_symb[ind].declr_list[declr_size].level = -1;
    class_symb[ind].declr_list[declr_size].dtype_flag = Dtype_flag;
    class_symb[ind].declr_size++;
}

void class_func_insert(int ind, char* Name, char* Type)
{
    int cl_func_size = class_symb[ind].cl_func_size;

    class_symb[ind].func_list[cl_func_size].name = Name;
    class_symb[ind].func_list[cl_func_size].type = Type;
    class_symb[ind].func_list[cl_func_size].var_start = -1;
    class_symb[ind].func_list[cl_func_size].param_start = -1;
    class_symb[ind].func_list[cl_func_size].param_no =0;
    class_symb[ind].cl_func_size++;
}

void class_add_args(int ind, char* arg)
{
    int cl_func_size = class_symb[ind].cl_func_size;

    int param_no = class_symb[ind].func_list[cl_func_size-1].param_no;
    class_symb[ind].func_list[cl_func_size-1].args[param_no] = arg;
    class_symb[ind].func_list[cl_func_size-1].param_no++;
}

int class_func_search(char* Name, int ind)
{
    for(int i=0; i<class_symb[ind].cl_func_size; i++)
    {
        if(strcmp(Name, class_symb[ind].func_list[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}


void class_func_set(int ind, int Var_start, int Param_start, char* Name)
{
    int indx = class_func_search(Name, ind); 

    if(Var_start!=-1) class_symb[ind].func_list[indx].var_start = Var_start;
    if(Param_start!=-1) class_symb[ind].func_list[indx].param_start = Param_start;
}


int class_declr_search(char* Name, int ind)
{
    for(int i=0; i<class_symb[ind].declr_size; i++)
    {
        if(strcmp(Name, class_symb[ind].declr_list[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

int class_search(char* Name)
{
    for(int i=0; i<class_size; i++)
    {
        if(strcmp(Name, class_symb[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

void class_func_delete(int ind, char* Name)
{
    int indx = class_func_search(Name, ind); 
    class_symb[ind].func_list[indx].var_start=-1;
    class_symb[ind].func_list[indx].param_start=-1;
}


// STRUCT SYMBOL TABLE


void struct_insert(char* Name)
{
    struct_symb[struct_size].name = Name;
    struct_symb[struct_size].list_size = 0;
    struct_size++;
}

void add_struct_declrs(int ind, char* Name, char* Type, int Dtype_flag)
{
    int list_size = struct_symb[ind].list_size;

    struct_symb[ind].list[list_size].vp_flag = -1;
    struct_symb[ind].list[list_size].name = Name;
    struct_symb[ind].list[list_size].type = Type;
    struct_symb[ind].list[list_size].level = -1;
    struct_symb[ind].list[list_size].dtype_flag = Dtype_flag;
    struct_symb[ind].list_size++;
}


int struct_declr_search(char* Name, int ind)
{
    for(int i=0; i<struct_symb[ind].list_size; i++)
    {
        if(strcmp(Name, struct_symb[ind].list[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

int struct_search(char* Name)
{
    for(int i=0; i<struct_size; i++)
    {
        if(strcmp(Name, struct_symb[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

// SWITCH SYMBOL TABLE

void switch_insert(int Level)
{
    switch_symb[switch_size].level = Level;
    switch_size++;
}

void add_case(int Level, int case_no)
{
    int case_size = switch_symb[switch_size-1].case_size;

    for(int i=0; i<case_size; i++)
    {
        if(case_no==switch_symb[switch_size-1].case_list[i])
        {
            return; //EXIT STATEMENT
        }
    }
    switch_symb[switch_size-1].case_list[case_size] = case_no;
    switch_symb[switch_size-1].case_size++;
}

void switch_delete()
{
    switch_size--;
}


// ARRAY SYMBOL TABLE
void array_insert(char* Name, char* Ele_type, int Size)
{
	arr_symb[array_size].name = Name;
    arr_symb[array_size].ele_type = Ele_type;
    arr_symb[array_size].size = Size;
    array_size++;
}
void vect_insert(char* Name, char* Ele_type, int Size)
{
	vect_symb[vect_size].name = Name;
    vect_symb[vect_size].ele_type = Ele_type;
    vect_symb[vect_size].size = Size;
    vect_size++;
}

void matrix_insert(char* Name, int row, int col)
{
	matrix_symb[matrix_size].name = Name;
    matrix_symb[matrix_size].row_dim = row;
    matrix_symb[matrix_size].col_dim = col;
    matrix_size++;
}

void graph_insert(char* Name, int vert, int weight)
{
	graph_symb[graph_size].name = Name;
    graph_symb[graph_size].vert_no = vert;
    graph_symb[graph_size].weight_type = weight;
    graph_size++;
}


