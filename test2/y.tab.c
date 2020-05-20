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

#line 1 "test.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "tree.h"
	#include "hashing.c"
	#define NOTHING	struct value temp;temp.usethis="none";
	/*#include "lineno.h"*/
	int yylex();
	void yyerror(const char *s);
	char *id[100];
	char *type[100];
	int currentSymTabSize=0;
	enum ParseTreeNodeType {PROGRAM,MODULEDECLARATIONS,MODULEDECLARATION,OTHERMODULES,MODULE,RET,INPUT_PLIST,OUTPUT_PLIST,DATATYPE,TYPE,MODULEDEF,STATEMENTS,STATEMENT,IOSTMT,VAR,WHICHID,SIMPLESTMT,ASSIGNMENTSTMT,WHICHSTMT,LVALUEIDSTMT,LVALUEARRSTMT,INDEX,MODULEREUSESTMT,OPTIONAL,IDLIST,EXPRESSION,ARITHMETICEXPR,TERM,FACTOR,OP,BOOLEANEXPR,LOGICALOP,RELATIONALOP,DECLARESTMT,CONDITIONALSTMT,CASESTMT,VALUE,DEFAULT,ITERATIVESTMT,RANGE};
	const char* labels[] = {"PROGRAM","MODULEDECLARATIONS","MODULEDECLARATION","OTHERMODULES","MODULE","RET","INPUT_PLIST","OUTPUT_PLIST","DATATYPE","TYPE","MODULEDEF","STATEMENTS","STATEMENT","IOSTMT","VAR","WHICHID","SIMPLESTMT","ASSIGNMENTSTMT","WHICHSTMT","LVALUEIDSTMT","LVALUEARRSTMT","INDEX","MODULEREUSESTMT","OPTIONAL","IDLIST","EXPRESSION","ARITHMETICEXPR","TERM","FACTOR","OP","BOOLEANEXPR","LOGICALOP","RELATIONALOP","DECLARESTMT","CONDITIONALSTMT","CASESTMT","VALUE","DEFAULT","ITERATIVESTMT","RANGE"};

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 19 "test.y"
typedef union 	{
	int iVal;
	float fVal;
	char *sVal;
	BINARY_TREE tVal;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

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
#define TRUE_ 272
#define FALSE_ 273
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
#define DOLLAR 307
#define ID 308
#define NUM 309
#define RNUM 310
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    2,    2,    2,    3,    4,
    4,    5,    5,    5,    5,    5,   33,    6,    6,   34,
    7,    7,    7,    8,    8,    9,    9,   35,   10,   11,
   11,   12,   13,   14,   14,   36,   15,   16,   16,   17,
   17,   18,   18,   19,   19,   20,   20,   21,   21,   22,
   22,   22,   22,   23,   23,   23,   24,   24,   25,   25,
   25,   25,   25,   25,   26,   37,   27,   28,   28,   29,
   29,   29,   30,   30,   38,   31,   31,   39,   32,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    1,    6,    1,    1,    1,    3,    2,
    0,    1,    1,    1,    1,    1,    0,    6,    5,    0,
    3,    1,    1,    3,    0,    1,    1,    0,    3,    1,
    1,    3,    6,    1,    1,    0,    9,    4,    0,    3,
    1,    1,    1,    3,    1,    3,    1,    3,    1,    1,
    1,    1,    1,    3,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    5,    0,    9,    7,    0,    1,
    1,    1,    5,    0,    0,   10,    7,    0,    4,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,   12,   13,   26,   27,    0,   14,   15,
   16,    1,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    9,   10,    0,    0,    0,   17,   20,   22,   23,
    0,   75,   66,    0,   49,    0,    0,   47,    0,    0,
    0,    0,   29,   30,   31,    0,    2,    3,    4,    0,
    0,   40,    0,    0,    0,    0,    0,    0,    0,   50,
   51,   52,   53,   59,   60,   62,   61,   63,   64,    0,
    0,    0,   57,   58,    0,    0,   38,    0,    0,    0,
   35,   34,    0,   36,    0,   65,    0,    0,   21,   19,
    0,    0,   48,   56,    0,    0,    0,   46,    0,    0,
   32,    0,    0,   78,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   24,    0,    0,    0,   77,
    0,    0,    0,    0,    0,   71,   72,   70,    0,    0,
    0,   33,    0,   79,    6,    7,    8,    5,    0,    0,
    0,   67,   37,   76,    0,    0,    0,    0,    0,   73,
   68,
};
static const YYINT yydgoto[] = {                          2,
   61,  148,    3,   12,   13,   14,   45,   99,   15,   16,
   53,   54,   55,   93,   17,   18,   24,   88,   46,   47,
   48,   80,   90,   86,   81,   19,   20,  129,  139,  141,
   21,  115,   63,   64,   31,  113,   67,   66,  124,
};
static const YYINT yysindex[] = {                      -244,
 -257,    0, -282, -274, -269, -252, -245, -228, -219, -274,
    0, -163, -257,    0,    0,    0,    0, -167,    0,    0,
    0,    0,    0, -249, -198, -215, -182, -175, -251, -225,
 -178,    0,    0, -133, -176, -174,    0,    0,    0,    0,
 -171,    0,    0, -251,    0, -137, -169,    0, -263, -166,
 -251, -180,    0,    0,    0, -148,    0,    0,    0, -142,
 -138,    0, -143, -139, -135, -114, -136, -147, -261,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -204,
 -204, -204,    0,    0,  -95, -251,    0, -132, -137, -230,
    0,    0, -131,    0, -140,    0, -129, -134,    0,    0,
 -140,  -90,    0,    0, -204, -169, -169,    0, -257, -230,
    0, -127,  -94,    0, -126,    0, -125, -124, -105, -256,
  -83, -251,  -88, -118,  -76,    0,  -77, -267,  -98,    0,
 -113, -274, -121, -150, -257,    0,    0,    0, -109, -108,
  -72,    0, -170,    0,    0,    0,    0,    0,  -71, -257,
 -257,    0,    0,    0,  -89,  -87, -107, -103, -105,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
 -242,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -243,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -203,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -222,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -102, -101,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -179, -265,    0, -242, -262,
    0,    0,    0,    0,    0,    0,    0,    0, -255,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -68,    0,
    0,    0,    0,    0, -242,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -246,
 -246,    0,    0,    0,    0,    0,    0,    0, -255,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  -13,    0,    0,  174,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -9,   79,  -42,  122,
  121,  -44,  -25,    0,    0,    0,    0,   45,    0,    0,
    0,  104,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 205
static const YYINT yytable[] = {                         33,
   30,   68,   82,   49,  136,  137,    4,   69,   89,    5,
    6,   55,   55,   83,   84,   83,   84,    1,   69,   11,
   11,    7,   39,    8,   22,   39,   39,    9,   69,   70,
   71,   72,   73,   23,   55,   25,   11,   54,  107,   11,
   55,  138,   85,   54,  104,   10,   83,   84,   35,  103,
   11,   36,   26,   44,   25,   25,   38,   39,   40,   27,
  110,   82,  120,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   45,   45,   36,   28,   25,   50,   89,
   57,   58,   59,   25,   60,   29,   45,   45,   45,   45,
   45,   45,   38,   39,   40,  121,   45,   44,   44,   32,
  105,   34,   45,   38,   39,   40,  145,  146,  147,   37,
   44,   44,   44,   44,   44,   44,   70,   71,   72,   73,
   44,  149,  143,   51,   52,   42,   44,   91,   92,  153,
   36,   56,   43,   62,   65,   87,  155,  156,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,  103,   94,
   95,   96,   97,   98,  100,  101,  109,  111,  114,  102,
  116,  119,  112,  117,  122,  123,  128,  125,  126,  130,
  133,  127,  132,  134,  135,  140,  142,  144,  150,  151,
  152,  154,  159,  157,   74,  158,  160,   42,   43,   41,
  131,  106,  108,  161,  118,
};
static const YYINT yycheck[] = {                         13,
   10,   44,   47,   29,  272,  273,  264,  263,   51,  267,
  268,  277,  278,  277,  278,  277,  278,  262,   44,  263,
  263,  279,  269,  281,  307,  269,  269,  285,  284,  286,
  287,  288,  289,  308,  300,  305,  283,  300,   81,  283,
  306,  309,  306,  306,  306,  303,  277,  278,  298,  306,
  308,  301,  305,  305,  277,  278,  308,  309,  310,  305,
   86,  106,  105,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  277,  278,  301,  305,  300,  304,  122,
  257,  258,  259,  306,  261,  305,  290,  291,  292,  293,
  294,  295,  308,  309,  310,  109,  300,  277,  278,  263,
  305,  269,  306,  308,  309,  310,  257,  258,  259,  308,
  290,  291,  292,  293,  294,  295,  286,  287,  288,  289,
  300,  135,  132,  302,  303,  308,  306,  308,  309,  300,
  301,  265,  308,  308,  306,  302,  150,  151,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  306,  308,
  303,  300,  306,  303,  300,  280,  262,  300,  309,  306,
  300,  262,  304,  308,  302,  270,  282,  304,  304,  263,
  299,  306,  271,  260,  262,  284,  300,  309,  298,  298,
  263,  263,  300,  283,  263,  283,  300,  300,  300,   26,
  122,   80,   82,  159,  101,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 310
#define YYUNDFTOKEN 352
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
"WITH","PARAMETERS","TRUE_","FALSE_","TAKES","INPUT","RETURNS","AND","OR","FOR",
"IN","SWITCH","CASE","BREAK","DEFAULT","WHILE","PLUS","MINUS","MUL","DIV","LT",
"LE","GE","GT","EQ","NE","DEF","ENDDEF","COLON","RANGEOP","SEMICOL","COMMA",
"ASSIGNOP","SQBO","SQBC","BO","BC","DOLLAR","ID","NUM","RNUM",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : moduleDef DOLLAR",
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
"$$1 :",
"ioStmt : GET_VALUE BO ID $$1 BC SEMICOL",
"ioStmt : PRINT BO var BC SEMICOL",
"$$2 :",
"var : ID $$2 whichId",
"var : NUM",
"var : RNUM",
"whichId : SQBO ID SQBC",
"whichId :",
"simpleStmt : assignmentStmt",
"simpleStmt : moduleReusestmt",
"$$3 :",
"assignmentStmt : ID $$3 whichStmt",
"whichStmt : lvalueIDStmt",
"whichStmt : lvalueARRStmt",
"lvalueIDStmt : ASSIGNOP expression SEMICOL",
"lvalueARRStmt : SQBO index SQBC ASSIGNOP expression SEMICOL",
"index : NUM",
"index : ID",
"$$4 :",
"moduleReusestmt : optional USE MODULE ID $$4 WITH PARAMETERS idList SEMICOL",
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
"booleanExpr : arithmeticExpr relationalOp arithmeticExpr",
"booleanExpr : BO booleanExpr BC",
"logicalOp : AND",
"logicalOp : OR",
"relationalOp : LT",
"relationalOp : LE",
"relationalOp : GT",
"relationalOp : GE",
"relationalOp : EQ",
"relationalOp : NE",
"declareStmt : DECLARE idList COLON dataType SEMICOL",
"$$5 :",
"conditionalStmt : SWITCH BO ID $$5 BC START caseStmt default END",
"caseStmt : CASE value COLON statements BREAK SEMICOL caseStmt",
"caseStmt :",
"value : NUM",
"value : TRUE_",
"value : FALSE_",
"default : DEFAULT COLON statements BREAK SEMICOL",
"default :",
"$$6 :",
"iterativeStmt : FOR BO ID $$6 IN range BC START statements END",
"iterativeStmt : WHILE BO booleanExpr BC START statements END",
"$$7 :",
"range : NUM $$7 RANGEOP NUM",

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
#line 465 "test.y"

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

#line 482 "y.tab.c"

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
#line 142 "test.y"
	{BINARY_TREE ParseTree;
		struct value temp;
		temp.usethis="none";
										ParseTree = create_node(temp,PROGRAM,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
PrintTree(ParseTree);										printf("\nParsing Successful...!\n");}
break;
case 2:
#line 148 "test.y"
	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 3:
#line 153 "test.y"
	{	struct value temp;
						temp.v.s = "real";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 4:
#line 158 "test.y"
	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 5:
#line 163 "test.y"
	{	struct value temp;
									temp.v.s = "array";
									temp.usethis = "datatype";
									yyval.tVal = create_node(temp,DATATYPE,yystack.l_mark[-3].tVal,yystack.l_mark[0].tVal,NULL,NULL);
								}
break;
case 6:
#line 169 "test.y"
	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 7:
#line 174 "test.y"
	{	struct value temp;
						temp.v.s = "real";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 8:
#line 179 "test.y"
	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 9:
#line 185 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,MODULEDEF,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 10:
#line 189 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,STATEMENTS,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL,NULL);
							}
break;
case 11:
#line 192 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,STATEMENTS,NULL,NULL,NULL,NULL);
				}
break;
case 12:
#line 196 "test.y"
	{NOTHING
						yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 13:
#line 199 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 14:
#line 202 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 15:
#line 205 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 16:
#line 208 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 17:
#line 212 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 18:
#line 212 "test.y"
	{NOTHING
									yyval.tVal = create_node(temp,IOSTMT,NULL,NULL,NULL,NULL);
								}
break;
case 19:
#line 215 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,IOSTMT,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
							}
break;
case 20:
#line 219 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 21:
#line 219 "test.y"
	{NOTHING yyval.tVal = create_node(temp,VAR,NULL,NULL,NULL,NULL);}
break;
case 22:
#line 220 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}
break;
case 23:
#line 225 "test.y"
	{	struct value temp;
						temp.v.f = yylval.fVal;
						temp.usethis = "rnum";
						yyval.tVal = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}
break;
case 24:
#line 231 "test.y"
	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							yyval.tVal = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
break;
case 25:
#line 236 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
break;
case 26:
#line 240 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,SIMPLESTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 27:
#line 243 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,SIMPLESTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 28:
#line 247 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 29:
#line 247 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,ASSIGNMENTSTMT,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
						}
break;
case 30:
#line 251 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,WHICHSTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 31:
#line 254 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,WHICHSTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 32:
#line 258 "test.y"
	{NOTHING
									yyval.tVal = create_node(temp,LVALUEIDSTMT,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
								}
break;
case 33:
#line 262 "test.y"
	{NOTHING
											yyval.tVal = create_node(temp,LVALUEARRSTMT,yystack.l_mark[-4].tVal,NULL,NULL,NULL);
										}
break;
case 34:
#line 266 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
break;
case 35:
#line 271 "test.y"
	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						yyval.tVal = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
break;
case 36:
#line 277 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 37:
#line 277 "test.y"
	{NOTHING
	yyval.tVal = create_node(temp,MODULEREUSESTMT,yystack.l_mark[-8].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
}
break;
case 38:
#line 281 "test.y"
	{NOTHING
									yyval.tVal = create_node(temp,OPTIONAL,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
								}
break;
case 39:
#line 284 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,OPTIONAL,NULL,NULL,NULL,NULL);
				}
break;
case 40:
#line 288 "test.y"
	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							yyval.tVal = create_node(temp,IDLIST,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
						}
break;
case 41:
#line 293 "test.y"
	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						yyval.tVal = create_node(temp,IDLIST,NULL,NULL,NULL,NULL);
					}
break;
case 42:
#line 299 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,EXPRESSION,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 43:
#line 302 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,EXPRESSION,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 44:
#line 306 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,ARITHMETICEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
							}
break;
case 45:
#line 309 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,ARITHMETICEXPR,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 46:
#line 313 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,TERM,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
						}
break;
case 47:
#line 316 "test.y"
	{NOTHING
						yyval.tVal = create_node(temp,TERM,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 48:
#line 320 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,FACTOR,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 49:
#line 323 "test.y"
	{NOTHING
						yyval.tVal = create_node(temp,FACTOR,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 50:
#line 327 "test.y"
	{	struct value temp;
						temp.v.s="+";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 51:
#line 332 "test.y"
	{	struct value temp;
						temp.v.s="-";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 52:
#line 337 "test.y"
	{	struct value temp;
						temp.v.s="*";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 53:
#line 342 "test.y"
	{	struct value temp;
						temp.v.s="/";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 54:
#line 348 "test.y"
	{NOTHING
										yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
									}
break;
case 55:
#line 351 "test.y"
	{NOTHING
											yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
										}
break;
case 56:
#line 354 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 57:
#line 359 "test.y"
	{	struct value temp;
						temp.v.s="&&";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
break;
case 58:
#line 364 "test.y"
	{	struct value temp;
						temp.v.s="||";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
break;
case 59:
#line 370 "test.y"
	{	struct value temp;
						temp.v.s="<";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 60:
#line 375 "test.y"
	{	struct value temp;
						temp.v.s="<=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 61:
#line 380 "test.y"
	{	struct value temp;
						temp.v.s=">";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 62:
#line 385 "test.y"
	{	struct value temp;
						temp.v.s=">=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 63:
#line 390 "test.y"
	{	struct value temp;
						temp.v.s="==";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 64:
#line 395 "test.y"
	{	struct value temp;
						temp.v.s="!=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 65:
#line 401 "test.y"
	{NOTHING
										yyval.tVal = create_node(temp,DECLARESTMT,yystack.l_mark[-3].tVal,yystack.l_mark[-1].tVal,NULL,NULL);	int i,j,ti=0,ii=0;
		for(i=0;i<100;i++) {
			id[i] = (char *)malloc(IDLENGTH*sizeof(char));
			strcpy(id[i],"NIL");
			type[i] = (char *)malloc(10*sizeof(char));
			strcpy(type[i],"NIL");
		}
		ti=find_usage(yystack.l_mark[-1].tVal,type,ti,"datatype");
		ii=find_usage(yystack.l_mark[-3].tVal,id,ii,"identifier");
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
break;
case 66:
#line 422 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 67:
#line 422 "test.y"
	{NOTHING	
																			yyval.tVal = create_node(temp,CONDITIONALSTMT,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
																		}
break;
case 68:
#line 426 "test.y"
	{NOTHING
												yyval.tVal = create_node(temp,CASESTMT,yystack.l_mark[-5].tVal,yystack.l_mark[-3].tVal,yystack.l_mark[0].tVal,NULL);
											}
break;
case 69:
#line 429 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,CASESTMT,NULL,NULL,NULL,NULL);
				}
break;
case 70:
#line 433 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 71:
#line 438 "test.y"
	{	struct value temp;
						temp.v.s = "true";
						temp.usethis = "bool";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 72:
#line 443 "test.y"
	{	struct value temp;
						temp.v.s = "false";
						temp.usethis = "bool";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 73:
#line 449 "test.y"
	{NOTHING
										yyval.tVal = create_node(temp,DEFAULT,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
									}
break;
case 74:
#line 452 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,DEFAULT,NULL,NULL,NULL,NULL);
				}
break;
case 75:
#line 456 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 76:
#line 456 "test.y"
	{NOTHING
																			yyval.tVal = create_node(temp,ITERATIVESTMT,yystack.l_mark[-4].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
																		}
break;
case 77:
#line 459 "test.y"
	{NOTHING
											yyval.tVal = create_node(temp,ITERATIVESTMT,yystack.l_mark[-4].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
										}
break;
case 78:
#line 463 "test.y"
	{struct value temp;temp.v.i = yylval.iVal;temp.usethis = "num";}
break;
case 79:
#line 463 "test.y"
	{struct value temp;temp.v.i = yylval.iVal;temp.usethis = "num";}
break;
#line 1214 "y.tab.c"
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
