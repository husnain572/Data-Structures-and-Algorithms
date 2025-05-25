## Circular Linked List - Short Theory

A **circular linked list** is a type of linked list where the last node points back to the first node, forming a circle. It can be:

- **Singly Circular**: Each node has a single pointer to the next node; the last node points to the head.
- **Doubly Circular**: Each node has two pointers — one to the next and one to the previous node; the last node connects to the head, and the head’s previous points to the tail.

### Key Features:
- No `NULL` at the end.
- Useful for applications requiring continuous traversal (e.g., round-robin scheduling).
- Operations like insertion and deletion can be done at any point with proper pointer handling.
