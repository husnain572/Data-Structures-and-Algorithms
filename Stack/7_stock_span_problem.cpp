#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Stock Span Problem
void stockSpanProblem(vector<int> stock, vector<int>& span) {
    stack<int> s;

    // First day's span is always 1
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];

        // Remove all smaller/equal prices
        while (!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }

        // If no greater price exists on the left
        if (s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }

        // Store current index
        s.push(i);
    }

    // Print stock spans
    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size());

    stockSpanProblem(stock, span);

    return 0;
}
