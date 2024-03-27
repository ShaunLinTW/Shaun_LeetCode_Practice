class Solution {
public:
    int search(vector<int>& nums, int target) {
        // initialize left, right, middle index
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        // binary search
        while (left <= right){
            // calculate middle index
            mid = left + (right - left) / 2;

            // if find target in the middle, return it's index
            if (target == nums[mid]) return mid;
            // if target smaller than middle, search left
            else if (target < nums[mid]) right = mid - 1;
            // search right
            else left = mid + 1;
        }
        return -1;
    }
};