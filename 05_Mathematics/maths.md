# Mathematical Concepts for DSA in C++

In this lecture, we'll work through:

1. Prime numbers and checking primality efficiently
2. Counting primes in a range
3. Sieve of Eratosthenes
4. Extracting and counting digits
5. Sum of digits
6. Armstrong numbers
7. GCD / HCF and Euclid's algorithm
8. LCM using GCD
9. Reversing an integer and handling overflow
10. Palindrome numbers
11. Modular arithmetic and its useful properties
12. Binary exponentiation as homework
13. Catalan numbers as a preview of future DP problems

---

# 1. Prime numbers: do we really need to try every divisor?

### Teacher

Imagine I give you the number **47** and ask:

“Is 47 prime?”

A prime number is a number greater than 1 that has exactly two positive factors: 1 and itself.

So 47 is prime if no number other than 1 and 47 divides it exactly.

The slow way would be to try 2, 3, 4, 5, 6, 7, and keep going until 46. But that's unnecessary. Let's find the shortcut.

### The factor-pair trick

Think about the factors of 36:

- 1 × 36
- 2 × 18
- 3 × 12
- 4 × 9
- 6 × 6

Notice something? Factor pairs meet around the square root.

For any composite number `n`, if it has a factor larger than `sqrt(n)`, it must have a matching factor smaller than `sqrt(n)`. That means if we have checked every possible divisor from 2 through `sqrt(n)` and found none, we don't need to check beyond that.

For 47:

- `sqrt(47)` is approximately 6.85.
- We only need to test 2, 3, 4, 5, and 6.
- None divides 47 evenly.
- Therefore, 47 is prime.

For 42:

- `sqrt(42)` is approximately 6.48.
- Try 2 first.
- `42 % 2 == 0`, so we have already found a divisor other than 1 and 42.
- We can stop immediately. 42 is not prime.

### C++ implementation

```cpp
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
```

### Let's read the code like a programmer

- `if (n < 2)` handles 0, 1, and negative numbers. None is prime.
- `int i = 2` starts checking from the first possible divisor.
- `i * i <= n` is the same boundary idea as `i <= sqrt(n)`, but avoids repeatedly calculating a square root.
- `n % i == 0` means the remainder is zero, so `i` divides `n` exactly.
- The moment we find a divisor, return `false`. No need to continue.
- If the loop finishes without finding one, return `true`.

### Dry run: `isPrime(47)`

| `i` | `i * i` | Is `i * i <= 47`? | `47 % i` |
|---:|---:|---|---:|
| 2 | 4 | Yes | 1 |
| 3 | 9 | Yes | 2 |
| 4 | 16 | Yes | 3 |
| 5 | 25 | Yes | 2 |
| 6 | 36 | Yes | 5 |
| 7 | 49 | No | Stop |

No divisor was found. Result: `true`.

**Time complexity:** `O(sqrt(n))` for one number.

> **Your turn:** What will `isPrime(49)` return? Which value of `i` makes the function return `false`?

---

# 2. Counting primes in a range: why the obvious solution becomes slow

### Teacher

Now the question changes.

Instead of asking whether one number is prime, suppose I give you `n = 50` and ask:

“How many prime numbers are strictly less than 50?”

We already know how to check one number. So the first idea is simple:

1. Start at 2.
2. Check whether the current number is prime.
3. If it is, increase the count.
4. Repeat until we reach `n`.

### Brute-force code

```cpp
int countPrimes(int n) {
    int count = 0;

    for (int number = 2; number < n; number++) {
        if (isPrime(number)) {
            count++;
        }
    }

    return count;
}
```

This works logically. But think about the amount of work.

For every number, we run another loop to test its divisors. If the range becomes large, repeatedly checking primality becomes expensive. On coding platforms, this approach may result in **TLE (Time Limit Exceeded)**.

The lecture's key question is: can we avoid checking the same information again and again?

Yes. We can use the **Sieve of Eratosthenes**.

