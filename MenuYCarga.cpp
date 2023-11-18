#include "MenuYCarga.h" //Se incluye el .h
#include <fstream>
#include <sstream>

// Función para cargar datos desde un archivo a la lista doblemente enlazada

void MenuYCarga::loadData(DoublyLinkedList& list, const std::string& filename) {
    // Abre el archivo proporcionado

    std::ifstream file(filename);
    std::string line;
    // Lee cada línea del archivo

    while (getline(file, line)) {
        // Crea un objeto Key para almacenar los datos

        Key data;

        // Utiliza un stringstream para dividir la línea en elementos separados por comas

        std::stringstream ss(line);
        std::string item;
        getline(ss, item, ',');
        data.key = item;
        // Lee cada valor y lo agrega al vector de valores en el objeto Key

        while (getline(ss, item, ',')) {
            data.values.push_back(item);
        }
        // Agrega el objeto Key a la lista doblemente enlazada

        list.addNode(data);
    }
    // Cierra el archivo

    file.close();
}
