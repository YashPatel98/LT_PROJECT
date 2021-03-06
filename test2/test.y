%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "tree.h"
	#include "hashing.c"
	#define NOTHING	struct value temp;temp.usethis="none";
	//#include "lineno.h"
	int yylex();
	void yyerror(const char *s);
	char *id[100];
	char *type[100];
	int currentSymTabSize=0;
	enum ParseTreeNodeType {PROGRAM,MODULEDECLARATIONS,MODULEDECLARATION,OTHERMODULES,MODULE,RET,INPUT_PLIST,OUTPUT_PLIST,DATATYPE,TYPE,MODULEDEF,STATEMENTS,STATEMENT,IOSTMT,VAR,WHICHID,SIMPLESTMT,ASSIGNMENTSTMT,WHICHSTMT,LVALUEIDSTMT,LVALUEARRSTMT,INDEX,MODULEREUSESTMT,OPTIONAL,IDLIST,EXPRESSION,ARITHMETICEXPR,TERM,FACTOR,OP,BOOLEANEXPR,LOGICALOP,RELATIONALOP,DECLARESTMT,CONDITIONALSTMT,CASESTMT,VALUE,DEFAULT,ITERATIVESTMT,RANGE};
	const char* labels[] = {"PROGRAM","MODULEDECLARATIONS","MODULEDECLARATION","OTHERMODULES","MODULE","RET","INPUT_PLIST","OUTPUT_PLIST","DATATYPE","TYPE","MODULEDEF","STATEMENTS","STATEMENT","IOSTMT","VAR","WHICHID","SIMPLESTMT","ASSIGNMENTSTMT","WHICHSTMT","LVALUEIDSTMT","LVALUEARRSTMT","INDEX","MODULEREUSESTMT","OPTIONAL","IDLIST","EXPRESSION","ARITHMETICEXPR","TERM","FACTOR","OP","BOOLEANEXPR","LOGICALOP","RELATIONALOP","DECLARESTMT","CONDITIONALSTMT","CASESTMT","VALUE","DEFAULT","ITERATIVESTMT","RANGE"};

%}
%union 	{
	int iVal;
	float fVal;
	char *sVal;
	BINARY_TREE tVal;
}
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
%token TRUE_
%token FALSE_
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
%token DOLLAR

%token ID NUM RNUM

%type <sVal> ID
%type <iVal> NUM
%type <fVal> RNUM
 
%type <tVal> program /*moduleDeclarations moduleDeclaration otherModules module ret input_plist output_plist*/ dataType type moduleDef statements statement ioStmt var whichId simpleStmt assignmentStmt whichStmt lvalueIDStmt lvalueARRStmt index moduleReusestmt optional idList expression arithmeticExpr term factor op booleanExpr logicalOp relationalOp declareStmt conditionalStmt caseStmt value default iterativeStmt range
%start program
%%
/*program 		:	moduleDeclarations otherModules DOLLAR	{BINARY_TREE ParseTree;
		struct value temp;
		temp.usethis="none";
										ParseTree = create_node(temp,PROGRAM,$1,$2,NULL,NULL);
PrintTree(ParseTree);										printf("\nParsing Successful...!\n");}
			;
moduleDeclarations	:	moduleDeclaration moduleDeclarations	{NOTHING $$ = create_node(temp,MODULEDECLARATIONS,$1,$2,NULL,NULL);
									}
			|	{NOTHING
					$$ = create_node(temp,MODULEDECLARATIONS,NULL,NULL,NULL,NULL);
				}
			;
moduleDeclaration	:	DECLARE MODULE ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} SEMICOL	{NOTHING
									$$ = create_node(temp,MODULEDECLARATION,NULL,NULL,NULL,NULL);
								}
			|	{NOTHING
					$$ = create_node(temp,MODULEDECLARATION,NULL,NULL,NULL,NULL);
				}
			;
otherModules		:	module otherModules	{NOTHING
								$$ = create_node(temp,OTHERMODULES,$1,$2,NULL,NULL);
							}
			|	{NOTHING
					$$ = create_node(temp,OTHERMODULES,NULL,NULL,NULL,NULL);
				}
			;
module			:	DEF MODULE ID {struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} ENDDEF TAKES INPUT SQBO input_plist SQBC SEMICOL ret moduleDef	{NOTHING
															$$ = create_node(temp,MODULE,$9,$12,$13,NULL);
														}
			|	
				moduleDef	{NOTHING
							$$ = create_node(temp,MODULE,$1,NULL,NULL,NULL);
						}
			;

ret			:	RETURNS SQBO output_plist SQBC SEMICOL	{NOTHING
										$$ = create_node(temp,RET,$3,NULL,NULL,NULL);
									}
			|	{NOTHING
					$$ = create_node(temp,RET,NULL,NULL,NULL,NULL);
				}
			;
input_plist		:	input_plist COMMA ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} COLON dataType	{NOTHING
										$$ = create_node(temp,MODULEDEF,$1,$6,NULL,NULL);
									}
			|	ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} COLON dataType	{NOTHING
								$$ = create_node(temp,INPUT_PLIST,$4,NULL,NULL,NULL);
							}
			;
output_plist		:	output_plist COMMA ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} COLON type	{NOTHING
								$$ = create_node(temp,OUTPUT_PLIST,$1,$6,NULL,NULL);
									}
			|	ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} COLON type	{NOTHING
							$$ = create_node(temp,OUTPUT_PLIST,$4,NULL,NULL,NULL);
						}
			;*/
