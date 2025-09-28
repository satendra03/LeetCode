class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0;
        unordered_set<char> data;

        int left = 0, right = 0;
        while(right < n){
            if(!data.count(s[right])) {
                data.insert(s[right]);
                int currLen = data.size();
                len = max(len, currLen);
                right++;
            } else {
                data.erase(s[left]);
                left++;
            }
        }
        return len;
        
    }
};