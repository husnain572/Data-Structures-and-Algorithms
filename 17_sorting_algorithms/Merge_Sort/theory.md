
# Understanding Merge Sort in C++

Merge Sort is a divide and conquer algorithm that recursively splits an array into two halves, sorts each half, and then merges them back together.

## Steps of Merge Sort:

1. **Divide**: Split the array into two halves until each half contains a single element.
2. **Conquer**: Recursively sort the two halves.
3. **Merge**: Merge the sorted halves into a single sorted array.

## Time Complexity Analysis:

- **Best case**: O(n log n)  
- **Average case**: O(n log n)  
- **Worst case**: O(n log n)  

**Space Complexity**: O(n) (for temporary arrays used in merging)  

## Implementation of Merge Sort in C++

Here’s a simple implementation:

```cpp
#include <iostream>
using namespace std;

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two sorted subarrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Avoids overflow

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
```

## Explanation:

### `mergeSort(arr, left, right)`

- Recursively splits the array into two halves.
- Calls itself on each half.
- Merges the sorted halves using `merge()`.

### `merge(arr, left, mid, right)`

- Merges two sorted halves into a single sorted array.
- Uses two temporary arrays to hold elements of each half.
- Compares elements and inserts the smallest one first.

## Example Walkthrough

Let's sort `arr = {12, 11, 13, 5, 6, 7}` step by step:

### Step 1: Divide

```
[12, 11, 13]   [5, 6, 7]
```

### Step 2: Further Divide

```
[12, 11]  [13]   [5, 6]  [7]
[12]  [11]  [13]   [5]  [6]  [7]
```

### Step 3: Merge Step

```
[11, 12]  [13]   [5, 6]  [7]
[11, 12, 13]   [5, 6, 7]
```

### Final Merge

```
[5, 6, 7, 11, 12, 13]  // Sorted Array
```

## Why Use Merge Sort?

- **Stable Sort** (Maintains the relative order of equal elements)  
- **Guaranteed O(n log n) Performance** (Unlike QuickSort, which can degrade to O(n²) in worst cases)  
- **Efficient for Large Datasets** (Used in external sorting like disk-based sorting)  
- **Consumes Extra Space** (Requires additional memory for merging)  

