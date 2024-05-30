# Categorize Box According to Criteria

## Description

Given the dimensions (`length`, `width`, `height`) and `mass` of a box, categorize the box based on the following criteria:

- A box is considered **Bulky** if any of the dimensions are greater than or equal to 10000 units, or if the volume of the box is greater than or equal to 1,000,000,000 cubic units.
- A box is considered **Heavy** if its mass is greater than or equal to 100 units.
- A box can be categorized as:
  - "Both" if it is both Bulky and Heavy.
  - "Neither" if it is neither Bulky nor Heavy.
  - "Bulky" if it is Bulky but not Heavy.
  - "Heavy" if it is Heavy but not Bulky.

## Approach

1. **Calculate Volume**:
   - Compute the volume of the box using the formula `volume = length * width * height`.
2. **Determine Bulky**:
   - Check if any dimension is >= 10000 units or if the volume >= 1,000,000,000 cubic units.
3. **Determine Heavy**:
   - Check if the mass >= 100 units.
4. **Categorize the Box**:
   - Return the appropriate category based on the Bulky and Heavy flags.

## How to Use

1. **Compile**: `g++ -o solution solution.cpp`
2. **Run**: `./solution`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
