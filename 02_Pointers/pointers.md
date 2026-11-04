# C++ DSA – Pointers

## 1. Introduction

In this lecture, we will learn about **Pointers in C++**, one of the most important concepts for understanding programming fundamentals and Data Structures and Algorithms (DSA).

Topics covered:

1. Memory Addresses
2. Address-of Operator (`&`)
3. Pointers
4. Pointer to Pointer
5. Dereferencing Operator (`*`)
6. Null Pointers
7. Pointer-Based Problems
8. Pass by Reference
9. References (Aliases)
10. Array Pointers
11. Constant Pointers
12. Pointer Arithmetic
13. Pointer Arithmetic with Arrays
14. Pointer Subtraction and Comparison

---

# 2. Memory Addresses

Before understanding pointers, we must understand **memory addresses**.

Whenever we create a variable in C++, some space in computer memory is allocated to store its value.

For example:

```cpp
int a = 10;
```

Here:
- `a` is a variable.
- `10` is its value.
- Memory space is allocated to store this value.
- That memory location has a unique address.

A **memory address** identifies the location where a variable is stored in memory.

### 2.1 Hexadecimal Number System

Memory addresses are generally represented in hexadecimal format.

There are three important number systems:

| Number System | Base | Digits |
|---|---:|---|
| Decimal | 10 | 0–9 |
| Binary | 2 | 0, 1 |
| Hexadecimal | 16 | 0–9, A–F |

Hexadecimal contains 16 symbols:

- Numbers: `0–9` (10 symbols)
- Letters: `A–F` (6 symbols)

Total = 16 symbols.

Example of a memory address:

```text
0x36A6
```

Here:
- `0x` indicates hexadecimal representation.
- `36A6` is the hexadecimal address.

**Important:** Actual memory addresses are assigned by the system. They can differ every time a program runs.

### 2.2 Address-of Operator (`&`)

C++ provides the address-of operator (`&`) to obtain the memory address of a variable.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    cout << &a;

    return 0;
}
```

Possible output:

```text
0x7ffeefbff45c
```

The actual address will be different on different systems or executions.

Here:

```cpp
&a
```

means the memory address of variable `a`.

### 2.3 Multiple Uses of the `&` Operator

The `&` symbol has different uses in C++ depending on the context.

| Usage | Meaning |
|---|---|
| `a & b` | Bitwise AND |
| `a && b` | Logical AND |
| `&a` | Address-of operator |
| `int &b = a` | Reference declaration (alias) |

Remember that the same symbol can perform different operations depending on where it is used.

---

# 3. What Are Pointers?

A **pointer is a special type of variable that stores the memory address of another variable.**

Normal variables store values, whereas pointers store memory addresses.

For example:

```cpp
int a = 10;
```

Suppose the memory address of `a` is `100`.

We can visualize it as:

| Variable | Memory Address | Stored Value |
|---|---:|---:|
| `a` | 100 | 10 |

Now, suppose we want to store the address of `a` in another variable.

For this purpose, we use a pointer.

### 3.1 Pointer Declaration Syntax

```cpp
int* ptr;
```

Or:

```cpp
int *ptr;
```

Both declarations are valid.

Explanation:

- `int` represents the data type.
- `*` indicates that we are declaring a pointer.
- `ptr` is the pointer variable's name.

### 3.2 Assigning an Address to a Pointer

```cpp
int a = 10;

int* ptr = &a;
```

Here:
- `a` stores the value `10`.
- `&a` gives the memory address of `a`.
- `ptr` stores that memory address.

Suppose the memory representation is:

| Variable | Memory Address | Stored Value |
|---|---:|---:|
| `a` | 100 | 10 |
| `ptr` | 300 | 100 |

Notice the difference:

- `a` stores `10`.
- `ptr` stores `100`, which is the address of `a`.
- `ptr` itself also has its own memory address, which is `300` in this example.

### 3.3 Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int* ptr = &a;

    cout << ptr << endl;
    cout << &a << endl;
    cout << &ptr << endl;

    return 0;
}
```

Explanation:

| Expression | Meaning |
|---|---|
| `ptr` | Address stored inside the pointer |
| `&a` | Address of variable `a` |
| `&ptr` | Address of the pointer variable itself |

**Important:** `ptr` and `&a` will contain the same address because the pointer stores the address of `a`.

However, `&ptr` will be a different address because the pointer itself is another variable.

