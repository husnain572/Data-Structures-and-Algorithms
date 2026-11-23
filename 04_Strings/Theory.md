# C++ DSA – Introduction to Strings

## 1. What Are Strings?

A **string** is a sequence of characters enclosed in double quotation marks (`"`).

In programming, a string can represent:

- A single word: `"Hello"`
- A phrase: `"Hello World"`
- A complete sentence: `"My name is Husnain"`

### Examples

```cpp
"College"
"Hello World"
"This is my first C++ program"
```

All of these are strings because they are enclosed in double quotation marks.

In C++, there are two common ways to work with strings:

1. Character Arrays (C-style strings)
2. C++ STL Strings (`string` class)

Before learning STL strings, we need to understand character arrays.

---

# PART 1: CHARACTER ARRAYS (C-STYLE STRINGS)

## 2. What Are Character Arrays?

We have already studied different types of arrays, such as:

- Integer arrays
- Float arrays
- Boolean arrays

Similarly, we can create an array that stores characters. Such an array is called a **character array**.

### Syntax

```cpp
char arr[5];
```

Here:

- `char` specifies the data type.
- `arr` is the array name.
- `[5]` specifies the number of elements the array can store.

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[3] = {'A', 'B', 'C'};

    return 0;
}
```

This creates a character array containing three characters.

The characters are stored in consecutive memory locations, just like elements of a normal array.

## 3. What Is a Null Character (`\0`)?

This is one of the most important concepts when working with character arrays.

A character array can store individual characters. However, when we want to use it as a C-style string, we need a special character at the end.

That special character is called the **null character (`\0`)**.

### Example

```cpp
char arr[] = {'A', 'B', 'C', '\0'};
```

The array now contains:

| Index | Character |
|---|---|
| 0 | A |
| 1 | B |
| 2 | C |
| 3 | \0 |

The null character tells C++ where the string ends.

Without the null character, the program cannot reliably identify the end of a C-style string.

### ASCII Value of Null Character

Every character has an associated ASCII value.

For example:

- A has ASCII value 65.
- B has ASCII value 66.
- C has ASCII value 67.
- Null character (`\0`) has ASCII value 0.

### Important Points

1. `\0` is called the null character.
2. It indicates the end of a C-style string.
3. It occupies one byte of memory.
4. Although it is written using two symbols (`\` and `0`), it represents one character.
5. It is different from the character `'0'`.

**Remember:**

- `'\0'` = Null character.
- `'0'` = Character zero, whose ASCII value is 48.

## 4. How Does a Character Array Become a String?

Consider this character array:

```cpp
char arr[] = {'A', 'B', 'C', '\0'};
```

When we print the array name:

```cpp
cout << arr;
```

Output:

```text
ABC
```

Why?

When C++ prints a character array as a C-style string, it starts reading characters from the beginning and continues until it encounters the null character (`\0`).

The null character is not displayed.

Therefore, the output is:

```text
ABC
```

### What Happens Without a Null Character?

Consider:

```cpp
char arr[] = {'A', 'B', 'C'};

cout << arr;
```

This array is not a properly null-terminated C-style string.

Printing it as a string can cause undefined behavior because the program may continue reading memory beyond the array until it happens to encounter a null character.

Therefore, always ensure that a character array used as a C-style string is null-terminated.

## 5. Calculating the Length of a Character Array

C++ provides a function called `strlen()` to calculate the length of a C-style string.

Header file:

```cpp
#include <cstring>
```

### Example

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[] = {'A', 'B', 'C', '\0'};

    cout << strlen(arr);

    return 0;
}
```

Output:

```text
3
```

Why is the output 3 instead of 4?

Because `strlen()` does not count the null character.

It only counts the actual characters before `\0`.

### Another Way to Initialize a Character Array

Instead of writing individual characters, we can directly assign a string literal.

```cpp
char arr[] = "Hello";
```

Internally, C++ stores:

| Index | Character |
|---|---|
| 0 | H |
| 1 | e |
| 2 | l |
| 3 | l |
| 4 | o |
| 5 | \0 |

The array requires six elements, not five.

**Important formula:**

Array size required for a C-style string = String length + 1.

The additional position is reserved for the null character.

### Accessing Individual Characters

