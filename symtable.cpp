//
// Created by Racheli on 12/3/2018.
//
#include "symtable.h"
//#include <iostream>
/*
    * remark (racheli): I didn't want to unite all the "doesExist" functions to one because
    * then we wouldve needed a struct to wrap the two entries and it complicates things
 */
TableEntry* SymbolTable::getEntry(std::string name) {
    for (std::vector<TableEntry *>::const_iterator it = scope_table->begin(), end = scope_table->end();
         it != end; ++it) {
        if ((*it)->name == name){
            TableEntry* res = new TableEntry();
            res = *it;
            return res;
        }
    }
    if(!parent_table)
        return NULL;
    return parent_table->getEntry(name);
}

bool SymbolTable::insertVariableEntry(std::string name, typeName type, int offset, int f_offset){
    //check if an entry for variable to be inserted already exists in some scope table in the tree
    if(getEntry(name)) //entry already exist
        return false;
    //the new entry of the variable to be inserted to the table
    TableEntryVariable* new_entry = new TableEntryVariable();
    new_entry->name = name;
    new_entry->type = type;
    new_entry->offset = offset;
    new_entry->size =1;
    new_entry->f_offset=f_offset; //sn
    //insertion to table of current scope
    scope_table->push_back(new_entry);
    return true;
}

bool SymbolTable::insertStructTypeEntry(std::string name, std::string s_name, typeName type, int size, int offset, int f_offset){
    //check if an entry for variable to be inserted already exists in some scope table in the tree
    if(getEntry(name)) //entry already exist
        return false;
    //the new entry of the variable to be inserted to the table
    TableEntryStructType* new_entry = new TableEntryStructType();
    new_entry->name = name;
    new_entry->type = type;
    new_entry->structName = s_name;
    new_entry->size = size;
    //insertion to table of current scope
    new_entry->offset = offset;
    new_entry->f_offset=f_offset;//sn
    scope_table->push_back(new_entry);
    return true;
}

bool SymbolTable::insertFunctionEntry(std::string name, typeName return_type,int frame) {
    if(getEntry(name)) //entry already exist
        return false;
    TableEntryFunc* new_entry = new TableEntryFunc();
    new_entry->type = TYPE_FUNC;
    new_entry->name = name;
    new_entry->return_type = return_type;
    scope_table->push_back(new_entry);
    new_entry->f_offset=frame; //sn
    return true;
}

bool SymbolTable::insertStructEntry(std::string name, typeName type, StructMemListNode* fields_list,int size) {
    if(getEntry(name))
        return false; //entry alredy exist
    TableEntryStruct* new_entry = new TableEntryStruct();
    new_entry->name = name;
    new_entry->Fields = fields_list;
    new_entry->type = type;
    new_entry->size = size;
    scope_table->push_back(new_entry);
    return true;
}

StructMemNode* TableEntryStruct::getField(std::string name){
    for (std::vector<StructMemNode*>::iterator it = Fields->s_list->begin(), end = Fields->s_list->end();
         it != end; ++it) {
        if (((*it)->name) == name)
            return *it;
    }
    return NULL;
}

TableEntryFunc* SymbolTable::getLastFunctionEntry() {

    for (std::vector<TableEntry *>::reverse_iterator it = scope_table->rbegin();
         it != scope_table->rend(); ++it) {

        if ((*it)->type == TYPE_FUNC)
        {
            return (TableEntryFunc *) *it;
        }
    }

    if(!parent_table)
        return NULL;
    return parent_table->getLastFunctionEntry();

}

bool TableEntryFunc::compareArgumentTypes(std::vector<ExpNode*>* args) {
    //compare sizes of lists
    if (args->size() != declaration_list->size())
        return false;
    //set iterators of both lists
    std::vector<ExpNode *>::const_iterator it_a = args->begin();
    std::vector<FormalDeclNode *>::reverse_iterator it_b = declaration_list->rbegin();
    for (int i = 0; i < args->size(); i++) {
        if ((*it_a) && (*it_b) && (*it_a)->type != (*it_b)->type) {
            //an assignment of byte to int is allowed
            if ((*it_a) && (*it_b) && ((*it_a)->type == TYPE_STRUCTID)) {
                if ((*it_b)->s_name != (*it_a)->s_name) {
                    return false;
                }

            } else if ((*it_a)->type != (*it_b)->type) {
                if (!((*it_b)->type == TYPE_INT && (*it_a)->type == TYPE_BYTE))
                    return false;
            }
        }
        it_a++;
        it_b++;
    }
        return true;

}