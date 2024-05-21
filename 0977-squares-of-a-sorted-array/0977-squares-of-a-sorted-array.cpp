class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // simplest solution using quick sort
        // for (auto &x: nums) x *= x;
        // sort(nums.begin(), nums.end());
        // return nums;

        // two pointers solution (faster)
        int numsSize = nums.size();
        int start = 0;
        int end = numsSize - 1;
        // initialize a result vector
        vector<int> result(numsSize);

        for (int i = numsSize - 1; i >= 0; i--){
            if (abs(nums[start]) >= abs(nums[end])){
                result[i] = nums[start] * nums[start];
                start ++;
            }
            else{
                result[i] = nums[end] * nums[end];
                end --;
            }
        }
        return result;
    }
};