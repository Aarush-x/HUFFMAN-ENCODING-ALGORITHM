#ifndef HUFFMAN_MANAGER_H
#define HUFFMAN_MANAGER_H

#include <string>
#include "LinkedList.h"

class HuffmanManager {
private:
    LinkedList list;
    int frequencyArray[256]; // Replaced hash table with a simple array

public:
    HuffmanManager();
    void countFrequencies(std::string text);
    void printFrequencies();
    void runMenu();
};

#endif