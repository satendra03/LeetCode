class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBrackets;
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                int start = openBrackets.top();
                openBrackets.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }

        for(auto c:s){
            if(c == '(' || c == ')') continue;
            ans += c;
        }
        return ans;
    }
};