int removeDuplicates(int* nums, int numsSize) {
    // initialize index of visited array
    int index = 1;

    // don't check zero index, start from first index
    for (int i = 1; i < numsSize; i++){
        // add value to visited array, if it's not equal to visited value
        if (nums[i] != nums[i - 1]){
            nums[index] = nums[i];
            index++; //increment index
        }
    }
    return index;
}