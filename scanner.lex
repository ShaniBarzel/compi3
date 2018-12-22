%{

/* Declarations section */
#include <stdio.h>
#include "output.hpp"
#include "attributes.h"
#include "parser.tab.hpp"

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
whitespace	                    (\x09|\x20)
newline                         (\n)

%%
{VOID}								  { yylval=new VoidNode(yytext); printf("VOID ");
                                           return VOID;}
{INT}								  { yylval=new IntNode(yytext); printf("INT ");
                                           return INT;}
{BYTE}								  { yylval=new ByteNode(yytext); printf("BYTE ");
                                           return BYTE;}
{B}								      { yylval=new BNode(yytext); printf("B ");
                                           return B;}
{BOOL}								  { yylval=new BoolNode(yytext); printf("BOOL ");
                                           return BOOL;}
{STRUCT}							  { yylval=new StructNode(yytext); printf("STRUCT ");
                                           return STRUCT;}
{AND}							      { yylval=new AndNode(yytext); printf("AND ");
                                           return AND;}
{OR}							      { yylval=new OrNode(yytext); printf("OR ");
                                           return OR;}
{NOT}							      { yylval=new NotNode(yytext); printf("NOT ");
                                           return NOT;}
{TRUE}							      { yylval=new TrueNode(yytext); printf("TRUE ");
                                           return TRUE;}
{FALSE}							      { yylval=new FalseNode(yytext); printf("FALSE ");
                                           return FALSE;}
{RETURN}							  { yylval=new ReturnNode(yytext); printf("RETURN ");
                                           return RETURN;}
{IF}				                  { yylval=new IfNode(yytext); printf("IF ");
                                           return IF;}
{ELSE}							      { yylval=new ElseNode(yytext); printf("ELSE ");
                                           return ELSE;}
{WHILE}							      { yylval=new WhileNode(yytext); printf("WHILE ");
                                           return WHILE;}
{BREAK}							      { yylval=new BreakNode(yytext); printf("BREAK ");
                                           return BREAK;}
{CONTINUE}							  { yylval=new ContinueNode(yytext); printf("CONTINUE ");
                                           return CONTINUE;}
{SC}							      { yylval=new ScNode(yytext); printf("SC ");
                                           return SC;}
{COMMA}							      { yylval=new CommaNode(yytext); printf("COMMA ");
                                           return COMMA;}
{PERIOD}							  { yylval=new PeriodNode(yytext); printf("PERIOD ");
                                           return PERIOD;}
{LPAREN}							  { yylval=new LparenNode(yytext); printf("LPAREN ");
                                           return LPAREN;}
{RPAREN}							  { yylval=new RparenNode(yytext); printf("RPAREN ");
                                           return RPAREN;}
{LBRACE}							  { yylval=new LbraceNode(yytext); printf("LBRACE ");
                                           return LBRACE;}
{RBRASCE}							  { yylval=new RbraceNode(yytext); printf("RBRACE ");
                                           return RBRACE;}
{ASSIGN}							  { yylval=new AssignNode(yytext); printf("ASSIGN ");
                                           return ASSIGN;}
{ARELOP}							  { yylval=new RelopNode(yytext); printf("ARELOP ");
                                           return ARELOP;}
{NARELOP}							  { yylval=new RelopNode(yytext); printf("NARELOP ");
                                            return NARELOP;}
{ID}							      { yylval=new IdNode(yytext); printf("ID ");
                                           return ID;}
{NUM}							      { yylval=new NumNode(yytext); printf("NUM ");
                                           return NUM;}
{STRING}							  { yylval=new StringNode(yytext); printf("STRING ");
                                           return STRING;}
{whitespace}							 ;
{newline}                               {};
.                                      {printf("Error %c\n", yytext[yyleng-1]); output::errorLex(yylineno);}
%%
