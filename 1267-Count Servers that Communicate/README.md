# 1267-Count Servers that Communicate

## Description

You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

## Approach

1. **Initialization:**
    * Create arrays `row` and `col` to store the count of servers in each row and column respectively.
    * Initialize `total` to 0 to keep track of the total number of servers.

2. **Count Servers and Update Row/Column Counts:**
    * Iterate through the `grid`:
        * If a server is found (`grid[i][j] == 1`):
            * Increment `total`.
            * Increment `row[i]` (count of servers in the current row).
            * Increment `col[j]` (count of servers in the current column).

3. **Count Isolated Servers:**
    * Iterate through the `grid` again:
        * If a server is found:
            * If both `row[i]` and `col[j]` are equal to 1:
                * This server is isolated (only one server in its row and column).
                * Increment a counter for isolated servers.

4. **Calculate Connected Servers:**
    * Subtract the count of isolated servers from the `total` number of servers.
    * Return the result.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