---

# 3. Sieve of Eratosthenes: cross out the numbers that cannot be prime

### Teacher

Let's solve the same problem for numbers less than 50.

Imagine writing every number from 0 to 49 on a board. Initially, we'll mark every number as “possibly prime”.

But we already know:

- 0 is not prime.
- 1 is not prime.

Now follow this process:

1. The first unmarked number is 2. It is prime.
2. Cross out every multiple of 2 greater than 2: 4, 6, 8, 10, ...
3. The next unmarked number is 3. It is prime.
4. Cross out its multiples: 6, 9, 12, 15, ...
5. The next unmarked number is 5. It is prime. Cross out its multiples.
6. Continue in the same way.

A number that survives the process is prime.

### Why do we start crossing out at `p * p`?

Suppose we're processing `p = 5`.

Its multiples are:

`10, 15, 20, 25, 30, 35, 40, 45, ...`

But 10, 15, and 20 have already been crossed out:
- 10 was crossed out as a multiple of 2.
- 15 was crossed out as a multiple of 3.
- 20 was crossed out as a multiple of 2.

So the first multiple of 5 that still needs to be crossed out is `5 * 5 = 25`.

This is why the inner loop starts at `p * p`, not `2 * p`.

We only need to process prime candidates while `p * p < n`. If `p * p` is already outside the range, all relevant composite multiples have been handled by smaller factors.

### C++ implementation — LeetCode 204: Count Primes

The problem asks for the number of prime numbers **strictly less than `n`**.

```cpp
int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    vector<bool> isPrime(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple < n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count;
}
```

### What does the array represent?

`isPrime[x]` answers: “Is `x` still considered prime?”

- Initially, every entry is `true`.
- We set index 0 and index 1 to `false`.
- Whenever we find a prime `p`, we mark its multiples as `false`.
- At the end, the remaining `true` positions are prime numbers.

### A small visual example: `n = 12`

Start with candidates from 0 to 11:

```text
0  1  2  3  4  5  6  7  8  9  10  11
X  X  P  P  ?  P  ?  P  ?  ?   ?   P
```

- Process 2: cross out 4, 6, 8, 10.
- Process 3: cross out 9. (6 was already crossed out.)
- The remaining prime numbers are 2, 3, 5, 7, 11.

Answer: 5.

**Complexity:** The sieve runs in approximately `O(n log log n)` time and uses `O(n)` extra space.

**Important boundary detail:** In LeetCode 204, `n` itself is excluded. That is why the array has size `n` and the loops use `< n`, not `<= n`.

> **Your turn:** If `n = 3`, how many primes are strictly less than 3? Be careful: is 3 included?

---

# 4. Extracting digits: how can we take a number apart?

### Teacher

Suppose I give you:

```text
n = 4729
```

And I ask you to print its digits one by one, from right to left.

You don't need strings for this. Two arithmetic operations are enough:

- `n % 10` gives the last digit.
- `n / 10` removes the last digit when `n` is an integer.

Let's try:

| Current `n` | `n % 10` (last digit) | `n / 10` (remaining number) |
|---:|---:|---:|
| 4729 | 9 | 472 |
| 472 | 2 | 47 |
| 47 | 7 | 4 |
| 4 | 4 | 0 |

### C++ code

```cpp
int n = 4729;

while (n > 0) {
    int digit = n % 10;
    cout << digit << " ";
    n = n / 10;
}
```

Output:

```text
9 2 7 4
```

The loop ends when all digits have been removed and `n` becomes 0.

**A note about zero:** If the input itself is `0`, the loop above prints nothing. If your problem requires the digit 0 to be processed, handle that case separately.

**A note about negative numbers:** The example assumes a non-negative integer. For negative inputs, decide how the problem wants the sign handled before extracting digits.

---

# 5. Counting digits: how many times can we remove the last digit?

### Teacher

Now that we can extract digits, counting them is easy.

