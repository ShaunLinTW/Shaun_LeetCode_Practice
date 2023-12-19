class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using bitwise XOR
        int result = 0;
        for (auto i : nums) {
            result ^= i;
        }
        return result;
    }
};