%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <stdarg.h>
	#include "global.h"
	int idline=0; 
	int yylex(void);
	void yyerror(char *);
	tokenInfo* createnode(tokenInfo** head_ref){
    		tokenInfo* mynode = (tokenInfo*)malloc(sizeof(tokenInfo));
		mynode->nextToken = (*head_ref);
    		return mynode;
	}
	idInfo* createinode(idInfo** ihead){
    		idInfo* myinode = (idInfo*)malloc(sizeof(idInfo));
		myinode->nextId = (*ihead);
    		return myinode;
	}
	tokenInfo* tk = NULL;
	tokenInfo* dt = NULL;
	idInfo* idh = NULL;
	/*header initialise_head(){
    		header new = (header)malloc(sizeof(struct head));
    		new->headlink = NULL;
    	return new;
	}
	iheader initialise_ihead(){
    		iheader inew = (iheader)malloc(sizeof(struct ihead));
    		inew->headlink = NULL;
    	return inew;
	}
	iheader head[100];*/
%}
%union { int num; float rnum; char *id; tokenInfo* nodePtr; idInfo* inodePtr; };
%token INTEGER
%token REAL
%token BOOLEAN
%token OF
%token ARRAY
%token START
%token END
%token DECLARE
%token MODULE
%token PROGRAM
%token GET_VALUE
%token PRINT
%token USE
%token WITH
%token PARAMETERS
%token TRUEV
%token FALSEV
%token TAKES
%token INPUT
%token RETURNS
%token AND
%token OR
%token FOR
%token IN
%token SWITCH
%token CASE
%token BREAK
%token DEFAULT
%token WHILE
%token PLUS
%token MINUS
%token MUL
%token DIV
%token LT
%token LE
%token GE
%token GT
%token EQ
%token NE
%token DEF
%token ENDDEF
%token COLON
%token RANGEOP
%token SEMICOL
%token COMMA
%token ASSIGNOP
%token SQBO
%token SQBC
%token BO
%token BC
%token COMMENTMARK
%token EXIT

%token <num> NUM;
%token <rnum> RNUM;
%token <id> ID;

%left GE LE EQ NE GT LT
%left PLUS MINUS
%left MUL DIV

%type <nodePtr> relationalOp,dataType;
%type <inodePtr> idList;
%type <id> var,op;

%start program
%%
program 		:	moduleDeclarations otherModules EXIT {printf("\nParsing Successful!\n");exit(EXIT_SUCCESS);}
			;
moduleDeclarations	:	moduleDeclaration moduleDeclarations	
			|	
			;
moduleDeclaration	:	DECLARE MODULE ID SEMICOL
			|	
			;
otherModules		:	module otherModules	
			|	
			;
module			:	moduleDef
			;
dataType		:	INTEGER	{$$=stDataType("INTEGER");}
			|	REAL	{$$=stDataType("REAL");}
			| 	BOOLEAN	{$$=stDataType("BOOLEAN");}
			|	ARRAY SQBO range SQBC OF type {$$=stDataType("ARRAY");}	
			;
type			:	INTEGER	
			|	REAL	
			| 	BOOLEAN	
			;
moduleDef		:	START statements END	
			;
statements		:	statement statements	
			|	
			;
statement		:	ioStmt		
			|	simpleStmt	
			|	declareStmt	
			|	conditionalStmt	
			| 	iterativeStmt	
			;
ioStmt			:	GET_VALUE BO ID BC SEMICOL	{getVal($3);} 	
			|	PRINT BO var BC SEMICOL		{printVal($3);}
			;
var			:	ID whichId	{$$=$1;}	
			|	NUM	{sprintf($$,"%d",$1);}
			|	RNUM	{sprintf($$,"%f",$1);}
			;
whichId			:	SQBO ID SQBC	
			|	
			;
simpleStmt		:	assignmentStmt
			|	moduleReusestmt	
			;
assignmentStmt		:	ID whichStmt	{assignN($1,$2);}
			;
whichStmt		:	lvalueIDStmt	{$$=$1;}
			|	lvalueARRStmt	
			;
lvalueIDStmt		:	ASSIGNOP expression SEMICOL {$$=$2;}
			;
lvalueARRStmt		:	SQBO index SQBC ASSIGNOP expression SEMICOL 
			;
index			:	NUM	
			|	ID	
			;
moduleReusestmt		:	optional USE MODULE ID WITH PARAMETERS idList SEMICOL	
			;
optional		:	SQBO idList SQBC ASSIGNOP	
			|
			;
idList			:	idList COMMA ID	{$$=stId($3);}	
			|	ID	{$$=stId($1);}	
			;
