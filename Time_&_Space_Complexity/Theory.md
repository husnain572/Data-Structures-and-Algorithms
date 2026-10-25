# Time & Space Complexity

## 1. Why Do We Study Time & Space Complexity?

Time and Space Complexity are important for almost every **Data Structure and Algorithm (DSA)** problem.

They help us:

1. Design efficient algorithms.
2. Compare different algorithms.
3. Understand how an algorithm behaves as the input size increases.
4. Estimate whether a solution will pass coding-platform constraints.
5. Explain our solution during interviews.

In interviews, common questions include:

- What is the **Time Complexity**?
- What is the **Space Complexity**?

---

# 2. Time Complexity

## Definition

**Time Complexity describes how the number of operations performed by an algorithm grows as the input size `n` increases.**

> Time Complexity is **not the actual execution time in seconds**.

For example:

```text
0.05 seconds
```

is actual execution time, which can depend on:

- The machine
- CPU
- Server
- Programming language
- Platform

Time Complexity focuses on the **growth behavior of the algorithm**.

---

# 3. Example — Linear Search

Suppose an array contains `n` elements:

```text
for i = 0 → n-1
    if arr[i] == target
        return i
```

### Worst Case

The target is at the last index.

| Input `n` | Operations |
|---:|---:|
| 1 | ~1 |
| 10 | ~10 |
| 100 | ~100 |
| 100,000 | ~100,000 |

As `n` increases, the number of operations increases approximately linearly.

```text
n ↑  →  operations ↑
```

Therefore:

```text
Time Complexity = O(n)
```

---

# 4. Why Do We Usually Consider the Worst Case?

In DSA, we commonly analyze the **worst-case complexity** because it tells us how the algorithm behaves in the most demanding situation.

Example:

```text
arr = [1, 2, 3, 4, 5]
target = 1
```

The target is found immediately.

```text
Best Case = O(1)
```

But if the target is the last element:

```text
Worst Case = O(n)
```

For interviews and practical analysis, **focus primarily on the worst case** unless the problem specifically asks for something else.

---

# 5. Big-O Notation

**Big-O notation describes the growth rate of an algorithm.**

Common examples:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(2ⁿ)
O(n!)
```

In practical DSA and interviews, calculating the **Big-O complexity** of your solution is extremely important.

---

# 6. Basic Rules for Calculating Big-O

Suppose we have:

```text
4n² + 3n + 5
```

### Rule 1 — Ignore Constants

```text
n² + n + 1
```

### Rule 2 — Keep the Fastest-Growing Term

```text
n²
```

Therefore:

```text
O(n²)
```

### Example 2

```text
100 + 5n² + √n
```

Ignore constants:

```text
1 + n² + √n
```

Keep the fastest-growing term:

```text
n²
```

Therefore:

```text
O(n²)
```

### Remember

When calculating Big-O:

1. Ignore constant factors.
2. Ignore lower-order terms.
3. Keep the fastest-growing term.

---

# 7. Other Complexity Notations

The main notations are:

- **O (Big-O)** → upper-bound notation; commonly used for worst-case analysis.
- **Θ (Theta)** → tight bound.
- **Ω (Omega)** → lower bound.
- **o (small-o)** → strict upper bound.
- **ω (small-omega)** → strict lower bound.

### For DSA Interviews

Focus mainly on **Big-O**.

You usually do not need advanced calculus or mathematical derivations just to calculate the complexity of common DSA solutions.

---

# 8. Space Complexity

## Definition

**Space Complexity describes how the memory usage of an algorithm grows with the input size `n`.**

An important distinction is:

### Input Space

The memory already occupied by the input, such as:

```text
array
vector
string
```

is generally not counted when discussing **auxiliary space**.

### Auxiliary Space

**Auxiliary Space** is the extra memory used by the algorithm apart from the input.

---

# 9. Space Example — Creating a Square Array

Input:

```text
arr = [1, 2, 3, 4, 5]
```

Suppose we create another array:

```text
square = [1, 4, 9, 16, 25]
```

Input size:

```text
n
```

Extra array size:

```text
n
```

Therefore:

```text
Auxiliary Space = O(n)
```

---

# 10. Constant Space — O(1)

Suppose we calculate the sum of an array:

```text
sum = 0

