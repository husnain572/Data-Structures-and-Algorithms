# Queue
## What is a Queue?

A **Queue** is a linear data structure that follows **FIFO (First-In-First-Out)** order.

- Items are added from the **rear** (enqueue).
- Items are removed from the **front** (dequeue).

```cpp
queue<int> q;
q.push(1);     // enqueue
q.front();     // 1
q.pop();       // dequeue (removes 1)
```

## Types of Queues in DSA

| Type            | Description                                    |
| --------------- | ----------------------------------------------- |
| Regular Queue   | FIFO queue using `queue<T>` in C++              |
| Deque           | Double-ended queue (add/remove from both ends)  |
| Priority Queue  | Highest/lowest priority comes out first         |
| Circular Queue  | Fixed-size queue, wraps around                  |

## Pattern Recognition Keywords

| Problem Statement Mentions          | Pattern Involved          |
| ------------------------------------ | -------------------------- |
| "First in, first out"               | Queue or BFS               |
| "Level order traversal"             | Tree + Queue (BFS)         |
| "Find shortest path (unweighted)"   | Graph + BFS                |
| "Sliding window maximum/minimum"    | Monotonic deque            |
| "Rotating queue"                    | Circular queue / deque     |
| "Number of recent calls"            | Queue of timestamps        |
| "Minimum time to infect/rot/escape" | BFS queue (multi-source)   |

## Recognizing Queue-Based Problems

If a problem involves:

- Simulating processes in time order
- Level-wise traversal
- Breadth-first nature
- Processing neighbors first

→ it likely uses a **queue** or **BFS**.

## Tips

- Use `queue` for **BFS**, multi-level traversal, and simulation problems.
- Use `deque` for **sliding window** and monotonic problems.
- Use `priority_queue` for greedy problems where you need the max/min element quickly.
