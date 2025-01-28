class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // for testing purpose
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int fix=0; fix<n-2; fix++)
        {
            if(fix>0 && nums[fix]==nums[fix-1]) continue;
            int left=fix+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[fix]+nums[left]+nums[right];
                if(sum == 0)
                {
                    ans.push_back( {nums[fix], nums[left], nums[right]} );
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }
};