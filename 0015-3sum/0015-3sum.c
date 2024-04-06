/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    return *((int*)a) - *((int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // sort the input array
    qsort(nums, numsSize, sizeof(int), cmp);

    (*returnSize) = 0; // number of results
    // allocate memory for the result
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * numsSize * numsSize); // number of columns in each result
    
    int** results = (int**)malloc(sizeof(int*) * numsSize * numsSize); // result array

    // iterate through the array until last three elements
    for (int i = 0; i < numsSize - 2; i++){
        // if current element greater then 0, break the loop
        if (nums[i] > 0) break;
        // if current element is same as previous element, skip the current element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // initialize two pointers
        int j = i + 1;
        int k = numsSize - 1;

        // iterate through the array until j pointer meets k pointer
        while (j < k){
            // calculate the sum of three elements
            int sum = nums[i] + nums[j] + nums[k];
            // if sum greater then zero, move pointer k to left
            if (sum > 0) k--;
            // if sum less then zero, move pointer j to right
            else if (sum < 0) j++;
            // if sum equal to zero, append i, j, k to results array
            else{
                // allocate memory for the result 2D array
                results[(*returnSize)] = (int*)malloc(sizeof(int)*3);
                (*returnColumnSizes)[(*returnSize)] = 3; // number of columns in each array
                // append i, j, k to results array
                results[(*returnSize)][0] = nums[i];
                results[(*returnSize)][1] = nums[j];
                results[(*returnSize)][2] = nums[k];

                (*returnSize)++; // increment the number of results
                j++; // move pointer j to right
                while(j < k && nums[j] == nums[j - 1]) j++; // skip the same elements
            }
        }

    }
    return results;

}