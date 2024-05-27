# Distribute Elements Into Two Arrays I

## Description

Given an array `nums`, distribute its elements into two arrays `arr1` and `arr2` according to the following rules:

- First, assign the first element of `nums` to `arr1`.
- Second, assign the second element of `nums` to `arr2`.
- For the remaining elements of `nums`, distribute them alternately to `arr1` and `arr2` such that the elements in `arr1` are strictly greater than the elements in `arr2`.
- Return the resulting array `arr1`.

## Approach

1. **Initialize Arrays**:
   - Create two arrays `arr1` and `arr2`.
2. **Distribute Elements**:
   - Start with the first two elements of `nums` and assign them to `arr1` and `arr2`.
   - Iterate through the remaining elements of `nums`.
   - Compare the last elements of `arr1` and `arr2`.
   - Assign the current element of `nums` to the array with the smaller last element.
3. **Return Result**:
   - Return `arr1`.

## How to Use

1. **Compile**: `g++ -o distribute_elements distribute_elements.cpp`
2. **Run**: `./distribute_elements`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