### 3.4 Pointers of Different Data Types

A pointer's type should match the type of variable whose address it stores.

Example:

```cpp
int a = 10;
int* ptr = &a;

float price = 100.25f;
float* ptr2 = &price;
```

Here:
- `ptr` is an integer pointer.
- `ptr2` is a float pointer.

The pointer type determines the type of object it points to and affects pointer arithmetic.

---

# 4. Pointer to Pointer

A pointer can store the address of another pointer.

Such a pointer is called a **Pointer to Pointer** or a **Double Pointer**.

### 4.1 Declaration Syntax

```cpp
int** ptr2;
```

Explanation:

- `int*` represents an integer pointer.
- `int**` represents a pointer to an integer pointer.

### 4.2 Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int* ptr = &a;

    int** parentPtr = &ptr;

    cout << &ptr << endl;
    cout << parentPtr << endl;

    return 0;
}
```

Suppose our memory representation is:

| Variable | Memory Address | Stored Value |
|---|---:|---:|
| `a` | 100 | 10 |
| `ptr` | 300 | 100 |
| `parentPtr` | 1000 | 300 |

Explanation:

1. `a` stores `10`.
2. `ptr` stores the address of `a`, which is `100`.
3. `parentPtr` stores the address of `ptr`, which is `300`.

Therefore:

```cpp
parentPtr = &ptr;
```

**Important:** A double pointer stores the address of another pointer, not directly the value of the original variable.

---

# 5. Dereferencing Operator (`*`)

The dereferencing operator is represented by the `*` symbol.

Its purpose is to access the value stored at a particular memory address.

In simple words:

**Dereferencing means accessing the value stored at the address contained in a pointer.**

### 5.1 Basic Example

```cpp
int a = 10;

int* ptr = &a;

cout << *ptr;
```

Output:

```text
10
```

Explanation:

- `ptr` contains the address of `a`.
- `*ptr` accesses the value stored at that address.
- Therefore, the output is `10`.

### 5.2 Dereferencing an Address Directly

```cpp
int a = 10;

cout << *(&a);
```

Output:

```text
10
```

Why?

- `&a` gives the address of `a`.
- `*(&a)` accesses the value stored at that address.
- The value is `10`.

### 5.3 Dereferencing a Pointer to Pointer

Consider:

```cpp
int a = 10;

int* ptr = &a;

int** parentPtr = &ptr;
```

Remember the memory representation:

| Variable | Stored Value |
|---|---:|
| `a` | 10 |
| `ptr` | Address of `a` (100) |
| `parentPtr` | Address of `ptr` (300) |

Now understand the following expressions:

**Expression 1:**

```cpp
*parentPtr
```

This accesses the value stored at the address of `ptr`.

Therefore, the result is the address of `a` (100).

**Expression 2:**

```cpp
**parentPtr
```

This dereferences the result again.

- First dereference: Gets the address of `a`.
- Second dereference: Gets the value stored at the address of `a`.

Result:

```text
10
```

### 5.4 Dereferencing Summary

| Expression | Result |
|---|---|
| `ptr` | Address of `a` |
| `*ptr` | Value of `a` |
| `parentPtr` | Address of `ptr` |
| `*parentPtr` | Value of `ptr` (address of `a`) |
| `**parentPtr` | Value of `a` |

**Key Concept:** Every additional `*` dereferences one more pointer level.

---

# 6. Null Pointers

A **Null Pointer** is a pointer that does not point to a valid object or memory location.

It is used to indicate that a pointer currently does not hold a valid address.

### 6.1 Declaration

The lecture demonstrates:

```cpp
int* ptr = NULL;
```

A modern C++ alternative is:

```cpp
int* ptr = nullptr;
```

### 6.2 Why Do We Need Null Pointers?

Consider:

```cpp
int* ptr;

cout << ptr;
```

Here, the pointer has not been initialized.

It may contain an unpredictable value, commonly called a **garbage value**.

We should not use an uninitialized pointer because it may contain an invalid address.

Instead, initialize it:

```cpp
int* ptr = nullptr;
```

Now the pointer explicitly indicates that it is not pointing to a valid object.

### 6.3 Output of a Null Pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    cout << ptr;

    return 0;
}
```

A null pointer is commonly displayed as:

```text
0
```

Its exact display representation is implementation-dependent.

### 6.4 Can We Dereference a Null Pointer?

No.

