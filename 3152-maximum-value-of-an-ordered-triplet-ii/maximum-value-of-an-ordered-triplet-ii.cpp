typedef long long ll;
class Solution {
public:
    ll maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max(ans, nums[i]);
            left[i] = ans;
        }
        ans = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            ans = max(ans, nums[i]);
            right[i] = ans;
        }
        ll res = 0;
        for(int i=1; i<n-1; i++){
            res = max(res, (ll)(left[i-1]-nums[i]) * (ll)(right[i+1]));
        }
        return res;
    }
};