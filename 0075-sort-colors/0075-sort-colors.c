void sortColors(int* nums, int numsSize) {
    int zeros = 0, ones = 0;
    for (int num = 0; num < numsSize; num++){
        if(nums[num] == 0) zeros++;
        else if(nums[num] == 1) ones++;
    }

    for (int i = 0; i < zeros; ++i) nums[i] = 0;

    for (int i = zeros; i < zeros + ones; ++i) nums[i] = 1;

    for (int i = zeros + ones; i < numsSize; ++i) nums[i] = 2;
}