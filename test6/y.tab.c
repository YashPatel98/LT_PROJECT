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
	void sPush(char *);
	int sset = 0;
	struct value *valPtr;
	enum ParseTreeNodeType {PROGRAM,MODULEDECLARATIONS,MODULEDECLARATION,OTHERMODULES,MODULE,RET,INPUT_PLIST,OUTPUT_PLIST,DATATYPE,TYPE,MODULEDEF,STATEMENTS,STATEMENT,IOSTMT,VAR,WHICHID,SIMPLESTMT,ASSIGNMENTSTMT,WHICHSTMT,LVALUEIDSTMT,LVALUEARRSTMT,INDEX,MODULEREUSESTMT,OPTIONAL,IDLIST,EXPRESSION,ARITHMETICEXPR,TERM,FACTOR,OP,BOOLEANEXPR,LOGICALOP,RELATIONALOP,DECLARESTMT,CONDITIONALSTMT,CASESTMT,VALUE,DEFAULT,ITERATIVESTMT,RANGE};
	const char* labels[] = {"PROGRAM","MODULEDECLARATIONS","MODULEDECLARATION","OTHERMODULES","MODULE","RET","INPUT_PLIST","OUTPUT_PLIST","DATATYPE","TYPE","MODULEDEF","STATEMENTS","STATEMENT","IOSTMT","VAR","WHICHID","SIMPLESTMT","ASSIGNMENTSTMT","WHICHSTMT","LVALUEIDSTMT","LVALUEARRSTMT","INDEX","MODULEREUSESTMT","OPTIONAL","IDLIST","EXPRESSION","ARITHMETICEXPR","TERM","FACTOR","OP","BOOLEANEXPR","LOGICALOP","RELATIONALOP","DECLARESTMT","CONDITIONALSTMT","CASESTMT","VALUE","DEFAULT","ITERATIVESTMT","RANGE"};

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 22 "test.y"
typedef union 	{
	int iVal;
	float fVal;
	char *sVal;
	struct value sv;
	BINARY_TREE tVal;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 57 "y.tab.c"

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
#define STARTF 264
#define ENDF 265
#define DECLARE 266
#define MODULE 267
#define PROGRAM 268
#define GET_VALUE 269
#define PRINT 270
#define USE 271
#define WITH 272
#define PARAMETERS 273
#define TRUE_ 274
#define FALSE_ 275
#define TAKES 276
#define INPUT 277
#define RETURNS 278
#define AND 279
#define OR 280
#define FOR 281
#define IN 282
#define SWITCH 283
#define CASE 284
#define BREAK 285
#define DEFAULT 286
#define WHILE 287
#define PLUS 288
#define MINUS 289
#define MUL 290
#define DIV 291
#define LT 292
#define LE 293
#define GE 294
#define GT 295
#define EQ 296
#define NE 297
#define DEF 298
#define ENDDEF 299
#define COLON 300
#define RANGEOP 301
#define SEMICOL 302
#define COMMA 303
#define ASSIGNOP 304
#define SQBO 305
#define SQBC 306
#define BO 307
#define BC 308
#define DOLLAR 309
#define ID 310
#define NUM 311
#define RNUM 312
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    2,    2,    2,    3,    4,
    4,    5,    5,    5,    5,    5,   33,    6,    6,   34,
    7,    7,    7,   35,    8,    8,    9,    9,   36,   10,
   11,   11,   12,   13,   14,   14,   37,   15,   16,   16,
   17,   17,   18,   18,   19,   19,   20,   20,   21,   21,
   22,   22,   22,   22,   23,   23,   23,   24,   24,   25,
   25,   25,   25,   25,   25,   26,   38,   27,   28,   28,
   29,   29,   29,   30,   30,   39,   40,   31,   31,   32,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    1,    6,    1,    1,    1,    3,    2,
    0,    1,    1,    1,    1,    1,    0,    6,    5,    0,
    3,    1,    1,    0,    4,    0,    1,    1,    0,    3,
    1,    1,    3,    6,    1,    1,    0,    9,    4,    0,
    3,    1,    1,    1,    3,    1,    3,    1,    3,    1,
    1,    1,    1,    1,    3,    3,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    5,    0,    9,    7,    0,
    1,    1,    1,    5,    0,    0,    0,   11,    7,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,    0,    0,   12,   13,   27,   28,    0,   14,   15,
   16,    1,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    9,   10,    0,    0,    0,   17,   20,   22,   23,
    0,   76,   67,    0,   50,    0,    0,   48,    0,    0,
    0,    0,   30,   31,   32,    0,    2,    3,    4,    0,
    0,   41,    0,    0,    0,    0,    0,    0,    0,   51,
   52,   53,   54,   60,   61,   63,   62,   64,   65,    0,
    0,    0,   58,   59,    0,    0,   39,    0,    0,    0,
   36,   35,    0,   37,    0,   66,    0,    0,   21,   19,
    0,    0,   49,   57,    0,    0,    0,   47,    0,    0,
   33,    0,    0,    0,    0,   18,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,   80,    0,   25,    0,   72,   73,   71,    0,
    0,    0,   34,    0,    6,    7,    8,    5,   77,    0,
    0,   68,   38,    0,    0,    0,   78,    0,    0,    0,
   74,   69,
};
static const YYINT yydgoto[] = {                          2,
   61,  148,    3,   12,   13,   14,   45,   99,   15,   16,
   53,   54,   55,   93,   17,   18,   24,   88,   46,   47,
   48,   80,   90,   86,   81,   19,   20,  129,  140,  142,
   21,  115,   63,   64,  126,   31,  113,   67,   66,  154,
};
static const YYINT yysindex[] = {                      -258,
 -260,    0, -292, -288, -272, -268, -251, -248, -246, -288,
    0, -216, -260,    0,    0,    0,    0, -230,    0,    0,
    0,    0,    0, -257, -247, -147, -245, -232, -204, -254,
 -250,    0,    0, -167,  -99, -225,    0,    0,    0,    0,
 -213,    0,    0, -204,    0, -140, -172,    0, -264, -202,
 -204, -223,    0,    0,    0, -206,    0,    0,    0, -196,
 -177,    0, -163, -159, -141, -113, -138, -161, -255,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -168,
 -168, -168,    0,    0,  -90, -204,    0, -131, -140, -158,
    0,    0, -133,    0, -137,    0, -127, -134,    0,    0,
 -137,  -85,    0,    0, -168, -172, -172,    0, -260, -158,
    0, -126,  -93, -121, -125,    0,    0, -124, -102, -207,
  -80, -204,  -88, -123,  -74, -119,  -75, -263,  -96,    0,
 -111, -288,    0,  -91,    0, -260,    0,    0,    0, -108,
 -107,  -69,    0, -162,    0,    0,    0,    0,    0, -260,
 -260,    0,    0,  -70,  -89,  -87,    0, -105, -103, -102,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -243,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -234,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -203,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -222,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -101, -100,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -182, -266,    0, -243, -276,
    0,    0,    0,    0,    0,    0,    0,    0, -256,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -63,    0,
    0,    0,    0,    0,    0, -231,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -252,
 -252,    0,    0,    0,    0,    0,    0,    0,    0, -256,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  -13,    0,    0,  177,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -8,   82,  -43,  125,
  124,  -42,  -26,    0,    0,    0,    0,   47,    0,    0,
    0,  107,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 208
static const YYINT yytable[] = {                         33,
   68,   30,   49,    1,   82,    4,   70,   89,    5,    6,
  137,  138,   56,   56,   83,   84,   22,   69,   40,   11,
    7,   23,    8,   83,   84,   55,    9,   40,   11,   70,
   11,   55,   11,   11,   25,   56,   40,  107,   26,   40,
   34,   56,   35,   85,   10,   36,   32,  139,   36,   11,
   11,   50,  104,   51,   52,   27,   26,   26,   28,  110,
   29,  120,   37,   82,   42,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   46,   46,   43,   89,   26,
   70,   71,   72,   73,   62,   26,   91,   92,   46,   46,
   46,   46,   46,   46,   65,  121,   45,   45,   46,   56,
  103,   87,   44,   94,   46,   38,   39,   40,   95,   45,
   45,   45,   45,   45,   45,   70,   71,   72,   73,   45,
   83,   84,  149,  144,   96,   45,   70,   71,   72,   73,
   74,   75,   76,   77,   78,   79,  155,  156,  105,  153,
   36,   38,   39,   40,   97,   98,  103,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   57,   58,   59,
  100,   60,   38,   39,   40,  145,  146,  147,  101,  102,
  111,  109,  112,  114,  116,  117,  119,  122,  123,  124,
  125,  128,  130,  127,  132,  134,  135,  133,  136,  141,
  143,  150,  151,  152,  157,  158,  160,  159,  161,   75,
   43,   44,   41,  131,  106,  108,  162,  118,
};
static const YYINT yycheck[] = {                         13,
   44,   10,   29,  262,   47,  266,  263,   51,  269,  270,
  274,  275,  279,  280,  279,  280,  309,   44,  271,  263,
  281,  310,  283,  279,  280,  302,  287,  271,  263,  286,
  265,  308,  285,  265,  307,  302,  271,   81,  307,  271,
  271,  308,  300,  308,  305,  303,  263,  311,  303,  310,
  285,  306,  308,  304,  305,  307,  279,  280,  307,   86,
  307,  105,  310,  106,  310,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  279,  280,  310,  122,  302,
  288,  289,  290,  291,  310,  308,  310,  311,  292,  293,
  294,  295,  296,  297,  308,  109,  279,  280,  302,  267,
  308,  304,  307,  310,  308,  310,  311,  312,  305,  292,
  293,  294,  295,  296,  297,  288,  289,  290,  291,  302,
  279,  280,  136,  132,  302,  308,  288,  289,  290,  291,
  292,  293,  294,  295,  296,  297,  150,  151,  307,  302,
  303,  310,  311,  312,  308,  305,  308,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  257,  258,  259,
  302,  261,  310,  311,  312,  257,  258,  259,  282,  308,
  302,  262,  306,  311,  302,  310,  262,  304,  272,  301,
  306,  284,  263,  308,  273,  260,  306,  311,  264,  286,
  302,  300,  300,  263,  265,  285,  302,  285,  302,  263,
  302,  302,   26,  122,   80,   82,  160,  101,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 312
#define YYUNDFTOKEN 355
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
"ARRAY","START","END","STARTF","ENDF","DECLARE","MODULE","PROGRAM","GET_VALUE",
"PRINT","USE","WITH","PARAMETERS","TRUE_","FALSE_","TAKES","INPUT","RETURNS",
"AND","OR","FOR","IN","SWITCH","CASE","BREAK","DEFAULT","WHILE","PLUS","MINUS",
"MUL","DIV","LT","LE","GE","GT","EQ","NE","DEF","ENDDEF","COLON","RANGEOP",
"SEMICOL","COMMA","ASSIGNOP","SQBO","SQBC","BO","BC","DOLLAR","ID","NUM","RNUM",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
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
"$$3 :",
"whichId : SQBO ID $$3 SQBC",
"whichId :",
"simpleStmt : assignmentStmt",
"simpleStmt : moduleReusestmt",
"$$4 :",
"assignmentStmt : ID $$4 whichStmt",
"whichStmt : lvalueIDStmt",
"whichStmt : lvalueARRStmt",
"lvalueIDStmt : ASSIGNOP expression SEMICOL",
"lvalueARRStmt : SQBO index SQBC ASSIGNOP expression SEMICOL",
"index : NUM",
"index : ID",
"$$5 :",
"moduleReusestmt : optional USE MODULE ID $$5 WITH PARAMETERS idList SEMICOL",
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
"$$6 :",
"conditionalStmt : SWITCH BO ID $$6 BC START caseStmt default END",
"caseStmt : CASE value COLON statements BREAK SEMICOL caseStmt",
"caseStmt :",
"value : NUM",
"value : TRUE_",
"value : FALSE_",
"default : DEFAULT COLON statements BREAK SEMICOL",
"default :",
"$$7 :",
"$$8 :",
"iterativeStmt : FOR BO ID $$7 IN range BC STARTF statements $$8 ENDF",
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
#line 597 "test.y"

#include <stdio.h>
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
struct value perfOp(BINARY_TREE op1, char *op, BINARY_TREE op2)
{
	struct value vop;
	if(strcmp(op1->val.usethis,op2->val.usethis)==0)
	{
		vop.usethis=op1->val.usethis;
		if(strcmp(op,"+")==0)
		{
			if(strcmp(vop.usethis,"num")==0) vop.v.i=(op1->val.v.i + op2->val.v.i);
			else if(strcmp(vop.usethis,"rnum")==0)	vop.v.f=(op1->val.v.f + op2->val.v.f);			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"-")==0)
		{
			if(strcmp(vop.usethis,"num")==0) vop.v.i=(op1->val.v.i - op2->val.v.i);
			else if(strcmp(vop.usethis,"rnum")==0)	vop.v.f=(op1->val.v.f - op2->val.v.f);			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"*")==0)
		{
			if(strcmp(vop.usethis,"num")==0) vop.v.i=(op1->val.v.i * op2->val.v.i);
			else if(strcmp(vop.usethis,"rnum")==0)	vop.v.f=(op1->val.v.f * op2->val.v.f);			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"/")==0)
		{
			if(strcmp(vop.usethis,"num")==0) vop.v.i=(op1->val.v.i / op2->val.v.i);
			else if(strcmp(vop.usethis,"rnum")==0)	vop.v.f=(op1->val.v.f / op2->val.v.f);			
			//printf("%d",vop.v.i);
			return vop;
		}
	}
	else
		yyerror("type mismatch!\n");
}
struct value perfRop(BINARY_TREE op1, char *op, BINARY_TREE op2)
{
	struct value vop;
	if(strcmp(op1->val.usethis,op2->val.usethis)==0)
	{
		vop.usethis="bool";
		if(strcmp(op,"<")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) < (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) < (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"<=")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) <= (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) <= (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,">")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) > (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) > (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,">=")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) > (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) > (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"==")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) == (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) == (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
		else if(strcmp(op,"!=")==0)
		{
			if(strcmp(op1->val.usethis,"num")==0){if((op1->val.v.i) != (op2->val.v.i))vop.v.s="true"; else vop.v.s="false";}
			else if(strcmp(op1->val.usethis,"rnum")==0){if((op1->val.v.f) != (op2->val.v.f))vop.v.s="true"; else vop.v.s="false";}			
			//printf("%d",vop.v.i);
			return vop;
		}
	}
	else
		yyerror("type mismatch!\n");
}
struct value perfBop(BINARY_TREE op1, char *op, BINARY_TREE op2)
{
	struct value vop;
	if(strcmp(op1->val.usethis,op2->val.usethis)==0)
	{
		vop.usethis="bool";
		if(strcmp(op,"&&")==0){
			if(op1->val.v.s=="true" && op2->val.v.s=="true") vop.v.s="true";
			else vop.v.s="false";
			return vop;
		}
		else if(strcmp(op,"||")==0){
			if(op1->val.v.s=="false" && op2->val.v.s=="false") vop.v.s="false";
			else vop.v.s="true";
			return vop;
		}
	}
	else
		yyerror("type mismatch!\n");
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
	//if(t->first!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->first->nodeIdentifier]);
	//if(t->fourth!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->fourth->nodeIdentifier]);
	//if(t->third!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->third->nodeIdentifier]);
	//if(t->second!=NULL) printf(" Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->second->nodeIdentifier]);
	PrintTree(t->first);
	PrintTree(t->second);
	PrintTree(t->third);
	PrintTree(t->fourth);
}
void sPush(char *s){
FILE *fp; 
fp = fopen("forloop.txt", "a");
fseek(fp,0,SEEK_END);
fprintf(fp,"%s",s);
fclose(fp);
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

#line 606 "y.tab.c"

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
#line 148 "test.y"
	{BINARY_TREE ParseTree;
		struct value temp;
		temp.usethis="none";
										ParseTree = create_node(temp,PROGRAM,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
										/*PrintTree(ParseTree);										*/
										printf("\nParsing Successful...!\n");}
break;
case 2:
#line 155 "test.y"
	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 3:
#line 160 "test.y"
	{	struct value temp;
						temp.v.s = "real   ";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 4:
#line 165 "test.y"
	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "datatype";
						yyval.tVal = create_node(temp,DATATYPE,NULL,NULL,NULL,NULL);
					}
break;
case 5:
#line 170 "test.y"
	{	struct value temp;
									temp.v.s = "array";
									temp.usethis = "datatype";
									yyval.tVal = create_node(temp,DATATYPE,yystack.l_mark[-3].tVal,yystack.l_mark[0].tVal,NULL,NULL);
								}
break;
case 6:
#line 176 "test.y"
	{	struct value temp;
						temp.v.s = "integer";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 7:
#line 181 "test.y"
	{	struct value temp;
						temp.v.s = "real   ";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 8:
#line 186 "test.y"
	{	struct value temp;
						temp.v.s = "boolean";
						temp.usethis = "type";
						yyval.tVal = create_node(temp,TYPE,NULL,NULL,NULL,NULL);
					}
break;
case 9:
#line 192 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,MODULEDEF,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 10:
#line 196 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,STATEMENTS,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL,NULL);
							}
break;
case 11:
#line 199 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,STATEMENTS,NULL,NULL,NULL,NULL);
				}
break;
case 12:
#line 203 "test.y"
	{NOTHING
						yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 13:
#line 206 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 14:
#line 209 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 15:
#line 212 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 16:
#line 215 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,STATEMENT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 17:
#line 219 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";yystack.l_mark[0].sv=temp;
						int j=hash_search(temp.v.s); 
						if(j!=-1){
						char str[20]; 
						if(strcmp(symtab[j].type,"integer")==0)
							{int x;scanf("%d",&x);sprintf(str,"%d",x);hash_insert_val(temp.v.s,str);}
						else if(strcmp(symtab[j].type,"real   ")==0)
							{float x;scanf("%d",&x);sprintf(str,"%f",x);hash_insert_val(temp.v.s,str);}
						else if(strcmp(symtab[j].type,"boolean")==0)
							{char x[20];scanf("%s",x);if(strcmp(x,"true")==0||strcmp(x,"false")==0) strcpy(str,x);hash_insert_val(temp.v.s,str);}
						
						}
						}
break;
case 18:
#line 231 "test.y"
	{NOTHING
									yyval.tVal = create_node(temp,IOSTMT,NULL,NULL,NULL,NULL);
								}
break;
case 19:
#line 234 "test.y"
	{NOTHING		
								if(sset) sPush("print(");
								yyval.tVal = create_node(temp,IOSTMT,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
								/*printf("%d\n",$$->val.v.i);*/
								if(strcmp(yystack.l_mark[-2].tVal->val.usethis,"identifier")==0){
									/*printf("%s\n",$3->val.v.s);*/
									for(int i=0;i<SYMTABSIZE;i++) {
										if(strcmp(symtab[i].name,yystack.l_mark[-2].tVal->val.v.s)==0){
											printf("%s\n",symtab[i].val);
											if(sset) sPush(symtab[i].val);
											break;
										}
									}
								}
								else if(strcmp(yystack.l_mark[-2].tVal->val.usethis,"rnum")==0)
									printf("%f\n",yystack.l_mark[-2].tVal->val.v.f);
								else if(strcmp(yystack.l_mark[-2].tVal->val.usethis,"num")==0)
									printf("%d\n",yystack.l_mark[-2].tVal->val.v.i);
								if(sset) sPush(");");
							}
break;
case 20:
#line 255 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";yystack.l_mark[0].sv=temp;}
break;
case 21:
#line 255 "test.y"
	{NOTHING temp=yystack.l_mark[-2].sv; yyval.tVal = create_node(temp,VAR,yystack.l_mark[0].tVal,NULL,NULL,NULL);}
break;
case 22:
#line 256 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}
break;
case 23:
#line 261 "test.y"
	{	struct value temp;
						temp.v.f = yylval.fVal;
						temp.usethis = "rnum";
						yyval.tVal = create_node(temp,VAR,NULL,NULL,NULL,NULL);
					}
break;
case 24:
#line 267 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";yystack.l_mark[0].sv=temp;}
break;
case 25:
#line 267 "test.y"
	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							yyval.tVal = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
break;
case 26:
#line 272 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,WHICHID,NULL,NULL,NULL,NULL);
						}
break;
case 27:
#line 276 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,SIMPLESTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 28:
#line 279 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,SIMPLESTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 29:
#line 283 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";yystack.l_mark[0].sv=temp;}
break;
case 30:
#line 283 "test.y"
	{						
							/*char str[20];*/
							/*if(strcmp($3->val.usethis,"rnum")==0)*/
							/*	sprintf(str,"%f",$3->val.v.f);*/
							/*else if(strcmp($3->val.usethis,"num")==0)*/
							/*	sprintf(str,"%d",$3->val.v.i);*/
							/*else if(strcmp($3->val.usethis,"bool")==0)*/
							/*strcpy(str,$3->val.v.s);*/
							
						NOTHING
							temp=yystack.l_mark[-2].sv;
							char str[20];
							int j=hash_search(yystack.l_mark[-2].sv.v.s); 
						if(j!=-1){
						if(strcmp(symtab[j].type,"integer")==0 && strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
							{sprintf(str,"%d",yystack.l_mark[0].tVal->val.v.i); hash_insert_val(temp.v.s,str);}
						else if(strcmp(symtab[j].type,"real   ")==0 && strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
							{sprintf(str,"%f",yystack.l_mark[0].tVal->val.v.f); hash_insert_val(temp.v.s,str);}
						else if(strcmp(symtab[j].type,"boolean")==0 && strcmp(yystack.l_mark[0].tVal->val.usethis,"bool")==0)
							{strcpy(str,yystack.l_mark[0].tVal->val.v.s);hash_insert_val(temp.v.s,str);}
						else
							yyerror("type mismatch!\n");						
						}
							/*hash_insert_val($1.v.s,str);*/
							yyval.tVal = create_node(temp,ASSIGNMENTSTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 31:
#line 310 "test.y"
	{NOTHING
							if(strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
							temp.v.f=yystack.l_mark[0].tVal->val.v.f;
							else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
							temp.v.i=yystack.l_mark[0].tVal->val.v.i;
							else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"bool")==0)
							temp.v.s=yystack.l_mark[0].tVal->val.v.s;
							temp.usethis=yystack.l_mark[0].tVal->val.usethis;
							yyval.tVal = create_node(temp,WHICHSTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 32:
#line 320 "test.y"
	{NOTHING
							yyval.tVal = create_node(temp,WHICHSTMT,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 33:
#line 324 "test.y"
	{NOTHING
									if(strcmp(yystack.l_mark[-1].tVal->val.usethis,"rnum")==0)
									temp.v.f=yystack.l_mark[-1].tVal->val.v.f;
									else if(strcmp(yystack.l_mark[-1].tVal->val.usethis,"num")==0)
									temp.v.i=yystack.l_mark[-1].tVal->val.v.i;
									else if(strcmp(yystack.l_mark[-1].tVal->val.usethis,"bool")==0)
									temp.v.s=yystack.l_mark[-1].tVal->val.v.s;
									temp.usethis=yystack.l_mark[-1].tVal->val.usethis;
									yyval.tVal = create_node(temp,LVALUEIDSTMT,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
								}
break;
case 34:
#line 335 "test.y"
	{NOTHING
											yyval.tVal = create_node(temp,LVALUEARRSTMT,yystack.l_mark[-4].tVal,NULL,NULL,NULL);
										}
break;
case 35:
#line 339 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
break;
case 36:
#line 344 "test.y"
	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						yystack.l_mark[0].sv=temp;
						yyval.tVal = create_node(temp,INDEX,NULL,NULL,NULL,NULL);
					}
break;
case 37:
#line 351 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 38:
#line 351 "test.y"
	{NOTHING
	yyval.tVal = create_node(temp,MODULEREUSESTMT,yystack.l_mark[-8].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
}
break;
case 39:
#line 355 "test.y"
	{NOTHING
									yyval.tVal = create_node(temp,OPTIONAL,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
								}
break;
case 40:
#line 358 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,OPTIONAL,NULL,NULL,NULL,NULL);
				}
break;
case 41:
#line 362 "test.y"
	{	struct value temp;
							temp.v.s = yylval.sVal;
							temp.usethis = "identifier";
							yystack.l_mark[0].sv=temp;
							yyval.tVal = create_node(temp,IDLIST,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
						}
break;
case 42:
#line 368 "test.y"
	{	struct value temp;
						temp.v.s = yylval.sVal;
						temp.usethis = "identifier";
						yystack.l_mark[0].sv=temp;
						yyval.tVal = create_node(temp,IDLIST,NULL,NULL,NULL,NULL);
					}
break;
case 43:
#line 375 "test.y"
	{NOTHING
							if(strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
							temp.v.f=yystack.l_mark[0].tVal->val.v.f;
							else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
							temp.v.i=yystack.l_mark[0].tVal->val.v.i;
							temp.usethis=yystack.l_mark[0].tVal->val.usethis;
							yyval.tVal = create_node(temp,EXPRESSION,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 44:
#line 383 "test.y"
	{NOTHING
							temp.usethis=yystack.l_mark[0].tVal->val.usethis;
							temp.v.s=yystack.l_mark[0].tVal->val.v.s;
							yyval.tVal = create_node(temp,EXPRESSION,yystack.l_mark[0].tVal,NULL,NULL,NULL);
						}
break;
case 45:
#line 389 "test.y"
	{NOTHING
								temp=perfOp(yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal->val.v.s,yystack.l_mark[0].tVal);
								yyval.tVal = create_node(temp,ARITHMETICEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
							}
break;
case 46:
#line 393 "test.y"
	{NOTHING
						if(strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
						temp.v.f=yystack.l_mark[0].tVal->val.v.f;
						else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
						temp.v.i=yystack.l_mark[0].tVal->val.v.i;
						temp.usethis=yystack.l_mark[0].tVal->val.usethis;
						yyval.tVal = create_node(temp,ARITHMETICEXPR,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 47:
#line 402 "test.y"
	{NOTHING
							temp=perfOp(yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal->val.v.s,yystack.l_mark[0].tVal);
							yyval.tVal = create_node(temp,TERM,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
						}
break;
case 48:
#line 406 "test.y"
	{NOTHING
						if(strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
						temp.v.f=yystack.l_mark[0].tVal->val.v.f;
						else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
						temp.v.i=yystack.l_mark[0].tVal->val.v.i;
						temp.usethis=yystack.l_mark[0].tVal->val.usethis;				
						yyval.tVal = create_node(temp,TERM,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 49:
#line 415 "test.y"
	{NOTHING
								yyval.tVal = create_node(temp,FACTOR,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 50:
#line 418 "test.y"
	{NOTHING
						if(strcmp(yystack.l_mark[0].tVal->val.usethis,"identifier")==0)
						{
							for(int i=0;i<SYMTABSIZE;i++) {
								if(strcmp(symtab[i].name,yystack.l_mark[0].tVal->val.v.s)==0){
									if(strcmp(symtab[i].type,"integer")==0)
									{temp.v.i=atoi(symtab[i].val);temp.usethis="num";}
									else if(strcmp(symtab[i].type,"real   ")==0)
									{temp.v.f=strtof(symtab[i].val,NULL);temp.usethis="rnum";}
									i=SYMTABSIZE;
								}
							}	
						}
						else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"rnum")==0)
						{temp.v.f=yystack.l_mark[0].tVal->val.v.f;temp.usethis=yystack.l_mark[0].tVal->val.usethis;}
						else if(strcmp(yystack.l_mark[0].tVal->val.usethis,"num")==0)
						{temp.v.i=yystack.l_mark[0].tVal->val.v.i;temp.usethis=yystack.l_mark[0].tVal->val.usethis;}					
						yyval.tVal = create_node(temp,FACTOR,yystack.l_mark[0].tVal,NULL,NULL,NULL);
					}
break;
case 51:
#line 438 "test.y"
	{	struct value temp;
						temp.v.s="+";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 52:
#line 443 "test.y"
	{	struct value temp;
						temp.v.s="-";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 53:
#line 448 "test.y"
	{	struct value temp;
						temp.v.s="*";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 54:
#line 453 "test.y"
	{	struct value temp;
						temp.v.s="/";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,OP,NULL,NULL,NULL,NULL);
					}
break;
case 55:
#line 459 "test.y"
	{NOTHING
										temp=perfBop(yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal->val.v.s,yystack.l_mark[0].tVal);
										yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
									}
break;
case 56:
#line 463 "test.y"
	{NOTHING
											temp=perfRop(yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal->val.v.s,yystack.l_mark[0].tVal);
											yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,yystack.l_mark[0].tVal,NULL);
										}
break;
case 57:
#line 467 "test.y"
	{NOTHING
								temp=yystack.l_mark[-1].tVal->val;
								yyval.tVal = create_node(temp,BOOLEANEXPR,yystack.l_mark[-1].tVal,NULL,NULL,NULL);
							}
break;
case 58:
#line 473 "test.y"
	{	struct value temp;
						temp.v.s="&&";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
break;
case 59:
#line 478 "test.y"
	{	struct value temp;
						temp.v.s="||";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,LOGICALOP,NULL,NULL,NULL,NULL);
					}
break;
case 60:
#line 484 "test.y"
	{	struct value temp;
						temp.v.s="<";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 61:
#line 489 "test.y"
	{	struct value temp;
						temp.v.s="<=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 62:
#line 494 "test.y"
	{	struct value temp;
						temp.v.s=">";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 63:
#line 499 "test.y"
	{	struct value temp;
						temp.v.s=">=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 64:
#line 504 "test.y"
	{	struct value temp;
						temp.v.s="==";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 65:
#line 509 "test.y"
	{	struct value temp;
						temp.v.s="!=";
						temp.usethis = "op";
						yyval.tVal = create_node(temp,RELATIONALOP,NULL,NULL,NULL,NULL);
					}
break;
case 66:
#line 515 "test.y"
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
case 67:
#line 536 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";}
break;
case 68:
#line 536 "test.y"
	{NOTHING	
																			yyval.tVal = create_node(temp,CONDITIONALSTMT,yystack.l_mark[-2].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
																		}
break;
case 69:
#line 540 "test.y"
	{NOTHING
												yyval.tVal = create_node(temp,CASESTMT,yystack.l_mark[-5].tVal,yystack.l_mark[-3].tVal,yystack.l_mark[0].tVal,NULL);
											}
break;
case 70:
#line 543 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,CASESTMT,NULL,NULL,NULL,NULL);
				}
break;
case 71:
#line 547 "test.y"
	{	struct value temp;
						temp.v.i = yylval.iVal;
						temp.usethis = "num";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 72:
#line 552 "test.y"
	{	struct value temp;
						temp.v.s = "true";
						temp.usethis = "bool";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 73:
#line 557 "test.y"
	{	struct value temp;
						temp.v.s = "false";
						temp.usethis = "bool";
						yyval.tVal = create_node(temp,VALUE,NULL,NULL,NULL,NULL);
					}
break;
case 74:
#line 563 "test.y"
	{NOTHING
										yyval.tVal = create_node(temp,DEFAULT,yystack.l_mark[-2].tVal,NULL,NULL,NULL);
									}
break;
case 75:
#line 566 "test.y"
	{NOTHING
					yyval.tVal = create_node(temp,DEFAULT,NULL,NULL,NULL,NULL);
				}
break;
case 76:
#line 570 "test.y"
	{struct value temp;temp.v.s = yylval.sVal;temp.usethis = "identifier";yystack.l_mark[0].sv=temp; sset=1;FILE *fp = fopen("forloop.txt", "w"); fprintf(fp,"start ");fclose(fp);}
break;
case 77:
#line 570 "test.y"
	{FILE *fp; 
fp = fopen("forloop.txt", "a");
fseek(fp,0,SEEK_END);
fprintf(fp," end $");
fclose(fp);}
break;
case 78:
#line 574 "test.y"
	{NOTHING
																				temp=yystack.l_mark[-8].sv;
																				char str[20];
																				sprintf(str,"%d",yystack.l_mark[-5].tVal->val.v.i);	
				hash_insert_val(temp.v.s,str);	/*printf("%d %d",$6->val.v.i,$6->val.e);*/
				/*for(int i=$6->val.v.i;i<=$6->val.e;i++);				*/
				/*{*/
					/*PrintTree($9);*/
					/*PrintTree($9);*/
				/*}													*/
				yyval.tVal = create_node(temp,ITERATIVESTMT,yystack.l_mark[-5].tVal,yystack.l_mark[-2].tVal,NULL,NULL);
																	
			}
break;
case 79:
#line 587 "test.y"
	{NOTHING
											yyval.tVal = create_node(temp,ITERATIVESTMT,yystack.l_mark[-4].tVal,yystack.l_mark[-1].tVal,NULL,NULL);
										}
break;
case 80:
#line 591 "test.y"
	{NOTHING
				temp.v.i=yystack.l_mark[-2].iVal;
				temp.e=yystack.l_mark[0].iVal;
				yyval.tVal = create_node(temp,RANGE,NULL,NULL,NULL,NULL);
				}
break;
#line 1468 "y.tab.c"
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
