/*----------- 1st method (55ms: two pointers with vector) --------------*/
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // Initialize an 2D array
//         vector<vector<int>> result;
//         int n = nums.size();
//         if (n < 3){
//             return result;
//         }
//         // Sort input array
//         sort(nums.begin(), nums.end());

//         //Iterate through the input array until the third last element, because the array is sorted, so we don't need to iterated over the entire array, so I used n - 2
//         for (int i = 0; i < n - 2; i++){
//             // If the current element is greater than 0, then break the loop, because the input array is sorted in ascending order, so it's not possible to find a triplet that sums up to 0.
//             if (nums[i] > 0){
//                 break;
//             }
//             // If the current element is a duplicate of the previous element, then skips the current iteration.
//             if (i > 0 && nums[i - 1] == nums[i]){
//                 continue;
//             }
//             // Initialize two pointers for the array
//             int j = i + 1;
//             int k = n - 1;

//             // Loop untill j = k, then complete search the sum
//             while (j < k){
//                 // Initialize sum = i+j+k
//                 int sum = nums[i] + nums[j] + nums[k];
//                 // If sum < 0, then shift j pointer from left to right
//                 if (sum < 0){
//                     j++;
//                 }
//                 // If sum > 0, then shift k pointer from right to left
//                 else if (sum > 0){
//                     k--;
//                 }
//                 // If sum = 0, append i, j, k to result
//                 else {
//                     result.push_back({nums[i], nums[j], nums[k]});
//                     // skips any duplicate elements in nums[j]
//                     while (j < k && nums[j] == nums[j + 1]){
//                         j++;
//                     }
//                     j++;
//                     // skips any duplicate elements in nums[k]
//                     while (j < k && nums[k - 1] == nums[k]){
//                         k--;
//                     }
//                     k--;
//                 }
//             }
//         }
//         return result;
//     }
// };

/*----------- 2md method (1150ms: two pointers with set)--------------*/
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // sort the input array
//         sort(nums.begin(), nums.end());

//         // initialize target sum as 0
//         int target = 0;

//         // initialize a set to store the unique triplets and an output vector to store the final result
//         set<vector<int>> unique_set;
//         vector<vector<int>> output;

//         // iterate through array
//         for (int i = 0; i < nums.size(); i++){
//             // initialize two pointers
//             int j = i + 1; // next index of i
//             int k = nums.size() - 1; // end index of the array

//             // iterate through until index j meet k
//             while(j < k){
//                 // calculate sum of the current index + next index + end index value
//                 int sum = nums[i] + nums[j] + nums[k];
//                 // check if sum equal to 0, if it is -> insert the triplet indexs into the set, then move index -> increment j and decrement k
//                 if (sum == target){
//                     unique_set.insert({nums[i], nums[j], nums[k]});
//                     j++;
//                     k--;
//                 }
//                 else if (sum < target){
//                     j++;
//                 }
//                 else {
//                     k--;
//                 }
//             }
//         }
//         for (auto triplets : unique_set){
//             output.push_back(triplets);
//         }
//         return output;
//     }
// };

/*----------- 3rd method (260ms: hashmap) --------------*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());
        // special case, if array smaler then 3 means not enough for the 3sum condition or first value greater then 0, cause there's no possible to sum to 0
        if(nums.size() < 3 || nums[0] > 0){
            return {};
        }

        // initialize hashmap, and hashing of indices
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        /* Current Hashmap:
         *   Key   : Value
         * nums[i] :   i
        */

        // initialize results array
        vector<vector<int>> results;

        // iterate through the array until last third element
        for (int i = 0; i < nums.size() - 2; i++){
            // If the current element is greater than 0, then break the loop, because the input array is sorted in ascending order, so it's not possible to find a triplet that sums up to 0.
            if (nums[i] > 0){
                break;
            }
            // If the current element is a duplicate of the previous element, then skips the current iteration.
            if (i > 0 && nums[i - 1] == nums[i]){
                continue;
            }

            // iterate through array start from next index of i until last element
            for (int j = i + 1; j < nums.size() - 1; j++){
                int required = -(nums[i]+nums[j]);
                // if (hashmap.count(-(nums[i]+nums[j])) && hashmap.find(-(nums[i]+nums[j]))->second > j){
                if (hashmap.count(required) && hashmap.find(required)->second > j){
                    results.push_back({nums[i], nums[j], -(nums[i]+nums[j])});
                }
                j = hashmap.find(nums[j])->second;
            }
            i = hashmap.find(nums[i])->second;
        }
        return results;

    }
};