/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#include "linkedlist.h"


/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/

LinkedList::LinkedList(unsigned long* associativity){
    head = NULL; 
    tail = NULL;
    nodeCount = INVALID;
    assoc = *associativity;
    for(int i = 0; i < assoc; i++){
        addNode(INVALID,INVALID);
    }

}

LinkedList::~LinkedList(){
    clearList(); 
}



/*********************************
PRIVATE
*********************************/

bool LinkedList::addNode(int tag, int validBit){
    bool success = false;
    if(nodeCount < assoc){
        Node *newNode = new Node;
        newNode->data.validBit = INVALID;
        newNode->data.tag = tag;
        if(head == NULL){
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
            success = true;
        }else{
            if(validBit == VALID){
                newNode->data.validBit = VALID;
            }
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            success = true;
        }
        nodeCount++;
    }
    return success;
}

bool LinkedList::moveNode(Node* toMove){
    bool success = false;
    if(toMove != head){
        if(toMove == tail){
            toMove->prev->next = NULL;
            tail = toMove->prev;
        }
        else{
            toMove->next->prev = toMove->prev;
            toMove->prev->next = toMove->next;
        }
        toMove->prev = NULL;
        toMove->next = head;
        head->prev = toMove;
        head = toMove;
        success = true;    
    }
    return success;
}

bool LinkedList::deleteNode(){
    bool success = false;
    if(tail != NULL){
        Node *current = tail;
        tail = current->prev;
        delete current;
        if(tail == NULL){
            head = NULL;
        }else{
            tail->next = NULL;
        }
        success = true;
        nodeCount--;
    }
    return success;
}

bool LinkedList::clearList(){
    bool success = false;
    if(tail != NULL){
        Node *current = tail;
        while(current != NULL){
            tail = current->prev;
            delete current;
            current = tail;
            nodeCount--;
        }
        head = NULL;
        tail = NULL;
        success = true;
    }
    return success;
}

/*********************************
PUBLIC
*********************************/


bool LinkedList::findTag(int tag){
    bool success = false;
    Node* current = head;
    while(tag != current->data.tag && current->data.validBit != INVALID && current->next != NULL){
        current = current->next;
    }
    if(tag == current->data.tag && current->data.validBit == VALID){
        moveNode(current);
        success = true;
    }else if(current->data.validBit == INVALID){
        current->data.tag = tag;
        current->data.validBit = VALID;
        moveNode(current);
    }else{
        deleteNode();
        addNode(tag,VALID);
    }

    return success;
} 


