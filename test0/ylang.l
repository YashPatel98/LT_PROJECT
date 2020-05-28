%{
	#include <stdio.h> 
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include "global.h"
	void yyerror(char *);
	#include "y.tab.h"
%}
DIGIT    [0-9]
%%
integer		{return INTEGER;}
real		{return REAL;}
boolean		{return BOOLEAN;}
of		{return OF;}
array		{return ARRAY;}
start		{return START;}
end		{return END;}
declare		{return DECLARE;}
module		{return MODULE;}
program		{return PROGRAM;}
get_value	{return GET_VALUE;}
print		{return PRINT;}
use		{return USE;}
with		{return WITH;}
parameters	{return PARAMETERS;}
true		{return TRUEV;}
false		{return FALSEV;}
takes		{return TAKES;}
input		{return INPUT;}
returns		{return RETURNS;}
AND		{return AND;}
OR		{return OR;}
for		{return FOR;}
in		{return IN;}
switch		{return SWITCH;}
case		{return CASE;}
break		{return BREAK;}
default		{return DEFAULT;}
while		{return WHILE;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"<="		{return LE;}
"<"		{return LT;}
">="		{return GE;}
">"		{return GT;}
"=="		{return EQ;}
"!="		{return NE;}
"<<"		{return DEF;}
">>"		{return ENDDEF;}
":"		{return COLON;}
".."		{return RANGEOP;}
";"		{return SEMICOL;}
","		{return COMMA;}
":="		{return ASSIGNOP;}
"["		{return SQBO;}
"]"		{return SQBC;}
"("		{return BO;}
")"		{return BC;}
"**"		{return COMMENTMARK;}
"$"		{return EXIT;}

[ \t\n]+          /* eat up whitespace */
"**"[^*]*"**"     /* eat up comment start:** end:** */
{DIGIT}+	{
			//printf( "An integer: %s\n", yytext);
			yylval.num = atoi(yytext);
			return NUM;
                }

{DIGIT}+"."{DIGIT}*	{
                     		//printf( "A real: %s\n", yytext);
				yylval.rnum = atof(yytext);
				return RNUM;
			}
{DIGIT}+"."{DIGIT}+[Ee]("+"|"-"){0,1}{DIGIT}+ 	{
                     						//printf( "A real: %s\n", yytext);
								yylval.rnum = atof(yytext);
								return RNUM;                     	
						}
													
[a-zA-Z][a-zA-Z0-9]*	{
				yylval.id=strdup(yytext);
				return ID;
			}
.	printf( "Unrecognized character: %s\n", yytext );
%%
int yywrap(void) {
return 1;
}