We can access individual characters using their indexes, just like normal arrays.

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[] = "Hello";

    cout << arr[0] << endl;
    cout << arr[2] << endl;
    cout << arr[4] << endl;
    cout << arr[5] << endl;

    return 0;
}
```

Output:

```text
H
l
o
```

The fourth output is the null character, which is not visibly printed.

---

## 6. String Literals

A string literal is a sequence of characters written inside double quotation marks.

Examples:

```cpp
"Hello"
"College"
"Hello World"
```

These are called string literals.

A literal represents a fixed value written directly in the source code.

For example:

```cpp
char arr[] = "Hello";
```

Here, `"Hello"` is the string literal.

**Important clarification:** A string literal itself cannot be modified. However, the character array initialized from it is a separate, modifiable array.

For example:

```cpp
char arr[] = "Hello";

arr[0] = 'Y';

cout << arr;
```

Output:

```text
Yello
```

---

## 7. Taking Input in Character Arrays

We can use `cin` to take a single-word string as input.

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[100];

    cout << "Enter a string: ";
    cin >> arr;

    cout << arr;

    return 0;
}
```

Input:

```text
Hello
```

Output:

```text
Hello
```

Here, the character array has a capacity of 100 characters.

However, remember that one position is required for the null character.

### Problem with `cin`

What happens if we enter a complete phrase?

Input:

```text
Hello World
```

Output:

```text
Hello
```

Why?

Because `cin` stops reading when it encounters whitespace.

Whitespace includes:

- Spaces
- Tabs
- Newline characters

Therefore, `cin` only reads the first word.

To solve this problem, we use `cin.getline()`.

## 8. Using `cin.getline()` to Read Complete Strings

The `cin.getline()` function allows us to read a complete line, including spaces.

### Syntax

```cpp
cin.getline(arrayName, size);
```

Parameters:

1. `arrayName`: The character array in which the input will be stored.
2. `size`: The maximum number of characters the array can hold, including the null character.

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[100];

    cout << "Enter a string: ";

    cin.getline(arr, 100);

    cout << arr;

    return 0;
}
```

Input:

```text
Hello World
```

Output:

```text
Hello World
```

Now the complete phrase is stored successfully.

### 9. What Is a Delimiter?

A delimiter is a special character that tells an input operation where to stop reading.

By default, `cin.getline()` uses the newline character (`\n`) as its delimiter.

This means it stops reading when the user presses Enter.

However, we can specify our own delimiter.

### Syntax

```cpp
cin.getline(arrayName, size, delimiter);
```

The third parameter is optional.

### Example: Using `$` as a Delimiter

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[100];

    cout << "Enter a string: ";

    cin.getline(arr, 100, '$');

    cout << arr;

    return 0;
}
```

Input:

```text
Hello World$ Welcome to C++
```

Output:

```text
Hello World
```

Why?

Because `$` is the delimiter.

As soon as the program encounters `$`, it stops reading.

The delimiter itself is not stored in the resulting string.

**Remember:**

- Default delimiter: `\n`
- Custom delimiter: Any character we specify.
- The delimiter marks the end of the input.

---

## 10. Printing Character Arrays Using Loops

We can also print individual characters of a character array using loops.

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[] = "College";

    for (char ch : arr) {
        cout << ch << " ";
    }

    return 0;
}
```

Output:

```text
C o l l e g e
```

This is called a **range-based for loop** (or for-each loop).

It accesses each element of the array one by one.

### Important Note

When a range-based loop processes a null-terminated character array, it also processes the null character.

The null character is invisible when printed, but it is still part of the iteration.

---

## 11. Calculating String Length Using a Loop

We can calculate the length of a C-style string without using `strlen()`.

The logic is simple:

1. Start from index 0.
2. Check whether the current character is equal to `\0`.
3. If it is not equal to `\0`, increase the length.
4. Continue until the null character is reached.

### Code

```cpp
#include <iostream>
using namespace std;

int main() {
    char arr[] = "College";

    int length = 0;

    for (int i = 0; arr[i] != '\0'; i++) {
        length++;
    }

    cout << "Length: " << length;

    return 0;
}
```

Output:

```text
Length: 7
```

### Dry Run

For `"College"`:

| Iteration | Character | Length |
|---|---|---|
| 1 | C | 1 |
| 2 | o | 2 |
| 3 | l | 3 |
| 4 | l | 4 |
| 5 | e | 5 |
| 6 | g | 6 |
| 7 | e | 7 |
| 8 | \0 | Loop stops |

The loop stops when it reaches the null character.

### Two Ways to Calculate Length

| Method | Function |
|---|---|
| Built-in function | `strlen(arr)` |
| Manual approach | Loop until `arr[i] == '\0'` |

Both approaches calculate the number of actual characters, excluding the null character.

---

# PART 2: C++ STL STRINGS

## 12. What Are C++ Strings?

Character arrays have certain limitations.

To overcome these limitations, C++ provides an advanced and more convenient way to work with strings through the **STL string class**.

A C++ string is an object of the `string` class.

It provides several built-in functions and operations that make string manipulation easier.

### Header File

```cpp
#include <string>
```

The `string` class belongs to the C++ Standard Library.

For standard C++ programs, include `<string>` whenever you use `std::string`.

### Creating a String

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    str = "College";

    cout << str;

    return 0;
}
```