program 		:	moduleDef DOLLAR	{BINARY_TREE ParseTree;
		struct value temp;
		temp.usethis="none";
										ParseTree = create_node(temp,PROGRAM,$1,NULL,NULL,NULL);
PrintTree(ParseTree);										printf("\nParsing Successful...!\n");}

dataType		:	INTEGER	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "datatype";
						$$ = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
			|	REAL	{	struct value temp;
						temp.v.s = "real";
						temp.usethis = "datatype";
						$$ = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
			| 	BOOLEAN	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "datatype";
						$$ = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
			|	ARRAY SQBO range SQBC OF type	{	struct value temp;
									temp.v.s = "array";
									temp.usethis = "datatype";
									$$ = create_node(temp,DATATYPE,$3,$6,NULL,NULL);
								}
			;
type			:	INTEGER	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "type";
						$$ = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
			|	REAL	{	struct value temp;
						temp.v.s = "real";
						temp.usethis = "type";
						$$ = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
			| 	BOOLEAN	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "type";
						$$ = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
			;
moduleDef		:	START statements END	{NOTHING
								$$ = create_node(temp,MODULEDEF,$2,NULL,NULL,NULL);
							}
			;
statements		:	statement statements	{NOTHING
								$$ = create_node(temp,STATEMENTS,$1,$2,NULL,NULL);
							}
			|	{NOTHING
					$$ = create_node(temp,STATEMENTS,NULL,NULL,NULL,NULL);
				}
			;
statement		:	ioStmt	{NOTHING
						$$ = create_node(temp,STATEMENT,$1,NULL,NULL,NULL);
					}
			|	simpleStmt	{NOTHING
							$$ = create_node(temp,STATEMENT,$1,NULL,NULL,NULL);
						}
			|	declareStmt	{NOTHING
							$$ = create_node(temp,STATEMENT,$1,NULL,NULL,NULL);
						}
			|	conditionalStmt	{NOTHING
							$$ = create_node(temp,STATEMENT,$1,NULL,NULL,NULL);
						}
			| 	iterativeStmt	{NOTHING
							$$ = create_node(temp,STATEMENT,$1,NULL,NULL,NULL);
						}
			;
ioStmt			:	GET_VALUE BO ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} BC SEMICOL	{NOTHING
									$$ = create_node(temp,IOSTMT,NULL,NULL,NULL,NULL);
								}
			|	PRINT BO var BC SEMICOL	{NOTHING
								$$ = create_node(temp,IOSTMT,$3,NULL,NULL,NULL);
							}
			;
var			:	ID {struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}whichId	{NOTHING $$ = create_node(temp,VAR,NULL,NULL,NULL,NULL);}
			|	NUM	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						$$ = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}	
			|	RNUM	{	struct value temp;
						temp.v.f = yylval.fVal;
						temp.usethis = "rnum";
						$$ = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}
			;
