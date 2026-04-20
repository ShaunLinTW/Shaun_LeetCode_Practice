#include <string>
#include <unordered_map>

using namespace std;

// Right-to-left hashmap solution
// Time complexity:  O(n)
// Space complexity: O(1) — hashmap size is fixed at 7 entries
class Solution {
public:
    int romanToInt(string s) {
        // map each Roman symbol to its integer value
        unordered_map<char, int> hashmap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = 0;
        int prev = 0; // value of the symbol to the right of current

        // iterate right to left so we can detect subtractive pairs
        // e.g. CM -> C is less than M, so subtract C instead of adding
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            int curr = hashmap[s[i]];
            // if current symbol is less than the previous (right-side) symbol,
            // it is part of a subtractive pair (e.g. I in IV, X in XC)
            if (curr < prev) sum -= curr;
            else sum += curr;
            prev = curr;
        }

        return sum;
    }
};