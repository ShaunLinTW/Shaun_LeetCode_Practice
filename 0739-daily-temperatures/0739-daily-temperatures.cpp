class Solution {
public:
    // stack approach:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // initialize a result vector to update number of days have to wait, the last element must 0
        vector<int> result(temperatures.size(), 0);
        // initialize a stack vector to store all temperatures
        vector<int> stack;

        // iterate through temperatures array from the end of array
        for (int i = temperatures.size() - 1; i >= 0; --i){
            int currTemp = temperatures[i];

            // if stack is not empty, and current visited temperature greater than last element of temperatures array
            while (!stack.empty() && currTemp >= temperatures[stack.back()]){
                stack.pop_back(); // pop the stack
            }

            // if stack is not empty
            if (!stack.empty()){
                result[i] = stack.back() - i; // why???
            }
            
            stack.push_back(i); // 1st iteration stack is empty, push the index to stack

        }
        return result;
    }
};