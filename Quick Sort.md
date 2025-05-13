# Quick Sort Algorithm Notes

## Concept:
Quick Sort is a **divide and conquer** algorithm. It works by selecting a **pivot** element and partitioning the array around it so that:
- All elements **less than or equal** to the pivot are on its **left**.
- All elements **greater** than the pivot are on its **right**.

> **Note:** The left and right subarrays are *not necessarily sorted* after partitioning.

---

## Pivot Selection:
There are multiple strategies to choose a pivot:
- First element
- Last element
- Median element
- Random element

In this implementation, **we use the last element as the pivot.**

---

## Steps of Quick Sort:
1. **Pick a pivot** (we'll use the last element).
2. **Partition** the array so that elements < pivot are on the left, and elements > pivot are on the right.
3. **Recursively apply Quick Sort** on the left and right subarrays.

---

## C++ Code Implementation:

```cpp
#include<iostream>
#include<vector>
using namespace std;

// Partition function: places pivot at its correct position
int partition(vector<int>& arr, int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]); // Place pivot at correct index
    return idx;
}

// QuickSort function
void quickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int piv_idx = partition(arr, st, end);
        quickSort(arr, st, piv_idx - 1);   // Sort left half
        quickSort(arr, piv_idx + 1, end); // Sort right half
    }
}

// Driver code
int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    quickSort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}
````

---

## ⏱️ Time and Space Complexity:

| Case       | Time Complexity | Space Complexity |
| ---------- | --------------- | ---------------- |
| Best / Avg | O(n log n)      | O(1) (in-place)  |
| Worst      | O(n²)           | O(1)             |

> **Worst case** occurs when the pivot is always the smallest or largest element, e.g., in already sorted arrays.
