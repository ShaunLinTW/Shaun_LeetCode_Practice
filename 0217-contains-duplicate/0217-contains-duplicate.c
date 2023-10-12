int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool containsDuplicate(int* nums, int numsSize){
    // Step 1: sort the array using quick sort
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // Step 2: check if there is any duplicate
    for (int i = 0; i < numsSize - 1; i++) {
        // ex: [1, 1, 2, 3]
        //      ^  ^
        if (nums[i] == nums[i+1]) return true;
    }
    // Step 3: return false if no duplicate
    return false;
}