#include <iostream>
#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    // set the current nodes to nullptr
    smaller = nullptr;
    larger = nullptr;

    // Base case
    if (head == nullptr){
        return;
    }

    // Store the head node in a temp variable and move the head to the next node
    Node* temp = head;
    head = head -> next;
    temp -> next = nullptr;

    // If the value is less than or equal to the pivot, add it to the smaller list
    if (temp->val <= pivot){
        smaller = temp;
        llpivot(head, smaller->next, larger, pivot);
    }
    // If the value is greater than the pivot, add it to the larger list
    else {
        larger = temp;
        llpivot(head, smaller, larger->next, pivot);
    }
}
