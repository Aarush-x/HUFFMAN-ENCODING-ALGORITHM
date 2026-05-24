#include <iostream>
#include "HuffmanManager.h"

using namespace std;

HuffmanManager::HuffmanManager() {
    // Initialize the array with zeros
    for (int i = 0; i < 256; i++) {
        frequencyArray[i] = 0;
    }
    huffmanTreeRoot = nullptr;
}

void HuffmanManager::countFrequencies(string text) {
    // Reset array first
    for (int i = 0; i < 256; i++) {
        frequencyArray[i] = 0;
    }
    // Count using ASCII values as the array index
    for (int i = 0; i < text.length(); i++) {
        frequencyArray[(unsigned char)text[i]]++;
    }
}

void HuffmanManager::printFrequencies() {
    cout << "\nCharacter Frequencies:\n";
    for (int i = 0; i < 256; i++) {
        if (frequencyArray[i] > 0) {
            cout << "'" << (char)i << "' : " << frequencyArray[i] << "\n";
        }
    }
}

void HuffmanManager::buildHuffmanTree() {
    while (list.getSize() > 1) {
        TreeNode* left = list.popFront();
        TreeNode* right = list.popFront();

        int combinedFreq = left->data.getFrequency() + right->data.getFrequency();

        HuffmanData internalData('\0', combinedFreq); // Internal node has no character
        TreeNode* internalNode = new TreeNode(internalData);

        internalNode->left = left;
        internalNode->right = right;

        list.insertSorted(internalNode);
	}

    huffmanTreeRoot = list.getFront();
}

void HuffmanManager::printTreeRecursive(TreeNode* node, int space) {
    if (node == nullptr) return;
    // Increase distance between levels
    space += 5;
    // Process right child first
    printTreeRecursive(node->right, space);
    // Print current node after space count
    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    if (node->data.getCharacter() != '\0') {
        cout << "'" << node->data.getCharacter() << "' (" << node->data.getFrequency() << ")\n";
    } else {
        cout << "* (" << node->data.getFrequency() << ")\n"; // Internal node
    }
    // Process left child
    printTreeRecursive(node->left, space);
}

void HuffmanManager::printHuffmanTree() {
    if (huffmanTreeRoot == nullptr) {
        cout << "Huffman tree not built yet.\n";
    } else {
        printTreeRecursive(huffmanTreeRoot, 0);
	}
}

void HuffmanManager::runMenu() {
    int choice = 0; // Initialize to 0 so the while loop runs the first time
    string dummyText = "Mississippi"; // Hardcoded just to show Week 3 output
    
    // Build the frequency array and linked list for our test output
    countFrequencies(dummyText);
    for (int i = 0; i < 256; i++) {
        if (frequencyArray[i] > 0) {
            HuffmanData hd((char)i, frequencyArray[i]);
            TreeNode* newNode = new TreeNode(hd);
            list.insertSorted(newNode);
        }
    }

    while (choice != 8) {
        cout << "\n--- Huffman Encoding Menu ---\n";
        cout << "1. Print the character weights (frequencies)\n";
        cout << "2. Print Tree (Right-Root-Left)\n";
        cout << "3. Print the Huffman codes\n";
        cout << "4. Enter one character to get its code\n";
        cout << "5. Enter a word to get ASCII and Huffman binary\n";
        cout << "6. Encode a file\n";
        cout << "7. Decode a file\n";
        cout << "8. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            printFrequencies();
            cout << "\n";
            list.printList();
        } 
        else if (choice == 2) {
            buildHuffmanTree();
            printHuffmanTree();
        } 
        else if (choice >= 3 && choice <= 7) {
            cout << "\n[Module under construction]\n";
        } 
        else if (choice == 8) {
            cout << "Exiting program...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}