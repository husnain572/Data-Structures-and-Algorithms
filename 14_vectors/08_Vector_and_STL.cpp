#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

```
// Vector Creation

  vector<int> vec;

vector<int> nums = {5, 2, 8, 1, 4};

vector<int> zeros(5, 0);

// Vector Functions

nums.push_back(10);

nums.pop_back();

cout << "Size: " << nums.size() << endl;

cout << "First: " << nums.front() << endl;

cout << "Last: " << nums.back() << endl;

cout << "Element at index 2: " << nums.at(2) << endl;

// Traversal

for (int x : nums) {
    cout << x << " ";
}

cout << endl;

// Sorting

sort(nums.begin(), nums.end());

// Reverse

reverse(nums.begin(), nums.end());

// Find

auto it = find(nums.begin(), nums.end(), 5);

if (it != nums.end()) {
    cout << "Element found" << endl;
}

// Count

int frequency = count(nums.begin(), nums.end(), 5);

cout << "Frequency: " << frequency << endl;

// Minimum Element

auto minIt = min_element(nums.begin(), nums.end());

cout << "Minimum: " << *minIt << endl;

// Maximum Element

auto maxIt = max_element(nums.begin(), nums.end());

cout << "Maximum: " << *maxIt << endl;

// Sum

int sum = accumulate(nums.begin(), nums.end(), 0);

cout << "Sum: " << sum << endl;

// Fill

fill(nums.begin(), nums.end(), 0);

for (int x : nums) {
    cout << x << " ";
}

cout << endl;

return 0;
```

}
