#include "MenuYCarga.h"
#include "DoublyLinkedList.h"
#include "Hash.h"
#include <iostream>

// Función para realizar una búsqueda binaria en la lista
Node* binarySearch(DoublyLinkedList& list, std::string key) {
    Node* start = list.head;
    Node* end = list.tail;

    while (start != NULL && end != NULL && start != end->next && end != start->prev) {
        Node* mid = start;
        Node* temp = start;
        int count = 0;
        int midCount = 0;

        while (temp != end) {
            count++;
            temp = temp->next;
        }

        midCount = count / 2;
        while (midCount--) {
            mid = mid->next;
        }

        if (mid->data.key == key) {
            return mid;
        } else if (mid->data.key < key) {
            start = mid->next;
        } else {
            end = mid->prev;
        }
    }

    return NULL;
}

std::vector<Node*> sequentialSearch(DoublyLinkedList& list, std::string value) {
    std::vector<Node*> results;
    Node* temp = list.head;
    while (temp != NULL) {
        for (const auto& val : temp->data.values) {
            if (val == value) {
                results.push_back(temp);
                break;
            }
        }
        temp = temp->next;
    }
    return results;
}
int main() {
    DoublyLinkedList list;
    std::string filename = "datos.txt";
    MenuYCarga::loadData(list, filename);
    std::string key;
    Node* result;

    while (true) {
        std::cout << "1. Cargar más datos\n";
        std::cout << "2. Buscar datos por llave\n";
        std::cout << "3. Buscar datos por valor\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opción: ";
        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Ingrese la ruta del archivo: ";
                std::cin >> filename;
                MenuYCarga::loadData(list, filename);
                break;
            }
            case 2: {
                std::cout << "Ingrese la llave a buscar: ";
                std::cin >> key;
                result = binarySearch(list, Hash::hashFunction(key));
                if (result != NULL) {
                    std::cout << "Datos encontrados: ";
                    for (const auto& value : result->data.values) {
                        std::cout << value << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "No se encontraron datos con esa llave\n";
                }
                break;
            }
            case 3: {
                std::string value;
                std::cout << "Ingrese el valor a buscar: ";
                std::cin >> value;
                std::vector<Node*> results = sequentialSearch(list, value);
                if (!results.empty()) {
                    std::cout << "Datos encontrados: \n";
                    for (const auto& node : results) {
                        for (const auto& val : node->data.values) {
                            std::cout << val << " ";
                        }
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "No se encontraron datos con ese valor\n";
                }
                break;
            }
            case 4:
                return 0;
            default:
                std::cout << "Opción no válida\n";
        }
    }

    return 0;
}
