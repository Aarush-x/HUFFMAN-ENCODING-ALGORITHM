/*
 * Group Number: 2
 * Project Title: Huffman Encoding Algorithm
 * Programmer: Zhen Huey Lee (Student 2)
 * Assignment/Role: Data Structure Design, Binary Tree algorithms, and Hash Table (frequency) algorithms.
 */
#ifndef HUFFMAN_STRUCTURES_H
#define HUFFMAN_STRUCTURES_H

// Class to hold the character and its frequency
class HuffmanData {
private:
    char character;
    int frequency;

public:
    HuffmanData() {
        character = '\0';
        frequency = 0;
    }
    
    HuffmanData(char c, int f) {
        character = c;
        frequency = f;
    }

    char getCharacter() { return character; }
    int getFrequency() { return frequency; }
};

// Node for the binary tree (Week 7 stuff will go here later)
class TreeNode {
public:
    HuffmanData data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(HuffmanData d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Node for the linked list
class ListNode {
public:
    TreeNode* treeRoot;
    ListNode* next;

    ListNode(TreeNode* root) {
        treeRoot = root;
        next = nullptr;
    }
};

#endif
