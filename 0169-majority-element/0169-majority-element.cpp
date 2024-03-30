class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 1st way (Sorting):
        // sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        // initialize the size of the array
        int n = nums.size();
        // return n/2, because the majority element will always present at index n/2
        return nums[n/2];

        // 2nd way (Hash Map):
        // initialize the size of the array, and using unordered_map to create hash map
        // int n = nums.size();
        // unordered_map<int, int> map;
        
        // // iterate through array, and increments its count in the hash map
        // for(int i = 0; i < n; i++){
        //     // one line code:
        //     // map[nums[i]]++; // access or insert the value into hash map & increment its count
            
        //     // multiple line code:
        //     int key = nums[i]; // extract key
        //     int& value = map[key]; // access or insert the value associated with the key in the map
        //     value++; // increment value
        // }

        // n = n/2; // get the middle of the array
        // // iterate through hash map
        // for(auto x: map){
        //     // if the count greater than n, return it's key, which is the majority element.
        //     if(x.second > n){
        //         return x.first;
        //     }
        // }
        // return 0;
    }
};