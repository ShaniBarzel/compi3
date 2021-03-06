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
class TableEntryStructType;
class TableEntryStruct;
class SymbolTable;

class TableEntry {
public:
    std::string name;
    typeName type;
    int size;
    int offset; //scope offset
    int f_offset; //frame offset
    TableEntry(){};
    virtual ~TableEntry(){};

};

class TableEntryVariable : public TableEntry{
};


class TableEntryStruct : public TableEntry{
public:
    StructMemListNode* Fields;
    TableEntryStruct() : TableEntry() , Fields(new StructMemListNode()){};
    virtual ~TableEntryStruct(){delete(Fields);};
    StructMemNode* getField(std::string name);

};

class TableEntryFunc : public TableEntry{
public:
    typeName return_type;
    std::vector<FormalDeclNode*>* declaration_list;
    TableEntryFunc() : TableEntry(), return_type() ,declaration_list(new std::vector<FormalDeclNode*>()){};
    virtual ~TableEntryFunc(){delete(declaration_list);};
    /*
     * compareArgumentTypes
     * compares declaration list to argument list
     * input: an argument list to compare
     */
    bool compareArgumentTypes(std::vector<ExpNode*>* args);
};

class TableEntryStructType : public TableEntry{ //todo: shani
public:
    std::string structName;
};

/*
 * each symbol table is a node in the tree
 */
class SymbolTable {


public:
    /*
 * remark: we don't need to have a scope_offset field since the current scope's offset is accessible
 * from the top of the offsets stack
 */
    //parent_table is the father of the current node in the symbol tables tree
    SymbolTable* parent_table;
    //scope_table is vector representing the current scope's symbol table
    std::vector<TableEntry*>* scope_table;
    /*
     * c'tor
     * creates a new scope table which is the son of p
     */
    SymbolTable(SymbolTable* p) : parent_table(p), scope_table(new std::vector<TableEntry*>()){};
    ~SymbolTable(){delete(scope_table);};
    /*
        * getEntry
        * checks if a table entry whose name field is "name" already exists
        * if yes - returns it, else - returns null
    */
    TableEntry* getEntry(std::string name);

    SymbolTable* getParent(){
        return parent_table;
    }
    /*
    * insertVariableEntry
    * inserts an entry of a variable to the table
    * returns true if succeeds
    */
    bool insertVariableEntry(std::string name, typeName type, int offset,int f_offset);
    /*
  * insertFunctionEntry
  * inserts an entry of a function to the table
  * returns true if succeeds
  */
    bool insertFunctionEntry(std::string name, typeName return_type, int f_offset);
    /*
    * insertStructEntry
    * inserts an entry of a struct to the table
    * returns true if succeeds
    */
    bool insertStructEntry(std::string name, typeName type, StructMemListNode* fields_list,int size);
    /* insertStructTypeEntry
    * inserts an entry of a struct type to the table
    * returns true if succeeds
    */
    bool insertStructTypeEntry(std::string name, std::string s_name, typeName type, int size,int offset,int f_offset);
    /*
     * this function returns the latest function entry in the table
     * if exists - returns it, else - nullptr
     */
    TableEntryFunc* getLastFunctionEntry();
};

#endif //COMPI3_SYMTABLE_H
