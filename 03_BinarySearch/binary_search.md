# DSA – Binary Search Algorithm (C++)

## 1. What Is Binary Search?

Binary Search is a searching algorithm used to find a specific element in a **sorted array**.

Instead of checking every element one by one, Binary Search repeatedly divides the search space into two halves.

It compares the target value with the middle element and decides whether to search in the left half or the right half.

### Real-Life Example: Dictionary

Imagine searching for a word in a dictionary.

You don't start reading from the first page and check every word. Instead:

1. Open the dictionary somewhere in the middle.
2. Check the word on that page.
3. If your target word comes alphabetically before it, search the left half.
4. If it comes after it, search the right half.
5. Repeat until you find the word.

This is the basic idea behind Binary Search.

## 2. Linear Search vs Binary Search

### Linear Search

Linear Search checks each element one by one until it finds the target.

Example:

```cpp
int arr[] = {2, 4, 6, 8, 10};
int target = 8;
```

The algorithm checks:

- Index 0: 2
- Index 1: 4
- Index 2: 6
- Index 3: 8

The target is found at index 3.

**Time Complexity:** O(n)

### Binary Search

Binary Search repeatedly divides the search space into two halves.

For the same sorted array:

```cpp
int arr[] = {2, 4, 6, 8, 10};
int target = 8;
```

It checks the middle element first and eliminates half of the search space based on the comparison.

**Time Complexity:** O(log n)

### Comparison

| Feature | Linear Search | Binary Search |
|---|---|---|
| Requirement | Sorted array not required | Sorted array required |
| Searching method | One by one | Divide into halves |
| Time complexity | O(n) | O(log n) |
| Efficiency on large arrays | Slower | Faster |

## 3. Important Requirement of Binary Search

**Binary Search works on sorted data.**

The array must be arranged in ascending or descending order.

For example, this array is sorted:

```cpp
int arr[] = {1, 3, 4, 5, 9, 12, 15};
```

This array is not sorted:

```cpp
int arr[] = {5, 1, 9, 3, 15, 4, 12};
```

Binary Search cannot be applied directly to an unsorted array because its left/right elimination decisions depend on the ordering of elements.

## 4. Understanding the Three Important Variables

Binary Search commonly uses three variables:

- `start`: Starting index of the current search range.
- `end`: Ending index of the current search range.
- `mid`: Middle index of the current search range.

Initially:

```cpp
int start = 0;
int end = n - 1;
```

The middle index is calculated as:

```cpp
int mid = start + (end - start) / 2;
```

Why use this formula instead of `(start + end) / 2`?

Because adding `start + end` directly can cause integer overflow when the index values are very large. The alternative formula avoids that risk.

## 5. Three Possible Cases

After calculating the middle index, compare the middle element with the target.

### Case 1: Target equals the middle element

```cpp
if (arr[mid] == target)
```

The target has been found.

Return the middle index:

```cpp
return mid;
```

### Case 2: Target is greater than the middle element

```cpp
else if (arr[mid] < target)
```

Because the array is sorted, the target can only exist in the right half.

Update:

```cpp
start = mid + 1;
```

Why `mid + 1`?

Because the middle element has already been checked. We don't need to search it again.

### Case 3: Target is smaller than the middle element

```cpp
else
```

The target can only exist in the left half.

Update:

```cpp
end = mid - 1;
```

Again, we use `mid - 1` because the middle element has already been checked.

## 6. Complete Iterative Binary Search Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        else if (arr[mid] < target) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {

    int arr[] = {1, 3, 4, 5, 9, 12, 15};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 15;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
