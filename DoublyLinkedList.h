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
    ~DoublyLinkedList(); // Agregar un destructor para liberar la memoria al destruir el objeto
    void addNode(Key data);
    void display();
    void clearMemory(); // Declarar la función clearMemory
};

#endif
