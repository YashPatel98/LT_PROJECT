#include <stdlib.h>
#include <stdio.h>

typedef struct TokenInfo{
	char token[30];
	char value[30];
	int line;
	struct TokenInfo* nextToken;
}tokenInfo;
typedef struct IdInfo{
	char id[30];
	char value[30];
	char datatype[30];
	int idn;
	struct IdInfo* nextId; 
}idInfo;
/*
struct Node{
	tokenInfo* tk;         
};
typedef struct Node node;
struct iNode{
	idInfo* ii;         
};
typedef struct iNode inode;

struct head{
	struct Node* headlink;
};
typedef struct head *header;
struct ihead{
	inode* headlink;
};

typedef struct ihead* iheader;*/
