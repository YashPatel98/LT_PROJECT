/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ylang.y"
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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 35 "ylang.y"
typedef union { int num; float rnum; char *id; tokenInfo* nodePtr; idInfo* inodePtr; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 63 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define REAL 258
#define BOOLEAN 259
#define OF 260
#define ARRAY 261
#define START 262
#define END 263
#define DECLARE 264
#define MODULE 265
#define PROGRAM 266
#define GET_VALUE 267
#define PRINT 268
#define USE 269
#define WITH 270
#define PARAMETERS 271
#define TRUEV 272
#define FALSEV 273
#define TAKES 274
#define INPUT 275
#define RETURNS 276
#define AND 277
#define OR 278
#define FOR 279
#define IN 280
#define SWITCH 281
#define CASE 282
#define BREAK 283
#define DEFAULT 284
#define WHILE 285
#define PLUS 286
#define MINUS 287
#define MUL 288
#define DIV 289
#define LT 290
#define LE 291
#define GE 292
#define GT 293
#define EQ 294
#define NE 295
#define DEF 296
#define ENDDEF 297
#define COLON 298
#define RANGEOP 299
#define SEMICOL 300
#define COMMA 301
#define ASSIGNOP 302
#define SQBO 303
#define SQBC 304
#define BO 305
#define BC 306
#define COMMENTMARK 307
#define EXIT 308
#define NUM 309
#define RNUM 310
#define ID 311
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    6,    6,    8,    8,    7,    7,    9,    3,    3,
    3,    3,   12,   12,   12,   10,   13,   13,   14,   14,
   14,   14,   14,   15,   15,    5,    5,    5,   20,   20,
   16,   16,   21,   23,   23,   24,   25,   27,   27,   22,
   28,   28,    4,    4,   26,   26,   29,   29,   31,   31,
   32,   32,    1,    1,    1,    1,   30,   33,   33,   30,
   30,    2,    2,    2,    2,    2,    2,   17,   18,   34,
   36,   36,   36,   35,   35,   19,   19,   11,
};
static const YYINT yylen[] = {                            2,
    3,    2,    0,    4,    0,    2,    0,    1,    1,    1,
    1,    6,    1,    1,    1,    3,    2,    0,    1,    1,
    1,    1,    1,    5,    5,    2,    1,    1,    3,    0,
    1,    1,    2,    1,    1,    3,    6,    1,    1,    8,
    4,    0,    3,    1,    1,    1,    3,    1,    3,    1,
    3,    1,    1,    1,    1,    1,    3,    1,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    5,    8,    7,
    1,    1,    1,    5,    0,    9,    7,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    8,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   19,   20,   21,   22,   23,   31,   32,    0,    1,
    6,    4,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   33,   34,   35,   16,   17,    0,    0,    0,
    0,   27,   28,    0,    0,    0,    0,    0,   52,    0,
    0,    0,   50,    0,    0,    0,    0,   38,   39,    0,
    0,    9,   10,   11,    0,    0,   43,    0,    0,   26,
    0,    0,    0,    0,    0,   53,   54,   55,   56,   62,
   63,   65,   64,   66,   67,    0,    0,   58,   59,    0,
    0,    0,   41,   36,    0,    0,    0,   68,   24,    0,
   25,    0,    0,    0,   51,   61,    0,    0,    0,    0,
    0,   49,    0,    0,    0,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   78,    0,   72,   73,   71,
    0,    0,    0,   77,   37,    0,    0,    0,    0,    0,
   69,   40,   13,   14,   15,   12,   76,    0,    0,    0,
    0,    0,   74,   70,
};
static const YYINT yydgoto[] = {                          2,
   96,   97,   76,   34,   59,    3,    7,    4,    8,    9,
  113,  156,   20,   21,   22,   23,   24,   25,   26,   80,
   27,   28,   43,   44,   45,   65,   70,   29,   60,   67,
   62,   63,  101,  130,  143,  141,
};
static const YYINT yysindex[] = {                      -248,
 -241,    0, -242, -248, -282, -258, -259, -242,    0,    0,
 -223, -217, -253, -160, -159, -153, -151, -217, -239, -108,
 -258,    0,    0,    0,    0,    0,    0,    0, -113,    0,
    0,    0,    0, -251, -154, -190, -152, -150, -243, -157,
 -243, -158,    0,    0,    0,    0,    0, -107, -246, -149,
 -143,    0,    0, -139, -141, -120, -140, -243,    0, -156,
 -260, -146,    0, -135, -132, -156, -191,    0,    0, -134,
 -142,    0,    0,    0, -131, -129,    0, -127, -137,    0,
 -125, -133,  -85, -181, -247,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -187, -187,    0,    0,  -84,
 -243, -187,    0,    0, -123,  -90, -133,    0,    0, -122,
    0, -118, -121,  -99,    0,    0, -187, -146, -146, -258,
 -191,    0, -243,  -87, -117,    0, -119,  -76, -265,  -96,
 -206,  -74, -106, -217,  -69,    0, -258,    0,    0,    0,
 -105, -103,  -71,    0,    0, -174, -109,  -67, -258, -258,
    0,    0,    0,    0,    0,    0,    0,  -86,  -83, -102,
 -101,  -99,    0,    0,
};
static const YYINT yyrindex[] = {                      -257,
    0,    0, -104, -257,    0, -167,    0, -104,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -168,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -252,    0,    0,    0,    0,    0,    0,
    0, -221,    0,    0,    0,  -98,  -97,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -202, -245, -167,
 -203,    0,    0,    0,    0,    0,    0,    0,    0,  -62,
    0,    0,    0,    0,    0,    0, -167,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -255, -255,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -58,    0,    0,  -17,  169,  202,  199,    0,    0,    0,
  101,    0,  -21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,    0,    0,  -39,  -36,
  114,  109,    0,   50,    0,    0,
};
#define YYTABLESIZE 212
static const YYINT yytable[] = {                         47,
   40,   66,   61,  102,    3,   12,  138,  139,   13,   14,
   72,   73,   74,   42,   75,    1,   98,   99,   84,    6,
   15,   85,   16,    5,   30,   30,   17,   18,   11,   98,
   99,   60,   60,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,  140,   18,  100,   49,   30,   30,   50,
    3,   35,   19,   30,   60,   48,   48,  119,  116,  102,
   60,   58,   41,   42,  121,   52,   53,   54,   48,   48,
   48,   48,   48,   48,   47,   47,   32,  131,   48,   86,
   87,   88,   89,   66,   48,   98,   99,   47,   47,   47,
   47,   47,   47,   33,   18,   18,   57,   47,  132,  115,
   42,   42,   57,   47,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   18,  148,  146,  117,   52,   53,
   54,   52,   53,   54,  115,  152,   50,  158,  159,   86,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   86,
   87,   88,   89,   50,   36,   37,   64,  153,  154,  155,
   68,   38,   69,   39,   46,   48,   51,   71,   56,   82,
   57,   77,   78,   79,   81,   83,  103,  104,  106,  105,
  108,  107,  109,  110,  111,  112,  114,  120,  123,  124,
  127,  126,  129,  134,  128,  137,  135,  142,  144,  136,
  147,  151,  149,  145,  150,  157,  160,  162,  163,  161,
   75,   45,   46,    7,   55,   10,   31,  125,  133,  118,
  122,  164,
};
static const YYINT yycheck[] = {                         21,
   18,   41,   39,   62,  262,  264,  272,  273,  267,  268,
  257,  258,  259,  269,  261,  264,  277,  278,   58,  262,
  279,   58,  281,  265,  277,  278,  285,  283,  311,  277,
  278,  277,  278,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  309,  303,  306,  298,  300,  308,  301,
  308,  305,  311,  306,  300,  277,  278,   97,  306,  118,
  306,  305,  302,  303,  101,  309,  310,  311,  290,  291,
  292,  293,  294,  295,  277,  278,  300,  117,  300,  286,
  287,  288,  289,  123,  306,  277,  278,  290,  291,  292,
  293,  294,  295,  311,  263,  263,  300,  300,  120,  306,
  269,  269,  306,  306,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  295,  283,  137,  134,  305,  309,  310,
  311,  309,  310,  311,  306,  300,  301,  149,  150,  286,
  287,  288,  289,  290,  291,  292,  293,  294,  295,  286,
  287,  288,  289,  301,  305,  305,  304,  257,  258,  259,
  309,  305,  311,  305,  263,  269,  311,  265,  311,  280,
  311,  311,  306,  303,  306,  306,  302,  300,  311,  304,
  300,  303,  300,  311,  300,  309,  262,  262,  302,  270,
  299,  304,  282,  271,  306,  262,  304,  284,  263,  309,
  260,  263,  298,  300,  298,  263,  283,  300,  300,  283,
  263,  300,  300,  308,   36,    4,    8,  107,  123,   96,
  102,  162,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#define YYUNDFTOKEN 350
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","REAL","BOOLEAN","OF",
"ARRAY","START","END","DECLARE","MODULE","PROGRAM","GET_VALUE","PRINT","USE",
"WITH","PARAMETERS","TRUEV","FALSEV","TAKES","INPUT","RETURNS","AND","OR","FOR",
"IN","SWITCH","CASE","BREAK","DEFAULT","WHILE","PLUS","MINUS","MUL","DIV","LT",
"LE","GE","GT","EQ","NE","DEF","ENDDEF","COLON","RANGEOP","SEMICOL","COMMA",
"ASSIGNOP","SQBO","SQBC","BO","BC","COMMENTMARK","EXIT","NUM","RNUM","ID",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : moduleDeclarations otherModules EXIT",
"moduleDeclarations : moduleDeclaration moduleDeclarations",
"moduleDeclarations :",
"moduleDeclaration : DECLARE MODULE ID SEMICOL",
"moduleDeclaration :",
"otherModules : module otherModules",
"otherModules :",
"module : moduleDef",
"dataType : INTEGER",
"dataType : REAL",
"dataType : BOOLEAN",
"dataType : ARRAY SQBO range SQBC OF type",
"type : INTEGER",
"type : REAL",
"type : BOOLEAN",
"moduleDef : START statements END",
"statements : statement statements",
"statements :",
"statement : ioStmt",
"statement : simpleStmt",
"statement : declareStmt",
"statement : conditionalStmt",
"statement : iterativeStmt",
"ioStmt : GET_VALUE BO ID BC SEMICOL",
"ioStmt : PRINT BO var BC SEMICOL",
"var : ID whichId",
"var : NUM",
"var : RNUM",
"whichId : SQBO ID SQBC",
"whichId :",
"simpleStmt : assignmentStmt",
"simpleStmt : moduleReusestmt",
"assignmentStmt : ID whichStmt",
"whichStmt : lvalueIDStmt",
"whichStmt : lvalueARRStmt",
"lvalueIDStmt : ASSIGNOP expression SEMICOL",
"lvalueARRStmt : SQBO index SQBC ASSIGNOP expression SEMICOL",
"index : NUM",
"index : ID",
"moduleReusestmt : optional USE MODULE ID WITH PARAMETERS idList SEMICOL",
"optional : SQBO idList SQBC ASSIGNOP",
"optional :",
"idList : idList COMMA ID",
"idList : ID",
"expression : arithmeticExpr",
"expression : booleanExpr",
"arithmeticExpr : arithmeticExpr op term",
"arithmeticExpr : term",
"term : term op factor",
"term : factor",
"factor : BO arithmeticExpr BC",
"factor : var",
"op : PLUS",
"op : MINUS",
"op : MUL",
"op : DIV",
"booleanExpr : booleanExpr logicalOp booleanExpr",
"logicalOp : AND",
"logicalOp : OR",
"booleanExpr : arithmeticExpr relationalOp arithmeticExpr",
"booleanExpr : BO booleanExpr BC",
"relationalOp : LT",
"relationalOp : LE",
"relationalOp : GT",
"relationalOp : GE",
"relationalOp : EQ",
"relationalOp : NE",
"declareStmt : DECLARE idList COLON dataType SEMICOL",
"conditionalStmt : SWITCH BO ID BC START caseStmt default END",
"caseStmt : CASE value COLON statements BREAK SEMICOL caseStmt",
"value : NUM",
"value : TRUEV",
"value : FALSEV",
"default : DEFAULT COLON statements BREAK SEMICOL",
"default :",
"iterativeStmt : FOR BO ID IN range BC START statements END",
"iterativeStmt : WHILE BO booleanExpr BC START statements END",
"range : NUM RANGEOP NUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 221 "ylang.y"
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
	printf("datatype assigned to %s: %s\n",ilist->id,ilist->datatype);
	ilist=ilist->nextId;
}
}
void getVal(char* iD){
idInfo* tmp = idh;
while(tmp!=NULL){
	printf("tmp->id=%s tmp->datatype=%s\n",tmp->id,tmp->datatype);
	if(strcmp(tmp->id,iD)==0){
		printf("Matched!\n");
		break;
	}
	tmp=tmp->nextId;
}
printf("tmp->id=%s tmp->datatype=%s\n",tmp->id,tmp->datatype);
if(strcmp(tmp->datatype,"INTEGER")==0){
	printf("Enter integer:");
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
#line 509 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 103 "ylang.y"
	{printf("\nParsing Successful!\n");exit(EXIT_SUCCESS);}
break;
case 9:
#line 116 "ylang.y"
	{yyval.nodePtr=stDataType("INTEGER");}
break;
case 10:
#line 117 "ylang.y"
	{yyval.nodePtr=stDataType("REAL");}
break;
case 11:
#line 118 "ylang.y"
	{yyval.nodePtr=stDataType("BOOLEAN");}
break;
case 12:
#line 119 "ylang.y"
	{yyval.nodePtr=stDataType("ARRAY");}
break;
case 24:
#line 136 "ylang.y"
	{printf("getvalue:");getVal(yystack.l_mark[-2].id);}
break;
case 25:
#line 137 "ylang.y"
	{printVal(yystack.l_mark[-2].id);}
break;
case 26:
#line 139 "ylang.y"
	{yyval.id=yystack.l_mark[-1].id;}
break;
case 27:
#line 140 "ylang.y"
	{sprintf(yyval.id,"%d",yystack.l_mark[0].num);}
break;
case 28:
#line 141 "ylang.y"
	{sprintf(yyval.id,"%f",yystack.l_mark[0].rnum);}
break;
case 43:
#line 166 "ylang.y"
	{yyval.inodePtr=stId(yystack.l_mark[0].id);}
break;
case 44:
#line 167 "ylang.y"
	{yyval.inodePtr=stId(yystack.l_mark[0].id);}
break;
case 53:
#line 181 "ylang.y"
	{yyval.nodePtr=stTok("PLUS","+");}
break;
case 54:
#line 182 "ylang.y"
	{yyval.nodePtr=stTok("MINUS","-");}
break;
case 55:
#line 183 "ylang.y"
	{yyval.nodePtr=stTok("DIV","*");}
break;
case 56:
#line 184 "ylang.y"
	{yyval.nodePtr=stTok("MUL","/");}
break;
case 62:
#line 195 "ylang.y"
	{yyval.nodePtr=stTok("LT","<");}
break;
case 63:
#line 196 "ylang.y"
	{yyval.nodePtr=stTok("LT","<=");}
break;
case 64:
#line 197 "ylang.y"
	{yyval.nodePtr=stTok("LT",">");}
break;
case 65:
#line 198 "ylang.y"
	{yyval.nodePtr=stTok("LT",">=");}
break;
case 66:
#line 199 "ylang.y"
	{yyval.nodePtr=stTok("LT","==");}
break;
case 67:
#line 200 "ylang.y"
	{yyval.nodePtr=stTok("LT","!=");}
break;
case 68:
#line 202 "ylang.y"
	{assignDT(yystack.l_mark[-3].inodePtr,yystack.l_mark[-1].nodePtr);}
break;
#line 800 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
