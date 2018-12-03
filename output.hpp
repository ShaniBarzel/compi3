#ifndef _236360_3_
#define _236360_3_

#include <vector>
#include <string>
using namespace std;

struct Node {
    //todo: check if bellow needs to be fields:
   /* int id, offset;
    std::string type;*/
    char* yytext_array;
public:
    Node()=default;
    Node(char* yytext) : yytext_array(yytext){};
    //todo: check if need to add enum for token names (i/o section, 2.a)
    virtual string printID(int id, int offset, string type){};
};
class Void : public Node {
public:
   string printID(int id, int offset, string type){

    }

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

namespace output{
    void endScope();
    void printID(const string& id, int offset, const string& type);
    void printStructType(const string& name, vector<string>& memTypes, vector<string>& memNames);

    /* Do not save the string returned from this function in a data structure 
        as it is not dynamically allocated and will be destroyed(!) at the end of the calling scope.
    */
    string makeFunctionType(const string& retType, vector<string>& argTypes);

    void errorLex(int lineno);
    void errorSyn(int lineno);
    void errorUndef(int lineno, const string& id);
    void errorDef(int lineno, const string& id);
    void errorUndefFunc(int lineno, const string& id);
    void errorUndefStruct(int lineno, const string& id);
    void errorUndefStructMember(int lineno, const string& id);
    void errorMismatch(int lineno);
    void errorPrototypeMismatch(int lineno, const string& id, vector<string>& argTypes);
    void errorUnexpectedBreak(int lineno);
    void errorUnexpectedContinue(int lineno);
    void errorMainMissing();
    void errorByteTooLarge(int lineno, const string& value);
}

#endif