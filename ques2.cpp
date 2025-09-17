#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// helper to insert at end (for quick testing)
void insertEnd(int val) {
    Node* temp = new Node{val, nullptr};
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

int deleteKeyOccurrences(int key) {
    int count = 0;

    // Remove key nodes from the start
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }

    // Remove key nodes from the rest
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* t = curr->next;
            curr->next = t->next;
            delete t;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void display() {
    Node* p = head;
    while (p) { cout << p->data; if (p->next) cout << "->"; p = p->next; }
    cout << "\n";
}

int main() {
    // Build sample list: 1->2->1->2->1->3->1
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertEnd(x);

    cout << "Original List: ";
    display();

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    int count = deleteKeyOccurrences(key);
    cout << "Count: " << count << "\n";

    cout << "Updated Linked List: ";
    display();

    return 0;
}
