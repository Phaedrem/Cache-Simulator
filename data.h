/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#ifndef DATA_H
#define DATA_H

struct Data {
    int validBit; 
    int tag; 
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

