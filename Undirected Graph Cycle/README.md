# Undirected Graph Cycle


## Description

Given an undirected graph with `V` vertices labelled from `0` to `V-1` and `E` edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where `adj[i]` contains all the vertices that are directly connected to vertex `i`.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex `i` and vertex `j`, both `j` will be `adj[i]` and `i` will be in `adj[j]`.

### Approach

1. **Graph Representation**:
   - The graph is represented using an adjacency list, where each vertex `i` is connected to all vertices in `adj[i]`.

2. **Cycle Detection using BFS**:
   - Use Breadth First Search (BFS) to traverse the graph.
   - Maintain a `visited` vector to track whether a vertex has been visited.
   - Use a queue to store pairs of vertices and their parents. Each pair consists of the current vertex and the vertex from which it was discovered.

3. **Algorithm**:
   - For each vertex `i` from `0` to `n-1`, if it is not visited, perform the following:
     - Initialize a BFS queue and push the starting vertex `i` with a parent of `-1`.
     - While the queue is not empty:
       - Dequeue the front element, marking the current vertex as visited.
       - For each neighbor of the current vertex:
         - If the neighbor is already visited and is not the parent of the current vertex, a cycle is detected.
         - If the neighbor is not visited, add it to the queue with the current vertex as its parent.

4. **Return**:
   - If any cycle is detected during the BFS traversal, return `true`.
   - If no cycles are detected, return `false`.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