Example:

```cpp
int* ptr = nullptr;

cout << *ptr;
```

This results in undefined behavior. It may cause a segmentation fault or program crash.

Why?

Because the pointer does not point to a valid object.

**Important:** Never dereference a null pointer.

### 6.5 Where Are Null Pointers Used?

Null pointers are particularly useful in:

- Linked Lists
- Trees
- Dynamic Data Structures

For example, a node's next pointer in a linked list can be null when there is no next node.

---

# 7. Practice Question: Understanding Pointers

Consider the following:

```cpp
int a = 5;

int* p = &a;

int** q = &p;
```

Suppose the memory addresses are:

| Variable | Address | Stored Value |
|---|---:|---:|
| `a` | 100 | 5 |
| `p` | 500 | 100 |
| `q` | 700 | 500 |

Let's evaluate the expressions.

### Question 1

```cpp
cout << *p;
```

Explanation:

- `p` stores `100`.
- Address `100` contains the value `5`.
- Therefore, `*p` gives `5`.

Answer: `5`

### Question 2

```cpp
cout << **q;
```

Explanation:

- `q` stores `500`.
- Address `500` contains `100`.
- Address `100` contains `5`.

Answer: `5`

### Question 3

```cpp
cout << p;
```

`p` stores the address of `a`.

Answer: `100`

### Question 4

```cpp
cout << *q;
```

- `q` stores `500`.
- Address `500` contains `100`.

Answer: `100`

### Complete Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;

    int* p = &a;

    int** q = &p;

    cout << *p << endl;
    cout << **q << endl;

    cout << p << endl;
    cout << *q << endl;

    cout << &a << endl;

    return 0;
}
```

Notice that:

```cpp
p == *q == &a
```

All three expressions represent the same memory address.

---

# 8. Pass by Value vs Pass by Reference

When we pass arguments to functions in C++, there are different ways of passing data.

Two important concepts are:

1. Pass by Value
2. Pass by Reference

### 8.1 Pass by Value

In pass by value, a copy of the original variable is passed to the function.

Example:

```cpp
#include <iostream>
using namespace std;

void changeA(int a) {
    a = 20;
}

int main() {
    int a = 10;

    changeA(a);

    cout << a;

    return 0;
}
```

Output:

```text
10
```

Why?

- The original variable `a` contains `10`.
- A copy of `a` is passed to the function.
- The function changes the copied value to `20`.
- The original variable remains unchanged.

### 8.2 Pass by Reference Using Pointers

We can use pointers to modify the original variable inside a function.

Instead of passing the variable's value, we pass its memory address.

Example:

```cpp
#include <iostream>
using namespace std;

void changeA(int* ptr) {
    *ptr = 20;
}

int main() {
    int a = 10;

    changeA(&a);

    cout << a;

    return 0;
}
```

Output:

```text
20
```

Explanation:

1. Initially, `a = 10`.
2. We pass `&a` to the function.
3. The function receives the address through the pointer `ptr`.
4. `*ptr` accesses the original variable.
5. We assign `20` to that memory location.
6. The original variable is now updated.

**Important:**

```cpp
changeA(&a);
```

Passes the address of `a`.

```cpp
*ptr = 20;
```

Changes the original value through the pointer.

---

# 9. References (Aliases) in C++

Another way to implement pass by reference is through references.

A reference is an **alias (another name) for an existing variable**.

For example, imagine Tony Stark and Iron Man.

Both names refer to the same person.

Similarly, two variable names can refer to the same memory location.

### 9.1 Reference Declaration

```cpp
int a = 10;

int& b = a;
```

Here:

- `a` is the original variable.
- `b` is a reference to `a`.
- Both refer to the same memory location.

If we change `b`, the value of `a` also changes.

### 9.2 Example: Pass by Reference Using References

```cpp
#include <iostream>
using namespace std;

void changeA(int& b) {
    b = 20;
}

