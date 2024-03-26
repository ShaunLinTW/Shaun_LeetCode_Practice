int findMin(int* nums, int numsSize) {
    
}int findMin(int* nums, int numsSize) {
    // initialize left, right, middle index
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    // no rotation case
    if (nums[left] < nums[right]){
        return nums[left];
    }

    // iterate through array until left value bigger than right value
    while (left < right){
        // calculate middle index
        mid = left + (right - left) / 2;

        // if middle value bigger than right value, move the left index middle + 1
        if (nums[mid] > nums[right]){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return nums[left];
}