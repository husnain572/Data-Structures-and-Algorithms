# Char Arrays & Strings
---

# 1. Character Basics

In C++, `char` is a data type used to store single characters.

```cpp
char ch = 'A';
````

* Size of `char` = 1 byte
* Characters are stored internally using ASCII values.

---

# 2. ASCII Values

ASCII stands for:

> American Standard Code for Information Interchange

Every character has a numeric ASCII value.

Examples:

```cpp
'a' -> 97
'z' -> 122

'A' -> 65
'Z' -> 90

'0' -> 48
'9' -> 57
```

Example Code:

```cpp
#include<iostream>
using namespace std;

int main(){

    char ch = 'a';

    cout << ch << endl;
    cout << int(ch) << endl;

    return 0;
}
```

Output:

```txt
a
97
```

---

# Character Position Trick

Very useful in interview problems.

```cpp
char ch = 'f';

int position = ch - 'a';
cout << position;
```

Output:

```txt
5
```

Reason:

```txt
'f' = 102
'a' = 97

102 - 97 = 5
```

Reverse Conversion:

```cpp
char ch = 'a' + 5;

cout << ch;
```

Output:

```txt
f
```

---

# 3. Character Arrays

Character arrays are arrays of type `char`.

Example:

```cpp
char arr[5];
```

---

# 4. C-Strings

A C-string is a character array terminated by:

```cpp
'\0'
```

Example:

```cpp
char word[] = "code";
```

Memory Representation:

```txt
[c][o][d][e][\0]
```

---

# 5. Null Character `'\0'`

The null character marks the end of a string.

ASCII value of `'\0'` is:

```cpp
0
```

Without `'\0'`, C++ cannot determine where the string ends.

---

# Why Null Character Is Important

Wrong:

```cpp
char arr[] = {'c','o','d','e'};
```

This is NOT a proper C-string.

Correct:

```cpp
char arr[] = {'c','o','d','e','\0'};
```

---

# 6. Ways to Initialize Character Arrays

## Method 1

```cpp
char arr1[] = "code";
```

Compiler automatically adds `'\0'`.

---

## Method 2

```cpp
char arr2[5] = "code";
```

---

## Method 3

```cpp
char arr3[] = {'c','o','d','e','\0'};
```

---

## Method 4

```cpp
char arr4[50] = {'c','o','d','e','\0'};
```

---

# Example Program

```cpp
#include<iostream>
using namespace std;

int main(){

    char arr1[] = "code";
    char arr2[5] = "code";
    char arr3[] = {'c','o','d','e','\0'};
    char arr4[50] = {'c','o','d','e','\0'};

    cout << arr1 << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;
    cout << arr4 << endl;

    return 0;
}
```

---

# String Literal

```cpp
"Hello World"
```

This is called a string literal.

---

# 7. Input & Output in Character Arrays

---

# Using `cin`

```cpp
char word[50];

cin >> word;
```

Limitation:

* Stops reading at space.

Input:

```txt
hello world
```

Output:

```txt
hello
```

---

# Using `cin.getline()`

Used for full sentence input.

Syntax:

```cpp
cin.getline(array_name, size);
```

Example:

```cpp
char sentence[100];

cin.getline(sentence, 100);

cout << sentence;
```

Input:

```txt
hello world
```

Output:

```txt
hello world
```

---

# Using Delimiter

```cpp
cin.getline(sentence, 100, '.');
```

Input:

```txt
Hello world. Pakistan
```

Output:

```txt
Hello world
```

---

# Complete Example

```cpp
#include<iostream>
#include<cstring>

using namespace std;

int main(){

    char word[50];

    cin >> word;

    cout << "Word : " << word << endl;
    cout << "Length : " << strlen(word) << endl;

    cin.ignore();

    char sentence[100];

    cin.getline(sentence, 100);

    cout << "Sentence : " << sentence << endl;
    cout << "Length : " << strlen(sentence);

    return 0;
}
```

---

# 8. Important `<cstring>` Functions

Include:

```cpp
#include<cstring>
```

---

# 1. strlen()

Returns string length.

```cpp
strlen(str)
```

Example:

```cpp
char word[] = "coder";

cout << strlen(word);
```

Output:

```txt
5
```

Time Complexity:

```txt
O(n)
```

---

# 2. strcpy()

Copies source string into destination.

Syntax:

```cpp
strcpy(destination, source);
```

Example:

```cpp
char src[] = "Husnain";
char dest[100];

strcpy(dest, src);

cout << dest;
```

---

# 3. strcat()

Concatenates strings.

Syntax:

```cpp
strcat(str1, str2);
```

Example:

```cpp
char first[100] = "Husnain";
char last[] = " Malik";

strcat(first, last);

cout << first;
```

Output:

```txt
Husnain Malik
```

---

# 4. strcmp()

Compares two strings lexicographically.

Syntax:

```cpp
strcmp(str1, str2)
```

Returns:

```txt
0   -> equal
-ve -> str1 < str2
+ve -> str1 > str2
```

Example:

```cpp
char a[] = "abc";
char b[] = "abd";

cout << strcmp(a, b);
```

---

# 9. String Manipulation Problems

---

# Convert to Uppercase

```cpp
#include<iostream>
#include<cstring>
using namespace std;

void toUpper(char word[], int n){

    for(int i = 0; i < n; i++){

        char ch = word[i];

        if(ch >= 'A' && ch <= 'Z'){
            continue;
        }

        word[i] = ch - 'a' + 'A';
    }
}

