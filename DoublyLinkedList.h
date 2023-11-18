#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Key.h"

class Node {
public:
    Key data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList();
    ~DoublyLinkedList();
    void addNode(Key data);
    void display();
    void clearMemory();
};

#endif
