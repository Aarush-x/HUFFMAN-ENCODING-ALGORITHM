#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "HuffmanStructures.h"

class LinkedList {
private:
    ListNode* head;
	int size; // Keep track of the size of the list 

public:
    LinkedList();
    void insertSorted(TreeNode* root);
    void printList();
    TreeNode* popFront();
	int getSize();
    TreeNode* getFront();
};

#endif