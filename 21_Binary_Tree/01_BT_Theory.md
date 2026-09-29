# Binary Tree

## 1. Generic Tree

A **tree** is a **hierarchical data structure** made up of nodes connected by branches (edges).

### Basic Terminology

* **Node:** An individual element of a tree.
* **Root Node:** The top-most node of the tree. It has no parent.
* **Parent Node:** A node that has one or more children.
* **Child Node:** A node directly connected below another node.
* **Branch / Edge:** Connection between two nodes.

### Real-World Example

A computer's **directory/folder structure** is a common example of hierarchical data:

```text
Computer
│
├── Documents
│   ├── Notes
│   └── Assignments
│
├── Pictures
│
└── Videos
```


# 2. Binary Tree

A **Binary Tree** is a hierarchical data structure in which every node has **at most two children**:

* Left child
* Right child

A node can therefore have:

```text
0 children
1 child
2 children
```

Example:

```text
        1
       / \
      2   3
     / \
    4   5
```


# 3. Important Binary Tree Terminology

### Root Node

The top-most node.

```text
        1  ← Root
       / \
      2   3
```

### Leaf Node

A node with **no children**.

```text
        1
       / \
      2   3
     / \
    4   5

Leaf nodes = 4, 5, 3
```

### Sibling Nodes

Nodes having the **same parent** are called siblings.

```text
        1
       / \
      2   3
```

`2` and `3` are siblings.

### Parent and Child

```text
        1
       / \
      2   3
```

* `1` is parent of `2` and `3`.
* `2` and `3` are children of `1`.

# 4. Level of a Node

A **level** represents the position of a node relative to the root.

There are two common conventions.

### Level starts from 0

```text
          1          Level 0
         / \
        2   3        Level 1
       / \
      4   5          Level 2
```

### Level starts from 1

```text
          1          Level 1
         / \
        2   3        Level 2
       / \
      4   5          Level 3
```

Always check which convention is being used.

# 5. Height and Depth

These terms are related but should not be treated as exactly the same thing.

### Depth

**Depth of a node** = number of edges from the root to that node.

For example:

```text
          1
         /
        2
       /
      4
```

Using root depth `0`:

```text
Depth(1) = 0
Depth(2) = 1
Depth(4) = 2
```

### Height of a Node

**Height of a node** = number of edges on the longest path from that node to a leaf.

For the tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

```text
Height(4) = 0
Height(5) = 0
Height(2) = 1
Height(3) = 0
Height(1) = 2
```

### Height of the Tree

The height of the tree is the height of its root.

> Some lectures define height using number of **nodes/levels** instead of edges. Always confirm the convention being used.

# 6. Subtree

A **subtree** is a smaller tree formed from a node and all of its descendants.

Subtrees are defined **in the context of a particular node**.

Example:

```text
          1
         / \
        2   3
       / \
      4   5
```

The subtree rooted at `2` is:

```text
        2
       / \
      4   5
```

Every node can be considered the root of its own subtree.


# 7. Types of Binary Trees

## Full Binary Tree

Every node has either:

* `0` children, or
* `2` children.

No node has exactly one child.

```text
        1
       / \
      2   3
```

## Perfect Binary Tree

All internal nodes have two children and **all leaf nodes are at the same level**.

Every level is completely filled.

```text
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```


## Complete Binary Tree

* Every level is completely filled except possibly the last.
* The last level is filled **from left to right**.

Example:

```text
          1
        /   \
       2     3
      / \   /
     4   5 6
```

## Balanced Binary Tree

A binary tree is balanced when the height difference between the left and right subtrees of a node satisfies the required balance condition.

For the common height-balanced definition:

```text
|height(left) - height(right)| <= 1
```

This condition must hold for the relevant nodes throughout the tree.

# 8. Binary Tree Traversals

Traversal means **visiting all nodes of a tree in a specific order**.

There are four important traversals.

| Traversal   | Order                         |
| ----------- | ----------------------------- |
| Preorder    | Root → Left → Right           |
| Inorder     | Left → Root → Right           |
| Postorder   | Left → Right → Root           |
| Level Order | Level by level, left to right |

## Preorder

