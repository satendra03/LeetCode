class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxLen = 0, len = 0, maxFreq = 0;
        unordered_map<char, int> data;

        while(right < n){
            data[s[right]]++;
            maxFreq = max(maxFreq, data[s[right]]);

            int currLen = right-left+1;
            int toChange = currLen-maxFreq;
            if(toChange > k){
                data[s[left]]--;
                left++;
                currLen = right-left+1;
            }
            maxLen = max(maxLen, currLen);
            right++;
        }
        return maxLen; 
    }
};