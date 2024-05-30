# Get Equal Substrings Within Budget

## Description

Given two strings `s` and `t` of the same length, and an integer `m` representing the maximum cost, find the maximum length of a substring that can be changed to make `s` equal to `t` under the budget `m`. The cost of changing the character `s[i]` to `t[i]` is `|s[i] - t[i]|`.

## Approach

1. **Initialize Variables**:
   - Use two pointers `i` and `j` to represent the current window.
   - Initialize `val` to track the current cost and `len` to track the maximum length of the valid substring.
2. **Sliding Window**:
   - Iterate through the string with the pointer `j`.
   - Add the cost of changing `s[j]` to `t[j]` to `val`.
   - If `val` exceeds `m`, adjust the window by incrementing `i` and subtracting the cost of `s[i]` to `t[i]` from `val`.
   - Update `len` to be the maximum of its current value and the current window size (`j - i + 1`).
3. **Return Result**:
   - Return the maximum length of the substring that meets the budget constraint.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
