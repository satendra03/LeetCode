/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++)
            ans[i] = nums[i] * nums[i];
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Test function
int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(nums);
    cout << "Sorted Squares: ";
    for(int num : result)
        cout << num << " ";
    cout << endl;
    return 0;
}