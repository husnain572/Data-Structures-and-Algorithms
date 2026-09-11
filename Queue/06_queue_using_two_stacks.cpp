// Queue implementation using two stacks
#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data) {
        // Move everything from s1 -> s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        // Move everything back s2 -> s1, so the new element sits at the bottom
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        s1.pop();
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
