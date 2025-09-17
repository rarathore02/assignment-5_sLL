#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;   // start of the list

// 1. Insert at beginning
void insertBegin(int val) {
    Node* temp = new Node{val, head};
    head = temp;
}

// 2. Insert at end
void insertEnd(int val) {
    Node* temp = new Node{val, nullptr};
    if (!head) { head = temp; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

// 3. Insert before a value
void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) { insertBegin(val); return; }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (p->next) p->next = new Node{val, p->next};
    else cout << "Value " << key << " not found\n";
}

// 4. Insert after a value
void insertAfter(int key, int val) {
    Node* p = head;
    while (p && p->data != key) p = p->next;
    if (p) p->next = new Node{val, p->next};
    else cout << "Value " << key << " not found\n";
}

// 5. Delete from beginning
void deleteBegin() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// 6. Delete from end
void deleteEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = nullptr;
}

// 7. Delete specific node
void deleteValue(int key) {
    if (!head) return;
    if (head->data == key) { deleteBegin(); return; }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (p->next) {
        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    } else cout << "Value " << key << " not found\n";
}

// 8. Search node
void search(int key) {
    Node* p = head;
    int pos = 1;
    while (p && p->data != key) { p = p->next; pos++; }
    if (p) cout << "Found at position " << pos << "\n";
    else  cout << "Not found\n";
}

// 9. Display list
void display() {
    Node* p = head;
    while (p) { cout << p->data << " "; p = p->next; }
    cout << "\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1.Insert at Beginning\n2.Insert at End\n"
             << "3.Insert Before a Value\n4.Insert After a Value\n"
             << "5.Delete from Beginning\n6.Delete from End\n"
             << "7.Delete a Specific Value\n8.Search a Value\n"
             << "9.Display\n0.Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Value: "; cin >> val; insertBegin(val); break;
            case 2: cout << "Value: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Insert value: "; cin >> val;
                    cout << "Before which value: "; cin >> key;
                    insertBefore(key,val); break;
            case 4: cout << "Insert value: "; cin >> val;
                    cout << "After which value: "; cin >> key;
                    insertAfter(key,val); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cout << "Delete which value: "; cin >> key;
                    deleteValue(key); break;
            case 8: cout << "Search value: "; cin >> key;
                    search(key); break;
            case 9: display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
