//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_ATTRIBUTES_H
#define COMPI3_ATTRIBUTES_H

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstddef>

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

    Node(char* yytext_a= NULL) : size(), name(), type(), yytext_array(yytext_a){};
    virtual ~Node() {};
    //todo: check if need to add enum for token names (i/o section, 2.a)
    // virtual string printID(int id, int offset, yytokentype type){};

};
// terminals classes
class VoidNode : public Node {
public:
    VoidNode(char* yytext_a):Node(yytext_a){};
};
class IntNode : public Node {
public:
    IntNode(char* yytext_a):Node(yytext_a){};
};
class ByteNode : public Node {
public:
    ByteNode(char* yytext_a):Node(yytext_a){};
};
class BNode : public Node {
public:
    BNode(char* yytext_a):Node(yytext_a){};
};
class BoolNode : public Node {
public:
    BoolNode(char* yytext_a):Node(yytext_a){};
};
class StructNode : public Node {
public:
    StructNode(char* yytext_a):Node(yytext_a){};
};
class AndNode : public Node {
public:
    AndNode(char* yytext_a):Node(yytext_a){};
};
class OrNode : public Node {
public:
    OrNode(char* yytext_a):Node(yytext_a){};
};
class NotNode : public Node {
public:
    NotNode(char* yytext_a):Node(yytext_a){};
};
class TrueNode : public Node {
public:
    TrueNode(char* yytext_a):Node(yytext_a){};
};
class FalseNode : public Node {
public:
    FalseNode(char* yytext_a):Node(yytext_a){};
};
class ReturnNode : public Node {
public:
    ReturnNode(char* yytext_a):Node(yytext_a){};
};
class IfNode : public Node {
public:
    IfNode(char* yytext_a):Node(yytext_a){};
};
class ElseNode : public Node {
public:
    ElseNode(char* yytext_a):Node(yytext_a){};
};
class WhileNode : public Node {
public:
    WhileNode(char* yytext_a):Node(yytext_a){};
};
class BreakNode : public Node {
public:
    BreakNode(char* yytext_a):Node(yytext_a){};
};
class ContinueNode : public Node {
public:
    ContinueNode(char* yytext_a):Node(yytext_a){};
};
class ScNode : public Node {
public:
    ScNode(char* yytext_a):Node(yytext_a){};
};
class CommaNode : public Node {
public:
    CommaNode(char* yytext_a):Node(yytext_a){};
};
class PeriodNode : public Node {
public:
    PeriodNode(char* yytext_a):Node(yytext_a){};
};
class LparenNode : public Node{
public:
    LparenNode(char* yytext_a):Node(yytext_a){};
};
class RparenNode : public Node{
public:
    RparenNode(char* yytext_a):Node(yytext_a){};
};
class LbraceNode : public Node{
public:
    LbraceNode(char* yytext_a):Node(yytext_a){};
};
class RbraceNode : public Node{
public:
    RbraceNode(char* yytext_a):Node(yytext_a){};
};
class AssignNode : public Node{
public:
    AssignNode(char* yytext_a):Node(yytext_a){};
};
class RelopNode : public Node{
public:
    RelopNode(char* yytext_a):Node(yytext_a){};
};
class BinopNode : public Node{
public:
    BinopNode(char* yytext_a):Node(yytext_a){};
};
class IdNode : public Node{
public:
    IdNode(char* yytext_a):Node(yytext_a){};
};
class NumNode : public Node{
public:
    NumNode(char* yytext_a):Node(yytext_a){};
};
class StringNode : public Node{
public:
    StringNode(char* yytext_a):Node(yytext_a){};
};

//non terminals
class ExpNode : public Node{
public:
    ExpNode() : Node(NULL), value(){};
    virtual ~ExpNode(){};
    std::string value;
};
class ExpListNode : public Node{
public:
    std::vector<ExpNode>* exp_list;
   ExpListNode() :Node(NULL), exp_list(new std::vector<ExpNode>){};

    virtual ~ExpListNode() {delete(exp_list);};
//todo shani
    std::vector<ExpNode>* getList(){
        return exp_list;
    }
};
//types:
class TypeNode : public Node{
public:
    TypeNode():Node(NULL), value(){};
    typeName value;
    virtual ~TypeNode();
};

class StructTypeNode : public Node{
public:
    StructTypeNode() : Node(NULL){};
    virtual ~StructTypeNode(){};
};
class FormalDeclNode : public Node{
public:
    FormalDeclNode() : Node(NULL), s_type(StructTypeNode()){};
    virtual ~FormalDeclNode(){};
    StructTypeNode s_type;
};
class FuncDeclNode : public Node{
public:
    FuncDeclNode() : Node(NULL), return_type(){};
    virtual ~FuncDeclNode(){};
    typeName return_type;
};
class FormalsListNode : public Node{
public:
    std::vector<FormalDeclNode>* dec_list;
    FormalsListNode() : Node(NULL), dec_list(new std::vector<FormalDeclNode>){};
    virtual ~FormalsListNode(){delete(dec_list);};
};
class FormalsNode : public Node{
public:
    FormalsListNode* list;
    FormalsNode() : Node(NULL), list(new FormalsListNode()){};
    virtual ~FormalsNode(){delete(list);};
};
//structs
class StructMemNode : public Node{
public:
    StructMemNode() : Node(NULL){};
    virtual ~StructMemNode(){};
};
class StructMemListNode : public Node{
public:
    std::vector<StructMemNode>* s_list;
    StructMemListNode() :Node(NULL),  s_list(new std::vector<StructMemNode>){};
    virtual ~StructMemListNode(){delete(s_list);};
};

class StructsDeclNode : public Node{
public:
    StructsDeclNode() : Node(NULL), s(StructNode(NULL)), identifier(IdNode(NULL)), s_mem_list(StructMemListNode()){};
    StructNode s;
    IdNode identifier;
    StructMemListNode s_mem_list;
};

class RetTypeNode : public Node{
public:
    RetTypeNode() :Node(NULL){};
    virtual ~RetTypeNode(){};
};

class StructsNode : public Node{
public:
    StructsNode() : Node(NULL) , s_decl(StructsDeclNode()){}
    StructsDeclNode s_decl;
};

class CallNode : public Node{
public:
    CallNode() : Node(NULL), return_type(){};
    typeName return_type;
};
#define YYSTYPE Node*

extern YYSTYPE yyval;
#endif //COMPI3_ATTRIBUTES_H
