typedef long long ll;
class Solution {
public:
    vector<ll> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto& num:nums) num = num%k;
        vector<ll> ans(k, 0);
        unordered_map<ll,ll> prev;
        int step = 0;
        for(auto& num:nums){
            unordered_map<ll,ll> curr;
            curr[num]++;
            for(auto& [rem, freq]:prev) curr[ (rem*num)%k ] +=  freq;
            for(auto& [rem, freq]:curr) ans[rem]+=freq;
            prev = curr;
        }
        return ans;
    }
};