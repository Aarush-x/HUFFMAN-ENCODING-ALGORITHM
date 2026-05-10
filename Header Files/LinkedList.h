#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "HuffmanStructures.h"

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList();
    void insertSorted(TreeNode* root);
    void printList();
};

#endif