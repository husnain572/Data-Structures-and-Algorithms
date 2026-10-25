# TIME & SPACE COMPLEXITY

## 1. Why do we study Time & Space Complexity?

- Almost every **DS / Algorithm** ke saath Time + Space Complexity use hoti hai.
- Coding platforms par solution submit karte waqt important.
- Interviews mein aksar poocha jata hai:
  - **Time Complexity?**
  - **Space Complexity?**
- Main purpose:
  1. Efficient algorithms design karna.
  2. Different algorithms ko compare karna.
  3. Input size barhne par algorithm ka behavior samajhna.

---

# 2. TIME COMPLEXITY

### Definition

**Time Complexity = input size `n` ke function ke taur par algorithm kitne operations perform karta hai.**

Important:

> Time Complexity actual seconds nahi hoti.

Example:

`0.05 sec`

ye actual execution time hai, jo:
- Machine par depend kar sakta hai.
- Server/platform par depend kar sakta hai.

Time Complexity algorithm ke **growth behavior** ko describe karti hai.

---

# 3. Example — Linear Search

Array size = `n`

```text
for i = 0 → n-1
    if arr[i] == target
        return i
```

### Worst Case

Target last index par hai.

| Input `n` | Operations |
|---|---:|
| 1 | ~1 |
| 10 | ~10 |
| 100 | ~100 |
| 100000 | ~100000 |

So:

```text
n ↑  →  operations ↑
```

Graph:

```text
Operations
    |
    |        /
    |      /
    |    /
    |  /
    |/____________ Input (n)
```

Growth is linear.

### Time Complexity:

**O(n)**

---

# 4. Why Worst Case?

Generally DSA mein hum **worst-case Time Complexity** consider karte hain.

Example:

```text
arr = [1,2,3,4,5]
target = 1
```

Best case → first element mil gaya.

```text
Best Case = O(1)
```

Agar target last mein ho:

```text
Worst Case = O(n)
```

Interview / practical analysis mein generally:

**Worst Case ko focus karo.**

---

# 5. Big-O Notation

Big-O ek **notation** hai jo algorithm ke growth ko represent karti hai.

Example:

```text
O(n)
O(n²)
O(log n)
O(1)
```

Lecture ka practical focus:

> **Interview / coding problems mein Big-O calculate karna sabse important hai.**

Big-O ko lecture mein **worst-case / upper-bound behavior** represent karne ke liye use kiya gaya hai.

---

# 6. Big-O Calculate Karne ke Basic Rules

Suppose:

```text
4n² + 3n + 5
```

### Step 1 — Constants ignore karo

```text
n² + n + 1
```

### Step 2 — Largest-growing term rakho

```text
n²
```

Therefore:

```text
O(n²)
```

---

### Example 2

```text
100 + 5n² + √n
```

Constants ignore:

```text
1 + n² + √n
```

Largest term:

```text
n²
```

Therefore:

```text
O(n²)
```

### Remember:

**Big-O mein:**

1. Constants ignore.
2. Lower-order terms ignore.
3. Highest-growing term keep.

---

# 7. Other Notations

Lecture mein mention ki gayi:

- **O** → upper bound / practical worst-case notation
- **Θ (Theta)** → tight bound
- **Ω (Omega)** → lower bound

Also mathematically:

- Small-o
- Small-omega

### For interviews:

**Big-O par focus karo.**

Calculus / limits / advanced mathematical derivations ki practical interview mein generally zaroorat nahi.

---

# 8. SPACE COMPLEXITY

### Definition

**Space Complexity = input size `n` ke function ke taur par algorithm kitni extra space use karta hai.**

Important distinction:

### Input Space

Jo input already diya gaya hai:

```text
array
vector
string
```

isko generally extra/auxiliary space mein count nahi karte.

### Auxiliary Space

Algorithm input ke ilawa jo extra memory use karta hai.

---

# 9. Space Example — Square Array

Input:

```text
arr = [1,2,3,4,5]
```

Output ke liye another array:

```text
square = [1,4,9,16,25]
```

Input array size:

```text
n
```

Extra array size:

```text
n
```

Therefore:

```text
Space Complexity = O(n)
```

---

# 10. Constant Space

Suppose array ka sum nikalna hai:

```text
sum = 0

for i = 0 → n-1
    sum += arr[i]
```

Extra variable sirf:

```text
sum
```

Array ka size chahe:

```text
10
100
1000000
```

`sum` variable ki memory same rahegi.

Therefore:

```text
Space Complexity = O(1)
```

