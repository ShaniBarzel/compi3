//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_ATTRIBUTES_H
#define COMPI3_ATTRIBUTES_H

#include <iostream>

//todo: not sure if yytokentype is needed
typedef enum{
    VOID,
    INT,
    BYTE,
    B,
    BOOL,
    STRUCT,
    AND,
    OR,
    NOT,
    TRUE,
    FALSE,
    RETURN,
    IF,
    ELSE,
    WHIILE,
    BREAK,
    CONTINUE,
    SC,
    COMMA,
    PERIOD,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    ASSIGN,
    RELOP,
    BINOP,
    ID,
    NUM,
    STRING
}  yytokentype ;
typedef enum{
    TYPE_INT,
    TYPE_BOOL,
    TYPE_STRING
} Type;

struct Node {
    Node()=default;
    Node(char* yytext) : yytext_array(yytext){};
    //todo: check if need to add enum for token names (i/o section, 2.a)
    // virtual string printID(int id, int offset, yytokentype type){};
private:
    int id, offset;
    std::string type;
    char* yytext_array;
};
class Void : public Node {
public:


};
class Int : public Node { //...
};
class Byte : public Node { //...
};
class B : public Node { //...
};
class Bool : public Node { //...
};
class Struct<id> : public Node { //...
};
class And : public Node { //...
};
class Or : public Node { //...
};
class Not : public Node { //...
};
class True : public Node { //...
};
class False : public Node { //...
};
class Return : public Node { //...
};
class If : public Node { //...
};
class Else : public Node { //...
};
class While : public Node { //...
};
class Break : public Node { //...
};
class Continue : public Node { //...
};
class Sc : public Node { //...
};
class Comma : public Node { //...
};
class Period : public Node { //...
};



#define YYSTYPE Node*

extern YYSTYPE yyval;
#endif //COMPI3_ATTRIBUTES_H
