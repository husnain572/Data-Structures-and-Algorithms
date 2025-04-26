
# 📚 DSA Maths Basics – Notes

---

## 1. Prime Numbers
- A **prime number** is a number greater than 1 that is not divisible by any number other than 1 and itself.
- If a number `n` is **not divisible** by any number from **2 to √n**, then `n` is prime.

### Code to Check Prime:
```cpp
#include <iostream>
using namespace std;

string isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return "Non Prime";
        }
    }
    return "Prime";
}

int main() {
    cout << isPrime(12); // Output: Non Prime
    return 0;
}
```

---
## 2. Digits Operations

### a) Print Digits
```cpp
void printDigits(int n) {
    while (n != 0) {
        int digit = n % 10;
        cout << digit;
        n = n / 10;
    }
}
```

### b) Count Digits
```cpp
void countDigits(int n) {
    int count = 0;
    while (n != 0) {
        int digit = n % 10;
        count++;
        n = n / 10;
    }
    cout << count;
}
```

### c) Sum of Digits
```cpp
void digits_sum(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit;
        n = n / 10;
    }
    cout << sum;
}
```

---
## 3. Armstrong Number
- An **Armstrong number** is a number that is equal to the **sum of the cubes of its digits**.

### Example:
- 153 = 1³ + 5³ + 3³ = 153
- 371 = 3³ + 7³ + 1³ = 371

---
## 4. GCD (Greatest Common Divisor) / HCF
- Find GCD using **Euclid’s Algorithm**:
  - `gcd(a, b) = gcd(a % b, b)` if a > b
  - `gcd(a, b) = gcd(a, b % a)` if b > a
  - If `a = 0`, then `gcd = b`
  - If `b = 0`, then `gcd = a`

### Code for GCD:
```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) return b;
    return a;
}

int main() {
    cout << gcd(20, 28); // Output: 4
    return 0;
}
```

---
## 5. LCM (Least Common Multiple)
- Formula:  
  \[
  lcm(a, b) = \frac{a \times b}{gcd(a, b)}
  \]

### Code for LCM:
```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) return b;
    return a;
}

int lcm(int a, int b) {
    int gcd_value = gcd(a, b);
    return (a * b) / gcd_value;
}

int main() {
    cout << lcm(20, 28) << endl;
    cout << gcd(20, 28);
    return 0;
}
```

---
## 6. Reverse Number
- Problem Link: [Reverse Integer – LeetCode](https://leetcode.com/problems/reverse-integer/)

---
## 7. Palindrome Number
- Problem Link: [Palindrome Number – LeetCode](https://leetcode.com/problems/palindrome-number/)

---
## 8. Modulo Arithmetic Properties

When working with modulus:

- **Addition:**
  \[
  (x + y) \% m = (x\%m + y\%m) \% m
  \]
- **Subtraction:**
  \[
  (x - y) \% m = (x\%m - y\%m + m) \% m
  \]
- **Multiplication:**
  \[
  (x \times y) \% m = (x\%m \times y\%m) \% m
  \]
- **Nested Modulus:**
  \[
  ((x \% m) \% m) \% m = x \% m
  \]

---

# 📌 Summary of Today's Topics:
- Prime Numbers + Sieve of Eratosthenes (Theory; Sieve code will come later)
- Digit Operations: Printing, Counting, and Sum
- Armstrong Numbers
- Reverse a Number
- Palindrome Check
- GCD/HCF and LCM (with Euclid's Algorithm)
- Modulo Arithmetic Properties

---

# 🚀 Keep Practicing!

---
