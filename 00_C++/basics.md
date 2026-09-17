# 0. C++ Basics

## 1. Input / Output (I/O)

```cpp
#include<iostream>
using namespace std;
```

- `cin` → input lene ke liye
- `cout` → output print karne ke liye
- `<<` → insertion operator
- `>>` → extraction operator

```cpp
int x, y;
cin >> x >> y;
cout << x << " " << y;
```

### Important:

- `endl` → new line + flush (slow)
- `\n` → new line (fast, preferred in DSA)

## 2. Data Types

| Type | Use |
| --- | --- |
| `int` | small integers |
| `long` | bigger integers |
| `long long` | very large integers |
| `float` | decimal (less precision) |
| `double` | decimal (high precision) |
| `char` | single character |
| `string` | text |

```cpp
int a = 10;
long long b = 10000000000;
char c = 'A';
string s = "Husnain";
```

## 3. `getline()`

Used to take **full line input (including spaces)**

```cpp
string s;
getline(cin, s);
```

### Important Trap:

If you use `cin` before `getline`, it may skip input.

Fix:

```cpp
cin.ignore();
getline(cin, s);
```

## 4. Conditional Statements (if / else)

```cpp
int age;
cin >> age;

if (age > 18) {
    cout << "Eligible";
} else {
    cout << "Not Eligible";
}
```

### Key Points:

- Conditions always return **true/false**
- Use `{}` for multiple statements

## 5. Switch Statement

Used when checking multiple fixed values

```cpp
int day;
cin >> day;

switch(day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    ...
    default: cout << "Invalid";
}
```

### Important:

- `break` is mandatory
- Only works with **int / char (not strings)**

## 6. Arrays

Used to store same type of data.

```cpp
int arr[] = {4, 12, 3, 4};
```

### Access:

```cpp
cout << arr[0];  // 4
```

### Indexing:

- Starts from `0`
- Size = number of elements

## 7. 2D Arrays

Matrix type structure

```cpp
int arr[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
};
```

### Access:

```cpp
cout << arr[1][1];  // 4
```

---

## 8. Strings

```cpp
string str = "Husnain";
```

### Access characters:

```cpp
cout << str[0];  // H
```

### Loop through string:

```cpp
for(int i = 0; i < str.size(); i++) {
    cout << str[i];
}
```

---

# DSA Tips

- Always use `\n` instead of `endl`
- Prefer `long long` for large constraints
- Arrays = most used DS in interviews
- Strings behave like arrays of characters
- Practice dry runs (you struggled earlier → improve this)

---

# Quick Revision

- `cin/cout` → input/output
- `getline()` → full line input
- `if/else` → conditions
- `switch` → multiple fixed cases
- `array` → indexed storage
- `2D array` → matrix
- `string` → character array

# Part 2: Loops & Functions

---

## 1. for Loop

### Concept

Used when the number of iterations is known

### Syntax

```cpp
for(initialization; condition; update) {
    // code
}
```

### Example

```cpp
for(int i = 0; i < 5; i++) {
    cout << i << "\n";
}
```

### Notes

- Initialization runs once
- Condition is checked before every iteration
- Update runs after every iteration

---

## 2. while Loop

### Concept

Used when the number of iterations is not fixed

### Syntax

```cpp
while(condition) {
    // code
}
```

### Example

```cpp
int i = 0;
while(i < 5) {
    cout << i << "\n";
    i++;
}
```

### Notes

- Condition checked before execution
- May run zero times

---

## 3. do-while Loop

### Concept

Executes at least once even if condition is false

### Syntax

```cpp
do {
    // code
} while(condition);
```

### Example

```cpp
int i = 0;
do {
    cout << i << "\n";
    i++;
} while(i < 5);
```

### Notes

- Condition checked after execution
- Runs at least once

---

## 4. Functions

### Concept

Reusable block of code

---

### 4.1 Void Function (No Return)

```cpp
void greet() {
    cout << "Hello\n";
}
```

---

### 4.2 Function with Return

```cpp
int sum(int a, int b) {
    return a + b;
}
```

---

### 4.3 Parameterised Function

```cpp
void printSum(int a, int b) {
    cout << a + b;
}
```

---

### 4.4 Non-Parameterised Function

```cpp
void greet() {
    cout << "Hello";
}
```

---

### Function Call

```cpp
greet();
int result = sum(2, 3);
```

---

## 5. Pass by Value

### Concept

A copy of the variable is passed

### Example

```cpp
void change(int x) {
    x = 10;
}

int main() {
    int a = 5;
    change(a);
    cout << a;  // Output: 5
}
```

### Notes

