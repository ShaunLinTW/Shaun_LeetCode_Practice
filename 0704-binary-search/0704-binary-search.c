int search(int* nums, int numsSize, int target) {
    // initialize left, right, mid index
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    // binary search
    while (left <= right){
        // calculate middle index
        mid = left + (right - left) / 2;

        // if target smaller than middle value, search left
        if (target < nums[mid]){
            right = mid - 1;
        }
        // search right
        else if (target > nums[mid]){
            left = mid + 1;
        }
        else {
            return mid; // found target index, and return it
        }
    }
    return -1;
}