/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "data.h" 

#define INVALID 0
#define VALID 1

using std::cout;
using std::endl;

class LinkedList {

public:
    LinkedList(unsigned long*);
    ~LinkedList();
    bool findTag(int);


private:
    int nodeCount;
    int assoc;
    Node *head;
    Node *tail;
    bool addNode(int, int);
    bool moveNode(Node*);
    bool deleteNode();
    bool clearList();

};

#endif //LINKED_LIST_H