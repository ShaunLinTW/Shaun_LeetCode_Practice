int removeElement(int* nums, int numsSize, int val) {
    int index = 0;

    // iterate through and visiting each element in the array
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != val){
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}