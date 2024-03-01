/*
You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Leetcode Solution
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int count0 = 0, count1 = 0;
        for (char i : s) {
            if (i == '0')
                ++count0;
            else
                ++count1;
        }
        for (int i = 1; i < count1; i++)
            ans.push_back('1');
        for (int i = 1; i <= count0; i++)
            ans.push_back('0');
        return ans + '1';
    }
};

int main() {
    Solution sol;
    string input = "1011101"; // Example input
    string result = sol.maximumOddBinaryNumber(input);
    cout << "Result: " << result << endl;
    return 0;
}