int main() {
    int a = 10;

    changeA(a);

    cout << a;

    return 0;
}
```

Output:

```text
20
```

Explanation:

1. `a` is initialized with `10`.
2. We pass `a` to the function.
3. The function receives it as `int& b`.
4. `b` becomes an alias for `a`.
5. Changing `b` changes the original variable.

### 9.3 Pass by Reference: Two Approaches

| Method | Function Parameter | Function Call |
|---|---|---|
| Using pointers | `int* ptr` | `changeA(&a)` |
| Using references | `int& b` | `changeA(a)` |

**Important:** The `&` in a reference declaration does not mean address-of. It indicates that the parameter is a reference.

### 9.4 Why Are References Important in DSA?

References are commonly used when we want to avoid unnecessary copying of large objects.

For example:

```cpp
void solve(vector<int>& nums) {
    // Operations on the original vector
}
```

Here, `nums` refers to the original vector.

Changes made to `nums` will affect the original vector.

---

# 10. Array Pointers

Arrays and pointers are closely related in C++.

Consider:

```cpp
int arr[] = {1, 2, 3, 4, 5};
```

The array contains five integer elements.

In most expressions, the array name decays into a pointer to its first element.

Therefore:

```cpp
arr
```

generally represents the address of the first element.

### 10.1 Array Memory Representation

Suppose the array is stored at the following addresses:

| Index | Value | Address |
|---|---:|---:|
| 0 | 1 | 100 |
| 1 | 2 | 104 |
| 2 | 3 | 108 |
| 3 | 4 | 112 |
| 4 | 5 | 116 |

Assuming each integer occupies 4 bytes.

The array elements are stored in contiguous memory locations.

### 10.2 Printing the Array Address

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl;

    return 0;
}
```

The output will be the address of the first element.

### 10.3 Dereferencing the Array Name

```cpp
cout << *arr;
```

Output:

```text
1
```

Why?

- `arr` points to the first element.
- `*arr` accesses the value at the first element.
- The first element is `1`.

### 10.4 Accessing Array Elements Using Pointer Arithmetic

We can access array elements using:

```cpp
*(arr + 0)
*(arr + 1)
*(arr + 2)
*(arr + 3)
```

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << *(arr + 0) << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << *(arr + 3) << endl;

    return 0;
}
```

Output:

```text
1
2
3
4
```

This works because the array elements are stored in contiguous memory locations.

**Important:**

```cpp
arr[i]
```

is equivalent to:

```cpp
*(arr + i)
```

---

# 11. Constant Pointers

A constant pointer is a pointer whose stored address cannot be changed after initialization.

The array name behaves like a non-modifiable pointer expression in the context discussed in this lecture.

### 11.1 Normal Pointer

Consider:

```cpp
int a = 15;
int b = 10;

int* ptr = &a;

ptr = &b;
```

This is valid.

Why?

Because a normal pointer can be reassigned to point to another compatible variable.

### 11.2 Array Name Cannot Be Reassigned

Consider:

```cpp
int arr[] = {1, 2, 3, 4, 5};

arr = &a;
```

This is invalid.

The array name cannot be assigned another address.

The reason is that an array is a fixed block of elements, and its name is not a modifiable pointer variable.

### 11.3 Important Difference

| Normal Pointer | Array Name |
|---|---|
| Stores an address | Identifies an array |
| Can be reassigned | Cannot be reassigned |
| Can point to different compatible variables | Remains associated with its array |

**Technical note:** An array name is not literally a pointer variable. It converts to a pointer to its first element in most expressions.

---

# 12. Pointer Arithmetic

Pointer arithmetic means performing mathematical operations on pointers.

Unlike normal variables, pointer arithmetic depends on the data type of the pointer.

For example, incrementing an integer pointer moves it forward by the size of one integer, not simply one byte.

### 12.1 Increment Operator (`++`)

Consider:

```cpp
int a = 10;

int* ptr = &a;
```

Suppose the address of `a` is:

```text
100
```

If we perform:

```cpp
ptr++;
```

The pointer moves forward by the size of its data type.

Assuming an integer occupies 4 bytes:

```text
Original address = 100
After increment  = 104
```

If we increment again:

```text
104 + 4 = 108
```

### 12.2 Decrement Operator (`--`)

Similarly:

```cpp
ptr--;
```

Moves the pointer backward by the size of its data type.

For an integer pointer:

```text
Original address = 100
After decrement  = 96
```

### 12.3 Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int* ptr = &a;

    cout << ptr << endl;

    ptr++;

    cout << ptr << endl;

    ptr--;

    cout << ptr << endl;

    return 0;
}
```

Assuming a 4-byte integer:

- First output: Original address.
- Second output: Original address + 4.
- Third output: Original address again.

### 12.4 Pointer Arithmetic Depends on Data Type

