#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> map = {{')','('},{']','['},{'}','{'}};
        for (char c : s){
            if (c == '(' || c == '[' || c == '{'){
                stack.push(c);
            }
            else {
                if (stack.empty() || stack.top() != map[c]){
                    return false;
                }
                else {
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};