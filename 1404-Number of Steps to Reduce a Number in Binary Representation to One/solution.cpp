#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    long long numSteps(string s) {
        int count = 0; // To store the number of steps taken
        int carry = 0; // To store the carry in case of addition

        // Start from the last bit and move towards the first bit
        for (int i = s.size() - 1; i > 0; --i) {
            int currentBit = s[i] - '0' + carry; // Calculate the current bit value including the carry
            
            if (currentBit == 1) { 
                // If the current bit (including carry) is 1, it means we need to make it 0 and add a carry
                carry = 1;
                count += 2; // 1 step to make it 0 and 1 step to add 1 to the next bit
            }
            else {
                // If the current bit (including carry) is 0, just move to the next bit
                count += 1; // 1 step to move to the next bit
            }
        }
        // If there's a carry left after processing all bits, we need 1 more step to complete the process
        return count + carry;
    }
};

int main() {
    // Example input
    string s = "1101";
    
    // Create a Solution object
    Solution solution;
    
    // Call the numSteps method and print the result
    long long result = solution.numSteps(s);
    cout << "The number of steps to reduce the binary string to '1' is: " << result << endl;

    return 0;
}
