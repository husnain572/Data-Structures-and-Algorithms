# C++ Character Arrays vs. String Class

**Concepts Covered:** `strlen`, `cin`, `getline`, string concatenation, indexing

## Theoretical Explanation

In C++, we have two main ways to handle strings:

### 1. Character Arrays (C-style strings)
- These are arrays of characters terminated by a null character `\0`.
- If `\0` is missing, functions like `strlen()` or `cout` may behave unpredictably.
- Requires manual memory management and is more prone to errors.
- Useful in low-level systems like embedded environments.

### 2. String Class (`std::string` from C++ Standard Library)
- Safer, easier, and more powerful alternative.
- Automatically manages memory and null-termination.
- Provides built-in functions like `.length()`, `.substr()`, `.find()`, etc.
- Supports input using `getline(cin, str, delimiter)` — ideal for full-line or delimited input.
- Allows easy concatenation using the `+` operator.

## Input Handling
- `cin >> str` reads only until the first whitespace.
- `cin.getline(char_array, size, delimiter)` is better for multi-word or custom-delimited input.
- `getline(cin, string_variable, delimiter)` is used with `std::string` for safer and clearer code.

## Recommendation
- Use `char[]` when you need low-level control or due to specific constraints.
- Prefer `std::string` in modern C++ programs due to simplicity and flexibility.