```

## 7. Understanding the While Loop Condition

```cpp
while (start <= end)
```

This condition means that the search should continue as long as the search range is valid.

Why use `start <= end` instead of `start < end`?

Because the remaining search range may contain just one element.

For example:

```text
start = 3
end = 3
```

There is still one element to check at index 3.

If we used `start < end`, the loop would stop without checking that element.

Therefore, `start <= end` is important.

When `start > end`, the search range becomes invalid, which means the target does not exist in the array.

In that case, the function returns:

```cpp
return -1;
```

## 8. Dry Run – Example 1 (Odd Number of Elements)

Array:

```cpp
int arr[] = {1, 3, 4, 5, 9, 12, 15};
int target = 15;
```

Initial values:

```text
start = 0
end = 6
```

| Iteration | Start | End | Mid | arr[mid] | Decision |
|---|---:|---:|---:|---:|---|
| 1 | 0 | 6 | 3 | 5 | 15 is greater, search right |
| 2 | 4 | 6 | 5 | 12 | 15 is greater, search right |
| 3 | 6 | 6 | 6 | 15 | Target found |

Output:

```text
Element found at index: 6
```

Notice that the algorithm found the target in only three comparisons.

## 9. Dry Run – Example 2 (Even Number of Elements)

Array:

```cpp
int arr[] = {2, 4, 6, 8, 10, 12};
int target = 4;
```

Initial values:

```text
start = 0
end = 5
```

| Iteration | Start | End | Mid | arr[mid] | Decision |
|---|---:|---:|---:|---:|---|
| 1 | 0 | 5 | 2 | 6 | 4 is smaller, search left |
| 2 | 0 | 1 | 0 | 2 | 4 is greater, search right |
| 3 | 1 | 1 | 1 | 4 | Target found |

Output:

```text
Element found at index: 1
```

### Important Observation

When the number of elements is even, there are two middle positions.

The formula:

```cpp
int mid = start + (end - start) / 2;
```

selects the lower middle index.

For example, if:

```text
start = 0
end = 5
```

Then:

```text
mid = 0 + (5 - 0) / 2
mid = 2
```

Integer division removes the decimal part.

## 10. Recursive Binary Search

Binary Search can also be implemented using recursion.

In recursion, a function calls itself to solve a smaller version of the same problem.

Instead of using a `while` loop, we call the same function again with an updated search range.

### Recursive Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {

    // Base case: target does not exist
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    // Target found
    if (arr[mid] == target) {
        return mid;
    }

    // Search right half
    else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, end, target);
    }

    // Search left half
    else {
        return binarySearch(arr, start, mid - 1, target);
    }
}

int main() {

    int arr[] = {1, 3, 4, 5, 9, 12, 15};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 12;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result;
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
```

### Understanding the Recursive Function

The function receives four arguments:

```cpp
binarySearch(arr, start, end, target);
```

Each recursive call reduces the search range.

There are three important parts:

1. **Base case:** If `start > end`, return `-1`.
2. **Comparison:** Check whether the middle element is equal to the target.
3. **Recursive call:** Search either the left half or the right half.

### Recursive Dry Run

Array:

```cpp
int arr[] = {1, 3, 4, 5, 9, 12, 15};
int target = 12;
```

| Call | Start | End | Mid | arr[mid] | Action |
|---|---:|---:|---:|---:|---|
| 1 | 0 | 6 | 3 | 5 | Search right |
| 2 | 4 | 6 | 5 | 12 | Target found |

The function returns index `5`.

## 11. Time Complexity of Binary Search

The most important concept is that Binary Search reduces the search space by half in every iteration.

Suppose the original number of elements is `n`.

After each iteration:

| Step | Remaining elements |
|---|---|
| Initially | n |
| After 1 iteration | n / 2 |
| After 2 iterations | n / 4 |
| After 3 iterations | n / 8 |
| After k iterations | n / 2^k |

When the search is complete, approximately one element remains.

Therefore:

```text
n / 2^k = 1
```

Multiply both sides by `2^k`:

```text
n = 2^k
```

Taking the logarithm base 2:

```text
k = log2(n)
```

This means the number of iterations grows logarithmically with the number of elements.

**Time Complexity: O(log n)**

### Example

Suppose an array contains 1,024 elements.

