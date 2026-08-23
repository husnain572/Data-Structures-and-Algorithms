#include <iostream>
#include <vector>
using namespace std;

// Stack Implementation using Vector
template <class T>
class Stack {
public:
    vector<T> v;

    // Push element onto stack
    void push(T val) {
        v.push_back(val);
    }

    // Remove top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        v.pop_back();
    }

    // Return top element
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return v[v.size() - 1];
    }

    // Check whether stack is empty
    bool isEmpty() {
        return v.size() == 0;
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
