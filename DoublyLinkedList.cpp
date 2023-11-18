#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    clearMemory(); // Llama a clearMemory en el destructor
}

void DoublyLinkedList::addNode(Key data) {
    try {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error de asignación de memoria: " << e.what() << std::endl;
        std::cerr << "No se pudo agregar el nodo al árbol." << std::endl;

        // Liberar memoria antes de cerrar el programa
        clearMemory();

        // Puedes elegir cerrar el programa o manejar de otra manera según tus necesidades.
        exit(EXIT_FAILURE);
    }
}

void DoublyLinkedList::clearMemory() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data.key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
