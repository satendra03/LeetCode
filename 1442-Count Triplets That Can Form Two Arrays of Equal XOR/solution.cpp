#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0; // To store the count of triplets satisfying the condition

        // Iterate over all possible pairs (i, j) where i < j
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = 0; // To store the XOR of elements from i to j-1
                
                // Calculate XOR for the first segment [i, j-1]
                for(int temp = i; temp < j; temp++) 
                    a ^= arr[temp];

                // Iterate over all possible k where j <= k < n
                for(int k = j; k < n; k++) {
                    int b = 0; // To store the XOR of elements from j to k
                    
                    // Calculate XOR for the second segment [j, k]
                    for(int temp = j; temp <= k; temp++) 
                        b ^= arr[temp];
                    
                    // If both segments have equal XOR, increment the count
                    if(a == b) 
                        count++;
                }
            }
        }
        return count; // Return the total count of valid triplets
    }
};

// Main function to test the code
int main() {
    // Example input
    vector<int> arr = {2, 3, 1, 6, 7};

    // Create a Solution object
    Solution solution;

    // Call the countTriplets method and print the result
    int result = solution.countTriplets(arr);
    cout << "The number of triplets is: " << result << endl;

    return 0;
}
