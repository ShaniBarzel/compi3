//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_SYMTABLE_H
#define COMPI3_SYMTABLE_H

#include <string>
#include <vector>
#include "attributes.h"

class TableEntry;
class TableEntryVariable;
class TableEntryFunc;
class SymbolTable;

class TableEntry{
public:
    std::string name;
    typeName type;
    int size;
    int offset;

};

class TableEntryVariable : public TableEntry{
};
class TableEntryStruct : public TableEntry{
public:
    std::string name;
    typeName type;
    std::vector<StructMemNode> Fields;

};
class TableEntryFunc : public TableEntry{
public:
    std::string name;
    typeName return_type;
    std::vector<FormalDeclNode> declaration_list;
};

/*
 * each symbol table is a node in the tree
 */
class SymbolTable {
    /*
     * remark(racheli): we don't need to have a scope_offset field since the current scope's offset is accessible
     * from the top of the offsets stack
     */
    //parent_table is the father of the current node in the symbol tables tree
    SymbolTable* parent_table;
    //scope_table is vector representing the current scope's symbol table
    std::vector<TableEntry*> scope_table;

public:
    /*
     * c'tor
     * creates a new scope table which is the son of p
     */
    SymbolTable(SymbolTable* p) : parent_table(p), scope_table(){};
    /*
        * getEntry
        * checks if a table entry whose name field is "name" already exists
        * if yes - returns it, else - returns null
    */
    TableEntry* getEntry(std::string name);
    /*
     * insertVariableEntry
     * inserts an entry of a variable to the table
     * returns true if succeeds
     */
    bool insertVariableEntry(std::string name, typeName type, int offset);
    /*
  * insertFunctionEntry
  * inserts an entry of a function to the table
  * returns true if succeeds
  */
    bool insertFunctionEntry(std::string name, typeName return_type, std::vector<FormalDeclNode> dec_list);
    /*
* insertStructEntry
* inserts an entry of a struct to the table
* returns true if succeeds
*/
    bool insertStructEntry(std::string name, typeName type, std::vector<StructMemNode> fields_list);

};

#endif //COMPI3_SYMTABLE_H
