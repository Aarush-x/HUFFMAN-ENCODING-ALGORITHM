#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

// Insert a tree node into the list sorted by frequency
void LinkedList::insertSorted(TreeNode* root) {
    ListNode* newNode = new ListNode(root);

    // If list is empty or new node has smaller frequency than head
    if (head == nullptr || head->treeRoot->data.getFrequency() >= root->data.getFrequency()) {
        newNode->next = head;
        head = newNode;
    } else {
        // Find the right spot to insert
        ListNode* current = head;
        while (current->next != nullptr && 
               current->next->treeRoot->data.getFrequency() < root->data.getFrequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
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