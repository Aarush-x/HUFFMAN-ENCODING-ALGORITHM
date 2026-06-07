/*
 * Group Number: 2
 * Project Title: Huffman Encoding Algorithm
 * Programmer: Aarush Muralinathan (Student 1)
 * Assignment/Role: Data Structure Design, Linked List algorithms, main(), menu(), and file I/O.
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;  // Initialize size
}

// Insert a tree node into the list sorted by frequency
void LinkedList::insertSorted(TreeNode* root) {
    ListNode* newNode = new ListNode(root);

    // If list is empty or new node has smaller frequency than head
    if (head == nullptr || head->treeRoot->data.getFrequency() > root->data.getFrequency()) {
        newNode->next = head;
        head = newNode;
    } else {
        // Find the right spot to insert
        ListNode* current = head;
        while (current->next != nullptr && 
               current->next->treeRoot->data.getFrequency() <= root->data.getFrequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;  // Increment size when adding a node
}

// Just for testing our Week 3 deliverable
void LinkedList::printList() {
    ListNode* current = head;
    cout << "Linked List (Sorted by Frequency): ";
    while (current != nullptr) {
        cout << "(" << current->treeRoot->data.getCharacter() << ", " 
             << current->treeRoot->data.getFrequency() << ") -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

//pop front
TreeNode* LinkedList::popFront() {
    if (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        TreeNode* ret = temp->treeRoot;
        delete temp;
        size--;  // Decrement size when removing a node
        return ret;
    }
    return nullptr;
}

//get size
int LinkedList::getSize() {
    return size;
}

//get front
TreeNode* LinkedList::getFront() {
    if (head != nullptr) {
        return head->treeRoot;
    }
    return nullptr;
}
