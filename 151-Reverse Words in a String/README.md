# Reverse Words in a String

## Description

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

## Approach

1. **Split the String**:
   - Split the input string `s` into a list of words using the `split` method, with a space (" ") as the delimiter.
   - Filter out any empty strings from the list to handle multiple spaces.

2. **Reverse the Words**:
   - Reverse the order of words in the list using the `reverse` method.

3. **Reconstruct the String**:
   - Initialize an empty string `ans` to store the result.
   - Iterate through the reversed list and append each word to `ans`:
     - Add a space before each word (except the first one) to maintain proper spacing.

4. **Return the Result**:
   - Return the final reversed string `ans`.


## How to Use

2. **Run**: `node solution.js`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