for i = 0 → n-1
    sum += arr[i]
```

The only extra variable is:

```text
sum
```

Whether the array contains:

```text
10
100
1,000,000
```

elements, the extra memory used by `sum` remains constant.

Therefore:

```text
Space Complexity = O(1)
```

---

# 11. Time vs Space

### O(1)

The number of operations or extra memory does not grow with `n`.

### O(n)

If `n` doubles, the work generally grows approximately 2×.

### O(n²)

If `n` doubles, the work generally grows approximately 4×.

---

# 12. Common Time Complexities

From generally better to worse:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2ⁿ)
O(n!)
```

General intuition:

```text
O(1)       → excellent
O(log n)   → very good
O(n)       → good
O(n log n) → usually good
O(n²)      → slower
O(n³)      → very slow for large n
O(2ⁿ)      → very expensive
O(n!)      → extremely expensive
```

---

# 13. O(1) — Constant Time

The input size does not affect the number of operations significantly.

### Array Access

```text
arr[0]
```

Direct access:

```text
O(1)
```

The last element:

```text
arr[n-1]
```

is also directly accessed:

```text
O(1)
```

### Mathematical Formula

Sum of numbers from `1` to `n`:

```text
n(n+1)/2
```

No loop is required.

Therefore:

```text
O(1)
```

### Hash Table

Operations such as:

```text
Insert
Delete
Find
```

in a hash table are generally treated as:

```text
O(1)
```

in average/amortized practical analysis, although worst-case behavior can be different.

---

# 14. O(n) — Linear Time

The amount of work grows linearly with the input size.

### Linear Search

```text
O(n)
```

### Single Loop

```text
for i = 0 → n
```

```text
O(n)
```

### Sum of an Array

```text
for each element:
    sum += element
```

```text
O(n)
```

### Kadane's Algorithm

Kadane's Algorithm makes a single pass through the array:

```text
O(n)
```

---

# 15. O(n²) — Quadratic Time

Quadratic complexity commonly appears with nested loops.

Example:

```text
for i = 0 → n
    for j = 0 → n
        constant work
```

Outer loop:

```text
n
```

Inner loop:

```text
n
```

Total:

```text
n × n = n²
```

Therefore:

```text
O(n²)
```

---

# 16. Nested Loops — Important Rule

If we have:

```text
loop → n times
    loop → n times
```

then it is generally:

```text
O(n²)
```

Three nested loops:

```text
loop → n
    loop → n
        loop → n
```

give:

```text
O(n³)
```

General rule:

```text
k nested n-loops → O(nᵏ)
```

**But do not blindly assume that every nested loop is O(n²).**

Always check how many times the inner loop actually runs.

---

# 17. Bubble Sort, Selection Sort & Insertion Sort

Typical worst-case complexities:

```text
Bubble Sort     → O(n²)
Selection Sort  → O(n²)
Insertion Sort  → O(n²)
```

Their basic implementations perform approximately quadratic work.

---

# 18. Detailed Nested Loop Example

Suppose:

```text
n = 4
```

The inner loop may run:

```text
3 + 2 + 1
```

Total:

```text
3 + 2 + 1 = 6
```

For general `n`:

```text
1 + 2 + 3 + ... + (n-1)
```

The sum is:

```text
n(n-1)/2
```

Expand:

```text
(n² - n)/2
```

Ignore constants and lower-order terms:

```text
O(n²)
```

### Important Intuition

Do not blindly think:

> "Nested loop = O(n²)."

Instead, check how the loops actually run.

---

# 19. O(n³) — Cubic Time

Three nested loops:

```text
for i = 0 → n
    for j = 0 → n
        for k = 0 → n
```

Total work:

```text
n × n × n
= n³
```

