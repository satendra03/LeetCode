# Number of Enclaves

## Description

You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the `grid`.

Return the number of land cells in `grid` for which we cannot walk off the boundary of the grid in any number of moves.

## Approach

1. **Problem Understanding**:
   - We need to count the number of land cells (`1`) that are completely surrounded by water (`0`) and are not connected to the boundary.

2. **Steps to Solve**:
   - **Mark Boundary Land Cells**:
     - Use Depth-First Search (DFS) to mark all land cells connected to the boundary as "visited."
     - This ensures boundary-connected land cells are not considered enclaves.
   - **Count Enclaved Land Cells**:
     - Traverse the grid and count all unvisited land cells. These cells are the enclaves.

3. **Code Explanation**:
   - **DFS Function**:
     - Recursively marks all connected land cells as visited.
   - **Boundary Traversal**:
     - Traverse all boundary rows (`0` and `m-1`) and columns (`0` and `n-1`).
     - Start DFS from any land cell (`1`) found on the boundary.
   - **Count Remaining Land Cells**:
     - Traverse the grid and count land cells that are not visited.

4. **Complexity Analysis**:
   - **Time Complexity**: \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns. Each cell is visited at most once.
   - **Space Complexity**: \(O(m \times n)\), for the `visited` matrix and recursive call stack.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
