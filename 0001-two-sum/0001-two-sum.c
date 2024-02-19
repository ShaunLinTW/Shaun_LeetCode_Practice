/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2; // initialize the returnSize pointer to 2, which is the size of the returned array
    int* result = (int*)malloc(sizeof(int) * 2); // allocate memory for 2 elements
    // iterate through the array's 1st element
    for (int i = 0; i < numsSize; i++) {
        // iterate through the array's 2nd element
        for (int j = i+1; j < numsSize; j++) {
            // if the sum of the 1st and 2nd element equals to the target, return the indices of the 1st and 2nd element
            if (nums[i] + nums[j] == target) {
                result[0] = i; // index of first element
                result[1] = j; // index of second element
                return result; // return the indices, not the elements
            }
        }
    }
    return result;
}