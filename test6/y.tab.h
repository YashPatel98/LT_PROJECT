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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union 	{
	int iVal;
	float fVal;
	char *sVal;
	struct value sv;
	BINARY_TREE tVal;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
