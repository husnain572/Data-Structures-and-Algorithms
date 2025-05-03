
# Recursion - Lecture 1 Notes

## **What is Recursion?**

Recursion is a programming technique where a function **calls itself** to solve smaller instances of the same problem.

### 🔁 Basic Flow

Main function → Calls recursive function → That function calls itself → Continues until a **base case** is reached.

---

##  Example 1: Print Numbers Using Recursion

```cpp
#include<iostream>
using namespace std;

void printNums(int n) {
    // Base Case
    if (n == 1) {
        cout << "1\n";
        return;
    }

    cout << n << " ";
    printNums(n - 1);
}

int main() {
    printNums(10);
    return 0;
}
```

### 🔍 Key Points:

* Recursion continues to call until `n == 1`, which is the **base case**.
* After base case, all previous calls start returning (unwinding).
* Anything achievable by loops can also be done using recursion, and vice versa.

---

## Concepts in Recursion

### Call Stack

Each recursive call adds a new frame to the **call stack**. The stack grows deeper with each call until the base case is reached, then starts shrinking as each function returns.

###  Recursion Tree

Visual representation of how recursive calls are made and how they branch out. Useful for analyzing performance.

---

## 🔁 Recurrence Relation

Used to define the **time complexity** of recursive functions.

Example (for factorial):

```
T(n) = T(n-1) + O(1)
```

---

##  Time Complexity of Recursion

### Two Ways to Analyze:

1. **Recurrence Relation**

   * Define `T(n)` based on the recursive calls.
2. **Direct Method**

   * `Time = Total number of recursive calls × Work done per call`

---

## Example 2: Factorial Using Recursion

```cpp
#include<iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5) << endl;
    return 0;
}
```

### Time Complexity:

* Total calls = `n + 1` (from n down to 0)
* Work per call = O(1)
*  **Time Complexity:** O(n)

### Space Complexity:

* `SC = Height of call stack × Space per call`
* Here, **SC = O(n)** because call stack depth is `n`.

---

## Example 3: Sum of First N Numbers

```cpp
#include<iostream>
using namespace std;

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main() {
    cout << sum(5) << endl;
    return 0;
}
```

* Base Case: `if (n == 1)`
* Recursive Case: `return n + sum(n - 1)`

---

## Summary:

* Recursion is solving a big problem by **breaking it into smaller subproblems**.
* Must always define a **base case** to avoid infinite recursion.
* Understanding the **call stack** and **recursion tree** helps in debugging and analyzing performance.

