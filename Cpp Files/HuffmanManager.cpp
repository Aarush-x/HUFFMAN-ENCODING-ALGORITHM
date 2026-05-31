#include <iostream>
#include "HuffmanManager.h"
#include <fstream>

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

// Traverses the tree. Goes left = add "0", goes right = add "1"
void HuffmanManager::generateCodesRecursive(TreeNode* node, string code) {
    if (node == nullptr) return;

    // If it's a leaf node, store the code
    if (node->left == nullptr && node->right == nullptr) {
        huffmanCodes[(unsigned char)node->data.getCharacter()] = code;
    }

    // Traverse left and right children
    generateCodesRecursive(node->left, code + "0");
    generateCodesRecursive(node->right, code + "1");
}

void HuffmanManager::generateHuffmanCodes() {
    if (huffmanTreeRoot == nullptr) {
        cout << "Huffman tree not built yet. Cannot generate codes.\n";
    } else {
        generateCodesRecursive(huffmanTreeRoot, "");
    }
}

// Converts a character to its 8-bit binary string representation
string HuffmanManager::characterToBinaryString(char c) {
    string binaryString = "";
    for (int i = 7; i >= 0; i--) {
        binaryString += ((c >> i) & 1) ? '1' : '0';
    }
    return binaryString;
}

void HuffmanManager::encodeFile(string inputFile, string outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        string code = huffmanCodes[(unsigned char)ch];
        outFile << characterToBinaryString(ch) << " " << code << endl;
    }

    inFile.close();
    outFile.close();
    cout << "File encoded successfully to " << outputFile << endl;
}

void HuffmanManager::decodeFile(string inputFile, string outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || huffmanTreeRoot == nullptr || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    char ch;
    TreeNode* currentNode = huffmanTreeRoot;
    while (inFile.get(ch)) {
        // Check if currentNode is valid before dereferencing
        if (currentNode == nullptr) {
            cout << "Error: Invalid encoded data detected!" << endl;
            break;
        }

        if (ch == '0') {
            currentNode = currentNode->left;
        }
        else if (ch == '1') {
            currentNode = currentNode->right;
        }

        // Check if currentNode is valid before dereferencing
        if (currentNode != nullptr && currentNode->left == nullptr && currentNode->right == nullptr) {
            outFile << currentNode->data.getCharacter();
            currentNode = huffmanTreeRoot; // Reset for the next character
        }
    }

    inFile.close();
    outFile.close();
    cout << "File decoded successfully to " << outputFile << endl;
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
        else if (choice == 3) {
            generateHuffmanCodes();
            cout << "\nHuffman Codes:\n";
            for (int i = 0; i < 256; i++) {
                if (!huffmanCodes[i].empty()) {
                    cout << "'" << (char)i << "' : " << huffmanCodes[i] << "\n";
                }
            }
            
        } 
        else if (choice == 4) {
            char c;
            cout << "Enter a character: ";
            cin >> c;
            cout << "Huffman code for '" << c << "': " << huffmanCodes[(unsigned char)c] << "\n";
        } 
        else if (choice == 5) {
            string word;
            cout << "Enter a word: ";
            cin >> word;
            cout << "ASCII Binary: ";
            for (int i = 0; i < word.length(); i++) {
                cout << characterToBinaryString(word[i]) << " ";
            }
            cout << "\nHuffman Binary: ";
            for (int i = 0; i < word.length(); i++) {
                cout << huffmanCodes[(unsigned char)word[i]] << " ";
            }
            cout << "\n";
        } 
        else if (choice == 6) {
            string inputFile, outputFile;
            cout << "Enter input file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            encodeFile(inputFile, outputFile);
        } 
        else if (choice == 7) {
            string inputFile, outputFile;
            cout << "Enter input file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            decodeFile(inputFile, outputFile);
        }
        else if (choice == 8) {
            cout << "Exiting program...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}