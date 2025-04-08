class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> data;
        int ans = 0;
        for(auto& num:nums) data[num]++;
        if(check(data)) return ans;
        for(int i=0; i<n-2; i+=3){
            for(int j=0; j<3; j++){
                if(data[nums[i+j]] > 0) data[nums[i+j]]--;
            }
            ans++;
            if(check(data)) return ans;
        }
        if(check(data)) return ans;
        return ans+1;
    }
private:
    bool check(map<int,int>& data){
        for(auto& pair:data) if(pair.second > 1) return false;
        return true;
    }
};