whichId			:	SQBO ID SQBC	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							$$ = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
			|			{NOTHING
							$$ = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
			;
simpleStmt		:	assignmentStmt	{NOTHING
							$$ = create_node(temp,SIMPLESTMT,$1,NULL,NULL,NULL);
						}
			|	moduleReusestmt	{NOTHING
							$$ = create_node(temp,SIMPLESTMT,$1,NULL,NULL,NULL);
						}
			;
assignmentStmt		:	ID {struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} whichStmt	{NOTHING
							$$ = create_node(temp,ASSIGNMENTSTMT,$2,NULL,NULL,NULL);
						}
			;
whichStmt		:	lvalueIDStmt	{NOTHING
							$$ = create_node(temp,WHICHSTMT,$1,NULL,NULL,NULL);
						}
			|	lvalueARRStmt	{NOTHING
							$$ = create_node(temp,WHICHSTMT,$1,NULL,NULL,NULL);
						}
			;
lvalueIDStmt		:	ASSIGNOP expression SEMICOL	{NOTHING
									$$ = create_node(temp,LVALUEIDSTMT,$2,NULL,NULL,NULL);
								}
			;
lvalueARRStmt		:	SQBO index SQBC ASSIGNOP expression SEMICOL	{NOTHING
											$$ = create_node(temp,LVALUEARRSTMT,$2,NULL,NULL,NULL);
										}
			;
index			:	NUM	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						$$ = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
			|	ID	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						$$ = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
			;
moduleReusestmt		:	optional USE MODULE ID {struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} WITH PARAMETERS idList SEMICOL	{NOTHING
	$$ = create_node(temp,MODULEREUSESTMT,$1,$8,NULL,NULL);
}
			;
optional		:	SQBO idList SQBC ASSIGNOP	{NOTHING
									$$ = create_node(temp,OPTIONAL,$2,NULL,NULL,NULL);
								}
			|	{NOTHING
					$$ = create_node(temp,OPTIONAL,NULL,NULL,NULL,NULL);
				}
			;
idList			:	idList COMMA ID	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							$$ = create_node(temp,IDLIST,$1,NULL,NULL,NULL);
						}
			|	ID	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						$$ = create_node(temp,IDLIST,NULL,NULL,NULL,NULL);
					}
			;
expression		:	arithmeticExpr	{NOTHING
							$$ = create_node(temp,EXPRESSION,$1,NULL,NULL,NULL);
						}
			|	booleanExpr	{NOTHING
							$$ = create_node(temp,EXPRESSION,$1,NULL,NULL,NULL);
						}
			;
arithmeticExpr		:	arithmeticExpr op term	{NOTHING
								$$ = create_node(temp,ARITHMETICEXPR,$1,$2,$3,NULL);
							}
			|	term	{NOTHING
								$$ = create_node(temp,ARITHMETICEXPR,$1,NULL,NULL,NULL);
					}
			;
term			:	term op factor	{NOTHING
							$$ = create_node(temp,TERM,$1,$2,$3,NULL);
						}
			|	factor	{NOTHING
						$$ = create_node(temp,TERM,$1,NULL,NULL,NULL);
					}
			;
factor			:	BO arithmeticExpr BC	{NOTHING
								$$ = create_node(temp,FACTOR,$2,NULL,NULL,NULL);
							}
			|	var	{NOTHING
						$$ = create_node(temp,FACTOR,$1,NULL,NULL,NULL);
					}
			;
