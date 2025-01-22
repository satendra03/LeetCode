# Number of Provinces

## Description

You are given an `m x n` matrix `board` containing letters `'X'` and `'O'`, capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every `'O'` cell.
Surround: The region is surrounded with `'X'` cells if you can connect the region with `'X'` cells and none of the region cells are on the edge of the `board`.
To capture a surrounded region, replace all `'O's` with `'X's` in-place within the original board. You do not need to return anything.

### Approach to Solve the Problem

1. **Problem Understanding**:
   - Replace all `'O'` regions that are not connected to the boundary with `'X'`.
   - Regions connected to the boundary cannot be flipped to `'X'`.

2. **Steps to Solve**:
   - **Boundary Detection**:
     - Traverse the boundary rows (`0` and `m-1`) and columns (`0` and `n-1`) of the board.
     - For each cell containing `'O'`, start a BFS to mark it and all connected `'O'` cells as "safe" (using a visited matrix).
   - **Breadth-First Search (BFS)**:
     - Use a queue to explore all `'O'` cells connected to the boundary.
     - Explore in four possible directions (up, down, left, right).
     - Mark all visited cells to ensure they are not flipped.
   - **Flipping the Board**:
     - Traverse the board again:
       - Flip all unvisited `'O'` cells to `'X'`.
       - Leave the visited `'O'` cells unchanged (they are safe).

3. **Code Explanation**:
   - `row` and `col`: Used to traverse boundary rows and columns.
   - `visited`: Keeps track of visited cells to avoid reprocessing and to identify safe cells.
   - BFS traversal is implemented using a queue to explore connected `'O'` cells.
   - Final loop flips the non-safe `'O'` cells to `'X'`.



## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
