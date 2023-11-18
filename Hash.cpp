// Hash.cpp
#include "Hash.h" //Se incluye el .h

// Función de hash para convertir una clave en un valor hash

std::string Hash::hashFunction(const std::string& key) {
    const int prime = 31;
    long long hashValue = 0;

    // Itera sobre cada carácter de la clave y calcula el valor hash

    for (char ch : key) {
        hashValue = (hashValue * prime + ch) % INT_MAX;
    }
    // Convierte el valor hash a cadena y lo devuelve

    return std::to_string(hashValue);
}