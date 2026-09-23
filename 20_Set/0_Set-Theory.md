# Set in C++ STL  

## Overview  
A **set** is a container in the C++ Standard Template Library (STL) that stores **unique values** in an **ordered** manner.

### Characteristics of a Set:
- **STL Container**: Used to store **unique values**.  
- **Ordered Storage**: Values are stored in an **increasing** or **decreasing** order.  
- **No Indexing**: Elements are accessed by their values; **indexing is not supported**.  
- **Immutability**: Once a value is inserted, it **cannot be modified**.  

---

## Advantages of Set  
**Unique Values**: Automatically ensures that elements are unique.  
**Ordered**: Maintains elements in a sorted order.  
**Dynamic Size**: Resizes dynamically to avoid overflow.  
**Efficiency**: **Insertion, deletion, and search** operations take **O(log N)** time.  

## Disadvantages of Set
**No Indexing**: Cannot access elements by index like an array.  
**Memory Usage**: Typically uses **more memory** than arrays.  
 **Large Datasets**: May not be suitable for **very large datasets** due to performance considerations.  

---

## Declaration of a Set  

```cpp
#include <set>

// Declaration of a set
std::set<data_type> set_name;

// Example with integer values:
std::set<int> set1 = {1, 5, 4, 3};

// For a set with elements in decreasing order:
std::set<data_type, std::greater<data_type>> setName;
```

---

## Inserting Elements into a Set  
- **Syntax**:  
  
  set_name.insert(value);
  
- **Example**:  
  ```
  set1.insert(5);
  set1.insert(1);
  set1.insert(2);
  ```
- **Time Complexity**: **O(log N)** per insertion.  
- **Note**: The `insert` function returns an iterator pointing to the inserted value.  

---

## Traversal of a Set  
- **Iterator Requirement**: A set **must** be traversed using iterators.  
- **Functions**:  
  - `set_name.begin()`: Returns an iterator to the **first element**.  
  - `set_name.end()`: Returns an iterator to the position **just after the last element**.  

---

## Deleting Elements from a Set  
- **By Value**:  
  ```
  setName.erase(value);
  ```
- **By Iterator/Position**:  
  ```
  setName.erase(position);
  ```
- **Range Deletion**:  
  ```
  setName.erase(start_position, end_position);
  ```
  - Deletes elements starting from **start_position** (inclusive) to **end_position** (exclusive).  
  - **Time Complexity**: **O(N)**.  

---

## Member Functions of a Set  

### 1. **Capacity Functions**  
- `size()`: Returns the **number of elements** in the set.  
- `max_size()`: Returns the **maximum number of elements** the set can hold.  
- `empty()`: Returns **true** if the set is empty, otherwise **false**.  

### 2. **Element Access**  
- `count(element)`: Returns **0 or 1**, since sets store **unique values**.  
- `find(element)`: Returns an **iterator** to the element if found; otherwise, returns `end()`.  

### 3. **Bound Functions**  
- `lower_bound(element)`: Returns an **iterator** pointing to the element **if present**, or the next greater element if not.  
- `upper_bound(element)`: Returns an **iterator** pointing to the element **just greater** than the given element.  

### 4. **Iterator Functions for Reverse Traversal**  
- `rbegin()`: Returns a **reverse iterator** pointing to the first element in reverse order.  
- `rend()`: Returns a **reverse iterator** pointing to the position after the last element in reverse order.  

---
