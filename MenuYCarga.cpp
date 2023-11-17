#include "MenuYCarga.h"
#include <fstream>
#include <sstream>

void MenuYCarga::loadData(DoublyLinkedList& list, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        Key data;
        std::stringstream ss(line);
        std::string item;
        getline(ss, item, ',');
        data.key = item;
        while (getline(ss, item, ',')) {
            data.values.push_back(item);
        }
        list.addNode(data);
    }
    file.close();
}