op			:	PLUS	{	struct value temp;
						temp.v.s="+";
						temp.usethis = "op";
						$$ = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
			|	MINUS	{	struct value temp;
						temp.v.s="-";
						temp.usethis = "op";
						$$ = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
			|	MUL	{	struct value temp;
						temp.v.s="*";
						temp.usethis = "op";
						$$ = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
			|	DIV	{	struct value temp;
						temp.v.s="/";
						temp.usethis = "op";
						$$ = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
			;
booleanExpr		:	booleanExpr logicalOp booleanExpr	{NOTHING
										$$ = create_node(temp,BOOLEANEXPR,$1,$2,$3,NULL);
									}
			|	arithmeticExpr relationalOp arithmeticExpr	{NOTHING
											$$ = create_node(temp,BOOLEANEXPR,$1,$2,$3,NULL);
										}
			|	BO booleanExpr BC	{NOTHING
								$$ = create_node(temp,BOOLEANEXPR,$2,NULL,NULL,NULL);
							}
			;
			;
logicalOp		:	AND	{	struct value temp;
						temp.v.s="&&";
						temp.usethis = "op";
						$$ = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
			|	OR	{	struct value temp;
						temp.v.s="||";
						temp.usethis = "op";
						$$ = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
			;
relationalOp		:	LT	{	struct value temp;
						temp.v.s="<";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			|	LE	{	struct value temp;
						temp.v.s="<=";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			|	GT	{	struct value temp;
						temp.v.s=">";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			|	GE	{	struct value temp;
						temp.v.s=">=";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			|	EQ	{	struct value temp;
						temp.v.s="==";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			|	NE	{	struct value temp;
						temp.v.s="!=";
						temp.usethis = "op";
						$$ = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
			;
declareStmt		:	DECLARE idList COLON dataType SEMICOL	{NOTHING
										$$ = create_node(temp,DECLARESTMT,$2,$4,NULL,NULL);	int i,j,ti=0,ii=0;
		for(i=0;i<100;i++) {
			id[i] = (char *)malloc(IDLENGTH*sizeof(char));
			strcpy(id[i],"NIL");
			type[i] = (char *)malloc(10*sizeof(char));
			strcpy(type[i],"NIL");
		}
		ti=find_usage($4,type,ti,"datatype");
		ii=find_usage($2,id,ii,"identifier");
		for(i=0;i<ii;i++) {
			for(j=1;j<ti;j++) {
				if(strcmp(type[j],"NIL")!=0) {
					strcat(type[0]," ");
					strcat(type[0],type[j]);
				}
			}
			hash_insert(id[i],type[0]);
		}
									}
			;
conditionalStmt		:	SWITCH BO ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} BC START caseStmt default END	{NOTHING	
																			$$ = create_node(temp,CONDITIONALSTMT,$7,$8,NULL,NULL);
																		}
			;
caseStmt		:	CASE value COLON statements BREAK SEMICOL caseStmt	{NOTHING
												$$ = create_node(temp,CASESTMT,$2,$4,$7,NULL);
											}
			|	{NOTHING
					$$ = create_node(temp,CASESTMT,NULL,NULL,NULL,NULL);
				}
			;
value			:	NUM	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						$$ = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
			|	TRUE_	{	struct value temp;
						temp.v.s = "true";
						temp.usethis = "bool";
						$$ = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
			|	FALSE_	{	struct value temp;
						temp.v.s = "false";
						temp.usethis = "bool";
						$$ = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
			;
default			:	DEFAULT COLON statements BREAK SEMICOL 	{NOTHING
										$$ = create_node(temp,DEFAULT,$3,NULL,NULL,NULL);
									}
			|	{NOTHING
					$$ = create_node(temp,DEFAULT,NULL,NULL,NULL,NULL);
				}
			;
iterativeStmt		:	FOR BO ID{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";} IN range BC START statements END	{NOTHING
																			$$ = create_node(temp,ITERATIVESTMT,$6,$9,NULL,NULL);
																		}
			|	WHILE BO booleanExpr BC START statements END	{NOTHING
											$$ = create_node(temp,ITERATIVESTMT,$3,$6,NULL,NULL);
										}
			;
range			:	NUM {struct value temp;temp.v.i = yylval.iVal;temp.usethis = "num";} RANGEOP NUM {struct value temp;temp.v.i = yylval.iVal;temp.usethis = "num";}
			;
%%
#include <stdio.h>
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
BINARY_TREE create_node(struct value val,int case_identifier,BINARY_TREE p1,BINARY_TREE p2,BINARY_TREE p3,BINARY_TREE p4) {
	BINARY_TREE t;
	t= (BINARY_TREE)malloc(sizeof(TREE_NODE));
	t->val = val;
	t->nodeIdentifier = case_identifier;
	t->first = p1;
	t->second = p2;
	t->third = p3;
	t->fourth = p4;
	return (t);
}
void PrintTree(BINARY_TREE t) {
	if(t==NULL)
		return; 
	if(strcmp(t->val.usethis,"string")==0)
		printf("Value: %s ",t->val.v.s);
	if(strcmp(t->val.usethis,"identifier")==0)
		printf("Value: %s ",t->val.v.s);
	else if(strcmp(t->val.usethis,"rnum")==0)
		printf("Value: %f ",t->val.v.f);
	else if(strcmp(t->val.usethis,"num")==0)
		printf("Value: %d ",t->val.v.i);
	else if(strcmp(t->val.usethis,"op")==0)
		printf("Value: %d ",t->val.v.s);
	else if(strcmp(t->val.usethis,"bool")==0)
		printf("Value: %d ",t->val.v.s);
	else if(strcmp(t->val.usethis,"type")==0)
		printf("Value: %d ",t->val.v.s);
	else 
		printf("Value: ");

	printf("Label: %s\n",labels[(t->nodeIdentifier)]);
	if(t->first!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->first->nodeIdentifier]);
	if(t->fourth!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->fourth->nodeIdentifier]);
	if(t->third!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->third->nodeIdentifier]);
	if(t->second!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->second->nodeIdentifier]);
	PrintTree(t->first);
	PrintTree(t->second);
	PrintTree(t->third);
	PrintTree(t->fourth);
}
int find_usage(BINARY_TREE p,char *type[100],int i,char *u) {
if(p==NULL)
	return i;
if(strcmp(p->val.usethis,u)==0) {
	strcpy(type[i],p->val.v.s);
	i++;
}
i=find_usage(p->first,type,i,u);
i=find_usage(p->second,type,i,u);
i=find_usage(p->third,type,i,u);
i=find_usage(p->fourth,type,i,u);
return i;
}

