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
{VOID}								  { yylval=new Void(yytext->name);
                                           return VOID;}
{INT}								  { yylval=new IntNode(yytext->name);
                                           return INT;}
{BYTE}								  { yylval=new ByteNode(yytext->name);
                                           return BYTE;}
{B}								      { yylval=new BNode(yytext->name);
                                           return B;}
{BOOL}								  { yylval=new BoolNode(yytext->name);
                                           return BOOL;}
{STRUCT}							  { yylval=new StructNode(yytext->name);
                                           return STRUCT;}
{AND}							      { yylval=new AndNode(yytext->name);
                                           return AND;}
{OR}							      { yylval=new OrNode(yytext->name);
                                           return OR;}
{NOT}							      { yylval=new NotNode(yytext->name);
                                           return NOT;}
{TRUE}							      { yylval=new TrueNode(yytext->name);
                                           return STRUCT;}
{FALSE}							      { yylval=new FalseNode(yytext->name);
                                           return FALSE;}
{RETURN}							  { yylval=new ReturnNode(yytext->name);
                                           return RETURN;}
{IF}				                  { yylval=new IfNode(yytext->name);
                                           return IF;}
{ELSE}							      { yylval=new ElseNode(yytext->name);
                                           return ELSE;}
{WHILE}							      { yylval=new WhileNode(yytext->name);
                                           return WHILE;}
{BREAK}							      { yylval=new BreakNode(yytext->name);
                                           return BREAK;}
{CONTINUE}							  { yylval=new ContinueNode(yytext->name);
                                           return CONTINUE;}
{SC}							      { yylval=new ScNode(yytext->name);
                                           return SC;}
{COMMA}							      { yylval=new CommaNode(yytext->name);
                                           return COMMA;}
{PERIOD}							  { yylval=new PeriodNode(yytext->name);
                                           return PERIOD;}
{LPAREN}							  { yylval=new LparenNode(yytext->name);
                                           return LPAREN;}
{RPAREN}							  { yylval=new RparenNode(yytext->name);
                                           return RPAREN;}
{LBRACE}							  { yylval=new LbraceNode(yytext->name);
                                           return LBRACE;}
{RBRASCE}							  { yylval=new RbraceNode(yytext->name);
                                           return RBRACE;}
{ASSIGN}							  { yylval=new AssignNode(yytext->name);
                                           return ASSIGN;}
{ARELOP}							  { yylval=new RelopNode(yytext->name);
                                           return ARELOP;}
{NARELOP}							  { yylval=new RelopNode(yytext->name);
                                            return NARELOP;}
{ID}							      { yylval=new IdNode(yytext->name);
                                           return ID;}
{NUM}							      { yylval=new NumNode(yytext->name);
                                           return NUM;}
{STRING}							  { yylval=new StringNode(yytext->name);
                                           return STRING;}
.                                      {errorLex(yylineno);}
%%
