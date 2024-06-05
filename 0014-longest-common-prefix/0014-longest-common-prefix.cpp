class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // get the string's length
        int n = strs.size();
        // empty case
        if (n == 0) return "";

        // sort the strings, so we can easily compare the first and last string
        sort(strs.begin(), strs.end());

        // get the first and last string
        string first = strs[0];
        string last = strs[n - 1];

        // initialize the result 
        string result = "";

        // compare the first and last string
        for (int i = 0; i < first.size(); i++){
            if (first[i] == last[i]) result += first[i];
            else break;
        }
        return result;
    }
};