For 4729:
- Remove 9: one digit counted.
- Remove 2: two digits counted.
- Remove 7: three digits counted.
- Remove 4: four digits counted.

### Loop approach

```cpp
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }

    int count = 0;

    while (n > 0) {
        count++;
        n = n / 10;
    }

    return count;
}
```

We keep dividing by 10 until no digits remain.

### Mathematical shortcut using logarithms

For a positive integer `n`, the number of digits is:

```text
floor(log10(n)) + 1
```

For example:

- `n = 4729`
- `log10(4729)` is approximately 3.67
- `floor(3.67) + 1 = 4`

So 4729 has four digits.

**Important:** The logarithm formula needs special handling for `n = 0`, and care with negative numbers and floating-point precision. In ordinary DSA code, the loop is often the safer and clearer choice.

> **Your turn:** How many times will the loop execute for `n = 800`? What will the values of `n` be after each division?

---

# 6. Sum of digits: turn the extracted digits into an answer

### Teacher

Let's use the same number, 4729.

Instead of printing each digit, add each digit to a running total:

`9 + 2 + 7 + 4 = 22`

The extraction logic stays exactly the same. We only change what we do with each digit.

### C++ code

```cpp
int sumOfDigits(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        n = n / 10;
    }

    return sum;
}
```

### Dry run

| `n` | Extracted digit | Running sum |
|---:|---:|---:|
| 4729 | 9 | 9 |
| 472 | 2 | 11 |
| 47 | 7 | 18 |
| 4 | 4 | 22 |

Result: `22`.

Again, decide how to handle `n = 0` and negative inputs according to the problem statement.

---

# 7. Armstrong numbers: does the sum of powered digits equal the number?

### Teacher

Here is a number puzzle.

Take **153**. Split it into its digits:

`1, 5, 3`

Because 153 has three digits, cube each digit and add them:

`1³ + 5³ + 3³`

`= 1 + 125 + 27`

`= 153`

We got the original number back. That makes 153 an Armstrong number (also called a narcissistic number).

For a three-digit number, the familiar test is the sum of the cubes of its digits. More generally, for an `k`-digit number, raise each digit to the power `k` and add the results. If the sum equals the original number, it is an Armstrong number.

### General C++ implementation

```cpp
int countDigits(int n) {
    if (n == 0) return 1;

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

bool isArmstrong(int n) {
    if (n < 0) {
        return false;
    }

    int original = n;
    int digits = countDigits(n);
    long long sum = 0;

    while (n > 0) {
        int digit = n % 10;

        long long powered = 1;
        for (int i = 0; i < digits; i++) {
            powered *= digit;
        }

        sum += powered;
        n /= 10;
    }

    return sum == original;
}
```

This version uses a small loop to calculate each digit's power. It avoids relying on floating-point `pow()` for an exact integer comparison.

For `n = 153`, the function returns `true`.

**Try these:** 153, 370, 371, 407. These are classic three-digit Armstrong numbers.

---

# 8. GCD / HCF: what is the biggest number that divides both?

### Teacher

Suppose you have two numbers:

```text
a = 12
b = 18
```

List their factors:

- Factors of 12: 1, 2, 3, 4, 6, 12
- Factors of 18: 1, 2, 3, 6, 9, 18

The common factors are 1, 2, 3, and 6.

The greatest common factor is **6**.

This is called GCD (Greatest Common Divisor) or HCF (Highest Common Factor). They mean the same thing.

### Brute-force approach

A straightforward method is to try every possible divisor up to the smaller of the two numbers and remember the largest one that divides both.

```cpp
int gcdBruteForce(int a, int b) {
    int answer = 1;

    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            answer = i;
        }
    }

    return answer;
}
```

This is easy to understand, but it can be slow when the numbers are large.

### Euclid's algorithm: the clever shortcut

There is a much faster observation:

```text
gcd(a, b) = gcd(b, a % b)
```

Why does this work?

