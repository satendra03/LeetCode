class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> nextGreat(n, 0);
        nextGreat[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            if(nextGreat[i+1] == -1){
                if(nums[i+1] > nums[i]) nextGreat[i] = nums[i+1];
                else nextGreat[i] = -1;
            } else {
                if(nextGreat[i+1] > nums[i]) nextGreat[i] = nextGreat[i+1];
                else nextGreat[i] = -1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, nextGreat[i]-nums[i]);
        }
        return ans;
    }
};