Therefore:

```text
O(n³)
```

---

# 20. O(log n) — Logarithmic Time

A common pattern for `O(log n)` is repeatedly reducing the problem size by a constant factor, especially by half.

For example:

```text
n
n/2
n/4
n/8
n/16
...
1
```

Therefore:

```text
O(log n)
```

### Key Clue

> **If the search/problem space is roughly cut in half at every step, think O(log n).**

---

# 21. Binary Search

Binary Search repeatedly halves the search space:

```text
n
n/2
n/4
n/8
...
1
```

Suppose we divide the search space `x` times:

```text
n / 2ˣ = 1
```

Therefore:

```text
n = 2ˣ
```

Taking log:

```text
x = log₂ n
```

Therefore:

```text
Binary Search = O(log n)
```

### Practical Recognition

If every step reduces the search space by roughly half:

```text
→ O(log n)
```

Operations on a **balanced BST** can also be `O(log n)`.

---

# 22. O(n log n)

This is a very common efficient complexity.

Examples:

```text
Merge Sort → O(n log n)
Quick Sort → O(n log n) average
```

A common pattern is:

```text
O(n) work
×
O(log n) levels
```

Therefore:

```text
O(n log n)
```

Comparison:

```text
O(n) < O(n log n) < O(n²)
```

So `n log n` grows more slowly than `n²`.

---

# 23. O(2ⁿ) — Exponential Time

Exponential complexity commonly appears in brute-force recursive algorithms.

Example:

```text
Brute-force Fibonacci
```

It can occur when each recursive call produces multiple recursive calls.

This becomes extremely expensive as `n` grows.

Typical simplified complexity:

```text
O(2ⁿ)
```

---

# 24. O(n!) — Factorial Time

Factorial complexity is even worse than exponential complexity.

It commonly appears when generating all permutations.

For a string of size `3`:

```text
3! = 6
```

Possible permutations:

```text
abc
acb
bac
bca
cab
cba
```

Therefore, generating all permutations generally requires:

```text
O(n!)
```

Other brute-force examples can include:

- N-Queens
- Knight's Tour
- Permutation-based problems

Comparison:

```text
O(2ⁿ) < O(n!)
```

Therefore:

```text
O(n!)
```

grows even faster.

---

# 25. Recursion — Time Complexity

There are two common approaches to analyzing recursive algorithms.

### Method 1 — Recurrence Relation

For example:

```text
T(n) = T(n-1) + ...
```

Then solve the recurrence mathematically.

### Method 2 — Practical Approach

Think in terms of:

```text
Number of recursive calls
×
Work done in each call
```

This can be easier for many practical DSA problems.

---

# 26. Recursive Fibonacci

Brute-force Fibonacci looks like:

```text
fib(n)
 ├── fib(n-1)
 └── fib(n-2)
```

Each call creates more calls.

The recursion tree grows approximately like:

```text
1
2
4
8
...
```

This leads to exponential growth.

For practical Big-O analysis:

```text
Time Complexity = O(2ⁿ)
```

The more precise growth rate is closer to `O(1.618ⁿ)`, but `O(2ⁿ)` is the common simplified interview answer.

---

# 27. Recursive Fibonacci — Space Complexity

Recursion uses the **call stack**.

The maximum recursion depth is approximately:

```text
n
```

Each call uses constant memory.

Therefore:

```text
Space Complexity = O(n)
```

### Important

Even if you do not explicitly create an array or vector, recursion can still use extra memory because of the **call stack**.

---

# 28. Recursion — Space Formula

A useful mental model is:

```text
Space =
recursion depth
×
memory used per call
```

If:

```text
depth = n
memory per call = O(1)
```

then:

```text
Space = O(n)
```

---

# 29. Merge Sort

Merge Sort has two important parts:

## 1. Divide

The array is repeatedly divided into halves:

```text
n
n/2
n/4
n/8
...
1
```

Number of levels:

```text
O(log n)
```

## 2. Merge

At each level, the total merging work is:

