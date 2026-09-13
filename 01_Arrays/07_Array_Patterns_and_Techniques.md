# Array Problem-Solving Patterns

Array questions are often not about basic traversal. The main challenge is recognizing the correct pattern.

## 1. Two Pointers

### Idea

Use two indexes/pointers to process an array from different positions.

Common form:

```cpp
int left = 0;
int right = n - 1;
```

Useful for:

* Pair Sum
* Two Sum in sorted array
* Reversing an array
* Removing duplicates
* Partitioning problems

Example:

```text
[1, 2, 3, 4, 5]
 ↑           ↑
left       right
```



# 2. Sliding Window

Used when dealing with **contiguous subarrays/substrings**.

Example problem:

> Find the maximum sum of a subarray of size `k`.

Instead of calculating every subarray from scratch, maintain a moving window.

```text
[1 2 3] 4 5
 ↑-----↑
 window
```

Useful for:

* Fixed-size subarrays.
* Longest/shortest subarray problems.
* Maximum/minimum window problems.



# 3. Prefix Sum

Prefix sum stores cumulative sums.

Example:

```text
Array:
2  4  1  3

Prefix:
2  6  7  10
```

Useful for:

* Range sum queries.
* Subarray sum problems.
* Converting repeated range-sum calculations from O(n) to O(1) after preprocessing.



# 4. Binary Search

Binary search repeatedly reduces the search space by half.

Basic requirement:

* The search space must have an appropriate ordered/monotonic property.

For a sorted array:

```text
[1 3 5 7 9 11 13]
       ↑
      mid
```

Useful for:

* Searching sorted arrays.
* Finding boundaries.
* Rotated sorted arrays.
* Finding positions satisfying a monotonic condition.

Time complexity:

```text
O(log n)
```



# 5. Hashing

Hashing can provide fast lookup.

Common containers:

```cpp
unordered_map
unordered_set
```

Useful for:

* Two Sum.
* Frequency counting.
* Duplicate detection.
* Subarray sum problems.
* Tracking previously seen elements.

Typical average lookup complexity:

```text
O(1)
```


# 6. Sorting + Greedy

Sometimes sorting the array first makes the problem much easier.

Common examples:

* Interval problems.
* Scheduling.
* Pair/triplet problems.
* Greedy optimization problems.

Typical structure:

```text
Sort
  ↓
Process in a strategic order
  ↓
Make locally optimal decisions
```

# 7. Complexity Awareness

When solving an array problem, compare possible approaches.

Example:

### Brute Force

```text
O(n²)
```

### Hashing

Often:

```text
O(n)
```

with additional space.

### Sorting + Two Pointers

Usually:

```text
O(n log n)
```

because of sorting.

The goal is not always to eliminate extra space. Instead, understand the trade-off between:

```text
Time ↔ Space
```


# 8. Common Array Mistakes

### Off-by-One Error

Incorrect:

```cpp
for (int i = 0; i <= n; i++)
```

Correct:

```cpp
for (int i = 0; i < n; i++)
```

Because the last valid index is:

```text
n - 1
```



### Accessing Outside the Array

For:

```cpp
int arr[5];
```

valid indexes are:

```text
0 1 2 3 4
```

Not:

```text
5
```
### Forgetting the Array Size in Functions

```cpp
void printArray(int arr[])
```

The function does not know the original array length from `arr` alone.

Pass the size:

```cpp
void printArray(int arr[], int size)
```


### Confusing Size and Last Index

If:

```text
n = 5
```

then:

```text
size       = 5
last index = 4
```

Remember:

```text
last index = n - 1
```