---

# 11. Time vs Space

### O(1)

Input size barhne par operations/extra space approximately same.

### O(n)

Input double → work roughly double.

### O(n²)

Input double → work roughly 4×.

---

# 12. Common Time Complexities

From better → worse:

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

General idea:

```text
O(1)       → excellent
O(log n)   → very good
O(n)       → good
O(n log n) → good/acceptable
O(n²)      → slower
O(n³)      → very slow for large n
O(2ⁿ)      → very bad
O(n!)      → extremely bad
```

---

# 13. O(1) — Constant Time

Input size se farq nahi padta.

### Example

```text
arr[0]
```

First element directly access.

```text
O(1)
```

### Sorted array ka last element

```text
arr[n-1]
```

Direct access:

```text
O(1)
```

### Formula

1 se n ka sum:

```text
n(n+1)/2
```

No loop required.

```text
O(1)
```

### Hash Table

Lecture ke practical context mein:

```text
HashMap / HashSet
```

Insert / Delete / Find ko generally:

```text
O(1)
```

assume kiya jata hai.

More precisely, lecture notes this as **amortized/practical O(1)**.

---

# 14. O(n) — Linear Time

Input ke saath work linearly grow karta hai.

### Linear Search

```text
O(n)
```

### Simple loop

```text
for i = 0 → n
```

```text
O(n)
```

### Sum of array

```text
for each element:
    sum += element
```

```text
O(n)
```

### Kadane's Algorithm

Single pass:

```text
O(n)
```

---

# 15. O(n²) — Quadratic

Usually **nested loops**.

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

Agar:

```text
loop → n times
    loop → n times
```

then:

```text
O(n²)
```

Agar:

```text
loop → n
    loop → n
        loop → n
```

then:

```text
O(n³)
```

General:

```text
k nested n-loops → O(nᵏ)
```

---

# 17. Bubble Sort / Selection Sort / Insertion Sort

Lecture examples:

```text
Bubble Sort     → O(n²)
Selection Sort  → O(n²)
Insertion Sort  → O(n²)
```

Reason:

Nested loops / approximately quadratic amount of work.

---

# 18. Detailed Nested Loop Example

Suppose:

```text
n = 4
```

Outer loop:

```text
i = 0
i = 1
i = 2
```

Inner loop runs approximately:

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

Sum:

```text
n(n-1)/2
```

Expand:

```text
(n² - n)/2
```

Ignore constants + lower term:

```text
O(n²)
```

### Important intuition:

Don't blindly say:

> "Nested loop = O(n²)"

Always check how the inner loop actually runs.

But in most normal:

```text
n × n
```

nested-loop patterns:

```text
O(n²)
```

---

# 19. O(n³)

Three nested loops:

```text
for i = 0 → n
    for j = 0 → n
        for k = 0 → n
```

Total:

```text
n × n × n
= n³
```

Therefore:

```text
O(n³)
```

Example mentioned:

Generating all subarrays using a straightforward triple-loop approach.

---

# 20. O(log n)

One of the best common complexities.

### Main Pattern

If search/work space becomes:

```text
n
n/2
n/4
n/8
n/16
...
1
```

then:

```text
O(log n)
```

### Key clue:

> **Har step mein problem/search space half ho rahi ho → think O(log n).**

---

# 21. Binary Search

Binary Search:

```text
n
n/2
n/4
n/8
...
1
```

Suppose after `x` divisions:

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

So:

```text
Binary Search = O(log n)
```

### Practical recognition:

If every step cuts the search space roughly in half:

```text
→ O(log n)
```

BST operations can also commonly be:

```text
O(log n)
```

under the relevant balanced-tree assumptions.

---

# 22. O(n log n)

Very common efficient complexity.

Examples:

```text
Merge Sort → O(n log n)
Quick Sort → O(n log n) average
```

Also commonly appears in algorithms involving sorting.

Comparison:

```text
O(n) < O(n log n) < O(n²)
```

So:

```text
n log n
```

is better than:

```text
n²
```

---

# 23. O(2ⁿ) — Exponential

Commonly appears in brute-force recursion.

Examples:

```text
Brute-force Fibonacci
```

and other recursion problems where each call generates multiple recursive calls.

Very bad for large `n`.

---

# 24. O(n!)

Factorial complexity.

Examples mentioned:

- N-Queens brute-force approach
- Knight's Tour brute-force approach
- Generating all permutations of a string

For a string of size 3:

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

Therefore generating all permutations generally requires:

```text
O(n!)
```