| Pointer Type | Typical Size | Increment |
|---|---:|---:|
| `char*` | 1 byte | +1 byte |
| `int*` | 4 bytes | +4 bytes |
| `double*` | 8 bytes | +8 bytes |

Actual type sizes are implementation-dependent.

---

# 13. Adding and Subtracting Numbers from Pointers

We can add or subtract integer values from pointers.

The effect is similar to incrementing or decrementing a pointer.

### 13.1 Adding a Number

Consider:

```cpp
int* ptr;
ptr = ptr + 1;
```

For an integer pointer, adding `1` moves it forward by one integer-sized position.

Assuming an integer occupies 4 bytes:

```text
ptr + 1 = Original address + 4
```

Similarly:

```cpp
ptr = ptr + 3;
```

Moves the pointer forward by three integer positions.

Total movement:

```text
3 × 4 = 12 bytes
```

### 13.2 Example

Suppose the original address is `100`.

| Expression | Resulting Address |
|---|---:|
| `ptr` | 100 |
| `ptr + 1` | 104 |
| `ptr + 2` | 108 |
| `ptr + 3` | 112 |

### 13.3 Subtracting a Number

Similarly:

```cpp
ptr = ptr - 2;
```

For an integer pointer, the address moves backward by:

```text
2 × 4 = 8 bytes
```

---

# 14. Pointer Arithmetic with Arrays

One of the most useful applications of pointer arithmetic is accessing array elements.

Consider:

```cpp
int arr[] = {1, 2, 3, 4, 5};
```

Suppose the addresses are:

| Index | Value | Address |
|---|---:|---:|
| 0 | 1 | 100 |
| 1 | 2 | 104 |
| 2 | 3 | 108 |
| 3 | 4 | 112 |
| 4 | 5 | 116 |

We already know:

```cpp
arr
```

Points to the first element.

Now:

```cpp
arr + 1
```

Points to the second element.

Similarly:

```cpp
arr + 2
```

Points to the third element.

### 14.1 Accessing Elements

To access the actual values, we dereference the pointer.

```cpp
*(arr + 0)  // 1
*(arr + 1)  // 2
*(arr + 2)  // 3
*(arr + 3)  // 4
```

### 14.2 Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << *(arr + 0) << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << *(arr + 3) << endl;

    return 0;
}
```

Output:

```text
1
2
3
4
```

**Remember:**

- `arr + 1` gives the address of the second element.
- `*(arr + 1)` gives the value of the second element.

---

# 15. Subtracting Two Pointers

C++ allows us to subtract two pointers of compatible types when they point into the same array (or one past its end).

The result represents the number of elements between them, not the number of bytes.

### 15.1 Example

Suppose:

```text
Address 100 → First integer
Address 104 → Second integer
Address 108 → Third integer
```

If:

- `ptr2` points to address `100`.
- `ptr1` points to address `108`.

Then:

```cpp
ptr1 - ptr2
```

Returns:

```text
2
```

Why?

There are two integer positions between these addresses.

### 15.2 Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40};

    int* ptr2 = arr;
    int* ptr1 = arr + 2;

    cout << ptr1 - ptr2;

    return 0;
}
```

Output:

```text
2
```

**Important:** Pointer subtraction gives the difference in elements, not bytes.

---

# 16. Comparing Two Pointers

Pointers can also be compared using relational operators.

Examples:

```cpp
<
>
<=
>=
==
!=
```

For pointers into the same array, relational comparisons can be used to determine their relative positions.

### 16.1 Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40};

    int* ptr1 = arr;
    int* ptr2 = arr + 2;

    cout << (ptr1 < ptr2) << endl;
    cout << (ptr1 == ptr2) << endl;
    cout << (ptr1 != ptr2) << endl;

    return 0;
}
```

Output:

```text
1
0
1
```

Explanation:

| Expression | Result | Meaning |
|---|---:|---|
| `ptr1 < ptr2` | 1 | True |
| `ptr1 == ptr2` | 0 | False |
| `ptr1 != ptr2` | 1 | True |

In C++, `1` represents true and `0` represents false when printed as an integer.

**Important:** Relational pointer comparisons should be used with pointers into the same array. Do not assume that comparing arbitrary unrelated memory addresses has the same portable meaning.

---

# 17. Practice Question: Pointer Arithmetic

Consider the following array:

```cpp
int arr[] = {10, 20, 30, 40};

