# Number of Provinces

## Description

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the total number of provinces.

## Approach

1. **Convert Adjacency Matrix to Adjacency List**:
   - Traverse the `isConnected` matrix to create an adjacency list for efficient traversal.
   - Ignore self-loops (`isConnected[i][i]`).

2. **Breadth-First Search (BFS)**:
   - Use BFS to traverse connected components starting from unvisited nodes.
   - Mark nodes as visited during traversal.

3. **Count Provinces**:
   - For each unvisited node, perform BFS and increment the province count.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
