typedef long long ll;
class Solution {
public:
    ll MOD = 1000000007;
    int countGoodNumbers(ll n) {
        ll evenIndex = n%2 ? (n/2)+1 : (n/2);
        ll oddIndex = n - evenIndex;
        ll ans = (myPow(5, evenIndex) * myPow(4, oddIndex) )% MOD;
        return (int)ans;
    }
private:
    ll myPow(ll x, ll n) {
        ll ans = 1;
        while(n){
            if(n%2) ans = (ans*x) % MOD;
            x = (x*x) % MOD;
            n /= 2;
        }
        return ans;
    }
};