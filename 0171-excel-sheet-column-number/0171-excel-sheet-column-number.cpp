class Solution {
public:
    int titleToNumber(string columnTitle) {
        // initialize result number
        int result = 0;

        for (int i = 0; i < columnTitle.size(); i++){
            result *= 26; // each iteration * 26 to maintain base
            result += columnTitle[i] - 'A' + 1; // A in ASSIC represent 65, by doing subtraction current element with 'A' to make sure number start from 0, them + 1 
        }
        return result;
    }
};