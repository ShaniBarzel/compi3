//note: this is the previous lexer, we need to change it //todo: delete
%{

/* Declarations section */
#include <stdio.h>

%}
%option yylineno
%option noyywrap
%option caseless

VOID								  (void)
BYTE								  (byte)
B                                     (b)
BOOL								 (bool)
STRUCT							  (struct)
AND							      (and)
OR							      (or)
NOT							      (not)
TRUE							      (true)
FALSE							      (false)
RETURN							  (return)
IF			                  (if)
ELSE							  (else)
WHILE							      (while)
BREAK						      (break)
CONTINUE							  (continue)
SC							      (\;)
COMMA							      (\,)
PERIOD							  (\.)
LPAREN							  (\()
RPAREN							  (\))
LBRACE							  (\{)
RBRASCE							  (\})
ASSIGN							  (\=)
RELOP							  ((\=\=)|(\!\=)|(\<)|(\>)|(\<\=)|(\>\=))
BINOP					          ((\+)|(\-)|(\*)|(\/))
ID							      [a-zA-Z][a-zA-Z0-9]*
NUM							      0|[1-9][0-9]*
STRING							  (\")([^\n\r\"\\]|\\[rnt"\\])+(\")
.                                  {errorLex(yylineno);}



%s KA IN K //todo: change
%%
{VOID}								  { yylval=new Void(yytext)
                                           return VOID;}
{INT}								  { yylval=new Int(yytext)
                                           return INT;}
{BYTE}								  { yylval=new Byte(yytext)
                                           return BYTE;}
{B}								      { yylval=new B(yytext)
                                           return B;}
{BOOL}								  { yylval=new Bool(yytext)
                                           return BOOL;}
{STRUCT}							  { yylval=new Struct(yytext)
                                           return STRUCT;}
{AND}							      { yylval=new And(yytext)
                                           return AND;}
{OR}							      { yylval=new Or(yytext)
                                           return OR;}
{NOT}							      { yylval=new Not(yytext)
                                           return NOT;}
{TRUE}							      { yylval=new True(yytext)
                                           return STRUCT;}
{FALSE}							      { yylval=new False(yytext)
                                           return FALSE;}
{RETURN}							  { yylval=new Return(yytext)
                                           return RETURN;}
{IF}				                  { yylval=new If(yytext)
                                           return IF;}
{ELSE}							      { yylval=new Else(yytext)
                                           return ELSE;}
{WHILE}							      { yylval=new While(yytext)
                                           return WHILE;}
{BREAK}							      { yylval=new Break(yytext)
                                           return BREAK;}
{CONTINUE}							  { yylval=new Continue(yytext)
                                           return CONTINUE;}
{SC}							      { yylval=new Sc(yytext)
                                           return SC;}
{COMMA}							      { yylval=new Comma(yytext)
                                           return COMMA;}
{PERIOD}							  { yylval=new Period(yytext)
                                           return PERIOD;}
{LPAREN}							  { yylval=new Lparen(yytext)
                                           return LPAREN;}
{RPAREN}							  { yylval=new Rparen(yytext)
                                           return RPAREN;}
{LBRACE}							  { yylval=new Lbrace(yytext)
                                           return LBRACE;}
{RBRASCE}							  { yylval=new Rbrace(yytext)
                                           return RBRACE;}
{ASSIGN}							  { yylval=new Assign(yytext)
                                           return ASSIGN;}
{RELOP}							      { yylval=new Relop(yytext)
                                           return RELOP;}
{BINOP}							      { yylval=new Binop(yytext)
                                           return BINOP;}
{ID}							      { yylval=new Id(yytext)
                                           return ID;}
{NUM}							      { yylval=new Num(yytext)
                                           return NUM;}
{STRING}							  { yylval=new String(yytext)
                                           return STRING;}












<K,KA>{assign}	   	 					 {BEGIN(KA); return(ASSIGN); }
{comment}                                {return(-1);}
{section}	 					 		 {return(SECTION);}
^{indent}       						 {BEGIN(IN); return(INDENT);}
<<EOF>>        						     {return(EF);}
<IN,KA>{true}/.* 					     {return(TRUE);}
<IN,KA>{false}/.*    					 {return(FALSE);}
<IN,KA>{integer}        		 		 {return(INTEGER);}
<IN,KA>{real}          		 			 {return(REAL);}
<IN,KA>{path}           		 		 {return(PATH);}
<IN,KA>{link}           		 		 {return(LINK);}
<IN,KA>{sep}             				 {return(SEP);}
<IN,KA>{string}          				 {return(STRING);}
{line}								     BEGIN(0);
{whitespace}							 ;
.									     {printf("Error %c\n", yytext[yyleng-1]); exit(0);}
%%
