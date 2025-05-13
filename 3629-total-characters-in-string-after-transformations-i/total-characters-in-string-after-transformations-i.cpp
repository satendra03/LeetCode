class Solution {
public:
    int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {

        long long f[26] = {0};
        for (auto& c:s) f[c - 'a']++;

        for (int i = 0; i < t; i++) {
            long long temp[26] = {0};
            for(int j = 0; j < 25; j++) temp[j+1] = f[j];
            temp[0] = (temp[0] + f[25]) % MOD;
            temp[1] = (temp[1] + f[25]) % MOD;
            for(int j=0; j<26; j++) f[j] = temp[j];
        }

        long long ans = 0;
        for (auto num : f) ans = (ans + num) % MOD;
        return ans;
    }
};

// count = b / c - (a - 1) / c;

// "abcyy"
// 2
// "azbk"
// 1
// "a"
// 78
// "ab"
// 26
// "satendra"
// 237