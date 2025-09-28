class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<k; i++)  sum += nums[i];
        int last = n-1;
        int ans = sum;
        for(int i=k-1; i>=0; i--){
            sum -= nums[i];
            sum += nums[last];
            ans = max(ans, sum);
            last--;
        }
        return ans;
    }
};