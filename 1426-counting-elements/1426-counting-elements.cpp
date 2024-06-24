class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        
        // initialize a vector of 1001 elements with 0
        vector<int> v(1001, 0);

        // using vector to store the count of each element
        for (int i = 0; i < arr.size(); i++) {
            v[arr[i]]++;
        }
        // check if the next element exists
        for (int i = 0; i < 1000; i++) {
            if(v[i] && v[i + 1]) count += v[i]; // if the next element exists, add the count of the current element
        }

        // unordered set method (AKA hash set, but no need to use sortered set)
        // unordered_set<int> hashSet(arr.begin(), arr.end());

        // for (int i = 0; i < arr.size(); i++) {
        //     if(hashSet.find(arr[i]+1) != hashSet.end()) count++;
        // }
        return count;
    }
};