int main(){

    char word[] = "hUsNaIn";

    toUpper(word, strlen(word));

    cout << word;

    return 0;
}
```

---

# Reverse a String

```cpp
#include<iostream>
#include<cstring>
using namespace std;

void reverse(char word[], int n){

    int st = 0;
    int end = n - 1;

    while(st < end){

        swap(word[st], word[end]);

        st++;
        end--;
    }
}

int main(){

    char word[] = "coder";

    reverse(word, strlen(word));

    cout << word;

    return 0;
}
```

---

# Palindrome Check

A palindrome reads same from both sides.

Examples:

```txt
racecar
madam
level
```

Code:

```cpp
#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char word[], int n){

    int st = 0;
    int end = n - 1;

    while(st < end){

        if(word[st] != word[end]){
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main(){

    char word[] = "racecar";

    if(isPalindrome(word, strlen(word))){
        cout << "Palindrome";
    }else{
        cout << "Not Palindrome";
    }

    return 0;
}
```

---

# 10. C++ STL Strings

C++ provides a built-in `string` class.

Advantages over char arrays:

* Dynamic size
* Easy to use
* Rich built-in functions
* Safer than C-strings

Include:

```cpp
#include<string>
```

---

# Creating Strings

```cpp
string str = "Hello";
```

---

# Taking Input

## Single Word

```cpp
cin >> str;
```

---

## Full Sentence

```cpp
getline(cin, str);
```

---

# Example Program

```cpp
#include<iostream>
#include<string>
using namespace std;

int main(){

    string str = "Hello";

    cout << str << endl;

    str = "World";

    cout << str << endl;

    string sentence;

    getline(cin, sentence);

    cout << sentence << endl;

    return 0;
}
```

---

# Traversing a String

## Using Loop

```cpp
for(int i = 0; i < str.length(); i++){
    cout << str[i] << " ";
}
```

---

## Using Range-Based Loop

```cpp
for(char ch : str){
    cout << ch << " ";
}
```

---

# 11. Important String Functions

---

# length()

```cpp
str.length()
```

Returns string length.

---

# at()

```cpp
str.at(index)
```

Example:

```cpp
cout << str.at(3);
```

---

# substr()

```cpp
str.substr(start, length)
```

Example:

```cpp
str.substr(1,4)
```

---

# find()

Returns index of first occurrence.

```cpp
str.find("abc")
```

Example:

```cpp
string str = "Husnain Malik";

cout << str.find("Malik");
```

---

# Complete Example

```cpp
#include<iostream>
using namespace std;

int main(){

    string str = "Husnain Husnain";

    cout << str.length() << endl;

    cout << str.at(3) << endl;

    cout << str.substr(1,4) << endl;

    cout << str.find("nain") << endl;

    return 0;
}
```

---

# 12. Common Interview Problems

---

# Valid Anagram

Two strings are anagrams if they contain same characters with same frequencies.

Examples:

```txt
anagram -> nagaram
listen  -> silent
```

---

# Optimized Approach

Use frequency array.

Time Complexity:

```txt
O(n)
```

Space Complexity:

```txt
O(1)
```

---

# Code

```cpp
#include<iostream>
using namespace std;

bool isAnagram(string str1, string str2){

    if(str1.length() != str2.length()){
        return false;
    }

    int count[26] = {0};

    for(int i = 0; i < str1.length(); i++){

        int idx = str1[i] - 'a';

        count[idx]++;
    }

    for(int i = 0; i < str2.length(); i++){

        int idx = str2[i] - 'a';

        if(count[idx] == 0){
            return false;
        }

        count[idx]--;
    }

    return true;
}

int main(){

    string str1 = "anagram";
    string str2 = "nagaram";

    if(isAnagram(str1, str2)){
        cout << "Valid Anagram";
    }else{
        cout << "Invalid Anagram";
    }

    return 0;
}
```

---

# 13. Time Complexities

| Operation        | Complexity |
| ---------------- | ---------- |
| strlen()         | O(n)       |
| strcpy()         | O(n)       |
| strcat()         | O(n)       |
| strcmp()         | O(n)       |
| Reverse String   | O(n)       |
| Palindrome Check | O(n)       |
| Anagram Check    | O(n)       |

---

# 14. Common Mistakes

---

# 1. Forgetting `'\0'`

Wrong:

```cpp
char arr[] = {'a','b','c'};
```

Correct:

```cpp
char arr[] = {'a','b','c','\0'};
```

---

# 2. Using `cin` for Sentences

Wrong:

```cpp
cin >> sentence;
```

Correct:

```cpp
cin.getline(sentence, 100);
```

---

# 3. Array Size Too Small

Wrong:

```cpp
char arr[4] = "code";
```

Need space for `'\0'`.

Correct:

```cpp
char arr[5] = "code";
```

---

# 4. Mixing `cin` and `getline`

After `cin`, newline remains in buffer.

Fix:

```cpp
cin.ignore();
```

---

# 15. Interview Tips

* Master ASCII conversions.
* Practice frequency-array problems.
* Learn two-pointer technique.
* Prefer STL `string` in interviews unless interviewer specifically asks for char arrays.
* Practice:

  * Reverse String
  * Palindrome
  * Anagram
  * String Compression
  * Valid Parentheses
  * Sliding Window problems
