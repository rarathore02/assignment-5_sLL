#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Helper to insert at end for testing
void insertEnd(int val) {
    Node* temp = new Node{val, nullptr};
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

int findMiddle() {
    if (!head) { throw runtime_error("List is empty"); }

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // When fast reaches end, slow is at middle
    return slow->data;
}

void display() {
    Node* p = head;
    while (p) { cout << p->data; if (p->next) cout << "->"; p = p->next; }
    cout << "\n";
}

int main() {
    // Build sample list: 1->2->3->4->5
    int arr[] = {1,2,3,4,5};
    for (int x : arr) insertEnd(x);

    cout << "Linked List: ";
    display();

    try {
        cout << "Middle Element: " << findMiddle() << "\n";
    } catch (exception& e) {
        cout << e.what() << "\n";
    }

    return 0;
}