expression		:	arithmeticExpr	{$$=$1;}
			|	booleanExpr	{$$=$1;}
			;
arithmeticExpr		:	arithmeticExpr op term	{$$=perfOp($1,$2,$3);}	
			|	term	{$$=$1;}
			;
term			:	term op factor	{$$=perfOp($1,$2,$3);}
			|	factor	{$$=$1;}
			;
factor			:	BO arithmeticExpr BC	{$$=$2;}	
			|	var	{$$=$1;}	
			;
op			:	PLUS	{$$="+";}	
			|	MINUS	{$$="-";}
			|	MUL	{$$="*";}
			|	DIV	{$$="/";}

			;
booleanExpr		:	booleanExpr logicalOp booleanExpr	{$$=perfOp($1,$2,$3);}
			|	arithmeticExpr relationalOp arithmeticExpr	{$$=perfOp($1,$2,$3);}
			|	BO booleanExpr BC	{$$=perfOp($1,$2,$3);}
			;
logicalOp		:	AND	{$$=stTok("AND","&&");}
			|	OR	{$$=stTok("OR","||");}	
			;
relationalOp		:	LT	{$$=stTok("LT","<");}	
			|	LE	{$$=stTok("LT","<=");}
			|	GT	{$$=stTok("LT",">");}
			|	GE	{$$=stTok("LT",">=");}
			|	EQ	{$$=stTok("LT","==");}
			|	NE	{$$=stTok("LT","!=");}
			;
declareStmt		:	DECLARE idList COLON dataType SEMICOL {assignDT($2,$4);}		
			;
conditionalStmt		:	SWITCH BO ID BC START caseStmt default END	
			;
caseStmt		:	CASE value COLON statements BREAK SEMICOL caseStmt	
			;
value			:	NUM	
			|	TRUEV	
			|	FALSEV	
			;
default			:	DEFAULT COLON statements BREAK SEMICOL	
			|	
			;
iterativeStmt		:	FOR BO ID IN range BC START statements END	
			|	WHILE BO booleanExpr BC START statements END	
			;
range			:	NUM RANGEOP NUM	
			;
%%
tokenInfo* stTok(char* tkName, char* tkVal){	
	tokenInfo* Lexer = createnode(&tk);
        strcpy(Lexer->token,tkName);
        strcpy(Lexer->value,tkVal);
	Lexer->line++;
	tk=Lexer;
	return Lexer;
}
tokenInfo* stDataType(char* tkName){
	tokenInfo* Lexer = createnode(&dt);
        strcpy(Lexer->token,tkName);
        strcpy(Lexer->value,tkName);
	Lexer->line++;
	dt=Lexer;
	return Lexer;
}
idInfo* stId(char* idName){
	idInfo* Lexer = createinode(&idh);
        strcpy(Lexer->id,idName);
	Lexer->idn=idline++;
	idh=Lexer;	
	return Lexer;
}
void assignDT(idInfo* ilist,tokenInfo* dtType){
while(ilist !=NULL){
	strcpy(ilist->datatype,dtType->value);
	//printf("datatype assigned to %s: %s\n",ilist->id,ilist->datatype);
	ilist=ilist->nextId;
}
}
char* perfOp(char* op1,char *op,char* op2){
	
}
void getVal(char* iD){
idInfo* tmp = idh;
while(tmp!=NULL){
	//printf("tmp->id=%s tmp->datatype=%s\n",tmp->id,tmp->datatype);
	if(strcmp(tmp->id,iD)==0){
		//printf("Matched!\n");
		break;
	}
	tmp=tmp->nextId;
}
//printf("tmp->id=%s tmp->datatype=%s\n",tmp->id,tmp->datatype);
if(strcmp(tmp->datatype,"INTEGER")==0){
	//printf("Enter integer:");
	int x;
	scanf("%d ",&x);
	sprintf(tmp->value,"%d",x);
}
else if(strcmp(tmp->datatype,"REAL")==0){
	float x;
	scanf("%f ",&x);
	sprintf(tmp->value,"%f",x);
}
else if(strcmp(tmp->datatype,"BOOLEAN")==0){
	char x[30];
	scanf("%s ",x);
	strcpy(tmp->value,x);
}
}
void printVal(char* iD){
idInfo* tmp = idh;
while(tmp!=NULL){
	if(strcmp(tmp->id,iD)==0){
		break;
	}
	tmp=tmp->nextId;
}
printf("%s ",tmp->value);
}
void yyerror(char *s) {
fprintf(stdout, "%s\n", s);
}
int main(void) {
yyparse();
return 0;
}
