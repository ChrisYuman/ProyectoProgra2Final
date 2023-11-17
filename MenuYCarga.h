#ifndef MENUYCARGA_H
#define MENUYCARGA_H

#include "DoublyLinkedList.h"
#include <string>

class MenuYCarga {
public:
    static void loadData(DoublyLinkedList& list, const std::string& filename);
};

#endif
