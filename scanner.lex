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
EQUAL							 (\=\=)
NOTEQUAL                         (\!\=)
SMALLER                          (\<)
BIGGER                           (\>)
BEQ                              (\>\=)
SEQ                              (\<\=)
PLUS					         (\+)
MINUS                            (\-)
MUL                              (\*)
DIV                              (\/)
ID							     [a-zA-Z][a-zA-Z0-9]*
NUM							     0|[1-9][0-9]*
STRING							 (\")([^\n\r\"\\]|\\[rnt"\\])+(\")
whitespace	                    (\x09|\x20)
comment                         \/\/[^\r\n]*[\r|\n|\r\n]?
newline                         (\n)



%%
{VOID}								  { yylval=new VoidNode(yytext);
                                           return VOID;}
{INT}								  { yylval=new IntNode(yytext);
                                           return INT;}
{BYTE}								  { yylval=new ByteNode(yytext);
                                           return BYTE;}
{B}								      { yylval=new BNode(yytext);
                                           return B;}
{BOOL}								  { yylval=new BoolNode(yytext);
                                           return BOOL;}
{STRUCT}							  { yylval=new StructNode(yytext);
                                           return STRUCT;}
{AND}							      { yylval=new AndNode(yytext);
                                           return AND;}
{OR}							      { yylval=new OrNode(yytext);
                                           return OR;}
{NOT}							      { yylval=new NotNode(yytext);
                                           return NOT;}
{TRUE}							      { yylval=new TrueNode(yytext);
                                           return TRUE;}
{FALSE}							      { yylval=new FalseNode(yytext);
                                           return FALSE;}
{RETURN}							  { yylval=new ReturnNode(yytext);
                                           return RETURN;}
{IF}				                  { yylval=new IfNode(yytext);
                                           return IF;}
{ELSE}							      { yylval=new ElseNode(yytext);
                                           return ELSE;}
{WHILE}							      { yylval=new WhileNode(yytext);
                                           return WHILE;}
{BREAK}							      { yylval=new BreakNode(yytext);
                                           return BREAK;}
{CONTINUE}							  { yylval=new ContinueNode(yytext);
                                           return CONTINUE;}
{SC}							      { yylval=new ScNode(yytext);
                                           return SC;}
{COMMA}							      { yylval=new CommaNode(yytext);
                                           return COMMA;}
{PERIOD}							  { yylval=new PeriodNode(yytext);
                                           return PERIOD;}
{LPAREN}							  { yylval=new LparenNode(yytext);
                                           return LPAREN;}
{RPAREN}							  { yylval=new RparenNode(yytext);
                                           return RPAREN;}
{LBRACE}							  { yylval=new LbraceNode(yytext);
                                           return LBRACE;}
{RBRASCE}							  { yylval=new RbraceNode(yytext);
                                           return RBRACE;}
{ASSIGN}							  { yylval=new AssignNode(yytext);
                                           return ASSIGN;}
{EQUAL}							      { yylval=new EqualNode(yytext);
                                           return EQUAL;}
{NOTEQUAL}							  { yylval=new NotEqualNode(yytext);
                                           return NOTEQUAL;}
{SMALLER}							  { yylval=new SmallerNode(yytext);
                                            return SMALLER;}
{BIGGER}							  { yylval=new BiggerNode(yytext);
                                            return BIGGER;}
{BEQ}							      { yylval=new BeqNode(yytext);
                                            return BEQ;}
{SEQ}							      { yylval=new SeqNode(yytext);
                                            return SEQ;}
{ID}							      { yylval=new IdNode(yytext);
                                           return ID;}
{NUM}							      { yylval=new NumNode(yytext);
                                           return NUM;}
{STRING}							  { yylval=new StringNode(yytext);
                                           return STRING;}
{MINUS}                               { yylval = new MinusNode(yytext);
                                           return MINUS;}
{PLUS}                                { yylval = new PlusNode(yytext);
                                           return PLUS;}
{MUL}                                 { yylval = new MulNode(yytext);
                                           return MUL;}
{DIV}                                 { yylval = new DivNode(yytext);
                                           return DIV;}
{whitespace}				          ;
{newline}                             ;
{comment}                             ;
.                                     {output::errorLex(yylineno); exit(0);}
%%
