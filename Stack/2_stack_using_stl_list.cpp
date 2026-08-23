#include <iostream>
#include <list>
using namespace std;

// Stack Implementation using STL List
template <class T>
class Stack {
private:
    list<T> ll;

public:
    // Push element onto stack
    void push(T val) {
        ll.push_front(val);
    }

    // Remove top element
    void pop() {
        ll.pop_front();
    }

    // Return top element
    T top() {
        return ll.front();
    }

    // Check whether stack is empty
    bool isEmpty() {
        return ll.size() == 0;
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
