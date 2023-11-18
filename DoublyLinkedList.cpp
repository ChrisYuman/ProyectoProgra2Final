#include "DoublyLinkedList.h"
#include <iostream>
// Constructor: inicializa la lista doblemente enlazada

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}
// Destructor: libera la memoria de la lista

DoublyLinkedList::~DoublyLinkedList() {
    clearMemory();
}

void DoublyLinkedList::addNode(Key data) {
    try {
        // Crea un nuevo nodo y asigna los datos

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        // Actualiza el puntero 'next' del nodo anterior si no es el primer nodo

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        // Actualiza el puntero 'head' si es el primer nodo

        if (head == nullptr) {
            head = newNode;
        }
    } catch (const std::bad_alloc& e) {
        // Manejo de error en caso de fallo en la asignación de memoria

        std::cerr << "Error de asignación de memoria: " << e.what() << std::endl;
        std::cerr << "No se pudo agregar el nodo al árbol." << std::endl;

        // Liberar memoria antes de cerrar el programa
        clearMemory();

    }
}
// Función para liberar la memoria de la lista

void DoublyLinkedList::clearMemory() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}
// Función para mostrar los datos almacenados en la lista

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data.key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