If a number divides both `a` and `b`, it also divides their difference. The remainder `a % b` is what remains after subtracting a multiple of `b` from `a`. So the common divisors are preserved when we replace `(a, b)` with `(b, a % b)`.

Let's dry-run `gcd(18, 12)`:

| `a` | `b` | `a % b` |
|---:|---:|---:|
| 18 | 12 | 6 |
| 12 | 6 | 0 |

When the remainder becomes 0, the current `b` is the GCD.

Answer: 6.

### Iterative C++ code

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}
```

### Recursive version

```cpp
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
```

Both versions implement the same algorithm.

**Complexity:** Euclid's algorithm takes `O(log(min(a, b)))` time in the usual analysis, which is dramatically better than checking every possible divisor.

**Input note:** These examples assume non-negative inputs. In production code or a problem that permits negative values, normalize signs and consider the minimum integer edge case.

> **Your turn:** Dry-run `gcd(48, 18)`. Write down each pair before moving to the next call.

---

# 9. LCM: the smallest number both numbers divide into

### Teacher

GCD asks for the largest number that divides both inputs.

LCM asks a different question:

“What is the smallest positive number that is a multiple of both inputs?”

For 12 and 18:

- Multiples of 12: 12, 24, 36, 48, ...
- Multiples of 18: 18, 36, 54, ...

The smallest common multiple is 36.

### The useful relationship

For positive integers `a` and `b`:

```text
LCM(a, b) = (a / GCD(a, b)) * b
```

Why divide first? It reduces the chance of overflowing during multiplication.

### C++ code

```cpp
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    long long g = gcd(a, b);
    return (a / g) * b;
}
```

This assumes `gcd` is implemented for the chosen integer type and that the final LCM fits in `long long`. For signed inputs, handle absolute values carefully.

### Dry run: `LCM(12, 18)`

- `GCD(12, 18) = 6`
- `12 / 6 = 2`
- `2 * 18 = 36`

Answer: `36`.

---

# 10. Reverse an integer: build the answer one digit at a time

### Teacher

Suppose the input is:

```text
n = 1234
```

We want:

```text
4321
```

We already know how to extract the last digit. Now we need to place each extracted digit at the end of a new number.

The trick is:

```text
reversed = reversed * 10 + digit
```

Why multiply by 10? Because it shifts every digit already in `reversed` one place to the left, making room for the new digit.

### Dry run

| Current `n` | Digit (`n % 10`) | Calculation | New `reversed` |
|---:|---:|---|---:|
| 1234 | 4 | `0 * 10 + 4` | 4 |
| 123 | 3 | `4 * 10 + 3` | 43 |
| 12 | 2 | `43 * 10 + 2` | 432 |
| 1 | 1 | `432 * 10 + 1` | 4321 |

### Basic C++ code

```cpp
int reverseNumber(int n) {
    int reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return reversed;
}
```

This shows the core idea, but it has an important problem: **integer overflow**.

### The overflow problem — LeetCode 7: Reverse Integer

A signed 32-bit `int` can store values only from:

```text
-2147483648 to 2147483647
```

Suppose the reversed result becomes larger than this range. The calculation cannot be represented by an `int`.

The lecture highlights that we must check before performing:

```cpp
reversed = reversed * 10 + digit;
```

A safe implementation checks whether multiplying by 10 and adding the next digit would exceed the allowed range.

```cpp
int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > INT_MAX / 10 ||
            (reversed == INT_MAX / 10 && digit > 7)) {
            return 0;
        }

        if (reversed < INT_MIN / 10 ||
            (reversed == INT_MIN / 10 && digit < -8)) {
            return 0;
        }

        reversed = reversed * 10 + digit;
    }

    return reversed;
}
```

`INT_MAX` and `INT_MIN` are available through `<climits>`.

Why 7 and -8? The largest positive 32-bit integer ends in 7, while the smallest negative 32-bit integer ends in 8. If the current reversed prefix is already at the boundary, the next digit must not cross that final digit.

LeetCode 7 expects `0` when the reversed result overflows.

---

# 11. Palindrome number: does the number read the same both ways?

### Teacher

A palindrome reads the same from left to right and right to left.

Examples:

- 121 → palindrome
- 1331 → palindrome
- 123 → not a palindrome

We already know how to reverse an integer. So a first solution is:

1. Store the original number.
2. Reverse the number.
3. Compare the reversed value with the original.
4. If they are equal, it is a palindrome.

### Basic C++ idea

```cpp
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int original = x;
    long long reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}
