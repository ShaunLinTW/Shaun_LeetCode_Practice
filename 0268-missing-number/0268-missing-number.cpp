class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //use bit manipulation, space = O(1)
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            // Using XOR operation
            // [0, 1, 2, 3] ^ [0, 1, 3] = 2
            result ^= i ^ nums[i];
        }
        return result;
    }
};
// XOR operation
// A B C
// 0 0 0
// 0 1 1
// 1 0 1
// 1 1 0