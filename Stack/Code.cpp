//  Custom Stack Using `std::vector`

#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;
public:
    void push(int val) {       // O(1)
        v.push_back(val);
    }
    void pop() {               // O(1)
        v.pop_back();
    }
    int top() {                // O(1)
        return v.back();
    }
    bool empty() {             // O(1)
        return v.empty();
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(12);
    s.push(14);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

// Custom Stack Using `std::list`

#include <iostream>
#include <list>
using namespace std;

class Stack {
    list<int> ll;
public:
    void push(int val) {       // O(1)
        ll.push_front(val);
    }
    void pop() {               // O(1)
        ll.pop_front();
    }
    int top() {                // O(1)
        return ll.front();
    }
    bool empty() {             // O(1)
        return ll.empty();
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(12);
    s.push(14);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

//  Stack Using STL `std::stack`

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(5);
    s.push(12);
    s.push(14);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
