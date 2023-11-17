#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

void DoublyLinkedList::addNode(Key data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == NULL) {
        head = newNode;
    }
}

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data.key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
