/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include "linkedlist.h"

using std::cout;
using std::endl;

class HashTable {

public:
    HashTable(unsigned long*, unsigned long*);
    ~HashTable();
    bool seachFill(int);

private:
    int hash(int);
    unsigned long cacheSize;
    unsigned long cacheDepth;
    LinkedList **cachetable;
    int count; 


};

#endif //HASH_TABLE_H