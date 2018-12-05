//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_ATTRIBUTES_H
#define COMPI3_ATTRIBUTES_H

#include <iostream>
#include <list>

typedef enum{
    TYPE_INT,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_VOID
} typeName;



class Node {
    int name, size;
    //todo: check if defining as typeName is better
    std::string type;
    //typeName type;
    char* yytext_array;
public:
    Node()=default;
    Node(char* yytext) : yytext_array(yytext){};
    //todo: check if need to add enum for token names (i/o section, 2.a)
    // virtual string printID(int id, int offset, yytokentype type){};

};
// terminals classes
class Void : public Node {};
class Int : public Node {};
class Byte : public Node {};
class B : public Node {};
class Bool : public Node {};
class Struct : public Node {};
class And : public Node {};
class Or : public Node {};
class Not : public Node {};
class True : public Node {};
class False : public Node {};
class Return : public Node {};
class If : public Node {};
class Else : public Node {};
class While : public Node {};
class Break : public Node {};
class Continue : public Node {};
class Sc : public Node {};
class Comma : public Node {};
class Period : public Node {};
class Lparen : public Node{};
class Rparen : public Node{};
class Lbrace : public Node{};
class Rbrace : public Node{};
class Assign : public Node{};
class Relop : public Node{};
class Binop : public Node{};
class Id : public Node{};
class Num : public Node{};
class String : public Node{};

//non terminals
class Exp : public Node{
    std::string value;
};
class ExpList : public Node{
    std::list<Exp> exp_list;
};
//types:
class Type : public Node{
    typeName value;
};
class StructType : public Node{
    Struct s;
    Id id;
};
class FormalDecl : public Node{
    Type type;
    Id id;
    StructType s_type;
};
class FormalsList : public Node{
    std::list<FormalDecl> dec_list;
};
class Formals : public Node{
    FormalsList list;
};
//structs

class StructsDecl : public Node{
    Struct s;
    Id identifier;

};
class Structs : public Node{
    StructsDecl
};
class StructMem : public Node{
    Type type;
    Id id;
};
class StructMemList : public Node{

};


#define YYSTYPE Node*

extern YYSTYPE yyval;
#endif //COMPI3_ATTRIBUTES_H
