class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n&1;
        // 0-> false and 1->true;
        n=n>>1;
        while(n){
            int last = n&1;
            n = n>>1;
            if(last==flag) return false;
            flag = !flag;
        }
        return true;

    }
};