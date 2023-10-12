class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the two strings have different lengths, they cannot be anagrams, so return false.
        if (s.length() != t.length()){
            return false;
        }

        //Create two unordered maps to store the frequescies of each character in the string
        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;

        // Loop through each character in the first string s and update its frequency in the map.
        for (char c : s){
            freq_s[c]++;
        }

        // Loop through each character in the second string t and update its frequency in the map.
        for (char c: t){
            freq_t[c]++;
        }

        // Loop through each character in the first string and compare its frequency in the map.
        for (char c : s){
            // If the frequencies of a character differ between two maps, which means not anagram, then return false.
            if (freq_s[c] != freq_t[c]){
                return false;
            }
        }
        return true;
    }
};