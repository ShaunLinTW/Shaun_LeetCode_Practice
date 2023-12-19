int singleNumber(int* nums, int numsSize) {
    // using XOR to find the single number
    int result = 0;
    for (int i = 0; i < numsSize; i++){
        result ^= nums[i];
    }
    return result;
}