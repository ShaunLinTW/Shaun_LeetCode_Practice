class Solution {
public:
    int strStr(string haystack, string needle) {
        // empty case
        if(needle == "") return 0;
    
        // two pointers method
        int i = 0;
        int j = 0;

        while(i < haystack.size() && j < needle.size()){
            if(haystack[i] == needle[j]){
                // increase two pointer if the string element match
                i++;
                j++;
                // if the whole pattern has been matched, then return the value by going needle size steps backwards from the current index in array
                if(j == needle.size()) return i - needle.size();
            }
            // when no match, start checking from the haystack index
            else{
                i = i - j + 1; // goes backwards till whatever length has been matched, which means only update 1st pointer
                j = 0; // check from pattern's beginning, which means restart 2nd pointer
            }
        }
        return -1;
    }
};