typedef long long ll;
class Solution {
public:
    ll minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, zero1 = 0, sum2 = 0, zero2 = 0;
        for(auto& num:nums1){
            sum1 += num;
            if(!num) zero1++;
        }
        for(auto& num:nums2){
            sum2 += num;
            if(!num) zero2++;
        }

        ll SUM1 = sum1 + zero1;
        ll SUM2 = sum2 + zero2;

        if(SUM1==SUM2) return SUM1;
        if(SUM1 > SUM2 and zero2) return SUM1;
        if(SUM2 > SUM1 and zero1) return SUM2;
        return -1;
    }
};