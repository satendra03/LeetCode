class Solution {
public:
    int longestPalindrome(string s, string t) {

        int ans = 0;
        int n = s.size();
        int m = t.size();

        // s.substr(x,y) s->start, y->size
        // map<string, int> data;

        
        for(int i=0; i<=n; i++){
            for(int j = i; j<=n; j++){
                string subS = s.substr(i, j-i); // substring from s

                for(int k=0; k<=m; k++){
                    for(int l=k; l<=m; l++){
                        string subT = t.substr(k, l-k); // substring from t

                        string finalStr = subS + subT;
                        int size = finalStr.size();
                        if(isPalindrome(finalStr)) ans = max(ans, size);
                    }
                }
            }
        }

        return ans;
    }
private:
    bool isPalindrome(string &str) {
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }  
    int max(int a,int b){
        if(a > b) return a;
        return b;
    }
};