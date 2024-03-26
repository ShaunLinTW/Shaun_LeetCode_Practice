class Solution {
public:
    int findMin(vector<int>& nums) {
        // initialize the result as first element
        int result = nums[0];

        // initialize the left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        // no rotation case
        if (nums[left] <= nums[right]){
            return nums[left];
        }

        // iterate through the vector until the left pointer is less or equal to the right pointer
        while (left <= right){
            // calculate the middle pointer
            int mid = left + (right - left) / 2;
            result = min(result, nums[mid]);

            // if the middle element is greater than the right element, move the left pointer to the middle + 1
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return result;
    }
};