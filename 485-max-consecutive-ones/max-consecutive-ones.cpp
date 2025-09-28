class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, maxOnes = 0, ones = 0;
        while(right < n){
            if(nums[right]){
                ones++;
                maxOnes = max(maxOnes, ones);
            } else {
                ones = 0;
                left = right+1;
            }
            right++;
        }
        return maxOnes;
    }
};