class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> freq;
        for(int i:nums) freq[i]++;
        while(freq.size()) {
            for(pair<int,int> p:freq){
                // cout << p.first << " " << p.second << "\n";
                if(p.second) {
                    ans.push_back(p.first);
                    freq[p.first]--;
                }
            }
            for(pair<int,int> p:freq) if(freq[p.first] == 0) freq.erase(p.first);
        }
        return ans;
    }
};