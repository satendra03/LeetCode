# Minimum Length of String After Deleting Similar Ends

## Description

Given a string `s`, repeatedly delete characters from the beginning and the end of the string as long as the first and last characters are equal. Return the minimum length of the string after performing this operation.

## Approach

1. **Initialize Pointers**:
   - Use two pointers, `left` at the start of the string and `right` at the end.
2. **Skip Similar Characters**:
   - Move the `left` pointer rightward while the current and next characters are the same.
   - Move the `right` pointer leftward while the current and previous characters are the same.
   - If the characters at `left` and `right` are the same, move both pointers inward.
3. **Determine Result**:
   - If the `right` pointer crosses the `left` pointer, return 0.
   - Otherwise, return the length of the substring between `left` and `right`.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
