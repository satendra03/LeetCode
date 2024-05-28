// Include necessary headers
#include <iostream>
#include <string>
#include <cmath> // for abs function
#include <algorithm> // for max function

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int m) {
        int len = 0; // To store the maximum length of the substring found
        int val = 0; // To store the current total cost of converting substring of s to t
        int i = 0; // Left pointer for the sliding window

        // Loop through each character in the string using the right pointer j
        for(int j = 0; j < s.size(); j++) {
            // Add the cost of converting current character s[j] to t[j]
            val += abs(s[j] - t[j]);

            // If the total cost exceeds m, adjust the left pointer i to reduce the cost
            if(val > m) {
                val -= abs(s[i] - t[i]);
                i++;
            }

            // Update the maximum length of the valid substring found so far
            len = max(len, j - i + 1);
        }

        return len; // Return the maximum length of the substring
    }
};

// Main function to test the code
int main() {
    // Example input
    string s = "abcd";
    string t = "bcdf";
    int m = 3;

    // Create a Solution object
    Solution solution;

    // Call the equalSubstring method and print the result
    int result = solution.equalSubstring(s, t, m);
    cout << "The maximum length of the substring is: " << result << endl;

    return 0;
}
