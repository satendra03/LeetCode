# Maximum Odd Binary Number

## Description

Given a binary string `s`, return the maximum odd binary number that can be obtained by rearranging the digits of `s`. An odd binary number is a binary number that ends in `1`.

## Approach

1. **Count Digits**:
   - Count the number of `0`s and `1`s in the string.
2. **Construct the Result**:
   - Append `count1 - 1` ones (`1`) to the result string.
   - Append all zeros (`0`) to the result string.
   - Finally, append one `1` to ensure the number is odd.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
