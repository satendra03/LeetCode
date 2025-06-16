typedef long long ll;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0;
        bool isNegative = false;
        while(index<n and s[index]==' ') index++;
        if(s[index]=='-' or s[index]=='+') {
            isNegative = (s[index]=='-');
            index++;
        }
        long long ans = 0;
        solve(index, s, ans);
        if(ans > INT_MAX) return isNegative ? INT_MIN : INT_MAX;
        return isNegative ? -ans : ans;
    }
private:
    void solve(int index, string& s, long long& ans){
        if(index >= s.size() or !isdigit(s[index])) return;
        ans = ans*10 + s[index]-'0';
        if(ans > INT_MAX) return;
        solve(index+1, s, ans);
    }
};