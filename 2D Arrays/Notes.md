Bilkul! Jo content aapne aaj cover kiya hai (2D Arrays in C++ + Operations), usko main neat, clean aur professional Markdown (md) document mein organize kar ke de raha hoon —  
taake aap directly GitHub par upload kar sakein aur apne liye revision ke liye bhi use kar sakein.

Yeh raha aapka **final ready-to-upload md file**:

---

# 2D Arrays (Matrix) in C++

## Table of Contents
- [Introduction](#introduction)
- [Syntax](#syntax)
- [Initialization](#initialization)
- [Accessing Elements](#accessing-elements)
- [Traversing a 2D Array](#traversing-a-2d-array)
- [Memory Storage](#memory-storage)
- [Linear Search in 2D Array](#linear-search-in-2d-array)
- [Questions and Solutions](#questions-and-solutions)
  - [Maximum Row Sum](#maximum-row-sum)
  - [Maximum Column Sum](#maximum-column-sum)
  - [Diagonal Sum](#diagonal-sum)
- [Summary](#summary)

---

## Introduction
- A **2D Array** (or Matrix) stores data in a **tabular format**: rows and columns.
- Example:  
  ```cpp
  int matrix[4][3];
  ```
  Here:
  - 4 = number of rows
  - 3 = number of columns

---

## Syntax
```cpp
datatype array_name[rows][columns];
```
Example:
```cpp
int matrix[4][3];
```

---

## Initialization
Initialize while declaring:
```cpp
int matrix[4][3] = {
  {1,2,3},
  {4,5,6},
  {7,8,9},
  {10,11,12}
};
```

---

## Accessing Elements
Access elements using indices:

```cpp
cout << matrix[1][1]; // Outputs 5
```
**(Rows and Columns are 0-indexed)**

---

## Traversing a 2D Array

**Input Elements:**
```cpp
for (int i = 0; i < rows; i++) {
  for (int j = 0; j < columns; j++) {
    cin >> matrix[i][j];
  }
}
```

**Output Elements:**
```cpp
for (int i = 0; i < rows; i++) {
  for (int j = 0; j < columns; j++) {
    cout << matrix[i][j] << " ";
  }
  cout << endl;
}
```

---

## Memory Storage
2D Arrays are stored in memory in two ways:
1. **Row Major Order** (default in C++) — Entire row is stored first, then next row, and so on.
2. **Column Major Order** — Entire column is stored first, then next column.

---

## Linear Search in 2D Array

### Code:
```cpp
#include <iostream>
#include <utility> // for std::pair
using namespace std;

pair<int, int> linearSearch(int matrix[4][3], int rows, int columns, int target) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (matrix[i][j] == target) {
        return {i, j}; // Return the coordinates
      }
    }
  }
  return {-1, -1}; // Target not found
}

int main() {
  int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  int rows = 4;
  int columns = 3;
  int target = 14;

  auto result = linearSearch(matrix, rows, columns, target);
  cout << "(" << result.first << ", " << result.second << ")" << endl;

  return 0;
}
```

---

## Questions and Solutions

### Maximum Row Sum

**Problem:**  
Find the row which has the maximum sum.

**Code:**
```cpp
#include <iostream>
using namespace std;

int maxRowSum(int matrix[4][3], int rows, int columns) {
  int maxSum = 0;
  for (int i = 0; i < rows; i++) {
    int rowSum = 0;
    for (int j = 0; j < columns; j++) {
      rowSum += matrix[i][j];
    }
    if (rowSum >= maxSum) {
      maxSum = rowSum;
    }
  }
  return maxSum;
}

int main() {
  int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  cout << maxRowSum(matrix, 4, 3); // Output: 33
  return 0;
}
```

---

### Maximum Column Sum

**Problem:**  
Find the column which has the maximum sum.

**Code:**
```cpp
#include <iostream>
using namespace std;

int maxColumnSum(int matrix[4][3], int rows, int columns) {
  int maxSum = 0;
  for (int i = 0; i < columns; i++) {
    int colSum = 0;
    for (int j = 0; j < rows; j++) {
      colSum += matrix[j][i];
    }
    if (colSum >= maxSum) {
      maxSum = colSum;
    }
  }
  return maxSum;
}

int main() {
  int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  cout << maxColumnSum(matrix, 4, 3); // Output: 30
  return 0;
}
```

---

### Diagonal Sum

**Problem:**  
Find the sum of the main and secondary diagonals in a square matrix.

**Code:**
```cpp
#include <iostream>
using namespace std;

int diagonalSum(int matrix[][4], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += matrix[i][i]; // Main diagonal
    if (i != n - i - 1) { 
      sum += matrix[i][n - i - 1]; // Secondary diagonal
    }
  }
  return sum;
}

int main() {
  int matrix[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  cout << diagonalSum(matrix, 4); // Output: 68
  return 0;
}
```

---

## Summary

| Topic               | Key Points                          |
|---------------------|-------------------------------------|
| Definition          | 2D Array = Array of arrays          |
| Syntax              | `datatype array_name[rows][columns]` |
| Accessing Elements  | `matrix[i][j]`                      |
| Traversing          | Nested loops                        |
| Memory Storage      | Row Major / Column Major            |
| Linear Search       | Check each element manually         |
| Maximum Row/Column  | Calculate sum and find maximum      |
| Diagonal Sum        | Sum of both diagonals               |

---

✅ **Important Tips:**
- 2D Arrays are **fixed size** in C++ (not dynamic like vectors).
- Always be careful with indices to avoid out-of-bounds errors.
- Useful for matrices, grids, tables, images (pixel data), games like Tic-Tac-Toe.

---

# End of Notes 🚀

---
