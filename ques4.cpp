#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Helper to insert at end (for testing)
void insertEnd(int val) {
    Node* temp = new Node{val, nullptr};
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

// Reverse the linked list
void reverseList() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    head = prev;             // new head
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    // Build sample list: 1->2->3->4->NULL
    int arr[] = {1,2,3,4};
    for (int x : arr) insertEnd(x);

    cout << "Original List: ";
    display();

    reverseList();

    cout << "Reversed List: ";
    display();

    return 0;
}