```text
Root → Left → Right
```

Example:

```text
        1
       / \
      2   3
     / \
    4   5
```

Preorder:

```text
1 2 4 5 3
```

## Inorder

```text
Left → Root → Right
```

For the same tree:

```text
4 2 5 1 3
```

## Postorder

```text
Left → Right → Root
```

For the same tree:

```text
4 5 2 3 1
```

## Level Order

Visits nodes **level by level from left to right**.

```text
        1
       / \
      2   3
     / \
    4   5
```

Level order:

```text
1 2 3 4 5
```

Level order traversal uses **BFS (Breadth-First Search)** and a **queue**.


# 9. General Recursion Pattern

Many binary tree problems use recursion.

Basic structure:

```cpp
solve(root) {

    solve(root->left);

    solve(root->right);

    // process root
}
```

The exact position of the root-processing step determines the traversal.

### Preorder

```cpp
process(root);

solve(root->left);
solve(root->right);
```

### Inorder

```cpp
solve(root->left);

process(root);

solve(root->right);
```

### Postorder

```cpp
solve(root->left);
solve(root->right);

process(root);
```


# 10. Building a Binary Tree from Preorder

A binary tree can be constructed from a preorder sequence if `-1` represents a `NULL` child.

Example:

```text
Preorder:
1 2 -1 -1 3 4 -1 -1 5 -1 -1
```

The order is:

```text
Root → Left → Right
```

`-1` means:

```text
No node / NULL
```

The resulting tree is:

```text
          1
         / \
        2   3
           / \
          4   5
```

### Important Idea

When building recursively:

> Complete the left and right subtrees of a node before returning that node.

# 11. Building Logic

Use an index to keep track of the current position in the preorder array.

```cpp
static int idx = -1;

Node* buildTree(vector<int>& preorder) {

    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);

    root->right = buildTree(preorder);

    return root;
}
```

### Dry Run Idea

For:

```text
1 2 -1 -1 3 4 -1 -1 5 -1 -1
```

Start:

```text
idx = 0 → 1
```

Create node `1`.

Then recursively build:

```text
left of 1 → 2
```

For `2`:

```text
left → -1
right → -1
```

So node `2` is complete.

Then return to `1` and build:

```text
right of 1 → 3
```

Then recursively construct its left and right subtrees.

This continues until the entire tree is built.

# 12. Pattern Recognition

When you see these keywords in a problem, think about these common patterns:

| Problem Keyword                 | Common Approach           |
| ------------------------------- | ------------------------- |
| Traversal                       | DFS / BFS                 |
| Level order                     | BFS + Queue               |
| Height / Depth                  | DFS + Recursion           |
| Diameter                        | DFS / Postorder           |
| Balanced                        | DFS + Recursion           |
| Symmetric                       | DFS / Recursion           |
| Same Tree                       | DFS / Recursion           |
| Lowest Common Ancestor          | LCA pattern               |
| Serialization / Deserialization | Tree traversal + encoding |
| Root-to-leaf path               | DFS + Backtracking        |
| Path Sum                        | DFS + Recursion           |
| Kth smallest/largest            | Often Inorder traversal   |

These are **patterns to recognize**, not rules that every problem must follow.


# 13. Important Revision Points

Remember:

```text
Tree
 ↓
Hierarchical data structure

Binary Tree
 ↓
At most 2 children

Children
 ↓
Left + Right

Leaf
 ↓
0 children

Sibling
 ↓
Same parent

Subtree
 ↓
Node + its descendants

Preorder
 ↓
Root → Left → Right

Inorder
 ↓
Left → Root → Right

Postorder
 ↓
Left → Right → Root

Level Order
 ↓
BFS + Queue
```

### Most Important Things to Remember

* Binary tree ≠ binary search tree.
* A binary tree can have at most **two children**.
* Left and right children are distinct.
* Recursion is heavily used for DFS tree problems.
* Level order uses a **queue**.
* `NULL` represents the absence of a child.
* Preorder = Root first.
* Inorder = Root in the middle.
* Postorder = Root last.
* Height and depth are different concepts.
* Always check whether levels/height are counted from `0` or `1`, and whether height means edges or nodes/levels.
