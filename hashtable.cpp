/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#include "hashtable.h"

/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/

HashTable::HashTable(unsigned long* num_entries, unsigned long* associativity){
    cacheSize = *num_entries/(*associativity);
    cachetable = new LinkedList*[cacheSize];
    for(int i = 0; i < cacheSize; i++){
        cachetable[i] = new LinkedList(associativity);
        }
    }

HashTable::~HashTable(){
    for(int i = 0; i < cacheSize; i++){
        delete cachetable[i];
    }
}

/*********************************
PRIVATE
*********************************/

int HashTable::hash(int tag){
    return tag % cacheSize;
}

/*********************************
PUBLIC
*********************************/

bool HashTable::seachFill(int tag){
    bool found = false;
    int index = hash(tag);
    if(cachetable[index]->findTag(tag)){
        found = true;
    }
    return found;
}