```

For `x = 121`:

- Reverse becomes 121.
- Original is 121.
- They match, so return `true`.

For `x = 123`:

- Reverse becomes 321.
- Original is 123.
- They do not match, so return `false`.

For `x = 0`, the loop does not run, `reversed` stays 0, and the function correctly returns `true`.

This version uses `long long` for the reversed value to avoid overflow for an `int` input. Another common LeetCode solution reverses only half the number, but the full-reversal idea is the central concept in this lecture.

**LeetCode connection:** Problem 9 — Palindrome Number.

> **Your turn:** What happens with `-121`? Why should the function return `false` immediately?

---

# 12. Modular arithmetic: why do coding problems ask for an answer modulo 1,000,000,007?

### Teacher

You solve a problem, calculate the answer, and the platform says:

“Return the answer modulo `10^9 + 7`.”

Why not simply return the answer?

Because some answers become enormous.

Imagine a problem asks you to calculate the number of permutations of 50 elements. The count is:

```text
50!
```

Factorials grow extremely quickly. Even `long long` cannot store many such answers.

Instead of storing the complete answer, many programming problems ask us to return its remainder after division by a fixed number:

```cpp
const int MOD = 1'000'000'007;
```

This number is commonly used because it is large and prime, and it works well with many modular-arithmetic techniques.

### What does modulo mean?

`x % m` gives the remainder when `x` is divided by `m`.

For example:

```text
17 % 5 = 2
100 % 3 = 1
```

If we calculate `x % m`, the result is always in the range:

```text
0 to m - 1
```

For example, if `m = 5`, possible remainders are 0, 1, 2, 3, and 4.

### Why can we keep taking modulo during a calculation?

For a positive modulus `m`, these useful properties hold:

**Addition**

```text
(a + b) % m = ((a % m) + (b % m)) % m
```

Example with `a = 8`, `b = 9`, `m = 3`:

- Left side: `(8 + 9) % 3 = 17 % 3 = 2`
- Right side: `((8 % 3) + (9 % 3)) % 3`
- `= (2 + 0) % 3 = 2`

Both sides match.

**Subtraction**

```text
(a - b) % m
```

is congruent to:

```text
((a % m) - (b % m) + m) % m
```

The extra `+ m` helps keep the result non-negative when using the usual non-negative modular representation in C++.

Example: `a = 5`, `b = 8`, `m = 3`.

- `(5 - 8)` is `-3`, whose mathematical remainder modulo 3 is 0.
- `((5 % 3) - (8 % 3) + 3) % 3`
- `= (2 - 2 + 3) % 3 = 0`.

**Multiplication**

```text
(a * b) % m = ((a % m) * (b % m)) % m
```

This allows us to reduce values as we calculate, rather than waiting until the end.

**Repeated modulo**

Once a value has been reduced modulo `m`, reducing it again by the same `m` does not change it:

```text
((x % m) % m) = x % m
```

For example:

- `100 % 3 = 1`
- `1 % 3 = 1`
- Repeating it again still gives 1.

### A practical C++ pattern

```cpp
const long long MOD = 1'000'000'007;

