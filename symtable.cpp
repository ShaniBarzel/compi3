//
// Created by Racheli on 12/3/2018.
//
#include "symtable.h"

/*
    * remark (racheli): I didn't want to unite all the "doesExist" functions to one because
    * then we wouldve needed a struct to wrap the two entries and it complicates things
 */
TableEntry* SymbolTable::getVariableEntry(std::string name) {
    for (std::vector<TableEntry *>::const_iterator it = variables_scope_table.begin(), end = variables_scope_table.end();
         it != end; ++it) {
        if ((*it)->name == name)
            return *it;
    }
    if(!parent_table)
        return nullptr;
    return parent_table->getVariableEntry(name);
}

TableEntryFunc* SymbolTable::getFunctionEntry(std::string name) {
    for (std::vector<TableEntryFunc *>::const_iterator it = functions_scope_table.begin(), end = functions_scope_table.end();
         it != end; ++it) {
        if ((*it)->name == name)
            return *it;
    }
    if(!parent_table)
        return nullptr;
    return parent_table->getFunctionEntry(name);
}


bool SymbolTable::insertVariableEntry(std::string name, typeName type, int offset){
    //check if an entry for variable to be inserted already exists in some scope table in the tree
    if(getVariableEntry(name))
        return false;
    //the new entry of the variable to be inserted to the table
    TableEntry* new_entry = new TableEntry();
    new_entry->name = name;
    new_entry->type = type;
    new_entry->offset = offset;
    //insertion to table of current scope
    variables_scope_table.push_back(new_entry);
    return true;
}

bool SymbolTable::insertFunctionEntry(std::string name, typeName return_type, std::vector<FormalDeclNode> dec_list) {
    if(getFunctionEntry(name))
        return false;
    TableEntryFunc* new_entry = new TableEntryFunc();
    new_entry->name = name;
    new_entry->declaration_list = dec_list;
    new_entry->return_type = return_type;
    functions_scope_table.push_back(new_entry);
    return true;
}

