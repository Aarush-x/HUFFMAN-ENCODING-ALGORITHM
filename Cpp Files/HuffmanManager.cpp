#include <iostream>
#include "HuffmanManager.h"

using namespace std;

HuffmanManager::HuffmanManager() {
    // Initialize the array with zeros
    for (int i = 0; i < 256; i++) {
        frequencyArray[i] = 0;
    }
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
            cout << "\n[Tree building and printing module reserved for Week 7]\n";
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