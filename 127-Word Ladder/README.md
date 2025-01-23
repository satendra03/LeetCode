# 127-Word Ladder

## Description

A transformation sequence from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the number of words in the shortest transformation sequence from `beginWord` to `endWord`, or `0` if no such sequence exists.

## Approach

1. **Input Validation**:
   - Check if the `endWord` exists in `wordList`. If not, return 0.
   - If `beginWord` is not in `wordList`, add it.

2. **Graph Construction**:
   - Create an adjacency list where nodes represent words.
   - Add edges between words that differ by exactly one character.

3. **Breadth-First Search (BFS)**:
   - Start BFS from the `beginWord` with an initial level of 1.
   - Use a queue to traverse the graph level by level.
   - Track visited nodes to avoid revisiting words.

4. **Transformation Sequence**:
   - During BFS, if the `endWord` is reached, return the current level as the length of the shortest transformation sequence.
   - If the queue is empty and the `endWord` is not found, return 0.


## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
