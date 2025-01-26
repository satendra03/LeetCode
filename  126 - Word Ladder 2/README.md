#  126 - Word Ladder 2

## Description

A transformation sequence from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that beginWord does not need to be in wordList.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return all the shortest transformation sequences from `beginWord` to `endWord`, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words `[beginWord, s1, s2, ..., sk]`.

## Approach

1. **Input Validation**:
   - Check if the `endWord` exists in the `wordList`. If not, return an empty result.
   - Use an unordered set for efficient lookups of words in the `wordList`.

2. **Breadth-First Search (BFS)**:
   - Start BFS from the `beginWord`, marking its depth as 1.
   - For each word in the BFS, transform it by replacing one character at a time (from 'a' to 'z').
   - If the transformed word is in the `wordList`, push it to the queue, remove it from the list, and record its depth.
   - Stop BFS when the `endWord` is found and track its depth.

3. **Track Depth**:
   - Use an unordered map to store the depth of each word encountered during BFS. This helps ensure that only valid paths in the shortest transformation sequence are followed in the DFS step.

4. **Depth-First Search (DFS)**:
   - Start DFS from the `endWord` to backtrack to the `beginWord`.
   - Add the current word to the path and explore all valid transformations (words with depth one less than the current word).
   - If the `beginWord` is reached, store the path as a valid transformation sequence.

5. **Path Construction**:
   - Reverse the constructed path during DFS before adding it to the final result since DFS constructs the path backward from `endWord` to `beginWord`.

6. **Return Results**:
   - Return all possible shortest transformation sequences stored during DFS.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
