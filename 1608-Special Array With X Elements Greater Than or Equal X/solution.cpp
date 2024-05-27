/*
LeetCode Problem: Special Array With X Elements Greater Than or Equal X
Description:
You are given an array `nums` of non-negative integers. `nums` is called a special array if there exists a number `x` such that there are exactly `x` numbers in `nums` that are greater than or equal to `x`. 
Return `x` if the array is special, otherwise return `-1`. It can be proven that if `x` is found, it is unique.
*/

/*
Approach:
1. Sort the array in ascending order.
2. Use binary search to find the value `x`.
3. Initialize the binary search with `left` as 0 and `right` as 10001 (a value larger than any possible length of `nums`).
4. In each iteration of the binary search:
   - Calculate the middle point `mid`.
   - Count the number of elements in `nums` that are greater than or equal to `mid`.
   - If the count equals `mid`, return `mid`.
   - If the count is greater than `mid`, search the right half by updating `left`.
   - If the count is less than `mid`, search the left half by updating `right`.
5. If no such `x` is found, return `-1`.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Sort the array to make it easier to count elements >= mid
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 10001;
        int mid;

        // Perform binary search to find the special value `x`
        while(left <= right) {
            mid = (left + right) / 2;
            int count = 0;

            // Count the number of elements >= mid
            for(auto i : nums) {
                if(i >= mid) count++;
            }

            // Check if the count equals mid
            if(mid == count) return mid;
            else if(mid < count) left = mid + 1; // Search the right half
            else right = mid - 1; // Search the left half
        }

        // If no special value is found, return -1
        return -1;
    }
};

// Test function
int main() {
    Solution sol;
    vector<int> nums = {3, 5, 6, 7, 8};
    int result = sol.specialArray(nums);
    cout << "Special Array Result: " << result << endl;
    return 0;
}