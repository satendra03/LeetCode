class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[start]);
                start++;
            }
        }
        for (int i = n-1; i > -1; i--) {
            if (nums[i] == 2) {
                swap(nums[i], nums[end]);
                end--;
            }
        }
    }
};