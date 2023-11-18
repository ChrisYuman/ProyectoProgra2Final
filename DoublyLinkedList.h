#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Key.h"
// Definición de la clase Node que representa un nodo en la lista

class Node {
public:
    Key data;
    Node* next;
    Node* prev;
};
// Definición de la clase DoublyLinkedList que representa una lista doblemente enlazada

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    // Constructores y destructor

    DoublyLinkedList();
    ~DoublyLinkedList();
    // Funciones para manipular la lista

    void addNode(Key data);
    void display();
    void clearMemory();
};

#endif
