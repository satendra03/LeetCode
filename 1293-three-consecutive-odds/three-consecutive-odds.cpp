class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        for(int i=0; i<n-2; i++){
            if(nums[i]%2 and nums[i+1]%2 and nums[i+2]%2) return true;
        }
        return false;
    }
};