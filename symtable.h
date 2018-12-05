//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_SYMTABLE_H
#define COMPI3_SYMTABLE_H

#include <string>
#include <vector>
#include "attributes.h"

struct TableEntry; //todo: shani: why struct? i need constructor
class SymbolTable;
class SymbolTablesTree;

struct TableEntry {
    std::string name;
    Type type;
    std::string* StructType; //todo: shani: if the type of the variable is a variable that it's type is struct. else, it will be null
    int size;
    int offset;
};

/*
 * each symbol table is a node in the tree
 */
class SymbolTable {
    //parent_table is the father of the current node in the symbol tables tree
    SymbolTable* parent_table;
    //scope_table is vector representing the current scope's symbol table
    std::vector<TableEntry*> scope_table;
public:
    std::vector<TableEntry*> getScopeTable(){
        return scope_table;
    }

    //todo: shani: how is the fact that this is a tree is menifests? can i think of it as a stack, and the "father" is the sybTable below it?
    /*
     * creates a new scope table which is the son of p
     */
    SymbolTable(SymbolTable* p) : parent_table(p), scope_table() {};
    /*
     * inserts an entry of a variable to the table
     */
    void insert(std::string name, Type type, int offset);

};

/*
 * the tree of symbol tables created in executing MakeTable(parent)
 */
//todo: check when and where should MakeTable be executed
//todo: shani: Maketable is a function that supposed to call the contstructor of SymbleTable. i cannot see the need of this class :(
class SymboleTablesTree{
    SymbolTable* root;
public:
    //setting the root node of the symbol tables tree
    SymboleTablesTree(SymbolTable* r) : root(r) {};
    /*
     * an auxiliary function to check if the tree already contains an entry for the variable name
     */
    bool doesTableEntryExist(std::string name){
        //root_table contains the whole tables tree vector (from the root)
        std::vector<TableEntry*> root_table = root->getScopeTable();
        for (std::vector<TableEntry*>::const_iterator it = root_table.begin(), end = root_table.end();
             it != end; ++it) { //todo: shani: the iteration is only on the root table, and not his sons.
            if ((*it)->name == name)
                return true;
        }
        /*todo: shani: here's an idea: we need this function in order to check if a veriable is already defind in the current
        scope, or in the scopes that he is contained in. why not put this as a method of the class "SymbleTable", and let it be recursive search?
        i mean, take this function as it is , and add this right here:

        if (this->p == nullptr) return false; //we reached the root
        else return (this->p)->doesTableEntryExsist(name);

         */
         return false;
    }
};

#endif //COMPI3_SYMTABLE_H