Output:

```text
College
```

Here:

- `string` is the data type/class.
- `str` is the variable (object) name.
- `"College"` is the assigned string value.

Unlike a character array, we do not need to specify its size.

## 13. Difference Between Character Arrays and STL Strings

One of the most important differences is that C++ STL strings are dynamic in nature.

This means their size can automatically change when we assign or add different values.

### Example: Character Array

```cpp
char arr[20] = "College";
```

The array has a fixed capacity of 20 characters.

We cannot resize this array during normal runtime operations.

### Example: STL String

```cpp
string str = "College";

str = "Hello";

cout << str;
```

Output:

```text
Hello
```

The string can change its length automatically.

We do not need to specify a fixed array size.

### Comparison

| Feature | Character Array | STL String |
|---|---|---|
| Data type | `char` | `string` |
| Size | Fixed capacity | Dynamically managed |
| Null character | Required for C-style string | Managed internally |
| Direct concatenation | Not supported with `+` | Supported |
| Direct comparison | Not supported with `==` for contents | Supported |
| Length | `strlen()` | `.length()` or `.size()` |
| Input with spaces | `cin.getline()` | `getline()` |
| Ease of use | More manual work | More convenient |

**Important:** An STL string manages its own memory and size. Internally, its storage is contiguous, but you do not need to manage its null terminator yourself.

---

## 14. Dynamic Nature of STL Strings

Consider:

```cpp
string str = "College";

str = "Hello";

cout << str;
```

Output:

```text
Hello
```

The string automatically adjusts its size.

This is one of the major advantages of STL strings over fixed-size character arrays.

Remember that a normal built-in array cannot be resized simply by assigning it a new, differently sized string.

---

## 15. Concatenation of Strings

Concatenation means joining two or more strings together.

In C++ STL strings, we can use the `+` operator to concatenate strings.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello ";
    string str2 = "World";

    string str3 = str1 + str2;

    cout << str3;

    return 0;
}
```

Output:

```text
Hello World
```

Here:

- `str1` contains `"Hello "`.
- `str2` contains `"World"`.
- `str3` stores the combined result.

This operation is called **string concatenation**.

### Important

The `+` operator works directly with `std::string` objects.

For C-style character arrays, we generally use functions such as `strcat()` from `<cstring>` instead.

---

## 16. Comparing Two Strings

C++ STL strings allow us to compare two strings using relational operators.

For example:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Husnain";
    string str2 = "Husnain";

    cout << (str1 == str2);

    return 0;
}
```

Output:

```text
1
```

Here, `1` represents `true`.

Both strings contain the same characters in the same order.

### Different Strings

```cpp
string str1 = "Hello";
string str2 = "World";

cout << (str1 == str2);
```

Output:

```text
0
```

Because the strings are different.

### Why Is This Useful?

With character arrays, using `==` does not compare the contents of two arrays.

It compares their addresses after array-to-pointer conversion.

To compare C-style string contents, we generally use:

```cpp
strcmp(str1, str2);
```

For STL strings, we can simply use:

```cpp
str1 == str2
```

This makes string comparison much easier.

---

## 17. Lexicographical Comparison

We can also compare strings using:

- `>`
- `<`
- `>=`
- `<=`

These operators compare strings lexicographically.

