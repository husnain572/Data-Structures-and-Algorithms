#include <iostream>
#include <stack>
using namespace std;

// Stack Implementation using STL stack
int main() {
    stack<int> s;

    s.push(5);
    s.push(6);
    s.push(7);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
