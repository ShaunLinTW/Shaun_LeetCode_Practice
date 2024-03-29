class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // initialize visited index which not the target value
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                // shift current visit value to front, you can assume that nums[index] is visited array, and nums[i] is current visiting array
                nums[index] = nums[i];
                // increment index to next position
                index++;
            }
        }
        return index;
    }
};