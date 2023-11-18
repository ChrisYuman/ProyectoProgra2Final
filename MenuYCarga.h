#ifndef MENUYCARGA_H
#define MENUYCARGA_H

#include "DoublyLinkedList.h" //Se incluye el .h
#include <string>

class MenuYCarga {
public:
    // Declaración de la función para cargar datos desde un archivo

    static void loadData(DoublyLinkedList& list, const std::string& filename);
};

#endif