### Comparison

```text
O(2ⁿ) < O(n!)
```

So:

```text
O(n!)
```

is even worse than exponential `O(2ⁿ)`.

---

# 25. Recursion — Time Complexity

For recursion, lecture gives two practical approaches:

### Method 1

Use a **recurrence relation**.

Example idea:

```text
T(n) = T(n-1) + ...
```

Then solve mathematically.

### Method 2 — Practical

```text
Total recursive calls
×
work done in each call
```

Lecture prefers the second method in many practical cases because recurrence solving can become mathematical.

---

# 26. Recursive Fibonacci

Brute-force Fibonacci:

```text
fib(n)
 ├── fib(n-1)
 └── fib(n-2)
```

Each call produces more calls.

Recursion tree approximately doubles at each level:

```text
1
2
4
8
...
```

For `n` levels:

```text
2ⁿ
```

Therefore:

```text
Time Complexity = O(2ⁿ)
```

Lecture also mentions the more exact growth around:

```text
O(1.618ⁿ)
```

but for interview/practical analysis:

```text
O(2ⁿ)
```

is the expected simplified answer.

---

# 27. Recursive Fibonacci — Space

Recursion creates a **call stack**.

For Fibonacci, maximum recursion depth is approximately:

```text
n
```

Each call uses constant memory.

Therefore:

```text
Space Complexity = O(n)
```

### Important:

Even if you don't explicitly create an extra array/vector, recursion can still use extra space because of the **call stack**.

---

# 28. Recursion — Space Formula

Useful mental model:

```text
Space =
recursion depth
×
memory used per call
```

If:

```text
depth = n
memory/call = O(1)
```

then:

```text
Space = O(n)
```

---

# 29. Merge Sort

Merge Sort has two important parts:

### 1. Divide

Array repeatedly divided into halves:

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

### 2. Merge

At each level, total merging work is:

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

Merge operation takes two sorted arrays and combines them.

Example:

```text
[1,5] + [3,6]
```

Result:

```text
[1,3,5,6]
```

All elements are traversed/copy kiye jate hain.

Therefore:

```text
Merge Step Time = O(n)
```

Temporary array/vector is also used:

```text
Merge Step Space = O(n)
```

---

# 31. Merge Sort Space

Merge Sort has:

### Recursion stack

```text
O(log n)
```

### Temporary merge array

```text
O(n)
```

Combined:

```text
O(log n + n)
```

Largest term:

```text
O(n)
```

Therefore:

```text
Merge Sort Space = O(n)
```

### Final:

```text
Merge Sort
Time  = O(n log n)
Space = O(n)
```

---

# 32. Constraint → Complexity

This is one of the **most practical parts** of the lecture.

Coding problems usually give:

```text
1 ≤ n ≤ ...
```

This constraint tells us:

> What complexity can probably pass?

Lecture uses approximately:

```text
10⁸ operations ≈ around 1 second
```

So if an algorithm performs much more than this, it may produce:

```text
TLE = Time Limit Exceeded
```

---

# 33. Constraint Cheat Sheet

Use this as a rough interview/LeetCode estimator:

| Constraint | Complexity you can think about |
|---|---|
| `n ≤ 10⁸` | O(1), O(log n), sometimes O(n) |
| `n ≤ 10⁶` | O(n), O(n log n) |
| `n ≤ 10⁵` | O(n log n), sometimes O(n²) depending on limits |
| `n ≤ 500` | O(n³) can be possible |
| `n ≤ 25` | O(2ⁿ) may be possible |
| `n ≤ 12` | O(n!) may be possible |

These are **rough estimates**, not absolute rules.

---

# 34. Example — n ≤ 10⁵

Suppose:

```text
n ≤ 10⁵
```

Try:

```text
O(n²)
```

Maximum operations:

```text
(10⁵)²
= 10¹⁰
```

Too large compared with the ~10⁸ operations guideline.

So:

```text
O(n²) → likely TLE
```

Try:

```text
O(n log n)
```

This is much smaller and can be acceptable.

### Practical thought:

If:

```text
n ≤ 10⁵
```

and you need around:

```text
O(n log n)
```

think:

- Sorting
- Binary-search-based approaches
- Efficient data structures

---

# 35. Constraint as a Hint

Constraint doesn't just tell you what will pass.

It can also give you a **hint about the intended algorithm**.

Example:

```text
n ≤ 25
```

This small `n` means:

```text
O(2ⁿ)
```

might be acceptable.

So think:

```text
Brute force
Recursion
Backtracking
```

