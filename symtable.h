//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_SYMTABLE_H
#define COMPI3_SYMTABLE_H
#include <list>
#include <string>
#include "attributes.h"

class Func {
public:
    std::string id;
    Type retType;
    std::list<FormalDeclNode> decl_list;
};

class Node {
public:
    std::string id;
    Type type;
    int size;
    int offset;
};

class SymbolTable {
public:
    SymbolTable* parent;
    std::list<Func*> funcs;
    std::list<Var*> vars;
    int defaults;
    SymbolTable(SymbolTable* parent);
    int InsertVar(std::string name,Type type,int size,int offset);
    int InsertFunc(std::string name,Type retType,std::list<FormalDeclNode>);
    Var* getVar(std::string name);
    Func* getFunc(std::string name);
    Func* getLatest();
    Type getRetType(std::string name);
    SymbolTable* getParent();
    ~SymbolTable();
};
#endif //COMPI3_SYMTABLE_H
