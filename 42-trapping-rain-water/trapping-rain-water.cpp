class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax(n, -1), nextMax(n, -1);

        // for(int i=n-2; i>=0; i--){
        //     if(nextMax[i+1] == -1) {
        //         if(arr[i+1] > arr[i]) nextMax[i] = arr[i+1];
        //     } else if(nextMax[i+1] > arr[i]) nextMax[i] = nextMax[i+1]; 
        // }
        // for(int i=1; i<n; i++){
        //     if(preMax[i-1] == -1) {
        //         if(arr[i-1] > arr[i]) preMax[i] = arr[i-1];
        //     } else if(preMax[i-1] > arr[i]) preMax[i] = preMax[i-1];
        // }

        preMax[0] = arr[0];
        for(int i=1; i<n; i++) preMax[i] = max(arr[i], preMax[i-1]);
        nextMax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) nextMax[i] = max(arr[i], nextMax[i+1]);

        int ans = 0;
        for(int i=0; i<n; i++){
            if(preMax[i]!=-1 and nextMax[i]!=-1){
                int height = min(preMax[i], nextMax[i]);
                ans += height-arr[i];
            }
        }
        return ans;
        
    }
};