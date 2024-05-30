# Count Triplets That Can Form Two Arrays of Equal XOR

## Description

Given an array of integers `arr`, return the number of triplets `(i, j, k)` such that `0 <= i < j <= k < arr.length` and the XOR of the subarray `arr[i]` to `arr[j-1]` is equal to the XOR of the subarray `arr[j]` to `arr[k]`.

## Approach

1. **Initialize Variables**:
   - `count` to track the number of valid triplets.
   - `n` to store the length of the array `arr`.
2. **Nested Loops**:
   - Use three nested loops to generate all possible triplets `(i, j, k)`:
     - The outer loop runs from `0` to `n-2` for `i`.
     - The middle loop runs from `i+1` to `n-1` for `j`.
     - The inner loop runs from `j` to `n-1` for `k`.
   - Calculate the XOR for the subarray `arr[i]` to `arr[j-1]` and store it in `a`.
   - Calculate the XOR for the subarray `arr[j]` to `arr[k]` and store it in `b`.
   - If `a` is equal to `b`, increment the `count`.
3. **Return Result**:
   - Return the count of valid triplets.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
