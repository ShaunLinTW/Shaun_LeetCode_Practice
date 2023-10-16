/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2; // 2 elements
    int* result = (int*)malloc(sizeof(int) * 2); // allocate memory for 2 elements

    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i; // index of first element
                result[1] = j; // index of second element
                return result;
            }
        }
    }
    return result;
}