```text
1024 = 2^10
```

Therefore, Binary Search needs at most approximately 10 divisions to reduce the search space to one element.

Compare this with Linear Search, which may need to check all 1,024 elements.

### Complexity Comparison

| Number of elements | Linear Search | Binary Search (approx.) |
|---:|---:|---:|
| 10 | 10 | 4 |
| 100 | 100 | 7 |
| 1,000 | 1,000 | 10 |
| 10,000 | 10,000 | 14 |
| 1,000,000 | 1,000,000 | 20 |

The values for Binary Search represent approximate maximum comparisons, depending on the array size and implementation.

## 12. Space Complexity

### Iterative Binary Search

The iterative implementation uses a fixed number of variables:

- `start`
- `end`
- `mid`

It does not create additional recursive function calls.

**Auxiliary Space Complexity: O(1)**

### Recursive Binary Search

Every recursive call uses stack memory.

Since the search range is divided by two each time, the maximum recursion depth is logarithmic.

**Auxiliary Space Complexity: O(log n)**

### Comparison

| Implementation | Time Complexity | Auxiliary Space |
|---|---|---|
| Iterative | O(log n) | O(1) |
| Recursive | O(log n) | O(log n) |

## 13. Important Interview Questions

**Q1. What is Binary Search?**

Binary Search is an efficient searching algorithm that repeatedly divides a sorted search space into two halves to find a target element.

**Q2. What is the main requirement of Binary Search?**

The data must be sorted.

**Q3. What is the time complexity of Binary Search?**

O(log n).

**Q4. Why is Binary Search faster than Linear Search?**

Because it eliminates half of the remaining search space after every comparison.

**Q5. Why do we use `start <= end`?**

To ensure that even a search range containing one element is checked.

**Q6. Why do we use `mid + 1` and `mid - 1`?**

Because the middle element has already been checked, so it should not be included in the next search range.

**Q7. What happens if the target is not present?**

The search range eventually becomes invalid (`start > end`), and the function returns `-1`.

**Q8. Can Binary Search work on an unsorted array?**

Not directly. The array must first be sorted, or another suitable searching method must be used.

**Q9. What is the difference between iterative and recursive Binary Search?**

Iterative Binary Search uses a loop, while recursive Binary Search calls itself with a smaller search range.

**Q10. What is the space complexity of iterative and recursive Binary Search?**

Iterative: O(1).

Recursive: O(log n), because of the recursive call stack.

## 14. Problems to Practice After Understanding Binary Search

Once you understand basic Binary Search, gradually move towards its variations and applications.

1. Binary Search in a sorted array.
2. First and last occurrence of an element.
3. Search Insert Position.
4. Find the peak element.
5. Search in a rotated sorted array.
6. Find the pivot in an array.
7. Aggressive Cows.
8. Book Allocation Problem.
9. Painter's Partition Problem.

These problems help develop the ability to recognize when Binary Search can be applied beyond simple array searching.

## 15. Final Revision Sheet

| Concept | Key Point |
|---|---|
| Algorithm | Binary Search |
| Requirement | Sorted array |
| Main variables | start, end, mid |
| Middle formula | `start + (end - start) / 2` |
| Target found | `arr[mid] == target` |
| Search right | `start = mid + 1` |
| Search left | `end = mid - 1` |
| Loop condition | `start <= end` |
| Target not found | Return `-1` |
| Time complexity | O(log n) |
| Iterative space | O(1) |
| Recursive space | O(log n) |

## 16. What You Should Remember

- Binary Search only works directly on sorted data.
- It checks the middle element instead of checking every element.
- Every iteration eliminates approximately half of the remaining search space.
- `start` and `end` define the current search range.
- `mid` identifies the middle position.
- If the target is greater than the middle element, search the right half.
- If the target is smaller than the middle element, search the left half.
- Always remember the base condition and loop condition.
- Binary Search has O(log n) time complexity.

