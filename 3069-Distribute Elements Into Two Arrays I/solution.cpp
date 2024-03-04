/*
You are given a 1-indexed array of distinct integers nums of length n.
You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].
Return the array result.
*/


#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]); // First operation
        arr2.push_back(nums[1]); // Second operation
        for(int i = 2; i < nums.size(); i++) {
            if(arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        for(int i : arr2)
            arr1.push_back(i);
        return arr1;
    }
};

// Test function
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 2, 1, 5};
    vector<int> result = sol.resultArray(nums);
    cout << "Resulting Array: ";
    for(int num : result)
        cout << num << " ";
    cout << endl;
    return 0;
}
