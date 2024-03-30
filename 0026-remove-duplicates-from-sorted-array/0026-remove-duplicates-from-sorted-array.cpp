class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // initialize a index for the visited array
        int index = 1;

        // don't check zero index's value, start from first index
        for (int i = 1; i < nums.size(); i++){
            // if current array's value not equals to visited array's value, add that value to visited array, and increment index of the visited array
            if (nums[i] != nums[i - 1]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};