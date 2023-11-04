class Solution {
public:
    vector<int> countBits(int n) {
        // Initialize a vector with n+1 elements and all set to 0
        vector<int> result(n + 1, 0);
        
        // Iterate from 1 to n
        for (int i = 1; i <= n; i++) {
            // For each i, find the number of 1's in its binary representation
            // and assign it to the result vector at index i.
            // To do this, we can use the previously calaulated values in the 
            // result vector for smaller numbers, i.e. (i/2) , and add 1 if i is odd.
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
            
        }
        
        return result;
    }
};