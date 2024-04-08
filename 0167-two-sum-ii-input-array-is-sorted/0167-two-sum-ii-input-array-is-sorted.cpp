class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // initialize result arrauy
        vector<int> result;
        // initialize two pointers from the left side of the array and right side of the array
        int j = 0;
        int k = numbers.size() - 1;

        // iterate through array until left index j meet right index k
        while (j < k){
            // calculate sum of the two indices' number
            int sum = numbers[j] + numbers[k];
            
            // if sum equal target, append indices to result array
            if (sum == target){
                // note that: return index start from 1
                result.push_back(j+1);
                result.push_back(k+1);
                break; // break the while loop
            }
            // if sum greater then target, move right index k to left
            else if (sum > target){
                k--;
            }
            // if sum less then target, move left index j to right
            else{
                j++;
            }
        }
        return result;
    }
};