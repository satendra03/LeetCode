class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long count = 0;
        while(n){
            int digit = n%10;
            if(digit){
                sum += digit;
                num += digit*pow(10, count++);
            }
            n /= 10;
        }
        cout << num << " " << sum;
        return num*sum;
    }
};