Lexicographical comparison means comparing strings according to character order, similar to dictionary order.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "apple";
    string str2 = "banana";

    cout << (str1 < str2);

    return 0;
}
```

Output:

```text
1
```

Why?

Because `"apple"` comes before `"banana"` in lexicographical order.

### How Does It Work?

The comparison happens character by character.

For example:

```text
apple
banana
```

The first characters are:

```text
a and b
```

Since `a` comes before `b`, `"apple"` is smaller than `"banana"`.

If the first characters are equal, the comparison continues to the next characters until a difference is found or one string ends.

**Important:** C++ string comparisons are case-sensitive and use character ordering, not natural-language dictionary rules. Uppercase and lowercase letters can produce different comparison results.

---

## 18. Finding the Length of an STL String

We can use the built-in `.length()` method to calculate the length of a string.

### Syntax

```cpp
str.length();
```

We can also use:

```cpp
str.size();
```

Both return the number of characters in the string.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Husnain";

    cout << str.length();

    return 0;
}
```

Output:

```text
7
```

### Important Difference

For a C-style string:

```cpp
strlen(arr);
```

For an STL string:

```cpp
str.length();
```

Both calculate the number of characters, but they work with different string representations.

---

## 19. Taking Input in STL Strings

We can use `cin` to take a single-word input.

### Example

```cpp
string str;

cin >> str;
```

However, just like character arrays, `cin` stops reading when it encounters whitespace.

For example:

Input:

```text
Hello World
```

Stored value:

```text
Hello
```

To read a complete line containing spaces, we use the `getline()` function.

### Syntax

```cpp
getline(cin, str);
```

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";

    getline(cin, str);

    cout << str;

    return 0;
}
```

Input:

```text
Hello from my college
```

Output:

```text
Hello from my college
```

The complete sentence is stored in the string.

### Difference Between Both getline Functions

| Character Array | STL String |
|---|---|
| `cin.getline(arr, 100);` | `getline(cin, str);` |
| Reads into a character array | Reads into an STL string |
| Size must be provided | No array size required |

The STL string version can also accept a custom delimiter:

```cpp
getline(cin, str, '$');
```

It reads until `$` is encountered.

### Important Input Issue

If you use `cin >>` before `getline()`, the newline left in the input buffer may cause `getline()` to read an empty line.

For example:

```cpp
int age;
string name;

cin >> age;
cin.ignore();

getline(cin, name);
```

Here, `cin.ignore()` removes the leftover newline before reading the full name.

---

## 20. Accessing Individual Characters in STL Strings

We can access individual characters using square bracket notation.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "College";

    cout << str[0] << endl;
    cout << str[1] << endl;
    cout << str[2] << endl;

    return 0;
}
```

Output:

```text
C
o
l
```

Just like arrays, string indexing starts from zero.

| Index | Character |
|---|---|
| 0 | C |
| 1 | o |
| 2 | l |
| 3 | l |
| 4 | e |
| 5 | g |
| 6 | e |

We can also modify individual characters:

```cpp
string str = "Hello";

str[0] = 'Y';

cout << str;
```

Output:

```text
Yello
```

---

## 21. Traversing an STL String Using a Normal For Loop

We can access each character using its index.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "College";

    for (int i = 0; i < str.length(); i++) {
        cout << str[i] << " ";
    }

    return 0;
}
```

Output:

```text
C o l l e g e
```

### Explanation

- `i = 0`: Start from the first character.
- `i < str.length()`: Continue until the last character.
- `i++`: Move to the next index.
- `str[i]`: Access the character at the current index.

---

## 22. Traversing an STL String Using a Range-Based For Loop

We can also use a range-based for loop.

### Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "College";

    for (char ch : str) {
        cout << ch << " ";
    }

    return 0;
}
```

Output:

```text
C o l l e g e
```

### Explanation

In every iteration:

1. One character is picked from the string.
2. It is stored in the variable `ch`.
3. The character is printed.
4. The loop moves to the next character.

This approach is useful when we need to access every character without needing its index.

---

# PART 3: REVERSING STRINGS

## 23. What Is String Reversal?

Reversing a string means changing the order of its characters from last to first.

### Example

Original string:

```text
HELLO
```

Reversed string:

```text
OLLEH
```

Another example:

```text
HUSNAIN
```

Reversed:

```text
NIANSUH
```

We will learn two approaches:

1. Reversing a character array manually.
2. Reversing an STL string using the built-in `reverse()` function.

---

## 24. Two-Pointer Approach

Before reversing a string, we need to understand the two-pointer approach.

Suppose we have an array:

```text
10 20 30 40
```

We want to reverse it:

```text
40 30 20 10
```

We can solve this using two pointers:

- `start`: Points to the first element.
- `end`: Points to the last element.

### Steps

1. Start points to index 0.
2. End points to the last index.
3. Swap the values at both positions.
4. Increment `start`.
5. Decrement `end`.
6. Repeat until `start` is no longer less than `end`.

