#ifndef COMPI3_ATTRIBUTES_H
#define COMPI3_ATTRIBUTES_H

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstddef>
#include <string>
#include <sstream> //for num to string convert


typedef enum{
    TYPE_BYTE,
    TYPE_INT,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_VOID,
    TYPE_STRUCT,
    TYPE_STRUCTID,
    TYPE_FUNC
} typeName;

typedef enum{
    T0,
    T1,
    T2,
    T3,
    T4,
    T5,
    T6,
    T7,
    T8,
    T9,
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    NUM_OF_TEMP_REGS,
    NONE,
} TempReg;

class Node {
public:
    int size;
    std::string name;
    typeName type;
    char* yytext_array;
    bool err;
    int line_num;
    TempReg reg;
    // std::vector<int>* trueList;
    //std::vector<int>* falseList;
    //std::vector<int>* returnList;
    //std::vector<int>* breakList;

    Node() : size(0), name(), type(), yytext_array(), err(false), line_num(0){};
    Node(char* yytext_a) : size(0),yytext_array(yytext_a),err(false),line_num(0),reg(NONE){ //shani6 reg none init - very inportent!
        if (yytext_a)
            name = std::string(yytext_a);
    };
    virtual ~Node(){};
};
#define YYSTYPE Node*

extern YYSTYPE yyval;
// terminals classes
class CommentNode : public Node {

};
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
class EqualNode : public Node{
public:
    EqualNode(char* yytext_a):Node(yytext_a){};
};
class NotEqualNode : public Node{
public:
    NotEqualNode(char* yytext_a):Node(yytext_a){};
};
class SeqNode : public Node{
public:
    SeqNode(char* yytext_a):Node(yytext_a){};
};
class BeqNode : public Node{
public:
    BeqNode(char* yytext_a):Node(yytext_a){};
};
class SmallerNode : public Node{
public:
    SmallerNode(char* yytext_a):Node(yytext_a){};
};
class BiggerNode : public Node{
public:
    BiggerNode(char* yytext_a):Node(yytext_a){};
};
class MinusNode : public Node{
public:
    MinusNode(char* yytext_a):Node(yytext_a){};
};
class PlusNode : public Node{
public:
    PlusNode(char* yytext_a):Node(yytext_a){};
};
class DivNode : public Node{
public:
    DivNode(char* yytext_a):Node(yytext_a){};
};
class MulNode : public Node{
public:
    MulNode(char* yytext_a):Node(yytext_a){};
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

class StatementNode : public Node{
public:
    StatementNode(): Node(NULL), breakList(new std::vector<int>), returnList(new std::vector<int>), nextList(new std::vector<int>){};
    std::vector<int>* breakList;
    std::vector<int>* returnList;
    std::vector<int>* nextList;
    virtual ~StatementNode(){};

};
class StatementsNode : public Node {
public:
    StatementsNode(): Node(NULL), breakList(new std::vector<int>), returnList(new std::vector<int>),nextList(new std::vector<int>){};
    std::vector<int>* breakList;
    std::vector<int>* returnList;
    std::vector<int>* nextList; //shani
    virtual ~StatementsNode(){};
};

class MNode : public Node{
public:
    MNode(std::string q) :Node(NULL), quad(q){};
    std::string quad;
    virtual ~MNode(){};
};

class NNode : public Node{
public:
    std::vector<int>* nextList;
    NNode(std::vector<int> n_list):Node(NULL),nextList(new std::vector<int>){
        *nextList=n_list;
    };
    virtual ~NNode(){};
};

class ElseMarkerNode : public Node{
public:
    ElseMarkerNode(): Node(NULL), breakList(new std::vector<int>), returnList(new std::vector<int>), nextList(new std::vector<int>){};
    std::string quad;
    std::vector<int>* nextList;
    std::vector<int>* breakList;
    std::vector<int>* returnList;
};

//non terminals
class ExpNode : public Node{
public:
    TempReg loc;
    std::string value;
    std::vector<int>* trueList;
    std::vector<int>* falseList;
    std::vector<int>* returnList;
    std::string s_name;
//  TempReg regName; //(racheli)the reg in which exp value is saved
    ExpNode(std::string v) : Node(NULL), value(v), s_name(),
                             trueList(new std::vector<int>()),falseList(new std::vector<int>()),returnList(new std::vector<int>()){};
    virtual ~ExpNode(){};

};

class ExpListNode : public Node{
public:
    std::vector<ExpNode*>* exp_list;
    ExpListNode() :Node(NULL), exp_list(new std::vector<ExpNode*>){};

    virtual ~ExpListNode() {delete(exp_list);};
    std::vector<ExpNode*>* getList(){
        return exp_list;
    }
};
//types:
class TypeNode : public Node{
public:
    TypeNode():Node(NULL), value(){};
    typeName value;
    virtual ~TypeNode(){};
};

class StructTypeNode : public Node{
public:
    std::string structName;
    int offset;
    StructTypeNode(std::string structName) : Node(NULL), structName(structName){};
    virtual ~StructTypeNode(){};
};

class FormalDeclNode : public Node{
public:
    std::string s_name; // for when we have structType in the parameters list
    FormalDeclNode() : Node(NULL){};
    virtual ~FormalDeclNode(){};
};
class FuncDeclNode : public Node{
public:
    FuncDeclNode() : Node(NULL), return_type(){};
    virtual ~FuncDeclNode(){};
    typeName return_type;
};
class FormalsListNode : public Node{
public:
    std::vector<FormalDeclNode*>* dec_list;
    FormalsListNode() : Node(NULL), dec_list(new std::vector<FormalDeclNode*>){};
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
    int relative_offset; //shani hw4
};
class StructMemListNode : public Node{
public:
    int lineNumberStart;
    std::vector<StructMemNode*>* s_list;
    StructMemListNode() :Node(NULL),  lineNumberStart(),s_list(new std::vector<StructMemNode*>){};
    virtual ~StructMemListNode(){delete(s_list);};
};

class StructsDeclNode : public Node{
public:
    StructsDeclNode() : Node(NULL),s_mem_list(new StructMemListNode()){};
    StructMemListNode* s_mem_list;
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

class lbNode : public Node{
public:
    lbNode(std::string label) : label(label){};
    std::string label;
};

#endif //COMPI3_ATTRIBUTES_H
