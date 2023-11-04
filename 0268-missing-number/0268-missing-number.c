int missingNumber(int* nums, int numsSize) {
    // initialize as the length of the array
    int ans = numsSize;

    // iterate through the array, and use XOR operation to find the missing number
    for (int i = 0; i < numsSize; i++) {
        ans ^= i ^ nums[i];
    }
    return ans;
}