```text
O(n)
```

Therefore:

```text
O(n) × O(log n)
```

Final:

```text
Merge Sort Time = O(n log n)
```

---

# 30. Merge Step Complexity

The merge operation combines two sorted arrays.

Example:

```text
[1,5] + [3,6]
```

Result:

```text
[1,3,5,6]
```

The elements are processed during the merge.

Therefore:

```text
Merge Step Time = O(n)
```

A temporary array/vector is also commonly used:

```text
Merge Step Space = O(n)
```

---

# 31. Merge Sort Space Complexity

Merge Sort typically uses:

### Recursion Stack

```text
O(log n)
```

### Temporary Merge Array

```text
O(n)
```

Combined:

```text
O(log n + n)
```

Keep the largest term:

```text
O(n)
```

Therefore:

```text
Merge Sort
Time  = O(n log n)
Space = O(n)
```

---

# 32. Constraints → Complexity

This is one of the most practical uses of complexity analysis.

Coding problems usually provide a constraint such as:

```text
1 ≤ n ≤ ...
```

The constraint tells you approximately:

> **What complexity is likely to be acceptable?**

A common rough competitive-programming guideline is:

```text
10⁸ simple operations ≈ around 1 second
```

This is only an approximation and depends on the language, machine, and operation.

If your algorithm performs too much work, you may get:

```text
TLE = Time Limit Exceeded
```

---

# 33. Constraint Cheat Sheet

Use this only as a **rough estimator**:

| Constraint | Possible Complexity |
|---|---|
| `n ≤ 10⁸` | O(1), O(log n), sometimes O(n) |
| `n ≤ 10⁶` | O(n), O(n log n) |
| `n ≤ 10⁵` | O(n log n), sometimes O(n²) depending on the problem |
| `n ≤ 500` | O(n³) may be possible |
| `n ≤ 25` | O(2ⁿ) may be possible |
| `n ≤ 12` | O(n!) may be possible |

These are **rough guidelines, not absolute rules**.

---

# 34. Example — n ≤ 10⁵

Suppose:

```text
n ≤ 10⁵
```

Consider:

```text
O(n²)
```

Maximum work:

```text
(10⁵)²
= 10¹⁰
```

This is much larger than the rough `10⁸` operations guideline.

Therefore:

```text
O(n²) → likely too slow
```

Instead, try to find something closer to:

```text
O(n log n)
```

For `n ≤ 10⁵`, think about:

- Sorting
- Binary search
- Hashing
- Efficient data structures
- Other `O(n)` or `O(n log n)` approaches

---

# 35. Constraints Can Give You a Hint

Constraints do not only tell you whether your solution will pass.

They can also give you a **hint about the intended approach**.

### Example

```text
n ≤ 25
```

Since `n` is small, something like:

```text
O(2ⁿ)
```

may be acceptable.

Think about:

```text
Brute force
Recursion
Backtracking
```

Another example:

```text
n ≤ 12
```

`O(n!)` may be possible.

Think about:

```text
Permutations
Brute-force recursion
Backtracking
```

---

# 36. Mental Process When Solving a Problem

When you see a DSA problem:

### Step 1 — Check the Constraint

Ask:

```text
What is the maximum n?
```

### Step 2 — Estimate the Allowed Complexity

Determine approximately what complexity can pass.

### Step 3 — Reject Too-Slow Approaches

Do not spend time implementing an approach that is obviously too slow.

### Step 4 — Choose a Suitable Pattern

For example, if:

```text
n = 10⁵
```

ask:

```text
Can I solve it in O(n)?
Can I use O(n log n)?
Can sorting help?
Can hashing help?
Can binary search help?
```

---

# 37. Quick Recognition Table

| Pattern | Typical Complexity |
|---|---|
| Direct calculation | O(1) |
| `arr[i]` | O(1) |
| Single loop to `n` | O(n) |
| Two sequential loops | O(n) |
| Nested `n × n` loops | O(n²) |
| Three nested `n` loops | O(n³) |
| Search space repeatedly halves | O(log n) |
| Divide + linear work at each level | O(n log n) |
| Two recursive branches | Often O(2ⁿ) |
| Generate all permutations | O(n!) |

