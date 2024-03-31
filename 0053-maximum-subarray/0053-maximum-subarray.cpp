class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // <Simple solution>:
        // initialize max sum, use INT_MIN to ensure that any valid subarray sum will be greater than it
        int maxSum = INT_MIN;
        // initialize current sum
        int currentSum = 0;

        // iterate through array
        for (int i = 0; i < nums.size(); i++){
            currentSum += nums[i];

            // if currentSum greater than maxSum, update maxSum to it
            if (currentSum > maxSum){
                maxSum = currentSum;
            }
            // if smaller than 0, reset currentSum to 0
            if (currentSum < 0){
                currentSum = 0;
            }
        }
        return maxSum;

        // <used max function>:
        // int maxSum = INT_MIN;
        // int currentSum = 0;

        // for (int i = 0; i < nums.size(); i++){
        //     currentSum = max(currentSum + nums[i], nums[i]);
        //     maxSum = max(maxSum, currentSum);
        // }
        // return maxSum;
    }
};
