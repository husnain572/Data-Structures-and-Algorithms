#include<iostream>
using namespace std;

// Node class representing an individual node in the list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// DoublyList class for managing the list
class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    // Insert node at the front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert node at the back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete node from the front
    void pop_front() {
        if (head == NULL) {
            cout << "Doubly Linked List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // List becomes empty
        }
        delete temp;
    }

    // Delete node from the back
    void pop_back() {
        if (head == NULL) {
            cout << "Doubly Linked List is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL; // List becomes empty
        }
        delete temp;
    }

    // Print the list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function to demonstrate functionality
int main() {
    DoublyList dl1;

    dl1.push_front(3);
    dl1.push_front(2);
    dl1.push_front(1);

    dl1.push_back(4);

    dl1.pop_front(); // Removes 1
    dl1.pop_back();  // Removes 4

    dl1.print();     // Output: 2 <=> 3 <=> NULL

    return 0;
}
