class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create an unordered set to store the numbers that have already been seen.
        unordered_set<int> seen_nums;

        // Loop through the input vector.
        for (int num : nums){ // here can't use for (int i = 0; i < nums.size(); i++) because we need to check if the current number is already in the set.
            // Check if the current number is already in the set.
            if (seen_nums.count(num)){
                // If it is, we know that the vector contains a duplicate and return true.
                return true;
            }

            // If we reach the end of the loop without finding a duplicate, return false
            seen_nums.insert(num); // Add the current number to the set.
        }

        return false;
    }
};