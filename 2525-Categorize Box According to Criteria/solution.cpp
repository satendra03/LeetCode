/*
Given four integers length, width, height, and mass, representing the dimensions and mass of a box, respectively, return a string representing the category of the box.

The box is "Bulky" if:
    Any of the dimensions of the box is greater or equal to 104.
    Or, the volume of the box is greater or equal to 109.
If the mass of the box is greater or equal to 100, it is "Heavy".
If the box is both "Bulky" and "Heavy", then its category is "Both".
If the box is neither "Bulky" nor "Heavy", then its category is "Neither".
If the box is "Bulky" but not "Heavy", then its category is "Bulky".
If the box is "Heavy" but not "Bulky", then its category is "Heavy".
Note that the volume of the box is the product of its length, width and height.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        size_t volume = (long long)length * (long long)width * (long long)height;
        bool Bulky = false, Heavy = false, Both = false, Neither = false;
        if (length >= 10000 || width >= 10000 || height >= 10000 ||
            volume >= 1000000000)
            Bulky = true;
        if (mass >= 100)
            Heavy = true;
        if (Bulky && Heavy)
            return "Both";
        if (!Bulky && !Heavy)
            return "Neither";
        if (Bulky && !Heavy)
            return "Bulky";
        if (Heavy && !Bulky)
            return "Heavy";
        return "";
    }
};

// Test function
int main() {
    Solution sol;
    int length = 10001, width = 9999, height = 10000, mass = 50;
    string category = sol.categorizeBox(length, width, height, mass);
    cout << "Category: " << category << endl;
    return 0;
}