int* ptr = arr;
```

Suppose the memory representation is:

| Index | Value | Address |
|---|---:|---:|
| 0 | 10 | 100 |
| 1 | 20 | 104 |
| 2 | 30 | 108 |
| 3 | 40 | 112 |

Now evaluate the following expressions:

### Expression 1

```cpp
*(ptr + 1)
```

Explanation:

- `ptr` points to index 0.
- `ptr + 1` points to index 1.
- Dereferencing accesses its value.

Answer:

```text
20
```

### Expression 2

```cpp
*(ptr + 3)
```

Explanation:

- `ptr + 3` points to index 3.
- Index 3 contains `40`.

Answer:

```text
40
```

### Expression 3

```cpp
ptr++;
```

After incrementing:

- The pointer moves forward by one integer position.
- It now points to index 1.

Therefore:

```cpp
*ptr
```

Returns:

```text
20
```

### Complete Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40};

    int* ptr = arr;

    cout << *(ptr + 1) << endl;
    cout << *(ptr + 3) << endl;

    ptr++;

    cout << *ptr << endl;

    return 0;
}
```

Output:

```text
20
40
20
```

---

# 18. Quick Revision: Important Operators

Two operators are especially important in the pointer chapter:

## 18.1 Address-of Operator (`&`)

The `&` operator has multiple uses:

| Expression | Purpose |
|---|---|
| `a & b` | Bitwise AND |
| `a && b` | Logical AND |
| `&a` | Get the memory address of `a` |
| `int& b = a` | Create a reference to `a` |

## 18.2 Asterisk Operator (`*`)

The `*` operator also has multiple uses:

| Expression | Purpose |
|---|---|
| `a * b` | Multiplication |
| `int* ptr` | Declare a pointer |
| `*ptr` | Dereference a pointer |

The meaning depends on the context in which the operator is used.

---

# 19. Important Interview and Placement Questions

1. What is a pointer in C++?
2. What is a memory address?
3. What is the purpose of the address-of operator?
4. What is the difference between `ptr` and `*ptr`?
5. What is the difference between `&a` and `&ptr`?
6. What is a pointer to pointer?
7. What does `int** ptr` mean?
8. What is dereferencing?
9. What happens when we dereference a null pointer?
10. What is a null pointer?
11. What is the difference between pass by value and pass by reference?
12. How can we implement pass by reference using pointers?
13. What is a reference or alias?
14. What is the relationship between arrays and pointers?
15. Why can't we reassign an array name?
16. What is pointer arithmetic?
17. How does pointer increment work?
18. Why does an integer pointer generally move by 4 bytes when incremented?
19. What is the difference between `arr[i]` and `*(arr + i)`?
20. What happens when we subtract two pointers?

---

# 20. Final Summary

In this lecture, we covered the following concepts:

| Concept | Key Learning |
|---|---|
| Memory Address | Identifies where a variable is stored |
| Address-of (`&`) | Retrieves the address of a variable |
| Pointer | Stores the address of another variable |
| Double Pointer (`**`) | Stores the address of another pointer |
| Dereferencing (`*`) | Retrieves the value stored at an address |
| Null Pointer | Does not point to a valid object |
| Pass by Value | Passes a copy of the variable |
| Pass by Reference | Allows modification of the original variable |
| References | Provide another name for an existing variable |
| Array Pointers | Array names convert to pointers to their first elements in most expressions |
| Constant Pointer | Its stored address cannot be reassigned |
| Pointer Arithmetic | Performs arithmetic based on the pointed-to data type |
| Pointer Subtraction | Calculates the difference in element positions |
| Pointer Comparison | Compares pointer positions where the comparison is valid |

## Most Important Things to Remember

1. A pointer stores an address, not the original variable's value.
2. `&a` gives the address of variable `a`.
3. `*ptr` gives the value stored at the address contained in `ptr`.
4. A double pointer stores the address of another pointer.
5. `**ptr` dereferences two pointer levels.
6. Never dereference a null or uninitialized pointer.
7. Pass by reference can be implemented using pointers or references.
8. An array name generally behaves like a pointer to its first element in expressions.
9. Pointer arithmetic depends on the data type.
10. Adding `1` to an integer pointer generally moves it forward by 4 bytes on systems where `sizeof(int) == 4`.
11. `arr[i]` is equivalent to `*(arr + i)`.
12. Subtracting two pointers into the same array gives the difference in element positions.

