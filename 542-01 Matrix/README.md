# 01 Matrix

## Description

Given an `m x n` binary matrix `mat`, return the distance of the nearest `0` for each cell.

The distance between two cells sharing a common edge is `1`.

### Approach

1. **Problem Understanding**:
   - The goal is to calculate the distance of each cell in the matrix from the nearest `0`. 
   - A Breadth-First Search (BFS) approach is ideal for this, as it explores the shortest distance layer by layer.

2. **Initialization**:
   - Use a queue to perform BFS. Each element in the queue stores the coordinates `(i, j)` and the current distance from the nearest `0`.
   - Initialize a result matrix `ans` with all values set to `INT_MAX`.
   - Create a `visited` matrix to avoid processing the same cell multiple times.

3. **Add Zero Cells to Queue**:
   - Iterate through the input matrix:
     - For cells with value `0`, update `ans[i][j]` to `0`, mark them as visited, and push their coordinates into the queue with distance `0`.

4. **BFS Traversal**:
   - Use BFS to calculate distances:
     - Pop the front element of the queue and explore its neighbors in four directions (up, right, down, left).
     - If a neighbor cell is within bounds, not visited, and has not been updated in `ans`, calculate the new distance and update it in `ans`.
     - Push the neighbor into the queue with the updated distance and mark it as visited.

5. **Result Matrix**:
   - After BFS completes, the `ans` matrix contains the shortest distance from each cell to the nearest `0`.

6. **Return**:
   - Return the `ans` matrix as the final result.


## Complexity
- **Time Complexity**: \(O(n \times m)\), where \(n\) is the number of rows and \(m\) is the number of columns. Each cell is processed at most once.
- **Space Complexity**: \(O(n \times m)\), for the queue, visited matrix, and result matrix.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
