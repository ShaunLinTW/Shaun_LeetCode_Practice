class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map to store the numbers as keys and their indices as values.
        unordered_map<int, int> m;
        
        // Create a vector to store the result indices.
        vector<int> result;
        
        // Iterate through the input vector 'nums'.
        for(int i = 0; i < nums.size(); i++){
            // Calculate the complement for the current number to achieve the target sum.
            int complement = target - nums[i];
            
            // Check if the complement is present in the map.
            if(m.find(complement) != m.end()){
                // If complement is found, store its index and the current index in the result vector.
                result.push_back(m[complement]);  // Index of the complement.
                result.push_back(i);              // Current index.
                
                // Since there is only one valid solution, we can break out of the loop.
                break;
            }
            else {
                // If complement is not found, insert the current number and its index into the map.
                m.insert({nums[i], i});
            }
        }
        
        // Return the result vector containing the indices of the two numbers that add up to the target.
        return result;
    }
};


/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using two pass hash table
        // create an empty hash table to store elements and indices
        unordered_map<int, int> map;

        // iterate through nums array to build hash table
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }

        // iterate through the nums array
        for (int i = 0; i < nums.size(); i++){
            // calculate complement value by subtracting target with current number
            int complement_val = target - nums[i];
            // if the complement_val in the hash table, if it does, return the current index and complement_val index in the hash table 
            if (map.count(complement_val) && map[complement_val] != i){
                return {i, map[complement_val]};
            }
        }
        // other, no solution found, return empty
        return {};
    }
};
*/