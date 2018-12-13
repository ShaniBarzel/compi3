%{

/* Declarations section */
#include <stdio.h>
#include "output.hpp"
#include "attributes.h"
#include "source.tab.hpp"

%}
%option yylineno
%option noyywrap
%option caseless

VOID							 (void)
INT                              (int)
BYTE							 (byte)
B                                (b)
BOOL						     (bool)
STRUCT						     (struct)
AND							     (and)
OR							     (or)
NOT							     (not)
TRUE							 (true)
FALSE							 (false)
RETURN							 (return)
IF			                     (if)
ELSE							 (else)
WHILE							 (while)
BREAK						     (break)
CONTINUE						 (continue)
SC							     (\;)
COMMA							 (\,)
PERIOD							 (\.)
LPAREN							 (\()
RPAREN							 (\))
LBRACE							 (\{)
RBRASCE							 (\})
ASSIGN							 (\=)
ARELOP							 ((\=\=)|(\!\=))
NARELOP                          ((\<)|(\>)|(\<\=)|(\>\=))
LBINOP					         (\+)|(\-)
SBINOP                           (\*)|(\/)
ID							     [a-zA-Z][a-zA-Z0-9]*
NUM							     0|[1-9][0-9]*
STRING							 (\")([^\n\r\"\\]|\\[rnt"\\])+(\")


%%
{VOID}								  { yylval=new Void(yytext)
                                           return VOID;}
{INT}								  { yylval=new IntNode(yytext)
                                           return INT;}
{BYTE}								  { yylval=new ByteNode(yytext)
                                           return BYTE;}
{B}								      { yylval=new BNode(yytext)
                                           return B;}
{BOOL}								  { yylval=new BoolNode(yytext)
                                           return BOOL;}
{STRUCT}							  { yylval=new StructNode(yytext)
                                           return STRUCT;}
{AND}							      { yylval=new AndNode(yytext)
                                           return AND;}
{OR}							      { yylval=new OrNode(yytext)
                                           return OR;}
{NOT}							      { yylval=new NotNode(yytext)
                                           return NOT;}
{TRUE}							      { yylval=new TrueNode(yytext)
                                           return STRUCT;}
{FALSE}							      { yylval=new FalseNode(yytext)
                                           return FALSE;}
{RETURN}							  { yylval=new ReturnNode(yytext)
                                           return RETURN;}
{IF}				                  { yylval=new IfNode(yytext)
                                           return IF;}
{ELSE}							      { yylval=new ElseNode(yytext)
                                           return ELSE;}
{WHILE}							      { yylval=new WhileNode(yytext)
                                           return WHILE;}
{BREAK}							      { yylval=new BreakNode(yytext)
                                           return BREAK;}
{CONTINUE}							  { yylval=new ContinueNode(yytext)
                                           return CONTINUE;}
{SC}							      { yylval=new ScNode(yytext)
                                           return SC;}
{COMMA}							      { yylval=new CommaNode(yytext)
                                           return COMMA;}
{PERIOD}							  { yylval=new PeriodNode(yytext)
                                           return PERIOD;}
{LPAREN}							  { yylval=new LparenNode(yytext)
                                           return LPAREN;}
{RPAREN}							  { yylval=new RparenNode(yytext)
                                           return RPAREN;}
{LBRACE}							  { yylval=new LbraceNode(yytext)
                                           return LBRACE;}
{RBRASCE}							  { yylval=new RbraceNode(yytext)
                                           return RBRACE;}
{ASSIGN}							  { yylval=new AssignNode(yytext)
                                           return ASSIGN;}
{ARELOP}							  { yylval=new RelopNode(yytext)
                                           return ARELOP;}
{NARELOP}							  { yylval=new RelopNode(yytext)
                                            return NARELOP;}
{ID}							      { yylval=new IdNode(yytext)
                                           return ID;}
{NUM}							      { yylval=new NumNode(yytext)
                                           return NUM;}
{STRING}							  { yylval=new StringNode(yytext)
                                           return STRING;}
.                                      {errorLex(yylineno);}
%%