---

# 38. Independent vs Nested Loops

This is very important.

## Sequential Loops

```text
for i = 0 → n
    ...

for j = 0 → n
    ...
```

These loops run one after another.

Total:

```text
n + n
= 2n
```

Ignore the constant:

```text
O(n)
```

## Nested Loops

```text
for i = 0 → n
    for j = 0 → n
        ...
```

The inner loop runs for each iteration of the outer loop.

Total:

```text
n × n
= n²
```

Therefore:

```text
O(n²)
```

### Remember

**Sequential loops → Add**

**Nested loops → Multiply**

---

# 39. Most Important Rules to Memorize

### Rule 1 — Ignore Constants

```text
O(5n) → O(n)
O(100n²) → O(n²)
```

### Rule 2 — Keep the Largest-Growing Term

```text
O(n² + n + 1)
→ O(n²)
```

### Rule 3 — Sequential Work Adds

```text
O(n) + O(n)
→ O(n)
```

### Rule 4 — Nested Work Multiplies

```text
O(n) × O(n)
→ O(n²)
```

### Rule 5 — Halving Pattern

```text
n → n/2 → n/4 → ...
→ O(log n)
```

### Rule 6 — Divide + Process All Elements

```text
O(n) work × O(log n) levels
→ O(n log n)
```

### Rule 7 — Recursive Branching

```text
1 → 2 → 4 → 8 → ...
→ O(2ⁿ)
```

### Rule 8 — All Permutations

```text
n!
→ O(n!)
```

---

# 40. Complexity Ranking

Memorize this order from generally better to worse:

```text
O(1)
   ↓
O(log n)
   ↓
O(n)
   ↓
O(n log n)
   ↓
O(n²)
   ↓
O(n³)
   ↓
O(2ⁿ)
   ↓
O(n!)
```

**Top = generally better**

**Bottom = generally worse**

---

# 41. Final One-Page Revision

## Time Complexity

```text
How the number of operations grows with input size n.
```

## Space Complexity

```text
How the extra memory usage grows with input size n.
```

## Big-O

```text
A notation used to describe an algorithm's growth,
commonly for worst-case analysis.
```

## Calculating Big-O

```text
1. Ignore constants.
2. Keep the fastest-growing term.
```

## Common Complexities

```text
O(1)       → direct access / formula
O(log n)   → repeatedly reduce the search space
O(n)       → single pass
O(n log n) → efficient sorting / divide & conquer
O(n²)      → nested loops
O(n³)      → triple nested loops
O(2ⁿ)      → brute-force recursive branching
O(n!)      → permutations / brute-force arrangements
```

## Recursion

```text
Time  ≈ number of calls × work per call
Space ≈ recursion depth × memory per call
```

## Merge Sort

```text
Time  = O(n log n)
Space = O(n)
```

## Brute-Force Fibonacci

```text
Time  = O(2ⁿ)
Space = O(n)
```

## Constraints

```text
Large n → need a more efficient algorithm
Small n → more expensive algorithms may be acceptable
```

---

# 42. What You Actually Need to Remember

Do **not** try to memorize the entire lecture word-for-word.

Make these five patterns automatic:

```text
1. Single loop          → O(n)

2. Nested loops         → usually O(n²)

3. Search space halves  → O(log n)

4. Divide + n work      → O(n log n)

5. Recursive branching  → often O(2ⁿ)
```

Whenever you solve a DSA problem, ask yourself:

```text
1. What is my n?

2. How many times does each loop run?

3. Are my loops sequential or nested?

4. Is my search space shrinking?

5. Am I using extra memory?

6. Can this complexity pass the given constraint?
```

### Golden Rule

> **Check the constraint first → estimate the allowed complexity → choose an appropriate algorithm/pattern.**

That is the practical purpose of Time & Space Complexity.
