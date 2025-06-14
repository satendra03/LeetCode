typedef long long ll;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        ll num =0;
        int index = 0;
        while(index<n and s[index]==' ') index++;
        bool isNeg = s[index] == '-' ? true:false;

        if(s[index]=='-' or s[index]=='+') index++;
        while(index<n and s[index]=='0') index++;
        while(index<n and isdigit(s[index])) {
            num = num*10 + s[index++] - '0';
            if(num < INT_MIN or num > INT_MAX) break;
        }

        if (isNeg) num = -num;

        if (num < INT_MIN) return INT_MIN;
        if (num > INT_MAX) return INT_MAX;

        return (int)num;
    }
};