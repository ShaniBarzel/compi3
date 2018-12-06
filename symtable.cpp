//
// Created by Racheli on 12/3/2018.
//
#include "symtable.h"

/*
    * remark (racheli): I didn't want to unite all the "doesExist" functions to one because
    * then we wouldve needed a struct to wrap the two entries and it complicates things
 */
TableEntry* SymbolTable::getEntry(std::string name) {
    for (std::vector<TableEntry *>::const_iterator it = scope_table.begin(), end = scope_table.end();
         it != end; ++it) {
        if ((*it)->name == name)
            return *it;
    }
    if(!parent_table)
        return nullptr;
    return parent_table->getEntry(name);
}

bool SymbolTable::insertVariableEntry(std::string name, typeName type, int offset){
    //check if an entry for variable to be inserted already exists in some scope table in the tree
    if(getEntry(name))
        return false;
    //the new entry of the variable to be inserted to the table
    TableEntryVariable* new_entry = new TableEntryVariable();
    new_entry->name = name;
    new_entry->type = type;
    new_entry->offset = offset;
    //insertion to table of current scope
    scope_table.push_back(new_entry);
    return true;
}

bool SymbolTable::insertFunctionEntry(std::string name, typeName return_type, std::vector<FormalDeclNode> dec_list) {
    if(getEntry(name))
        return false;
    TableEntryFunc* new_entry = new TableEntryFunc();
    new_entry->name = name;
    new_entry->declaration_list = dec_list;
    new_entry->return_type = return_type;
    scope_table.push_back(new_entry);
    return true;
}

bool SymbolTable::insertStructEntry(std::string name, typeName type, std::vector<StructMemNode> fields_list) {
    if(getEntry(name))
        return false;
    TableEntryStruct* new_entry = new TableEntryStruct();
    new_entry->name = name;
    new_entry->Fields = fields_list;
    new_entry->type = type;
    scope_table.push_back(new_entry);
    return true;
}