#include <iostream>
using namespace std;

// Node of Linked List
template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

// Stack Implementation using Linked List
template <class T>
class Stack {
private:
    Node<T>* head;

public:
    Stack() {
        head = NULL;
    }

    // Push element onto stack
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Remove top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    // Return top element
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return head->data;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    Stack<int> s;

    s.push(5);
    s.push(6);
    s.push(7);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
