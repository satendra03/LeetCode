# Modify the Matrix

## Description

Given a matrix `matrix`, where `matrix[i][j] = -1` indicates that the value at cell `(i, j)` needs to be modified, modify the matrix such that each cell with `-1` is replaced by the maximum value in its column.

## Approach

1. **Find Maximum of Column**:
   - Define a function `maxofcol` to find the maximum value in a given column.
2. **Modify the Matrix**:
   - Iterate through each cell of the matrix.
   - If the cell value is `-1`, replace it with the maximum value in its column using the `maxofcol` function.
3. **Return Modified Matrix**:
   - Return the modified matrix.

## How to Use

1. **Compile**: `g++ -o modify_matrix modify_matrix.cpp`
2. **Run**: `./modify_matrix`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
