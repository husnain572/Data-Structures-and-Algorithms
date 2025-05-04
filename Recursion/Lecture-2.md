
```cpp
// =============================
//  Recursion Practice - Day 2
// 3 Questions (2 LeetCode + 1 Basic)
// =============================

#include<iostream>
#include<vector>
using namespace std;

// -------------------------------------------------
// Question 1: Check if an Array is Sorted (Recursive)
// Description: Returns true if the array is sorted in non-decreasing order.
// -------------------------------------------------

bool isSorted(vector<int> arr, int n){
    if(n == 0 || n == 1){
        return true;
    }
    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main(){
    vector<int> arr = {1, 2, 3, 6, 4, 3};
    cout << "Is array sorted? " << isSorted(arr, arr.size()) << endl;
    return 0;
}
```

```cpp
// -------------------------------------------------
// Question 2: LeetCode - 704. Binary Search (Recursive)
// Link: https://leetcode.com/problems/binary-search/
// -------------------------------------------------

class Solution {
public:
    int Binarysearch(vector<int>& arr, int tar, int start, int end) {
        if(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == tar) return mid;
            else if(arr[mid] < tar){
                return Binarysearch(arr, tar, mid + 1, end);
            } else {
                return Binarysearch(arr, tar, start, mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int tar) {
        return Binarysearch(arr, tar, 0, arr.size() - 1);
    }
};
```

```cpp
// -------------------------------------------------
// Question 3: LeetCode - 509. Fibonacci Number (Recursive)
// Link: https://leetcode.com/problems/fibonacci-number/
// -------------------------------------------------

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
```


