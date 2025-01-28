# Number of Distinct Islands

## Description

Given a boolean 2D matrix `grid` of size `n * m`. You have to find the number of distinct islands where a group of connected `1`s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

## Approach

1. **Initialization**:
   - Define `n` and `m` for the dimensions of the grid.
   - Use a 2D vector `visited` to track visited cells.
   - Maintain a set `data` to store unique island paths using a custom comparator (`Vector2DComparator`) for vector comparison.

2. **DFS Traversal for Each Island**:
   - Traverse each cell in the grid.
   - If the cell is land (`1`) and not visited, perform a DFS to find the shape of the island.
   - Store the relative path of each island by subtracting the original starting coordinates (`orgX`, `orgY`) to normalize the path coordinates.

3. **DFS Function Details**:
   - Mark the current cell as visited.
   - Record the relative coordinates in the `path`.
   - Move in all four possible directions (up, right, down, left) using the `dx` and `dy` arrays.
   - Recurse if the next cell is within bounds, land, and unvisited.

4. **Store Unique Island Paths**:
   - After each DFS traversal, insert the normalized `path` into the set `data`.
   - Since set only keeps unique elements, this ensures distinct islands are counted.

5. **Result**:
   - Return the size of the set, which represents the number of distinct islands.

### Complexity Analysis
- **Time Complexity**: \(O(N \times M)\) — Each cell is visited at most once during DFS.
- **Space Complexity**: \(O(N \times M)\) — Space for the `visited` grid and the set to store distinct island paths.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
