class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // initialize a acronym string
        string str = "";
        for(auto w: words) str += w[0];
        return (str == s);
    }
};