//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_ATTRIBUTES_H
#define COMPI3_ATTRIBUTES_H

#include <iostream>
#include <vector>

typedef enum{
    TYPE_BYTE, //todo: shani
    TYPE_INT,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_VOID,
    TYPE_STRUCT,     //todo: RACHELI
    TYPE_STRUCTID, //todo: shani
    TYPE_FUNC //todo: shani
} typeName;


class Node {
public:
    int size; //todo: why name is int?
    std::string name;
    typeName type;
    char* yytext_array;

    Node()=default;
    Node(char* yytext) : yytext_array(yytext){};
    //todo: check if need to add enum for token names (i/o section, 2.a)
    // virtual string printID(int id, int offset, yytokentype type){};

};
// terminals classes
class VoidNode : public Node {};
class IntNode : public Node {};
class ByteNode : public Node {};
class BNode : public Node {};
class BoolNode : public Node {};
class StructNode : public Node {};
class AndNode : public Node {};
class OrNode : public Node {};
class NotNode : public Node {};
class TrueNode : public Node {};
class FalseNode : public Node {};
class ReturnNode : public Node {};
class IfNode : public Node {};
class ElseNode : public Node {};
class WhileNode : public Node {};
class BreakNode : public Node {};
class ContinueNode : public Node {};
class ScNode : public Node {};
class CommaNode : public Node {};
class PeriodNode : public Node {};
class LparenNode : public Node{};
class RparenNode : public Node{};
class LbraceNode : public Node{};
class RbraceNode : public Node{};
class AssignNode : public Node{};
class RelopNode : public Node{};
class BinopNode : public Node{};
class IdNode : public Node{};
class NumNode : public Node{};
class StringNode : public Node{};

//non terminals
class ExpNode : public Node{
    std::string value;
};
class ExpListNode : public Node{
    std::vector<ExpNode>* exp_list;
public:
    ExpListNode() : exp_list(new std::vector<ExpNode>){};
    ~ExpListNode() {delete(exp_list);};
//todo shani
    std::vector<ExpNode>* getList(){
        return exp_list;
    }
};
//types:
class TypeNode : public Node{
public:
    typeName value;
};
class StructTypeNode : public Node{};
class FormalDeclNode : public Node{
    //TypeNode type; //todo: shani: type is alredy in Node
    StructTypeNode s_type;
};
class FormalsListNode : public Node{
public:
    std::vector<FormalDeclNode>* dec_list; //todo: shani: i moved it to public
    FormalsListNode() : dec_list(new std::vector<FormalDeclNode>){};
    ~FormalsListNode(){delete(dec_list);};
};
class FormalsNode : public Node{
public: //todo: shani
    FormalsListNode list;
};
//structs
class StructMemNode : public Node{
public:
    //TypeNode type; //todo: shani: type is alredy in Node
};
class StructMemListNode : public Node{
    std::vector<StructMemNode>* s_list;
public:
    StructMemListNode() : s_list(new std::vector<StructMemNode>){};
    ~StructMemListNode(){delete(s_list);};
};

class StructsDeclNode : public Node{
    StructNode s;
    IdNode identifier;
    StructMemListNode s_mem_list;
};

class StructsNode : public Node{
    StructsDeclNode s_decl;
};


#define YYSTYPE Node*

extern YYSTYPE yyval;
#endif //COMPI3_ATTRIBUTES_H
