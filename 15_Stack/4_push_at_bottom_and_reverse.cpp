#include <iostream>
#include <stack>
using namespace std;

// Push an element at the bottom of the stack using recursion
void pushAtBottom(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, val);

    s.push(temp);
}

// Reverse a stack using recursion
void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();

    reverseStack(s);

    pushAtBottom(s, temp);
}

// Print stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main() {
    stack<int> s;

    s.push(5);
    s.push(6);
    s.push(7);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
