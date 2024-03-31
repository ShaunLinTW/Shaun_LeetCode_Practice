int maxSubArray(int* nums, int numsSize) {
    // initialize masSum and currentSum 
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < numsSize; i++){
        // update currentSum
        currentSum += nums[i];

        // if currentSum greater than maxSum, update maxSum to it
        if (currentSum > maxSum){
            maxSum = currentSum;
        }
        // if currentSum smaller than 0, reset it to 0
        if (currentSum < 0){
            currentSum = 0;
        }
    }
    return maxSum;
}