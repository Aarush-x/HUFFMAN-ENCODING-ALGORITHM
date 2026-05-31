#ifndef HUFFMAN_MANAGER_H
#define HUFFMAN_MANAGER_H

#include <string>
#include "LinkedList.h"

class HuffmanManager {
private:
    LinkedList list;
    int frequencyArray[256];
    std::string huffmanCodes[256]; // To store the Huffman codes for each character
	TreeNode* huffmanTreeRoot; // This will hold the root of the Huffman tree once built
	void printTreeRecursive(TreeNode* node, int space);
    void generateCodesRecursive(TreeNode* node, std::string code);
    std::string characterToBinaryString(char c);

public:
    HuffmanManager();
    void countFrequencies(std::string text);
    void printFrequencies();
    void buildHuffmanTree();
    void printHuffmanTree();
    void generateHuffmanCodes();
    void encodeFile(std::string inputFile, std::string outputFile);
    void decodeFile(std::string inputFile, std::string outputFile);
    void runMenu();
};

#endif