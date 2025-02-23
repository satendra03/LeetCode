class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        int totalDays = n / 4;
        int oddDays = ceil(totalDays / 2.0);
        int evenDays = totalDays/2;
        sort(pizzas.begin(), pizzas.end());
        long long ans = 0;

        for(int i=0; i<oddDays; i++) ans += pizzas[n-i-1];
        
        bool skip = false;
        n = n-oddDays;
        for(int i=0; i<2*evenDays; i++){
            if(!skip) {
                skip = true;
                continue;
            }
            skip = false;
            ans += pizzas[n-1-i];
        }

        
        
        return ans;
        
    }
};