class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        vector<string> ans;
        int index = 0;
        map<string, bool> seen;
        string newSegment = "", segmentAfterAdding = "";
        for (int i = 0; i < n; i++) {
            segmentAfterAdding.push_back(s[i]);
            if (seen[segmentAfterAdding])
                newSegment.push_back(s[i]);
            else {
                seen[segmentAfterAdding] = true;
                ans.push_back(segmentAfterAdding);
                newSegment = "";
            }
            segmentAfterAdding = newSegment;
        }
        return ans;
    }
};