#ifndef HUFFMAN_MANAGER_H
#define HUFFMAN_MANAGER_H

#include <string>
#include "LinkedList.h"

class HuffmanManager {
private:
    LinkedList list;
    int frequencyArray[256]; // Replaced hash table with a simple array
	TreeNode* huffmanTreeRoot; // This will hold the root of the Huffman tree once built

	void printTreeRecursive(TreeNode* node, int space);

public:
    HuffmanManager();
    void countFrequencies(std::string text);
    void printFrequencies();
    void buildHuffmanTree();
    void printHuffmanTree();
    void runMenu();
};

#endif