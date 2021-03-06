#include <stdlib.h>
#include <stdio.h>

//keywords
char* keyword_dict[30] = {"integer","real","boolean","of","array","start","end","declare","module","driver","program","get_value","print","use","with","parameters","true","false","takes","input","returns","AND","OR","for","in","switch","case","break","default","while"};             

//tokens
char* token_key[30] = {"INTEGER","REAL","BOOLEAN","OF","ARRAY","START","END","DECLARE","MODULE","DRIVER","PROGRAM","GET_VALUE","PRINT","USE","WITH","PARAMETERS","TRUE","FALSE","TAKES","INPUT","RETURNS","AND","OR","FOR","IN","SWITCH","CASE","BREAK","DEFAULT","WHILE"};              

typedef char* buffer;

int state;

struct TokenInfo{
	char token[30];
	char value[30];
	int line;
};

typedef struct TokenInfo tokenInfo;

struct Node{
	tokenInfo* tk;         
};

typedef struct Node node;

struct head{
	struct Node* headlink;
};

typedef struct head *header;