- Original value does not change
- Uses extra memory for copy

---

## 6. Pass by Reference

### Concept

The original variable is passed using reference

### Example

```cpp
void change(int &x) {
    x = 10;
}

int main() {
    int a = 5;
    change(a);
    cout << a;  // Output: 10
}
```

### Notes

- Original value changes
- No extra copy created
- Use `&` operator

---

## Comparison: Value vs Reference

| Feature | Pass by Value | Pass by Reference |
| --- | --- | --- |
| Copy created | Yes | No |
| Original changes | No | Yes |
| Memory usage | More | Less |
| Speed | Slower | Faster |

---

## Quick Revision

- for → fixed iterations
- while → condition-based loop
- do-while → runs at least once
- function → reusable code
- void → no return
- return → gives output
- parameterised → takes input
- non-parameterised → no input
- pass by value → copy
- pass by reference → original

# Time & Space Complexity

---

## 1. What is Time Complexity?

### Concept

Time Complexity measures how the execution time of code grows with respect to input size (N).

- It does NOT measure actual time (seconds)
- It depends on input size, not machine speed

### Why not actual time?

- Different machines give different execution times
- Example:
    - Low-end PC → slower
    - High-end machine → faster
- So, real time is not a reliable metric

---

## 2. Definition

Time Complexity = Rate at which time increases with input size (N)

---

## 3. Big O Notation

### Concept

Used to represent time complexity

Example:

```cpp
for(int i = 0; i < N; i++) {
    cout << "Hello";
}
```

- Loop runs N times
- Each iteration → constant work
- Time Complexity = O(N)

---

## 4. Basic Example Breakdown

For loop running N times:

- Each iteration → 3 operations (check, print, increment)
- Total steps = 3N

Time Complexity:

- O(3N) → simplified to → O(N)

---

## 5. Rules to Calculate Time Complexity

### Rule 1: Always consider Worst Case

### Cases:

- Best Case → minimum steps
- Worst Case → maximum steps
- Average Case → in between

We always take worst case because:

- Ensures system works efficiently in all situations

---

### Rule 2: Ignore Constants

Example:

- O(3N) → O(N)
- O(100) → O(1)

Reason:

- Constants do not affect growth rate

---

### Rule 3: Ignore Lower Order Terms

Example:

- O(N² + N + 1) → O(N²)
- O(4N³ + 3N² + 8) → O(N³)

Reason:

- Higher power dominates for large N

---

## 6. Common Time Complexities

| Complexity | Meaning |
| --- | --- |
| O(1) | Constant |
| O(N) | Linear |
| O(N²) | Nested loops |
| O(log N) | Binary search |
| O(N log N) | Efficient sorting |

---

## 7. Practice Examples

### Example 1: Nested Loop

```cpp
for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        // constant work
    }
}
```

- Outer loop → N times
- Inner loop → N times

Total = N × N = N²

Time Complexity = O(N²)

---

### Example 2: Triangular Loop

```cpp
for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
        // constant work
    }
}
```

Total operations:

- 1 + 2 + 3 + ... + N = N(N+1)/2

Time Complexity:

- O(N²)

---

## 8. What is Space Complexity?

### Concept

Memory used by a program

Space Complexity = Input Space + Auxiliary Space

---

## 9. Types of Space

### Input Space

- Memory used to store input

### Auxiliary Space

- Extra memory used during execution

---

### Example

```cpp
int a, b;   // input space
int c = a + b; // auxiliary space
```

Space Complexity = O(1)

---

### Example (Array)

```cpp
int arr[N];
```

Space Complexity = O(N)

---

## 10. Important Rule (Interviews)

Do NOT modify input data unnecessarily

Bad practice:

```cpp
b = a + b;
```

Better:

```cpp
int c = a + b;
```

Reason:

- Input data may be reused
- Always preserve original inputs unless instructed

---

## 11. Competitive Programming Insight

### Key Rule

- 1 second ≈ 10⁸ operations

### Examples:

- 1s → ~10⁸ operations
- 2s → ~2 × 10⁸
- 5s → ~5 × 10⁸

---

### Interpretation

| N Value | Acceptable Complexity |
| --- | --- |
| N ≤ 10⁵ | O(N), O(N log N) |
| N ≤ 10³ | O(N²) |
| N ≤ 10⁷ | O(N) |
| N very large | O(log N) |

---

## 12. Quick Revision

- Time complexity depends on input size (N)
- Ignore constants and lower terms
- Always consider worst case
- Nested loops → multiply
- Sequential loops → add (but keep highest term)
- Space complexity = input + extra space
- Do not modify given input data
- 10⁸ operations ≈ 1 second
