class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> data(candyType.begin(), candyType.end());
        int num = candyType.size() / 2;
        if(data.size() >= num) return num;
        return data.size();
    }
};