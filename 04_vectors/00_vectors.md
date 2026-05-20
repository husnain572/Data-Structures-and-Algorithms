# Vectors

## 1. Static Memory Allocation

Memory allocated before runtime.

### Example

```cpp
int arr[5] = {1,2,3,4,5};
```

### Characteristics

* Fixed size
* Stored in stack memory
* Automatically destroyed
* Fast access

## 2. Dynamic Memory Allocation

Memory allocated during runtime using `new`.

### Example

```cpp
int* arr = new int[size];
```

### Characteristics

* Runtime size allocation
* Stored in heap memory
* Flexible
* Must manually free memory

## `delete` Keyword

Used to free dynamically allocated memory.

### Single Variable

```cpp
delete ptr;
```

### For Arrays

```cpp
delete[] arr;
```

### Good Practice

```cpp
arr = nullptr;
```

## 3. Stack vs Heap Memory

| Stack Memory   | Heap Memory                       |
| -------------- | --------------------------------- |
| Automatic      | Manual                            |
| Faster         | Slower                            |
| Fixed size     | Dynamic size                      |
| Function scope | Lifetime controlled by programmer |

## 4. Memory Leak

A memory leak occurs when heap memory is allocated but never deleted.

### Example

```cpp
int* ptr = new int;
```

If `delete ptr` is not called:

* Memory remains occupied
* Performance decreases
* Program may crash in large applications

### Example Function

```cpp
int* func(){

    int* ptr = new int;

    *ptr = 1200;

    return ptr;
}
```

### Fix

```cpp
delete ptr;
```

## 5. Dynamic 2D Arrays

Dynamic 2D arrays are created using double pointers.

### Syntax

```cpp
int** matrix = new int*[rows];
```

Then allocate each row:

```cpp
for(int i = 0; i < rows; i++){
    matrix[i] = new int[cols];
}
```

### Accessing Elements

Both are the same:

```cpp
matrix[i][j]
```

```cpp
*(*(matrix+i)+j)
```

### Deallocation

```cpp
for(int i = 0; i < rows; i++){
    delete[] matrix[i];
}

delete[] matrix;
```
## 6. STL Vector

Vector is a dynamic array provided by STL.

### Include

```cpp
#include <vector>
```

### Declaration

```cpp
vector<int> vec;
```

### Characteristics

* Dynamic resizing
* Contiguous memory allocation
* Fast random access
* Automatic memory management

## 7. Vector Initialization

### Empty Vector

```cpp
vector<int> vec;
```

### Initialize with Values

```cpp
vector<int> vec = {1,2,3,4};
```

### Fixed Size Vector

```cpp
vector<int> vec(5);
```

Creates vector of size 5.

### Fixed Size with Initial Value

```cpp
vector<int> vec(5, -1);
```

### Output

```txt
-1 -1 -1 -1 -1
```
## 8. Important Vector Functions

### `size()`

Returns number of elements.

```cpp
vec.size()
```

### `capacity()`

Returns total allocated memory capacity.

```cpp
vec.capacity()
```

### `push_back()`

Adds element at the end.

```cpp
vec.push_back(10);
```

### `pop_back()`

Removes the last element.

```cpp
vec.pop_back();
```

### `front()`

Returns the first element.

```cpp
vec.front()
```

### `back()`

Returns the last element.

```cpp
vec.back()
```

### Example

```cpp
vector<int> vec = {1,2,3};

vec.push_back(4);

cout << vec.size() << endl;
cout << vec.capacity() << endl;
```
## 9. Size vs Capacity

### Size

Number of actual elements stored.

#### Example

```txt
[1,2,3]
size = 3
```

### Capacity

Total memory allocated internally.

Capacity grows dynamically.

Usually doubles when exceeded.

#### Example

```txt
size = 4
capacity = 4

After push_back():

size = 5
capacity = 8
```

### Why Capacity Exists

To avoid reallocating memory on every insertion.

Improves performance.

## 10. 2D Vectors

2D vectors are vectors inside vectors.

### Declaration

```cpp
vector<vector<int>> matrix;
```

### Initialization

```cpp
vector<vector<int>> matrix = {
    {1,2,3},
    {4,5},
    {6}
};
```

This is called a **jagged array**.

### Traversing a 2D Vector

```cpp
for(int i = 0; i < matrix.size(); i++){

    for(int j = 0; j < matrix[i].size(); j++){

        cout << matrix[i][j] << " ";
    }

    cout << endl;
}
```
## 11. Time Complexities

| Operation        | Complexity     |
| ---------------- | -------------- |
| Access by index  | O(1)           |
| `push_back()`    | O(1) amortized |
| `pop_back()`     | O(1)           |
| Insert at middle | O(n)           |
| Delete at middle | O(n)           |
| `size()`         | O(1)           |

## 12. Common Mistakes

### 1. Forgetting `delete[]`

#### Wrong

```cpp
int* arr = new int[5];
```

#### Correct

```cpp
delete[] arr;
```

### 2. Memory Leak

#### Wrong

```cpp
int* ptr = new int;
```

Without deleting memory.

### 3. Accessing Out of Bounds

#### Wrong

```cpp
vec[100]
```

Can cause undefined behavior.

### 4. Confusing Size and Capacity

```txt
size     -> elements stored
capacity -> allocated memory
```

## 13. Interview Tips

* Learn the difference between stack and heap.
* Understand vector resizing internally.
* Practice:

  * Dynamic arrays
  * Matrix problems
  * Prefix sums
  * Sliding window
  * 2D vector traversal

### Know These Functions

* `push_back()`
* `pop_back()`
* `size()`
* `capacity()`

# Revision
* [Stack vs Heap]
* Dynamic memory allocation
* `delete` and `delete[]`
* Memory leak
* Dynamic 2D arrays
* Vector basics
* Vector functions
* Size vs Capacity
* 2D vectors