long long addMod(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long multiplyMod(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
```

**Important overflow warning:** Applying `% MOD` after a multiplication does not prevent overflow if `a * b` overflows before the modulo is applied. Choose a sufficiently wide type or a safe multiplication method for the constraints. With values already reduced below `1,000,000,007`, their product fits in signed 64-bit `long long`.

### One subtle point about division

You can reduce values safely across addition, subtraction, and multiplication using the properties above. Ordinary division does **not** work the same way. In modular arithmetic, division usually requires a modular inverse, and that inverse exists only under the appropriate conditions.

The lecture introduces the basic properties here; modular inverses are a separate topic.

---

# 13. Binary exponentiation: homework from the earlier lecture

### Teacher

The lecture refers back to Lecture 13, where power calculation was already taught.

The homework is to revisit the problem of calculating:

```text
x^n
```

and understand **binary exponentiation** (also called fast exponentiation).

The basic idea is that we do not need to multiply by `x` exactly `n` times.

For example:

```text
x^8 = x^4 * x^4
x^4 = x^2 * x^2
x^2 = x * x
```

We repeatedly square the base and reduce the exponent. This makes the number of steps logarithmic in `n`.

### Iterative C++ version

```cpp
long long binaryExponentiation(long long x, long long n) {
    long long answer = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            answer *= x;
        }

        x *= x;
        n /= 2;
    }

    return answer;
}
```

This simple version assumes the result and intermediate products fit in `long long`. If the problem asks for an answer modulo `MOD`, apply modular multiplication safely at each step.

### Your homework

1. Dry-run `binaryExponentiation(2, 5)`.
2. Write down `answer`, `x`, and `n` after every iteration.
3. Then solve the same problem with modulo `1'000'000'007`.

---

# 14. Catalan numbers: a preview of future dynamic programming problems

### Teacher

One final concept is introduced as a preview: **Catalan numbers**.

You do not need to master them in this lecture. The important point is to recognize that one mathematical sequence appears in several classic DSA and dynamic programming problems.

Catalan numbers begin:

```text
1, 1, 2, 5, 14, 42, 132, ...
```

A common formula is:

```text
C(n) = (2n)! / ((n + 1)! * n!)
```

They also have the recurrence:

```text
C(0) = 1

C(n) = C(0)C(n-1) + C(1)C(n-2) + ... + C(n-1)C(0)
```

The lecture points out that several classical DP problems are connected to Catalan numbers — at least seven or eight familiar problems, as mentioned by the instructor.

Examples commonly associated with Catalan numbers include:
- Counting valid arrangements of balanced parentheses
- Counting structurally different binary search trees
- Counting ways to triangulate a convex polygon

We'll study the relevant details when these problems appear in the DP part of the course.

---

# 15. Final recap: what should you be able to do now?

Let's close the lecture by connecting each idea to the kind of problem it helps solve.

| Concept | Main idea to remember | Where it helps |
|---|---|---|
| Prime checking | Test divisors only up to `sqrt(n)` | Prime / factor problems |
| Counting primes | Repeated primality checks can be slow | Range-based prime problems |
| Sieve of Eratosthenes | Cross out multiples of each prime | LeetCode 204 — Count Primes |
| Extracting digits | `% 10` gets the last digit; `/ 10` removes it | Number manipulation |
| Counting digits | Keep removing digits, or use a logarithm carefully | Digit-based problems |
| Sum of digits | Extract each digit and add it | Number properties |
| Armstrong number | Sum each digit raised to the number of digits | Armstrong-number checks |
| GCD / HCF | Largest common divisor | Number theory |
| Euclid's algorithm | `gcd(a, b) = gcd(b, a % b)` | Efficient GCD |
| LCM | `a / gcd(a,b) * b` | Common-multiple problems |
| Reverse integer | `reversed = reversed * 10 + digit` | LeetCode 7 |
| Palindrome number | Compare a number with its reverse | LeetCode 9 |
| Modular arithmetic | Keep large answers within a remainder range | Large-count / competitive-programming problems |
| Binary exponentiation | Square the base and halve the exponent | Fast power |
| Catalan numbers | A sequence linked to several classic counting problems | Dynamic programming |
