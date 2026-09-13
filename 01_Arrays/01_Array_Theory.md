# Arrays

## 1. What is an Array?

An **array** is a collection of elements of the **same data type** stored in **contiguous memory locations**.

Arrays allow us to store multiple values under one variable name and access individual elements using an **index**.

### Key Characteristics

* Stores elements of the same data type.
* Elements are stored in contiguous memory locations.
* Indexing starts from `0`.
* Direct access by index takes **O(1)** time.
* Size of a built-in array is fixed after declaration.

Example:

```cpp
int arr[] = {10, 20, 30, 40, 50};
```

Memory conceptually looks like:

```text
Index:    0    1    2    3    4
         -------------------------
Value:   10   20   30   40   50
         -------------------------
```

---

## 2. Array Size / Length

The **size** or **length** of an array means the number of elements it can contain.

```cpp
int arr[5];
```

Here:

```text
Size = 5
Valid indexes = 0 to 4
```

Therefore:

```cpp
arr[0]   // first element
arr[4]   // last element
```

Accessing `arr[5]` would be outside the valid range.

---

## 3. Array Index

An **index** represents the position of an element in an array.

C++ uses **zero-based indexing**.

For:

```cpp
int arr[] = {10, 20, 30, 40};
```

```text
Element:  10   20   30   40
Index:     0    1    2    3
```

The last valid index is:

```text
size - 1
```

---

# 4. Creating an Array

## Declaration

```cpp
int marks[50];
```

This creates an array capable of storing `50` integers.

For a local array, the elements are not automatically initialized to zero.

---

## Declaration + Partial Initialization

```cpp
int marks[50] = {1, 2, 3};
```

The first three elements are initialized:

```text
1  2  3  0  0  0  ...
```

The remaining elements are value-initialized to `0`.

---

## Declaration + Full Initialization

```cpp
int marks[] = {1, 2, 3};
```

The compiler determines the size from the number of initializers.

Therefore:

```text
Size = 3
```

---

# 5. Accessing and Modifying Elements

Access an element using its index:

```cpp
int arr[] = {10, 20, 30};

cout << arr[0];
```

Output:

```text
10
```

Modify an element:

```cpp
arr[1] = 50;
```

Array becomes:

```text
10 50 30
```

---

# 6. Memory Layout

Array elements are stored next to each other in memory.

For example:

```cpp
int arr[] = {10, 20, 30};
```

Conceptually:

```text
Address       Value
1000          10
1004          20
1008          30
```

The exact addresses depend on the system, but the important point is that the elements are **contiguous**.

This contiguous layout is one reason arrays provide efficient indexed access.

---

# 7. Array Name and Pointer

In most expressions, the name of an array **decays to a pointer to its first element**.

For:

```cpp
int arr[] = {10, 20, 30};
```

`arr` generally represents the address of the first element:

```cpp
&arr[0]
```

Therefore:

```cpp
cout << *arr;
```

prints:

```text
10
```

Because:

```text
arr
 ↓
address of arr[0]

*arr
 ↓
value at arr[0]
```

---

## Pointer Arithmetic

```cpp
cout << *arr;
cout << *(arr + 1);
cout << *(arr + 2);
```

Output:

```text
10
20
30
```

Relationship:

```text
arr       → arr[0]
arr + 1   → arr[1]
arr + 2   → arr[2]
```

Therefore:

```cpp
arr[i] == *(arr + i)
```

---

# 8. Finding the Size of a Built-in Array

For an array whose size is known in the current scope:

```cpp
int arr[] = {10, 20, 30, 40, 50};

int n = sizeof(arr) / sizeof(arr[0]);
```

Here:

```text
sizeof(arr)
```

gives the total number of bytes occupied by the entire array.

And:

```text
sizeof(arr[0])
```

gives the size of one element.

Therefore:

```text
Number of elements =
Total array size / Size of one element
```

Example:

```cpp
int arr[] = {1, 2, 3, 4, 5};

int n = sizeof(arr) / sizeof(arr[0]);

cout << n;
```

