//
// Created by Racheli on 12/3/2018.
//
#include "symtable.h"

//creating the tree of scope tables
SymbolTable* root_node = new SymbolTable(nullptr); //todo: shani - are these global variables? why are thay defined in here?
SymboleTablesTree* table_tree = new SymboleTablesTree(root_node);

//todo: check if needs to return boolean
void SymbolTable::insert(std::string name, Type type, int offset){
    //check if an entry for variable to be inserted already exists in some scope table in the tree
    if(table_tree->doesTableEntryExist(name)) //todo: tableTree should be "this" if we are going eith my idea. else, is will be alwase empty
        return;
    //the new entry of the variable to be inserted to the table
    TableEntry* new_entry = new TableEntry();
    new_entry->name = name;
    new_entry->type = type;
    new_entry->offset = offset;
    //insertion to table of current scope
    scope_table.push_back(new_entry);
}