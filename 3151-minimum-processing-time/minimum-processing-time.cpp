class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        sort(pt.rbegin(), pt.rend());
        sort(t.begin(), t.end());
        int time = INT_MIN;
        for(int i=0; i<pt.size(); i++){
            time = max(time, pt[i]+max({
                t[i*4], t[i*4+1], t[i*4+2], t[i*4+3]
            }));
        }
        return time;
    }
};