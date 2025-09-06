
# Arrays and Vectors – Notes

---

## What is an Array?
An array is a **collection of elements stored at contiguous memory locations**.  
It allows **constant time access by index** and is widely used for storing and processing sequential data.

---

## Array Basics (C++)

### Declaration
```cpp
int arr[5];                     // Uninitialized array of size 5
int arr[] = {1, 2, 3, 4, 5};     // Initialized array
````

### Access & Modification

```cpp
int x = arr[0];   // Access first element
arr[2] = 10;      // Modify element at index 2
```

### Size of Static Array

```cpp
int n = sizeof(arr) / sizeof(arr[0]);
```

---

## Vectors in C++

A `vector` is a **dynamic array** from the C++ STL that can **grow and shrink** in size.
It is stored in **heap memory** (dynamic allocation), unlike static arrays which are stored in stack memory.

### Declaration

```cpp
#include <vector>
vector<int> vec;                   // Empty vector
vector<int> vec = {2, 3, 4};       // Initialized vector
vector<int> vec(3, 0);              // Vector of size 3 with all values 0
```

### Traversal

```cpp
for (int val : vec) {  // Range-based loop (for-each loop)
    cout << val << " ";
}
```

### Common Functions

| Function       | Description                           |
| -------------- | ------------------------------------- |
| `size()`       | Number of elements in the vector      |
| `push_back(x)` | Add element to the end                |
| `pop_back()`   | Remove last element                   |
| `front()`      | First element                         |
| `back()`       | Last element                          |
| `at(i)`        | Element at index `i` (bounds-checked) |
| `capacity()`   | Current allocated storage capacity    |

**Note:**

* **size** → Number of elements stored
* **capacity** → Amount of memory currently allocated (can be greater than size)

---

## Useful STL Array Functions

| Function                    | Description                         |
| --------------------------- | ----------------------------------- |
| `sort(arr, arr+n)`          | Sort array                          |
| `reverse(arr, arr+n)`       | Reverse array                       |
| `accumulate(arr, arr+n, 0)` | Sum of elements (`<numeric>`)       |
| `min_element(arr, arr+n)`   | Iterator to min element             |
| `max_element(arr, arr+n)`   | Iterator to max element             |
| `count(arr, arr+n, x)`      | Count occurrences of `x`            |
| `find(arr, arr+n, x)`       | Iterator to first occurrence of `x` |

---

## Traversing Arrays

```cpp
// Classic loop
for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

// Range-based loop
for (int x : arr)
    cout << x << " ";
```

---

## Patterns and Techniques

| Technique        | Use Case                                  |
| ---------------- | ----------------------------------------- |
| Two Pointers     | Sorted array, pair sum, remove duplicates |
| Sliding Window   | Max sum subarray of size k                |
| Prefix Sum       | Subarray sum queries                      |
| Binary Search    | Search in sorted or rotated arrays        |
| Hashing          | Two Sum, frequency problems               |
| Sorting + Greedy | Interval problems                         |

---

## Edge Cases

* Empty array
* Single element
* Duplicate values
* Negative numbers
* Integer overflow (use `long long`)
* Unsorted vs sorted arrays

---

## Interview Tips

* Check if the array is sorted
* Be careful with off-by-one errors
* Always dry run small inputs

---

# Implementations

### Printing Arrays & Taking Input

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 4};

    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
    cout << endl;

    int size = sizeof(arr) / sizeof(int);
    for (int j = 0; j < size; j++) cin >> arr[j];

    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    return 0;
}
```

---

### Find Smallest and Largest

```cpp
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {4, 5, 7};
    int size = 3;

    int smallest = INT_MAX, largest = INT_MIN;
    int idx_min = 0, idx_max = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            idx_min = i;
        }
        if (arr[i] > largest) {
            largest = arr[i];
            idx_max = i;
        }
    }

    cout << "Smallest: " << smallest << " at index " << idx_min << endl;
    cout << "Largest: " << largest << " at index " << idx_max << endl;
}
```

---

### Pass Array by Reference

```cpp
#include <iostream>
using namespace std;

void changeArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] *= 2;
}

int main() {
    int arr[] = {1, 2, 3};
    changeArr(arr, 3);

    for (int i = 0; i < 3; i++) cout << arr[i] << " ";
}
```

---

### Linear Search

```cpp
#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target) return i;
    return -1;
}

int main() {
    int arr[] = {4, 2, 6, 5, 8, 1, 9};
    cout << linearSearch(arr, 7, 1);
}
```

---

### Reverse Array

```cpp
#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {4, 6, 0, 1, 5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
```

---

### Sum and Product

```cpp
#include <iostream>
using namespace std;

void operations(int arr[], int size) {
    int sum = 0, product = 1;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    cout << "Sum: " << sum << "\nProduct: " << product;
}

int main() {
    int arr[] = {6, 4, 9, 7, 1, 2};
    operations(arr, 6);
}
```

---

### Swap Min and Max

```cpp
#include <iostream>
#include <climits>
using namespace std;

void swapMinMax(int arr[], int size) {
    int min_val = INT_MAX, max_val = INT_MIN;
    int min_idx = -1, max_idx = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min_val) { min_val = arr[i]; min_idx = i; }
        if (arr[i] > max_val) { max_val = arr[i]; max_idx = i; }
    }
    swap(arr[min_idx], arr[max_idx]);
}

int main() {
    int arr[] = {9, 4, 3, 1, 0};
    swapMinMax(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
```

---

### Unique Elements

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

void printUnique(int arr[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) == seen.end()) {
            cout << arr[i] << " ";
            seen.insert(arr[i]);
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 12, 14, 72, 5, 14};
    printUnique(arr, 6);
}
```

---

### Intersection of Two Arrays

```cpp
#include <iostream>
using namespace std;

void printIntersection(int arr1[], int n1, int arr2[], int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {4, 3, 9, 6, 5, 7};
    int arr2[] = {0, 5, 1, 9, 3};
    printIntersection(arr1, 6, arr2, 5);
}
```

---

# LeetCode Practice Problems

### Easy

* Two Sum (#1)
* Best Time to Buy and Sell Stock (#121)
* Maximum Subarray (#53)
* Remove Duplicates from Sorted Array (#26)
* Merge Sorted Array (#88)
* Valid Mountain Array (#941)
* Squares of a Sorted Array (#977)

### Medium

* 3Sum (#15)
* Container With Most Water (#11)
* Subarray Sum Equals K (#560)
* Product of Array Except Self (#238)

### Hard

* Median of Two Sorted Arrays (#4)
* Trapping Rain Water (#42)
* First Missing Positive (#41)