### Visual Explanation

Initial:

```text
10  20  30  40
^           ^
start       end
```

After first swap:

```text
40  20  30  10
    ^   ^
    start end
```

After second swap:

```text
40  30  20  10
```

The array is reversed.

The same logic can be applied to character arrays and STL strings.

---

## 25. Reversing a Character Array Manually

Suppose we have:

```cpp
char arr[] = "HELLO";
```

Internally:

| Index | Character |
|---|---|
| 0 | H |
| 1 | E |
| 2 | L |
| 3 | L |
| 4 | O |
| 5 | \0 |

The actual string length is 5.

We do not include the null character in the reversal.

### Logic

Initialize:

```cpp
int start = 0;
int end = strlen(arr) - 1;
```

Why `strlen(arr) - 1`?

Because indexing starts from zero.

For a string of length 5, the last valid character is at index 4.

Then:

- Swap `arr[start]` and `arr[end]`.
- Increase `start`.
- Decrease `end`.
- Continue until `start >= end`.

### Complete Code

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[] = "HELLO";

    int start = 0;
    int end = strlen(arr) - 1;

    while (start < end) {
        swap(arr[start], arr[end]);

        start++;
        end--;
    }

    cout << arr;

    return 0;
}
```

Output:

```text
OLLEH
```

### Time Complexity

The algorithm takes:

`O(n)`

Because we traverse approximately half of the string and perform swaps.

### Space Complexity

`O(1)` auxiliary space.

Because we reverse the string in place without creating another array.

---

## 26. LeetCode Problem 344 – Reverse String

The lecture also discusses the LeetCode problem:

**Problem Number: 344 – Reverse String**

The problem provides a vector of characters and asks us to reverse it in place.

Example:

Input:

```text
["h","e","l","l","o"]
```

Output:

```text
["o","l","l","e","h"]
```

The same two-pointer approach is used.

### C++ Solution

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {

            swap(s[start], s[end]);

            start++;
            end--;
        }
    }
};
```

### Explanation

- `start = 0`: First character.
- `end = s.size() - 1`: Last character.
- `swap()`: Exchanges two characters.
- `start++`: Moves the first pointer forward.
- `end--`: Moves the second pointer backward.

The process continues until both pointers meet or cross.

**Complexity:**

- Time: `O(n)`
- Auxiliary Space: `O(1)`

---

## 27. Reversing an STL String Using the Built-in reverse() Function

C++ provides a built-in algorithm called `reverse()`.

It belongs to the STL algorithms library.

### Header File

```cpp
#include <algorithm>
```

### Syntax

```cpp
reverse(str.begin(), str.end());
```

Here:

- `str.begin()` returns an iterator pointing to the first character.
- `str.end()` returns an iterator pointing just after the last character.

The function reverses the elements in the specified range.

### Example

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string str = "College";

    reverse(str.begin(), str.end());

    cout << str;

    return 0;
}
```

Output:

```text
egelloC
```

### Why Is This Easier?

Compare both approaches:

**Manual approach:**

```cpp
int start = 0;
int end = str.length() - 1;

