# Binary Tree Patterns

## 1. Pattern Recognition

When reading a binary tree problem, certain keywords often indicate a common approach.

| Problem Keywords                | Common Pattern / Approach |
| ------------------------------- | ------------------------- |
| Traversal                       | DFS / BFS                 |
| Level Order                     | BFS + Queue               |
| Height                          | DFS + Recursion           |
| Depth                           | DFS + Recursion           |
| Diameter                        | DFS / Postorder           |
| Balanced                        | DFS + Recursion           |
| Symmetric                       | DFS + Recursion           |
| Same Tree                       | DFS + Recursion           |
| Lowest Common Ancestor          | LCA Pattern               |
| Serialization / Deserialization | Tree Traversal + Encoding |
| Path Sum                        | DFS + Recursion           |
| Root-to-Leaf Path               | DFS + Backtracking        |
| Kth Smallest / Largest          | Inorder Traversal         |

These are common patterns, not strict rules. The actual approach depends on the problem.

---

# 2. DFS Pattern

Depth First Search explores a tree by going deeper into its subtrees.

The general recursive structure is:

```cpp
solve(root) {

    solve(root->left);

    solve(root->right);

    // process root
}
```

The position of `process root` determines the traversal.

### Preorder

```text
Root → Left → Right
```

```cpp
process(root);
solve(root->left);
solve(root->right);
```

### Inorder

```text
Left → Root → Right
```

```cpp
solve(root->left);
process(root);
solve(root->right);
```

### Postorder

```text
Left → Right → Root
```

```cpp
solve(root->left);
solve(root->right);
process(root);
```
# 3. BFS Pattern

Breadth First Search visits nodes level by level.

For a binary tree, BFS is commonly implemented using a `queue`.

```cpp
queue<Node*> q;

q.push(root);

while (!q.empty()) {

    Node* curr = q.front();
    q.pop();

    // process curr

    if (curr->left != NULL)
        q.push(curr->left);

    if (curr->right != NULL)
        q.push(curr->right);
}
```

### Remember

```text
DFS → Recursion / Stack
BFS → Queue
```

# 4. Height / Depth Pattern

Height and depth problems commonly use DFS and recursion.

### Height of a Node

```text
height(node)
=
1 + max(
    height(left),
    height(right)
)
```

Base case depends on the convention being used.

For example, when height is measured in edges:

```text
height(NULL) = -1
```

When measured in nodes:

```text
height(NULL) = 0
```

Always check the convention used by the problem.

# 5. Diameter Pattern

The **diameter** is the longest path between two nodes of a tree.

A common DFS/postorder approach calculates the height of the left and right subtrees and uses them to determine the longest path through the current node.

Core idea:

```text
diameter through node
=
left height + right height + 2
```

when height is measured in edges.

The exact implementation can vary depending on the definition used by the problem.

# 6. Balanced Tree Pattern

For a height-balanced tree, compare the heights of the left and right subtrees.

Common condition:

```text
|height(left) - height(right)| <= 1
```

This condition must hold throughout the tree.

A DFS/postorder approach can calculate subtree heights while checking balance.


# 7. Symmetric Tree Pattern

A tree is symmetric if its left and right sides are mirror images.

Compare:

```text
left.left  ↔ right.right
left.right ↔ right.left
```

Common approach:

```text
DFS + Recursion
```

# 8. Same Tree Pattern

To determine whether two trees are identical, recursively compare:

1. Current node values.
2. Left subtrees.
3. Right subtrees.

Conceptually:

```text
sameTree(a, b)

if both NULL
    → true

if one NULL
    → false

if values different
    → false

compare left subtrees
compare right subtrees
```

# 9. Lowest Common Ancestor (LCA)

The **Lowest Common Ancestor** of two nodes is the lowest node in the tree that has both nodes as descendants.

Typical approach:

```text
DFS + Recursion
```

The exact implementation depends on whether the tree is:

* A normal binary tree.
* A Binary Search Tree (BST).

# 10. Path Sum / Root-to-Leaf Path

Problems involving:

```text
Path Sum
Root-to-Leaf Path
All Paths
```

commonly use:

```text
DFS + Recursion
```

If we need to maintain the current path, **backtracking** may be required.

General idea:

```text
Choose node
   ↓
Add node to path
   ↓
Explore children
   ↓
Remove node from path
```

# 11. Kth Smallest / Largest

For a **Binary Search Tree (BST)**:

```text
Inorder traversal
```

visits values in sorted ascending order:

```text
Left → Root → Right
```

Therefore:

```text
1st inorder node → smallest
2nd inorder node → 2nd smallest
...
```

For kth largest, reverse the traversal:

```text
Right → Root → Left
```

**Important:** This property applies to a BST, not to an arbitrary binary tree.

# 12. Serialization / Deserialization

### Serialization

Convert a tree into a format such as a string or sequence so that it can be stored/transmitted.

### Deserialization

Reconstruct the original tree from that representation.

Common approach:

```text
Tree Traversal
+
Encoding/Decoding
```

A traversal must preserve enough information to reconstruct the tree.

For example, using preorder with `NULL` markers:

```text
1 2 -1 -1 3 -1 -1
```

Here `-1` represents a missing child.

# 13. Quick Pattern Cheat Sheet

```text
Traversal
    ↓
DFS / BFS

Level Order
    ↓
BFS + Queue

Preorder
    ↓
Root → Left → Right

Inorder
    ↓
Left → Root → Right

Postorder
    ↓
Left → Right → Root

Height / Depth
    ↓
DFS + Recursion

Diameter
    ↓
DFS + Postorder

Balanced
    ↓
DFS + Height

Symmetric
    ↓
DFS + Mirror Comparison

Same Tree
    ↓
DFS + Recursion

LCA
    ↓
DFS + Recursion

Path Sum
    ↓
DFS + Backtracking

Kth Smallest in BST
    ↓
Inorder

Kth Largest in BST
    ↓
Reverse Inorder

Serialization
    ↓
Traversal + Encoding
```
