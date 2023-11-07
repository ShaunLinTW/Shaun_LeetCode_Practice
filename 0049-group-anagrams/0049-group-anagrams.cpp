class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        // Loop through each string in the input vector.
        for (string s : strs){
            // Sort the string and use the sorted string as a key in the unordered map.
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            groups[sorted_s].push_back(s);
        }
        // Create a 2D string array to store result
        vector<vector<string>> result;

        // Loop through each key-value pair in the unordered map.
        for (auto p : groups){
            // Add the value (a vector of anagrams) to the result vector.
            result.push_back(p.second);
        }
        return result;
    }
};