Example:

```text
n ≤ 12
```

`O(n!)` may be possible.

So think:

```text
Permutation
Brute-force recursion
Backtracking
```

---

# 36. Important Mental Process for Problems

When you see a problem:

### Step 1
Look at constraint.

```text
What is maximum n?
```

### Step 2
Estimate acceptable complexity.

### Step 3
Reject algorithms that are too slow.

### Step 4
Think about patterns that match the allowed complexity.

Example:

```text
n = 10⁵
```

Don't immediately start writing:

```text
O(n²)
```

Instead think:

```text
Can I solve it in O(n)?
Can I use O(n log n)?
Can sorting help?
Can hashing help?
Can binary search help?
```

---

# 37. Quick Recognition Table

| Code / Pattern | Complexity |
|---|---|
| Direct calculation | O(1) |
| `arr[i]` | O(1) |
| Single loop to n | O(n) |
| Two independent loops | O(n) |
| Nested n × n loops | O(n²) |
| 3 nested n loops | O(n³) |
| Search space halves | O(log n) |
| Divide + linear work at each level | O(n log n) |
| Two recursive branches | often O(2ⁿ) |
| All permutations | O(n!) |

---

# 38. Independent vs Nested Loops

### Important distinction

These:

```text
for i = 0 → n
for j = 0 → n
```

are **sequential**.

Total:

```text
n + n = 2n
```

Ignore constant:

```text
O(n)
```

But:

```text
for i = 0 → n
    for j = 0 → n
```

are **nested**.

Total:

```text
n × n = n²
```

Therefore:

```text
O(n²)
```

### Remember:

**Sequential loops → add**

**Nested loops → multiply**

---

# 39. Most Important Rules to Memorize

### Rule 1

```text
Constants ignore
```

```text
O(5n) → O(n)
O(100n²) → O(n²)
```

### Rule 2

Keep largest term:

```text
O(n² + n + 1)
→ O(n²)
```

### Rule 3

Sequential:

```text
O(n) + O(n)
→ O(n)
```

### Rule 4

Nested:

```text
O(n) × O(n)
→ O(n²)
```

### Rule 5

Halving pattern:

```text
n → n/2 → n/4 → ...
→ O(log n)
```

### Rule 6

Divide into halves + process all elements:

```text
O(n) work × O(log n) levels
→ O(n log n)
```

### Rule 7

Recursive branching:

```text
1 → 2 → 4 → 8 ...
→ O(2ⁿ)
```

### Rule 8

All permutations:

```text
n!
→ O(n!)
```

---

# 40. Final Complexity Ranking

Memorize this order:

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

**Top = better**

**Bottom = worse**

---

# 41. Final Revision — One Page

### Time Complexity

```text
How operations grow with input size n.
```

### Space Complexity

```text
How extra memory grows with input size n.
```

### Big-O

```text
Practical worst-case growth notation.
```

### Calculation

```text
1. Ignore constants.
2. Keep largest-growing term.
```

### Common complexities

```text
O(1)       → direct access / formula
O(log n)   → repeatedly divide by 2
O(n)       → single pass
O(n log n) → efficient sorting / divide & conquer
O(n²)      → nested loops
O(n³)      → triple nested loops
O(2ⁿ)      → brute-force recursion
O(n!)      → permutations / brute-force arrangements
```

### Recursion

```text
Time ≈ number of calls × work/call
Space ≈ recursion depth × memory/call
```

### Merge Sort

```text
Time  = O(n log n)
Space = O(n)
```

### Fibonacci brute force

```text
Time  = O(2ⁿ)
Space = O(n)
```

### Constraints

```text
n large → need efficient complexity
n small → worse complexity may be acceptable
```

### Golden mental rule

> **Problem solve karne se pehle constraint dekho → allowed complexity estimate karo → phir algorithm/pattern choose karo.**

---

# 42. What You Should Actually Remember

Don't try to memorize the entire lecture word-for-word.

Just make these 5 things automatic:

```text
1. Single loop          → O(n)

2. Nested loops         → usually O(n²)

3. Halving search space → O(log n)

4. Divide + n work      → O(n log n)

5. Recursive branching  → often O(2ⁿ)
```

And whenever you solve a DSA problem, ask yourself:

```text
"What is my n?"
"How many times does my loop run?"
"Are loops sequential or nested?"
"Is my search space shrinking?"
"Am I creating extra memory?"
"Can this complexity pass the given constraint?"
```

**This is the real practical use of Time & Space Complexity.**
