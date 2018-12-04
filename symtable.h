//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_SYMTABLE_H
#define COMPI3_SYMTABLE_H

#include <string>
#include <vector>
#include "attributes.h"

struct TableEntry;
class SymbolTable;
class SymbolTablesTree;

struct TableEntry {
    std::string name;
    Type type;
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
                it != end; ++it) {
            if ((*it)->name == name)
                return true;
        }
        return false;
    }
};

#endif //COMPI3_SYMTABLE_H
