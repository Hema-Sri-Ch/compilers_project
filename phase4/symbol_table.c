#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct data_node
{
    int vp_flag; // p=0, v=1
    int level;
    char* name;
    char* type;
    char* ele_type; // A, V
    int dim_A; // A, G, M
    int dim_B; // only for matrix
};

struct struct_node
{
    struct data_node list[20];
    char* name;
    int list_size;
};

struct func_node
{
    char* name;
    char* type;
    char* args[20];
    int param_no;
};

struct class_node
{
    char* name;
    struct func_node func_list[20];
    int cl_func_size;
    struct data_node declr_list[20];
    int declr_size;
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

struct func_node func_symb[50];
struct data_node var_symb[100];
struct struct_node struct_symb[20];
struct class_node class_symb[20];
struct switch_cases switch_symb[10];
char* label_symb[20];

int var_size=0;
int func_size=0;    
int struct_size=0;
int class_size=0;
int switch_size=0;
int label_size=0;


// VARIABLE & PARAMETER SYMBOL TABLE

void printVarNode(struct data_node node){
	printf("Name : %s;	", node.name);
	printf("Type : %s;	", node.type);
	printf("Level: %d\n", node.level);
}

void var_insert(int Flag, int Level, char* Name, char* Type, char* Ele_type, int Dim_A, int Dim_B)
{
    var_symb[var_size].vp_flag = Flag;
    var_symb[var_size].name = Name;
    var_symb[var_size].type = Type;
    var_symb[var_size].level = Level;
    var_symb[var_size].dim_A = Dim_A;
    var_symb[var_size].dim_B = Dim_B;
    var_symb[var_size].ele_type = Ele_type;
    // printVarNode(var_symb[var_size]);
    var_size++;
}


int var_search(char* Name)
{
    // int ind = func_symb[func_size-1].param_start;
    for(int i=0; i<var_size; i++)
    {
        if(strcmp(Name, var_symb[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

void var_delete(int cur_level)
{
    while(var_size>0)
    {
        if(var_symb[var_size-1].level==cur_level)
        {
            var_size--;
        }
        else break;
    }
}


// FUNCTION SYMBOL TABLE

void printFuncDetails(int cInd, int fInd){
	if(cInd == -1){
		printf("Name: %s\n", func_symb[fInd].name);
		printf("Type: %s\n", func_symb[fInd].type);
		printf("Args: ");
		for(int i=0; i<func_symb[fInd].param_no; i++) printf("%s, ", func_symb[fInd].args[i]); 
		printf("\n");
	}
	else{
		int cl_func_size = class_symb[cInd].cl_func_size;
		printf("Name: %s\n", class_symb[cInd].func_list[cl_func_size-1].name);
		printf("Type: %s\n", class_symb[cInd].func_list[cl_func_size-1].type);
		printf("Args: ");
		for(int i=0; i<class_symb[cInd].func_list[cl_func_size-1].param_no; i++) printf("%s, ", class_symb[cInd].func_list[cl_func_size-1].args[i]); 
		printf("\n");
	}
}

void func_insert(char* Name, char* Type) // to insert function details at begining
{
    func_symb[func_size].name = Name;
    func_symb[func_size].type = Type;
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


// CLASS SYMBOL TABLE

void printClassNode(struct class_node node){
	printf("Name: %s\n", node.name);
	printf("Attributes: ");
	for(int i=0; i<node.declr_size; i++) printf("%s, ", node.declr_list[i].name);
	printf("\n");
	printf("Functions: ");
	for(int i=0; i<node.cl_func_size; i++) printf("%s ", node.func_list[i].name);
	printf("\n");
}


void class_insert(char* Name)
{
    class_symb[class_size].name = Name;
    class_symb[class_size].declr_size=0;
    class_symb[class_size].cl_func_size=0;
    class_size++;
}

void add_class_declrs(char* Name, char* Type, int Flag, int Level, char* Ele_type, int Dim_A, int Dim_B )
{
    int ind = class_size-1;
    int declr_size = class_symb[ind].declr_size;

    class_symb[ind].declr_list[declr_size].ele_type = Ele_type;
    class_symb[ind].declr_list[declr_size].name = Name;
    class_symb[ind].declr_list[declr_size].dim_A = Dim_A;
    class_symb[ind].declr_list[declr_size].dim_B = Dim_B;
    class_symb[ind].declr_list[declr_size].type = Type;
    class_symb[ind].declr_list[declr_size].vp_flag = Flag;
    class_symb[ind].declr_list[declr_size].level = Level;
    class_symb[ind].declr_size++;
}

void class_func_insert(int ind, char* Name, char* Type)
{
    int cl_func_size = class_symb[ind].cl_func_size;

    class_symb[ind].func_list[cl_func_size].name = Name;
    class_symb[ind].func_list[cl_func_size].type = Type;
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

// STRUCT SYMBOL TABLE

void printStructNode(struct struct_node node){
	printf("Name: %s\n", node.name);
	printf("Struct args: ");
	for(int i=0; i<node.list_size; i++) printf("%s: %s; ", node.list[i].name, node.list[i].type);
	printf("\n");
}

void struct_insert(char* Name)
{
    struct_symb[struct_size].name = Name;
    struct_symb[struct_size].list_size = 0;
    struct_size++;
}

void add_struct_declrs(char* Name, char* Type, int Flag, int Level, char* Ele_type, int Dim_A, int Dim_B )
{
    int ind = struct_size-1;
    int list_size = struct_symb[ind].list_size;

    struct_symb[ind].list[list_size].vp_flag = Flag;
    struct_symb[ind].list[list_size].name = Name;
    struct_symb[ind].list[list_size].type = Type;
    struct_symb[ind].list[list_size].ele_type = Ele_type;
    struct_symb[ind].list[list_size].level = Level;
    struct_symb[ind].list[list_size].dim_A = Dim_A;
    struct_symb[ind].list[list_size].dim_B = Dim_B;
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

void add_case(int Level, char* Case_no)
{
	int case_no = atoi(Case_no);
    int case_size = switch_symb[switch_size-1].case_size;

    for(int i=0; i<case_size; i++)
    {
        if(case_no==switch_symb[switch_size-1].case_list[i])
        {
        	printf("Error: Duplicate cases in switch\n");
            exit(1); //EXIT STATEMENT
        }
    }
    switch_symb[switch_size-1].case_list[case_size] = case_no;
    switch_symb[switch_size-1].case_size++;
}

void switch_delete()
{
	switch_symb[switch_size-1].case_size = 0;
    switch_size--;
}

// LABEL SYMBOL TABLE
void label_insert(char* Name)
{
    label_symb[label_size] = Name;
    label_size++;
}

int label_search(char* Name)
{
    for(int i=0; i<label_size; i++)
    {
        if(strcmp(label_symb[i], Name)==0) return i;
    }
    return -1;
}
