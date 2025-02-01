# Topological Sort

## Description

Given an adjacency list for a Directed Acyclic Graph (DAG) where `adj[u]` contains a list of all vertices `v` such that there exists a directed edge `u -> v`. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be `1` else `0`.

## Approach

1. **Graph Representation**:
   - The graph is provided as an adjacency list where each index represents a vertex and the corresponding list contains its neighbors.

2. **Depth-First Search (DFS)**:
   - Traverse the graph using DFS starting from each unvisited vertex.
   - Mark each vertex as visited when it is processed.
   - After processing all neighbors of a vertex, push the vertex onto a stack. This ensures that vertices with no outgoing edges (or all outgoing edges processed) are placed at the top.

3. **Constructing the Topological Order**:
   - Once the DFS is complete for all vertices, the stack contains the vertices in reverse topological order.
   - Pop vertices from the stack one by one to obtain the topological order.

4. **Return the Result**:
   - The resulting vector, constructed by popping from the stack, is the topologically sorted order of vertices.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
