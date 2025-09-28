class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> count;
        int left = 0, maxLen = 0;

        for (int right=0; right<n; right++) {
            count[fruits[right]]++;

            if (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) count.erase(fruits[left]);
                left++;
            }

            if(count.size() <= 2) maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
