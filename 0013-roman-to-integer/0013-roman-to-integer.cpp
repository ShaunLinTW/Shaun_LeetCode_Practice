class Solution {
public:
    int romanToInt(string s) {
        // use hashmap solution
        // initialize hash map and sum
        unordered_map<char, int> hashmap
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};
        int sum = 0;

        // iterate through string
        for (int i = 0; i < s.size(); i++){
            // if i+1 value greater than current index value, minus that value
            if (hashmap[s[i]] < hashmap[s[i+1]]){
                sum -= hashmap[s[i]];
            }
            // add key's value to sum
            else{
                sum += hashmap[s[i]];
            }
        }
        return sum;
    }
};