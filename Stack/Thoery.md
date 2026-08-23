### What is a Stack?

A **stack** is a linear data structure that follows the **LIFO (Last-In, First-Out)** principle.

The element that is inserted **last** is removed **first**.

Think of a stack of plates: you place a plate on the top and also remove the top plate first.

### Basic Operations

| Operation          | Meaning                      | Time     |
| ------------------ | ---------------------------- | -------- |
| `push(x)`          | Add element to top           | **O(1)** |
| `pop()`            | Remove top element           | **O(1)** |
| `top()` / `peek()` | Access top element           | **O(1)** |
| `empty()`          | Check whether stack is empty | **O(1)** |
| `size()`           | Number of elements           | **O(1)** |

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

st.top();    // 30
st.pop();    // removes 30
st.top();    // 20
```

### Important Point

A stack allows access to **only one end**, called the **top**.

You cannot directly access the middle element like you can with an array/vector.


## Where is Stack Used?

Stacks are commonly used for:

* **Reversing** data
* **Parentheses/bracket matching**
* **Expression evaluation**
* **Expression conversion**
* **Monotonic stack problems**
* **Backtracking**
* **Undo/Redo operations**
* **Function calls and recursion**
* **Depth First Search (DFS)**
* **Parsing nested structures**

# Stack Implementations

A stack can be implemented using:

### 1. Vector

```cpp
vector<int> v;

v.push_back(x);  // push
v.pop_back();    // pop
v.back();        // top
```

### 2. Linked List

The head of the linked list can represent the **top of the stack**.

### 3. STL `stack`

C++ provides a built-in stack container:

```cpp
#include <stack>

stack<int> st;

st.push(10);
st.pop();
st.top();
st.empty();
```
# Pattern Recognition Keywords

When you see these phrases in a LeetCode problem, think about **Stack**:

| Problem Phrase                     | Stack Concept                      |
| ---------------------------------- | ---------------------------------- |
| **Valid Parentheses**              | Matching opening/closing brackets  |
| **Next Greater Element**           | Monotonic stack                    |
| **Previous Greater Element**       | Monotonic stack                    |
| **Next Smaller Element**           | Monotonic stack                    |
| **Daily Temperatures**             | Monotonic decreasing stack         |
| **Stock Span**                     | Monotonic stack                    |
| **Evaluate Expression**            | Operators + operands using stack   |
| **Decode String**                  | Nested structures using stacks     |
| **Backspace String**               | Simulate undo behavior             |
| **Remove Duplicates**              | Keep track of previous characters  |
| **Asteroid Collision**             | Resolve elements against stack top |
| **Largest Rectangle in Histogram** | Monotonic stack                    |
| **Undo / Redo**                    | Stack history                      |
| **Backtracking**                   | Store previous states              |


# Common Stack Techniques

### 1. Basic Push / Pop

```cpp
s.push(x);
s.pop();
s.top();
s.empty();
```

### 2. Reversing Something

If you need to reverse the order of elements:

**Push → Traverse → Pop**

```text
Original:  1 2 3 4

Push into stack
      ↓
Pop from stack
      ↓
Reversed:  4 3 2 1
```

### 3. Valid Parentheses

Use a stack to store **opening brackets**.

```text
( [ { 
```

When a closing bracket appears, compare it with the stack's top.

```text
( )     → valid
[ ]     → valid
{ ]     → invalid
```

### 4. Monotonic Stack

A **monotonic stack** maintains elements in a particular increasing or decreasing order.

Commonly used for:

* Next Greater Element
* Next Smaller Element
* Previous Greater Element
* Previous Smaller Element
* Daily Temperatures
* Stock Span
* Largest Rectangle in Histogram

Typical pattern:

```cpp
while (!s.empty() && arr[s.top()] <= arr[i]) {
    s.pop();
}
```

**Key idea:** Instead of checking every previous element, remove elements that can no longer be useful.

### 5. Nested Structures

Stacks are useful when dealing with **nested data**.

For example:

```text
3[a2[c]]
```

The stack helps keep track of the previous strings and numbers while processing the nested structure.

### 6. Backtracking / Undo

A stack naturally represents:

```text
Current State
     ↓
Previous State
     ↓
Older State
```

When you need to go backward, pop the most recent state.

Examples:

* Browser history
* Undo operations
* Backtracking
* DFS
* Recursion

# Stack and Recursion

Every recursive function uses the **call stack**.

For example:

```cpp
void fun(int n) {
    if (n == 0)
        return;

    fun(n - 1);
}
```

The function calls are stored in memory like a stack:

```text
fun(3)
  ↓
fun(2)
  ↓
fun(1)
  ↓
fun(0)
```

The last function call finishes first.

**Therefore, recursion follows the stack's LIFO behavior.**

# Stack in DFS

Depth First Search can be implemented using a stack.

```text
Start
  ↓
Go deep
  ↓
Go deeper
  ↓
Dead end
  ↓
Backtrack
```

DFS can use either:

* **Explicit stack**
* **Recursion → implicit call stack**

# Important Tips for LeetCode

### Think Stack when:

* You need to **reverse** something.
* You need to **undo** something.
* You need to **backtrack**.
* You need to match **opening and closing brackets**.
* You are dealing with **nested structures**.
* You need to find **next/previous greater or smaller elements**.
* You need to process elements while maintaining an **increasing/decreasing order**.

### Strongest keyword to remember:

> **"Next Greater / Next Smaller" → Think Monotonic Stack.**

And:

> **"Last action should be undone first" → Think Stack.**

# Complexity

For a normal stack:

```text
push()  → O(1)
pop()   → O(1)
top()   → O(1)
empty() → O(1)
```

Space complexity:

```text
O(n)
```

for `n` elements stored in the stack.


## Quick Revision

```text
STACK
  ↓
LIFO
  ↓
Last In → First Out
  ↓
--------------------------------
push()   → Add to top
pop()    → Remove from top
top()    → View top
empty()  → Check empty
--------------------------------
Common Uses:
Reverse
Parentheses
Recursion
Backtracking
DFS
Expression Evaluation
Monotonic Stack
Undo/Redo
```

**DSA mindset:** When a problem requires you to remember the **most recent unresolved element/state** and deal with it before older ones, a **stack is often the right data structure**.
