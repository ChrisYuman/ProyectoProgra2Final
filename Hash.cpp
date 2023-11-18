// Hash.cpp
#include "Hash.h"

std::string Hash::hashFunction(const std::string& key) {
    const int prime = 31;
    long long hashValue = 0;

    for (char ch : key) {
        hashValue = (hashValue * prime + ch) % INT_MAX;
    }

    return std::to_string(hashValue);
}