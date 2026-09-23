# Linked List

## Characteristics:
- Stores data in a linear fashion.
- The address of each node is random (not contiguous like arrays).
- Dynamic in nature (nodes can be added/removed at runtime).
- Each node consists of:
  - `data` (the value stored)
  - `pointer` (which stores the address of the next node)
- The last node stores a `NULL` pointer to indicate the end of the list.
- `Head` pointer points to the address of the first node.
- We use the `head` pointer to access all nodes in the list.
- `Tail` pointer is optional, but useful in certain operations (especially in doubly linked lists).
- It is a data structure that allows forward traversal using a temporary pointer while preserving the first node’s address in the `head`.
- **Time Complexity**: `O(n)` in the worst case for operations like search.

## Implementation Methods:
1. Using STL (Standard Template Library).
2. Using OOP (Object-Oriented Programming) with classes.

---

# Basic Operations in Linked List

## 1. Push Front
### Cases:
1. **Head is NULL:**  
   - Create a new node.  
   - Set both `head` and `tail` to this node.

2. **Head is not NULL:**  
   - Create a new node.  
   - `newNode->next = head`  
   - `head = newNode`

## 2. Push Back
### Cases:
1. **Head is NULL:**  
   - Create a new node.  
   - Set both `head` and `tail` to this node.

2. **Head is not NULL:**  
   - Create a new node.  
   - `tail->next = newNode`  
   - `tail = newNode`

## 3. Pop Front
- Check if list is empty.
- Save `head` in a temporary node.
- Move `head` to `head->next`.
- Delete the temporary node.

## 4. Pop Back
- Check if list is empty.
- Traverse to the second-last node.
- Delete the last node.
- Set `tail` to the second-last node.

## 5. Insert at Position
- If `pos == 0`: call `push_front`.
- Else, traverse to `pos - 1` and insert the new node.

## 6. Search
- Traverse the list and return the index of the first node matching the key.
- Return `-1` if not found.

## 7. Print Linked List
- Traverse the list from `head` and print each node's data.

---
