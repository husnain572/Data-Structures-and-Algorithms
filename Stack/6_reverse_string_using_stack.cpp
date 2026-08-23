#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Reverse a string using stack
string reverseString(string str) {
    stack<char> s;

    // Push every character into the stack
    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    string ans;

    // Pop characters to get them in reverse order
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string str = "husnain";

    cout << reverseString(str);

    return 0;
}
