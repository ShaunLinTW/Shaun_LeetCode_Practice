/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    return *((int*)a) - *((int*)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // simplest solution using quick sort
    // for (int i = 0; i < numsSize; i++) nums[i] *= nums[i];
    // qsort(nums, numsSize, sizeof(int), cmp);
    // *returnSize = numsSize;
    // return nums;

    // two pointers solution (faster)
    // initialize two pointers
    int start = 0;
    int end = numsSize - 1;
    // initialize a result array
    int* result = (int*)malloc(sizeof(int) *numsSize);

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
    *returnSize = numsSize;
    return result;
}