/*
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        if (s.size() == 1)
            return 1;
        int left = 0;
        int right = s.size() - 1;
        while (s[left] == s[right] && left < right) {
            while (left < s.size() - 1 && s[left] == s[left + 1])
                left++;
            while (right > 0 && s[right - 1] == s[right])
                right--;
            if(left < s.size()-1) left++;
            if(right > 0) right--;
        }
        if(right < left) return 0;
        return right-left+1;
    }
};

// Test function
int main() {
    Solution sol;
    string input = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    int minLen = sol.minimumLength(input);
    cout << "Minimum Length: " << minLen << endl;
    return 0;
}