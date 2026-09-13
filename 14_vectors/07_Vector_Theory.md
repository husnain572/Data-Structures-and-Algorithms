# Vectors in C++

## 1. What is a Vector?

A `vector` is a **dynamic array** provided by the C++ Standard Library.

Unlike a built-in array, a vector can dynamically grow and shrink.

```cpp
#include <vector>

vector<int> vec;
```

---

# 2. Declaration

### Empty Vector

```cpp
vector<int> vec;
```

### Initialized Vector

```cpp
vector<int> vec = {2, 3, 4};
```

### Vector with Size

```cpp
vector<int> vec(3);
```

Creates:

```text
0 0 0
```

### Vector with Size and Initial Value

```cpp
vector<int> vec(3, 0);
```

Creates:

```text
0 0 0
```

Another example:

```cpp
vector<int> vec(5, -1);
```

Creates:

```text
-1 -1 -1 -1 -1
```

---

# 3. Vector Size

```cpp
vec.size();
```

Returns the number of elements currently stored.

Example:

```cpp
vector<int> vec = {10, 20, 30};

cout << vec.size();
```

Output:

```text
3
```

---

# 4. Vector Capacity

```cpp
vec.capacity();
```

`capacity()` represents the amount of storage currently allocated for elements.

Important distinction:

```text
size     = number of elements currently stored
capacity = allocated storage available
```

Capacity can be greater than size.

Example:

```text
size     = 3
capacity = 8
```

This means the vector currently contains 3 elements but has storage available for more before another reallocation may be needed.

---

# 5. Adding Elements

```cpp
vec.push_back(10);
```

Adds `10` to the end of the vector.

Example:

```cpp
vector<int> vec;

vec.push_back(10);
vec.push_back(20);
vec.push_back(30);
```

Vector:

```text
10 20 30
```

---

# 6. Removing the Last Element

```cpp
vec.pop_back();
```

Example:

```cpp
vector<int> vec = {10, 20, 30};

vec.pop_back();
```

Vector becomes:

```text
10 20
```

---

# 7. Accessing Elements

Using index:

```cpp
vec[0]
```

Using `at()`:

```cpp
vec.at(0)
```

Difference:

```text
vec[i]
    → does not perform bounds checking

vec.at(i)
    → performs bounds checking
```

---

# 8. First and Last Element

```cpp
vec.front();
```

Returns the first element.

```cpp
vec.back();
```

Returns the last element.

Example:

```cpp
vector<int> vec = {10, 20, 30};

cout << vec.front();  // 10
cout << vec.back();   // 30
```

---

# 9. Traversing a Vector

### Classic Loop

```cpp
for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}
```

### Range-Based Loop

```cpp
for (int x : vec) {
    cout << x << " ";
}
```

---

# 10. Vector Iterators

```cpp
vec.begin()
```

Points to the first element.

```cpp
vec.end()
```

Points to the position **just after the last element**.

Important:

> `end()` does not point to the last element.

Example:

```text
10 20 30

begin()
  ↓
 10  20  30
          ↑
        end()
```

The last element is:

```cpp
vec.back()
```

or:

```cpp
*(vec.end() - 1)
```

---

# 11. Why Use Vector?

Vectors are commonly preferred in DSA because:

* They have dynamic size.
* They provide O(1) random access.
* They work naturally with STL algorithms.
* They automatically manage memory.
* They are widely used in competitive programming and interviews.

---

# 12. Raw Array vs Vector

| Feature            | Raw Array | Vector    |
| ------------------ | --------- | --------- |
| Size               | Fixed     | Dynamic   |
| `size()`           | No        | Yes       |
| `push_back()`      | No        | Yes       |
| `pop_back()`       | No        | Yes       |
| Random access      | O(1)      | O(1)      |
| Automatic resizing | No        | Yes       |
| STL integration    | Good      | Excellent |

---

# 13. Important Memory Note

Do not memorize:

> "Vector itself is stored on the heap."

More accurately:

A vector object can itself be stored wherever it is declared, while its dynamically allocated element storage is typically managed separately.

For DSA purposes, the important idea is:

> **Vector manages dynamically allocated storage for its elements.**