while (start < end) {
    swap(str[start], str[end]);

    start++;
    end--;
}
```

**Built-in approach:**

```cpp
reverse(str.begin(), str.end());
```

Both reverse the string, but the second approach requires much less code.

### What Are begin() and end()?

These functions return iterators.

An iterator is an object that allows us to access or move through elements of a container.

For now, remember:

- `begin()` represents the first element.
- `end()` represents the position immediately after the last element.

The `reverse()` algorithm uses these two iterators to identify the range that needs to be reversed.

### Complexity

- Time Complexity: `O(n)`
- Auxiliary Space: `O(1)` for the standard in-place reversal algorithm.

---

# PART 4: HOMEWORK PROBLEM

## 28. Check Whether a String Is a Palindrome

The lecture ends with a homework problem.

**Problem: Determine whether a given string is a palindrome.**

### What Is a Palindrome?

A palindrome is a string that reads the same from left to right and right to left.

### Examples

| String | Reversed | Result |
|---|---|---|
| `racecar` | `racecar` | Palindrome |
| `madam` | `madam` | Palindrome |
| `level` | `level` | Palindrome |
| `hello` | `olleh` | Not a palindrome |
| `husnain` | `niansuh` | Not a palindrome |

### Problem Statement

You are given a string containing lowercase English letters from `a` to `z`.

You need to determine whether the string is a palindrome.

You are provided with a Boolean function:

```cpp
bool isPalindrome(string str)
```

Complete this function.

The function should:

- Return `true` if the string is a palindrome.
- Return `false` if the string is not a palindrome.

### Hint

You can use the two-pointer approach.

1. Initialize one pointer at the beginning.
2. Initialize another pointer at the end.
3. Compare the characters at both positions.
4. If they are different, the string is not a palindrome.
5. If they are the same, move both pointers toward the center.
6. If all corresponding characters match, the string is a palindrome.

**Try solving this problem yourself before looking at its solution in the next lecture.**

---

# PART 5: IMPORTANT REVISION SHEET

## 29. Important Functions and Syntax

| Purpose | Character Array | STL String |
|---|---|---|
| Declaration | `char arr[100];` | `string str;` |
| Initialization | `char arr[] = "Hello";` | `string str = "Hello";` |
| Input (single word) | `cin >> arr;` | `cin >> str;` |
| Input (full line) | `cin.getline(arr, 100);` | `getline(cin, str);` |
| Output | `cout << arr;` | `cout << str;` |
| Length | `strlen(arr)` | `str.length()` |
| Access character | `arr[i]` | `str[i]` |
| Concatenation | `strcat()` | `+` |
| Comparison | `strcmp()` | `==`, `<`, `>` |
| Reverse | Manual two-pointer approach | `reverse(str.begin(), str.end())` |

## 30. Important Header Files

| Header File | Purpose |
|---|---|
| `<iostream>` | Input and output |
| `<string>` | STL string class |
| `<cstring>` | C-style string functions such as `strlen()` and `strcmp()` |
| `<algorithm>` | STL algorithms such as `reverse()` and `swap()` |

## 31. Important Concepts to Remember

1. A string is a sequence of characters.
2. Character arrays are used to store C-style strings.
3. A C-style string must end with a null character (`\0`).
4. The null character has ASCII value 0.
5. The null character occupies one byte.
6. `strlen()` calculates string length without counting `\0`.
7. `cin` stops reading at whitespace.
8. `cin.getline()` reads a complete line into a character array.
9. A delimiter determines where input reading stops.
10. STL strings belong to the `string` class.
11. STL strings manage their memory dynamically.
12. The `+` operator concatenates STL strings.
13. The `==` operator compares STL string contents.
14. `.length()` and `.size()` return the length of an STL string.
15. `getline(cin, str)` reads a complete line into an STL string.
16. `str[i]` accesses a character using its index.
17. Range-based loops can traverse strings.
18. Two pointers can reverse strings in place.
19. `reverse(str.begin(), str.end())` reverses an STL string.
20. A palindrome reads the same forward and backward.

---

# PART 6: PRACTICE QUESTIONS

Try these questions to test your understanding.

### Conceptual Questions

1. What is a string in C++?
2. What is the difference between a character and a string?
3. What is a character array?
4. Why do we need a null character in C-style strings?
5. What is the ASCII value of `\0`?
6. Does `strlen()` count the null character?
7. Why does `cin` stop reading after a space?
8. What is the difference between `cin.getline()` and `getline()`?
9. What is a string literal?
10. What is the difference between a character array and an STL string?
11. Why are STL strings called dynamic?
12. What is string concatenation?
13. How do we compare two STL strings?
14. What is lexicographical comparison?
15. What are iterators?
16. What do `begin()` and `end()` return?
17. What is the two-pointer approach?
18. What is a palindrome?

### Coding Practice

1. Take a string as input and print it.
2. Calculate the length of a string using `strlen()`.
3. Calculate the length of a C-style string using a loop.
4. Count the number of vowels in a string.
5. Count the number of consonants in a string.
6. Reverse a character array using two pointers.
7. Reverse an STL string using `reverse()`.
8. Compare two strings.
9. Concatenate two strings.
10. Check whether a string is a palindrome.

---

# Final Takeaway

There are two major ways to work with strings in C++:

**1. Character Arrays (C-style strings)**

These store characters in a fixed-size array and require a null character (`\0`) to mark the end of the string. Many operations require manual implementation or C-style library functions.

**2. STL Strings**

These use the built-in `string` class. They manage memory automatically and provide convenient operations such as concatenation, comparison, length calculation, and input handling.

For DSA problem-solving in C++, becoming comfortable with STL strings is especially important because most string-based coding problems use `string` objects.

