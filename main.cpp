#include "MenuYCarga.h"
#include "DoublyLinkedList.h"
#include "Hash.h"
#include <iostream>

// Función para realizar una búsqueda binaria en la lista
std::vector<Node*> binarySearch(DoublyLinkedList& list, std::string key) {
    std::vector<Node*> results;
    Node* temp = list.head;

    while (temp != nullptr) {
        if (temp->data.key == key) {
            results.push_back(temp);
        }
        temp = temp->next;
    }

    return results;
}


// Función para realizar una búsqueda sequencial en la lista

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

    std::cout << "Bienvenido al proyecto de busqueda de llaves y datos. Por Christopher Yuman" << std::endl;
    std::cout << "                                                                                   \n";
    std::cout << "                                                                                   \n";
    std::cout << "                                                                                   \n";
    std::cout << "              +=================================*-                               \n";
    std::cout << "              *.::..............................**+                              \n";
    std::cout << "              *...:::::::.......................*++*:                            \n";
    std::cout << "              *...:::::::::.:.....:::...........*===*=                           \n";
    std::cout << "              *..:-------------::::::...........*====+*.                         \n";
    std::cout << "              *..-#+++++++++++++-+++++++++++++++#======*=                        \n";
    std::cout << "              *..:*-========--=+=*****+*********%*******#*                       \n";
    std::cout << "              *..-*--=======--=+:::::::..........:::.....*.                      \n";
    std::cout << "              *..:*--======---=+-+++++++++++++++++==++-..*.                      \n";
    std::cout << "              *..-*--======---=*=#************++******+..*.                      \n";
    std::cout << "              *..-*---====----=+::::::::.::..............*.                      \n";
    std::cout << "              *..-*---===-----=+:=====================-..*.                      \n";
    std::cout << "              *..:*---=-====--=*=#************++******+..*.                      \n";
    std::cout << "              *..:*---======--=*::::::::::::::::::::::...*.                      \n";
    std::cout << "              *..-*--=======--=+:=================----:..*.                      \n";
    std::cout << "              *..:*---=========+=#********************+..*.                      \n";
    std::cout << "              *..:#************+:----------::::::::::::..*.                      \n";
    std::cout << "              *..............::::::::::::::::............*.                      \n";
    std::cout << "              *...------------------------------------:..*.                      \n";
    std::cout << "              *..:#************************************..*.                      \n";
    std::cout << "              *...------------------------------------:..*.                      \n";
    std::cout << "              *...::::::::::::---------------::::::::::..*.                      \n";
    std::cout << "              *..:%*****************************+******..*.                      \n";
    std::cout << "              *...---------=-=================---=----:..*.                      \n";
    std::cout << "              *..............::::::::::::::::::..........*.                      \n";
    std::cout << "              *........:*+++++++++++++++++++++++=........*.                      \n";
    std::cout << "              *........-*=====---=--------------*........*.                      \n";
    std::cout << "              *........-*-==================---=*........*.                      \n";
    std::cout << "              *........-*--=====================*::......*.                      \n";
    std::cout << "              *........-*-----=---------========*:::.....*.                      \n";
    std::cout << "              *........-#+++++++++++++++++++++++*::::....*.                      \n";
    std::cout << "              *.........:::::::::::::::::::::::::::::....*.                      \n";
    std::cout << "              *...............................::..:::::..*.                      \n";
    std::cout << "              *.......................................:::*.                      \n";
    std::cout << "              ===========================================+                       \n";
    std::cout << "                                                                                   \n";

    DoublyLinkedList list;
    std::string filename;
    std::string key;
    std::vector<Node*> results;

    // Preguntar primero por la carga de datos

    std::cout << "Ingrese la ruta del archivo: ";
    std::cin >> filename;
    MenuYCarga::loadData(list, filename);
    std::cout << "Datos cargados exitosamente.\n";

    while (true) {
        std::cout << "1. Cargar mas datos\n";
        std::cout << "2. Buscar datos por llave\n";
        std::cout << "3. Buscar datos por valor\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese una opcion: ";

        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Ingrese la ruta del archivo adicional: ";
                std::cin >> filename;
                MenuYCarga::loadData(list, filename);
                std::cout << "Datos cargados exitosamente.\n";
                break;
            }
            case 2: {
                if (list.head == nullptr) {
                    std::cout << "Primero carga datos antes de buscar.\n";
                    break;
                }
                std::cout << "Ingrese la llave a buscar: ";
                std::cin >> key;
                results = binarySearch(list, key);
                if (!results.empty()) {
                    std::cout << "Numero de coincidencias: " << results.size() << "\n";
                    std::cout << "Datos encontrados: \n";
                    for (const auto& node : results) {
                        for (const auto& val : node->data.values) {
                            std::cout << val << " ";
                        }
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "No se encontraron datos con esa llave\n";
                }
                break;
            }
            case 3: {
                if (list.head == nullptr) {
                    std::cout << "Primero carga datos antes de buscar.\n";
                    break;
                }
                std::string value;
                std::cout << "Ingrese el valor a buscar: ";
                std::cin >> value;
                std::vector<Node*> results = sequentialSearch(list, value);
                if (!results.empty()) {
                    std::cout << "Numero de coincidencias: " << results.size() << "\n";
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
                std::cout << "Opcion no valida\n";
        }
    }

    return 0;
}
