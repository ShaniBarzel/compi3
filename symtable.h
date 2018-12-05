//
// Created by Racheli on 12/3/2018.
//

#ifndef COMPI3_SYMTABLE_H
#define COMPI3_SYMTABLE_H

#include <string>
#include <vector>
#include "attributes.h"

class TableEntry;
class TableEntryFunc;
class SymbolTable;
//class SymbolTablesTree;

class TableEntry { //todo : shani: i changed it to class
public:
    std::string name;
    typeName type;
    std::string sTypeName; //only if the type is StructType
    int size;
    int offset;
    std::vector<IdNode> Fields; //for struct entry only
};
class TableEntryFunc{ //todo : shani: i changed it to class
public:
    std::string name;
    typeName return_type;
    std::list<FormalDecl> declaration_list;
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
    //variables_scope_table is vector representing the current scope's symbol table of variables
    std::vector<TableEntry*> variables_scope_table;
    //functions_scope_table is vector representing the current scope's symbol table of functions
    std::vector<TableEntryFunc*> functions_scope_table;
public:
    /*
     * c'tor
     * creates a new scope table which is the son of p
     */
    SymbolTable(SymbolTable* p) : parent_table(p), variables_scope_table(), functions_scope_table(){};
    /*
        * getVariableEntry
        * checks if a variable table entry whose name field is "name" already exists
        * if yes - returns it, else - returns null
    */
    TableEntry* getVariableEntry(std::string name);
    /*
        * getFunctionEntry
        * checks if a function table entry whose name field is "name" already exists
        * if yes - returns it, else - returns null
    */
    TableEntryFunc* getFunctionEntry(std::string name);

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
    bool insertFunctionEntry(std::string name, typeName return_type, std::list<FormalDecl> dec_list);
};

#endif //COMPI3_SYMTABLE_H
