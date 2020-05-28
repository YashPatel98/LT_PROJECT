%{
	int yylex(void);
	void yyerror(char *);
%}
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
%token TRUE
%token FALSE
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
%start program
%%
program 			:	moduleDeclarations otherModules
					;
moduleDeclarations	:	moduleDelcaration moduleDelcarations
					|
					;
moduleDelcaration	:	DECLARE MODULE ID SEMICOL
					;
otherModules		:	module otherMuodules
					|
					;
module				:	DEF MODULE ID ENDDEF TAKES INPUT SQBO input_plist SQBC SEMICOL ret moduleDef
					;
ret					:	RETURNS SQBO output_plist SQBC SEMICOL
					|
					;
input_plist			:	input_plist COMMA ID COLON dataType
					|	ID COLON dataType
					;
output_plist		:	output_plist COMMA ID COLON type
					|	ID COLON type
					;
dataType			:	INTEGER
					|	REAL
					| 	BOOLEAN
					|	ARRAY SQBO range SQBC OF type
					;
type				:	INTEGER
					|	REAL
					| 	BOOLEAN
					;
moduleDef			:	START statements END
					;
statements			:	statement statements
					|
					;
statement			:	ioStmt
					|	simpleStmt
					|	declareStmt
					|	conditionalStmt
					| 	iterativeStmt
					;
ioStmt				:	GET_VALUE BO ID BC SEMICOL
					|	PRINT BO var BC SEMICOL
					;
var					:	ID whichId
					|	NUM
					|	RNUM
					;
whichId				:	SQBO ID SQBC
					|
					;
simpleStmt			:	assignmentStmt
					|	moduleReusestmt
					;
assignmentStmt		:	ID whichStmt
					;
whichStmt			:	lvalueIDStmt
					|	lvalueARRStmt
					;
lvalueIDStmt		:	ASSIGNOP expression SEMICOL
					;
lvalueARRStmt		:	SQBO index SQBC ASSIGNOP expression SEMICOL
					;
index				:	NUM
					|	ID
					;
moduleReusestmt		:	optional USE MODULE ID WITH PARAMETERS idList Semicol
					;
optional			:	SQBO idList SQBC ASSIGNOP
					|
					;
idList				:	idList COMMA ID
					|	ID
					;
expression			:	arithmeticExpr
					|	booleanExpr
					;
arithmeticExpr		:	arithmeticExpr op term
					|	term
					;
term				:	term op factor
					:	factor
					;
factor				:	BO arithmeticExpr BC
					|	var
					;
op					:	PLUS
					|	MINUS
					|	MUL
					|	DIV
					;
booleanExpr			:	booleanExpr logicalOp booleanExpr
					;
logicalOp			:	AND
					|	OR
					;
booleanExpr			:	arithmeticExpr relationalOp arithmeticExpr
					|	BO booleanExpr BC
					;
relationalOp		:	LT
					|	LE
					|	GT
					|	GE
					|	EQ
					|	NE
					;
declareStmt			:	DECLARE idList COLON dataType SEMICOL
					;
conditionalStmt		:	SWITCH BO ID BC START caseStmt default END
					;
caseStmt			:	CASE value COLON statements BREAK SEMICOL caseStmt
					;
value				:	NUM
					|	TRUE
					|	FALSE
					;
default				:	DEFAULT COLON statements BREAK SEMICOL
					|
					;
iterativeStmt		:	FOR BO ID IN range BC START statements END
					|	WHILE BO booleanExpr BC START statements END
					;
range				:	NUM RANGEOP NUM
					;
%%