Output:

```text
5
```

### Important

This technique works when `arr` is actually an array in that scope.

It does **not** work after an array has decayed to a pointer.

---

# 9. Passing an Array to a Function

Consider:

```cpp
void printArr(int arr[], int size)
{
    // ...
}
```

In a function parameter, these two declarations are equivalent:

```cpp
void printArr(int arr[], int size)
```

and:

```cpp
void printArr(int* arr, int size)
```

The array parameter is adjusted to a pointer parameter.

Therefore, the function does not automatically know the original array's length.

That is why we normally pass the size separately:

```cpp
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
```

Call:

```cpp
int arr[] = {1, 2, 3};

printArr(arr, 3);
```

---

# 10. Can a Function Modify the Original Array?

Yes.

When a built-in array is passed to a function, the function receives access to the original array's elements through a pointer.

Example:

```cpp
void changeArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] *= 2;
}
```

If:

```text
Original:
1 2 3
```

After calling:

```cpp
changeArr(arr, 3);
```

The original array becomes:

```text
2 4 6
```

So, practically:

> Changes made through the array parameter affect the original array.

---

# 11. Time Complexity of Common Array Operations

| Operation             | Time Complexity |
| --------------------- | --------------: |
| Access by index       |            O(1) |
| Update by index       |            O(1) |
| Linear search         |            O(n) |
| Insert at beginning   |            O(n) |
| Insert at middle      |            O(n) |
| Delete from beginning |            O(n) |
| Delete from middle    |            O(n) |
| Traverse entire array |            O(n) |

The exact complexity of insertion/deletion depends on where the operation occurs.

---

# 12. Advantages of Arrays

* Simple data structure.
* Fast indexed access.
* Contiguous memory improves cache locality.
* Easy to traverse.
* Useful foundation for many other data structures and algorithms.

---

# 13. Limitations of Built-in Arrays

* Fixed size.
* Inserting/deleting elements in the middle can require shifting.
* No built-in `size()` function for raw arrays.
* Must carefully manage valid indexes.
* Out-of-bounds access causes undefined behavior.

---

# 14. Common Edge Cases

Always consider:

* Empty input / zero-length logical input.
* Single element.
* Duplicate values.
* Negative numbers.
* All values equal.
* Already sorted array.
* Reverse sorted array.
* Very large values and integer overflow.
* Target does not exist.
* Target occurs multiple times.
* Off-by-one errors.

For potentially large sums or products, consider using:

```cpp
long long
```

instead of:

```cpp
int
```

---

# 15. Interview / Problem-Solving Tips

Before solving an array problem, ask:

1. Is the array sorted?
2. Are duplicate values allowed?
3. Can I modify the original array?
4. Do I need the indexes or the values?
5. Is the answer affected by negative numbers?
6. Can the sum overflow `int`?
7. Is there a faster approach than O(n²)?
8. Can two pointers, sliding window, prefix sum, hashing, or binary search help?

Always dry-run the solution on a small example.

---

# 16. Important Array Patterns

Array problems frequently use:

### Two Pointers

Useful for:

* Pair sum in sorted arrays.
* Removing duplicates.
* Reversing arrays.
* Partitioning.

### Sliding Window

Useful for:

* Maximum/minimum sum of a subarray of size `k`.
* Longest/shortest subarray satisfying a condition.

### Prefix Sum

Useful for:

* Range sum queries.
* Subarray sum problems.

### Binary Search

Useful when the search space is ordered or has a monotonic property.

Examples:

* Searching a sorted array.
* Search in rotated sorted array.
* Finding boundaries.

### Hashing

Useful for:

* Two Sum.
* Frequency counting.
* Duplicate detection.
* Subarray-sum problems.

Common containers:

```cpp
unordered_map
unordered_set
```

### Sorting + Greedy

Useful for:

* Interval problems.
* Scheduling.
* Triplet/pair problems.
* Optimization problems.
